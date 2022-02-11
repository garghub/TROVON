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
F_46 ( V_7 , & V_73 ) ;
if ( V_40 -> V_44 . V_50 && ( V_7 -> V_52 & V_74 ) )
F_46 ( V_7 , & V_75 ) ;
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
if ( V_7 -> V_52 & V_76 )
F_49 ( V_5 ) ;
return V_5 ;
}
static int F_50 ( int type )
{
int V_77 = F_51 ( sizeof( struct V_78 ) )
+ F_52 ( 4 ) ;
if ( type == - 1 || type == V_79 )
V_77 += F_52 ( 4 ) ;
#ifdef F_53
if ( type == - 1 || type == V_80 )
V_77 += F_52 ( 4 ) ;
#endif
return V_77 ;
}
static int F_54 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 , T_1 V_86 ,
T_1 V_87 , int V_88 , unsigned int V_52 ,
int type )
{
struct V_89 * V_90 ;
struct V_78 * V_91 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( struct V_78 ) ,
V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
V_91 = F_56 ( V_90 ) ;
V_91 -> V_93 = V_94 ;
if ( F_57 ( V_82 , V_95 , V_83 ) < 0 )
goto V_96;
if ( ( type == - 1 || type == V_79 ) &&
F_57 ( V_82 , V_79 , V_85 -> V_50 ) < 0 )
goto V_96;
#ifdef F_53
if ( ( type == - 1 || type == V_80 ) &&
F_57 ( V_82 , V_80 ,
V_85 -> V_97 ) < 0 )
goto V_96;
#endif
return F_58 ( V_82 , V_90 ) ;
V_96:
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
void F_60 ( struct V_98 * V_98 , int type , int V_83 ,
struct V_84 * V_85 )
{
struct V_81 * V_82 ;
int V_99 = - V_100 ;
V_82 = F_61 ( F_50 ( type ) , V_101 ) ;
if ( V_82 == NULL )
goto V_102;
V_99 = F_54 ( V_82 , V_83 , V_85 , 0 , 0 ,
V_103 , 0 , type ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_102;
}
F_63 ( V_82 , V_98 , 0 , V_104 , NULL , V_101 ) ;
return;
V_102:
F_64 ( V_98 , V_104 , V_99 ) ;
}
static int F_65 ( struct V_81 * V_105 ,
struct V_89 * V_90 ,
void * V_106 )
{
struct V_98 * V_98 = F_66 ( V_105 -> V_107 ) ;
struct V_108 * V_109 [ V_110 + 1 ] ;
struct V_78 * V_91 ;
struct V_81 * V_82 ;
struct V_84 * V_85 ;
struct V_4 * V_111 ;
struct V_6 * V_7 ;
int V_83 ;
int V_99 ;
V_99 = F_67 ( V_90 , sizeof( * V_91 ) , V_109 , V_110 ,
V_112 ) ;
if ( V_99 < 0 )
goto V_102;
V_99 = V_113 ;
if ( ! V_109 [ V_95 ] )
goto V_102;
V_83 = F_68 ( V_109 [ V_95 ] ) ;
switch ( V_83 ) {
case V_114 :
V_85 = V_98 -> V_23 . V_115 ;
break;
case V_116 :
V_85 = V_98 -> V_23 . V_45 ;
break;
default:
V_7 = F_69 ( V_98 , V_83 ) ;
if ( V_7 == NULL )
goto V_102;
V_111 = F_48 ( V_7 ) ;
if ( V_111 == NULL )
goto V_102;
V_85 = & V_111 -> V_44 ;
break;
}
V_99 = - V_100 ;
V_82 = F_61 ( F_50 ( - 1 ) , V_101 ) ;
if ( V_82 == NULL )
goto V_102;
V_99 = F_54 ( V_82 , V_83 , V_85 ,
F_70 ( V_105 ) . V_86 ,
V_90 -> V_117 , V_103 , 0 ,
- 1 ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_102;
}
V_99 = F_71 ( V_82 , V_98 , F_70 ( V_105 ) . V_86 ) ;
V_102:
return V_99 ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_118 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_44 . V_50 )
F_33 ( V_7 ) ;
if ( V_7 -> V_52 & V_74 ) {
if ( V_5 -> V_44 . V_50 ) {
F_46 ( V_7 , & V_75 ) ;
F_46 ( V_7 , & V_119 ) ;
F_46 ( V_7 , & V_120 ) ;
} else {
F_73 ( V_7 , & V_75 ) ;
F_73 ( V_7 , & V_119 ) ;
F_73 ( V_7 , & V_120 ) ;
}
}
F_74 (ifa, &idev->addr_list, if_list) {
if ( V_118 -> V_52 & V_121 )
continue;
if ( V_5 -> V_44 . V_50 )
F_75 ( V_118 ) ;
else
F_76 ( V_118 ) ;
}
F_60 ( F_31 ( V_7 ) , V_79 ,
V_7 -> V_83 , & V_5 -> V_44 ) ;
}
static void F_77 ( struct V_98 * V_98 , T_2 V_122 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_78 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_123 = ( ! V_5 -> V_44 . V_50 ) ^ ( ! V_122 ) ;
V_5 -> V_44 . V_50 = V_122 ;
if ( V_123 )
F_72 ( V_5 ) ;
}
}
}
static int F_79 ( struct V_124 * V_125 , int * V_126 , int V_122 )
{
struct V_98 * V_98 ;
int V_127 ;
if ( ! F_80 () )
return F_81 () ;
V_98 = (struct V_98 * ) V_125 -> V_128 ;
V_127 = * V_126 ;
* V_126 = V_122 ;
if ( V_126 == & V_98 -> V_23 . V_45 -> V_50 ) {
if ( ( ! V_122 ) ^ ( ! V_127 ) )
F_60 ( V_98 , V_79 ,
V_116 ,
V_98 -> V_23 . V_45 ) ;
F_82 () ;
return 0 ;
}
if ( V_126 == & V_98 -> V_23 . V_115 -> V_50 ) {
V_98 -> V_23 . V_45 -> V_50 = V_122 ;
F_77 ( V_98 , V_122 ) ;
if ( ( ! V_122 ) ^ ( ! V_127 ) )
F_60 ( V_98 , V_79 ,
V_114 ,
V_98 -> V_23 . V_115 ) ;
} else if ( ( ! V_122 ) ^ ( ! V_127 ) )
F_72 ( (struct V_4 * ) V_125 -> V_129 ) ;
F_82 () ;
if ( V_122 )
F_83 ( V_98 ) ;
return 1 ;
}
void F_84 ( struct V_8 * V_9 )
{
F_20 ( ! F_85 ( & V_9 -> V_130 ) ) ;
#ifdef F_22
F_23 ( L_7 , V_36 ) ;
#endif
F_86 ( V_9 -> V_5 ) ;
if ( F_7 ( & V_9 -> V_10 ) )
F_87 ( L_8 , V_9 ) ;
if ( V_9 -> V_131 != V_132 ) {
F_25 ( L_9 , V_9 ) ;
return;
}
F_88 ( V_9 -> V_133 ) ;
F_26 ( V_9 , V_39 ) ;
}
static void
F_89 ( struct V_4 * V_5 , struct V_8 * V_9 )
{
struct V_134 * V_126 ;
int V_135 = F_90 ( & V_9 -> V_136 ) ;
F_91 (p, &idev->addr_list) {
struct V_8 * V_118
= F_92 ( V_126 , struct V_8 , V_137 ) ;
if ( V_135 >= F_90 ( & V_118 -> V_136 ) )
break;
}
F_93 ( & V_9 -> V_137 , V_126 ) ;
}
static T_1 F_94 ( const struct V_138 * V_136 )
{
return F_95 ( F_96 ( V_136 ) , V_139 ) ;
}
static struct V_8 *
F_97 ( struct V_4 * V_5 , const struct V_138 * V_136 , int V_140 ,
int V_141 , T_1 V_52 )
{
struct V_8 * V_118 = NULL ;
struct V_142 * V_133 ;
unsigned int V_143 ;
int V_99 = 0 ;
int V_144 = F_98 ( V_136 ) ;
if ( V_144 == V_145 ||
V_144 & V_146 ||
( ! ( V_5 -> V_7 -> V_52 & V_54 ) &&
V_144 & V_147 ) )
return F_99 ( - V_148 ) ;
F_100 () ;
if ( V_5 -> V_38 ) {
V_99 = - V_149 ;
goto V_150;
}
if ( V_5 -> V_44 . V_151 ) {
V_99 = - V_152 ;
goto V_150;
}
F_101 ( & V_153 ) ;
if ( F_102 ( F_31 ( V_5 -> V_7 ) , V_136 , V_5 -> V_7 ) ) {
F_35 ( ( L_10 ) ) ;
V_99 = - V_154 ;
goto V_155;
}
V_118 = F_15 ( sizeof( struct V_8 ) , V_101 ) ;
if ( V_118 == NULL ) {
F_35 ( ( L_11 ) ) ;
V_99 = - V_100 ;
goto V_155;
}
V_133 = F_103 ( V_5 , V_136 , false ) ;
if ( F_104 ( V_133 ) ) {
V_99 = F_105 ( V_133 ) ;
goto V_155;
}
V_118 -> V_136 = * V_136 ;
F_106 ( & V_118 -> V_43 ) ;
F_106 ( & V_118 -> V_156 ) ;
F_107 ( & V_118 -> V_10 ) ;
F_108 ( & V_118 -> V_130 ) ;
V_118 -> V_10 . V_157 = ( unsigned long ) V_118 ;
V_118 -> V_141 = V_141 ;
V_118 -> V_158 = V_140 ;
V_118 -> V_52 = V_52 | V_121 ;
V_118 -> V_1 = V_118 -> V_70 = V_20 ;
V_118 -> V_133 = V_133 ;
V_118 -> V_5 = V_5 ;
F_38 ( V_5 ) ;
F_10 ( V_118 ) ;
V_143 = F_94 ( V_136 ) ;
F_109 ( & V_118 -> V_130 , & V_159 [ V_143 ] ) ;
F_110 ( & V_153 ) ;
F_111 ( & V_5 -> V_43 ) ;
F_89 ( V_5 , V_118 ) ;
#ifdef F_41
if ( V_118 -> V_52 & V_160 ) {
F_112 ( & V_118 -> V_161 , & V_5 -> V_61 ) ;
F_10 ( V_118 ) ;
}
#endif
F_10 ( V_118 ) ;
F_113 ( & V_5 -> V_43 ) ;
V_150:
F_114 () ;
if ( F_115 ( V_99 == 0 ) )
F_116 ( V_162 , V_118 ) ;
else {
F_16 ( V_118 ) ;
V_118 = F_99 ( V_99 ) ;
}
return V_118 ;
V_155:
F_110 ( & V_153 ) ;
goto V_150;
}
static void F_117 ( struct V_8 * V_9 )
{
struct V_8 * V_118 , * V_163 ;
struct V_4 * V_5 = V_9 -> V_5 ;
int V_131 ;
int V_164 = 0 , V_165 = 0 ;
unsigned long V_19 = V_20 ;
F_118 ( & V_9 -> V_156 ) ;
V_131 = V_9 -> V_131 ;
V_9 -> V_131 = V_132 ;
F_119 ( & V_9 -> V_156 ) ;
if ( V_131 == V_132 )
goto V_155;
F_118 ( & V_153 ) ;
F_120 ( & V_9 -> V_130 ) ;
F_119 ( & V_153 ) ;
F_121 ( & V_5 -> V_43 ) ;
#ifdef F_41
if ( V_9 -> V_52 & V_160 ) {
F_122 ( & V_9 -> V_161 ) ;
if ( V_9 -> V_166 ) {
F_123 ( V_9 -> V_166 ) ;
V_9 -> V_166 = NULL ;
}
F_8 ( V_9 ) ;
}
#endif
F_124 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_118 == V_9 ) {
F_125 ( & V_9 -> V_137 ) ;
F_8 ( V_9 ) ;
if ( ! ( V_9 -> V_52 & V_167 ) || V_165 > 0 )
break;
V_164 = 1 ;
continue;
} else if ( V_9 -> V_52 & V_167 ) {
if ( F_126 ( & V_118 -> V_136 , & V_9 -> V_136 ,
V_9 -> V_158 ) ) {
if ( V_118 -> V_52 & V_167 ) {
V_165 = 1 ;
if ( V_164 )
break;
} else {
unsigned long V_168 ;
if ( ! V_165 )
V_165 = - 1 ;
F_101 ( & V_118 -> V_43 ) ;
V_168 = F_127 ( V_118 -> V_169 , V_3 ) ;
if ( F_128 ( V_19 ,
V_118 -> V_70 + V_168 * V_3 ) )
V_19 = V_118 -> V_70 + V_168 * V_3 ;
F_110 ( & V_118 -> V_43 ) ;
}
}
}
}
F_129 ( & V_5 -> V_43 ) ;
F_6 ( V_9 ) ;
F_130 ( V_170 , V_9 ) ;
F_116 ( V_171 , V_9 ) ;
if ( ( V_9 -> V_52 & V_167 ) && V_165 < 1 ) {
struct V_138 V_172 ;
struct V_142 * V_133 ;
F_131 ( & V_172 , & V_9 -> V_136 , V_9 -> V_158 ) ;
V_133 = F_132 ( & V_172 ,
V_9 -> V_158 ,
V_9 -> V_5 -> V_7 ,
0 , V_173 | V_174 ) ;
if ( V_133 ) {
if ( V_165 == 0 ) {
F_133 ( V_133 ) ;
V_133 = NULL ;
} else if ( ! ( V_133 -> V_175 & V_176 ) ) {
F_134 ( V_133 , V_19 ) ;
}
}
F_88 ( V_133 ) ;
}
F_135 ( V_9 ) ;
V_155:
F_123 ( V_9 ) ;
}
static int F_136 ( struct V_8 * V_9 , struct V_8 * V_177 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_138 V_136 , * V_178 ;
unsigned long V_179 , V_180 , V_181 , V_182 ;
unsigned long V_183 ;
int V_184 ;
int V_185 = 0 ;
int V_186 ;
T_1 V_187 ;
unsigned long V_188 = V_20 ;
F_111 ( & V_5 -> V_43 ) ;
if ( V_177 ) {
F_118 ( & V_177 -> V_43 ) ;
memcpy ( & V_136 . V_189 [ 8 ] , & V_177 -> V_136 . V_189 [ 8 ] , 8 ) ;
F_119 ( & V_177 -> V_43 ) ;
V_178 = & V_136 ;
} else {
V_178 = NULL ;
}
V_190:
F_38 ( V_5 ) ;
if ( V_5 -> V_44 . V_67 <= 0 ) {
F_113 ( & V_5 -> V_43 ) ;
F_40 ( L_12 , V_36 ) ;
F_86 ( V_5 ) ;
V_185 = - 1 ;
goto V_155;
}
F_118 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_191 ++ >= V_5 -> V_44 . V_192 ) {
V_5 -> V_44 . V_67 = - 1 ;
F_119 ( & V_9 -> V_43 ) ;
F_113 ( & V_5 -> V_43 ) ;
F_25 ( L_13 ,
V_36 ) ;
F_86 ( V_5 ) ;
V_185 = - 1 ;
goto V_155;
}
F_10 ( V_9 ) ;
memcpy ( V_136 . V_189 , V_9 -> V_136 . V_189 , 8 ) ;
F_137 ( V_5 , V_178 ) ;
memcpy ( & V_136 . V_189 [ 8 ] , V_5 -> V_193 , 8 ) ;
V_182 = ( V_188 - V_9 -> V_70 ) / V_3 ;
V_180 = F_138 ( V_194 ,
V_9 -> V_169 ,
V_5 -> V_44 . V_195 + V_182 ) ;
V_179 = F_138 ( V_194 ,
V_9 -> V_196 ,
V_5 -> V_44 . V_197 + V_182 -
V_5 -> V_44 . V_198 ) ;
V_184 = V_9 -> V_158 ;
V_186 = V_5 -> V_44 . V_186 ;
V_181 = V_9 -> V_70 ;
F_119 ( & V_9 -> V_43 ) ;
V_183 = V_5 -> V_44 . V_192 *
V_5 -> V_44 . V_199 *
V_5 -> V_48 -> V_200 / V_3 ;
F_113 ( & V_5 -> V_43 ) ;
if ( V_179 <= V_183 ) {
F_123 ( V_9 ) ;
F_86 ( V_5 ) ;
V_185 = - 1 ;
goto V_155;
}
V_187 = V_160 ;
if ( V_9 -> V_52 & V_201 )
V_187 |= V_201 ;
V_177 = ! V_186 ||
F_139 ( V_5 ) < V_186 ?
F_97 ( V_5 , & V_136 , V_184 ,
F_98 ( & V_136 ) & V_202 ,
V_187 ) : NULL ;
if ( F_140 ( V_177 ) ) {
F_123 ( V_9 ) ;
F_86 ( V_5 ) ;
F_40 ( L_14 , V_36 ) ;
V_178 = & V_136 ;
F_111 ( & V_5 -> V_43 ) ;
goto V_190;
}
F_118 ( & V_177 -> V_43 ) ;
V_177 -> V_166 = V_9 ;
V_177 -> V_169 = V_180 ;
V_177 -> V_196 = V_179 ;
V_177 -> V_1 = V_188 ;
V_177 -> V_70 = V_181 ;
F_119 ( & V_177 -> V_43 ) ;
F_141 ( V_177 ) ;
F_123 ( V_177 ) ;
F_86 ( V_5 ) ;
V_155:
return V_185 ;
}
static inline int F_142 ( int type )
{
if ( type & ( V_203 | V_204 | V_147 ) )
return 1 ;
return 0 ;
}
static int F_143 ( struct V_98 * V_98 ,
struct V_205 * V_206 ,
struct V_207 * V_208 ,
int V_209 )
{
int V_185 ;
if ( V_209 <= V_206 -> V_210 ) {
switch ( V_209 ) {
case V_211 :
V_185 = V_206 -> V_212 ;
break;
case V_213 :
V_185 = V_206 -> V_214 ;
break;
default:
V_185 = ! ! F_144 ( V_209 , V_206 -> V_215 ) ;
}
goto V_155;
}
switch ( V_209 ) {
case V_216 :
V_185 = ! ! V_206 -> V_118 ;
break;
case V_217 :
V_185 = F_145 ( & V_206 -> V_118 -> V_136 , V_208 -> V_136 ) ;
break;
case V_211 :
V_185 = F_146 ( V_206 -> V_144 ) ;
if ( V_185 >= V_208 -> V_141 )
V_185 = - V_185 ;
else
V_185 -= 128 ;
V_206 -> V_212 = V_185 ;
break;
case V_218 :
V_185 = F_142 ( V_206 -> V_144 ) ||
! ( V_206 -> V_118 -> V_52 & ( V_219 | V_201 ) ) ;
break;
#ifdef F_147
case V_220 :
{
int V_221 = ! ( V_208 -> V_222 & V_223 ) ;
V_185 = ! ( V_206 -> V_118 -> V_52 & V_224 ) ^ V_221 ;
break;
}
#endif
case V_225 :
V_185 = ( ! V_208 -> V_83 ||
V_208 -> V_83 == V_206 -> V_118 -> V_5 -> V_7 -> V_83 ) ;
break;
case V_226 :
V_185 = F_148 ( V_98 ,
& V_206 -> V_118 -> V_136 , V_206 -> V_144 ,
V_206 -> V_118 -> V_5 -> V_7 -> V_83 ) == V_208 -> V_227 ;
break;
#ifdef F_41
case V_228 :
{
int V_229 = V_208 -> V_222 & ( V_230 | V_231 ) ?
! ! ( V_208 -> V_222 & V_231 ) :
V_206 -> V_118 -> V_5 -> V_44 . V_67 >= 2 ;
V_185 = ( ! ( V_206 -> V_118 -> V_52 & V_160 ) ) ^ V_229 ;
break;
}
#endif
case V_232 :
V_185 = ! ( F_149 ( & V_206 -> V_118 -> V_136 ) ^
F_149 ( V_208 -> V_136 ) ) ;
break;
case V_213 :
V_185 = F_150 ( & V_206 -> V_118 -> V_136 , V_208 -> V_136 ) ;
if ( V_185 > V_206 -> V_118 -> V_158 )
V_185 = V_206 -> V_118 -> V_158 ;
V_206 -> V_214 = V_185 ;
break;
default:
V_185 = 0 ;
}
if ( V_185 )
F_151 ( V_209 , V_206 -> V_215 ) ;
V_206 -> V_210 = V_209 ;
V_155:
return V_185 ;
}
int F_152 ( struct V_98 * V_98 , const struct V_6 * V_233 ,
const struct V_138 * V_234 , unsigned int V_222 ,
struct V_138 * V_235 )
{
struct V_205 V_236 [ 2 ] ,
* V_206 = & V_236 [ 0 ] , * V_237 = & V_236 [ 1 ] ;
struct V_207 V_208 ;
struct V_6 * V_7 ;
int V_238 ;
V_238 = F_153 ( V_234 ) ;
V_208 . V_136 = V_234 ;
V_208 . V_83 = V_233 ? V_233 -> V_83 : 0 ;
V_208 . V_141 = F_146 ( V_238 ) ;
V_208 . V_227 = F_148 ( V_98 , V_234 , V_238 , V_208 . V_83 ) ;
V_208 . V_222 = V_222 ;
V_237 -> V_210 = - 1 ;
V_237 -> V_118 = NULL ;
F_154 () ;
F_155 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_238 & V_146 ) ||
V_208 . V_141 <= V_239 ) &&
V_208 . V_83 && V_7 -> V_83 != V_208 . V_83 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_156 ( & V_5 -> V_43 ) ;
F_74 (score->ifa, &idev->addr_list, if_list) {
int V_209 ;
if ( ( V_206 -> V_118 -> V_52 & V_121 ) &&
( ! ( V_206 -> V_118 -> V_52 & V_201 ) ) )
continue;
V_206 -> V_144 = F_153 ( & V_206 -> V_118 -> V_136 ) ;
if ( F_157 ( V_206 -> V_144 == V_145 ||
V_206 -> V_144 & V_146 ) ) {
F_158 ( V_240
L_15
L_16 ,
V_7 -> V_37 ) ;
continue;
}
V_206 -> V_210 = - 1 ;
F_159 ( V_206 -> V_215 , V_241 ) ;
for ( V_209 = 0 ; V_209 < V_241 ; V_209 ++ ) {
int V_242 , V_243 ;
V_242 = F_143 ( V_98 , V_237 , & V_208 , V_209 ) ;
V_243 = F_143 ( V_98 , V_206 , & V_208 , V_209 ) ;
if ( V_242 > V_243 ) {
if ( V_209 == V_211 &&
V_206 -> V_212 > 0 ) {
goto V_244;
}
break;
} else if ( V_242 < V_243 ) {
if ( V_237 -> V_118 )
F_123 ( V_237 -> V_118 ) ;
F_10 ( V_206 -> V_118 ) ;
F_160 ( V_237 , V_206 ) ;
V_206 -> V_118 = V_237 -> V_118 ;
break;
}
}
}
V_244:
F_161 ( & V_5 -> V_43 ) ;
}
F_162 () ;
if ( ! V_237 -> V_118 )
return - V_148 ;
* V_235 = V_237 -> V_118 -> V_136 ;
F_123 ( V_237 -> V_118 ) ;
return 0 ;
}
int F_163 ( struct V_6 * V_7 , struct V_138 * V_136 ,
unsigned char V_245 )
{
struct V_4 * V_5 ;
int V_99 = - V_148 ;
F_154 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_141 == V_246 &&
! ( V_9 -> V_52 & V_245 ) ) {
* V_136 = V_9 -> V_136 ;
V_99 = 0 ;
break;
}
}
F_161 ( & V_5 -> V_43 ) ;
}
F_162 () ;
return V_99 ;
}
static int F_139 ( struct V_4 * V_5 )
{
int V_247 = 0 ;
struct V_8 * V_9 ;
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list)
V_247 ++ ;
F_161 ( & V_5 -> V_43 ) ;
return V_247 ;
}
int F_164 ( struct V_98 * V_98 , const struct V_138 * V_136 ,
struct V_6 * V_7 , int V_248 )
{
struct V_8 * V_9 ;
unsigned int V_143 = F_94 ( V_136 ) ;
F_100 () ;
F_165 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_166 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_145 ( & V_9 -> V_136 , V_136 ) &&
! ( V_9 -> V_52 & V_121 ) &&
( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_141 & ( V_246 | V_249 ) || V_248 ) ) ) {
F_114 () ;
return 1 ;
}
}
F_114 () ;
return 0 ;
}
static bool F_102 ( struct V_98 * V_98 , const struct V_138 * V_136 ,
struct V_6 * V_7 )
{
unsigned int V_143 = F_94 ( V_136 ) ;
struct V_8 * V_9 ;
F_167 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_166 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_145 ( & V_9 -> V_136 , V_136 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_168 ( const struct V_138 * V_136 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_8 * V_118 ;
int V_165 ;
V_165 = 0 ;
F_154 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifa, &idev->addr_list, if_list) {
V_165 = F_126 ( V_136 , & V_118 -> V_136 ,
V_118 -> V_158 ) ;
if ( V_165 )
break;
}
F_161 ( & V_5 -> V_43 ) ;
}
F_162 () ;
return V_165 ;
}
struct V_8 * F_169 ( struct V_98 * V_98 , const struct V_138 * V_136 ,
struct V_6 * V_7 , int V_248 )
{
struct V_8 * V_9 , * V_250 = NULL ;
unsigned int V_143 = F_94 ( V_136 ) ;
F_100 () ;
F_170 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_166 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_145 ( & V_9 -> V_136 , V_136 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_141 & ( V_246 | V_249 ) || V_248 ) ) {
V_250 = V_9 ;
F_10 ( V_9 ) ;
break;
}
}
}
F_114 () ;
return V_250 ;
}
static void F_171 ( struct V_8 * V_9 , int V_251 )
{
if ( V_9 -> V_52 & V_167 ) {
F_118 ( & V_9 -> V_43 ) ;
F_6 ( V_9 ) ;
V_9 -> V_52 |= V_121 ;
if ( V_251 )
V_9 -> V_52 |= V_252 ;
F_119 ( & V_9 -> V_43 ) ;
if ( V_251 )
F_130 ( 0 , V_9 ) ;
F_123 ( V_9 ) ;
#ifdef F_41
} else if ( V_9 -> V_52 & V_160 ) {
struct V_8 * V_166 ;
F_118 ( & V_9 -> V_43 ) ;
V_166 = V_9 -> V_166 ;
if ( V_166 ) {
F_10 ( V_166 ) ;
F_119 ( & V_9 -> V_43 ) ;
F_136 ( V_166 , V_9 ) ;
F_123 ( V_166 ) ;
} else {
F_119 ( & V_9 -> V_43 ) ;
}
F_117 ( V_9 ) ;
#endif
} else
F_117 ( V_9 ) ;
}
static int F_172 ( struct V_8 * V_9 )
{
int V_99 = - V_253 ;
F_101 ( & V_9 -> V_156 ) ;
if ( V_9 -> V_131 == V_254 ) {
V_9 -> V_131 = V_255 ;
V_99 = 0 ;
}
F_110 ( & V_9 -> V_156 ) ;
return V_99 ;
}
void F_173 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
if ( F_172 ( V_9 ) ) {
F_123 ( V_9 ) ;
return;
}
F_174 ( L_17 ,
V_9 -> V_5 -> V_7 -> V_37 , & V_9 -> V_136 ) ;
if ( V_5 -> V_44 . V_55 > 1 && ! V_5 -> V_44 . V_151 ) {
struct V_138 V_136 ;
V_136 . V_256 [ 0 ] = F_175 ( 0xfe800000 ) ;
V_136 . V_256 [ 1 ] = 0 ;
if ( ! F_176 ( V_136 . V_189 + 8 , V_5 -> V_7 ) &&
F_145 ( & V_9 -> V_136 , & V_136 ) ) {
V_5 -> V_44 . V_151 = 1 ;
F_40 ( L_18 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
}
}
F_171 ( V_9 , 1 ) ;
}
void F_177 ( struct V_6 * V_7 , const struct V_138 * V_136 )
{
struct V_138 V_257 ;
if ( V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_178 ( V_136 , & V_257 ) ;
F_46 ( V_7 , & V_257 ) ;
}
void F_179 ( struct V_4 * V_5 , const struct V_138 * V_136 )
{
struct V_138 V_257 ;
if ( V_5 -> V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_178 ( V_136 , & V_257 ) ;
F_180 ( V_5 , & V_257 ) ;
}
static void F_75 ( struct V_8 * V_9 )
{
struct V_138 V_136 ;
if ( V_9 -> V_158 == 127 )
return;
F_131 ( & V_136 , & V_9 -> V_136 , V_9 -> V_158 ) ;
if ( F_181 ( & V_136 ) )
return;
F_182 ( V_9 -> V_5 -> V_7 , & V_136 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
struct V_138 V_136 ;
if ( V_9 -> V_158 == 127 )
return;
F_131 ( & V_136 , & V_9 -> V_136 , V_9 -> V_158 ) ;
if ( F_181 ( & V_136 ) )
return;
F_183 ( V_9 -> V_5 , & V_136 ) ;
}
static int F_184 ( T_3 * V_258 , struct V_6 * V_7 )
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
static int F_185 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_263 )
return - 1 ;
memcpy ( V_258 , V_7 -> V_261 , 8 ) ;
V_258 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_186 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_264 )
return - 1 ;
memset ( V_258 , 0 , 7 ) ;
V_258 [ 7 ] = * ( T_3 * ) V_7 -> V_261 ;
return 0 ;
}
static int F_187 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_265 )
return - 1 ;
memcpy ( V_258 , V_7 -> V_261 + 12 , 8 ) ;
V_258 [ 0 ] |= 2 ;
return 0 ;
}
static int F_188 ( T_3 * V_258 , T_4 V_136 )
{
if ( V_136 == 0 )
return - 1 ;
V_258 [ 0 ] = ( F_189 ( V_136 ) || F_190 ( V_136 ) ||
F_191 ( V_136 ) || F_192 ( V_136 ) ||
F_193 ( V_136 ) || F_194 ( V_136 ) ||
F_195 ( V_136 ) || F_196 ( V_136 ) ||
F_197 ( V_136 ) || F_198 ( V_136 ) ||
F_199 ( V_136 ) ) ? 0x00 : 0x02 ;
V_258 [ 1 ] = 0 ;
V_258 [ 2 ] = 0x5E ;
V_258 [ 3 ] = 0xFE ;
memcpy ( V_258 + 4 , & V_136 , 4 ) ;
return 0 ;
}
static int F_200 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_58 & V_59 )
return F_188 ( V_258 , * ( T_4 * ) V_7 -> V_261 ) ;
return - 1 ;
}
static int F_201 ( T_3 * V_258 , struct V_6 * V_7 )
{
return F_188 ( V_258 , * ( T_4 * ) V_7 -> V_261 ) ;
}
static int F_176 ( T_3 * V_258 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_266 :
case V_267 :
return F_184 ( V_258 , V_7 ) ;
case V_268 :
return F_186 ( V_258 , V_7 ) ;
case V_269 :
return F_187 ( V_258 , V_7 ) ;
case V_57 :
return F_200 ( V_258 , V_7 ) ;
case V_270 :
return F_201 ( V_258 , V_7 ) ;
case V_271 :
return F_185 ( V_258 , V_7 ) ;
}
return - 1 ;
}
static int F_202 ( T_3 * V_258 , struct V_4 * V_5 )
{
int V_99 = - 1 ;
struct V_8 * V_9 ;
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_141 == V_246 && ! ( V_9 -> V_52 & V_121 ) ) {
memcpy ( V_258 , V_9 -> V_136 . V_189 + 8 , 8 ) ;
V_99 = 0 ;
break;
}
}
F_161 ( & V_5 -> V_43 ) ;
return V_99 ;
}
static void F_203 ( struct V_4 * V_5 )
{
V_272:
F_204 ( V_5 -> V_193 , sizeof( V_5 -> V_193 ) ) ;
V_5 -> V_193 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_193 [ 0 ] == 0xfd &&
( V_5 -> V_193 [ 1 ] & V_5 -> V_193 [ 2 ] & V_5 -> V_193 [ 3 ] & V_5 -> V_193 [ 4 ] & V_5 -> V_193 [ 5 ] & V_5 -> V_193 [ 6 ] ) == 0xff &&
( V_5 -> V_193 [ 7 ] & 0x80 ) )
goto V_272;
if ( ( V_5 -> V_193 [ 0 ] | V_5 -> V_193 [ 1 ] ) == 0 ) {
if ( V_5 -> V_193 [ 2 ] == 0x5e && V_5 -> V_193 [ 3 ] == 0xfe )
goto V_272;
if ( ( V_5 -> V_193 [ 2 ] | V_5 -> V_193 [ 3 ] | V_5 -> V_193 [ 4 ] | V_5 -> V_193 [ 5 ] | V_5 -> V_193 [ 6 ] | V_5 -> V_193 [ 7 ] ) == 0x00 )
goto V_272;
}
}
static void V_63 ( unsigned long V_157 )
{
struct V_4 * V_5 = (struct V_4 * ) V_157 ;
unsigned long V_19 ;
F_100 () ;
F_121 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 )
goto V_155;
F_203 ( V_5 ) ;
V_19 = V_20 +
V_5 -> V_44 . V_197 * V_3 -
V_5 -> V_44 . V_192 * V_5 -> V_44 . V_199 * V_5 -> V_48 -> V_200 -
V_5 -> V_44 . V_198 * V_3 ;
if ( F_128 ( V_19 , V_20 ) ) {
F_25 ( L_19 ,
V_36 , V_5 -> V_7 -> V_37 ) ;
goto V_155;
}
if ( ! F_205 ( & V_5 -> V_62 , V_19 ) )
F_38 ( V_5 ) ;
V_155:
F_129 ( & V_5 -> V_43 ) ;
F_114 () ;
F_86 ( V_5 ) ;
}
static void F_137 ( struct V_4 * V_5 , struct V_138 * V_178 )
{
if ( V_178 && memcmp ( V_5 -> V_193 , & V_178 -> V_189 [ 8 ] , 8 ) == 0 )
F_203 ( V_5 ) ;
}
static void
F_206 ( struct V_138 * V_273 , int V_274 , struct V_6 * V_7 ,
unsigned long V_19 , T_1 V_52 )
{
struct V_275 V_276 = {
. V_277 = V_278 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_83 ,
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
F_207 ( & V_276 ) ;
}
static struct V_142 * F_132 ( const struct V_138 * V_273 ,
int V_274 ,
const struct V_6 * V_7 ,
T_1 V_52 , T_1 V_293 )
{
struct V_294 * V_295 ;
struct V_142 * V_133 = NULL ;
struct V_296 * V_125 ;
V_125 = F_208 ( F_31 ( V_7 ) , V_278 ) ;
if ( V_125 == NULL )
return NULL ;
F_156 ( & V_125 -> V_297 ) ;
V_295 = F_209 ( & V_125 -> V_298 , V_273 , V_274 , NULL , 0 ) ;
if ( ! V_295 )
goto V_155;
for ( V_133 = V_295 -> V_299 ; V_133 ; V_133 = V_133 -> V_208 . V_300 ) {
if ( V_133 -> V_208 . V_7 -> V_83 != V_7 -> V_83 )
continue;
if ( ( V_133 -> V_175 & V_52 ) != V_52 )
continue;
if ( ( V_133 -> V_175 & V_293 ) != 0 )
continue;
F_210 ( & V_133 -> V_208 ) ;
break;
}
V_155:
F_161 ( & V_125 -> V_297 ) ;
return V_133 ;
}
static void F_211 ( struct V_6 * V_7 )
{
struct V_275 V_276 = {
. V_277 = V_301 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_83 ,
. V_283 = 8 ,
. V_284 = V_285 ,
. V_286 . V_287 = F_31 ( V_7 ) ,
} ;
F_212 ( & V_276 . V_290 , F_175 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_207 ( & V_276 ) ;
}
static void F_213 ( struct V_6 * V_7 )
{
struct V_275 V_276 = {
. V_277 = V_302 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_83 ,
. V_283 = 96 ,
. V_284 = V_285 | V_292 ,
. V_286 . V_287 = F_31 ( V_7 ) ,
} ;
F_207 ( & V_276 ) ;
}
static struct V_4 * F_214 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_99 ( - V_100 ) ;
if ( V_5 -> V_44 . V_151 )
return F_99 ( - V_152 ) ;
if ( ! ( V_7 -> V_52 & V_54 ) )
F_211 ( V_7 ) ;
return V_5 ;
}
void F_215 ( struct V_6 * V_7 , T_3 * V_303 , int V_304 , bool V_305 )
{
struct V_306 * V_307 ;
V_194 V_169 ;
V_194 V_196 ;
int V_144 ;
struct V_4 * V_111 ;
struct V_98 * V_98 = F_31 ( V_7 ) ;
V_307 = (struct V_306 * ) V_303 ;
if ( V_304 < sizeof( struct V_306 ) ) {
F_35 ( ( L_20 ) ) ;
return;
}
V_144 = F_98 ( & V_307 -> V_172 ) ;
if ( V_144 & ( V_146 | V_308 ) )
return;
V_169 = F_216 ( V_307 -> V_309 ) ;
V_196 = F_216 ( V_307 -> V_310 ) ;
if ( V_196 > V_169 ) {
F_217 ( L_21 ) ;
return;
}
V_111 = F_218 ( V_7 ) ;
if ( V_111 == NULL ) {
F_219 ( L_22 ,
V_7 -> V_37 ) ;
return;
}
if ( V_307 -> V_165 ) {
struct V_142 * V_133 ;
unsigned long V_311 ;
if ( V_3 > V_312 )
V_311 = F_127 ( V_169 , V_3 ) ;
else
V_311 = F_127 ( V_169 , V_312 ) ;
if ( F_220 ( V_311 ) )
V_311 *= V_3 ;
V_133 = F_132 ( & V_307 -> V_172 ,
V_307 -> V_158 ,
V_7 ,
V_313 | V_314 ,
V_173 | V_174 ) ;
if ( V_133 ) {
if ( V_169 == 0 ) {
F_133 ( V_133 ) ;
V_133 = NULL ;
} else if ( F_220 ( V_311 ) ) {
F_134 ( V_133 , V_20 + V_311 ) ;
} else {
F_221 ( V_133 ) ;
}
} else if ( V_169 ) {
T_5 V_19 = 0 ;
int V_52 = V_313 | V_314 ;
if ( F_220 ( V_311 ) ) {
V_52 |= V_176 ;
V_19 = F_222 ( V_311 ) ;
}
F_206 ( & V_307 -> V_172 , V_307 -> V_158 ,
V_7 , V_19 , V_52 ) ;
}
F_88 ( V_133 ) ;
}
if ( V_307 -> V_315 && V_111 -> V_44 . V_315 ) {
struct V_8 * V_9 ;
struct V_138 V_136 ;
int V_316 = 0 , V_317 = 0 ;
if ( V_307 -> V_158 == 64 ) {
memcpy ( & V_136 , & V_307 -> V_172 , 8 ) ;
if ( F_176 ( V_136 . V_189 + 8 , V_7 ) &&
F_202 ( V_136 . V_189 + 8 , V_111 ) ) {
F_86 ( V_111 ) ;
return;
}
goto V_318;
}
F_219 ( L_23 ,
V_307 -> V_158 ) ;
F_86 ( V_111 ) ;
return;
V_318:
V_9 = F_169 ( V_98 , & V_136 , V_7 , 1 ) ;
if ( V_9 == NULL && V_169 ) {
int V_186 = V_111 -> V_44 . V_186 ;
T_1 V_187 = 0 ;
#ifdef F_223
if ( V_111 -> V_44 . V_319 &&
! V_98 -> V_23 . V_115 -> V_50 && V_305 )
V_187 = V_201 ;
#endif
if ( ! V_186 ||
F_139 ( V_111 ) < V_186 )
V_9 = F_97 ( V_111 , & V_136 , V_307 -> V_158 ,
V_144 & V_202 ,
V_187 ) ;
if ( F_140 ( V_9 ) ) {
F_86 ( V_111 ) ;
return;
}
V_317 = V_316 = 1 ;
V_9 -> V_1 = V_20 ;
F_141 ( V_9 ) ;
}
if ( V_9 ) {
int V_52 ;
unsigned long V_188 ;
#ifdef F_41
struct V_8 * V_177 ;
#endif
T_1 V_320 ;
F_101 ( & V_9 -> V_43 ) ;
V_188 = V_20 ;
if ( V_9 -> V_169 > ( V_188 - V_9 -> V_70 ) / V_3 )
V_320 = V_9 -> V_169 - ( V_188 - V_9 -> V_70 ) / V_3 ;
else
V_320 = 0 ;
if ( ! V_317 && V_320 ) {
if ( V_169 > V_321 ||
V_169 > V_320 )
V_317 = 1 ;
else if ( V_320 <= V_321 ) {
if ( V_196 != V_9 -> V_196 ) {
V_169 = V_320 ;
V_317 = 1 ;
}
} else {
V_169 = V_321 ;
if ( V_169 < V_196 )
V_196 = V_169 ;
V_317 = 1 ;
}
}
if ( V_317 ) {
V_9 -> V_169 = V_169 ;
V_9 -> V_196 = V_196 ;
V_9 -> V_70 = V_188 ;
V_52 = V_9 -> V_52 ;
V_9 -> V_52 &= ~ V_219 ;
F_110 ( & V_9 -> V_43 ) ;
if ( ! ( V_52 & V_121 ) )
F_130 ( 0 , V_9 ) ;
} else
F_110 ( & V_9 -> V_43 ) ;
#ifdef F_41
F_156 ( & V_111 -> V_43 ) ;
F_74 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_182 , V_322 , V_323 ;
if ( V_9 != V_177 -> V_166 )
continue;
V_182 = ( V_188 - V_177 -> V_1 ) / V_3 ;
V_322 = V_111 -> V_44 . V_195 - V_182 ;
if ( V_322 < 0 )
V_322 = 0 ;
V_323 = V_111 -> V_44 . V_197 -
V_111 -> V_44 . V_198 -
V_182 ;
if ( V_323 < 0 )
V_323 = 0 ;
if ( V_169 > V_322 )
V_169 = V_322 ;
if ( V_196 > V_323 )
V_196 = V_323 ;
F_101 ( & V_177 -> V_43 ) ;
V_52 = V_177 -> V_52 ;
V_177 -> V_169 = V_169 ;
V_177 -> V_196 = V_196 ;
V_177 -> V_70 = V_188 ;
if ( V_196 > 0 )
V_177 -> V_52 &= ~ V_219 ;
F_110 ( & V_177 -> V_43 ) ;
if ( ! ( V_52 & V_121 ) )
F_130 ( 0 , V_177 ) ;
}
if ( ( V_316 || F_21 ( & V_111 -> V_61 ) ) && V_111 -> V_44 . V_67 > 0 ) {
F_161 ( & V_111 -> V_43 ) ;
F_136 ( V_9 , NULL ) ;
} else {
F_161 ( & V_111 -> V_43 ) ;
}
#endif
F_123 ( V_9 ) ;
F_224 ( 0 ) ;
}
}
F_225 ( V_324 , V_111 , V_307 ) ;
F_86 ( V_111 ) ;
}
int F_226 ( struct V_98 * V_98 , void T_6 * V_106 )
{
struct V_325 V_326 ;
struct V_6 * V_7 ;
int V_99 = - V_113 ;
F_227 () ;
V_99 = - V_327 ;
if ( F_228 ( & V_326 , V_106 , sizeof( struct V_325 ) ) )
goto V_328;
V_7 = F_69 ( V_98 , V_326 . V_329 ) ;
V_99 = - V_149 ;
if ( V_7 == NULL )
goto V_328;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 ) {
const struct V_330 * V_331 = V_7 -> V_332 ;
struct V_333 V_334 ;
struct V_335 V_126 ;
V_99 = - V_148 ;
if ( ! ( F_98 ( & V_326 . V_336 ) & V_204 ) )
goto V_328;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_337 . V_234 = V_326 . V_336 . V_256 [ 3 ] ;
V_126 . V_337 . V_235 = 0 ;
V_126 . V_337 . V_338 = 4 ;
V_126 . V_337 . V_339 = 5 ;
V_126 . V_337 . V_340 = V_341 ;
V_126 . V_337 . V_342 = 64 ;
V_334 . V_343 . V_344 = ( V_345 void T_6 * ) & V_126 ;
if ( V_331 -> V_346 ) {
T_7 V_347 = F_229 () ;
F_230 ( V_348 ) ;
V_99 = V_331 -> V_346 ( V_7 , & V_334 , V_349 ) ;
F_230 ( V_347 ) ;
} else
V_99 = - V_350 ;
if ( V_99 == 0 ) {
V_99 = - V_100 ;
V_7 = F_231 ( V_98 , V_126 . V_37 ) ;
if ( ! V_7 )
goto V_328;
V_99 = F_232 ( V_7 ) ;
}
}
#endif
V_328:
F_82 () ;
return V_99 ;
}
static int F_233 ( struct V_98 * V_98 , int V_83 , const struct V_138 * V_273 ,
unsigned int V_274 , T_8 V_351 , V_194 V_196 ,
V_194 V_169 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_141 ;
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_352 ;
F_28 () ;
if ( V_274 > 128 )
return - V_113 ;
if ( ! V_169 || V_196 > V_169 )
return - V_113 ;
V_7 = F_69 ( V_98 , V_83 ) ;
if ( ! V_7 )
return - V_149 ;
V_5 = F_214 ( V_7 ) ;
if ( F_104 ( V_5 ) )
return F_105 ( V_5 ) ;
V_141 = F_234 ( V_273 ) ;
V_352 = F_127 ( V_169 , V_3 ) ;
if ( F_220 ( V_352 ) ) {
V_19 = F_222 ( V_352 * V_3 ) ;
V_169 = V_352 ;
V_52 = V_176 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_351 |= V_167 ;
}
V_352 = F_127 ( V_196 , V_3 ) ;
if ( F_220 ( V_352 ) ) {
if ( V_352 == 0 )
V_351 |= V_219 ;
V_196 = V_352 ;
}
V_9 = F_97 ( V_5 , V_273 , V_274 , V_141 , V_351 ) ;
if ( ! F_104 ( V_9 ) ) {
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_169 = V_169 ;
V_9 -> V_196 = V_196 ;
V_9 -> V_70 = V_20 ;
F_119 ( & V_9 -> V_43 ) ;
F_206 ( & V_9 -> V_136 , V_9 -> V_158 , V_7 ,
V_19 , V_52 ) ;
F_141 ( V_9 ) ;
F_123 ( V_9 ) ;
F_224 ( 0 ) ;
return 0 ;
}
return F_105 ( V_9 ) ;
}
static int F_235 ( struct V_98 * V_98 , int V_83 , const struct V_138 * V_273 ,
unsigned int V_274 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_274 > 128 )
return - V_113 ;
V_7 = F_69 ( V_98 , V_83 ) ;
if ( ! V_7 )
return - V_149 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_353 ;
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_158 == V_274 &&
F_145 ( V_273 , & V_9 -> V_136 ) ) {
F_10 ( V_9 ) ;
F_161 ( & V_5 -> V_43 ) ;
F_117 ( V_9 ) ;
if ( F_21 ( & V_5 -> V_34 ) )
F_236 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_161 ( & V_5 -> V_43 ) ;
return - V_148 ;
}
int F_237 ( struct V_98 * V_98 , void T_6 * V_106 )
{
struct V_325 V_326 ;
int V_99 ;
if ( ! F_238 ( V_98 -> V_354 , V_355 ) )
return - V_356 ;
if ( F_228 ( & V_326 , V_106 , sizeof( struct V_325 ) ) )
return - V_327 ;
F_227 () ;
V_99 = F_233 ( V_98 , V_326 . V_329 , & V_326 . V_336 ,
V_326 . V_357 , V_167 ,
V_358 , V_358 ) ;
F_82 () ;
return V_99 ;
}
int F_239 ( struct V_98 * V_98 , void T_6 * V_106 )
{
struct V_325 V_326 ;
int V_99 ;
if ( ! F_238 ( V_98 -> V_354 , V_355 ) )
return - V_356 ;
if ( F_228 ( & V_326 , V_106 , sizeof( struct V_325 ) ) )
return - V_327 ;
F_227 () ;
V_99 = F_235 ( V_98 , V_326 . V_329 , & V_326 . V_336 ,
V_326 . V_357 ) ;
F_82 () ;
return V_99 ;
}
static void F_240 ( struct V_4 * V_5 , const struct V_138 * V_136 ,
int V_274 , int V_141 )
{
struct V_8 * V_9 ;
V_9 = F_97 ( V_5 , V_136 , V_274 , V_141 , V_167 ) ;
if ( ! F_104 ( V_9 ) ) {
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_52 &= ~ V_121 ;
F_119 ( & V_9 -> V_43 ) ;
F_130 ( V_359 , V_9 ) ;
F_123 ( V_9 ) ;
}
}
static void F_241 ( struct V_4 * V_5 )
{
struct V_138 V_136 ;
struct V_6 * V_7 ;
struct V_98 * V_98 = F_31 ( V_5 -> V_7 ) ;
int V_141 ;
F_28 () ;
memset ( & V_136 , 0 , sizeof( struct V_138 ) ) ;
memcpy ( & V_136 . V_256 [ 3 ] , V_5 -> V_7 -> V_261 , 4 ) ;
if ( V_5 -> V_7 -> V_52 & V_291 ) {
V_136 . V_256 [ 0 ] = F_175 ( 0xfe800000 ) ;
V_141 = V_246 ;
} else {
V_141 = V_204 ;
}
if ( V_136 . V_256 [ 3 ] ) {
F_240 ( V_5 , & V_136 , 128 , V_141 ) ;
return;
}
F_78 (net, dev) {
struct V_360 * V_361 = F_242 ( V_7 ) ;
if ( V_361 && ( V_7 -> V_52 & V_76 ) ) {
struct V_362 * V_118 ;
int V_363 = V_141 ;
for ( V_118 = V_361 -> V_364 ; V_118 ; V_118 = V_118 -> V_365 ) {
int V_274 ;
V_136 . V_256 [ 3 ] = V_118 -> V_366 ;
if ( V_118 -> V_367 == V_368 )
continue;
if ( V_118 -> V_367 >= V_369 ) {
if ( V_5 -> V_7 -> V_52 & V_291 )
continue;
V_363 |= V_249 ;
}
if ( V_5 -> V_7 -> V_52 & V_291 )
V_274 = 64 ;
else
V_274 = 96 ;
F_240 ( V_5 , & V_136 , V_274 , V_363 ) ;
}
}
}
}
static void F_243 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_370 ;
struct V_8 * V_371 ;
struct V_142 * V_372 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_240 ( V_5 , & V_373 , 128 , V_249 ) ;
F_78 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_370 -> V_37 , V_7 -> V_37 ) )
continue;
V_5 = F_48 ( V_370 ) ;
if ( ! V_5 )
continue;
F_156 ( & V_5 -> V_43 ) ;
F_74 (sp_ifa, &idev->addr_list, if_list) {
if ( V_371 -> V_52 & ( V_252 | V_121 ) )
continue;
V_372 = F_103 ( V_5 , & V_371 -> V_136 , 0 ) ;
if ( ! F_104 ( V_372 ) )
F_244 ( V_372 ) ;
}
F_161 ( & V_5 -> V_43 ) ;
}
}
static void F_245 ( struct V_4 * V_5 , const struct V_138 * V_136 )
{
struct V_8 * V_9 ;
T_1 V_187 = V_167 ;
#ifdef F_223
if ( V_5 -> V_44 . V_319 &&
! F_31 ( V_5 -> V_7 ) -> V_23 . V_115 -> V_50 )
V_187 |= V_201 ;
#endif
V_9 = F_97 ( V_5 , V_136 , 64 , V_246 , V_187 ) ;
if ( ! F_104 ( V_9 ) ) {
F_206 ( & V_9 -> V_136 , V_9 -> V_158 , V_5 -> V_7 , 0 , 0 ) ;
F_141 ( V_9 ) ;
F_123 ( V_9 ) ;
}
}
static void F_246 ( struct V_6 * V_7 )
{
struct V_138 V_136 ;
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_7 -> type != V_266 ) &&
( V_7 -> type != V_267 ) &&
( V_7 -> type != V_268 ) &&
( V_7 -> type != V_269 ) &&
( V_7 -> type != V_271 ) ) {
return;
}
V_5 = F_214 ( V_7 ) ;
if ( F_104 ( V_5 ) )
return;
memset ( & V_136 , 0 , sizeof( struct V_138 ) ) ;
V_136 . V_256 [ 0 ] = F_175 ( 0xFE800000 ) ;
if ( F_176 ( V_136 . V_189 + 8 , V_7 ) == 0 )
F_245 ( V_5 , & V_136 ) ;
}
static void F_247 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
if ( V_7 -> V_58 & V_59 ) {
struct V_138 V_136 ;
F_212 ( & V_136 , F_175 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_206 ( & V_136 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_176 ( V_136 . V_189 + 8 , V_7 ) )
F_245 ( V_5 , & V_136 ) ;
return;
}
F_241 ( V_5 ) ;
if ( V_7 -> V_52 & V_291 )
F_211 ( V_7 ) ;
else
F_213 ( V_7 ) ;
}
static void F_248 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_138 V_136 ;
F_40 ( L_25 , V_36 , V_7 -> V_37 ) ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_212 ( & V_136 , F_175 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_206 ( & V_136 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_176 ( V_136 . V_189 + 8 , V_7 ) )
F_245 ( V_5 , & V_136 ) ;
}
static inline int
F_249 ( struct V_4 * V_5 , struct V_6 * V_374 )
{
struct V_138 V_375 ;
if ( ! F_163 ( V_374 , & V_375 , V_121 ) ) {
F_245 ( V_5 , & V_375 ) ;
return 0 ;
}
return - 1 ;
}
static void F_250 ( struct V_4 * V_5 )
{
struct V_6 * V_374 ;
struct V_98 * V_98 = F_31 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_376 &&
( V_374 = F_69 ( V_98 , V_5 -> V_7 -> V_376 ) ) ) {
if ( ! F_249 ( V_5 , V_374 ) )
return;
}
F_78 (net, link_dev) {
if ( ! F_249 ( V_5 , V_374 ) )
return;
}
F_23 ( L_26 ) ;
}
static void F_251 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_214 ( V_7 ) ;
if ( F_104 ( V_5 ) ) {
F_23 ( L_27 ) ;
return;
}
F_250 ( V_5 ) ;
}
static int F_252 ( struct V_377 * V_378 , unsigned long V_88 ,
void * V_157 )
{
struct V_6 * V_7 = (struct V_6 * ) V_157 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_379 = 0 ;
int V_99 ;
switch ( V_88 ) {
case V_380 :
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( ! V_5 )
return F_253 ( - V_33 ) ;
}
break;
case V_162 :
case V_381 :
if ( V_7 -> V_52 & V_382 )
break;
if ( V_88 == V_162 ) {
if ( ! F_4 ( V_7 ) ) {
F_40 ( L_28 ,
V_7 -> V_37 ) ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 )
V_5 = F_27 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_68 |= V_69 ;
V_379 = 1 ;
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
V_379 = 1 ;
}
switch ( V_7 -> type ) {
#if F_39 ( V_56 )
case V_57 :
F_247 ( V_7 ) ;
break;
#endif
#if F_39 ( V_383 )
case V_270 :
F_248 ( V_7 ) ;
break;
#endif
case V_65 :
F_251 ( V_7 ) ;
break;
case V_384 :
F_243 ( V_7 ) ;
break;
default:
F_246 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_379 )
F_254 ( V_5 ) ;
if ( V_5 -> V_44 . V_46 != V_7 -> V_41 &&
V_7 -> V_41 >= V_42 ) {
F_255 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
}
V_5 -> V_70 = V_20 ;
F_256 ( V_385 , V_5 ) ;
if ( V_7 -> V_41 < V_42 )
F_236 ( V_7 , 1 ) ;
}
break;
case V_386 :
if ( V_5 && V_7 -> V_41 >= V_42 ) {
F_255 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( V_5 )
break;
}
case V_171 :
case V_387 :
F_236 ( V_7 , V_88 != V_171 ) ;
break;
case V_388 :
if ( V_5 ) {
F_257 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_99 = F_37 ( V_5 ) ;
if ( V_99 )
return F_253 ( V_99 ) ;
}
break;
case V_389 :
case V_390 :
F_258 ( V_7 , V_88 ) ;
break;
}
return V_391 ;
}
static void F_258 ( struct V_6 * V_7 , unsigned long V_88 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_88 == V_390 )
F_259 ( V_5 ) ;
else if ( V_88 == V_389 )
F_260 ( V_5 ) ;
}
static int F_236 ( struct V_6 * V_7 , int V_392 )
{
struct V_98 * V_98 = F_31 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_8 * V_118 ;
int V_131 , V_209 ;
F_28 () ;
F_261 ( V_98 , V_7 ) ;
F_262 ( & V_49 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_149 ;
if ( V_392 ) {
V_5 -> V_38 = 1 ;
F_263 ( V_7 -> V_71 , NULL ) ;
F_257 ( V_5 ) ;
}
for ( V_209 = 0 ; V_209 < V_393 ; V_209 ++ ) {
struct V_394 * V_395 = & V_159 [ V_209 ] ;
F_118 ( & V_153 ) ;
V_396:
F_165 (ifa, h, addr_lst) {
if ( V_118 -> V_5 == V_5 ) {
F_120 ( & V_118 -> V_130 ) ;
F_6 ( V_118 ) ;
goto V_396;
}
}
F_119 ( & V_153 ) ;
}
F_121 ( & V_5 -> V_43 ) ;
if ( ! V_392 )
V_5 -> V_68 &= ~ ( V_397 | V_398 | V_69 ) ;
#ifdef F_41
if ( V_392 && F_7 ( & V_5 -> V_62 ) )
F_86 ( V_5 ) ;
while ( ! F_21 ( & V_5 -> V_61 ) ) {
V_118 = F_264 ( & V_5 -> V_61 ,
struct V_8 , V_161 ) ;
F_122 ( & V_118 -> V_161 ) ;
F_129 ( & V_5 -> V_43 ) ;
F_118 ( & V_118 -> V_43 ) ;
if ( V_118 -> V_166 ) {
F_123 ( V_118 -> V_166 ) ;
V_118 -> V_166 = NULL ;
}
F_119 ( & V_118 -> V_43 ) ;
F_123 ( V_118 ) ;
F_121 ( & V_5 -> V_43 ) ;
}
#endif
while ( ! F_21 ( & V_5 -> V_34 ) ) {
V_118 = F_264 ( & V_5 -> V_34 ,
struct V_8 , V_137 ) ;
F_6 ( V_118 ) ;
F_122 ( & V_118 -> V_137 ) ;
F_129 ( & V_5 -> V_43 ) ;
F_118 ( & V_118 -> V_156 ) ;
V_131 = V_118 -> V_131 ;
V_118 -> V_131 = V_132 ;
F_119 ( & V_118 -> V_156 ) ;
if ( V_131 != V_132 ) {
F_265 ( V_170 , V_118 ) ;
F_116 ( V_171 , V_118 ) ;
}
F_123 ( V_118 ) ;
F_121 ( & V_5 -> V_43 ) ;
}
F_129 ( & V_5 -> V_43 ) ;
if ( V_392 )
F_266 ( V_5 ) ;
else
F_267 ( V_5 ) ;
V_5 -> V_70 = V_20 ;
if ( V_392 ) {
F_3 ( V_5 ) ;
F_36 ( & V_49 , V_5 -> V_48 ) ;
F_262 ( & V_49 , V_7 ) ;
F_86 ( V_5 ) ;
}
return 0 ;
}
static void V_18 ( unsigned long V_157 )
{
struct V_8 * V_9 = (struct V_8 * ) V_157 ;
struct V_4 * V_5 = V_9 -> V_5 ;
F_268 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_68 & V_69 ) )
goto V_155;
if ( ! F_269 ( V_5 ) )
goto V_155;
if ( V_5 -> V_68 & V_398 )
goto V_155;
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_399 ++ < V_5 -> V_44 . V_60 ) {
F_9 ( V_9 , V_17 ,
( V_9 -> V_399 == V_5 -> V_44 . V_60 ) ?
V_5 -> V_44 . V_400 :
V_5 -> V_44 . V_401 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_270 ( V_5 -> V_7 , & V_9 -> V_136 , & V_75 ) ;
} else {
F_110 ( & V_9 -> V_43 ) ;
F_23 ( L_30 , V_5 -> V_7 -> V_37 ) ;
}
V_155:
F_271 ( & V_5 -> V_43 ) ;
F_123 ( V_9 ) ;
}
static void F_272 ( struct V_8 * V_9 )
{
unsigned long V_402 ;
struct V_4 * V_5 = V_9 -> V_5 ;
if ( V_9 -> V_52 & V_201 )
V_402 = 0 ;
else
V_402 = F_273 () % ( V_5 -> V_44 . V_400 ? : 1 ) ;
V_9 -> V_399 = V_5 -> V_44 . V_199 ;
F_9 ( V_9 , V_14 , V_402 ) ;
}
static void F_141 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_177 ( V_7 , & V_9 -> V_136 ) ;
F_274 ( V_9 -> V_136 . V_256 [ 3 ] ) ;
F_156 ( & V_5 -> V_43 ) ;
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_131 == V_132 )
goto V_155;
if ( V_7 -> V_52 & ( V_53 | V_54 ) ||
V_5 -> V_44 . V_55 < 1 ||
! ( V_9 -> V_52 & V_121 ) ||
V_9 -> V_52 & V_403 ) {
V_9 -> V_52 &= ~ ( V_121 | V_201 | V_252 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_161 ( & V_5 -> V_43 ) ;
F_275 ( V_9 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_110 ( & V_9 -> V_43 ) ;
F_161 ( & V_5 -> V_43 ) ;
F_10 ( V_9 ) ;
F_171 ( V_9 , 0 ) ;
return;
}
if ( V_9 -> V_52 & V_201 )
F_244 ( V_9 -> V_133 ) ;
F_272 ( V_9 ) ;
V_155:
F_110 ( & V_9 -> V_43 ) ;
F_161 ( & V_5 -> V_43 ) ;
}
static void V_16 ( unsigned long V_157 )
{
struct V_8 * V_9 = (struct V_8 * ) V_157 ;
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_138 V_404 ;
if ( ! V_9 -> V_399 && F_172 ( V_9 ) )
goto V_155;
F_268 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_68 & V_69 ) ) {
F_271 ( & V_5 -> V_43 ) ;
goto V_155;
}
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_131 == V_132 ) {
F_110 ( & V_9 -> V_43 ) ;
F_271 ( & V_5 -> V_43 ) ;
goto V_155;
}
if ( V_9 -> V_399 == 0 ) {
V_9 -> V_52 &= ~ ( V_121 | V_201 | V_252 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_271 ( & V_5 -> V_43 ) ;
F_275 ( V_9 ) ;
goto V_155;
}
V_9 -> V_399 -- ;
F_9 ( V_9 , V_14 , V_9 -> V_5 -> V_48 -> V_200 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_271 ( & V_5 -> V_43 ) ;
F_178 ( & V_9 -> V_136 , & V_404 ) ;
F_276 ( V_9 -> V_5 -> V_7 , NULL , & V_9 -> V_136 , & V_404 , & V_405 ) ;
V_155:
F_123 ( V_9 ) ;
}
static void F_275 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_5 -> V_7 ;
F_130 ( V_359 , V_9 ) ;
if ( F_269 ( V_9 -> V_5 ) &&
V_9 -> V_5 -> V_44 . V_60 > 0 &&
( V_7 -> V_52 & V_54 ) == 0 &&
( F_98 ( & V_9 -> V_136 ) & V_308 ) ) {
F_270 ( V_9 -> V_5 -> V_7 , & V_9 -> V_136 , & V_75 ) ;
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_399 = 1 ;
V_9 -> V_5 -> V_68 |= V_397 ;
F_9 ( V_9 , V_17 , V_9 -> V_5 -> V_44 . V_401 ) ;
F_119 ( & V_9 -> V_43 ) ;
}
}
static void F_254 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
F_156 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_52 & V_121 &&
V_9 -> V_131 == V_254 )
F_272 ( V_9 ) ;
F_110 ( & V_9 -> V_43 ) ;
}
F_161 ( & V_5 -> V_43 ) ;
}
static struct V_8 * F_277 ( struct V_406 * V_87 , T_9 V_407 )
{
struct V_8 * V_118 = NULL ;
struct V_408 * V_131 = V_87 -> V_409 ;
struct V_98 * V_98 = F_278 ( V_87 ) ;
int V_126 = 0 ;
if ( V_407 == 0 ) {
V_131 -> V_410 = 0 ;
V_131 -> V_411 = 0 ;
}
for (; V_131 -> V_410 < V_393 ; ++ V_131 -> V_410 ) {
F_170 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_166 ( F_31 ( V_118 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( V_126 < V_131 -> V_411 ) {
V_126 ++ ;
continue;
}
V_131 -> V_411 ++ ;
return V_118 ;
}
V_131 -> V_411 = 0 ;
V_126 = 0 ;
}
return NULL ;
}
static struct V_8 * F_279 ( struct V_406 * V_87 ,
struct V_8 * V_118 )
{
struct V_408 * V_131 = V_87 -> V_409 ;
struct V_98 * V_98 = F_278 ( V_87 ) ;
F_280 (ifa, addr_lst) {
if ( ! F_166 ( F_31 ( V_118 -> V_5 -> V_7 ) , V_98 ) )
continue;
V_131 -> V_411 ++ ;
return V_118 ;
}
while ( ++ V_131 -> V_410 < V_393 ) {
V_131 -> V_411 = 0 ;
F_170 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_166 ( F_31 ( V_118 -> V_5 -> V_7 ) , V_98 ) )
continue;
V_131 -> V_411 ++ ;
return V_118 ;
}
}
return NULL ;
}
static void * F_281 ( struct V_406 * V_87 , T_9 * V_407 )
__acquires( T_10 )
{
F_100 () ;
return F_277 ( V_87 , * V_407 ) ;
}
static void * F_282 ( struct V_406 * V_87 , void * V_412 , T_9 * V_407 )
{
struct V_8 * V_118 ;
V_118 = F_279 ( V_87 , V_412 ) ;
++ * V_407 ;
return V_118 ;
}
static void F_283 ( struct V_406 * V_87 , void * V_412 )
__releases( T_10 )
{
F_114 () ;
}
static int F_284 ( struct V_406 * V_87 , void * V_412 )
{
struct V_8 * V_9 = (struct V_8 * ) V_412 ;
F_285 ( V_87 , L_31 ,
& V_9 -> V_136 ,
V_9 -> V_5 -> V_7 -> V_83 ,
V_9 -> V_158 ,
V_9 -> V_141 ,
V_9 -> V_52 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
return 0 ;
}
static int F_286 ( struct V_413 * V_413 , struct V_414 * V_414 )
{
return F_287 ( V_413 , V_414 , & V_415 ,
sizeof( struct V_408 ) ) ;
}
static int T_11 F_288 ( struct V_98 * V_98 )
{
if ( ! F_289 ( L_32 , V_416 , V_98 -> V_417 , & V_418 ) )
return - V_33 ;
return 0 ;
}
static void T_12 F_290 ( struct V_98 * V_98 )
{
F_291 ( L_32 , V_98 -> V_417 ) ;
}
int T_13 F_292 ( void )
{
return F_293 ( & V_419 ) ;
}
void F_294 ( void )
{
F_295 ( & V_419 ) ;
}
int F_296 ( struct V_98 * V_98 , const struct V_138 * V_136 )
{
int V_185 = 0 ;
struct V_8 * V_9 = NULL ;
unsigned int V_143 = F_94 ( V_136 ) ;
F_100 () ;
F_170 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_166 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_145 ( & V_9 -> V_136 , V_136 ) &&
( V_9 -> V_52 & V_224 ) ) {
V_185 = 1 ;
break;
}
}
F_114 () ;
return V_185 ;
}
static void F_224 ( unsigned long V_420 )
{
unsigned long V_188 , V_421 , V_422 , V_423 ;
struct V_8 * V_9 ;
int V_209 ;
F_100 () ;
F_101 ( & V_424 ) ;
V_188 = V_20 ;
V_421 = F_297 ( V_188 + V_425 ) ;
F_7 ( & V_426 ) ;
for ( V_209 = 0 ; V_209 < V_393 ; V_209 ++ ) {
V_396:
F_170 (ifp,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_182 ;
if ( V_9 -> V_52 & V_167 )
continue;
F_101 ( & V_9 -> V_43 ) ;
V_182 = ( V_188 - V_9 -> V_70 + V_427 ) / V_3 ;
if ( V_9 -> V_169 != V_358 &&
V_182 >= V_9 -> V_169 ) {
F_110 ( & V_9 -> V_43 ) ;
F_10 ( V_9 ) ;
F_117 ( V_9 ) ;
goto V_396;
} else if ( V_9 -> V_196 == V_358 ) {
F_110 ( & V_9 -> V_43 ) ;
continue;
} else if ( V_182 >= V_9 -> V_196 ) {
int V_428 = 0 ;
if ( ! ( V_9 -> V_52 & V_219 ) ) {
V_428 = 1 ;
V_9 -> V_52 |= V_219 ;
}
if ( F_128 ( V_9 -> V_70 + V_9 -> V_169 * V_3 , V_421 ) )
V_421 = V_9 -> V_70 + V_9 -> V_169 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
if ( V_428 ) {
F_10 ( V_9 ) ;
F_130 ( 0 , V_9 ) ;
F_123 ( V_9 ) ;
goto V_396;
}
#ifdef F_41
} else if ( ( V_9 -> V_52 & V_160 ) &&
! ( V_9 -> V_52 & V_121 ) ) {
unsigned long V_183 = V_9 -> V_5 -> V_44 . V_192 *
V_9 -> V_5 -> V_44 . V_199 *
V_9 -> V_5 -> V_48 -> V_200 / V_3 ;
if ( V_182 >= V_9 -> V_196 - V_183 ) {
struct V_8 * V_166 = V_9 -> V_166 ;
if ( F_128 ( V_9 -> V_70 + V_9 -> V_196 * V_3 , V_421 ) )
V_421 = V_9 -> V_70 + V_9 -> V_196 * V_3 ;
if ( ! V_9 -> V_191 && V_166 ) {
V_9 -> V_191 ++ ;
F_10 ( V_9 ) ;
F_10 ( V_166 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_101 ( & V_166 -> V_43 ) ;
V_166 -> V_191 = 0 ;
F_110 ( & V_166 -> V_43 ) ;
F_136 ( V_166 , V_9 ) ;
F_123 ( V_166 ) ;
F_123 ( V_9 ) ;
goto V_396;
}
} else if ( F_128 ( V_9 -> V_70 + V_9 -> V_196 * V_3 - V_183 * V_3 , V_421 ) )
V_421 = V_9 -> V_70 + V_9 -> V_196 * V_3 - V_183 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
#endif
} else {
if ( F_128 ( V_9 -> V_70 + V_9 -> V_196 * V_3 , V_421 ) )
V_421 = V_9 -> V_70 + V_9 -> V_196 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
}
}
}
V_422 = F_297 ( V_421 ) ;
V_423 = V_421 ;
if ( F_128 ( V_422 , V_421 + V_429 ) )
V_423 = V_422 ;
if ( F_128 ( V_423 , V_20 + V_430 ) )
V_423 = V_20 + V_430 ;
F_35 ( ( V_240 L_33 ,
V_188 , V_421 , V_422 , V_423 ) ) ;
V_426 . V_19 = V_423 ;
F_11 ( & V_426 ) ;
F_110 ( & V_424 ) ;
F_114 () ;
}
static struct V_138 * F_298 ( struct V_108 * V_136 , struct V_108 * V_431 )
{
struct V_138 * V_273 = NULL ;
if ( V_136 )
V_273 = F_299 ( V_136 ) ;
if ( V_431 ) {
if ( V_273 && F_300 ( V_431 , V_273 , sizeof( * V_273 ) ) )
V_273 = NULL ;
else
V_273 = F_299 ( V_431 ) ;
}
return V_273 ;
}
static int
F_301 ( struct V_81 * V_82 , struct V_89 * V_90 , void * V_106 )
{
struct V_98 * V_98 = F_66 ( V_82 -> V_107 ) ;
struct V_432 * V_433 ;
struct V_108 * V_109 [ V_434 + 1 ] ;
struct V_138 * V_273 ;
int V_99 ;
V_99 = F_67 ( V_90 , sizeof( * V_433 ) , V_109 , V_434 , V_435 ) ;
if ( V_99 < 0 )
return V_99 ;
V_433 = F_56 ( V_90 ) ;
V_273 = F_298 ( V_109 [ V_436 ] , V_109 [ V_437 ] ) ;
if ( V_273 == NULL )
return - V_113 ;
return F_235 ( V_98 , V_433 -> V_438 , V_273 , V_433 -> V_439 ) ;
}
static int F_302 ( struct V_8 * V_9 , T_3 V_351 ,
T_1 V_196 , T_1 V_169 )
{
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_352 ;
if ( ! V_169 || ( V_196 > V_169 ) )
return - V_113 ;
V_352 = F_127 ( V_169 , V_3 ) ;
if ( F_220 ( V_352 ) ) {
V_19 = F_222 ( V_352 * V_3 ) ;
V_169 = V_352 ;
V_52 = V_176 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_351 |= V_167 ;
}
V_352 = F_127 ( V_196 , V_3 ) ;
if ( F_220 ( V_352 ) ) {
if ( V_352 == 0 )
V_351 |= V_219 ;
V_196 = V_352 ;
}
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_52 = ( V_9 -> V_52 & ~ ( V_219 | V_167 | V_403 | V_224 ) ) | V_351 ;
V_9 -> V_70 = V_20 ;
V_9 -> V_169 = V_169 ;
V_9 -> V_196 = V_196 ;
F_119 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_52 & V_121 ) )
F_130 ( 0 , V_9 ) ;
F_206 ( & V_9 -> V_136 , V_9 -> V_158 , V_9 -> V_5 -> V_7 ,
V_19 , V_52 ) ;
F_224 ( 0 ) ;
return 0 ;
}
static int
F_303 ( struct V_81 * V_82 , struct V_89 * V_90 , void * V_106 )
{
struct V_98 * V_98 = F_66 ( V_82 -> V_107 ) ;
struct V_432 * V_433 ;
struct V_108 * V_109 [ V_434 + 1 ] ;
struct V_138 * V_273 ;
struct V_8 * V_118 ;
struct V_6 * V_7 ;
T_1 V_169 = V_358 , V_440 = V_358 ;
T_3 V_351 ;
int V_99 ;
V_99 = F_67 ( V_90 , sizeof( * V_433 ) , V_109 , V_434 , V_435 ) ;
if ( V_99 < 0 )
return V_99 ;
V_433 = F_56 ( V_90 ) ;
V_273 = F_298 ( V_109 [ V_436 ] , V_109 [ V_437 ] ) ;
if ( V_273 == NULL )
return - V_113 ;
if ( V_109 [ V_441 ] ) {
struct V_442 * V_443 ;
V_443 = F_299 ( V_109 [ V_441 ] ) ;
V_169 = V_443 -> V_444 ;
V_440 = V_443 -> V_445 ;
} else {
V_440 = V_358 ;
V_169 = V_358 ;
}
V_7 = F_69 ( V_98 , V_433 -> V_438 ) ;
if ( V_7 == NULL )
return - V_149 ;
V_351 = V_433 -> V_351 & ( V_403 | V_224 ) ;
V_118 = F_169 ( V_98 , V_273 , V_7 , 1 ) ;
if ( V_118 == NULL ) {
return F_233 ( V_98 , V_433 -> V_438 , V_273 ,
V_433 -> V_439 , V_351 ,
V_440 , V_169 ) ;
}
if ( V_90 -> V_446 & V_447 ||
! ( V_90 -> V_446 & V_448 ) )
V_99 = - V_154 ;
else
V_99 = F_302 ( V_118 , V_351 , V_440 , V_169 ) ;
F_123 ( V_118 ) ;
return V_99 ;
}
static void F_304 ( struct V_89 * V_90 , T_3 V_449 , T_3 V_52 ,
T_3 V_141 , int V_83 )
{
struct V_432 * V_433 ;
V_433 = F_56 ( V_90 ) ;
V_433 -> V_450 = V_94 ;
V_433 -> V_439 = V_449 ;
V_433 -> V_351 = V_52 ;
V_433 -> V_367 = V_141 ;
V_433 -> V_438 = V_83 ;
}
static int F_305 ( struct V_81 * V_82 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_451 , T_1 V_309 )
{
struct V_442 V_443 ;
V_443 . V_1 = F_1 ( V_1 ) ;
V_443 . V_70 = F_1 ( V_70 ) ;
V_443 . V_445 = V_451 ;
V_443 . V_444 = V_309 ;
return F_306 ( V_82 , V_441 , sizeof( V_443 ) , & V_443 ) ;
}
static inline int F_307 ( int V_367 )
{
if ( V_367 & V_249 )
return V_369 ;
else if ( V_367 & V_246 )
return V_368 ;
else if ( V_367 & V_452 )
return V_453 ;
else
return V_454 ;
}
static inline int F_308 ( void )
{
return F_51 ( sizeof( struct V_432 ) )
+ F_52 ( 16 )
+ F_52 ( sizeof( struct V_442 ) ) ;
}
static int F_309 ( struct V_81 * V_82 , struct V_8 * V_118 ,
T_1 V_86 , T_1 V_87 , int V_88 , unsigned int V_52 )
{
struct V_89 * V_90 ;
T_1 V_451 , V_309 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( struct V_432 ) , V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
F_304 ( V_90 , V_118 -> V_158 , V_118 -> V_52 , F_307 ( V_118 -> V_141 ) ,
V_118 -> V_5 -> V_7 -> V_83 ) ;
if ( ! ( V_118 -> V_52 & V_167 ) ) {
V_451 = V_118 -> V_196 ;
V_309 = V_118 -> V_169 ;
if ( V_451 != V_358 ) {
long V_455 = ( V_20 - V_118 -> V_70 ) / V_3 ;
if ( V_451 > V_455 )
V_451 -= V_455 ;
else
V_451 = 0 ;
if ( V_309 != V_358 ) {
if ( V_309 > V_455 )
V_309 -= V_455 ;
else
V_309 = 0 ;
}
}
} else {
V_451 = V_358 ;
V_309 = V_358 ;
}
if ( F_306 ( V_82 , V_436 , 16 , & V_118 -> V_136 ) < 0 ||
F_305 ( V_82 , V_118 -> V_1 , V_118 -> V_70 , V_451 , V_309 ) < 0 ) {
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
return F_58 ( V_82 , V_90 ) ;
}
static int F_310 ( struct V_81 * V_82 , struct V_456 * V_457 ,
T_1 V_86 , T_1 V_87 , int V_88 , T_14 V_52 )
{
struct V_89 * V_90 ;
T_3 V_141 = V_454 ;
int V_83 = V_457 -> V_5 -> V_7 -> V_83 ;
if ( F_234 ( & V_457 -> V_458 ) & V_452 )
V_141 = V_453 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( struct V_432 ) , V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
F_304 ( V_90 , 128 , V_167 , V_141 , V_83 ) ;
if ( F_306 ( V_82 , V_459 , 16 , & V_457 -> V_458 ) < 0 ||
F_305 ( V_82 , V_457 -> V_460 , V_457 -> V_461 ,
V_358 , V_358 ) < 0 ) {
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
return F_58 ( V_82 , V_90 ) ;
}
static int F_311 ( struct V_81 * V_82 , struct V_462 * V_463 ,
T_1 V_86 , T_1 V_87 , int V_88 , unsigned int V_52 )
{
struct V_89 * V_90 ;
T_3 V_141 = V_454 ;
int V_83 = V_463 -> V_464 -> V_7 -> V_83 ;
if ( F_234 ( & V_463 -> V_465 ) & V_452 )
V_141 = V_453 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( struct V_432 ) , V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
F_304 ( V_90 , 128 , V_167 , V_141 , V_83 ) ;
if ( F_306 ( V_82 , V_466 , 16 , & V_463 -> V_465 ) < 0 ||
F_305 ( V_82 , V_463 -> V_467 , V_463 -> V_468 ,
V_358 , V_358 ) < 0 ) {
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
return F_58 ( V_82 , V_90 ) ;
}
static int F_312 ( struct V_4 * V_5 , struct V_81 * V_82 ,
struct V_469 * V_470 , enum V_471 type ,
int V_472 , int * V_473 )
{
struct V_456 * V_457 ;
struct V_462 * V_463 ;
int V_99 = 1 ;
int V_474 = * V_473 ;
F_156 ( & V_5 -> V_43 ) ;
switch ( type ) {
case V_475 : {
struct V_8 * V_118 ;
F_74 (ifa, &idev->addr_list, if_list) {
if ( ++ V_474 < V_472 )
continue;
V_99 = F_309 ( V_82 , V_118 ,
F_70 ( V_470 -> V_82 ) . V_86 ,
V_470 -> V_90 -> V_117 ,
V_359 ,
V_476 ) ;
if ( V_99 <= 0 )
break;
}
break;
}
case V_477 :
for ( V_457 = V_5 -> V_35 ; V_457 ;
V_457 = V_457 -> V_421 , V_474 ++ ) {
if ( V_474 < V_472 )
continue;
V_99 = F_310 ( V_82 , V_457 ,
F_70 ( V_470 -> V_82 ) . V_86 ,
V_470 -> V_90 -> V_117 ,
V_478 ,
V_476 ) ;
if ( V_99 <= 0 )
break;
}
break;
case V_479 :
for ( V_463 = V_5 -> V_480 ; V_463 ;
V_463 = V_463 -> V_481 , V_474 ++ ) {
if ( V_474 < V_472 )
continue;
V_99 = F_311 ( V_82 , V_463 ,
F_70 ( V_470 -> V_82 ) . V_86 ,
V_470 -> V_90 -> V_117 ,
V_482 ,
V_476 ) ;
if ( V_99 <= 0 )
break;
}
break;
default:
break;
}
F_161 ( & V_5 -> V_43 ) ;
* V_473 = V_474 ;
return V_99 ;
}
static int F_313 ( struct V_81 * V_82 , struct V_469 * V_470 ,
enum V_471 type )
{
struct V_98 * V_98 = F_66 ( V_82 -> V_107 ) ;
int V_395 , V_483 ;
int V_484 , V_474 ;
int V_485 , V_472 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_394 * V_486 ;
V_483 = V_470 -> args [ 0 ] ;
V_485 = V_484 = V_470 -> args [ 1 ] ;
V_472 = V_474 = V_470 -> args [ 2 ] ;
F_154 () ;
for ( V_395 = V_483 ; V_395 < V_487 ; V_395 ++ , V_485 = 0 ) {
V_484 = 0 ;
V_486 = & V_98 -> V_488 [ V_395 ] ;
F_165 (dev, head, index_hlist) {
if ( V_484 < V_485 )
goto V_489;
if ( V_395 > V_483 || V_484 > V_485 )
V_472 = 0 ;
V_474 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_489;
if ( F_312 ( V_5 , V_82 , V_470 , type ,
V_472 , & V_474 ) <= 0 )
goto V_490;
V_489:
V_484 ++ ;
}
}
V_490:
F_162 () ;
V_470 -> args [ 0 ] = V_395 ;
V_470 -> args [ 1 ] = V_484 ;
V_470 -> args [ 2 ] = V_474 ;
return V_82 -> V_304 ;
}
static int F_314 ( struct V_81 * V_82 , struct V_469 * V_470 )
{
enum V_471 type = V_475 ;
return F_313 ( V_82 , V_470 , type ) ;
}
static int F_315 ( struct V_81 * V_82 , struct V_469 * V_470 )
{
enum V_471 type = V_477 ;
return F_313 ( V_82 , V_470 , type ) ;
}
static int F_316 ( struct V_81 * V_82 , struct V_469 * V_470 )
{
enum V_471 type = V_479 ;
return F_313 ( V_82 , V_470 , type ) ;
}
static int F_317 ( struct V_81 * V_105 , struct V_89 * V_90 ,
void * V_106 )
{
struct V_98 * V_98 = F_66 ( V_105 -> V_107 ) ;
struct V_432 * V_433 ;
struct V_108 * V_109 [ V_434 + 1 ] ;
struct V_138 * V_136 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_118 ;
struct V_81 * V_82 ;
int V_99 ;
V_99 = F_67 ( V_90 , sizeof( * V_433 ) , V_109 , V_434 , V_435 ) ;
if ( V_99 < 0 )
goto V_102;
V_136 = F_298 ( V_109 [ V_436 ] , V_109 [ V_437 ] ) ;
if ( V_136 == NULL ) {
V_99 = - V_113 ;
goto V_102;
}
V_433 = F_56 ( V_90 ) ;
if ( V_433 -> V_438 )
V_7 = F_69 ( V_98 , V_433 -> V_438 ) ;
V_118 = F_169 ( V_98 , V_136 , V_7 , 1 ) ;
if ( ! V_118 ) {
V_99 = - V_148 ;
goto V_102;
}
V_82 = F_61 ( F_308 () , V_28 ) ;
if ( ! V_82 ) {
V_99 = - V_100 ;
goto V_491;
}
V_99 = F_309 ( V_82 , V_118 , F_70 ( V_105 ) . V_86 ,
V_90 -> V_117 , V_359 , 0 ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_491;
}
V_99 = F_71 ( V_82 , V_98 , F_70 ( V_105 ) . V_86 ) ;
V_491:
F_123 ( V_118 ) ;
V_102:
return V_99 ;
}
static void F_318 ( int V_88 , struct V_8 * V_118 )
{
struct V_81 * V_82 ;
struct V_98 * V_98 = F_31 ( V_118 -> V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_82 = F_61 ( F_308 () , V_101 ) ;
if ( V_82 == NULL )
goto V_102;
V_99 = F_309 ( V_82 , V_118 , 0 , 0 , V_88 , 0 ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_102;
}
F_63 ( V_82 , V_98 , 0 , V_492 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_64 ( V_98 , V_492 , V_99 ) ;
}
static inline void F_319 ( struct V_84 * V_44 ,
T_2 * V_493 , int V_494 )
{
F_320 ( V_494 < ( V_495 * 4 ) ) ;
memset ( V_493 , 0 , V_494 ) ;
V_493 [ V_496 ] = V_44 -> V_50 ;
V_493 [ V_497 ] = V_44 -> V_498 ;
V_493 [ V_499 ] = V_44 -> V_46 ;
V_493 [ V_500 ] = V_44 -> V_501 ;
V_493 [ V_502 ] = V_44 -> V_503 ;
V_493 [ V_504 ] = V_44 -> V_315 ;
V_493 [ V_505 ] = V_44 -> V_199 ;
V_493 [ V_506 ] = V_44 -> V_60 ;
V_493 [ V_507 ] =
F_321 ( V_44 -> V_401 ) ;
V_493 [ V_508 ] =
F_321 ( V_44 -> V_400 ) ;
V_493 [ V_509 ] = V_44 -> V_510 ;
#ifdef F_41
V_493 [ V_511 ] = V_44 -> V_67 ;
V_493 [ V_512 ] = V_44 -> V_195 ;
V_493 [ V_513 ] = V_44 -> V_197 ;
V_493 [ V_514 ] = V_44 -> V_192 ;
V_493 [ V_515 ] = V_44 -> V_198 ;
#endif
V_493 [ V_516 ] = V_44 -> V_186 ;
V_493 [ V_517 ] = V_44 -> V_518 ;
V_493 [ V_519 ] = V_44 -> V_520 ;
#ifdef F_322
V_493 [ V_521 ] = V_44 -> V_522 ;
V_493 [ V_523 ] =
F_321 ( V_44 -> V_524 ) ;
#ifdef F_323
V_493 [ V_525 ] = V_44 -> V_526 ;
#endif
#endif
V_493 [ V_527 ] = V_44 -> V_528 ;
V_493 [ V_529 ] = V_44 -> V_530 ;
#ifdef F_223
V_493 [ V_531 ] = V_44 -> V_319 ;
#endif
#ifdef F_53
V_493 [ V_532 ] = V_44 -> V_97 ;
#endif
V_493 [ V_533 ] = V_44 -> V_151 ;
V_493 [ V_534 ] = V_44 -> V_55 ;
V_493 [ V_535 ] = V_44 -> V_536 ;
V_493 [ V_537 ] = V_44 -> V_538 ;
}
static inline T_15 F_324 ( void )
{
return F_52 ( 4 )
+ F_52 ( sizeof( struct V_539 ) )
+ F_52 ( V_495 * 4 )
+ F_52 ( V_540 * 8 )
+ F_52 ( V_541 * 8 ) ;
}
static inline T_15 F_325 ( void )
{
return F_51 ( sizeof( struct V_542 ) )
+ F_52 ( V_543 )
+ F_52 ( V_544 )
+ F_52 ( 4 )
+ F_52 ( 4 )
+ F_52 ( F_324 () ) ;
}
static inline void F_326 ( T_16 * V_22 , T_17 * V_545 ,
int V_546 , int V_494 )
{
int V_209 ;
int V_547 = V_494 - sizeof( T_16 ) * V_546 ;
F_320 ( V_547 < 0 ) ;
F_327 ( V_546 , & V_22 [ 0 ] ) ;
for ( V_209 = 1 ; V_209 < V_546 ; V_209 ++ )
F_327 ( F_328 ( & V_545 [ V_209 ] ) , & V_22 [ V_209 ] ) ;
memset ( & V_22 [ V_546 ] , 0 , V_547 ) ;
}
static inline void F_329 ( T_16 * V_22 , void V_21 * * V_545 ,
int V_546 , int V_494 , T_15 V_548 )
{
int V_209 ;
int V_547 = V_494 - sizeof( T_16 ) * V_546 ;
F_320 ( V_547 < 0 ) ;
F_327 ( V_546 , & V_22 [ 0 ] ) ;
for ( V_209 = 1 ; V_209 < V_546 ; V_209 ++ )
F_327 ( F_330 ( V_545 , V_209 , V_548 ) , & V_22 [ V_209 ] ) ;
memset ( & V_22 [ V_546 ] , 0 , V_547 ) ;
}
static void F_331 ( T_16 * V_22 , struct V_4 * V_5 , int V_549 ,
int V_494 )
{
switch ( V_549 ) {
case V_550 :
F_329 ( V_22 , ( void V_21 * * ) V_5 -> V_22 . V_23 ,
V_540 , V_494 , F_332 ( struct V_24 , V_551 ) ) ;
break;
case V_552 :
F_326 ( V_22 , V_5 -> V_22 . V_26 -> V_553 , V_541 , V_494 ) ;
break;
}
}
static int F_333 ( struct V_81 * V_82 , struct V_4 * V_5 )
{
struct V_108 * V_554 ;
struct V_539 V_443 ;
if ( F_334 ( V_82 , V_555 , V_5 -> V_68 ) )
goto V_96;
V_443 . V_556 = V_557 ;
V_443 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_443 . V_558 = F_321 ( V_5 -> V_48 -> V_558 ) ;
V_443 . V_200 = F_321 ( V_5 -> V_48 -> V_200 ) ;
if ( F_306 ( V_82 , V_559 , sizeof( V_443 ) , & V_443 ) )
goto V_96;
V_554 = F_335 ( V_82 , V_560 , V_495 * sizeof( V_561 ) ) ;
if ( V_554 == NULL )
goto V_96;
F_319 ( & V_5 -> V_44 , F_299 ( V_554 ) , F_336 ( V_554 ) ) ;
V_554 = F_335 ( V_82 , V_550 , V_540 * sizeof( T_16 ) ) ;
if ( V_554 == NULL )
goto V_96;
F_331 ( F_299 ( V_554 ) , V_5 , V_550 , F_336 ( V_554 ) ) ;
V_554 = F_335 ( V_82 , V_552 , V_541 * sizeof( T_16 ) ) ;
if ( V_554 == NULL )
goto V_96;
F_331 ( F_299 ( V_554 ) , V_5 , V_552 , F_336 ( V_554 ) ) ;
return 0 ;
V_96:
return - V_92 ;
}
static T_15 F_337 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_324 () ;
}
static int F_338 ( struct V_81 * V_82 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_562 ;
if ( F_333 ( V_82 , V_5 ) < 0 )
return - V_92 ;
return 0 ;
}
static int F_339 ( struct V_81 * V_82 , struct V_4 * V_5 ,
T_1 V_86 , T_1 V_87 , int V_88 , unsigned int V_52 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_542 * V_563 ;
struct V_89 * V_90 ;
void * V_564 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( * V_563 ) , V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
V_563 = F_56 ( V_90 ) ;
V_563 -> V_565 = V_94 ;
V_563 -> V_566 = 0 ;
V_563 -> V_567 = V_7 -> type ;
V_563 -> V_568 = V_7 -> V_83 ;
V_563 -> V_569 = F_340 ( V_7 ) ;
V_563 -> V_570 = 0 ;
if ( F_341 ( V_82 , V_571 , V_7 -> V_37 ) ||
( V_7 -> V_259 &&
F_306 ( V_82 , V_572 , V_7 -> V_259 , V_7 -> V_261 ) ) ||
F_334 ( V_82 , V_573 , V_7 -> V_41 ) ||
( V_7 -> V_83 != V_7 -> V_376 &&
F_334 ( V_82 , V_574 , V_7 -> V_376 ) ) )
goto V_96;
V_564 = F_342 ( V_82 , V_575 ) ;
if ( V_564 == NULL )
goto V_96;
if ( F_333 ( V_82 , V_5 ) < 0 )
goto V_96;
F_343 ( V_82 , V_564 ) ;
return F_58 ( V_82 , V_90 ) ;
V_96:
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
static int F_344 ( struct V_81 * V_82 , struct V_469 * V_470 )
{
struct V_98 * V_98 = F_66 ( V_82 -> V_107 ) ;
int V_395 , V_483 ;
int V_484 = 0 , V_485 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_394 * V_486 ;
V_483 = V_470 -> args [ 0 ] ;
V_485 = V_470 -> args [ 1 ] ;
F_154 () ;
for ( V_395 = V_483 ; V_395 < V_487 ; V_395 ++ , V_485 = 0 ) {
V_484 = 0 ;
V_486 = & V_98 -> V_488 [ V_395 ] ;
F_165 (dev, head, index_hlist) {
if ( V_484 < V_485 )
goto V_489;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_489;
if ( F_339 ( V_82 , V_5 ,
F_70 ( V_470 -> V_82 ) . V_86 ,
V_470 -> V_90 -> V_117 ,
V_385 , V_476 ) <= 0 )
goto V_155;
V_489:
V_484 ++ ;
}
}
V_155:
F_162 () ;
V_470 -> args [ 1 ] = V_484 ;
V_470 -> args [ 0 ] = V_395 ;
return V_82 -> V_304 ;
}
void F_256 ( int V_88 , struct V_4 * V_5 )
{
struct V_81 * V_82 ;
struct V_98 * V_98 = F_31 ( V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_82 = F_61 ( F_325 () , V_101 ) ;
if ( V_82 == NULL )
goto V_102;
V_99 = F_339 ( V_82 , V_5 , 0 , 0 , V_88 , 0 ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_102;
}
F_63 ( V_82 , V_98 , 0 , V_576 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_64 ( V_98 , V_576 , V_99 ) ;
}
static inline T_15 F_345 ( void )
{
return F_51 ( sizeof( struct V_577 ) )
+ F_52 ( sizeof( struct V_138 ) )
+ F_52 ( sizeof( struct V_578 ) ) ;
}
static int F_346 ( struct V_81 * V_82 , struct V_4 * V_5 ,
struct V_306 * V_307 , T_1 V_86 , T_1 V_87 ,
int V_88 , unsigned int V_52 )
{
struct V_577 * V_579 ;
struct V_89 * V_90 ;
struct V_578 V_443 ;
V_90 = F_55 ( V_82 , V_86 , V_87 , V_88 , sizeof( * V_579 ) , V_52 ) ;
if ( V_90 == NULL )
return - V_92 ;
V_579 = F_56 ( V_90 ) ;
V_579 -> V_580 = V_94 ;
V_579 -> V_581 = 0 ;
V_579 -> V_582 = 0 ;
V_579 -> V_583 = V_5 -> V_7 -> V_83 ;
V_579 -> V_158 = V_307 -> V_158 ;
V_579 -> V_584 = V_307 -> type ;
V_579 -> V_585 = 0 ;
V_579 -> V_586 = 0 ;
if ( V_307 -> V_165 )
V_579 -> V_586 |= V_587 ;
if ( V_307 -> V_315 )
V_579 -> V_586 |= V_588 ;
if ( F_306 ( V_82 , V_589 , sizeof( V_307 -> V_172 ) , & V_307 -> V_172 ) )
goto V_96;
V_443 . V_590 = F_216 ( V_307 -> V_310 ) ;
V_443 . V_591 = F_216 ( V_307 -> V_309 ) ;
if ( F_306 ( V_82 , V_592 , sizeof( V_443 ) , & V_443 ) )
goto V_96;
return F_58 ( V_82 , V_90 ) ;
V_96:
F_59 ( V_82 , V_90 ) ;
return - V_92 ;
}
static void F_225 ( int V_88 , struct V_4 * V_5 ,
struct V_306 * V_307 )
{
struct V_81 * V_82 ;
struct V_98 * V_98 = F_31 ( V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_82 = F_61 ( F_345 () , V_101 ) ;
if ( V_82 == NULL )
goto V_102;
V_99 = F_346 ( V_82 , V_5 , V_307 , 0 , 0 , V_88 , 0 ) ;
if ( V_99 < 0 ) {
F_20 ( V_99 == - V_92 ) ;
F_62 ( V_82 ) ;
goto V_102;
}
F_63 ( V_82 , V_98 , 0 , V_593 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_64 ( V_98 , V_593 , V_99 ) ;
}
static void F_265 ( int V_88 , struct V_8 * V_9 )
{
F_318 ( V_88 ? : V_359 , V_9 ) ;
switch ( V_88 ) {
case V_359 :
if ( ! ( V_9 -> V_133 -> V_594 ) )
F_244 ( V_9 -> V_133 ) ;
if ( V_9 -> V_5 -> V_44 . V_50 )
F_75 ( V_9 ) ;
break;
case V_170 :
if ( V_9 -> V_5 -> V_44 . V_50 )
F_76 ( V_9 ) ;
F_179 ( V_9 -> V_5 , & V_9 -> V_136 ) ;
F_210 ( & V_9 -> V_133 -> V_208 ) ;
if ( F_133 ( V_9 -> V_133 ) )
F_347 ( & V_9 -> V_133 -> V_208 ) ;
break;
}
}
static void F_130 ( int V_88 , struct V_8 * V_9 )
{
F_100 () ;
if ( F_115 ( V_9 -> V_5 -> V_38 == 0 ) )
F_265 ( V_88 , V_9 ) ;
F_114 () ;
}
static
int F_348 ( V_124 * V_595 , int V_596 ,
void T_6 * V_597 , T_15 * V_598 , T_9 * V_599 )
{
int * V_600 = V_595 -> V_157 ;
int V_601 = * V_600 ;
T_9 V_407 = * V_599 ;
V_124 V_602 ;
int V_185 ;
V_602 = * V_595 ;
V_602 . V_157 = & V_601 ;
V_185 = F_349 ( & V_602 , V_596 , V_597 , V_598 , V_599 ) ;
if ( V_596 )
V_185 = F_79 ( V_595 , V_600 , V_601 ) ;
if ( V_185 )
* V_599 = V_407 ;
return V_185 ;
}
static void F_350 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_44 . V_151 )
F_252 ( NULL , V_171 , V_5 -> V_7 ) ;
else
F_252 ( NULL , V_162 , V_5 -> V_7 ) ;
}
static void F_351 ( struct V_98 * V_98 , T_2 V_122 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_154 () ;
F_155 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_123 = ( ! V_5 -> V_44 . V_151 ) ^ ( ! V_122 ) ;
V_5 -> V_44 . V_151 = V_122 ;
if ( V_123 )
F_350 ( V_5 ) ;
}
}
F_162 () ;
}
static int F_352 ( struct V_124 * V_125 , int * V_126 , int V_122 )
{
struct V_98 * V_98 ;
int V_127 ;
if ( ! F_80 () )
return F_81 () ;
V_98 = (struct V_98 * ) V_125 -> V_128 ;
V_127 = * V_126 ;
* V_126 = V_122 ;
if ( V_126 == & V_98 -> V_23 . V_45 -> V_151 ) {
F_82 () ;
return 0 ;
}
if ( V_126 == & V_98 -> V_23 . V_115 -> V_151 ) {
V_98 -> V_23 . V_45 -> V_151 = V_122 ;
F_351 ( V_98 , V_122 ) ;
} else if ( ( ! V_122 ) ^ ( ! V_127 ) )
F_350 ( (struct V_4 * ) V_125 -> V_129 ) ;
F_82 () ;
return 0 ;
}
static
int F_353 ( V_124 * V_595 , int V_596 ,
void T_6 * V_597 , T_15 * V_598 , T_9 * V_599 )
{
int * V_600 = V_595 -> V_157 ;
int V_601 = * V_600 ;
T_9 V_407 = * V_599 ;
V_124 V_602 ;
int V_185 ;
V_602 = * V_595 ;
V_602 . V_157 = & V_601 ;
V_185 = F_349 ( & V_602 , V_596 , V_597 , V_598 , V_599 ) ;
if ( V_596 )
V_185 = F_352 ( V_595 , V_600 , V_601 ) ;
if ( V_185 )
* V_599 = V_407 ;
return V_185 ;
}
static int F_354 ( struct V_98 * V_98 , char * V_603 ,
struct V_4 * V_5 , struct V_84 * V_126 )
{
int V_209 ;
struct V_604 * V_605 ;
char V_606 [ sizeof( L_34 ) + V_543 ] ;
V_605 = F_355 ( & V_607 , sizeof( * V_605 ) , V_28 ) ;
if ( V_605 == NULL )
goto V_155;
for ( V_209 = 0 ; V_605 -> V_608 [ V_209 ] . V_157 ; V_209 ++ ) {
V_605 -> V_608 [ V_209 ] . V_157 += ( char * ) V_126 - ( char * ) & V_84 ;
V_605 -> V_608 [ V_209 ] . V_129 = V_5 ;
V_605 -> V_608 [ V_209 ] . V_128 = V_98 ;
}
snprintf ( V_606 , sizeof( V_606 ) , L_35 , V_603 ) ;
V_605 -> V_609 = F_356 ( V_98 , V_606 , V_605 -> V_608 ) ;
if ( V_605 -> V_609 == NULL )
goto free;
V_126 -> V_47 = V_605 ;
return 0 ;
free:
F_16 ( V_605 ) ;
V_155:
return - V_100 ;
}
static void F_357 ( struct V_84 * V_126 )
{
struct V_604 * V_605 ;
if ( V_126 -> V_47 == NULL )
return;
V_605 = V_126 -> V_47 ;
V_126 -> V_47 = NULL ;
F_358 ( V_605 -> V_609 ) ;
F_16 ( V_605 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_359 ( V_5 -> V_7 , V_5 -> V_48 , L_36 ,
& V_610 ) ;
F_354 ( F_31 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_37 ,
V_5 , & V_5 -> V_44 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_357 ( & V_5 -> V_44 ) ;
F_360 ( V_5 -> V_48 ) ;
}
static int T_11 F_361 ( struct V_98 * V_98 )
{
int V_99 = - V_33 ;
struct V_84 * V_611 , * V_612 ;
V_611 = F_355 ( & V_84 , sizeof( V_84 ) , V_28 ) ;
if ( V_611 == NULL )
goto V_613;
V_612 = F_355 ( & V_614 , sizeof( V_614 ) , V_28 ) ;
if ( V_612 == NULL )
goto V_615;
V_612 -> V_315 = V_616 . V_315 ;
V_612 -> V_151 = V_616 . V_151 ;
V_98 -> V_23 . V_115 = V_611 ;
V_98 -> V_23 . V_45 = V_612 ;
#ifdef F_362
V_99 = F_354 ( V_98 , L_37 , NULL , V_611 ) ;
if ( V_99 < 0 )
goto V_617;
V_99 = F_354 ( V_98 , L_38 , NULL , V_612 ) ;
if ( V_99 < 0 )
goto V_618;
#endif
return 0 ;
#ifdef F_362
V_618:
F_357 ( V_611 ) ;
V_617:
F_16 ( V_612 ) ;
#endif
V_615:
F_16 ( V_611 ) ;
V_613:
return V_99 ;
}
static void T_12 F_363 ( struct V_98 * V_98 )
{
#ifdef F_362
F_357 ( V_98 -> V_23 . V_45 ) ;
F_357 ( V_98 -> V_23 . V_115 ) ;
#endif
if ( ! F_166 ( V_98 , & V_619 ) ) {
F_16 ( V_98 -> V_23 . V_45 ) ;
F_16 ( V_98 -> V_23 . V_115 ) ;
}
}
int T_13 F_364 ( void )
{
int V_209 , V_99 ;
V_99 = F_365 () ;
if ( V_99 < 0 ) {
F_366 ( L_39 ,
V_36 , V_99 ) ;
goto V_155;
}
V_99 = F_293 ( & V_620 ) ;
if ( V_99 < 0 )
goto V_621;
F_227 () ;
if ( ! F_27 ( V_619 . V_622 ) )
V_99 = - V_33 ;
F_82 () ;
if ( V_99 )
goto V_623;
for ( V_209 = 0 ; V_209 < V_393 ; V_209 ++ )
F_367 ( & V_159 [ V_209 ] ) ;
F_368 ( & V_624 ) ;
F_224 ( 0 ) ;
V_99 = F_369 ( & V_625 ) ;
if ( V_99 < 0 )
goto V_626;
V_99 = F_370 ( V_627 , V_628 , NULL , F_344 ,
NULL ) ;
if ( V_99 < 0 )
goto V_102;
F_370 ( V_627 , V_359 , F_303 , NULL , NULL ) ;
F_370 ( V_627 , V_170 , F_301 , NULL , NULL ) ;
F_370 ( V_627 , V_629 , F_317 ,
F_314 , NULL ) ;
F_370 ( V_627 , V_478 , NULL ,
F_315 , NULL ) ;
F_370 ( V_627 , V_482 , NULL ,
F_316 , NULL ) ;
F_370 ( V_627 , V_630 , F_65 ,
NULL , NULL ) ;
F_371 () ;
return 0 ;
V_102:
F_372 ( & V_625 ) ;
V_626:
F_373 ( & V_624 ) ;
V_623:
F_295 ( & V_620 ) ;
V_621:
F_374 () ;
V_155:
return V_99 ;
}
void F_375 ( void )
{
struct V_6 * V_7 ;
int V_209 ;
F_373 ( & V_624 ) ;
F_295 ( & V_620 ) ;
F_374 () ;
F_227 () ;
F_376 ( & V_625 ) ;
F_78 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_236 ( V_7 , 1 ) ;
}
F_236 ( V_619 . V_622 , 2 ) ;
F_118 ( & V_153 ) ;
for ( V_209 = 0 ; V_209 < V_393 ; V_209 ++ )
F_20 ( ! F_377 ( & V_159 [ V_209 ] ) ) ;
F_119 ( & V_153 ) ;
F_7 ( & V_426 ) ;
F_82 () ;
}
