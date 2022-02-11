static inline T_1 F_1 ( unsigned long V_1 )
{
return ( V_1 - V_2 ) * 100UL / V_3 ;
}
static inline T_2 F_2 ( T_2 V_4 )
{
T_3 V_5 = ( 900000 + F_3 () % 200001 ) * ( T_3 ) V_4 ;
F_4 ( V_5 , 1000000 ) ;
return ( T_2 ) V_5 ;
}
static inline T_2 F_5 ( T_2 V_6 , T_2 V_7 )
{
T_3 V_5 = ( 1900000 + F_3 () % 200001 ) * ( T_3 ) V_6 ;
F_4 ( V_5 , 1000000 ) ;
if ( ( T_2 ) V_5 > V_7 ) {
V_5 = ( 900000 + F_3 () % 200001 ) * ( T_3 ) V_7 ;
F_4 ( V_5 , 1000000 ) ;
}
return ( T_2 ) V_5 ;
}
static inline int F_6 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_7 ( struct V_8 * V_9 )
{
}
static inline bool F_8 ( const struct V_10 * V_11 )
{
return ! F_9 ( V_11 ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
if ( F_11 ( & V_9 -> V_12 ) )
F_12 ( V_9 ) ;
}
static void F_13 ( struct V_13 * V_14 )
{
if ( F_14 ( & V_14 -> V_15 ) )
F_15 ( V_14 ) ;
}
static void F_16 ( struct V_8 * V_9 ,
unsigned long V_16 )
{
if ( ! F_17 ( & V_9 -> V_12 ) )
F_18 ( V_9 ) ;
F_19 ( & V_9 -> V_12 , V_17 + V_16 ) ;
}
static void F_20 ( struct V_13 * V_14 ,
unsigned long V_18 )
{
F_21 ( V_14 ) ;
if ( F_22 ( V_19 , & V_14 -> V_15 , V_18 ) )
F_23 ( V_14 ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
int V_20 ;
V_9 -> V_21 . V_22 = F_25 ( struct V_23 ) ;
if ( ! V_9 -> V_21 . V_22 )
goto V_24;
F_26 (i) {
struct V_23 * V_25 ;
V_25 = F_27 ( V_9 -> V_21 . V_22 , V_20 ) ;
F_28 ( & V_25 -> V_26 ) ;
}
V_9 -> V_21 . V_27 = F_29 ( sizeof( struct V_28 ) ,
V_29 ) ;
if ( ! V_9 -> V_21 . V_27 )
goto V_30;
V_9 -> V_21 . V_31 = F_29 ( sizeof( struct V_32 ) ,
V_29 ) ;
if ( ! V_9 -> V_21 . V_31 )
goto V_33;
return 0 ;
V_33:
F_30 ( V_9 -> V_21 . V_27 ) ;
V_30:
F_31 ( V_9 -> V_21 . V_22 ) ;
V_24:
return - V_34 ;
}
static struct V_8 * F_32 ( struct V_10 * V_11 )
{
struct V_8 * V_35 ;
int V_36 = - V_34 ;
F_33 () ;
if ( V_11 -> V_37 < V_38 )
return F_34 ( - V_39 ) ;
V_35 = F_29 ( sizeof( struct V_8 ) , V_29 ) ;
if ( ! V_35 )
return F_34 ( V_36 ) ;
F_35 ( & V_35 -> V_40 ) ;
V_35 -> V_11 = V_11 ;
F_36 ( & V_35 -> V_41 ) ;
F_37 ( & V_35 -> V_12 , V_42 ,
( unsigned long ) V_35 ) ;
memcpy ( & V_35 -> V_43 , F_38 ( V_11 ) -> V_22 . V_44 , sizeof( V_35 -> V_43 ) ) ;
if ( V_35 -> V_43 . V_45 . V_46 )
V_35 -> V_43 . V_47 = V_48 ;
else
V_35 -> V_43 . V_47 = V_49 . V_47 ;
V_35 -> V_43 . V_50 = V_11 -> V_37 ;
V_35 -> V_51 = F_39 ( V_11 , & V_52 ) ;
if ( ! V_35 -> V_51 ) {
F_30 ( V_35 ) ;
return F_34 ( V_36 ) ;
}
if ( V_35 -> V_43 . V_53 )
F_40 ( V_11 ) ;
F_41 ( V_11 ) ;
if ( F_24 ( V_35 ) < 0 ) {
F_42 ( V_54
L_1 ,
V_55 , V_11 -> V_56 ) ;
F_43 ( & V_52 , V_35 -> V_51 ) ;
F_44 ( V_11 ) ;
F_30 ( V_35 ) ;
return F_34 ( V_36 ) ;
}
if ( F_45 ( V_35 ) < 0 ) {
F_42 ( V_54
L_2 ,
V_55 , V_11 -> V_56 ) ;
goto V_57;
}
F_46 ( & V_35 -> V_58 , 1 ) ;
if ( V_11 -> V_59 & ( V_60 | V_61 ) )
V_35 -> V_43 . V_62 = - 1 ;
#if F_47 ( V_63 )
if ( V_11 -> type == V_64 && ( V_11 -> V_65 & V_66 ) ) {
F_48 ( L_3 , V_11 -> V_56 ) ;
V_35 -> V_43 . V_67 = 0 ;
}
#endif
F_36 ( & V_35 -> V_68 ) ;
V_35 -> V_69 = V_70 ;
if ( ( V_11 -> V_59 & V_61 ) ||
V_11 -> type == V_71 ||
V_11 -> type == V_72 ||
V_11 -> type == V_64 ||
V_11 -> type == V_73 ) {
V_35 -> V_43 . V_74 = - 1 ;
} else
F_49 ( V_35 ) ;
V_35 -> V_75 = V_76 ;
if ( F_50 ( V_11 ) && F_8 ( V_11 ) )
V_35 -> V_77 |= V_78 ;
F_51 ( V_35 ) ;
V_35 -> V_79 = V_17 ;
V_36 = F_6 ( V_35 ) ;
if ( V_36 ) {
F_52 ( V_35 ) ;
F_53 ( V_35 ) ;
goto V_57;
}
F_54 ( V_11 -> V_80 , V_35 ) ;
F_55 ( V_11 , & V_81 ) ;
F_55 ( V_11 , & V_82 ) ;
if ( V_35 -> V_43 . V_53 && ( V_11 -> V_59 & V_83 ) )
F_55 ( V_11 , & V_84 ) ;
return V_35 ;
V_57:
F_43 ( & V_52 , V_35 -> V_51 ) ;
V_35 -> V_85 = 1 ;
F_56 ( V_35 ) ;
return F_34 ( V_36 ) ;
}
static struct V_8 * F_57 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_59 ( V_9 ) )
return NULL ;
}
if ( V_11 -> V_59 & V_86 )
F_60 ( V_9 ) ;
return V_9 ;
}
static int F_61 ( int type )
{
int V_87 = F_62 ( sizeof( struct V_88 ) )
+ F_63 ( 4 ) ;
bool V_89 = false ;
if ( type == V_90 )
V_89 = true ;
if ( V_89 || type == V_91 )
V_87 += F_63 ( 4 ) ;
#ifdef F_64
if ( V_89 || type == V_92 )
V_87 += F_63 ( 4 ) ;
#endif
if ( V_89 || type == V_93 )
V_87 += F_63 ( 4 ) ;
if ( V_89 || type == V_94 )
V_87 += F_63 ( 4 ) ;
return V_87 ;
}
static int F_65 ( struct V_95 * V_96 , int V_97 ,
struct V_98 * V_99 , T_1 V_100 ,
T_1 V_101 , int V_102 , unsigned int V_59 ,
int type )
{
struct V_103 * V_104 ;
struct V_88 * V_105 ;
bool V_89 = false ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( struct V_88 ) ,
V_59 ) ;
if ( ! V_104 )
return - V_106 ;
if ( type == V_90 )
V_89 = true ;
V_105 = F_67 ( V_104 ) ;
V_105 -> V_107 = V_108 ;
if ( F_68 ( V_96 , V_109 , V_97 ) < 0 )
goto V_110;
if ( ! V_99 )
goto V_111;
if ( ( V_89 || type == V_91 ) &&
F_68 ( V_96 , V_91 , V_99 -> V_53 ) < 0 )
goto V_110;
#ifdef F_64
if ( ( V_89 || type == V_92 ) &&
F_68 ( V_96 , V_92 ,
V_99 -> V_112 ) < 0 )
goto V_110;
#endif
if ( ( V_89 || type == V_93 ) &&
F_68 ( V_96 , V_93 , V_99 -> V_113 ) < 0 )
goto V_110;
if ( ( V_89 || type == V_94 ) &&
F_68 ( V_96 , V_94 ,
V_99 -> V_114 ) < 0 )
goto V_110;
V_111:
F_69 ( V_96 , V_104 ) ;
return 0 ;
V_110:
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
void F_71 ( struct V_115 * V_115 , int V_102 , int type ,
int V_97 , struct V_98 * V_99 )
{
struct V_95 * V_96 ;
int V_36 = - V_116 ;
V_96 = F_72 ( F_61 ( type ) , V_29 ) ;
if ( ! V_96 )
goto V_117;
V_36 = F_65 ( V_96 , V_97 , V_99 , 0 , 0 ,
V_102 , 0 , type ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_117;
}
F_75 ( V_96 , V_115 , 0 , V_118 , NULL , V_29 ) ;
return;
V_117:
F_76 ( V_115 , V_118 , V_36 ) ;
}
static int F_77 ( struct V_95 * V_119 ,
struct V_103 * V_104 ,
struct V_120 * V_121 )
{
struct V_115 * V_115 = F_78 ( V_119 -> V_122 ) ;
struct V_123 * V_124 [ V_125 + 1 ] ;
struct V_88 * V_105 ;
struct V_95 * V_96 ;
struct V_98 * V_99 ;
struct V_8 * V_126 ;
struct V_10 * V_11 ;
int V_97 ;
int V_36 ;
V_36 = F_79 ( V_104 , sizeof( * V_105 ) , V_124 , V_125 ,
V_127 , V_121 ) ;
if ( V_36 < 0 )
goto V_117;
V_36 = - V_39 ;
if ( ! V_124 [ V_109 ] )
goto V_117;
V_97 = F_80 ( V_124 [ V_109 ] ) ;
switch ( V_97 ) {
case V_128 :
V_99 = V_115 -> V_22 . V_129 ;
break;
case V_130 :
V_99 = V_115 -> V_22 . V_44 ;
break;
default:
V_11 = F_81 ( V_115 , V_97 ) ;
if ( ! V_11 )
goto V_117;
V_126 = F_58 ( V_11 ) ;
if ( ! V_126 )
goto V_117;
V_99 = & V_126 -> V_43 ;
break;
}
V_36 = - V_116 ;
V_96 = F_72 ( F_61 ( V_90 ) , V_131 ) ;
if ( ! V_96 )
goto V_117;
V_36 = F_65 ( V_96 , V_97 , V_99 ,
F_82 ( V_119 ) . V_100 ,
V_104 -> V_132 , V_133 , 0 ,
V_90 ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_117;
}
V_36 = F_83 ( V_96 , V_115 , F_82 ( V_119 ) . V_100 ) ;
V_117:
return V_36 ;
}
static int F_84 ( struct V_95 * V_96 ,
struct V_134 * V_135 )
{
struct V_115 * V_115 = F_78 ( V_96 -> V_122 ) ;
int V_136 , V_137 ;
int V_138 , V_139 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_140 * V_141 ;
V_137 = V_135 -> args [ 0 ] ;
V_139 = V_138 = V_135 -> args [ 1 ] ;
for ( V_136 = V_137 ; V_136 < V_142 ; V_136 ++ , V_139 = 0 ) {
V_138 = 0 ;
V_141 = & V_115 -> V_143 [ V_136 ] ;
F_85 () ;
V_135 -> V_101 = F_86 ( & V_115 -> V_22 . V_144 ) ^
V_115 -> V_145 ;
F_87 (dev, head, index_hlist) {
if ( V_138 < V_139 )
goto V_146;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
goto V_146;
if ( F_65 ( V_96 , V_11 -> V_97 ,
& V_9 -> V_43 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_133 ,
V_147 ,
V_90 ) < 0 ) {
F_88 () ;
goto V_148;
}
F_89 ( V_135 , F_90 ( V_96 ) ) ;
V_146:
V_138 ++ ;
}
F_88 () ;
}
if ( V_136 == V_142 ) {
if ( F_65 ( V_96 , V_128 ,
V_115 -> V_22 . V_129 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_133 , V_147 ,
V_90 ) < 0 )
goto V_148;
else
V_136 ++ ;
}
if ( V_136 == V_142 + 1 ) {
if ( F_65 ( V_96 , V_130 ,
V_115 -> V_22 . V_44 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_133 , V_147 ,
V_90 ) < 0 )
goto V_148;
else
V_136 ++ ;
}
V_148:
V_135 -> args [ 0 ] = V_136 ;
V_135 -> args [ 1 ] = V_138 ;
return V_96 -> V_149 ;
}
static void F_91 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_13 * V_150 ;
if ( ! V_9 )
return;
V_11 = V_9 -> V_11 ;
if ( V_9 -> V_43 . V_53 )
F_40 ( V_11 ) ;
if ( V_11 -> V_59 & V_83 ) {
if ( V_9 -> V_43 . V_53 ) {
F_55 ( V_11 , & V_84 ) ;
F_55 ( V_11 , & V_151 ) ;
F_55 ( V_11 , & V_152 ) ;
} else {
F_92 ( V_11 , & V_84 ) ;
F_92 ( V_11 , & V_151 ) ;
F_92 ( V_11 , & V_152 ) ;
}
}
F_93 (ifa, &idev->addr_list, if_list) {
if ( V_150 -> V_59 & V_153 )
continue;
if ( V_9 -> V_43 . V_53 )
F_94 ( V_150 ) ;
else
F_95 ( V_150 ) ;
}
F_71 ( F_38 ( V_11 ) , V_133 ,
V_91 ,
V_11 -> V_97 , & V_9 -> V_43 ) ;
}
static void F_96 ( struct V_115 * V_115 , T_4 V_154 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_97 (net, dev) {
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
int V_155 = ( ! V_9 -> V_43 . V_53 ) ^ ( ! V_154 ) ;
V_9 -> V_43 . V_53 = V_154 ;
if ( V_155 )
F_91 ( V_9 ) ;
}
}
}
static int F_98 ( struct V_156 * V_157 , int * V_158 , int V_154 )
{
struct V_115 * V_115 ;
int V_159 ;
if ( ! F_99 () )
return F_100 () ;
V_115 = (struct V_115 * ) V_157 -> V_160 ;
V_159 = * V_158 ;
* V_158 = V_154 ;
if ( V_158 == & V_115 -> V_22 . V_44 -> V_53 ) {
if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_71 ( V_115 , V_133 ,
V_91 ,
V_130 ,
V_115 -> V_22 . V_44 ) ;
F_101 () ;
return 0 ;
}
if ( V_158 == & V_115 -> V_22 . V_129 -> V_53 ) {
int V_161 = V_115 -> V_22 . V_44 -> V_53 ;
V_115 -> V_22 . V_44 -> V_53 = V_154 ;
if ( ( ! V_154 ) ^ ( ! V_161 ) )
F_71 ( V_115 , V_133 ,
V_91 ,
V_130 ,
V_115 -> V_22 . V_44 ) ;
F_96 ( V_115 , V_154 ) ;
if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_71 ( V_115 , V_133 ,
V_91 ,
V_128 ,
V_115 -> V_22 . V_129 ) ;
} else if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_91 ( (struct V_8 * ) V_157 -> V_162 ) ;
F_101 () ;
if ( V_154 )
F_102 ( V_115 ) ;
return 1 ;
}
static void F_103 ( struct V_115 * V_115 , T_4 V_154 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_97 (net, dev) {
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
int V_155 = ( ! V_9 -> V_43 . V_114 ) ^ ( ! V_154 ) ;
V_9 -> V_43 . V_114 = V_154 ;
if ( V_155 )
F_71 ( F_38 ( V_11 ) ,
V_133 ,
V_94 ,
V_11 -> V_97 ,
& V_9 -> V_43 ) ;
}
}
}
static int F_104 ( struct V_156 * V_157 , int * V_158 , int V_154 )
{
struct V_115 * V_115 ;
int V_159 ;
if ( ! F_99 () )
return F_100 () ;
V_115 = (struct V_115 * ) V_157 -> V_160 ;
V_159 = * V_158 ;
* V_158 = V_154 ;
if ( V_158 == & V_115 -> V_22 . V_44 -> V_114 ) {
if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_71 ( V_115 ,
V_133 ,
V_94 ,
V_130 ,
V_115 -> V_22 . V_44 ) ;
F_101 () ;
return 0 ;
}
if ( V_158 == & V_115 -> V_22 . V_129 -> V_114 ) {
V_115 -> V_22 . V_44 -> V_114 = V_154 ;
F_103 ( V_115 , V_154 ) ;
if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_71 ( V_115 ,
V_133 ,
V_94 ,
V_128 ,
V_115 -> V_22 . V_129 ) ;
}
F_101 () ;
return 1 ;
}
void F_105 ( struct V_13 * V_14 )
{
F_73 ( ! F_106 ( & V_14 -> V_163 ) ) ;
#ifdef F_107
F_108 ( L_4 , V_55 ) ;
#endif
F_109 ( V_14 -> V_9 ) ;
if ( F_14 ( & V_14 -> V_15 ) )
F_110 ( L_5 ,
V_14 ) ;
if ( V_14 -> V_164 != V_165 ) {
F_111 ( L_6 , V_14 ) ;
return;
}
F_112 ( V_14 -> V_6 ) ;
F_113 ( V_14 , V_166 ) ;
}
static void
F_114 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
struct V_167 * V_158 ;
int V_168 = F_115 ( & V_14 -> V_169 ) ;
F_116 (p, &idev->addr_list) {
struct V_13 * V_150
= F_117 ( V_158 , struct V_13 , V_170 ) ;
if ( V_168 >= F_115 ( & V_150 -> V_169 ) )
break;
}
F_118 ( & V_14 -> V_170 , V_158 ) ;
}
static T_1 F_119 ( const struct V_171 * V_169 )
{
return F_120 ( F_121 ( V_169 ) , V_172 ) ;
}
static struct V_13 *
F_122 ( struct V_8 * V_9 , const struct V_171 * V_169 ,
const struct V_171 * V_173 , int V_174 ,
int V_175 , T_1 V_59 , T_1 V_176 , T_1 V_177 )
{
struct V_115 * V_115 = F_38 ( V_9 -> V_11 ) ;
struct V_13 * V_150 = NULL ;
struct V_178 * V_6 ;
struct V_179 V_180 ;
unsigned int V_181 ;
int V_36 = 0 ;
int V_182 = F_123 ( V_169 ) ;
if ( V_182 == V_183 ||
V_182 & V_184 ||
( ! ( V_9 -> V_11 -> V_59 & V_61 ) &&
V_182 & V_185 ) )
return F_34 ( - V_186 ) ;
F_124 () ;
F_18 ( V_9 ) ;
if ( V_9 -> V_85 ) {
V_36 = - V_187 ;
goto V_188;
}
if ( V_9 -> V_43 . V_189 ) {
V_36 = - V_190 ;
goto V_188;
}
V_180 . V_191 = * V_169 ;
V_180 . V_192 = V_9 ;
F_125 () ;
V_36 = F_126 ( V_193 , & V_180 ) ;
F_124 () ;
V_36 = F_127 ( V_36 ) ;
if ( V_36 )
goto V_188;
F_128 ( & V_194 ) ;
if ( F_129 ( F_38 ( V_9 -> V_11 ) , V_169 , V_9 -> V_11 ) ) {
F_42 ( L_7 ) ;
V_36 = - V_195 ;
goto V_111;
}
V_150 = F_29 ( sizeof( struct V_13 ) , V_131 ) ;
if ( ! V_150 ) {
F_42 ( L_8 ) ;
V_36 = - V_116 ;
goto V_111;
}
V_6 = F_130 ( V_9 , V_169 , false ) ;
if ( F_59 ( V_6 ) ) {
V_36 = F_131 ( V_6 ) ;
goto V_111;
}
if ( V_115 -> V_22 . V_129 -> V_196 ||
V_9 -> V_43 . V_196 )
V_6 -> V_197 . V_59 |= V_198 ;
F_132 ( V_9 -> V_51 ) ;
V_150 -> V_169 = * V_169 ;
if ( V_173 )
V_150 -> V_173 = * V_173 ;
F_133 ( & V_150 -> V_40 ) ;
F_134 ( & V_150 -> V_15 , V_199 ) ;
F_135 ( & V_150 -> V_163 ) ;
V_150 -> V_175 = V_175 ;
V_150 -> V_200 = V_174 ;
V_150 -> V_59 = V_59 ;
if ( ! ( V_59 & V_201 ) )
V_150 -> V_59 |= V_153 ;
V_150 -> V_176 = V_176 ;
V_150 -> V_177 = V_177 ;
V_150 -> V_1 = V_150 -> V_79 = V_17 ;
V_150 -> V_202 = false ;
V_150 -> V_6 = V_6 ;
V_150 -> V_9 = V_9 ;
F_46 ( & V_150 -> V_58 , 1 ) ;
V_181 = F_119 ( V_169 ) ;
F_136 ( & V_150 -> V_163 , & V_203 [ V_181 ] ) ;
F_137 ( & V_194 ) ;
F_138 ( & V_9 -> V_40 ) ;
F_114 ( V_9 , V_150 ) ;
if ( V_150 -> V_59 & V_204 ) {
F_139 ( & V_150 -> V_205 , & V_9 -> V_68 ) ;
F_21 ( V_150 ) ;
}
F_21 ( V_150 ) ;
F_140 ( & V_9 -> V_40 ) ;
V_188:
F_125 () ;
if ( F_141 ( V_36 == 0 ) )
F_142 ( V_193 , V_150 ) ;
else {
F_30 ( V_150 ) ;
F_109 ( V_9 ) ;
V_150 = F_34 ( V_36 ) ;
}
return V_150 ;
V_111:
F_137 ( & V_194 ) ;
goto V_188;
}
static enum V_206
F_143 ( struct V_13 * V_14 , unsigned long * V_207 )
{
struct V_13 * V_150 ;
struct V_8 * V_9 = V_14 -> V_9 ;
unsigned long V_208 ;
enum V_206 V_209 = V_210 ;
* V_207 = V_17 ;
F_93 (ifa, &idev->addr_list, if_list) {
if ( V_150 == V_14 )
continue;
if ( ! F_144 ( & V_150 -> V_169 , & V_14 -> V_169 ,
V_14 -> V_200 ) )
continue;
if ( V_150 -> V_59 & ( V_211 | V_212 ) )
return V_213 ;
V_209 = V_214 ;
F_128 ( & V_150 -> V_40 ) ;
V_208 = F_145 ( V_150 -> V_176 , V_3 ) ;
if ( F_146 ( * V_207 , V_150 -> V_79 + V_208 * V_3 ) )
* V_207 = V_150 -> V_79 + V_208 * V_3 ;
F_137 ( & V_150 -> V_40 ) ;
}
return V_209 ;
}
static void
F_147 ( struct V_13 * V_14 , unsigned long V_207 , bool V_215 )
{
struct V_178 * V_6 ;
V_6 = F_148 ( & V_14 -> V_169 ,
V_14 -> V_200 ,
V_14 -> V_9 -> V_11 ,
0 , V_216 | V_217 ) ;
if ( V_6 ) {
if ( V_215 )
F_149 ( V_6 ) ;
else {
if ( ! ( V_6 -> V_218 & V_219 ) )
F_150 ( V_6 , V_207 ) ;
F_112 ( V_6 ) ;
}
}
}
static void F_151 ( struct V_13 * V_14 )
{
int V_164 ;
enum V_206 V_209 = V_213 ;
unsigned long V_207 ;
F_33 () ;
F_152 ( & V_14 -> V_40 ) ;
V_164 = V_14 -> V_164 ;
V_14 -> V_164 = V_165 ;
F_153 ( & V_14 -> V_40 ) ;
if ( V_164 == V_165 )
goto V_111;
F_152 ( & V_194 ) ;
F_154 ( & V_14 -> V_163 ) ;
F_153 ( & V_194 ) ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_14 -> V_59 & V_204 ) {
F_156 ( & V_14 -> V_205 ) ;
if ( V_14 -> V_220 ) {
F_23 ( V_14 -> V_220 ) ;
V_14 -> V_220 = NULL ;
}
F_15 ( V_14 ) ;
}
if ( V_14 -> V_59 & V_211 && ! ( V_14 -> V_59 & V_212 ) )
V_209 = F_143 ( V_14 , & V_207 ) ;
F_157 ( & V_14 -> V_170 ) ;
F_15 ( V_14 ) ;
F_158 ( & V_14 -> V_9 -> V_40 ) ;
F_13 ( V_14 ) ;
F_159 ( V_221 , V_14 ) ;
F_142 ( V_222 , V_14 ) ;
if ( V_209 != V_213 ) {
F_147 ( V_14 , V_207 ,
V_209 == V_210 ) ;
}
F_160 ( V_14 ) ;
V_111:
F_23 ( V_14 ) ;
}
static int F_161 ( struct V_13 * V_14 , struct V_13 * V_223 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_171 V_169 , * V_224 ;
unsigned long V_225 , V_226 , V_227 , V_228 ;
unsigned long V_229 ;
int V_230 ;
int V_231 = 0 ;
T_1 V_232 ;
unsigned long V_233 = V_17 ;
long V_234 ;
T_2 V_235 ;
F_155 ( & V_9 -> V_40 ) ;
if ( V_223 ) {
F_152 ( & V_223 -> V_40 ) ;
memcpy ( & V_169 . V_236 [ 8 ] , & V_223 -> V_169 . V_236 [ 8 ] , 8 ) ;
F_153 ( & V_223 -> V_40 ) ;
V_224 = & V_169 ;
} else {
V_224 = NULL ;
}
V_237:
F_18 ( V_9 ) ;
if ( V_9 -> V_43 . V_74 <= 0 ) {
F_158 ( & V_9 -> V_40 ) ;
F_48 ( L_9 , V_55 ) ;
F_109 ( V_9 ) ;
V_231 = - 1 ;
goto V_111;
}
F_152 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_238 ++ >= V_9 -> V_43 . V_239 ) {
V_9 -> V_43 . V_74 = - 1 ;
F_153 ( & V_14 -> V_40 ) ;
F_158 ( & V_9 -> V_40 ) ;
F_111 ( L_10 ,
V_55 ) ;
F_109 ( V_9 ) ;
V_231 = - 1 ;
goto V_111;
}
F_21 ( V_14 ) ;
memcpy ( V_169 . V_236 , V_14 -> V_169 . V_236 , 8 ) ;
F_162 ( V_9 , V_224 ) ;
memcpy ( & V_169 . V_236 [ 8 ] , V_9 -> V_240 , 8 ) ;
V_228 = ( V_233 - V_14 -> V_79 ) / V_3 ;
V_229 = V_9 -> V_43 . V_239 *
V_9 -> V_43 . V_241 *
F_163 ( V_9 -> V_51 , V_242 ) / V_3 ;
V_235 = F_164 ( V_9 -> V_43 . V_243 ) ;
V_234 = F_165 ( V_244 ,
V_9 -> V_43 . V_234 ,
V_235 - V_229 ) ;
if ( F_166 ( V_9 -> V_69 > V_234 ) ) {
if ( V_234 > 0 ) {
F_167 ( & V_9 -> V_69 ,
sizeof( V_9 -> V_69 ) ) ;
V_9 -> V_69 %= V_234 ;
} else {
V_9 -> V_69 = 0 ;
}
}
V_226 = F_165 ( V_244 ,
V_14 -> V_176 ,
V_9 -> V_43 . V_245 + V_228 ) ;
V_225 = V_235 + V_228 -
V_9 -> V_69 ;
V_225 = F_165 ( V_244 , V_14 -> V_177 , V_225 ) ;
V_230 = V_14 -> V_200 ;
V_227 = V_14 -> V_79 ;
F_153 ( & V_14 -> V_40 ) ;
F_158 ( & V_9 -> V_40 ) ;
V_228 = ( V_233 - V_227 + V_246 ) / V_3 ;
if ( V_225 <= V_229 + V_228 ) {
F_23 ( V_14 ) ;
F_109 ( V_9 ) ;
V_231 = - 1 ;
goto V_111;
}
V_232 = V_204 ;
if ( V_14 -> V_59 & V_247 )
V_232 |= V_247 ;
V_223 = F_122 ( V_9 , & V_169 , NULL , V_230 ,
F_168 ( & V_169 ) , V_232 ,
V_226 , V_225 ) ;
if ( F_59 ( V_223 ) ) {
F_23 ( V_14 ) ;
F_109 ( V_9 ) ;
F_48 ( L_11 , V_55 ) ;
V_224 = & V_169 ;
F_155 ( & V_9 -> V_40 ) ;
goto V_237;
}
F_152 ( & V_223 -> V_40 ) ;
V_223 -> V_220 = V_14 ;
V_223 -> V_1 = V_233 ;
V_223 -> V_79 = V_227 ;
F_153 ( & V_223 -> V_40 ) ;
F_169 ( V_223 ) ;
F_23 ( V_223 ) ;
F_109 ( V_9 ) ;
V_111:
return V_231 ;
}
static inline int F_170 ( int type )
{
if ( type & ( V_248 | V_249 | V_185 ) )
return 1 ;
return 0 ;
}
static bool F_171 ( struct V_115 * V_115 ,
struct V_8 * V_9 )
{
#ifdef F_172
if ( ! V_9 )
return false ;
if ( ! V_115 -> V_22 . V_129 -> V_250 && ! V_9 -> V_43 . V_250 )
return false ;
if ( ! V_115 -> V_22 . V_129 -> V_251 && ! V_9 -> V_43 . V_251 )
return false ;
return true ;
#else
return false ;
#endif
}
static int F_173 ( struct V_115 * V_115 ,
struct V_252 * V_253 ,
struct V_254 * V_197 ,
int V_20 )
{
int V_231 ;
if ( V_20 <= V_253 -> V_255 ) {
switch ( V_20 ) {
case V_256 :
V_231 = V_253 -> V_257 ;
break;
case V_258 :
V_231 = V_253 -> V_259 ;
break;
default:
V_231 = ! ! F_174 ( V_20 , V_253 -> V_260 ) ;
}
goto V_111;
}
switch ( V_20 ) {
case V_261 :
V_231 = ! ! V_253 -> V_150 ;
break;
case V_262 :
V_231 = F_175 ( & V_253 -> V_150 -> V_169 , V_197 -> V_169 ) ;
break;
case V_256 :
V_231 = F_176 ( V_253 -> V_182 ) ;
if ( V_231 >= V_197 -> V_175 )
V_231 = - V_231 ;
else
V_231 -= 128 ;
V_253 -> V_257 = V_231 ;
break;
case V_263 :
{
T_5 V_264 = V_265 ;
if ( ! F_171 ( V_115 , V_253 -> V_150 -> V_9 ) )
V_264 |= V_247 ;
V_231 = F_170 ( V_253 -> V_182 ) ||
! ( V_253 -> V_150 -> V_59 & V_264 ) ;
break;
}
#ifdef F_177
case V_266 :
{
int V_267 = ! ( V_197 -> V_268 & V_269 ) ;
V_231 = ! ( V_253 -> V_150 -> V_59 & V_270 ) ^ V_267 ;
break;
}
#endif
case V_271 :
V_231 = ( ! V_197 -> V_97 ||
V_197 -> V_97 == V_253 -> V_150 -> V_9 -> V_11 -> V_97 ) ;
break;
case V_272 :
V_231 = F_178 ( V_115 ,
& V_253 -> V_150 -> V_169 , V_253 -> V_182 ,
V_253 -> V_150 -> V_9 -> V_11 -> V_97 ) == V_197 -> V_273 ;
break;
case V_274 :
{
int V_275 = V_197 -> V_268 & ( V_276 | V_277 ) ?
! ! ( V_197 -> V_268 & V_277 ) :
V_253 -> V_150 -> V_9 -> V_43 . V_74 >= 2 ;
V_231 = ( ! ( V_253 -> V_150 -> V_59 & V_204 ) ) ^ V_275 ;
break;
}
case V_278 :
V_231 = ! ( F_179 ( & V_253 -> V_150 -> V_169 ) ^
F_179 ( V_197 -> V_169 ) ) ;
break;
case V_258 :
V_231 = F_180 ( & V_253 -> V_150 -> V_169 , V_197 -> V_169 ) ;
if ( V_231 > V_253 -> V_150 -> V_200 )
V_231 = V_253 -> V_150 -> V_200 ;
V_253 -> V_259 = V_231 ;
break;
#ifdef F_172
case V_279 :
V_231 = ! ( V_253 -> V_150 -> V_59 & V_247 ) ;
break;
#endif
default:
V_231 = 0 ;
}
if ( V_231 )
F_181 ( V_20 , V_253 -> V_260 ) ;
V_253 -> V_255 = V_20 ;
V_111:
return V_231 ;
}
static int F_182 ( struct V_115 * V_115 ,
struct V_254 * V_197 ,
struct V_8 * V_9 ,
struct V_252 * V_280 ,
int V_281 )
{
struct V_252 * V_253 = & V_280 [ 1 - V_281 ] , * V_282 = & V_280 [ V_281 ] ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (score->ifa, &idev->addr_list, if_list) {
int V_20 ;
if ( ( V_253 -> V_150 -> V_59 & V_153 ) &&
( ! ( V_253 -> V_150 -> V_59 & V_247 ) ) )
continue;
V_253 -> V_182 = F_184 ( & V_253 -> V_150 -> V_169 ) ;
if ( F_166 ( V_253 -> V_182 == V_183 ||
V_253 -> V_182 & V_184 ) ) {
F_185 ( L_12 ,
V_9 -> V_11 -> V_56 ) ;
continue;
}
V_253 -> V_255 = - 1 ;
F_186 ( V_253 -> V_260 , V_283 ) ;
for ( V_20 = 0 ; V_20 < V_283 ; V_20 ++ ) {
int V_284 , V_285 ;
V_284 = F_173 ( V_115 , V_282 , V_197 , V_20 ) ;
V_285 = F_173 ( V_115 , V_253 , V_197 , V_20 ) ;
if ( V_284 > V_285 ) {
if ( V_20 == V_256 &&
V_253 -> V_257 > 0 ) {
goto V_111;
}
break;
} else if ( V_284 < V_285 ) {
if ( V_282 -> V_150 )
F_23 ( V_282 -> V_150 ) ;
F_21 ( V_253 -> V_150 ) ;
F_187 ( V_282 , V_253 ) ;
V_281 = 1 - V_281 ;
V_253 -> V_150 = V_282 -> V_150 ;
break;
}
}
}
V_111:
F_188 ( & V_9 -> V_40 ) ;
return V_281 ;
}
static int F_189 ( struct V_115 * V_115 ,
const struct V_10 * V_286 ,
const struct V_10 * V_287 ,
struct V_254 * V_197 ,
struct V_252 * V_280 ,
int V_281 )
{
struct V_8 * V_9 ;
V_9 = F_58 ( V_286 ) ;
if ( V_9 )
V_281 = F_182 ( V_115 , V_197 , V_9 ,
V_280 , V_281 ) ;
V_9 = F_58 ( V_287 ) ;
if ( V_9 )
V_281 = F_182 ( V_115 , V_197 , V_9 ,
V_280 , V_281 ) ;
return V_281 ;
}
int F_190 ( struct V_115 * V_115 , const struct V_10 * V_286 ,
const struct V_171 * V_288 , unsigned int V_268 ,
struct V_171 * V_289 )
{
struct V_252 V_280 [ 2 ] , * V_282 ;
struct V_254 V_197 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_290 ;
bool V_291 = false ;
int V_281 = 0 ;
V_290 = F_184 ( V_288 ) ;
V_197 . V_169 = V_288 ;
V_197 . V_97 = V_286 ? V_286 -> V_97 : 0 ;
V_197 . V_175 = F_176 ( V_290 ) ;
V_197 . V_273 = F_178 ( V_115 , V_288 , V_290 , V_197 . V_97 ) ;
V_197 . V_268 = V_268 ;
V_280 [ V_281 ] . V_255 = - 1 ;
V_280 [ V_281 ] . V_150 = NULL ;
F_85 () ;
if ( V_286 ) {
V_9 = F_58 ( V_286 ) ;
if ( ( V_290 & V_184 ) ||
V_197 . V_175 <= V_292 ||
( V_9 && V_9 -> V_43 . V_293 ) ) {
V_291 = true ;
}
}
if ( V_291 ) {
if ( V_9 )
V_281 = F_182 ( V_115 , & V_197 , V_9 , V_280 , V_281 ) ;
} else {
const struct V_10 * V_287 ;
int V_294 = 0 ;
V_287 = F_191 ( V_286 ) ;
if ( V_287 ) {
V_294 = V_287 -> V_97 ;
V_281 = F_189 ( V_115 , V_286 ,
V_287 , & V_197 ,
V_280 , V_281 ) ;
if ( V_280 [ V_281 ] . V_150 )
goto V_111;
}
F_192 (net, dev) {
if ( F_193 ( V_11 ) != V_294 )
continue;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
continue;
V_281 = F_182 ( V_115 , & V_197 , V_9 , V_280 , V_281 ) ;
}
}
V_111:
F_88 () ;
V_282 = & V_280 [ V_281 ] ;
if ( ! V_282 -> V_150 )
return - V_186 ;
* V_289 = V_282 -> V_150 -> V_169 ;
F_23 ( V_282 -> V_150 ) ;
return 0 ;
}
int F_194 ( struct V_8 * V_9 , struct V_171 * V_169 ,
T_1 V_295 )
{
struct V_13 * V_14 ;
int V_36 = - V_186 ;
F_195 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_175 > V_296 )
break;
if ( V_14 -> V_175 == V_296 &&
! ( V_14 -> V_59 & V_295 ) ) {
* V_169 = V_14 -> V_169 ;
V_36 = 0 ;
break;
}
}
return V_36 ;
}
int F_196 ( struct V_10 * V_11 , struct V_171 * V_169 ,
T_1 V_295 )
{
struct V_8 * V_9 ;
int V_36 = - V_186 ;
F_85 () ;
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
F_183 ( & V_9 -> V_40 ) ;
V_36 = F_194 ( V_9 , V_169 , V_295 ) ;
F_188 ( & V_9 -> V_40 ) ;
}
F_88 () ;
return V_36 ;
}
static int F_197 ( struct V_8 * V_9 )
{
int V_297 = 0 ;
struct V_13 * V_14 ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifp, &idev->addr_list, if_list)
V_297 ++ ;
F_188 ( & V_9 -> V_40 ) ;
return V_297 ;
}
int F_198 ( struct V_115 * V_115 , const struct V_171 * V_169 ,
const struct V_10 * V_11 , int V_298 )
{
return F_199 ( V_115 , V_169 , V_11 , V_298 , V_153 ) ;
}
int F_199 ( struct V_115 * V_115 , const struct V_171 * V_169 ,
const struct V_10 * V_11 , int V_298 ,
T_1 V_295 )
{
struct V_13 * V_14 ;
unsigned int V_181 = F_119 ( V_169 ) ;
T_1 V_299 ;
F_124 () ;
F_87 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_200 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_115 ) )
continue;
V_299 = ( V_14 -> V_59 & V_247 )
? ( V_14 -> V_59 & ~ V_153 )
: V_14 -> V_59 ;
if ( F_175 ( & V_14 -> V_169 , V_169 ) &&
! ( V_299 & V_295 ) &&
( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_175 & ( V_296 | V_300 ) || V_298 ) ) ) {
F_125 () ;
return 1 ;
}
}
F_125 () ;
return 0 ;
}
static bool F_129 ( struct V_115 * V_115 , const struct V_171 * V_169 ,
struct V_10 * V_11 )
{
unsigned int V_181 = F_119 ( V_169 ) ;
struct V_13 * V_14 ;
F_201 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_200 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_115 ) )
continue;
if ( F_175 ( & V_14 -> V_169 , V_169 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 )
return true ;
}
}
return false ;
}
bool F_202 ( const struct V_171 * V_169 ,
const unsigned int V_200 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_150 ;
bool V_231 = false ;
F_85 () ;
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifa, &idev->addr_list, if_list) {
V_231 = F_144 ( V_169 , & V_150 -> V_169 , V_200 ) ;
if ( V_231 )
break;
}
F_188 ( & V_9 -> V_40 ) ;
}
F_88 () ;
return V_231 ;
}
int F_203 ( const struct V_171 * V_169 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_150 ;
int V_301 ;
V_301 = 0 ;
F_85 () ;
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifa, &idev->addr_list, if_list) {
V_301 = F_144 ( V_169 , & V_150 -> V_169 ,
V_150 -> V_200 ) ;
if ( V_301 )
break;
}
F_188 ( & V_9 -> V_40 ) ;
}
F_88 () ;
return V_301 ;
}
struct V_13 * F_204 ( struct V_115 * V_115 , const struct V_171 * V_169 ,
struct V_10 * V_11 , int V_298 )
{
struct V_13 * V_14 , * V_302 = NULL ;
unsigned int V_181 = F_119 ( V_169 ) ;
F_124 () ;
F_205 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_200 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_115 ) )
continue;
if ( F_175 ( & V_14 -> V_169 , V_169 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_175 & ( V_296 | V_300 ) || V_298 ) ) {
V_302 = V_14 ;
F_21 ( V_14 ) ;
break;
}
}
}
F_125 () ;
return V_302 ;
}
static void F_206 ( struct V_13 * V_14 , int V_303 )
{
if ( V_303 )
V_14 -> V_59 |= V_304 ;
if ( V_14 -> V_59 & V_204 ) {
struct V_13 * V_220 ;
F_152 ( & V_14 -> V_40 ) ;
V_220 = V_14 -> V_220 ;
if ( V_220 ) {
F_21 ( V_220 ) ;
F_153 ( & V_14 -> V_40 ) ;
F_161 ( V_220 , V_14 ) ;
F_23 ( V_220 ) ;
} else {
F_153 ( & V_14 -> V_40 ) ;
}
F_151 ( V_14 ) ;
} else if ( V_14 -> V_59 & V_211 || ! V_303 ) {
F_152 ( & V_14 -> V_40 ) ;
F_13 ( V_14 ) ;
V_14 -> V_59 |= V_153 ;
F_153 ( & V_14 -> V_40 ) ;
if ( V_303 )
F_159 ( 0 , V_14 ) ;
F_23 ( V_14 ) ;
} else {
F_151 ( V_14 ) ;
}
}
static int F_207 ( struct V_13 * V_14 )
{
int V_36 = - V_305 ;
F_152 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_164 == V_306 ) {
V_14 -> V_164 = V_307 ;
V_36 = 0 ;
}
F_153 ( & V_14 -> V_40 ) ;
return V_36 ;
}
void F_208 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_115 * V_115 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( F_207 ( V_14 ) ) {
F_23 ( V_14 ) ;
return;
}
F_209 ( L_13 ,
V_14 -> V_9 -> V_11 -> V_56 , & V_14 -> V_169 ) ;
F_152 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_59 & V_308 ) {
int V_175 = V_14 -> V_175 ;
T_1 V_59 = V_14 -> V_59 ;
struct V_171 V_309 ;
struct V_13 * V_310 ;
T_1 V_176 , V_311 ;
int V_174 = V_14 -> V_200 ;
int V_312 = V_14 -> V_313 + 1 ;
if ( V_312 > V_115 -> V_22 . V_314 . V_315 ) {
F_209 ( L_14 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
goto V_316;
}
V_309 = V_14 -> V_169 ;
if ( F_210 ( & V_309 , V_312 ,
V_9 ) )
goto V_316;
V_176 = V_14 -> V_176 ;
V_311 = V_14 -> V_177 ;
F_153 ( & V_14 -> V_40 ) ;
if ( V_9 -> V_43 . V_317 &&
F_197 ( V_9 ) >=
V_9 -> V_43 . V_317 )
goto V_318;
F_209 ( L_15 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_310 = F_122 ( V_9 , & V_309 , NULL , V_174 ,
V_175 , V_59 , V_176 ,
V_311 ) ;
if ( F_59 ( V_310 ) )
goto V_318;
F_152 ( & V_310 -> V_40 ) ;
V_310 -> V_313 = V_312 ;
V_310 -> V_164 = V_319 ;
F_153 ( & V_310 -> V_40 ) ;
F_20 ( V_310 , V_115 -> V_22 . V_314 . V_320 ) ;
F_23 ( V_310 ) ;
V_318:
F_152 ( & V_14 -> V_40 ) ;
}
V_316:
V_14 -> V_164 = V_321 ;
F_153 ( & V_14 -> V_40 ) ;
F_20 ( V_14 , 0 ) ;
F_23 ( V_14 ) ;
}
void F_211 ( struct V_10 * V_11 , const struct V_171 * V_169 )
{
struct V_171 V_322 ;
if ( V_11 -> V_59 & ( V_61 | V_60 ) )
return;
F_212 ( V_169 , & V_322 ) ;
F_55 ( V_11 , & V_322 ) ;
}
void F_213 ( struct V_8 * V_9 , const struct V_171 * V_169 )
{
struct V_171 V_322 ;
if ( V_9 -> V_11 -> V_59 & ( V_61 | V_60 ) )
return;
F_212 ( V_169 , & V_322 ) ;
F_214 ( V_9 , & V_322 ) ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_171 V_169 ;
if ( V_14 -> V_200 >= 127 )
return;
F_215 ( & V_169 , & V_14 -> V_169 , V_14 -> V_200 ) ;
if ( F_216 ( & V_169 ) )
return;
F_217 ( V_14 -> V_9 , & V_169 ) ;
}
static void F_95 ( struct V_13 * V_14 )
{
struct V_171 V_169 ;
if ( V_14 -> V_200 >= 127 )
return;
F_215 ( & V_169 , & V_14 -> V_169 , V_14 -> V_200 ) ;
if ( F_216 ( & V_169 ) )
return;
F_218 ( V_14 -> V_9 , & V_169 ) ;
}
static int F_219 ( T_5 * V_323 , struct V_10 * V_11 )
{
switch ( V_11 -> V_324 ) {
case V_325 :
memcpy ( V_323 , V_11 -> V_326 , 3 ) ;
V_323 [ 3 ] = 0xFF ;
V_323 [ 4 ] = 0xFE ;
memcpy ( V_323 + 5 , V_11 -> V_326 + 3 , 3 ) ;
break;
case V_327 :
memcpy ( V_323 , V_11 -> V_326 , V_327 ) ;
V_323 [ 0 ] ^= 2 ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_220 ( T_5 * V_323 , struct V_10 * V_11 )
{
union V_328 * V_329 ;
if ( V_11 -> V_324 != V_330 )
return - 1 ;
V_329 = (union V_328 * ) V_11 -> V_326 ;
memcpy ( V_323 , & V_329 -> V_331 . V_332 , sizeof( V_329 -> V_331 . V_332 ) ) ;
V_323 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_221 ( T_5 * V_323 , struct V_10 * V_11 )
{
if ( V_11 -> V_324 != V_333 )
return - 1 ;
memset ( V_323 , 0 , 7 ) ;
V_323 [ 7 ] = * ( T_5 * ) V_11 -> V_326 ;
return 0 ;
}
static int F_222 ( T_5 * V_323 , struct V_10 * V_11 )
{
if ( V_11 -> V_324 != V_334 )
return - 1 ;
memcpy ( V_323 , V_11 -> V_326 + 12 , 8 ) ;
V_323 [ 0 ] |= 2 ;
return 0 ;
}
static int F_223 ( T_5 * V_323 , T_6 V_169 )
{
if ( V_169 == 0 )
return - 1 ;
V_323 [ 0 ] = ( F_224 ( V_169 ) || F_225 ( V_169 ) ||
F_226 ( V_169 ) || F_227 ( V_169 ) ||
F_228 ( V_169 ) || F_229 ( V_169 ) ||
F_230 ( V_169 ) || F_231 ( V_169 ) ||
F_232 ( V_169 ) || F_233 ( V_169 ) ||
F_234 ( V_169 ) ) ? 0x00 : 0x02 ;
V_323 [ 1 ] = 0 ;
V_323 [ 2 ] = 0x5E ;
V_323 [ 3 ] = 0xFE ;
memcpy ( V_323 + 4 , & V_169 , 4 ) ;
return 0 ;
}
static int F_235 ( T_5 * V_323 , struct V_10 * V_11 )
{
if ( V_11 -> V_65 & V_66 )
return F_223 ( V_323 , * ( T_6 * ) V_11 -> V_326 ) ;
return - 1 ;
}
static int F_236 ( T_5 * V_323 , struct V_10 * V_11 )
{
return F_223 ( V_323 , * ( T_6 * ) V_11 -> V_326 ) ;
}
static int F_237 ( T_5 * V_323 , struct V_10 * V_11 )
{
memcpy ( V_323 , V_11 -> V_335 , 3 ) ;
memcpy ( V_323 + 5 , V_11 -> V_335 + 3 , 3 ) ;
V_323 [ 3 ] = 0xFF ;
V_323 [ 4 ] = 0xFE ;
V_323 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_238 ( T_5 * V_323 , struct V_10 * V_11 )
{
switch ( V_11 -> type ) {
case V_336 :
case V_337 :
return F_239 ( V_323 , V_11 ) ;
case V_338 :
return F_221 ( V_323 , V_11 ) ;
case V_339 :
return F_222 ( V_323 , V_11 ) ;
case V_64 :
return F_235 ( V_323 , V_11 ) ;
case V_340 :
case V_71 :
return F_236 ( V_323 , V_11 ) ;
case V_341 :
return F_219 ( V_323 , V_11 ) ;
case V_342 :
return F_220 ( V_323 , V_11 ) ;
case V_72 :
case V_343 :
return F_237 ( V_323 , V_11 ) ;
}
return - 1 ;
}
static int F_240 ( T_5 * V_323 , struct V_8 * V_9 )
{
int V_36 = - 1 ;
struct V_13 * V_14 ;
F_183 ( & V_9 -> V_40 ) ;
F_195 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_175 > V_296 )
break;
if ( V_14 -> V_175 == V_296 && ! ( V_14 -> V_59 & V_153 ) ) {
memcpy ( V_323 , V_14 -> V_169 . V_236 + 8 , 8 ) ;
V_36 = 0 ;
break;
}
}
F_188 ( & V_9 -> V_40 ) ;
return V_36 ;
}
static void F_49 ( struct V_8 * V_9 )
{
V_344:
F_167 ( V_9 -> V_240 , sizeof( V_9 -> V_240 ) ) ;
V_9 -> V_240 [ 0 ] &= ~ 0x02 ;
if ( V_9 -> V_240 [ 0 ] == 0xfd &&
( V_9 -> V_240 [ 1 ] & V_9 -> V_240 [ 2 ] & V_9 -> V_240 [ 3 ] & V_9 -> V_240 [ 4 ] & V_9 -> V_240 [ 5 ] & V_9 -> V_240 [ 6 ] ) == 0xff &&
( V_9 -> V_240 [ 7 ] & 0x80 ) )
goto V_344;
if ( ( V_9 -> V_240 [ 0 ] | V_9 -> V_240 [ 1 ] ) == 0 ) {
if ( V_9 -> V_240 [ 2 ] == 0x5e && V_9 -> V_240 [ 3 ] == 0xfe )
goto V_344;
if ( ( V_9 -> V_240 [ 2 ] | V_9 -> V_240 [ 3 ] | V_9 -> V_240 [ 4 ] | V_9 -> V_240 [ 5 ] | V_9 -> V_240 [ 6 ] | V_9 -> V_240 [ 7 ] ) == 0x00 )
goto V_344;
}
}
static void F_162 ( struct V_8 * V_9 , struct V_171 * V_224 )
{
if ( V_224 && memcmp ( V_9 -> V_240 , & V_224 -> V_236 [ 8 ] , 8 ) == 0 )
F_49 ( V_9 ) ;
}
static void
F_241 ( struct V_171 * V_345 , int V_346 , struct V_10 * V_11 ,
unsigned long V_207 , T_1 V_59 )
{
struct V_347 V_348 = {
. V_349 = F_242 ( V_11 ) ? : V_350 ,
. V_351 = V_352 ,
. V_353 = V_11 -> V_97 ,
. V_354 = V_207 ,
. V_355 = V_346 ,
. V_356 = V_357 | V_59 ,
. V_358 . V_359 = F_38 ( V_11 ) ,
. V_360 = V_361 ,
} ;
V_348 . V_362 = * V_345 ;
#if F_47 ( V_63 )
if ( V_11 -> type == V_64 && ( V_11 -> V_59 & V_363 ) )
V_348 . V_356 |= V_364 ;
#endif
F_243 ( & V_348 , NULL ) ;
}
static struct V_178 * F_148 ( const struct V_171 * V_345 ,
int V_346 ,
const struct V_10 * V_11 ,
T_1 V_59 , T_1 V_365 )
{
struct V_366 * V_367 ;
struct V_178 * V_6 = NULL ;
struct V_368 * V_157 ;
T_1 V_369 = F_242 ( V_11 ) ? : V_350 ;
V_157 = F_244 ( F_38 ( V_11 ) , V_369 ) ;
if ( ! V_157 )
return NULL ;
F_183 ( & V_157 -> V_370 ) ;
V_367 = F_245 ( & V_157 -> V_371 , V_345 , V_346 , NULL , 0 ) ;
if ( ! V_367 )
goto V_111;
V_365 |= V_372 ;
for ( V_6 = V_367 -> V_373 ; V_6 ; V_6 = V_6 -> V_197 . V_374 ) {
if ( V_6 -> V_197 . V_11 -> V_97 != V_11 -> V_97 )
continue;
if ( ( V_6 -> V_218 & V_59 ) != V_59 )
continue;
if ( ( V_6 -> V_218 & V_365 ) != 0 )
continue;
F_246 ( & V_6 -> V_197 ) ;
break;
}
V_111:
F_188 ( & V_157 -> V_370 ) ;
return V_6 ;
}
static void F_247 ( struct V_10 * V_11 )
{
struct V_347 V_348 = {
. V_349 = F_242 ( V_11 ) ? : V_375 ,
. V_351 = V_352 ,
. V_353 = V_11 -> V_97 ,
. V_355 = 8 ,
. V_356 = V_357 ,
. V_358 . V_359 = F_38 ( V_11 ) ,
} ;
F_248 ( & V_348 . V_362 , F_249 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_243 ( & V_348 , NULL ) ;
}
static struct V_8 * F_250 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return F_34 ( - V_116 ) ;
if ( V_9 -> V_43 . V_189 )
return F_34 ( - V_190 ) ;
if ( ! ( V_11 -> V_59 & V_61 ) && ! F_251 ( V_11 ) )
F_247 ( V_11 ) ;
return V_9 ;
}
static void F_252 ( struct V_8 * V_9 ,
struct V_13 * V_14 ,
V_244 V_176 , V_244 V_177 ,
bool V_376 , unsigned long V_233 )
{
T_1 V_59 ;
struct V_13 * V_223 ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (ift, &idev->tempaddr_list, tmp_list) {
int V_228 , V_377 , V_378 ;
if ( V_14 != V_223 -> V_220 )
continue;
V_228 = ( V_233 - V_223 -> V_1 ) / V_3 ;
V_377 = V_9 -> V_43 . V_245 - V_228 ;
if ( V_377 < 0 )
V_377 = 0 ;
V_378 = V_9 -> V_43 . V_243 -
V_9 -> V_69 - V_228 ;
if ( V_378 < 0 )
V_378 = 0 ;
if ( V_176 > V_377 )
V_176 = V_377 ;
if ( V_177 > V_378 )
V_177 = V_378 ;
F_128 ( & V_223 -> V_40 ) ;
V_59 = V_223 -> V_59 ;
V_223 -> V_176 = V_176 ;
V_223 -> V_177 = V_177 ;
V_223 -> V_79 = V_233 ;
if ( V_177 > 0 )
V_223 -> V_59 &= ~ V_265 ;
F_137 ( & V_223 -> V_40 ) ;
if ( ! ( V_59 & V_153 ) )
F_159 ( 0 , V_223 ) ;
}
if ( ( V_376 || F_253 ( & V_9 -> V_68 ) ) &&
V_9 -> V_43 . V_74 > 0 ) {
F_188 ( & V_9 -> V_40 ) ;
F_161 ( V_14 , NULL ) ;
} else {
F_188 ( & V_9 -> V_40 ) ;
}
}
static bool F_254 ( struct V_8 * V_9 )
{
return V_9 -> V_43 . V_47 == V_48 ||
V_9 -> V_43 . V_47 == V_379 ;
}
int F_255 ( struct V_115 * V_115 , struct V_10 * V_11 ,
const struct V_380 * V_381 ,
struct V_8 * V_126 ,
const struct V_171 * V_169 , int V_182 ,
T_1 V_232 , bool V_382 , bool V_202 ,
V_244 V_176 , T_1 V_177 )
{
struct V_13 * V_14 = F_204 ( V_115 , V_169 , V_11 , 1 ) ;
int V_376 = 0 , V_383 = 0 ;
if ( ! V_14 && V_176 ) {
int V_317 = V_126 -> V_43 . V_317 ;
#ifdef F_172
if ( ( V_115 -> V_22 . V_129 -> V_250 ||
V_126 -> V_43 . V_250 ) &&
! V_115 -> V_22 . V_129 -> V_53 && V_382 )
V_232 |= V_247 ;
#endif
if ( ! V_317 ||
F_197 ( V_126 ) < V_317 )
V_14 = F_122 ( V_126 , V_169 , NULL ,
V_381 -> V_200 ,
V_182 & V_384 ,
V_232 , V_176 ,
V_177 ) ;
if ( F_256 ( V_14 ) )
return - 1 ;
V_383 = 0 ;
V_376 = 1 ;
F_152 ( & V_14 -> V_40 ) ;
V_14 -> V_59 |= V_385 ;
V_14 -> V_1 = V_17 ;
V_14 -> V_202 = V_202 ;
F_153 ( & V_14 -> V_40 ) ;
F_169 ( V_14 ) ;
}
if ( V_14 ) {
T_1 V_59 ;
unsigned long V_233 ;
T_1 V_386 ;
F_152 ( & V_14 -> V_40 ) ;
V_233 = V_17 ;
if ( V_14 -> V_176 > ( V_233 - V_14 -> V_79 ) / V_3 )
V_386 = V_14 -> V_176 - ( V_233 - V_14 -> V_79 ) / V_3 ;
else
V_386 = 0 ;
if ( ! V_383 && ! V_376 && V_386 ) {
const T_1 V_387 = F_165 ( T_1 ,
V_386 , V_388 ) ;
V_176 = F_257 ( V_176 , V_387 ) ;
V_383 = 1 ;
}
if ( V_383 ) {
V_14 -> V_176 = V_176 ;
V_14 -> V_177 = V_177 ;
V_14 -> V_79 = V_233 ;
V_59 = V_14 -> V_59 ;
V_14 -> V_59 &= ~ V_265 ;
F_153 ( & V_14 -> V_40 ) ;
if ( ! ( V_59 & V_153 ) )
F_159 ( 0 , V_14 ) ;
} else
F_153 ( & V_14 -> V_40 ) ;
F_252 ( V_126 , V_14 , V_176 , V_177 ,
V_376 , V_233 ) ;
F_23 ( V_14 ) ;
F_258 () ;
}
return 0 ;
}
void F_259 ( struct V_10 * V_11 , T_5 * V_389 , int V_149 , bool V_382 )
{
struct V_380 * V_381 ;
V_244 V_176 ;
V_244 V_177 ;
int V_182 , V_36 ;
T_1 V_232 = 0 ;
struct V_8 * V_126 ;
struct V_115 * V_115 = F_38 ( V_11 ) ;
V_381 = (struct V_380 * ) V_389 ;
if ( V_149 < sizeof( struct V_380 ) ) {
F_42 ( L_16 ) ;
return;
}
V_182 = F_123 ( & V_381 -> V_390 ) ;
if ( V_182 & ( V_184 | V_391 ) )
return;
V_176 = F_260 ( V_381 -> V_392 ) ;
V_177 = F_260 ( V_381 -> V_393 ) ;
if ( V_177 > V_176 ) {
F_261 ( L_17 ) ;
return;
}
V_126 = F_262 ( V_11 ) ;
if ( ! V_126 ) {
F_185 ( L_18 ,
V_11 -> V_56 ) ;
return;
}
if ( V_381 -> V_301 ) {
struct V_178 * V_6 ;
unsigned long V_394 ;
if ( V_3 > V_395 )
V_394 = F_145 ( V_176 , V_3 ) ;
else
V_394 = F_145 ( V_176 , V_395 ) ;
if ( F_263 ( V_394 ) )
V_394 *= V_3 ;
V_6 = F_148 ( & V_381 -> V_390 ,
V_381 -> V_200 ,
V_11 ,
V_396 | V_397 ,
V_216 | V_217 ) ;
if ( V_6 ) {
if ( V_176 == 0 ) {
F_149 ( V_6 ) ;
V_6 = NULL ;
} else if ( F_263 ( V_394 ) ) {
F_150 ( V_6 , V_17 + V_394 ) ;
} else {
F_264 ( V_6 ) ;
}
} else if ( V_176 ) {
T_7 V_207 = 0 ;
int V_59 = V_396 | V_397 ;
if ( F_263 ( V_394 ) ) {
V_59 |= V_219 ;
V_207 = F_265 ( V_394 ) ;
}
F_241 ( & V_381 -> V_390 , V_381 -> V_200 ,
V_11 , V_207 , V_59 ) ;
}
F_112 ( V_6 ) ;
}
if ( V_381 -> V_398 && V_126 -> V_43 . V_398 ) {
struct V_171 V_169 ;
bool V_202 = false , V_399 = false ;
if ( V_381 -> V_200 == 64 ) {
memcpy ( & V_169 , & V_381 -> V_390 , 8 ) ;
if ( ! F_216 ( & V_126 -> V_75 ) ) {
F_183 ( & V_126 -> V_40 ) ;
memcpy ( V_169 . V_236 + 8 ,
V_126 -> V_75 . V_236 + 8 , 8 ) ;
F_188 ( & V_126 -> V_40 ) ;
V_202 = true ;
} else if ( F_254 ( V_126 ) &&
! F_210 ( & V_169 , 0 ,
V_126 ) ) {
V_232 |= V_308 ;
goto V_400;
} else if ( F_238 ( V_169 . V_236 + 8 , V_11 ) &&
F_240 ( V_169 . V_236 + 8 , V_126 ) ) {
goto V_401;
} else {
V_399 = true ;
}
goto V_400;
}
F_185 ( L_19 ,
V_381 -> V_200 ) ;
goto V_401;
V_400:
V_36 = F_255 ( V_115 , V_11 , V_381 , V_126 ,
& V_169 , V_182 ,
V_232 , V_382 ,
V_202 , V_176 ,
V_177 ) ;
if ( V_36 )
goto V_401;
F_266 ( V_115 , V_11 , V_381 , V_126 , & V_169 ,
V_182 , V_232 , V_382 ,
V_202 , V_176 ,
V_177 ,
V_399 ) ;
}
F_267 ( V_402 , V_126 , V_381 ) ;
V_401:
F_109 ( V_126 ) ;
}
int F_268 ( struct V_115 * V_115 , void T_8 * V_403 )
{
struct V_404 V_405 ;
struct V_10 * V_11 ;
int V_36 = - V_39 ;
F_269 () ;
V_36 = - V_406 ;
if ( F_270 ( & V_405 , V_403 , sizeof( struct V_404 ) ) )
goto V_407;
V_11 = F_81 ( V_115 , V_405 . V_408 ) ;
V_36 = - V_187 ;
if ( ! V_11 )
goto V_407;
#if F_47 ( V_63 )
if ( V_11 -> type == V_64 ) {
const struct V_409 * V_410 = V_11 -> V_411 ;
struct V_412 V_413 ;
struct V_414 V_158 ;
V_36 = - V_186 ;
if ( ! ( F_123 ( & V_405 . V_415 ) & V_249 ) )
goto V_407;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_416 . V_288 = V_405 . V_415 . V_417 [ 3 ] ;
V_158 . V_416 . V_289 = 0 ;
V_158 . V_416 . V_418 = 4 ;
V_158 . V_416 . V_419 = 5 ;
V_158 . V_416 . V_420 = V_421 ;
V_158 . V_416 . V_422 = 64 ;
V_413 . V_423 . V_424 = ( V_425 void T_8 * ) & V_158 ;
if ( V_410 -> V_426 ) {
T_9 V_427 = F_271 () ;
F_272 ( V_428 ) ;
V_36 = V_410 -> V_426 ( V_11 , & V_413 , V_429 ) ;
F_272 ( V_427 ) ;
} else
V_36 = - V_430 ;
if ( V_36 == 0 ) {
V_36 = - V_116 ;
V_11 = F_273 ( V_115 , V_158 . V_56 ) ;
if ( ! V_11 )
goto V_407;
V_36 = F_274 ( V_11 ) ;
}
}
#endif
V_407:
F_101 () ;
return V_36 ;
}
static int F_275 ( struct V_431 * V_122 , bool V_432 ,
const struct V_171 * V_169 , int V_97 )
{
int V_231 ;
F_33 () ;
F_276 ( V_122 ) ;
if ( V_432 )
V_231 = F_277 ( V_122 , V_97 , V_169 ) ;
else
V_231 = F_278 ( V_122 , V_97 , V_169 ) ;
F_279 ( V_122 ) ;
return V_231 ;
}
static int F_280 ( struct V_115 * V_115 , int V_97 ,
const struct V_171 * V_345 ,
const struct V_171 * V_433 ,
unsigned int V_346 , V_244 V_434 ,
V_244 V_177 , V_244 V_176 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned long V_435 ;
T_7 V_207 ;
int V_175 ;
T_1 V_59 ;
F_33 () ;
if ( V_346 > 128 )
return - V_39 ;
if ( ! V_176 || V_177 > V_176 )
return - V_39 ;
if ( V_434 & V_385 && V_346 != 64 )
return - V_39 ;
V_11 = F_81 ( V_115 , V_97 ) ;
if ( ! V_11 )
return - V_187 ;
V_9 = F_250 ( V_11 ) ;
if ( F_59 ( V_9 ) )
return F_131 ( V_9 ) ;
if ( V_434 & V_436 ) {
int V_231 = F_275 ( V_115 -> V_22 . V_437 ,
true , V_345 , V_97 ) ;
if ( V_231 < 0 )
return V_231 ;
}
V_175 = F_168 ( V_345 ) ;
V_435 = F_145 ( V_176 , V_3 ) ;
if ( F_263 ( V_435 ) ) {
V_207 = F_265 ( V_435 * V_3 ) ;
V_176 = V_435 ;
V_59 = V_219 ;
} else {
V_207 = 0 ;
V_59 = 0 ;
V_434 |= V_211 ;
}
V_435 = F_145 ( V_177 , V_3 ) ;
if ( F_263 ( V_435 ) ) {
if ( V_435 == 0 )
V_434 |= V_265 ;
V_177 = V_435 ;
}
V_14 = F_122 ( V_9 , V_345 , V_433 , V_346 , V_175 , V_434 ,
V_176 , V_177 ) ;
if ( ! F_59 ( V_14 ) ) {
if ( ! ( V_434 & V_212 ) ) {
F_241 ( & V_14 -> V_169 , V_14 -> V_200 , V_11 ,
V_207 , V_59 ) ;
}
F_169 ( V_14 ) ;
if ( V_434 & V_385 )
F_252 ( V_9 , V_14 , V_176 , V_177 ,
true , V_17 ) ;
F_23 ( V_14 ) ;
F_281 () ;
return 0 ;
} else if ( V_434 & V_436 ) {
F_275 ( V_115 -> V_22 . V_437 ,
false , V_345 , V_97 ) ;
}
return F_131 ( V_14 ) ;
}
static int F_282 ( struct V_115 * V_115 , int V_97 , T_1 V_434 ,
const struct V_171 * V_345 , unsigned int V_346 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_346 > 128 )
return - V_39 ;
V_11 = F_81 ( V_115 , V_97 ) ;
if ( ! V_11 )
return - V_187 ;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
return - V_438 ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_200 == V_346 &&
F_175 ( V_345 , & V_14 -> V_169 ) ) {
F_21 ( V_14 ) ;
F_188 ( & V_9 -> V_40 ) ;
if ( ! ( V_14 -> V_59 & V_204 ) &&
( V_434 & V_385 ) )
F_252 ( V_9 , V_14 , 0 , 0 , false ,
V_17 ) ;
F_151 ( V_14 ) ;
F_281 () ;
if ( F_283 ( V_345 ) ) {
F_275 ( V_115 -> V_22 . V_437 ,
false , V_345 , V_11 -> V_97 ) ;
}
return 0 ;
}
}
F_188 ( & V_9 -> V_40 ) ;
return - V_186 ;
}
int F_284 ( struct V_115 * V_115 , void T_8 * V_403 )
{
struct V_404 V_405 ;
int V_36 ;
if ( ! F_285 ( V_115 -> V_439 , V_440 ) )
return - V_441 ;
if ( F_270 ( & V_405 , V_403 , sizeof( struct V_404 ) ) )
return - V_406 ;
F_269 () ;
V_36 = F_280 ( V_115 , V_405 . V_408 , & V_405 . V_415 , NULL ,
V_405 . V_442 , V_211 ,
V_443 , V_443 ) ;
F_101 () ;
return V_36 ;
}
int F_286 ( struct V_115 * V_115 , void T_8 * V_403 )
{
struct V_404 V_405 ;
int V_36 ;
if ( ! F_285 ( V_115 -> V_439 , V_440 ) )
return - V_441 ;
if ( F_270 ( & V_405 , V_403 , sizeof( struct V_404 ) ) )
return - V_406 ;
F_269 () ;
V_36 = F_282 ( V_115 , V_405 . V_408 , 0 , & V_405 . V_415 ,
V_405 . V_442 ) ;
F_101 () ;
return V_36 ;
}
static void F_287 ( struct V_8 * V_9 , const struct V_171 * V_169 ,
int V_346 , int V_175 )
{
struct V_13 * V_14 ;
V_14 = F_122 ( V_9 , V_169 , NULL , V_346 ,
V_175 , V_211 ,
V_443 , V_443 ) ;
if ( ! F_59 ( V_14 ) ) {
F_152 ( & V_14 -> V_40 ) ;
V_14 -> V_59 &= ~ V_153 ;
F_153 ( & V_14 -> V_40 ) ;
F_288 ( F_38 ( V_9 -> V_11 ) ) ;
F_159 ( V_444 , V_14 ) ;
F_23 ( V_14 ) ;
}
}
static void F_289 ( struct V_8 * V_9 )
{
struct V_171 V_169 ;
struct V_10 * V_11 ;
struct V_115 * V_115 = F_38 ( V_9 -> V_11 ) ;
int V_175 , V_346 ;
T_1 V_445 = 0 ;
F_33 () ;
memset ( & V_169 , 0 , sizeof( struct V_171 ) ) ;
memcpy ( & V_169 . V_417 [ 3 ] , V_9 -> V_11 -> V_326 , 4 ) ;
if ( V_9 -> V_11 -> V_59 & V_363 ) {
V_169 . V_417 [ 0 ] = F_249 ( 0xfe800000 ) ;
V_175 = V_296 ;
V_346 = 64 ;
} else {
V_175 = V_249 ;
V_346 = 96 ;
V_445 |= V_364 ;
}
if ( V_169 . V_417 [ 3 ] ) {
F_287 ( V_9 , & V_169 , V_346 , V_175 ) ;
F_241 ( & V_169 , V_346 , V_9 -> V_11 , 0 , V_445 ) ;
return;
}
F_97 (net, dev) {
struct V_446 * V_447 = F_290 ( V_11 ) ;
if ( V_447 && ( V_11 -> V_59 & V_86 ) ) {
struct V_448 * V_150 ;
int V_449 = V_175 ;
for ( V_150 = V_447 -> V_450 ; V_150 ; V_150 = V_150 -> V_451 ) {
V_169 . V_417 [ 3 ] = V_150 -> V_452 ;
if ( V_150 -> V_453 == V_454 )
continue;
if ( V_150 -> V_453 >= V_455 ) {
if ( V_9 -> V_11 -> V_59 & V_363 )
continue;
V_449 |= V_300 ;
}
F_287 ( V_9 , & V_169 , V_346 , V_449 ) ;
F_241 ( & V_169 , V_346 , V_9 -> V_11 , 0 ,
V_445 ) ;
}
}
}
}
static void F_291 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 ) {
F_108 ( L_20 , V_55 ) ;
return;
}
F_287 ( V_9 , & V_456 , 128 , V_300 ) ;
}
void F_292 ( struct V_8 * V_9 ,
const struct V_171 * V_169 , T_1 V_59 )
{
struct V_13 * V_14 ;
T_1 V_232 = V_59 | V_211 ;
#ifdef F_172
if ( ( F_38 ( V_9 -> V_11 ) -> V_22 . V_129 -> V_250 ||
V_9 -> V_43 . V_250 ) &&
! F_38 ( V_9 -> V_11 ) -> V_22 . V_129 -> V_53 )
V_232 |= V_247 ;
#endif
V_14 = F_122 ( V_9 , V_169 , NULL , 64 , V_296 , V_232 ,
V_443 , V_443 ) ;
if ( ! F_59 ( V_14 ) ) {
F_241 ( & V_14 -> V_169 , V_14 -> V_200 , V_9 -> V_11 , 0 , 0 ) ;
F_169 ( V_14 ) ;
F_23 ( V_14 ) ;
}
}
static bool F_293 ( struct V_171 V_457 )
{
if ( ( V_457 . V_417 [ 2 ] | V_457 . V_417 [ 3 ] ) == 0 )
return true ;
if ( V_457 . V_417 [ 2 ] == F_249 ( 0x02005eff ) &&
( ( V_457 . V_417 [ 3 ] & F_249 ( 0xfe000000 ) ) == F_249 ( 0xfe000000 ) ) )
return true ;
if ( V_457 . V_417 [ 2 ] == F_249 ( 0xfdffffff ) &&
( ( V_457 . V_417 [ 3 ] & F_249 ( 0xffffff80 ) ) == F_249 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_210 ( struct V_171 * V_457 ,
T_5 V_458 ,
const struct V_8 * V_9 )
{
static F_294 ( V_40 ) ;
static V_244 V_459 [ V_460 ] ;
static V_244 V_461 [ V_462 ] ;
static union {
char V_463 [ V_464 ] ;
struct {
struct V_171 V_465 ;
T_6 V_390 [ 2 ] ;
unsigned char V_466 [ V_467 ] ;
T_5 V_458 ;
} V_468 ;
} V_469 ;
struct V_171 V_465 ;
struct V_171 V_470 ;
struct V_115 * V_115 = F_38 ( V_9 -> V_11 ) ;
F_295 ( sizeof( V_469 . V_463 ) != sizeof( V_469 ) ) ;
if ( V_9 -> V_43 . V_45 . V_46 )
V_465 = V_9 -> V_43 . V_45 . V_465 ;
else if ( V_115 -> V_22 . V_44 -> V_45 . V_46 )
V_465 = V_115 -> V_22 . V_44 -> V_45 . V_465 ;
else
return - 1 ;
V_237:
F_152 ( & V_40 ) ;
F_296 ( V_459 ) ;
memset ( & V_469 , 0 , sizeof( V_469 ) ) ;
memset ( V_461 , 0 , sizeof( V_461 ) ) ;
memcpy ( V_469 . V_466 , V_9 -> V_11 -> V_335 , V_9 -> V_11 -> V_324 ) ;
V_469 . V_390 [ 0 ] = V_457 -> V_417 [ 0 ] ;
V_469 . V_390 [ 1 ] = V_457 -> V_417 [ 1 ] ;
V_469 . V_465 = V_465 ;
V_469 . V_458 = V_458 ;
F_297 ( V_459 , V_469 . V_463 , V_461 ) ;
V_470 = * V_457 ;
V_470 . V_417 [ 2 ] = ( V_425 T_6 ) V_459 [ 0 ] ;
V_470 . V_417 [ 3 ] = ( V_425 T_6 ) V_459 [ 1 ] ;
F_153 ( & V_40 ) ;
if ( F_293 ( V_470 ) ) {
V_458 ++ ;
if ( V_458 > F_38 ( V_9 -> V_11 ) -> V_22 . V_314 . V_315 )
return - 1 ;
goto V_237;
}
* V_457 = V_470 ;
return 0 ;
}
static void F_298 ( struct V_8 * V_9 )
{
struct V_471 * V_472 = & V_9 -> V_43 . V_45 ;
if ( V_472 -> V_46 )
return;
V_472 = & V_9 -> V_43 . V_45 ;
F_167 ( & V_472 -> V_465 , sizeof( V_472 -> V_465 ) ) ;
V_472 -> V_46 = true ;
}
static void F_299 ( struct V_8 * V_9 , bool V_473 )
{
struct V_171 V_169 ;
if ( F_251 ( V_9 -> V_11 ) )
return;
F_248 ( & V_169 , F_249 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_9 -> V_43 . V_47 ) {
case V_379 :
F_298 ( V_9 ) ;
case V_48 :
if ( ! F_210 ( & V_169 , 0 , V_9 ) )
F_292 ( V_9 , & V_169 ,
V_308 ) ;
else if ( V_473 )
F_241 ( & V_169 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_474 :
if ( F_238 ( V_169 . V_236 + 8 , V_9 -> V_11 ) == 0 )
F_292 ( V_9 , & V_169 , 0 ) ;
else if ( V_473 )
F_241 ( & V_169 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_475 :
default:
break;
}
}
static void F_300 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
if ( ( V_11 -> type != V_336 ) &&
( V_11 -> type != V_337 ) &&
( V_11 -> type != V_338 ) &&
( V_11 -> type != V_339 ) &&
( V_11 -> type != V_342 ) &&
( V_11 -> type != V_72 ) &&
( V_11 -> type != V_341 ) &&
( V_11 -> type != V_343 ) &&
( V_11 -> type != V_340 ) &&
( V_11 -> type != V_71 ) &&
( V_11 -> type != V_73 ) ) {
return;
}
V_9 = F_250 ( V_11 ) ;
if ( F_59 ( V_9 ) )
return;
if ( V_11 -> type == V_73 &&
V_9 -> V_43 . V_47 == V_474 )
V_9 -> V_43 . V_47 = V_379 ;
F_299 ( V_9 , false ) ;
}
static void F_301 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 ) {
F_108 ( L_20 , V_55 ) ;
return;
}
if ( V_11 -> V_65 & V_66 ) {
F_299 ( V_9 , false ) ;
return;
}
F_289 ( V_9 ) ;
if ( V_11 -> V_59 & V_363 )
F_247 ( V_11 ) ;
}
static void F_302 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 ) {
F_108 ( L_20 , V_55 ) ;
return;
}
F_299 ( V_9 , true ) ;
if ( V_11 -> V_59 & V_363 )
F_247 ( V_11 ) ;
}
static int F_303 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_6 || ! V_14 -> V_6 -> V_476 ) {
struct V_178 * V_6 , * V_477 ;
V_6 = F_130 ( V_9 , & V_14 -> V_169 , false ) ;
if ( F_166 ( F_59 ( V_6 ) ) )
return F_131 ( V_6 ) ;
F_128 ( & V_14 -> V_40 ) ;
V_477 = V_14 -> V_6 ;
V_14 -> V_6 = V_6 ;
F_137 ( & V_14 -> V_40 ) ;
F_112 ( V_477 ) ;
}
if ( ! ( V_14 -> V_59 & V_212 ) ) {
F_241 ( & V_14 -> V_169 , V_14 -> V_200 ,
V_9 -> V_11 , 0 , 0 ) ;
}
if ( V_14 -> V_164 == V_319 )
F_169 ( V_14 ) ;
return 0 ;
}
static void F_304 ( struct V_10 * V_11 )
{
struct V_13 * V_14 , * V_5 ;
struct V_8 * V_9 ;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
return;
F_155 ( & V_9 -> V_40 ) ;
F_305 (ifp, tmp, &idev->addr_list, if_list) {
if ( ( V_14 -> V_59 & V_211 ) &&
F_303 ( V_9 , V_14 ) < 0 ) {
F_158 ( & V_9 -> V_40 ) ;
F_21 ( V_14 ) ;
F_151 ( V_14 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_209 ( L_21 ,
V_9 -> V_11 -> V_56 , & V_14 -> V_169 ) ;
}
}
F_158 ( & V_9 -> V_40 ) ;
}
static int F_306 ( struct V_478 * V_479 , unsigned long V_102 ,
void * V_480 )
{
struct V_10 * V_11 = F_307 ( V_480 ) ;
struct V_481 * V_482 ;
struct V_8 * V_9 = F_58 ( V_11 ) ;
struct V_115 * V_115 = F_38 ( V_11 ) ;
int V_483 = 0 ;
int V_36 ;
switch ( V_102 ) {
case V_484 :
if ( ! V_9 && V_11 -> V_37 >= V_38 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_59 ( V_9 ) )
return F_308 ( F_131 ( V_9 ) ) ;
}
break;
case V_485 :
if ( V_11 -> V_37 < V_38 ) {
F_309 ( V_11 , V_11 != V_115 -> V_486 ) ;
break;
}
if ( V_9 ) {
F_310 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
break;
}
V_9 = F_32 ( V_11 ) ;
if ( F_59 ( V_9 ) )
break;
if ( ! ( V_9 -> V_77 & V_78 ) )
break;
V_483 = 1 ;
case V_193 :
case V_487 :
if ( V_11 -> V_59 & V_488 )
break;
if ( V_9 && V_9 -> V_43 . V_189 )
break;
if ( V_102 == V_193 ) {
F_304 ( V_11 ) ;
if ( ! F_8 ( V_11 ) ) {
F_48 ( L_22 ,
V_11 -> V_56 ) ;
break;
}
if ( ! V_9 && V_11 -> V_37 >= V_38 )
V_9 = F_32 ( V_11 ) ;
if ( ! F_256 ( V_9 ) ) {
V_9 -> V_77 |= V_78 ;
V_483 = 1 ;
}
} else if ( V_102 == V_487 ) {
if ( ! F_8 ( V_11 ) ) {
break;
}
if ( V_9 ) {
if ( V_9 -> V_77 & V_78 ) {
F_60 ( V_9 ) ;
break;
}
V_9 -> V_77 |= V_78 ;
}
F_48 ( L_23 ,
V_11 -> V_56 ) ;
V_483 = 1 ;
}
switch ( V_11 -> type ) {
#if F_47 ( V_63 )
case V_64 :
F_301 ( V_11 ) ;
break;
#endif
#if F_47 ( V_489 )
case V_340 :
F_302 ( V_11 ) ;
break;
#endif
case V_490 :
F_291 ( V_11 ) ;
break;
default:
F_300 ( V_11 ) ;
break;
}
if ( ! F_256 ( V_9 ) ) {
if ( V_483 )
F_311 ( V_9 ) ;
if ( V_9 -> V_43 . V_50 != V_11 -> V_37 &&
V_11 -> V_37 >= V_38 ) {
F_310 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
}
V_9 -> V_79 = V_17 ;
F_312 ( V_491 , V_9 ) ;
if ( V_11 -> V_37 < V_38 )
F_309 ( V_11 , V_11 != V_115 -> V_486 ) ;
}
break;
case V_222 :
case V_492 :
F_309 ( V_11 , V_102 != V_222 ) ;
break;
case V_493 :
if ( V_9 ) {
F_53 ( V_9 ) ;
F_7 ( V_9 ) ;
V_36 = F_6 ( V_9 ) ;
if ( V_36 )
return F_308 ( V_36 ) ;
V_36 = F_45 ( V_9 ) ;
if ( V_36 ) {
F_7 ( V_9 ) ;
return F_308 ( V_36 ) ;
}
}
break;
case V_494 :
case V_495 :
if ( V_9 )
F_313 ( V_11 , V_102 ) ;
break;
case V_496 :
V_482 = V_480 ;
if ( V_482 -> V_497 && F_251 ( V_482 -> V_497 ) )
F_309 ( V_11 , 0 ) ;
}
return V_498 ;
}
static void F_313 ( struct V_10 * V_11 , unsigned long V_102 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_58 ( V_11 ) ;
if ( V_102 == V_495 )
F_314 ( V_9 ) ;
else if ( V_102 == V_494 )
F_315 ( V_9 ) ;
}
static bool F_316 ( const struct V_171 * V_169 )
{
return F_123 ( V_169 ) &
( V_391 | V_185 ) ;
}
static int F_309 ( struct V_10 * V_11 , int V_499 )
{
struct V_115 * V_115 = F_38 ( V_11 ) ;
struct V_8 * V_9 ;
struct V_13 * V_150 , * V_5 ;
struct V_167 V_500 ;
int V_501 ;
bool V_502 ;
int V_164 , V_20 ;
F_33 () ;
F_317 ( V_115 , V_11 ) ;
F_318 ( & V_52 , V_11 ) ;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
return - V_187 ;
if ( V_499 ) {
V_9 -> V_85 = 1 ;
F_319 ( V_11 -> V_80 , NULL ) ;
F_53 ( V_9 ) ;
}
V_501 = V_115 -> V_22 . V_129 -> V_503 ;
if ( ! V_501 )
V_501 = V_9 -> V_43 . V_503 ;
V_502 = ! ( V_499 || V_501 <= 0 || V_9 -> V_43 . V_189 ) ;
for ( V_20 = 0 ; V_20 < V_504 ; V_20 ++ ) {
struct V_140 * V_136 = & V_203 [ V_20 ] ;
F_152 ( & V_194 ) ;
V_505:
F_87 (ifa, h, addr_lst) {
if ( V_150 -> V_9 == V_9 ) {
F_13 ( V_150 ) ;
if ( ! V_502 ||
! ( V_150 -> V_59 & V_211 ) ||
F_316 ( & V_150 -> V_169 ) ) {
F_154 ( & V_150 -> V_163 ) ;
goto V_505;
}
}
}
F_153 ( & V_194 ) ;
}
F_155 ( & V_9 -> V_40 ) ;
F_10 ( V_9 ) ;
if ( ! V_499 )
V_9 -> V_77 &= ~ ( V_506 | V_507 | V_78 ) ;
while ( ! F_253 ( & V_9 -> V_68 ) ) {
V_150 = F_320 ( & V_9 -> V_68 ,
struct V_13 , V_205 ) ;
F_156 ( & V_150 -> V_205 ) ;
F_158 ( & V_9 -> V_40 ) ;
F_152 ( & V_150 -> V_40 ) ;
if ( V_150 -> V_220 ) {
F_23 ( V_150 -> V_220 ) ;
V_150 -> V_220 = NULL ;
}
F_153 ( & V_150 -> V_40 ) ;
F_23 ( V_150 ) ;
F_155 ( & V_9 -> V_40 ) ;
}
V_502 = ( ! V_499 && V_501 > 0 && ! V_9 -> V_43 . V_189 ) ;
F_36 ( & V_500 ) ;
F_305 (ifa, tmp, &idev->addr_list, if_list) {
struct V_178 * V_6 = NULL ;
bool V_508 ;
F_13 ( V_150 ) ;
V_508 = V_502 && ( V_150 -> V_59 & V_211 ) &&
! F_316 ( & V_150 -> V_169 ) ;
if ( ! V_508 )
F_321 ( & V_150 -> V_170 , & V_500 ) ;
F_158 ( & V_9 -> V_40 ) ;
F_152 ( & V_150 -> V_40 ) ;
if ( V_508 ) {
V_164 = V_165 ;
V_150 -> V_164 = V_319 ;
if ( ! ( V_150 -> V_59 & V_201 ) )
V_150 -> V_59 |= V_153 ;
V_6 = V_150 -> V_6 ;
V_150 -> V_6 = NULL ;
} else {
V_164 = V_150 -> V_164 ;
V_150 -> V_164 = V_165 ;
}
F_153 ( & V_150 -> V_40 ) ;
if ( V_6 )
F_149 ( V_6 ) ;
if ( V_164 != V_165 ) {
F_322 ( V_221 , V_150 ) ;
F_142 ( V_222 , V_150 ) ;
} else {
if ( V_9 -> V_43 . V_53 )
F_95 ( V_150 ) ;
F_213 ( V_150 -> V_9 , & V_150 -> V_169 ) ;
}
F_155 ( & V_9 -> V_40 ) ;
}
F_158 ( & V_9 -> V_40 ) ;
while ( ! F_253 ( & V_500 ) ) {
V_150 = F_320 ( & V_500 ,
struct V_13 , V_170 ) ;
F_156 ( & V_150 -> V_170 ) ;
F_23 ( V_150 ) ;
}
if ( V_499 ) {
F_323 ( V_9 ) ;
F_52 ( V_9 ) ;
} else {
F_324 ( V_9 ) ;
}
V_9 -> V_79 = V_17 ;
if ( V_499 ) {
F_7 ( V_9 ) ;
F_43 ( & V_52 , V_9 -> V_51 ) ;
F_318 ( & V_52 , V_11 ) ;
F_109 ( V_9 ) ;
}
return 0 ;
}
static void V_42 ( unsigned long V_469 )
{
struct V_8 * V_9 = (struct V_8 * ) V_469 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_171 V_509 ;
F_138 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_85 || ! ( V_9 -> V_77 & V_78 ) )
goto V_111;
if ( ! F_325 ( V_9 ) )
goto V_111;
if ( V_9 -> V_77 & V_507 )
goto V_111;
if ( V_9 -> V_510 ++ < V_9 -> V_43 . V_67 || V_9 -> V_43 . V_67 < 0 ) {
F_140 ( & V_9 -> V_40 ) ;
if ( ! F_196 ( V_11 , & V_509 , V_153 ) )
F_326 ( V_11 , & V_509 ,
& V_84 ) ;
else
goto V_401;
F_138 ( & V_9 -> V_40 ) ;
V_9 -> V_511 = F_5 (
V_9 -> V_511 , V_9 -> V_43 . V_512 ) ;
F_16 ( V_9 , ( V_9 -> V_510 ==
V_9 -> V_43 . V_67 ) ?
V_9 -> V_43 . V_513 :
V_9 -> V_511 ) ;
} else {
F_108 ( L_24 , V_9 -> V_11 -> V_56 ) ;
}
V_111:
F_140 ( & V_9 -> V_40 ) ;
V_401:
F_109 ( V_9 ) ;
}
static void F_327 ( struct V_13 * V_14 )
{
unsigned long V_514 ;
struct V_8 * V_9 = V_14 -> V_9 ;
T_3 V_515 ;
if ( V_14 -> V_59 & V_247 )
V_514 = 0 ;
else
V_514 = F_3 () % ( V_9 -> V_43 . V_513 ? : 1 ) ;
V_515 = 0 ;
if ( V_9 -> V_43 . V_516 ||
F_38 ( V_9 -> V_11 ) -> V_22 . V_129 -> V_516 ) {
do
F_167 ( & V_515 , 6 ) ;
while ( V_515 == 0 );
}
V_14 -> V_517 = V_515 ;
V_14 -> V_518 = V_9 -> V_43 . V_241 ;
F_20 ( V_14 , V_514 ) ;
}
static void F_328 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_519 , V_520 = false ;
F_211 ( V_11 , & V_14 -> V_169 ) ;
F_329 ( ( V_425 T_1 ) V_14 -> V_169 . V_417 [ 3 ] ) ;
F_183 ( & V_9 -> V_40 ) ;
F_128 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_164 == V_165 )
goto V_111;
if ( V_11 -> V_59 & ( V_60 | V_61 ) ||
( F_38 ( V_11 ) -> V_22 . V_129 -> V_62 < 1 &&
V_9 -> V_43 . V_62 < 1 ) ||
! ( V_14 -> V_59 & V_153 ) ||
V_14 -> V_59 & V_201 ) {
V_519 = V_14 -> V_59 & V_153 ;
V_14 -> V_59 &= ~ ( V_153 | V_247 | V_304 ) ;
F_137 ( & V_14 -> V_40 ) ;
F_188 ( & V_9 -> V_40 ) ;
F_330 ( V_14 , V_519 ) ;
return;
}
if ( ! ( V_9 -> V_77 & V_78 ) ) {
F_137 ( & V_14 -> V_40 ) ;
F_188 ( & V_9 -> V_40 ) ;
F_21 ( V_14 ) ;
F_206 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_59 & V_247 ) {
F_331 ( V_14 -> V_6 ) ;
if ( F_171 ( F_38 ( V_11 ) , V_9 ) ) {
V_520 = true ;
}
}
F_327 ( V_14 ) ;
V_111:
F_137 ( & V_14 -> V_40 ) ;
F_188 ( & V_9 -> V_40 ) ;
if ( V_520 )
F_159 ( V_444 , V_14 ) ;
}
static void F_169 ( struct V_13 * V_14 )
{
bool V_521 = false ;
F_152 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_164 != V_165 ) {
V_14 -> V_164 = V_319 ;
V_521 = true ;
}
F_153 ( & V_14 -> V_40 ) ;
if ( V_521 )
F_20 ( V_14 , 0 ) ;
}
static void V_199 ( struct V_522 * V_523 )
{
struct V_13 * V_14 = F_332 ( F_333 ( V_523 ) ,
struct V_13 ,
V_15 ) ;
struct V_8 * V_9 = V_14 -> V_9 ;
bool V_519 , V_189 = false ;
struct V_171 V_524 ;
enum {
V_525 ,
V_526 ,
V_527 ,
} V_209 = V_525 ;
F_269 () ;
F_152 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_164 == V_319 ) {
V_209 = V_526 ;
V_14 -> V_164 = V_306 ;
} else if ( V_14 -> V_164 == V_321 ) {
V_209 = V_527 ;
V_14 -> V_164 = V_307 ;
if ( ( F_38 ( V_9 -> V_11 ) -> V_22 . V_129 -> V_62 > 1 ||
V_9 -> V_43 . V_62 > 1 ) &&
! V_9 -> V_43 . V_189 &&
! ( V_14 -> V_59 & V_308 ) ) {
struct V_171 V_169 ;
V_169 . V_417 [ 0 ] = F_249 ( 0xfe800000 ) ;
V_169 . V_417 [ 1 ] = 0 ;
if ( ! F_238 ( V_169 . V_236 + 8 , V_9 -> V_11 ) &&
F_175 ( & V_14 -> V_169 , & V_169 ) ) {
V_9 -> V_43 . V_189 = 1 ;
F_48 ( L_25 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_189 = true ;
}
}
}
F_153 ( & V_14 -> V_40 ) ;
if ( V_209 == V_526 ) {
F_328 ( V_14 ) ;
goto V_111;
} else if ( V_209 == V_527 ) {
F_21 ( V_14 ) ;
F_206 ( V_14 , 1 ) ;
if ( V_189 )
F_309 ( V_9 -> V_11 , 0 ) ;
goto V_111;
}
if ( ! V_14 -> V_518 && F_207 ( V_14 ) )
goto V_111;
F_155 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_85 || ! ( V_9 -> V_77 & V_78 ) ) {
F_158 ( & V_9 -> V_40 ) ;
goto V_111;
}
F_128 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_164 == V_165 ) {
F_137 ( & V_14 -> V_40 ) ;
F_158 ( & V_9 -> V_40 ) ;
goto V_111;
}
if ( V_14 -> V_518 == 0 ) {
V_519 = V_14 -> V_59 & V_153 ;
V_14 -> V_59 &= ~ ( V_153 | V_247 | V_304 ) ;
F_137 ( & V_14 -> V_40 ) ;
F_158 ( & V_9 -> V_40 ) ;
F_330 ( V_14 , V_519 ) ;
goto V_111;
}
V_14 -> V_518 -- ;
F_20 ( V_14 ,
F_163 ( V_14 -> V_9 -> V_51 , V_242 ) ) ;
F_137 ( & V_14 -> V_40 ) ;
F_158 ( & V_9 -> V_40 ) ;
F_212 ( & V_14 -> V_169 , & V_524 ) ;
F_334 ( V_14 -> V_9 -> V_11 , & V_14 -> V_169 , & V_524 , & V_76 ,
V_14 -> V_517 ) ;
V_111:
F_23 ( V_14 ) ;
F_101 () ;
}
static bool F_335 ( struct V_13 * V_14 )
{
struct V_13 * V_528 ;
struct V_8 * V_9 = V_14 -> V_9 ;
F_195 (ifpiter, &idev->addr_list, if_list) {
if ( V_528 -> V_175 > V_296 )
break;
if ( V_14 != V_528 && V_528 -> V_175 == V_296 &&
( V_528 -> V_59 & ( V_211 | V_153 |
V_247 | V_304 ) ) ==
V_211 )
return false ;
}
return true ;
}
static void F_330 ( struct V_13 * V_14 , bool V_519 )
{
struct V_10 * V_11 = V_14 -> V_9 -> V_11 ;
struct V_171 V_509 ;
bool V_529 , V_530 ;
F_13 ( V_14 ) ;
F_159 ( V_444 , V_14 ) ;
F_183 ( & V_14 -> V_9 -> V_40 ) ;
V_530 = V_14 -> V_175 == V_296 && F_335 ( V_14 ) ;
V_529 = V_530 &&
F_325 ( V_14 -> V_9 ) &&
V_14 -> V_9 -> V_43 . V_67 != 0 &&
( V_11 -> V_59 & V_61 ) == 0 ;
F_188 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_530 )
F_336 ( V_14 -> V_9 ) ;
if ( V_529 ) {
if ( F_196 ( V_11 , & V_509 , V_153 ) )
return;
F_326 ( V_11 , & V_509 , & V_84 ) ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
F_128 ( & V_14 -> V_40 ) ;
V_14 -> V_9 -> V_511 = F_2 (
V_14 -> V_9 -> V_43 . V_531 ) ;
V_14 -> V_9 -> V_510 = 1 ;
V_14 -> V_9 -> V_77 |= V_506 ;
F_16 ( V_14 -> V_9 , V_14 -> V_9 -> V_511 ) ;
F_137 ( & V_14 -> V_40 ) ;
F_158 ( & V_14 -> V_9 -> V_40 ) ;
}
if ( V_519 )
F_288 ( F_38 ( V_11 ) ) ;
if ( V_14 -> V_59 & V_204 )
F_281 () ;
}
static void F_311 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifp, &idev->addr_list, if_list) {
F_128 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_59 & V_153 &&
V_14 -> V_164 == V_306 )
F_327 ( V_14 ) ;
F_137 ( & V_14 -> V_40 ) ;
}
F_188 ( & V_9 -> V_40 ) ;
}
static struct V_13 * F_337 ( struct V_532 * V_101 , T_10 V_533 )
{
struct V_13 * V_150 = NULL ;
struct V_534 * V_164 = V_101 -> V_535 ;
struct V_115 * V_115 = F_338 ( V_101 ) ;
int V_158 = 0 ;
if ( V_533 == 0 ) {
V_164 -> V_536 = 0 ;
V_164 -> V_537 = 0 ;
}
for (; V_164 -> V_536 < V_504 ; ++ V_164 -> V_536 ) {
F_205 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_200 ( F_38 ( V_150 -> V_9 -> V_11 ) , V_115 ) )
continue;
if ( V_158 < V_164 -> V_537 ) {
V_158 ++ ;
continue;
}
V_164 -> V_537 ++ ;
return V_150 ;
}
V_164 -> V_537 = 0 ;
V_158 = 0 ;
}
return NULL ;
}
static struct V_13 * F_339 ( struct V_532 * V_101 ,
struct V_13 * V_150 )
{
struct V_534 * V_164 = V_101 -> V_535 ;
struct V_115 * V_115 = F_338 ( V_101 ) ;
F_340 (ifa, addr_lst) {
if ( ! F_200 ( F_38 ( V_150 -> V_9 -> V_11 ) , V_115 ) )
continue;
V_164 -> V_537 ++ ;
return V_150 ;
}
while ( ++ V_164 -> V_536 < V_504 ) {
V_164 -> V_537 = 0 ;
F_205 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_200 ( F_38 ( V_150 -> V_9 -> V_11 ) , V_115 ) )
continue;
V_164 -> V_537 ++ ;
return V_150 ;
}
}
return NULL ;
}
static void * F_341 ( struct V_532 * V_101 , T_10 * V_533 )
__acquires( T_11 )
{
F_124 () ;
return F_337 ( V_101 , * V_533 ) ;
}
static void * F_342 ( struct V_532 * V_101 , void * V_538 , T_10 * V_533 )
{
struct V_13 * V_150 ;
V_150 = F_339 ( V_101 , V_538 ) ;
++ * V_533 ;
return V_150 ;
}
static void F_343 ( struct V_532 * V_101 , void * V_538 )
__releases( T_11 )
{
F_125 () ;
}
static int F_344 ( struct V_532 * V_101 , void * V_538 )
{
struct V_13 * V_14 = (struct V_13 * ) V_538 ;
F_345 ( V_101 , L_26 ,
& V_14 -> V_169 ,
V_14 -> V_9 -> V_11 -> V_97 ,
V_14 -> V_200 ,
V_14 -> V_175 ,
( T_5 ) V_14 -> V_59 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
return 0 ;
}
static int F_346 ( struct V_539 * V_539 , struct V_540 * V_540 )
{
return F_347 ( V_539 , V_540 , & V_541 ,
sizeof( struct V_534 ) ) ;
}
static int T_12 F_348 ( struct V_115 * V_115 )
{
if ( ! F_349 ( L_27 , V_542 , V_115 -> V_543 , & V_544 ) )
return - V_34 ;
return 0 ;
}
static void T_13 F_350 ( struct V_115 * V_115 )
{
F_351 ( L_27 , V_115 -> V_543 ) ;
}
int T_14 F_352 ( void )
{
return F_353 ( & V_545 ) ;
}
void F_354 ( void )
{
F_355 ( & V_545 ) ;
}
int F_356 ( struct V_115 * V_115 , const struct V_171 * V_169 )
{
int V_231 = 0 ;
struct V_13 * V_14 = NULL ;
unsigned int V_181 = F_119 ( V_169 ) ;
F_124 () ;
F_205 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_200 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_115 ) )
continue;
if ( F_175 ( & V_14 -> V_169 , V_169 ) &&
( V_14 -> V_59 & V_270 ) ) {
V_231 = 1 ;
break;
}
}
F_125 () ;
return V_231 ;
}
static void F_281 ( void )
{
unsigned long V_233 , V_546 , V_547 , V_548 ;
struct V_13 * V_14 ;
int V_20 ;
F_33 () ;
F_124 () ;
V_233 = V_17 ;
V_546 = F_357 ( V_233 + V_549 ) ;
F_14 ( & V_550 ) ;
for ( V_20 = 0 ; V_20 < V_504 ; V_20 ++ ) {
V_505:
F_205 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_228 ;
if ( ( V_14 -> V_59 & V_211 ) &&
( V_14 -> V_177 == V_443 ) )
continue;
F_128 ( & V_14 -> V_40 ) ;
V_228 = ( V_233 - V_14 -> V_79 + V_246 ) / V_3 ;
if ( V_14 -> V_176 != V_443 &&
V_228 >= V_14 -> V_176 ) {
F_137 ( & V_14 -> V_40 ) ;
F_21 ( V_14 ) ;
F_151 ( V_14 ) ;
goto V_505;
} else if ( V_14 -> V_177 == V_443 ) {
F_137 ( & V_14 -> V_40 ) ;
continue;
} else if ( V_228 >= V_14 -> V_177 ) {
int V_551 = 0 ;
if ( ! ( V_14 -> V_59 & V_265 ) ) {
V_551 = 1 ;
V_14 -> V_59 |= V_265 ;
}
if ( ( V_14 -> V_176 != V_443 ) &&
( F_146 ( V_14 -> V_79 + V_14 -> V_176 * V_3 , V_546 ) ) )
V_546 = V_14 -> V_79 + V_14 -> V_176 * V_3 ;
F_137 ( & V_14 -> V_40 ) ;
if ( V_551 ) {
F_21 ( V_14 ) ;
F_159 ( 0 , V_14 ) ;
F_23 ( V_14 ) ;
goto V_505;
}
} else if ( ( V_14 -> V_59 & V_204 ) &&
! ( V_14 -> V_59 & V_153 ) ) {
unsigned long V_229 = V_14 -> V_9 -> V_43 . V_239 *
V_14 -> V_9 -> V_43 . V_241 *
F_163 ( V_14 -> V_9 -> V_51 , V_242 ) / V_3 ;
if ( V_228 >= V_14 -> V_177 - V_229 ) {
struct V_13 * V_220 = V_14 -> V_220 ;
if ( F_146 ( V_14 -> V_79 + V_14 -> V_177 * V_3 , V_546 ) )
V_546 = V_14 -> V_79 + V_14 -> V_177 * V_3 ;
if ( ! V_14 -> V_238 && V_220 ) {
V_14 -> V_238 ++ ;
F_21 ( V_14 ) ;
F_21 ( V_220 ) ;
F_137 ( & V_14 -> V_40 ) ;
F_128 ( & V_220 -> V_40 ) ;
V_220 -> V_238 = 0 ;
F_137 ( & V_220 -> V_40 ) ;
F_161 ( V_220 , V_14 ) ;
F_23 ( V_220 ) ;
F_23 ( V_14 ) ;
goto V_505;
}
} else if ( F_146 ( V_14 -> V_79 + V_14 -> V_177 * V_3 - V_229 * V_3 , V_546 ) )
V_546 = V_14 -> V_79 + V_14 -> V_177 * V_3 - V_229 * V_3 ;
F_137 ( & V_14 -> V_40 ) ;
} else {
if ( F_146 ( V_14 -> V_79 + V_14 -> V_177 * V_3 , V_546 ) )
V_546 = V_14 -> V_79 + V_14 -> V_177 * V_3 ;
F_137 ( & V_14 -> V_40 ) ;
}
}
}
V_547 = F_357 ( V_546 ) ;
V_548 = V_546 ;
if ( F_146 ( V_547 , V_546 + V_552 ) )
V_548 = V_547 ;
if ( F_146 ( V_548 , V_17 + V_553 ) )
V_548 = V_17 + V_553 ;
F_42 ( V_554 L_28 ,
V_233 , V_546 , V_547 , V_548 ) ;
F_22 ( V_19 , & V_550 , V_548 - V_233 ) ;
F_125 () ;
}
static void F_358 ( struct V_522 * V_523 )
{
F_269 () ;
F_281 () ;
F_101 () ;
}
static void F_258 ( void )
{
F_22 ( V_19 , & V_550 , 0 ) ;
}
static struct V_171 * F_359 ( struct V_123 * V_169 , struct V_123 * V_555 ,
struct V_171 * * V_433 )
{
struct V_171 * V_345 = NULL ;
* V_433 = NULL ;
if ( V_169 )
V_345 = F_360 ( V_169 ) ;
if ( V_555 ) {
if ( V_345 && F_361 ( V_555 , V_345 , sizeof( * V_345 ) ) )
* V_433 = V_345 ;
V_345 = F_360 ( V_555 ) ;
}
return V_345 ;
}
static int
F_362 ( struct V_95 * V_96 , struct V_103 * V_104 ,
struct V_120 * V_121 )
{
struct V_115 * V_115 = F_78 ( V_96 -> V_122 ) ;
struct V_556 * V_557 ;
struct V_123 * V_124 [ V_558 + 1 ] ;
struct V_171 * V_345 , * V_433 ;
T_1 V_434 ;
int V_36 ;
V_36 = F_79 ( V_104 , sizeof( * V_557 ) , V_124 , V_558 , V_559 ,
V_121 ) ;
if ( V_36 < 0 )
return V_36 ;
V_557 = F_67 ( V_104 ) ;
V_345 = F_359 ( V_124 [ V_560 ] , V_124 [ V_561 ] , & V_433 ) ;
if ( ! V_345 )
return - V_39 ;
V_434 = V_124 [ V_562 ] ? F_363 ( V_124 [ V_562 ] ) : V_557 -> V_434 ;
V_434 &= V_385 ;
return F_282 ( V_115 , V_557 -> V_563 , V_434 , V_345 ,
V_557 -> V_564 ) ;
}
static int F_364 ( struct V_13 * V_14 , T_1 V_434 ,
T_1 V_177 , T_1 V_176 )
{
T_1 V_59 ;
T_7 V_207 ;
unsigned long V_435 ;
bool V_565 ;
bool V_566 ;
F_33 () ;
if ( ! V_176 || ( V_177 > V_176 ) )
return - V_39 ;
if ( V_434 & V_385 &&
( V_14 -> V_59 & V_204 || V_14 -> V_200 != 64 ) )
return - V_39 ;
V_435 = F_145 ( V_176 , V_3 ) ;
if ( F_263 ( V_435 ) ) {
V_207 = F_265 ( V_435 * V_3 ) ;
V_176 = V_435 ;
V_59 = V_219 ;
} else {
V_207 = 0 ;
V_59 = 0 ;
V_434 |= V_211 ;
}
V_435 = F_145 ( V_177 , V_3 ) ;
if ( F_263 ( V_435 ) ) {
if ( V_435 == 0 )
V_434 |= V_265 ;
V_177 = V_435 ;
}
F_152 ( & V_14 -> V_40 ) ;
V_565 = V_14 -> V_59 & V_385 ;
V_566 = V_14 -> V_59 & V_211 &&
! ( V_14 -> V_59 & V_212 ) ;
V_14 -> V_59 &= ~ ( V_265 | V_211 | V_201 |
V_270 | V_385 |
V_212 ) ;
V_14 -> V_59 |= V_434 ;
V_14 -> V_79 = V_17 ;
V_14 -> V_176 = V_176 ;
V_14 -> V_177 = V_177 ;
F_153 ( & V_14 -> V_40 ) ;
if ( ! ( V_14 -> V_59 & V_153 ) )
F_159 ( 0 , V_14 ) ;
if ( ! ( V_434 & V_212 ) ) {
F_241 ( & V_14 -> V_169 , V_14 -> V_200 , V_14 -> V_9 -> V_11 ,
V_207 , V_59 ) ;
} else if ( V_566 ) {
enum V_206 V_209 ;
unsigned long V_394 ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
V_209 = F_143 ( V_14 , & V_394 ) ;
F_158 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_209 != V_213 ) {
F_147 ( V_14 , V_394 ,
V_209 == V_210 ) ;
}
}
if ( V_565 || V_14 -> V_59 & V_385 ) {
if ( V_565 && ! ( V_14 -> V_59 & V_385 ) )
V_176 = V_177 = 0 ;
F_252 ( V_14 -> V_9 , V_14 , V_176 , V_177 ,
! V_565 , V_17 ) ;
}
F_281 () ;
return 0 ;
}
static int
F_365 ( struct V_95 * V_96 , struct V_103 * V_104 ,
struct V_120 * V_121 )
{
struct V_115 * V_115 = F_78 ( V_96 -> V_122 ) ;
struct V_556 * V_557 ;
struct V_123 * V_124 [ V_558 + 1 ] ;
struct V_171 * V_345 , * V_433 ;
struct V_13 * V_150 ;
struct V_10 * V_11 ;
T_1 V_176 = V_443 , V_311 = V_443 ;
T_1 V_434 ;
int V_36 ;
V_36 = F_79 ( V_104 , sizeof( * V_557 ) , V_124 , V_558 , V_559 ,
V_121 ) ;
if ( V_36 < 0 )
return V_36 ;
V_557 = F_67 ( V_104 ) ;
V_345 = F_359 ( V_124 [ V_560 ] , V_124 [ V_561 ] , & V_433 ) ;
if ( ! V_345 )
return - V_39 ;
if ( V_124 [ V_567 ] ) {
struct V_568 * V_569 ;
V_569 = F_360 ( V_124 [ V_567 ] ) ;
V_176 = V_569 -> V_570 ;
V_311 = V_569 -> V_571 ;
} else {
V_311 = V_443 ;
V_176 = V_443 ;
}
V_11 = F_81 ( V_115 , V_557 -> V_563 ) ;
if ( ! V_11 )
return - V_187 ;
V_434 = V_124 [ V_562 ] ? F_363 ( V_124 [ V_562 ] ) : V_557 -> V_434 ;
V_434 &= V_201 | V_270 | V_385 |
V_212 | V_436 ;
V_150 = F_204 ( V_115 , V_345 , V_11 , 1 ) ;
if ( ! V_150 ) {
return F_280 ( V_115 , V_557 -> V_563 , V_345 , V_433 ,
V_557 -> V_564 , V_434 ,
V_311 , V_176 ) ;
}
if ( V_104 -> V_572 & V_573 ||
! ( V_104 -> V_572 & V_574 ) )
V_36 = - V_195 ;
else
V_36 = F_364 ( V_150 , V_434 , V_311 , V_176 ) ;
F_23 ( V_150 ) ;
return V_36 ;
}
static void F_366 ( struct V_103 * V_104 , T_5 V_575 , T_1 V_59 ,
T_5 V_175 , int V_97 )
{
struct V_556 * V_557 ;
V_557 = F_67 ( V_104 ) ;
V_557 -> V_576 = V_108 ;
V_557 -> V_564 = V_575 ;
V_557 -> V_434 = V_59 ;
V_557 -> V_453 = V_175 ;
V_557 -> V_563 = V_97 ;
}
static int F_367 ( struct V_95 * V_96 , unsigned long V_1 ,
unsigned long V_79 , T_1 V_577 , T_1 V_392 )
{
struct V_568 V_569 ;
V_569 . V_1 = F_1 ( V_1 ) ;
V_569 . V_79 = F_1 ( V_79 ) ;
V_569 . V_571 = V_577 ;
V_569 . V_570 = V_392 ;
return F_368 ( V_96 , V_567 , sizeof( V_569 ) , & V_569 ) ;
}
static inline int F_369 ( int V_453 )
{
if ( V_453 & V_300 )
return V_455 ;
else if ( V_453 & V_296 )
return V_454 ;
else if ( V_453 & V_578 )
return V_579 ;
else
return V_580 ;
}
static inline int F_370 ( void )
{
return F_62 ( sizeof( struct V_556 ) )
+ F_63 ( 16 )
+ F_63 ( 16 )
+ F_63 ( sizeof( struct V_568 ) )
+ F_63 ( 4 ) ;
}
static int F_371 ( struct V_95 * V_96 , struct V_13 * V_150 ,
T_1 V_100 , T_1 V_101 , int V_102 , unsigned int V_59 )
{
struct V_103 * V_104 ;
T_1 V_577 , V_392 ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( struct V_556 ) , V_59 ) ;
if ( ! V_104 )
return - V_106 ;
F_366 ( V_104 , V_150 -> V_200 , V_150 -> V_59 , F_369 ( V_150 -> V_175 ) ,
V_150 -> V_9 -> V_11 -> V_97 ) ;
if ( ! ( ( V_150 -> V_59 & V_211 ) &&
( V_150 -> V_177 == V_443 ) ) ) {
V_577 = V_150 -> V_177 ;
V_392 = V_150 -> V_176 ;
if ( V_577 != V_443 ) {
long V_581 = ( V_17 - V_150 -> V_79 ) / V_3 ;
if ( V_577 > V_581 )
V_577 -= V_581 ;
else
V_577 = 0 ;
if ( V_392 != V_443 ) {
if ( V_392 > V_581 )
V_392 -= V_581 ;
else
V_392 = 0 ;
}
}
} else {
V_577 = V_443 ;
V_392 = V_443 ;
}
if ( ! F_216 ( & V_150 -> V_173 ) ) {
if ( F_372 ( V_96 , V_561 , & V_150 -> V_169 ) < 0 ||
F_372 ( V_96 , V_560 , & V_150 -> V_173 ) < 0 )
goto error;
} else
if ( F_372 ( V_96 , V_560 , & V_150 -> V_169 ) < 0 )
goto error;
if ( F_367 ( V_96 , V_150 -> V_1 , V_150 -> V_79 , V_577 , V_392 ) < 0 )
goto error;
if ( F_373 ( V_96 , V_562 , V_150 -> V_59 ) < 0 )
goto error;
F_69 ( V_96 , V_104 ) ;
return 0 ;
error:
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
static int F_374 ( struct V_95 * V_96 , struct V_582 * V_583 ,
T_1 V_100 , T_1 V_101 , int V_102 , T_15 V_59 )
{
struct V_103 * V_104 ;
T_5 V_175 = V_580 ;
int V_97 = V_583 -> V_9 -> V_11 -> V_97 ;
if ( F_168 ( & V_583 -> V_584 ) & V_578 )
V_175 = V_579 ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( struct V_556 ) , V_59 ) ;
if ( ! V_104 )
return - V_106 ;
F_366 ( V_104 , 128 , V_211 , V_175 , V_97 ) ;
if ( F_372 ( V_96 , V_585 , & V_583 -> V_584 ) < 0 ||
F_367 ( V_96 , V_583 -> V_586 , V_583 -> V_587 ,
V_443 , V_443 ) < 0 ) {
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
F_69 ( V_96 , V_104 ) ;
return 0 ;
}
static int F_375 ( struct V_95 * V_96 , struct V_588 * V_589 ,
T_1 V_100 , T_1 V_101 , int V_102 , unsigned int V_59 )
{
struct V_103 * V_104 ;
T_5 V_175 = V_580 ;
int V_97 = V_589 -> V_590 -> V_11 -> V_97 ;
if ( F_168 ( & V_589 -> V_591 ) & V_578 )
V_175 = V_579 ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( struct V_556 ) , V_59 ) ;
if ( ! V_104 )
return - V_106 ;
F_366 ( V_104 , 128 , V_211 , V_175 , V_97 ) ;
if ( F_372 ( V_96 , V_592 , & V_589 -> V_591 ) < 0 ||
F_367 ( V_96 , V_589 -> V_593 , V_589 -> V_594 ,
V_443 , V_443 ) < 0 ) {
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
F_69 ( V_96 , V_104 ) ;
return 0 ;
}
static int F_376 ( struct V_8 * V_9 , struct V_95 * V_96 ,
struct V_134 * V_135 , enum V_595 type ,
int V_596 , int * V_597 )
{
struct V_582 * V_583 ;
struct V_588 * V_589 ;
int V_36 = 1 ;
int V_598 = * V_597 ;
F_183 ( & V_9 -> V_40 ) ;
switch ( type ) {
case V_599 : {
struct V_13 * V_150 ;
F_93 (ifa, &idev->addr_list, if_list) {
if ( ++ V_598 < V_596 )
continue;
V_36 = F_371 ( V_96 , V_150 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_444 ,
V_147 ) ;
if ( V_36 < 0 )
break;
F_89 ( V_135 , F_90 ( V_96 ) ) ;
}
break;
}
case V_600 :
for ( V_583 = V_9 -> V_601 ; V_583 ;
V_583 = V_583 -> V_546 , V_598 ++ ) {
if ( V_598 < V_596 )
continue;
V_36 = F_374 ( V_96 , V_583 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_602 ,
V_147 ) ;
if ( V_36 < 0 )
break;
}
break;
case V_603 :
for ( V_589 = V_9 -> V_604 ; V_589 ;
V_589 = V_589 -> V_605 , V_598 ++ ) {
if ( V_598 < V_596 )
continue;
V_36 = F_375 ( V_96 , V_589 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_606 ,
V_147 ) ;
if ( V_36 < 0 )
break;
}
break;
default:
break;
}
F_188 ( & V_9 -> V_40 ) ;
* V_597 = V_598 ;
return V_36 ;
}
static int F_377 ( struct V_95 * V_96 , struct V_134 * V_135 ,
enum V_595 type )
{
struct V_115 * V_115 = F_78 ( V_96 -> V_122 ) ;
int V_136 , V_137 ;
int V_138 , V_598 ;
int V_139 , V_596 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_140 * V_141 ;
V_137 = V_135 -> args [ 0 ] ;
V_139 = V_138 = V_135 -> args [ 1 ] ;
V_596 = V_598 = V_135 -> args [ 2 ] ;
F_85 () ;
V_135 -> V_101 = F_86 ( & V_115 -> V_22 . V_144 ) ^ V_115 -> V_145 ;
for ( V_136 = V_137 ; V_136 < V_142 ; V_136 ++ , V_139 = 0 ) {
V_138 = 0 ;
V_141 = & V_115 -> V_143 [ V_136 ] ;
F_87 (dev, head, index_hlist) {
if ( V_138 < V_139 )
goto V_146;
if ( V_136 > V_137 || V_138 > V_139 )
V_596 = 0 ;
V_598 = 0 ;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
goto V_146;
if ( F_376 ( V_9 , V_96 , V_135 , type ,
V_596 , & V_598 ) < 0 )
goto V_148;
V_146:
V_138 ++ ;
}
}
V_148:
F_88 () ;
V_135 -> args [ 0 ] = V_136 ;
V_135 -> args [ 1 ] = V_138 ;
V_135 -> args [ 2 ] = V_598 ;
return V_96 -> V_149 ;
}
static int F_378 ( struct V_95 * V_96 , struct V_134 * V_135 )
{
enum V_595 type = V_599 ;
return F_377 ( V_96 , V_135 , type ) ;
}
static int F_379 ( struct V_95 * V_96 , struct V_134 * V_135 )
{
enum V_595 type = V_600 ;
return F_377 ( V_96 , V_135 , type ) ;
}
static int F_380 ( struct V_95 * V_96 , struct V_134 * V_135 )
{
enum V_595 type = V_603 ;
return F_377 ( V_96 , V_135 , type ) ;
}
static int F_381 ( struct V_95 * V_119 , struct V_103 * V_104 ,
struct V_120 * V_121 )
{
struct V_115 * V_115 = F_78 ( V_119 -> V_122 ) ;
struct V_556 * V_557 ;
struct V_123 * V_124 [ V_558 + 1 ] ;
struct V_171 * V_169 = NULL , * V_607 ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_150 ;
struct V_95 * V_96 ;
int V_36 ;
V_36 = F_79 ( V_104 , sizeof( * V_557 ) , V_124 , V_558 , V_559 ,
V_121 ) ;
if ( V_36 < 0 )
goto V_117;
V_169 = F_359 ( V_124 [ V_560 ] , V_124 [ V_561 ] , & V_607 ) ;
if ( ! V_169 ) {
V_36 = - V_39 ;
goto V_117;
}
V_557 = F_67 ( V_104 ) ;
if ( V_557 -> V_563 )
V_11 = F_81 ( V_115 , V_557 -> V_563 ) ;
V_150 = F_204 ( V_115 , V_169 , V_11 , 1 ) ;
if ( ! V_150 ) {
V_36 = - V_186 ;
goto V_117;
}
V_96 = F_72 ( F_370 () , V_29 ) ;
if ( ! V_96 ) {
V_36 = - V_116 ;
goto V_608;
}
V_36 = F_371 ( V_96 , V_150 , F_82 ( V_119 ) . V_100 ,
V_104 -> V_132 , V_444 , 0 ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_608;
}
V_36 = F_83 ( V_96 , V_115 , F_82 ( V_119 ) . V_100 ) ;
V_608:
F_23 ( V_150 ) ;
V_117:
return V_36 ;
}
static void F_382 ( int V_102 , struct V_13 * V_150 )
{
struct V_95 * V_96 ;
struct V_115 * V_115 = F_38 ( V_150 -> V_9 -> V_11 ) ;
int V_36 = - V_116 ;
if ( V_150 -> V_59 & V_153 && ! ( V_150 -> V_59 & V_304 ) &&
V_102 == V_221 )
return;
V_96 = F_72 ( F_370 () , V_131 ) ;
if ( ! V_96 )
goto V_117;
V_36 = F_371 ( V_96 , V_150 , 0 , 0 , V_102 , 0 ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_117;
}
F_75 ( V_96 , V_115 , 0 , V_609 , NULL , V_131 ) ;
return;
V_117:
if ( V_36 < 0 )
F_76 ( V_115 , V_609 , V_36 ) ;
}
static inline void F_383 ( struct V_98 * V_43 ,
T_4 * V_610 , int V_611 )
{
F_384 ( V_611 < ( V_612 * 4 ) ) ;
memset ( V_610 , 0 , V_611 ) ;
V_610 [ V_613 ] = V_43 -> V_53 ;
V_610 [ V_614 ] = V_43 -> V_615 ;
V_610 [ V_616 ] = V_43 -> V_50 ;
V_610 [ V_617 ] = V_43 -> V_618 ;
V_610 [ V_619 ] = V_43 -> V_620 ;
V_610 [ V_621 ] = V_43 -> V_398 ;
V_610 [ V_622 ] = V_43 -> V_241 ;
V_610 [ V_623 ] = V_43 -> V_67 ;
V_610 [ V_624 ] =
F_385 ( V_43 -> V_531 ) ;
V_610 [ V_625 ] =
F_385 ( V_43 -> V_512 ) ;
V_610 [ V_626 ] =
F_385 ( V_43 -> V_513 ) ;
V_610 [ V_627 ] = V_43 -> V_628 ;
V_610 [ V_629 ] =
F_385 ( V_43 -> V_630 ) ;
V_610 [ V_631 ] =
F_385 ( V_43 -> V_632 ) ;
V_610 [ V_633 ] = V_43 -> V_74 ;
V_610 [ V_634 ] = V_43 -> V_245 ;
V_610 [ V_635 ] = V_43 -> V_243 ;
V_610 [ V_636 ] = V_43 -> V_239 ;
V_610 [ V_637 ] = V_43 -> V_234 ;
V_610 [ V_638 ] = V_43 -> V_317 ;
V_610 [ V_639 ] = V_43 -> V_640 ;
V_610 [ V_641 ] = V_43 -> V_642 ;
V_610 [ V_643 ] = V_43 -> V_644 ;
#ifdef F_386
V_610 [ V_645 ] = V_43 -> V_646 ;
V_610 [ V_647 ] =
F_385 ( V_43 -> V_648 ) ;
#ifdef F_387
V_610 [ V_649 ] = V_43 -> V_650 ;
V_610 [ V_651 ] = V_43 -> V_652 ;
#endif
#endif
V_610 [ V_653 ] = V_43 -> V_113 ;
V_610 [ V_654 ] = V_43 -> V_655 ;
#ifdef F_172
V_610 [ V_656 ] = V_43 -> V_250 ;
V_610 [ V_657 ] = V_43 -> V_251 ;
#endif
#ifdef F_64
V_610 [ V_658 ] = V_43 -> V_112 ;
#endif
V_610 [ V_659 ] = V_43 -> V_189 ;
V_610 [ V_660 ] = V_43 -> V_62 ;
V_610 [ V_661 ] = V_43 -> V_662 ;
V_610 [ V_663 ] = V_43 -> V_664 ;
V_610 [ V_665 ] = V_43 -> V_666 ;
V_610 [ V_667 ] = V_43 -> V_668 ;
V_610 [ V_669 ] = V_43 -> V_670 ;
V_610 [ V_671 ] = V_43 -> V_114 ;
V_610 [ V_672 ] = V_43 -> V_293 ;
V_610 [ V_673 ] = V_43 -> V_674 ;
V_610 [ V_675 ] = V_43 -> V_676 ;
V_610 [ V_677 ] = V_43 -> V_503 ;
V_610 [ V_678 ] = V_43 -> V_679 ;
#ifdef F_388
V_610 [ V_680 ] = V_43 -> V_681 ;
#endif
V_610 [ V_682 ] = V_43 -> V_516 ;
V_610 [ V_683 ] = V_43 -> V_47 ;
V_610 [ V_684 ] = V_43 -> V_196 ;
}
static inline T_16 F_389 ( void )
{
return F_63 ( 4 )
+ F_63 ( sizeof( struct V_685 ) )
+ F_63 ( V_612 * 4 )
+ F_63 ( V_686 * 8 )
+ F_63 ( V_687 * 8 )
+ F_63 ( sizeof( struct V_171 ) ) ;
}
static inline T_16 F_390 ( void )
{
return F_62 ( sizeof( struct V_688 ) )
+ F_63 ( V_689 )
+ F_63 ( V_467 )
+ F_63 ( 4 )
+ F_63 ( 4 )
+ F_63 ( 1 )
+ F_63 ( F_389 () ) ;
}
static inline void F_391 ( T_3 * V_21 , T_17 * V_690 ,
int V_611 )
{
int V_20 ;
int V_691 = V_611 - sizeof( T_3 ) * V_687 ;
F_384 ( V_691 < 0 ) ;
F_392 ( V_687 , & V_21 [ 0 ] ) ;
for ( V_20 = 1 ; V_20 < V_687 ; V_20 ++ )
F_392 ( F_393 ( & V_690 [ V_20 ] ) , & V_21 [ V_20 ] ) ;
memset ( & V_21 [ V_687 ] , 0 , V_691 ) ;
}
static inline void F_394 ( T_3 * V_21 , void T_18 * V_690 ,
int V_611 , T_16 V_692 )
{
int V_20 , V_693 ;
T_3 V_694 [ V_686 ] ;
int V_691 = V_611 - sizeof( T_3 ) * V_686 ;
F_384 ( V_691 < 0 ) ;
memset ( V_694 , 0 , sizeof( V_694 ) ) ;
V_694 [ 0 ] = V_686 ;
F_26 (c) {
for ( V_20 = 1 ; V_20 < V_686 ; V_20 ++ )
V_694 [ V_20 ] += F_395 ( V_690 , V_693 , V_20 , V_692 ) ;
}
memcpy ( V_21 , V_694 , V_686 * sizeof( T_3 ) ) ;
memset ( & V_21 [ V_686 ] , 0 , V_691 ) ;
}
static void F_396 ( T_3 * V_21 , struct V_8 * V_9 , int V_695 ,
int V_611 )
{
switch ( V_695 ) {
case V_696 :
F_394 ( V_21 , V_9 -> V_21 . V_22 , V_611 ,
F_397 ( struct V_23 , V_26 ) ) ;
break;
case V_697 :
F_391 ( V_21 , V_9 -> V_21 . V_27 -> V_698 , V_611 ) ;
break;
}
}
static int F_398 ( struct V_95 * V_96 , struct V_8 * V_9 ,
T_1 V_699 )
{
struct V_123 * V_700 ;
struct V_685 V_569 ;
if ( F_373 ( V_96 , V_701 , V_9 -> V_77 ) )
goto V_110;
V_569 . V_702 = V_703 ;
V_569 . V_79 = F_1 ( V_9 -> V_79 ) ;
V_569 . V_704 = F_385 ( V_9 -> V_51 -> V_704 ) ;
V_569 . V_705 = F_385 ( F_163 ( V_9 -> V_51 , V_242 ) ) ;
if ( F_368 ( V_96 , V_706 , sizeof( V_569 ) , & V_569 ) )
goto V_110;
V_700 = F_399 ( V_96 , V_707 , V_612 * sizeof( T_2 ) ) ;
if ( ! V_700 )
goto V_110;
F_383 ( & V_9 -> V_43 , F_360 ( V_700 ) , F_400 ( V_700 ) ) ;
if ( V_699 & V_708 )
return 0 ;
V_700 = F_399 ( V_96 , V_696 , V_686 * sizeof( T_3 ) ) ;
if ( ! V_700 )
goto V_110;
F_396 ( F_360 ( V_700 ) , V_9 , V_696 , F_400 ( V_700 ) ) ;
V_700 = F_399 ( V_96 , V_697 , V_687 * sizeof( T_3 ) ) ;
if ( ! V_700 )
goto V_110;
F_396 ( F_360 ( V_700 ) , V_9 , V_697 , F_400 ( V_700 ) ) ;
V_700 = F_399 ( V_96 , V_709 , sizeof( struct V_171 ) ) ;
if ( ! V_700 )
goto V_110;
if ( F_401 ( V_96 , V_710 , V_9 -> V_43 . V_47 ) )
goto V_110;
F_183 ( & V_9 -> V_40 ) ;
memcpy ( F_360 ( V_700 ) , V_9 -> V_75 . V_236 , F_400 ( V_700 ) ) ;
F_188 ( & V_9 -> V_40 ) ;
return 0 ;
V_110:
return - V_106 ;
}
static T_16 F_402 ( const struct V_10 * V_11 ,
T_1 V_699 )
{
if ( ! F_58 ( V_11 ) )
return 0 ;
return F_389 () ;
}
static int F_403 ( struct V_95 * V_96 , const struct V_10 * V_11 ,
T_1 V_699 )
{
struct V_8 * V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
return - V_711 ;
if ( F_398 ( V_96 , V_9 , V_699 ) < 0 )
return - V_106 ;
return 0 ;
}
static int F_404 ( struct V_8 * V_9 , struct V_171 * V_75 )
{
struct V_13 * V_14 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_712 , V_713 = false ;
struct V_171 V_714 ;
F_33 () ;
if ( ! V_75 )
return - V_39 ;
if ( V_11 -> V_59 & ( V_61 | V_60 ) )
return - V_39 ;
if ( ! F_325 ( V_9 ) )
return - V_39 ;
if ( V_9 -> V_43 . V_67 == 0 )
return - V_39 ;
F_155 ( & V_9 -> V_40 ) ;
F_295 ( sizeof( V_75 -> V_236 ) != 16 ) ;
memcpy ( V_9 -> V_75 . V_236 + 8 , V_75 -> V_236 + 8 , 8 ) ;
F_158 ( & V_9 -> V_40 ) ;
V_712 = F_216 ( V_75 ) ;
if ( V_712 )
goto V_383;
if ( ! V_9 -> V_85 && ( V_9 -> V_77 & V_78 ) &&
! F_196 ( V_11 , & V_714 , V_153 |
V_247 ) ) {
F_326 ( V_11 , & V_714 , & V_84 ) ;
V_713 = true ;
}
V_383:
F_155 ( & V_9 -> V_40 ) ;
if ( V_713 ) {
V_9 -> V_77 |= V_506 ;
V_9 -> V_511 = F_2 (
V_9 -> V_43 . V_531 ) ;
V_9 -> V_510 = 1 ;
F_16 ( V_9 , V_9 -> V_511 ) ;
}
F_93 (ifp, &idev->addr_list, if_list) {
F_128 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_202 ) {
V_14 -> V_176 = 0 ;
V_14 -> V_177 = 0 ;
}
F_137 ( & V_14 -> V_40 ) ;
}
F_158 ( & V_9 -> V_40 ) ;
F_312 ( V_491 , V_9 ) ;
F_281 () ;
return 0 ;
}
static int F_405 ( const struct V_10 * V_11 ,
const struct V_123 * V_700 )
{
struct V_123 * V_124 [ V_715 + 1 ] ;
if ( V_11 && ! F_58 ( V_11 ) )
return - V_716 ;
return F_406 ( V_124 , V_715 , V_700 , V_717 ,
NULL ) ;
}
static int F_407 ( int V_718 )
{
if ( V_718 != V_474 &&
V_718 != V_475 &&
V_718 != V_48 &&
V_718 != V_379 )
return - V_39 ;
return 1 ;
}
static int F_408 ( struct V_8 * V_9 , struct V_115 * V_115 ,
int V_718 )
{
if ( V_718 == V_48 &&
! V_9 -> V_43 . V_45 . V_46 &&
! V_115 -> V_22 . V_44 -> V_45 . V_46 )
return - V_39 ;
return 1 ;
}
static int F_409 ( struct V_10 * V_11 , const struct V_123 * V_700 )
{
int V_36 = - V_39 ;
struct V_8 * V_9 = F_58 ( V_11 ) ;
struct V_123 * V_124 [ V_715 + 1 ] ;
if ( ! V_9 )
return - V_716 ;
if ( F_406 ( V_124 , V_715 , V_700 , NULL , NULL ) < 0 )
F_410 () ;
if ( V_124 [ V_709 ] ) {
V_36 = F_404 ( V_9 , F_360 ( V_124 [ V_709 ] ) ) ;
if ( V_36 )
return V_36 ;
}
if ( V_124 [ V_710 ] ) {
T_5 V_718 = F_411 ( V_124 [ V_710 ] ) ;
if ( F_407 ( V_718 ) < 0 ||
F_408 ( V_9 , F_38 ( V_11 ) , V_718 ) < 0 )
return - V_39 ;
V_9 -> V_43 . V_47 = V_718 ;
V_36 = 0 ;
}
return V_36 ;
}
static int F_412 ( struct V_95 * V_96 , struct V_8 * V_9 ,
T_1 V_100 , T_1 V_101 , int V_102 , unsigned int V_59 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_688 * V_719 ;
struct V_103 * V_104 ;
void * V_720 ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( * V_719 ) , V_59 ) ;
if ( ! V_104 )
return - V_106 ;
V_719 = F_67 ( V_104 ) ;
V_719 -> V_721 = V_108 ;
V_719 -> V_722 = 0 ;
V_719 -> V_723 = V_11 -> type ;
V_719 -> V_724 = V_11 -> V_97 ;
V_719 -> V_725 = F_413 ( V_11 ) ;
V_719 -> V_726 = 0 ;
if ( F_414 ( V_96 , V_727 , V_11 -> V_56 ) ||
( V_11 -> V_324 &&
F_368 ( V_96 , V_728 , V_11 -> V_324 , V_11 -> V_326 ) ) ||
F_373 ( V_96 , V_729 , V_11 -> V_37 ) ||
( V_11 -> V_97 != F_415 ( V_11 ) &&
F_373 ( V_96 , V_730 , F_415 ( V_11 ) ) ) ||
F_401 ( V_96 , V_731 ,
F_50 ( V_11 ) ? V_11 -> V_732 : V_733 ) )
goto V_110;
V_720 = F_416 ( V_96 , V_734 ) ;
if ( ! V_720 )
goto V_110;
if ( F_398 ( V_96 , V_9 , 0 ) < 0 )
goto V_110;
F_417 ( V_96 , V_720 ) ;
F_69 ( V_96 , V_104 ) ;
return 0 ;
V_110:
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
static int F_418 ( struct V_95 * V_96 , struct V_134 * V_135 )
{
struct V_115 * V_115 = F_78 ( V_96 -> V_122 ) ;
int V_136 , V_137 ;
int V_138 = 0 , V_139 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_140 * V_141 ;
V_137 = V_135 -> args [ 0 ] ;
V_139 = V_135 -> args [ 1 ] ;
F_85 () ;
for ( V_136 = V_137 ; V_136 < V_142 ; V_136 ++ , V_139 = 0 ) {
V_138 = 0 ;
V_141 = & V_115 -> V_143 [ V_136 ] ;
F_87 (dev, head, index_hlist) {
if ( V_138 < V_139 )
goto V_146;
V_9 = F_58 ( V_11 ) ;
if ( ! V_9 )
goto V_146;
if ( F_412 ( V_96 , V_9 ,
F_82 ( V_135 -> V_96 ) . V_100 ,
V_135 -> V_104 -> V_132 ,
V_491 , V_147 ) < 0 )
goto V_111;
V_146:
V_138 ++ ;
}
}
V_111:
F_88 () ;
V_135 -> args [ 1 ] = V_138 ;
V_135 -> args [ 0 ] = V_136 ;
return V_96 -> V_149 ;
}
void F_312 ( int V_102 , struct V_8 * V_9 )
{
struct V_95 * V_96 ;
struct V_115 * V_115 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_116 ;
V_96 = F_72 ( F_390 () , V_131 ) ;
if ( ! V_96 )
goto V_117;
V_36 = F_412 ( V_96 , V_9 , 0 , 0 , V_102 , 0 ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_117;
}
F_75 ( V_96 , V_115 , 0 , V_735 , NULL , V_131 ) ;
return;
V_117:
if ( V_36 < 0 )
F_76 ( V_115 , V_735 , V_36 ) ;
}
static inline T_16 F_419 ( void )
{
return F_62 ( sizeof( struct V_736 ) )
+ F_63 ( sizeof( struct V_171 ) )
+ F_63 ( sizeof( struct V_737 ) ) ;
}
static int F_420 ( struct V_95 * V_96 , struct V_8 * V_9 ,
struct V_380 * V_381 , T_1 V_100 , T_1 V_101 ,
int V_102 , unsigned int V_59 )
{
struct V_736 * V_738 ;
struct V_103 * V_104 ;
struct V_737 V_569 ;
V_104 = F_66 ( V_96 , V_100 , V_101 , V_102 , sizeof( * V_738 ) , V_59 ) ;
if ( ! V_104 )
return - V_106 ;
V_738 = F_67 ( V_104 ) ;
V_738 -> V_739 = V_108 ;
V_738 -> V_740 = 0 ;
V_738 -> V_741 = 0 ;
V_738 -> V_742 = V_9 -> V_11 -> V_97 ;
V_738 -> V_200 = V_381 -> V_200 ;
V_738 -> V_743 = V_381 -> type ;
V_738 -> V_744 = 0 ;
V_738 -> V_745 = 0 ;
if ( V_381 -> V_301 )
V_738 -> V_745 |= V_746 ;
if ( V_381 -> V_398 )
V_738 -> V_745 |= V_747 ;
if ( F_368 ( V_96 , V_748 , sizeof( V_381 -> V_390 ) , & V_381 -> V_390 ) )
goto V_110;
V_569 . V_749 = F_260 ( V_381 -> V_393 ) ;
V_569 . V_750 = F_260 ( V_381 -> V_392 ) ;
if ( F_368 ( V_96 , V_751 , sizeof( V_569 ) , & V_569 ) )
goto V_110;
F_69 ( V_96 , V_104 ) ;
return 0 ;
V_110:
F_70 ( V_96 , V_104 ) ;
return - V_106 ;
}
static void F_267 ( int V_102 , struct V_8 * V_9 ,
struct V_380 * V_381 )
{
struct V_95 * V_96 ;
struct V_115 * V_115 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_116 ;
V_96 = F_72 ( F_419 () , V_131 ) ;
if ( ! V_96 )
goto V_117;
V_36 = F_420 ( V_96 , V_9 , V_381 , 0 , 0 , V_102 , 0 ) ;
if ( V_36 < 0 ) {
F_73 ( V_36 == - V_106 ) ;
F_74 ( V_96 ) ;
goto V_117;
}
F_75 ( V_96 , V_115 , 0 , V_752 , NULL , V_131 ) ;
return;
V_117:
if ( V_36 < 0 )
F_76 ( V_115 , V_752 , V_36 ) ;
}
static void F_322 ( int V_102 , struct V_13 * V_14 )
{
struct V_115 * V_115 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( V_102 )
F_33 () ;
F_382 ( V_102 ? : V_444 , V_14 ) ;
switch ( V_102 ) {
case V_444 :
if ( ! F_421 ( V_14 -> V_6 -> V_476 ) )
F_331 ( V_14 -> V_6 ) ;
if ( V_14 -> V_9 -> V_43 . V_53 )
F_94 ( V_14 ) ;
if ( ! F_216 ( & V_14 -> V_173 ) )
F_241 ( & V_14 -> V_173 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
break;
case V_221 :
if ( V_14 -> V_9 -> V_43 . V_53 )
F_95 ( V_14 ) ;
F_213 ( V_14 -> V_9 , & V_14 -> V_169 ) ;
if ( ! F_216 ( & V_14 -> V_173 ) ) {
struct V_178 * V_6 ;
V_6 = F_148 ( & V_14 -> V_173 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
if ( V_6 )
F_149 ( V_6 ) ;
}
if ( V_14 -> V_6 ) {
if ( F_422 ( & V_14 -> V_6 -> V_197 ) )
F_149 ( V_14 -> V_6 ) ;
}
F_288 ( V_115 ) ;
break;
}
F_423 ( & V_115 -> V_22 . V_144 ) ;
}
static void F_159 ( int V_102 , struct V_13 * V_14 )
{
F_124 () ;
if ( F_141 ( V_14 -> V_9 -> V_85 == 0 ) )
F_322 ( V_102 , V_14 ) ;
F_125 () ;
}
static
int F_424 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 , T_10 * V_757 )
{
int * V_758 = V_753 -> V_469 ;
int V_759 = * V_758 ;
T_10 V_533 = * V_757 ;
struct V_156 V_760 ;
int V_231 ;
V_760 = * V_753 ;
V_760 . V_469 = & V_759 ;
V_231 = F_425 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_754 )
V_231 = F_98 ( V_753 , V_758 , V_759 ) ;
if ( V_231 )
* V_757 = V_533 ;
return V_231 ;
}
static
int F_426 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 , T_10 * V_757 )
{
struct V_8 * V_9 = V_753 -> V_162 ;
int V_761 = V_38 ;
struct V_156 V_760 ;
V_760 = * V_753 ;
V_760 . V_162 = & V_761 ;
V_760 . V_160 = V_9 ? & V_9 -> V_11 -> V_37 : NULL ;
return F_427 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
}
static void F_428 ( struct V_8 * V_9 )
{
struct V_762 V_482 ;
if ( ! V_9 || ! V_9 -> V_11 )
return;
F_429 ( & V_482 , V_9 -> V_11 ) ;
if ( V_9 -> V_43 . V_189 )
F_306 ( NULL , V_222 , & V_482 ) ;
else
F_306 ( NULL , V_193 , & V_482 ) ;
}
static void F_430 ( struct V_115 * V_115 , T_4 V_154 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_97 (net, dev) {
V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
int V_155 = ( ! V_9 -> V_43 . V_189 ) ^ ( ! V_154 ) ;
V_9 -> V_43 . V_189 = V_154 ;
if ( V_155 )
F_428 ( V_9 ) ;
}
}
}
static int F_431 ( struct V_156 * V_157 , int * V_158 , int V_154 )
{
struct V_115 * V_115 ;
int V_159 ;
if ( ! F_99 () )
return F_100 () ;
V_115 = (struct V_115 * ) V_157 -> V_160 ;
V_159 = * V_158 ;
* V_158 = V_154 ;
if ( V_158 == & V_115 -> V_22 . V_44 -> V_189 ) {
F_101 () ;
return 0 ;
}
if ( V_158 == & V_115 -> V_22 . V_129 -> V_189 ) {
V_115 -> V_22 . V_44 -> V_189 = V_154 ;
F_430 ( V_115 , V_154 ) ;
} else if ( ( ! V_154 ) ^ ( ! V_159 ) )
F_428 ( (struct V_8 * ) V_157 -> V_162 ) ;
F_101 () ;
return 0 ;
}
static
int F_432 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 , T_10 * V_757 )
{
int * V_758 = V_753 -> V_469 ;
int V_759 = * V_758 ;
T_10 V_533 = * V_757 ;
struct V_156 V_760 ;
int V_231 ;
V_760 = * V_753 ;
V_760 . V_469 = & V_759 ;
V_231 = F_425 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_754 )
V_231 = F_431 ( V_753 , V_758 , V_759 ) ;
if ( V_231 )
* V_757 = V_533 ;
return V_231 ;
}
static
int F_433 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 , T_10 * V_757 )
{
int * V_758 = V_753 -> V_469 ;
int V_231 ;
int V_159 , V_763 ;
V_159 = * V_758 ;
V_231 = F_425 ( V_753 , V_754 , V_755 , V_756 , V_757 ) ;
V_763 = * V_758 ;
if ( V_754 && V_159 != V_763 ) {
struct V_115 * V_115 = V_753 -> V_160 ;
if ( ! F_99 () )
return F_100 () ;
if ( V_758 == & V_115 -> V_22 . V_44 -> V_113 )
F_71 ( V_115 , V_133 ,
V_93 ,
V_130 ,
V_115 -> V_22 . V_44 ) ;
else if ( V_758 == & V_115 -> V_22 . V_129 -> V_113 )
F_71 ( V_115 , V_133 ,
V_93 ,
V_128 ,
V_115 -> V_22 . V_129 ) ;
else {
struct V_8 * V_9 = V_753 -> V_162 ;
F_71 ( V_115 , V_133 ,
V_93 ,
V_9 -> V_11 -> V_97 ,
& V_9 -> V_43 ) ;
}
F_101 () ;
}
return V_231 ;
}
static int F_434 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 ,
T_10 * V_757 )
{
int V_231 = 0 ;
int V_764 ;
struct V_8 * V_9 = (struct V_8 * ) V_753 -> V_162 ;
struct V_115 * V_115 = (struct V_115 * ) V_753 -> V_160 ;
if ( ! F_99 () )
return F_100 () ;
V_231 = F_425 ( V_753 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_754 ) {
V_764 = * ( ( int * ) V_753 -> V_469 ) ;
if ( F_407 ( V_764 ) < 0 ) {
V_231 = - V_39 ;
goto V_111;
}
if ( & V_115 -> V_22 . V_44 -> V_47 == V_753 -> V_469 ) {
V_49 . V_47 = V_764 ;
} else {
if ( ! V_9 )
goto V_111;
if ( F_408 ( V_9 , V_115 , V_764 ) < 0 ) {
V_231 = - V_39 ;
goto V_111;
}
if ( V_9 -> V_43 . V_47 != V_764 ) {
V_9 -> V_43 . V_47 = V_764 ;
F_300 ( V_9 -> V_11 ) ;
}
}
}
V_111:
F_101 () ;
return V_231 ;
}
static int F_435 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 ,
T_10 * V_757 )
{
int V_36 ;
struct V_171 V_169 ;
char V_765 [ V_766 ] ;
struct V_156 V_760 = * V_753 ;
struct V_115 * V_115 = V_753 -> V_160 ;
struct V_471 * V_465 = V_753 -> V_469 ;
if ( & V_115 -> V_22 . V_129 -> V_45 == V_753 -> V_469 )
return - V_767 ;
V_760 . V_768 = V_766 ;
V_760 . V_469 = V_765 ;
if ( ! F_99 () )
return F_100 () ;
if ( ! V_754 && ! V_465 -> V_46 ) {
V_36 = - V_767 ;
goto V_111;
}
V_36 = snprintf ( V_765 , sizeof( V_765 ) , L_29 , & V_465 -> V_465 ) ;
if ( V_36 >= sizeof( V_765 ) ) {
V_36 = - V_767 ;
goto V_111;
}
V_36 = F_436 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_36 || ! V_754 )
goto V_111;
if ( F_437 ( V_765 , - 1 , V_169 . V_769 . V_770 , - 1 , NULL ) != 1 ) {
V_36 = - V_767 ;
goto V_111;
}
V_465 -> V_46 = true ;
V_465 -> V_465 = V_169 ;
if ( & V_115 -> V_22 . V_44 -> V_45 == V_753 -> V_469 ) {
struct V_10 * V_11 ;
F_97 (net, dev) {
struct V_8 * V_9 = F_58 ( V_11 ) ;
if ( V_9 ) {
V_9 -> V_43 . V_47 =
V_48 ;
}
}
} else {
struct V_8 * V_9 = V_753 -> V_162 ;
V_9 -> V_43 . V_47 = V_48 ;
}
V_111:
F_101 () ;
return V_36 ;
}
static
int F_438 ( struct V_156 * V_753 ,
int V_754 ,
void T_8 * V_755 ,
T_16 * V_756 ,
T_10 * V_757 )
{
int * V_758 = V_753 -> V_469 ;
int V_759 = * V_758 ;
T_10 V_533 = * V_757 ;
struct V_156 V_760 ;
int V_231 ;
V_760 = * V_753 ;
V_760 . V_469 = & V_759 ;
V_231 = F_425 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_754 )
V_231 = F_104 ( V_753 , V_758 , V_759 ) ;
if ( V_231 )
* V_757 = V_533 ;
return V_231 ;
}
static
void F_439 ( struct V_178 * V_6 , int V_209 )
{
if ( V_6 ) {
if ( V_209 )
V_6 -> V_197 . V_59 |= V_198 ;
else
V_6 -> V_197 . V_59 &= ~ V_198 ;
}
}
static
void F_440 ( struct V_8 * V_9 , int V_759 )
{
struct V_13 * V_150 ;
F_183 ( & V_9 -> V_40 ) ;
F_93 (ifa, &idev->addr_list, if_list) {
F_128 ( & V_150 -> V_40 ) ;
if ( V_150 -> V_6 ) {
struct V_178 * V_6 = V_150 -> V_6 ;
struct V_368 * V_157 = V_6 -> V_771 ;
int V_772 ;
F_441 ( & V_157 -> V_370 ) ;
F_439 ( V_150 -> V_6 , V_759 ) ;
if ( V_6 -> V_773 ) {
F_26 (cpu) {
struct V_178 * * V_774 ;
V_774 = F_27 ( V_6 -> V_773 , V_772 ) ;
F_439 ( * V_774 , V_759 ) ;
}
}
F_442 ( & V_157 -> V_370 ) ;
}
F_137 ( & V_150 -> V_40 ) ;
}
F_188 ( & V_9 -> V_40 ) ;
}
static
int F_443 ( struct V_156 * V_753 , int * V_758 , int V_759 )
{
struct V_8 * V_9 ;
struct V_115 * V_115 ;
if ( ! F_99 () )
return F_100 () ;
* V_758 = V_759 ;
V_115 = (struct V_115 * ) V_753 -> V_160 ;
if ( V_758 == & V_115 -> V_22 . V_44 -> V_196 ) {
F_101 () ;
return 0 ;
}
if ( V_758 == & V_115 -> V_22 . V_129 -> V_196 ) {
struct V_10 * V_11 ;
F_97 (net, dev) {
V_9 = F_58 ( V_11 ) ;
if ( V_9 )
F_440 ( V_9 , V_759 ) ;
}
} else {
V_9 = (struct V_8 * ) V_753 -> V_162 ;
F_440 ( V_9 , V_759 ) ;
}
F_101 () ;
return 0 ;
}
static
int F_444 ( struct V_156 * V_753 , int V_754 ,
void T_8 * V_755 , T_16 * V_756 ,
T_10 * V_757 )
{
int * V_758 = V_753 -> V_469 ;
int V_759 = * V_758 ;
T_10 V_533 = * V_757 ;
struct V_156 V_760 ;
int V_231 ;
V_760 = * V_753 ;
V_760 . V_469 = & V_759 ;
V_231 = F_425 ( & V_760 , V_754 , V_755 , V_756 , V_757 ) ;
if ( V_754 && ( * V_758 != V_759 ) )
V_231 = F_443 ( V_753 , V_758 , V_759 ) ;
if ( V_231 )
* V_757 = V_533 ;
return V_231 ;
}
static int F_445 ( struct V_115 * V_115 , char * V_775 ,
struct V_8 * V_9 , struct V_98 * V_158 )
{
int V_20 , V_97 ;
struct V_156 * V_157 ;
char V_776 [ sizeof( L_30 ) + V_689 ] ;
V_157 = F_446 ( V_777 , sizeof( V_777 ) , V_29 ) ;
if ( ! V_157 )
goto V_111;
for ( V_20 = 0 ; V_157 [ V_20 ] . V_469 ; V_20 ++ ) {
V_157 [ V_20 ] . V_469 += ( char * ) V_158 - ( char * ) & V_98 ;
if ( ! V_157 [ V_20 ] . V_162 && ! V_157 [ V_20 ] . V_160 ) {
V_157 [ V_20 ] . V_162 = V_9 ;
V_157 [ V_20 ] . V_160 = V_115 ;
}
}
snprintf ( V_776 , sizeof( V_776 ) , L_31 , V_775 ) ;
V_158 -> V_778 = F_447 ( V_115 , V_776 , V_157 ) ;
if ( ! V_158 -> V_778 )
goto free;
if ( ! strcmp ( V_775 , L_32 ) )
V_97 = V_128 ;
else if ( ! strcmp ( V_775 , L_33 ) )
V_97 = V_130 ;
else
V_97 = V_9 -> V_11 -> V_97 ;
F_71 ( V_115 , V_133 , V_90 ,
V_97 , V_158 ) ;
return 0 ;
free:
F_30 ( V_157 ) ;
V_111:
return - V_116 ;
}
static void F_448 ( struct V_115 * V_115 ,
struct V_98 * V_158 , int V_97 )
{
struct V_156 * V_157 ;
if ( ! V_158 -> V_778 )
return;
V_157 = V_158 -> V_778 -> V_779 ;
F_449 ( V_158 -> V_778 ) ;
V_158 -> V_778 = NULL ;
F_30 ( V_157 ) ;
F_71 ( V_115 , V_780 , 0 , V_97 , NULL ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
int V_36 ;
if ( ! F_450 ( V_9 -> V_11 -> V_56 ) )
return - V_39 ;
V_36 = F_451 ( V_9 -> V_11 , V_9 -> V_51 ,
& V_781 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_445 ( F_38 ( V_9 -> V_11 ) , V_9 -> V_11 -> V_56 ,
V_9 , & V_9 -> V_43 ) ;
if ( V_36 )
F_452 ( V_9 -> V_51 ) ;
return V_36 ;
}
static void F_7 ( struct V_8 * V_9 )
{
F_448 ( F_38 ( V_9 -> V_11 ) , & V_9 -> V_43 ,
V_9 -> V_11 -> V_97 ) ;
F_452 ( V_9 -> V_51 ) ;
}
static int T_12 F_453 ( struct V_115 * V_115 )
{
int V_36 = - V_34 ;
struct V_98 * V_89 , * V_782 ;
V_89 = F_446 ( & V_98 , sizeof( V_98 ) , V_29 ) ;
if ( ! V_89 )
goto V_783;
V_782 = F_446 ( & V_49 , sizeof( V_49 ) , V_29 ) ;
if ( ! V_782 )
goto V_784;
V_782 -> V_398 = V_785 . V_398 ;
V_782 -> V_189 = V_785 . V_189 ;
V_782 -> V_45 . V_46 = false ;
V_89 -> V_45 . V_46 = false ;
V_115 -> V_22 . V_129 = V_89 ;
V_115 -> V_22 . V_44 = V_782 ;
#ifdef F_454
V_36 = F_445 ( V_115 , L_32 , NULL , V_89 ) ;
if ( V_36 < 0 )
goto V_786;
V_36 = F_445 ( V_115 , L_33 , NULL , V_782 ) ;
if ( V_36 < 0 )
goto V_787;
#endif
return 0 ;
#ifdef F_454
V_787:
F_448 ( V_115 , V_89 , V_128 ) ;
V_786:
F_30 ( V_782 ) ;
#endif
V_784:
F_30 ( V_89 ) ;
V_783:
return V_36 ;
}
static void T_13 F_455 ( struct V_115 * V_115 )
{
#ifdef F_454
F_448 ( V_115 , V_115 -> V_22 . V_44 ,
V_130 ) ;
F_448 ( V_115 , V_115 -> V_22 . V_129 ,
V_128 ) ;
#endif
F_30 ( V_115 -> V_22 . V_44 ) ;
F_30 ( V_115 -> V_22 . V_129 ) ;
}
int T_14 F_456 ( void )
{
struct V_8 * V_9 ;
int V_20 , V_36 ;
V_36 = F_457 () ;
if ( V_36 < 0 ) {
F_458 ( L_34 ,
V_55 , V_36 ) ;
goto V_111;
}
V_36 = F_353 ( & V_788 ) ;
if ( V_36 < 0 )
goto V_789;
V_19 = F_459 ( L_35 ) ;
if ( ! V_19 ) {
V_36 = - V_34 ;
goto V_790;
}
F_269 () ;
V_9 = F_32 ( V_791 . V_486 ) ;
F_101 () ;
if ( F_59 ( V_9 ) ) {
V_36 = F_131 ( V_9 ) ;
goto V_792;
}
F_460 () ;
for ( V_20 = 0 ; V_20 < V_504 ; V_20 ++ )
F_461 ( & V_203 [ V_20 ] ) ;
F_462 ( & V_793 ) ;
F_258 () ;
F_463 ( & V_794 ) ;
V_36 = F_464 ( V_795 , V_796 , NULL , F_418 ,
0 ) ;
if ( V_36 < 0 )
goto V_117;
F_464 ( V_795 , V_444 , F_365 , NULL , 0 ) ;
F_464 ( V_795 , V_221 , F_362 , NULL , 0 ) ;
F_464 ( V_795 , V_797 , F_381 ,
F_378 , 0 ) ;
F_464 ( V_795 , V_602 , NULL ,
F_379 , 0 ) ;
F_464 ( V_795 , V_606 , NULL ,
F_380 , 0 ) ;
F_464 ( V_795 , V_798 , F_77 ,
F_84 , 0 ) ;
F_465 () ;
return 0 ;
V_117:
F_466 ( & V_794 ) ;
F_467 ( & V_793 ) ;
V_792:
F_468 ( V_19 ) ;
V_790:
F_355 ( & V_788 ) ;
V_789:
F_469 () ;
V_111:
return V_36 ;
}
void F_470 ( void )
{
struct V_10 * V_11 ;
int V_20 ;
F_467 ( & V_793 ) ;
F_355 ( & V_788 ) ;
F_469 () ;
F_269 () ;
F_471 ( & V_794 ) ;
F_97 (&init_net, dev) {
if ( F_58 ( V_11 ) == NULL )
continue;
F_309 ( V_11 , 1 ) ;
}
F_309 ( V_791 . V_486 , 2 ) ;
F_152 ( & V_194 ) ;
for ( V_20 = 0 ; V_20 < V_504 ; V_20 ++ )
F_73 ( ! F_472 ( & V_203 [ V_20 ] ) ) ;
F_153 ( & V_194 ) ;
F_14 ( & V_550 ) ;
F_101 () ;
F_468 ( V_19 ) ;
}
