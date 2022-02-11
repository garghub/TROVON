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
F_18 ( V_35 ) ;
if ( V_11 -> V_58 & ( V_59 | V_60 ) )
V_35 -> V_43 . V_61 = - 1 ;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 && ( V_11 -> V_64 & V_65 ) ) {
F_47 ( L_3 , V_11 -> V_56 ) ;
V_35 -> V_43 . V_66 = 0 ;
}
#endif
F_36 ( & V_35 -> V_67 ) ;
V_35 -> V_68 = V_69 ;
if ( ( V_11 -> V_58 & V_60 ) ||
V_11 -> type == V_70 ||
V_11 -> type == V_71 ||
V_11 -> type == V_63 ||
V_11 -> type == V_72 ) {
V_35 -> V_43 . V_73 = - 1 ;
} else
F_48 ( V_35 ) ;
V_35 -> V_74 = V_75 ;
if ( F_49 ( V_11 ) && F_8 ( V_11 ) )
V_35 -> V_76 |= V_77 ;
F_50 ( V_35 ) ;
V_35 -> V_78 = V_17 ;
V_36 = F_6 ( V_35 ) ;
if ( V_36 ) {
F_51 ( V_35 ) ;
F_52 ( V_35 ) ;
goto V_57;
}
F_53 ( V_11 -> V_79 , V_35 ) ;
F_54 ( V_11 , & V_80 ) ;
F_54 ( V_11 , & V_81 ) ;
if ( V_35 -> V_43 . V_53 && ( V_11 -> V_58 & V_82 ) )
F_54 ( V_11 , & V_83 ) ;
return V_35 ;
V_57:
F_43 ( & V_52 , V_35 -> V_51 ) ;
V_35 -> V_84 = 1 ;
F_55 ( V_35 ) ;
return F_34 ( V_36 ) ;
}
static struct V_8 * F_56 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return NULL ;
}
if ( V_11 -> V_58 & V_85 )
F_59 ( V_9 ) ;
return V_9 ;
}
static int F_60 ( int type )
{
int V_86 = F_61 ( sizeof( struct V_87 ) )
+ F_62 ( 4 ) ;
bool V_88 = false ;
if ( type == V_89 )
V_88 = true ;
if ( V_88 || type == V_90 )
V_86 += F_62 ( 4 ) ;
#ifdef F_63
if ( V_88 || type == V_91 )
V_86 += F_62 ( 4 ) ;
#endif
if ( V_88 || type == V_92 )
V_86 += F_62 ( 4 ) ;
if ( V_88 || type == V_93 )
V_86 += F_62 ( 4 ) ;
return V_86 ;
}
static int F_64 ( struct V_94 * V_95 , int V_96 ,
struct V_97 * V_98 , T_1 V_99 ,
T_1 V_100 , int V_101 , unsigned int V_58 ,
int type )
{
struct V_102 * V_103 ;
struct V_87 * V_104 ;
bool V_88 = false ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_87 ) ,
V_58 ) ;
if ( ! V_103 )
return - V_105 ;
if ( type == V_89 )
V_88 = true ;
V_104 = F_66 ( V_103 ) ;
V_104 -> V_106 = V_107 ;
if ( F_67 ( V_95 , V_108 , V_96 ) < 0 )
goto V_109;
if ( ! V_98 )
goto V_110;
if ( ( V_88 || type == V_90 ) &&
F_67 ( V_95 , V_90 , V_98 -> V_53 ) < 0 )
goto V_109;
#ifdef F_63
if ( ( V_88 || type == V_91 ) &&
F_67 ( V_95 , V_91 ,
V_98 -> V_111 ) < 0 )
goto V_109;
#endif
if ( ( V_88 || type == V_92 ) &&
F_67 ( V_95 , V_92 , V_98 -> V_112 ) < 0 )
goto V_109;
if ( ( V_88 || type == V_93 ) &&
F_67 ( V_95 , V_93 ,
V_98 -> V_113 ) < 0 )
goto V_109;
V_110:
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
void F_70 ( struct V_114 * V_114 , int V_101 , int type ,
int V_96 , struct V_97 * V_98 )
{
struct V_94 * V_95 ;
int V_36 = - V_115 ;
V_95 = F_71 ( F_60 ( type ) , V_29 ) ;
if ( ! V_95 )
goto V_116;
V_36 = F_64 ( V_95 , V_96 , V_98 , 0 , 0 ,
V_101 , 0 , type ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_116;
}
F_74 ( V_95 , V_114 , 0 , V_117 , NULL , V_29 ) ;
return;
V_116:
F_75 ( V_114 , V_117 , V_36 ) ;
}
static int F_76 ( struct V_94 * V_118 ,
struct V_102 * V_103 ,
struct V_119 * V_120 )
{
struct V_114 * V_114 = F_77 ( V_118 -> V_121 ) ;
struct V_122 * V_123 [ V_124 + 1 ] ;
struct V_87 * V_104 ;
struct V_94 * V_95 ;
struct V_97 * V_98 ;
struct V_8 * V_125 ;
struct V_10 * V_11 ;
int V_96 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_104 ) , V_123 , V_124 ,
V_126 , V_120 ) ;
if ( V_36 < 0 )
goto V_116;
V_36 = - V_39 ;
if ( ! V_123 [ V_108 ] )
goto V_116;
V_96 = F_79 ( V_123 [ V_108 ] ) ;
switch ( V_96 ) {
case V_127 :
V_98 = V_114 -> V_22 . V_128 ;
break;
case V_129 :
V_98 = V_114 -> V_22 . V_44 ;
break;
default:
V_11 = F_80 ( V_114 , V_96 ) ;
if ( ! V_11 )
goto V_116;
V_125 = F_57 ( V_11 ) ;
if ( ! V_125 )
goto V_116;
V_98 = & V_125 -> V_43 ;
break;
}
V_36 = - V_115 ;
V_95 = F_71 ( F_60 ( V_89 ) , V_130 ) ;
if ( ! V_95 )
goto V_116;
V_36 = F_64 ( V_95 , V_96 , V_98 ,
F_81 ( V_118 ) . V_99 ,
V_103 -> V_131 , V_132 , 0 ,
V_89 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_116;
}
V_36 = F_82 ( V_95 , V_114 , F_81 ( V_118 ) . V_99 ) ;
V_116:
return V_36 ;
}
static int F_83 ( struct V_94 * V_95 ,
struct V_133 * V_134 )
{
struct V_114 * V_114 = F_77 ( V_95 -> V_121 ) ;
int V_135 , V_136 ;
int V_137 , V_138 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_139 * V_140 ;
V_136 = V_134 -> args [ 0 ] ;
V_138 = V_137 = V_134 -> args [ 1 ] ;
for ( V_135 = V_136 ; V_135 < V_141 ; V_135 ++ , V_138 = 0 ) {
V_137 = 0 ;
V_140 = & V_114 -> V_142 [ V_135 ] ;
F_84 () ;
V_134 -> V_100 = F_85 ( & V_114 -> V_22 . V_143 ) ^
V_114 -> V_144 ;
F_86 (dev, head, index_hlist) {
if ( V_137 < V_138 )
goto V_145;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_145;
if ( F_64 ( V_95 , V_11 -> V_96 ,
& V_9 -> V_43 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_132 ,
V_146 ,
V_89 ) < 0 ) {
F_87 () ;
goto V_147;
}
F_88 ( V_134 , F_89 ( V_95 ) ) ;
V_145:
V_137 ++ ;
}
F_87 () ;
}
if ( V_135 == V_141 ) {
if ( F_64 ( V_95 , V_127 ,
V_114 -> V_22 . V_128 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_132 , V_146 ,
V_89 ) < 0 )
goto V_147;
else
V_135 ++ ;
}
if ( V_135 == V_141 + 1 ) {
if ( F_64 ( V_95 , V_129 ,
V_114 -> V_22 . V_44 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_132 , V_146 ,
V_89 ) < 0 )
goto V_147;
else
V_135 ++ ;
}
V_147:
V_134 -> args [ 0 ] = V_135 ;
V_134 -> args [ 1 ] = V_137 ;
return V_95 -> V_148 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_13 * V_149 ;
if ( ! V_9 )
return;
V_11 = V_9 -> V_11 ;
if ( V_9 -> V_43 . V_53 )
F_40 ( V_11 ) ;
if ( V_11 -> V_58 & V_82 ) {
if ( V_9 -> V_43 . V_53 ) {
F_54 ( V_11 , & V_83 ) ;
F_54 ( V_11 , & V_150 ) ;
F_54 ( V_11 , & V_151 ) ;
} else {
F_91 ( V_11 , & V_83 ) ;
F_91 ( V_11 , & V_150 ) ;
F_91 ( V_11 , & V_151 ) ;
}
}
F_92 (ifa, &idev->addr_list, if_list) {
if ( V_149 -> V_58 & V_152 )
continue;
if ( V_9 -> V_43 . V_53 )
F_93 ( V_149 ) ;
else
F_94 ( V_149 ) ;
}
F_70 ( F_38 ( V_11 ) , V_132 ,
V_90 ,
V_11 -> V_96 , & V_9 -> V_43 ) ;
}
static void F_95 ( struct V_114 * V_114 , T_4 V_153 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_154 = ( ! V_9 -> V_43 . V_53 ) ^ ( ! V_153 ) ;
V_9 -> V_43 . V_53 = V_153 ;
if ( V_154 )
F_90 ( V_9 ) ;
}
}
}
static int F_97 ( struct V_155 * V_156 , int * V_157 , int V_153 )
{
struct V_114 * V_114 ;
int V_158 ;
if ( ! F_98 () )
return F_99 () ;
V_114 = (struct V_114 * ) V_156 -> V_159 ;
V_158 = * V_157 ;
* V_157 = V_153 ;
if ( V_157 == & V_114 -> V_22 . V_44 -> V_53 ) {
if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_70 ( V_114 , V_132 ,
V_90 ,
V_129 ,
V_114 -> V_22 . V_44 ) ;
F_100 () ;
return 0 ;
}
if ( V_157 == & V_114 -> V_22 . V_128 -> V_53 ) {
int V_160 = V_114 -> V_22 . V_44 -> V_53 ;
V_114 -> V_22 . V_44 -> V_53 = V_153 ;
if ( ( ! V_153 ) ^ ( ! V_160 ) )
F_70 ( V_114 , V_132 ,
V_90 ,
V_129 ,
V_114 -> V_22 . V_44 ) ;
F_95 ( V_114 , V_153 ) ;
if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_70 ( V_114 , V_132 ,
V_90 ,
V_127 ,
V_114 -> V_22 . V_128 ) ;
} else if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_90 ( (struct V_8 * ) V_156 -> V_161 ) ;
F_100 () ;
if ( V_153 )
F_101 ( V_114 ) ;
return 1 ;
}
static void F_102 ( struct V_114 * V_114 , T_4 V_153 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_154 = ( ! V_9 -> V_43 . V_113 ) ^ ( ! V_153 ) ;
V_9 -> V_43 . V_113 = V_153 ;
if ( V_154 )
F_70 ( F_38 ( V_11 ) ,
V_132 ,
V_93 ,
V_11 -> V_96 ,
& V_9 -> V_43 ) ;
}
}
}
static int F_103 ( struct V_155 * V_156 , int * V_157 , int V_153 )
{
struct V_114 * V_114 ;
int V_158 ;
if ( ! F_98 () )
return F_99 () ;
V_114 = (struct V_114 * ) V_156 -> V_159 ;
V_158 = * V_157 ;
* V_157 = V_153 ;
if ( V_157 == & V_114 -> V_22 . V_44 -> V_113 ) {
if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_70 ( V_114 ,
V_132 ,
V_93 ,
V_129 ,
V_114 -> V_22 . V_44 ) ;
F_100 () ;
return 0 ;
}
if ( V_157 == & V_114 -> V_22 . V_128 -> V_113 ) {
V_114 -> V_22 . V_44 -> V_113 = V_153 ;
F_102 ( V_114 , V_153 ) ;
if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_70 ( V_114 ,
V_132 ,
V_93 ,
V_127 ,
V_114 -> V_22 . V_128 ) ;
}
F_100 () ;
return 1 ;
}
void F_104 ( struct V_13 * V_14 )
{
F_72 ( ! F_105 ( & V_14 -> V_162 ) ) ;
#ifdef F_106
F_107 ( L_4 , V_55 ) ;
#endif
F_108 ( V_14 -> V_9 ) ;
if ( F_14 ( & V_14 -> V_15 ) )
F_109 ( L_5 ,
V_14 ) ;
if ( V_14 -> V_163 != V_164 ) {
F_110 ( L_6 , V_14 ) ;
return;
}
F_111 ( V_14 -> V_6 ) ;
F_112 ( V_14 , V_165 ) ;
}
static void
F_113 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
struct V_166 * V_157 ;
int V_167 = F_114 ( & V_14 -> V_168 ) ;
F_115 (p, &idev->addr_list) {
struct V_13 * V_149
= F_116 ( V_157 , struct V_13 , V_169 ) ;
if ( V_167 >= F_114 ( & V_149 -> V_168 ) )
break;
}
F_117 ( & V_14 -> V_169 , V_157 ) ;
}
static T_1 F_118 ( const struct V_170 * V_168 )
{
return F_119 ( F_120 ( V_168 ) , V_171 ) ;
}
static struct V_13 *
F_121 ( struct V_8 * V_9 , const struct V_170 * V_168 ,
const struct V_170 * V_172 , int V_173 ,
int V_174 , T_1 V_58 , T_1 V_175 , T_1 V_176 )
{
struct V_114 * V_114 = F_38 ( V_9 -> V_11 ) ;
struct V_13 * V_149 = NULL ;
struct V_177 * V_6 ;
unsigned int V_178 ;
int V_36 = 0 ;
int V_179 = F_122 ( V_168 ) ;
if ( V_179 == V_180 ||
V_179 & V_181 ||
( ! ( V_9 -> V_11 -> V_58 & V_60 ) &&
V_179 & V_182 ) )
return F_34 ( - V_183 ) ;
F_123 () ;
if ( V_9 -> V_84 ) {
V_36 = - V_184 ;
goto V_185;
}
if ( V_9 -> V_43 . V_186 ) {
V_36 = - V_187 ;
goto V_185;
}
F_124 ( & V_188 ) ;
if ( F_125 ( F_38 ( V_9 -> V_11 ) , V_168 , V_9 -> V_11 ) ) {
F_42 ( L_7 ) ;
V_36 = - V_189 ;
goto V_110;
}
V_149 = F_29 ( sizeof( struct V_13 ) , V_130 ) ;
if ( ! V_149 ) {
F_42 ( L_8 ) ;
V_36 = - V_115 ;
goto V_110;
}
V_6 = F_126 ( V_9 , V_168 , false ) ;
if ( F_58 ( V_6 ) ) {
V_36 = F_127 ( V_6 ) ;
goto V_110;
}
if ( V_114 -> V_22 . V_128 -> V_190 ||
V_9 -> V_43 . V_190 )
V_6 -> V_191 . V_58 |= V_192 ;
F_128 ( V_9 -> V_51 ) ;
V_149 -> V_168 = * V_168 ;
if ( V_172 )
V_149 -> V_172 = * V_172 ;
F_129 ( & V_149 -> V_40 ) ;
F_130 ( & V_149 -> V_15 , V_193 ) ;
F_131 ( & V_149 -> V_162 ) ;
V_149 -> V_174 = V_174 ;
V_149 -> V_194 = V_173 ;
V_149 -> V_58 = V_58 ;
if ( ! ( V_58 & V_195 ) )
V_149 -> V_58 |= V_152 ;
V_149 -> V_175 = V_175 ;
V_149 -> V_176 = V_176 ;
V_149 -> V_1 = V_149 -> V_78 = V_17 ;
V_149 -> V_196 = false ;
V_149 -> V_6 = V_6 ;
V_149 -> V_9 = V_9 ;
F_18 ( V_9 ) ;
F_21 ( V_149 ) ;
V_178 = F_118 ( V_168 ) ;
F_132 ( & V_149 -> V_162 , & V_197 [ V_178 ] ) ;
F_133 ( & V_188 ) ;
F_134 ( & V_9 -> V_40 ) ;
F_113 ( V_9 , V_149 ) ;
if ( V_149 -> V_58 & V_198 ) {
F_135 ( & V_149 -> V_199 , & V_9 -> V_67 ) ;
F_21 ( V_149 ) ;
}
F_21 ( V_149 ) ;
F_136 ( & V_9 -> V_40 ) ;
V_185:
F_137 () ;
if ( F_138 ( V_36 == 0 ) )
F_139 ( V_200 , V_149 ) ;
else {
F_30 ( V_149 ) ;
V_149 = F_34 ( V_36 ) ;
}
return V_149 ;
V_110:
F_133 ( & V_188 ) ;
goto V_185;
}
static enum V_201
F_140 ( struct V_13 * V_14 , unsigned long * V_202 )
{
struct V_13 * V_149 ;
struct V_8 * V_9 = V_14 -> V_9 ;
unsigned long V_203 ;
enum V_201 V_204 = V_205 ;
* V_202 = V_17 ;
F_92 (ifa, &idev->addr_list, if_list) {
if ( V_149 == V_14 )
continue;
if ( ! F_141 ( & V_149 -> V_168 , & V_14 -> V_168 ,
V_14 -> V_194 ) )
continue;
if ( V_149 -> V_58 & ( V_206 | V_207 ) )
return V_208 ;
V_204 = V_209 ;
F_124 ( & V_149 -> V_40 ) ;
V_203 = F_142 ( V_149 -> V_175 , V_3 ) ;
if ( F_143 ( * V_202 , V_149 -> V_78 + V_203 * V_3 ) )
* V_202 = V_149 -> V_78 + V_203 * V_3 ;
F_133 ( & V_149 -> V_40 ) ;
}
return V_204 ;
}
static void
F_144 ( struct V_13 * V_14 , unsigned long V_202 , bool V_210 )
{
struct V_177 * V_6 ;
V_6 = F_145 ( & V_14 -> V_168 ,
V_14 -> V_194 ,
V_14 -> V_9 -> V_11 ,
0 , V_211 | V_212 ) ;
if ( V_6 ) {
if ( V_210 )
F_146 ( V_6 ) ;
else {
if ( ! ( V_6 -> V_213 & V_214 ) )
F_147 ( V_6 , V_202 ) ;
F_111 ( V_6 ) ;
}
}
}
static void F_148 ( struct V_13 * V_14 )
{
int V_163 ;
enum V_201 V_204 = V_208 ;
unsigned long V_202 ;
F_33 () ;
F_149 ( & V_14 -> V_40 ) ;
V_163 = V_14 -> V_163 ;
V_14 -> V_163 = V_164 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_163 == V_164 )
goto V_110;
F_149 ( & V_188 ) ;
F_151 ( & V_14 -> V_162 ) ;
F_150 ( & V_188 ) ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_14 -> V_58 & V_198 ) {
F_153 ( & V_14 -> V_199 ) ;
if ( V_14 -> V_215 ) {
F_23 ( V_14 -> V_215 ) ;
V_14 -> V_215 = NULL ;
}
F_15 ( V_14 ) ;
}
if ( V_14 -> V_58 & V_206 && ! ( V_14 -> V_58 & V_207 ) )
V_204 = F_140 ( V_14 , & V_202 ) ;
F_154 ( & V_14 -> V_169 ) ;
F_15 ( V_14 ) ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
F_13 ( V_14 ) ;
F_156 ( V_216 , V_14 ) ;
F_139 ( V_217 , V_14 ) ;
if ( V_204 != V_208 ) {
F_144 ( V_14 , V_202 ,
V_204 == V_205 ) ;
}
F_157 ( V_14 ) ;
V_110:
F_23 ( V_14 ) ;
}
static int F_158 ( struct V_13 * V_14 , struct V_13 * V_218 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_170 V_168 , * V_219 ;
unsigned long V_220 , V_221 , V_222 , V_223 ;
unsigned long V_224 ;
int V_225 ;
int V_226 = 0 ;
T_1 V_227 ;
unsigned long V_228 = V_17 ;
long V_229 ;
T_2 V_230 ;
F_152 ( & V_9 -> V_40 ) ;
if ( V_218 ) {
F_149 ( & V_218 -> V_40 ) ;
memcpy ( & V_168 . V_231 [ 8 ] , & V_218 -> V_168 . V_231 [ 8 ] , 8 ) ;
F_150 ( & V_218 -> V_40 ) ;
V_219 = & V_168 ;
} else {
V_219 = NULL ;
}
V_232:
F_18 ( V_9 ) ;
if ( V_9 -> V_43 . V_73 <= 0 ) {
F_155 ( & V_9 -> V_40 ) ;
F_47 ( L_9 , V_55 ) ;
F_108 ( V_9 ) ;
V_226 = - 1 ;
goto V_110;
}
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_233 ++ >= V_9 -> V_43 . V_234 ) {
V_9 -> V_43 . V_73 = - 1 ;
F_150 ( & V_14 -> V_40 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_110 ( L_10 ,
V_55 ) ;
F_108 ( V_9 ) ;
V_226 = - 1 ;
goto V_110;
}
F_21 ( V_14 ) ;
memcpy ( V_168 . V_231 , V_14 -> V_168 . V_231 , 8 ) ;
F_159 ( V_9 , V_219 ) ;
memcpy ( & V_168 . V_231 [ 8 ] , V_9 -> V_235 , 8 ) ;
V_223 = ( V_228 - V_14 -> V_78 ) / V_3 ;
V_224 = V_9 -> V_43 . V_234 *
V_9 -> V_43 . V_236 *
F_160 ( V_9 -> V_51 , V_237 ) / V_3 ;
V_230 = F_161 ( V_9 -> V_43 . V_238 ) ;
V_229 = F_162 ( V_239 ,
V_9 -> V_43 . V_229 ,
V_230 - V_224 ) ;
if ( F_163 ( V_9 -> V_68 > V_229 ) ) {
if ( V_229 > 0 ) {
F_164 ( & V_9 -> V_68 ,
sizeof( V_9 -> V_68 ) ) ;
V_9 -> V_68 %= V_229 ;
} else {
V_9 -> V_68 = 0 ;
}
}
V_221 = F_162 ( V_239 ,
V_14 -> V_175 ,
V_9 -> V_43 . V_240 + V_223 ) ;
V_220 = V_230 + V_223 -
V_9 -> V_68 ;
V_220 = F_162 ( V_239 , V_14 -> V_176 , V_220 ) ;
V_225 = V_14 -> V_194 ;
V_222 = V_14 -> V_78 ;
F_150 ( & V_14 -> V_40 ) ;
F_155 ( & V_9 -> V_40 ) ;
V_223 = ( V_228 - V_222 + V_241 ) / V_3 ;
if ( V_220 <= V_224 + V_223 ) {
F_23 ( V_14 ) ;
F_108 ( V_9 ) ;
V_226 = - 1 ;
goto V_110;
}
V_227 = V_198 ;
if ( V_14 -> V_58 & V_242 )
V_227 |= V_242 ;
V_218 = F_121 ( V_9 , & V_168 , NULL , V_225 ,
F_165 ( & V_168 ) , V_227 ,
V_221 , V_220 ) ;
if ( F_58 ( V_218 ) ) {
F_23 ( V_14 ) ;
F_108 ( V_9 ) ;
F_47 ( L_11 , V_55 ) ;
V_219 = & V_168 ;
F_152 ( & V_9 -> V_40 ) ;
goto V_232;
}
F_149 ( & V_218 -> V_40 ) ;
V_218 -> V_215 = V_14 ;
V_218 -> V_1 = V_228 ;
V_218 -> V_78 = V_222 ;
F_150 ( & V_218 -> V_40 ) ;
F_166 ( V_218 ) ;
F_23 ( V_218 ) ;
F_108 ( V_9 ) ;
V_110:
return V_226 ;
}
static inline int F_167 ( int type )
{
if ( type & ( V_243 | V_244 | V_182 ) )
return 1 ;
return 0 ;
}
static inline bool F_168 ( struct V_8 * V_9 )
{
#ifdef F_169
return V_9 && V_9 -> V_43 . V_245 && V_9 -> V_43 . V_246 ;
#else
return false ;
#endif
}
static int F_170 ( struct V_114 * V_114 ,
struct V_247 * V_248 ,
struct V_249 * V_191 ,
int V_20 )
{
int V_226 ;
if ( V_20 <= V_248 -> V_250 ) {
switch ( V_20 ) {
case V_251 :
V_226 = V_248 -> V_252 ;
break;
case V_253 :
V_226 = V_248 -> V_254 ;
break;
default:
V_226 = ! ! F_171 ( V_20 , V_248 -> V_255 ) ;
}
goto V_110;
}
switch ( V_20 ) {
case V_256 :
V_226 = ! ! V_248 -> V_149 ;
break;
case V_257 :
V_226 = F_172 ( & V_248 -> V_149 -> V_168 , V_191 -> V_168 ) ;
break;
case V_251 :
V_226 = F_173 ( V_248 -> V_179 ) ;
if ( V_226 >= V_191 -> V_174 )
V_226 = - V_226 ;
else
V_226 -= 128 ;
V_248 -> V_252 = V_226 ;
break;
case V_258 :
{
T_5 V_259 = V_260 ;
if ( ! F_168 ( V_248 -> V_149 -> V_9 ) )
V_259 |= V_242 ;
V_226 = F_167 ( V_248 -> V_179 ) ||
! ( V_248 -> V_149 -> V_58 & V_259 ) ;
break;
}
#ifdef F_174
case V_261 :
{
int V_262 = ! ( V_191 -> V_263 & V_264 ) ;
V_226 = ! ( V_248 -> V_149 -> V_58 & V_265 ) ^ V_262 ;
break;
}
#endif
case V_266 :
V_226 = ( ! V_191 -> V_96 ||
V_191 -> V_96 == V_248 -> V_149 -> V_9 -> V_11 -> V_96 ) ;
break;
case V_267 :
V_226 = F_175 ( V_114 ,
& V_248 -> V_149 -> V_168 , V_248 -> V_179 ,
V_248 -> V_149 -> V_9 -> V_11 -> V_96 ) == V_191 -> V_268 ;
break;
case V_269 :
{
int V_270 = V_191 -> V_263 & ( V_271 | V_272 ) ?
! ! ( V_191 -> V_263 & V_272 ) :
V_248 -> V_149 -> V_9 -> V_43 . V_73 >= 2 ;
V_226 = ( ! ( V_248 -> V_149 -> V_58 & V_198 ) ) ^ V_270 ;
break;
}
case V_273 :
V_226 = ! ( F_176 ( & V_248 -> V_149 -> V_168 ) ^
F_176 ( V_191 -> V_168 ) ) ;
break;
case V_253 :
V_226 = F_177 ( & V_248 -> V_149 -> V_168 , V_191 -> V_168 ) ;
if ( V_226 > V_248 -> V_149 -> V_194 )
V_226 = V_248 -> V_149 -> V_194 ;
V_248 -> V_254 = V_226 ;
break;
#ifdef F_169
case V_274 :
V_226 = ! ( V_248 -> V_149 -> V_58 & V_242 ) ;
break;
#endif
default:
V_226 = 0 ;
}
if ( V_226 )
F_178 ( V_20 , V_248 -> V_255 ) ;
V_248 -> V_250 = V_20 ;
V_110:
return V_226 ;
}
static int F_179 ( struct V_114 * V_114 ,
struct V_249 * V_191 ,
struct V_8 * V_9 ,
struct V_247 * V_275 ,
int V_276 )
{
struct V_247 * V_248 = & V_275 [ 1 - V_276 ] , * V_277 = & V_275 [ V_276 ] ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (score->ifa, &idev->addr_list, if_list) {
int V_20 ;
if ( ( V_248 -> V_149 -> V_58 & V_152 ) &&
( ! ( V_248 -> V_149 -> V_58 & V_242 ) ) )
continue;
V_248 -> V_179 = F_181 ( & V_248 -> V_149 -> V_168 ) ;
if ( F_163 ( V_248 -> V_179 == V_180 ||
V_248 -> V_179 & V_181 ) ) {
F_182 ( L_12 ,
V_9 -> V_11 -> V_56 ) ;
continue;
}
V_248 -> V_250 = - 1 ;
F_183 ( V_248 -> V_255 , V_278 ) ;
for ( V_20 = 0 ; V_20 < V_278 ; V_20 ++ ) {
int V_279 , V_280 ;
V_279 = F_170 ( V_114 , V_277 , V_191 , V_20 ) ;
V_280 = F_170 ( V_114 , V_248 , V_191 , V_20 ) ;
if ( V_279 > V_280 ) {
if ( V_20 == V_251 &&
V_248 -> V_252 > 0 ) {
goto V_110;
}
break;
} else if ( V_279 < V_280 ) {
if ( V_277 -> V_149 )
F_23 ( V_277 -> V_149 ) ;
F_21 ( V_248 -> V_149 ) ;
F_184 ( V_277 , V_248 ) ;
V_276 = 1 - V_276 ;
V_248 -> V_149 = V_277 -> V_149 ;
break;
}
}
}
V_110:
F_185 ( & V_9 -> V_40 ) ;
return V_276 ;
}
static int F_186 ( struct V_114 * V_114 ,
const struct V_10 * V_281 ,
const struct V_10 * V_282 ,
struct V_249 * V_191 ,
struct V_247 * V_275 ,
int V_276 )
{
struct V_8 * V_9 ;
V_9 = F_57 ( V_281 ) ;
if ( V_9 )
V_276 = F_179 ( V_114 , V_191 , V_9 ,
V_275 , V_276 ) ;
V_9 = F_57 ( V_282 ) ;
if ( V_9 )
V_276 = F_179 ( V_114 , V_191 , V_9 ,
V_275 , V_276 ) ;
return V_276 ;
}
int F_187 ( struct V_114 * V_114 , const struct V_10 * V_281 ,
const struct V_170 * V_283 , unsigned int V_263 ,
struct V_170 * V_284 )
{
struct V_247 V_275 [ 2 ] , * V_277 ;
struct V_249 V_191 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_285 ;
bool V_286 = false ;
int V_276 = 0 ;
V_285 = F_181 ( V_283 ) ;
V_191 . V_168 = V_283 ;
V_191 . V_96 = V_281 ? V_281 -> V_96 : 0 ;
V_191 . V_174 = F_173 ( V_285 ) ;
V_191 . V_268 = F_175 ( V_114 , V_283 , V_285 , V_191 . V_96 ) ;
V_191 . V_263 = V_263 ;
V_275 [ V_276 ] . V_250 = - 1 ;
V_275 [ V_276 ] . V_149 = NULL ;
F_84 () ;
if ( V_281 ) {
V_9 = F_57 ( V_281 ) ;
if ( ( V_285 & V_181 ) ||
V_191 . V_174 <= V_287 ||
( V_9 && V_9 -> V_43 . V_288 ) ) {
V_286 = true ;
}
}
if ( V_286 ) {
if ( V_9 )
V_276 = F_179 ( V_114 , & V_191 , V_9 , V_275 , V_276 ) ;
} else {
const struct V_10 * V_282 ;
int V_289 = 0 ;
V_282 = F_188 ( V_281 ) ;
if ( V_282 ) {
V_289 = V_282 -> V_96 ;
V_276 = F_186 ( V_114 , V_281 ,
V_282 , & V_191 ,
V_275 , V_276 ) ;
if ( V_275 [ V_276 ] . V_149 )
goto V_110;
}
F_189 (net, dev) {
if ( F_190 ( V_11 ) != V_289 )
continue;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
continue;
V_276 = F_179 ( V_114 , & V_191 , V_9 , V_275 , V_276 ) ;
}
}
V_110:
F_87 () ;
V_277 = & V_275 [ V_276 ] ;
if ( ! V_277 -> V_149 )
return - V_183 ;
* V_284 = V_277 -> V_149 -> V_168 ;
F_23 ( V_277 -> V_149 ) ;
return 0 ;
}
int F_191 ( struct V_8 * V_9 , struct V_170 * V_168 ,
T_1 V_290 )
{
struct V_13 * V_14 ;
int V_36 = - V_183 ;
F_192 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_174 > V_291 )
break;
if ( V_14 -> V_174 == V_291 &&
! ( V_14 -> V_58 & V_290 ) ) {
* V_168 = V_14 -> V_168 ;
V_36 = 0 ;
break;
}
}
return V_36 ;
}
int F_193 ( struct V_10 * V_11 , struct V_170 * V_168 ,
T_1 V_290 )
{
struct V_8 * V_9 ;
int V_36 = - V_183 ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_180 ( & V_9 -> V_40 ) ;
V_36 = F_191 ( V_9 , V_168 , V_290 ) ;
F_185 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_36 ;
}
static int F_194 ( struct V_8 * V_9 )
{
int V_292 = 0 ;
struct V_13 * V_14 ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list)
V_292 ++ ;
F_185 ( & V_9 -> V_40 ) ;
return V_292 ;
}
int F_195 ( struct V_114 * V_114 , const struct V_170 * V_168 ,
const struct V_10 * V_11 , int V_293 )
{
return F_196 ( V_114 , V_168 , V_11 , V_293 , V_152 ) ;
}
int F_196 ( struct V_114 * V_114 , const struct V_170 * V_168 ,
const struct V_10 * V_11 , int V_293 ,
T_1 V_290 )
{
struct V_13 * V_14 ;
unsigned int V_178 = F_118 ( V_168 ) ;
T_1 V_294 ;
F_123 () ;
F_86 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_197 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_114 ) )
continue;
V_294 = ( V_14 -> V_58 & V_242 )
? ( V_14 -> V_58 & ~ V_152 )
: V_14 -> V_58 ;
if ( F_172 ( & V_14 -> V_168 , V_168 ) &&
! ( V_294 & V_290 ) &&
( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_174 & ( V_291 | V_295 ) || V_293 ) ) ) {
F_137 () ;
return 1 ;
}
}
F_137 () ;
return 0 ;
}
static bool F_125 ( struct V_114 * V_114 , const struct V_170 * V_168 ,
struct V_10 * V_11 )
{
unsigned int V_178 = F_118 ( V_168 ) ;
struct V_13 * V_14 ;
F_198 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_197 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_114 ) )
continue;
if ( F_172 ( & V_14 -> V_168 , V_168 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 )
return true ;
}
}
return false ;
}
bool F_199 ( const struct V_170 * V_168 ,
const unsigned int V_194 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_149 ;
bool V_226 = false ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifa, &idev->addr_list, if_list) {
V_226 = F_141 ( V_168 , & V_149 -> V_168 , V_194 ) ;
if ( V_226 )
break;
}
F_185 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_226 ;
}
int F_200 ( const struct V_170 * V_168 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_149 ;
int V_296 ;
V_296 = 0 ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifa, &idev->addr_list, if_list) {
V_296 = F_141 ( V_168 , & V_149 -> V_168 ,
V_149 -> V_194 ) ;
if ( V_296 )
break;
}
F_185 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_296 ;
}
struct V_13 * F_201 ( struct V_114 * V_114 , const struct V_170 * V_168 ,
struct V_10 * V_11 , int V_293 )
{
struct V_13 * V_14 , * V_297 = NULL ;
unsigned int V_178 = F_118 ( V_168 ) ;
F_123 () ;
F_202 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_197 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_114 ) )
continue;
if ( F_172 ( & V_14 -> V_168 , V_168 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_174 & ( V_291 | V_295 ) || V_293 ) ) {
V_297 = V_14 ;
F_21 ( V_14 ) ;
break;
}
}
}
F_137 () ;
return V_297 ;
}
static void F_203 ( struct V_13 * V_14 , int V_298 )
{
if ( V_298 )
V_14 -> V_58 |= V_299 ;
if ( V_14 -> V_58 & V_206 ) {
F_149 ( & V_14 -> V_40 ) ;
F_13 ( V_14 ) ;
V_14 -> V_58 |= V_152 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_298 )
F_156 ( 0 , V_14 ) ;
F_23 ( V_14 ) ;
} else if ( V_14 -> V_58 & V_198 ) {
struct V_13 * V_215 ;
F_149 ( & V_14 -> V_40 ) ;
V_215 = V_14 -> V_215 ;
if ( V_215 ) {
F_21 ( V_215 ) ;
F_150 ( & V_14 -> V_40 ) ;
F_158 ( V_215 , V_14 ) ;
F_23 ( V_215 ) ;
} else {
F_150 ( & V_14 -> V_40 ) ;
}
F_148 ( V_14 ) ;
} else {
F_148 ( V_14 ) ;
}
}
static int F_204 ( struct V_13 * V_14 )
{
int V_36 = - V_300 ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_163 == V_301 ) {
V_14 -> V_163 = V_302 ;
V_36 = 0 ;
}
F_150 ( & V_14 -> V_40 ) ;
return V_36 ;
}
void F_205 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_114 * V_114 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( F_204 ( V_14 ) ) {
F_23 ( V_14 ) ;
return;
}
F_206 ( L_13 ,
V_14 -> V_9 -> V_11 -> V_56 , & V_14 -> V_168 ) ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_58 & V_303 ) {
int V_174 = V_14 -> V_174 ;
T_1 V_58 = V_14 -> V_58 ;
struct V_170 V_304 ;
struct V_13 * V_305 ;
T_1 V_175 , V_306 ;
int V_173 = V_14 -> V_194 ;
int V_307 = V_14 -> V_308 + 1 ;
if ( V_307 > V_114 -> V_22 . V_309 . V_310 ) {
F_206 ( L_14 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
goto V_311;
}
V_304 = V_14 -> V_168 ;
if ( F_207 ( & V_304 , V_307 ,
V_9 ) )
goto V_311;
V_175 = V_14 -> V_175 ;
V_306 = V_14 -> V_176 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_9 -> V_43 . V_312 &&
F_194 ( V_9 ) >=
V_9 -> V_43 . V_312 )
goto V_313;
F_206 ( L_15 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_305 = F_121 ( V_9 , & V_304 , NULL , V_173 ,
V_174 , V_58 , V_175 ,
V_306 ) ;
if ( F_58 ( V_305 ) )
goto V_313;
F_149 ( & V_305 -> V_40 ) ;
V_305 -> V_308 = V_307 ;
V_305 -> V_163 = V_314 ;
F_150 ( & V_305 -> V_40 ) ;
F_20 ( V_305 , V_114 -> V_22 . V_309 . V_315 ) ;
F_23 ( V_305 ) ;
V_313:
F_149 ( & V_14 -> V_40 ) ;
}
V_311:
V_14 -> V_163 = V_316 ;
F_150 ( & V_14 -> V_40 ) ;
F_20 ( V_14 , 0 ) ;
F_23 ( V_14 ) ;
}
void F_208 ( struct V_10 * V_11 , const struct V_170 * V_168 )
{
struct V_170 V_317 ;
if ( V_11 -> V_58 & ( V_60 | V_59 ) )
return;
F_209 ( V_168 , & V_317 ) ;
F_54 ( V_11 , & V_317 ) ;
}
void F_210 ( struct V_8 * V_9 , const struct V_170 * V_168 )
{
struct V_170 V_317 ;
if ( V_9 -> V_11 -> V_58 & ( V_60 | V_59 ) )
return;
F_209 ( V_168 , & V_317 ) ;
F_211 ( V_9 , & V_317 ) ;
}
static void F_93 ( struct V_13 * V_14 )
{
struct V_170 V_168 ;
if ( V_14 -> V_194 >= 127 )
return;
F_212 ( & V_168 , & V_14 -> V_168 , V_14 -> V_194 ) ;
if ( F_213 ( & V_168 ) )
return;
F_214 ( V_14 -> V_9 , & V_168 ) ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_170 V_168 ;
if ( V_14 -> V_194 >= 127 )
return;
F_212 ( & V_168 , & V_14 -> V_168 , V_14 -> V_194 ) ;
if ( F_213 ( & V_168 ) )
return;
F_215 ( V_14 -> V_9 , & V_168 ) ;
}
static int F_216 ( T_5 * V_318 , struct V_10 * V_11 )
{
switch ( V_11 -> V_319 ) {
case V_320 :
memcpy ( V_318 , V_11 -> V_321 , 3 ) ;
V_318 [ 3 ] = 0xFF ;
V_318 [ 4 ] = 0xFE ;
memcpy ( V_318 + 5 , V_11 -> V_321 + 3 , 3 ) ;
break;
case V_322 :
memcpy ( V_318 , V_11 -> V_321 , V_322 ) ;
V_318 [ 0 ] ^= 2 ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_217 ( T_5 * V_318 , struct V_10 * V_11 )
{
union V_323 * V_324 ;
if ( V_11 -> V_319 != V_325 )
return - 1 ;
V_324 = (union V_323 * ) V_11 -> V_321 ;
memcpy ( V_318 , & V_324 -> V_326 . V_327 , sizeof( V_324 -> V_326 . V_327 ) ) ;
V_318 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_218 ( T_5 * V_318 , struct V_10 * V_11 )
{
if ( V_11 -> V_319 != V_328 )
return - 1 ;
memset ( V_318 , 0 , 7 ) ;
V_318 [ 7 ] = * ( T_5 * ) V_11 -> V_321 ;
return 0 ;
}
static int F_219 ( T_5 * V_318 , struct V_10 * V_11 )
{
if ( V_11 -> V_319 != V_329 )
return - 1 ;
memcpy ( V_318 , V_11 -> V_321 + 12 , 8 ) ;
V_318 [ 0 ] |= 2 ;
return 0 ;
}
static int F_220 ( T_5 * V_318 , T_6 V_168 )
{
if ( V_168 == 0 )
return - 1 ;
V_318 [ 0 ] = ( F_221 ( V_168 ) || F_222 ( V_168 ) ||
F_223 ( V_168 ) || F_224 ( V_168 ) ||
F_225 ( V_168 ) || F_226 ( V_168 ) ||
F_227 ( V_168 ) || F_228 ( V_168 ) ||
F_229 ( V_168 ) || F_230 ( V_168 ) ||
F_231 ( V_168 ) ) ? 0x00 : 0x02 ;
V_318 [ 1 ] = 0 ;
V_318 [ 2 ] = 0x5E ;
V_318 [ 3 ] = 0xFE ;
memcpy ( V_318 + 4 , & V_168 , 4 ) ;
return 0 ;
}
static int F_232 ( T_5 * V_318 , struct V_10 * V_11 )
{
if ( V_11 -> V_64 & V_65 )
return F_220 ( V_318 , * ( T_6 * ) V_11 -> V_321 ) ;
return - 1 ;
}
static int F_233 ( T_5 * V_318 , struct V_10 * V_11 )
{
return F_220 ( V_318 , * ( T_6 * ) V_11 -> V_321 ) ;
}
static int F_234 ( T_5 * V_318 , struct V_10 * V_11 )
{
memcpy ( V_318 , V_11 -> V_330 , 3 ) ;
memcpy ( V_318 + 5 , V_11 -> V_330 + 3 , 3 ) ;
V_318 [ 3 ] = 0xFF ;
V_318 [ 4 ] = 0xFE ;
V_318 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_235 ( T_5 * V_318 , struct V_10 * V_11 )
{
switch ( V_11 -> type ) {
case V_331 :
case V_332 :
return F_236 ( V_318 , V_11 ) ;
case V_333 :
return F_218 ( V_318 , V_11 ) ;
case V_334 :
return F_219 ( V_318 , V_11 ) ;
case V_63 :
return F_232 ( V_318 , V_11 ) ;
case V_335 :
case V_70 :
return F_233 ( V_318 , V_11 ) ;
case V_336 :
return F_216 ( V_318 , V_11 ) ;
case V_337 :
return F_217 ( V_318 , V_11 ) ;
case V_71 :
case V_338 :
return F_234 ( V_318 , V_11 ) ;
}
return - 1 ;
}
static int F_237 ( T_5 * V_318 , struct V_8 * V_9 )
{
int V_36 = - 1 ;
struct V_13 * V_14 ;
F_180 ( & V_9 -> V_40 ) ;
F_192 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_174 > V_291 )
break;
if ( V_14 -> V_174 == V_291 && ! ( V_14 -> V_58 & V_152 ) ) {
memcpy ( V_318 , V_14 -> V_168 . V_231 + 8 , 8 ) ;
V_36 = 0 ;
break;
}
}
F_185 ( & V_9 -> V_40 ) ;
return V_36 ;
}
static void F_48 ( struct V_8 * V_9 )
{
V_339:
F_164 ( V_9 -> V_235 , sizeof( V_9 -> V_235 ) ) ;
V_9 -> V_235 [ 0 ] &= ~ 0x02 ;
if ( V_9 -> V_235 [ 0 ] == 0xfd &&
( V_9 -> V_235 [ 1 ] & V_9 -> V_235 [ 2 ] & V_9 -> V_235 [ 3 ] & V_9 -> V_235 [ 4 ] & V_9 -> V_235 [ 5 ] & V_9 -> V_235 [ 6 ] ) == 0xff &&
( V_9 -> V_235 [ 7 ] & 0x80 ) )
goto V_339;
if ( ( V_9 -> V_235 [ 0 ] | V_9 -> V_235 [ 1 ] ) == 0 ) {
if ( V_9 -> V_235 [ 2 ] == 0x5e && V_9 -> V_235 [ 3 ] == 0xfe )
goto V_339;
if ( ( V_9 -> V_235 [ 2 ] | V_9 -> V_235 [ 3 ] | V_9 -> V_235 [ 4 ] | V_9 -> V_235 [ 5 ] | V_9 -> V_235 [ 6 ] | V_9 -> V_235 [ 7 ] ) == 0x00 )
goto V_339;
}
}
static void F_159 ( struct V_8 * V_9 , struct V_170 * V_219 )
{
if ( V_219 && memcmp ( V_9 -> V_235 , & V_219 -> V_231 [ 8 ] , 8 ) == 0 )
F_48 ( V_9 ) ;
}
static void
F_238 ( struct V_170 * V_340 , int V_341 , struct V_10 * V_11 ,
unsigned long V_202 , T_1 V_58 )
{
struct V_342 V_343 = {
. V_344 = F_239 ( V_11 ) ? : V_345 ,
. V_346 = V_347 ,
. V_348 = V_11 -> V_96 ,
. V_349 = V_202 ,
. V_350 = V_341 ,
. V_351 = V_352 | V_58 ,
. V_353 . V_354 = F_38 ( V_11 ) ,
. V_355 = V_356 ,
} ;
V_343 . V_357 = * V_340 ;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 && ( V_11 -> V_58 & V_358 ) )
V_343 . V_351 |= V_359 ;
#endif
F_240 ( & V_343 ) ;
}
static struct V_177 * F_145 ( const struct V_170 * V_340 ,
int V_341 ,
const struct V_10 * V_11 ,
T_1 V_58 , T_1 V_360 )
{
struct V_361 * V_362 ;
struct V_177 * V_6 = NULL ;
struct V_363 * V_156 ;
T_1 V_364 = F_239 ( V_11 ) ? : V_345 ;
V_156 = F_241 ( F_38 ( V_11 ) , V_364 ) ;
if ( ! V_156 )
return NULL ;
F_180 ( & V_156 -> V_365 ) ;
V_362 = F_242 ( & V_156 -> V_366 , V_340 , V_341 , NULL , 0 ) ;
if ( ! V_362 )
goto V_110;
V_360 |= V_367 ;
for ( V_6 = V_362 -> V_368 ; V_6 ; V_6 = V_6 -> V_191 . V_369 ) {
if ( V_6 -> V_191 . V_11 -> V_96 != V_11 -> V_96 )
continue;
if ( ( V_6 -> V_213 & V_58 ) != V_58 )
continue;
if ( ( V_6 -> V_213 & V_360 ) != 0 )
continue;
F_243 ( & V_6 -> V_191 ) ;
break;
}
V_110:
F_185 ( & V_156 -> V_365 ) ;
return V_6 ;
}
static void F_244 ( struct V_10 * V_11 )
{
struct V_342 V_343 = {
. V_344 = F_239 ( V_11 ) ? : V_370 ,
. V_346 = V_347 ,
. V_348 = V_11 -> V_96 ,
. V_350 = 8 ,
. V_351 = V_352 ,
. V_353 . V_354 = F_38 ( V_11 ) ,
} ;
F_245 ( & V_343 . V_357 , F_246 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_240 ( & V_343 ) ;
}
static struct V_8 * F_247 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 )
return F_34 ( - V_115 ) ;
if ( V_9 -> V_43 . V_186 )
return F_34 ( - V_187 ) ;
if ( ! ( V_11 -> V_58 & V_60 ) && ! F_248 ( V_11 ) )
F_244 ( V_11 ) ;
return V_9 ;
}
static void F_249 ( struct V_8 * V_9 ,
struct V_13 * V_14 ,
V_239 V_175 , V_239 V_176 ,
bool V_371 , unsigned long V_228 )
{
T_1 V_58 ;
struct V_13 * V_218 ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (ift, &idev->tempaddr_list, tmp_list) {
int V_223 , V_372 , V_373 ;
if ( V_14 != V_218 -> V_215 )
continue;
V_223 = ( V_228 - V_218 -> V_1 ) / V_3 ;
V_372 = V_9 -> V_43 . V_240 - V_223 ;
if ( V_372 < 0 )
V_372 = 0 ;
V_373 = V_9 -> V_43 . V_238 -
V_9 -> V_68 - V_223 ;
if ( V_373 < 0 )
V_373 = 0 ;
if ( V_175 > V_372 )
V_175 = V_372 ;
if ( V_176 > V_373 )
V_176 = V_373 ;
F_124 ( & V_218 -> V_40 ) ;
V_58 = V_218 -> V_58 ;
V_218 -> V_175 = V_175 ;
V_218 -> V_176 = V_176 ;
V_218 -> V_78 = V_228 ;
if ( V_176 > 0 )
V_218 -> V_58 &= ~ V_260 ;
F_133 ( & V_218 -> V_40 ) ;
if ( ! ( V_58 & V_152 ) )
F_156 ( 0 , V_218 ) ;
}
if ( ( V_371 || F_250 ( & V_9 -> V_67 ) ) &&
V_9 -> V_43 . V_73 > 0 ) {
F_185 ( & V_9 -> V_40 ) ;
F_158 ( V_14 , NULL ) ;
} else {
F_185 ( & V_9 -> V_40 ) ;
}
}
static bool F_251 ( struct V_8 * V_9 )
{
return V_9 -> V_43 . V_47 == V_48 ||
V_9 -> V_43 . V_47 == V_374 ;
}
int F_252 ( struct V_114 * V_114 , struct V_10 * V_11 ,
const struct V_375 * V_376 ,
struct V_8 * V_125 ,
const struct V_170 * V_168 , int V_179 ,
T_1 V_227 , bool V_377 , bool V_196 ,
V_239 V_175 , T_1 V_176 )
{
struct V_13 * V_14 = F_201 ( V_114 , V_168 , V_11 , 1 ) ;
int V_371 = 0 , V_378 = 0 ;
if ( ! V_14 && V_175 ) {
int V_312 = V_125 -> V_43 . V_312 ;
#ifdef F_169
if ( V_125 -> V_43 . V_245 &&
! V_114 -> V_22 . V_128 -> V_53 && V_377 )
V_227 |= V_242 ;
#endif
if ( ! V_312 ||
F_194 ( V_125 ) < V_312 )
V_14 = F_121 ( V_125 , V_168 , NULL ,
V_376 -> V_194 ,
V_179 & V_379 ,
V_227 , V_175 ,
V_176 ) ;
if ( F_253 ( V_14 ) )
return - 1 ;
V_378 = 0 ;
V_371 = 1 ;
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 |= V_380 ;
V_14 -> V_1 = V_17 ;
V_14 -> V_196 = V_196 ;
F_150 ( & V_14 -> V_40 ) ;
F_166 ( V_14 ) ;
}
if ( V_14 ) {
T_1 V_58 ;
unsigned long V_228 ;
T_1 V_381 ;
F_149 ( & V_14 -> V_40 ) ;
V_228 = V_17 ;
if ( V_14 -> V_175 > ( V_228 - V_14 -> V_78 ) / V_3 )
V_381 = V_14 -> V_175 - ( V_228 - V_14 -> V_78 ) / V_3 ;
else
V_381 = 0 ;
if ( ! V_378 && ! V_371 && V_381 ) {
const T_1 V_382 = F_162 ( T_1 ,
V_381 , V_383 ) ;
V_175 = F_254 ( V_175 , V_382 ) ;
V_378 = 1 ;
}
if ( V_378 ) {
V_14 -> V_175 = V_175 ;
V_14 -> V_176 = V_176 ;
V_14 -> V_78 = V_228 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_260 ;
F_150 ( & V_14 -> V_40 ) ;
if ( ! ( V_58 & V_152 ) )
F_156 ( 0 , V_14 ) ;
} else
F_150 ( & V_14 -> V_40 ) ;
F_249 ( V_125 , V_14 , V_175 , V_176 ,
V_371 , V_228 ) ;
F_23 ( V_14 ) ;
F_255 () ;
}
return 0 ;
}
void F_256 ( struct V_10 * V_11 , T_5 * V_384 , int V_148 , bool V_377 )
{
struct V_375 * V_376 ;
V_239 V_175 ;
V_239 V_176 ;
int V_179 , V_36 ;
T_1 V_227 = 0 ;
struct V_8 * V_125 ;
struct V_114 * V_114 = F_38 ( V_11 ) ;
V_376 = (struct V_375 * ) V_384 ;
if ( V_148 < sizeof( struct V_375 ) ) {
F_42 ( L_16 ) ;
return;
}
V_179 = F_122 ( & V_376 -> V_385 ) ;
if ( V_179 & ( V_181 | V_386 ) )
return;
V_175 = F_257 ( V_376 -> V_387 ) ;
V_176 = F_257 ( V_376 -> V_388 ) ;
if ( V_176 > V_175 ) {
F_258 ( L_17 ) ;
return;
}
V_125 = F_259 ( V_11 ) ;
if ( ! V_125 ) {
F_182 ( L_18 ,
V_11 -> V_56 ) ;
return;
}
if ( V_376 -> V_296 ) {
struct V_177 * V_6 ;
unsigned long V_389 ;
if ( V_3 > V_390 )
V_389 = F_142 ( V_175 , V_3 ) ;
else
V_389 = F_142 ( V_175 , V_390 ) ;
if ( F_260 ( V_389 ) )
V_389 *= V_3 ;
V_6 = F_145 ( & V_376 -> V_385 ,
V_376 -> V_194 ,
V_11 ,
V_391 | V_392 ,
V_211 | V_212 ) ;
if ( V_6 ) {
if ( V_175 == 0 ) {
F_146 ( V_6 ) ;
V_6 = NULL ;
} else if ( F_260 ( V_389 ) ) {
F_147 ( V_6 , V_17 + V_389 ) ;
} else {
F_261 ( V_6 ) ;
}
} else if ( V_175 ) {
T_7 V_202 = 0 ;
int V_58 = V_391 | V_392 ;
if ( F_260 ( V_389 ) ) {
V_58 |= V_214 ;
V_202 = F_262 ( V_389 ) ;
}
F_238 ( & V_376 -> V_385 , V_376 -> V_194 ,
V_11 , V_202 , V_58 ) ;
}
F_111 ( V_6 ) ;
}
if ( V_376 -> V_393 && V_125 -> V_43 . V_393 ) {
struct V_170 V_168 ;
bool V_196 = false , V_394 = false ;
if ( V_376 -> V_194 == 64 ) {
memcpy ( & V_168 , & V_376 -> V_385 , 8 ) ;
if ( ! F_213 ( & V_125 -> V_74 ) ) {
F_180 ( & V_125 -> V_40 ) ;
memcpy ( V_168 . V_231 + 8 ,
V_125 -> V_74 . V_231 + 8 , 8 ) ;
F_185 ( & V_125 -> V_40 ) ;
V_196 = true ;
} else if ( F_251 ( V_125 ) &&
! F_207 ( & V_168 , 0 ,
V_125 ) ) {
V_227 |= V_303 ;
goto V_395;
} else if ( F_235 ( V_168 . V_231 + 8 , V_11 ) &&
F_237 ( V_168 . V_231 + 8 , V_125 ) ) {
goto V_396;
} else {
V_394 = true ;
}
goto V_395;
}
F_182 ( L_19 ,
V_376 -> V_194 ) ;
goto V_396;
V_395:
V_36 = F_252 ( V_114 , V_11 , V_376 , V_125 ,
& V_168 , V_179 ,
V_227 , V_377 ,
V_196 , V_175 ,
V_176 ) ;
if ( V_36 )
goto V_396;
F_263 ( V_114 , V_11 , V_376 , V_125 , & V_168 ,
V_179 , V_227 , V_377 ,
V_196 , V_175 ,
V_176 ,
V_394 ) ;
}
F_264 ( V_397 , V_125 , V_376 ) ;
V_396:
F_108 ( V_125 ) ;
}
int F_265 ( struct V_114 * V_114 , void T_8 * V_398 )
{
struct V_399 V_400 ;
struct V_10 * V_11 ;
int V_36 = - V_39 ;
F_266 () ;
V_36 = - V_401 ;
if ( F_267 ( & V_400 , V_398 , sizeof( struct V_399 ) ) )
goto V_402;
V_11 = F_80 ( V_114 , V_400 . V_403 ) ;
V_36 = - V_184 ;
if ( ! V_11 )
goto V_402;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 ) {
const struct V_404 * V_405 = V_11 -> V_406 ;
struct V_407 V_408 ;
struct V_409 V_157 ;
V_36 = - V_183 ;
if ( ! ( F_122 ( & V_400 . V_410 ) & V_244 ) )
goto V_402;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_157 . V_411 . V_283 = V_400 . V_410 . V_412 [ 3 ] ;
V_157 . V_411 . V_284 = 0 ;
V_157 . V_411 . V_413 = 4 ;
V_157 . V_411 . V_414 = 5 ;
V_157 . V_411 . V_415 = V_416 ;
V_157 . V_411 . V_417 = 64 ;
V_408 . V_418 . V_419 = ( V_420 void T_8 * ) & V_157 ;
if ( V_405 -> V_421 ) {
T_9 V_422 = F_268 () ;
F_269 ( V_423 ) ;
V_36 = V_405 -> V_421 ( V_11 , & V_408 , V_424 ) ;
F_269 ( V_422 ) ;
} else
V_36 = - V_425 ;
if ( V_36 == 0 ) {
V_36 = - V_115 ;
V_11 = F_270 ( V_114 , V_157 . V_56 ) ;
if ( ! V_11 )
goto V_402;
V_36 = F_271 ( V_11 ) ;
}
}
#endif
V_402:
F_100 () ;
return V_36 ;
}
static int F_272 ( struct V_426 * V_121 , bool V_427 ,
const struct V_170 * V_168 , int V_96 )
{
int V_226 ;
F_33 () ;
F_273 ( V_121 ) ;
if ( V_427 )
V_226 = F_274 ( V_121 , V_96 , V_168 ) ;
else
V_226 = F_275 ( V_121 , V_96 , V_168 ) ;
F_276 ( V_121 ) ;
return V_226 ;
}
static int F_277 ( struct V_114 * V_114 , int V_96 ,
const struct V_170 * V_340 ,
const struct V_170 * V_428 ,
unsigned int V_341 , V_239 V_429 ,
V_239 V_176 , V_239 V_175 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned long V_430 ;
T_7 V_202 ;
int V_174 ;
T_1 V_58 ;
F_33 () ;
if ( V_341 > 128 )
return - V_39 ;
if ( ! V_175 || V_176 > V_175 )
return - V_39 ;
if ( V_429 & V_380 && V_341 != 64 )
return - V_39 ;
V_11 = F_80 ( V_114 , V_96 ) ;
if ( ! V_11 )
return - V_184 ;
V_9 = F_247 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_127 ( V_9 ) ;
if ( V_429 & V_431 ) {
int V_226 = F_272 ( V_114 -> V_22 . V_432 ,
true , V_340 , V_96 ) ;
if ( V_226 < 0 )
return V_226 ;
}
V_174 = F_165 ( V_340 ) ;
V_430 = F_142 ( V_175 , V_3 ) ;
if ( F_260 ( V_430 ) ) {
V_202 = F_262 ( V_430 * V_3 ) ;
V_175 = V_430 ;
V_58 = V_214 ;
} else {
V_202 = 0 ;
V_58 = 0 ;
V_429 |= V_206 ;
}
V_430 = F_142 ( V_176 , V_3 ) ;
if ( F_260 ( V_430 ) ) {
if ( V_430 == 0 )
V_429 |= V_260 ;
V_176 = V_430 ;
}
V_14 = F_121 ( V_9 , V_340 , V_428 , V_341 , V_174 , V_429 ,
V_175 , V_176 ) ;
if ( ! F_58 ( V_14 ) ) {
if ( ! ( V_429 & V_207 ) ) {
F_238 ( & V_14 -> V_168 , V_14 -> V_194 , V_11 ,
V_202 , V_58 ) ;
}
F_166 ( V_14 ) ;
if ( V_429 & V_380 )
F_249 ( V_9 , V_14 , V_175 , V_176 ,
true , V_17 ) ;
F_23 ( V_14 ) ;
F_278 () ;
return 0 ;
} else if ( V_429 & V_431 ) {
F_272 ( V_114 -> V_22 . V_432 ,
false , V_340 , V_96 ) ;
}
return F_127 ( V_14 ) ;
}
static int F_279 ( struct V_114 * V_114 , int V_96 , T_1 V_429 ,
const struct V_170 * V_340 , unsigned int V_341 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_341 > 128 )
return - V_39 ;
V_11 = F_80 ( V_114 , V_96 ) ;
if ( ! V_11 )
return - V_184 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_433 ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_194 == V_341 &&
F_172 ( V_340 , & V_14 -> V_168 ) ) {
F_21 ( V_14 ) ;
F_185 ( & V_9 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_198 ) &&
( V_429 & V_380 ) )
F_249 ( V_9 , V_14 , 0 , 0 , false ,
V_17 ) ;
F_148 ( V_14 ) ;
F_278 () ;
if ( F_280 ( V_340 ) ) {
F_272 ( V_114 -> V_22 . V_432 ,
false , V_340 , V_11 -> V_96 ) ;
}
return 0 ;
}
}
F_185 ( & V_9 -> V_40 ) ;
return - V_183 ;
}
int F_281 ( struct V_114 * V_114 , void T_8 * V_398 )
{
struct V_399 V_400 ;
int V_36 ;
if ( ! F_282 ( V_114 -> V_434 , V_435 ) )
return - V_436 ;
if ( F_267 ( & V_400 , V_398 , sizeof( struct V_399 ) ) )
return - V_401 ;
F_266 () ;
V_36 = F_277 ( V_114 , V_400 . V_403 , & V_400 . V_410 , NULL ,
V_400 . V_437 , V_206 ,
V_438 , V_438 ) ;
F_100 () ;
return V_36 ;
}
int F_283 ( struct V_114 * V_114 , void T_8 * V_398 )
{
struct V_399 V_400 ;
int V_36 ;
if ( ! F_282 ( V_114 -> V_434 , V_435 ) )
return - V_436 ;
if ( F_267 ( & V_400 , V_398 , sizeof( struct V_399 ) ) )
return - V_401 ;
F_266 () ;
V_36 = F_279 ( V_114 , V_400 . V_403 , 0 , & V_400 . V_410 ,
V_400 . V_437 ) ;
F_100 () ;
return V_36 ;
}
static void F_284 ( struct V_8 * V_9 , const struct V_170 * V_168 ,
int V_341 , int V_174 )
{
struct V_13 * V_14 ;
V_14 = F_121 ( V_9 , V_168 , NULL , V_341 ,
V_174 , V_206 ,
V_438 , V_438 ) ;
if ( ! F_58 ( V_14 ) ) {
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 &= ~ V_152 ;
F_150 ( & V_14 -> V_40 ) ;
F_285 ( F_38 ( V_9 -> V_11 ) ) ;
F_156 ( V_439 , V_14 ) ;
F_23 ( V_14 ) ;
}
}
static void F_286 ( struct V_8 * V_9 )
{
struct V_170 V_168 ;
struct V_10 * V_11 ;
struct V_114 * V_114 = F_38 ( V_9 -> V_11 ) ;
int V_174 , V_341 ;
T_1 V_440 = 0 ;
F_33 () ;
memset ( & V_168 , 0 , sizeof( struct V_170 ) ) ;
memcpy ( & V_168 . V_412 [ 3 ] , V_9 -> V_11 -> V_321 , 4 ) ;
if ( V_9 -> V_11 -> V_58 & V_358 ) {
V_168 . V_412 [ 0 ] = F_246 ( 0xfe800000 ) ;
V_174 = V_291 ;
V_341 = 64 ;
} else {
V_174 = V_244 ;
V_341 = 96 ;
V_440 |= V_359 ;
}
if ( V_168 . V_412 [ 3 ] ) {
F_284 ( V_9 , & V_168 , V_341 , V_174 ) ;
F_238 ( & V_168 , V_341 , V_9 -> V_11 , 0 , V_440 ) ;
return;
}
F_96 (net, dev) {
struct V_441 * V_442 = F_287 ( V_11 ) ;
if ( V_442 && ( V_11 -> V_58 & V_85 ) ) {
struct V_443 * V_149 ;
int V_444 = V_174 ;
for ( V_149 = V_442 -> V_445 ; V_149 ; V_149 = V_149 -> V_446 ) {
V_168 . V_412 [ 3 ] = V_149 -> V_447 ;
if ( V_149 -> V_448 == V_449 )
continue;
if ( V_149 -> V_448 >= V_450 ) {
if ( V_9 -> V_11 -> V_58 & V_358 )
continue;
V_444 |= V_295 ;
}
F_284 ( V_9 , & V_168 , V_341 , V_444 ) ;
F_238 ( & V_168 , V_341 , V_9 -> V_11 , 0 ,
V_440 ) ;
}
}
}
}
static void F_288 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_10 * V_451 ;
struct V_13 * V_452 ;
struct V_177 * V_453 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
F_284 ( V_9 , & V_454 , 128 , V_295 ) ;
F_96 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_451 -> V_56 , V_11 -> V_56 ) )
continue;
V_9 = F_57 ( V_451 ) ;
if ( ! V_9 )
continue;
F_180 ( & V_9 -> V_40 ) ;
F_92 (sp_ifa, &idev->addr_list, if_list) {
if ( V_452 -> V_58 & ( V_299 | V_152 ) )
continue;
if ( V_452 -> V_6 ) {
if ( ! F_85 ( & V_452 -> V_6 -> V_455 ) ) {
F_111 ( V_452 -> V_6 ) ;
V_452 -> V_6 = NULL ;
} else {
continue;
}
}
V_453 = F_126 ( V_9 , & V_452 -> V_168 , false ) ;
if ( ! F_58 ( V_453 ) ) {
V_452 -> V_6 = V_453 ;
F_289 ( V_453 ) ;
}
}
F_185 ( & V_9 -> V_40 ) ;
}
}
void F_290 ( struct V_8 * V_9 ,
const struct V_170 * V_168 , T_1 V_58 )
{
struct V_13 * V_14 ;
T_1 V_227 = V_58 | V_206 ;
#ifdef F_169
if ( V_9 -> V_43 . V_245 &&
! F_38 ( V_9 -> V_11 ) -> V_22 . V_128 -> V_53 )
V_227 |= V_242 ;
#endif
V_14 = F_121 ( V_9 , V_168 , NULL , 64 , V_291 , V_227 ,
V_438 , V_438 ) ;
if ( ! F_58 ( V_14 ) ) {
F_238 ( & V_14 -> V_168 , V_14 -> V_194 , V_9 -> V_11 , 0 , 0 ) ;
F_166 ( V_14 ) ;
F_23 ( V_14 ) ;
}
}
static bool F_291 ( struct V_170 V_456 )
{
if ( ( V_456 . V_412 [ 2 ] | V_456 . V_412 [ 3 ] ) == 0 )
return true ;
if ( V_456 . V_412 [ 2 ] == F_246 ( 0x02005eff ) &&
( ( V_456 . V_412 [ 3 ] & F_246 ( 0xfe000000 ) ) == F_246 ( 0xfe000000 ) ) )
return true ;
if ( V_456 . V_412 [ 2 ] == F_246 ( 0xfdffffff ) &&
( ( V_456 . V_412 [ 3 ] & F_246 ( 0xffffff80 ) ) == F_246 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_207 ( struct V_170 * V_456 ,
T_5 V_457 ,
const struct V_8 * V_9 )
{
static F_292 ( V_40 ) ;
static V_239 V_458 [ V_459 ] ;
static V_239 V_460 [ V_461 ] ;
static union {
char V_462 [ V_463 ] ;
struct {
struct V_170 V_464 ;
T_6 V_385 [ 2 ] ;
unsigned char V_465 [ V_466 ] ;
T_5 V_457 ;
} V_467 ;
} V_468 ;
struct V_170 V_464 ;
struct V_170 V_469 ;
struct V_114 * V_114 = F_38 ( V_9 -> V_11 ) ;
F_293 ( sizeof( V_468 . V_462 ) != sizeof( V_468 ) ) ;
if ( V_9 -> V_43 . V_45 . V_46 )
V_464 = V_9 -> V_43 . V_45 . V_464 ;
else if ( V_114 -> V_22 . V_44 -> V_45 . V_46 )
V_464 = V_114 -> V_22 . V_44 -> V_45 . V_464 ;
else
return - 1 ;
V_232:
F_149 ( & V_40 ) ;
F_294 ( V_458 ) ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
memset ( V_460 , 0 , sizeof( V_460 ) ) ;
memcpy ( V_468 . V_465 , V_9 -> V_11 -> V_330 , V_9 -> V_11 -> V_319 ) ;
V_468 . V_385 [ 0 ] = V_456 -> V_412 [ 0 ] ;
V_468 . V_385 [ 1 ] = V_456 -> V_412 [ 1 ] ;
V_468 . V_464 = V_464 ;
V_468 . V_457 = V_457 ;
F_295 ( V_458 , V_468 . V_462 , V_460 ) ;
V_469 = * V_456 ;
V_469 . V_412 [ 2 ] = ( V_420 T_6 ) V_458 [ 0 ] ;
V_469 . V_412 [ 3 ] = ( V_420 T_6 ) V_458 [ 1 ] ;
F_150 ( & V_40 ) ;
if ( F_291 ( V_469 ) ) {
V_457 ++ ;
if ( V_457 > F_38 ( V_9 -> V_11 ) -> V_22 . V_309 . V_310 )
return - 1 ;
goto V_232;
}
* V_456 = V_469 ;
return 0 ;
}
static void F_296 ( struct V_8 * V_9 )
{
struct V_470 * V_471 = & V_9 -> V_43 . V_45 ;
if ( V_471 -> V_46 )
return;
V_471 = & V_9 -> V_43 . V_45 ;
F_164 ( & V_471 -> V_464 , sizeof( V_471 -> V_464 ) ) ;
V_471 -> V_46 = true ;
}
static void F_297 ( struct V_8 * V_9 , bool V_472 )
{
struct V_170 V_168 ;
if ( F_248 ( V_9 -> V_11 ) )
return;
F_245 ( & V_168 , F_246 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_9 -> V_43 . V_47 ) {
case V_374 :
F_296 ( V_9 ) ;
case V_48 :
if ( ! F_207 ( & V_168 , 0 , V_9 ) )
F_290 ( V_9 , & V_168 ,
V_303 ) ;
else if ( V_472 )
F_238 ( & V_168 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_473 :
if ( F_235 ( V_168 . V_231 + 8 , V_9 -> V_11 ) == 0 )
F_290 ( V_9 , & V_168 , 0 ) ;
else if ( V_472 )
F_238 ( & V_168 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_474 :
default:
break;
}
}
static void F_298 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
if ( ( V_11 -> type != V_331 ) &&
( V_11 -> type != V_332 ) &&
( V_11 -> type != V_333 ) &&
( V_11 -> type != V_334 ) &&
( V_11 -> type != V_337 ) &&
( V_11 -> type != V_71 ) &&
( V_11 -> type != V_336 ) &&
( V_11 -> type != V_338 ) &&
( V_11 -> type != V_335 ) &&
( V_11 -> type != V_70 ) &&
( V_11 -> type != V_72 ) ) {
return;
}
V_9 = F_247 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return;
if ( V_11 -> type == V_72 &&
V_9 -> V_43 . V_47 == V_473 )
V_9 -> V_43 . V_47 = V_374 ;
F_297 ( V_9 , false ) ;
}
static void F_299 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
if ( V_11 -> V_64 & V_65 ) {
F_297 ( V_9 , false ) ;
return;
}
F_286 ( V_9 ) ;
if ( V_11 -> V_58 & V_358 )
F_244 ( V_11 ) ;
}
static void F_300 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
F_297 ( V_9 , true ) ;
if ( V_11 -> V_58 & V_358 )
F_244 ( V_11 ) ;
}
static int F_301 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_6 || ! F_85 ( & V_14 -> V_6 -> V_455 ) ) {
struct V_177 * V_6 , * V_475 ;
V_6 = F_126 ( V_9 , & V_14 -> V_168 , false ) ;
if ( F_163 ( F_58 ( V_6 ) ) )
return F_127 ( V_6 ) ;
F_124 ( & V_14 -> V_40 ) ;
V_475 = V_14 -> V_6 ;
V_14 -> V_6 = V_6 ;
F_133 ( & V_14 -> V_40 ) ;
F_111 ( V_475 ) ;
}
if ( ! ( V_14 -> V_58 & V_207 ) ) {
F_238 ( & V_14 -> V_168 , V_14 -> V_194 ,
V_9 -> V_11 , 0 , 0 ) ;
}
if ( V_14 -> V_163 == V_314 )
F_166 ( V_14 ) ;
return 0 ;
}
static void F_302 ( struct V_10 * V_11 )
{
struct V_13 * V_14 , * V_5 ;
struct V_8 * V_9 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return;
F_152 ( & V_9 -> V_40 ) ;
F_303 (ifp, tmp, &idev->addr_list, if_list) {
if ( ( V_14 -> V_58 & V_206 ) &&
F_301 ( V_9 , V_14 ) < 0 ) {
F_155 ( & V_9 -> V_40 ) ;
F_148 ( V_14 ) ;
F_152 ( & V_9 -> V_40 ) ;
F_206 ( L_21 ,
V_9 -> V_11 -> V_56 , & V_14 -> V_168 ) ;
}
}
F_155 ( & V_9 -> V_40 ) ;
}
static int F_304 ( struct V_476 * V_477 , unsigned long V_101 ,
void * V_478 )
{
struct V_10 * V_11 = F_305 ( V_478 ) ;
struct V_479 * V_480 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
struct V_114 * V_114 = F_38 ( V_11 ) ;
int V_481 = 0 ;
int V_36 ;
switch ( V_101 ) {
case V_482 :
if ( ! V_9 && V_11 -> V_37 >= V_38 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_306 ( F_127 ( V_9 ) ) ;
}
break;
case V_483 :
if ( V_11 -> V_37 < V_38 ) {
F_307 ( V_11 , V_11 != V_114 -> V_484 ) ;
break;
}
if ( V_9 ) {
F_308 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
break;
}
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
break;
if ( ! ( V_9 -> V_76 & V_77 ) )
break;
V_481 = 1 ;
case V_200 :
case V_485 :
if ( V_11 -> V_58 & V_486 )
break;
if ( V_9 && V_9 -> V_43 . V_186 )
break;
if ( V_101 == V_200 ) {
F_302 ( V_11 ) ;
if ( ! F_8 ( V_11 ) ) {
F_47 ( L_22 ,
V_11 -> V_56 ) ;
break;
}
if ( ! V_9 && V_11 -> V_37 >= V_38 )
V_9 = F_32 ( V_11 ) ;
if ( ! F_253 ( V_9 ) ) {
V_9 -> V_76 |= V_77 ;
V_481 = 1 ;
}
} else if ( V_101 == V_485 ) {
if ( ! F_8 ( V_11 ) ) {
break;
}
if ( V_9 ) {
if ( V_9 -> V_76 & V_77 ) {
F_59 ( V_9 ) ;
break;
}
V_9 -> V_76 |= V_77 ;
}
F_47 ( L_23 ,
V_11 -> V_56 ) ;
V_481 = 1 ;
}
switch ( V_11 -> type ) {
#if F_46 ( V_62 )
case V_63 :
F_299 ( V_11 ) ;
break;
#endif
#if F_46 ( V_487 )
case V_335 :
F_300 ( V_11 ) ;
break;
#endif
case V_488 :
F_288 ( V_11 ) ;
break;
default:
F_298 ( V_11 ) ;
break;
}
if ( ! F_253 ( V_9 ) ) {
if ( V_481 )
F_309 ( V_9 ) ;
if ( V_9 -> V_43 . V_50 != V_11 -> V_37 &&
V_11 -> V_37 >= V_38 ) {
F_308 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
}
V_9 -> V_78 = V_17 ;
F_310 ( V_489 , V_9 ) ;
if ( V_11 -> V_37 < V_38 )
F_307 ( V_11 , V_11 != V_114 -> V_484 ) ;
}
break;
case V_217 :
case V_490 :
F_307 ( V_11 , V_101 != V_217 ) ;
break;
case V_491 :
if ( V_9 ) {
F_52 ( V_9 ) ;
F_7 ( V_9 ) ;
V_36 = F_6 ( V_9 ) ;
if ( V_36 )
return F_306 ( V_36 ) ;
V_36 = F_45 ( V_9 ) ;
if ( V_36 ) {
F_7 ( V_9 ) ;
return F_306 ( V_36 ) ;
}
}
break;
case V_492 :
case V_493 :
if ( V_9 )
F_311 ( V_11 , V_101 ) ;
break;
case V_494 :
V_480 = V_478 ;
if ( V_480 -> V_495 && F_248 ( V_480 -> V_495 ) )
F_307 ( V_11 , 0 ) ;
}
return V_496 ;
}
static void F_311 ( struct V_10 * V_11 , unsigned long V_101 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_101 == V_493 )
F_312 ( V_9 ) ;
else if ( V_101 == V_492 )
F_313 ( V_9 ) ;
}
static bool F_314 ( const struct V_170 * V_168 )
{
return F_122 ( V_168 ) &
( V_386 | V_182 ) ;
}
static int F_307 ( struct V_10 * V_11 , int V_497 )
{
struct V_114 * V_114 = F_38 ( V_11 ) ;
struct V_8 * V_9 ;
struct V_13 * V_149 , * V_5 ;
struct V_166 V_498 ;
int V_499 ;
bool V_500 ;
int V_163 , V_20 ;
F_33 () ;
F_315 ( V_114 , V_11 ) ;
F_316 ( & V_52 , V_11 ) ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_184 ;
if ( V_497 ) {
V_9 -> V_84 = 1 ;
F_317 ( V_11 -> V_79 , NULL ) ;
F_52 ( V_9 ) ;
}
V_499 = V_114 -> V_22 . V_128 -> V_501 ;
if ( ! V_499 )
V_499 = V_9 -> V_43 . V_501 ;
V_500 = ! ( V_497 || V_499 <= 0 || V_9 -> V_43 . V_186 ) ;
for ( V_20 = 0 ; V_20 < V_502 ; V_20 ++ ) {
struct V_139 * V_135 = & V_197 [ V_20 ] ;
F_149 ( & V_188 ) ;
V_503:
F_86 (ifa, h, addr_lst) {
if ( V_149 -> V_9 == V_9 ) {
F_13 ( V_149 ) ;
if ( ! V_500 ||
! ( V_149 -> V_58 & V_206 ) ||
F_314 ( & V_149 -> V_168 ) ) {
F_151 ( & V_149 -> V_162 ) ;
goto V_503;
}
}
}
F_150 ( & V_188 ) ;
}
F_152 ( & V_9 -> V_40 ) ;
F_10 ( V_9 ) ;
if ( ! V_497 )
V_9 -> V_76 &= ~ ( V_504 | V_505 | V_77 ) ;
while ( ! F_250 ( & V_9 -> V_67 ) ) {
V_149 = F_318 ( & V_9 -> V_67 ,
struct V_13 , V_199 ) ;
F_153 ( & V_149 -> V_199 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_149 ( & V_149 -> V_40 ) ;
if ( V_149 -> V_215 ) {
F_23 ( V_149 -> V_215 ) ;
V_149 -> V_215 = NULL ;
}
F_150 ( & V_149 -> V_40 ) ;
F_23 ( V_149 ) ;
F_152 ( & V_9 -> V_40 ) ;
}
V_500 = ( ! V_497 && V_499 > 0 && ! V_9 -> V_43 . V_186 ) ;
F_36 ( & V_498 ) ;
F_303 (ifa, tmp, &idev->addr_list, if_list) {
struct V_177 * V_6 = NULL ;
bool V_506 ;
F_13 ( V_149 ) ;
V_506 = V_500 && ( V_149 -> V_58 & V_206 ) &&
! F_314 ( & V_149 -> V_168 ) ;
if ( ! V_506 )
F_319 ( & V_149 -> V_169 , & V_498 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_149 ( & V_149 -> V_40 ) ;
if ( V_506 ) {
V_163 = V_164 ;
V_149 -> V_163 = V_314 ;
if ( ! ( V_149 -> V_58 & V_195 ) )
V_149 -> V_58 |= V_152 ;
V_6 = V_149 -> V_6 ;
V_149 -> V_6 = NULL ;
} else {
V_163 = V_149 -> V_163 ;
V_149 -> V_163 = V_164 ;
}
F_150 ( & V_149 -> V_40 ) ;
if ( V_6 )
F_146 ( V_6 ) ;
if ( V_163 != V_164 ) {
F_320 ( V_216 , V_149 ) ;
F_139 ( V_217 , V_149 ) ;
} else {
if ( V_9 -> V_43 . V_53 )
F_94 ( V_149 ) ;
F_210 ( V_149 -> V_9 , & V_149 -> V_168 ) ;
}
F_152 ( & V_9 -> V_40 ) ;
}
F_155 ( & V_9 -> V_40 ) ;
while ( ! F_250 ( & V_498 ) ) {
V_149 = F_318 ( & V_498 ,
struct V_13 , V_169 ) ;
F_153 ( & V_149 -> V_169 ) ;
F_23 ( V_149 ) ;
}
if ( V_497 ) {
F_321 ( V_9 ) ;
F_51 ( V_9 ) ;
} else {
F_322 ( V_9 ) ;
}
V_9 -> V_78 = V_17 ;
if ( V_497 ) {
F_7 ( V_9 ) ;
F_43 ( & V_52 , V_9 -> V_51 ) ;
F_316 ( & V_52 , V_11 ) ;
F_108 ( V_9 ) ;
}
return 0 ;
}
static void V_42 ( unsigned long V_468 )
{
struct V_8 * V_9 = (struct V_8 * ) V_468 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_170 V_507 ;
F_134 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_84 || ! ( V_9 -> V_76 & V_77 ) )
goto V_110;
if ( ! F_323 ( V_9 ) )
goto V_110;
if ( V_9 -> V_76 & V_505 )
goto V_110;
if ( V_9 -> V_508 ++ < V_9 -> V_43 . V_66 || V_9 -> V_43 . V_66 < 0 ) {
F_136 ( & V_9 -> V_40 ) ;
if ( ! F_193 ( V_11 , & V_507 , V_152 ) )
F_324 ( V_11 , & V_507 ,
& V_83 ) ;
else
goto V_396;
F_134 ( & V_9 -> V_40 ) ;
V_9 -> V_509 = F_5 (
V_9 -> V_509 , V_9 -> V_43 . V_510 ) ;
F_16 ( V_9 , ( V_9 -> V_508 ==
V_9 -> V_43 . V_66 ) ?
V_9 -> V_43 . V_511 :
V_9 -> V_509 ) ;
} else {
F_107 ( L_24 , V_9 -> V_11 -> V_56 ) ;
}
V_110:
F_136 ( & V_9 -> V_40 ) ;
V_396:
F_108 ( V_9 ) ;
}
static void F_325 ( struct V_13 * V_14 )
{
unsigned long V_512 ;
struct V_8 * V_9 = V_14 -> V_9 ;
T_3 V_513 ;
if ( V_14 -> V_58 & V_242 )
V_512 = 0 ;
else
V_512 = F_3 () % ( V_9 -> V_43 . V_511 ? : 1 ) ;
V_513 = 0 ;
if ( V_9 -> V_43 . V_514 ||
F_38 ( V_9 -> V_11 ) -> V_22 . V_128 -> V_514 ) {
do
F_164 ( & V_513 , 6 ) ;
while ( V_513 == 0 );
}
V_14 -> V_515 = V_513 ;
V_14 -> V_516 = V_9 -> V_43 . V_236 ;
F_20 ( V_14 , V_512 ) ;
}
static void F_326 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_517 , V_518 = false ;
F_208 ( V_11 , & V_14 -> V_168 ) ;
F_327 ( ( V_420 T_1 ) V_14 -> V_168 . V_412 [ 3 ] ) ;
F_180 ( & V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_163 == V_164 )
goto V_110;
if ( V_11 -> V_58 & ( V_59 | V_60 ) ||
V_9 -> V_43 . V_61 < 1 ||
! ( V_14 -> V_58 & V_152 ) ||
V_14 -> V_58 & V_195 ) {
V_517 = V_14 -> V_58 & V_152 ;
V_14 -> V_58 &= ~ ( V_152 | V_242 | V_299 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_185 ( & V_9 -> V_40 ) ;
F_328 ( V_14 , V_517 ) ;
return;
}
if ( ! ( V_9 -> V_76 & V_77 ) ) {
F_133 ( & V_14 -> V_40 ) ;
F_185 ( & V_9 -> V_40 ) ;
F_21 ( V_14 ) ;
F_203 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_58 & V_242 ) {
F_289 ( V_14 -> V_6 ) ;
if ( F_168 ( V_9 ) ) {
V_518 = true ;
}
}
F_325 ( V_14 ) ;
V_110:
F_133 ( & V_14 -> V_40 ) ;
F_185 ( & V_9 -> V_40 ) ;
if ( V_518 )
F_156 ( V_439 , V_14 ) ;
}
static void F_166 ( struct V_13 * V_14 )
{
bool V_519 = false ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_163 != V_164 ) {
V_14 -> V_163 = V_314 ;
V_519 = true ;
}
F_150 ( & V_14 -> V_40 ) ;
if ( V_519 )
F_20 ( V_14 , 0 ) ;
}
static void V_193 ( struct V_520 * V_521 )
{
struct V_13 * V_14 = F_329 ( F_330 ( V_521 ) ,
struct V_13 ,
V_15 ) ;
struct V_8 * V_9 = V_14 -> V_9 ;
bool V_517 , V_186 = false ;
struct V_170 V_522 ;
enum {
V_523 ,
V_524 ,
V_525 ,
} V_204 = V_523 ;
F_266 () ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_163 == V_314 ) {
V_204 = V_524 ;
V_14 -> V_163 = V_301 ;
} else if ( V_14 -> V_163 == V_316 ) {
V_204 = V_525 ;
V_14 -> V_163 = V_302 ;
if ( V_9 -> V_43 . V_61 > 1 && ! V_9 -> V_43 . V_186 &&
! ( V_14 -> V_58 & V_303 ) ) {
struct V_170 V_168 ;
V_168 . V_412 [ 0 ] = F_246 ( 0xfe800000 ) ;
V_168 . V_412 [ 1 ] = 0 ;
if ( ! F_235 ( V_168 . V_231 + 8 , V_9 -> V_11 ) &&
F_172 ( & V_14 -> V_168 , & V_168 ) ) {
V_9 -> V_43 . V_186 = 1 ;
F_47 ( L_25 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_186 = true ;
}
}
}
F_150 ( & V_14 -> V_40 ) ;
if ( V_204 == V_524 ) {
F_326 ( V_14 ) ;
goto V_110;
} else if ( V_204 == V_525 ) {
F_21 ( V_14 ) ;
F_203 ( V_14 , 1 ) ;
if ( V_186 )
F_307 ( V_9 -> V_11 , 0 ) ;
goto V_110;
}
if ( ! V_14 -> V_516 && F_204 ( V_14 ) )
goto V_110;
F_152 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_84 || ! ( V_9 -> V_76 & V_77 ) ) {
F_155 ( & V_9 -> V_40 ) ;
goto V_110;
}
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_163 == V_164 ) {
F_133 ( & V_14 -> V_40 ) ;
F_155 ( & V_9 -> V_40 ) ;
goto V_110;
}
if ( V_14 -> V_516 == 0 ) {
V_517 = V_14 -> V_58 & V_152 ;
V_14 -> V_58 &= ~ ( V_152 | V_242 | V_299 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_328 ( V_14 , V_517 ) ;
goto V_110;
}
V_14 -> V_516 -- ;
F_20 ( V_14 ,
F_160 ( V_14 -> V_9 -> V_51 , V_237 ) ) ;
F_133 ( & V_14 -> V_40 ) ;
F_155 ( & V_9 -> V_40 ) ;
F_209 ( & V_14 -> V_168 , & V_522 ) ;
F_331 ( V_14 -> V_9 -> V_11 , & V_14 -> V_168 , & V_522 , & V_75 ,
V_14 -> V_515 ) ;
V_110:
F_23 ( V_14 ) ;
F_100 () ;
}
static bool F_332 ( struct V_13 * V_14 )
{
struct V_13 * V_526 ;
struct V_8 * V_9 = V_14 -> V_9 ;
F_192 (ifpiter, &idev->addr_list, if_list) {
if ( V_526 -> V_174 > V_291 )
break;
if ( V_14 != V_526 && V_526 -> V_174 == V_291 &&
( V_526 -> V_58 & ( V_206 | V_152 |
V_242 | V_299 ) ) ==
V_206 )
return false ;
}
return true ;
}
static void F_328 ( struct V_13 * V_14 , bool V_517 )
{
struct V_10 * V_11 = V_14 -> V_9 -> V_11 ;
struct V_170 V_507 ;
bool V_527 , V_528 ;
F_13 ( V_14 ) ;
F_156 ( V_439 , V_14 ) ;
F_180 ( & V_14 -> V_9 -> V_40 ) ;
V_528 = V_14 -> V_174 == V_291 && F_332 ( V_14 ) ;
V_527 = V_528 &&
F_323 ( V_14 -> V_9 ) &&
V_14 -> V_9 -> V_43 . V_66 != 0 &&
( V_11 -> V_58 & V_60 ) == 0 ;
F_185 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_528 )
F_333 ( V_14 -> V_9 ) ;
if ( V_527 ) {
if ( F_193 ( V_11 , & V_507 , V_152 ) )
return;
F_324 ( V_11 , & V_507 , & V_83 ) ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
V_14 -> V_9 -> V_509 = F_2 (
V_14 -> V_9 -> V_43 . V_529 ) ;
V_14 -> V_9 -> V_508 = 1 ;
V_14 -> V_9 -> V_76 |= V_504 ;
F_16 ( V_14 -> V_9 , V_14 -> V_9 -> V_509 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
}
if ( V_517 )
F_285 ( F_38 ( V_11 ) ) ;
if ( V_14 -> V_58 & V_198 )
F_278 () ;
}
static void F_309 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list) {
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_58 & V_152 &&
V_14 -> V_163 == V_301 )
F_325 ( V_14 ) ;
F_133 ( & V_14 -> V_40 ) ;
}
F_185 ( & V_9 -> V_40 ) ;
}
static struct V_13 * F_334 ( struct V_530 * V_100 , T_10 V_531 )
{
struct V_13 * V_149 = NULL ;
struct V_532 * V_163 = V_100 -> V_533 ;
struct V_114 * V_114 = F_335 ( V_100 ) ;
int V_157 = 0 ;
if ( V_531 == 0 ) {
V_163 -> V_534 = 0 ;
V_163 -> V_535 = 0 ;
}
for (; V_163 -> V_534 < V_502 ; ++ V_163 -> V_534 ) {
F_202 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_197 ( F_38 ( V_149 -> V_9 -> V_11 ) , V_114 ) )
continue;
if ( V_157 < V_163 -> V_535 ) {
V_157 ++ ;
continue;
}
V_163 -> V_535 ++ ;
return V_149 ;
}
V_163 -> V_535 = 0 ;
V_157 = 0 ;
}
return NULL ;
}
static struct V_13 * F_336 ( struct V_530 * V_100 ,
struct V_13 * V_149 )
{
struct V_532 * V_163 = V_100 -> V_533 ;
struct V_114 * V_114 = F_335 ( V_100 ) ;
F_337 (ifa, addr_lst) {
if ( ! F_197 ( F_38 ( V_149 -> V_9 -> V_11 ) , V_114 ) )
continue;
V_163 -> V_535 ++ ;
return V_149 ;
}
while ( ++ V_163 -> V_534 < V_502 ) {
V_163 -> V_535 = 0 ;
F_202 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_197 ( F_38 ( V_149 -> V_9 -> V_11 ) , V_114 ) )
continue;
V_163 -> V_535 ++ ;
return V_149 ;
}
}
return NULL ;
}
static void * F_338 ( struct V_530 * V_100 , T_10 * V_531 )
__acquires( T_11 )
{
F_123 () ;
return F_334 ( V_100 , * V_531 ) ;
}
static void * F_339 ( struct V_530 * V_100 , void * V_536 , T_10 * V_531 )
{
struct V_13 * V_149 ;
V_149 = F_336 ( V_100 , V_536 ) ;
++ * V_531 ;
return V_149 ;
}
static void F_340 ( struct V_530 * V_100 , void * V_536 )
__releases( T_11 )
{
F_137 () ;
}
static int F_341 ( struct V_530 * V_100 , void * V_536 )
{
struct V_13 * V_14 = (struct V_13 * ) V_536 ;
F_342 ( V_100 , L_26 ,
& V_14 -> V_168 ,
V_14 -> V_9 -> V_11 -> V_96 ,
V_14 -> V_194 ,
V_14 -> V_174 ,
( T_5 ) V_14 -> V_58 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
return 0 ;
}
static int F_343 ( struct V_537 * V_537 , struct V_538 * V_538 )
{
return F_344 ( V_537 , V_538 , & V_539 ,
sizeof( struct V_532 ) ) ;
}
static int T_12 F_345 ( struct V_114 * V_114 )
{
if ( ! F_346 ( L_27 , V_540 , V_114 -> V_541 , & V_542 ) )
return - V_34 ;
return 0 ;
}
static void T_13 F_347 ( struct V_114 * V_114 )
{
F_348 ( L_27 , V_114 -> V_541 ) ;
}
int T_14 F_349 ( void )
{
return F_350 ( & V_543 ) ;
}
void F_351 ( void )
{
F_352 ( & V_543 ) ;
}
int F_353 ( struct V_114 * V_114 , const struct V_170 * V_168 )
{
int V_226 = 0 ;
struct V_13 * V_14 = NULL ;
unsigned int V_178 = F_118 ( V_168 ) ;
F_123 () ;
F_202 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_197 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_114 ) )
continue;
if ( F_172 ( & V_14 -> V_168 , V_168 ) &&
( V_14 -> V_58 & V_265 ) ) {
V_226 = 1 ;
break;
}
}
F_137 () ;
return V_226 ;
}
static void F_278 ( void )
{
unsigned long V_228 , V_544 , V_545 , V_546 ;
struct V_13 * V_14 ;
int V_20 ;
F_33 () ;
F_123 () ;
V_228 = V_17 ;
V_544 = F_354 ( V_228 + V_547 ) ;
F_14 ( & V_548 ) ;
for ( V_20 = 0 ; V_20 < V_502 ; V_20 ++ ) {
V_503:
F_202 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_223 ;
if ( ( V_14 -> V_58 & V_206 ) &&
( V_14 -> V_176 == V_438 ) )
continue;
F_124 ( & V_14 -> V_40 ) ;
V_223 = ( V_228 - V_14 -> V_78 + V_241 ) / V_3 ;
if ( V_14 -> V_175 != V_438 &&
V_223 >= V_14 -> V_175 ) {
F_133 ( & V_14 -> V_40 ) ;
F_21 ( V_14 ) ;
F_148 ( V_14 ) ;
goto V_503;
} else if ( V_14 -> V_176 == V_438 ) {
F_133 ( & V_14 -> V_40 ) ;
continue;
} else if ( V_223 >= V_14 -> V_176 ) {
int V_549 = 0 ;
if ( ! ( V_14 -> V_58 & V_260 ) ) {
V_549 = 1 ;
V_14 -> V_58 |= V_260 ;
}
if ( ( V_14 -> V_175 != V_438 ) &&
( F_143 ( V_14 -> V_78 + V_14 -> V_175 * V_3 , V_544 ) ) )
V_544 = V_14 -> V_78 + V_14 -> V_175 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
if ( V_549 ) {
F_21 ( V_14 ) ;
F_156 ( 0 , V_14 ) ;
F_23 ( V_14 ) ;
goto V_503;
}
} else if ( ( V_14 -> V_58 & V_198 ) &&
! ( V_14 -> V_58 & V_152 ) ) {
unsigned long V_224 = V_14 -> V_9 -> V_43 . V_234 *
V_14 -> V_9 -> V_43 . V_236 *
F_160 ( V_14 -> V_9 -> V_51 , V_237 ) / V_3 ;
if ( V_223 >= V_14 -> V_176 - V_224 ) {
struct V_13 * V_215 = V_14 -> V_215 ;
if ( F_143 ( V_14 -> V_78 + V_14 -> V_176 * V_3 , V_544 ) )
V_544 = V_14 -> V_78 + V_14 -> V_176 * V_3 ;
if ( ! V_14 -> V_233 && V_215 ) {
V_14 -> V_233 ++ ;
F_21 ( V_14 ) ;
F_21 ( V_215 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_124 ( & V_215 -> V_40 ) ;
V_215 -> V_233 = 0 ;
F_133 ( & V_215 -> V_40 ) ;
F_158 ( V_215 , V_14 ) ;
F_23 ( V_215 ) ;
F_23 ( V_14 ) ;
goto V_503;
}
} else if ( F_143 ( V_14 -> V_78 + V_14 -> V_176 * V_3 - V_224 * V_3 , V_544 ) )
V_544 = V_14 -> V_78 + V_14 -> V_176 * V_3 - V_224 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
} else {
if ( F_143 ( V_14 -> V_78 + V_14 -> V_176 * V_3 , V_544 ) )
V_544 = V_14 -> V_78 + V_14 -> V_176 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
}
}
}
V_545 = F_354 ( V_544 ) ;
V_546 = V_544 ;
if ( F_143 ( V_545 , V_544 + V_550 ) )
V_546 = V_545 ;
if ( F_143 ( V_546 , V_17 + V_551 ) )
V_546 = V_17 + V_551 ;
F_42 ( V_552 L_28 ,
V_228 , V_544 , V_545 , V_546 ) ;
F_22 ( V_19 , & V_548 , V_546 - V_228 ) ;
F_137 () ;
}
static void F_355 ( struct V_520 * V_521 )
{
F_266 () ;
F_278 () ;
F_100 () ;
}
static void F_255 ( void )
{
F_22 ( V_19 , & V_548 , 0 ) ;
}
static struct V_170 * F_356 ( struct V_122 * V_168 , struct V_122 * V_553 ,
struct V_170 * * V_428 )
{
struct V_170 * V_340 = NULL ;
* V_428 = NULL ;
if ( V_168 )
V_340 = F_357 ( V_168 ) ;
if ( V_553 ) {
if ( V_340 && F_358 ( V_553 , V_340 , sizeof( * V_340 ) ) )
* V_428 = V_340 ;
V_340 = F_357 ( V_553 ) ;
}
return V_340 ;
}
static int
F_359 ( struct V_94 * V_95 , struct V_102 * V_103 ,
struct V_119 * V_120 )
{
struct V_114 * V_114 = F_77 ( V_95 -> V_121 ) ;
struct V_554 * V_555 ;
struct V_122 * V_123 [ V_556 + 1 ] ;
struct V_170 * V_340 , * V_428 ;
T_1 V_429 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_555 ) , V_123 , V_556 , V_557 ,
V_120 ) ;
if ( V_36 < 0 )
return V_36 ;
V_555 = F_66 ( V_103 ) ;
V_340 = F_356 ( V_123 [ V_558 ] , V_123 [ V_559 ] , & V_428 ) ;
if ( ! V_340 )
return - V_39 ;
V_429 = V_123 [ V_560 ] ? F_360 ( V_123 [ V_560 ] ) : V_555 -> V_429 ;
V_429 &= V_380 ;
return F_279 ( V_114 , V_555 -> V_561 , V_429 , V_340 ,
V_555 -> V_562 ) ;
}
static int F_361 ( struct V_13 * V_14 , T_1 V_429 ,
T_1 V_176 , T_1 V_175 )
{
T_1 V_58 ;
T_7 V_202 ;
unsigned long V_430 ;
bool V_563 ;
bool V_564 ;
F_33 () ;
if ( ! V_175 || ( V_176 > V_175 ) )
return - V_39 ;
if ( V_429 & V_380 &&
( V_14 -> V_58 & V_198 || V_14 -> V_194 != 64 ) )
return - V_39 ;
V_430 = F_142 ( V_175 , V_3 ) ;
if ( F_260 ( V_430 ) ) {
V_202 = F_262 ( V_430 * V_3 ) ;
V_175 = V_430 ;
V_58 = V_214 ;
} else {
V_202 = 0 ;
V_58 = 0 ;
V_429 |= V_206 ;
}
V_430 = F_142 ( V_176 , V_3 ) ;
if ( F_260 ( V_430 ) ) {
if ( V_430 == 0 )
V_429 |= V_260 ;
V_176 = V_430 ;
}
F_149 ( & V_14 -> V_40 ) ;
V_563 = V_14 -> V_58 & V_380 ;
V_564 = V_14 -> V_58 & V_206 &&
! ( V_14 -> V_58 & V_207 ) ;
V_14 -> V_58 &= ~ ( V_260 | V_206 | V_195 |
V_265 | V_380 |
V_207 ) ;
V_14 -> V_58 |= V_429 ;
V_14 -> V_78 = V_17 ;
V_14 -> V_175 = V_175 ;
V_14 -> V_176 = V_176 ;
F_150 ( & V_14 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_152 ) )
F_156 ( 0 , V_14 ) ;
if ( ! ( V_429 & V_207 ) ) {
F_238 ( & V_14 -> V_168 , V_14 -> V_194 , V_14 -> V_9 -> V_11 ,
V_202 , V_58 ) ;
} else if ( V_564 ) {
enum V_201 V_204 ;
unsigned long V_389 ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
V_204 = F_140 ( V_14 , & V_389 ) ;
F_155 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_204 != V_208 ) {
F_144 ( V_14 , V_389 ,
V_204 == V_205 ) ;
}
}
if ( V_563 || V_14 -> V_58 & V_380 ) {
if ( V_563 && ! ( V_14 -> V_58 & V_380 ) )
V_175 = V_176 = 0 ;
F_249 ( V_14 -> V_9 , V_14 , V_175 , V_176 ,
! V_563 , V_17 ) ;
}
F_278 () ;
return 0 ;
}
static int
F_362 ( struct V_94 * V_95 , struct V_102 * V_103 ,
struct V_119 * V_120 )
{
struct V_114 * V_114 = F_77 ( V_95 -> V_121 ) ;
struct V_554 * V_555 ;
struct V_122 * V_123 [ V_556 + 1 ] ;
struct V_170 * V_340 , * V_428 ;
struct V_13 * V_149 ;
struct V_10 * V_11 ;
T_1 V_175 = V_438 , V_306 = V_438 ;
T_1 V_429 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_555 ) , V_123 , V_556 , V_557 ,
V_120 ) ;
if ( V_36 < 0 )
return V_36 ;
V_555 = F_66 ( V_103 ) ;
V_340 = F_356 ( V_123 [ V_558 ] , V_123 [ V_559 ] , & V_428 ) ;
if ( ! V_340 )
return - V_39 ;
if ( V_123 [ V_565 ] ) {
struct V_566 * V_567 ;
V_567 = F_357 ( V_123 [ V_565 ] ) ;
V_175 = V_567 -> V_568 ;
V_306 = V_567 -> V_569 ;
} else {
V_306 = V_438 ;
V_175 = V_438 ;
}
V_11 = F_80 ( V_114 , V_555 -> V_561 ) ;
if ( ! V_11 )
return - V_184 ;
V_429 = V_123 [ V_560 ] ? F_360 ( V_123 [ V_560 ] ) : V_555 -> V_429 ;
V_429 &= V_195 | V_265 | V_380 |
V_207 | V_431 ;
V_149 = F_201 ( V_114 , V_340 , V_11 , 1 ) ;
if ( ! V_149 ) {
return F_277 ( V_114 , V_555 -> V_561 , V_340 , V_428 ,
V_555 -> V_562 , V_429 ,
V_306 , V_175 ) ;
}
if ( V_103 -> V_570 & V_571 ||
! ( V_103 -> V_570 & V_572 ) )
V_36 = - V_189 ;
else
V_36 = F_361 ( V_149 , V_429 , V_306 , V_175 ) ;
F_23 ( V_149 ) ;
return V_36 ;
}
static void F_363 ( struct V_102 * V_103 , T_5 V_573 , T_1 V_58 ,
T_5 V_174 , int V_96 )
{
struct V_554 * V_555 ;
V_555 = F_66 ( V_103 ) ;
V_555 -> V_574 = V_107 ;
V_555 -> V_562 = V_573 ;
V_555 -> V_429 = V_58 ;
V_555 -> V_448 = V_174 ;
V_555 -> V_561 = V_96 ;
}
static int F_364 ( struct V_94 * V_95 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_575 , T_1 V_387 )
{
struct V_566 V_567 ;
V_567 . V_1 = F_1 ( V_1 ) ;
V_567 . V_78 = F_1 ( V_78 ) ;
V_567 . V_569 = V_575 ;
V_567 . V_568 = V_387 ;
return F_365 ( V_95 , V_565 , sizeof( V_567 ) , & V_567 ) ;
}
static inline int F_366 ( int V_448 )
{
if ( V_448 & V_295 )
return V_450 ;
else if ( V_448 & V_291 )
return V_449 ;
else if ( V_448 & V_576 )
return V_577 ;
else
return V_578 ;
}
static inline int F_367 ( void )
{
return F_61 ( sizeof( struct V_554 ) )
+ F_62 ( 16 )
+ F_62 ( 16 )
+ F_62 ( sizeof( struct V_566 ) )
+ F_62 ( 4 ) ;
}
static int F_368 ( struct V_94 * V_95 , struct V_13 * V_149 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_1 V_575 , V_387 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_554 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_363 ( V_103 , V_149 -> V_194 , V_149 -> V_58 , F_366 ( V_149 -> V_174 ) ,
V_149 -> V_9 -> V_11 -> V_96 ) ;
if ( ! ( ( V_149 -> V_58 & V_206 ) &&
( V_149 -> V_176 == V_438 ) ) ) {
V_575 = V_149 -> V_176 ;
V_387 = V_149 -> V_175 ;
if ( V_575 != V_438 ) {
long V_579 = ( V_17 - V_149 -> V_78 ) / V_3 ;
if ( V_575 > V_579 )
V_575 -= V_579 ;
else
V_575 = 0 ;
if ( V_387 != V_438 ) {
if ( V_387 > V_579 )
V_387 -= V_579 ;
else
V_387 = 0 ;
}
}
} else {
V_575 = V_438 ;
V_387 = V_438 ;
}
if ( ! F_213 ( & V_149 -> V_172 ) ) {
if ( F_369 ( V_95 , V_559 , & V_149 -> V_168 ) < 0 ||
F_369 ( V_95 , V_558 , & V_149 -> V_172 ) < 0 )
goto error;
} else
if ( F_369 ( V_95 , V_558 , & V_149 -> V_168 ) < 0 )
goto error;
if ( F_364 ( V_95 , V_149 -> V_1 , V_149 -> V_78 , V_575 , V_387 ) < 0 )
goto error;
if ( F_370 ( V_95 , V_560 , V_149 -> V_58 ) < 0 )
goto error;
F_68 ( V_95 , V_103 ) ;
return 0 ;
error:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_371 ( struct V_94 * V_95 , struct V_580 * V_581 ,
T_1 V_99 , T_1 V_100 , int V_101 , T_15 V_58 )
{
struct V_102 * V_103 ;
T_5 V_174 = V_578 ;
int V_96 = V_581 -> V_9 -> V_11 -> V_96 ;
if ( F_165 ( & V_581 -> V_582 ) & V_576 )
V_174 = V_577 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_554 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_363 ( V_103 , 128 , V_206 , V_174 , V_96 ) ;
if ( F_369 ( V_95 , V_583 , & V_581 -> V_582 ) < 0 ||
F_364 ( V_95 , V_581 -> V_584 , V_581 -> V_585 ,
V_438 , V_438 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_372 ( struct V_94 * V_95 , struct V_586 * V_587 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_5 V_174 = V_578 ;
int V_96 = V_587 -> V_588 -> V_11 -> V_96 ;
if ( F_165 ( & V_587 -> V_589 ) & V_576 )
V_174 = V_577 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_554 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_363 ( V_103 , 128 , V_206 , V_174 , V_96 ) ;
if ( F_369 ( V_95 , V_590 , & V_587 -> V_589 ) < 0 ||
F_364 ( V_95 , V_587 -> V_591 , V_587 -> V_592 ,
V_438 , V_438 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_373 ( struct V_8 * V_9 , struct V_94 * V_95 ,
struct V_133 * V_134 , enum V_593 type ,
int V_594 , int * V_595 )
{
struct V_580 * V_581 ;
struct V_586 * V_587 ;
int V_36 = 1 ;
int V_596 = * V_595 ;
F_180 ( & V_9 -> V_40 ) ;
switch ( type ) {
case V_597 : {
struct V_13 * V_149 ;
F_92 (ifa, &idev->addr_list, if_list) {
if ( ++ V_596 < V_594 )
continue;
V_36 = F_368 ( V_95 , V_149 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_439 ,
V_146 ) ;
if ( V_36 < 0 )
break;
F_88 ( V_134 , F_89 ( V_95 ) ) ;
}
break;
}
case V_598 :
for ( V_581 = V_9 -> V_599 ; V_581 ;
V_581 = V_581 -> V_544 , V_596 ++ ) {
if ( V_596 < V_594 )
continue;
V_36 = F_371 ( V_95 , V_581 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_600 ,
V_146 ) ;
if ( V_36 < 0 )
break;
}
break;
case V_601 :
for ( V_587 = V_9 -> V_602 ; V_587 ;
V_587 = V_587 -> V_603 , V_596 ++ ) {
if ( V_596 < V_594 )
continue;
V_36 = F_372 ( V_95 , V_587 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_604 ,
V_146 ) ;
if ( V_36 < 0 )
break;
}
break;
default:
break;
}
F_185 ( & V_9 -> V_40 ) ;
* V_595 = V_596 ;
return V_36 ;
}
static int F_374 ( struct V_94 * V_95 , struct V_133 * V_134 ,
enum V_593 type )
{
struct V_114 * V_114 = F_77 ( V_95 -> V_121 ) ;
int V_135 , V_136 ;
int V_137 , V_596 ;
int V_138 , V_594 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_139 * V_140 ;
V_136 = V_134 -> args [ 0 ] ;
V_138 = V_137 = V_134 -> args [ 1 ] ;
V_594 = V_596 = V_134 -> args [ 2 ] ;
F_84 () ;
V_134 -> V_100 = F_85 ( & V_114 -> V_22 . V_143 ) ^ V_114 -> V_144 ;
for ( V_135 = V_136 ; V_135 < V_141 ; V_135 ++ , V_138 = 0 ) {
V_137 = 0 ;
V_140 = & V_114 -> V_142 [ V_135 ] ;
F_86 (dev, head, index_hlist) {
if ( V_137 < V_138 )
goto V_145;
if ( V_135 > V_136 || V_137 > V_138 )
V_594 = 0 ;
V_596 = 0 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_145;
if ( F_373 ( V_9 , V_95 , V_134 , type ,
V_594 , & V_596 ) < 0 )
goto V_147;
V_145:
V_137 ++ ;
}
}
V_147:
F_87 () ;
V_134 -> args [ 0 ] = V_135 ;
V_134 -> args [ 1 ] = V_137 ;
V_134 -> args [ 2 ] = V_596 ;
return V_95 -> V_148 ;
}
static int F_375 ( struct V_94 * V_95 , struct V_133 * V_134 )
{
enum V_593 type = V_597 ;
return F_374 ( V_95 , V_134 , type ) ;
}
static int F_376 ( struct V_94 * V_95 , struct V_133 * V_134 )
{
enum V_593 type = V_598 ;
return F_374 ( V_95 , V_134 , type ) ;
}
static int F_377 ( struct V_94 * V_95 , struct V_133 * V_134 )
{
enum V_593 type = V_601 ;
return F_374 ( V_95 , V_134 , type ) ;
}
static int F_378 ( struct V_94 * V_118 , struct V_102 * V_103 ,
struct V_119 * V_120 )
{
struct V_114 * V_114 = F_77 ( V_118 -> V_121 ) ;
struct V_554 * V_555 ;
struct V_122 * V_123 [ V_556 + 1 ] ;
struct V_170 * V_168 = NULL , * V_605 ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_149 ;
struct V_94 * V_95 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_555 ) , V_123 , V_556 , V_557 ,
V_120 ) ;
if ( V_36 < 0 )
goto V_116;
V_168 = F_356 ( V_123 [ V_558 ] , V_123 [ V_559 ] , & V_605 ) ;
if ( ! V_168 ) {
V_36 = - V_39 ;
goto V_116;
}
V_555 = F_66 ( V_103 ) ;
if ( V_555 -> V_561 )
V_11 = F_80 ( V_114 , V_555 -> V_561 ) ;
V_149 = F_201 ( V_114 , V_168 , V_11 , 1 ) ;
if ( ! V_149 ) {
V_36 = - V_183 ;
goto V_116;
}
V_95 = F_71 ( F_367 () , V_29 ) ;
if ( ! V_95 ) {
V_36 = - V_115 ;
goto V_606;
}
V_36 = F_368 ( V_95 , V_149 , F_81 ( V_118 ) . V_99 ,
V_103 -> V_131 , V_439 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_606;
}
V_36 = F_82 ( V_95 , V_114 , F_81 ( V_118 ) . V_99 ) ;
V_606:
F_23 ( V_149 ) ;
V_116:
return V_36 ;
}
static void F_379 ( int V_101 , struct V_13 * V_149 )
{
struct V_94 * V_95 ;
struct V_114 * V_114 = F_38 ( V_149 -> V_9 -> V_11 ) ;
int V_36 = - V_115 ;
if ( V_149 -> V_58 & V_152 && V_101 == V_216 )
return;
V_95 = F_71 ( F_367 () , V_130 ) ;
if ( ! V_95 )
goto V_116;
V_36 = F_368 ( V_95 , V_149 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_116;
}
F_74 ( V_95 , V_114 , 0 , V_607 , NULL , V_130 ) ;
return;
V_116:
if ( V_36 < 0 )
F_75 ( V_114 , V_607 , V_36 ) ;
}
static inline void F_380 ( struct V_97 * V_43 ,
T_4 * V_608 , int V_609 )
{
F_381 ( V_609 < ( V_610 * 4 ) ) ;
memset ( V_608 , 0 , V_609 ) ;
V_608 [ V_611 ] = V_43 -> V_53 ;
V_608 [ V_612 ] = V_43 -> V_613 ;
V_608 [ V_614 ] = V_43 -> V_50 ;
V_608 [ V_615 ] = V_43 -> V_616 ;
V_608 [ V_617 ] = V_43 -> V_618 ;
V_608 [ V_619 ] = V_43 -> V_393 ;
V_608 [ V_620 ] = V_43 -> V_236 ;
V_608 [ V_621 ] = V_43 -> V_66 ;
V_608 [ V_622 ] =
F_382 ( V_43 -> V_529 ) ;
V_608 [ V_623 ] =
F_382 ( V_43 -> V_510 ) ;
V_608 [ V_624 ] =
F_382 ( V_43 -> V_511 ) ;
V_608 [ V_625 ] = V_43 -> V_626 ;
V_608 [ V_627 ] =
F_382 ( V_43 -> V_628 ) ;
V_608 [ V_629 ] =
F_382 ( V_43 -> V_630 ) ;
V_608 [ V_631 ] = V_43 -> V_73 ;
V_608 [ V_632 ] = V_43 -> V_240 ;
V_608 [ V_633 ] = V_43 -> V_238 ;
V_608 [ V_634 ] = V_43 -> V_234 ;
V_608 [ V_635 ] = V_43 -> V_229 ;
V_608 [ V_636 ] = V_43 -> V_312 ;
V_608 [ V_637 ] = V_43 -> V_638 ;
V_608 [ V_639 ] = V_43 -> V_640 ;
V_608 [ V_641 ] = V_43 -> V_642 ;
#ifdef F_383
V_608 [ V_643 ] = V_43 -> V_644 ;
V_608 [ V_645 ] =
F_382 ( V_43 -> V_646 ) ;
#ifdef F_384
V_608 [ V_647 ] = V_43 -> V_648 ;
V_608 [ V_649 ] = V_43 -> V_650 ;
#endif
#endif
V_608 [ V_651 ] = V_43 -> V_112 ;
V_608 [ V_652 ] = V_43 -> V_653 ;
#ifdef F_169
V_608 [ V_654 ] = V_43 -> V_245 ;
V_608 [ V_655 ] = V_43 -> V_246 ;
#endif
#ifdef F_63
V_608 [ V_656 ] = V_43 -> V_111 ;
#endif
V_608 [ V_657 ] = V_43 -> V_186 ;
V_608 [ V_658 ] = V_43 -> V_61 ;
V_608 [ V_659 ] = V_43 -> V_660 ;
V_608 [ V_661 ] = V_43 -> V_662 ;
V_608 [ V_663 ] = V_43 -> V_664 ;
V_608 [ V_665 ] = V_43 -> V_666 ;
V_608 [ V_667 ] = V_43 -> V_668 ;
V_608 [ V_669 ] = V_43 -> V_113 ;
V_608 [ V_670 ] = V_43 -> V_288 ;
V_608 [ V_671 ] = V_43 -> V_672 ;
V_608 [ V_673 ] = V_43 -> V_674 ;
V_608 [ V_675 ] = V_43 -> V_501 ;
V_608 [ V_676 ] = V_43 -> V_677 ;
#ifdef F_385
V_608 [ V_678 ] = V_43 -> V_679 ;
#endif
V_608 [ V_680 ] = V_43 -> V_514 ;
V_608 [ V_681 ] = V_43 -> V_47 ;
V_608 [ V_682 ] = V_43 -> V_190 ;
}
static inline T_16 F_386 ( void )
{
return F_62 ( 4 )
+ F_62 ( sizeof( struct V_683 ) )
+ F_62 ( V_610 * 4 )
+ F_62 ( V_684 * 8 )
+ F_62 ( V_685 * 8 )
+ F_62 ( sizeof( struct V_170 ) ) ;
}
static inline T_16 F_387 ( void )
{
return F_61 ( sizeof( struct V_686 ) )
+ F_62 ( V_687 )
+ F_62 ( V_466 )
+ F_62 ( 4 )
+ F_62 ( 4 )
+ F_62 ( 1 )
+ F_62 ( F_386 () ) ;
}
static inline void F_388 ( T_3 * V_21 , T_17 * V_688 ,
int V_609 )
{
int V_20 ;
int V_689 = V_609 - sizeof( T_3 ) * V_685 ;
F_381 ( V_689 < 0 ) ;
F_389 ( V_685 , & V_21 [ 0 ] ) ;
for ( V_20 = 1 ; V_20 < V_685 ; V_20 ++ )
F_389 ( F_390 ( & V_688 [ V_20 ] ) , & V_21 [ V_20 ] ) ;
memset ( & V_21 [ V_685 ] , 0 , V_689 ) ;
}
static inline void F_391 ( T_3 * V_21 , void T_18 * V_688 ,
int V_609 , T_16 V_690 )
{
int V_20 , V_691 ;
T_3 V_692 [ V_684 ] ;
int V_689 = V_609 - sizeof( T_3 ) * V_684 ;
F_381 ( V_689 < 0 ) ;
memset ( V_692 , 0 , sizeof( V_692 ) ) ;
V_692 [ 0 ] = V_684 ;
F_26 (c) {
for ( V_20 = 1 ; V_20 < V_684 ; V_20 ++ )
V_692 [ V_20 ] += F_392 ( V_688 , V_691 , V_20 , V_690 ) ;
}
memcpy ( V_21 , V_692 , V_684 * sizeof( T_3 ) ) ;
memset ( & V_21 [ V_684 ] , 0 , V_689 ) ;
}
static void F_393 ( T_3 * V_21 , struct V_8 * V_9 , int V_693 ,
int V_609 )
{
switch ( V_693 ) {
case V_694 :
F_391 ( V_21 , V_9 -> V_21 . V_22 , V_609 ,
F_394 ( struct V_23 , V_26 ) ) ;
break;
case V_695 :
F_388 ( V_21 , V_9 -> V_21 . V_27 -> V_696 , V_609 ) ;
break;
}
}
static int F_395 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_697 )
{
struct V_122 * V_698 ;
struct V_683 V_567 ;
if ( F_370 ( V_95 , V_699 , V_9 -> V_76 ) )
goto V_109;
V_567 . V_700 = V_701 ;
V_567 . V_78 = F_1 ( V_9 -> V_78 ) ;
V_567 . V_702 = F_382 ( V_9 -> V_51 -> V_702 ) ;
V_567 . V_703 = F_382 ( F_160 ( V_9 -> V_51 , V_237 ) ) ;
if ( F_365 ( V_95 , V_704 , sizeof( V_567 ) , & V_567 ) )
goto V_109;
V_698 = F_396 ( V_95 , V_705 , V_610 * sizeof( T_2 ) ) ;
if ( ! V_698 )
goto V_109;
F_380 ( & V_9 -> V_43 , F_357 ( V_698 ) , F_397 ( V_698 ) ) ;
if ( V_697 & V_706 )
return 0 ;
V_698 = F_396 ( V_95 , V_694 , V_684 * sizeof( T_3 ) ) ;
if ( ! V_698 )
goto V_109;
F_393 ( F_357 ( V_698 ) , V_9 , V_694 , F_397 ( V_698 ) ) ;
V_698 = F_396 ( V_95 , V_695 , V_685 * sizeof( T_3 ) ) ;
if ( ! V_698 )
goto V_109;
F_393 ( F_357 ( V_698 ) , V_9 , V_695 , F_397 ( V_698 ) ) ;
V_698 = F_396 ( V_95 , V_707 , sizeof( struct V_170 ) ) ;
if ( ! V_698 )
goto V_109;
if ( F_398 ( V_95 , V_708 , V_9 -> V_43 . V_47 ) )
goto V_109;
F_180 ( & V_9 -> V_40 ) ;
memcpy ( F_357 ( V_698 ) , V_9 -> V_74 . V_231 , F_397 ( V_698 ) ) ;
F_185 ( & V_9 -> V_40 ) ;
return 0 ;
V_109:
return - V_105 ;
}
static T_16 F_399 ( const struct V_10 * V_11 ,
T_1 V_697 )
{
if ( ! F_57 ( V_11 ) )
return 0 ;
return F_386 () ;
}
static int F_400 ( struct V_94 * V_95 , const struct V_10 * V_11 ,
T_1 V_697 )
{
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_709 ;
if ( F_395 ( V_95 , V_9 , V_697 ) < 0 )
return - V_105 ;
return 0 ;
}
static int F_401 ( struct V_8 * V_9 , struct V_170 * V_74 )
{
struct V_13 * V_14 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_710 , V_711 = false ;
struct V_170 V_712 ;
F_33 () ;
if ( ! V_74 )
return - V_39 ;
if ( V_11 -> V_58 & ( V_60 | V_59 ) )
return - V_39 ;
if ( ! F_323 ( V_9 ) )
return - V_39 ;
if ( V_9 -> V_43 . V_66 == 0 )
return - V_39 ;
F_152 ( & V_9 -> V_40 ) ;
F_293 ( sizeof( V_74 -> V_231 ) != 16 ) ;
memcpy ( V_9 -> V_74 . V_231 + 8 , V_74 -> V_231 + 8 , 8 ) ;
F_155 ( & V_9 -> V_40 ) ;
V_710 = F_213 ( V_74 ) ;
if ( V_710 )
goto V_378;
if ( ! V_9 -> V_84 && ( V_9 -> V_76 & V_77 ) &&
! F_193 ( V_11 , & V_712 , V_152 |
V_242 ) ) {
F_324 ( V_11 , & V_712 , & V_83 ) ;
V_711 = true ;
}
V_378:
F_152 ( & V_9 -> V_40 ) ;
if ( V_711 ) {
V_9 -> V_76 |= V_504 ;
V_9 -> V_509 = F_2 (
V_9 -> V_43 . V_529 ) ;
V_9 -> V_508 = 1 ;
F_16 ( V_9 , V_9 -> V_509 ) ;
}
F_92 (ifp, &idev->addr_list, if_list) {
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_196 ) {
V_14 -> V_175 = 0 ;
V_14 -> V_176 = 0 ;
}
F_133 ( & V_14 -> V_40 ) ;
}
F_155 ( & V_9 -> V_40 ) ;
F_310 ( V_489 , V_9 ) ;
F_278 () ;
return 0 ;
}
static int F_402 ( const struct V_10 * V_11 ,
const struct V_122 * V_698 )
{
struct V_122 * V_123 [ V_713 + 1 ] ;
if ( V_11 && ! F_57 ( V_11 ) )
return - V_714 ;
return F_403 ( V_123 , V_713 , V_698 , V_715 ,
NULL ) ;
}
static int F_404 ( int V_716 )
{
if ( V_716 != V_473 &&
V_716 != V_474 &&
V_716 != V_48 &&
V_716 != V_374 )
return - V_39 ;
return 1 ;
}
static int F_405 ( struct V_8 * V_9 , struct V_114 * V_114 ,
int V_716 )
{
if ( V_716 == V_48 &&
! V_9 -> V_43 . V_45 . V_46 &&
! V_114 -> V_22 . V_44 -> V_45 . V_46 )
return - V_39 ;
return 1 ;
}
static int F_406 ( struct V_10 * V_11 , const struct V_122 * V_698 )
{
int V_36 = - V_39 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
struct V_122 * V_123 [ V_713 + 1 ] ;
if ( ! V_9 )
return - V_714 ;
if ( F_403 ( V_123 , V_713 , V_698 , NULL , NULL ) < 0 )
F_407 () ;
if ( V_123 [ V_707 ] ) {
V_36 = F_401 ( V_9 , F_357 ( V_123 [ V_707 ] ) ) ;
if ( V_36 )
return V_36 ;
}
if ( V_123 [ V_708 ] ) {
T_5 V_716 = F_408 ( V_123 [ V_708 ] ) ;
if ( F_404 ( V_716 ) < 0 ||
F_405 ( V_9 , F_38 ( V_11 ) , V_716 ) < 0 )
return - V_39 ;
V_9 -> V_43 . V_47 = V_716 ;
V_36 = 0 ;
}
return V_36 ;
}
static int F_409 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_686 * V_717 ;
struct V_102 * V_103 ;
void * V_718 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_717 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_717 = F_66 ( V_103 ) ;
V_717 -> V_719 = V_107 ;
V_717 -> V_720 = 0 ;
V_717 -> V_721 = V_11 -> type ;
V_717 -> V_722 = V_11 -> V_96 ;
V_717 -> V_723 = F_410 ( V_11 ) ;
V_717 -> V_724 = 0 ;
if ( F_411 ( V_95 , V_725 , V_11 -> V_56 ) ||
( V_11 -> V_319 &&
F_365 ( V_95 , V_726 , V_11 -> V_319 , V_11 -> V_321 ) ) ||
F_370 ( V_95 , V_727 , V_11 -> V_37 ) ||
( V_11 -> V_96 != F_412 ( V_11 ) &&
F_370 ( V_95 , V_728 , F_412 ( V_11 ) ) ) ||
F_398 ( V_95 , V_729 ,
F_49 ( V_11 ) ? V_11 -> V_730 : V_731 ) )
goto V_109;
V_718 = F_413 ( V_95 , V_732 ) ;
if ( ! V_718 )
goto V_109;
if ( F_395 ( V_95 , V_9 , 0 ) < 0 )
goto V_109;
F_414 ( V_95 , V_718 ) ;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_415 ( struct V_94 * V_95 , struct V_133 * V_134 )
{
struct V_114 * V_114 = F_77 ( V_95 -> V_121 ) ;
int V_135 , V_136 ;
int V_137 = 0 , V_138 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_139 * V_140 ;
V_136 = V_134 -> args [ 0 ] ;
V_138 = V_134 -> args [ 1 ] ;
F_84 () ;
for ( V_135 = V_136 ; V_135 < V_141 ; V_135 ++ , V_138 = 0 ) {
V_137 = 0 ;
V_140 = & V_114 -> V_142 [ V_135 ] ;
F_86 (dev, head, index_hlist) {
if ( V_137 < V_138 )
goto V_145;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_145;
if ( F_409 ( V_95 , V_9 ,
F_81 ( V_134 -> V_95 ) . V_99 ,
V_134 -> V_103 -> V_131 ,
V_489 , V_146 ) < 0 )
goto V_110;
V_145:
V_137 ++ ;
}
}
V_110:
F_87 () ;
V_134 -> args [ 1 ] = V_137 ;
V_134 -> args [ 0 ] = V_135 ;
return V_95 -> V_148 ;
}
void F_310 ( int V_101 , struct V_8 * V_9 )
{
struct V_94 * V_95 ;
struct V_114 * V_114 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_115 ;
V_95 = F_71 ( F_387 () , V_130 ) ;
if ( ! V_95 )
goto V_116;
V_36 = F_409 ( V_95 , V_9 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_116;
}
F_74 ( V_95 , V_114 , 0 , V_733 , NULL , V_130 ) ;
return;
V_116:
if ( V_36 < 0 )
F_75 ( V_114 , V_733 , V_36 ) ;
}
static inline T_16 F_416 ( void )
{
return F_61 ( sizeof( struct V_734 ) )
+ F_62 ( sizeof( struct V_170 ) )
+ F_62 ( sizeof( struct V_735 ) ) ;
}
static int F_417 ( struct V_94 * V_95 , struct V_8 * V_9 ,
struct V_375 * V_376 , T_1 V_99 , T_1 V_100 ,
int V_101 , unsigned int V_58 )
{
struct V_734 * V_736 ;
struct V_102 * V_103 ;
struct V_735 V_567 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_736 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_736 = F_66 ( V_103 ) ;
V_736 -> V_737 = V_107 ;
V_736 -> V_738 = 0 ;
V_736 -> V_739 = 0 ;
V_736 -> V_740 = V_9 -> V_11 -> V_96 ;
V_736 -> V_194 = V_376 -> V_194 ;
V_736 -> V_741 = V_376 -> type ;
V_736 -> V_742 = 0 ;
V_736 -> V_743 = 0 ;
if ( V_376 -> V_296 )
V_736 -> V_743 |= V_744 ;
if ( V_376 -> V_393 )
V_736 -> V_743 |= V_745 ;
if ( F_365 ( V_95 , V_746 , sizeof( V_376 -> V_385 ) , & V_376 -> V_385 ) )
goto V_109;
V_567 . V_747 = F_257 ( V_376 -> V_388 ) ;
V_567 . V_748 = F_257 ( V_376 -> V_387 ) ;
if ( F_365 ( V_95 , V_749 , sizeof( V_567 ) , & V_567 ) )
goto V_109;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static void F_264 ( int V_101 , struct V_8 * V_9 ,
struct V_375 * V_376 )
{
struct V_94 * V_95 ;
struct V_114 * V_114 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_115 ;
V_95 = F_71 ( F_416 () , V_130 ) ;
if ( ! V_95 )
goto V_116;
V_36 = F_417 ( V_95 , V_9 , V_376 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_116;
}
F_74 ( V_95 , V_114 , 0 , V_750 , NULL , V_130 ) ;
return;
V_116:
if ( V_36 < 0 )
F_75 ( V_114 , V_750 , V_36 ) ;
}
static void F_320 ( int V_101 , struct V_13 * V_14 )
{
struct V_114 * V_114 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( V_101 )
F_33 () ;
F_379 ( V_101 ? : V_439 , V_14 ) ;
switch ( V_101 ) {
case V_439 :
if ( ! ( V_14 -> V_6 -> V_751 ) )
F_289 ( V_14 -> V_6 ) ;
if ( V_14 -> V_9 -> V_43 . V_53 )
F_93 ( V_14 ) ;
if ( ! F_213 ( & V_14 -> V_172 ) )
F_238 ( & V_14 -> V_172 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
break;
case V_216 :
if ( V_14 -> V_9 -> V_43 . V_53 )
F_94 ( V_14 ) ;
F_210 ( V_14 -> V_9 , & V_14 -> V_168 ) ;
if ( ! F_213 ( & V_14 -> V_172 ) ) {
struct V_177 * V_6 ;
V_6 = F_145 ( & V_14 -> V_172 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
if ( V_6 )
F_146 ( V_6 ) ;
}
if ( V_14 -> V_6 ) {
F_243 ( & V_14 -> V_6 -> V_191 ) ;
F_146 ( V_14 -> V_6 ) ;
}
F_285 ( V_114 ) ;
break;
}
F_418 ( & V_114 -> V_22 . V_143 ) ;
}
static void F_156 ( int V_101 , struct V_13 * V_14 )
{
F_123 () ;
if ( F_138 ( V_14 -> V_9 -> V_84 == 0 ) )
F_320 ( V_101 , V_14 ) ;
F_137 () ;
}
static
int F_419 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 , T_10 * V_756 )
{
int * V_757 = V_752 -> V_468 ;
int V_758 = * V_757 ;
T_10 V_531 = * V_756 ;
struct V_155 V_759 ;
int V_226 ;
V_759 = * V_752 ;
V_759 . V_468 = & V_758 ;
V_226 = F_420 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_753 )
V_226 = F_97 ( V_752 , V_757 , V_758 ) ;
if ( V_226 )
* V_756 = V_531 ;
return V_226 ;
}
static
int F_421 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 , T_10 * V_756 )
{
struct V_8 * V_9 = V_752 -> V_161 ;
int V_760 = V_38 ;
struct V_155 V_759 ;
V_759 = * V_752 ;
V_759 . V_161 = & V_760 ;
V_759 . V_159 = V_9 ? & V_9 -> V_11 -> V_37 : NULL ;
return F_422 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
}
static void F_423 ( struct V_8 * V_9 )
{
struct V_761 V_480 ;
if ( ! V_9 || ! V_9 -> V_11 )
return;
F_424 ( & V_480 , V_9 -> V_11 ) ;
if ( V_9 -> V_43 . V_186 )
F_304 ( NULL , V_217 , & V_480 ) ;
else
F_304 ( NULL , V_200 , & V_480 ) ;
}
static void F_425 ( struct V_114 * V_114 , T_4 V_153 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_154 = ( ! V_9 -> V_43 . V_186 ) ^ ( ! V_153 ) ;
V_9 -> V_43 . V_186 = V_153 ;
if ( V_154 )
F_423 ( V_9 ) ;
}
}
}
static int F_426 ( struct V_155 * V_156 , int * V_157 , int V_153 )
{
struct V_114 * V_114 ;
int V_158 ;
if ( ! F_98 () )
return F_99 () ;
V_114 = (struct V_114 * ) V_156 -> V_159 ;
V_158 = * V_157 ;
* V_157 = V_153 ;
if ( V_157 == & V_114 -> V_22 . V_44 -> V_186 ) {
F_100 () ;
return 0 ;
}
if ( V_157 == & V_114 -> V_22 . V_128 -> V_186 ) {
V_114 -> V_22 . V_44 -> V_186 = V_153 ;
F_425 ( V_114 , V_153 ) ;
} else if ( ( ! V_153 ) ^ ( ! V_158 ) )
F_423 ( (struct V_8 * ) V_156 -> V_161 ) ;
F_100 () ;
return 0 ;
}
static
int F_427 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 , T_10 * V_756 )
{
int * V_757 = V_752 -> V_468 ;
int V_758 = * V_757 ;
T_10 V_531 = * V_756 ;
struct V_155 V_759 ;
int V_226 ;
V_759 = * V_752 ;
V_759 . V_468 = & V_758 ;
V_226 = F_420 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_753 )
V_226 = F_426 ( V_752 , V_757 , V_758 ) ;
if ( V_226 )
* V_756 = V_531 ;
return V_226 ;
}
static
int F_428 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 , T_10 * V_756 )
{
int * V_757 = V_752 -> V_468 ;
int V_226 ;
int V_158 , V_762 ;
V_158 = * V_757 ;
V_226 = F_420 ( V_752 , V_753 , V_754 , V_755 , V_756 ) ;
V_762 = * V_757 ;
if ( V_753 && V_158 != V_762 ) {
struct V_114 * V_114 = V_752 -> V_159 ;
if ( ! F_98 () )
return F_99 () ;
if ( V_757 == & V_114 -> V_22 . V_44 -> V_112 )
F_70 ( V_114 , V_132 ,
V_92 ,
V_129 ,
V_114 -> V_22 . V_44 ) ;
else if ( V_757 == & V_114 -> V_22 . V_128 -> V_112 )
F_70 ( V_114 , V_132 ,
V_92 ,
V_127 ,
V_114 -> V_22 . V_128 ) ;
else {
struct V_8 * V_9 = V_752 -> V_161 ;
F_70 ( V_114 , V_132 ,
V_92 ,
V_9 -> V_11 -> V_96 ,
& V_9 -> V_43 ) ;
}
F_100 () ;
}
return V_226 ;
}
static int F_429 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 ,
T_10 * V_756 )
{
int V_226 = 0 ;
int V_763 ;
struct V_8 * V_9 = (struct V_8 * ) V_752 -> V_161 ;
struct V_114 * V_114 = (struct V_114 * ) V_752 -> V_159 ;
if ( ! F_98 () )
return F_99 () ;
V_226 = F_420 ( V_752 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_753 ) {
V_763 = * ( ( int * ) V_752 -> V_468 ) ;
if ( F_404 ( V_763 ) < 0 ) {
V_226 = - V_39 ;
goto V_110;
}
if ( & V_114 -> V_22 . V_44 -> V_47 == V_752 -> V_468 ) {
V_49 . V_47 = V_763 ;
} else {
if ( ! V_9 )
goto V_110;
if ( F_405 ( V_9 , V_114 , V_763 ) < 0 ) {
V_226 = - V_39 ;
goto V_110;
}
if ( V_9 -> V_43 . V_47 != V_763 ) {
V_9 -> V_43 . V_47 = V_763 ;
F_298 ( V_9 -> V_11 ) ;
}
}
}
V_110:
F_100 () ;
return V_226 ;
}
static int F_430 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 ,
T_10 * V_756 )
{
int V_36 ;
struct V_170 V_168 ;
char V_764 [ V_765 ] ;
struct V_155 V_759 = * V_752 ;
struct V_114 * V_114 = V_752 -> V_159 ;
struct V_470 * V_464 = V_752 -> V_468 ;
if ( & V_114 -> V_22 . V_128 -> V_45 == V_752 -> V_468 )
return - V_766 ;
V_759 . V_767 = V_765 ;
V_759 . V_468 = V_764 ;
if ( ! F_98 () )
return F_99 () ;
if ( ! V_753 && ! V_464 -> V_46 ) {
V_36 = - V_766 ;
goto V_110;
}
V_36 = snprintf ( V_764 , sizeof( V_764 ) , L_29 , & V_464 -> V_464 ) ;
if ( V_36 >= sizeof( V_764 ) ) {
V_36 = - V_766 ;
goto V_110;
}
V_36 = F_431 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_36 || ! V_753 )
goto V_110;
if ( F_432 ( V_764 , - 1 , V_168 . V_768 . V_769 , - 1 , NULL ) != 1 ) {
V_36 = - V_766 ;
goto V_110;
}
V_464 -> V_46 = true ;
V_464 -> V_464 = V_168 ;
if ( & V_114 -> V_22 . V_44 -> V_45 == V_752 -> V_468 ) {
struct V_10 * V_11 ;
F_96 (net, dev) {
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
V_9 -> V_43 . V_47 =
V_48 ;
}
}
} else {
struct V_8 * V_9 = V_752 -> V_161 ;
V_9 -> V_43 . V_47 = V_48 ;
}
V_110:
F_100 () ;
return V_36 ;
}
static
int F_433 ( struct V_155 * V_752 ,
int V_753 ,
void T_8 * V_754 ,
T_16 * V_755 ,
T_10 * V_756 )
{
int * V_757 = V_752 -> V_468 ;
int V_758 = * V_757 ;
T_10 V_531 = * V_756 ;
struct V_155 V_759 ;
int V_226 ;
V_759 = * V_752 ;
V_759 . V_468 = & V_758 ;
V_226 = F_420 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_753 )
V_226 = F_103 ( V_752 , V_757 , V_758 ) ;
if ( V_226 )
* V_756 = V_531 ;
return V_226 ;
}
static
void F_434 ( struct V_177 * V_6 , int V_204 )
{
if ( V_6 ) {
if ( V_204 )
V_6 -> V_191 . V_58 |= V_192 ;
else
V_6 -> V_191 . V_58 &= ~ V_192 ;
}
}
static
void F_435 ( struct V_8 * V_9 , int V_758 )
{
struct V_13 * V_149 ;
F_180 ( & V_9 -> V_40 ) ;
F_92 (ifa, &idev->addr_list, if_list) {
F_124 ( & V_149 -> V_40 ) ;
if ( V_149 -> V_6 ) {
struct V_177 * V_6 = V_149 -> V_6 ;
struct V_363 * V_156 = V_6 -> V_770 ;
int V_771 ;
F_436 ( & V_156 -> V_365 ) ;
F_434 ( V_149 -> V_6 , V_758 ) ;
if ( V_6 -> V_772 ) {
F_26 (cpu) {
struct V_177 * * V_773 ;
V_773 = F_27 ( V_6 -> V_772 , V_771 ) ;
F_434 ( * V_773 , V_758 ) ;
}
}
F_437 ( & V_156 -> V_365 ) ;
}
F_133 ( & V_149 -> V_40 ) ;
}
F_185 ( & V_9 -> V_40 ) ;
}
static
int F_438 ( struct V_155 * V_752 , int * V_757 , int V_758 )
{
struct V_8 * V_9 ;
struct V_114 * V_114 ;
if ( ! F_98 () )
return F_99 () ;
* V_757 = V_758 ;
V_114 = (struct V_114 * ) V_752 -> V_159 ;
if ( V_757 == & V_114 -> V_22 . V_44 -> V_190 ) {
F_100 () ;
return 0 ;
}
if ( V_757 == & V_114 -> V_22 . V_128 -> V_190 ) {
struct V_10 * V_11 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 )
F_435 ( V_9 , V_758 ) ;
}
} else {
V_9 = (struct V_8 * ) V_752 -> V_161 ;
F_435 ( V_9 , V_758 ) ;
}
F_100 () ;
return 0 ;
}
static
int F_439 ( struct V_155 * V_752 , int V_753 ,
void T_8 * V_754 , T_16 * V_755 ,
T_10 * V_756 )
{
int * V_757 = V_752 -> V_468 ;
int V_758 = * V_757 ;
T_10 V_531 = * V_756 ;
struct V_155 V_759 ;
int V_226 ;
V_759 = * V_752 ;
V_759 . V_468 = & V_758 ;
V_226 = F_420 ( & V_759 , V_753 , V_754 , V_755 , V_756 ) ;
if ( V_753 && ( * V_757 != V_758 ) )
V_226 = F_438 ( V_752 , V_757 , V_758 ) ;
if ( V_226 )
* V_756 = V_531 ;
return V_226 ;
}
static int F_440 ( struct V_114 * V_114 , char * V_774 ,
struct V_8 * V_9 , struct V_97 * V_157 )
{
int V_20 , V_96 ;
struct V_155 * V_156 ;
char V_775 [ sizeof( L_30 ) + V_687 ] ;
V_156 = F_441 ( V_776 , sizeof( V_776 ) , V_29 ) ;
if ( ! V_156 )
goto V_110;
for ( V_20 = 0 ; V_156 [ V_20 ] . V_468 ; V_20 ++ ) {
V_156 [ V_20 ] . V_468 += ( char * ) V_157 - ( char * ) & V_97 ;
if ( ! V_156 [ V_20 ] . V_161 && ! V_156 [ V_20 ] . V_159 ) {
V_156 [ V_20 ] . V_161 = V_9 ;
V_156 [ V_20 ] . V_159 = V_114 ;
}
}
snprintf ( V_775 , sizeof( V_775 ) , L_31 , V_774 ) ;
V_157 -> V_777 = F_442 ( V_114 , V_775 , V_156 ) ;
if ( ! V_157 -> V_777 )
goto free;
if ( ! strcmp ( V_774 , L_32 ) )
V_96 = V_127 ;
else if ( ! strcmp ( V_774 , L_33 ) )
V_96 = V_129 ;
else
V_96 = V_9 -> V_11 -> V_96 ;
F_70 ( V_114 , V_132 , V_89 ,
V_96 , V_157 ) ;
return 0 ;
free:
F_30 ( V_156 ) ;
V_110:
return - V_115 ;
}
static void F_443 ( struct V_114 * V_114 ,
struct V_97 * V_157 , int V_96 )
{
struct V_155 * V_156 ;
if ( ! V_157 -> V_777 )
return;
V_156 = V_157 -> V_777 -> V_778 ;
F_444 ( V_157 -> V_777 ) ;
V_157 -> V_777 = NULL ;
F_30 ( V_156 ) ;
F_70 ( V_114 , V_779 , 0 , V_96 , NULL ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
int V_36 ;
if ( ! F_445 ( V_9 -> V_11 -> V_56 ) )
return - V_39 ;
V_36 = F_446 ( V_9 -> V_11 , V_9 -> V_51 ,
& V_780 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_440 ( F_38 ( V_9 -> V_11 ) , V_9 -> V_11 -> V_56 ,
V_9 , & V_9 -> V_43 ) ;
if ( V_36 )
F_447 ( V_9 -> V_51 ) ;
return V_36 ;
}
static void F_7 ( struct V_8 * V_9 )
{
F_443 ( F_38 ( V_9 -> V_11 ) , & V_9 -> V_43 ,
V_9 -> V_11 -> V_96 ) ;
F_447 ( V_9 -> V_51 ) ;
}
static int T_12 F_448 ( struct V_114 * V_114 )
{
int V_36 = - V_34 ;
struct V_97 * V_88 , * V_781 ;
V_88 = F_441 ( & V_97 , sizeof( V_97 ) , V_29 ) ;
if ( ! V_88 )
goto V_782;
V_781 = F_441 ( & V_49 , sizeof( V_49 ) , V_29 ) ;
if ( ! V_781 )
goto V_783;
V_781 -> V_393 = V_784 . V_393 ;
V_781 -> V_186 = V_784 . V_186 ;
V_781 -> V_45 . V_46 = false ;
V_88 -> V_45 . V_46 = false ;
V_114 -> V_22 . V_128 = V_88 ;
V_114 -> V_22 . V_44 = V_781 ;
#ifdef F_449
V_36 = F_440 ( V_114 , L_32 , NULL , V_88 ) ;
if ( V_36 < 0 )
goto V_785;
V_36 = F_440 ( V_114 , L_33 , NULL , V_781 ) ;
if ( V_36 < 0 )
goto V_786;
#endif
return 0 ;
#ifdef F_449
V_786:
F_443 ( V_114 , V_88 , V_127 ) ;
V_785:
F_30 ( V_781 ) ;
#endif
V_783:
F_30 ( V_88 ) ;
V_782:
return V_36 ;
}
static void T_13 F_450 ( struct V_114 * V_114 )
{
#ifdef F_449
F_443 ( V_114 , V_114 -> V_22 . V_44 ,
V_129 ) ;
F_443 ( V_114 , V_114 -> V_22 . V_128 ,
V_127 ) ;
#endif
F_30 ( V_114 -> V_22 . V_44 ) ;
F_30 ( V_114 -> V_22 . V_128 ) ;
}
int T_14 F_451 ( void )
{
struct V_8 * V_9 ;
int V_20 , V_36 ;
V_36 = F_452 () ;
if ( V_36 < 0 ) {
F_453 ( L_34 ,
V_55 , V_36 ) ;
goto V_110;
}
V_36 = F_350 ( & V_787 ) ;
if ( V_36 < 0 )
goto V_788;
V_19 = F_454 ( L_35 ) ;
if ( ! V_19 ) {
V_36 = - V_34 ;
goto V_789;
}
F_266 () ;
V_9 = F_32 ( V_790 . V_484 ) ;
F_100 () ;
if ( F_58 ( V_9 ) ) {
V_36 = F_127 ( V_9 ) ;
goto V_791;
}
F_455 () ;
for ( V_20 = 0 ; V_20 < V_502 ; V_20 ++ )
F_456 ( & V_197 [ V_20 ] ) ;
F_457 ( & V_792 ) ;
F_255 () ;
F_458 ( & V_793 ) ;
V_36 = F_459 ( V_794 , V_795 , NULL , F_415 ,
NULL ) ;
if ( V_36 < 0 )
goto V_116;
F_459 ( V_794 , V_439 , F_362 , NULL , NULL ) ;
F_459 ( V_794 , V_216 , F_359 , NULL , NULL ) ;
F_459 ( V_794 , V_796 , F_378 ,
F_375 , NULL ) ;
F_459 ( V_794 , V_600 , NULL ,
F_376 , NULL ) ;
F_459 ( V_794 , V_604 , NULL ,
F_377 , NULL ) ;
F_459 ( V_794 , V_797 , F_76 ,
F_83 , NULL ) ;
F_460 () ;
return 0 ;
V_116:
F_461 ( & V_793 ) ;
F_462 ( & V_792 ) ;
V_791:
F_463 ( V_19 ) ;
V_789:
F_352 ( & V_787 ) ;
V_788:
F_464 () ;
V_110:
return V_36 ;
}
void F_465 ( void )
{
struct V_10 * V_11 ;
int V_20 ;
F_462 ( & V_792 ) ;
F_352 ( & V_787 ) ;
F_464 () ;
F_266 () ;
F_466 ( & V_793 ) ;
F_96 (&init_net, dev) {
if ( F_57 ( V_11 ) == NULL )
continue;
F_307 ( V_11 , 1 ) ;
}
F_307 ( V_790 . V_484 , 2 ) ;
F_149 ( & V_188 ) ;
for ( V_20 = 0 ; V_20 < V_502 ; V_20 ++ )
F_72 ( ! F_467 ( & V_197 [ V_20 ] ) ) ;
F_150 ( & V_188 ) ;
F_14 ( & V_548 ) ;
F_100 () ;
F_463 ( V_19 ) ;
}
