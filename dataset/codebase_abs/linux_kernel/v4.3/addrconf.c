static inline T_1 F_1 ( unsigned long V_1 )
{
return ( V_1 - V_2 ) * 100UL / V_3 ;
}
static inline int F_2 ( struct V_4 * V_5 )
{
return 0 ;
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
if ( F_10 ( & V_10 -> V_11 ) )
F_11 ( V_10 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
unsigned long V_12 )
{
if ( ! F_13 ( & V_5 -> V_8 ) )
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_8 , V_13 + V_12 ) ;
}
static void F_16 ( struct V_9 * V_10 ,
unsigned long V_14 )
{
if ( ! F_17 ( & V_10 -> V_11 ) )
F_18 ( V_10 ) ;
F_19 ( V_15 , & V_10 -> V_11 , V_14 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_16 ;
V_5 -> V_17 . V_18 = F_21 ( struct V_19 ) ;
if ( ! V_5 -> V_17 . V_18 )
goto V_20;
F_22 (i) {
struct V_19 * V_21 ;
V_21 = F_23 ( V_5 -> V_17 . V_18 , V_16 ) ;
F_24 ( & V_21 -> V_22 ) ;
}
V_5 -> V_17 . V_23 = F_25 ( sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_5 -> V_17 . V_23 )
goto V_26;
V_5 -> V_17 . V_27 = F_25 ( sizeof( struct V_28 ) ,
V_25 ) ;
if ( ! V_5 -> V_17 . V_27 )
goto V_29;
return 0 ;
V_29:
F_26 ( V_5 -> V_17 . V_23 ) ;
V_26:
F_27 ( V_5 -> V_17 . V_18 ) ;
V_20:
return - V_30 ;
}
static struct V_4 * F_28 ( struct V_6 * V_7 )
{
struct V_4 * V_31 ;
int V_32 = - V_30 ;
F_29 () ;
if ( V_7 -> V_33 < V_34 )
return F_30 ( - V_35 ) ;
V_31 = F_25 ( sizeof( struct V_4 ) , V_25 ) ;
if ( ! V_31 )
return F_30 ( V_32 ) ;
F_31 ( & V_31 -> V_36 ) ;
V_31 -> V_7 = V_7 ;
F_32 ( & V_31 -> V_37 ) ;
F_33 ( & V_31 -> V_8 , V_38 ,
( unsigned long ) V_31 ) ;
memcpy ( & V_31 -> V_39 , F_34 ( V_7 ) -> V_18 . V_40 , sizeof( V_31 -> V_39 ) ) ;
V_31 -> V_39 . V_41 = V_7 -> V_33 ;
V_31 -> V_39 . V_42 = NULL ;
V_31 -> V_43 = F_35 ( V_7 , & V_44 ) ;
if ( ! V_31 -> V_43 ) {
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( V_31 -> V_39 . V_45 )
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( F_20 ( V_31 ) < 0 ) {
F_38 ( V_46
L_1 ,
V_47 , V_7 -> V_48 ) ;
F_39 ( & V_44 , V_31 -> V_43 ) ;
F_40 ( V_7 ) ;
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( F_41 ( V_31 ) < 0 ) {
F_38 ( V_46
L_2 ,
V_47 , V_7 -> V_48 ) ;
goto V_49;
}
F_14 ( V_31 ) ;
if ( V_7 -> V_50 & ( V_51 | V_52 ) )
V_31 -> V_39 . V_53 = - 1 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_56 & V_57 ) ) {
F_43 ( L_3 , V_7 -> V_48 ) ;
V_31 -> V_39 . V_58 = 0 ;
}
#endif
F_32 ( & V_31 -> V_59 ) ;
F_33 ( & V_31 -> V_60 , V_61 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_50 & V_52 ) ||
V_7 -> type == V_62 ||
V_7 -> type == V_63 ||
V_7 -> type == V_55 ||
V_7 -> type == V_64 ) {
V_31 -> V_39 . V_65 = - 1 ;
} else {
F_14 ( V_31 ) ;
V_61 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_66 = V_67 ;
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_68 |= V_69 ;
F_45 ( V_31 ) ;
V_31 -> V_70 = V_13 ;
V_32 = F_2 ( V_31 ) ;
if ( V_32 ) {
F_46 ( V_31 ) ;
F_7 ( & V_31 -> V_60 ) ;
goto V_49;
}
F_47 ( V_7 -> V_71 , V_31 ) ;
F_48 ( V_7 , & V_72 ) ;
F_48 ( V_7 , & V_73 ) ;
if ( V_31 -> V_39 . V_45 && ( V_7 -> V_50 & V_74 ) )
F_48 ( V_7 , & V_75 ) ;
return V_31 ;
V_49:
F_39 ( & V_44 , V_31 -> V_43 ) ;
V_31 -> V_76 = 1 ;
F_49 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
static struct V_4 * F_50 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return NULL ;
}
if ( V_7 -> V_50 & V_77 )
F_53 ( V_5 ) ;
return V_5 ;
}
static int F_54 ( int type )
{
int V_78 = F_55 ( sizeof( struct V_79 ) )
+ F_56 ( 4 ) ;
if ( type == - 1 || type == V_80 )
V_78 += F_56 ( 4 ) ;
#ifdef F_57
if ( type == - 1 || type == V_81 )
V_78 += F_56 ( 4 ) ;
#endif
if ( type == - 1 || type == V_82 )
V_78 += F_56 ( 4 ) ;
if ( type == - 1 || type == V_83 )
V_78 += F_56 ( 4 ) ;
return V_78 ;
}
static int F_58 ( struct V_84 * V_85 , int V_86 ,
struct V_87 * V_88 , T_1 V_89 ,
T_1 V_90 , int V_91 , unsigned int V_50 ,
int type )
{
struct V_92 * V_93 ;
struct V_79 * V_94 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( struct V_79 ) ,
V_50 ) ;
if ( ! V_93 )
return - V_95 ;
V_94 = F_60 ( V_93 ) ;
V_94 -> V_96 = V_97 ;
if ( F_61 ( V_85 , V_98 , V_86 ) < 0 )
goto V_99;
if ( ( type == - 1 || type == V_80 ) &&
F_61 ( V_85 , V_80 , V_88 -> V_45 ) < 0 )
goto V_99;
#ifdef F_57
if ( ( type == - 1 || type == V_81 ) &&
F_61 ( V_85 , V_81 ,
V_88 -> V_100 ) < 0 )
goto V_99;
#endif
if ( ( type == - 1 || type == V_82 ) &&
F_61 ( V_85 , V_82 , V_88 -> V_101 ) < 0 )
goto V_99;
if ( ( type == - 1 || type == V_83 ) &&
F_61 ( V_85 , V_83 ,
V_88 -> V_102 ) < 0 )
goto V_99;
F_62 ( V_85 , V_93 ) ;
return 0 ;
V_99:
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
void F_64 ( struct V_103 * V_103 , int type , int V_86 ,
struct V_87 * V_88 )
{
struct V_84 * V_85 ;
int V_32 = - V_104 ;
V_85 = F_65 ( F_54 ( type ) , V_105 ) ;
if ( ! V_85 )
goto V_106;
V_32 = F_58 ( V_85 , V_86 , V_88 , 0 , 0 ,
V_107 , 0 , type ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_106;
}
F_68 ( V_85 , V_103 , 0 , V_108 , NULL , V_105 ) ;
return;
V_106:
F_69 ( V_103 , V_108 , V_32 ) ;
}
static int F_70 ( struct V_84 * V_109 ,
struct V_92 * V_93 )
{
struct V_103 * V_103 = F_71 ( V_109 -> V_110 ) ;
struct V_111 * V_112 [ V_113 + 1 ] ;
struct V_79 * V_94 ;
struct V_84 * V_85 ;
struct V_87 * V_88 ;
struct V_4 * V_114 ;
struct V_6 * V_7 ;
int V_86 ;
int V_32 ;
V_32 = F_72 ( V_93 , sizeof( * V_94 ) , V_112 , V_113 ,
V_115 ) ;
if ( V_32 < 0 )
goto V_106;
V_32 = V_35 ;
if ( ! V_112 [ V_98 ] )
goto V_106;
V_86 = F_73 ( V_112 [ V_98 ] ) ;
switch ( V_86 ) {
case V_116 :
V_88 = V_103 -> V_18 . V_117 ;
break;
case V_118 :
V_88 = V_103 -> V_18 . V_40 ;
break;
default:
V_7 = F_74 ( V_103 , V_86 ) ;
if ( ! V_7 )
goto V_106;
V_114 = F_51 ( V_7 ) ;
if ( ! V_114 )
goto V_106;
V_88 = & V_114 -> V_39 ;
break;
}
V_32 = - V_104 ;
V_85 = F_65 ( F_54 ( - 1 ) , V_105 ) ;
if ( ! V_85 )
goto V_106;
V_32 = F_58 ( V_85 , V_86 , V_88 ,
F_75 ( V_109 ) . V_89 ,
V_93 -> V_119 , V_107 , 0 ,
- 1 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_106;
}
V_32 = F_76 ( V_85 , V_103 , F_75 ( V_109 ) . V_89 ) ;
V_106:
return V_32 ;
}
static int F_77 ( struct V_84 * V_85 ,
struct V_120 * V_121 )
{
struct V_103 * V_103 = F_71 ( V_85 -> V_110 ) ;
int V_122 , V_123 ;
int V_124 , V_125 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_126 * V_127 ;
V_123 = V_121 -> args [ 0 ] ;
V_125 = V_124 = V_121 -> args [ 1 ] ;
for ( V_122 = V_123 ; V_122 < V_128 ; V_122 ++ , V_125 = 0 ) {
V_124 = 0 ;
V_127 = & V_103 -> V_129 [ V_122 ] ;
F_78 () ;
V_121 -> V_90 = F_79 ( & V_103 -> V_18 . V_130 ) ^
V_103 -> V_131 ;
F_80 (dev, head, index_hlist) {
if ( V_124 < V_125 )
goto V_132;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_132;
if ( F_58 ( V_85 , V_7 -> V_86 ,
& V_5 -> V_39 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_107 ,
V_133 ,
- 1 ) < 0 ) {
F_81 () ;
goto V_134;
}
F_82 ( V_121 , F_83 ( V_85 ) ) ;
V_132:
V_124 ++ ;
}
F_81 () ;
}
if ( V_122 == V_128 ) {
if ( F_58 ( V_85 , V_116 ,
V_103 -> V_18 . V_117 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_107 , V_133 ,
- 1 ) < 0 )
goto V_134;
else
V_122 ++ ;
}
if ( V_122 == V_128 + 1 ) {
if ( F_58 ( V_85 , V_118 ,
V_103 -> V_18 . V_40 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_107 , V_133 ,
- 1 ) < 0 )
goto V_134;
else
V_122 ++ ;
}
V_134:
V_121 -> args [ 0 ] = V_122 ;
V_121 -> args [ 1 ] = V_124 ;
return V_85 -> V_135 ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_136 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_45 )
F_36 ( V_7 ) ;
if ( V_7 -> V_50 & V_74 ) {
if ( V_5 -> V_39 . V_45 ) {
F_48 ( V_7 , & V_75 ) ;
F_48 ( V_7 , & V_137 ) ;
F_48 ( V_7 , & V_138 ) ;
} else {
F_85 ( V_7 , & V_75 ) ;
F_85 ( V_7 , & V_137 ) ;
F_85 ( V_7 , & V_138 ) ;
}
}
F_86 (ifa, &idev->addr_list, if_list) {
if ( V_136 -> V_50 & V_139 )
continue;
if ( V_5 -> V_39 . V_45 )
F_87 ( V_136 ) ;
else
F_88 ( V_136 ) ;
}
F_64 ( F_34 ( V_7 ) , V_80 ,
V_7 -> V_86 , & V_5 -> V_39 ) ;
}
static void F_89 ( struct V_103 * V_103 , T_2 V_140 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_90 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_141 = ( ! V_5 -> V_39 . V_45 ) ^ ( ! V_140 ) ;
V_5 -> V_39 . V_45 = V_140 ;
if ( V_141 )
F_84 ( V_5 ) ;
}
}
}
static int F_91 ( struct V_142 * V_143 , int * V_144 , int V_140 )
{
struct V_103 * V_103 ;
int V_145 ;
if ( ! F_92 () )
return F_93 () ;
V_103 = (struct V_103 * ) V_143 -> V_146 ;
V_145 = * V_144 ;
* V_144 = V_140 ;
if ( V_144 == & V_103 -> V_18 . V_40 -> V_45 ) {
if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_64 ( V_103 , V_80 ,
V_118 ,
V_103 -> V_18 . V_40 ) ;
F_94 () ;
return 0 ;
}
if ( V_144 == & V_103 -> V_18 . V_117 -> V_45 ) {
V_103 -> V_18 . V_40 -> V_45 = V_140 ;
F_89 ( V_103 , V_140 ) ;
if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_64 ( V_103 , V_80 ,
V_116 ,
V_103 -> V_18 . V_117 ) ;
} else if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_84 ( (struct V_4 * ) V_143 -> V_147 ) ;
F_94 () ;
if ( V_140 )
F_95 ( V_103 ) ;
return 1 ;
}
static void F_96 ( struct V_103 * V_103 , T_2 V_140 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_90 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_141 = ( ! V_5 -> V_39 . V_102 ) ^ ( ! V_140 ) ;
V_5 -> V_39 . V_102 = V_140 ;
if ( V_141 )
F_64 ( F_34 ( V_7 ) ,
V_83 ,
V_7 -> V_86 ,
& V_5 -> V_39 ) ;
}
}
}
static int F_97 ( struct V_142 * V_143 , int * V_144 , int V_140 )
{
struct V_103 * V_103 ;
int V_145 ;
if ( ! F_92 () )
return F_93 () ;
V_103 = (struct V_103 * ) V_143 -> V_146 ;
V_145 = * V_144 ;
* V_144 = V_140 ;
if ( V_144 == & V_103 -> V_18 . V_40 -> V_102 ) {
if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_64 ( V_103 ,
V_83 ,
V_118 ,
V_103 -> V_18 . V_40 ) ;
F_94 () ;
return 0 ;
}
if ( V_144 == & V_103 -> V_18 . V_117 -> V_102 ) {
V_103 -> V_18 . V_40 -> V_102 = V_140 ;
F_96 ( V_103 , V_140 ) ;
if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_64 ( V_103 ,
V_83 ,
V_116 ,
V_103 -> V_18 . V_117 ) ;
}
F_94 () ;
return 1 ;
}
void F_98 ( struct V_9 * V_10 )
{
F_66 ( ! F_99 ( & V_10 -> V_148 ) ) ;
#ifdef F_100
F_101 ( L_4 , V_47 ) ;
#endif
F_102 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_103 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_149 != V_150 ) {
F_104 ( L_6 , V_10 ) ;
return;
}
F_105 ( V_10 -> V_151 ) ;
F_106 ( V_10 , V_152 ) ;
}
static void
F_107 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_153 * V_144 ;
int V_154 = F_108 ( & V_10 -> V_155 ) ;
F_109 (p, &idev->addr_list) {
struct V_9 * V_136
= F_110 ( V_144 , struct V_9 , V_156 ) ;
if ( V_154 >= F_108 ( & V_136 -> V_155 ) )
break;
}
F_111 ( & V_10 -> V_156 , V_144 ) ;
}
static T_1 F_112 ( const struct V_157 * V_155 )
{
return F_113 ( F_114 ( V_155 ) , V_158 ) ;
}
static struct V_9 *
F_115 ( struct V_4 * V_5 , const struct V_157 * V_155 ,
const struct V_157 * V_159 , int V_160 ,
int V_161 , T_1 V_50 , T_1 V_162 , T_1 V_163 )
{
struct V_9 * V_136 = NULL ;
struct V_164 * V_151 ;
unsigned int V_165 ;
int V_32 = 0 ;
int V_166 = F_116 ( V_155 ) ;
if ( V_166 == V_167 ||
V_166 & V_168 ||
( ! ( V_5 -> V_7 -> V_50 & V_52 ) &&
V_166 & V_169 ) )
return F_30 ( - V_170 ) ;
F_117 () ;
if ( V_5 -> V_76 ) {
V_32 = - V_171 ;
goto V_172;
}
if ( V_5 -> V_39 . V_173 ) {
V_32 = - V_174 ;
goto V_172;
}
F_118 ( & V_175 ) ;
if ( F_119 ( F_34 ( V_5 -> V_7 ) , V_155 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_32 = - V_176 ;
goto V_177;
}
V_136 = F_25 ( sizeof( struct V_9 ) , V_105 ) ;
if ( ! V_136 ) {
F_38 ( L_8 ) ;
V_32 = - V_104 ;
goto V_177;
}
V_151 = F_120 ( V_5 , V_155 , false ) ;
if ( F_52 ( V_151 ) ) {
V_32 = F_121 ( V_151 ) ;
goto V_177;
}
F_122 ( V_5 -> V_43 ) ;
V_136 -> V_155 = * V_155 ;
if ( V_159 )
V_136 -> V_159 = * V_159 ;
F_123 ( & V_136 -> V_36 ) ;
F_124 ( & V_136 -> V_11 , V_178 ) ;
F_125 ( & V_136 -> V_148 ) ;
V_136 -> V_161 = V_161 ;
V_136 -> V_179 = V_160 ;
V_136 -> V_50 = V_50 | V_139 ;
V_136 -> V_162 = V_162 ;
V_136 -> V_163 = V_163 ;
V_136 -> V_1 = V_136 -> V_70 = V_13 ;
V_136 -> V_180 = false ;
V_136 -> V_151 = V_151 ;
V_136 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_136 ) ;
V_165 = F_112 ( V_155 ) ;
F_126 ( & V_136 -> V_148 , & V_181 [ V_165 ] ) ;
F_127 ( & V_175 ) ;
F_128 ( & V_5 -> V_36 ) ;
F_107 ( V_5 , V_136 ) ;
if ( V_136 -> V_50 & V_182 ) {
F_129 ( & V_136 -> V_183 , & V_5 -> V_59 ) ;
F_18 ( V_136 ) ;
}
F_18 ( V_136 ) ;
F_130 ( & V_5 -> V_36 ) ;
V_172:
F_131 () ;
if ( F_132 ( V_32 == 0 ) )
F_133 ( V_184 , V_136 ) ;
else {
F_26 ( V_136 ) ;
V_136 = F_30 ( V_32 ) ;
}
return V_136 ;
V_177:
F_127 ( & V_175 ) ;
goto V_172;
}
static enum V_185
F_134 ( struct V_9 * V_10 , unsigned long * V_186 )
{
struct V_9 * V_136 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_187 ;
enum V_185 V_188 = V_189 ;
* V_186 = V_13 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( V_136 == V_10 )
continue;
if ( ! F_135 ( & V_136 -> V_155 , & V_10 -> V_155 ,
V_10 -> V_179 ) )
continue;
if ( V_136 -> V_50 & ( V_190 | V_191 ) )
return V_192 ;
V_188 = V_193 ;
F_118 ( & V_136 -> V_36 ) ;
V_187 = F_136 ( V_136 -> V_162 , V_3 ) ;
if ( F_137 ( * V_186 , V_136 -> V_70 + V_187 * V_3 ) )
* V_186 = V_136 -> V_70 + V_187 * V_3 ;
F_127 ( & V_136 -> V_36 ) ;
}
return V_188 ;
}
static void
F_138 ( struct V_9 * V_10 , unsigned long V_186 , bool V_194 )
{
struct V_164 * V_151 ;
V_151 = F_139 ( & V_10 -> V_155 ,
V_10 -> V_179 ,
V_10 -> V_5 -> V_7 ,
0 , V_195 | V_196 ) ;
if ( V_151 ) {
if ( V_194 )
F_140 ( V_151 ) ;
else {
if ( ! ( V_151 -> V_197 & V_198 ) )
F_141 ( V_151 , V_186 ) ;
F_105 ( V_151 ) ;
}
}
}
static void F_142 ( struct V_9 * V_10 )
{
int V_149 ;
enum V_185 V_188 = V_192 ;
unsigned long V_186 ;
F_29 () ;
F_143 ( & V_10 -> V_36 ) ;
V_149 = V_10 -> V_149 ;
V_10 -> V_149 = V_150 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_149 == V_150 )
goto V_177;
F_143 ( & V_175 ) ;
F_145 ( & V_10 -> V_148 ) ;
F_144 ( & V_175 ) ;
F_146 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_50 & V_182 ) {
F_147 ( & V_10 -> V_183 ) ;
if ( V_10 -> V_199 ) {
F_148 ( V_10 -> V_199 ) ;
V_10 -> V_199 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_50 & V_190 && ! ( V_10 -> V_50 & V_191 ) )
V_188 = F_134 ( V_10 , & V_186 ) ;
F_149 ( & V_10 -> V_156 ) ;
F_11 ( V_10 ) ;
F_150 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_151 ( V_200 , V_10 ) ;
F_133 ( V_201 , V_10 ) ;
if ( V_188 != V_192 ) {
F_138 ( V_10 , V_186 ,
V_188 == V_189 ) ;
}
F_152 ( V_10 ) ;
V_177:
F_148 ( V_10 ) ;
}
static int F_153 ( struct V_9 * V_10 , struct V_9 * V_202 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_157 V_155 , * V_203 ;
unsigned long V_204 , V_205 , V_206 , V_207 ;
unsigned long V_208 ;
int V_209 ;
int V_210 = 0 ;
T_1 V_211 ;
unsigned long V_212 = V_13 ;
F_146 ( & V_5 -> V_36 ) ;
if ( V_202 ) {
F_143 ( & V_202 -> V_36 ) ;
memcpy ( & V_155 . V_213 [ 8 ] , & V_202 -> V_155 . V_213 [ 8 ] , 8 ) ;
F_144 ( & V_202 -> V_36 ) ;
V_203 = & V_155 ;
} else {
V_203 = NULL ;
}
V_214:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_65 <= 0 ) {
F_150 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_47 ) ;
F_102 ( V_5 ) ;
V_210 = - 1 ;
goto V_177;
}
F_143 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_215 ++ >= V_5 -> V_39 . V_216 ) {
V_5 -> V_39 . V_65 = - 1 ;
F_144 ( & V_10 -> V_36 ) ;
F_150 ( & V_5 -> V_36 ) ;
F_104 ( L_10 ,
V_47 ) ;
F_102 ( V_5 ) ;
V_210 = - 1 ;
goto V_177;
}
F_18 ( V_10 ) ;
memcpy ( V_155 . V_213 , V_10 -> V_155 . V_213 , 8 ) ;
F_154 ( V_5 , V_203 ) ;
memcpy ( & V_155 . V_213 [ 8 ] , V_5 -> V_217 , 8 ) ;
V_207 = ( V_212 - V_10 -> V_70 ) / V_3 ;
V_205 = F_155 ( V_218 ,
V_10 -> V_162 ,
V_5 -> V_39 . V_219 + V_207 ) ;
V_204 = F_155 ( V_218 ,
V_10 -> V_163 ,
V_5 -> V_39 . V_220 + V_207 -
V_5 -> V_39 . V_221 ) ;
V_209 = V_10 -> V_179 ;
V_206 = V_10 -> V_70 ;
F_144 ( & V_10 -> V_36 ) ;
V_208 = V_5 -> V_39 . V_216 *
V_5 -> V_39 . V_222 *
F_156 ( V_5 -> V_43 , V_223 ) / V_3 ;
F_150 ( & V_5 -> V_36 ) ;
V_207 = ( V_212 - V_206 + V_224 ) / V_3 ;
if ( V_204 <= V_208 + V_207 ) {
F_148 ( V_10 ) ;
F_102 ( V_5 ) ;
V_210 = - 1 ;
goto V_177;
}
V_211 = V_182 ;
if ( V_10 -> V_50 & V_225 )
V_211 |= V_225 ;
V_202 = F_115 ( V_5 , & V_155 , NULL , V_209 ,
F_157 ( & V_155 ) , V_211 ,
V_205 , V_204 ) ;
if ( F_52 ( V_202 ) ) {
F_148 ( V_10 ) ;
F_102 ( V_5 ) ;
F_43 ( L_11 , V_47 ) ;
V_203 = & V_155 ;
F_146 ( & V_5 -> V_36 ) ;
goto V_214;
}
F_143 ( & V_202 -> V_36 ) ;
V_202 -> V_199 = V_10 ;
V_202 -> V_1 = V_212 ;
V_202 -> V_70 = V_206 ;
F_144 ( & V_202 -> V_36 ) ;
F_158 ( V_202 ) ;
F_148 ( V_202 ) ;
F_102 ( V_5 ) ;
V_177:
return V_210 ;
}
static inline int F_159 ( int type )
{
if ( type & ( V_226 | V_227 | V_169 ) )
return 1 ;
return 0 ;
}
static inline bool F_160 ( struct V_4 * V_5 )
{
#ifdef F_161
return V_5 && V_5 -> V_39 . V_228 && V_5 -> V_39 . V_229 ;
#else
return false ;
#endif
}
static int F_162 ( struct V_103 * V_103 ,
struct V_230 * V_231 ,
struct V_232 * V_233 ,
int V_16 )
{
int V_210 ;
if ( V_16 <= V_231 -> V_234 ) {
switch ( V_16 ) {
case V_235 :
V_210 = V_231 -> V_236 ;
break;
case V_237 :
V_210 = V_231 -> V_238 ;
break;
default:
V_210 = ! ! F_163 ( V_16 , V_231 -> V_239 ) ;
}
goto V_177;
}
switch ( V_16 ) {
case V_240 :
V_210 = ! ! V_231 -> V_136 ;
break;
case V_241 :
V_210 = F_164 ( & V_231 -> V_136 -> V_155 , V_233 -> V_155 ) ;
break;
case V_235 :
V_210 = F_165 ( V_231 -> V_166 ) ;
if ( V_210 >= V_233 -> V_161 )
V_210 = - V_210 ;
else
V_210 -= 128 ;
V_231 -> V_236 = V_210 ;
break;
case V_242 :
{
T_3 V_243 = V_244 ;
if ( ! F_160 ( V_231 -> V_136 -> V_5 ) )
V_243 |= V_225 ;
V_210 = F_159 ( V_231 -> V_166 ) ||
! ( V_231 -> V_136 -> V_50 & V_243 ) ;
break;
}
#ifdef F_166
case V_245 :
{
int V_246 = ! ( V_233 -> V_247 & V_248 ) ;
V_210 = ! ( V_231 -> V_136 -> V_50 & V_249 ) ^ V_246 ;
break;
}
#endif
case V_250 :
V_210 = ( ! V_233 -> V_86 ||
V_233 -> V_86 == V_231 -> V_136 -> V_5 -> V_7 -> V_86 ) ;
break;
case V_251 :
V_210 = F_167 ( V_103 ,
& V_231 -> V_136 -> V_155 , V_231 -> V_166 ,
V_231 -> V_136 -> V_5 -> V_7 -> V_86 ) == V_233 -> V_252 ;
break;
case V_253 :
{
int V_254 = V_233 -> V_247 & ( V_255 | V_256 ) ?
! ! ( V_233 -> V_247 & V_256 ) :
V_231 -> V_136 -> V_5 -> V_39 . V_65 >= 2 ;
V_210 = ( ! ( V_231 -> V_136 -> V_50 & V_182 ) ) ^ V_254 ;
break;
}
case V_257 :
V_210 = ! ( F_168 ( & V_231 -> V_136 -> V_155 ) ^
F_168 ( V_233 -> V_155 ) ) ;
break;
case V_237 :
V_210 = F_169 ( & V_231 -> V_136 -> V_155 , V_233 -> V_155 ) ;
if ( V_210 > V_231 -> V_136 -> V_179 )
V_210 = V_231 -> V_136 -> V_179 ;
V_231 -> V_238 = V_210 ;
break;
#ifdef F_161
case V_258 :
V_210 = ! ( V_231 -> V_136 -> V_50 & V_225 ) ;
break;
#endif
default:
V_210 = 0 ;
}
if ( V_210 )
F_170 ( V_16 , V_231 -> V_239 ) ;
V_231 -> V_234 = V_16 ;
V_177:
return V_210 ;
}
static int F_171 ( struct V_103 * V_103 ,
struct V_232 * V_233 ,
struct V_4 * V_5 ,
struct V_230 * V_259 ,
int V_260 )
{
struct V_230 * V_231 = & V_259 [ 1 - V_260 ] , * V_261 = & V_259 [ V_260 ] ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_231 -> V_136 -> V_50 & V_139 ) &&
( ! ( V_231 -> V_136 -> V_50 & V_225 ) ) )
continue;
V_231 -> V_166 = F_173 ( & V_231 -> V_136 -> V_155 ) ;
if ( F_174 ( V_231 -> V_166 == V_167 ||
V_231 -> V_166 & V_168 ) ) {
F_175 ( L_12 ,
V_5 -> V_7 -> V_48 ) ;
continue;
}
V_231 -> V_234 = - 1 ;
F_176 ( V_231 -> V_239 , V_262 ) ;
for ( V_16 = 0 ; V_16 < V_262 ; V_16 ++ ) {
int V_263 , V_264 ;
V_263 = F_162 ( V_103 , V_261 , V_233 , V_16 ) ;
V_264 = F_162 ( V_103 , V_231 , V_233 , V_16 ) ;
if ( V_263 > V_264 ) {
if ( V_16 == V_235 &&
V_231 -> V_236 > 0 ) {
goto V_177;
}
break;
} else if ( V_263 < V_264 ) {
if ( V_261 -> V_136 )
F_148 ( V_261 -> V_136 ) ;
F_18 ( V_231 -> V_136 ) ;
F_177 ( V_261 , V_231 ) ;
V_260 = 1 - V_260 ;
V_231 -> V_136 = V_261 -> V_136 ;
break;
}
}
}
V_177:
F_178 ( & V_5 -> V_36 ) ;
return V_260 ;
}
int F_179 ( struct V_103 * V_103 , const struct V_6 * V_265 ,
const struct V_157 * V_266 , unsigned int V_247 ,
struct V_157 * V_267 )
{
struct V_230 V_259 [ 2 ] , * V_261 ;
struct V_232 V_233 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_268 ;
bool V_269 = false ;
int V_260 = 0 ;
V_268 = F_173 ( V_266 ) ;
V_233 . V_155 = V_266 ;
V_233 . V_86 = V_265 ? V_265 -> V_86 : 0 ;
V_233 . V_161 = F_165 ( V_268 ) ;
V_233 . V_252 = F_167 ( V_103 , V_266 , V_268 , V_233 . V_86 ) ;
V_233 . V_247 = V_247 ;
V_259 [ V_260 ] . V_234 = - 1 ;
V_259 [ V_260 ] . V_136 = NULL ;
F_78 () ;
if ( V_265 ) {
V_5 = F_51 ( V_265 ) ;
if ( ( V_268 & V_168 ) ||
V_233 . V_161 <= V_270 ||
( V_5 && V_5 -> V_39 . V_271 ) ) {
V_269 = true ;
}
}
if ( V_269 ) {
if ( V_5 )
V_260 = F_171 ( V_103 , & V_233 , V_5 , V_259 , V_260 ) ;
} else {
F_180 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
continue;
V_260 = F_171 ( V_103 , & V_233 , V_5 , V_259 , V_260 ) ;
}
}
F_81 () ;
V_261 = & V_259 [ V_260 ] ;
if ( ! V_261 -> V_136 )
return - V_170 ;
* V_267 = V_261 -> V_136 -> V_155 ;
F_148 ( V_261 -> V_136 ) ;
return 0 ;
}
int F_181 ( struct V_4 * V_5 , struct V_157 * V_155 ,
T_1 V_272 )
{
struct V_9 * V_10 ;
int V_32 = - V_170 ;
F_182 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_161 > V_273 )
break;
if ( V_10 -> V_161 == V_273 &&
! ( V_10 -> V_50 & V_272 ) ) {
* V_155 = V_10 -> V_155 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_183 ( struct V_6 * V_7 , struct V_157 * V_155 ,
T_1 V_272 )
{
struct V_4 * V_5 ;
int V_32 = - V_170 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
V_32 = F_181 ( V_5 , V_155 , V_272 ) ;
F_178 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_32 ;
}
static int F_184 ( struct V_4 * V_5 )
{
int V_274 = 0 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list)
V_274 ++ ;
F_178 ( & V_5 -> V_36 ) ;
return V_274 ;
}
int F_185 ( struct V_103 * V_103 , const struct V_157 * V_155 ,
const struct V_6 * V_7 , int V_275 )
{
return F_186 ( V_103 , V_155 , V_7 , V_275 , V_139 ) ;
}
int F_186 ( struct V_103 * V_103 , const struct V_157 * V_155 ,
const struct V_6 * V_7 , int V_275 ,
T_1 V_272 )
{
struct V_9 * V_10 ;
unsigned int V_165 = F_112 ( V_155 ) ;
T_1 V_276 ;
F_117 () ;
F_80 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_187 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_103 ) )
continue;
V_276 = ( V_10 -> V_50 & V_225 )
? ( V_10 -> V_50 & ~ V_139 )
: V_10 -> V_50 ;
if ( F_164 ( & V_10 -> V_155 , V_155 ) &&
! ( V_276 & V_272 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_161 & ( V_273 | V_277 ) || V_275 ) ) ) {
F_131 () ;
return 1 ;
}
}
F_131 () ;
return 0 ;
}
static bool F_119 ( struct V_103 * V_103 , const struct V_157 * V_155 ,
struct V_6 * V_7 )
{
unsigned int V_165 = F_112 ( V_155 ) ;
struct V_9 * V_10 ;
F_188 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_187 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_103 ) )
continue;
if ( F_164 ( & V_10 -> V_155 , V_155 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_189 ( const struct V_157 * V_155 ,
const unsigned int V_179 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_136 ;
bool V_210 = false ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_210 = F_135 ( V_155 , & V_136 -> V_155 , V_179 ) ;
if ( V_210 )
break;
}
F_178 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_210 ;
}
int F_190 ( const struct V_157 * V_155 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_136 ;
int V_278 ;
V_278 = 0 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_278 = F_135 ( V_155 , & V_136 -> V_155 ,
V_136 -> V_179 ) ;
if ( V_278 )
break;
}
F_178 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_278 ;
}
struct V_9 * F_191 ( struct V_103 * V_103 , const struct V_157 * V_155 ,
struct V_6 * V_7 , int V_275 )
{
struct V_9 * V_10 , * V_279 = NULL ;
unsigned int V_165 = F_112 ( V_155 ) ;
F_117 () ;
F_192 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_187 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_103 ) )
continue;
if ( F_164 ( & V_10 -> V_155 , V_155 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_161 & ( V_273 | V_277 ) || V_275 ) ) {
V_279 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_131 () ;
return V_279 ;
}
static void F_193 ( struct V_9 * V_10 , int V_280 )
{
if ( V_10 -> V_50 & V_190 ) {
F_143 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_139 ;
if ( V_280 )
V_10 -> V_50 |= V_281 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_280 )
F_151 ( 0 , V_10 ) ;
F_148 ( V_10 ) ;
} else if ( V_10 -> V_50 & V_182 ) {
struct V_9 * V_199 ;
F_143 ( & V_10 -> V_36 ) ;
V_199 = V_10 -> V_199 ;
if ( V_199 ) {
F_18 ( V_199 ) ;
F_144 ( & V_10 -> V_36 ) ;
F_153 ( V_199 , V_10 ) ;
F_148 ( V_199 ) ;
} else {
F_144 ( & V_10 -> V_36 ) ;
}
F_142 ( V_10 ) ;
} else {
F_142 ( V_10 ) ;
}
}
static int F_194 ( struct V_9 * V_10 )
{
int V_32 = - V_282 ;
F_143 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_149 == V_283 ) {
V_10 -> V_149 = V_284 ;
V_32 = 0 ;
}
F_144 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_195 ( struct V_9 * V_10 )
{
struct V_157 V_155 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_103 * V_103 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_194 ( V_10 ) ) {
F_148 ( V_10 ) ;
return;
}
F_196 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_155 ) ;
F_143 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_285 ) {
int V_161 = V_10 -> V_161 ;
T_1 V_50 = V_10 -> V_50 ;
struct V_157 V_286 ;
struct V_9 * V_287 ;
T_1 V_162 , V_288 ;
int V_160 = V_10 -> V_179 ;
int V_289 = V_10 -> V_290 + 1 ;
if ( V_289 > V_103 -> V_18 . V_42 . V_291 ) {
F_196 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
goto V_292;
}
V_286 = V_10 -> V_155 ;
if ( F_197 ( & V_286 , V_289 ,
V_5 ) )
goto V_292;
V_162 = V_10 -> V_162 ;
V_288 = V_10 -> V_163 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_293 &&
F_184 ( V_5 ) >=
V_5 -> V_39 . V_293 )
goto V_294;
F_196 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
V_287 = F_115 ( V_5 , & V_286 , NULL , V_160 ,
V_161 , V_50 , V_162 ,
V_288 ) ;
if ( F_52 ( V_287 ) )
goto V_294;
F_143 ( & V_287 -> V_36 ) ;
V_287 -> V_290 = V_289 ;
V_287 -> V_149 = V_295 ;
F_144 ( & V_287 -> V_36 ) ;
F_16 ( V_287 , V_103 -> V_18 . V_42 . V_296 ) ;
F_148 ( V_287 ) ;
V_294:
F_143 ( & V_10 -> V_36 ) ;
} else if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_173 ) {
V_155 . V_297 [ 0 ] = F_198 ( 0xfe800000 ) ;
V_155 . V_297 [ 1 ] = 0 ;
if ( ! F_199 ( V_155 . V_213 + 8 , V_5 -> V_7 ) &&
F_164 ( & V_10 -> V_155 , & V_155 ) ) {
V_5 -> V_39 . V_173 = 1 ;
F_43 ( L_16 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
V_292:
V_10 -> V_149 = V_298 ;
F_144 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_200 ( struct V_6 * V_7 , const struct V_157 * V_155 )
{
struct V_157 V_299 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_201 ( V_155 , & V_299 ) ;
F_48 ( V_7 , & V_299 ) ;
}
void F_202 ( struct V_4 * V_5 , const struct V_157 * V_155 )
{
struct V_157 V_299 ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_201 ( V_155 , & V_299 ) ;
F_203 ( V_5 , & V_299 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_157 V_155 ;
if ( V_10 -> V_179 >= 127 )
return;
F_204 ( & V_155 , & V_10 -> V_155 , V_10 -> V_179 ) ;
if ( F_205 ( & V_155 ) )
return;
F_206 ( V_10 -> V_5 , & V_155 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_157 V_155 ;
if ( V_10 -> V_179 >= 127 )
return;
F_204 ( & V_155 , & V_10 -> V_155 , V_10 -> V_179 ) ;
if ( F_205 ( & V_155 ) )
return;
F_207 ( V_10 -> V_5 , & V_155 ) ;
}
static int F_208 ( T_3 * V_300 , struct V_6 * V_7 )
{
if ( V_7 -> V_301 != V_302 )
return - 1 ;
memcpy ( V_300 , V_7 -> V_303 , 8 ) ;
V_300 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_209 ( T_3 * V_300 , struct V_6 * V_7 )
{
union V_304 * V_305 ;
if ( V_7 -> V_301 != V_306 )
return - 1 ;
V_305 = (union V_304 * ) V_7 -> V_303 ;
memcpy ( V_300 , & V_305 -> V_307 . V_308 , sizeof( V_305 -> V_307 . V_308 ) ) ;
V_300 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_210 ( T_3 * V_300 , struct V_6 * V_7 )
{
if ( V_7 -> V_301 != V_309 )
return - 1 ;
memset ( V_300 , 0 , 7 ) ;
V_300 [ 7 ] = * ( T_3 * ) V_7 -> V_303 ;
return 0 ;
}
static int F_211 ( T_3 * V_300 , struct V_6 * V_7 )
{
if ( V_7 -> V_301 != V_310 )
return - 1 ;
memcpy ( V_300 , V_7 -> V_303 + 12 , 8 ) ;
V_300 [ 0 ] |= 2 ;
return 0 ;
}
static int F_212 ( T_3 * V_300 , T_4 V_155 )
{
if ( V_155 == 0 )
return - 1 ;
V_300 [ 0 ] = ( F_213 ( V_155 ) || F_214 ( V_155 ) ||
F_215 ( V_155 ) || F_216 ( V_155 ) ||
F_217 ( V_155 ) || F_218 ( V_155 ) ||
F_219 ( V_155 ) || F_220 ( V_155 ) ||
F_221 ( V_155 ) || F_222 ( V_155 ) ||
F_223 ( V_155 ) ) ? 0x00 : 0x02 ;
V_300 [ 1 ] = 0 ;
V_300 [ 2 ] = 0x5E ;
V_300 [ 3 ] = 0xFE ;
memcpy ( V_300 + 4 , & V_155 , 4 ) ;
return 0 ;
}
static int F_224 ( T_3 * V_300 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_212 ( V_300 , * ( T_4 * ) V_7 -> V_303 ) ;
return - 1 ;
}
static int F_225 ( T_3 * V_300 , struct V_6 * V_7 )
{
return F_212 ( V_300 , * ( T_4 * ) V_7 -> V_303 ) ;
}
static int F_226 ( T_3 * V_300 , struct V_6 * V_7 )
{
memcpy ( V_300 , V_7 -> V_311 , 3 ) ;
memcpy ( V_300 + 5 , V_7 -> V_311 + 3 , 3 ) ;
V_300 [ 3 ] = 0xFF ;
V_300 [ 4 ] = 0xFE ;
V_300 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_199 ( T_3 * V_300 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_312 :
case V_313 :
return F_227 ( V_300 , V_7 ) ;
case V_314 :
return F_210 ( V_300 , V_7 ) ;
case V_315 :
return F_211 ( V_300 , V_7 ) ;
case V_55 :
return F_224 ( V_300 , V_7 ) ;
case V_316 :
return F_225 ( V_300 , V_7 ) ;
case V_317 :
case V_318 :
return F_208 ( V_300 , V_7 ) ;
case V_319 :
return F_209 ( V_300 , V_7 ) ;
case V_63 :
return F_226 ( V_300 , V_7 ) ;
}
return - 1 ;
}
static int F_228 ( T_3 * V_300 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_182 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_161 > V_273 )
break;
if ( V_10 -> V_161 == V_273 && ! ( V_10 -> V_50 & V_139 ) ) {
memcpy ( V_300 , V_10 -> V_155 . V_213 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_178 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_229 ( struct V_4 * V_5 )
{
V_320:
F_230 ( V_5 -> V_217 , sizeof( V_5 -> V_217 ) ) ;
V_5 -> V_217 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_217 [ 0 ] == 0xfd &&
( V_5 -> V_217 [ 1 ] & V_5 -> V_217 [ 2 ] & V_5 -> V_217 [ 3 ] & V_5 -> V_217 [ 4 ] & V_5 -> V_217 [ 5 ] & V_5 -> V_217 [ 6 ] ) == 0xff &&
( V_5 -> V_217 [ 7 ] & 0x80 ) )
goto V_320;
if ( ( V_5 -> V_217 [ 0 ] | V_5 -> V_217 [ 1 ] ) == 0 ) {
if ( V_5 -> V_217 [ 2 ] == 0x5e && V_5 -> V_217 [ 3 ] == 0xfe )
goto V_320;
if ( ( V_5 -> V_217 [ 2 ] | V_5 -> V_217 [ 3 ] | V_5 -> V_217 [ 4 ] | V_5 -> V_217 [ 5 ] | V_5 -> V_217 [ 6 ] | V_5 -> V_217 [ 7 ] ) == 0x00 )
goto V_320;
}
}
static void V_61 ( unsigned long V_321 )
{
struct V_4 * V_5 = (struct V_4 * ) V_321 ;
unsigned long V_186 ;
F_117 () ;
F_146 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 )
goto V_177;
F_229 ( V_5 ) ;
V_186 = V_13 +
V_5 -> V_39 . V_220 * V_3 -
V_5 -> V_39 . V_216 * V_5 -> V_39 . V_222 *
F_156 ( V_5 -> V_43 , V_223 ) -
V_5 -> V_39 . V_221 * V_3 ;
if ( F_137 ( V_186 , V_13 ) ) {
F_104 ( L_17 ,
V_47 , V_5 -> V_7 -> V_48 ) ;
goto V_177;
}
if ( ! F_15 ( & V_5 -> V_60 , V_186 ) )
F_14 ( V_5 ) ;
V_177:
F_150 ( & V_5 -> V_36 ) ;
F_131 () ;
F_102 ( V_5 ) ;
}
static void F_154 ( struct V_4 * V_5 , struct V_157 * V_203 )
{
if ( V_203 && memcmp ( V_5 -> V_217 , & V_203 -> V_213 [ 8 ] , 8 ) == 0 )
F_229 ( V_5 ) ;
}
static void
F_231 ( struct V_157 * V_322 , int V_323 , struct V_6 * V_7 ,
unsigned long V_186 , T_1 V_50 )
{
struct V_324 V_325 = {
. V_326 = V_327 ,
. V_328 = V_329 ,
. V_330 = V_7 -> V_86 ,
. V_331 = V_186 ,
. V_332 = V_323 ,
. V_333 = V_334 | V_50 ,
. V_335 . V_336 = F_34 ( V_7 ) ,
. V_337 = V_338 ,
} ;
V_325 . V_339 = * V_322 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_340 ) )
V_325 . V_333 |= V_341 ;
#endif
F_232 ( & V_325 ) ;
}
static struct V_164 * F_139 ( const struct V_157 * V_322 ,
int V_323 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_342 )
{
struct V_343 * V_344 ;
struct V_164 * V_151 = NULL ;
struct V_345 * V_143 ;
V_143 = F_233 ( F_34 ( V_7 ) , V_327 ) ;
if ( ! V_143 )
return NULL ;
F_172 ( & V_143 -> V_346 ) ;
V_344 = F_234 ( & V_143 -> V_347 , V_322 , V_323 , NULL , 0 ) ;
if ( ! V_344 )
goto V_177;
V_342 |= V_348 ;
for ( V_151 = V_344 -> V_349 ; V_151 ; V_151 = V_151 -> V_233 . V_350 ) {
if ( V_151 -> V_233 . V_7 -> V_86 != V_7 -> V_86 )
continue;
if ( ( V_151 -> V_197 & V_50 ) != V_50 )
continue;
if ( ( V_151 -> V_197 & V_342 ) != 0 )
continue;
F_235 ( & V_151 -> V_233 ) ;
break;
}
V_177:
F_178 ( & V_143 -> V_346 ) ;
return V_151 ;
}
static void F_236 ( struct V_6 * V_7 )
{
struct V_324 V_325 = {
. V_326 = V_351 ,
. V_328 = V_329 ,
. V_330 = V_7 -> V_86 ,
. V_332 = 8 ,
. V_333 = V_334 ,
. V_335 . V_336 = F_34 ( V_7 ) ,
} ;
F_237 ( & V_325 . V_339 , F_198 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_232 ( & V_325 ) ;
}
static struct V_4 * F_238 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_104 ) ;
if ( V_5 -> V_39 . V_173 )
return F_30 ( - V_174 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_236 ( V_7 ) ;
return V_5 ;
}
static void F_239 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_218 V_162 , V_218 V_163 ,
bool V_352 , unsigned long V_212 )
{
T_1 V_50 ;
struct V_9 * V_202 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_207 , V_353 , V_354 ;
if ( V_10 != V_202 -> V_199 )
continue;
V_207 = ( V_212 - V_202 -> V_1 ) / V_3 ;
V_353 = V_5 -> V_39 . V_219 - V_207 ;
if ( V_353 < 0 )
V_353 = 0 ;
V_354 = V_5 -> V_39 . V_220 -
V_5 -> V_39 . V_221 - V_207 ;
if ( V_354 < 0 )
V_354 = 0 ;
if ( V_162 > V_353 )
V_162 = V_353 ;
if ( V_163 > V_354 )
V_163 = V_354 ;
F_118 ( & V_202 -> V_36 ) ;
V_50 = V_202 -> V_50 ;
V_202 -> V_162 = V_162 ;
V_202 -> V_163 = V_163 ;
V_202 -> V_70 = V_212 ;
if ( V_163 > 0 )
V_202 -> V_50 &= ~ V_244 ;
F_127 ( & V_202 -> V_36 ) ;
if ( ! ( V_50 & V_139 ) )
F_151 ( 0 , V_202 ) ;
}
if ( ( V_352 || F_240 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_178 ( & V_5 -> V_36 ) ;
F_153 ( V_10 , NULL ) ;
} else {
F_178 ( & V_5 -> V_36 ) ;
}
}
void F_241 ( struct V_6 * V_7 , T_3 * V_355 , int V_135 , bool V_356 )
{
struct V_357 * V_358 ;
V_218 V_162 ;
V_218 V_163 ;
int V_166 ;
T_1 V_211 = 0 ;
struct V_4 * V_114 ;
struct V_103 * V_103 = F_34 ( V_7 ) ;
V_358 = (struct V_357 * ) V_355 ;
if ( V_135 < sizeof( struct V_357 ) ) {
F_38 ( L_18 ) ;
return;
}
V_166 = F_116 ( & V_358 -> V_359 ) ;
if ( V_166 & ( V_168 | V_360 ) )
return;
V_162 = F_242 ( V_358 -> V_361 ) ;
V_163 = F_242 ( V_358 -> V_362 ) ;
if ( V_163 > V_162 ) {
F_243 ( L_19 ) ;
return;
}
V_114 = F_244 ( V_7 ) ;
if ( ! V_114 ) {
F_175 ( L_20 ,
V_7 -> V_48 ) ;
return;
}
if ( V_358 -> V_278 ) {
struct V_164 * V_151 ;
unsigned long V_363 ;
if ( V_3 > V_364 )
V_363 = F_136 ( V_162 , V_3 ) ;
else
V_363 = F_136 ( V_162 , V_364 ) ;
if ( F_245 ( V_363 ) )
V_363 *= V_3 ;
V_151 = F_139 ( & V_358 -> V_359 ,
V_358 -> V_179 ,
V_7 ,
V_365 | V_366 ,
V_195 | V_196 ) ;
if ( V_151 ) {
if ( V_162 == 0 ) {
F_140 ( V_151 ) ;
V_151 = NULL ;
} else if ( F_245 ( V_363 ) ) {
F_141 ( V_151 , V_13 + V_363 ) ;
} else {
F_246 ( V_151 ) ;
}
} else if ( V_162 ) {
T_5 V_186 = 0 ;
int V_50 = V_365 | V_366 ;
if ( F_245 ( V_363 ) ) {
V_50 |= V_198 ;
V_186 = F_247 ( V_363 ) ;
}
F_231 ( & V_358 -> V_359 , V_358 -> V_179 ,
V_7 , V_186 , V_50 ) ;
}
F_105 ( V_151 ) ;
}
if ( V_358 -> V_367 && V_114 -> V_39 . V_367 ) {
struct V_9 * V_10 ;
struct V_157 V_155 ;
int V_352 = 0 , V_368 = 0 ;
bool V_180 = false ;
if ( V_358 -> V_179 == 64 ) {
memcpy ( & V_155 , & V_358 -> V_359 , 8 ) ;
if ( ! F_205 ( & V_114 -> V_66 ) ) {
F_172 ( & V_114 -> V_36 ) ;
memcpy ( V_155 . V_213 + 8 ,
V_114 -> V_66 . V_213 + 8 , 8 ) ;
F_178 ( & V_114 -> V_36 ) ;
V_180 = true ;
} else if ( V_114 -> V_369 ==
V_370 &&
! F_197 ( & V_155 , 0 ,
V_114 ) ) {
V_211 |= V_285 ;
goto V_371;
} else if ( F_199 ( V_155 . V_213 + 8 , V_7 ) &&
F_228 ( V_155 . V_213 + 8 , V_114 ) ) {
F_102 ( V_114 ) ;
return;
}
goto V_371;
}
F_175 ( L_21 ,
V_358 -> V_179 ) ;
F_102 ( V_114 ) ;
return;
V_371:
V_10 = F_191 ( V_103 , & V_155 , V_7 , 1 ) ;
if ( ! V_10 && V_162 ) {
int V_293 = V_114 -> V_39 . V_293 ;
#ifdef F_161
if ( V_114 -> V_39 . V_228 &&
! V_103 -> V_18 . V_117 -> V_45 && V_356 )
V_211 = V_225 ;
#endif
if ( ! V_293 ||
F_184 ( V_114 ) < V_293 )
V_10 = F_115 ( V_114 , & V_155 , NULL ,
V_358 -> V_179 ,
V_166 & V_372 ,
V_211 , V_162 ,
V_163 ) ;
if ( F_248 ( V_10 ) ) {
F_102 ( V_114 ) ;
return;
}
V_368 = 0 ;
V_352 = 1 ;
F_143 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_373 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_180 = V_180 ;
F_144 ( & V_10 -> V_36 ) ;
F_158 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_212 ;
T_1 V_374 ;
F_143 ( & V_10 -> V_36 ) ;
V_212 = V_13 ;
if ( V_10 -> V_162 > ( V_212 - V_10 -> V_70 ) / V_3 )
V_374 = V_10 -> V_162 - ( V_212 - V_10 -> V_70 ) / V_3 ;
else
V_374 = 0 ;
if ( ! V_368 && ! V_352 && V_374 ) {
const T_1 V_375 = F_155 ( T_1 ,
V_374 , V_376 ) ;
V_162 = F_249 ( V_162 , V_375 ) ;
V_368 = 1 ;
}
if ( V_368 ) {
V_10 -> V_162 = V_162 ;
V_10 -> V_163 = V_163 ;
V_10 -> V_70 = V_212 ;
V_50 = V_10 -> V_50 ;
V_10 -> V_50 &= ~ V_244 ;
F_144 ( & V_10 -> V_36 ) ;
if ( ! ( V_50 & V_139 ) )
F_151 ( 0 , V_10 ) ;
} else
F_144 ( & V_10 -> V_36 ) ;
F_239 ( V_114 , V_10 , V_162 , V_163 ,
V_352 , V_212 ) ;
F_148 ( V_10 ) ;
F_250 () ;
}
}
F_251 ( V_377 , V_114 , V_358 ) ;
F_102 ( V_114 ) ;
}
int F_252 ( struct V_103 * V_103 , void T_6 * V_378 )
{
struct V_379 V_380 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_253 () ;
V_32 = - V_381 ;
if ( F_254 ( & V_380 , V_378 , sizeof( struct V_379 ) ) )
goto V_382;
V_7 = F_74 ( V_103 , V_380 . V_383 ) ;
V_32 = - V_171 ;
if ( ! V_7 )
goto V_382;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_384 * V_385 = V_7 -> V_386 ;
struct V_387 V_388 ;
struct V_389 V_144 ;
V_32 = - V_170 ;
if ( ! ( F_116 ( & V_380 . V_390 ) & V_227 ) )
goto V_382;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_391 . V_266 = V_380 . V_390 . V_297 [ 3 ] ;
V_144 . V_391 . V_267 = 0 ;
V_144 . V_391 . V_392 = 4 ;
V_144 . V_391 . V_393 = 5 ;
V_144 . V_391 . V_394 = V_395 ;
V_144 . V_391 . V_396 = 64 ;
V_388 . V_397 . V_398 = ( V_399 void T_6 * ) & V_144 ;
if ( V_385 -> V_400 ) {
T_7 V_401 = F_255 () ;
F_256 ( V_402 ) ;
V_32 = V_385 -> V_400 ( V_7 , & V_388 , V_403 ) ;
F_256 ( V_401 ) ;
} else
V_32 = - V_404 ;
if ( V_32 == 0 ) {
V_32 = - V_104 ;
V_7 = F_257 ( V_103 , V_144 . V_48 ) ;
if ( ! V_7 )
goto V_382;
V_32 = F_258 ( V_7 ) ;
}
}
#endif
V_382:
F_94 () ;
return V_32 ;
}
static int F_259 ( struct V_405 * V_110 , bool V_406 ,
const struct V_157 * V_155 , int V_86 )
{
int V_210 ;
F_29 () ;
F_260 ( V_110 ) ;
if ( V_406 )
V_210 = F_261 ( V_110 , V_86 , V_155 ) ;
else
V_210 = F_262 ( V_110 , V_86 , V_155 ) ;
F_263 ( V_110 ) ;
return V_210 ;
}
static int F_264 ( struct V_103 * V_103 , int V_86 ,
const struct V_157 * V_322 ,
const struct V_157 * V_407 ,
unsigned int V_323 , V_218 V_408 ,
V_218 V_163 , V_218 V_162 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_409 ;
T_5 V_186 ;
int V_161 ;
T_1 V_50 ;
F_29 () ;
if ( V_323 > 128 )
return - V_35 ;
if ( ! V_162 || V_163 > V_162 )
return - V_35 ;
if ( V_408 & V_373 && V_323 != 64 )
return - V_35 ;
V_7 = F_74 ( V_103 , V_86 ) ;
if ( ! V_7 )
return - V_171 ;
V_5 = F_238 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_121 ( V_5 ) ;
if ( V_408 & V_410 ) {
int V_210 = F_259 ( V_103 -> V_18 . V_411 ,
true , V_322 , V_86 ) ;
if ( V_210 < 0 )
return V_210 ;
}
V_161 = F_157 ( V_322 ) ;
V_409 = F_136 ( V_162 , V_3 ) ;
if ( F_245 ( V_409 ) ) {
V_186 = F_247 ( V_409 * V_3 ) ;
V_162 = V_409 ;
V_50 = V_198 ;
} else {
V_186 = 0 ;
V_50 = 0 ;
V_408 |= V_190 ;
}
V_409 = F_136 ( V_163 , V_3 ) ;
if ( F_245 ( V_409 ) ) {
if ( V_409 == 0 )
V_408 |= V_244 ;
V_163 = V_409 ;
}
V_10 = F_115 ( V_5 , V_322 , V_407 , V_323 , V_161 , V_408 ,
V_162 , V_163 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_408 & V_191 ) ) {
F_231 ( & V_10 -> V_155 , V_10 -> V_179 , V_7 ,
V_186 , V_50 ) ;
}
F_158 ( V_10 ) ;
if ( V_408 & V_373 )
F_239 ( V_5 , V_10 , V_162 , V_163 ,
true , V_13 ) ;
F_148 ( V_10 ) ;
F_265 () ;
return 0 ;
} else if ( V_408 & V_410 ) {
F_259 ( V_103 -> V_18 . V_411 ,
false , V_322 , V_86 ) ;
}
return F_121 ( V_10 ) ;
}
static int F_266 ( struct V_103 * V_103 , int V_86 , T_1 V_408 ,
const struct V_157 * V_322 , unsigned int V_323 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_323 > 128 )
return - V_35 ;
V_7 = F_74 ( V_103 , V_86 ) ;
if ( ! V_7 )
return - V_171 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_412 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_179 == V_323 &&
F_164 ( V_322 , & V_10 -> V_155 ) ) {
F_18 ( V_10 ) ;
F_178 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_182 ) &&
( V_408 & V_373 ) )
F_239 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_142 ( V_10 ) ;
F_265 () ;
if ( F_267 ( V_322 ) ) {
F_259 ( V_103 -> V_18 . V_411 ,
false , V_322 , V_7 -> V_86 ) ;
}
return 0 ;
}
}
F_178 ( & V_5 -> V_36 ) ;
return - V_170 ;
}
int F_268 ( struct V_103 * V_103 , void T_6 * V_378 )
{
struct V_379 V_380 ;
int V_32 ;
if ( ! F_269 ( V_103 -> V_413 , V_414 ) )
return - V_415 ;
if ( F_254 ( & V_380 , V_378 , sizeof( struct V_379 ) ) )
return - V_381 ;
F_253 () ;
V_32 = F_264 ( V_103 , V_380 . V_383 , & V_380 . V_390 , NULL ,
V_380 . V_416 , V_190 ,
V_417 , V_417 ) ;
F_94 () ;
return V_32 ;
}
int F_270 ( struct V_103 * V_103 , void T_6 * V_378 )
{
struct V_379 V_380 ;
int V_32 ;
if ( ! F_269 ( V_103 -> V_413 , V_414 ) )
return - V_415 ;
if ( F_254 ( & V_380 , V_378 , sizeof( struct V_379 ) ) )
return - V_381 ;
F_253 () ;
V_32 = F_266 ( V_103 , V_380 . V_383 , 0 , & V_380 . V_390 ,
V_380 . V_416 ) ;
F_94 () ;
return V_32 ;
}
static void F_271 ( struct V_4 * V_5 , const struct V_157 * V_155 ,
int V_323 , int V_161 )
{
struct V_9 * V_10 ;
V_10 = F_115 ( V_5 , V_155 , NULL , V_323 ,
V_161 , V_190 ,
V_417 , V_417 ) ;
if ( ! F_52 ( V_10 ) ) {
F_143 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_139 ;
F_144 ( & V_10 -> V_36 ) ;
F_151 ( V_418 , V_10 ) ;
F_148 ( V_10 ) ;
}
}
static void F_272 ( struct V_4 * V_5 )
{
struct V_157 V_155 ;
struct V_6 * V_7 ;
struct V_103 * V_103 = F_34 ( V_5 -> V_7 ) ;
int V_161 , V_323 ;
T_1 V_419 = 0 ;
F_29 () ;
memset ( & V_155 , 0 , sizeof( struct V_157 ) ) ;
memcpy ( & V_155 . V_297 [ 3 ] , V_5 -> V_7 -> V_303 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_340 ) {
V_155 . V_297 [ 0 ] = F_198 ( 0xfe800000 ) ;
V_161 = V_273 ;
V_323 = 64 ;
} else {
V_161 = V_227 ;
V_323 = 96 ;
V_419 |= V_341 ;
}
if ( V_155 . V_297 [ 3 ] ) {
F_271 ( V_5 , & V_155 , V_323 , V_161 ) ;
F_231 ( & V_155 , V_323 , V_5 -> V_7 , 0 , V_419 ) ;
return;
}
F_90 (net, dev) {
struct V_420 * V_421 = F_273 ( V_7 ) ;
if ( V_421 && ( V_7 -> V_50 & V_77 ) ) {
struct V_422 * V_136 ;
int V_423 = V_161 ;
for ( V_136 = V_421 -> V_424 ; V_136 ; V_136 = V_136 -> V_425 ) {
V_155 . V_297 [ 3 ] = V_136 -> V_426 ;
if ( V_136 -> V_427 == V_428 )
continue;
if ( V_136 -> V_427 >= V_429 ) {
if ( V_5 -> V_7 -> V_50 & V_340 )
continue;
V_423 |= V_277 ;
}
F_271 ( V_5 , & V_155 , V_323 , V_423 ) ;
F_231 ( & V_155 , V_323 , V_5 -> V_7 , 0 ,
V_419 ) ;
}
}
}
}
static void F_274 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_430 ;
struct V_9 * V_431 ;
struct V_164 * V_432 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_101 ( L_22 , V_47 ) ;
return;
}
F_271 ( V_5 , & V_433 , 128 , V_277 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_430 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_430 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_431 -> V_50 & ( V_281 | V_139 ) )
continue;
if ( V_431 -> V_151 ) {
if ( V_431 -> V_151 -> V_233 . V_434 > 0 ) {
F_105 ( V_431 -> V_151 ) ;
V_431 -> V_151 = NULL ;
} else {
continue;
}
}
V_432 = F_120 ( V_5 , & V_431 -> V_155 , false ) ;
if ( ! F_52 ( V_432 ) ) {
V_431 -> V_151 = V_432 ;
F_275 ( V_432 ) ;
}
}
F_178 ( & V_5 -> V_36 ) ;
}
}
static void F_276 ( struct V_4 * V_5 ,
const struct V_157 * V_155 , T_1 V_50 )
{
struct V_9 * V_10 ;
T_1 V_211 = V_50 | V_190 ;
#ifdef F_161
if ( V_5 -> V_39 . V_228 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_117 -> V_45 )
V_211 |= V_225 ;
#endif
V_10 = F_115 ( V_5 , V_155 , NULL , 64 , V_273 , V_211 ,
V_417 , V_417 ) ;
if ( ! F_52 ( V_10 ) ) {
F_231 ( & V_10 -> V_155 , V_10 -> V_179 , V_5 -> V_7 , 0 , 0 ) ;
F_158 ( V_10 ) ;
F_148 ( V_10 ) ;
}
}
static bool F_277 ( struct V_157 V_435 )
{
if ( ( V_435 . V_297 [ 2 ] | V_435 . V_297 [ 3 ] ) == 0 )
return true ;
if ( V_435 . V_297 [ 2 ] == F_198 ( 0x02005eff ) &&
( ( V_435 . V_297 [ 3 ] & F_198 ( 0xfe000000 ) ) == F_198 ( 0xfe000000 ) ) )
return true ;
if ( V_435 . V_297 [ 2 ] == F_198 ( 0xfdffffff ) &&
( ( V_435 . V_297 [ 3 ] & F_198 ( 0xffffff80 ) ) == F_198 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_197 ( struct V_157 * V_435 ,
T_3 V_436 ,
const struct V_4 * V_5 )
{
static F_278 ( V_36 ) ;
static V_218 V_437 [ V_438 ] ;
static V_218 V_439 [ V_440 ] ;
static union {
char V_441 [ V_442 ] ;
struct {
struct V_157 V_443 ;
T_4 V_359 [ 2 ] ;
unsigned char V_444 [ V_445 ] ;
T_3 V_436 ;
} V_446 ;
} V_321 ;
struct V_157 V_443 ;
struct V_157 V_447 ;
struct V_103 * V_103 = F_34 ( V_5 -> V_7 ) ;
F_279 ( sizeof( V_321 . V_441 ) != sizeof( V_321 ) ) ;
if ( V_5 -> V_39 . V_448 . V_449 )
V_443 = V_5 -> V_39 . V_448 . V_443 ;
else if ( V_103 -> V_18 . V_40 -> V_448 . V_449 )
V_443 = V_103 -> V_18 . V_40 -> V_448 . V_443 ;
else
return - 1 ;
V_214:
F_143 ( & V_36 ) ;
F_280 ( V_437 ) ;
memset ( & V_321 , 0 , sizeof( V_321 ) ) ;
memset ( V_439 , 0 , sizeof( V_439 ) ) ;
memcpy ( V_321 . V_444 , V_5 -> V_7 -> V_311 , V_5 -> V_7 -> V_301 ) ;
V_321 . V_359 [ 0 ] = V_435 -> V_297 [ 0 ] ;
V_321 . V_359 [ 1 ] = V_435 -> V_297 [ 1 ] ;
V_321 . V_443 = V_443 ;
V_321 . V_436 = V_436 ;
F_281 ( V_437 , V_321 . V_441 , V_439 ) ;
V_447 = * V_435 ;
V_447 . V_297 [ 2 ] = ( V_399 T_4 ) V_437 [ 0 ] ;
V_447 . V_297 [ 3 ] = ( V_399 T_4 ) V_437 [ 1 ] ;
F_144 ( & V_36 ) ;
if ( F_277 ( V_447 ) ) {
V_436 ++ ;
if ( V_436 > F_34 ( V_5 -> V_7 ) -> V_18 . V_42 . V_291 )
return - 1 ;
goto V_214;
}
* V_435 = V_447 ;
return 0 ;
}
static void F_282 ( struct V_4 * V_5 , bool V_450 )
{
struct V_157 V_155 ;
F_237 ( & V_155 , F_198 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( V_5 -> V_369 == V_370 ) {
if ( ! F_197 ( & V_155 , 0 , V_5 ) )
F_276 ( V_5 , & V_155 ,
V_285 ) ;
else if ( V_450 )
F_231 ( & V_155 , 64 , V_5 -> V_7 , 0 , 0 ) ;
} else if ( V_5 -> V_369 == V_451 ) {
if ( F_199 ( V_155 . V_213 + 8 , V_5 -> V_7 ) == 0 )
F_276 ( V_5 , & V_155 , 0 ) ;
else if ( V_450 )
F_231 ( & V_155 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_283 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_312 ) &&
( V_7 -> type != V_313 ) &&
( V_7 -> type != V_314 ) &&
( V_7 -> type != V_315 ) &&
( V_7 -> type != V_318 ) &&
( V_7 -> type != V_319 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_317 ) ) {
return;
}
V_5 = F_238 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return;
F_282 ( V_5 , false ) ;
}
static void F_284 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_101 ( L_22 , V_47 ) ;
return;
}
if ( V_7 -> V_56 & V_57 ) {
F_282 ( V_5 , false ) ;
return;
}
F_272 ( V_5 ) ;
if ( V_7 -> V_50 & V_340 )
F_236 ( V_7 ) ;
}
static void F_285 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_101 ( L_22 , V_47 ) ;
return;
}
F_282 ( V_5 , true ) ;
if ( V_7 -> V_50 & V_340 )
F_236 ( V_7 ) ;
}
static int F_286 ( struct V_452 * V_453 , unsigned long V_91 ,
void * V_454 )
{
struct V_6 * V_7 = F_287 ( V_454 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_455 = 0 ;
int V_32 ;
switch ( V_91 ) {
case V_456 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_288 ( F_121 ( V_5 ) ) ;
}
break;
case V_184 :
case V_457 :
if ( V_7 -> V_50 & V_458 )
break;
if ( V_5 && V_5 -> V_39 . V_173 )
break;
if ( V_91 == V_184 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_23 ,
V_7 -> V_48 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_248 ( V_5 ) ) {
V_5 -> V_68 |= V_69 ;
V_455 = 1 ;
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
F_43 ( L_24 ,
V_7 -> V_48 ) ;
V_455 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_284 ( V_7 ) ;
break;
#endif
#if F_42 ( V_459 )
case V_316 :
F_285 ( V_7 ) ;
break;
#endif
case V_460 :
F_274 ( V_7 ) ;
break;
default:
F_283 ( V_7 ) ;
break;
}
if ( ! F_248 ( V_5 ) ) {
if ( V_455 )
F_289 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_290 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_291 ( V_461 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_292 ( V_7 , 1 ) ;
}
break;
case V_462 :
if ( V_5 && V_7 -> V_33 >= V_34 ) {
F_290 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! F_52 ( V_5 ) )
break;
}
case V_201 :
case V_463 :
F_292 ( V_7 , V_91 != V_201 ) ;
break;
case V_464 :
if ( V_5 ) {
F_293 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_288 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_288 ( V_32 ) ;
}
}
break;
case V_465 :
case V_466 :
F_294 ( V_7 , V_91 ) ;
break;
}
return V_467 ;
}
static void F_294 ( struct V_6 * V_7 , unsigned long V_91 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_91 == V_466 )
F_295 ( V_5 ) ;
else if ( V_91 == V_465 )
F_296 ( V_5 ) ;
}
static int F_292 ( struct V_6 * V_7 , int V_468 )
{
struct V_103 * V_103 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_136 ;
int V_149 , V_16 ;
F_29 () ;
F_297 ( V_103 , V_7 ) ;
F_298 ( & V_44 , V_7 ) ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_171 ;
if ( V_468 ) {
V_5 -> V_76 = 1 ;
F_299 ( V_7 -> V_71 , NULL ) ;
F_293 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_469 ; V_16 ++ ) {
struct V_126 * V_122 = & V_181 [ V_16 ] ;
F_143 ( & V_175 ) ;
V_470:
F_80 (ifa, h, addr_lst) {
if ( V_136 -> V_5 == V_5 ) {
F_145 ( & V_136 -> V_148 ) ;
F_9 ( V_136 ) ;
goto V_470;
}
}
F_144 ( & V_175 ) ;
}
F_146 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_468 )
V_5 -> V_68 &= ~ ( V_471 | V_472 | V_69 ) ;
if ( V_468 && F_7 ( & V_5 -> V_60 ) )
F_102 ( V_5 ) ;
while ( ! F_240 ( & V_5 -> V_59 ) ) {
V_136 = F_300 ( & V_5 -> V_59 ,
struct V_9 , V_183 ) ;
F_147 ( & V_136 -> V_183 ) ;
F_150 ( & V_5 -> V_36 ) ;
F_143 ( & V_136 -> V_36 ) ;
if ( V_136 -> V_199 ) {
F_148 ( V_136 -> V_199 ) ;
V_136 -> V_199 = NULL ;
}
F_144 ( & V_136 -> V_36 ) ;
F_148 ( V_136 ) ;
F_146 ( & V_5 -> V_36 ) ;
}
while ( ! F_240 ( & V_5 -> V_37 ) ) {
V_136 = F_300 ( & V_5 -> V_37 ,
struct V_9 , V_156 ) ;
F_9 ( V_136 ) ;
F_147 ( & V_136 -> V_156 ) ;
F_150 ( & V_5 -> V_36 ) ;
F_143 ( & V_136 -> V_36 ) ;
V_149 = V_136 -> V_149 ;
V_136 -> V_149 = V_150 ;
F_144 ( & V_136 -> V_36 ) ;
if ( V_149 != V_150 ) {
F_301 ( V_200 , V_136 ) ;
F_133 ( V_201 , V_136 ) ;
}
F_148 ( V_136 ) ;
F_146 ( & V_5 -> V_36 ) ;
}
F_150 ( & V_5 -> V_36 ) ;
if ( V_468 ) {
F_302 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_303 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_468 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_298 ( & V_44 , V_7 ) ;
F_102 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_321 )
{
struct V_4 * V_5 = (struct V_4 * ) V_321 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_157 V_473 ;
F_128 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_177;
if ( ! F_304 ( V_5 ) )
goto V_177;
if ( V_5 -> V_68 & V_472 )
goto V_177;
if ( V_5 -> V_474 ++ < V_5 -> V_39 . V_58 ) {
F_130 ( & V_5 -> V_36 ) ;
if ( ! F_183 ( V_7 , & V_473 , V_139 ) )
F_305 ( V_7 , & V_473 ,
& V_75 ) ;
else
goto V_475;
F_128 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_474 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_476 :
V_5 -> V_39 . V_477 ) ;
} else {
F_101 ( L_25 , V_5 -> V_7 -> V_48 ) ;
}
V_177:
F_130 ( & V_5 -> V_36 ) ;
V_475:
F_102 ( V_5 ) ;
}
static void F_306 ( struct V_9 * V_10 )
{
unsigned long V_478 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_225 )
V_478 = 0 ;
else
V_478 = F_307 () % ( V_5 -> V_39 . V_476 ? : 1 ) ;
V_10 -> V_479 = V_5 -> V_39 . V_222 ;
F_16 ( V_10 , V_478 ) ;
}
static void F_308 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_200 ( V_7 , & V_10 -> V_155 ) ;
F_309 ( ( V_399 T_1 ) V_10 -> V_155 . V_297 [ 3 ] ) ;
F_172 ( & V_5 -> V_36 ) ;
F_118 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_149 == V_150 )
goto V_177;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_139 ) ||
V_10 -> V_50 & V_480 ) {
V_10 -> V_50 &= ~ ( V_139 | V_225 | V_281 ) ;
F_127 ( & V_10 -> V_36 ) ;
F_178 ( & V_5 -> V_36 ) ;
F_310 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_127 ( & V_10 -> V_36 ) ;
F_178 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_193 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_50 & V_225 ) {
F_275 ( V_10 -> V_151 ) ;
if ( F_160 ( V_5 ) ) {
F_151 ( V_418 , V_10 ) ;
}
}
F_306 ( V_10 ) ;
V_177:
F_127 ( & V_10 -> V_36 ) ;
F_178 ( & V_5 -> V_36 ) ;
}
static void F_158 ( struct V_9 * V_10 )
{
bool V_481 = false ;
F_143 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_149 != V_150 ) {
V_10 -> V_149 = V_295 ;
V_481 = true ;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_481 )
F_16 ( V_10 , 0 ) ;
}
static void V_178 ( struct V_482 * V_483 )
{
struct V_9 * V_10 = F_311 ( F_312 ( V_483 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_157 V_484 ;
enum {
V_485 ,
V_486 ,
V_487 ,
} V_188 = V_485 ;
F_253 () ;
F_143 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_149 == V_295 ) {
V_188 = V_486 ;
V_10 -> V_149 = V_283 ;
} else if ( V_10 -> V_149 == V_298 ) {
V_188 = V_487 ;
V_10 -> V_149 = V_284 ;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_188 == V_486 ) {
F_308 ( V_10 ) ;
goto V_177;
} else if ( V_188 == V_487 ) {
F_193 ( V_10 , 1 ) ;
goto V_177;
}
if ( ! V_10 -> V_479 && F_194 ( V_10 ) )
goto V_177;
F_146 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) ) {
F_150 ( & V_5 -> V_36 ) ;
goto V_177;
}
F_118 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_149 == V_150 ) {
F_127 ( & V_10 -> V_36 ) ;
F_150 ( & V_5 -> V_36 ) ;
goto V_177;
}
if ( V_10 -> V_479 == 0 ) {
V_10 -> V_50 &= ~ ( V_139 | V_225 | V_281 ) ;
F_127 ( & V_10 -> V_36 ) ;
F_150 ( & V_5 -> V_36 ) ;
F_310 ( V_10 ) ;
goto V_177;
}
V_10 -> V_479 -- ;
F_16 ( V_10 ,
F_156 ( V_10 -> V_5 -> V_43 , V_223 ) ) ;
F_127 ( & V_10 -> V_36 ) ;
F_150 ( & V_5 -> V_36 ) ;
F_201 ( & V_10 -> V_155 , & V_484 ) ;
F_313 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_155 , & V_484 , & V_67 , NULL ) ;
V_177:
F_148 ( V_10 ) ;
F_94 () ;
}
static bool F_314 ( struct V_9 * V_10 )
{
struct V_9 * V_488 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_182 (ifpiter, &idev->addr_list, if_list) {
if ( V_488 -> V_161 > V_273 )
break;
if ( V_10 != V_488 && V_488 -> V_161 == V_273 &&
( V_488 -> V_50 & ( V_190 | V_139 |
V_225 | V_281 ) ) ==
V_190 )
return false ;
}
return true ;
}
static void F_310 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_157 V_473 ;
bool V_489 , V_490 ;
F_9 ( V_10 ) ;
F_151 ( V_418 , V_10 ) ;
F_172 ( & V_10 -> V_5 -> V_36 ) ;
V_490 = V_10 -> V_161 == V_273 && F_314 ( V_10 ) ;
V_489 = V_490 &&
F_304 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_178 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_490 )
F_315 ( V_10 -> V_5 ) ;
if ( V_489 ) {
if ( F_183 ( V_7 , & V_473 , V_139 ) )
return;
F_305 ( V_7 , & V_473 , & V_75 ) ;
F_146 ( & V_10 -> V_5 -> V_36 ) ;
F_118 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_474 = 1 ;
V_10 -> V_5 -> V_68 |= V_471 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_477 ) ;
F_127 ( & V_10 -> V_36 ) ;
F_150 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_289 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
F_118 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_139 &&
V_10 -> V_149 == V_283 )
F_306 ( V_10 ) ;
F_127 ( & V_10 -> V_36 ) ;
}
F_178 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_316 ( struct V_491 * V_90 , T_8 V_492 )
{
struct V_9 * V_136 = NULL ;
struct V_493 * V_149 = V_90 -> V_494 ;
struct V_103 * V_103 = F_317 ( V_90 ) ;
int V_144 = 0 ;
if ( V_492 == 0 ) {
V_149 -> V_495 = 0 ;
V_149 -> V_496 = 0 ;
}
for (; V_149 -> V_495 < V_469 ; ++ V_149 -> V_495 ) {
F_192 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_187 ( F_34 ( V_136 -> V_5 -> V_7 ) , V_103 ) )
continue;
if ( V_144 < V_149 -> V_496 ) {
V_144 ++ ;
continue;
}
V_149 -> V_496 ++ ;
return V_136 ;
}
V_149 -> V_496 = 0 ;
V_144 = 0 ;
}
return NULL ;
}
static struct V_9 * F_318 ( struct V_491 * V_90 ,
struct V_9 * V_136 )
{
struct V_493 * V_149 = V_90 -> V_494 ;
struct V_103 * V_103 = F_317 ( V_90 ) ;
F_319 (ifa, addr_lst) {
if ( ! F_187 ( F_34 ( V_136 -> V_5 -> V_7 ) , V_103 ) )
continue;
V_149 -> V_496 ++ ;
return V_136 ;
}
while ( ++ V_149 -> V_495 < V_469 ) {
V_149 -> V_496 = 0 ;
F_192 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_187 ( F_34 ( V_136 -> V_5 -> V_7 ) , V_103 ) )
continue;
V_149 -> V_496 ++ ;
return V_136 ;
}
}
return NULL ;
}
static void * F_320 ( struct V_491 * V_90 , T_8 * V_492 )
__acquires( T_9 )
{
F_117 () ;
return F_316 ( V_90 , * V_492 ) ;
}
static void * F_321 ( struct V_491 * V_90 , void * V_497 , T_8 * V_492 )
{
struct V_9 * V_136 ;
V_136 = F_318 ( V_90 , V_497 ) ;
++ * V_492 ;
return V_136 ;
}
static void F_322 ( struct V_491 * V_90 , void * V_497 )
__releases( T_9 )
{
F_131 () ;
}
static int F_323 ( struct V_491 * V_90 , void * V_497 )
{
struct V_9 * V_10 = (struct V_9 * ) V_497 ;
F_324 ( V_90 , L_26 ,
& V_10 -> V_155 ,
V_10 -> V_5 -> V_7 -> V_86 ,
V_10 -> V_179 ,
V_10 -> V_161 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_325 ( struct V_498 * V_498 , struct V_499 * V_499 )
{
return F_326 ( V_498 , V_499 , & V_500 ,
sizeof( struct V_493 ) ) ;
}
static int T_10 F_327 ( struct V_103 * V_103 )
{
if ( ! F_328 ( L_27 , V_501 , V_103 -> V_502 , & V_503 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_329 ( struct V_103 * V_103 )
{
F_330 ( L_27 , V_103 -> V_502 ) ;
}
int T_12 F_331 ( void )
{
return F_332 ( & V_504 ) ;
}
void F_333 ( void )
{
F_334 ( & V_504 ) ;
}
int F_335 ( struct V_103 * V_103 , const struct V_157 * V_155 )
{
int V_210 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_165 = F_112 ( V_155 ) ;
F_117 () ;
F_192 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_187 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_103 ) )
continue;
if ( F_164 ( & V_10 -> V_155 , V_155 ) &&
( V_10 -> V_50 & V_249 ) ) {
V_210 = 1 ;
break;
}
}
F_131 () ;
return V_210 ;
}
static void F_265 ( void )
{
unsigned long V_212 , V_505 , V_506 , V_507 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_117 () ;
V_212 = V_13 ;
V_505 = F_336 ( V_212 + V_508 ) ;
F_10 ( & V_509 ) ;
for ( V_16 = 0 ; V_16 < V_469 ; V_16 ++ ) {
V_470:
F_192 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_207 ;
if ( ( V_10 -> V_50 & V_190 ) &&
( V_10 -> V_163 == V_417 ) )
continue;
F_118 ( & V_10 -> V_36 ) ;
V_207 = ( V_212 - V_10 -> V_70 + V_224 ) / V_3 ;
if ( V_10 -> V_162 != V_417 &&
V_207 >= V_10 -> V_162 ) {
F_127 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_142 ( V_10 ) ;
goto V_470;
} else if ( V_10 -> V_163 == V_417 ) {
F_127 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_207 >= V_10 -> V_163 ) {
int V_510 = 0 ;
if ( ! ( V_10 -> V_50 & V_244 ) ) {
V_510 = 1 ;
V_10 -> V_50 |= V_244 ;
}
if ( ( V_10 -> V_162 != V_417 ) &&
( F_137 ( V_10 -> V_70 + V_10 -> V_162 * V_3 , V_505 ) ) )
V_505 = V_10 -> V_70 + V_10 -> V_162 * V_3 ;
F_127 ( & V_10 -> V_36 ) ;
if ( V_510 ) {
F_18 ( V_10 ) ;
F_151 ( 0 , V_10 ) ;
F_148 ( V_10 ) ;
goto V_470;
}
} else if ( ( V_10 -> V_50 & V_182 ) &&
! ( V_10 -> V_50 & V_139 ) ) {
unsigned long V_208 = V_10 -> V_5 -> V_39 . V_216 *
V_10 -> V_5 -> V_39 . V_222 *
F_156 ( V_10 -> V_5 -> V_43 , V_223 ) / V_3 ;
if ( V_207 >= V_10 -> V_163 - V_208 ) {
struct V_9 * V_199 = V_10 -> V_199 ;
if ( F_137 ( V_10 -> V_70 + V_10 -> V_163 * V_3 , V_505 ) )
V_505 = V_10 -> V_70 + V_10 -> V_163 * V_3 ;
if ( ! V_10 -> V_215 && V_199 ) {
V_10 -> V_215 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_199 ) ;
F_127 ( & V_10 -> V_36 ) ;
F_118 ( & V_199 -> V_36 ) ;
V_199 -> V_215 = 0 ;
F_127 ( & V_199 -> V_36 ) ;
F_153 ( V_199 , V_10 ) ;
F_148 ( V_199 ) ;
F_148 ( V_10 ) ;
goto V_470;
}
} else if ( F_137 ( V_10 -> V_70 + V_10 -> V_163 * V_3 - V_208 * V_3 , V_505 ) )
V_505 = V_10 -> V_70 + V_10 -> V_163 * V_3 - V_208 * V_3 ;
F_127 ( & V_10 -> V_36 ) ;
} else {
if ( F_137 ( V_10 -> V_70 + V_10 -> V_163 * V_3 , V_505 ) )
V_505 = V_10 -> V_70 + V_10 -> V_163 * V_3 ;
F_127 ( & V_10 -> V_36 ) ;
}
}
}
V_506 = F_336 ( V_505 ) ;
V_507 = V_505 ;
if ( F_137 ( V_506 , V_505 + V_511 ) )
V_507 = V_506 ;
if ( F_137 ( V_507 , V_13 + V_512 ) )
V_507 = V_13 + V_512 ;
F_38 ( V_513 L_28 ,
V_212 , V_505 , V_506 , V_507 ) ;
F_19 ( V_15 , & V_509 , V_507 - V_212 ) ;
F_131 () ;
}
static void F_337 ( struct V_482 * V_483 )
{
F_253 () ;
F_265 () ;
F_94 () ;
}
static void F_250 ( void )
{
F_19 ( V_15 , & V_509 , 0 ) ;
}
static struct V_157 * F_338 ( struct V_111 * V_155 , struct V_111 * V_514 ,
struct V_157 * * V_407 )
{
struct V_157 * V_322 = NULL ;
* V_407 = NULL ;
if ( V_155 )
V_322 = F_339 ( V_155 ) ;
if ( V_514 ) {
if ( V_322 && F_340 ( V_514 , V_322 , sizeof( * V_322 ) ) )
* V_407 = V_322 ;
V_322 = F_339 ( V_514 ) ;
}
return V_322 ;
}
static int
F_341 ( struct V_84 * V_85 , struct V_92 * V_93 )
{
struct V_103 * V_103 = F_71 ( V_85 -> V_110 ) ;
struct V_515 * V_516 ;
struct V_111 * V_112 [ V_517 + 1 ] ;
struct V_157 * V_322 , * V_407 ;
T_1 V_408 ;
int V_32 ;
V_32 = F_72 ( V_93 , sizeof( * V_516 ) , V_112 , V_517 , V_518 ) ;
if ( V_32 < 0 )
return V_32 ;
V_516 = F_60 ( V_93 ) ;
V_322 = F_338 ( V_112 [ V_519 ] , V_112 [ V_520 ] , & V_407 ) ;
if ( ! V_322 )
return - V_35 ;
V_408 = V_112 [ V_521 ] ? F_342 ( V_112 [ V_521 ] ) : V_516 -> V_408 ;
V_408 &= V_373 ;
return F_266 ( V_103 , V_516 -> V_522 , V_408 , V_322 ,
V_516 -> V_523 ) ;
}
static int F_343 ( struct V_9 * V_10 , T_1 V_408 ,
T_1 V_163 , T_1 V_162 )
{
T_1 V_50 ;
T_5 V_186 ;
unsigned long V_409 ;
bool V_524 ;
bool V_525 ;
F_29 () ;
if ( ! V_162 || ( V_163 > V_162 ) )
return - V_35 ;
if ( V_408 & V_373 &&
( V_10 -> V_50 & V_182 || V_10 -> V_179 != 64 ) )
return - V_35 ;
V_409 = F_136 ( V_162 , V_3 ) ;
if ( F_245 ( V_409 ) ) {
V_186 = F_247 ( V_409 * V_3 ) ;
V_162 = V_409 ;
V_50 = V_198 ;
} else {
V_186 = 0 ;
V_50 = 0 ;
V_408 |= V_190 ;
}
V_409 = F_136 ( V_163 , V_3 ) ;
if ( F_245 ( V_409 ) ) {
if ( V_409 == 0 )
V_408 |= V_244 ;
V_163 = V_409 ;
}
F_143 ( & V_10 -> V_36 ) ;
V_524 = V_10 -> V_50 & V_373 ;
V_525 = V_10 -> V_50 & V_190 &&
! ( V_10 -> V_50 & V_191 ) ;
V_10 -> V_50 &= ~ ( V_244 | V_190 | V_480 |
V_249 | V_373 |
V_191 ) ;
V_10 -> V_50 |= V_408 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_162 = V_162 ;
V_10 -> V_163 = V_163 ;
F_144 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_139 ) )
F_151 ( 0 , V_10 ) ;
if ( ! ( V_408 & V_191 ) ) {
F_231 ( & V_10 -> V_155 , V_10 -> V_179 , V_10 -> V_5 -> V_7 ,
V_186 , V_50 ) ;
} else if ( V_525 ) {
enum V_185 V_188 ;
unsigned long V_363 ;
F_146 ( & V_10 -> V_5 -> V_36 ) ;
V_188 = F_134 ( V_10 , & V_363 ) ;
F_150 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_188 != V_192 ) {
F_138 ( V_10 , V_363 ,
V_188 == V_189 ) ;
}
}
if ( V_524 || V_10 -> V_50 & V_373 ) {
if ( V_524 && ! ( V_10 -> V_50 & V_373 ) )
V_162 = V_163 = 0 ;
F_239 ( V_10 -> V_5 , V_10 , V_162 , V_163 ,
! V_524 , V_13 ) ;
}
F_265 () ;
return 0 ;
}
static int
F_344 ( struct V_84 * V_85 , struct V_92 * V_93 )
{
struct V_103 * V_103 = F_71 ( V_85 -> V_110 ) ;
struct V_515 * V_516 ;
struct V_111 * V_112 [ V_517 + 1 ] ;
struct V_157 * V_322 , * V_407 ;
struct V_9 * V_136 ;
struct V_6 * V_7 ;
T_1 V_162 = V_417 , V_288 = V_417 ;
T_1 V_408 ;
int V_32 ;
V_32 = F_72 ( V_93 , sizeof( * V_516 ) , V_112 , V_517 , V_518 ) ;
if ( V_32 < 0 )
return V_32 ;
V_516 = F_60 ( V_93 ) ;
V_322 = F_338 ( V_112 [ V_519 ] , V_112 [ V_520 ] , & V_407 ) ;
if ( ! V_322 )
return - V_35 ;
if ( V_112 [ V_526 ] ) {
struct V_527 * V_528 ;
V_528 = F_339 ( V_112 [ V_526 ] ) ;
V_162 = V_528 -> V_529 ;
V_288 = V_528 -> V_530 ;
} else {
V_288 = V_417 ;
V_162 = V_417 ;
}
V_7 = F_74 ( V_103 , V_516 -> V_522 ) ;
if ( ! V_7 )
return - V_171 ;
V_408 = V_112 [ V_521 ] ? F_342 ( V_112 [ V_521 ] ) : V_516 -> V_408 ;
V_408 &= V_480 | V_249 | V_373 |
V_191 | V_410 ;
V_136 = F_191 ( V_103 , V_322 , V_7 , 1 ) ;
if ( ! V_136 ) {
return F_264 ( V_103 , V_516 -> V_522 , V_322 , V_407 ,
V_516 -> V_523 , V_408 ,
V_288 , V_162 ) ;
}
if ( V_93 -> V_531 & V_532 ||
! ( V_93 -> V_531 & V_533 ) )
V_32 = - V_176 ;
else
V_32 = F_343 ( V_136 , V_408 , V_288 , V_162 ) ;
F_148 ( V_136 ) ;
return V_32 ;
}
static void F_345 ( struct V_92 * V_93 , T_3 V_534 , T_1 V_50 ,
T_3 V_161 , int V_86 )
{
struct V_515 * V_516 ;
V_516 = F_60 ( V_93 ) ;
V_516 -> V_535 = V_97 ;
V_516 -> V_523 = V_534 ;
V_516 -> V_408 = V_50 ;
V_516 -> V_427 = V_161 ;
V_516 -> V_522 = V_86 ;
}
static int F_346 ( struct V_84 * V_85 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_536 , T_1 V_361 )
{
struct V_527 V_528 ;
V_528 . V_1 = F_1 ( V_1 ) ;
V_528 . V_70 = F_1 ( V_70 ) ;
V_528 . V_530 = V_536 ;
V_528 . V_529 = V_361 ;
return F_347 ( V_85 , V_526 , sizeof( V_528 ) , & V_528 ) ;
}
static inline int F_348 ( int V_427 )
{
if ( V_427 & V_277 )
return V_429 ;
else if ( V_427 & V_273 )
return V_428 ;
else if ( V_427 & V_537 )
return V_538 ;
else
return V_539 ;
}
static inline int F_349 ( void )
{
return F_55 ( sizeof( struct V_515 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_527 ) )
+ F_56 ( 4 ) ;
}
static int F_350 ( struct V_84 * V_85 , struct V_9 * V_136 ,
T_1 V_89 , T_1 V_90 , int V_91 , unsigned int V_50 )
{
struct V_92 * V_93 ;
T_1 V_536 , V_361 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( struct V_515 ) , V_50 ) ;
if ( ! V_93 )
return - V_95 ;
F_345 ( V_93 , V_136 -> V_179 , V_136 -> V_50 , F_348 ( V_136 -> V_161 ) ,
V_136 -> V_5 -> V_7 -> V_86 ) ;
if ( ! ( ( V_136 -> V_50 & V_190 ) &&
( V_136 -> V_163 == V_417 ) ) ) {
V_536 = V_136 -> V_163 ;
V_361 = V_136 -> V_162 ;
if ( V_536 != V_417 ) {
long V_540 = ( V_13 - V_136 -> V_70 ) / V_3 ;
if ( V_536 > V_540 )
V_536 -= V_540 ;
else
V_536 = 0 ;
if ( V_361 != V_417 ) {
if ( V_361 > V_540 )
V_361 -= V_540 ;
else
V_361 = 0 ;
}
}
} else {
V_536 = V_417 ;
V_361 = V_417 ;
}
if ( ! F_205 ( & V_136 -> V_159 ) ) {
if ( F_351 ( V_85 , V_520 , & V_136 -> V_155 ) < 0 ||
F_351 ( V_85 , V_519 , & V_136 -> V_159 ) < 0 )
goto error;
} else
if ( F_351 ( V_85 , V_519 , & V_136 -> V_155 ) < 0 )
goto error;
if ( F_346 ( V_85 , V_136 -> V_1 , V_136 -> V_70 , V_536 , V_361 ) < 0 )
goto error;
if ( F_352 ( V_85 , V_521 , V_136 -> V_50 ) < 0 )
goto error;
F_62 ( V_85 , V_93 ) ;
return 0 ;
error:
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
static int F_353 ( struct V_84 * V_85 , struct V_541 * V_542 ,
T_1 V_89 , T_1 V_90 , int V_91 , T_13 V_50 )
{
struct V_92 * V_93 ;
T_3 V_161 = V_539 ;
int V_86 = V_542 -> V_5 -> V_7 -> V_86 ;
if ( F_157 ( & V_542 -> V_543 ) & V_537 )
V_161 = V_538 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( struct V_515 ) , V_50 ) ;
if ( ! V_93 )
return - V_95 ;
F_345 ( V_93 , 128 , V_190 , V_161 , V_86 ) ;
if ( F_351 ( V_85 , V_544 , & V_542 -> V_543 ) < 0 ||
F_346 ( V_85 , V_542 -> V_545 , V_542 -> V_546 ,
V_417 , V_417 ) < 0 ) {
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
F_62 ( V_85 , V_93 ) ;
return 0 ;
}
static int F_354 ( struct V_84 * V_85 , struct V_547 * V_548 ,
T_1 V_89 , T_1 V_90 , int V_91 , unsigned int V_50 )
{
struct V_92 * V_93 ;
T_3 V_161 = V_539 ;
int V_86 = V_548 -> V_549 -> V_7 -> V_86 ;
if ( F_157 ( & V_548 -> V_550 ) & V_537 )
V_161 = V_538 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( struct V_515 ) , V_50 ) ;
if ( ! V_93 )
return - V_95 ;
F_345 ( V_93 , 128 , V_190 , V_161 , V_86 ) ;
if ( F_351 ( V_85 , V_551 , & V_548 -> V_550 ) < 0 ||
F_346 ( V_85 , V_548 -> V_552 , V_548 -> V_553 ,
V_417 , V_417 ) < 0 ) {
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
F_62 ( V_85 , V_93 ) ;
return 0 ;
}
static int F_355 ( struct V_4 * V_5 , struct V_84 * V_85 ,
struct V_120 * V_121 , enum V_554 type ,
int V_555 , int * V_556 )
{
struct V_541 * V_542 ;
struct V_547 * V_548 ;
int V_32 = 1 ;
int V_557 = * V_556 ;
F_172 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_558 : {
struct V_9 * V_136 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_557 < V_555 )
continue;
V_32 = F_350 ( V_85 , V_136 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_418 ,
V_133 ) ;
if ( V_32 < 0 )
break;
F_82 ( V_121 , F_83 ( V_85 ) ) ;
}
break;
}
case V_559 :
for ( V_542 = V_5 -> V_560 ; V_542 ;
V_542 = V_542 -> V_505 , V_557 ++ ) {
if ( V_557 < V_555 )
continue;
V_32 = F_353 ( V_85 , V_542 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_561 ,
V_133 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_562 :
for ( V_548 = V_5 -> V_563 ; V_548 ;
V_548 = V_548 -> V_564 , V_557 ++ ) {
if ( V_557 < V_555 )
continue;
V_32 = F_354 ( V_85 , V_548 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_565 ,
V_133 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_178 ( & V_5 -> V_36 ) ;
* V_556 = V_557 ;
return V_32 ;
}
static int F_356 ( struct V_84 * V_85 , struct V_120 * V_121 ,
enum V_554 type )
{
struct V_103 * V_103 = F_71 ( V_85 -> V_110 ) ;
int V_122 , V_123 ;
int V_124 , V_557 ;
int V_125 , V_555 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_126 * V_127 ;
V_123 = V_121 -> args [ 0 ] ;
V_125 = V_124 = V_121 -> args [ 1 ] ;
V_555 = V_557 = V_121 -> args [ 2 ] ;
F_78 () ;
V_121 -> V_90 = F_79 ( & V_103 -> V_18 . V_130 ) ^ V_103 -> V_131 ;
for ( V_122 = V_123 ; V_122 < V_128 ; V_122 ++ , V_125 = 0 ) {
V_124 = 0 ;
V_127 = & V_103 -> V_129 [ V_122 ] ;
F_80 (dev, head, index_hlist) {
if ( V_124 < V_125 )
goto V_132;
if ( V_122 > V_123 || V_124 > V_125 )
V_555 = 0 ;
V_557 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_132;
if ( F_355 ( V_5 , V_85 , V_121 , type ,
V_555 , & V_557 ) < 0 )
goto V_134;
V_132:
V_124 ++ ;
}
}
V_134:
F_81 () ;
V_121 -> args [ 0 ] = V_122 ;
V_121 -> args [ 1 ] = V_124 ;
V_121 -> args [ 2 ] = V_557 ;
return V_85 -> V_135 ;
}
static int F_357 ( struct V_84 * V_85 , struct V_120 * V_121 )
{
enum V_554 type = V_558 ;
return F_356 ( V_85 , V_121 , type ) ;
}
static int F_358 ( struct V_84 * V_85 , struct V_120 * V_121 )
{
enum V_554 type = V_559 ;
return F_356 ( V_85 , V_121 , type ) ;
}
static int F_359 ( struct V_84 * V_85 , struct V_120 * V_121 )
{
enum V_554 type = V_562 ;
return F_356 ( V_85 , V_121 , type ) ;
}
static int F_360 ( struct V_84 * V_109 , struct V_92 * V_93 )
{
struct V_103 * V_103 = F_71 ( V_109 -> V_110 ) ;
struct V_515 * V_516 ;
struct V_111 * V_112 [ V_517 + 1 ] ;
struct V_157 * V_155 = NULL , * V_566 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_136 ;
struct V_84 * V_85 ;
int V_32 ;
V_32 = F_72 ( V_93 , sizeof( * V_516 ) , V_112 , V_517 , V_518 ) ;
if ( V_32 < 0 )
goto V_106;
V_155 = F_338 ( V_112 [ V_519 ] , V_112 [ V_520 ] , & V_566 ) ;
if ( ! V_155 ) {
V_32 = - V_35 ;
goto V_106;
}
V_516 = F_60 ( V_93 ) ;
if ( V_516 -> V_522 )
V_7 = F_74 ( V_103 , V_516 -> V_522 ) ;
V_136 = F_191 ( V_103 , V_155 , V_7 , 1 ) ;
if ( ! V_136 ) {
V_32 = - V_170 ;
goto V_106;
}
V_85 = F_65 ( F_349 () , V_25 ) ;
if ( ! V_85 ) {
V_32 = - V_104 ;
goto V_567;
}
V_32 = F_350 ( V_85 , V_136 , F_75 ( V_109 ) . V_89 ,
V_93 -> V_119 , V_418 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_567;
}
V_32 = F_76 ( V_85 , V_103 , F_75 ( V_109 ) . V_89 ) ;
V_567:
F_148 ( V_136 ) ;
V_106:
return V_32 ;
}
static void F_361 ( int V_91 , struct V_9 * V_136 )
{
struct V_84 * V_85 ;
struct V_103 * V_103 = F_34 ( V_136 -> V_5 -> V_7 ) ;
int V_32 = - V_104 ;
V_85 = F_65 ( F_349 () , V_105 ) ;
if ( ! V_85 )
goto V_106;
V_32 = F_350 ( V_85 , V_136 , 0 , 0 , V_91 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_106;
}
F_68 ( V_85 , V_103 , 0 , V_568 , NULL , V_105 ) ;
return;
V_106:
if ( V_32 < 0 )
F_69 ( V_103 , V_568 , V_32 ) ;
}
static inline void F_362 ( struct V_87 * V_39 ,
T_2 * V_569 , int V_570 )
{
F_363 ( V_570 < ( V_571 * 4 ) ) ;
memset ( V_569 , 0 , V_570 ) ;
V_569 [ V_572 ] = V_39 -> V_45 ;
V_569 [ V_573 ] = V_39 -> V_574 ;
V_569 [ V_575 ] = V_39 -> V_41 ;
V_569 [ V_576 ] = V_39 -> V_577 ;
V_569 [ V_578 ] = V_39 -> V_579 ;
V_569 [ V_580 ] = V_39 -> V_367 ;
V_569 [ V_581 ] = V_39 -> V_222 ;
V_569 [ V_582 ] = V_39 -> V_58 ;
V_569 [ V_583 ] =
F_364 ( V_39 -> V_477 ) ;
V_569 [ V_584 ] =
F_364 ( V_39 -> V_476 ) ;
V_569 [ V_585 ] = V_39 -> V_586 ;
V_569 [ V_587 ] =
F_364 ( V_39 -> V_588 ) ;
V_569 [ V_589 ] =
F_364 ( V_39 -> V_590 ) ;
V_569 [ V_591 ] = V_39 -> V_65 ;
V_569 [ V_592 ] = V_39 -> V_219 ;
V_569 [ V_593 ] = V_39 -> V_220 ;
V_569 [ V_594 ] = V_39 -> V_216 ;
V_569 [ V_595 ] = V_39 -> V_221 ;
V_569 [ V_596 ] = V_39 -> V_293 ;
V_569 [ V_597 ] = V_39 -> V_598 ;
V_569 [ V_599 ] = V_39 -> V_600 ;
V_569 [ V_601 ] = V_39 -> V_602 ;
#ifdef F_365
V_569 [ V_603 ] = V_39 -> V_604 ;
V_569 [ V_605 ] =
F_364 ( V_39 -> V_606 ) ;
#ifdef F_366
V_569 [ V_607 ] = V_39 -> V_608 ;
#endif
#endif
V_569 [ V_609 ] = V_39 -> V_101 ;
V_569 [ V_610 ] = V_39 -> V_611 ;
#ifdef F_161
V_569 [ V_612 ] = V_39 -> V_228 ;
V_569 [ V_613 ] = V_39 -> V_229 ;
#endif
#ifdef F_57
V_569 [ V_614 ] = V_39 -> V_100 ;
#endif
V_569 [ V_615 ] = V_39 -> V_173 ;
V_569 [ V_616 ] = V_39 -> V_53 ;
V_569 [ V_617 ] = V_39 -> V_618 ;
V_569 [ V_619 ] = V_39 -> V_620 ;
V_569 [ V_621 ] = V_39 -> V_622 ;
V_569 [ V_623 ] = V_39 -> V_624 ;
V_569 [ V_625 ] = V_39 -> V_626 ;
V_569 [ V_627 ] = V_39 -> V_102 ;
V_569 [ V_628 ] = V_39 -> V_271 ;
}
static inline T_14 F_367 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_629 ) )
+ F_56 ( V_571 * 4 )
+ F_56 ( V_630 * 8 )
+ F_56 ( V_631 * 8 )
+ F_56 ( sizeof( struct V_157 ) ) ;
}
static inline T_14 F_368 ( void )
{
return F_55 ( sizeof( struct V_632 ) )
+ F_56 ( V_633 )
+ F_56 ( V_445 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( 1 )
+ F_56 ( F_367 () ) ;
}
static inline void F_369 ( T_15 * V_17 , T_16 * V_634 ,
int V_635 , int V_570 )
{
int V_16 ;
int V_636 = V_570 - sizeof( T_15 ) * V_635 ;
F_363 ( V_636 < 0 ) ;
F_370 ( V_635 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_635 ; V_16 ++ )
F_370 ( F_371 ( & V_634 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_635 ] , 0 , V_636 ) ;
}
static inline void F_372 ( T_15 * V_17 , void T_17 * V_634 ,
int V_570 , T_14 V_637 )
{
int V_16 , V_638 ;
T_15 V_639 [ V_630 ] ;
int V_636 = V_570 - sizeof( T_15 ) * V_630 ;
F_363 ( V_636 < 0 ) ;
memset ( V_639 , 0 , sizeof( V_639 ) ) ;
V_639 [ 0 ] = V_630 ;
F_22 (c) {
for ( V_16 = 1 ; V_16 < V_630 ; V_16 ++ )
V_639 [ V_16 ] += F_373 ( V_634 , V_638 , V_16 , V_637 ) ;
}
memcpy ( V_17 , V_639 , V_630 * sizeof( T_15 ) ) ;
memset ( & V_17 [ V_630 ] , 0 , V_636 ) ;
}
static void F_374 ( T_15 * V_17 , struct V_4 * V_5 , int V_640 ,
int V_570 )
{
switch ( V_640 ) {
case V_641 :
F_372 ( V_17 , V_5 -> V_17 . V_18 , V_570 ,
F_375 ( struct V_19 , V_22 ) ) ;
break;
case V_642 :
F_369 ( V_17 , V_5 -> V_17 . V_23 -> V_643 , V_631 , V_570 ) ;
break;
}
}
static int F_376 ( struct V_84 * V_85 , struct V_4 * V_5 )
{
struct V_111 * V_644 ;
struct V_629 V_528 ;
if ( F_352 ( V_85 , V_645 , V_5 -> V_68 ) )
goto V_99;
V_528 . V_646 = V_647 ;
V_528 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_528 . V_648 = F_364 ( V_5 -> V_43 -> V_648 ) ;
V_528 . V_649 = F_364 ( F_156 ( V_5 -> V_43 , V_223 ) ) ;
if ( F_347 ( V_85 , V_650 , sizeof( V_528 ) , & V_528 ) )
goto V_99;
V_644 = F_377 ( V_85 , V_651 , V_571 * sizeof( V_652 ) ) ;
if ( ! V_644 )
goto V_99;
F_362 ( & V_5 -> V_39 , F_339 ( V_644 ) , F_378 ( V_644 ) ) ;
V_644 = F_377 ( V_85 , V_641 , V_630 * sizeof( T_15 ) ) ;
if ( ! V_644 )
goto V_99;
F_374 ( F_339 ( V_644 ) , V_5 , V_641 , F_378 ( V_644 ) ) ;
V_644 = F_377 ( V_85 , V_642 , V_631 * sizeof( T_15 ) ) ;
if ( ! V_644 )
goto V_99;
F_374 ( F_339 ( V_644 ) , V_5 , V_642 , F_378 ( V_644 ) ) ;
V_644 = F_377 ( V_85 , V_653 , sizeof( struct V_157 ) ) ;
if ( ! V_644 )
goto V_99;
if ( F_379 ( V_85 , V_654 , V_5 -> V_369 ) )
goto V_99;
F_172 ( & V_5 -> V_36 ) ;
memcpy ( F_339 ( V_644 ) , V_5 -> V_66 . V_213 , F_378 ( V_644 ) ) ;
F_178 ( & V_5 -> V_36 ) ;
return 0 ;
V_99:
return - V_95 ;
}
static T_14 F_380 ( const struct V_6 * V_7 )
{
if ( ! F_51 ( V_7 ) )
return 0 ;
return F_367 () ;
}
static int F_381 ( struct V_84 * V_85 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_655 ;
if ( F_376 ( V_85 , V_5 ) < 0 )
return - V_95 ;
return 0 ;
}
static int F_382 ( struct V_4 * V_5 , struct V_157 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_656 = false ;
struct V_157 V_657 ;
F_29 () ;
if ( ! V_66 )
return - V_35 ;
if ( F_205 ( V_66 ) )
return - V_35 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return - V_35 ;
if ( ! F_304 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_58 <= 0 )
return - V_35 ;
F_146 ( & V_5 -> V_36 ) ;
F_279 ( sizeof( V_66 -> V_213 ) != 16 ) ;
memcpy ( V_5 -> V_66 . V_213 + 8 , V_66 -> V_213 + 8 , 8 ) ;
F_150 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_76 && ( V_5 -> V_68 & V_69 ) &&
! F_183 ( V_7 , & V_657 , V_139 |
V_225 ) ) {
F_305 ( V_7 , & V_657 , & V_75 ) ;
V_656 = true ;
}
F_146 ( & V_5 -> V_36 ) ;
if ( V_656 ) {
V_5 -> V_68 |= V_471 ;
V_5 -> V_474 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_477 ) ;
}
F_86 (ifp, &idev->addr_list, if_list) {
F_118 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_180 ) {
V_10 -> V_162 = 0 ;
V_10 -> V_163 = 0 ;
}
F_127 ( & V_10 -> V_36 ) ;
}
F_150 ( & V_5 -> V_36 ) ;
F_291 ( V_461 , V_5 ) ;
F_265 () ;
return 0 ;
}
static int F_383 ( const struct V_6 * V_7 ,
const struct V_111 * V_644 )
{
struct V_111 * V_112 [ V_658 + 1 ] ;
if ( V_7 && ! F_51 ( V_7 ) )
return - V_659 ;
return F_384 ( V_112 , V_658 , V_644 , V_660 ) ;
}
static int F_385 ( struct V_6 * V_7 , const struct V_111 * V_644 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_111 * V_112 [ V_658 + 1 ] ;
if ( ! V_5 )
return - V_659 ;
if ( F_384 ( V_112 , V_658 , V_644 , NULL ) < 0 )
F_386 () ;
if ( V_112 [ V_653 ] ) {
V_32 = F_382 ( V_5 , F_339 ( V_112 [ V_653 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_112 [ V_654 ] ) {
T_3 V_661 = F_387 ( V_112 [ V_654 ] ) ;
if ( V_661 != V_451 &&
V_661 != V_662 &&
V_661 != V_370 )
return - V_35 ;
if ( V_661 == V_370 &&
! V_5 -> V_39 . V_448 . V_449 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_448 . V_449 )
return - V_35 ;
V_5 -> V_369 = V_661 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_388 ( struct V_84 * V_85 , struct V_4 * V_5 ,
T_1 V_89 , T_1 V_90 , int V_91 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_632 * V_663 ;
struct V_92 * V_93 ;
void * V_664 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( * V_663 ) , V_50 ) ;
if ( ! V_93 )
return - V_95 ;
V_663 = F_60 ( V_93 ) ;
V_663 -> V_665 = V_97 ;
V_663 -> V_666 = 0 ;
V_663 -> V_667 = V_7 -> type ;
V_663 -> V_668 = V_7 -> V_86 ;
V_663 -> V_669 = F_389 ( V_7 ) ;
V_663 -> V_670 = 0 ;
if ( F_390 ( V_85 , V_671 , V_7 -> V_48 ) ||
( V_7 -> V_301 &&
F_347 ( V_85 , V_672 , V_7 -> V_301 , V_7 -> V_303 ) ) ||
F_352 ( V_85 , V_673 , V_7 -> V_33 ) ||
( V_7 -> V_86 != F_391 ( V_7 ) &&
F_352 ( V_85 , V_674 , F_391 ( V_7 ) ) ) ||
F_379 ( V_85 , V_675 ,
F_44 ( V_7 ) ? V_7 -> V_676 : V_677 ) )
goto V_99;
V_664 = F_392 ( V_85 , V_678 ) ;
if ( ! V_664 )
goto V_99;
if ( F_376 ( V_85 , V_5 ) < 0 )
goto V_99;
F_393 ( V_85 , V_664 ) ;
F_62 ( V_85 , V_93 ) ;
return 0 ;
V_99:
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
static int F_394 ( struct V_84 * V_85 , struct V_120 * V_121 )
{
struct V_103 * V_103 = F_71 ( V_85 -> V_110 ) ;
int V_122 , V_123 ;
int V_124 = 0 , V_125 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_126 * V_127 ;
V_123 = V_121 -> args [ 0 ] ;
V_125 = V_121 -> args [ 1 ] ;
F_78 () ;
for ( V_122 = V_123 ; V_122 < V_128 ; V_122 ++ , V_125 = 0 ) {
V_124 = 0 ;
V_127 = & V_103 -> V_129 [ V_122 ] ;
F_80 (dev, head, index_hlist) {
if ( V_124 < V_125 )
goto V_132;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_132;
if ( F_388 ( V_85 , V_5 ,
F_75 ( V_121 -> V_85 ) . V_89 ,
V_121 -> V_93 -> V_119 ,
V_461 , V_133 ) < 0 )
goto V_177;
V_132:
V_124 ++ ;
}
}
V_177:
F_81 () ;
V_121 -> args [ 1 ] = V_124 ;
V_121 -> args [ 0 ] = V_122 ;
return V_85 -> V_135 ;
}
void F_291 ( int V_91 , struct V_4 * V_5 )
{
struct V_84 * V_85 ;
struct V_103 * V_103 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_104 ;
V_85 = F_65 ( F_368 () , V_105 ) ;
if ( ! V_85 )
goto V_106;
V_32 = F_388 ( V_85 , V_5 , 0 , 0 , V_91 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_106;
}
F_68 ( V_85 , V_103 , 0 , V_679 , NULL , V_105 ) ;
return;
V_106:
if ( V_32 < 0 )
F_69 ( V_103 , V_679 , V_32 ) ;
}
static inline T_14 F_395 ( void )
{
return F_55 ( sizeof( struct V_680 ) )
+ F_56 ( sizeof( struct V_157 ) )
+ F_56 ( sizeof( struct V_681 ) ) ;
}
static int F_396 ( struct V_84 * V_85 , struct V_4 * V_5 ,
struct V_357 * V_358 , T_1 V_89 , T_1 V_90 ,
int V_91 , unsigned int V_50 )
{
struct V_680 * V_682 ;
struct V_92 * V_93 ;
struct V_681 V_528 ;
V_93 = F_59 ( V_85 , V_89 , V_90 , V_91 , sizeof( * V_682 ) , V_50 ) ;
if ( ! V_93 )
return - V_95 ;
V_682 = F_60 ( V_93 ) ;
V_682 -> V_683 = V_97 ;
V_682 -> V_684 = 0 ;
V_682 -> V_685 = 0 ;
V_682 -> V_686 = V_5 -> V_7 -> V_86 ;
V_682 -> V_179 = V_358 -> V_179 ;
V_682 -> V_687 = V_358 -> type ;
V_682 -> V_688 = 0 ;
V_682 -> V_689 = 0 ;
if ( V_358 -> V_278 )
V_682 -> V_689 |= V_690 ;
if ( V_358 -> V_367 )
V_682 -> V_689 |= V_691 ;
if ( F_347 ( V_85 , V_692 , sizeof( V_358 -> V_359 ) , & V_358 -> V_359 ) )
goto V_99;
V_528 . V_693 = F_242 ( V_358 -> V_362 ) ;
V_528 . V_694 = F_242 ( V_358 -> V_361 ) ;
if ( F_347 ( V_85 , V_695 , sizeof( V_528 ) , & V_528 ) )
goto V_99;
F_62 ( V_85 , V_93 ) ;
return 0 ;
V_99:
F_63 ( V_85 , V_93 ) ;
return - V_95 ;
}
static void F_251 ( int V_91 , struct V_4 * V_5 ,
struct V_357 * V_358 )
{
struct V_84 * V_85 ;
struct V_103 * V_103 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_104 ;
V_85 = F_65 ( F_395 () , V_105 ) ;
if ( ! V_85 )
goto V_106;
V_32 = F_396 ( V_85 , V_5 , V_358 , 0 , 0 , V_91 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_95 ) ;
F_67 ( V_85 ) ;
goto V_106;
}
F_68 ( V_85 , V_103 , 0 , V_696 , NULL , V_105 ) ;
return;
V_106:
if ( V_32 < 0 )
F_69 ( V_103 , V_696 , V_32 ) ;
}
static void F_301 ( int V_91 , struct V_9 * V_10 )
{
struct V_103 * V_103 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_91 )
F_29 () ;
F_361 ( V_91 ? : V_418 , V_10 ) ;
switch ( V_91 ) {
case V_418 :
if ( ! ( V_10 -> V_151 -> V_697 ) )
F_275 ( V_10 -> V_151 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_87 ( V_10 ) ;
if ( ! F_205 ( & V_10 -> V_159 ) )
F_231 ( & V_10 -> V_159 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_200 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_88 ( V_10 ) ;
F_202 ( V_10 -> V_5 , & V_10 -> V_155 ) ;
if ( ! F_205 ( & V_10 -> V_159 ) ) {
struct V_164 * V_151 ;
V_151 = F_139 ( & V_10 -> V_159 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_151 )
F_140 ( V_151 ) ;
}
F_235 ( & V_10 -> V_151 -> V_233 ) ;
F_140 ( V_10 -> V_151 ) ;
F_397 ( V_103 ) ;
break;
}
F_398 ( & V_103 -> V_18 . V_130 ) ;
}
static void F_151 ( int V_91 , struct V_9 * V_10 )
{
F_117 () ;
if ( F_132 ( V_10 -> V_5 -> V_76 == 0 ) )
F_301 ( V_91 , V_10 ) ;
F_131 () ;
}
static
int F_399 ( struct V_142 * V_698 , int V_699 ,
void T_6 * V_700 , T_14 * V_701 , T_8 * V_702 )
{
int * V_703 = V_698 -> V_321 ;
int V_704 = * V_703 ;
T_8 V_492 = * V_702 ;
struct V_142 V_705 ;
int V_210 ;
V_705 = * V_698 ;
V_705 . V_321 = & V_704 ;
V_210 = F_400 ( & V_705 , V_699 , V_700 , V_701 , V_702 ) ;
if ( V_699 )
V_210 = F_91 ( V_698 , V_703 , V_704 ) ;
if ( V_210 )
* V_702 = V_492 ;
return V_210 ;
}
static
int F_401 ( struct V_142 * V_698 , int V_699 ,
void T_6 * V_700 , T_14 * V_701 , T_8 * V_702 )
{
struct V_4 * V_5 = V_698 -> V_147 ;
int V_706 = V_34 ;
struct V_142 V_705 ;
V_705 = * V_698 ;
V_705 . V_147 = & V_706 ;
V_705 . V_146 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_402 ( & V_705 , V_699 , V_700 , V_701 , V_702 ) ;
}
static void F_403 ( struct V_4 * V_5 )
{
struct V_707 V_708 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_404 ( & V_708 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_173 )
F_286 ( NULL , V_201 , & V_708 ) ;
else
F_286 ( NULL , V_184 , & V_708 ) ;
}
static void F_405 ( struct V_103 * V_103 , T_2 V_140 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_78 () ;
F_180 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_141 = ( ! V_5 -> V_39 . V_173 ) ^ ( ! V_140 ) ;
V_5 -> V_39 . V_173 = V_140 ;
if ( V_141 )
F_403 ( V_5 ) ;
}
}
F_81 () ;
}
static int F_406 ( struct V_142 * V_143 , int * V_144 , int V_140 )
{
struct V_103 * V_103 ;
int V_145 ;
if ( ! F_92 () )
return F_93 () ;
V_103 = (struct V_103 * ) V_143 -> V_146 ;
V_145 = * V_144 ;
* V_144 = V_140 ;
if ( V_144 == & V_103 -> V_18 . V_40 -> V_173 ) {
F_94 () ;
return 0 ;
}
if ( V_144 == & V_103 -> V_18 . V_117 -> V_173 ) {
V_103 -> V_18 . V_40 -> V_173 = V_140 ;
F_405 ( V_103 , V_140 ) ;
} else if ( ( ! V_140 ) ^ ( ! V_145 ) )
F_403 ( (struct V_4 * ) V_143 -> V_147 ) ;
F_94 () ;
return 0 ;
}
static
int F_407 ( struct V_142 * V_698 , int V_699 ,
void T_6 * V_700 , T_14 * V_701 , T_8 * V_702 )
{
int * V_703 = V_698 -> V_321 ;
int V_704 = * V_703 ;
T_8 V_492 = * V_702 ;
struct V_142 V_705 ;
int V_210 ;
V_705 = * V_698 ;
V_705 . V_321 = & V_704 ;
V_210 = F_400 ( & V_705 , V_699 , V_700 , V_701 , V_702 ) ;
if ( V_699 )
V_210 = F_406 ( V_698 , V_703 , V_704 ) ;
if ( V_210 )
* V_702 = V_492 ;
return V_210 ;
}
static
int F_408 ( struct V_142 * V_698 , int V_699 ,
void T_6 * V_700 , T_14 * V_701 , T_8 * V_702 )
{
int * V_703 = V_698 -> V_321 ;
int V_210 ;
int V_145 , V_709 ;
V_145 = * V_703 ;
V_210 = F_400 ( V_698 , V_699 , V_700 , V_701 , V_702 ) ;
V_709 = * V_703 ;
if ( V_699 && V_145 != V_709 ) {
struct V_103 * V_103 = V_698 -> V_146 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_703 == & V_103 -> V_18 . V_40 -> V_101 )
F_64 ( V_103 , V_82 ,
V_118 ,
V_103 -> V_18 . V_40 ) ;
else if ( V_703 == & V_103 -> V_18 . V_117 -> V_101 )
F_64 ( V_103 , V_82 ,
V_116 ,
V_103 -> V_18 . V_117 ) ;
else {
struct V_4 * V_5 = V_698 -> V_147 ;
F_64 ( V_103 , V_82 ,
V_5 -> V_7 -> V_86 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_210 ;
}
static int F_409 ( struct V_142 * V_698 , int V_699 ,
void T_6 * V_700 , T_14 * V_701 ,
T_8 * V_702 )
{
int V_32 ;
struct V_157 V_155 ;
char V_710 [ V_711 ] ;
struct V_142 V_705 = * V_698 ;
struct V_103 * V_103 = V_698 -> V_146 ;
struct V_712 * V_443 = V_698 -> V_321 ;
if ( & V_103 -> V_18 . V_117 -> V_448 == V_698 -> V_321 )
return - V_713 ;
V_705 . V_714 = V_711 ;
V_705 . V_321 = V_710 ;
if ( ! F_92 () )
return F_93 () ;
if ( ! V_699 && ! V_443 -> V_449 ) {
V_32 = - V_713 ;
goto V_177;
}
if ( ! V_699 ) {
V_32 = snprintf ( V_710 , sizeof( V_710 ) , L_29 ,
& V_443 -> V_443 ) ;
if ( V_32 >= sizeof( V_710 ) ) {
V_32 = - V_713 ;
goto V_177;
}
}
V_32 = F_410 ( & V_705 , V_699 , V_700 , V_701 , V_702 ) ;
if ( V_32 || ! V_699 )
goto V_177;
if ( F_411 ( V_710 , - 1 , V_155 . V_715 . V_716 , - 1 , NULL ) != 1 ) {
V_32 = - V_713 ;
goto V_177;
}
V_443 -> V_449 = true ;
V_443 -> V_443 = V_155 ;
if ( & V_103 -> V_18 . V_40 -> V_448 == V_698 -> V_321 ) {
struct V_6 * V_7 ;
F_90 (net, dev) {
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_369 =
V_370 ;
}
}
} else {
struct V_4 * V_5 = V_698 -> V_147 ;
V_5 -> V_369 = V_370 ;
}
V_177:
F_94 () ;
return V_32 ;
}
static
int F_412 ( struct V_142 * V_698 ,
int V_699 ,
void T_6 * V_700 ,
T_14 * V_701 ,
T_8 * V_702 )
{
int * V_703 = V_698 -> V_321 ;
int V_704 = * V_703 ;
T_8 V_492 = * V_702 ;
struct V_142 V_705 ;
int V_210 ;
V_705 = * V_698 ;
V_705 . V_321 = & V_704 ;
V_210 = F_400 ( & V_705 , V_699 , V_700 , V_701 , V_702 ) ;
if ( V_699 )
V_210 = F_97 ( V_698 , V_703 , V_704 ) ;
if ( V_210 )
* V_702 = V_492 ;
return V_210 ;
}
static int F_413 ( struct V_103 * V_103 , char * V_717 ,
struct V_4 * V_5 , struct V_87 * V_144 )
{
int V_16 ;
struct V_718 * V_719 ;
char V_720 [ sizeof( L_30 ) + V_633 ] ;
V_719 = F_414 ( & V_721 , sizeof( * V_719 ) , V_25 ) ;
if ( ! V_719 )
goto V_177;
for ( V_16 = 0 ; V_719 -> V_722 [ V_16 ] . V_321 ; V_16 ++ ) {
V_719 -> V_722 [ V_16 ] . V_321 += ( char * ) V_144 - ( char * ) & V_87 ;
V_719 -> V_722 [ V_16 ] . V_147 = V_5 ;
V_719 -> V_722 [ V_16 ] . V_146 = V_103 ;
}
snprintf ( V_720 , sizeof( V_720 ) , L_31 , V_717 ) ;
V_719 -> V_723 = F_415 ( V_103 , V_720 , V_719 -> V_722 ) ;
if ( ! V_719 -> V_723 )
goto free;
V_144 -> V_42 = V_719 ;
return 0 ;
free:
F_26 ( V_719 ) ;
V_177:
return - V_104 ;
}
static void F_416 ( struct V_87 * V_144 )
{
struct V_718 * V_719 ;
if ( ! V_144 -> V_42 )
return;
V_719 = V_144 -> V_42 ;
V_144 -> V_42 = NULL ;
F_417 ( V_719 -> V_723 ) ;
F_26 ( V_719 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_418 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_419 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_724 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_413 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_420 ( V_5 -> V_43 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_416 ( & V_5 -> V_39 ) ;
F_420 ( V_5 -> V_43 ) ;
}
static int T_10 F_421 ( struct V_103 * V_103 )
{
int V_32 = - V_30 ;
struct V_87 * V_725 , * V_726 ;
V_725 = F_414 ( & V_87 , sizeof( V_87 ) , V_25 ) ;
if ( ! V_725 )
goto V_727;
V_726 = F_414 ( & V_728 , sizeof( V_728 ) , V_25 ) ;
if ( ! V_726 )
goto V_729;
V_726 -> V_367 = V_730 . V_367 ;
V_726 -> V_173 = V_730 . V_173 ;
V_726 -> V_448 . V_449 = false ;
V_725 -> V_448 . V_449 = false ;
V_103 -> V_18 . V_117 = V_725 ;
V_103 -> V_18 . V_40 = V_726 ;
#ifdef F_422
V_32 = F_413 ( V_103 , L_32 , NULL , V_725 ) ;
if ( V_32 < 0 )
goto V_731;
V_32 = F_413 ( V_103 , L_33 , NULL , V_726 ) ;
if ( V_32 < 0 )
goto V_732;
#endif
return 0 ;
#ifdef F_422
V_732:
F_416 ( V_725 ) ;
V_731:
F_26 ( V_726 ) ;
#endif
V_729:
F_26 ( V_725 ) ;
V_727:
return V_32 ;
}
static void T_11 F_423 ( struct V_103 * V_103 )
{
#ifdef F_422
F_416 ( V_103 -> V_18 . V_40 ) ;
F_416 ( V_103 -> V_18 . V_117 ) ;
#endif
F_26 ( V_103 -> V_18 . V_40 ) ;
F_26 ( V_103 -> V_18 . V_117 ) ;
}
int T_12 F_424 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_425 () ;
if ( V_32 < 0 ) {
F_426 ( L_34 ,
V_47 , V_32 ) ;
goto V_177;
}
V_32 = F_332 ( & V_733 ) ;
if ( V_32 < 0 )
goto V_734;
V_15 = F_427 ( L_35 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_735;
}
F_253 () ;
V_5 = F_28 ( V_736 . V_737 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_121 ( V_5 ) ;
goto V_738;
}
for ( V_16 = 0 ; V_16 < V_469 ; V_16 ++ )
F_428 ( & V_181 [ V_16 ] ) ;
F_429 ( & V_739 ) ;
F_250 () ;
F_430 ( & V_740 ) ;
V_32 = F_431 ( V_741 , V_742 , NULL , F_394 ,
NULL ) ;
if ( V_32 < 0 )
goto V_106;
F_431 ( V_741 , V_418 , F_344 , NULL , NULL ) ;
F_431 ( V_741 , V_200 , F_341 , NULL , NULL ) ;
F_431 ( V_741 , V_743 , F_360 ,
F_357 , NULL ) ;
F_431 ( V_741 , V_561 , NULL ,
F_358 , NULL ) ;
F_431 ( V_741 , V_565 , NULL ,
F_359 , NULL ) ;
F_431 ( V_741 , V_744 , F_70 ,
F_77 , NULL ) ;
F_432 () ;
return 0 ;
V_106:
F_433 ( & V_740 ) ;
F_434 ( & V_739 ) ;
V_738:
F_435 ( V_15 ) ;
V_735:
F_334 ( & V_733 ) ;
V_734:
F_436 () ;
V_177:
return V_32 ;
}
void F_437 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_434 ( & V_739 ) ;
F_334 ( & V_733 ) ;
F_436 () ;
F_253 () ;
F_438 ( & V_740 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_292 ( V_7 , 1 ) ;
}
F_292 ( V_736 . V_737 , 2 ) ;
F_143 ( & V_175 ) ;
for ( V_16 = 0 ; V_16 < V_469 ; V_16 ++ )
F_66 ( ! F_439 ( & V_181 [ V_16 ] ) ) ;
F_144 ( & V_175 ) ;
F_10 ( & V_509 ) ;
F_94 () ;
F_435 ( V_15 ) ;
}
