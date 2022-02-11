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
static void F_6 ( struct V_4 * V_5 )
{
if ( F_7 ( & V_5 -> V_8 ) )
F_8 ( V_5 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
if ( F_7 ( & V_10 -> V_11 ) )
F_10 ( V_10 ) ;
}
static void F_11 ( struct V_4 * V_5 ,
unsigned long V_12 )
{
if ( ! F_12 ( & V_5 -> V_8 ) )
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_8 , V_13 + V_12 ) ;
}
static void F_15 ( struct V_9 * V_10 ,
unsigned long V_12 )
{
if ( ! F_12 ( & V_10 -> V_11 ) )
F_16 ( V_10 ) ;
F_14 ( & V_10 -> V_11 , V_13 + V_12 ) ;
}
static int F_17 ( struct V_4 * V_5 )
{
if ( F_18 ( ( void V_14 * * ) V_5 -> V_15 . V_16 ,
sizeof( struct V_17 ) ,
F_19 ( struct V_17 ) ) < 0 )
goto V_18;
V_5 -> V_15 . V_19 = F_20 ( sizeof( struct V_20 ) ,
V_21 ) ;
if ( ! V_5 -> V_15 . V_19 )
goto V_22;
V_5 -> V_15 . V_23 = F_20 ( sizeof( struct V_24 ) ,
V_21 ) ;
if ( ! V_5 -> V_15 . V_23 )
goto V_25;
return 0 ;
V_25:
F_21 ( V_5 -> V_15 . V_19 ) ;
V_22:
F_22 ( ( void V_14 * * ) V_5 -> V_15 . V_16 ) ;
V_18:
return - V_26 ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_21 ( V_5 -> V_15 . V_23 ) ;
F_21 ( V_5 -> V_15 . V_19 ) ;
F_22 ( ( void V_14 * * ) V_5 -> V_15 . V_16 ) ;
}
void F_24 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_25 ( ! F_26 ( & V_5 -> V_27 ) ) ;
F_25 ( V_5 -> V_28 != NULL ) ;
F_25 ( F_12 ( & V_5 -> V_8 ) ) ;
#ifdef F_27
F_28 ( L_1 , V_29 , V_7 ? V_7 -> V_30 : L_2 ) ;
#endif
F_29 ( V_7 ) ;
if ( ! V_5 -> V_31 ) {
F_30 ( L_3 , V_5 ) ;
return;
}
F_23 ( V_5 ) ;
F_31 ( V_5 , V_32 ) ;
}
static struct V_4 * F_32 ( struct V_6 * V_7 )
{
struct V_4 * V_33 ;
F_33 () ;
if ( V_7 -> V_34 < V_35 )
return NULL ;
V_33 = F_20 ( sizeof( struct V_4 ) , V_21 ) ;
if ( V_33 == NULL )
return NULL ;
F_34 ( & V_33 -> V_36 ) ;
V_33 -> V_7 = V_7 ;
F_35 ( & V_33 -> V_27 ) ;
F_36 ( & V_33 -> V_8 , V_37 ,
( unsigned long ) V_33 ) ;
memcpy ( & V_33 -> V_38 , F_37 ( V_7 ) -> V_16 . V_39 , sizeof( V_33 -> V_38 ) ) ;
V_33 -> V_38 . V_40 = V_7 -> V_34 ;
V_33 -> V_38 . V_41 = NULL ;
V_33 -> V_42 = F_38 ( V_7 , & V_43 ) ;
if ( V_33 -> V_42 == NULL ) {
F_21 ( V_33 ) ;
return NULL ;
}
if ( V_33 -> V_38 . V_44 )
F_39 ( V_7 ) ;
F_40 ( V_7 ) ;
if ( F_17 ( V_33 ) < 0 ) {
F_41 ( ( V_45
L_4 ,
V_29 , V_7 -> V_30 ) ) ;
F_42 ( & V_43 , V_33 -> V_42 ) ;
F_29 ( V_7 ) ;
F_21 ( V_33 ) ;
return NULL ;
}
if ( F_43 ( V_33 ) < 0 ) {
F_41 ( ( V_45
L_5 ,
V_29 , V_7 -> V_30 ) ) ;
F_42 ( & V_43 , V_33 -> V_42 ) ;
V_33 -> V_31 = 1 ;
F_24 ( V_33 ) ;
return NULL ;
}
F_13 ( V_33 ) ;
if ( V_7 -> V_46 & ( V_47 | V_48 ) )
V_33 -> V_38 . V_49 = - 1 ;
#if F_44 ( V_50 )
if ( V_7 -> type == V_51 && ( V_7 -> V_52 & V_53 ) ) {
F_45 ( L_6 , V_7 -> V_30 ) ;
V_33 -> V_38 . V_54 = 0 ;
}
#endif
#ifdef F_46
F_35 ( & V_33 -> V_55 ) ;
F_36 ( & V_33 -> V_56 , V_57 , ( unsigned long ) V_33 ) ;
if ( ( V_7 -> V_46 & V_48 ) ||
V_7 -> type == V_58 ||
V_7 -> type == V_59 ||
V_7 -> type == V_51 ||
V_7 -> type == V_60 ) {
V_33 -> V_38 . V_61 = - 1 ;
} else {
F_13 ( V_33 ) ;
V_57 ( ( unsigned long ) V_33 ) ;
}
#endif
V_33 -> V_62 = V_63 ;
if ( F_47 ( V_7 ) && F_4 ( V_7 ) )
V_33 -> V_64 |= V_65 ;
F_48 ( V_33 ) ;
V_33 -> V_66 = V_13 ;
F_2 ( V_33 ) ;
F_49 ( V_7 -> V_67 , V_33 ) ;
F_50 ( V_7 , & V_68 ) ;
F_50 ( V_7 , & V_69 ) ;
if ( V_33 -> V_38 . V_44 && ( V_7 -> V_46 & V_70 ) )
F_50 ( V_7 , & V_71 ) ;
return V_33 ;
}
static struct V_4 * F_51 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_33 () ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_32 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_46 & V_72 )
F_53 ( V_5 ) ;
return V_5 ;
}
static int F_54 ( int type )
{
int V_73 = F_55 ( sizeof( struct V_74 ) )
+ F_56 ( 4 ) ;
if ( type == - 1 || type == V_75 )
V_73 += F_56 ( 4 ) ;
#ifdef F_57
if ( type == - 1 || type == V_76 )
V_73 += F_56 ( 4 ) ;
#endif
return V_73 ;
}
static int F_58 ( struct V_77 * V_78 , int V_79 ,
struct V_80 * V_81 , T_1 V_82 ,
T_1 V_83 , int V_84 , unsigned int V_46 ,
int type )
{
struct V_85 * V_86 ;
struct V_74 * V_87 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( struct V_74 ) ,
V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
V_87 = F_60 ( V_86 ) ;
V_87 -> V_89 = V_90 ;
if ( F_61 ( V_78 , V_91 , V_79 ) < 0 )
goto V_92;
if ( ( type == - 1 || type == V_75 ) &&
F_61 ( V_78 , V_75 , V_81 -> V_44 ) < 0 )
goto V_92;
#ifdef F_57
if ( ( type == - 1 || type == V_76 ) &&
F_61 ( V_78 , V_76 ,
V_81 -> V_93 ) < 0 )
goto V_92;
#endif
return F_62 ( V_78 , V_86 ) ;
V_92:
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
void F_64 ( struct V_94 * V_94 , int type , int V_79 ,
struct V_80 * V_81 )
{
struct V_77 * V_78 ;
int V_95 = - V_96 ;
V_78 = F_65 ( F_54 ( type ) , V_97 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_58 ( V_78 , V_79 , V_81 , 0 , 0 ,
V_99 , 0 , type ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_98;
}
F_67 ( V_78 , V_94 , 0 , V_100 , NULL , V_97 ) ;
return;
V_98:
F_68 ( V_94 , V_100 , V_95 ) ;
}
static int F_69 ( struct V_77 * V_101 ,
struct V_85 * V_86 )
{
struct V_94 * V_94 = F_70 ( V_101 -> V_102 ) ;
struct V_103 * V_104 [ V_105 + 1 ] ;
struct V_74 * V_87 ;
struct V_77 * V_78 ;
struct V_80 * V_81 ;
struct V_4 * V_106 ;
struct V_6 * V_7 ;
int V_79 ;
int V_95 ;
V_95 = F_71 ( V_86 , sizeof( * V_87 ) , V_104 , V_105 ,
V_107 ) ;
if ( V_95 < 0 )
goto V_98;
V_95 = V_108 ;
if ( ! V_104 [ V_91 ] )
goto V_98;
V_79 = F_72 ( V_104 [ V_91 ] ) ;
switch ( V_79 ) {
case V_109 :
V_81 = V_94 -> V_16 . V_110 ;
break;
case V_111 :
V_81 = V_94 -> V_16 . V_39 ;
break;
default:
V_7 = F_73 ( V_94 , V_79 ) ;
if ( V_7 == NULL )
goto V_98;
V_106 = F_52 ( V_7 ) ;
if ( V_106 == NULL )
goto V_98;
V_81 = & V_106 -> V_38 ;
break;
}
V_95 = - V_96 ;
V_78 = F_65 ( F_54 ( - 1 ) , V_97 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_58 ( V_78 , V_79 , V_81 ,
F_74 ( V_101 ) . V_82 ,
V_86 -> V_112 , V_99 , 0 ,
- 1 ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_98;
}
V_95 = F_75 ( V_78 , V_94 , F_74 ( V_101 ) . V_82 ) ;
V_98:
return V_95 ;
}
static int F_76 ( struct V_77 * V_78 ,
struct V_113 * V_114 )
{
struct V_94 * V_94 = F_70 ( V_78 -> V_102 ) ;
int V_115 , V_116 ;
int V_117 , V_118 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_119 * V_120 ;
V_116 = V_114 -> args [ 0 ] ;
V_118 = V_117 = V_114 -> args [ 1 ] ;
for ( V_115 = V_116 ; V_115 < V_121 ; V_115 ++ , V_118 = 0 ) {
V_117 = 0 ;
V_120 = & V_94 -> V_122 [ V_115 ] ;
F_77 () ;
V_114 -> V_83 = F_78 ( & V_94 -> V_16 . V_123 ) ^
V_94 -> V_124 ;
F_79 (dev, head, index_hlist) {
if ( V_117 < V_118 )
goto V_125;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_125;
if ( F_58 ( V_78 , V_7 -> V_79 ,
& V_5 -> V_38 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_99 ,
V_126 ,
- 1 ) <= 0 ) {
F_80 () ;
goto V_127;
}
F_81 ( V_114 , F_82 ( V_78 ) ) ;
V_125:
V_117 ++ ;
}
F_80 () ;
}
if ( V_115 == V_121 ) {
if ( F_58 ( V_78 , V_109 ,
V_94 -> V_16 . V_110 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_99 , V_126 ,
- 1 ) <= 0 )
goto V_127;
else
V_115 ++ ;
}
if ( V_115 == V_121 + 1 ) {
if ( F_58 ( V_78 , V_111 ,
V_94 -> V_16 . V_39 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_99 , V_126 ,
- 1 ) <= 0 )
goto V_127;
else
V_115 ++ ;
}
V_127:
V_114 -> args [ 0 ] = V_115 ;
V_114 -> args [ 1 ] = V_117 ;
return V_78 -> V_128 ;
}
static void F_83 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_129 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_38 . V_44 )
F_39 ( V_7 ) ;
if ( V_7 -> V_46 & V_70 ) {
if ( V_5 -> V_38 . V_44 ) {
F_50 ( V_7 , & V_71 ) ;
F_50 ( V_7 , & V_130 ) ;
F_50 ( V_7 , & V_131 ) ;
} else {
F_84 ( V_7 , & V_71 ) ;
F_84 ( V_7 , & V_130 ) ;
F_84 ( V_7 , & V_131 ) ;
}
}
F_85 (ifa, &idev->addr_list, if_list) {
if ( V_129 -> V_46 & V_132 )
continue;
if ( V_5 -> V_38 . V_44 )
F_86 ( V_129 ) ;
else
F_87 ( V_129 ) ;
}
F_64 ( F_37 ( V_7 ) , V_75 ,
V_7 -> V_79 , & V_5 -> V_38 ) ;
}
static void F_88 ( struct V_94 * V_94 , T_2 V_133 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_89 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_134 = ( ! V_5 -> V_38 . V_44 ) ^ ( ! V_133 ) ;
V_5 -> V_38 . V_44 = V_133 ;
if ( V_134 )
F_83 ( V_5 ) ;
}
}
}
static int F_90 ( struct V_135 * V_136 , int * V_137 , int V_133 )
{
struct V_94 * V_94 ;
int V_138 ;
if ( ! F_91 () )
return F_92 () ;
V_94 = (struct V_94 * ) V_136 -> V_139 ;
V_138 = * V_137 ;
* V_137 = V_133 ;
if ( V_137 == & V_94 -> V_16 . V_39 -> V_44 ) {
if ( ( ! V_133 ) ^ ( ! V_138 ) )
F_64 ( V_94 , V_75 ,
V_111 ,
V_94 -> V_16 . V_39 ) ;
F_93 () ;
return 0 ;
}
if ( V_137 == & V_94 -> V_16 . V_110 -> V_44 ) {
V_94 -> V_16 . V_39 -> V_44 = V_133 ;
F_88 ( V_94 , V_133 ) ;
if ( ( ! V_133 ) ^ ( ! V_138 ) )
F_64 ( V_94 , V_75 ,
V_109 ,
V_94 -> V_16 . V_110 ) ;
} else if ( ( ! V_133 ) ^ ( ! V_138 ) )
F_83 ( (struct V_4 * ) V_136 -> V_140 ) ;
F_93 () ;
if ( V_133 )
F_94 ( V_94 ) ;
return 1 ;
}
void F_95 ( struct V_9 * V_10 )
{
F_25 ( ! F_96 ( & V_10 -> V_141 ) ) ;
#ifdef F_27
F_28 ( L_7 , V_29 ) ;
#endif
F_97 ( V_10 -> V_5 ) ;
if ( F_7 ( & V_10 -> V_11 ) )
F_98 ( L_8 , V_10 ) ;
if ( V_10 -> V_142 != V_143 ) {
F_30 ( L_9 , V_10 ) ;
return;
}
F_99 ( V_10 -> V_144 ) ;
F_31 ( V_10 , V_32 ) ;
}
static void
F_100 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_145 * V_137 ;
int V_146 = F_101 ( & V_10 -> V_147 ) ;
F_102 (p, &idev->addr_list) {
struct V_9 * V_129
= F_103 ( V_137 , struct V_9 , V_148 ) ;
if ( V_146 >= F_101 ( & V_129 -> V_147 ) )
break;
}
F_104 ( & V_10 -> V_148 , V_137 ) ;
}
static T_1 F_105 ( const struct V_149 * V_147 )
{
return F_106 ( F_107 ( V_147 ) , V_150 ) ;
}
static struct V_9 *
F_108 ( struct V_4 * V_5 , const struct V_149 * V_147 ,
const struct V_149 * V_151 , int V_152 ,
int V_153 , T_1 V_46 , T_1 V_154 , T_1 V_155 )
{
struct V_9 * V_129 = NULL ;
struct V_156 * V_144 ;
unsigned int V_157 ;
int V_95 = 0 ;
int V_158 = F_109 ( V_147 ) ;
if ( V_158 == V_159 ||
V_158 & V_160 ||
( ! ( V_5 -> V_7 -> V_46 & V_48 ) &&
V_158 & V_161 ) )
return F_110 ( - V_162 ) ;
F_111 () ;
if ( V_5 -> V_31 ) {
V_95 = - V_163 ;
goto V_164;
}
if ( V_5 -> V_38 . V_165 ) {
V_95 = - V_166 ;
goto V_164;
}
F_112 ( & V_167 ) ;
if ( F_113 ( F_37 ( V_5 -> V_7 ) , V_147 , V_5 -> V_7 ) ) {
F_41 ( ( L_10 ) ) ;
V_95 = - V_168 ;
goto V_169;
}
V_129 = F_20 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_129 == NULL ) {
F_41 ( ( L_11 ) ) ;
V_95 = - V_96 ;
goto V_169;
}
V_144 = F_114 ( V_5 , V_147 , false ) ;
if ( F_115 ( V_144 ) ) {
V_95 = F_116 ( V_144 ) ;
goto V_169;
}
V_129 -> V_147 = * V_147 ;
if ( V_151 )
V_129 -> V_151 = * V_151 ;
F_117 ( & V_129 -> V_36 ) ;
F_117 ( & V_129 -> V_170 ) ;
F_36 ( & V_129 -> V_11 , V_171 ,
( unsigned long ) V_129 ) ;
F_118 ( & V_129 -> V_141 ) ;
V_129 -> V_153 = V_153 ;
V_129 -> V_172 = V_152 ;
V_129 -> V_46 = V_46 | V_132 ;
V_129 -> V_154 = V_154 ;
V_129 -> V_155 = V_155 ;
V_129 -> V_1 = V_129 -> V_66 = V_13 ;
V_129 -> V_173 = false ;
V_129 -> V_144 = V_144 ;
V_129 -> V_5 = V_5 ;
F_13 ( V_5 ) ;
F_16 ( V_129 ) ;
V_157 = F_105 ( V_147 ) ;
F_119 ( & V_129 -> V_141 , & V_174 [ V_157 ] ) ;
F_120 ( & V_167 ) ;
F_121 ( & V_5 -> V_36 ) ;
F_100 ( V_5 , V_129 ) ;
#ifdef F_46
if ( V_129 -> V_46 & V_175 ) {
F_122 ( & V_129 -> V_176 , & V_5 -> V_55 ) ;
F_16 ( V_129 ) ;
}
#endif
F_16 ( V_129 ) ;
F_123 ( & V_5 -> V_36 ) ;
V_164:
F_124 () ;
if ( F_125 ( V_95 == 0 ) )
F_126 ( V_177 , V_129 ) ;
else {
F_21 ( V_129 ) ;
V_129 = F_110 ( V_95 ) ;
}
return V_129 ;
V_169:
F_120 ( & V_167 ) ;
goto V_164;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_9 * V_129 , * V_178 ;
struct V_4 * V_5 = V_10 -> V_5 ;
int V_142 ;
int V_179 = 0 , V_180 = 0 ;
unsigned long V_181 = V_13 ;
F_128 ( & V_10 -> V_170 ) ;
V_142 = V_10 -> V_142 ;
V_10 -> V_142 = V_143 ;
F_129 ( & V_10 -> V_170 ) ;
if ( V_142 == V_143 )
goto V_169;
F_128 ( & V_167 ) ;
F_130 ( & V_10 -> V_141 ) ;
F_129 ( & V_167 ) ;
F_131 ( & V_5 -> V_36 ) ;
#ifdef F_46
if ( V_10 -> V_46 & V_175 ) {
F_132 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_182 ) {
F_133 ( V_10 -> V_182 ) ;
V_10 -> V_182 = NULL ;
}
F_10 ( V_10 ) ;
}
#endif
F_134 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_129 == V_10 ) {
F_135 ( & V_10 -> V_148 ) ;
F_10 ( V_10 ) ;
if ( ! ( V_10 -> V_46 & V_183 ) || V_180 > 0 )
break;
V_179 = 1 ;
continue;
} else if ( V_10 -> V_46 & V_183 ) {
if ( F_136 ( & V_129 -> V_147 , & V_10 -> V_147 ,
V_10 -> V_172 ) ) {
if ( V_129 -> V_46 & V_183 ) {
V_180 = 1 ;
if ( V_179 )
break;
} else {
unsigned long V_184 ;
if ( ! V_180 )
V_180 = - 1 ;
F_112 ( & V_129 -> V_36 ) ;
V_184 = F_137 ( V_129 -> V_154 , V_3 ) ;
if ( F_138 ( V_181 ,
V_129 -> V_66 + V_184 * V_3 ) )
V_181 = V_129 -> V_66 + V_184 * V_3 ;
F_120 ( & V_129 -> V_36 ) ;
}
}
}
}
F_139 ( & V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_140 ( V_185 , V_10 ) ;
F_126 ( V_186 , V_10 ) ;
if ( ( V_10 -> V_46 & V_183 ) && V_180 < 1 ) {
struct V_149 V_187 ;
struct V_156 * V_144 ;
F_141 ( & V_187 , & V_10 -> V_147 , V_10 -> V_172 ) ;
V_144 = F_142 ( & V_187 ,
V_10 -> V_172 ,
V_10 -> V_5 -> V_7 ,
0 , V_188 | V_189 ) ;
if ( V_144 ) {
if ( V_180 == 0 ) {
F_143 ( V_144 ) ;
V_144 = NULL ;
} else if ( ! ( V_144 -> V_190 & V_191 ) ) {
F_144 ( V_144 , V_181 ) ;
}
}
F_99 ( V_144 ) ;
}
F_145 ( V_10 ) ;
V_169:
F_133 ( V_10 ) ;
}
static int F_146 ( struct V_9 * V_10 , struct V_9 * V_192 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_149 V_147 , * V_193 ;
unsigned long V_194 , V_195 , V_196 , V_197 ;
unsigned long V_198 ;
int V_199 ;
int V_200 = 0 ;
int V_201 ;
T_1 V_202 ;
unsigned long V_203 = V_13 ;
F_121 ( & V_5 -> V_36 ) ;
if ( V_192 ) {
F_128 ( & V_192 -> V_36 ) ;
memcpy ( & V_147 . V_204 [ 8 ] , & V_192 -> V_147 . V_204 [ 8 ] , 8 ) ;
F_129 ( & V_192 -> V_36 ) ;
V_193 = & V_147 ;
} else {
V_193 = NULL ;
}
V_205:
F_13 ( V_5 ) ;
if ( V_5 -> V_38 . V_61 <= 0 ) {
F_123 ( & V_5 -> V_36 ) ;
F_45 ( L_12 , V_29 ) ;
F_97 ( V_5 ) ;
V_200 = - 1 ;
goto V_169;
}
F_128 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_206 ++ >= V_5 -> V_38 . V_207 ) {
V_5 -> V_38 . V_61 = - 1 ;
F_129 ( & V_10 -> V_36 ) ;
F_123 ( & V_5 -> V_36 ) ;
F_30 ( L_13 ,
V_29 ) ;
F_97 ( V_5 ) ;
V_200 = - 1 ;
goto V_169;
}
F_16 ( V_10 ) ;
memcpy ( V_147 . V_204 , V_10 -> V_147 . V_204 , 8 ) ;
F_147 ( V_5 , V_193 ) ;
memcpy ( & V_147 . V_204 [ 8 ] , V_5 -> V_208 , 8 ) ;
V_197 = ( V_203 - V_10 -> V_66 ) / V_3 ;
V_195 = F_148 ( V_209 ,
V_10 -> V_154 ,
V_5 -> V_38 . V_210 + V_197 ) ;
V_194 = F_148 ( V_209 ,
V_10 -> V_155 ,
V_5 -> V_38 . V_211 + V_197 -
V_5 -> V_38 . V_212 ) ;
V_199 = V_10 -> V_172 ;
V_201 = V_5 -> V_38 . V_201 ;
V_196 = V_10 -> V_66 ;
F_129 ( & V_10 -> V_36 ) ;
V_198 = V_5 -> V_38 . V_207 *
V_5 -> V_38 . V_213 *
V_5 -> V_42 -> V_214 / V_3 ;
F_123 ( & V_5 -> V_36 ) ;
if ( V_194 <= V_198 ) {
F_133 ( V_10 ) ;
F_97 ( V_5 ) ;
V_200 = - 1 ;
goto V_169;
}
V_202 = V_175 ;
if ( V_10 -> V_46 & V_215 )
V_202 |= V_215 ;
V_192 = F_108 ( V_5 , & V_147 , NULL , V_199 ,
F_149 ( & V_147 ) , V_202 ,
V_195 , V_194 ) ;
if ( F_115 ( V_192 ) ) {
F_133 ( V_10 ) ;
F_97 ( V_5 ) ;
F_45 ( L_14 , V_29 ) ;
V_193 = & V_147 ;
F_121 ( & V_5 -> V_36 ) ;
goto V_205;
}
F_128 ( & V_192 -> V_36 ) ;
V_192 -> V_182 = V_10 ;
V_192 -> V_1 = V_203 ;
V_192 -> V_66 = V_196 ;
F_129 ( & V_192 -> V_36 ) ;
F_150 ( V_192 ) ;
F_133 ( V_192 ) ;
F_97 ( V_5 ) ;
V_169:
return V_200 ;
}
static inline int F_151 ( int type )
{
if ( type & ( V_216 | V_217 | V_161 ) )
return 1 ;
return 0 ;
}
static int F_152 ( struct V_94 * V_94 ,
struct V_218 * V_219 ,
struct V_220 * V_221 ,
int V_222 )
{
int V_200 ;
if ( V_222 <= V_219 -> V_223 ) {
switch ( V_222 ) {
case V_224 :
V_200 = V_219 -> V_225 ;
break;
case V_226 :
V_200 = V_219 -> V_227 ;
break;
default:
V_200 = ! ! F_153 ( V_222 , V_219 -> V_228 ) ;
}
goto V_169;
}
switch ( V_222 ) {
case V_229 :
V_200 = ! ! V_219 -> V_129 ;
break;
case V_230 :
V_200 = F_154 ( & V_219 -> V_129 -> V_147 , V_221 -> V_147 ) ;
break;
case V_224 :
V_200 = F_155 ( V_219 -> V_158 ) ;
if ( V_200 >= V_221 -> V_153 )
V_200 = - V_200 ;
else
V_200 -= 128 ;
V_219 -> V_225 = V_200 ;
break;
case V_231 :
V_200 = F_151 ( V_219 -> V_158 ) ||
! ( V_219 -> V_129 -> V_46 & ( V_232 | V_215 ) ) ;
break;
#ifdef F_156
case V_233 :
{
int V_234 = ! ( V_221 -> V_235 & V_236 ) ;
V_200 = ! ( V_219 -> V_129 -> V_46 & V_237 ) ^ V_234 ;
break;
}
#endif
case V_238 :
V_200 = ( ! V_221 -> V_79 ||
V_221 -> V_79 == V_219 -> V_129 -> V_5 -> V_7 -> V_79 ) ;
break;
case V_239 :
V_200 = F_157 ( V_94 ,
& V_219 -> V_129 -> V_147 , V_219 -> V_158 ,
V_219 -> V_129 -> V_5 -> V_7 -> V_79 ) == V_221 -> V_240 ;
break;
#ifdef F_46
case V_241 :
{
int V_242 = V_221 -> V_235 & ( V_243 | V_244 ) ?
! ! ( V_221 -> V_235 & V_244 ) :
V_219 -> V_129 -> V_5 -> V_38 . V_61 >= 2 ;
V_200 = ( ! ( V_219 -> V_129 -> V_46 & V_175 ) ) ^ V_242 ;
break;
}
#endif
case V_245 :
V_200 = ! ( F_158 ( & V_219 -> V_129 -> V_147 ) ^
F_158 ( V_221 -> V_147 ) ) ;
break;
case V_226 :
V_200 = F_159 ( & V_219 -> V_129 -> V_147 , V_221 -> V_147 ) ;
if ( V_200 > V_219 -> V_129 -> V_172 )
V_200 = V_219 -> V_129 -> V_172 ;
V_219 -> V_227 = V_200 ;
break;
default:
V_200 = 0 ;
}
if ( V_200 )
F_160 ( V_222 , V_219 -> V_228 ) ;
V_219 -> V_223 = V_222 ;
V_169:
return V_200 ;
}
int F_161 ( struct V_94 * V_94 , const struct V_6 * V_246 ,
const struct V_149 * V_247 , unsigned int V_235 ,
struct V_149 * V_248 )
{
struct V_218 V_249 [ 2 ] ,
* V_219 = & V_249 [ 0 ] , * V_250 = & V_249 [ 1 ] ;
struct V_220 V_221 ;
struct V_6 * V_7 ;
int V_251 ;
V_251 = F_162 ( V_247 ) ;
V_221 . V_147 = V_247 ;
V_221 . V_79 = V_246 ? V_246 -> V_79 : 0 ;
V_221 . V_153 = F_155 ( V_251 ) ;
V_221 . V_240 = F_157 ( V_94 , V_247 , V_251 , V_221 . V_79 ) ;
V_221 . V_235 = V_235 ;
V_250 -> V_223 = - 1 ;
V_250 -> V_129 = NULL ;
F_77 () ;
F_163 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_251 & V_160 ) ||
V_221 . V_153 <= V_252 ) &&
V_221 . V_79 && V_7 -> V_79 != V_221 . V_79 )
continue;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
continue;
F_164 ( & V_5 -> V_36 ) ;
F_85 (score->ifa, &idev->addr_list, if_list) {
int V_222 ;
if ( ( V_219 -> V_129 -> V_46 & V_132 ) &&
( ! ( V_219 -> V_129 -> V_46 & V_215 ) ) )
continue;
V_219 -> V_158 = F_162 ( & V_219 -> V_129 -> V_147 ) ;
if ( F_165 ( V_219 -> V_158 == V_159 ||
V_219 -> V_158 & V_160 ) ) {
F_166 ( V_253
L_15
L_16 ,
V_7 -> V_30 ) ;
continue;
}
V_219 -> V_223 = - 1 ;
F_167 ( V_219 -> V_228 , V_254 ) ;
for ( V_222 = 0 ; V_222 < V_254 ; V_222 ++ ) {
int V_255 , V_256 ;
V_255 = F_152 ( V_94 , V_250 , & V_221 , V_222 ) ;
V_256 = F_152 ( V_94 , V_219 , & V_221 , V_222 ) ;
if ( V_255 > V_256 ) {
if ( V_222 == V_224 &&
V_219 -> V_225 > 0 ) {
goto V_257;
}
break;
} else if ( V_255 < V_256 ) {
if ( V_250 -> V_129 )
F_133 ( V_250 -> V_129 ) ;
F_16 ( V_219 -> V_129 ) ;
F_168 ( V_250 , V_219 ) ;
V_219 -> V_129 = V_250 -> V_129 ;
break;
}
}
}
V_257:
F_169 ( & V_5 -> V_36 ) ;
}
F_80 () ;
if ( ! V_250 -> V_129 )
return - V_162 ;
* V_248 = V_250 -> V_129 -> V_147 ;
F_133 ( V_250 -> V_129 ) ;
return 0 ;
}
int F_170 ( struct V_4 * V_5 , struct V_149 * V_147 ,
unsigned char V_258 )
{
struct V_9 * V_10 ;
int V_95 = - V_162 ;
F_85 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_153 == V_259 &&
! ( V_10 -> V_46 & V_258 ) ) {
* V_147 = V_10 -> V_147 ;
V_95 = 0 ;
break;
}
}
return V_95 ;
}
int F_171 ( struct V_6 * V_7 , struct V_149 * V_147 ,
unsigned char V_258 )
{
struct V_4 * V_5 ;
int V_95 = - V_162 ;
F_77 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_164 ( & V_5 -> V_36 ) ;
V_95 = F_170 ( V_5 , V_147 , V_258 ) ;
F_169 ( & V_5 -> V_36 ) ;
}
F_80 () ;
return V_95 ;
}
static int F_172 ( struct V_4 * V_5 )
{
int V_260 = 0 ;
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_36 ) ;
F_85 (ifp, &idev->addr_list, if_list)
V_260 ++ ;
F_169 ( & V_5 -> V_36 ) ;
return V_260 ;
}
int F_173 ( struct V_94 * V_94 , const struct V_149 * V_147 ,
const struct V_6 * V_7 , int V_261 )
{
struct V_9 * V_10 ;
unsigned int V_157 = F_105 ( V_147 ) ;
F_111 () ;
F_79 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_37 ( V_10 -> V_5 -> V_7 ) , V_94 ) )
continue;
if ( F_154 ( & V_10 -> V_147 , V_147 ) &&
! ( V_10 -> V_46 & V_132 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_153 & ( V_259 | V_262 ) || V_261 ) ) ) {
F_124 () ;
return 1 ;
}
}
F_124 () ;
return 0 ;
}
static bool F_113 ( struct V_94 * V_94 , const struct V_149 * V_147 ,
struct V_6 * V_7 )
{
unsigned int V_157 = F_105 ( V_147 ) ;
struct V_9 * V_10 ;
F_175 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_37 ( V_10 -> V_5 -> V_7 ) , V_94 ) )
continue;
if ( F_154 ( & V_10 -> V_147 , V_147 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_176 ( const struct V_149 * V_147 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_129 ;
int V_180 ;
V_180 = 0 ;
F_77 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_164 ( & V_5 -> V_36 ) ;
F_85 (ifa, &idev->addr_list, if_list) {
V_180 = F_136 ( V_147 , & V_129 -> V_147 ,
V_129 -> V_172 ) ;
if ( V_180 )
break;
}
F_169 ( & V_5 -> V_36 ) ;
}
F_80 () ;
return V_180 ;
}
struct V_9 * F_177 ( struct V_94 * V_94 , const struct V_149 * V_147 ,
struct V_6 * V_7 , int V_261 )
{
struct V_9 * V_10 , * V_263 = NULL ;
unsigned int V_157 = F_105 ( V_147 ) ;
F_111 () ;
F_178 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_37 ( V_10 -> V_5 -> V_7 ) , V_94 ) )
continue;
if ( F_154 ( & V_10 -> V_147 , V_147 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_153 & ( V_259 | V_262 ) || V_261 ) ) {
V_263 = V_10 ;
F_16 ( V_10 ) ;
break;
}
}
}
F_124 () ;
return V_263 ;
}
static void F_179 ( struct V_9 * V_10 , int V_264 )
{
if ( V_10 -> V_46 & V_183 ) {
F_128 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_46 |= V_132 ;
if ( V_264 )
V_10 -> V_46 |= V_265 ;
F_129 ( & V_10 -> V_36 ) ;
if ( V_264 )
F_140 ( 0 , V_10 ) ;
F_133 ( V_10 ) ;
#ifdef F_46
} else if ( V_10 -> V_46 & V_175 ) {
struct V_9 * V_182 ;
F_128 ( & V_10 -> V_36 ) ;
V_182 = V_10 -> V_182 ;
if ( V_182 ) {
F_16 ( V_182 ) ;
F_129 ( & V_10 -> V_36 ) ;
F_146 ( V_182 , V_10 ) ;
F_133 ( V_182 ) ;
} else {
F_129 ( & V_10 -> V_36 ) ;
}
F_127 ( V_10 ) ;
#endif
} else
F_127 ( V_10 ) ;
}
static int F_180 ( struct V_9 * V_10 )
{
int V_95 = - V_266 ;
F_112 ( & V_10 -> V_170 ) ;
if ( V_10 -> V_142 == V_267 ) {
V_10 -> V_142 = V_268 ;
V_95 = 0 ;
}
F_120 ( & V_10 -> V_170 ) ;
return V_95 ;
}
void F_181 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_180 ( V_10 ) ) {
F_133 ( V_10 ) ;
return;
}
F_182 ( L_17 ,
V_10 -> V_5 -> V_7 -> V_30 , & V_10 -> V_147 ) ;
if ( V_5 -> V_38 . V_49 > 1 && ! V_5 -> V_38 . V_165 ) {
struct V_149 V_147 ;
V_147 . V_269 [ 0 ] = F_183 ( 0xfe800000 ) ;
V_147 . V_269 [ 1 ] = 0 ;
if ( ! F_184 ( V_147 . V_204 + 8 , V_5 -> V_7 ) &&
F_154 ( & V_10 -> V_147 , & V_147 ) ) {
V_5 -> V_38 . V_165 = 1 ;
F_45 ( L_18 ,
V_10 -> V_5 -> V_7 -> V_30 ) ;
}
}
F_179 ( V_10 , 1 ) ;
}
void F_185 ( struct V_6 * V_7 , const struct V_149 * V_147 )
{
struct V_149 V_270 ;
if ( V_7 -> V_46 & ( V_48 | V_47 ) )
return;
F_186 ( V_147 , & V_270 ) ;
F_50 ( V_7 , & V_270 ) ;
}
void F_187 ( struct V_4 * V_5 , const struct V_149 * V_147 )
{
struct V_149 V_270 ;
if ( V_5 -> V_7 -> V_46 & ( V_48 | V_47 ) )
return;
F_186 ( V_147 , & V_270 ) ;
F_188 ( V_5 , & V_270 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_149 V_147 ;
if ( V_10 -> V_172 == 127 )
return;
F_141 ( & V_147 , & V_10 -> V_147 , V_10 -> V_172 ) ;
if ( F_189 ( & V_147 ) )
return;
F_190 ( V_10 -> V_5 -> V_7 , & V_147 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_149 V_147 ;
if ( V_10 -> V_172 == 127 )
return;
F_141 ( & V_147 , & V_10 -> V_147 , V_10 -> V_172 ) ;
if ( F_189 ( & V_147 ) )
return;
F_191 ( V_10 -> V_5 , & V_147 ) ;
}
static int F_192 ( T_3 * V_271 , struct V_6 * V_7 )
{
if ( V_7 -> V_272 != V_273 )
return - 1 ;
memcpy ( V_271 , V_7 -> V_274 , 3 ) ;
memcpy ( V_271 + 5 , V_7 -> V_274 + 3 , 3 ) ;
if ( V_7 -> V_275 ) {
V_271 [ 3 ] = ( V_7 -> V_275 >> 8 ) & 0xFF ;
V_271 [ 4 ] = V_7 -> V_275 & 0xFF ;
} else {
V_271 [ 3 ] = 0xFF ;
V_271 [ 4 ] = 0xFE ;
V_271 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_193 ( T_3 * V_271 , struct V_6 * V_7 )
{
if ( V_7 -> V_272 != V_276 )
return - 1 ;
memcpy ( V_271 , V_7 -> V_274 , 8 ) ;
V_271 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_194 ( T_3 * V_271 , struct V_6 * V_7 )
{
union V_277 * V_278 ;
if ( V_7 -> V_272 != V_279 )
return - 1 ;
V_278 = (union V_277 * ) V_7 -> V_274 ;
memcpy ( V_271 , & V_278 -> V_280 . V_281 , sizeof( V_278 -> V_280 . V_281 ) ) ;
V_271 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_195 ( T_3 * V_271 , struct V_6 * V_7 )
{
if ( V_7 -> V_272 != V_282 )
return - 1 ;
memset ( V_271 , 0 , 7 ) ;
V_271 [ 7 ] = * ( T_3 * ) V_7 -> V_274 ;
return 0 ;
}
static int F_196 ( T_3 * V_271 , struct V_6 * V_7 )
{
if ( V_7 -> V_272 != V_283 )
return - 1 ;
memcpy ( V_271 , V_7 -> V_274 + 12 , 8 ) ;
V_271 [ 0 ] |= 2 ;
return 0 ;
}
static int F_197 ( T_3 * V_271 , T_4 V_147 )
{
if ( V_147 == 0 )
return - 1 ;
V_271 [ 0 ] = ( F_198 ( V_147 ) || F_199 ( V_147 ) ||
F_200 ( V_147 ) || F_201 ( V_147 ) ||
F_202 ( V_147 ) || F_203 ( V_147 ) ||
F_204 ( V_147 ) || F_205 ( V_147 ) ||
F_206 ( V_147 ) || F_207 ( V_147 ) ||
F_208 ( V_147 ) ) ? 0x00 : 0x02 ;
V_271 [ 1 ] = 0 ;
V_271 [ 2 ] = 0x5E ;
V_271 [ 3 ] = 0xFE ;
memcpy ( V_271 + 4 , & V_147 , 4 ) ;
return 0 ;
}
static int F_209 ( T_3 * V_271 , struct V_6 * V_7 )
{
if ( V_7 -> V_52 & V_53 )
return F_197 ( V_271 , * ( T_4 * ) V_7 -> V_274 ) ;
return - 1 ;
}
static int F_210 ( T_3 * V_271 , struct V_6 * V_7 )
{
return F_197 ( V_271 , * ( T_4 * ) V_7 -> V_274 ) ;
}
static int F_184 ( T_3 * V_271 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_284 :
case V_285 :
return F_192 ( V_271 , V_7 ) ;
case V_286 :
return F_195 ( V_271 , V_7 ) ;
case V_287 :
return F_196 ( V_271 , V_7 ) ;
case V_51 :
return F_209 ( V_271 , V_7 ) ;
case V_288 :
return F_210 ( V_271 , V_7 ) ;
case V_289 :
return F_193 ( V_271 , V_7 ) ;
case V_290 :
return F_194 ( V_271 , V_7 ) ;
}
return - 1 ;
}
static int F_211 ( T_3 * V_271 , struct V_4 * V_5 )
{
int V_95 = - 1 ;
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_36 ) ;
F_85 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_153 == V_259 && ! ( V_10 -> V_46 & V_132 ) ) {
memcpy ( V_271 , V_10 -> V_147 . V_204 + 8 , 8 ) ;
V_95 = 0 ;
break;
}
}
F_169 ( & V_5 -> V_36 ) ;
return V_95 ;
}
static void F_212 ( struct V_4 * V_5 )
{
V_291:
F_213 ( V_5 -> V_208 , sizeof( V_5 -> V_208 ) ) ;
V_5 -> V_208 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_208 [ 0 ] == 0xfd &&
( V_5 -> V_208 [ 1 ] & V_5 -> V_208 [ 2 ] & V_5 -> V_208 [ 3 ] & V_5 -> V_208 [ 4 ] & V_5 -> V_208 [ 5 ] & V_5 -> V_208 [ 6 ] ) == 0xff &&
( V_5 -> V_208 [ 7 ] & 0x80 ) )
goto V_291;
if ( ( V_5 -> V_208 [ 0 ] | V_5 -> V_208 [ 1 ] ) == 0 ) {
if ( V_5 -> V_208 [ 2 ] == 0x5e && V_5 -> V_208 [ 3 ] == 0xfe )
goto V_291;
if ( ( V_5 -> V_208 [ 2 ] | V_5 -> V_208 [ 3 ] | V_5 -> V_208 [ 4 ] | V_5 -> V_208 [ 5 ] | V_5 -> V_208 [ 6 ] | V_5 -> V_208 [ 7 ] ) == 0x00 )
goto V_291;
}
}
static void V_57 ( unsigned long V_292 )
{
struct V_4 * V_5 = (struct V_4 * ) V_292 ;
unsigned long V_181 ;
F_111 () ;
F_131 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_31 )
goto V_169;
F_212 ( V_5 ) ;
V_181 = V_13 +
V_5 -> V_38 . V_211 * V_3 -
V_5 -> V_38 . V_207 * V_5 -> V_38 . V_213 * V_5 -> V_42 -> V_214 -
V_5 -> V_38 . V_212 * V_3 ;
if ( F_138 ( V_181 , V_13 ) ) {
F_30 ( L_19 ,
V_29 , V_5 -> V_7 -> V_30 ) ;
goto V_169;
}
if ( ! F_14 ( & V_5 -> V_56 , V_181 ) )
F_13 ( V_5 ) ;
V_169:
F_139 ( & V_5 -> V_36 ) ;
F_124 () ;
F_97 ( V_5 ) ;
}
static void F_147 ( struct V_4 * V_5 , struct V_149 * V_193 )
{
if ( V_193 && memcmp ( V_5 -> V_208 , & V_193 -> V_204 [ 8 ] , 8 ) == 0 )
F_212 ( V_5 ) ;
}
static void
F_214 ( struct V_149 * V_293 , int V_294 , struct V_6 * V_7 ,
unsigned long V_181 , T_1 V_46 )
{
struct V_295 V_296 = {
. V_297 = V_298 ,
. V_299 = V_300 ,
. V_301 = V_7 -> V_79 ,
. V_302 = V_181 ,
. V_303 = V_294 ,
. V_304 = V_305 | V_46 ,
. V_306 . V_307 = F_37 ( V_7 ) ,
. V_308 = V_309 ,
} ;
V_296 . V_310 = * V_293 ;
#if F_44 ( V_50 )
if ( V_7 -> type == V_51 && ( V_7 -> V_46 & V_311 ) )
V_296 . V_304 |= V_312 ;
#endif
F_215 ( & V_296 ) ;
}
static struct V_156 * F_142 ( const struct V_149 * V_293 ,
int V_294 ,
const struct V_6 * V_7 ,
T_1 V_46 , T_1 V_313 )
{
struct V_314 * V_315 ;
struct V_156 * V_144 = NULL ;
struct V_316 * V_136 ;
V_136 = F_216 ( F_37 ( V_7 ) , V_298 ) ;
if ( V_136 == NULL )
return NULL ;
F_164 ( & V_136 -> V_317 ) ;
V_315 = F_217 ( & V_136 -> V_318 , V_293 , V_294 , NULL , 0 ) ;
if ( ! V_315 )
goto V_169;
for ( V_144 = V_315 -> V_319 ; V_144 ; V_144 = V_144 -> V_221 . V_320 ) {
if ( V_144 -> V_221 . V_7 -> V_79 != V_7 -> V_79 )
continue;
if ( ( V_144 -> V_190 & V_46 ) != V_46 )
continue;
if ( ( V_144 -> V_190 & V_313 ) != 0 )
continue;
F_218 ( & V_144 -> V_221 ) ;
break;
}
V_169:
F_169 ( & V_136 -> V_317 ) ;
return V_144 ;
}
static void F_219 ( struct V_6 * V_7 )
{
struct V_295 V_296 = {
. V_297 = V_321 ,
. V_299 = V_300 ,
. V_301 = V_7 -> V_79 ,
. V_303 = 8 ,
. V_304 = V_305 ,
. V_306 . V_307 = F_37 ( V_7 ) ,
} ;
F_220 ( & V_296 . V_310 , F_183 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_215 ( & V_296 ) ;
}
static void F_221 ( struct V_6 * V_7 )
{
struct V_295 V_296 = {
. V_297 = V_322 ,
. V_299 = V_300 ,
. V_301 = V_7 -> V_79 ,
. V_303 = 96 ,
. V_304 = V_305 | V_312 ,
. V_306 . V_307 = F_37 ( V_7 ) ,
} ;
F_215 ( & V_296 ) ;
}
static struct V_4 * F_222 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_33 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return F_110 ( - V_96 ) ;
if ( V_5 -> V_38 . V_165 )
return F_110 ( - V_166 ) ;
if ( ! ( V_7 -> V_46 & V_48 ) )
F_219 ( V_7 ) ;
return V_5 ;
}
void F_223 ( struct V_6 * V_7 , T_3 * V_323 , int V_128 , bool V_324 )
{
struct V_325 * V_326 ;
V_209 V_154 ;
V_209 V_155 ;
int V_158 ;
struct V_4 * V_106 ;
struct V_94 * V_94 = F_37 ( V_7 ) ;
V_326 = (struct V_325 * ) V_323 ;
if ( V_128 < sizeof( struct V_325 ) ) {
F_41 ( ( L_20 ) ) ;
return;
}
V_158 = F_109 ( & V_326 -> V_187 ) ;
if ( V_158 & ( V_160 | V_327 ) )
return;
V_154 = F_224 ( V_326 -> V_328 ) ;
V_155 = F_224 ( V_326 -> V_329 ) ;
if ( V_155 > V_154 ) {
F_225 ( L_21 ) ;
return;
}
V_106 = F_226 ( V_7 ) ;
if ( V_106 == NULL ) {
F_227 ( L_22 ,
V_7 -> V_30 ) ;
return;
}
if ( V_326 -> V_180 ) {
struct V_156 * V_144 ;
unsigned long V_330 ;
if ( V_3 > V_331 )
V_330 = F_137 ( V_154 , V_3 ) ;
else
V_330 = F_137 ( V_154 , V_331 ) ;
if ( F_228 ( V_330 ) )
V_330 *= V_3 ;
V_144 = F_142 ( & V_326 -> V_187 ,
V_326 -> V_172 ,
V_7 ,
V_332 | V_333 ,
V_188 | V_189 ) ;
if ( V_144 ) {
if ( V_154 == 0 ) {
F_143 ( V_144 ) ;
V_144 = NULL ;
} else if ( F_228 ( V_330 ) ) {
F_144 ( V_144 , V_13 + V_330 ) ;
} else {
F_229 ( V_144 ) ;
}
} else if ( V_154 ) {
T_5 V_181 = 0 ;
int V_46 = V_332 | V_333 ;
if ( F_228 ( V_330 ) ) {
V_46 |= V_191 ;
V_181 = F_230 ( V_330 ) ;
}
F_214 ( & V_326 -> V_187 , V_326 -> V_172 ,
V_7 , V_181 , V_46 ) ;
}
F_99 ( V_144 ) ;
}
if ( V_326 -> V_334 && V_106 -> V_38 . V_334 ) {
struct V_9 * V_10 ;
struct V_149 V_147 ;
int V_335 = 0 , V_336 = 0 ;
bool V_173 = false ;
if ( V_326 -> V_172 == 64 ) {
memcpy ( & V_147 , & V_326 -> V_187 , 8 ) ;
if ( ! F_189 ( & V_106 -> V_62 ) ) {
F_164 ( & V_106 -> V_36 ) ;
memcpy ( V_147 . V_204 + 8 ,
V_106 -> V_62 . V_204 + 8 , 8 ) ;
F_169 ( & V_106 -> V_36 ) ;
V_173 = true ;
} else if ( F_184 ( V_147 . V_204 + 8 , V_7 ) &&
F_211 ( V_147 . V_204 + 8 , V_106 ) ) {
F_97 ( V_106 ) ;
return;
}
goto V_337;
}
F_227 ( L_23 ,
V_326 -> V_172 ) ;
F_97 ( V_106 ) ;
return;
V_337:
V_10 = F_177 ( V_94 , & V_147 , V_7 , 1 ) ;
if ( V_10 == NULL && V_154 ) {
int V_201 = V_106 -> V_38 . V_201 ;
T_1 V_202 = 0 ;
#ifdef F_231
if ( V_106 -> V_38 . V_338 &&
! V_94 -> V_16 . V_110 -> V_44 && V_324 )
V_202 = V_215 ;
#endif
if ( ! V_201 ||
F_172 ( V_106 ) < V_201 )
V_10 = F_108 ( V_106 , & V_147 , NULL ,
V_326 -> V_172 ,
V_158 & V_339 ,
V_202 , V_154 ,
V_155 ) ;
if ( F_232 ( V_10 ) ) {
F_97 ( V_106 ) ;
return;
}
V_336 = 0 ;
V_335 = 1 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_173 = V_173 ;
F_150 ( V_10 ) ;
}
if ( V_10 ) {
int V_46 ;
unsigned long V_203 ;
#ifdef F_46
struct V_9 * V_192 ;
#endif
T_1 V_340 ;
F_112 ( & V_10 -> V_36 ) ;
V_203 = V_13 ;
if ( V_10 -> V_154 > ( V_203 - V_10 -> V_66 ) / V_3 )
V_340 = V_10 -> V_154 - ( V_203 - V_10 -> V_66 ) / V_3 ;
else
V_340 = 0 ;
if ( ! V_336 && ! V_335 && V_340 ) {
if ( V_154 > V_341 ||
V_154 > V_340 )
V_336 = 1 ;
else if ( V_340 <= V_341 ) {
if ( V_155 != V_10 -> V_155 ) {
V_154 = V_340 ;
V_336 = 1 ;
}
} else {
V_154 = V_341 ;
if ( V_154 < V_155 )
V_155 = V_154 ;
V_336 = 1 ;
}
}
if ( V_336 ) {
V_10 -> V_154 = V_154 ;
V_10 -> V_155 = V_155 ;
V_10 -> V_66 = V_203 ;
V_46 = V_10 -> V_46 ;
V_10 -> V_46 &= ~ V_232 ;
F_120 ( & V_10 -> V_36 ) ;
if ( ! ( V_46 & V_132 ) )
F_140 ( 0 , V_10 ) ;
} else
F_120 ( & V_10 -> V_36 ) ;
#ifdef F_46
F_164 ( & V_106 -> V_36 ) ;
F_85 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_197 , V_342 , V_343 ;
if ( V_10 != V_192 -> V_182 )
continue;
V_197 = ( V_203 - V_192 -> V_1 ) / V_3 ;
V_342 = V_106 -> V_38 . V_210 - V_197 ;
if ( V_342 < 0 )
V_342 = 0 ;
V_343 = V_106 -> V_38 . V_211 -
V_106 -> V_38 . V_212 -
V_197 ;
if ( V_343 < 0 )
V_343 = 0 ;
if ( V_154 > V_342 )
V_154 = V_342 ;
if ( V_155 > V_343 )
V_155 = V_343 ;
F_112 ( & V_192 -> V_36 ) ;
V_46 = V_192 -> V_46 ;
V_192 -> V_154 = V_154 ;
V_192 -> V_155 = V_155 ;
V_192 -> V_66 = V_203 ;
if ( V_155 > 0 )
V_192 -> V_46 &= ~ V_232 ;
F_120 ( & V_192 -> V_36 ) ;
if ( ! ( V_46 & V_132 ) )
F_140 ( 0 , V_192 ) ;
}
if ( ( V_335 || F_26 ( & V_106 -> V_55 ) ) && V_106 -> V_38 . V_61 > 0 ) {
F_169 ( & V_106 -> V_36 ) ;
F_146 ( V_10 , NULL ) ;
} else {
F_169 ( & V_106 -> V_36 ) ;
}
#endif
F_133 ( V_10 ) ;
F_233 ( 0 ) ;
}
}
F_234 ( V_344 , V_106 , V_326 ) ;
F_97 ( V_106 ) ;
}
int F_235 ( struct V_94 * V_94 , void T_6 * V_345 )
{
struct V_346 V_347 ;
struct V_6 * V_7 ;
int V_95 = - V_108 ;
F_236 () ;
V_95 = - V_348 ;
if ( F_237 ( & V_347 , V_345 , sizeof( struct V_346 ) ) )
goto V_349;
V_7 = F_73 ( V_94 , V_347 . V_350 ) ;
V_95 = - V_163 ;
if ( V_7 == NULL )
goto V_349;
#if F_44 ( V_50 )
if ( V_7 -> type == V_51 ) {
const struct V_351 * V_352 = V_7 -> V_353 ;
struct V_354 V_355 ;
struct V_356 V_137 ;
V_95 = - V_162 ;
if ( ! ( F_109 ( & V_347 . V_357 ) & V_217 ) )
goto V_349;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_358 . V_247 = V_347 . V_357 . V_269 [ 3 ] ;
V_137 . V_358 . V_248 = 0 ;
V_137 . V_358 . V_359 = 4 ;
V_137 . V_358 . V_360 = 5 ;
V_137 . V_358 . V_361 = V_362 ;
V_137 . V_358 . V_363 = 64 ;
V_355 . V_364 . V_365 = ( V_366 void T_6 * ) & V_137 ;
if ( V_352 -> V_367 ) {
T_7 V_368 = F_238 () ;
F_239 ( V_369 ) ;
V_95 = V_352 -> V_367 ( V_7 , & V_355 , V_370 ) ;
F_239 ( V_368 ) ;
} else
V_95 = - V_371 ;
if ( V_95 == 0 ) {
V_95 = - V_96 ;
V_7 = F_240 ( V_94 , V_137 . V_30 ) ;
if ( ! V_7 )
goto V_349;
V_95 = F_241 ( V_7 ) ;
}
}
#endif
V_349:
F_93 () ;
return V_95 ;
}
static int F_242 ( struct V_94 * V_94 , int V_79 , const struct V_149 * V_293 ,
const struct V_149 * V_372 ,
unsigned int V_294 , T_8 V_373 , V_209 V_155 ,
V_209 V_154 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_153 ;
T_1 V_46 ;
T_5 V_181 ;
unsigned long V_374 ;
F_33 () ;
if ( V_294 > 128 )
return - V_108 ;
if ( ! V_154 || V_155 > V_154 )
return - V_108 ;
V_7 = F_73 ( V_94 , V_79 ) ;
if ( ! V_7 )
return - V_163 ;
V_5 = F_222 ( V_7 ) ;
if ( F_115 ( V_5 ) )
return F_116 ( V_5 ) ;
V_153 = F_149 ( V_293 ) ;
V_374 = F_137 ( V_154 , V_3 ) ;
if ( F_228 ( V_374 ) ) {
V_181 = F_230 ( V_374 * V_3 ) ;
V_154 = V_374 ;
V_46 = V_191 ;
} else {
V_181 = 0 ;
V_46 = 0 ;
V_373 |= V_183 ;
}
V_374 = F_137 ( V_155 , V_3 ) ;
if ( F_228 ( V_374 ) ) {
if ( V_374 == 0 )
V_373 |= V_232 ;
V_155 = V_374 ;
}
V_10 = F_108 ( V_5 , V_293 , V_372 , V_294 , V_153 , V_373 ,
V_154 , V_155 ) ;
if ( ! F_115 ( V_10 ) ) {
F_214 ( & V_10 -> V_147 , V_10 -> V_172 , V_7 ,
V_181 , V_46 ) ;
F_150 ( V_10 ) ;
F_133 ( V_10 ) ;
F_233 ( 0 ) ;
return 0 ;
}
return F_116 ( V_10 ) ;
}
static int F_243 ( struct V_94 * V_94 , int V_79 , const struct V_149 * V_293 ,
unsigned int V_294 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_294 > 128 )
return - V_108 ;
V_7 = F_73 ( V_94 , V_79 ) ;
if ( ! V_7 )
return - V_163 ;
if ( ( V_5 = F_52 ( V_7 ) ) == NULL )
return - V_375 ;
F_164 ( & V_5 -> V_36 ) ;
F_85 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_172 == V_294 &&
F_154 ( V_293 , & V_10 -> V_147 ) ) {
F_16 ( V_10 ) ;
F_169 ( & V_5 -> V_36 ) ;
F_127 ( V_10 ) ;
return 0 ;
}
}
F_169 ( & V_5 -> V_36 ) ;
return - V_162 ;
}
int F_244 ( struct V_94 * V_94 , void T_6 * V_345 )
{
struct V_346 V_347 ;
int V_95 ;
if ( ! F_245 ( V_94 -> V_376 , V_377 ) )
return - V_378 ;
if ( F_237 ( & V_347 , V_345 , sizeof( struct V_346 ) ) )
return - V_348 ;
F_236 () ;
V_95 = F_242 ( V_94 , V_347 . V_350 , & V_347 . V_357 , NULL ,
V_347 . V_379 , V_183 ,
V_380 , V_380 ) ;
F_93 () ;
return V_95 ;
}
int F_246 ( struct V_94 * V_94 , void T_6 * V_345 )
{
struct V_346 V_347 ;
int V_95 ;
if ( ! F_245 ( V_94 -> V_376 , V_377 ) )
return - V_378 ;
if ( F_237 ( & V_347 , V_345 , sizeof( struct V_346 ) ) )
return - V_348 ;
F_236 () ;
V_95 = F_243 ( V_94 , V_347 . V_350 , & V_347 . V_357 ,
V_347 . V_379 ) ;
F_93 () ;
return V_95 ;
}
static void F_247 ( struct V_4 * V_5 , const struct V_149 * V_147 ,
int V_294 , int V_153 )
{
struct V_9 * V_10 ;
V_10 = F_108 ( V_5 , V_147 , NULL , V_294 ,
V_153 , V_183 , 0 , 0 ) ;
if ( ! F_115 ( V_10 ) ) {
F_128 ( & V_10 -> V_36 ) ;
V_10 -> V_46 &= ~ V_132 ;
F_129 ( & V_10 -> V_36 ) ;
F_140 ( V_381 , V_10 ) ;
F_133 ( V_10 ) ;
}
}
static void F_248 ( struct V_4 * V_5 )
{
struct V_149 V_147 ;
struct V_6 * V_7 ;
struct V_94 * V_94 = F_37 ( V_5 -> V_7 ) ;
int V_153 ;
F_33 () ;
memset ( & V_147 , 0 , sizeof( struct V_149 ) ) ;
memcpy ( & V_147 . V_269 [ 3 ] , V_5 -> V_7 -> V_274 , 4 ) ;
if ( V_5 -> V_7 -> V_46 & V_311 ) {
V_147 . V_269 [ 0 ] = F_183 ( 0xfe800000 ) ;
V_153 = V_259 ;
} else {
V_153 = V_217 ;
}
if ( V_147 . V_269 [ 3 ] ) {
F_247 ( V_5 , & V_147 , 128 , V_153 ) ;
return;
}
F_89 (net, dev) {
struct V_382 * V_383 = F_249 ( V_7 ) ;
if ( V_383 && ( V_7 -> V_46 & V_72 ) ) {
struct V_384 * V_129 ;
int V_385 = V_153 ;
for ( V_129 = V_383 -> V_386 ; V_129 ; V_129 = V_129 -> V_387 ) {
int V_294 ;
V_147 . V_269 [ 3 ] = V_129 -> V_388 ;
if ( V_129 -> V_389 == V_390 )
continue;
if ( V_129 -> V_389 >= V_391 ) {
if ( V_5 -> V_7 -> V_46 & V_311 )
continue;
V_385 |= V_262 ;
}
if ( V_5 -> V_7 -> V_46 & V_311 )
V_294 = 64 ;
else
V_294 = 96 ;
F_247 ( V_5 , & V_147 , V_294 , V_385 ) ;
}
}
}
}
static void F_250 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_392 ;
struct V_9 * V_393 ;
struct V_156 * V_394 ;
F_33 () ;
if ( ( V_5 = F_51 ( V_7 ) ) == NULL ) {
F_28 ( L_24 , V_29 ) ;
return;
}
F_247 ( V_5 , & V_395 , 128 , V_262 ) ;
F_89 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_392 -> V_30 , V_7 -> V_30 ) )
continue;
V_5 = F_52 ( V_392 ) ;
if ( ! V_5 )
continue;
F_164 ( & V_5 -> V_36 ) ;
F_85 (sp_ifa, &idev->addr_list, if_list) {
if ( V_393 -> V_46 & ( V_265 | V_132 ) )
continue;
if ( V_393 -> V_144 )
continue;
V_394 = F_114 ( V_5 , & V_393 -> V_147 , 0 ) ;
if ( ! F_115 ( V_394 ) ) {
V_393 -> V_144 = V_394 ;
F_251 ( V_394 ) ;
}
}
F_169 ( & V_5 -> V_36 ) ;
}
}
static void F_252 ( struct V_4 * V_5 , const struct V_149 * V_147 )
{
struct V_9 * V_10 ;
T_1 V_202 = V_183 ;
#ifdef F_231
if ( V_5 -> V_38 . V_338 &&
! F_37 ( V_5 -> V_7 ) -> V_16 . V_110 -> V_44 )
V_202 |= V_215 ;
#endif
V_10 = F_108 ( V_5 , V_147 , NULL , 64 , V_259 , V_202 , 0 , 0 ) ;
if ( ! F_115 ( V_10 ) ) {
F_214 ( & V_10 -> V_147 , V_10 -> V_172 , V_5 -> V_7 , 0 , 0 ) ;
F_150 ( V_10 ) ;
F_133 ( V_10 ) ;
}
}
static void F_253 ( struct V_6 * V_7 )
{
struct V_149 V_147 ;
struct V_4 * V_5 ;
F_33 () ;
if ( ( V_7 -> type != V_284 ) &&
( V_7 -> type != V_285 ) &&
( V_7 -> type != V_286 ) &&
( V_7 -> type != V_287 ) &&
( V_7 -> type != V_289 ) &&
( V_7 -> type != V_290 ) ) {
return;
}
V_5 = F_222 ( V_7 ) ;
if ( F_115 ( V_5 ) )
return;
memset ( & V_147 , 0 , sizeof( struct V_149 ) ) ;
V_147 . V_269 [ 0 ] = F_183 ( 0xFE800000 ) ;
if ( F_184 ( V_147 . V_204 + 8 , V_7 ) == 0 )
F_252 ( V_5 , & V_147 ) ;
}
static void F_254 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_33 () ;
if ( ( V_5 = F_51 ( V_7 ) ) == NULL ) {
F_28 ( L_24 , V_29 ) ;
return;
}
if ( V_7 -> V_52 & V_53 ) {
struct V_149 V_147 ;
F_220 ( & V_147 , F_183 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_214 ( & V_147 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_184 ( V_147 . V_204 + 8 , V_7 ) )
F_252 ( V_5 , & V_147 ) ;
return;
}
F_248 ( V_5 ) ;
if ( V_7 -> V_46 & V_311 )
F_219 ( V_7 ) ;
else
F_221 ( V_7 ) ;
}
static void F_255 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_149 V_147 ;
F_33 () ;
if ( ( V_5 = F_51 ( V_7 ) ) == NULL ) {
F_28 ( L_24 , V_29 ) ;
return;
}
F_220 ( & V_147 , F_183 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_214 ( & V_147 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_184 ( V_147 . V_204 + 8 , V_7 ) )
F_252 ( V_5 , & V_147 ) ;
}
static inline int
F_256 ( struct V_4 * V_5 , struct V_6 * V_396 )
{
struct V_149 V_397 ;
if ( ! F_171 ( V_396 , & V_397 , V_132 ) ) {
F_252 ( V_5 , & V_397 ) ;
return 0 ;
}
return - 1 ;
}
static void F_257 ( struct V_4 * V_5 )
{
struct V_6 * V_396 ;
struct V_94 * V_94 = F_37 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_398 &&
( V_396 = F_73 ( V_94 , V_5 -> V_7 -> V_398 ) ) ) {
if ( ! F_256 ( V_5 , V_396 ) )
return;
}
F_89 (net, link_dev) {
if ( ! F_256 ( V_5 , V_396 ) )
return;
}
F_28 ( L_25 ) ;
}
static void F_258 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_33 () ;
V_5 = F_222 ( V_7 ) ;
if ( F_115 ( V_5 ) ) {
F_28 ( L_26 ) ;
return;
}
F_257 ( V_5 ) ;
}
static int F_259 ( struct V_399 * V_400 , unsigned long V_84 ,
void * V_401 )
{
struct V_6 * V_7 = F_260 ( V_401 ) ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_402 = 0 ;
int V_95 ;
switch ( V_84 ) {
case V_403 :
if ( ! V_5 && V_7 -> V_34 >= V_35 ) {
V_5 = F_32 ( V_7 ) ;
if ( ! V_5 )
return F_261 ( - V_26 ) ;
}
break;
case V_177 :
case V_404 :
if ( V_7 -> V_46 & V_405 )
break;
if ( V_84 == V_177 ) {
if ( ! F_4 ( V_7 ) ) {
F_45 ( L_27 ,
V_7 -> V_30 ) ;
break;
}
if ( ! V_5 && V_7 -> V_34 >= V_35 )
V_5 = F_32 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_64 |= V_65 ;
V_402 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_64 & V_65 )
break;
V_5 -> V_64 |= V_65 ;
}
F_45 ( L_28 ,
V_7 -> V_30 ) ;
V_402 = 1 ;
}
switch ( V_7 -> type ) {
#if F_44 ( V_50 )
case V_51 :
F_254 ( V_7 ) ;
break;
#endif
#if F_44 ( V_406 )
case V_288 :
F_255 ( V_7 ) ;
break;
#endif
case V_59 :
F_258 ( V_7 ) ;
break;
case V_407 :
F_250 ( V_7 ) ;
break;
default:
F_253 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_402 )
F_262 ( V_5 ) ;
if ( V_5 -> V_38 . V_40 != V_7 -> V_34 &&
V_7 -> V_34 >= V_35 ) {
F_263 ( V_7 , V_7 -> V_34 ) ;
V_5 -> V_38 . V_40 = V_7 -> V_34 ;
}
V_5 -> V_66 = V_13 ;
F_264 ( V_408 , V_5 ) ;
if ( V_7 -> V_34 < V_35 )
F_265 ( V_7 , 1 ) ;
}
break;
case V_409 :
if ( V_5 && V_7 -> V_34 >= V_35 ) {
F_263 ( V_7 , V_7 -> V_34 ) ;
V_5 -> V_38 . V_40 = V_7 -> V_34 ;
break;
}
if ( ! V_5 && V_7 -> V_34 >= V_35 ) {
V_5 = F_32 ( V_7 ) ;
if ( V_5 )
break;
}
case V_186 :
case V_410 :
F_265 ( V_7 , V_84 != V_186 ) ;
break;
case V_411 :
if ( V_5 ) {
F_266 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_95 = F_43 ( V_5 ) ;
if ( V_95 )
return F_261 ( V_95 ) ;
}
break;
case V_412 :
case V_413 :
F_267 ( V_7 , V_84 ) ;
break;
}
return V_414 ;
}
static void F_267 ( struct V_6 * V_7 , unsigned long V_84 )
{
struct V_4 * V_5 ;
F_33 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_84 == V_413 )
F_268 ( V_5 ) ;
else if ( V_84 == V_412 )
F_269 ( V_5 ) ;
}
static int F_265 ( struct V_6 * V_7 , int V_415 )
{
struct V_94 * V_94 = F_37 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_129 ;
int V_142 , V_222 ;
F_33 () ;
F_270 ( V_94 , V_7 ) ;
F_271 ( & V_43 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 == NULL )
return - V_163 ;
if ( V_415 ) {
V_5 -> V_31 = 1 ;
F_272 ( V_7 -> V_67 , NULL ) ;
F_266 ( V_5 ) ;
}
for ( V_222 = 0 ; V_222 < V_416 ; V_222 ++ ) {
struct V_119 * V_115 = & V_174 [ V_222 ] ;
F_128 ( & V_167 ) ;
V_417:
F_79 (ifa, h, addr_lst) {
if ( V_129 -> V_5 == V_5 ) {
F_130 ( & V_129 -> V_141 ) ;
F_9 ( V_129 ) ;
goto V_417;
}
}
F_129 ( & V_167 ) ;
}
F_131 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_415 )
V_5 -> V_64 &= ~ ( V_418 | V_419 | V_65 ) ;
#ifdef F_46
if ( V_415 && F_7 ( & V_5 -> V_56 ) )
F_97 ( V_5 ) ;
while ( ! F_26 ( & V_5 -> V_55 ) ) {
V_129 = F_273 ( & V_5 -> V_55 ,
struct V_9 , V_176 ) ;
F_132 ( & V_129 -> V_176 ) ;
F_139 ( & V_5 -> V_36 ) ;
F_128 ( & V_129 -> V_36 ) ;
if ( V_129 -> V_182 ) {
F_133 ( V_129 -> V_182 ) ;
V_129 -> V_182 = NULL ;
}
F_129 ( & V_129 -> V_36 ) ;
F_133 ( V_129 ) ;
F_131 ( & V_5 -> V_36 ) ;
}
#endif
while ( ! F_26 ( & V_5 -> V_27 ) ) {
V_129 = F_273 ( & V_5 -> V_27 ,
struct V_9 , V_148 ) ;
F_9 ( V_129 ) ;
F_132 ( & V_129 -> V_148 ) ;
F_139 ( & V_5 -> V_36 ) ;
F_128 ( & V_129 -> V_170 ) ;
V_142 = V_129 -> V_142 ;
V_129 -> V_142 = V_143 ;
F_129 ( & V_129 -> V_170 ) ;
if ( V_142 != V_143 ) {
F_274 ( V_185 , V_129 ) ;
F_126 ( V_186 , V_129 ) ;
}
F_133 ( V_129 ) ;
F_131 ( & V_5 -> V_36 ) ;
}
F_139 ( & V_5 -> V_36 ) ;
if ( V_415 )
F_275 ( V_5 ) ;
else
F_276 ( V_5 ) ;
V_5 -> V_66 = V_13 ;
if ( V_415 ) {
F_3 ( V_5 ) ;
F_42 ( & V_43 , V_5 -> V_42 ) ;
F_271 ( & V_43 , V_7 ) ;
F_97 ( V_5 ) ;
}
return 0 ;
}
static void V_37 ( unsigned long V_292 )
{
struct V_4 * V_5 = (struct V_4 * ) V_292 ;
struct V_149 V_397 ;
F_121 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_31 || ! ( V_5 -> V_64 & V_65 ) )
goto V_169;
if ( ! F_277 ( V_5 ) )
goto V_169;
if ( V_5 -> V_64 & V_419 )
goto V_169;
if ( V_5 -> V_420 ++ < V_5 -> V_38 . V_54 ) {
if ( ! F_170 ( V_5 , & V_397 , V_132 ) )
F_278 ( V_5 -> V_7 , & V_397 ,
& V_71 ) ;
else
goto V_169;
F_11 ( V_5 , ( V_5 -> V_420 ==
V_5 -> V_38 . V_54 ) ?
V_5 -> V_38 . V_421 :
V_5 -> V_38 . V_422 ) ;
} else {
F_28 ( L_29 , V_5 -> V_7 -> V_30 ) ;
}
V_169:
F_123 ( & V_5 -> V_36 ) ;
F_97 ( V_5 ) ;
}
static void F_279 ( struct V_9 * V_10 )
{
unsigned long V_423 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_46 & V_215 )
V_423 = 0 ;
else
V_423 = F_280 () % ( V_5 -> V_38 . V_421 ? : 1 ) ;
V_10 -> V_424 = V_5 -> V_38 . V_213 ;
F_15 ( V_10 , V_423 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_185 ( V_7 , & V_10 -> V_147 ) ;
F_281 ( V_10 -> V_147 . V_269 [ 3 ] ) ;
F_164 ( & V_5 -> V_36 ) ;
F_112 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_142 == V_143 )
goto V_169;
if ( V_7 -> V_46 & ( V_47 | V_48 ) ||
V_5 -> V_38 . V_49 < 1 ||
! ( V_10 -> V_46 & V_132 ) ||
V_10 -> V_46 & V_425 ) {
V_10 -> V_46 &= ~ ( V_132 | V_215 | V_265 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_169 ( & V_5 -> V_36 ) ;
F_282 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_64 & V_65 ) ) {
F_120 ( & V_10 -> V_36 ) ;
F_169 ( & V_5 -> V_36 ) ;
F_16 ( V_10 ) ;
F_179 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_46 & V_215 )
F_251 ( V_10 -> V_144 ) ;
F_279 ( V_10 ) ;
V_169:
F_120 ( & V_10 -> V_36 ) ;
F_169 ( & V_5 -> V_36 ) ;
}
static void V_171 ( unsigned long V_292 )
{
struct V_9 * V_10 = (struct V_9 * ) V_292 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_149 V_426 ;
if ( ! V_10 -> V_424 && F_180 ( V_10 ) )
goto V_169;
F_121 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_31 || ! ( V_5 -> V_64 & V_65 ) ) {
F_123 ( & V_5 -> V_36 ) ;
goto V_169;
}
F_112 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_142 == V_143 ) {
F_120 ( & V_10 -> V_36 ) ;
F_123 ( & V_5 -> V_36 ) ;
goto V_169;
}
if ( V_10 -> V_424 == 0 ) {
V_10 -> V_46 &= ~ ( V_132 | V_215 | V_265 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_123 ( & V_5 -> V_36 ) ;
F_282 ( V_10 ) ;
goto V_169;
}
V_10 -> V_424 -- ;
F_15 ( V_10 , V_10 -> V_5 -> V_42 -> V_214 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_123 ( & V_5 -> V_36 ) ;
F_186 ( & V_10 -> V_147 , & V_426 ) ;
F_283 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_147 , & V_426 , & V_63 ) ;
V_169:
F_133 ( V_10 ) ;
}
static void F_282 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_149 V_397 ;
bool V_427 , V_428 ;
F_9 ( V_10 ) ;
F_140 ( V_381 , V_10 ) ;
F_164 ( & V_10 -> V_5 -> V_36 ) ;
F_112 ( & V_10 -> V_36 ) ;
V_428 = F_109 ( & V_10 -> V_147 ) & V_327 &&
V_10 -> V_5 -> V_429 == 1 ;
V_427 = V_428 &&
F_277 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_38 . V_54 > 0 &&
( V_7 -> V_46 & V_48 ) == 0 ;
F_120 ( & V_10 -> V_36 ) ;
F_169 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_428 )
F_284 ( V_10 -> V_5 ) ;
if ( V_427 ) {
if ( F_171 ( V_7 , & V_397 , V_132 ) )
return;
F_278 ( V_7 , & V_397 , & V_71 ) ;
F_131 ( & V_10 -> V_5 -> V_36 ) ;
F_112 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_420 = 1 ;
V_10 -> V_5 -> V_64 |= V_418 ;
F_11 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_38 . V_422 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_139 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_36 ) ;
F_85 (ifp, &idev->addr_list, if_list) {
F_112 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_46 & V_132 &&
V_10 -> V_142 == V_267 )
F_279 ( V_10 ) ;
F_120 ( & V_10 -> V_36 ) ;
}
F_169 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_285 ( struct V_430 * V_83 , T_9 V_431 )
{
struct V_9 * V_129 = NULL ;
struct V_432 * V_142 = V_83 -> V_433 ;
struct V_94 * V_94 = F_286 ( V_83 ) ;
int V_137 = 0 ;
if ( V_431 == 0 ) {
V_142 -> V_434 = 0 ;
V_142 -> V_435 = 0 ;
}
for (; V_142 -> V_434 < V_416 ; ++ V_142 -> V_434 ) {
F_178 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_174 ( F_37 ( V_129 -> V_5 -> V_7 ) , V_94 ) )
continue;
if ( V_137 < V_142 -> V_435 ) {
V_137 ++ ;
continue;
}
V_142 -> V_435 ++ ;
return V_129 ;
}
V_142 -> V_435 = 0 ;
V_137 = 0 ;
}
return NULL ;
}
static struct V_9 * F_287 ( struct V_430 * V_83 ,
struct V_9 * V_129 )
{
struct V_432 * V_142 = V_83 -> V_433 ;
struct V_94 * V_94 = F_286 ( V_83 ) ;
F_288 (ifa, addr_lst) {
if ( ! F_174 ( F_37 ( V_129 -> V_5 -> V_7 ) , V_94 ) )
continue;
V_142 -> V_435 ++ ;
return V_129 ;
}
while ( ++ V_142 -> V_434 < V_416 ) {
V_142 -> V_435 = 0 ;
F_178 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_174 ( F_37 ( V_129 -> V_5 -> V_7 ) , V_94 ) )
continue;
V_142 -> V_435 ++ ;
return V_129 ;
}
}
return NULL ;
}
static void * F_289 ( struct V_430 * V_83 , T_9 * V_431 )
__acquires( T_10 )
{
F_111 () ;
return F_285 ( V_83 , * V_431 ) ;
}
static void * F_290 ( struct V_430 * V_83 , void * V_436 , T_9 * V_431 )
{
struct V_9 * V_129 ;
V_129 = F_287 ( V_83 , V_436 ) ;
++ * V_431 ;
return V_129 ;
}
static void F_291 ( struct V_430 * V_83 , void * V_436 )
__releases( T_10 )
{
F_124 () ;
}
static int F_292 ( struct V_430 * V_83 , void * V_436 )
{
struct V_9 * V_10 = (struct V_9 * ) V_436 ;
F_293 ( V_83 , L_30 ,
& V_10 -> V_147 ,
V_10 -> V_5 -> V_7 -> V_79 ,
V_10 -> V_172 ,
V_10 -> V_153 ,
V_10 -> V_46 ,
V_10 -> V_5 -> V_7 -> V_30 ) ;
return 0 ;
}
static int F_294 ( struct V_437 * V_437 , struct V_438 * V_438 )
{
return F_295 ( V_437 , V_438 , & V_439 ,
sizeof( struct V_432 ) ) ;
}
static int T_11 F_296 ( struct V_94 * V_94 )
{
if ( ! F_297 ( L_31 , V_440 , V_94 -> V_441 , & V_442 ) )
return - V_26 ;
return 0 ;
}
static void T_12 F_298 ( struct V_94 * V_94 )
{
F_299 ( L_31 , V_94 -> V_441 ) ;
}
int T_13 F_300 ( void )
{
return F_301 ( & V_443 ) ;
}
void F_302 ( void )
{
F_303 ( & V_443 ) ;
}
int F_304 ( struct V_94 * V_94 , const struct V_149 * V_147 )
{
int V_200 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_157 = F_105 ( V_147 ) ;
F_111 () ;
F_178 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_37 ( V_10 -> V_5 -> V_7 ) , V_94 ) )
continue;
if ( F_154 ( & V_10 -> V_147 , V_147 ) &&
( V_10 -> V_46 & V_237 ) ) {
V_200 = 1 ;
break;
}
}
F_124 () ;
return V_200 ;
}
static void F_233 ( unsigned long V_444 )
{
unsigned long V_203 , V_445 , V_446 , V_447 ;
struct V_9 * V_10 ;
int V_222 ;
F_111 () ;
F_112 ( & V_448 ) ;
V_203 = V_13 ;
V_445 = F_305 ( V_203 + V_449 ) ;
F_7 ( & V_450 ) ;
for ( V_222 = 0 ; V_222 < V_416 ; V_222 ++ ) {
V_417:
F_178 (ifp,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_197 ;
if ( V_10 -> V_46 & V_183 )
continue;
F_112 ( & V_10 -> V_36 ) ;
V_197 = ( V_203 - V_10 -> V_66 + V_451 ) / V_3 ;
if ( V_10 -> V_154 != V_380 &&
V_197 >= V_10 -> V_154 ) {
F_120 ( & V_10 -> V_36 ) ;
F_16 ( V_10 ) ;
F_127 ( V_10 ) ;
goto V_417;
} else if ( V_10 -> V_155 == V_380 ) {
F_120 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_197 >= V_10 -> V_155 ) {
int V_452 = 0 ;
if ( ! ( V_10 -> V_46 & V_232 ) ) {
V_452 = 1 ;
V_10 -> V_46 |= V_232 ;
}
if ( F_138 ( V_10 -> V_66 + V_10 -> V_154 * V_3 , V_445 ) )
V_445 = V_10 -> V_66 + V_10 -> V_154 * V_3 ;
F_120 ( & V_10 -> V_36 ) ;
if ( V_452 ) {
F_16 ( V_10 ) ;
F_140 ( 0 , V_10 ) ;
F_133 ( V_10 ) ;
goto V_417;
}
#ifdef F_46
} else if ( ( V_10 -> V_46 & V_175 ) &&
! ( V_10 -> V_46 & V_132 ) ) {
unsigned long V_198 = V_10 -> V_5 -> V_38 . V_207 *
V_10 -> V_5 -> V_38 . V_213 *
V_10 -> V_5 -> V_42 -> V_214 / V_3 ;
if ( V_197 >= V_10 -> V_155 - V_198 ) {
struct V_9 * V_182 = V_10 -> V_182 ;
if ( F_138 ( V_10 -> V_66 + V_10 -> V_155 * V_3 , V_445 ) )
V_445 = V_10 -> V_66 + V_10 -> V_155 * V_3 ;
if ( ! V_10 -> V_206 && V_182 ) {
V_10 -> V_206 ++ ;
F_16 ( V_10 ) ;
F_16 ( V_182 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_112 ( & V_182 -> V_36 ) ;
V_182 -> V_206 = 0 ;
F_120 ( & V_182 -> V_36 ) ;
F_146 ( V_182 , V_10 ) ;
F_133 ( V_182 ) ;
F_133 ( V_10 ) ;
goto V_417;
}
} else if ( F_138 ( V_10 -> V_66 + V_10 -> V_155 * V_3 - V_198 * V_3 , V_445 ) )
V_445 = V_10 -> V_66 + V_10 -> V_155 * V_3 - V_198 * V_3 ;
F_120 ( & V_10 -> V_36 ) ;
#endif
} else {
if ( F_138 ( V_10 -> V_66 + V_10 -> V_155 * V_3 , V_445 ) )
V_445 = V_10 -> V_66 + V_10 -> V_155 * V_3 ;
F_120 ( & V_10 -> V_36 ) ;
}
}
}
V_446 = F_305 ( V_445 ) ;
V_447 = V_445 ;
if ( F_138 ( V_446 , V_445 + V_453 ) )
V_447 = V_446 ;
if ( F_138 ( V_447 , V_13 + V_454 ) )
V_447 = V_13 + V_454 ;
F_41 ( ( V_253 L_32 ,
V_203 , V_445 , V_446 , V_447 ) ) ;
V_450 . V_181 = V_447 ;
F_306 ( & V_450 ) ;
F_120 ( & V_448 ) ;
F_124 () ;
}
static struct V_149 * F_307 ( struct V_103 * V_147 , struct V_103 * V_455 ,
struct V_149 * * V_372 )
{
struct V_149 * V_293 = NULL ;
* V_372 = NULL ;
if ( V_147 )
V_293 = F_308 ( V_147 ) ;
if ( V_455 ) {
if ( V_293 && F_309 ( V_455 , V_293 , sizeof( * V_293 ) ) )
* V_372 = V_293 ;
V_293 = F_308 ( V_455 ) ;
}
return V_293 ;
}
static int
F_310 ( struct V_77 * V_78 , struct V_85 * V_86 )
{
struct V_94 * V_94 = F_70 ( V_78 -> V_102 ) ;
struct V_456 * V_457 ;
struct V_103 * V_104 [ V_458 + 1 ] ;
struct V_149 * V_293 , * V_372 ;
int V_95 ;
V_95 = F_71 ( V_86 , sizeof( * V_457 ) , V_104 , V_458 , V_459 ) ;
if ( V_95 < 0 )
return V_95 ;
V_457 = F_60 ( V_86 ) ;
V_293 = F_307 ( V_104 [ V_460 ] , V_104 [ V_461 ] , & V_372 ) ;
if ( V_293 == NULL )
return - V_108 ;
return F_243 ( V_94 , V_457 -> V_462 , V_293 , V_457 -> V_463 ) ;
}
static int F_311 ( struct V_9 * V_10 , T_3 V_373 ,
T_1 V_155 , T_1 V_154 )
{
T_1 V_46 ;
T_5 V_181 ;
unsigned long V_374 ;
if ( ! V_154 || ( V_155 > V_154 ) )
return - V_108 ;
V_374 = F_137 ( V_154 , V_3 ) ;
if ( F_228 ( V_374 ) ) {
V_181 = F_230 ( V_374 * V_3 ) ;
V_154 = V_374 ;
V_46 = V_191 ;
} else {
V_181 = 0 ;
V_46 = 0 ;
V_373 |= V_183 ;
}
V_374 = F_137 ( V_155 , V_3 ) ;
if ( F_228 ( V_374 ) ) {
if ( V_374 == 0 )
V_373 |= V_232 ;
V_155 = V_374 ;
}
F_128 ( & V_10 -> V_36 ) ;
V_10 -> V_46 = ( V_10 -> V_46 & ~ ( V_232 | V_183 | V_425 | V_237 ) ) | V_373 ;
V_10 -> V_66 = V_13 ;
V_10 -> V_154 = V_154 ;
V_10 -> V_155 = V_155 ;
F_129 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_46 & V_132 ) )
F_140 ( 0 , V_10 ) ;
F_214 ( & V_10 -> V_147 , V_10 -> V_172 , V_10 -> V_5 -> V_7 ,
V_181 , V_46 ) ;
F_233 ( 0 ) ;
return 0 ;
}
static int
F_312 ( struct V_77 * V_78 , struct V_85 * V_86 )
{
struct V_94 * V_94 = F_70 ( V_78 -> V_102 ) ;
struct V_456 * V_457 ;
struct V_103 * V_104 [ V_458 + 1 ] ;
struct V_149 * V_293 , * V_372 ;
struct V_9 * V_129 ;
struct V_6 * V_7 ;
T_1 V_154 = V_380 , V_464 = V_380 ;
T_3 V_373 ;
int V_95 ;
V_95 = F_71 ( V_86 , sizeof( * V_457 ) , V_104 , V_458 , V_459 ) ;
if ( V_95 < 0 )
return V_95 ;
V_457 = F_60 ( V_86 ) ;
V_293 = F_307 ( V_104 [ V_460 ] , V_104 [ V_461 ] , & V_372 ) ;
if ( V_293 == NULL )
return - V_108 ;
if ( V_104 [ V_465 ] ) {
struct V_466 * V_467 ;
V_467 = F_308 ( V_104 [ V_465 ] ) ;
V_154 = V_467 -> V_468 ;
V_464 = V_467 -> V_469 ;
} else {
V_464 = V_380 ;
V_154 = V_380 ;
}
V_7 = F_73 ( V_94 , V_457 -> V_462 ) ;
if ( V_7 == NULL )
return - V_163 ;
V_373 = V_457 -> V_373 & ( V_425 | V_237 ) ;
V_129 = F_177 ( V_94 , V_293 , V_7 , 1 ) ;
if ( V_129 == NULL ) {
return F_242 ( V_94 , V_457 -> V_462 , V_293 , V_372 ,
V_457 -> V_463 , V_373 ,
V_464 , V_154 ) ;
}
if ( V_86 -> V_470 & V_471 ||
! ( V_86 -> V_470 & V_472 ) )
V_95 = - V_168 ;
else
V_95 = F_311 ( V_129 , V_373 , V_464 , V_154 ) ;
F_133 ( V_129 ) ;
return V_95 ;
}
static void F_313 ( struct V_85 * V_86 , T_3 V_473 , T_3 V_46 ,
T_3 V_153 , int V_79 )
{
struct V_456 * V_457 ;
V_457 = F_60 ( V_86 ) ;
V_457 -> V_474 = V_90 ;
V_457 -> V_463 = V_473 ;
V_457 -> V_373 = V_46 ;
V_457 -> V_389 = V_153 ;
V_457 -> V_462 = V_79 ;
}
static int F_314 ( struct V_77 * V_78 , unsigned long V_1 ,
unsigned long V_66 , T_1 V_475 , T_1 V_328 )
{
struct V_466 V_467 ;
V_467 . V_1 = F_1 ( V_1 ) ;
V_467 . V_66 = F_1 ( V_66 ) ;
V_467 . V_469 = V_475 ;
V_467 . V_468 = V_328 ;
return F_315 ( V_78 , V_465 , sizeof( V_467 ) , & V_467 ) ;
}
static inline int F_316 ( int V_389 )
{
if ( V_389 & V_262 )
return V_391 ;
else if ( V_389 & V_259 )
return V_390 ;
else if ( V_389 & V_476 )
return V_477 ;
else
return V_478 ;
}
static inline int F_317 ( void )
{
return F_55 ( sizeof( struct V_456 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_466 ) ) ;
}
static int F_318 ( struct V_77 * V_78 , struct V_9 * V_129 ,
T_1 V_82 , T_1 V_83 , int V_84 , unsigned int V_46 )
{
struct V_85 * V_86 ;
T_1 V_475 , V_328 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( struct V_456 ) , V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
F_313 ( V_86 , V_129 -> V_172 , V_129 -> V_46 , F_316 ( V_129 -> V_153 ) ,
V_129 -> V_5 -> V_7 -> V_79 ) ;
if ( ! ( V_129 -> V_46 & V_183 ) ) {
V_475 = V_129 -> V_155 ;
V_328 = V_129 -> V_154 ;
if ( V_475 != V_380 ) {
long V_479 = ( V_13 - V_129 -> V_66 ) / V_3 ;
if ( V_475 > V_479 )
V_475 -= V_479 ;
else
V_475 = 0 ;
if ( V_328 != V_380 ) {
if ( V_328 > V_479 )
V_328 -= V_479 ;
else
V_328 = 0 ;
}
}
} else {
V_475 = V_380 ;
V_328 = V_380 ;
}
if ( ! F_189 ( & V_129 -> V_151 ) ) {
if ( F_315 ( V_78 , V_461 , 16 , & V_129 -> V_147 ) < 0 ||
F_315 ( V_78 , V_460 , 16 , & V_129 -> V_151 ) < 0 )
goto error;
} else
if ( F_315 ( V_78 , V_460 , 16 , & V_129 -> V_147 ) < 0 )
goto error;
if ( F_314 ( V_78 , V_129 -> V_1 , V_129 -> V_66 , V_475 , V_328 ) < 0 )
goto error;
return F_62 ( V_78 , V_86 ) ;
error:
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
static int F_319 ( struct V_77 * V_78 , struct V_480 * V_481 ,
T_1 V_82 , T_1 V_83 , int V_84 , T_14 V_46 )
{
struct V_85 * V_86 ;
T_3 V_153 = V_478 ;
int V_79 = V_481 -> V_5 -> V_7 -> V_79 ;
if ( F_149 ( & V_481 -> V_482 ) & V_476 )
V_153 = V_477 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( struct V_456 ) , V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
F_313 ( V_86 , 128 , V_183 , V_153 , V_79 ) ;
if ( F_315 ( V_78 , V_483 , 16 , & V_481 -> V_482 ) < 0 ||
F_314 ( V_78 , V_481 -> V_484 , V_481 -> V_485 ,
V_380 , V_380 ) < 0 ) {
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
return F_62 ( V_78 , V_86 ) ;
}
static int F_320 ( struct V_77 * V_78 , struct V_486 * V_487 ,
T_1 V_82 , T_1 V_83 , int V_84 , unsigned int V_46 )
{
struct V_85 * V_86 ;
T_3 V_153 = V_478 ;
int V_79 = V_487 -> V_488 -> V_7 -> V_79 ;
if ( F_149 ( & V_487 -> V_489 ) & V_476 )
V_153 = V_477 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( struct V_456 ) , V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
F_313 ( V_86 , 128 , V_183 , V_153 , V_79 ) ;
if ( F_315 ( V_78 , V_490 , 16 , & V_487 -> V_489 ) < 0 ||
F_314 ( V_78 , V_487 -> V_491 , V_487 -> V_492 ,
V_380 , V_380 ) < 0 ) {
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
return F_62 ( V_78 , V_86 ) ;
}
static int F_321 ( struct V_4 * V_5 , struct V_77 * V_78 ,
struct V_113 * V_114 , enum V_493 type ,
int V_494 , int * V_495 )
{
struct V_480 * V_481 ;
struct V_486 * V_487 ;
int V_95 = 1 ;
int V_496 = * V_495 ;
F_164 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_497 : {
struct V_9 * V_129 ;
F_85 (ifa, &idev->addr_list, if_list) {
if ( ++ V_496 < V_494 )
continue;
V_95 = F_318 ( V_78 , V_129 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_381 ,
V_126 ) ;
if ( V_95 <= 0 )
break;
F_81 ( V_114 , F_82 ( V_78 ) ) ;
}
break;
}
case V_498 :
for ( V_481 = V_5 -> V_28 ; V_481 ;
V_481 = V_481 -> V_445 , V_496 ++ ) {
if ( V_496 < V_494 )
continue;
V_95 = F_319 ( V_78 , V_481 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_499 ,
V_126 ) ;
if ( V_95 <= 0 )
break;
}
break;
case V_500 :
for ( V_487 = V_5 -> V_501 ; V_487 ;
V_487 = V_487 -> V_502 , V_496 ++ ) {
if ( V_496 < V_494 )
continue;
V_95 = F_320 ( V_78 , V_487 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_503 ,
V_126 ) ;
if ( V_95 <= 0 )
break;
}
break;
default:
break;
}
F_169 ( & V_5 -> V_36 ) ;
* V_495 = V_496 ;
return V_95 ;
}
static int F_322 ( struct V_77 * V_78 , struct V_113 * V_114 ,
enum V_493 type )
{
struct V_94 * V_94 = F_70 ( V_78 -> V_102 ) ;
int V_115 , V_116 ;
int V_117 , V_496 ;
int V_118 , V_494 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_119 * V_120 ;
V_116 = V_114 -> args [ 0 ] ;
V_118 = V_117 = V_114 -> args [ 1 ] ;
V_494 = V_496 = V_114 -> args [ 2 ] ;
F_77 () ;
V_114 -> V_83 = F_78 ( & V_94 -> V_16 . V_123 ) ^ V_94 -> V_124 ;
for ( V_115 = V_116 ; V_115 < V_121 ; V_115 ++ , V_118 = 0 ) {
V_117 = 0 ;
V_120 = & V_94 -> V_122 [ V_115 ] ;
F_79 (dev, head, index_hlist) {
if ( V_117 < V_118 )
goto V_125;
if ( V_115 > V_116 || V_117 > V_118 )
V_494 = 0 ;
V_496 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_125;
if ( F_321 ( V_5 , V_78 , V_114 , type ,
V_494 , & V_496 ) <= 0 )
goto V_127;
V_125:
V_117 ++ ;
}
}
V_127:
F_80 () ;
V_114 -> args [ 0 ] = V_115 ;
V_114 -> args [ 1 ] = V_117 ;
V_114 -> args [ 2 ] = V_496 ;
return V_78 -> V_128 ;
}
static int F_323 ( struct V_77 * V_78 , struct V_113 * V_114 )
{
enum V_493 type = V_497 ;
return F_322 ( V_78 , V_114 , type ) ;
}
static int F_324 ( struct V_77 * V_78 , struct V_113 * V_114 )
{
enum V_493 type = V_498 ;
return F_322 ( V_78 , V_114 , type ) ;
}
static int F_325 ( struct V_77 * V_78 , struct V_113 * V_114 )
{
enum V_493 type = V_500 ;
return F_322 ( V_78 , V_114 , type ) ;
}
static int F_326 ( struct V_77 * V_101 , struct V_85 * V_86 )
{
struct V_94 * V_94 = F_70 ( V_101 -> V_102 ) ;
struct V_456 * V_457 ;
struct V_103 * V_104 [ V_458 + 1 ] ;
struct V_149 * V_147 = NULL , * V_504 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_129 ;
struct V_77 * V_78 ;
int V_95 ;
V_95 = F_71 ( V_86 , sizeof( * V_457 ) , V_104 , V_458 , V_459 ) ;
if ( V_95 < 0 )
goto V_98;
V_147 = F_307 ( V_104 [ V_460 ] , V_104 [ V_461 ] , & V_504 ) ;
if ( V_147 == NULL ) {
V_95 = - V_108 ;
goto V_98;
}
V_457 = F_60 ( V_86 ) ;
if ( V_457 -> V_462 )
V_7 = F_73 ( V_94 , V_457 -> V_462 ) ;
V_129 = F_177 ( V_94 , V_147 , V_7 , 1 ) ;
if ( ! V_129 ) {
V_95 = - V_162 ;
goto V_98;
}
V_78 = F_65 ( F_317 () , V_21 ) ;
if ( ! V_78 ) {
V_95 = - V_96 ;
goto V_505;
}
V_95 = F_318 ( V_78 , V_129 , F_74 ( V_101 ) . V_82 ,
V_86 -> V_112 , V_381 , 0 ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_505;
}
V_95 = F_75 ( V_78 , V_94 , F_74 ( V_101 ) . V_82 ) ;
V_505:
F_133 ( V_129 ) ;
V_98:
return V_95 ;
}
static void F_327 ( int V_84 , struct V_9 * V_129 )
{
struct V_77 * V_78 ;
struct V_94 * V_94 = F_37 ( V_129 -> V_5 -> V_7 ) ;
int V_95 = - V_96 ;
V_78 = F_65 ( F_317 () , V_97 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_318 ( V_78 , V_129 , 0 , 0 , V_84 , 0 ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_98;
}
F_67 ( V_78 , V_94 , 0 , V_506 , NULL , V_97 ) ;
return;
V_98:
if ( V_95 < 0 )
F_68 ( V_94 , V_506 , V_95 ) ;
}
static inline void F_328 ( struct V_80 * V_38 ,
T_2 * V_507 , int V_508 )
{
F_329 ( V_508 < ( V_509 * 4 ) ) ;
memset ( V_507 , 0 , V_508 ) ;
V_507 [ V_510 ] = V_38 -> V_44 ;
V_507 [ V_511 ] = V_38 -> V_512 ;
V_507 [ V_513 ] = V_38 -> V_40 ;
V_507 [ V_514 ] = V_38 -> V_515 ;
V_507 [ V_516 ] = V_38 -> V_517 ;
V_507 [ V_518 ] = V_38 -> V_334 ;
V_507 [ V_519 ] = V_38 -> V_213 ;
V_507 [ V_520 ] = V_38 -> V_54 ;
V_507 [ V_521 ] =
F_330 ( V_38 -> V_422 ) ;
V_507 [ V_522 ] =
F_330 ( V_38 -> V_421 ) ;
V_507 [ V_523 ] = V_38 -> V_524 ;
#ifdef F_46
V_507 [ V_525 ] = V_38 -> V_61 ;
V_507 [ V_526 ] = V_38 -> V_210 ;
V_507 [ V_527 ] = V_38 -> V_211 ;
V_507 [ V_528 ] = V_38 -> V_207 ;
V_507 [ V_529 ] = V_38 -> V_212 ;
#endif
V_507 [ V_530 ] = V_38 -> V_201 ;
V_507 [ V_531 ] = V_38 -> V_532 ;
V_507 [ V_533 ] = V_38 -> V_534 ;
#ifdef F_331
V_507 [ V_535 ] = V_38 -> V_536 ;
V_507 [ V_537 ] =
F_330 ( V_38 -> V_538 ) ;
#ifdef F_332
V_507 [ V_539 ] = V_38 -> V_540 ;
#endif
#endif
V_507 [ V_541 ] = V_38 -> V_542 ;
V_507 [ V_543 ] = V_38 -> V_544 ;
#ifdef F_231
V_507 [ V_545 ] = V_38 -> V_338 ;
#endif
#ifdef F_57
V_507 [ V_546 ] = V_38 -> V_93 ;
#endif
V_507 [ V_547 ] = V_38 -> V_165 ;
V_507 [ V_548 ] = V_38 -> V_49 ;
V_507 [ V_549 ] = V_38 -> V_550 ;
V_507 [ V_551 ] = V_38 -> V_552 ;
}
static inline T_15 F_333 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_553 ) )
+ F_56 ( V_509 * 4 )
+ F_56 ( V_554 * 8 )
+ F_56 ( V_555 * 8 )
+ F_56 ( sizeof( struct V_149 ) ) ;
}
static inline T_15 F_334 ( void )
{
return F_55 ( sizeof( struct V_556 ) )
+ F_56 ( V_557 )
+ F_56 ( V_558 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_333 () ) ;
}
static inline void F_335 ( T_16 * V_15 , T_17 * V_559 ,
int V_560 , int V_508 )
{
int V_222 ;
int V_561 = V_508 - sizeof( T_16 ) * V_560 ;
F_329 ( V_561 < 0 ) ;
F_336 ( V_560 , & V_15 [ 0 ] ) ;
for ( V_222 = 1 ; V_222 < V_560 ; V_222 ++ )
F_336 ( F_337 ( & V_559 [ V_222 ] ) , & V_15 [ V_222 ] ) ;
memset ( & V_15 [ V_560 ] , 0 , V_561 ) ;
}
static inline void F_338 ( T_16 * V_15 , void V_14 * * V_559 ,
int V_560 , int V_508 , T_15 V_562 )
{
int V_222 ;
int V_561 = V_508 - sizeof( T_16 ) * V_560 ;
F_329 ( V_561 < 0 ) ;
F_336 ( V_560 , & V_15 [ 0 ] ) ;
for ( V_222 = 1 ; V_222 < V_560 ; V_222 ++ )
F_336 ( F_339 ( V_559 , V_222 , V_562 ) , & V_15 [ V_222 ] ) ;
memset ( & V_15 [ V_560 ] , 0 , V_561 ) ;
}
static void F_340 ( T_16 * V_15 , struct V_4 * V_5 , int V_563 ,
int V_508 )
{
switch ( V_563 ) {
case V_564 :
F_338 ( V_15 , ( void V_14 * * ) V_5 -> V_15 . V_16 ,
V_554 , V_508 , F_341 ( struct V_17 , V_565 ) ) ;
break;
case V_566 :
F_335 ( V_15 , V_5 -> V_15 . V_19 -> V_567 , V_555 , V_508 ) ;
break;
}
}
static int F_342 ( struct V_77 * V_78 , struct V_4 * V_5 )
{
struct V_103 * V_568 ;
struct V_553 V_467 ;
if ( F_343 ( V_78 , V_569 , V_5 -> V_64 ) )
goto V_92;
V_467 . V_570 = V_571 ;
V_467 . V_66 = F_1 ( V_5 -> V_66 ) ;
V_467 . V_572 = F_330 ( V_5 -> V_42 -> V_572 ) ;
V_467 . V_214 = F_330 ( V_5 -> V_42 -> V_214 ) ;
if ( F_315 ( V_78 , V_573 , sizeof( V_467 ) , & V_467 ) )
goto V_92;
V_568 = F_344 ( V_78 , V_574 , V_509 * sizeof( V_575 ) ) ;
if ( V_568 == NULL )
goto V_92;
F_328 ( & V_5 -> V_38 , F_308 ( V_568 ) , F_345 ( V_568 ) ) ;
V_568 = F_344 ( V_78 , V_564 , V_554 * sizeof( T_16 ) ) ;
if ( V_568 == NULL )
goto V_92;
F_340 ( F_308 ( V_568 ) , V_5 , V_564 , F_345 ( V_568 ) ) ;
V_568 = F_344 ( V_78 , V_566 , V_555 * sizeof( T_16 ) ) ;
if ( V_568 == NULL )
goto V_92;
F_340 ( F_308 ( V_568 ) , V_5 , V_566 , F_345 ( V_568 ) ) ;
V_568 = F_344 ( V_78 , V_576 , sizeof( struct V_149 ) ) ;
if ( V_568 == NULL )
goto V_92;
F_164 ( & V_5 -> V_36 ) ;
memcpy ( F_308 ( V_568 ) , V_5 -> V_62 . V_204 , F_345 ( V_568 ) ) ;
F_169 ( & V_5 -> V_36 ) ;
return 0 ;
V_92:
return - V_88 ;
}
static T_15 F_346 ( const struct V_6 * V_7 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_333 () ;
}
static int F_347 ( struct V_77 * V_78 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_577 ;
if ( F_342 ( V_78 , V_5 ) < 0 )
return - V_88 ;
return 0 ;
}
static int F_348 ( struct V_4 * V_5 , struct V_149 * V_62 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_578 = false ;
struct V_149 V_579 ;
if ( V_62 == NULL )
return - V_108 ;
if ( F_189 ( V_62 ) )
return - V_108 ;
if ( V_7 -> V_46 & ( V_48 | V_47 ) )
return - V_108 ;
if ( ! F_277 ( V_5 ) )
return - V_108 ;
if ( V_5 -> V_38 . V_54 <= 0 )
return - V_108 ;
F_131 ( & V_5 -> V_36 ) ;
F_349 ( sizeof( V_62 -> V_204 ) != 16 ) ;
memcpy ( V_5 -> V_62 . V_204 + 8 , V_62 -> V_204 + 8 , 8 ) ;
F_139 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_31 && ( V_5 -> V_64 & V_65 ) &&
! F_171 ( V_7 , & V_579 , V_132 |
V_215 ) ) {
F_278 ( V_7 , & V_579 , & V_71 ) ;
V_578 = true ;
}
F_131 ( & V_5 -> V_36 ) ;
if ( V_578 ) {
V_5 -> V_64 |= V_418 ;
V_5 -> V_420 = 1 ;
F_11 ( V_5 , V_5 -> V_38 . V_422 ) ;
}
F_85 (ifp, &idev->addr_list, if_list) {
F_112 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_173 ) {
V_10 -> V_154 = 0 ;
V_10 -> V_155 = 0 ;
}
F_120 ( & V_10 -> V_36 ) ;
}
F_139 ( & V_5 -> V_36 ) ;
F_233 ( 0 ) ;
return 0 ;
}
static int F_350 ( struct V_6 * V_7 , const struct V_103 * V_568 )
{
int V_95 = - V_108 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_103 * V_104 [ V_580 + 1 ] ;
if ( ! V_5 )
return - V_581 ;
if ( F_351 ( V_104 , V_580 , V_568 , NULL ) < 0 )
F_352 () ;
if ( V_104 [ V_576 ] )
V_95 = F_348 ( V_5 , F_308 ( V_104 [ V_576 ] ) ) ;
return V_95 ;
}
static int F_353 ( struct V_77 * V_78 , struct V_4 * V_5 ,
T_1 V_82 , T_1 V_83 , int V_84 , unsigned int V_46 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_556 * V_582 ;
struct V_85 * V_86 ;
void * V_583 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( * V_582 ) , V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
V_582 = F_60 ( V_86 ) ;
V_582 -> V_584 = V_90 ;
V_582 -> V_585 = 0 ;
V_582 -> V_586 = V_7 -> type ;
V_582 -> V_587 = V_7 -> V_79 ;
V_582 -> V_588 = F_354 ( V_7 ) ;
V_582 -> V_589 = 0 ;
if ( F_355 ( V_78 , V_590 , V_7 -> V_30 ) ||
( V_7 -> V_272 &&
F_315 ( V_78 , V_591 , V_7 -> V_272 , V_7 -> V_274 ) ) ||
F_343 ( V_78 , V_592 , V_7 -> V_34 ) ||
( V_7 -> V_79 != V_7 -> V_398 &&
F_343 ( V_78 , V_593 , V_7 -> V_398 ) ) )
goto V_92;
V_583 = F_356 ( V_78 , V_594 ) ;
if ( V_583 == NULL )
goto V_92;
if ( F_342 ( V_78 , V_5 ) < 0 )
goto V_92;
F_357 ( V_78 , V_583 ) ;
return F_62 ( V_78 , V_86 ) ;
V_92:
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
static int F_358 ( struct V_77 * V_78 , struct V_113 * V_114 )
{
struct V_94 * V_94 = F_70 ( V_78 -> V_102 ) ;
int V_115 , V_116 ;
int V_117 = 0 , V_118 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_119 * V_120 ;
V_116 = V_114 -> args [ 0 ] ;
V_118 = V_114 -> args [ 1 ] ;
F_77 () ;
for ( V_115 = V_116 ; V_115 < V_121 ; V_115 ++ , V_118 = 0 ) {
V_117 = 0 ;
V_120 = & V_94 -> V_122 [ V_115 ] ;
F_79 (dev, head, index_hlist) {
if ( V_117 < V_118 )
goto V_125;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_125;
if ( F_353 ( V_78 , V_5 ,
F_74 ( V_114 -> V_78 ) . V_82 ,
V_114 -> V_86 -> V_112 ,
V_408 , V_126 ) <= 0 )
goto V_169;
V_125:
V_117 ++ ;
}
}
V_169:
F_80 () ;
V_114 -> args [ 1 ] = V_117 ;
V_114 -> args [ 0 ] = V_115 ;
return V_78 -> V_128 ;
}
void F_264 ( int V_84 , struct V_4 * V_5 )
{
struct V_77 * V_78 ;
struct V_94 * V_94 = F_37 ( V_5 -> V_7 ) ;
int V_95 = - V_96 ;
V_78 = F_65 ( F_334 () , V_97 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_353 ( V_78 , V_5 , 0 , 0 , V_84 , 0 ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_98;
}
F_67 ( V_78 , V_94 , 0 , V_595 , NULL , V_97 ) ;
return;
V_98:
if ( V_95 < 0 )
F_68 ( V_94 , V_595 , V_95 ) ;
}
static inline T_15 F_359 ( void )
{
return F_55 ( sizeof( struct V_596 ) )
+ F_56 ( sizeof( struct V_149 ) )
+ F_56 ( sizeof( struct V_597 ) ) ;
}
static int F_360 ( struct V_77 * V_78 , struct V_4 * V_5 ,
struct V_325 * V_326 , T_1 V_82 , T_1 V_83 ,
int V_84 , unsigned int V_46 )
{
struct V_596 * V_598 ;
struct V_85 * V_86 ;
struct V_597 V_467 ;
V_86 = F_59 ( V_78 , V_82 , V_83 , V_84 , sizeof( * V_598 ) , V_46 ) ;
if ( V_86 == NULL )
return - V_88 ;
V_598 = F_60 ( V_86 ) ;
V_598 -> V_599 = V_90 ;
V_598 -> V_600 = 0 ;
V_598 -> V_601 = 0 ;
V_598 -> V_602 = V_5 -> V_7 -> V_79 ;
V_598 -> V_172 = V_326 -> V_172 ;
V_598 -> V_603 = V_326 -> type ;
V_598 -> V_604 = 0 ;
V_598 -> V_605 = 0 ;
if ( V_326 -> V_180 )
V_598 -> V_605 |= V_606 ;
if ( V_326 -> V_334 )
V_598 -> V_605 |= V_607 ;
if ( F_315 ( V_78 , V_608 , sizeof( V_326 -> V_187 ) , & V_326 -> V_187 ) )
goto V_92;
V_467 . V_609 = F_224 ( V_326 -> V_329 ) ;
V_467 . V_610 = F_224 ( V_326 -> V_328 ) ;
if ( F_315 ( V_78 , V_611 , sizeof( V_467 ) , & V_467 ) )
goto V_92;
return F_62 ( V_78 , V_86 ) ;
V_92:
F_63 ( V_78 , V_86 ) ;
return - V_88 ;
}
static void F_234 ( int V_84 , struct V_4 * V_5 ,
struct V_325 * V_326 )
{
struct V_77 * V_78 ;
struct V_94 * V_94 = F_37 ( V_5 -> V_7 ) ;
int V_95 = - V_96 ;
V_78 = F_65 ( F_359 () , V_97 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_360 ( V_78 , V_5 , V_326 , 0 , 0 , V_84 , 0 ) ;
if ( V_95 < 0 ) {
F_25 ( V_95 == - V_88 ) ;
F_66 ( V_78 ) ;
goto V_98;
}
F_67 ( V_78 , V_94 , 0 , V_612 , NULL , V_97 ) ;
return;
V_98:
if ( V_95 < 0 )
F_68 ( V_94 , V_612 , V_95 ) ;
}
static void F_361 ( struct V_9 * V_10 , int V_613 )
{
F_131 ( & V_10 -> V_5 -> V_36 ) ;
F_112 ( & V_10 -> V_36 ) ;
if ( ( ( V_10 -> V_46 & ( V_183 | V_132 | V_215 |
V_265 ) ) == V_183 ) &&
( F_109 ( & V_10 -> V_147 ) & V_327 ) )
V_10 -> V_5 -> V_429 += V_613 ;
F_25 ( V_10 -> V_5 -> V_429 < 0 ) ;
F_120 ( & V_10 -> V_36 ) ;
F_139 ( & V_10 -> V_5 -> V_36 ) ;
}
static void F_274 ( int V_84 , struct V_9 * V_10 )
{
struct V_94 * V_94 = F_37 ( V_10 -> V_5 -> V_7 ) ;
F_327 ( V_84 ? : V_381 , V_10 ) ;
switch ( V_84 ) {
case V_381 :
F_361 ( V_10 , 1 ) ;
if ( ! ( V_10 -> V_144 -> V_614 ) )
F_251 ( V_10 -> V_144 ) ;
if ( V_10 -> V_5 -> V_38 . V_44 )
F_86 ( V_10 ) ;
if ( ! F_189 ( & V_10 -> V_151 ) )
F_214 ( & V_10 -> V_151 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_185 :
F_361 ( V_10 , - 1 ) ;
if ( V_10 -> V_5 -> V_38 . V_44 )
F_87 ( V_10 ) ;
F_187 ( V_10 -> V_5 , & V_10 -> V_147 ) ;
if ( ! F_189 ( & V_10 -> V_151 ) ) {
struct V_156 * V_144 ;
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
V_144 = F_362 ( F_37 ( V_7 ) , & V_10 -> V_151 , NULL ,
V_7 -> V_79 , 1 ) ;
if ( V_144 ) {
F_218 ( & V_144 -> V_221 ) ;
if ( F_143 ( V_144 ) )
F_363 ( & V_144 -> V_221 ) ;
}
}
F_218 ( & V_10 -> V_144 -> V_221 ) ;
if ( F_143 ( V_10 -> V_144 ) )
F_363 ( & V_10 -> V_144 -> V_221 ) ;
break;
}
F_364 ( & V_94 -> V_16 . V_123 ) ;
}
static void F_140 ( int V_84 , struct V_9 * V_10 )
{
F_111 () ;
if ( F_125 ( V_10 -> V_5 -> V_31 == 0 ) )
F_274 ( V_84 , V_10 ) ;
F_124 () ;
}
static
int F_365 ( struct V_135 * V_615 , int V_616 ,
void T_6 * V_617 , T_15 * V_618 , T_9 * V_619 )
{
int * V_620 = V_615 -> V_292 ;
int V_621 = * V_620 ;
T_9 V_431 = * V_619 ;
struct V_135 V_622 ;
int V_200 ;
V_622 = * V_615 ;
V_622 . V_292 = & V_621 ;
V_200 = F_366 ( & V_622 , V_616 , V_617 , V_618 , V_619 ) ;
if ( V_616 )
V_200 = F_90 ( V_615 , V_620 , V_621 ) ;
if ( V_200 )
* V_619 = V_431 ;
return V_200 ;
}
static void F_367 ( struct V_4 * V_5 )
{
struct V_623 V_624 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_368 ( & V_624 , V_5 -> V_7 ) ;
if ( V_5 -> V_38 . V_165 )
F_259 ( NULL , V_186 , & V_624 ) ;
else
F_259 ( NULL , V_177 , & V_624 ) ;
}
static void F_369 ( struct V_94 * V_94 , T_2 V_133 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_77 () ;
F_163 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_134 = ( ! V_5 -> V_38 . V_165 ) ^ ( ! V_133 ) ;
V_5 -> V_38 . V_165 = V_133 ;
if ( V_134 )
F_367 ( V_5 ) ;
}
}
F_80 () ;
}
static int F_370 ( struct V_135 * V_136 , int * V_137 , int V_133 )
{
struct V_94 * V_94 ;
int V_138 ;
if ( ! F_91 () )
return F_92 () ;
V_94 = (struct V_94 * ) V_136 -> V_139 ;
V_138 = * V_137 ;
* V_137 = V_133 ;
if ( V_137 == & V_94 -> V_16 . V_39 -> V_165 ) {
F_93 () ;
return 0 ;
}
if ( V_137 == & V_94 -> V_16 . V_110 -> V_165 ) {
V_94 -> V_16 . V_39 -> V_165 = V_133 ;
F_369 ( V_94 , V_133 ) ;
} else if ( ( ! V_133 ) ^ ( ! V_138 ) )
F_367 ( (struct V_4 * ) V_136 -> V_140 ) ;
F_93 () ;
return 0 ;
}
static
int F_371 ( struct V_135 * V_615 , int V_616 ,
void T_6 * V_617 , T_15 * V_618 , T_9 * V_619 )
{
int * V_620 = V_615 -> V_292 ;
int V_621 = * V_620 ;
T_9 V_431 = * V_619 ;
struct V_135 V_622 ;
int V_200 ;
V_622 = * V_615 ;
V_622 . V_292 = & V_621 ;
V_200 = F_366 ( & V_622 , V_616 , V_617 , V_618 , V_619 ) ;
if ( V_616 )
V_200 = F_370 ( V_615 , V_620 , V_621 ) ;
if ( V_200 )
* V_619 = V_431 ;
return V_200 ;
}
static int F_372 ( struct V_94 * V_94 , char * V_625 ,
struct V_4 * V_5 , struct V_80 * V_137 )
{
int V_222 ;
struct V_626 * V_627 ;
char V_628 [ sizeof( L_33 ) + V_557 ] ;
V_627 = F_373 ( & V_629 , sizeof( * V_627 ) , V_21 ) ;
if ( V_627 == NULL )
goto V_169;
for ( V_222 = 0 ; V_627 -> V_630 [ V_222 ] . V_292 ; V_222 ++ ) {
V_627 -> V_630 [ V_222 ] . V_292 += ( char * ) V_137 - ( char * ) & V_80 ;
V_627 -> V_630 [ V_222 ] . V_140 = V_5 ;
V_627 -> V_630 [ V_222 ] . V_139 = V_94 ;
}
snprintf ( V_628 , sizeof( V_628 ) , L_34 , V_625 ) ;
V_627 -> V_631 = F_374 ( V_94 , V_628 , V_627 -> V_630 ) ;
if ( V_627 -> V_631 == NULL )
goto free;
V_137 -> V_41 = V_627 ;
return 0 ;
free:
F_21 ( V_627 ) ;
V_169:
return - V_96 ;
}
static void F_375 ( struct V_80 * V_137 )
{
struct V_626 * V_627 ;
if ( V_137 -> V_41 == NULL )
return;
V_627 = V_137 -> V_41 ;
V_137 -> V_41 = NULL ;
F_376 ( V_627 -> V_631 ) ;
F_21 ( V_627 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_377 ( V_5 -> V_7 , V_5 -> V_42 , L_35 ,
& V_632 ) ;
F_372 ( F_37 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_30 ,
V_5 , & V_5 -> V_38 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_375 ( & V_5 -> V_38 ) ;
F_378 ( V_5 -> V_42 ) ;
}
static int T_11 F_379 ( struct V_94 * V_94 )
{
int V_95 = - V_26 ;
struct V_80 * V_633 , * V_634 ;
V_633 = F_373 ( & V_80 , sizeof( V_80 ) , V_21 ) ;
if ( V_633 == NULL )
goto V_635;
V_634 = F_373 ( & V_636 , sizeof( V_636 ) , V_21 ) ;
if ( V_634 == NULL )
goto V_637;
V_634 -> V_334 = V_638 . V_334 ;
V_634 -> V_165 = V_638 . V_165 ;
V_94 -> V_16 . V_110 = V_633 ;
V_94 -> V_16 . V_39 = V_634 ;
#ifdef F_380
V_95 = F_372 ( V_94 , L_36 , NULL , V_633 ) ;
if ( V_95 < 0 )
goto V_639;
V_95 = F_372 ( V_94 , L_37 , NULL , V_634 ) ;
if ( V_95 < 0 )
goto V_640;
#endif
return 0 ;
#ifdef F_380
V_640:
F_375 ( V_633 ) ;
V_639:
F_21 ( V_634 ) ;
#endif
V_637:
F_21 ( V_633 ) ;
V_635:
return V_95 ;
}
static void T_12 F_381 ( struct V_94 * V_94 )
{
#ifdef F_380
F_375 ( V_94 -> V_16 . V_39 ) ;
F_375 ( V_94 -> V_16 . V_110 ) ;
#endif
if ( ! F_174 ( V_94 , & V_641 ) ) {
F_21 ( V_94 -> V_16 . V_39 ) ;
F_21 ( V_94 -> V_16 . V_110 ) ;
}
}
int T_13 F_382 ( void )
{
int V_222 , V_95 ;
V_95 = F_383 () ;
if ( V_95 < 0 ) {
F_384 ( L_38 ,
V_29 , V_95 ) ;
goto V_169;
}
V_95 = F_301 ( & V_642 ) ;
if ( V_95 < 0 )
goto V_643;
F_236 () ;
if ( ! F_32 ( V_641 . V_644 ) )
V_95 = - V_26 ;
F_93 () ;
if ( V_95 )
goto V_645;
for ( V_222 = 0 ; V_222 < V_416 ; V_222 ++ )
F_385 ( & V_174 [ V_222 ] ) ;
F_386 ( & V_646 ) ;
F_233 ( 0 ) ;
V_95 = F_387 ( & V_647 ) ;
if ( V_95 < 0 )
goto V_648;
V_95 = F_388 ( V_649 , V_650 , NULL , F_358 ,
NULL ) ;
if ( V_95 < 0 )
goto V_98;
F_388 ( V_649 , V_381 , F_312 , NULL , NULL ) ;
F_388 ( V_649 , V_185 , F_310 , NULL , NULL ) ;
F_388 ( V_649 , V_651 , F_326 ,
F_323 , NULL ) ;
F_388 ( V_649 , V_499 , NULL ,
F_324 , NULL ) ;
F_388 ( V_649 , V_503 , NULL ,
F_325 , NULL ) ;
F_388 ( V_649 , V_652 , F_69 ,
F_76 , NULL ) ;
F_389 () ;
return 0 ;
V_98:
F_390 ( & V_647 ) ;
V_648:
F_391 ( & V_646 ) ;
V_645:
F_303 ( & V_642 ) ;
V_643:
F_392 () ;
V_169:
return V_95 ;
}
void F_393 ( void )
{
struct V_6 * V_7 ;
int V_222 ;
F_391 ( & V_646 ) ;
F_303 ( & V_642 ) ;
F_392 () ;
F_236 () ;
F_394 ( & V_647 ) ;
F_89 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_265 ( V_7 , 1 ) ;
}
F_265 ( V_641 . V_644 , 2 ) ;
F_128 ( & V_167 ) ;
for ( V_222 = 0 ; V_222 < V_416 ; V_222 ++ )
F_25 ( ! F_395 ( & V_174 [ V_222 ] ) ) ;
F_129 ( & V_167 ) ;
F_7 ( & V_450 ) ;
F_93 () ;
}
