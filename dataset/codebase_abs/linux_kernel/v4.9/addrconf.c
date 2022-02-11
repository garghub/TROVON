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
if ( ! F_21 ( & V_14 -> V_15 ) )
F_22 ( V_14 ) ;
F_23 ( V_19 , & V_14 -> V_15 , V_18 ) ;
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
V_35 -> V_47 = V_48 ;
else
V_35 -> V_47 = V_49 ;
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
if ( ( V_88 || type == V_90 ) &&
F_67 ( V_95 , V_90 , V_98 -> V_53 ) < 0 )
goto V_109;
#ifdef F_63
if ( ( V_88 || type == V_91 ) &&
F_67 ( V_95 , V_91 ,
V_98 -> V_110 ) < 0 )
goto V_109;
#endif
if ( ( V_88 || type == V_92 ) &&
F_67 ( V_95 , V_92 , V_98 -> V_111 ) < 0 )
goto V_109;
if ( ( V_88 || type == V_93 ) &&
F_67 ( V_95 , V_93 ,
V_98 -> V_112 ) < 0 )
goto V_109;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
void F_70 ( struct V_113 * V_113 , int type , int V_96 ,
struct V_97 * V_98 )
{
struct V_94 * V_95 ;
int V_36 = - V_114 ;
V_95 = F_71 ( F_60 ( type ) , V_29 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_64 ( V_95 , V_96 , V_98 , 0 , 0 ,
V_116 , 0 , type ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_117 , NULL , V_29 ) ;
return;
V_115:
F_75 ( V_113 , V_117 , V_36 ) ;
}
static int F_76 ( struct V_94 * V_118 ,
struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_118 -> V_119 ) ;
struct V_120 * V_121 [ V_122 + 1 ] ;
struct V_87 * V_104 ;
struct V_94 * V_95 ;
struct V_97 * V_98 ;
struct V_8 * V_123 ;
struct V_10 * V_11 ;
int V_96 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_104 ) , V_121 , V_122 ,
V_124 ) ;
if ( V_36 < 0 )
goto V_115;
V_36 = - V_39 ;
if ( ! V_121 [ V_108 ] )
goto V_115;
V_96 = F_79 ( V_121 [ V_108 ] ) ;
switch ( V_96 ) {
case V_125 :
V_98 = V_113 -> V_22 . V_126 ;
break;
case V_127 :
V_98 = V_113 -> V_22 . V_44 ;
break;
default:
V_11 = F_80 ( V_113 , V_96 ) ;
if ( ! V_11 )
goto V_115;
V_123 = F_57 ( V_11 ) ;
if ( ! V_123 )
goto V_115;
V_98 = & V_123 -> V_43 ;
break;
}
V_36 = - V_114 ;
V_95 = F_71 ( F_60 ( V_89 ) , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_64 ( V_95 , V_96 , V_98 ,
F_81 ( V_118 ) . V_99 ,
V_103 -> V_129 , V_116 , 0 ,
V_89 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
V_36 = F_82 ( V_95 , V_113 , F_81 ( V_118 ) . V_99 ) ;
V_115:
return V_36 ;
}
static int F_83 ( struct V_94 * V_95 ,
struct V_130 * V_131 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
int V_132 , V_133 ;
int V_134 , V_135 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_136 * V_137 ;
V_133 = V_131 -> args [ 0 ] ;
V_135 = V_134 = V_131 -> args [ 1 ] ;
for ( V_132 = V_133 ; V_132 < V_138 ; V_132 ++ , V_135 = 0 ) {
V_134 = 0 ;
V_137 = & V_113 -> V_139 [ V_132 ] ;
F_84 () ;
V_131 -> V_100 = F_85 ( & V_113 -> V_22 . V_140 ) ^
V_113 -> V_141 ;
F_86 (dev, head, index_hlist) {
if ( V_134 < V_135 )
goto V_142;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_142;
if ( F_64 ( V_95 , V_11 -> V_96 ,
& V_9 -> V_43 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_116 ,
V_143 ,
V_89 ) < 0 ) {
F_87 () ;
goto V_144;
}
F_88 ( V_131 , F_89 ( V_95 ) ) ;
V_142:
V_134 ++ ;
}
F_87 () ;
}
if ( V_132 == V_138 ) {
if ( F_64 ( V_95 , V_125 ,
V_113 -> V_22 . V_126 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_116 , V_143 ,
V_89 ) < 0 )
goto V_144;
else
V_132 ++ ;
}
if ( V_132 == V_138 + 1 ) {
if ( F_64 ( V_95 , V_127 ,
V_113 -> V_22 . V_44 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_116 , V_143 ,
V_89 ) < 0 )
goto V_144;
else
V_132 ++ ;
}
V_144:
V_131 -> args [ 0 ] = V_132 ;
V_131 -> args [ 1 ] = V_134 ;
return V_95 -> V_145 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_13 * V_146 ;
if ( ! V_9 )
return;
V_11 = V_9 -> V_11 ;
if ( V_9 -> V_43 . V_53 )
F_40 ( V_11 ) ;
if ( V_11 -> V_58 & V_82 ) {
if ( V_9 -> V_43 . V_53 ) {
F_54 ( V_11 , & V_83 ) ;
F_54 ( V_11 , & V_147 ) ;
F_54 ( V_11 , & V_148 ) ;
} else {
F_91 ( V_11 , & V_83 ) ;
F_91 ( V_11 , & V_147 ) ;
F_91 ( V_11 , & V_148 ) ;
}
}
F_92 (ifa, &idev->addr_list, if_list) {
if ( V_146 -> V_58 & V_149 )
continue;
if ( V_9 -> V_43 . V_53 )
F_93 ( V_146 ) ;
else
F_94 ( V_146 ) ;
}
F_70 ( F_38 ( V_11 ) , V_90 ,
V_11 -> V_96 , & V_9 -> V_43 ) ;
}
static void F_95 ( struct V_113 * V_113 , T_4 V_150 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_151 = ( ! V_9 -> V_43 . V_53 ) ^ ( ! V_150 ) ;
V_9 -> V_43 . V_53 = V_150 ;
if ( V_151 )
F_90 ( V_9 ) ;
}
}
}
static int F_97 ( struct V_152 * V_153 , int * V_154 , int V_150 )
{
struct V_113 * V_113 ;
int V_155 ;
if ( ! F_98 () )
return F_99 () ;
V_113 = (struct V_113 * ) V_153 -> V_156 ;
V_155 = * V_154 ;
* V_154 = V_150 ;
if ( V_154 == & V_113 -> V_22 . V_44 -> V_53 ) {
if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_70 ( V_113 , V_90 ,
V_127 ,
V_113 -> V_22 . V_44 ) ;
F_100 () ;
return 0 ;
}
if ( V_154 == & V_113 -> V_22 . V_126 -> V_53 ) {
int V_157 = V_113 -> V_22 . V_44 -> V_53 ;
V_113 -> V_22 . V_44 -> V_53 = V_150 ;
if ( ( ! V_150 ) ^ ( ! V_157 ) )
F_70 ( V_113 , V_90 ,
V_127 ,
V_113 -> V_22 . V_44 ) ;
F_95 ( V_113 , V_150 ) ;
if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_70 ( V_113 , V_90 ,
V_125 ,
V_113 -> V_22 . V_126 ) ;
} else if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_90 ( (struct V_8 * ) V_153 -> V_158 ) ;
F_100 () ;
if ( V_150 )
F_101 ( V_113 ) ;
return 1 ;
}
static void F_102 ( struct V_113 * V_113 , T_4 V_150 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_151 = ( ! V_9 -> V_43 . V_112 ) ^ ( ! V_150 ) ;
V_9 -> V_43 . V_112 = V_150 ;
if ( V_151 )
F_70 ( F_38 ( V_11 ) ,
V_93 ,
V_11 -> V_96 ,
& V_9 -> V_43 ) ;
}
}
}
static int F_103 ( struct V_152 * V_153 , int * V_154 , int V_150 )
{
struct V_113 * V_113 ;
int V_155 ;
if ( ! F_98 () )
return F_99 () ;
V_113 = (struct V_113 * ) V_153 -> V_156 ;
V_155 = * V_154 ;
* V_154 = V_150 ;
if ( V_154 == & V_113 -> V_22 . V_44 -> V_112 ) {
if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_70 ( V_113 ,
V_93 ,
V_127 ,
V_113 -> V_22 . V_44 ) ;
F_100 () ;
return 0 ;
}
if ( V_154 == & V_113 -> V_22 . V_126 -> V_112 ) {
V_113 -> V_22 . V_44 -> V_112 = V_150 ;
F_102 ( V_113 , V_150 ) ;
if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_70 ( V_113 ,
V_93 ,
V_125 ,
V_113 -> V_22 . V_126 ) ;
}
F_100 () ;
return 1 ;
}
void F_104 ( struct V_13 * V_14 )
{
F_72 ( ! F_105 ( & V_14 -> V_159 ) ) ;
#ifdef F_106
F_107 ( L_4 , V_55 ) ;
#endif
F_108 ( V_14 -> V_9 ) ;
if ( F_14 ( & V_14 -> V_15 ) )
F_109 ( L_5 ,
V_14 ) ;
if ( V_14 -> V_160 != V_161 ) {
F_110 ( L_6 , V_14 ) ;
return;
}
F_111 ( V_14 -> V_6 ) ;
F_112 ( V_14 , V_162 ) ;
}
static void
F_113 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
struct V_163 * V_154 ;
int V_164 = F_114 ( & V_14 -> V_165 ) ;
F_115 (p, &idev->addr_list) {
struct V_13 * V_146
= F_116 ( V_154 , struct V_13 , V_166 ) ;
if ( V_164 >= F_114 ( & V_146 -> V_165 ) )
break;
}
F_117 ( & V_14 -> V_166 , V_154 ) ;
}
static T_1 F_118 ( const struct V_167 * V_165 )
{
return F_119 ( F_120 ( V_165 ) , V_168 ) ;
}
static struct V_13 *
F_121 ( struct V_8 * V_9 , const struct V_167 * V_165 ,
const struct V_167 * V_169 , int V_170 ,
int V_171 , T_1 V_58 , T_1 V_172 , T_1 V_173 )
{
struct V_13 * V_146 = NULL ;
struct V_174 * V_6 ;
unsigned int V_175 ;
int V_36 = 0 ;
int V_176 = F_122 ( V_165 ) ;
if ( V_176 == V_177 ||
V_176 & V_178 ||
( ! ( V_9 -> V_11 -> V_58 & V_60 ) &&
V_176 & V_179 ) )
return F_34 ( - V_180 ) ;
F_123 () ;
if ( V_9 -> V_84 ) {
V_36 = - V_181 ;
goto V_182;
}
if ( V_9 -> V_43 . V_183 ) {
V_36 = - V_184 ;
goto V_182;
}
F_124 ( & V_185 ) ;
if ( F_125 ( F_38 ( V_9 -> V_11 ) , V_165 , V_9 -> V_11 ) ) {
F_42 ( L_7 ) ;
V_36 = - V_186 ;
goto V_187;
}
V_146 = F_29 ( sizeof( struct V_13 ) , V_128 ) ;
if ( ! V_146 ) {
F_42 ( L_8 ) ;
V_36 = - V_114 ;
goto V_187;
}
V_6 = F_126 ( V_9 , V_165 , false ) ;
if ( F_58 ( V_6 ) ) {
V_36 = F_127 ( V_6 ) ;
goto V_187;
}
F_128 ( V_9 -> V_51 ) ;
V_146 -> V_165 = * V_165 ;
if ( V_169 )
V_146 -> V_169 = * V_169 ;
F_129 ( & V_146 -> V_40 ) ;
F_130 ( & V_146 -> V_15 , V_188 ) ;
F_131 ( & V_146 -> V_159 ) ;
V_146 -> V_171 = V_171 ;
V_146 -> V_189 = V_170 ;
V_146 -> V_58 = V_58 | V_149 ;
V_146 -> V_172 = V_172 ;
V_146 -> V_173 = V_173 ;
V_146 -> V_1 = V_146 -> V_78 = V_17 ;
V_146 -> V_190 = false ;
V_146 -> V_6 = V_6 ;
V_146 -> V_9 = V_9 ;
F_18 ( V_9 ) ;
F_22 ( V_146 ) ;
V_175 = F_118 ( V_165 ) ;
F_132 ( & V_146 -> V_159 , & V_191 [ V_175 ] ) ;
F_133 ( & V_185 ) ;
F_134 ( & V_9 -> V_40 ) ;
F_113 ( V_9 , V_146 ) ;
if ( V_146 -> V_58 & V_192 ) {
F_135 ( & V_146 -> V_193 , & V_9 -> V_67 ) ;
F_22 ( V_146 ) ;
}
F_22 ( V_146 ) ;
F_136 ( & V_9 -> V_40 ) ;
V_182:
F_137 () ;
if ( F_138 ( V_36 == 0 ) )
F_139 ( V_194 , V_146 ) ;
else {
F_30 ( V_146 ) ;
V_146 = F_34 ( V_36 ) ;
}
return V_146 ;
V_187:
F_133 ( & V_185 ) ;
goto V_182;
}
static enum V_195
F_140 ( struct V_13 * V_14 , unsigned long * V_196 )
{
struct V_13 * V_146 ;
struct V_8 * V_9 = V_14 -> V_9 ;
unsigned long V_197 ;
enum V_195 V_198 = V_199 ;
* V_196 = V_17 ;
F_92 (ifa, &idev->addr_list, if_list) {
if ( V_146 == V_14 )
continue;
if ( ! F_141 ( & V_146 -> V_165 , & V_14 -> V_165 ,
V_14 -> V_189 ) )
continue;
if ( V_146 -> V_58 & ( V_200 | V_201 ) )
return V_202 ;
V_198 = V_203 ;
F_124 ( & V_146 -> V_40 ) ;
V_197 = F_142 ( V_146 -> V_172 , V_3 ) ;
if ( F_143 ( * V_196 , V_146 -> V_78 + V_197 * V_3 ) )
* V_196 = V_146 -> V_78 + V_197 * V_3 ;
F_133 ( & V_146 -> V_40 ) ;
}
return V_198 ;
}
static void
F_144 ( struct V_13 * V_14 , unsigned long V_196 , bool V_204 )
{
struct V_174 * V_6 ;
V_6 = F_145 ( & V_14 -> V_165 ,
V_14 -> V_189 ,
V_14 -> V_9 -> V_11 ,
0 , V_205 | V_206 ) ;
if ( V_6 ) {
if ( V_204 )
F_146 ( V_6 ) ;
else {
if ( ! ( V_6 -> V_207 & V_208 ) )
F_147 ( V_6 , V_196 ) ;
F_111 ( V_6 ) ;
}
}
}
static void F_148 ( struct V_13 * V_14 )
{
int V_160 ;
enum V_195 V_198 = V_202 ;
unsigned long V_196 ;
F_33 () ;
F_149 ( & V_14 -> V_40 ) ;
V_160 = V_14 -> V_160 ;
V_14 -> V_160 = V_161 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_160 == V_161 )
goto V_187;
F_149 ( & V_185 ) ;
F_151 ( & V_14 -> V_159 ) ;
F_150 ( & V_185 ) ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_14 -> V_58 & V_192 ) {
F_153 ( & V_14 -> V_193 ) ;
if ( V_14 -> V_209 ) {
F_154 ( V_14 -> V_209 ) ;
V_14 -> V_209 = NULL ;
}
F_15 ( V_14 ) ;
}
if ( V_14 -> V_58 & V_200 && ! ( V_14 -> V_58 & V_201 ) )
V_198 = F_140 ( V_14 , & V_196 ) ;
F_155 ( & V_14 -> V_166 ) ;
F_15 ( V_14 ) ;
F_156 ( & V_14 -> V_9 -> V_40 ) ;
F_13 ( V_14 ) ;
F_157 ( V_210 , V_14 ) ;
F_139 ( V_211 , V_14 ) ;
if ( V_198 != V_202 ) {
F_144 ( V_14 , V_196 ,
V_198 == V_199 ) ;
}
F_158 ( V_14 ) ;
V_187:
F_154 ( V_14 ) ;
}
static int F_159 ( struct V_13 * V_14 , struct V_13 * V_212 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_167 V_165 , * V_213 ;
unsigned long V_214 , V_215 , V_216 , V_217 ;
unsigned long V_218 ;
int V_219 ;
int V_220 = 0 ;
T_1 V_221 ;
unsigned long V_222 = V_17 ;
long V_223 ;
T_2 V_224 ;
F_152 ( & V_9 -> V_40 ) ;
if ( V_212 ) {
F_149 ( & V_212 -> V_40 ) ;
memcpy ( & V_165 . V_225 [ 8 ] , & V_212 -> V_165 . V_225 [ 8 ] , 8 ) ;
F_150 ( & V_212 -> V_40 ) ;
V_213 = & V_165 ;
} else {
V_213 = NULL ;
}
V_226:
F_18 ( V_9 ) ;
if ( V_9 -> V_43 . V_73 <= 0 ) {
F_156 ( & V_9 -> V_40 ) ;
F_47 ( L_9 , V_55 ) ;
F_108 ( V_9 ) ;
V_220 = - 1 ;
goto V_187;
}
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_227 ++ >= V_9 -> V_43 . V_228 ) {
V_9 -> V_43 . V_73 = - 1 ;
F_150 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_110 ( L_10 ,
V_55 ) ;
F_108 ( V_9 ) ;
V_220 = - 1 ;
goto V_187;
}
F_22 ( V_14 ) ;
memcpy ( V_165 . V_225 , V_14 -> V_165 . V_225 , 8 ) ;
F_160 ( V_9 , V_213 ) ;
memcpy ( & V_165 . V_225 [ 8 ] , V_9 -> V_229 , 8 ) ;
V_217 = ( V_222 - V_14 -> V_78 ) / V_3 ;
V_218 = V_9 -> V_43 . V_228 *
V_9 -> V_43 . V_230 *
F_161 ( V_9 -> V_51 , V_231 ) / V_3 ;
V_224 = F_162 ( V_9 -> V_43 . V_232 ) ;
V_223 = F_163 ( V_233 ,
V_9 -> V_43 . V_223 ,
V_224 - V_218 ) ;
if ( F_164 ( V_9 -> V_68 > V_223 ) ) {
if ( V_223 > 0 ) {
F_165 ( & V_9 -> V_68 ,
sizeof( V_9 -> V_68 ) ) ;
V_9 -> V_68 %= V_223 ;
} else {
V_9 -> V_68 = 0 ;
}
}
V_215 = F_163 ( V_233 ,
V_14 -> V_172 ,
V_9 -> V_43 . V_234 + V_217 ) ;
V_214 = V_224 + V_217 -
V_9 -> V_68 ;
V_214 = F_163 ( V_233 , V_14 -> V_173 , V_214 ) ;
V_219 = V_14 -> V_189 ;
V_216 = V_14 -> V_78 ;
F_150 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
V_217 = ( V_222 - V_216 + V_235 ) / V_3 ;
if ( V_214 <= V_218 + V_217 ) {
F_154 ( V_14 ) ;
F_108 ( V_9 ) ;
V_220 = - 1 ;
goto V_187;
}
V_221 = V_192 ;
if ( V_14 -> V_58 & V_236 )
V_221 |= V_236 ;
V_212 = F_121 ( V_9 , & V_165 , NULL , V_219 ,
F_166 ( & V_165 ) , V_221 ,
V_215 , V_214 ) ;
if ( F_58 ( V_212 ) ) {
F_154 ( V_14 ) ;
F_108 ( V_9 ) ;
F_47 ( L_11 , V_55 ) ;
V_213 = & V_165 ;
F_152 ( & V_9 -> V_40 ) ;
goto V_226;
}
F_149 ( & V_212 -> V_40 ) ;
V_212 -> V_209 = V_14 ;
V_212 -> V_1 = V_222 ;
V_212 -> V_78 = V_216 ;
F_150 ( & V_212 -> V_40 ) ;
F_167 ( V_212 ) ;
F_154 ( V_212 ) ;
F_108 ( V_9 ) ;
V_187:
return V_220 ;
}
static inline int F_168 ( int type )
{
if ( type & ( V_237 | V_238 | V_179 ) )
return 1 ;
return 0 ;
}
static inline bool F_169 ( struct V_8 * V_9 )
{
#ifdef F_170
return V_9 && V_9 -> V_43 . V_239 && V_9 -> V_43 . V_240 ;
#else
return false ;
#endif
}
static int F_171 ( struct V_113 * V_113 ,
struct V_241 * V_242 ,
struct V_243 * V_244 ,
int V_20 )
{
int V_220 ;
if ( V_20 <= V_242 -> V_245 ) {
switch ( V_20 ) {
case V_246 :
V_220 = V_242 -> V_247 ;
break;
case V_248 :
V_220 = V_242 -> V_249 ;
break;
default:
V_220 = ! ! F_172 ( V_20 , V_242 -> V_250 ) ;
}
goto V_187;
}
switch ( V_20 ) {
case V_251 :
V_220 = ! ! V_242 -> V_146 ;
break;
case V_252 :
V_220 = F_173 ( & V_242 -> V_146 -> V_165 , V_244 -> V_165 ) ;
break;
case V_246 :
V_220 = F_174 ( V_242 -> V_176 ) ;
if ( V_220 >= V_244 -> V_171 )
V_220 = - V_220 ;
else
V_220 -= 128 ;
V_242 -> V_247 = V_220 ;
break;
case V_253 :
{
T_5 V_254 = V_255 ;
if ( ! F_169 ( V_242 -> V_146 -> V_9 ) )
V_254 |= V_236 ;
V_220 = F_168 ( V_242 -> V_176 ) ||
! ( V_242 -> V_146 -> V_58 & V_254 ) ;
break;
}
#ifdef F_175
case V_256 :
{
int V_257 = ! ( V_244 -> V_258 & V_259 ) ;
V_220 = ! ( V_242 -> V_146 -> V_58 & V_260 ) ^ V_257 ;
break;
}
#endif
case V_261 :
V_220 = ( ! V_244 -> V_96 ||
V_244 -> V_96 == V_242 -> V_146 -> V_9 -> V_11 -> V_96 ) ;
break;
case V_262 :
V_220 = F_176 ( V_113 ,
& V_242 -> V_146 -> V_165 , V_242 -> V_176 ,
V_242 -> V_146 -> V_9 -> V_11 -> V_96 ) == V_244 -> V_263 ;
break;
case V_264 :
{
int V_265 = V_244 -> V_258 & ( V_266 | V_267 ) ?
! ! ( V_244 -> V_258 & V_267 ) :
V_242 -> V_146 -> V_9 -> V_43 . V_73 >= 2 ;
V_220 = ( ! ( V_242 -> V_146 -> V_58 & V_192 ) ) ^ V_265 ;
break;
}
case V_268 :
V_220 = ! ( F_177 ( & V_242 -> V_146 -> V_165 ) ^
F_177 ( V_244 -> V_165 ) ) ;
break;
case V_248 :
V_220 = F_178 ( & V_242 -> V_146 -> V_165 , V_244 -> V_165 ) ;
if ( V_220 > V_242 -> V_146 -> V_189 )
V_220 = V_242 -> V_146 -> V_189 ;
V_242 -> V_249 = V_220 ;
break;
#ifdef F_170
case V_269 :
V_220 = ! ( V_242 -> V_146 -> V_58 & V_236 ) ;
break;
#endif
default:
V_220 = 0 ;
}
if ( V_220 )
F_179 ( V_20 , V_242 -> V_250 ) ;
V_242 -> V_245 = V_20 ;
V_187:
return V_220 ;
}
static int F_180 ( struct V_113 * V_113 ,
struct V_243 * V_244 ,
struct V_8 * V_9 ,
struct V_241 * V_270 ,
int V_271 )
{
struct V_241 * V_242 = & V_270 [ 1 - V_271 ] , * V_272 = & V_270 [ V_271 ] ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (score->ifa, &idev->addr_list, if_list) {
int V_20 ;
if ( ( V_242 -> V_146 -> V_58 & V_149 ) &&
( ! ( V_242 -> V_146 -> V_58 & V_236 ) ) )
continue;
V_242 -> V_176 = F_182 ( & V_242 -> V_146 -> V_165 ) ;
if ( F_164 ( V_242 -> V_176 == V_177 ||
V_242 -> V_176 & V_178 ) ) {
F_183 ( L_12 ,
V_9 -> V_11 -> V_56 ) ;
continue;
}
V_242 -> V_245 = - 1 ;
F_184 ( V_242 -> V_250 , V_273 ) ;
for ( V_20 = 0 ; V_20 < V_273 ; V_20 ++ ) {
int V_274 , V_275 ;
V_274 = F_171 ( V_113 , V_272 , V_244 , V_20 ) ;
V_275 = F_171 ( V_113 , V_242 , V_244 , V_20 ) ;
if ( V_274 > V_275 ) {
if ( V_20 == V_246 &&
V_242 -> V_247 > 0 ) {
goto V_187;
}
break;
} else if ( V_274 < V_275 ) {
if ( V_272 -> V_146 )
F_154 ( V_272 -> V_146 ) ;
F_22 ( V_242 -> V_146 ) ;
F_185 ( V_272 , V_242 ) ;
V_271 = 1 - V_271 ;
V_242 -> V_146 = V_272 -> V_146 ;
break;
}
}
}
V_187:
F_186 ( & V_9 -> V_40 ) ;
return V_271 ;
}
static int F_187 ( struct V_113 * V_113 ,
const struct V_10 * V_276 ,
const struct V_10 * V_277 ,
struct V_243 * V_244 ,
struct V_241 * V_270 ,
int V_271 )
{
struct V_8 * V_9 ;
V_9 = F_57 ( V_276 ) ;
if ( V_9 )
V_271 = F_180 ( V_113 , V_244 , V_9 ,
V_270 , V_271 ) ;
V_9 = F_57 ( V_277 ) ;
if ( V_9 )
V_271 = F_180 ( V_113 , V_244 , V_9 ,
V_270 , V_271 ) ;
return V_271 ;
}
int F_188 ( struct V_113 * V_113 , const struct V_10 * V_276 ,
const struct V_167 * V_278 , unsigned int V_258 ,
struct V_167 * V_279 )
{
struct V_241 V_270 [ 2 ] , * V_272 ;
struct V_243 V_244 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_280 ;
bool V_281 = false ;
int V_271 = 0 ;
V_280 = F_182 ( V_278 ) ;
V_244 . V_165 = V_278 ;
V_244 . V_96 = V_276 ? V_276 -> V_96 : 0 ;
V_244 . V_171 = F_174 ( V_280 ) ;
V_244 . V_263 = F_176 ( V_113 , V_278 , V_280 , V_244 . V_96 ) ;
V_244 . V_258 = V_258 ;
V_270 [ V_271 ] . V_245 = - 1 ;
V_270 [ V_271 ] . V_146 = NULL ;
F_84 () ;
if ( V_276 ) {
V_9 = F_57 ( V_276 ) ;
if ( ( V_280 & V_178 ) ||
V_244 . V_171 <= V_282 ||
( V_9 && V_9 -> V_43 . V_283 ) ) {
V_281 = true ;
}
}
if ( V_281 ) {
if ( V_9 )
V_271 = F_180 ( V_113 , & V_244 , V_9 , V_270 , V_271 ) ;
} else {
const struct V_10 * V_277 ;
int V_284 = 0 ;
V_277 = F_189 ( V_276 ) ;
if ( V_277 ) {
V_284 = V_277 -> V_96 ;
V_271 = F_187 ( V_113 , V_276 ,
V_277 , & V_244 ,
V_270 , V_271 ) ;
if ( V_270 [ V_271 ] . V_146 )
goto V_187;
}
F_190 (net, dev) {
if ( F_191 ( V_11 ) != V_284 )
continue;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
continue;
V_271 = F_180 ( V_113 , & V_244 , V_9 , V_270 , V_271 ) ;
}
}
V_187:
F_87 () ;
V_272 = & V_270 [ V_271 ] ;
if ( ! V_272 -> V_146 )
return - V_180 ;
* V_279 = V_272 -> V_146 -> V_165 ;
F_154 ( V_272 -> V_146 ) ;
return 0 ;
}
int F_192 ( struct V_8 * V_9 , struct V_167 * V_165 ,
T_1 V_285 )
{
struct V_13 * V_14 ;
int V_36 = - V_180 ;
F_193 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_171 > V_286 )
break;
if ( V_14 -> V_171 == V_286 &&
! ( V_14 -> V_58 & V_285 ) ) {
* V_165 = V_14 -> V_165 ;
V_36 = 0 ;
break;
}
}
return V_36 ;
}
int F_194 ( struct V_10 * V_11 , struct V_167 * V_165 ,
T_1 V_285 )
{
struct V_8 * V_9 ;
int V_36 = - V_180 ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_181 ( & V_9 -> V_40 ) ;
V_36 = F_192 ( V_9 , V_165 , V_285 ) ;
F_186 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_36 ;
}
static int F_195 ( struct V_8 * V_9 )
{
int V_287 = 0 ;
struct V_13 * V_14 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list)
V_287 ++ ;
F_186 ( & V_9 -> V_40 ) ;
return V_287 ;
}
int F_196 ( struct V_113 * V_113 , const struct V_167 * V_165 ,
const struct V_10 * V_11 , int V_288 )
{
return F_197 ( V_113 , V_165 , V_11 , V_288 , V_149 ) ;
}
int F_197 ( struct V_113 * V_113 , const struct V_167 * V_165 ,
const struct V_10 * V_11 , int V_288 ,
T_1 V_285 )
{
struct V_13 * V_14 ;
unsigned int V_175 = F_118 ( V_165 ) ;
T_1 V_289 ;
F_123 () ;
F_86 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_198 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_113 ) )
continue;
V_289 = ( V_14 -> V_58 & V_236 )
? ( V_14 -> V_58 & ~ V_149 )
: V_14 -> V_58 ;
if ( F_173 ( & V_14 -> V_165 , V_165 ) &&
! ( V_289 & V_285 ) &&
( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_171 & ( V_286 | V_290 ) || V_288 ) ) ) {
F_137 () ;
return 1 ;
}
}
F_137 () ;
return 0 ;
}
static bool F_125 ( struct V_113 * V_113 , const struct V_167 * V_165 ,
struct V_10 * V_11 )
{
unsigned int V_175 = F_118 ( V_165 ) ;
struct V_13 * V_14 ;
F_199 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_198 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_113 ) )
continue;
if ( F_173 ( & V_14 -> V_165 , V_165 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 )
return true ;
}
}
return false ;
}
bool F_200 ( const struct V_167 * V_165 ,
const unsigned int V_189 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_146 ;
bool V_220 = false ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifa, &idev->addr_list, if_list) {
V_220 = F_141 ( V_165 , & V_146 -> V_165 , V_189 ) ;
if ( V_220 )
break;
}
F_186 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_220 ;
}
int F_201 ( const struct V_167 * V_165 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_13 * V_146 ;
int V_291 ;
V_291 = 0 ;
F_84 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifa, &idev->addr_list, if_list) {
V_291 = F_141 ( V_165 , & V_146 -> V_165 ,
V_146 -> V_189 ) ;
if ( V_291 )
break;
}
F_186 ( & V_9 -> V_40 ) ;
}
F_87 () ;
return V_291 ;
}
struct V_13 * F_202 ( struct V_113 * V_113 , const struct V_167 * V_165 ,
struct V_10 * V_11 , int V_288 )
{
struct V_13 * V_14 , * V_292 = NULL ;
unsigned int V_175 = F_118 ( V_165 ) ;
F_123 () ;
F_203 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_198 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_113 ) )
continue;
if ( F_173 ( & V_14 -> V_165 , V_165 ) ) {
if ( ! V_11 || V_14 -> V_9 -> V_11 == V_11 ||
! ( V_14 -> V_171 & ( V_286 | V_290 ) || V_288 ) ) {
V_292 = V_14 ;
F_22 ( V_14 ) ;
break;
}
}
}
F_137 () ;
return V_292 ;
}
static void F_204 ( struct V_13 * V_14 , int V_293 )
{
if ( V_293 )
V_14 -> V_58 |= V_294 ;
if ( V_14 -> V_58 & V_200 ) {
F_149 ( & V_14 -> V_40 ) ;
F_13 ( V_14 ) ;
V_14 -> V_58 |= V_149 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_293 )
F_157 ( 0 , V_14 ) ;
F_154 ( V_14 ) ;
} else if ( V_14 -> V_58 & V_192 ) {
struct V_13 * V_209 ;
F_149 ( & V_14 -> V_40 ) ;
V_209 = V_14 -> V_209 ;
if ( V_209 ) {
F_22 ( V_209 ) ;
F_150 ( & V_14 -> V_40 ) ;
F_159 ( V_209 , V_14 ) ;
F_154 ( V_209 ) ;
} else {
F_150 ( & V_14 -> V_40 ) ;
}
F_148 ( V_14 ) ;
} else {
F_148 ( V_14 ) ;
}
}
static int F_205 ( struct V_13 * V_14 )
{
int V_36 = - V_295 ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_296 ) {
V_14 -> V_160 = V_297 ;
V_36 = 0 ;
}
F_150 ( & V_14 -> V_40 ) ;
return V_36 ;
}
void F_206 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_113 * V_113 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( F_205 ( V_14 ) ) {
F_154 ( V_14 ) ;
return;
}
F_207 ( L_13 ,
V_14 -> V_9 -> V_11 -> V_56 , & V_14 -> V_165 ) ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_58 & V_298 ) {
int V_171 = V_14 -> V_171 ;
T_1 V_58 = V_14 -> V_58 ;
struct V_167 V_299 ;
struct V_13 * V_300 ;
T_1 V_172 , V_301 ;
int V_170 = V_14 -> V_189 ;
int V_302 = V_14 -> V_303 + 1 ;
if ( V_302 > V_113 -> V_22 . V_304 . V_305 ) {
F_207 ( L_14 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
goto V_306;
}
V_299 = V_14 -> V_165 ;
if ( F_208 ( & V_299 , V_302 ,
V_9 ) )
goto V_306;
V_172 = V_14 -> V_172 ;
V_301 = V_14 -> V_173 ;
F_150 ( & V_14 -> V_40 ) ;
if ( V_9 -> V_43 . V_307 &&
F_195 ( V_9 ) >=
V_9 -> V_43 . V_307 )
goto V_308;
F_207 ( L_15 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_300 = F_121 ( V_9 , & V_299 , NULL , V_170 ,
V_171 , V_58 , V_172 ,
V_301 ) ;
if ( F_58 ( V_300 ) )
goto V_308;
F_149 ( & V_300 -> V_40 ) ;
V_300 -> V_303 = V_302 ;
V_300 -> V_160 = V_309 ;
F_150 ( & V_300 -> V_40 ) ;
F_20 ( V_300 , V_113 -> V_22 . V_304 . V_310 ) ;
F_154 ( V_300 ) ;
V_308:
F_149 ( & V_14 -> V_40 ) ;
}
V_306:
V_14 -> V_160 = V_311 ;
F_150 ( & V_14 -> V_40 ) ;
F_20 ( V_14 , 0 ) ;
F_154 ( V_14 ) ;
}
void F_209 ( struct V_10 * V_11 , const struct V_167 * V_165 )
{
struct V_167 V_312 ;
if ( V_11 -> V_58 & ( V_60 | V_59 ) )
return;
F_210 ( V_165 , & V_312 ) ;
F_54 ( V_11 , & V_312 ) ;
}
void F_211 ( struct V_8 * V_9 , const struct V_167 * V_165 )
{
struct V_167 V_312 ;
if ( V_9 -> V_11 -> V_58 & ( V_60 | V_59 ) )
return;
F_210 ( V_165 , & V_312 ) ;
F_212 ( V_9 , & V_312 ) ;
}
static void F_93 ( struct V_13 * V_14 )
{
struct V_167 V_165 ;
if ( V_14 -> V_189 >= 127 )
return;
F_213 ( & V_165 , & V_14 -> V_165 , V_14 -> V_189 ) ;
if ( F_214 ( & V_165 ) )
return;
F_215 ( V_14 -> V_9 , & V_165 ) ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_167 V_165 ;
if ( V_14 -> V_189 >= 127 )
return;
F_213 ( & V_165 , & V_14 -> V_165 , V_14 -> V_189 ) ;
if ( F_214 ( & V_165 ) )
return;
F_216 ( V_14 -> V_9 , & V_165 ) ;
}
static int F_217 ( T_5 * V_313 , struct V_10 * V_11 )
{
if ( V_11 -> V_314 != V_315 )
return - 1 ;
memcpy ( V_313 , V_11 -> V_316 , V_315 ) ;
V_313 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_218 ( T_5 * V_313 , struct V_10 * V_11 )
{
union V_317 * V_318 ;
if ( V_11 -> V_314 != V_319 )
return - 1 ;
V_318 = (union V_317 * ) V_11 -> V_316 ;
memcpy ( V_313 , & V_318 -> V_320 . V_321 , sizeof( V_318 -> V_320 . V_321 ) ) ;
V_313 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_219 ( T_5 * V_313 , struct V_10 * V_11 )
{
if ( V_11 -> V_314 != V_322 )
return - 1 ;
memset ( V_313 , 0 , 7 ) ;
V_313 [ 7 ] = * ( T_5 * ) V_11 -> V_316 ;
return 0 ;
}
static int F_220 ( T_5 * V_313 , struct V_10 * V_11 )
{
if ( V_11 -> V_314 != V_323 )
return - 1 ;
memcpy ( V_313 , V_11 -> V_316 + 12 , 8 ) ;
V_313 [ 0 ] |= 2 ;
return 0 ;
}
static int F_221 ( T_5 * V_313 , T_6 V_165 )
{
if ( V_165 == 0 )
return - 1 ;
V_313 [ 0 ] = ( F_222 ( V_165 ) || F_223 ( V_165 ) ||
F_224 ( V_165 ) || F_225 ( V_165 ) ||
F_226 ( V_165 ) || F_227 ( V_165 ) ||
F_228 ( V_165 ) || F_229 ( V_165 ) ||
F_230 ( V_165 ) || F_231 ( V_165 ) ||
F_232 ( V_165 ) ) ? 0x00 : 0x02 ;
V_313 [ 1 ] = 0 ;
V_313 [ 2 ] = 0x5E ;
V_313 [ 3 ] = 0xFE ;
memcpy ( V_313 + 4 , & V_165 , 4 ) ;
return 0 ;
}
static int F_233 ( T_5 * V_313 , struct V_10 * V_11 )
{
if ( V_11 -> V_64 & V_65 )
return F_221 ( V_313 , * ( T_6 * ) V_11 -> V_316 ) ;
return - 1 ;
}
static int F_234 ( T_5 * V_313 , struct V_10 * V_11 )
{
return F_221 ( V_313 , * ( T_6 * ) V_11 -> V_316 ) ;
}
static int F_235 ( T_5 * V_313 , struct V_10 * V_11 )
{
memcpy ( V_313 , V_11 -> V_324 , 3 ) ;
memcpy ( V_313 + 5 , V_11 -> V_324 + 3 , 3 ) ;
V_313 [ 3 ] = 0xFF ;
V_313 [ 4 ] = 0xFE ;
V_313 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_236 ( T_5 * V_313 , struct V_10 * V_11 )
{
switch ( V_11 -> type ) {
case V_325 :
case V_326 :
return F_237 ( V_313 , V_11 ) ;
case V_327 :
return F_219 ( V_313 , V_11 ) ;
case V_328 :
return F_220 ( V_313 , V_11 ) ;
case V_63 :
return F_233 ( V_313 , V_11 ) ;
case V_329 :
return F_234 ( V_313 , V_11 ) ;
case V_330 :
return F_217 ( V_313 , V_11 ) ;
case V_331 :
return F_218 ( V_313 , V_11 ) ;
case V_71 :
return F_235 ( V_313 , V_11 ) ;
}
return - 1 ;
}
static int F_238 ( T_5 * V_313 , struct V_8 * V_9 )
{
int V_36 = - 1 ;
struct V_13 * V_14 ;
F_181 ( & V_9 -> V_40 ) ;
F_193 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_171 > V_286 )
break;
if ( V_14 -> V_171 == V_286 && ! ( V_14 -> V_58 & V_149 ) ) {
memcpy ( V_313 , V_14 -> V_165 . V_225 + 8 , 8 ) ;
V_36 = 0 ;
break;
}
}
F_186 ( & V_9 -> V_40 ) ;
return V_36 ;
}
static void F_48 ( struct V_8 * V_9 )
{
V_332:
F_165 ( V_9 -> V_229 , sizeof( V_9 -> V_229 ) ) ;
V_9 -> V_229 [ 0 ] &= ~ 0x02 ;
if ( V_9 -> V_229 [ 0 ] == 0xfd &&
( V_9 -> V_229 [ 1 ] & V_9 -> V_229 [ 2 ] & V_9 -> V_229 [ 3 ] & V_9 -> V_229 [ 4 ] & V_9 -> V_229 [ 5 ] & V_9 -> V_229 [ 6 ] ) == 0xff &&
( V_9 -> V_229 [ 7 ] & 0x80 ) )
goto V_332;
if ( ( V_9 -> V_229 [ 0 ] | V_9 -> V_229 [ 1 ] ) == 0 ) {
if ( V_9 -> V_229 [ 2 ] == 0x5e && V_9 -> V_229 [ 3 ] == 0xfe )
goto V_332;
if ( ( V_9 -> V_229 [ 2 ] | V_9 -> V_229 [ 3 ] | V_9 -> V_229 [ 4 ] | V_9 -> V_229 [ 5 ] | V_9 -> V_229 [ 6 ] | V_9 -> V_229 [ 7 ] ) == 0x00 )
goto V_332;
}
}
static void F_160 ( struct V_8 * V_9 , struct V_167 * V_213 )
{
if ( V_213 && memcmp ( V_9 -> V_229 , & V_213 -> V_225 [ 8 ] , 8 ) == 0 )
F_48 ( V_9 ) ;
}
static void
F_239 ( struct V_167 * V_333 , int V_334 , struct V_10 * V_11 ,
unsigned long V_196 , T_1 V_58 )
{
struct V_335 V_336 = {
. V_337 = F_240 ( V_11 ) ? : V_338 ,
. V_339 = V_340 ,
. V_341 = V_11 -> V_96 ,
. V_342 = V_196 ,
. V_343 = V_334 ,
. V_344 = V_345 | V_58 ,
. V_346 . V_347 = F_38 ( V_11 ) ,
. V_348 = V_349 ,
} ;
V_336 . V_350 = * V_333 ;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 && ( V_11 -> V_58 & V_351 ) )
V_336 . V_344 |= V_352 ;
#endif
F_241 ( & V_336 ) ;
}
static struct V_174 * F_145 ( const struct V_167 * V_333 ,
int V_334 ,
const struct V_10 * V_11 ,
T_1 V_58 , T_1 V_353 )
{
struct V_354 * V_355 ;
struct V_174 * V_6 = NULL ;
struct V_356 * V_153 ;
T_1 V_357 = F_240 ( V_11 ) ? : V_338 ;
V_153 = F_242 ( F_38 ( V_11 ) , V_357 ) ;
if ( ! V_153 )
return NULL ;
F_181 ( & V_153 -> V_358 ) ;
V_355 = F_243 ( & V_153 -> V_359 , V_333 , V_334 , NULL , 0 ) ;
if ( ! V_355 )
goto V_187;
V_353 |= V_360 ;
for ( V_6 = V_355 -> V_361 ; V_6 ; V_6 = V_6 -> V_244 . V_362 ) {
if ( V_6 -> V_244 . V_11 -> V_96 != V_11 -> V_96 )
continue;
if ( ( V_6 -> V_207 & V_58 ) != V_58 )
continue;
if ( ( V_6 -> V_207 & V_353 ) != 0 )
continue;
F_244 ( & V_6 -> V_244 ) ;
break;
}
V_187:
F_186 ( & V_153 -> V_358 ) ;
return V_6 ;
}
static void F_245 ( struct V_10 * V_11 )
{
struct V_335 V_336 = {
. V_337 = F_240 ( V_11 ) ? : V_363 ,
. V_339 = V_340 ,
. V_341 = V_11 -> V_96 ,
. V_343 = 8 ,
. V_344 = V_345 ,
. V_346 . V_347 = F_38 ( V_11 ) ,
} ;
F_246 ( & V_336 . V_350 , F_247 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_241 ( & V_336 ) ;
}
static struct V_8 * F_248 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 )
return F_34 ( - V_114 ) ;
if ( V_9 -> V_43 . V_183 )
return F_34 ( - V_184 ) ;
if ( ! ( V_11 -> V_58 & V_60 ) && ! F_249 ( V_11 ) )
F_245 ( V_11 ) ;
return V_9 ;
}
static void F_250 ( struct V_8 * V_9 ,
struct V_13 * V_14 ,
V_233 V_172 , V_233 V_173 ,
bool V_364 , unsigned long V_222 )
{
T_1 V_58 ;
struct V_13 * V_212 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ift, &idev->tempaddr_list, tmp_list) {
int V_217 , V_365 , V_366 ;
if ( V_14 != V_212 -> V_209 )
continue;
V_217 = ( V_222 - V_212 -> V_1 ) / V_3 ;
V_365 = V_9 -> V_43 . V_234 - V_217 ;
if ( V_365 < 0 )
V_365 = 0 ;
V_366 = V_9 -> V_43 . V_232 -
V_9 -> V_68 - V_217 ;
if ( V_366 < 0 )
V_366 = 0 ;
if ( V_172 > V_365 )
V_172 = V_365 ;
if ( V_173 > V_366 )
V_173 = V_366 ;
F_124 ( & V_212 -> V_40 ) ;
V_58 = V_212 -> V_58 ;
V_212 -> V_172 = V_172 ;
V_212 -> V_173 = V_173 ;
V_212 -> V_78 = V_222 ;
if ( V_173 > 0 )
V_212 -> V_58 &= ~ V_255 ;
F_133 ( & V_212 -> V_40 ) ;
if ( ! ( V_58 & V_149 ) )
F_157 ( 0 , V_212 ) ;
}
if ( ( V_364 || F_251 ( & V_9 -> V_67 ) ) &&
V_9 -> V_43 . V_73 > 0 ) {
F_186 ( & V_9 -> V_40 ) ;
F_159 ( V_14 , NULL ) ;
} else {
F_186 ( & V_9 -> V_40 ) ;
}
}
static bool F_252 ( struct V_8 * V_9 )
{
return V_9 -> V_47 == V_48 ||
V_9 -> V_47 == V_367 ;
}
int F_253 ( struct V_113 * V_113 , struct V_10 * V_11 ,
const struct V_368 * V_369 ,
struct V_8 * V_123 ,
const struct V_167 * V_165 , int V_176 ,
T_1 V_221 , bool V_370 , bool V_190 ,
V_233 V_172 , T_1 V_173 )
{
struct V_13 * V_14 = F_202 ( V_113 , V_165 , V_11 , 1 ) ;
int V_364 = 0 , V_371 = 0 ;
if ( ! V_14 && V_172 ) {
int V_307 = V_123 -> V_43 . V_307 ;
#ifdef F_170
if ( V_123 -> V_43 . V_239 &&
! V_113 -> V_22 . V_126 -> V_53 && V_370 )
V_221 |= V_236 ;
#endif
if ( ! V_307 ||
F_195 ( V_123 ) < V_307 )
V_14 = F_121 ( V_123 , V_165 , NULL ,
V_369 -> V_189 ,
V_176 & V_372 ,
V_221 , V_172 ,
V_173 ) ;
if ( F_254 ( V_14 ) )
return - 1 ;
V_371 = 0 ;
V_364 = 1 ;
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 |= V_373 ;
V_14 -> V_1 = V_17 ;
V_14 -> V_190 = V_190 ;
F_150 ( & V_14 -> V_40 ) ;
F_167 ( V_14 ) ;
}
if ( V_14 ) {
T_1 V_58 ;
unsigned long V_222 ;
T_1 V_374 ;
F_149 ( & V_14 -> V_40 ) ;
V_222 = V_17 ;
if ( V_14 -> V_172 > ( V_222 - V_14 -> V_78 ) / V_3 )
V_374 = V_14 -> V_172 - ( V_222 - V_14 -> V_78 ) / V_3 ;
else
V_374 = 0 ;
if ( ! V_371 && ! V_364 && V_374 ) {
const T_1 V_375 = F_163 ( T_1 ,
V_374 , V_376 ) ;
V_172 = F_255 ( V_172 , V_375 ) ;
V_371 = 1 ;
}
if ( V_371 ) {
V_14 -> V_172 = V_172 ;
V_14 -> V_173 = V_173 ;
V_14 -> V_78 = V_222 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_255 ;
F_150 ( & V_14 -> V_40 ) ;
if ( ! ( V_58 & V_149 ) )
F_157 ( 0 , V_14 ) ;
} else
F_150 ( & V_14 -> V_40 ) ;
F_250 ( V_123 , V_14 , V_172 , V_173 ,
V_364 , V_222 ) ;
F_154 ( V_14 ) ;
F_256 () ;
}
return 0 ;
}
void F_257 ( struct V_10 * V_11 , T_5 * V_377 , int V_145 , bool V_370 )
{
struct V_368 * V_369 ;
V_233 V_172 ;
V_233 V_173 ;
int V_176 , V_36 ;
T_1 V_221 = 0 ;
struct V_8 * V_123 ;
struct V_113 * V_113 = F_38 ( V_11 ) ;
V_369 = (struct V_368 * ) V_377 ;
if ( V_145 < sizeof( struct V_368 ) ) {
F_42 ( L_16 ) ;
return;
}
V_176 = F_122 ( & V_369 -> V_378 ) ;
if ( V_176 & ( V_178 | V_379 ) )
return;
V_172 = F_258 ( V_369 -> V_380 ) ;
V_173 = F_258 ( V_369 -> V_381 ) ;
if ( V_173 > V_172 ) {
F_259 ( L_17 ) ;
return;
}
V_123 = F_260 ( V_11 ) ;
if ( ! V_123 ) {
F_183 ( L_18 ,
V_11 -> V_56 ) ;
return;
}
if ( V_369 -> V_291 ) {
struct V_174 * V_6 ;
unsigned long V_382 ;
if ( V_3 > V_383 )
V_382 = F_142 ( V_172 , V_3 ) ;
else
V_382 = F_142 ( V_172 , V_383 ) ;
if ( F_261 ( V_382 ) )
V_382 *= V_3 ;
V_6 = F_145 ( & V_369 -> V_378 ,
V_369 -> V_189 ,
V_11 ,
V_384 | V_385 ,
V_205 | V_206 ) ;
if ( V_6 ) {
if ( V_172 == 0 ) {
F_146 ( V_6 ) ;
V_6 = NULL ;
} else if ( F_261 ( V_382 ) ) {
F_147 ( V_6 , V_17 + V_382 ) ;
} else {
F_262 ( V_6 ) ;
}
} else if ( V_172 ) {
T_7 V_196 = 0 ;
int V_58 = V_384 | V_385 ;
if ( F_261 ( V_382 ) ) {
V_58 |= V_208 ;
V_196 = F_263 ( V_382 ) ;
}
F_239 ( & V_369 -> V_378 , V_369 -> V_189 ,
V_11 , V_196 , V_58 ) ;
}
F_111 ( V_6 ) ;
}
if ( V_369 -> V_386 && V_123 -> V_43 . V_386 ) {
struct V_167 V_165 ;
bool V_190 = false , V_387 = false ;
if ( V_369 -> V_189 == 64 ) {
memcpy ( & V_165 , & V_369 -> V_378 , 8 ) ;
if ( ! F_214 ( & V_123 -> V_74 ) ) {
F_181 ( & V_123 -> V_40 ) ;
memcpy ( V_165 . V_225 + 8 ,
V_123 -> V_74 . V_225 + 8 , 8 ) ;
F_186 ( & V_123 -> V_40 ) ;
V_190 = true ;
} else if ( F_252 ( V_123 ) &&
! F_208 ( & V_165 , 0 ,
V_123 ) ) {
V_221 |= V_298 ;
goto V_388;
} else if ( F_236 ( V_165 . V_225 + 8 , V_11 ) &&
F_238 ( V_165 . V_225 + 8 , V_123 ) ) {
goto V_389;
} else {
V_387 = true ;
}
goto V_388;
}
F_183 ( L_19 ,
V_369 -> V_189 ) ;
goto V_389;
V_388:
V_36 = F_253 ( V_113 , V_11 , V_369 , V_123 ,
& V_165 , V_176 ,
V_221 , V_370 ,
V_190 , V_172 ,
V_173 ) ;
if ( V_36 )
goto V_389;
F_264 ( V_113 , V_11 , V_369 , V_123 , & V_165 ,
V_176 , V_221 , V_370 ,
V_190 , V_172 ,
V_173 ,
V_387 ) ;
}
F_265 ( V_390 , V_123 , V_369 ) ;
V_389:
F_108 ( V_123 ) ;
}
int F_266 ( struct V_113 * V_113 , void T_8 * V_391 )
{
struct V_392 V_393 ;
struct V_10 * V_11 ;
int V_36 = - V_39 ;
F_267 () ;
V_36 = - V_394 ;
if ( F_268 ( & V_393 , V_391 , sizeof( struct V_392 ) ) )
goto V_395;
V_11 = F_80 ( V_113 , V_393 . V_396 ) ;
V_36 = - V_181 ;
if ( ! V_11 )
goto V_395;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 ) {
const struct V_397 * V_398 = V_11 -> V_399 ;
struct V_400 V_401 ;
struct V_402 V_154 ;
V_36 = - V_180 ;
if ( ! ( F_122 ( & V_393 . V_403 ) & V_238 ) )
goto V_395;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_404 . V_278 = V_393 . V_403 . V_405 [ 3 ] ;
V_154 . V_404 . V_279 = 0 ;
V_154 . V_404 . V_406 = 4 ;
V_154 . V_404 . V_407 = 5 ;
V_154 . V_404 . V_408 = V_409 ;
V_154 . V_404 . V_410 = 64 ;
V_401 . V_411 . V_412 = ( V_413 void T_8 * ) & V_154 ;
if ( V_398 -> V_414 ) {
T_9 V_415 = F_269 () ;
F_270 ( V_416 ) ;
V_36 = V_398 -> V_414 ( V_11 , & V_401 , V_417 ) ;
F_270 ( V_415 ) ;
} else
V_36 = - V_418 ;
if ( V_36 == 0 ) {
V_36 = - V_114 ;
V_11 = F_271 ( V_113 , V_154 . V_56 ) ;
if ( ! V_11 )
goto V_395;
V_36 = F_272 ( V_11 ) ;
}
}
#endif
V_395:
F_100 () ;
return V_36 ;
}
static int F_273 ( struct V_419 * V_119 , bool V_420 ,
const struct V_167 * V_165 , int V_96 )
{
int V_220 ;
F_33 () ;
F_274 ( V_119 ) ;
if ( V_420 )
V_220 = F_275 ( V_119 , V_96 , V_165 ) ;
else
V_220 = F_276 ( V_119 , V_96 , V_165 ) ;
F_277 ( V_119 ) ;
return V_220 ;
}
static int F_278 ( struct V_113 * V_113 , int V_96 ,
const struct V_167 * V_333 ,
const struct V_167 * V_421 ,
unsigned int V_334 , V_233 V_422 ,
V_233 V_173 , V_233 V_172 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned long V_423 ;
T_7 V_196 ;
int V_171 ;
T_1 V_58 ;
F_33 () ;
if ( V_334 > 128 )
return - V_39 ;
if ( ! V_172 || V_173 > V_172 )
return - V_39 ;
if ( V_422 & V_373 && V_334 != 64 )
return - V_39 ;
V_11 = F_80 ( V_113 , V_96 ) ;
if ( ! V_11 )
return - V_181 ;
V_9 = F_248 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_127 ( V_9 ) ;
if ( V_422 & V_424 ) {
int V_220 = F_273 ( V_113 -> V_22 . V_425 ,
true , V_333 , V_96 ) ;
if ( V_220 < 0 )
return V_220 ;
}
V_171 = F_166 ( V_333 ) ;
V_423 = F_142 ( V_172 , V_3 ) ;
if ( F_261 ( V_423 ) ) {
V_196 = F_263 ( V_423 * V_3 ) ;
V_172 = V_423 ;
V_58 = V_208 ;
} else {
V_196 = 0 ;
V_58 = 0 ;
V_422 |= V_200 ;
}
V_423 = F_142 ( V_173 , V_3 ) ;
if ( F_261 ( V_423 ) ) {
if ( V_423 == 0 )
V_422 |= V_255 ;
V_173 = V_423 ;
}
V_14 = F_121 ( V_9 , V_333 , V_421 , V_334 , V_171 , V_422 ,
V_172 , V_173 ) ;
if ( ! F_58 ( V_14 ) ) {
if ( ! ( V_422 & V_201 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_11 ,
V_196 , V_58 ) ;
}
F_167 ( V_14 ) ;
if ( V_422 & V_373 )
F_250 ( V_9 , V_14 , V_172 , V_173 ,
true , V_17 ) ;
F_154 ( V_14 ) ;
F_279 () ;
return 0 ;
} else if ( V_422 & V_424 ) {
F_273 ( V_113 -> V_22 . V_425 ,
false , V_333 , V_96 ) ;
}
return F_127 ( V_14 ) ;
}
static int F_280 ( struct V_113 * V_113 , int V_96 , T_1 V_422 ,
const struct V_167 * V_333 , unsigned int V_334 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_334 > 128 )
return - V_39 ;
V_11 = F_80 ( V_113 , V_96 ) ;
if ( ! V_11 )
return - V_181 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_426 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_189 == V_334 &&
F_173 ( V_333 , & V_14 -> V_165 ) ) {
F_22 ( V_14 ) ;
F_186 ( & V_9 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_192 ) &&
( V_422 & V_373 ) )
F_250 ( V_9 , V_14 , 0 , 0 , false ,
V_17 ) ;
F_148 ( V_14 ) ;
F_279 () ;
if ( F_281 ( V_333 ) ) {
F_273 ( V_113 -> V_22 . V_425 ,
false , V_333 , V_11 -> V_96 ) ;
}
return 0 ;
}
}
F_186 ( & V_9 -> V_40 ) ;
return - V_180 ;
}
int F_282 ( struct V_113 * V_113 , void T_8 * V_391 )
{
struct V_392 V_393 ;
int V_36 ;
if ( ! F_283 ( V_113 -> V_427 , V_428 ) )
return - V_429 ;
if ( F_268 ( & V_393 , V_391 , sizeof( struct V_392 ) ) )
return - V_394 ;
F_267 () ;
V_36 = F_278 ( V_113 , V_393 . V_396 , & V_393 . V_403 , NULL ,
V_393 . V_430 , V_200 ,
V_431 , V_431 ) ;
F_100 () ;
return V_36 ;
}
int F_284 ( struct V_113 * V_113 , void T_8 * V_391 )
{
struct V_392 V_393 ;
int V_36 ;
if ( ! F_283 ( V_113 -> V_427 , V_428 ) )
return - V_429 ;
if ( F_268 ( & V_393 , V_391 , sizeof( struct V_392 ) ) )
return - V_394 ;
F_267 () ;
V_36 = F_280 ( V_113 , V_393 . V_396 , 0 , & V_393 . V_403 ,
V_393 . V_430 ) ;
F_100 () ;
return V_36 ;
}
static void F_285 ( struct V_8 * V_9 , const struct V_167 * V_165 ,
int V_334 , int V_171 )
{
struct V_13 * V_14 ;
V_14 = F_121 ( V_9 , V_165 , NULL , V_334 ,
V_171 , V_200 ,
V_431 , V_431 ) ;
if ( ! F_58 ( V_14 ) ) {
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 &= ~ V_149 ;
F_150 ( & V_14 -> V_40 ) ;
F_286 ( F_38 ( V_9 -> V_11 ) ) ;
F_157 ( V_432 , V_14 ) ;
F_154 ( V_14 ) ;
}
}
static void F_287 ( struct V_8 * V_9 )
{
struct V_167 V_165 ;
struct V_10 * V_11 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
int V_171 , V_334 ;
T_1 V_433 = 0 ;
F_33 () ;
memset ( & V_165 , 0 , sizeof( struct V_167 ) ) ;
memcpy ( & V_165 . V_405 [ 3 ] , V_9 -> V_11 -> V_316 , 4 ) ;
if ( V_9 -> V_11 -> V_58 & V_351 ) {
V_165 . V_405 [ 0 ] = F_247 ( 0xfe800000 ) ;
V_171 = V_286 ;
V_334 = 64 ;
} else {
V_171 = V_238 ;
V_334 = 96 ;
V_433 |= V_352 ;
}
if ( V_165 . V_405 [ 3 ] ) {
F_285 ( V_9 , & V_165 , V_334 , V_171 ) ;
F_239 ( & V_165 , V_334 , V_9 -> V_11 , 0 , V_433 ) ;
return;
}
F_96 (net, dev) {
struct V_434 * V_435 = F_288 ( V_11 ) ;
if ( V_435 && ( V_11 -> V_58 & V_85 ) ) {
struct V_436 * V_146 ;
int V_437 = V_171 ;
for ( V_146 = V_435 -> V_438 ; V_146 ; V_146 = V_146 -> V_439 ) {
V_165 . V_405 [ 3 ] = V_146 -> V_440 ;
if ( V_146 -> V_441 == V_442 )
continue;
if ( V_146 -> V_441 >= V_443 ) {
if ( V_9 -> V_11 -> V_58 & V_351 )
continue;
V_437 |= V_290 ;
}
F_285 ( V_9 , & V_165 , V_334 , V_437 ) ;
F_239 ( & V_165 , V_334 , V_9 -> V_11 , 0 ,
V_433 ) ;
}
}
}
}
static void F_289 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_10 * V_444 ;
struct V_13 * V_445 ;
struct V_174 * V_446 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
F_285 ( V_9 , & V_447 , 128 , V_290 ) ;
F_96 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_444 -> V_56 , V_11 -> V_56 ) )
continue;
V_9 = F_57 ( V_444 ) ;
if ( ! V_9 )
continue;
F_181 ( & V_9 -> V_40 ) ;
F_92 (sp_ifa, &idev->addr_list, if_list) {
if ( V_445 -> V_58 & ( V_294 | V_149 ) )
continue;
if ( V_445 -> V_6 ) {
if ( ! F_85 ( & V_445 -> V_6 -> V_448 ) ) {
F_111 ( V_445 -> V_6 ) ;
V_445 -> V_6 = NULL ;
} else {
continue;
}
}
V_446 = F_126 ( V_9 , & V_445 -> V_165 , false ) ;
if ( ! F_58 ( V_446 ) ) {
V_445 -> V_6 = V_446 ;
F_290 ( V_446 ) ;
}
}
F_186 ( & V_9 -> V_40 ) ;
}
}
void F_291 ( struct V_8 * V_9 ,
const struct V_167 * V_165 , T_1 V_58 )
{
struct V_13 * V_14 ;
T_1 V_221 = V_58 | V_200 ;
#ifdef F_170
if ( V_9 -> V_43 . V_239 &&
! F_38 ( V_9 -> V_11 ) -> V_22 . V_126 -> V_53 )
V_221 |= V_236 ;
#endif
V_14 = F_121 ( V_9 , V_165 , NULL , 64 , V_286 , V_221 ,
V_431 , V_431 ) ;
if ( ! F_58 ( V_14 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_9 -> V_11 , 0 , 0 ) ;
F_167 ( V_14 ) ;
F_154 ( V_14 ) ;
}
}
static bool F_292 ( struct V_167 V_449 )
{
if ( ( V_449 . V_405 [ 2 ] | V_449 . V_405 [ 3 ] ) == 0 )
return true ;
if ( V_449 . V_405 [ 2 ] == F_247 ( 0x02005eff ) &&
( ( V_449 . V_405 [ 3 ] & F_247 ( 0xfe000000 ) ) == F_247 ( 0xfe000000 ) ) )
return true ;
if ( V_449 . V_405 [ 2 ] == F_247 ( 0xfdffffff ) &&
( ( V_449 . V_405 [ 3 ] & F_247 ( 0xffffff80 ) ) == F_247 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_208 ( struct V_167 * V_449 ,
T_5 V_450 ,
const struct V_8 * V_9 )
{
static F_293 ( V_40 ) ;
static V_233 V_451 [ V_452 ] ;
static V_233 V_453 [ V_454 ] ;
static union {
char V_455 [ V_456 ] ;
struct {
struct V_167 V_457 ;
T_6 V_378 [ 2 ] ;
unsigned char V_458 [ V_459 ] ;
T_5 V_450 ;
} V_460 ;
} V_461 ;
struct V_167 V_457 ;
struct V_167 V_462 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
F_294 ( sizeof( V_461 . V_455 ) != sizeof( V_461 ) ) ;
if ( V_9 -> V_43 . V_45 . V_46 )
V_457 = V_9 -> V_43 . V_45 . V_457 ;
else if ( V_113 -> V_22 . V_44 -> V_45 . V_46 )
V_457 = V_113 -> V_22 . V_44 -> V_45 . V_457 ;
else
return - 1 ;
V_226:
F_149 ( & V_40 ) ;
F_295 ( V_451 ) ;
memset ( & V_461 , 0 , sizeof( V_461 ) ) ;
memset ( V_453 , 0 , sizeof( V_453 ) ) ;
memcpy ( V_461 . V_458 , V_9 -> V_11 -> V_324 , V_9 -> V_11 -> V_314 ) ;
V_461 . V_378 [ 0 ] = V_449 -> V_405 [ 0 ] ;
V_461 . V_378 [ 1 ] = V_449 -> V_405 [ 1 ] ;
V_461 . V_457 = V_457 ;
V_461 . V_450 = V_450 ;
F_296 ( V_451 , V_461 . V_455 , V_453 ) ;
V_462 = * V_449 ;
V_462 . V_405 [ 2 ] = ( V_413 T_6 ) V_451 [ 0 ] ;
V_462 . V_405 [ 3 ] = ( V_413 T_6 ) V_451 [ 1 ] ;
F_150 ( & V_40 ) ;
if ( F_292 ( V_462 ) ) {
V_450 ++ ;
if ( V_450 > F_38 ( V_9 -> V_11 ) -> V_22 . V_304 . V_305 )
return - 1 ;
goto V_226;
}
* V_449 = V_462 ;
return 0 ;
}
static void F_297 ( struct V_8 * V_9 )
{
struct V_463 * V_464 = & V_9 -> V_43 . V_45 ;
if ( V_464 -> V_46 )
return;
V_464 = & V_9 -> V_43 . V_45 ;
F_165 ( & V_464 -> V_457 , sizeof( V_464 -> V_457 ) ) ;
V_464 -> V_46 = true ;
}
static void F_298 ( struct V_8 * V_9 , bool V_465 )
{
struct V_167 V_165 ;
if ( F_249 ( V_9 -> V_11 ) )
return;
F_246 ( & V_165 , F_247 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_9 -> V_47 ) {
case V_367 :
F_297 ( V_9 ) ;
case V_48 :
if ( ! F_208 ( & V_165 , 0 , V_9 ) )
F_291 ( V_9 , & V_165 ,
V_298 ) ;
else if ( V_465 )
F_239 ( & V_165 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_49 :
if ( F_236 ( V_165 . V_225 + 8 , V_9 -> V_11 ) == 0 )
F_291 ( V_9 , & V_165 , 0 ) ;
else if ( V_465 )
F_239 ( & V_165 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_466 :
default:
break;
}
}
static void F_299 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
if ( ( V_11 -> type != V_325 ) &&
( V_11 -> type != V_326 ) &&
( V_11 -> type != V_327 ) &&
( V_11 -> type != V_328 ) &&
( V_11 -> type != V_331 ) &&
( V_11 -> type != V_71 ) &&
( V_11 -> type != V_330 ) &&
( V_11 -> type != V_72 ) ) {
return;
}
V_9 = F_248 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return;
if ( V_11 -> type == V_72 &&
V_9 -> V_47 == V_49 )
V_9 -> V_47 = V_367 ;
F_298 ( V_9 , false ) ;
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
if ( V_11 -> V_64 & V_65 ) {
F_298 ( V_9 , false ) ;
return;
}
F_287 ( V_9 ) ;
if ( V_11 -> V_58 & V_351 )
F_245 ( V_11 ) ;
}
static void F_301 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
F_298 ( V_9 , true ) ;
if ( V_11 -> V_58 & V_351 )
F_245 ( V_11 ) ;
}
static int F_302 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_6 ) {
struct V_174 * V_6 ;
V_6 = F_126 ( V_9 , & V_14 -> V_165 , false ) ;
if ( F_164 ( F_58 ( V_6 ) ) )
return F_127 ( V_6 ) ;
V_14 -> V_6 = V_6 ;
}
if ( ! ( V_14 -> V_58 & V_201 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 ,
V_9 -> V_11 , 0 , 0 ) ;
}
F_167 ( V_14 ) ;
return 0 ;
}
static void F_303 ( struct V_10 * V_11 )
{
struct V_13 * V_14 , * V_5 ;
struct V_8 * V_9 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return;
F_152 ( & V_9 -> V_40 ) ;
F_304 (ifp, tmp, &idev->addr_list, if_list) {
if ( ( V_14 -> V_58 & V_200 ) &&
F_302 ( V_9 , V_14 ) < 0 ) {
F_156 ( & V_9 -> V_40 ) ;
F_148 ( V_14 ) ;
F_152 ( & V_9 -> V_40 ) ;
F_207 ( L_21 ,
V_9 -> V_11 -> V_56 , & V_14 -> V_165 ) ;
}
}
F_156 ( & V_9 -> V_40 ) ;
}
static int F_305 ( struct V_467 * V_468 , unsigned long V_101 ,
void * V_469 )
{
struct V_10 * V_11 = F_306 ( V_469 ) ;
struct V_470 * V_471 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
int V_472 = 0 ;
int V_36 ;
switch ( V_101 ) {
case V_473 :
if ( ! V_9 && V_11 -> V_37 >= V_38 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_307 ( F_127 ( V_9 ) ) ;
}
break;
case V_474 :
if ( V_11 -> V_37 < V_38 ) {
F_308 ( V_11 , 1 ) ;
break;
}
if ( V_9 ) {
F_309 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
break;
}
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
break;
if ( ! ( V_9 -> V_76 & V_77 ) )
break;
V_472 = 1 ;
case V_194 :
case V_475 :
if ( V_11 -> V_58 & V_476 )
break;
if ( V_9 && V_9 -> V_43 . V_183 )
break;
if ( V_101 == V_194 ) {
F_303 ( V_11 ) ;
if ( ! F_8 ( V_11 ) ) {
F_47 ( L_22 ,
V_11 -> V_56 ) ;
break;
}
if ( ! V_9 && V_11 -> V_37 >= V_38 )
V_9 = F_32 ( V_11 ) ;
if ( ! F_254 ( V_9 ) ) {
V_9 -> V_76 |= V_77 ;
V_472 = 1 ;
}
} else if ( V_101 == V_475 ) {
if ( ! F_8 ( V_11 ) ) {
break;
}
if ( V_9 ) {
if ( V_9 -> V_76 & V_77 )
break;
V_9 -> V_76 |= V_77 ;
}
F_47 ( L_23 ,
V_11 -> V_56 ) ;
V_472 = 1 ;
}
switch ( V_11 -> type ) {
#if F_46 ( V_62 )
case V_63 :
F_300 ( V_11 ) ;
break;
#endif
#if F_46 ( V_477 )
case V_329 :
F_301 ( V_11 ) ;
break;
#endif
case V_478 :
F_289 ( V_11 ) ;
break;
default:
F_299 ( V_11 ) ;
break;
}
if ( ! F_254 ( V_9 ) ) {
if ( V_472 )
F_310 ( V_9 ) ;
if ( V_9 -> V_43 . V_50 != V_11 -> V_37 &&
V_11 -> V_37 >= V_38 ) {
F_309 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
}
V_9 -> V_78 = V_17 ;
F_311 ( V_479 , V_9 ) ;
if ( V_11 -> V_37 < V_38 )
F_308 ( V_11 , 1 ) ;
}
break;
case V_211 :
case V_480 :
F_308 ( V_11 , V_101 != V_211 ) ;
break;
case V_481 :
if ( V_9 ) {
F_52 ( V_9 ) ;
F_7 ( V_9 ) ;
V_36 = F_6 ( V_9 ) ;
if ( V_36 )
return F_307 ( V_36 ) ;
V_36 = F_45 ( V_9 ) ;
if ( V_36 ) {
F_7 ( V_9 ) ;
return F_307 ( V_36 ) ;
}
}
break;
case V_482 :
case V_483 :
if ( V_9 )
F_312 ( V_11 , V_101 ) ;
break;
case V_484 :
V_471 = V_469 ;
if ( V_471 -> V_485 && F_249 ( V_471 -> V_485 ) )
F_308 ( V_11 , 0 ) ;
}
return V_486 ;
}
static void F_312 ( struct V_10 * V_11 , unsigned long V_101 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_101 == V_483 )
F_313 ( V_9 ) ;
else if ( V_101 == V_482 )
F_314 ( V_9 ) ;
}
static bool F_315 ( const struct V_167 * V_165 )
{
return F_122 ( V_165 ) &
( V_379 | V_179 ) ;
}
static int F_308 ( struct V_10 * V_11 , int V_487 )
{
struct V_113 * V_113 = F_38 ( V_11 ) ;
struct V_8 * V_9 ;
struct V_13 * V_146 , * V_5 ;
struct V_163 V_488 ;
int V_489 ;
bool V_490 ;
int V_160 , V_20 ;
F_33 () ;
F_316 ( V_113 , V_11 ) ;
F_317 ( & V_52 , V_11 ) ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_181 ;
if ( V_487 ) {
V_9 -> V_84 = 1 ;
F_318 ( V_11 -> V_79 , NULL ) ;
F_52 ( V_9 ) ;
}
V_489 = V_113 -> V_22 . V_126 -> V_491 ;
if ( ! V_489 )
V_489 = V_9 -> V_43 . V_491 ;
V_490 = ! ( V_487 || V_489 <= 0 || V_9 -> V_43 . V_183 ) ;
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ ) {
struct V_136 * V_132 = & V_191 [ V_20 ] ;
F_149 ( & V_185 ) ;
V_493:
F_86 (ifa, h, addr_lst) {
if ( V_146 -> V_9 == V_9 ) {
F_13 ( V_146 ) ;
if ( ! V_490 ||
! ( V_146 -> V_58 & V_200 ) ||
F_315 ( & V_146 -> V_165 ) ) {
F_151 ( & V_146 -> V_159 ) ;
goto V_493;
}
}
}
F_150 ( & V_185 ) ;
}
F_152 ( & V_9 -> V_40 ) ;
F_10 ( V_9 ) ;
if ( ! V_487 )
V_9 -> V_76 &= ~ ( V_494 | V_495 | V_77 ) ;
while ( ! F_251 ( & V_9 -> V_67 ) ) {
V_146 = F_319 ( & V_9 -> V_67 ,
struct V_13 , V_193 ) ;
F_153 ( & V_146 -> V_193 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_149 ( & V_146 -> V_40 ) ;
if ( V_146 -> V_209 ) {
F_154 ( V_146 -> V_209 ) ;
V_146 -> V_209 = NULL ;
}
F_150 ( & V_146 -> V_40 ) ;
F_154 ( V_146 ) ;
F_152 ( & V_9 -> V_40 ) ;
}
V_490 = ( ! V_487 && V_489 > 0 && ! V_9 -> V_43 . V_183 ) ;
F_36 ( & V_488 ) ;
F_304 (ifa, tmp, &idev->addr_list, if_list) {
struct V_174 * V_6 = NULL ;
F_13 ( V_146 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_149 ( & V_146 -> V_40 ) ;
if ( V_490 && ( V_146 -> V_58 & V_200 ) &&
! F_315 ( & V_146 -> V_165 ) ) {
V_160 = V_161 ;
V_146 -> V_160 = 0 ;
if ( ! ( V_146 -> V_58 & V_496 ) )
V_146 -> V_58 |= V_149 ;
V_6 = V_146 -> V_6 ;
V_146 -> V_6 = NULL ;
} else {
V_160 = V_146 -> V_160 ;
V_146 -> V_160 = V_161 ;
F_320 ( & V_146 -> V_166 , & V_488 ) ;
}
F_150 ( & V_146 -> V_40 ) ;
if ( V_6 )
F_146 ( V_6 ) ;
if ( V_160 != V_161 ) {
F_321 ( V_210 , V_146 ) ;
F_139 ( V_211 , V_146 ) ;
} else {
if ( V_9 -> V_43 . V_53 )
F_94 ( V_146 ) ;
F_211 ( V_146 -> V_9 , & V_146 -> V_165 ) ;
}
F_152 ( & V_9 -> V_40 ) ;
}
F_156 ( & V_9 -> V_40 ) ;
while ( ! F_251 ( & V_488 ) ) {
V_146 = F_319 ( & V_488 ,
struct V_13 , V_166 ) ;
F_153 ( & V_146 -> V_166 ) ;
F_154 ( V_146 ) ;
}
if ( V_487 ) {
F_322 ( V_9 ) ;
F_51 ( V_9 ) ;
} else {
F_323 ( V_9 ) ;
}
V_9 -> V_78 = V_17 ;
if ( V_487 ) {
F_7 ( V_9 ) ;
F_43 ( & V_52 , V_9 -> V_51 ) ;
F_317 ( & V_52 , V_11 ) ;
F_108 ( V_9 ) ;
}
return 0 ;
}
static void V_42 ( unsigned long V_461 )
{
struct V_8 * V_9 = (struct V_8 * ) V_461 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_167 V_497 ;
F_134 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_84 || ! ( V_9 -> V_76 & V_77 ) )
goto V_187;
if ( ! F_324 ( V_9 ) )
goto V_187;
if ( V_9 -> V_76 & V_495 )
goto V_187;
if ( V_9 -> V_498 ++ < V_9 -> V_43 . V_66 || V_9 -> V_43 . V_66 < 0 ) {
F_136 ( & V_9 -> V_40 ) ;
if ( ! F_194 ( V_11 , & V_497 , V_149 ) )
F_325 ( V_11 , & V_497 ,
& V_83 ) ;
else
goto V_389;
F_134 ( & V_9 -> V_40 ) ;
V_9 -> V_499 = F_5 (
V_9 -> V_499 , V_9 -> V_43 . V_500 ) ;
F_16 ( V_9 , ( V_9 -> V_498 ==
V_9 -> V_43 . V_66 ) ?
V_9 -> V_43 . V_501 :
V_9 -> V_499 ) ;
} else {
F_107 ( L_24 , V_9 -> V_11 -> V_56 ) ;
}
V_187:
F_136 ( & V_9 -> V_40 ) ;
V_389:
F_108 ( V_9 ) ;
}
static void F_326 ( struct V_13 * V_14 )
{
unsigned long V_502 ;
struct V_8 * V_9 = V_14 -> V_9 ;
if ( V_14 -> V_58 & V_236 )
V_502 = 0 ;
else
V_502 = F_3 () % ( V_9 -> V_43 . V_501 ? : 1 ) ;
V_14 -> V_503 = V_9 -> V_43 . V_230 ;
F_20 ( V_14 , V_502 ) ;
}
static void F_327 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_504 , V_505 = false ;
F_209 ( V_11 , & V_14 -> V_165 ) ;
F_328 ( ( V_413 T_1 ) V_14 -> V_165 . V_405 [ 3 ] ) ;
F_181 ( & V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_161 )
goto V_187;
if ( V_11 -> V_58 & ( V_59 | V_60 ) ||
V_9 -> V_43 . V_61 < 1 ||
! ( V_14 -> V_58 & V_149 ) ||
V_14 -> V_58 & V_496 ) {
V_504 = V_14 -> V_58 & V_149 ;
V_14 -> V_58 &= ~ ( V_149 | V_236 | V_294 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_186 ( & V_9 -> V_40 ) ;
F_329 ( V_14 , V_504 ) ;
return;
}
if ( ! ( V_9 -> V_76 & V_77 ) ) {
F_133 ( & V_14 -> V_40 ) ;
F_186 ( & V_9 -> V_40 ) ;
F_22 ( V_14 ) ;
F_204 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_58 & V_236 ) {
F_290 ( V_14 -> V_6 ) ;
if ( F_169 ( V_9 ) ) {
V_505 = true ;
}
}
F_326 ( V_14 ) ;
V_187:
F_133 ( & V_14 -> V_40 ) ;
F_186 ( & V_9 -> V_40 ) ;
if ( V_505 )
F_157 ( V_432 , V_14 ) ;
}
static void F_167 ( struct V_13 * V_14 )
{
bool V_506 = false ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 != V_161 ) {
V_14 -> V_160 = V_309 ;
V_506 = true ;
}
F_150 ( & V_14 -> V_40 ) ;
if ( V_506 )
F_20 ( V_14 , 0 ) ;
}
static void V_188 ( struct V_507 * V_508 )
{
struct V_13 * V_14 = F_330 ( F_331 ( V_508 ) ,
struct V_13 ,
V_15 ) ;
struct V_8 * V_9 = V_14 -> V_9 ;
bool V_504 , V_183 = false ;
struct V_167 V_509 ;
enum {
V_510 ,
V_511 ,
V_512 ,
} V_198 = V_510 ;
F_267 () ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_309 ) {
V_198 = V_511 ;
V_14 -> V_160 = V_296 ;
} else if ( V_14 -> V_160 == V_311 ) {
V_198 = V_512 ;
V_14 -> V_160 = V_297 ;
if ( V_9 -> V_43 . V_61 > 1 && ! V_9 -> V_43 . V_183 &&
! ( V_14 -> V_58 & V_298 ) ) {
struct V_167 V_165 ;
V_165 . V_405 [ 0 ] = F_247 ( 0xfe800000 ) ;
V_165 . V_405 [ 1 ] = 0 ;
if ( ! F_236 ( V_165 . V_225 + 8 , V_9 -> V_11 ) &&
F_173 ( & V_14 -> V_165 , & V_165 ) ) {
V_9 -> V_43 . V_183 = 1 ;
F_47 ( L_25 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
V_183 = true ;
}
}
}
F_150 ( & V_14 -> V_40 ) ;
if ( V_198 == V_511 ) {
F_327 ( V_14 ) ;
goto V_187;
} else if ( V_198 == V_512 ) {
F_22 ( V_14 ) ;
F_204 ( V_14 , 1 ) ;
if ( V_183 )
F_308 ( V_9 -> V_11 , 0 ) ;
goto V_187;
}
if ( ! V_14 -> V_503 && F_205 ( V_14 ) )
goto V_187;
F_152 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_84 || ! ( V_9 -> V_76 & V_77 ) ) {
F_156 ( & V_9 -> V_40 ) ;
goto V_187;
}
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_161 ) {
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
goto V_187;
}
if ( V_14 -> V_503 == 0 ) {
V_504 = V_14 -> V_58 & V_149 ;
V_14 -> V_58 &= ~ ( V_149 | V_236 | V_294 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_329 ( V_14 , V_504 ) ;
goto V_187;
}
V_14 -> V_503 -- ;
F_20 ( V_14 ,
F_161 ( V_14 -> V_9 -> V_51 , V_231 ) ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_210 ( & V_14 -> V_165 , & V_509 ) ;
F_332 ( V_14 -> V_9 -> V_11 , & V_14 -> V_165 , & V_509 , & V_75 ) ;
V_187:
F_154 ( V_14 ) ;
F_100 () ;
}
static bool F_333 ( struct V_13 * V_14 )
{
struct V_13 * V_513 ;
struct V_8 * V_9 = V_14 -> V_9 ;
F_193 (ifpiter, &idev->addr_list, if_list) {
if ( V_513 -> V_171 > V_286 )
break;
if ( V_14 != V_513 && V_513 -> V_171 == V_286 &&
( V_513 -> V_58 & ( V_200 | V_149 |
V_236 | V_294 ) ) ==
V_200 )
return false ;
}
return true ;
}
static void F_329 ( struct V_13 * V_14 , bool V_504 )
{
struct V_10 * V_11 = V_14 -> V_9 -> V_11 ;
struct V_167 V_497 ;
bool V_514 , V_515 ;
F_13 ( V_14 ) ;
F_157 ( V_432 , V_14 ) ;
F_181 ( & V_14 -> V_9 -> V_40 ) ;
V_515 = V_14 -> V_171 == V_286 && F_333 ( V_14 ) ;
V_514 = V_515 &&
F_324 ( V_14 -> V_9 ) &&
V_14 -> V_9 -> V_43 . V_66 != 0 &&
( V_11 -> V_58 & V_60 ) == 0 ;
F_186 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_515 )
F_334 ( V_14 -> V_9 ) ;
if ( V_514 ) {
if ( F_194 ( V_11 , & V_497 , V_149 ) )
return;
F_325 ( V_11 , & V_497 , & V_83 ) ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
V_14 -> V_9 -> V_499 = F_2 (
V_14 -> V_9 -> V_43 . V_516 ) ;
V_14 -> V_9 -> V_498 = 1 ;
V_14 -> V_9 -> V_76 |= V_494 ;
F_16 ( V_14 -> V_9 , V_14 -> V_9 -> V_499 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_14 -> V_9 -> V_40 ) ;
}
if ( V_504 )
F_286 ( F_38 ( V_11 ) ) ;
}
static void F_310 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list) {
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_58 & V_149 &&
V_14 -> V_160 == V_296 )
F_326 ( V_14 ) ;
F_133 ( & V_14 -> V_40 ) ;
}
F_186 ( & V_9 -> V_40 ) ;
}
static struct V_13 * F_335 ( struct V_517 * V_100 , T_10 V_518 )
{
struct V_13 * V_146 = NULL ;
struct V_519 * V_160 = V_100 -> V_520 ;
struct V_113 * V_113 = F_336 ( V_100 ) ;
int V_154 = 0 ;
if ( V_518 == 0 ) {
V_160 -> V_521 = 0 ;
V_160 -> V_522 = 0 ;
}
for (; V_160 -> V_521 < V_492 ; ++ V_160 -> V_521 ) {
F_203 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
if ( V_154 < V_160 -> V_522 ) {
V_154 ++ ;
continue;
}
V_160 -> V_522 ++ ;
return V_146 ;
}
V_160 -> V_522 = 0 ;
V_154 = 0 ;
}
return NULL ;
}
static struct V_13 * F_337 ( struct V_517 * V_100 ,
struct V_13 * V_146 )
{
struct V_519 * V_160 = V_100 -> V_520 ;
struct V_113 * V_113 = F_336 ( V_100 ) ;
F_338 (ifa, addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
V_160 -> V_522 ++ ;
return V_146 ;
}
while ( ++ V_160 -> V_521 < V_492 ) {
V_160 -> V_522 = 0 ;
F_203 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
V_160 -> V_522 ++ ;
return V_146 ;
}
}
return NULL ;
}
static void * F_339 ( struct V_517 * V_100 , T_10 * V_518 )
__acquires( T_11 )
{
F_123 () ;
return F_335 ( V_100 , * V_518 ) ;
}
static void * F_340 ( struct V_517 * V_100 , void * V_523 , T_10 * V_518 )
{
struct V_13 * V_146 ;
V_146 = F_337 ( V_100 , V_523 ) ;
++ * V_518 ;
return V_146 ;
}
static void F_341 ( struct V_517 * V_100 , void * V_523 )
__releases( T_11 )
{
F_137 () ;
}
static int F_342 ( struct V_517 * V_100 , void * V_523 )
{
struct V_13 * V_14 = (struct V_13 * ) V_523 ;
F_343 ( V_100 , L_26 ,
& V_14 -> V_165 ,
V_14 -> V_9 -> V_11 -> V_96 ,
V_14 -> V_189 ,
V_14 -> V_171 ,
( T_5 ) V_14 -> V_58 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
return 0 ;
}
static int F_344 ( struct V_524 * V_524 , struct V_525 * V_525 )
{
return F_345 ( V_524 , V_525 , & V_526 ,
sizeof( struct V_519 ) ) ;
}
static int T_12 F_346 ( struct V_113 * V_113 )
{
if ( ! F_347 ( L_27 , V_527 , V_113 -> V_528 , & V_529 ) )
return - V_34 ;
return 0 ;
}
static void T_13 F_348 ( struct V_113 * V_113 )
{
F_349 ( L_27 , V_113 -> V_528 ) ;
}
int T_14 F_350 ( void )
{
return F_351 ( & V_530 ) ;
}
void F_352 ( void )
{
F_353 ( & V_530 ) ;
}
int F_354 ( struct V_113 * V_113 , const struct V_167 * V_165 )
{
int V_220 = 0 ;
struct V_13 * V_14 = NULL ;
unsigned int V_175 = F_118 ( V_165 ) ;
F_123 () ;
F_203 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_198 ( F_38 ( V_14 -> V_9 -> V_11 ) , V_113 ) )
continue;
if ( F_173 ( & V_14 -> V_165 , V_165 ) &&
( V_14 -> V_58 & V_260 ) ) {
V_220 = 1 ;
break;
}
}
F_137 () ;
return V_220 ;
}
static void F_279 ( void )
{
unsigned long V_222 , V_531 , V_532 , V_533 ;
struct V_13 * V_14 ;
int V_20 ;
F_33 () ;
F_123 () ;
V_222 = V_17 ;
V_531 = F_355 ( V_222 + V_534 ) ;
F_14 ( & V_535 ) ;
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ ) {
V_493:
F_203 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_217 ;
if ( ( V_14 -> V_58 & V_200 ) &&
( V_14 -> V_173 == V_431 ) )
continue;
F_124 ( & V_14 -> V_40 ) ;
V_217 = ( V_222 - V_14 -> V_78 + V_235 ) / V_3 ;
if ( V_14 -> V_172 != V_431 &&
V_217 >= V_14 -> V_172 ) {
F_133 ( & V_14 -> V_40 ) ;
F_22 ( V_14 ) ;
F_148 ( V_14 ) ;
goto V_493;
} else if ( V_14 -> V_173 == V_431 ) {
F_133 ( & V_14 -> V_40 ) ;
continue;
} else if ( V_217 >= V_14 -> V_173 ) {
int V_536 = 0 ;
if ( ! ( V_14 -> V_58 & V_255 ) ) {
V_536 = 1 ;
V_14 -> V_58 |= V_255 ;
}
if ( ( V_14 -> V_172 != V_431 ) &&
( F_143 ( V_14 -> V_78 + V_14 -> V_172 * V_3 , V_531 ) ) )
V_531 = V_14 -> V_78 + V_14 -> V_172 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
if ( V_536 ) {
F_22 ( V_14 ) ;
F_157 ( 0 , V_14 ) ;
F_154 ( V_14 ) ;
goto V_493;
}
} else if ( ( V_14 -> V_58 & V_192 ) &&
! ( V_14 -> V_58 & V_149 ) ) {
unsigned long V_218 = V_14 -> V_9 -> V_43 . V_228 *
V_14 -> V_9 -> V_43 . V_230 *
F_161 ( V_14 -> V_9 -> V_51 , V_231 ) / V_3 ;
if ( V_217 >= V_14 -> V_173 - V_218 ) {
struct V_13 * V_209 = V_14 -> V_209 ;
if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 , V_531 ) )
V_531 = V_14 -> V_78 + V_14 -> V_173 * V_3 ;
if ( ! V_14 -> V_227 && V_209 ) {
V_14 -> V_227 ++ ;
F_22 ( V_14 ) ;
F_22 ( V_209 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_124 ( & V_209 -> V_40 ) ;
V_209 -> V_227 = 0 ;
F_133 ( & V_209 -> V_40 ) ;
F_159 ( V_209 , V_14 ) ;
F_154 ( V_209 ) ;
F_154 ( V_14 ) ;
goto V_493;
}
} else if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 - V_218 * V_3 , V_531 ) )
V_531 = V_14 -> V_78 + V_14 -> V_173 * V_3 - V_218 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
} else {
if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 , V_531 ) )
V_531 = V_14 -> V_78 + V_14 -> V_173 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
}
}
}
V_532 = F_355 ( V_531 ) ;
V_533 = V_531 ;
if ( F_143 ( V_532 , V_531 + V_537 ) )
V_533 = V_532 ;
if ( F_143 ( V_533 , V_17 + V_538 ) )
V_533 = V_17 + V_538 ;
F_42 ( V_539 L_28 ,
V_222 , V_531 , V_532 , V_533 ) ;
F_23 ( V_19 , & V_535 , V_533 - V_222 ) ;
F_137 () ;
}
static void F_356 ( struct V_507 * V_508 )
{
F_267 () ;
F_279 () ;
F_100 () ;
}
static void F_256 ( void )
{
F_23 ( V_19 , & V_535 , 0 ) ;
}
static struct V_167 * F_357 ( struct V_120 * V_165 , struct V_120 * V_540 ,
struct V_167 * * V_421 )
{
struct V_167 * V_333 = NULL ;
* V_421 = NULL ;
if ( V_165 )
V_333 = F_358 ( V_165 ) ;
if ( V_540 ) {
if ( V_333 && F_359 ( V_540 , V_333 , sizeof( * V_333 ) ) )
* V_421 = V_333 ;
V_333 = F_358 ( V_540 ) ;
}
return V_333 ;
}
static int
F_360 ( struct V_94 * V_95 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
struct V_541 * V_542 ;
struct V_120 * V_121 [ V_543 + 1 ] ;
struct V_167 * V_333 , * V_421 ;
T_1 V_422 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_542 ) , V_121 , V_543 , V_544 ) ;
if ( V_36 < 0 )
return V_36 ;
V_542 = F_66 ( V_103 ) ;
V_333 = F_357 ( V_121 [ V_545 ] , V_121 [ V_546 ] , & V_421 ) ;
if ( ! V_333 )
return - V_39 ;
V_422 = V_121 [ V_547 ] ? F_361 ( V_121 [ V_547 ] ) : V_542 -> V_422 ;
V_422 &= V_373 ;
return F_280 ( V_113 , V_542 -> V_548 , V_422 , V_333 ,
V_542 -> V_549 ) ;
}
static int F_362 ( struct V_13 * V_14 , T_1 V_422 ,
T_1 V_173 , T_1 V_172 )
{
T_1 V_58 ;
T_7 V_196 ;
unsigned long V_423 ;
bool V_550 ;
bool V_551 ;
F_33 () ;
if ( ! V_172 || ( V_173 > V_172 ) )
return - V_39 ;
if ( V_422 & V_373 &&
( V_14 -> V_58 & V_192 || V_14 -> V_189 != 64 ) )
return - V_39 ;
V_423 = F_142 ( V_172 , V_3 ) ;
if ( F_261 ( V_423 ) ) {
V_196 = F_263 ( V_423 * V_3 ) ;
V_172 = V_423 ;
V_58 = V_208 ;
} else {
V_196 = 0 ;
V_58 = 0 ;
V_422 |= V_200 ;
}
V_423 = F_142 ( V_173 , V_3 ) ;
if ( F_261 ( V_423 ) ) {
if ( V_423 == 0 )
V_422 |= V_255 ;
V_173 = V_423 ;
}
F_149 ( & V_14 -> V_40 ) ;
V_550 = V_14 -> V_58 & V_373 ;
V_551 = V_14 -> V_58 & V_200 &&
! ( V_14 -> V_58 & V_201 ) ;
V_14 -> V_58 &= ~ ( V_255 | V_200 | V_496 |
V_260 | V_373 |
V_201 ) ;
V_14 -> V_58 |= V_422 ;
V_14 -> V_78 = V_17 ;
V_14 -> V_172 = V_172 ;
V_14 -> V_173 = V_173 ;
F_150 ( & V_14 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_149 ) )
F_157 ( 0 , V_14 ) ;
if ( ! ( V_422 & V_201 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_14 -> V_9 -> V_11 ,
V_196 , V_58 ) ;
} else if ( V_551 ) {
enum V_195 V_198 ;
unsigned long V_382 ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
V_198 = F_140 ( V_14 , & V_382 ) ;
F_156 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_198 != V_202 ) {
F_144 ( V_14 , V_382 ,
V_198 == V_199 ) ;
}
}
if ( V_550 || V_14 -> V_58 & V_373 ) {
if ( V_550 && ! ( V_14 -> V_58 & V_373 ) )
V_172 = V_173 = 0 ;
F_250 ( V_14 -> V_9 , V_14 , V_172 , V_173 ,
! V_550 , V_17 ) ;
}
F_279 () ;
return 0 ;
}
static int
F_363 ( struct V_94 * V_95 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
struct V_541 * V_542 ;
struct V_120 * V_121 [ V_543 + 1 ] ;
struct V_167 * V_333 , * V_421 ;
struct V_13 * V_146 ;
struct V_10 * V_11 ;
T_1 V_172 = V_431 , V_301 = V_431 ;
T_1 V_422 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_542 ) , V_121 , V_543 , V_544 ) ;
if ( V_36 < 0 )
return V_36 ;
V_542 = F_66 ( V_103 ) ;
V_333 = F_357 ( V_121 [ V_545 ] , V_121 [ V_546 ] , & V_421 ) ;
if ( ! V_333 )
return - V_39 ;
if ( V_121 [ V_552 ] ) {
struct V_553 * V_554 ;
V_554 = F_358 ( V_121 [ V_552 ] ) ;
V_172 = V_554 -> V_555 ;
V_301 = V_554 -> V_556 ;
} else {
V_301 = V_431 ;
V_172 = V_431 ;
}
V_11 = F_80 ( V_113 , V_542 -> V_548 ) ;
if ( ! V_11 )
return - V_181 ;
V_422 = V_121 [ V_547 ] ? F_361 ( V_121 [ V_547 ] ) : V_542 -> V_422 ;
V_422 &= V_496 | V_260 | V_373 |
V_201 | V_424 ;
V_146 = F_202 ( V_113 , V_333 , V_11 , 1 ) ;
if ( ! V_146 ) {
return F_278 ( V_113 , V_542 -> V_548 , V_333 , V_421 ,
V_542 -> V_549 , V_422 ,
V_301 , V_172 ) ;
}
if ( V_103 -> V_557 & V_558 ||
! ( V_103 -> V_557 & V_559 ) )
V_36 = - V_186 ;
else
V_36 = F_362 ( V_146 , V_422 , V_301 , V_172 ) ;
F_154 ( V_146 ) ;
return V_36 ;
}
static void F_364 ( struct V_102 * V_103 , T_5 V_560 , T_1 V_58 ,
T_5 V_171 , int V_96 )
{
struct V_541 * V_542 ;
V_542 = F_66 ( V_103 ) ;
V_542 -> V_561 = V_107 ;
V_542 -> V_549 = V_560 ;
V_542 -> V_422 = V_58 ;
V_542 -> V_441 = V_171 ;
V_542 -> V_548 = V_96 ;
}
static int F_365 ( struct V_94 * V_95 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_562 , T_1 V_380 )
{
struct V_553 V_554 ;
V_554 . V_1 = F_1 ( V_1 ) ;
V_554 . V_78 = F_1 ( V_78 ) ;
V_554 . V_556 = V_562 ;
V_554 . V_555 = V_380 ;
return F_366 ( V_95 , V_552 , sizeof( V_554 ) , & V_554 ) ;
}
static inline int F_367 ( int V_441 )
{
if ( V_441 & V_290 )
return V_443 ;
else if ( V_441 & V_286 )
return V_442 ;
else if ( V_441 & V_563 )
return V_564 ;
else
return V_565 ;
}
static inline int F_368 ( void )
{
return F_61 ( sizeof( struct V_541 ) )
+ F_62 ( 16 )
+ F_62 ( 16 )
+ F_62 ( sizeof( struct V_553 ) )
+ F_62 ( 4 ) ;
}
static int F_369 ( struct V_94 * V_95 , struct V_13 * V_146 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_1 V_562 , V_380 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_541 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , V_146 -> V_189 , V_146 -> V_58 , F_367 ( V_146 -> V_171 ) ,
V_146 -> V_9 -> V_11 -> V_96 ) ;
if ( ! ( ( V_146 -> V_58 & V_200 ) &&
( V_146 -> V_173 == V_431 ) ) ) {
V_562 = V_146 -> V_173 ;
V_380 = V_146 -> V_172 ;
if ( V_562 != V_431 ) {
long V_566 = ( V_17 - V_146 -> V_78 ) / V_3 ;
if ( V_562 > V_566 )
V_562 -= V_566 ;
else
V_562 = 0 ;
if ( V_380 != V_431 ) {
if ( V_380 > V_566 )
V_380 -= V_566 ;
else
V_380 = 0 ;
}
}
} else {
V_562 = V_431 ;
V_380 = V_431 ;
}
if ( ! F_214 ( & V_146 -> V_169 ) ) {
if ( F_370 ( V_95 , V_546 , & V_146 -> V_165 ) < 0 ||
F_370 ( V_95 , V_545 , & V_146 -> V_169 ) < 0 )
goto error;
} else
if ( F_370 ( V_95 , V_545 , & V_146 -> V_165 ) < 0 )
goto error;
if ( F_365 ( V_95 , V_146 -> V_1 , V_146 -> V_78 , V_562 , V_380 ) < 0 )
goto error;
if ( F_371 ( V_95 , V_547 , V_146 -> V_58 ) < 0 )
goto error;
F_68 ( V_95 , V_103 ) ;
return 0 ;
error:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_372 ( struct V_94 * V_95 , struct V_567 * V_568 ,
T_1 V_99 , T_1 V_100 , int V_101 , T_15 V_58 )
{
struct V_102 * V_103 ;
T_5 V_171 = V_565 ;
int V_96 = V_568 -> V_9 -> V_11 -> V_96 ;
if ( F_166 ( & V_568 -> V_569 ) & V_563 )
V_171 = V_564 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_541 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , 128 , V_200 , V_171 , V_96 ) ;
if ( F_370 ( V_95 , V_570 , & V_568 -> V_569 ) < 0 ||
F_365 ( V_95 , V_568 -> V_571 , V_568 -> V_572 ,
V_431 , V_431 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_373 ( struct V_94 * V_95 , struct V_573 * V_574 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_5 V_171 = V_565 ;
int V_96 = V_574 -> V_575 -> V_11 -> V_96 ;
if ( F_166 ( & V_574 -> V_576 ) & V_563 )
V_171 = V_564 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_541 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , 128 , V_200 , V_171 , V_96 ) ;
if ( F_370 ( V_95 , V_577 , & V_574 -> V_576 ) < 0 ||
F_365 ( V_95 , V_574 -> V_578 , V_574 -> V_579 ,
V_431 , V_431 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_374 ( struct V_8 * V_9 , struct V_94 * V_95 ,
struct V_130 * V_131 , enum V_580 type ,
int V_581 , int * V_582 )
{
struct V_567 * V_568 ;
struct V_573 * V_574 ;
int V_36 = 1 ;
int V_583 = * V_582 ;
F_181 ( & V_9 -> V_40 ) ;
switch ( type ) {
case V_584 : {
struct V_13 * V_146 ;
F_92 (ifa, &idev->addr_list, if_list) {
if ( ++ V_583 < V_581 )
continue;
V_36 = F_369 ( V_95 , V_146 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_432 ,
V_143 ) ;
if ( V_36 < 0 )
break;
F_88 ( V_131 , F_89 ( V_95 ) ) ;
}
break;
}
case V_585 :
for ( V_568 = V_9 -> V_586 ; V_568 ;
V_568 = V_568 -> V_531 , V_583 ++ ) {
if ( V_583 < V_581 )
continue;
V_36 = F_372 ( V_95 , V_568 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_587 ,
V_143 ) ;
if ( V_36 < 0 )
break;
}
break;
case V_588 :
for ( V_574 = V_9 -> V_589 ; V_574 ;
V_574 = V_574 -> V_590 , V_583 ++ ) {
if ( V_583 < V_581 )
continue;
V_36 = F_373 ( V_95 , V_574 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_591 ,
V_143 ) ;
if ( V_36 < 0 )
break;
}
break;
default:
break;
}
F_186 ( & V_9 -> V_40 ) ;
* V_582 = V_583 ;
return V_36 ;
}
static int F_375 ( struct V_94 * V_95 , struct V_130 * V_131 ,
enum V_580 type )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
int V_132 , V_133 ;
int V_134 , V_583 ;
int V_135 , V_581 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_136 * V_137 ;
V_133 = V_131 -> args [ 0 ] ;
V_135 = V_134 = V_131 -> args [ 1 ] ;
V_581 = V_583 = V_131 -> args [ 2 ] ;
F_84 () ;
V_131 -> V_100 = F_85 ( & V_113 -> V_22 . V_140 ) ^ V_113 -> V_141 ;
for ( V_132 = V_133 ; V_132 < V_138 ; V_132 ++ , V_135 = 0 ) {
V_134 = 0 ;
V_137 = & V_113 -> V_139 [ V_132 ] ;
F_86 (dev, head, index_hlist) {
if ( V_134 < V_135 )
goto V_142;
if ( V_132 > V_133 || V_134 > V_135 )
V_581 = 0 ;
V_583 = 0 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_142;
if ( F_374 ( V_9 , V_95 , V_131 , type ,
V_581 , & V_583 ) < 0 )
goto V_144;
V_142:
V_134 ++ ;
}
}
V_144:
F_87 () ;
V_131 -> args [ 0 ] = V_132 ;
V_131 -> args [ 1 ] = V_134 ;
V_131 -> args [ 2 ] = V_583 ;
return V_95 -> V_145 ;
}
static int F_376 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_580 type = V_584 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_377 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_580 type = V_585 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_378 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_580 type = V_588 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_379 ( struct V_94 * V_118 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_118 -> V_119 ) ;
struct V_541 * V_542 ;
struct V_120 * V_121 [ V_543 + 1 ] ;
struct V_167 * V_165 = NULL , * V_592 ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_146 ;
struct V_94 * V_95 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_542 ) , V_121 , V_543 , V_544 ) ;
if ( V_36 < 0 )
goto V_115;
V_165 = F_357 ( V_121 [ V_545 ] , V_121 [ V_546 ] , & V_592 ) ;
if ( ! V_165 ) {
V_36 = - V_39 ;
goto V_115;
}
V_542 = F_66 ( V_103 ) ;
if ( V_542 -> V_548 )
V_11 = F_80 ( V_113 , V_542 -> V_548 ) ;
V_146 = F_202 ( V_113 , V_165 , V_11 , 1 ) ;
if ( ! V_146 ) {
V_36 = - V_180 ;
goto V_115;
}
V_95 = F_71 ( F_368 () , V_29 ) ;
if ( ! V_95 ) {
V_36 = - V_114 ;
goto V_593;
}
V_36 = F_369 ( V_95 , V_146 , F_81 ( V_118 ) . V_99 ,
V_103 -> V_129 , V_432 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_593;
}
V_36 = F_82 ( V_95 , V_113 , F_81 ( V_118 ) . V_99 ) ;
V_593:
F_154 ( V_146 ) ;
V_115:
return V_36 ;
}
static void F_380 ( int V_101 , struct V_13 * V_146 )
{
struct V_94 * V_95 ;
struct V_113 * V_113 = F_38 ( V_146 -> V_9 -> V_11 ) ;
int V_36 = - V_114 ;
V_95 = F_71 ( F_368 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_369 ( V_95 , V_146 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_594 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_594 , V_36 ) ;
}
static inline void F_381 ( struct V_97 * V_43 ,
T_4 * V_595 , int V_596 )
{
F_382 ( V_596 < ( V_597 * 4 ) ) ;
memset ( V_595 , 0 , V_596 ) ;
V_595 [ V_598 ] = V_43 -> V_53 ;
V_595 [ V_599 ] = V_43 -> V_600 ;
V_595 [ V_601 ] = V_43 -> V_50 ;
V_595 [ V_602 ] = V_43 -> V_603 ;
V_595 [ V_604 ] = V_43 -> V_605 ;
V_595 [ V_606 ] = V_43 -> V_386 ;
V_595 [ V_607 ] = V_43 -> V_230 ;
V_595 [ V_608 ] = V_43 -> V_66 ;
V_595 [ V_609 ] =
F_383 ( V_43 -> V_516 ) ;
V_595 [ V_610 ] =
F_383 ( V_43 -> V_500 ) ;
V_595 [ V_611 ] =
F_383 ( V_43 -> V_501 ) ;
V_595 [ V_612 ] = V_43 -> V_613 ;
V_595 [ V_614 ] =
F_383 ( V_43 -> V_615 ) ;
V_595 [ V_616 ] =
F_383 ( V_43 -> V_617 ) ;
V_595 [ V_618 ] = V_43 -> V_73 ;
V_595 [ V_619 ] = V_43 -> V_234 ;
V_595 [ V_620 ] = V_43 -> V_232 ;
V_595 [ V_621 ] = V_43 -> V_228 ;
V_595 [ V_622 ] = V_43 -> V_223 ;
V_595 [ V_623 ] = V_43 -> V_307 ;
V_595 [ V_624 ] = V_43 -> V_625 ;
V_595 [ V_626 ] = V_43 -> V_627 ;
V_595 [ V_628 ] = V_43 -> V_629 ;
#ifdef F_384
V_595 [ V_630 ] = V_43 -> V_631 ;
V_595 [ V_632 ] =
F_383 ( V_43 -> V_633 ) ;
#ifdef F_385
V_595 [ V_634 ] = V_43 -> V_635 ;
#endif
#endif
V_595 [ V_636 ] = V_43 -> V_111 ;
V_595 [ V_637 ] = V_43 -> V_638 ;
#ifdef F_170
V_595 [ V_639 ] = V_43 -> V_239 ;
V_595 [ V_640 ] = V_43 -> V_240 ;
#endif
#ifdef F_63
V_595 [ V_641 ] = V_43 -> V_110 ;
#endif
V_595 [ V_642 ] = V_43 -> V_183 ;
V_595 [ V_643 ] = V_43 -> V_61 ;
V_595 [ V_644 ] = V_43 -> V_645 ;
V_595 [ V_646 ] = V_43 -> V_647 ;
V_595 [ V_648 ] = V_43 -> V_649 ;
V_595 [ V_650 ] = V_43 -> V_651 ;
V_595 [ V_652 ] = V_43 -> V_653 ;
V_595 [ V_654 ] = V_43 -> V_112 ;
V_595 [ V_655 ] = V_43 -> V_283 ;
V_595 [ V_656 ] = V_43 -> V_657 ;
V_595 [ V_658 ] = V_43 -> V_659 ;
V_595 [ V_660 ] = V_43 -> V_491 ;
}
static inline T_16 F_386 ( void )
{
return F_62 ( 4 )
+ F_62 ( sizeof( struct V_661 ) )
+ F_62 ( V_597 * 4 )
+ F_62 ( V_662 * 8 )
+ F_62 ( V_663 * 8 )
+ F_62 ( sizeof( struct V_167 ) ) ;
}
static inline T_16 F_387 ( void )
{
return F_61 ( sizeof( struct V_664 ) )
+ F_62 ( V_665 )
+ F_62 ( V_459 )
+ F_62 ( 4 )
+ F_62 ( 4 )
+ F_62 ( 1 )
+ F_62 ( F_386 () ) ;
}
static inline void F_388 ( T_3 * V_21 , T_17 * V_666 ,
int V_596 )
{
int V_20 ;
int V_667 = V_596 - sizeof( T_3 ) * V_663 ;
F_382 ( V_667 < 0 ) ;
F_389 ( V_663 , & V_21 [ 0 ] ) ;
for ( V_20 = 1 ; V_20 < V_663 ; V_20 ++ )
F_389 ( F_390 ( & V_666 [ V_20 ] ) , & V_21 [ V_20 ] ) ;
memset ( & V_21 [ V_663 ] , 0 , V_667 ) ;
}
static inline void F_391 ( T_3 * V_21 , void T_18 * V_666 ,
int V_596 , T_16 V_668 )
{
int V_20 , V_669 ;
T_3 V_670 [ V_662 ] ;
int V_667 = V_596 - sizeof( T_3 ) * V_662 ;
F_382 ( V_667 < 0 ) ;
memset ( V_670 , 0 , sizeof( V_670 ) ) ;
V_670 [ 0 ] = V_662 ;
F_26 (c) {
for ( V_20 = 1 ; V_20 < V_662 ; V_20 ++ )
V_670 [ V_20 ] += F_392 ( V_666 , V_669 , V_20 , V_668 ) ;
}
memcpy ( V_21 , V_670 , V_662 * sizeof( T_3 ) ) ;
memset ( & V_21 [ V_662 ] , 0 , V_667 ) ;
}
static void F_393 ( T_3 * V_21 , struct V_8 * V_9 , int V_671 ,
int V_596 )
{
switch ( V_671 ) {
case V_672 :
F_391 ( V_21 , V_9 -> V_21 . V_22 , V_596 ,
F_394 ( struct V_23 , V_26 ) ) ;
break;
case V_673 :
F_388 ( V_21 , V_9 -> V_21 . V_27 -> V_674 , V_596 ) ;
break;
}
}
static int F_395 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_675 )
{
struct V_120 * V_676 ;
struct V_661 V_554 ;
if ( F_371 ( V_95 , V_677 , V_9 -> V_76 ) )
goto V_109;
V_554 . V_678 = V_679 ;
V_554 . V_78 = F_1 ( V_9 -> V_78 ) ;
V_554 . V_680 = F_383 ( V_9 -> V_51 -> V_680 ) ;
V_554 . V_681 = F_383 ( F_161 ( V_9 -> V_51 , V_231 ) ) ;
if ( F_366 ( V_95 , V_682 , sizeof( V_554 ) , & V_554 ) )
goto V_109;
V_676 = F_396 ( V_95 , V_683 , V_597 * sizeof( T_2 ) ) ;
if ( ! V_676 )
goto V_109;
F_381 ( & V_9 -> V_43 , F_358 ( V_676 ) , F_397 ( V_676 ) ) ;
if ( V_675 & V_684 )
return 0 ;
V_676 = F_396 ( V_95 , V_672 , V_662 * sizeof( T_3 ) ) ;
if ( ! V_676 )
goto V_109;
F_393 ( F_358 ( V_676 ) , V_9 , V_672 , F_397 ( V_676 ) ) ;
V_676 = F_396 ( V_95 , V_673 , V_663 * sizeof( T_3 ) ) ;
if ( ! V_676 )
goto V_109;
F_393 ( F_358 ( V_676 ) , V_9 , V_673 , F_397 ( V_676 ) ) ;
V_676 = F_396 ( V_95 , V_685 , sizeof( struct V_167 ) ) ;
if ( ! V_676 )
goto V_109;
if ( F_398 ( V_95 , V_686 , V_9 -> V_47 ) )
goto V_109;
F_181 ( & V_9 -> V_40 ) ;
memcpy ( F_358 ( V_676 ) , V_9 -> V_74 . V_225 , F_397 ( V_676 ) ) ;
F_186 ( & V_9 -> V_40 ) ;
return 0 ;
V_109:
return - V_105 ;
}
static T_16 F_399 ( const struct V_10 * V_11 ,
T_1 V_675 )
{
if ( ! F_57 ( V_11 ) )
return 0 ;
return F_386 () ;
}
static int F_400 ( struct V_94 * V_95 , const struct V_10 * V_11 ,
T_1 V_675 )
{
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_687 ;
if ( F_395 ( V_95 , V_9 , V_675 ) < 0 )
return - V_105 ;
return 0 ;
}
static int F_401 ( struct V_8 * V_9 , struct V_167 * V_74 )
{
struct V_13 * V_14 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_688 , V_689 = false ;
struct V_167 V_690 ;
F_33 () ;
if ( ! V_74 )
return - V_39 ;
if ( V_11 -> V_58 & ( V_60 | V_59 ) )
return - V_39 ;
if ( ! F_324 ( V_9 ) )
return - V_39 ;
if ( V_9 -> V_43 . V_66 == 0 )
return - V_39 ;
F_152 ( & V_9 -> V_40 ) ;
F_294 ( sizeof( V_74 -> V_225 ) != 16 ) ;
memcpy ( V_9 -> V_74 . V_225 + 8 , V_74 -> V_225 + 8 , 8 ) ;
F_156 ( & V_9 -> V_40 ) ;
V_688 = F_214 ( V_74 ) ;
if ( V_688 )
goto V_371;
if ( ! V_9 -> V_84 && ( V_9 -> V_76 & V_77 ) &&
! F_194 ( V_11 , & V_690 , V_149 |
V_236 ) ) {
F_325 ( V_11 , & V_690 , & V_83 ) ;
V_689 = true ;
}
V_371:
F_152 ( & V_9 -> V_40 ) ;
if ( V_689 ) {
V_9 -> V_76 |= V_494 ;
V_9 -> V_499 = F_2 (
V_9 -> V_43 . V_516 ) ;
V_9 -> V_498 = 1 ;
F_16 ( V_9 , V_9 -> V_499 ) ;
}
F_92 (ifp, &idev->addr_list, if_list) {
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_190 ) {
V_14 -> V_172 = 0 ;
V_14 -> V_173 = 0 ;
}
F_133 ( & V_14 -> V_40 ) ;
}
F_156 ( & V_9 -> V_40 ) ;
F_311 ( V_479 , V_9 ) ;
F_279 () ;
return 0 ;
}
static int F_402 ( const struct V_10 * V_11 ,
const struct V_120 * V_676 )
{
struct V_120 * V_121 [ V_691 + 1 ] ;
if ( V_11 && ! F_57 ( V_11 ) )
return - V_692 ;
return F_403 ( V_121 , V_691 , V_676 , V_693 ) ;
}
static int F_404 ( struct V_10 * V_11 , const struct V_120 * V_676 )
{
int V_36 = - V_39 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
struct V_120 * V_121 [ V_691 + 1 ] ;
if ( ! V_9 )
return - V_692 ;
if ( F_403 ( V_121 , V_691 , V_676 , NULL ) < 0 )
F_405 () ;
if ( V_121 [ V_685 ] ) {
V_36 = F_401 ( V_9 , F_358 ( V_121 [ V_685 ] ) ) ;
if ( V_36 )
return V_36 ;
}
if ( V_121 [ V_686 ] ) {
T_5 V_694 = F_406 ( V_121 [ V_686 ] ) ;
if ( V_694 != V_49 &&
V_694 != V_466 &&
V_694 != V_48 &&
V_694 != V_367 )
return - V_39 ;
if ( V_694 == V_48 &&
! V_9 -> V_43 . V_45 . V_46 &&
! F_38 ( V_11 ) -> V_22 . V_44 -> V_45 . V_46 )
return - V_39 ;
V_9 -> V_47 = V_694 ;
V_36 = 0 ;
}
return V_36 ;
}
static int F_407 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_664 * V_695 ;
struct V_102 * V_103 ;
void * V_696 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_695 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_695 = F_66 ( V_103 ) ;
V_695 -> V_697 = V_107 ;
V_695 -> V_698 = 0 ;
V_695 -> V_699 = V_11 -> type ;
V_695 -> V_700 = V_11 -> V_96 ;
V_695 -> V_701 = F_408 ( V_11 ) ;
V_695 -> V_702 = 0 ;
if ( F_409 ( V_95 , V_703 , V_11 -> V_56 ) ||
( V_11 -> V_314 &&
F_366 ( V_95 , V_704 , V_11 -> V_314 , V_11 -> V_316 ) ) ||
F_371 ( V_95 , V_705 , V_11 -> V_37 ) ||
( V_11 -> V_96 != F_410 ( V_11 ) &&
F_371 ( V_95 , V_706 , F_410 ( V_11 ) ) ) ||
F_398 ( V_95 , V_707 ,
F_49 ( V_11 ) ? V_11 -> V_708 : V_709 ) )
goto V_109;
V_696 = F_411 ( V_95 , V_710 ) ;
if ( ! V_696 )
goto V_109;
if ( F_395 ( V_95 , V_9 , 0 ) < 0 )
goto V_109;
F_412 ( V_95 , V_696 ) ;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_413 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
int V_132 , V_133 ;
int V_134 = 0 , V_135 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_136 * V_137 ;
V_133 = V_131 -> args [ 0 ] ;
V_135 = V_131 -> args [ 1 ] ;
F_84 () ;
for ( V_132 = V_133 ; V_132 < V_138 ; V_132 ++ , V_135 = 0 ) {
V_134 = 0 ;
V_137 = & V_113 -> V_139 [ V_132 ] ;
F_86 (dev, head, index_hlist) {
if ( V_134 < V_135 )
goto V_142;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_142;
if ( F_407 ( V_95 , V_9 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_479 , V_143 ) < 0 )
goto V_187;
V_142:
V_134 ++ ;
}
}
V_187:
F_87 () ;
V_131 -> args [ 1 ] = V_134 ;
V_131 -> args [ 0 ] = V_132 ;
return V_95 -> V_145 ;
}
void F_311 ( int V_101 , struct V_8 * V_9 )
{
struct V_94 * V_95 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_114 ;
V_95 = F_71 ( F_387 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_407 ( V_95 , V_9 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_711 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_711 , V_36 ) ;
}
static inline T_16 F_414 ( void )
{
return F_61 ( sizeof( struct V_712 ) )
+ F_62 ( sizeof( struct V_167 ) )
+ F_62 ( sizeof( struct V_713 ) ) ;
}
static int F_415 ( struct V_94 * V_95 , struct V_8 * V_9 ,
struct V_368 * V_369 , T_1 V_99 , T_1 V_100 ,
int V_101 , unsigned int V_58 )
{
struct V_712 * V_714 ;
struct V_102 * V_103 ;
struct V_713 V_554 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_714 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_714 = F_66 ( V_103 ) ;
V_714 -> V_715 = V_107 ;
V_714 -> V_716 = 0 ;
V_714 -> V_717 = 0 ;
V_714 -> V_718 = V_9 -> V_11 -> V_96 ;
V_714 -> V_189 = V_369 -> V_189 ;
V_714 -> V_719 = V_369 -> type ;
V_714 -> V_720 = 0 ;
V_714 -> V_721 = 0 ;
if ( V_369 -> V_291 )
V_714 -> V_721 |= V_722 ;
if ( V_369 -> V_386 )
V_714 -> V_721 |= V_723 ;
if ( F_366 ( V_95 , V_724 , sizeof( V_369 -> V_378 ) , & V_369 -> V_378 ) )
goto V_109;
V_554 . V_725 = F_258 ( V_369 -> V_381 ) ;
V_554 . V_726 = F_258 ( V_369 -> V_380 ) ;
if ( F_366 ( V_95 , V_727 , sizeof( V_554 ) , & V_554 ) )
goto V_109;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static void F_265 ( int V_101 , struct V_8 * V_9 ,
struct V_368 * V_369 )
{
struct V_94 * V_95 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_114 ;
V_95 = F_71 ( F_414 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_415 ( V_95 , V_9 , V_369 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_728 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_728 , V_36 ) ;
}
static void F_321 ( int V_101 , struct V_13 * V_14 )
{
struct V_113 * V_113 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( V_101 )
F_33 () ;
F_380 ( V_101 ? : V_432 , V_14 ) ;
switch ( V_101 ) {
case V_432 :
if ( ! ( V_14 -> V_6 -> V_729 ) )
F_290 ( V_14 -> V_6 ) ;
if ( V_14 -> V_9 -> V_43 . V_53 )
F_93 ( V_14 ) ;
if ( ! F_214 ( & V_14 -> V_169 ) )
F_239 ( & V_14 -> V_169 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
break;
case V_210 :
if ( V_14 -> V_9 -> V_43 . V_53 )
F_94 ( V_14 ) ;
F_211 ( V_14 -> V_9 , & V_14 -> V_165 ) ;
if ( ! F_214 ( & V_14 -> V_169 ) ) {
struct V_174 * V_6 ;
V_6 = F_145 ( & V_14 -> V_169 , 128 ,
V_14 -> V_9 -> V_11 , 0 , 0 ) ;
if ( V_6 )
F_146 ( V_6 ) ;
}
if ( V_14 -> V_6 ) {
F_244 ( & V_14 -> V_6 -> V_244 ) ;
F_146 ( V_14 -> V_6 ) ;
}
F_286 ( V_113 ) ;
break;
}
F_416 ( & V_113 -> V_22 . V_140 ) ;
}
static void F_157 ( int V_101 , struct V_13 * V_14 )
{
F_123 () ;
if ( F_138 ( V_14 -> V_9 -> V_84 == 0 ) )
F_321 ( V_101 , V_14 ) ;
F_137 () ;
}
static
int F_417 ( struct V_152 * V_730 , int V_731 ,
void T_8 * V_732 , T_16 * V_733 , T_10 * V_734 )
{
int * V_735 = V_730 -> V_461 ;
int V_736 = * V_735 ;
T_10 V_518 = * V_734 ;
struct V_152 V_737 ;
int V_220 ;
V_737 = * V_730 ;
V_737 . V_461 = & V_736 ;
V_220 = F_418 ( & V_737 , V_731 , V_732 , V_733 , V_734 ) ;
if ( V_731 )
V_220 = F_97 ( V_730 , V_735 , V_736 ) ;
if ( V_220 )
* V_734 = V_518 ;
return V_220 ;
}
static
int F_419 ( struct V_152 * V_730 , int V_731 ,
void T_8 * V_732 , T_16 * V_733 , T_10 * V_734 )
{
struct V_8 * V_9 = V_730 -> V_158 ;
int V_738 = V_38 ;
struct V_152 V_737 ;
V_737 = * V_730 ;
V_737 . V_158 = & V_738 ;
V_737 . V_156 = V_9 ? & V_9 -> V_11 -> V_37 : NULL ;
return F_420 ( & V_737 , V_731 , V_732 , V_733 , V_734 ) ;
}
static void F_421 ( struct V_8 * V_9 )
{
struct V_739 V_471 ;
if ( ! V_9 || ! V_9 -> V_11 )
return;
F_422 ( & V_471 , V_9 -> V_11 ) ;
if ( V_9 -> V_43 . V_183 )
F_305 ( NULL , V_211 , & V_471 ) ;
else
F_305 ( NULL , V_194 , & V_471 ) ;
}
static void F_423 ( struct V_113 * V_113 , T_4 V_150 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_84 () ;
F_190 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_151 = ( ! V_9 -> V_43 . V_183 ) ^ ( ! V_150 ) ;
V_9 -> V_43 . V_183 = V_150 ;
if ( V_151 )
F_421 ( V_9 ) ;
}
}
F_87 () ;
}
static int F_424 ( struct V_152 * V_153 , int * V_154 , int V_150 )
{
struct V_113 * V_113 ;
int V_155 ;
if ( ! F_98 () )
return F_99 () ;
V_113 = (struct V_113 * ) V_153 -> V_156 ;
V_155 = * V_154 ;
* V_154 = V_150 ;
if ( V_154 == & V_113 -> V_22 . V_44 -> V_183 ) {
F_100 () ;
return 0 ;
}
if ( V_154 == & V_113 -> V_22 . V_126 -> V_183 ) {
V_113 -> V_22 . V_44 -> V_183 = V_150 ;
F_423 ( V_113 , V_150 ) ;
} else if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_421 ( (struct V_8 * ) V_153 -> V_158 ) ;
F_100 () ;
return 0 ;
}
static
int F_425 ( struct V_152 * V_730 , int V_731 ,
void T_8 * V_732 , T_16 * V_733 , T_10 * V_734 )
{
int * V_735 = V_730 -> V_461 ;
int V_736 = * V_735 ;
T_10 V_518 = * V_734 ;
struct V_152 V_737 ;
int V_220 ;
V_737 = * V_730 ;
V_737 . V_461 = & V_736 ;
V_220 = F_418 ( & V_737 , V_731 , V_732 , V_733 , V_734 ) ;
if ( V_731 )
V_220 = F_424 ( V_730 , V_735 , V_736 ) ;
if ( V_220 )
* V_734 = V_518 ;
return V_220 ;
}
static
int F_426 ( struct V_152 * V_730 , int V_731 ,
void T_8 * V_732 , T_16 * V_733 , T_10 * V_734 )
{
int * V_735 = V_730 -> V_461 ;
int V_220 ;
int V_155 , V_740 ;
V_155 = * V_735 ;
V_220 = F_418 ( V_730 , V_731 , V_732 , V_733 , V_734 ) ;
V_740 = * V_735 ;
if ( V_731 && V_155 != V_740 ) {
struct V_113 * V_113 = V_730 -> V_156 ;
if ( ! F_98 () )
return F_99 () ;
if ( V_735 == & V_113 -> V_22 . V_44 -> V_111 )
F_70 ( V_113 , V_92 ,
V_127 ,
V_113 -> V_22 . V_44 ) ;
else if ( V_735 == & V_113 -> V_22 . V_126 -> V_111 )
F_70 ( V_113 , V_92 ,
V_125 ,
V_113 -> V_22 . V_126 ) ;
else {
struct V_8 * V_9 = V_730 -> V_158 ;
F_70 ( V_113 , V_92 ,
V_9 -> V_11 -> V_96 ,
& V_9 -> V_43 ) ;
}
F_100 () ;
}
return V_220 ;
}
static int F_427 ( struct V_152 * V_730 , int V_731 ,
void T_8 * V_732 , T_16 * V_733 ,
T_10 * V_734 )
{
int V_36 ;
struct V_167 V_165 ;
char V_741 [ V_742 ] ;
struct V_152 V_737 = * V_730 ;
struct V_113 * V_113 = V_730 -> V_156 ;
struct V_463 * V_457 = V_730 -> V_461 ;
if ( & V_113 -> V_22 . V_126 -> V_45 == V_730 -> V_461 )
return - V_743 ;
V_737 . V_744 = V_742 ;
V_737 . V_461 = V_741 ;
if ( ! F_98 () )
return F_99 () ;
if ( ! V_731 && ! V_457 -> V_46 ) {
V_36 = - V_743 ;
goto V_187;
}
V_36 = snprintf ( V_741 , sizeof( V_741 ) , L_29 , & V_457 -> V_457 ) ;
if ( V_36 >= sizeof( V_741 ) ) {
V_36 = - V_743 ;
goto V_187;
}
V_36 = F_428 ( & V_737 , V_731 , V_732 , V_733 , V_734 ) ;
if ( V_36 || ! V_731 )
goto V_187;
if ( F_429 ( V_741 , - 1 , V_165 . V_745 . V_746 , - 1 , NULL ) != 1 ) {
V_36 = - V_743 ;
goto V_187;
}
V_457 -> V_46 = true ;
V_457 -> V_457 = V_165 ;
if ( & V_113 -> V_22 . V_44 -> V_45 == V_730 -> V_461 ) {
struct V_10 * V_11 ;
F_96 (net, dev) {
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
V_9 -> V_47 =
V_48 ;
}
}
} else {
struct V_8 * V_9 = V_730 -> V_158 ;
V_9 -> V_47 = V_48 ;
}
V_187:
F_100 () ;
return V_36 ;
}
static
int F_430 ( struct V_152 * V_730 ,
int V_731 ,
void T_8 * V_732 ,
T_16 * V_733 ,
T_10 * V_734 )
{
int * V_735 = V_730 -> V_461 ;
int V_736 = * V_735 ;
T_10 V_518 = * V_734 ;
struct V_152 V_737 ;
int V_220 ;
V_737 = * V_730 ;
V_737 . V_461 = & V_736 ;
V_220 = F_418 ( & V_737 , V_731 , V_732 , V_733 , V_734 ) ;
if ( V_731 )
V_220 = F_103 ( V_730 , V_735 , V_736 ) ;
if ( V_220 )
* V_734 = V_518 ;
return V_220 ;
}
static int F_431 ( struct V_113 * V_113 , char * V_747 ,
struct V_8 * V_9 , struct V_97 * V_154 )
{
int V_20 , V_96 ;
struct V_152 * V_153 ;
char V_748 [ sizeof( L_30 ) + V_665 ] ;
V_153 = F_432 ( V_749 , sizeof( V_749 ) , V_29 ) ;
if ( ! V_153 )
goto V_187;
for ( V_20 = 0 ; V_153 [ V_20 ] . V_461 ; V_20 ++ ) {
V_153 [ V_20 ] . V_461 += ( char * ) V_154 - ( char * ) & V_97 ;
if ( ! V_153 [ V_20 ] . V_158 && ! V_153 [ V_20 ] . V_156 ) {
V_153 [ V_20 ] . V_158 = V_9 ;
V_153 [ V_20 ] . V_156 = V_113 ;
}
}
snprintf ( V_748 , sizeof( V_748 ) , L_31 , V_747 ) ;
V_154 -> V_750 = F_433 ( V_113 , V_748 , V_153 ) ;
if ( ! V_154 -> V_750 )
goto free;
if ( ! strcmp ( V_747 , L_32 ) )
V_96 = V_125 ;
else if ( ! strcmp ( V_747 , L_33 ) )
V_96 = V_127 ;
else
V_96 = V_9 -> V_11 -> V_96 ;
F_70 ( V_113 , V_89 , V_96 , V_154 ) ;
return 0 ;
free:
F_30 ( V_153 ) ;
V_187:
return - V_114 ;
}
static void F_434 ( struct V_97 * V_154 )
{
struct V_152 * V_153 ;
if ( ! V_154 -> V_750 )
return;
V_153 = V_154 -> V_750 -> V_751 ;
F_435 ( V_154 -> V_750 ) ;
V_154 -> V_750 = NULL ;
F_30 ( V_153 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
int V_36 ;
if ( ! F_436 ( V_9 -> V_11 -> V_56 ) )
return - V_39 ;
V_36 = F_437 ( V_9 -> V_11 , V_9 -> V_51 ,
& V_752 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_431 ( F_38 ( V_9 -> V_11 ) , V_9 -> V_11 -> V_56 ,
V_9 , & V_9 -> V_43 ) ;
if ( V_36 )
F_438 ( V_9 -> V_51 ) ;
return V_36 ;
}
static void F_7 ( struct V_8 * V_9 )
{
F_434 ( & V_9 -> V_43 ) ;
F_438 ( V_9 -> V_51 ) ;
}
static int T_12 F_439 ( struct V_113 * V_113 )
{
int V_36 = - V_34 ;
struct V_97 * V_88 , * V_753 ;
V_88 = F_432 ( & V_97 , sizeof( V_97 ) , V_29 ) ;
if ( ! V_88 )
goto V_754;
V_753 = F_432 ( & V_755 , sizeof( V_755 ) , V_29 ) ;
if ( ! V_753 )
goto V_756;
V_753 -> V_386 = V_757 . V_386 ;
V_753 -> V_183 = V_757 . V_183 ;
V_753 -> V_45 . V_46 = false ;
V_88 -> V_45 . V_46 = false ;
V_113 -> V_22 . V_126 = V_88 ;
V_113 -> V_22 . V_44 = V_753 ;
#ifdef F_440
V_36 = F_431 ( V_113 , L_32 , NULL , V_88 ) ;
if ( V_36 < 0 )
goto V_758;
V_36 = F_431 ( V_113 , L_33 , NULL , V_753 ) ;
if ( V_36 < 0 )
goto V_759;
#endif
return 0 ;
#ifdef F_440
V_759:
F_434 ( V_88 ) ;
V_758:
F_30 ( V_753 ) ;
#endif
V_756:
F_30 ( V_88 ) ;
V_754:
return V_36 ;
}
static void T_13 F_441 ( struct V_113 * V_113 )
{
#ifdef F_440
F_434 ( V_113 -> V_22 . V_44 ) ;
F_434 ( V_113 -> V_22 . V_126 ) ;
#endif
F_30 ( V_113 -> V_22 . V_44 ) ;
F_30 ( V_113 -> V_22 . V_126 ) ;
}
int T_14 F_442 ( void )
{
struct V_8 * V_9 ;
int V_20 , V_36 ;
V_36 = F_443 () ;
if ( V_36 < 0 ) {
F_444 ( L_34 ,
V_55 , V_36 ) ;
goto V_187;
}
V_36 = F_351 ( & V_760 ) ;
if ( V_36 < 0 )
goto V_761;
V_19 = F_445 ( L_35 ) ;
if ( ! V_19 ) {
V_36 = - V_34 ;
goto V_762;
}
F_267 () ;
V_9 = F_32 ( V_763 . V_764 ) ;
F_100 () ;
if ( F_58 ( V_9 ) ) {
V_36 = F_127 ( V_9 ) ;
goto V_765;
}
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ )
F_446 ( & V_191 [ V_20 ] ) ;
F_447 ( & V_766 ) ;
F_256 () ;
F_448 ( & V_767 ) ;
V_36 = F_449 ( V_768 , V_769 , NULL , F_413 ,
NULL ) ;
if ( V_36 < 0 )
goto V_115;
F_449 ( V_768 , V_432 , F_363 , NULL , NULL ) ;
F_449 ( V_768 , V_210 , F_360 , NULL , NULL ) ;
F_449 ( V_768 , V_770 , F_379 ,
F_376 , NULL ) ;
F_449 ( V_768 , V_587 , NULL ,
F_377 , NULL ) ;
F_449 ( V_768 , V_591 , NULL ,
F_378 , NULL ) ;
F_449 ( V_768 , V_771 , F_76 ,
F_83 , NULL ) ;
F_450 () ;
return 0 ;
V_115:
F_451 ( & V_767 ) ;
F_452 ( & V_766 ) ;
V_765:
F_453 ( V_19 ) ;
V_762:
F_353 ( & V_760 ) ;
V_761:
F_454 () ;
V_187:
return V_36 ;
}
void F_455 ( void )
{
struct V_10 * V_11 ;
int V_20 ;
F_452 ( & V_766 ) ;
F_353 ( & V_760 ) ;
F_454 () ;
F_267 () ;
F_456 ( & V_767 ) ;
F_96 (&init_net, dev) {
if ( F_57 ( V_11 ) == NULL )
continue;
F_308 ( V_11 , 1 ) ;
}
F_308 ( V_763 . V_764 , 2 ) ;
F_149 ( & V_185 ) ;
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ )
F_72 ( ! F_457 ( & V_191 [ V_20 ] ) ) ;
F_150 ( & V_185 ) ;
F_14 ( & V_535 ) ;
F_100 () ;
F_453 ( V_19 ) ;
}
