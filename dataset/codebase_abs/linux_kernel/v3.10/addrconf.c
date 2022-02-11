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
V_40 -> V_68 = V_69 ;
if ( F_43 ( V_7 ) && F_4 ( V_7 ) )
V_40 -> V_70 |= V_71 ;
F_44 ( V_40 ) ;
V_40 -> V_72 = V_20 ;
F_2 ( V_40 ) ;
F_45 ( V_7 -> V_73 , V_40 ) ;
F_46 ( V_7 , & V_74 ) ;
F_46 ( V_7 , & V_75 ) ;
if ( V_40 -> V_44 . V_50 && ( V_7 -> V_52 & V_76 ) )
F_46 ( V_7 , & V_77 ) ;
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
if ( V_7 -> V_52 & V_78 )
F_49 ( V_5 ) ;
return V_5 ;
}
static int F_50 ( int type )
{
int V_79 = F_51 ( sizeof( struct V_80 ) )
+ F_52 ( 4 ) ;
if ( type == - 1 || type == V_81 )
V_79 += F_52 ( 4 ) ;
#ifdef F_53
if ( type == - 1 || type == V_82 )
V_79 += F_52 ( 4 ) ;
#endif
return V_79 ;
}
static int F_54 ( struct V_83 * V_84 , int V_85 ,
struct V_86 * V_87 , T_1 V_88 ,
T_1 V_89 , int V_90 , unsigned int V_52 ,
int type )
{
struct V_91 * V_92 ;
struct V_80 * V_93 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_80 ) ,
V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_93 = F_56 ( V_92 ) ;
V_93 -> V_95 = V_96 ;
if ( F_57 ( V_84 , V_97 , V_85 ) < 0 )
goto V_98;
if ( ( type == - 1 || type == V_81 ) &&
F_57 ( V_84 , V_81 , V_87 -> V_50 ) < 0 )
goto V_98;
#ifdef F_53
if ( ( type == - 1 || type == V_82 ) &&
F_57 ( V_84 , V_82 ,
V_87 -> V_99 ) < 0 )
goto V_98;
#endif
return F_58 ( V_84 , V_92 ) ;
V_98:
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
void F_60 ( struct V_100 * V_100 , int type , int V_85 ,
struct V_86 * V_87 )
{
struct V_83 * V_84 ;
int V_101 = - V_102 ;
V_84 = F_61 ( F_50 ( type ) , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_101 = F_54 ( V_84 , V_85 , V_87 , 0 , 0 ,
V_105 , 0 , type ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_104;
}
F_63 ( V_84 , V_100 , 0 , V_106 , NULL , V_103 ) ;
return;
V_104:
F_64 ( V_100 , V_106 , V_101 ) ;
}
static int F_65 ( struct V_83 * V_107 ,
struct V_91 * V_92 )
{
struct V_100 * V_100 = F_66 ( V_107 -> V_108 ) ;
struct V_109 * V_110 [ V_111 + 1 ] ;
struct V_80 * V_93 ;
struct V_83 * V_84 ;
struct V_86 * V_87 ;
struct V_4 * V_112 ;
struct V_6 * V_7 ;
int V_85 ;
int V_101 ;
V_101 = F_67 ( V_92 , sizeof( * V_93 ) , V_110 , V_111 ,
V_113 ) ;
if ( V_101 < 0 )
goto V_104;
V_101 = V_114 ;
if ( ! V_110 [ V_97 ] )
goto V_104;
V_85 = F_68 ( V_110 [ V_97 ] ) ;
switch ( V_85 ) {
case V_115 :
V_87 = V_100 -> V_23 . V_116 ;
break;
case V_117 :
V_87 = V_100 -> V_23 . V_45 ;
break;
default:
V_7 = F_69 ( V_100 , V_85 ) ;
if ( V_7 == NULL )
goto V_104;
V_112 = F_48 ( V_7 ) ;
if ( V_112 == NULL )
goto V_104;
V_87 = & V_112 -> V_44 ;
break;
}
V_101 = - V_102 ;
V_84 = F_61 ( F_50 ( - 1 ) , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_101 = F_54 ( V_84 , V_85 , V_87 ,
F_70 ( V_107 ) . V_88 ,
V_92 -> V_118 , V_105 , 0 ,
- 1 ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_104;
}
V_101 = F_71 ( V_84 , V_100 , F_70 ( V_107 ) . V_88 ) ;
V_104:
return V_101 ;
}
static int F_72 ( struct V_83 * V_84 ,
struct V_119 * V_120 )
{
struct V_100 * V_100 = F_66 ( V_84 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 , V_124 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_123 = V_120 -> args [ 1 ] ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_73 () ;
V_120 -> V_89 = F_74 ( & V_100 -> V_23 . V_129 ) ^
V_100 -> V_130 ;
F_75 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_54 ( V_84 , V_7 -> V_85 ,
& V_5 -> V_44 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_105 ,
V_132 ,
- 1 ) <= 0 ) {
F_76 () ;
goto V_133;
}
F_77 ( V_120 , F_78 ( V_84 ) ) ;
V_131:
V_123 ++ ;
}
F_76 () ;
}
if ( V_121 == V_127 ) {
if ( F_54 ( V_84 , V_115 ,
V_100 -> V_23 . V_116 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_105 , V_132 ,
- 1 ) <= 0 )
goto V_133;
else
V_121 ++ ;
}
if ( V_121 == V_127 + 1 ) {
if ( F_54 ( V_84 , V_117 ,
V_100 -> V_23 . V_45 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_105 , V_132 ,
- 1 ) <= 0 )
goto V_133;
else
V_121 ++ ;
}
V_133:
V_120 -> args [ 0 ] = V_121 ;
V_120 -> args [ 1 ] = V_123 ;
return V_84 -> V_134 ;
}
static void F_79 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_135 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_44 . V_50 )
F_33 ( V_7 ) ;
if ( V_7 -> V_52 & V_76 ) {
if ( V_5 -> V_44 . V_50 ) {
F_46 ( V_7 , & V_77 ) ;
F_46 ( V_7 , & V_136 ) ;
F_46 ( V_7 , & V_137 ) ;
} else {
F_80 ( V_7 , & V_77 ) ;
F_80 ( V_7 , & V_136 ) ;
F_80 ( V_7 , & V_137 ) ;
}
}
F_81 (ifa, &idev->addr_list, if_list) {
if ( V_135 -> V_52 & V_138 )
continue;
if ( V_5 -> V_44 . V_50 )
F_82 ( V_135 ) ;
else
F_83 ( V_135 ) ;
}
F_60 ( F_31 ( V_7 ) , V_81 ,
V_7 -> V_85 , & V_5 -> V_44 ) ;
}
static void F_84 ( struct V_100 * V_100 , T_2 V_139 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_85 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_140 = ( ! V_5 -> V_44 . V_50 ) ^ ( ! V_139 ) ;
V_5 -> V_44 . V_50 = V_139 ;
if ( V_140 )
F_79 ( V_5 ) ;
}
}
}
static int F_86 ( struct V_141 * V_142 , int * V_143 , int V_139 )
{
struct V_100 * V_100 ;
int V_144 ;
if ( ! F_87 () )
return F_88 () ;
V_100 = (struct V_100 * ) V_142 -> V_145 ;
V_144 = * V_143 ;
* V_143 = V_139 ;
if ( V_143 == & V_100 -> V_23 . V_45 -> V_50 ) {
if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_60 ( V_100 , V_81 ,
V_117 ,
V_100 -> V_23 . V_45 ) ;
F_89 () ;
return 0 ;
}
if ( V_143 == & V_100 -> V_23 . V_116 -> V_50 ) {
V_100 -> V_23 . V_45 -> V_50 = V_139 ;
F_84 ( V_100 , V_139 ) ;
if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_60 ( V_100 , V_81 ,
V_115 ,
V_100 -> V_23 . V_116 ) ;
} else if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_79 ( (struct V_4 * ) V_142 -> V_146 ) ;
F_89 () ;
if ( V_139 )
F_90 ( V_100 ) ;
return 1 ;
}
void F_91 ( struct V_8 * V_9 )
{
F_20 ( ! F_92 ( & V_9 -> V_147 ) ) ;
#ifdef F_22
F_23 ( L_7 , V_36 ) ;
#endif
F_93 ( V_9 -> V_5 ) ;
if ( F_7 ( & V_9 -> V_10 ) )
F_94 ( L_8 , V_9 ) ;
if ( V_9 -> V_148 != V_149 ) {
F_25 ( L_9 , V_9 ) ;
return;
}
F_95 ( V_9 -> V_150 ) ;
F_26 ( V_9 , V_39 ) ;
}
static void
F_96 ( struct V_4 * V_5 , struct V_8 * V_9 )
{
struct V_151 * V_143 ;
int V_152 = F_97 ( & V_9 -> V_153 ) ;
F_98 (p, &idev->addr_list) {
struct V_8 * V_135
= F_99 ( V_143 , struct V_8 , V_154 ) ;
if ( V_152 >= F_97 ( & V_135 -> V_153 ) )
break;
}
F_100 ( & V_9 -> V_154 , V_143 ) ;
}
static T_1 F_101 ( const struct V_155 * V_153 )
{
return F_102 ( F_103 ( V_153 ) , V_156 ) ;
}
static struct V_8 *
F_104 ( struct V_4 * V_5 , const struct V_155 * V_153 , int V_157 ,
int V_158 , T_1 V_52 )
{
struct V_8 * V_135 = NULL ;
struct V_159 * V_150 ;
unsigned int V_160 ;
int V_101 = 0 ;
int V_161 = F_105 ( V_153 ) ;
if ( V_161 == V_162 ||
V_161 & V_163 ||
( ! ( V_5 -> V_7 -> V_52 & V_54 ) &&
V_161 & V_164 ) )
return F_106 ( - V_165 ) ;
F_107 () ;
if ( V_5 -> V_38 ) {
V_101 = - V_166 ;
goto V_167;
}
if ( V_5 -> V_44 . V_168 ) {
V_101 = - V_169 ;
goto V_167;
}
F_108 ( & V_170 ) ;
if ( F_109 ( F_31 ( V_5 -> V_7 ) , V_153 , V_5 -> V_7 ) ) {
F_35 ( ( L_10 ) ) ;
V_101 = - V_171 ;
goto V_172;
}
V_135 = F_15 ( sizeof( struct V_8 ) , V_103 ) ;
if ( V_135 == NULL ) {
F_35 ( ( L_11 ) ) ;
V_101 = - V_102 ;
goto V_172;
}
V_150 = F_110 ( V_5 , V_153 , false ) ;
if ( F_111 ( V_150 ) ) {
V_101 = F_112 ( V_150 ) ;
goto V_172;
}
V_135 -> V_153 = * V_153 ;
F_113 ( & V_135 -> V_43 ) ;
F_113 ( & V_135 -> V_173 ) ;
F_114 ( & V_135 -> V_10 ) ;
F_115 ( & V_135 -> V_147 ) ;
V_135 -> V_10 . V_174 = ( unsigned long ) V_135 ;
V_135 -> V_158 = V_158 ;
V_135 -> V_175 = V_157 ;
V_135 -> V_52 = V_52 | V_138 ;
V_135 -> V_1 = V_135 -> V_72 = V_20 ;
V_135 -> V_176 = false ;
V_135 -> V_150 = V_150 ;
V_135 -> V_5 = V_5 ;
F_38 ( V_5 ) ;
F_10 ( V_135 ) ;
V_160 = F_101 ( V_153 ) ;
F_116 ( & V_135 -> V_147 , & V_177 [ V_160 ] ) ;
F_117 ( & V_170 ) ;
F_118 ( & V_5 -> V_43 ) ;
F_96 ( V_5 , V_135 ) ;
#ifdef F_41
if ( V_135 -> V_52 & V_178 ) {
F_119 ( & V_135 -> V_179 , & V_5 -> V_61 ) ;
F_10 ( V_135 ) ;
}
#endif
F_10 ( V_135 ) ;
F_120 ( & V_5 -> V_43 ) ;
V_167:
F_121 () ;
if ( F_122 ( V_101 == 0 ) )
F_123 ( V_180 , V_135 ) ;
else {
F_16 ( V_135 ) ;
V_135 = F_106 ( V_101 ) ;
}
return V_135 ;
V_172:
F_117 ( & V_170 ) ;
goto V_167;
}
static void F_124 ( struct V_8 * V_9 )
{
struct V_8 * V_135 , * V_181 ;
struct V_4 * V_5 = V_9 -> V_5 ;
int V_148 ;
int V_182 = 0 , V_183 = 0 ;
unsigned long V_19 = V_20 ;
F_125 ( & V_9 -> V_173 ) ;
V_148 = V_9 -> V_148 ;
V_9 -> V_148 = V_149 ;
F_126 ( & V_9 -> V_173 ) ;
if ( V_148 == V_149 )
goto V_172;
F_125 ( & V_170 ) ;
F_127 ( & V_9 -> V_147 ) ;
F_126 ( & V_170 ) ;
F_128 ( & V_5 -> V_43 ) ;
#ifdef F_41
if ( V_9 -> V_52 & V_178 ) {
F_129 ( & V_9 -> V_179 ) ;
if ( V_9 -> V_184 ) {
F_130 ( V_9 -> V_184 ) ;
V_9 -> V_184 = NULL ;
}
F_8 ( V_9 ) ;
}
#endif
F_131 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_135 == V_9 ) {
F_132 ( & V_9 -> V_154 ) ;
F_8 ( V_9 ) ;
if ( ! ( V_9 -> V_52 & V_185 ) || V_183 > 0 )
break;
V_182 = 1 ;
continue;
} else if ( V_9 -> V_52 & V_185 ) {
if ( F_133 ( & V_135 -> V_153 , & V_9 -> V_153 ,
V_9 -> V_175 ) ) {
if ( V_135 -> V_52 & V_185 ) {
V_183 = 1 ;
if ( V_182 )
break;
} else {
unsigned long V_186 ;
if ( ! V_183 )
V_183 = - 1 ;
F_108 ( & V_135 -> V_43 ) ;
V_186 = F_134 ( V_135 -> V_187 , V_3 ) ;
if ( F_135 ( V_19 ,
V_135 -> V_72 + V_186 * V_3 ) )
V_19 = V_135 -> V_72 + V_186 * V_3 ;
F_117 ( & V_135 -> V_43 ) ;
}
}
}
}
F_136 ( & V_5 -> V_43 ) ;
F_6 ( V_9 ) ;
F_137 ( V_188 , V_9 ) ;
F_123 ( V_189 , V_9 ) ;
if ( ( V_9 -> V_52 & V_185 ) && V_183 < 1 ) {
struct V_155 V_190 ;
struct V_159 * V_150 ;
F_138 ( & V_190 , & V_9 -> V_153 , V_9 -> V_175 ) ;
V_150 = F_139 ( & V_190 ,
V_9 -> V_175 ,
V_9 -> V_5 -> V_7 ,
0 , V_191 | V_192 ) ;
if ( V_150 ) {
if ( V_183 == 0 ) {
F_140 ( V_150 ) ;
V_150 = NULL ;
} else if ( ! ( V_150 -> V_193 & V_194 ) ) {
F_141 ( V_150 , V_19 ) ;
}
}
F_95 ( V_150 ) ;
}
F_142 ( V_9 ) ;
V_172:
F_130 ( V_9 ) ;
}
static int F_143 ( struct V_8 * V_9 , struct V_8 * V_195 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_155 V_153 , * V_196 ;
unsigned long V_197 , V_198 , V_199 , V_200 ;
unsigned long V_201 ;
int V_202 ;
int V_203 = 0 ;
int V_204 ;
T_1 V_205 ;
unsigned long V_206 = V_20 ;
F_118 ( & V_5 -> V_43 ) ;
if ( V_195 ) {
F_125 ( & V_195 -> V_43 ) ;
memcpy ( & V_153 . V_207 [ 8 ] , & V_195 -> V_153 . V_207 [ 8 ] , 8 ) ;
F_126 ( & V_195 -> V_43 ) ;
V_196 = & V_153 ;
} else {
V_196 = NULL ;
}
V_208:
F_38 ( V_5 ) ;
if ( V_5 -> V_44 . V_67 <= 0 ) {
F_120 ( & V_5 -> V_43 ) ;
F_40 ( L_12 , V_36 ) ;
F_93 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
F_125 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_209 ++ >= V_5 -> V_44 . V_210 ) {
V_5 -> V_44 . V_67 = - 1 ;
F_126 ( & V_9 -> V_43 ) ;
F_120 ( & V_5 -> V_43 ) ;
F_25 ( L_13 ,
V_36 ) ;
F_93 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
F_10 ( V_9 ) ;
memcpy ( V_153 . V_207 , V_9 -> V_153 . V_207 , 8 ) ;
F_144 ( V_5 , V_196 ) ;
memcpy ( & V_153 . V_207 [ 8 ] , V_5 -> V_211 , 8 ) ;
V_200 = ( V_206 - V_9 -> V_72 ) / V_3 ;
V_198 = F_145 ( V_212 ,
V_9 -> V_187 ,
V_5 -> V_44 . V_213 + V_200 ) ;
V_197 = F_145 ( V_212 ,
V_9 -> V_214 ,
V_5 -> V_44 . V_215 + V_200 -
V_5 -> V_44 . V_216 ) ;
V_202 = V_9 -> V_175 ;
V_204 = V_5 -> V_44 . V_204 ;
V_199 = V_9 -> V_72 ;
F_126 ( & V_9 -> V_43 ) ;
V_201 = V_5 -> V_44 . V_210 *
V_5 -> V_44 . V_217 *
V_5 -> V_48 -> V_218 / V_3 ;
F_120 ( & V_5 -> V_43 ) ;
if ( V_197 <= V_201 ) {
F_130 ( V_9 ) ;
F_93 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
V_205 = V_178 ;
if ( V_9 -> V_52 & V_219 )
V_205 |= V_219 ;
V_195 = ! V_204 ||
F_146 ( V_5 ) < V_204 ?
F_104 ( V_5 , & V_153 , V_202 ,
F_105 ( & V_153 ) & V_220 ,
V_205 ) : NULL ;
if ( F_147 ( V_195 ) ) {
F_130 ( V_9 ) ;
F_93 ( V_5 ) ;
F_40 ( L_14 , V_36 ) ;
V_196 = & V_153 ;
F_118 ( & V_5 -> V_43 ) ;
goto V_208;
}
F_125 ( & V_195 -> V_43 ) ;
V_195 -> V_184 = V_9 ;
V_195 -> V_187 = V_198 ;
V_195 -> V_214 = V_197 ;
V_195 -> V_1 = V_206 ;
V_195 -> V_72 = V_199 ;
F_126 ( & V_195 -> V_43 ) ;
F_148 ( V_195 ) ;
F_130 ( V_195 ) ;
F_93 ( V_5 ) ;
V_172:
return V_203 ;
}
static inline int F_149 ( int type )
{
if ( type & ( V_221 | V_222 | V_164 ) )
return 1 ;
return 0 ;
}
static int F_150 ( struct V_100 * V_100 ,
struct V_223 * V_224 ,
struct V_225 * V_226 ,
int V_227 )
{
int V_203 ;
if ( V_227 <= V_224 -> V_228 ) {
switch ( V_227 ) {
case V_229 :
V_203 = V_224 -> V_230 ;
break;
case V_231 :
V_203 = V_224 -> V_232 ;
break;
default:
V_203 = ! ! F_151 ( V_227 , V_224 -> V_233 ) ;
}
goto V_172;
}
switch ( V_227 ) {
case V_234 :
V_203 = ! ! V_224 -> V_135 ;
break;
case V_235 :
V_203 = F_152 ( & V_224 -> V_135 -> V_153 , V_226 -> V_153 ) ;
break;
case V_229 :
V_203 = F_153 ( V_224 -> V_161 ) ;
if ( V_203 >= V_226 -> V_158 )
V_203 = - V_203 ;
else
V_203 -= 128 ;
V_224 -> V_230 = V_203 ;
break;
case V_236 :
V_203 = F_149 ( V_224 -> V_161 ) ||
! ( V_224 -> V_135 -> V_52 & ( V_237 | V_219 ) ) ;
break;
#ifdef F_154
case V_238 :
{
int V_239 = ! ( V_226 -> V_240 & V_241 ) ;
V_203 = ! ( V_224 -> V_135 -> V_52 & V_242 ) ^ V_239 ;
break;
}
#endif
case V_243 :
V_203 = ( ! V_226 -> V_85 ||
V_226 -> V_85 == V_224 -> V_135 -> V_5 -> V_7 -> V_85 ) ;
break;
case V_244 :
V_203 = F_155 ( V_100 ,
& V_224 -> V_135 -> V_153 , V_224 -> V_161 ,
V_224 -> V_135 -> V_5 -> V_7 -> V_85 ) == V_226 -> V_245 ;
break;
#ifdef F_41
case V_246 :
{
int V_247 = V_226 -> V_240 & ( V_248 | V_249 ) ?
! ! ( V_226 -> V_240 & V_249 ) :
V_224 -> V_135 -> V_5 -> V_44 . V_67 >= 2 ;
V_203 = ( ! ( V_224 -> V_135 -> V_52 & V_178 ) ) ^ V_247 ;
break;
}
#endif
case V_250 :
V_203 = ! ( F_156 ( & V_224 -> V_135 -> V_153 ) ^
F_156 ( V_226 -> V_153 ) ) ;
break;
case V_231 :
V_203 = F_157 ( & V_224 -> V_135 -> V_153 , V_226 -> V_153 ) ;
if ( V_203 > V_224 -> V_135 -> V_175 )
V_203 = V_224 -> V_135 -> V_175 ;
V_224 -> V_232 = V_203 ;
break;
default:
V_203 = 0 ;
}
if ( V_203 )
F_158 ( V_227 , V_224 -> V_233 ) ;
V_224 -> V_228 = V_227 ;
V_172:
return V_203 ;
}
int F_159 ( struct V_100 * V_100 , const struct V_6 * V_251 ,
const struct V_155 * V_252 , unsigned int V_240 ,
struct V_155 * V_253 )
{
struct V_223 V_254 [ 2 ] ,
* V_224 = & V_254 [ 0 ] , * V_255 = & V_254 [ 1 ] ;
struct V_225 V_226 ;
struct V_6 * V_7 ;
int V_256 ;
V_256 = F_160 ( V_252 ) ;
V_226 . V_153 = V_252 ;
V_226 . V_85 = V_251 ? V_251 -> V_85 : 0 ;
V_226 . V_158 = F_153 ( V_256 ) ;
V_226 . V_245 = F_155 ( V_100 , V_252 , V_256 , V_226 . V_85 ) ;
V_226 . V_240 = V_240 ;
V_255 -> V_228 = - 1 ;
V_255 -> V_135 = NULL ;
F_73 () ;
F_161 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_256 & V_163 ) ||
V_226 . V_158 <= V_257 ) &&
V_226 . V_85 && V_7 -> V_85 != V_226 . V_85 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_162 ( & V_5 -> V_43 ) ;
F_81 (score->ifa, &idev->addr_list, if_list) {
int V_227 ;
if ( ( V_224 -> V_135 -> V_52 & V_138 ) &&
( ! ( V_224 -> V_135 -> V_52 & V_219 ) ) )
continue;
V_224 -> V_161 = F_160 ( & V_224 -> V_135 -> V_153 ) ;
if ( F_163 ( V_224 -> V_161 == V_162 ||
V_224 -> V_161 & V_163 ) ) {
F_164 ( V_258
L_15
L_16 ,
V_7 -> V_37 ) ;
continue;
}
V_224 -> V_228 = - 1 ;
F_165 ( V_224 -> V_233 , V_259 ) ;
for ( V_227 = 0 ; V_227 < V_259 ; V_227 ++ ) {
int V_260 , V_261 ;
V_260 = F_150 ( V_100 , V_255 , & V_226 , V_227 ) ;
V_261 = F_150 ( V_100 , V_224 , & V_226 , V_227 ) ;
if ( V_260 > V_261 ) {
if ( V_227 == V_229 &&
V_224 -> V_230 > 0 ) {
goto V_262;
}
break;
} else if ( V_260 < V_261 ) {
if ( V_255 -> V_135 )
F_130 ( V_255 -> V_135 ) ;
F_10 ( V_224 -> V_135 ) ;
F_166 ( V_255 , V_224 ) ;
V_224 -> V_135 = V_255 -> V_135 ;
break;
}
}
}
V_262:
F_167 ( & V_5 -> V_43 ) ;
}
F_76 () ;
if ( ! V_255 -> V_135 )
return - V_165 ;
* V_253 = V_255 -> V_135 -> V_153 ;
F_130 ( V_255 -> V_135 ) ;
return 0 ;
}
int F_168 ( struct V_6 * V_7 , struct V_155 * V_153 ,
unsigned char V_263 )
{
struct V_4 * V_5 ;
int V_101 = - V_165 ;
F_73 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_158 == V_264 &&
! ( V_9 -> V_52 & V_263 ) ) {
* V_153 = V_9 -> V_153 ;
V_101 = 0 ;
break;
}
}
F_167 ( & V_5 -> V_43 ) ;
}
F_76 () ;
return V_101 ;
}
static int F_146 ( struct V_4 * V_5 )
{
int V_265 = 0 ;
struct V_8 * V_9 ;
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifp, &idev->addr_list, if_list)
V_265 ++ ;
F_167 ( & V_5 -> V_43 ) ;
return V_265 ;
}
int F_169 ( struct V_100 * V_100 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_266 )
{
struct V_8 * V_9 ;
unsigned int V_160 = F_101 ( V_153 ) ;
F_107 () ;
F_75 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_170 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_152 ( & V_9 -> V_153 , V_153 ) &&
! ( V_9 -> V_52 & V_138 ) &&
( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_158 & ( V_264 | V_267 ) || V_266 ) ) ) {
F_121 () ;
return 1 ;
}
}
F_121 () ;
return 0 ;
}
static bool F_109 ( struct V_100 * V_100 , const struct V_155 * V_153 ,
struct V_6 * V_7 )
{
unsigned int V_160 = F_101 ( V_153 ) ;
struct V_8 * V_9 ;
F_171 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_170 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_152 ( & V_9 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_172 ( const struct V_155 * V_153 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_8 * V_135 ;
int V_183 ;
V_183 = 0 ;
F_73 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifa, &idev->addr_list, if_list) {
V_183 = F_133 ( V_153 , & V_135 -> V_153 ,
V_135 -> V_175 ) ;
if ( V_183 )
break;
}
F_167 ( & V_5 -> V_43 ) ;
}
F_76 () ;
return V_183 ;
}
struct V_8 * F_173 ( struct V_100 * V_100 , const struct V_155 * V_153 ,
struct V_6 * V_7 , int V_266 )
{
struct V_8 * V_9 , * V_268 = NULL ;
unsigned int V_160 = F_101 ( V_153 ) ;
F_107 () ;
F_174 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_170 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_152 ( & V_9 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_158 & ( V_264 | V_267 ) || V_266 ) ) {
V_268 = V_9 ;
F_10 ( V_9 ) ;
break;
}
}
}
F_121 () ;
return V_268 ;
}
static void F_175 ( struct V_8 * V_9 , int V_269 )
{
if ( V_9 -> V_52 & V_185 ) {
F_125 ( & V_9 -> V_43 ) ;
F_6 ( V_9 ) ;
V_9 -> V_52 |= V_138 ;
if ( V_269 )
V_9 -> V_52 |= V_270 ;
F_126 ( & V_9 -> V_43 ) ;
if ( V_269 )
F_137 ( 0 , V_9 ) ;
F_130 ( V_9 ) ;
#ifdef F_41
} else if ( V_9 -> V_52 & V_178 ) {
struct V_8 * V_184 ;
F_125 ( & V_9 -> V_43 ) ;
V_184 = V_9 -> V_184 ;
if ( V_184 ) {
F_10 ( V_184 ) ;
F_126 ( & V_9 -> V_43 ) ;
F_143 ( V_184 , V_9 ) ;
F_130 ( V_184 ) ;
} else {
F_126 ( & V_9 -> V_43 ) ;
}
F_124 ( V_9 ) ;
#endif
} else
F_124 ( V_9 ) ;
}
static int F_176 ( struct V_8 * V_9 )
{
int V_101 = - V_271 ;
F_108 ( & V_9 -> V_173 ) ;
if ( V_9 -> V_148 == V_272 ) {
V_9 -> V_148 = V_273 ;
V_101 = 0 ;
}
F_117 ( & V_9 -> V_173 ) ;
return V_101 ;
}
void F_177 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
if ( F_176 ( V_9 ) ) {
F_130 ( V_9 ) ;
return;
}
F_178 ( L_17 ,
V_9 -> V_5 -> V_7 -> V_37 , & V_9 -> V_153 ) ;
if ( V_5 -> V_44 . V_55 > 1 && ! V_5 -> V_44 . V_168 ) {
struct V_155 V_153 ;
V_153 . V_274 [ 0 ] = F_179 ( 0xfe800000 ) ;
V_153 . V_274 [ 1 ] = 0 ;
if ( ! F_180 ( V_153 . V_207 + 8 , V_5 -> V_7 ) &&
F_152 ( & V_9 -> V_153 , & V_153 ) ) {
V_5 -> V_44 . V_168 = 1 ;
F_40 ( L_18 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
}
}
F_175 ( V_9 , 1 ) ;
}
void F_181 ( struct V_6 * V_7 , const struct V_155 * V_153 )
{
struct V_155 V_275 ;
if ( V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_182 ( V_153 , & V_275 ) ;
F_46 ( V_7 , & V_275 ) ;
}
void F_183 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_155 V_275 ;
if ( V_5 -> V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_182 ( V_153 , & V_275 ) ;
F_184 ( V_5 , & V_275 ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
struct V_155 V_153 ;
if ( V_9 -> V_175 == 127 )
return;
F_138 ( & V_153 , & V_9 -> V_153 , V_9 -> V_175 ) ;
if ( F_185 ( & V_153 ) )
return;
F_186 ( V_9 -> V_5 -> V_7 , & V_153 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
struct V_155 V_153 ;
if ( V_9 -> V_175 == 127 )
return;
F_138 ( & V_153 , & V_9 -> V_153 , V_9 -> V_175 ) ;
if ( F_185 ( & V_153 ) )
return;
F_187 ( V_9 -> V_5 , & V_153 ) ;
}
static int F_188 ( T_3 * V_276 , struct V_6 * V_7 )
{
if ( V_7 -> V_277 != V_278 )
return - 1 ;
memcpy ( V_276 , V_7 -> V_279 , 3 ) ;
memcpy ( V_276 + 5 , V_7 -> V_279 + 3 , 3 ) ;
if ( V_7 -> V_280 ) {
V_276 [ 3 ] = ( V_7 -> V_280 >> 8 ) & 0xFF ;
V_276 [ 4 ] = V_7 -> V_280 & 0xFF ;
} else {
V_276 [ 3 ] = 0xFF ;
V_276 [ 4 ] = 0xFE ;
V_276 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_189 ( T_3 * V_276 , struct V_6 * V_7 )
{
if ( V_7 -> V_277 != V_281 )
return - 1 ;
memcpy ( V_276 , V_7 -> V_279 , 8 ) ;
V_276 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_190 ( T_3 * V_276 , struct V_6 * V_7 )
{
union V_282 * V_283 ;
if ( V_7 -> V_277 != V_284 )
return - 1 ;
V_283 = (union V_282 * ) V_7 -> V_279 ;
memcpy ( V_276 , & V_283 -> V_285 . V_286 , sizeof( V_283 -> V_285 . V_286 ) ) ;
V_276 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_191 ( T_3 * V_276 , struct V_6 * V_7 )
{
if ( V_7 -> V_277 != V_287 )
return - 1 ;
memset ( V_276 , 0 , 7 ) ;
V_276 [ 7 ] = * ( T_3 * ) V_7 -> V_279 ;
return 0 ;
}
static int F_192 ( T_3 * V_276 , struct V_6 * V_7 )
{
if ( V_7 -> V_277 != V_288 )
return - 1 ;
memcpy ( V_276 , V_7 -> V_279 + 12 , 8 ) ;
V_276 [ 0 ] |= 2 ;
return 0 ;
}
static int F_193 ( T_3 * V_276 , T_4 V_153 )
{
if ( V_153 == 0 )
return - 1 ;
V_276 [ 0 ] = ( F_194 ( V_153 ) || F_195 ( V_153 ) ||
F_196 ( V_153 ) || F_197 ( V_153 ) ||
F_198 ( V_153 ) || F_199 ( V_153 ) ||
F_200 ( V_153 ) || F_201 ( V_153 ) ||
F_202 ( V_153 ) || F_203 ( V_153 ) ||
F_204 ( V_153 ) ) ? 0x00 : 0x02 ;
V_276 [ 1 ] = 0 ;
V_276 [ 2 ] = 0x5E ;
V_276 [ 3 ] = 0xFE ;
memcpy ( V_276 + 4 , & V_153 , 4 ) ;
return 0 ;
}
static int F_205 ( T_3 * V_276 , struct V_6 * V_7 )
{
if ( V_7 -> V_58 & V_59 )
return F_193 ( V_276 , * ( T_4 * ) V_7 -> V_279 ) ;
return - 1 ;
}
static int F_206 ( T_3 * V_276 , struct V_6 * V_7 )
{
return F_193 ( V_276 , * ( T_4 * ) V_7 -> V_279 ) ;
}
static int F_180 ( T_3 * V_276 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_289 :
case V_290 :
return F_188 ( V_276 , V_7 ) ;
case V_291 :
return F_191 ( V_276 , V_7 ) ;
case V_292 :
return F_192 ( V_276 , V_7 ) ;
case V_57 :
return F_205 ( V_276 , V_7 ) ;
case V_293 :
return F_206 ( V_276 , V_7 ) ;
case V_294 :
return F_189 ( V_276 , V_7 ) ;
case V_295 :
return F_190 ( V_276 , V_7 ) ;
}
return - 1 ;
}
static int F_207 ( T_3 * V_276 , struct V_4 * V_5 )
{
int V_101 = - 1 ;
struct V_8 * V_9 ;
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_158 == V_264 && ! ( V_9 -> V_52 & V_138 ) ) {
memcpy ( V_276 , V_9 -> V_153 . V_207 + 8 , 8 ) ;
V_101 = 0 ;
break;
}
}
F_167 ( & V_5 -> V_43 ) ;
return V_101 ;
}
static void F_208 ( struct V_4 * V_5 )
{
V_296:
F_209 ( V_5 -> V_211 , sizeof( V_5 -> V_211 ) ) ;
V_5 -> V_211 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_211 [ 0 ] == 0xfd &&
( V_5 -> V_211 [ 1 ] & V_5 -> V_211 [ 2 ] & V_5 -> V_211 [ 3 ] & V_5 -> V_211 [ 4 ] & V_5 -> V_211 [ 5 ] & V_5 -> V_211 [ 6 ] ) == 0xff &&
( V_5 -> V_211 [ 7 ] & 0x80 ) )
goto V_296;
if ( ( V_5 -> V_211 [ 0 ] | V_5 -> V_211 [ 1 ] ) == 0 ) {
if ( V_5 -> V_211 [ 2 ] == 0x5e && V_5 -> V_211 [ 3 ] == 0xfe )
goto V_296;
if ( ( V_5 -> V_211 [ 2 ] | V_5 -> V_211 [ 3 ] | V_5 -> V_211 [ 4 ] | V_5 -> V_211 [ 5 ] | V_5 -> V_211 [ 6 ] | V_5 -> V_211 [ 7 ] ) == 0x00 )
goto V_296;
}
}
static void V_63 ( unsigned long V_174 )
{
struct V_4 * V_5 = (struct V_4 * ) V_174 ;
unsigned long V_19 ;
F_107 () ;
F_128 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 )
goto V_172;
F_208 ( V_5 ) ;
V_19 = V_20 +
V_5 -> V_44 . V_215 * V_3 -
V_5 -> V_44 . V_210 * V_5 -> V_44 . V_217 * V_5 -> V_48 -> V_218 -
V_5 -> V_44 . V_216 * V_3 ;
if ( F_135 ( V_19 , V_20 ) ) {
F_25 ( L_19 ,
V_36 , V_5 -> V_7 -> V_37 ) ;
goto V_172;
}
if ( ! F_210 ( & V_5 -> V_62 , V_19 ) )
F_38 ( V_5 ) ;
V_172:
F_136 ( & V_5 -> V_43 ) ;
F_121 () ;
F_93 ( V_5 ) ;
}
static void F_144 ( struct V_4 * V_5 , struct V_155 * V_196 )
{
if ( V_196 && memcmp ( V_5 -> V_211 , & V_196 -> V_207 [ 8 ] , 8 ) == 0 )
F_208 ( V_5 ) ;
}
static void
F_211 ( struct V_155 * V_297 , int V_298 , struct V_6 * V_7 ,
unsigned long V_19 , T_1 V_52 )
{
struct V_299 V_300 = {
. V_301 = V_302 ,
. V_303 = V_304 ,
. V_305 = V_7 -> V_85 ,
. V_306 = V_19 ,
. V_307 = V_298 ,
. V_308 = V_309 | V_52 ,
. V_310 . V_311 = F_31 ( V_7 ) ,
. V_312 = V_313 ,
} ;
V_300 . V_314 = * V_297 ;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 && ( V_7 -> V_52 & V_315 ) )
V_300 . V_308 |= V_316 ;
#endif
F_212 ( & V_300 ) ;
}
static struct V_159 * F_139 ( const struct V_155 * V_297 ,
int V_298 ,
const struct V_6 * V_7 ,
T_1 V_52 , T_1 V_317 )
{
struct V_318 * V_319 ;
struct V_159 * V_150 = NULL ;
struct V_320 * V_142 ;
V_142 = F_213 ( F_31 ( V_7 ) , V_302 ) ;
if ( V_142 == NULL )
return NULL ;
F_162 ( & V_142 -> V_321 ) ;
V_319 = F_214 ( & V_142 -> V_322 , V_297 , V_298 , NULL , 0 ) ;
if ( ! V_319 )
goto V_172;
for ( V_150 = V_319 -> V_323 ; V_150 ; V_150 = V_150 -> V_226 . V_324 ) {
if ( V_150 -> V_226 . V_7 -> V_85 != V_7 -> V_85 )
continue;
if ( ( V_150 -> V_193 & V_52 ) != V_52 )
continue;
if ( ( V_150 -> V_193 & V_317 ) != 0 )
continue;
F_215 ( & V_150 -> V_226 ) ;
break;
}
V_172:
F_167 ( & V_142 -> V_321 ) ;
return V_150 ;
}
static void F_216 ( struct V_6 * V_7 )
{
struct V_299 V_300 = {
. V_301 = V_325 ,
. V_303 = V_304 ,
. V_305 = V_7 -> V_85 ,
. V_307 = 8 ,
. V_308 = V_309 ,
. V_310 . V_311 = F_31 ( V_7 ) ,
} ;
F_217 ( & V_300 . V_314 , F_179 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_212 ( & V_300 ) ;
}
static void F_218 ( struct V_6 * V_7 )
{
struct V_299 V_300 = {
. V_301 = V_326 ,
. V_303 = V_304 ,
. V_305 = V_7 -> V_85 ,
. V_307 = 96 ,
. V_308 = V_309 | V_316 ,
. V_310 . V_311 = F_31 ( V_7 ) ,
} ;
F_212 ( & V_300 ) ;
}
static struct V_4 * F_219 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_106 ( - V_102 ) ;
if ( V_5 -> V_44 . V_168 )
return F_106 ( - V_169 ) ;
if ( ! ( V_7 -> V_52 & V_54 ) )
F_216 ( V_7 ) ;
return V_5 ;
}
void F_220 ( struct V_6 * V_7 , T_3 * V_327 , int V_134 , bool V_328 )
{
struct V_329 * V_330 ;
V_212 V_187 ;
V_212 V_214 ;
int V_161 ;
struct V_4 * V_112 ;
struct V_100 * V_100 = F_31 ( V_7 ) ;
V_330 = (struct V_329 * ) V_327 ;
if ( V_134 < sizeof( struct V_329 ) ) {
F_35 ( ( L_20 ) ) ;
return;
}
V_161 = F_105 ( & V_330 -> V_190 ) ;
if ( V_161 & ( V_163 | V_331 ) )
return;
V_187 = F_221 ( V_330 -> V_332 ) ;
V_214 = F_221 ( V_330 -> V_333 ) ;
if ( V_214 > V_187 ) {
F_222 ( L_21 ) ;
return;
}
V_112 = F_223 ( V_7 ) ;
if ( V_112 == NULL ) {
F_224 ( L_22 ,
V_7 -> V_37 ) ;
return;
}
if ( V_330 -> V_183 ) {
struct V_159 * V_150 ;
unsigned long V_334 ;
if ( V_3 > V_335 )
V_334 = F_134 ( V_187 , V_3 ) ;
else
V_334 = F_134 ( V_187 , V_335 ) ;
if ( F_225 ( V_334 ) )
V_334 *= V_3 ;
V_150 = F_139 ( & V_330 -> V_190 ,
V_330 -> V_175 ,
V_7 ,
V_336 | V_337 ,
V_191 | V_192 ) ;
if ( V_150 ) {
if ( V_187 == 0 ) {
F_140 ( V_150 ) ;
V_150 = NULL ;
} else if ( F_225 ( V_334 ) ) {
F_141 ( V_150 , V_20 + V_334 ) ;
} else {
F_226 ( V_150 ) ;
}
} else if ( V_187 ) {
T_5 V_19 = 0 ;
int V_52 = V_336 | V_337 ;
if ( F_225 ( V_334 ) ) {
V_52 |= V_194 ;
V_19 = F_227 ( V_334 ) ;
}
F_211 ( & V_330 -> V_190 , V_330 -> V_175 ,
V_7 , V_19 , V_52 ) ;
}
F_95 ( V_150 ) ;
}
if ( V_330 -> V_338 && V_112 -> V_44 . V_338 ) {
struct V_8 * V_9 ;
struct V_155 V_153 ;
int V_339 = 0 , V_340 = 0 ;
bool V_176 = false ;
if ( V_330 -> V_175 == 64 ) {
memcpy ( & V_153 , & V_330 -> V_190 , 8 ) ;
if ( ! F_185 ( & V_112 -> V_68 ) ) {
F_162 ( & V_112 -> V_43 ) ;
memcpy ( V_153 . V_207 + 8 ,
V_112 -> V_68 . V_207 + 8 , 8 ) ;
F_167 ( & V_112 -> V_43 ) ;
V_176 = true ;
} else if ( F_180 ( V_153 . V_207 + 8 , V_7 ) &&
F_207 ( V_153 . V_207 + 8 , V_112 ) ) {
F_93 ( V_112 ) ;
return;
}
goto V_341;
}
F_224 ( L_23 ,
V_330 -> V_175 ) ;
F_93 ( V_112 ) ;
return;
V_341:
V_9 = F_173 ( V_100 , & V_153 , V_7 , 1 ) ;
if ( V_9 == NULL && V_187 ) {
int V_204 = V_112 -> V_44 . V_204 ;
T_1 V_205 = 0 ;
#ifdef F_228
if ( V_112 -> V_44 . V_342 &&
! V_100 -> V_23 . V_116 -> V_50 && V_328 )
V_205 = V_219 ;
#endif
if ( ! V_204 ||
F_146 ( V_112 ) < V_204 )
V_9 = F_104 ( V_112 , & V_153 , V_330 -> V_175 ,
V_161 & V_220 ,
V_205 ) ;
if ( F_147 ( V_9 ) ) {
F_93 ( V_112 ) ;
return;
}
V_340 = V_339 = 1 ;
V_9 -> V_1 = V_20 ;
V_9 -> V_176 = V_176 ;
F_148 ( V_9 ) ;
}
if ( V_9 ) {
int V_52 ;
unsigned long V_206 ;
#ifdef F_41
struct V_8 * V_195 ;
#endif
T_1 V_343 ;
F_108 ( & V_9 -> V_43 ) ;
V_206 = V_20 ;
if ( V_9 -> V_187 > ( V_206 - V_9 -> V_72 ) / V_3 )
V_343 = V_9 -> V_187 - ( V_206 - V_9 -> V_72 ) / V_3 ;
else
V_343 = 0 ;
if ( ! V_340 && V_343 ) {
if ( V_187 > V_344 ||
V_187 > V_343 )
V_340 = 1 ;
else if ( V_343 <= V_344 ) {
if ( V_214 != V_9 -> V_214 ) {
V_187 = V_343 ;
V_340 = 1 ;
}
} else {
V_187 = V_344 ;
if ( V_187 < V_214 )
V_214 = V_187 ;
V_340 = 1 ;
}
}
if ( V_340 ) {
V_9 -> V_187 = V_187 ;
V_9 -> V_214 = V_214 ;
V_9 -> V_72 = V_206 ;
V_52 = V_9 -> V_52 ;
V_9 -> V_52 &= ~ V_237 ;
F_117 ( & V_9 -> V_43 ) ;
if ( ! ( V_52 & V_138 ) )
F_137 ( 0 , V_9 ) ;
} else
F_117 ( & V_9 -> V_43 ) ;
#ifdef F_41
F_162 ( & V_112 -> V_43 ) ;
F_81 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_200 , V_345 , V_346 ;
if ( V_9 != V_195 -> V_184 )
continue;
V_200 = ( V_206 - V_195 -> V_1 ) / V_3 ;
V_345 = V_112 -> V_44 . V_213 - V_200 ;
if ( V_345 < 0 )
V_345 = 0 ;
V_346 = V_112 -> V_44 . V_215 -
V_112 -> V_44 . V_216 -
V_200 ;
if ( V_346 < 0 )
V_346 = 0 ;
if ( V_187 > V_345 )
V_187 = V_345 ;
if ( V_214 > V_346 )
V_214 = V_346 ;
F_108 ( & V_195 -> V_43 ) ;
V_52 = V_195 -> V_52 ;
V_195 -> V_187 = V_187 ;
V_195 -> V_214 = V_214 ;
V_195 -> V_72 = V_206 ;
if ( V_214 > 0 )
V_195 -> V_52 &= ~ V_237 ;
F_117 ( & V_195 -> V_43 ) ;
if ( ! ( V_52 & V_138 ) )
F_137 ( 0 , V_195 ) ;
}
if ( ( V_339 || F_21 ( & V_112 -> V_61 ) ) && V_112 -> V_44 . V_67 > 0 ) {
F_167 ( & V_112 -> V_43 ) ;
F_143 ( V_9 , NULL ) ;
} else {
F_167 ( & V_112 -> V_43 ) ;
}
#endif
F_130 ( V_9 ) ;
F_229 ( 0 ) ;
}
}
F_230 ( V_347 , V_112 , V_330 ) ;
F_93 ( V_112 ) ;
}
int F_231 ( struct V_100 * V_100 , void T_6 * V_348 )
{
struct V_349 V_350 ;
struct V_6 * V_7 ;
int V_101 = - V_114 ;
F_232 () ;
V_101 = - V_351 ;
if ( F_233 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
goto V_352;
V_7 = F_69 ( V_100 , V_350 . V_353 ) ;
V_101 = - V_166 ;
if ( V_7 == NULL )
goto V_352;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 ) {
const struct V_354 * V_355 = V_7 -> V_356 ;
struct V_357 V_358 ;
struct V_359 V_143 ;
V_101 = - V_165 ;
if ( ! ( F_105 ( & V_350 . V_360 ) & V_222 ) )
goto V_352;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_361 . V_252 = V_350 . V_360 . V_274 [ 3 ] ;
V_143 . V_361 . V_253 = 0 ;
V_143 . V_361 . V_362 = 4 ;
V_143 . V_361 . V_363 = 5 ;
V_143 . V_361 . V_364 = V_365 ;
V_143 . V_361 . V_366 = 64 ;
V_358 . V_367 . V_368 = ( V_369 void T_6 * ) & V_143 ;
if ( V_355 -> V_370 ) {
T_7 V_371 = F_234 () ;
F_235 ( V_372 ) ;
V_101 = V_355 -> V_370 ( V_7 , & V_358 , V_373 ) ;
F_235 ( V_371 ) ;
} else
V_101 = - V_374 ;
if ( V_101 == 0 ) {
V_101 = - V_102 ;
V_7 = F_236 ( V_100 , V_143 . V_37 ) ;
if ( ! V_7 )
goto V_352;
V_101 = F_237 ( V_7 ) ;
}
}
#endif
V_352:
F_89 () ;
return V_101 ;
}
static int F_238 ( struct V_100 * V_100 , int V_85 , const struct V_155 * V_297 ,
unsigned int V_298 , T_8 V_375 , V_212 V_214 ,
V_212 V_187 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_158 ;
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_376 ;
F_28 () ;
if ( V_298 > 128 )
return - V_114 ;
if ( ! V_187 || V_214 > V_187 )
return - V_114 ;
V_7 = F_69 ( V_100 , V_85 ) ;
if ( ! V_7 )
return - V_166 ;
V_5 = F_219 ( V_7 ) ;
if ( F_111 ( V_5 ) )
return F_112 ( V_5 ) ;
V_158 = F_239 ( V_297 ) ;
V_376 = F_134 ( V_187 , V_3 ) ;
if ( F_225 ( V_376 ) ) {
V_19 = F_227 ( V_376 * V_3 ) ;
V_187 = V_376 ;
V_52 = V_194 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_375 |= V_185 ;
}
V_376 = F_134 ( V_214 , V_3 ) ;
if ( F_225 ( V_376 ) ) {
if ( V_376 == 0 )
V_375 |= V_237 ;
V_214 = V_376 ;
}
V_9 = F_104 ( V_5 , V_297 , V_298 , V_158 , V_375 ) ;
if ( ! F_111 ( V_9 ) ) {
F_125 ( & V_9 -> V_43 ) ;
V_9 -> V_187 = V_187 ;
V_9 -> V_214 = V_214 ;
V_9 -> V_72 = V_20 ;
F_126 ( & V_9 -> V_43 ) ;
F_211 ( & V_9 -> V_153 , V_9 -> V_175 , V_7 ,
V_19 , V_52 ) ;
F_148 ( V_9 ) ;
F_130 ( V_9 ) ;
F_229 ( 0 ) ;
return 0 ;
}
return F_112 ( V_9 ) ;
}
static int F_240 ( struct V_100 * V_100 , int V_85 , const struct V_155 * V_297 ,
unsigned int V_298 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_298 > 128 )
return - V_114 ;
V_7 = F_69 ( V_100 , V_85 ) ;
if ( ! V_7 )
return - V_166 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_377 ;
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_175 == V_298 &&
F_152 ( V_297 , & V_9 -> V_153 ) ) {
F_10 ( V_9 ) ;
F_167 ( & V_5 -> V_43 ) ;
F_124 ( V_9 ) ;
if ( F_21 ( & V_5 -> V_34 ) )
F_241 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_167 ( & V_5 -> V_43 ) ;
return - V_165 ;
}
int F_242 ( struct V_100 * V_100 , void T_6 * V_348 )
{
struct V_349 V_350 ;
int V_101 ;
if ( ! F_243 ( V_100 -> V_378 , V_379 ) )
return - V_380 ;
if ( F_233 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
return - V_351 ;
F_232 () ;
V_101 = F_238 ( V_100 , V_350 . V_353 , & V_350 . V_360 ,
V_350 . V_381 , V_185 ,
V_382 , V_382 ) ;
F_89 () ;
return V_101 ;
}
int F_244 ( struct V_100 * V_100 , void T_6 * V_348 )
{
struct V_349 V_350 ;
int V_101 ;
if ( ! F_243 ( V_100 -> V_378 , V_379 ) )
return - V_380 ;
if ( F_233 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
return - V_351 ;
F_232 () ;
V_101 = F_240 ( V_100 , V_350 . V_353 , & V_350 . V_360 ,
V_350 . V_381 ) ;
F_89 () ;
return V_101 ;
}
static void F_245 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_298 , int V_158 )
{
struct V_8 * V_9 ;
V_9 = F_104 ( V_5 , V_153 , V_298 , V_158 , V_185 ) ;
if ( ! F_111 ( V_9 ) ) {
F_125 ( & V_9 -> V_43 ) ;
V_9 -> V_52 &= ~ V_138 ;
F_126 ( & V_9 -> V_43 ) ;
F_137 ( V_383 , V_9 ) ;
F_130 ( V_9 ) ;
}
}
static void F_246 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_100 * V_100 = F_31 ( V_5 -> V_7 ) ;
int V_158 ;
F_28 () ;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
memcpy ( & V_153 . V_274 [ 3 ] , V_5 -> V_7 -> V_279 , 4 ) ;
if ( V_5 -> V_7 -> V_52 & V_315 ) {
V_153 . V_274 [ 0 ] = F_179 ( 0xfe800000 ) ;
V_158 = V_264 ;
} else {
V_158 = V_222 ;
}
if ( V_153 . V_274 [ 3 ] ) {
F_245 ( V_5 , & V_153 , 128 , V_158 ) ;
return;
}
F_85 (net, dev) {
struct V_384 * V_385 = F_247 ( V_7 ) ;
if ( V_385 && ( V_7 -> V_52 & V_78 ) ) {
struct V_386 * V_135 ;
int V_387 = V_158 ;
for ( V_135 = V_385 -> V_388 ; V_135 ; V_135 = V_135 -> V_389 ) {
int V_298 ;
V_153 . V_274 [ 3 ] = V_135 -> V_390 ;
if ( V_135 -> V_391 == V_392 )
continue;
if ( V_135 -> V_391 >= V_393 ) {
if ( V_5 -> V_7 -> V_52 & V_315 )
continue;
V_387 |= V_267 ;
}
if ( V_5 -> V_7 -> V_52 & V_315 )
V_298 = 64 ;
else
V_298 = 96 ;
F_245 ( V_5 , & V_153 , V_298 , V_387 ) ;
}
}
}
}
static void F_248 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_394 ;
struct V_8 * V_395 ;
struct V_159 * V_396 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_245 ( V_5 , & V_397 , 128 , V_267 ) ;
F_85 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_394 -> V_37 , V_7 -> V_37 ) )
continue;
V_5 = F_48 ( V_394 ) ;
if ( ! V_5 )
continue;
F_162 ( & V_5 -> V_43 ) ;
F_81 (sp_ifa, &idev->addr_list, if_list) {
if ( V_395 -> V_52 & ( V_270 | V_138 ) )
continue;
if ( V_395 -> V_150 )
continue;
V_396 = F_110 ( V_5 , & V_395 -> V_153 , 0 ) ;
if ( ! F_111 ( V_396 ) ) {
V_395 -> V_150 = V_396 ;
F_249 ( V_396 ) ;
}
}
F_167 ( & V_5 -> V_43 ) ;
}
}
static void F_250 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_8 * V_9 ;
T_1 V_205 = V_185 ;
#ifdef F_228
if ( V_5 -> V_44 . V_342 &&
! F_31 ( V_5 -> V_7 ) -> V_23 . V_116 -> V_50 )
V_205 |= V_219 ;
#endif
V_9 = F_104 ( V_5 , V_153 , 64 , V_264 , V_205 ) ;
if ( ! F_111 ( V_9 ) ) {
F_211 ( & V_9 -> V_153 , V_9 -> V_175 , V_5 -> V_7 , 0 , 0 ) ;
F_148 ( V_9 ) ;
F_130 ( V_9 ) ;
}
}
static void F_251 ( struct V_6 * V_7 )
{
struct V_155 V_153 ;
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_7 -> type != V_289 ) &&
( V_7 -> type != V_290 ) &&
( V_7 -> type != V_291 ) &&
( V_7 -> type != V_292 ) &&
( V_7 -> type != V_294 ) &&
( V_7 -> type != V_295 ) ) {
return;
}
V_5 = F_219 ( V_7 ) ;
if ( F_111 ( V_5 ) )
return;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
V_153 . V_274 [ 0 ] = F_179 ( 0xFE800000 ) ;
if ( F_180 ( V_153 . V_207 + 8 , V_7 ) == 0 )
F_250 ( V_5 , & V_153 ) ;
}
static void F_252 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
if ( V_7 -> V_58 & V_59 ) {
struct V_155 V_153 ;
F_217 ( & V_153 , F_179 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_211 ( & V_153 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_180 ( V_153 . V_207 + 8 , V_7 ) )
F_250 ( V_5 , & V_153 ) ;
return;
}
F_246 ( V_5 ) ;
if ( V_7 -> V_52 & V_315 )
F_216 ( V_7 ) ;
else
F_218 ( V_7 ) ;
}
static void F_253 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_155 V_153 ;
F_40 ( L_25 , V_36 , V_7 -> V_37 ) ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_217 ( & V_153 , F_179 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_211 ( & V_153 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_180 ( V_153 . V_207 + 8 , V_7 ) )
F_250 ( V_5 , & V_153 ) ;
}
static inline int
F_254 ( struct V_4 * V_5 , struct V_6 * V_398 )
{
struct V_155 V_399 ;
if ( ! F_168 ( V_398 , & V_399 , V_138 ) ) {
F_250 ( V_5 , & V_399 ) ;
return 0 ;
}
return - 1 ;
}
static void F_255 ( struct V_4 * V_5 )
{
struct V_6 * V_398 ;
struct V_100 * V_100 = F_31 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_400 &&
( V_398 = F_69 ( V_100 , V_5 -> V_7 -> V_400 ) ) ) {
if ( ! F_254 ( V_5 , V_398 ) )
return;
}
F_85 (net, link_dev) {
if ( ! F_254 ( V_5 , V_398 ) )
return;
}
F_23 ( L_26 ) ;
}
static void F_256 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_219 ( V_7 ) ;
if ( F_111 ( V_5 ) ) {
F_23 ( L_27 ) ;
return;
}
F_255 ( V_5 ) ;
}
static int F_257 ( struct V_401 * V_402 , unsigned long V_90 ,
void * V_174 )
{
struct V_6 * V_7 = (struct V_6 * ) V_174 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_403 = 0 ;
int V_101 ;
switch ( V_90 ) {
case V_404 :
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( ! V_5 )
return F_258 ( - V_33 ) ;
}
break;
case V_180 :
case V_405 :
if ( V_7 -> V_52 & V_406 )
break;
if ( V_90 == V_180 ) {
if ( ! F_4 ( V_7 ) ) {
F_40 ( L_28 ,
V_7 -> V_37 ) ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 )
V_5 = F_27 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_70 |= V_71 ;
V_403 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_70 & V_71 )
break;
V_5 -> V_70 |= V_71 ;
}
F_40 ( L_29 ,
V_7 -> V_37 ) ;
V_403 = 1 ;
}
switch ( V_7 -> type ) {
#if F_39 ( V_56 )
case V_57 :
F_252 ( V_7 ) ;
break;
#endif
#if F_39 ( V_407 )
case V_293 :
F_253 ( V_7 ) ;
break;
#endif
case V_65 :
F_256 ( V_7 ) ;
break;
case V_408 :
F_248 ( V_7 ) ;
break;
default:
F_251 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_403 )
F_259 ( V_5 ) ;
if ( V_5 -> V_44 . V_46 != V_7 -> V_41 &&
V_7 -> V_41 >= V_42 ) {
F_260 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
}
V_5 -> V_72 = V_20 ;
F_261 ( V_409 , V_5 ) ;
if ( V_7 -> V_41 < V_42 )
F_241 ( V_7 , 1 ) ;
}
break;
case V_410 :
if ( V_5 && V_7 -> V_41 >= V_42 ) {
F_260 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( V_5 )
break;
}
case V_189 :
case V_411 :
F_241 ( V_7 , V_90 != V_189 ) ;
break;
case V_412 :
if ( V_5 ) {
F_262 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_101 = F_37 ( V_5 ) ;
if ( V_101 )
return F_258 ( V_101 ) ;
}
break;
case V_413 :
case V_414 :
F_263 ( V_7 , V_90 ) ;
break;
}
return V_415 ;
}
static void F_263 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_90 == V_414 )
F_264 ( V_5 ) ;
else if ( V_90 == V_413 )
F_265 ( V_5 ) ;
}
static int F_241 ( struct V_6 * V_7 , int V_416 )
{
struct V_100 * V_100 = F_31 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_8 * V_135 ;
int V_148 , V_227 ;
F_28 () ;
F_266 ( V_100 , V_7 ) ;
F_267 ( & V_49 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_166 ;
if ( V_416 ) {
V_5 -> V_38 = 1 ;
F_268 ( V_7 -> V_73 , NULL ) ;
F_262 ( V_5 ) ;
}
for ( V_227 = 0 ; V_227 < V_417 ; V_227 ++ ) {
struct V_125 * V_121 = & V_177 [ V_227 ] ;
F_125 ( & V_170 ) ;
V_418:
F_75 (ifa, h, addr_lst) {
if ( V_135 -> V_5 == V_5 ) {
F_127 ( & V_135 -> V_147 ) ;
F_6 ( V_135 ) ;
goto V_418;
}
}
F_126 ( & V_170 ) ;
}
F_128 ( & V_5 -> V_43 ) ;
if ( ! V_416 )
V_5 -> V_70 &= ~ ( V_419 | V_420 | V_71 ) ;
#ifdef F_41
if ( V_416 && F_7 ( & V_5 -> V_62 ) )
F_93 ( V_5 ) ;
while ( ! F_21 ( & V_5 -> V_61 ) ) {
V_135 = F_269 ( & V_5 -> V_61 ,
struct V_8 , V_179 ) ;
F_129 ( & V_135 -> V_179 ) ;
F_136 ( & V_5 -> V_43 ) ;
F_125 ( & V_135 -> V_43 ) ;
if ( V_135 -> V_184 ) {
F_130 ( V_135 -> V_184 ) ;
V_135 -> V_184 = NULL ;
}
F_126 ( & V_135 -> V_43 ) ;
F_130 ( V_135 ) ;
F_128 ( & V_5 -> V_43 ) ;
}
#endif
while ( ! F_21 ( & V_5 -> V_34 ) ) {
V_135 = F_269 ( & V_5 -> V_34 ,
struct V_8 , V_154 ) ;
F_6 ( V_135 ) ;
F_129 ( & V_135 -> V_154 ) ;
F_136 ( & V_5 -> V_43 ) ;
F_125 ( & V_135 -> V_173 ) ;
V_148 = V_135 -> V_148 ;
V_135 -> V_148 = V_149 ;
F_126 ( & V_135 -> V_173 ) ;
if ( V_148 != V_149 ) {
F_270 ( V_188 , V_135 ) ;
F_123 ( V_189 , V_135 ) ;
}
F_130 ( V_135 ) ;
F_128 ( & V_5 -> V_43 ) ;
}
F_136 ( & V_5 -> V_43 ) ;
if ( V_416 )
F_271 ( V_5 ) ;
else
F_272 ( V_5 ) ;
V_5 -> V_72 = V_20 ;
if ( V_416 ) {
F_3 ( V_5 ) ;
F_36 ( & V_49 , V_5 -> V_48 ) ;
F_267 ( & V_49 , V_7 ) ;
F_93 ( V_5 ) ;
}
return 0 ;
}
static void V_18 ( unsigned long V_174 )
{
struct V_8 * V_9 = (struct V_8 * ) V_174 ;
struct V_4 * V_5 = V_9 -> V_5 ;
F_273 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_70 & V_71 ) )
goto V_172;
if ( ! F_274 ( V_5 ) )
goto V_172;
if ( V_5 -> V_70 & V_420 )
goto V_172;
F_108 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_421 ++ < V_5 -> V_44 . V_60 ) {
F_9 ( V_9 , V_17 ,
( V_9 -> V_421 == V_5 -> V_44 . V_60 ) ?
V_5 -> V_44 . V_422 :
V_5 -> V_44 . V_423 ) ;
F_117 ( & V_9 -> V_43 ) ;
F_275 ( V_5 -> V_7 , & V_9 -> V_153 , & V_77 ) ;
} else {
F_117 ( & V_9 -> V_43 ) ;
F_23 ( L_30 , V_5 -> V_7 -> V_37 ) ;
}
V_172:
F_276 ( & V_5 -> V_43 ) ;
F_130 ( V_9 ) ;
}
static void F_277 ( struct V_8 * V_9 )
{
unsigned long V_424 ;
struct V_4 * V_5 = V_9 -> V_5 ;
if ( V_9 -> V_52 & V_219 )
V_424 = 0 ;
else
V_424 = F_278 () % ( V_5 -> V_44 . V_422 ? : 1 ) ;
V_9 -> V_421 = V_5 -> V_44 . V_217 ;
F_9 ( V_9 , V_14 , V_424 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_181 ( V_7 , & V_9 -> V_153 ) ;
F_279 ( V_9 -> V_153 . V_274 [ 3 ] ) ;
F_162 ( & V_5 -> V_43 ) ;
F_108 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_148 == V_149 )
goto V_172;
if ( V_7 -> V_52 & ( V_53 | V_54 ) ||
V_5 -> V_44 . V_55 < 1 ||
! ( V_9 -> V_52 & V_138 ) ||
V_9 -> V_52 & V_425 ) {
V_9 -> V_52 &= ~ ( V_138 | V_219 | V_270 ) ;
F_117 ( & V_9 -> V_43 ) ;
F_167 ( & V_5 -> V_43 ) ;
F_280 ( V_9 ) ;
return;
}
if ( ! ( V_5 -> V_70 & V_71 ) ) {
F_117 ( & V_9 -> V_43 ) ;
F_167 ( & V_5 -> V_43 ) ;
F_10 ( V_9 ) ;
F_175 ( V_9 , 0 ) ;
return;
}
if ( V_9 -> V_52 & V_219 )
F_249 ( V_9 -> V_150 ) ;
F_277 ( V_9 ) ;
V_172:
F_117 ( & V_9 -> V_43 ) ;
F_167 ( & V_5 -> V_43 ) ;
}
static void V_16 ( unsigned long V_174 )
{
struct V_8 * V_9 = (struct V_8 * ) V_174 ;
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_155 V_426 ;
if ( ! V_9 -> V_421 && F_176 ( V_9 ) )
goto V_172;
F_273 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_70 & V_71 ) ) {
F_276 ( & V_5 -> V_43 ) ;
goto V_172;
}
F_108 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_148 == V_149 ) {
F_117 ( & V_9 -> V_43 ) ;
F_276 ( & V_5 -> V_43 ) ;
goto V_172;
}
if ( V_9 -> V_421 == 0 ) {
V_9 -> V_52 &= ~ ( V_138 | V_219 | V_270 ) ;
F_117 ( & V_9 -> V_43 ) ;
F_276 ( & V_5 -> V_43 ) ;
F_280 ( V_9 ) ;
goto V_172;
}
V_9 -> V_421 -- ;
F_9 ( V_9 , V_14 , V_9 -> V_5 -> V_48 -> V_218 ) ;
F_117 ( & V_9 -> V_43 ) ;
F_276 ( & V_5 -> V_43 ) ;
F_182 ( & V_9 -> V_153 , & V_426 ) ;
F_281 ( V_9 -> V_5 -> V_7 , NULL , & V_9 -> V_153 , & V_426 , & V_69 ) ;
V_172:
F_130 ( V_9 ) ;
}
static void F_280 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_5 -> V_7 ;
F_137 ( V_383 , V_9 ) ;
if ( F_274 ( V_9 -> V_5 ) &&
V_9 -> V_5 -> V_44 . V_60 > 0 &&
( V_7 -> V_52 & V_54 ) == 0 &&
( F_105 ( & V_9 -> V_153 ) & V_331 ) ) {
F_275 ( V_9 -> V_5 -> V_7 , & V_9 -> V_153 , & V_77 ) ;
F_125 ( & V_9 -> V_43 ) ;
V_9 -> V_421 = 1 ;
V_9 -> V_5 -> V_70 |= V_419 ;
F_9 ( V_9 , V_17 , V_9 -> V_5 -> V_44 . V_423 ) ;
F_126 ( & V_9 -> V_43 ) ;
}
}
static void F_259 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
F_162 ( & V_5 -> V_43 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
F_108 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_52 & V_138 &&
V_9 -> V_148 == V_272 )
F_277 ( V_9 ) ;
F_117 ( & V_9 -> V_43 ) ;
}
F_167 ( & V_5 -> V_43 ) ;
}
static struct V_8 * F_282 ( struct V_427 * V_89 , T_9 V_428 )
{
struct V_8 * V_135 = NULL ;
struct V_429 * V_148 = V_89 -> V_430 ;
struct V_100 * V_100 = F_283 ( V_89 ) ;
int V_143 = 0 ;
if ( V_428 == 0 ) {
V_148 -> V_431 = 0 ;
V_148 -> V_432 = 0 ;
}
for (; V_148 -> V_431 < V_417 ; ++ V_148 -> V_431 ) {
F_174 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_170 ( F_31 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( V_143 < V_148 -> V_432 ) {
V_143 ++ ;
continue;
}
V_148 -> V_432 ++ ;
return V_135 ;
}
V_148 -> V_432 = 0 ;
V_143 = 0 ;
}
return NULL ;
}
static struct V_8 * F_284 ( struct V_427 * V_89 ,
struct V_8 * V_135 )
{
struct V_429 * V_148 = V_89 -> V_430 ;
struct V_100 * V_100 = F_283 ( V_89 ) ;
F_285 (ifa, addr_lst) {
if ( ! F_170 ( F_31 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
V_148 -> V_432 ++ ;
return V_135 ;
}
while ( ++ V_148 -> V_431 < V_417 ) {
V_148 -> V_432 = 0 ;
F_174 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_170 ( F_31 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
V_148 -> V_432 ++ ;
return V_135 ;
}
}
return NULL ;
}
static void * F_286 ( struct V_427 * V_89 , T_9 * V_428 )
__acquires( T_10 )
{
F_107 () ;
return F_282 ( V_89 , * V_428 ) ;
}
static void * F_287 ( struct V_427 * V_89 , void * V_433 , T_9 * V_428 )
{
struct V_8 * V_135 ;
V_135 = F_284 ( V_89 , V_433 ) ;
++ * V_428 ;
return V_135 ;
}
static void F_288 ( struct V_427 * V_89 , void * V_433 )
__releases( T_10 )
{
F_121 () ;
}
static int F_289 ( struct V_427 * V_89 , void * V_433 )
{
struct V_8 * V_9 = (struct V_8 * ) V_433 ;
F_290 ( V_89 , L_31 ,
& V_9 -> V_153 ,
V_9 -> V_5 -> V_7 -> V_85 ,
V_9 -> V_175 ,
V_9 -> V_158 ,
V_9 -> V_52 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
return 0 ;
}
static int F_291 ( struct V_434 * V_434 , struct V_435 * V_435 )
{
return F_292 ( V_434 , V_435 , & V_436 ,
sizeof( struct V_429 ) ) ;
}
static int T_11 F_293 ( struct V_100 * V_100 )
{
if ( ! F_294 ( L_32 , V_437 , V_100 -> V_438 , & V_439 ) )
return - V_33 ;
return 0 ;
}
static void T_12 F_295 ( struct V_100 * V_100 )
{
F_296 ( L_32 , V_100 -> V_438 ) ;
}
int T_13 F_297 ( void )
{
return F_298 ( & V_440 ) ;
}
void F_299 ( void )
{
F_300 ( & V_440 ) ;
}
int F_301 ( struct V_100 * V_100 , const struct V_155 * V_153 )
{
int V_203 = 0 ;
struct V_8 * V_9 = NULL ;
unsigned int V_160 = F_101 ( V_153 ) ;
F_107 () ;
F_174 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_170 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_152 ( & V_9 -> V_153 , V_153 ) &&
( V_9 -> V_52 & V_242 ) ) {
V_203 = 1 ;
break;
}
}
F_121 () ;
return V_203 ;
}
static void F_229 ( unsigned long V_441 )
{
unsigned long V_206 , V_442 , V_443 , V_444 ;
struct V_8 * V_9 ;
int V_227 ;
F_107 () ;
F_108 ( & V_445 ) ;
V_206 = V_20 ;
V_442 = F_302 ( V_206 + V_446 ) ;
F_7 ( & V_447 ) ;
for ( V_227 = 0 ; V_227 < V_417 ; V_227 ++ ) {
V_418:
F_174 (ifp,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_200 ;
if ( V_9 -> V_52 & V_185 )
continue;
F_108 ( & V_9 -> V_43 ) ;
V_200 = ( V_206 - V_9 -> V_72 + V_448 ) / V_3 ;
if ( V_9 -> V_187 != V_382 &&
V_200 >= V_9 -> V_187 ) {
F_117 ( & V_9 -> V_43 ) ;
F_10 ( V_9 ) ;
F_124 ( V_9 ) ;
goto V_418;
} else if ( V_9 -> V_214 == V_382 ) {
F_117 ( & V_9 -> V_43 ) ;
continue;
} else if ( V_200 >= V_9 -> V_214 ) {
int V_449 = 0 ;
if ( ! ( V_9 -> V_52 & V_237 ) ) {
V_449 = 1 ;
V_9 -> V_52 |= V_237 ;
}
if ( F_135 ( V_9 -> V_72 + V_9 -> V_187 * V_3 , V_442 ) )
V_442 = V_9 -> V_72 + V_9 -> V_187 * V_3 ;
F_117 ( & V_9 -> V_43 ) ;
if ( V_449 ) {
F_10 ( V_9 ) ;
F_137 ( 0 , V_9 ) ;
F_130 ( V_9 ) ;
goto V_418;
}
#ifdef F_41
} else if ( ( V_9 -> V_52 & V_178 ) &&
! ( V_9 -> V_52 & V_138 ) ) {
unsigned long V_201 = V_9 -> V_5 -> V_44 . V_210 *
V_9 -> V_5 -> V_44 . V_217 *
V_9 -> V_5 -> V_48 -> V_218 / V_3 ;
if ( V_200 >= V_9 -> V_214 - V_201 ) {
struct V_8 * V_184 = V_9 -> V_184 ;
if ( F_135 ( V_9 -> V_72 + V_9 -> V_214 * V_3 , V_442 ) )
V_442 = V_9 -> V_72 + V_9 -> V_214 * V_3 ;
if ( ! V_9 -> V_209 && V_184 ) {
V_9 -> V_209 ++ ;
F_10 ( V_9 ) ;
F_10 ( V_184 ) ;
F_117 ( & V_9 -> V_43 ) ;
F_108 ( & V_184 -> V_43 ) ;
V_184 -> V_209 = 0 ;
F_117 ( & V_184 -> V_43 ) ;
F_143 ( V_184 , V_9 ) ;
F_130 ( V_184 ) ;
F_130 ( V_9 ) ;
goto V_418;
}
} else if ( F_135 ( V_9 -> V_72 + V_9 -> V_214 * V_3 - V_201 * V_3 , V_442 ) )
V_442 = V_9 -> V_72 + V_9 -> V_214 * V_3 - V_201 * V_3 ;
F_117 ( & V_9 -> V_43 ) ;
#endif
} else {
if ( F_135 ( V_9 -> V_72 + V_9 -> V_214 * V_3 , V_442 ) )
V_442 = V_9 -> V_72 + V_9 -> V_214 * V_3 ;
F_117 ( & V_9 -> V_43 ) ;
}
}
}
V_443 = F_302 ( V_442 ) ;
V_444 = V_442 ;
if ( F_135 ( V_443 , V_442 + V_450 ) )
V_444 = V_443 ;
if ( F_135 ( V_444 , V_20 + V_451 ) )
V_444 = V_20 + V_451 ;
F_35 ( ( V_258 L_33 ,
V_206 , V_442 , V_443 , V_444 ) ) ;
V_447 . V_19 = V_444 ;
F_11 ( & V_447 ) ;
F_117 ( & V_445 ) ;
F_121 () ;
}
static struct V_155 * F_303 ( struct V_109 * V_153 , struct V_109 * V_452 )
{
struct V_155 * V_297 = NULL ;
if ( V_153 )
V_297 = F_304 ( V_153 ) ;
if ( V_452 ) {
if ( V_297 && F_305 ( V_452 , V_297 , sizeof( * V_297 ) ) )
V_297 = NULL ;
else
V_297 = F_304 ( V_452 ) ;
}
return V_297 ;
}
static int
F_306 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_100 * V_100 = F_66 ( V_84 -> V_108 ) ;
struct V_453 * V_454 ;
struct V_109 * V_110 [ V_455 + 1 ] ;
struct V_155 * V_297 ;
int V_101 ;
V_101 = F_67 ( V_92 , sizeof( * V_454 ) , V_110 , V_455 , V_456 ) ;
if ( V_101 < 0 )
return V_101 ;
V_454 = F_56 ( V_92 ) ;
V_297 = F_303 ( V_110 [ V_457 ] , V_110 [ V_458 ] ) ;
if ( V_297 == NULL )
return - V_114 ;
return F_240 ( V_100 , V_454 -> V_459 , V_297 , V_454 -> V_460 ) ;
}
static int F_307 ( struct V_8 * V_9 , T_3 V_375 ,
T_1 V_214 , T_1 V_187 )
{
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_376 ;
if ( ! V_187 || ( V_214 > V_187 ) )
return - V_114 ;
V_376 = F_134 ( V_187 , V_3 ) ;
if ( F_225 ( V_376 ) ) {
V_19 = F_227 ( V_376 * V_3 ) ;
V_187 = V_376 ;
V_52 = V_194 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_375 |= V_185 ;
}
V_376 = F_134 ( V_214 , V_3 ) ;
if ( F_225 ( V_376 ) ) {
if ( V_376 == 0 )
V_375 |= V_237 ;
V_214 = V_376 ;
}
F_125 ( & V_9 -> V_43 ) ;
V_9 -> V_52 = ( V_9 -> V_52 & ~ ( V_237 | V_185 | V_425 | V_242 ) ) | V_375 ;
V_9 -> V_72 = V_20 ;
V_9 -> V_187 = V_187 ;
V_9 -> V_214 = V_214 ;
F_126 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_52 & V_138 ) )
F_137 ( 0 , V_9 ) ;
F_211 ( & V_9 -> V_153 , V_9 -> V_175 , V_9 -> V_5 -> V_7 ,
V_19 , V_52 ) ;
F_229 ( 0 ) ;
return 0 ;
}
static int
F_308 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_100 * V_100 = F_66 ( V_84 -> V_108 ) ;
struct V_453 * V_454 ;
struct V_109 * V_110 [ V_455 + 1 ] ;
struct V_155 * V_297 ;
struct V_8 * V_135 ;
struct V_6 * V_7 ;
T_1 V_187 = V_382 , V_461 = V_382 ;
T_3 V_375 ;
int V_101 ;
V_101 = F_67 ( V_92 , sizeof( * V_454 ) , V_110 , V_455 , V_456 ) ;
if ( V_101 < 0 )
return V_101 ;
V_454 = F_56 ( V_92 ) ;
V_297 = F_303 ( V_110 [ V_457 ] , V_110 [ V_458 ] ) ;
if ( V_297 == NULL )
return - V_114 ;
if ( V_110 [ V_462 ] ) {
struct V_463 * V_464 ;
V_464 = F_304 ( V_110 [ V_462 ] ) ;
V_187 = V_464 -> V_465 ;
V_461 = V_464 -> V_466 ;
} else {
V_461 = V_382 ;
V_187 = V_382 ;
}
V_7 = F_69 ( V_100 , V_454 -> V_459 ) ;
if ( V_7 == NULL )
return - V_166 ;
V_375 = V_454 -> V_375 & ( V_425 | V_242 ) ;
V_135 = F_173 ( V_100 , V_297 , V_7 , 1 ) ;
if ( V_135 == NULL ) {
return F_238 ( V_100 , V_454 -> V_459 , V_297 ,
V_454 -> V_460 , V_375 ,
V_461 , V_187 ) ;
}
if ( V_92 -> V_467 & V_468 ||
! ( V_92 -> V_467 & V_469 ) )
V_101 = - V_171 ;
else
V_101 = F_307 ( V_135 , V_375 , V_461 , V_187 ) ;
F_130 ( V_135 ) ;
return V_101 ;
}
static void F_309 ( struct V_91 * V_92 , T_3 V_470 , T_3 V_52 ,
T_3 V_158 , int V_85 )
{
struct V_453 * V_454 ;
V_454 = F_56 ( V_92 ) ;
V_454 -> V_471 = V_96 ;
V_454 -> V_460 = V_470 ;
V_454 -> V_375 = V_52 ;
V_454 -> V_391 = V_158 ;
V_454 -> V_459 = V_85 ;
}
static int F_310 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_72 , T_1 V_472 , T_1 V_332 )
{
struct V_463 V_464 ;
V_464 . V_1 = F_1 ( V_1 ) ;
V_464 . V_72 = F_1 ( V_72 ) ;
V_464 . V_466 = V_472 ;
V_464 . V_465 = V_332 ;
return F_311 ( V_84 , V_462 , sizeof( V_464 ) , & V_464 ) ;
}
static inline int F_312 ( int V_391 )
{
if ( V_391 & V_267 )
return V_393 ;
else if ( V_391 & V_264 )
return V_392 ;
else if ( V_391 & V_473 )
return V_474 ;
else
return V_475 ;
}
static inline int F_313 ( void )
{
return F_51 ( sizeof( struct V_453 ) )
+ F_52 ( 16 )
+ F_52 ( sizeof( struct V_463 ) ) ;
}
static int F_314 ( struct V_83 * V_84 , struct V_8 * V_135 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_52 )
{
struct V_91 * V_92 ;
T_1 V_472 , V_332 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_453 ) , V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_309 ( V_92 , V_135 -> V_175 , V_135 -> V_52 , F_312 ( V_135 -> V_158 ) ,
V_135 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( V_135 -> V_52 & V_185 ) ) {
V_472 = V_135 -> V_214 ;
V_332 = V_135 -> V_187 ;
if ( V_472 != V_382 ) {
long V_476 = ( V_20 - V_135 -> V_72 ) / V_3 ;
if ( V_472 > V_476 )
V_472 -= V_476 ;
else
V_472 = 0 ;
if ( V_332 != V_382 ) {
if ( V_332 > V_476 )
V_332 -= V_476 ;
else
V_332 = 0 ;
}
}
} else {
V_472 = V_382 ;
V_332 = V_382 ;
}
if ( F_311 ( V_84 , V_457 , 16 , & V_135 -> V_153 ) < 0 ||
F_310 ( V_84 , V_135 -> V_1 , V_135 -> V_72 , V_472 , V_332 ) < 0 ) {
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_58 ( V_84 , V_92 ) ;
}
static int F_315 ( struct V_83 * V_84 , struct V_477 * V_478 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_14 V_52 )
{
struct V_91 * V_92 ;
T_3 V_158 = V_475 ;
int V_85 = V_478 -> V_5 -> V_7 -> V_85 ;
if ( F_239 ( & V_478 -> V_479 ) & V_473 )
V_158 = V_474 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_453 ) , V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_309 ( V_92 , 128 , V_185 , V_158 , V_85 ) ;
if ( F_311 ( V_84 , V_480 , 16 , & V_478 -> V_479 ) < 0 ||
F_310 ( V_84 , V_478 -> V_481 , V_478 -> V_482 ,
V_382 , V_382 ) < 0 ) {
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_58 ( V_84 , V_92 ) ;
}
static int F_316 ( struct V_83 * V_84 , struct V_483 * V_484 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_52 )
{
struct V_91 * V_92 ;
T_3 V_158 = V_475 ;
int V_85 = V_484 -> V_485 -> V_7 -> V_85 ;
if ( F_239 ( & V_484 -> V_486 ) & V_473 )
V_158 = V_474 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_453 ) , V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_309 ( V_92 , 128 , V_185 , V_158 , V_85 ) ;
if ( F_311 ( V_84 , V_487 , 16 , & V_484 -> V_486 ) < 0 ||
F_310 ( V_84 , V_484 -> V_488 , V_484 -> V_489 ,
V_382 , V_382 ) < 0 ) {
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_58 ( V_84 , V_92 ) ;
}
static int F_317 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_119 * V_120 , enum V_490 type ,
int V_491 , int * V_492 )
{
struct V_477 * V_478 ;
struct V_483 * V_484 ;
int V_101 = 1 ;
int V_493 = * V_492 ;
F_162 ( & V_5 -> V_43 ) ;
switch ( type ) {
case V_494 : {
struct V_8 * V_135 ;
F_81 (ifa, &idev->addr_list, if_list) {
if ( ++ V_493 < V_491 )
continue;
V_101 = F_314 ( V_84 , V_135 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_383 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
F_77 ( V_120 , F_78 ( V_84 ) ) ;
}
break;
}
case V_495 :
for ( V_478 = V_5 -> V_35 ; V_478 ;
V_478 = V_478 -> V_442 , V_493 ++ ) {
if ( V_493 < V_491 )
continue;
V_101 = F_315 ( V_84 , V_478 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_496 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
}
break;
case V_497 :
for ( V_484 = V_5 -> V_498 ; V_484 ;
V_484 = V_484 -> V_499 , V_493 ++ ) {
if ( V_493 < V_491 )
continue;
V_101 = F_316 ( V_84 , V_484 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_500 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
}
break;
default:
break;
}
F_167 ( & V_5 -> V_43 ) ;
* V_492 = V_493 ;
return V_101 ;
}
static int F_318 ( struct V_83 * V_84 , struct V_119 * V_120 ,
enum V_490 type )
{
struct V_100 * V_100 = F_66 ( V_84 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 , V_493 ;
int V_124 , V_491 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_123 = V_120 -> args [ 1 ] ;
V_491 = V_493 = V_120 -> args [ 2 ] ;
F_73 () ;
V_120 -> V_89 = F_74 ( & V_100 -> V_23 . V_129 ) ^ V_100 -> V_130 ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_75 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
if ( V_121 > V_122 || V_123 > V_124 )
V_491 = 0 ;
V_493 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_317 ( V_5 , V_84 , V_120 , type ,
V_491 , & V_493 ) <= 0 )
goto V_133;
V_131:
V_123 ++ ;
}
}
V_133:
F_76 () ;
V_120 -> args [ 0 ] = V_121 ;
V_120 -> args [ 1 ] = V_123 ;
V_120 -> args [ 2 ] = V_493 ;
return V_84 -> V_134 ;
}
static int F_319 ( struct V_83 * V_84 , struct V_119 * V_120 )
{
enum V_490 type = V_494 ;
return F_318 ( V_84 , V_120 , type ) ;
}
static int F_320 ( struct V_83 * V_84 , struct V_119 * V_120 )
{
enum V_490 type = V_495 ;
return F_318 ( V_84 , V_120 , type ) ;
}
static int F_321 ( struct V_83 * V_84 , struct V_119 * V_120 )
{
enum V_490 type = V_497 ;
return F_318 ( V_84 , V_120 , type ) ;
}
static int F_322 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_100 * V_100 = F_66 ( V_107 -> V_108 ) ;
struct V_453 * V_454 ;
struct V_109 * V_110 [ V_455 + 1 ] ;
struct V_155 * V_153 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_135 ;
struct V_83 * V_84 ;
int V_101 ;
V_101 = F_67 ( V_92 , sizeof( * V_454 ) , V_110 , V_455 , V_456 ) ;
if ( V_101 < 0 )
goto V_104;
V_153 = F_303 ( V_110 [ V_457 ] , V_110 [ V_458 ] ) ;
if ( V_153 == NULL ) {
V_101 = - V_114 ;
goto V_104;
}
V_454 = F_56 ( V_92 ) ;
if ( V_454 -> V_459 )
V_7 = F_69 ( V_100 , V_454 -> V_459 ) ;
V_135 = F_173 ( V_100 , V_153 , V_7 , 1 ) ;
if ( ! V_135 ) {
V_101 = - V_165 ;
goto V_104;
}
V_84 = F_61 ( F_313 () , V_28 ) ;
if ( ! V_84 ) {
V_101 = - V_102 ;
goto V_501;
}
V_101 = F_314 ( V_84 , V_135 , F_70 ( V_107 ) . V_88 ,
V_92 -> V_118 , V_383 , 0 ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_501;
}
V_101 = F_71 ( V_84 , V_100 , F_70 ( V_107 ) . V_88 ) ;
V_501:
F_130 ( V_135 ) ;
V_104:
return V_101 ;
}
static void F_323 ( int V_90 , struct V_8 * V_135 )
{
struct V_83 * V_84 ;
struct V_100 * V_100 = F_31 ( V_135 -> V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_84 = F_61 ( F_313 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_101 = F_314 ( V_84 , V_135 , 0 , 0 , V_90 , 0 ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_104;
}
F_63 ( V_84 , V_100 , 0 , V_502 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_64 ( V_100 , V_502 , V_101 ) ;
}
static inline void F_324 ( struct V_86 * V_44 ,
T_2 * V_503 , int V_504 )
{
F_325 ( V_504 < ( V_505 * 4 ) ) ;
memset ( V_503 , 0 , V_504 ) ;
V_503 [ V_506 ] = V_44 -> V_50 ;
V_503 [ V_507 ] = V_44 -> V_508 ;
V_503 [ V_509 ] = V_44 -> V_46 ;
V_503 [ V_510 ] = V_44 -> V_511 ;
V_503 [ V_512 ] = V_44 -> V_513 ;
V_503 [ V_514 ] = V_44 -> V_338 ;
V_503 [ V_515 ] = V_44 -> V_217 ;
V_503 [ V_516 ] = V_44 -> V_60 ;
V_503 [ V_517 ] =
F_326 ( V_44 -> V_423 ) ;
V_503 [ V_518 ] =
F_326 ( V_44 -> V_422 ) ;
V_503 [ V_519 ] = V_44 -> V_520 ;
#ifdef F_41
V_503 [ V_521 ] = V_44 -> V_67 ;
V_503 [ V_522 ] = V_44 -> V_213 ;
V_503 [ V_523 ] = V_44 -> V_215 ;
V_503 [ V_524 ] = V_44 -> V_210 ;
V_503 [ V_525 ] = V_44 -> V_216 ;
#endif
V_503 [ V_526 ] = V_44 -> V_204 ;
V_503 [ V_527 ] = V_44 -> V_528 ;
V_503 [ V_529 ] = V_44 -> V_530 ;
#ifdef F_327
V_503 [ V_531 ] = V_44 -> V_532 ;
V_503 [ V_533 ] =
F_326 ( V_44 -> V_534 ) ;
#ifdef F_328
V_503 [ V_535 ] = V_44 -> V_536 ;
#endif
#endif
V_503 [ V_537 ] = V_44 -> V_538 ;
V_503 [ V_539 ] = V_44 -> V_540 ;
#ifdef F_228
V_503 [ V_541 ] = V_44 -> V_342 ;
#endif
#ifdef F_53
V_503 [ V_542 ] = V_44 -> V_99 ;
#endif
V_503 [ V_543 ] = V_44 -> V_168 ;
V_503 [ V_544 ] = V_44 -> V_55 ;
V_503 [ V_545 ] = V_44 -> V_546 ;
V_503 [ V_547 ] = V_44 -> V_548 ;
}
static inline T_15 F_329 ( void )
{
return F_52 ( 4 )
+ F_52 ( sizeof( struct V_549 ) )
+ F_52 ( V_505 * 4 )
+ F_52 ( V_550 * 8 )
+ F_52 ( V_551 * 8 )
+ F_52 ( sizeof( struct V_155 ) ) ;
}
static inline T_15 F_330 ( void )
{
return F_51 ( sizeof( struct V_552 ) )
+ F_52 ( V_553 )
+ F_52 ( V_554 )
+ F_52 ( 4 )
+ F_52 ( 4 )
+ F_52 ( F_329 () ) ;
}
static inline void F_331 ( T_16 * V_22 , T_17 * V_555 ,
int V_556 , int V_504 )
{
int V_227 ;
int V_557 = V_504 - sizeof( T_16 ) * V_556 ;
F_325 ( V_557 < 0 ) ;
F_332 ( V_556 , & V_22 [ 0 ] ) ;
for ( V_227 = 1 ; V_227 < V_556 ; V_227 ++ )
F_332 ( F_333 ( & V_555 [ V_227 ] ) , & V_22 [ V_227 ] ) ;
memset ( & V_22 [ V_556 ] , 0 , V_557 ) ;
}
static inline void F_334 ( T_16 * V_22 , void V_21 * * V_555 ,
int V_556 , int V_504 , T_15 V_558 )
{
int V_227 ;
int V_557 = V_504 - sizeof( T_16 ) * V_556 ;
F_325 ( V_557 < 0 ) ;
F_332 ( V_556 , & V_22 [ 0 ] ) ;
for ( V_227 = 1 ; V_227 < V_556 ; V_227 ++ )
F_332 ( F_335 ( V_555 , V_227 , V_558 ) , & V_22 [ V_227 ] ) ;
memset ( & V_22 [ V_556 ] , 0 , V_557 ) ;
}
static void F_336 ( T_16 * V_22 , struct V_4 * V_5 , int V_559 ,
int V_504 )
{
switch ( V_559 ) {
case V_560 :
F_334 ( V_22 , ( void V_21 * * ) V_5 -> V_22 . V_23 ,
V_550 , V_504 , F_337 ( struct V_24 , V_561 ) ) ;
break;
case V_562 :
F_331 ( V_22 , V_5 -> V_22 . V_26 -> V_563 , V_551 , V_504 ) ;
break;
}
}
static int F_338 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_564 ;
struct V_549 V_464 ;
if ( F_339 ( V_84 , V_565 , V_5 -> V_70 ) )
goto V_98;
V_464 . V_566 = V_567 ;
V_464 . V_72 = F_1 ( V_5 -> V_72 ) ;
V_464 . V_568 = F_326 ( V_5 -> V_48 -> V_568 ) ;
V_464 . V_218 = F_326 ( V_5 -> V_48 -> V_218 ) ;
if ( F_311 ( V_84 , V_569 , sizeof( V_464 ) , & V_464 ) )
goto V_98;
V_564 = F_340 ( V_84 , V_570 , V_505 * sizeof( V_571 ) ) ;
if ( V_564 == NULL )
goto V_98;
F_324 ( & V_5 -> V_44 , F_304 ( V_564 ) , F_341 ( V_564 ) ) ;
V_564 = F_340 ( V_84 , V_560 , V_550 * sizeof( T_16 ) ) ;
if ( V_564 == NULL )
goto V_98;
F_336 ( F_304 ( V_564 ) , V_5 , V_560 , F_341 ( V_564 ) ) ;
V_564 = F_340 ( V_84 , V_562 , V_551 * sizeof( T_16 ) ) ;
if ( V_564 == NULL )
goto V_98;
F_336 ( F_304 ( V_564 ) , V_5 , V_562 , F_341 ( V_564 ) ) ;
V_564 = F_340 ( V_84 , V_572 , sizeof( struct V_155 ) ) ;
if ( V_564 == NULL )
goto V_98;
F_162 ( & V_5 -> V_43 ) ;
memcpy ( F_304 ( V_564 ) , V_5 -> V_68 . V_207 , F_341 ( V_564 ) ) ;
F_167 ( & V_5 -> V_43 ) ;
return 0 ;
V_98:
return - V_94 ;
}
static T_15 F_342 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_329 () ;
}
static int F_343 ( struct V_83 * V_84 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_573 ;
if ( F_338 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_344 ( struct V_4 * V_5 , struct V_155 * V_68 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_574 = false ;
struct V_155 V_575 ;
if ( V_68 == NULL )
return - V_114 ;
if ( F_185 ( V_68 ) )
return - V_114 ;
if ( V_7 -> V_52 & ( V_54 | V_53 ) )
return - V_114 ;
if ( ! F_274 ( V_5 ) )
return - V_114 ;
if ( V_5 -> V_44 . V_60 <= 0 )
return - V_114 ;
F_128 ( & V_5 -> V_43 ) ;
F_345 ( sizeof( V_68 -> V_207 ) != 16 ) ;
memcpy ( V_5 -> V_68 . V_207 + 8 , V_68 -> V_207 + 8 , 8 ) ;
F_136 ( & V_5 -> V_43 ) ;
if ( ! V_5 -> V_38 && ( V_5 -> V_70 & V_71 ) &&
! F_168 ( V_7 , & V_575 , V_138 |
V_219 ) ) {
F_275 ( V_7 , & V_575 , & V_77 ) ;
V_574 = true ;
}
F_128 ( & V_5 -> V_43 ) ;
if ( V_574 )
V_5 -> V_70 |= V_419 ;
F_81 (ifp, &idev->addr_list, if_list) {
F_108 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_176 ) {
V_9 -> V_187 = 0 ;
V_9 -> V_214 = 0 ;
}
F_117 ( & V_9 -> V_43 ) ;
}
F_136 ( & V_5 -> V_43 ) ;
return 0 ;
}
static int F_346 ( struct V_6 * V_7 , const struct V_109 * V_564 )
{
int V_101 = - V_114 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
struct V_109 * V_110 [ V_576 + 1 ] ;
if ( ! V_5 )
return - V_577 ;
if ( F_347 ( V_110 , V_576 , V_564 , NULL ) < 0 )
F_348 () ;
if ( V_110 [ V_572 ] )
V_101 = F_344 ( V_5 , F_304 ( V_110 [ V_572 ] ) ) ;
return V_101 ;
}
static int F_349 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_52 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_552 * V_578 ;
struct V_91 * V_92 ;
void * V_579 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_578 ) , V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_578 = F_56 ( V_92 ) ;
V_578 -> V_580 = V_96 ;
V_578 -> V_581 = 0 ;
V_578 -> V_582 = V_7 -> type ;
V_578 -> V_583 = V_7 -> V_85 ;
V_578 -> V_584 = F_350 ( V_7 ) ;
V_578 -> V_585 = 0 ;
if ( F_351 ( V_84 , V_586 , V_7 -> V_37 ) ||
( V_7 -> V_277 &&
F_311 ( V_84 , V_587 , V_7 -> V_277 , V_7 -> V_279 ) ) ||
F_339 ( V_84 , V_588 , V_7 -> V_41 ) ||
( V_7 -> V_85 != V_7 -> V_400 &&
F_339 ( V_84 , V_589 , V_7 -> V_400 ) ) )
goto V_98;
V_579 = F_352 ( V_84 , V_590 ) ;
if ( V_579 == NULL )
goto V_98;
if ( F_338 ( V_84 , V_5 ) < 0 )
goto V_98;
F_353 ( V_84 , V_579 ) ;
return F_58 ( V_84 , V_92 ) ;
V_98:
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_354 ( struct V_83 * V_84 , struct V_119 * V_120 )
{
struct V_100 * V_100 = F_66 ( V_84 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 = 0 , V_124 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_120 -> args [ 1 ] ;
F_73 () ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_75 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_349 ( V_84 , V_5 ,
F_70 ( V_120 -> V_84 ) . V_88 ,
V_120 -> V_92 -> V_118 ,
V_409 , V_132 ) <= 0 )
goto V_172;
V_131:
V_123 ++ ;
}
}
V_172:
F_76 () ;
V_120 -> args [ 1 ] = V_123 ;
V_120 -> args [ 0 ] = V_121 ;
return V_84 -> V_134 ;
}
void F_261 ( int V_90 , struct V_4 * V_5 )
{
struct V_83 * V_84 ;
struct V_100 * V_100 = F_31 ( V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_84 = F_61 ( F_330 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_101 = F_349 ( V_84 , V_5 , 0 , 0 , V_90 , 0 ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_104;
}
F_63 ( V_84 , V_100 , 0 , V_591 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_64 ( V_100 , V_591 , V_101 ) ;
}
static inline T_15 F_355 ( void )
{
return F_51 ( sizeof( struct V_592 ) )
+ F_52 ( sizeof( struct V_155 ) )
+ F_52 ( sizeof( struct V_593 ) ) ;
}
static int F_356 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_329 * V_330 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_52 )
{
struct V_592 * V_594 ;
struct V_91 * V_92 ;
struct V_593 V_464 ;
V_92 = F_55 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_594 ) , V_52 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_594 = F_56 ( V_92 ) ;
V_594 -> V_595 = V_96 ;
V_594 -> V_596 = 0 ;
V_594 -> V_597 = 0 ;
V_594 -> V_598 = V_5 -> V_7 -> V_85 ;
V_594 -> V_175 = V_330 -> V_175 ;
V_594 -> V_599 = V_330 -> type ;
V_594 -> V_600 = 0 ;
V_594 -> V_601 = 0 ;
if ( V_330 -> V_183 )
V_594 -> V_601 |= V_602 ;
if ( V_330 -> V_338 )
V_594 -> V_601 |= V_603 ;
if ( F_311 ( V_84 , V_604 , sizeof( V_330 -> V_190 ) , & V_330 -> V_190 ) )
goto V_98;
V_464 . V_605 = F_221 ( V_330 -> V_333 ) ;
V_464 . V_606 = F_221 ( V_330 -> V_332 ) ;
if ( F_311 ( V_84 , V_607 , sizeof( V_464 ) , & V_464 ) )
goto V_98;
return F_58 ( V_84 , V_92 ) ;
V_98:
F_59 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_230 ( int V_90 , struct V_4 * V_5 ,
struct V_329 * V_330 )
{
struct V_83 * V_84 ;
struct V_100 * V_100 = F_31 ( V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_84 = F_61 ( F_355 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_101 = F_356 ( V_84 , V_5 , V_330 , 0 , 0 , V_90 , 0 ) ;
if ( V_101 < 0 ) {
F_20 ( V_101 == - V_94 ) ;
F_62 ( V_84 ) ;
goto V_104;
}
F_63 ( V_84 , V_100 , 0 , V_608 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_64 ( V_100 , V_608 , V_101 ) ;
}
static void F_270 ( int V_90 , struct V_8 * V_9 )
{
struct V_100 * V_100 = F_31 ( V_9 -> V_5 -> V_7 ) ;
F_323 ( V_90 ? : V_383 , V_9 ) ;
switch ( V_90 ) {
case V_383 :
if ( ! ( V_9 -> V_150 -> V_609 ) )
F_249 ( V_9 -> V_150 ) ;
if ( V_9 -> V_5 -> V_44 . V_50 )
F_82 ( V_9 ) ;
break;
case V_188 :
if ( V_9 -> V_5 -> V_44 . V_50 )
F_83 ( V_9 ) ;
F_183 ( V_9 -> V_5 , & V_9 -> V_153 ) ;
F_215 ( & V_9 -> V_150 -> V_226 ) ;
if ( F_140 ( V_9 -> V_150 ) )
F_357 ( & V_9 -> V_150 -> V_226 ) ;
break;
}
F_358 ( & V_100 -> V_23 . V_129 ) ;
}
static void F_137 ( int V_90 , struct V_8 * V_9 )
{
F_107 () ;
if ( F_122 ( V_9 -> V_5 -> V_38 == 0 ) )
F_270 ( V_90 , V_9 ) ;
F_121 () ;
}
static
int F_359 ( V_141 * V_610 , int V_611 ,
void T_6 * V_612 , T_15 * V_613 , T_9 * V_614 )
{
int * V_615 = V_610 -> V_174 ;
int V_616 = * V_615 ;
T_9 V_428 = * V_614 ;
V_141 V_617 ;
int V_203 ;
V_617 = * V_610 ;
V_617 . V_174 = & V_616 ;
V_203 = F_360 ( & V_617 , V_611 , V_612 , V_613 , V_614 ) ;
if ( V_611 )
V_203 = F_86 ( V_610 , V_615 , V_616 ) ;
if ( V_203 )
* V_614 = V_428 ;
return V_203 ;
}
static void F_361 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_44 . V_168 )
F_257 ( NULL , V_189 , V_5 -> V_7 ) ;
else
F_257 ( NULL , V_180 , V_5 -> V_7 ) ;
}
static void F_362 ( struct V_100 * V_100 , T_2 V_139 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_73 () ;
F_161 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_140 = ( ! V_5 -> V_44 . V_168 ) ^ ( ! V_139 ) ;
V_5 -> V_44 . V_168 = V_139 ;
if ( V_140 )
F_361 ( V_5 ) ;
}
}
F_76 () ;
}
static int F_363 ( struct V_141 * V_142 , int * V_143 , int V_139 )
{
struct V_100 * V_100 ;
int V_144 ;
if ( ! F_87 () )
return F_88 () ;
V_100 = (struct V_100 * ) V_142 -> V_145 ;
V_144 = * V_143 ;
* V_143 = V_139 ;
if ( V_143 == & V_100 -> V_23 . V_45 -> V_168 ) {
F_89 () ;
return 0 ;
}
if ( V_143 == & V_100 -> V_23 . V_116 -> V_168 ) {
V_100 -> V_23 . V_45 -> V_168 = V_139 ;
F_362 ( V_100 , V_139 ) ;
} else if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_361 ( (struct V_4 * ) V_142 -> V_146 ) ;
F_89 () ;
return 0 ;
}
static
int F_364 ( V_141 * V_610 , int V_611 ,
void T_6 * V_612 , T_15 * V_613 , T_9 * V_614 )
{
int * V_615 = V_610 -> V_174 ;
int V_616 = * V_615 ;
T_9 V_428 = * V_614 ;
V_141 V_617 ;
int V_203 ;
V_617 = * V_610 ;
V_617 . V_174 = & V_616 ;
V_203 = F_360 ( & V_617 , V_611 , V_612 , V_613 , V_614 ) ;
if ( V_611 )
V_203 = F_363 ( V_610 , V_615 , V_616 ) ;
if ( V_203 )
* V_614 = V_428 ;
return V_203 ;
}
static int F_365 ( struct V_100 * V_100 , char * V_618 ,
struct V_4 * V_5 , struct V_86 * V_143 )
{
int V_227 ;
struct V_619 * V_620 ;
char V_621 [ sizeof( L_34 ) + V_553 ] ;
V_620 = F_366 ( & V_622 , sizeof( * V_620 ) , V_28 ) ;
if ( V_620 == NULL )
goto V_172;
for ( V_227 = 0 ; V_620 -> V_623 [ V_227 ] . V_174 ; V_227 ++ ) {
V_620 -> V_623 [ V_227 ] . V_174 += ( char * ) V_143 - ( char * ) & V_86 ;
V_620 -> V_623 [ V_227 ] . V_146 = V_5 ;
V_620 -> V_623 [ V_227 ] . V_145 = V_100 ;
}
snprintf ( V_621 , sizeof( V_621 ) , L_35 , V_618 ) ;
V_620 -> V_624 = F_367 ( V_100 , V_621 , V_620 -> V_623 ) ;
if ( V_620 -> V_624 == NULL )
goto free;
V_143 -> V_47 = V_620 ;
return 0 ;
free:
F_16 ( V_620 ) ;
V_172:
return - V_102 ;
}
static void F_368 ( struct V_86 * V_143 )
{
struct V_619 * V_620 ;
if ( V_143 -> V_47 == NULL )
return;
V_620 = V_143 -> V_47 ;
V_143 -> V_47 = NULL ;
F_369 ( V_620 -> V_624 ) ;
F_16 ( V_620 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_370 ( V_5 -> V_7 , V_5 -> V_48 , L_36 ,
& V_625 ) ;
F_365 ( F_31 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_37 ,
V_5 , & V_5 -> V_44 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_368 ( & V_5 -> V_44 ) ;
F_371 ( V_5 -> V_48 ) ;
}
static int T_11 F_372 ( struct V_100 * V_100 )
{
int V_101 = - V_33 ;
struct V_86 * V_626 , * V_627 ;
V_626 = F_366 ( & V_86 , sizeof( V_86 ) , V_28 ) ;
if ( V_626 == NULL )
goto V_628;
V_627 = F_366 ( & V_629 , sizeof( V_629 ) , V_28 ) ;
if ( V_627 == NULL )
goto V_630;
V_627 -> V_338 = V_631 . V_338 ;
V_627 -> V_168 = V_631 . V_168 ;
V_100 -> V_23 . V_116 = V_626 ;
V_100 -> V_23 . V_45 = V_627 ;
#ifdef F_373
V_101 = F_365 ( V_100 , L_37 , NULL , V_626 ) ;
if ( V_101 < 0 )
goto V_632;
V_101 = F_365 ( V_100 , L_38 , NULL , V_627 ) ;
if ( V_101 < 0 )
goto V_633;
#endif
return 0 ;
#ifdef F_373
V_633:
F_368 ( V_626 ) ;
V_632:
F_16 ( V_627 ) ;
#endif
V_630:
F_16 ( V_626 ) ;
V_628:
return V_101 ;
}
static void T_12 F_374 ( struct V_100 * V_100 )
{
#ifdef F_373
F_368 ( V_100 -> V_23 . V_45 ) ;
F_368 ( V_100 -> V_23 . V_116 ) ;
#endif
if ( ! F_170 ( V_100 , & V_634 ) ) {
F_16 ( V_100 -> V_23 . V_45 ) ;
F_16 ( V_100 -> V_23 . V_116 ) ;
}
}
int T_13 F_375 ( void )
{
int V_227 , V_101 ;
V_101 = F_376 () ;
if ( V_101 < 0 ) {
F_377 ( L_39 ,
V_36 , V_101 ) ;
goto V_172;
}
V_101 = F_298 ( & V_635 ) ;
if ( V_101 < 0 )
goto V_636;
F_232 () ;
if ( ! F_27 ( V_634 . V_637 ) )
V_101 = - V_33 ;
F_89 () ;
if ( V_101 )
goto V_638;
for ( V_227 = 0 ; V_227 < V_417 ; V_227 ++ )
F_378 ( & V_177 [ V_227 ] ) ;
F_379 ( & V_639 ) ;
F_229 ( 0 ) ;
V_101 = F_380 ( & V_640 ) ;
if ( V_101 < 0 )
goto V_641;
V_101 = F_381 ( V_642 , V_643 , NULL , F_354 ,
NULL ) ;
if ( V_101 < 0 )
goto V_104;
F_381 ( V_642 , V_383 , F_308 , NULL , NULL ) ;
F_381 ( V_642 , V_188 , F_306 , NULL , NULL ) ;
F_381 ( V_642 , V_644 , F_322 ,
F_319 , NULL ) ;
F_381 ( V_642 , V_496 , NULL ,
F_320 , NULL ) ;
F_381 ( V_642 , V_500 , NULL ,
F_321 , NULL ) ;
F_381 ( V_642 , V_645 , F_65 ,
F_72 , NULL ) ;
F_382 () ;
return 0 ;
V_104:
F_383 ( & V_640 ) ;
V_641:
F_384 ( & V_639 ) ;
V_638:
F_300 ( & V_635 ) ;
V_636:
F_385 () ;
V_172:
return V_101 ;
}
void F_386 ( void )
{
struct V_6 * V_7 ;
int V_227 ;
F_384 ( & V_639 ) ;
F_300 ( & V_635 ) ;
F_385 () ;
F_232 () ;
F_387 ( & V_640 ) ;
F_85 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_241 ( V_7 , 1 ) ;
}
F_241 ( V_634 . V_637 , 2 ) ;
F_125 ( & V_170 ) ;
for ( V_227 = 0 ; V_227 < V_417 ; V_227 ++ )
F_20 ( ! F_388 ( & V_177 [ V_227 ] ) ) ;
F_126 ( & V_170 ) ;
F_7 ( & V_447 ) ;
F_89 () ;
}
