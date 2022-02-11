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
case V_70 :
return F_234 ( V_313 , V_11 ) ;
case V_330 :
return F_217 ( V_313 , V_11 ) ;
case V_331 :
return F_218 ( V_313 , V_11 ) ;
case V_71 :
case V_332 :
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
V_333:
F_165 ( V_9 -> V_229 , sizeof( V_9 -> V_229 ) ) ;
V_9 -> V_229 [ 0 ] &= ~ 0x02 ;
if ( V_9 -> V_229 [ 0 ] == 0xfd &&
( V_9 -> V_229 [ 1 ] & V_9 -> V_229 [ 2 ] & V_9 -> V_229 [ 3 ] & V_9 -> V_229 [ 4 ] & V_9 -> V_229 [ 5 ] & V_9 -> V_229 [ 6 ] ) == 0xff &&
( V_9 -> V_229 [ 7 ] & 0x80 ) )
goto V_333;
if ( ( V_9 -> V_229 [ 0 ] | V_9 -> V_229 [ 1 ] ) == 0 ) {
if ( V_9 -> V_229 [ 2 ] == 0x5e && V_9 -> V_229 [ 3 ] == 0xfe )
goto V_333;
if ( ( V_9 -> V_229 [ 2 ] | V_9 -> V_229 [ 3 ] | V_9 -> V_229 [ 4 ] | V_9 -> V_229 [ 5 ] | V_9 -> V_229 [ 6 ] | V_9 -> V_229 [ 7 ] ) == 0x00 )
goto V_333;
}
}
static void F_160 ( struct V_8 * V_9 , struct V_167 * V_213 )
{
if ( V_213 && memcmp ( V_9 -> V_229 , & V_213 -> V_225 [ 8 ] , 8 ) == 0 )
F_48 ( V_9 ) ;
}
static void
F_239 ( struct V_167 * V_334 , int V_335 , struct V_10 * V_11 ,
unsigned long V_196 , T_1 V_58 )
{
struct V_336 V_337 = {
. V_338 = F_240 ( V_11 ) ? : V_339 ,
. V_340 = V_341 ,
. V_342 = V_11 -> V_96 ,
. V_343 = V_196 ,
. V_344 = V_335 ,
. V_345 = V_346 | V_58 ,
. V_347 . V_348 = F_38 ( V_11 ) ,
. V_349 = V_350 ,
} ;
V_337 . V_351 = * V_334 ;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 && ( V_11 -> V_58 & V_352 ) )
V_337 . V_345 |= V_353 ;
#endif
F_241 ( & V_337 ) ;
}
static struct V_174 * F_145 ( const struct V_167 * V_334 ,
int V_335 ,
const struct V_10 * V_11 ,
T_1 V_58 , T_1 V_354 )
{
struct V_355 * V_356 ;
struct V_174 * V_6 = NULL ;
struct V_357 * V_153 ;
T_1 V_358 = F_240 ( V_11 ) ? : V_339 ;
V_153 = F_242 ( F_38 ( V_11 ) , V_358 ) ;
if ( ! V_153 )
return NULL ;
F_181 ( & V_153 -> V_359 ) ;
V_356 = F_243 ( & V_153 -> V_360 , V_334 , V_335 , NULL , 0 ) ;
if ( ! V_356 )
goto V_187;
V_354 |= V_361 ;
for ( V_6 = V_356 -> V_362 ; V_6 ; V_6 = V_6 -> V_244 . V_363 ) {
if ( V_6 -> V_244 . V_11 -> V_96 != V_11 -> V_96 )
continue;
if ( ( V_6 -> V_207 & V_58 ) != V_58 )
continue;
if ( ( V_6 -> V_207 & V_354 ) != 0 )
continue;
F_244 ( & V_6 -> V_244 ) ;
break;
}
V_187:
F_186 ( & V_153 -> V_359 ) ;
return V_6 ;
}
static void F_245 ( struct V_10 * V_11 )
{
struct V_336 V_337 = {
. V_338 = F_240 ( V_11 ) ? : V_364 ,
. V_340 = V_341 ,
. V_342 = V_11 -> V_96 ,
. V_344 = 8 ,
. V_345 = V_346 ,
. V_347 . V_348 = F_38 ( V_11 ) ,
} ;
F_246 ( & V_337 . V_351 , F_247 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_241 ( & V_337 ) ;
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
bool V_365 , unsigned long V_222 )
{
T_1 V_58 ;
struct V_13 * V_212 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ift, &idev->tempaddr_list, tmp_list) {
int V_217 , V_366 , V_367 ;
if ( V_14 != V_212 -> V_209 )
continue;
V_217 = ( V_222 - V_212 -> V_1 ) / V_3 ;
V_366 = V_9 -> V_43 . V_234 - V_217 ;
if ( V_366 < 0 )
V_366 = 0 ;
V_367 = V_9 -> V_43 . V_232 -
V_9 -> V_68 - V_217 ;
if ( V_367 < 0 )
V_367 = 0 ;
if ( V_172 > V_366 )
V_172 = V_366 ;
if ( V_173 > V_367 )
V_173 = V_367 ;
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
if ( ( V_365 || F_251 ( & V_9 -> V_67 ) ) &&
V_9 -> V_43 . V_73 > 0 ) {
F_186 ( & V_9 -> V_40 ) ;
F_159 ( V_14 , NULL ) ;
} else {
F_186 ( & V_9 -> V_40 ) ;
}
}
static bool F_252 ( struct V_8 * V_9 )
{
return V_9 -> V_43 . V_47 == V_48 ||
V_9 -> V_43 . V_47 == V_368 ;
}
int F_253 ( struct V_113 * V_113 , struct V_10 * V_11 ,
const struct V_369 * V_370 ,
struct V_8 * V_123 ,
const struct V_167 * V_165 , int V_176 ,
T_1 V_221 , bool V_371 , bool V_190 ,
V_233 V_172 , T_1 V_173 )
{
struct V_13 * V_14 = F_202 ( V_113 , V_165 , V_11 , 1 ) ;
int V_365 = 0 , V_372 = 0 ;
if ( ! V_14 && V_172 ) {
int V_307 = V_123 -> V_43 . V_307 ;
#ifdef F_170
if ( V_123 -> V_43 . V_239 &&
! V_113 -> V_22 . V_126 -> V_53 && V_371 )
V_221 |= V_236 ;
#endif
if ( ! V_307 ||
F_195 ( V_123 ) < V_307 )
V_14 = F_121 ( V_123 , V_165 , NULL ,
V_370 -> V_189 ,
V_176 & V_373 ,
V_221 , V_172 ,
V_173 ) ;
if ( F_254 ( V_14 ) )
return - 1 ;
V_372 = 0 ;
V_365 = 1 ;
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 |= V_374 ;
V_14 -> V_1 = V_17 ;
V_14 -> V_190 = V_190 ;
F_150 ( & V_14 -> V_40 ) ;
F_167 ( V_14 ) ;
}
if ( V_14 ) {
T_1 V_58 ;
unsigned long V_222 ;
T_1 V_375 ;
F_149 ( & V_14 -> V_40 ) ;
V_222 = V_17 ;
if ( V_14 -> V_172 > ( V_222 - V_14 -> V_78 ) / V_3 )
V_375 = V_14 -> V_172 - ( V_222 - V_14 -> V_78 ) / V_3 ;
else
V_375 = 0 ;
if ( ! V_372 && ! V_365 && V_375 ) {
const T_1 V_376 = F_163 ( T_1 ,
V_375 , V_377 ) ;
V_172 = F_255 ( V_172 , V_376 ) ;
V_372 = 1 ;
}
if ( V_372 ) {
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
V_365 , V_222 ) ;
F_154 ( V_14 ) ;
F_256 () ;
}
return 0 ;
}
void F_257 ( struct V_10 * V_11 , T_5 * V_378 , int V_145 , bool V_371 )
{
struct V_369 * V_370 ;
V_233 V_172 ;
V_233 V_173 ;
int V_176 , V_36 ;
T_1 V_221 = 0 ;
struct V_8 * V_123 ;
struct V_113 * V_113 = F_38 ( V_11 ) ;
V_370 = (struct V_369 * ) V_378 ;
if ( V_145 < sizeof( struct V_369 ) ) {
F_42 ( L_16 ) ;
return;
}
V_176 = F_122 ( & V_370 -> V_379 ) ;
if ( V_176 & ( V_178 | V_380 ) )
return;
V_172 = F_258 ( V_370 -> V_381 ) ;
V_173 = F_258 ( V_370 -> V_382 ) ;
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
if ( V_370 -> V_291 ) {
struct V_174 * V_6 ;
unsigned long V_383 ;
if ( V_3 > V_384 )
V_383 = F_142 ( V_172 , V_3 ) ;
else
V_383 = F_142 ( V_172 , V_384 ) ;
if ( F_261 ( V_383 ) )
V_383 *= V_3 ;
V_6 = F_145 ( & V_370 -> V_379 ,
V_370 -> V_189 ,
V_11 ,
V_385 | V_386 ,
V_205 | V_206 ) ;
if ( V_6 ) {
if ( V_172 == 0 ) {
F_146 ( V_6 ) ;
V_6 = NULL ;
} else if ( F_261 ( V_383 ) ) {
F_147 ( V_6 , V_17 + V_383 ) ;
} else {
F_262 ( V_6 ) ;
}
} else if ( V_172 ) {
T_7 V_196 = 0 ;
int V_58 = V_385 | V_386 ;
if ( F_261 ( V_383 ) ) {
V_58 |= V_208 ;
V_196 = F_263 ( V_383 ) ;
}
F_239 ( & V_370 -> V_379 , V_370 -> V_189 ,
V_11 , V_196 , V_58 ) ;
}
F_111 ( V_6 ) ;
}
if ( V_370 -> V_387 && V_123 -> V_43 . V_387 ) {
struct V_167 V_165 ;
bool V_190 = false , V_388 = false ;
if ( V_370 -> V_189 == 64 ) {
memcpy ( & V_165 , & V_370 -> V_379 , 8 ) ;
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
goto V_389;
} else if ( F_236 ( V_165 . V_225 + 8 , V_11 ) &&
F_238 ( V_165 . V_225 + 8 , V_123 ) ) {
goto V_390;
} else {
V_388 = true ;
}
goto V_389;
}
F_183 ( L_19 ,
V_370 -> V_189 ) ;
goto V_390;
V_389:
V_36 = F_253 ( V_113 , V_11 , V_370 , V_123 ,
& V_165 , V_176 ,
V_221 , V_371 ,
V_190 , V_172 ,
V_173 ) ;
if ( V_36 )
goto V_390;
F_264 ( V_113 , V_11 , V_370 , V_123 , & V_165 ,
V_176 , V_221 , V_371 ,
V_190 , V_172 ,
V_173 ,
V_388 ) ;
}
F_265 ( V_391 , V_123 , V_370 ) ;
V_390:
F_108 ( V_123 ) ;
}
int F_266 ( struct V_113 * V_113 , void T_8 * V_392 )
{
struct V_393 V_394 ;
struct V_10 * V_11 ;
int V_36 = - V_39 ;
F_267 () ;
V_36 = - V_395 ;
if ( F_268 ( & V_394 , V_392 , sizeof( struct V_393 ) ) )
goto V_396;
V_11 = F_80 ( V_113 , V_394 . V_397 ) ;
V_36 = - V_181 ;
if ( ! V_11 )
goto V_396;
#if F_46 ( V_62 )
if ( V_11 -> type == V_63 ) {
const struct V_398 * V_399 = V_11 -> V_400 ;
struct V_401 V_402 ;
struct V_403 V_154 ;
V_36 = - V_180 ;
if ( ! ( F_122 ( & V_394 . V_404 ) & V_238 ) )
goto V_396;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_405 . V_278 = V_394 . V_404 . V_406 [ 3 ] ;
V_154 . V_405 . V_279 = 0 ;
V_154 . V_405 . V_407 = 4 ;
V_154 . V_405 . V_408 = 5 ;
V_154 . V_405 . V_409 = V_410 ;
V_154 . V_405 . V_411 = 64 ;
V_402 . V_412 . V_413 = ( V_414 void T_8 * ) & V_154 ;
if ( V_399 -> V_415 ) {
T_9 V_416 = F_269 () ;
F_270 ( V_417 ) ;
V_36 = V_399 -> V_415 ( V_11 , & V_402 , V_418 ) ;
F_270 ( V_416 ) ;
} else
V_36 = - V_419 ;
if ( V_36 == 0 ) {
V_36 = - V_114 ;
V_11 = F_271 ( V_113 , V_154 . V_56 ) ;
if ( ! V_11 )
goto V_396;
V_36 = F_272 ( V_11 ) ;
}
}
#endif
V_396:
F_100 () ;
return V_36 ;
}
static int F_273 ( struct V_420 * V_119 , bool V_421 ,
const struct V_167 * V_165 , int V_96 )
{
int V_220 ;
F_33 () ;
F_274 ( V_119 ) ;
if ( V_421 )
V_220 = F_275 ( V_119 , V_96 , V_165 ) ;
else
V_220 = F_276 ( V_119 , V_96 , V_165 ) ;
F_277 ( V_119 ) ;
return V_220 ;
}
static int F_278 ( struct V_113 * V_113 , int V_96 ,
const struct V_167 * V_334 ,
const struct V_167 * V_422 ,
unsigned int V_335 , V_233 V_423 ,
V_233 V_173 , V_233 V_172 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned long V_424 ;
T_7 V_196 ;
int V_171 ;
T_1 V_58 ;
F_33 () ;
if ( V_335 > 128 )
return - V_39 ;
if ( ! V_172 || V_173 > V_172 )
return - V_39 ;
if ( V_423 & V_374 && V_335 != 64 )
return - V_39 ;
V_11 = F_80 ( V_113 , V_96 ) ;
if ( ! V_11 )
return - V_181 ;
V_9 = F_248 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_127 ( V_9 ) ;
if ( V_423 & V_425 ) {
int V_220 = F_273 ( V_113 -> V_22 . V_426 ,
true , V_334 , V_96 ) ;
if ( V_220 < 0 )
return V_220 ;
}
V_171 = F_166 ( V_334 ) ;
V_424 = F_142 ( V_172 , V_3 ) ;
if ( F_261 ( V_424 ) ) {
V_196 = F_263 ( V_424 * V_3 ) ;
V_172 = V_424 ;
V_58 = V_208 ;
} else {
V_196 = 0 ;
V_58 = 0 ;
V_423 |= V_200 ;
}
V_424 = F_142 ( V_173 , V_3 ) ;
if ( F_261 ( V_424 ) ) {
if ( V_424 == 0 )
V_423 |= V_255 ;
V_173 = V_424 ;
}
V_14 = F_121 ( V_9 , V_334 , V_422 , V_335 , V_171 , V_423 ,
V_172 , V_173 ) ;
if ( ! F_58 ( V_14 ) ) {
if ( ! ( V_423 & V_201 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_11 ,
V_196 , V_58 ) ;
}
F_167 ( V_14 ) ;
if ( V_423 & V_374 )
F_250 ( V_9 , V_14 , V_172 , V_173 ,
true , V_17 ) ;
F_154 ( V_14 ) ;
F_279 () ;
return 0 ;
} else if ( V_423 & V_425 ) {
F_273 ( V_113 -> V_22 . V_426 ,
false , V_334 , V_96 ) ;
}
return F_127 ( V_14 ) ;
}
static int F_280 ( struct V_113 * V_113 , int V_96 , T_1 V_423 ,
const struct V_167 * V_334 , unsigned int V_335 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_335 > 128 )
return - V_39 ;
V_11 = F_80 ( V_113 , V_96 ) ;
if ( ! V_11 )
return - V_181 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_427 ;
F_181 ( & V_9 -> V_40 ) ;
F_92 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_189 == V_335 &&
F_173 ( V_334 , & V_14 -> V_165 ) ) {
F_22 ( V_14 ) ;
F_186 ( & V_9 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_192 ) &&
( V_423 & V_374 ) )
F_250 ( V_9 , V_14 , 0 , 0 , false ,
V_17 ) ;
F_148 ( V_14 ) ;
F_279 () ;
if ( F_281 ( V_334 ) ) {
F_273 ( V_113 -> V_22 . V_426 ,
false , V_334 , V_11 -> V_96 ) ;
}
return 0 ;
}
}
F_186 ( & V_9 -> V_40 ) ;
return - V_180 ;
}
int F_282 ( struct V_113 * V_113 , void T_8 * V_392 )
{
struct V_393 V_394 ;
int V_36 ;
if ( ! F_283 ( V_113 -> V_428 , V_429 ) )
return - V_430 ;
if ( F_268 ( & V_394 , V_392 , sizeof( struct V_393 ) ) )
return - V_395 ;
F_267 () ;
V_36 = F_278 ( V_113 , V_394 . V_397 , & V_394 . V_404 , NULL ,
V_394 . V_431 , V_200 ,
V_432 , V_432 ) ;
F_100 () ;
return V_36 ;
}
int F_284 ( struct V_113 * V_113 , void T_8 * V_392 )
{
struct V_393 V_394 ;
int V_36 ;
if ( ! F_283 ( V_113 -> V_428 , V_429 ) )
return - V_430 ;
if ( F_268 ( & V_394 , V_392 , sizeof( struct V_393 ) ) )
return - V_395 ;
F_267 () ;
V_36 = F_280 ( V_113 , V_394 . V_397 , 0 , & V_394 . V_404 ,
V_394 . V_431 ) ;
F_100 () ;
return V_36 ;
}
static void F_285 ( struct V_8 * V_9 , const struct V_167 * V_165 ,
int V_335 , int V_171 )
{
struct V_13 * V_14 ;
V_14 = F_121 ( V_9 , V_165 , NULL , V_335 ,
V_171 , V_200 ,
V_432 , V_432 ) ;
if ( ! F_58 ( V_14 ) ) {
F_149 ( & V_14 -> V_40 ) ;
V_14 -> V_58 &= ~ V_149 ;
F_150 ( & V_14 -> V_40 ) ;
F_286 ( F_38 ( V_9 -> V_11 ) ) ;
F_157 ( V_433 , V_14 ) ;
F_154 ( V_14 ) ;
}
}
static void F_287 ( struct V_8 * V_9 )
{
struct V_167 V_165 ;
struct V_10 * V_11 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
int V_171 , V_335 ;
T_1 V_434 = 0 ;
F_33 () ;
memset ( & V_165 , 0 , sizeof( struct V_167 ) ) ;
memcpy ( & V_165 . V_406 [ 3 ] , V_9 -> V_11 -> V_316 , 4 ) ;
if ( V_9 -> V_11 -> V_58 & V_352 ) {
V_165 . V_406 [ 0 ] = F_247 ( 0xfe800000 ) ;
V_171 = V_286 ;
V_335 = 64 ;
} else {
V_171 = V_238 ;
V_335 = 96 ;
V_434 |= V_353 ;
}
if ( V_165 . V_406 [ 3 ] ) {
F_285 ( V_9 , & V_165 , V_335 , V_171 ) ;
F_239 ( & V_165 , V_335 , V_9 -> V_11 , 0 , V_434 ) ;
return;
}
F_96 (net, dev) {
struct V_435 * V_436 = F_288 ( V_11 ) ;
if ( V_436 && ( V_11 -> V_58 & V_85 ) ) {
struct V_437 * V_146 ;
int V_438 = V_171 ;
for ( V_146 = V_436 -> V_439 ; V_146 ; V_146 = V_146 -> V_440 ) {
V_165 . V_406 [ 3 ] = V_146 -> V_441 ;
if ( V_146 -> V_442 == V_443 )
continue;
if ( V_146 -> V_442 >= V_444 ) {
if ( V_9 -> V_11 -> V_58 & V_352 )
continue;
V_438 |= V_290 ;
}
F_285 ( V_9 , & V_165 , V_335 , V_438 ) ;
F_239 ( & V_165 , V_335 , V_9 -> V_11 , 0 ,
V_434 ) ;
}
}
}
}
static void F_289 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
struct V_10 * V_445 ;
struct V_13 * V_446 ;
struct V_174 * V_447 ;
F_33 () ;
V_9 = F_56 ( V_11 ) ;
if ( ! V_9 ) {
F_107 ( L_20 , V_55 ) ;
return;
}
F_285 ( V_9 , & V_448 , 128 , V_290 ) ;
F_96 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_445 -> V_56 , V_11 -> V_56 ) )
continue;
V_9 = F_57 ( V_445 ) ;
if ( ! V_9 )
continue;
F_181 ( & V_9 -> V_40 ) ;
F_92 (sp_ifa, &idev->addr_list, if_list) {
if ( V_446 -> V_58 & ( V_294 | V_149 ) )
continue;
if ( V_446 -> V_6 ) {
if ( ! F_85 ( & V_446 -> V_6 -> V_449 ) ) {
F_111 ( V_446 -> V_6 ) ;
V_446 -> V_6 = NULL ;
} else {
continue;
}
}
V_447 = F_126 ( V_9 , & V_446 -> V_165 , false ) ;
if ( ! F_58 ( V_447 ) ) {
V_446 -> V_6 = V_447 ;
F_290 ( V_447 ) ;
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
V_432 , V_432 ) ;
if ( ! F_58 ( V_14 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_9 -> V_11 , 0 , 0 ) ;
F_167 ( V_14 ) ;
F_154 ( V_14 ) ;
}
}
static bool F_292 ( struct V_167 V_450 )
{
if ( ( V_450 . V_406 [ 2 ] | V_450 . V_406 [ 3 ] ) == 0 )
return true ;
if ( V_450 . V_406 [ 2 ] == F_247 ( 0x02005eff ) &&
( ( V_450 . V_406 [ 3 ] & F_247 ( 0xfe000000 ) ) == F_247 ( 0xfe000000 ) ) )
return true ;
if ( V_450 . V_406 [ 2 ] == F_247 ( 0xfdffffff ) &&
( ( V_450 . V_406 [ 3 ] & F_247 ( 0xffffff80 ) ) == F_247 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_208 ( struct V_167 * V_450 ,
T_5 V_451 ,
const struct V_8 * V_9 )
{
static F_293 ( V_40 ) ;
static V_233 V_452 [ V_453 ] ;
static V_233 V_454 [ V_455 ] ;
static union {
char V_456 [ V_457 ] ;
struct {
struct V_167 V_458 ;
T_6 V_379 [ 2 ] ;
unsigned char V_459 [ V_460 ] ;
T_5 V_451 ;
} V_461 ;
} V_462 ;
struct V_167 V_458 ;
struct V_167 V_463 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
F_294 ( sizeof( V_462 . V_456 ) != sizeof( V_462 ) ) ;
if ( V_9 -> V_43 . V_45 . V_46 )
V_458 = V_9 -> V_43 . V_45 . V_458 ;
else if ( V_113 -> V_22 . V_44 -> V_45 . V_46 )
V_458 = V_113 -> V_22 . V_44 -> V_45 . V_458 ;
else
return - 1 ;
V_226:
F_149 ( & V_40 ) ;
F_295 ( V_452 ) ;
memset ( & V_462 , 0 , sizeof( V_462 ) ) ;
memset ( V_454 , 0 , sizeof( V_454 ) ) ;
memcpy ( V_462 . V_459 , V_9 -> V_11 -> V_324 , V_9 -> V_11 -> V_314 ) ;
V_462 . V_379 [ 0 ] = V_450 -> V_406 [ 0 ] ;
V_462 . V_379 [ 1 ] = V_450 -> V_406 [ 1 ] ;
V_462 . V_458 = V_458 ;
V_462 . V_451 = V_451 ;
F_296 ( V_452 , V_462 . V_456 , V_454 ) ;
V_463 = * V_450 ;
V_463 . V_406 [ 2 ] = ( V_414 T_6 ) V_452 [ 0 ] ;
V_463 . V_406 [ 3 ] = ( V_414 T_6 ) V_452 [ 1 ] ;
F_150 ( & V_40 ) ;
if ( F_292 ( V_463 ) ) {
V_451 ++ ;
if ( V_451 > F_38 ( V_9 -> V_11 ) -> V_22 . V_304 . V_305 )
return - 1 ;
goto V_226;
}
* V_450 = V_463 ;
return 0 ;
}
static void F_297 ( struct V_8 * V_9 )
{
struct V_464 * V_465 = & V_9 -> V_43 . V_45 ;
if ( V_465 -> V_46 )
return;
V_465 = & V_9 -> V_43 . V_45 ;
F_165 ( & V_465 -> V_458 , sizeof( V_465 -> V_458 ) ) ;
V_465 -> V_46 = true ;
}
static void F_298 ( struct V_8 * V_9 , bool V_466 )
{
struct V_167 V_165 ;
if ( F_249 ( V_9 -> V_11 ) )
return;
F_246 ( & V_165 , F_247 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_9 -> V_43 . V_47 ) {
case V_368 :
F_297 ( V_9 ) ;
case V_48 :
if ( ! F_208 ( & V_165 , 0 , V_9 ) )
F_291 ( V_9 , & V_165 ,
V_298 ) ;
else if ( V_466 )
F_239 ( & V_165 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_467 :
if ( F_236 ( V_165 . V_225 + 8 , V_9 -> V_11 ) == 0 )
F_291 ( V_9 , & V_165 , 0 ) ;
else if ( V_466 )
F_239 ( & V_165 , 64 , V_9 -> V_11 , 0 , 0 ) ;
break;
case V_468 :
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
( V_11 -> type != V_332 ) &&
( V_11 -> type != V_329 ) &&
( V_11 -> type != V_70 ) &&
( V_11 -> type != V_72 ) ) {
return;
}
V_9 = F_248 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return;
if ( V_11 -> type == V_72 &&
V_9 -> V_43 . V_47 == V_467 )
V_9 -> V_43 . V_47 = V_368 ;
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
if ( V_11 -> V_58 & V_352 )
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
if ( V_11 -> V_58 & V_352 )
F_245 ( V_11 ) ;
}
static int F_302 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_6 || ! F_85 ( & V_14 -> V_6 -> V_449 ) ) {
struct V_174 * V_6 , * V_469 ;
V_6 = F_126 ( V_9 , & V_14 -> V_165 , false ) ;
if ( F_164 ( F_58 ( V_6 ) ) )
return F_127 ( V_6 ) ;
F_124 ( & V_14 -> V_40 ) ;
V_469 = V_14 -> V_6 ;
V_14 -> V_6 = V_6 ;
F_133 ( & V_14 -> V_40 ) ;
F_111 ( V_469 ) ;
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
static int F_305 ( struct V_470 * V_471 , unsigned long V_101 ,
void * V_472 )
{
struct V_10 * V_11 = F_306 ( V_472 ) ;
struct V_473 * V_474 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
int V_475 = 0 ;
int V_36 ;
switch ( V_101 ) {
case V_476 :
if ( ! V_9 && V_11 -> V_37 >= V_38 ) {
V_9 = F_32 ( V_11 ) ;
if ( F_58 ( V_9 ) )
return F_307 ( F_127 ( V_9 ) ) ;
}
break;
case V_477 :
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
V_475 = 1 ;
case V_194 :
case V_478 :
if ( V_11 -> V_58 & V_479 )
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
V_475 = 1 ;
}
} else if ( V_101 == V_478 ) {
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
V_475 = 1 ;
}
switch ( V_11 -> type ) {
#if F_46 ( V_62 )
case V_63 :
F_300 ( V_11 ) ;
break;
#endif
#if F_46 ( V_480 )
case V_329 :
F_301 ( V_11 ) ;
break;
#endif
case V_481 :
F_289 ( V_11 ) ;
break;
default:
F_299 ( V_11 ) ;
break;
}
if ( ! F_254 ( V_9 ) ) {
if ( V_475 )
F_310 ( V_9 ) ;
if ( V_9 -> V_43 . V_50 != V_11 -> V_37 &&
V_11 -> V_37 >= V_38 ) {
F_309 ( V_11 , V_11 -> V_37 ) ;
V_9 -> V_43 . V_50 = V_11 -> V_37 ;
}
V_9 -> V_78 = V_17 ;
F_311 ( V_482 , V_9 ) ;
if ( V_11 -> V_37 < V_38 )
F_308 ( V_11 , 1 ) ;
}
break;
case V_211 :
case V_483 :
F_308 ( V_11 , V_101 != V_211 ) ;
break;
case V_484 :
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
case V_485 :
case V_486 :
if ( V_9 )
F_312 ( V_11 , V_101 ) ;
break;
case V_487 :
V_474 = V_472 ;
if ( V_474 -> V_488 && F_249 ( V_474 -> V_488 ) )
F_308 ( V_11 , 0 ) ;
}
return V_489 ;
}
static void F_312 ( struct V_10 * V_11 , unsigned long V_101 )
{
struct V_8 * V_9 ;
F_33 () ;
V_9 = F_57 ( V_11 ) ;
if ( V_101 == V_486 )
F_313 ( V_9 ) ;
else if ( V_101 == V_485 )
F_314 ( V_9 ) ;
}
static bool F_315 ( const struct V_167 * V_165 )
{
return F_122 ( V_165 ) &
( V_380 | V_179 ) ;
}
static int F_308 ( struct V_10 * V_11 , int V_490 )
{
struct V_113 * V_113 = F_38 ( V_11 ) ;
struct V_8 * V_9 ;
struct V_13 * V_146 , * V_5 ;
struct V_163 V_491 ;
int V_492 ;
bool V_493 ;
int V_160 , V_20 ;
F_33 () ;
F_316 ( V_113 , V_11 ) ;
F_317 ( & V_52 , V_11 ) ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_181 ;
if ( V_490 ) {
V_9 -> V_84 = 1 ;
F_318 ( V_11 -> V_79 , NULL ) ;
F_52 ( V_9 ) ;
}
V_492 = V_113 -> V_22 . V_126 -> V_494 ;
if ( ! V_492 )
V_492 = V_9 -> V_43 . V_494 ;
V_493 = ! ( V_490 || V_492 <= 0 || V_9 -> V_43 . V_183 ) ;
for ( V_20 = 0 ; V_20 < V_495 ; V_20 ++ ) {
struct V_136 * V_132 = & V_191 [ V_20 ] ;
F_149 ( & V_185 ) ;
V_496:
F_86 (ifa, h, addr_lst) {
if ( V_146 -> V_9 == V_9 ) {
F_13 ( V_146 ) ;
if ( ! V_493 ||
! ( V_146 -> V_58 & V_200 ) ||
F_315 ( & V_146 -> V_165 ) ) {
F_151 ( & V_146 -> V_159 ) ;
goto V_496;
}
}
}
F_150 ( & V_185 ) ;
}
F_152 ( & V_9 -> V_40 ) ;
F_10 ( V_9 ) ;
if ( ! V_490 )
V_9 -> V_76 &= ~ ( V_497 | V_498 | V_77 ) ;
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
V_493 = ( ! V_490 && V_492 > 0 && ! V_9 -> V_43 . V_183 ) ;
F_36 ( & V_491 ) ;
F_304 (ifa, tmp, &idev->addr_list, if_list) {
struct V_174 * V_6 = NULL ;
bool V_499 ;
F_13 ( V_146 ) ;
V_499 = V_493 && ( V_146 -> V_58 & V_200 ) &&
! F_315 ( & V_146 -> V_165 ) ;
if ( ! V_499 )
F_320 ( & V_146 -> V_166 , & V_491 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_149 ( & V_146 -> V_40 ) ;
if ( V_499 ) {
V_160 = V_161 ;
V_146 -> V_160 = 0 ;
if ( ! ( V_146 -> V_58 & V_500 ) )
V_146 -> V_58 |= V_149 ;
V_6 = V_146 -> V_6 ;
V_146 -> V_6 = NULL ;
} else {
V_160 = V_146 -> V_160 ;
V_146 -> V_160 = V_161 ;
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
while ( ! F_251 ( & V_491 ) ) {
V_146 = F_319 ( & V_491 ,
struct V_13 , V_166 ) ;
F_153 ( & V_146 -> V_166 ) ;
F_154 ( V_146 ) ;
}
if ( V_490 ) {
F_322 ( V_9 ) ;
F_51 ( V_9 ) ;
} else {
F_323 ( V_9 ) ;
}
V_9 -> V_78 = V_17 ;
if ( V_490 ) {
F_7 ( V_9 ) ;
F_43 ( & V_52 , V_9 -> V_51 ) ;
F_317 ( & V_52 , V_11 ) ;
F_108 ( V_9 ) ;
}
return 0 ;
}
static void V_42 ( unsigned long V_462 )
{
struct V_8 * V_9 = (struct V_8 * ) V_462 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_167 V_501 ;
F_134 ( & V_9 -> V_40 ) ;
if ( V_9 -> V_84 || ! ( V_9 -> V_76 & V_77 ) )
goto V_187;
if ( ! F_324 ( V_9 ) )
goto V_187;
if ( V_9 -> V_76 & V_498 )
goto V_187;
if ( V_9 -> V_502 ++ < V_9 -> V_43 . V_66 || V_9 -> V_43 . V_66 < 0 ) {
F_136 ( & V_9 -> V_40 ) ;
if ( ! F_194 ( V_11 , & V_501 , V_149 ) )
F_325 ( V_11 , & V_501 ,
& V_83 ) ;
else
goto V_390;
F_134 ( & V_9 -> V_40 ) ;
V_9 -> V_503 = F_5 (
V_9 -> V_503 , V_9 -> V_43 . V_504 ) ;
F_16 ( V_9 , ( V_9 -> V_502 ==
V_9 -> V_43 . V_66 ) ?
V_9 -> V_43 . V_505 :
V_9 -> V_503 ) ;
} else {
F_107 ( L_24 , V_9 -> V_11 -> V_56 ) ;
}
V_187:
F_136 ( & V_9 -> V_40 ) ;
V_390:
F_108 ( V_9 ) ;
}
static void F_326 ( struct V_13 * V_14 )
{
unsigned long V_506 ;
struct V_8 * V_9 = V_14 -> V_9 ;
T_3 V_507 ;
if ( V_14 -> V_58 & V_236 )
V_506 = 0 ;
else
V_506 = F_3 () % ( V_9 -> V_43 . V_505 ? : 1 ) ;
V_507 = 0 ;
if ( V_9 -> V_43 . V_508 ||
F_38 ( V_9 -> V_11 ) -> V_22 . V_126 -> V_508 ) {
do
F_165 ( & V_507 , 6 ) ;
while ( V_507 == 0 );
}
V_14 -> V_509 = V_507 ;
V_14 -> V_510 = V_9 -> V_43 . V_230 ;
F_20 ( V_14 , V_506 ) ;
}
static void F_327 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_511 , V_512 = false ;
F_209 ( V_11 , & V_14 -> V_165 ) ;
F_328 ( ( V_414 T_1 ) V_14 -> V_165 . V_406 [ 3 ] ) ;
F_181 ( & V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_161 )
goto V_187;
if ( V_11 -> V_58 & ( V_59 | V_60 ) ||
V_9 -> V_43 . V_61 < 1 ||
! ( V_14 -> V_58 & V_149 ) ||
V_14 -> V_58 & V_500 ) {
V_511 = V_14 -> V_58 & V_149 ;
V_14 -> V_58 &= ~ ( V_149 | V_236 | V_294 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_186 ( & V_9 -> V_40 ) ;
F_329 ( V_14 , V_511 ) ;
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
V_512 = true ;
}
}
F_326 ( V_14 ) ;
V_187:
F_133 ( & V_14 -> V_40 ) ;
F_186 ( & V_9 -> V_40 ) ;
if ( V_512 )
F_157 ( V_433 , V_14 ) ;
}
static void F_167 ( struct V_13 * V_14 )
{
bool V_513 = false ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 != V_161 ) {
V_14 -> V_160 = V_309 ;
V_513 = true ;
}
F_150 ( & V_14 -> V_40 ) ;
if ( V_513 )
F_20 ( V_14 , 0 ) ;
}
static void V_188 ( struct V_514 * V_515 )
{
struct V_13 * V_14 = F_330 ( F_331 ( V_515 ) ,
struct V_13 ,
V_15 ) ;
struct V_8 * V_9 = V_14 -> V_9 ;
bool V_511 , V_183 = false ;
struct V_167 V_516 ;
enum {
V_517 ,
V_518 ,
V_519 ,
} V_198 = V_517 ;
F_267 () ;
F_149 ( & V_14 -> V_40 ) ;
if ( V_14 -> V_160 == V_309 ) {
V_198 = V_518 ;
V_14 -> V_160 = V_296 ;
} else if ( V_14 -> V_160 == V_311 ) {
V_198 = V_519 ;
V_14 -> V_160 = V_297 ;
if ( V_9 -> V_43 . V_61 > 1 && ! V_9 -> V_43 . V_183 &&
! ( V_14 -> V_58 & V_298 ) ) {
struct V_167 V_165 ;
V_165 . V_406 [ 0 ] = F_247 ( 0xfe800000 ) ;
V_165 . V_406 [ 1 ] = 0 ;
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
if ( V_198 == V_518 ) {
F_327 ( V_14 ) ;
goto V_187;
} else if ( V_198 == V_519 ) {
F_22 ( V_14 ) ;
F_204 ( V_14 , 1 ) ;
if ( V_183 )
F_308 ( V_9 -> V_11 , 0 ) ;
goto V_187;
}
if ( ! V_14 -> V_510 && F_205 ( V_14 ) )
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
if ( V_14 -> V_510 == 0 ) {
V_511 = V_14 -> V_58 & V_149 ;
V_14 -> V_58 &= ~ ( V_149 | V_236 | V_294 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_329 ( V_14 , V_511 ) ;
goto V_187;
}
V_14 -> V_510 -- ;
F_20 ( V_14 ,
F_161 ( V_14 -> V_9 -> V_51 , V_231 ) ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_9 -> V_40 ) ;
F_210 ( & V_14 -> V_165 , & V_516 ) ;
F_332 ( V_14 -> V_9 -> V_11 , & V_14 -> V_165 , & V_516 , & V_75 ,
V_14 -> V_509 ) ;
V_187:
F_154 ( V_14 ) ;
F_100 () ;
}
static bool F_333 ( struct V_13 * V_14 )
{
struct V_13 * V_520 ;
struct V_8 * V_9 = V_14 -> V_9 ;
F_193 (ifpiter, &idev->addr_list, if_list) {
if ( V_520 -> V_171 > V_286 )
break;
if ( V_14 != V_520 && V_520 -> V_171 == V_286 &&
( V_520 -> V_58 & ( V_200 | V_149 |
V_236 | V_294 ) ) ==
V_200 )
return false ;
}
return true ;
}
static void F_329 ( struct V_13 * V_14 , bool V_511 )
{
struct V_10 * V_11 = V_14 -> V_9 -> V_11 ;
struct V_167 V_501 ;
bool V_521 , V_522 ;
F_13 ( V_14 ) ;
F_157 ( V_433 , V_14 ) ;
F_181 ( & V_14 -> V_9 -> V_40 ) ;
V_522 = V_14 -> V_171 == V_286 && F_333 ( V_14 ) ;
V_521 = V_522 &&
F_324 ( V_14 -> V_9 ) &&
V_14 -> V_9 -> V_43 . V_66 != 0 &&
( V_11 -> V_58 & V_60 ) == 0 ;
F_186 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_522 )
F_334 ( V_14 -> V_9 ) ;
if ( V_521 ) {
if ( F_194 ( V_11 , & V_501 , V_149 ) )
return;
F_325 ( V_11 , & V_501 , & V_83 ) ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
F_124 ( & V_14 -> V_40 ) ;
V_14 -> V_9 -> V_503 = F_2 (
V_14 -> V_9 -> V_43 . V_523 ) ;
V_14 -> V_9 -> V_502 = 1 ;
V_14 -> V_9 -> V_76 |= V_497 ;
F_16 ( V_14 -> V_9 , V_14 -> V_9 -> V_503 ) ;
F_133 ( & V_14 -> V_40 ) ;
F_156 ( & V_14 -> V_9 -> V_40 ) ;
}
if ( V_511 )
F_286 ( F_38 ( V_11 ) ) ;
if ( V_14 -> V_58 & V_192 )
F_279 () ;
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
static struct V_13 * F_335 ( struct V_524 * V_100 , T_10 V_525 )
{
struct V_13 * V_146 = NULL ;
struct V_526 * V_160 = V_100 -> V_527 ;
struct V_113 * V_113 = F_336 ( V_100 ) ;
int V_154 = 0 ;
if ( V_525 == 0 ) {
V_160 -> V_528 = 0 ;
V_160 -> V_529 = 0 ;
}
for (; V_160 -> V_528 < V_495 ; ++ V_160 -> V_528 ) {
F_203 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
if ( V_154 < V_160 -> V_529 ) {
V_154 ++ ;
continue;
}
V_160 -> V_529 ++ ;
return V_146 ;
}
V_160 -> V_529 = 0 ;
V_154 = 0 ;
}
return NULL ;
}
static struct V_13 * F_337 ( struct V_524 * V_100 ,
struct V_13 * V_146 )
{
struct V_526 * V_160 = V_100 -> V_527 ;
struct V_113 * V_113 = F_336 ( V_100 ) ;
F_338 (ifa, addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
V_160 -> V_529 ++ ;
return V_146 ;
}
while ( ++ V_160 -> V_528 < V_495 ) {
V_160 -> V_529 = 0 ;
F_203 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_198 ( F_38 ( V_146 -> V_9 -> V_11 ) , V_113 ) )
continue;
V_160 -> V_529 ++ ;
return V_146 ;
}
}
return NULL ;
}
static void * F_339 ( struct V_524 * V_100 , T_10 * V_525 )
__acquires( T_11 )
{
F_123 () ;
return F_335 ( V_100 , * V_525 ) ;
}
static void * F_340 ( struct V_524 * V_100 , void * V_530 , T_10 * V_525 )
{
struct V_13 * V_146 ;
V_146 = F_337 ( V_100 , V_530 ) ;
++ * V_525 ;
return V_146 ;
}
static void F_341 ( struct V_524 * V_100 , void * V_530 )
__releases( T_11 )
{
F_137 () ;
}
static int F_342 ( struct V_524 * V_100 , void * V_530 )
{
struct V_13 * V_14 = (struct V_13 * ) V_530 ;
F_343 ( V_100 , L_26 ,
& V_14 -> V_165 ,
V_14 -> V_9 -> V_11 -> V_96 ,
V_14 -> V_189 ,
V_14 -> V_171 ,
( T_5 ) V_14 -> V_58 ,
V_14 -> V_9 -> V_11 -> V_56 ) ;
return 0 ;
}
static int F_344 ( struct V_531 * V_531 , struct V_532 * V_532 )
{
return F_345 ( V_531 , V_532 , & V_533 ,
sizeof( struct V_526 ) ) ;
}
static int T_12 F_346 ( struct V_113 * V_113 )
{
if ( ! F_347 ( L_27 , V_534 , V_113 -> V_535 , & V_536 ) )
return - V_34 ;
return 0 ;
}
static void T_13 F_348 ( struct V_113 * V_113 )
{
F_349 ( L_27 , V_113 -> V_535 ) ;
}
int T_14 F_350 ( void )
{
return F_351 ( & V_537 ) ;
}
void F_352 ( void )
{
F_353 ( & V_537 ) ;
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
unsigned long V_222 , V_538 , V_539 , V_540 ;
struct V_13 * V_14 ;
int V_20 ;
F_33 () ;
F_123 () ;
V_222 = V_17 ;
V_538 = F_355 ( V_222 + V_541 ) ;
F_14 ( & V_542 ) ;
for ( V_20 = 0 ; V_20 < V_495 ; V_20 ++ ) {
V_496:
F_203 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_217 ;
if ( ( V_14 -> V_58 & V_200 ) &&
( V_14 -> V_173 == V_432 ) )
continue;
F_124 ( & V_14 -> V_40 ) ;
V_217 = ( V_222 - V_14 -> V_78 + V_235 ) / V_3 ;
if ( V_14 -> V_172 != V_432 &&
V_217 >= V_14 -> V_172 ) {
F_133 ( & V_14 -> V_40 ) ;
F_22 ( V_14 ) ;
F_148 ( V_14 ) ;
goto V_496;
} else if ( V_14 -> V_173 == V_432 ) {
F_133 ( & V_14 -> V_40 ) ;
continue;
} else if ( V_217 >= V_14 -> V_173 ) {
int V_543 = 0 ;
if ( ! ( V_14 -> V_58 & V_255 ) ) {
V_543 = 1 ;
V_14 -> V_58 |= V_255 ;
}
if ( ( V_14 -> V_172 != V_432 ) &&
( F_143 ( V_14 -> V_78 + V_14 -> V_172 * V_3 , V_538 ) ) )
V_538 = V_14 -> V_78 + V_14 -> V_172 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
if ( V_543 ) {
F_22 ( V_14 ) ;
F_157 ( 0 , V_14 ) ;
F_154 ( V_14 ) ;
goto V_496;
}
} else if ( ( V_14 -> V_58 & V_192 ) &&
! ( V_14 -> V_58 & V_149 ) ) {
unsigned long V_218 = V_14 -> V_9 -> V_43 . V_228 *
V_14 -> V_9 -> V_43 . V_230 *
F_161 ( V_14 -> V_9 -> V_51 , V_231 ) / V_3 ;
if ( V_217 >= V_14 -> V_173 - V_218 ) {
struct V_13 * V_209 = V_14 -> V_209 ;
if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 , V_538 ) )
V_538 = V_14 -> V_78 + V_14 -> V_173 * V_3 ;
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
goto V_496;
}
} else if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 - V_218 * V_3 , V_538 ) )
V_538 = V_14 -> V_78 + V_14 -> V_173 * V_3 - V_218 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
} else {
if ( F_143 ( V_14 -> V_78 + V_14 -> V_173 * V_3 , V_538 ) )
V_538 = V_14 -> V_78 + V_14 -> V_173 * V_3 ;
F_133 ( & V_14 -> V_40 ) ;
}
}
}
V_539 = F_355 ( V_538 ) ;
V_540 = V_538 ;
if ( F_143 ( V_539 , V_538 + V_544 ) )
V_540 = V_539 ;
if ( F_143 ( V_540 , V_17 + V_545 ) )
V_540 = V_17 + V_545 ;
F_42 ( V_546 L_28 ,
V_222 , V_538 , V_539 , V_540 ) ;
F_23 ( V_19 , & V_542 , V_540 - V_222 ) ;
F_137 () ;
}
static void F_356 ( struct V_514 * V_515 )
{
F_267 () ;
F_279 () ;
F_100 () ;
}
static void F_256 ( void )
{
F_23 ( V_19 , & V_542 , 0 ) ;
}
static struct V_167 * F_357 ( struct V_120 * V_165 , struct V_120 * V_547 ,
struct V_167 * * V_422 )
{
struct V_167 * V_334 = NULL ;
* V_422 = NULL ;
if ( V_165 )
V_334 = F_358 ( V_165 ) ;
if ( V_547 ) {
if ( V_334 && F_359 ( V_547 , V_334 , sizeof( * V_334 ) ) )
* V_422 = V_334 ;
V_334 = F_358 ( V_547 ) ;
}
return V_334 ;
}
static int
F_360 ( struct V_94 * V_95 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
struct V_548 * V_549 ;
struct V_120 * V_121 [ V_550 + 1 ] ;
struct V_167 * V_334 , * V_422 ;
T_1 V_423 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_549 ) , V_121 , V_550 , V_551 ) ;
if ( V_36 < 0 )
return V_36 ;
V_549 = F_66 ( V_103 ) ;
V_334 = F_357 ( V_121 [ V_552 ] , V_121 [ V_553 ] , & V_422 ) ;
if ( ! V_334 )
return - V_39 ;
V_423 = V_121 [ V_554 ] ? F_361 ( V_121 [ V_554 ] ) : V_549 -> V_423 ;
V_423 &= V_374 ;
return F_280 ( V_113 , V_549 -> V_555 , V_423 , V_334 ,
V_549 -> V_556 ) ;
}
static int F_362 ( struct V_13 * V_14 , T_1 V_423 ,
T_1 V_173 , T_1 V_172 )
{
T_1 V_58 ;
T_7 V_196 ;
unsigned long V_424 ;
bool V_557 ;
bool V_558 ;
F_33 () ;
if ( ! V_172 || ( V_173 > V_172 ) )
return - V_39 ;
if ( V_423 & V_374 &&
( V_14 -> V_58 & V_192 || V_14 -> V_189 != 64 ) )
return - V_39 ;
V_424 = F_142 ( V_172 , V_3 ) ;
if ( F_261 ( V_424 ) ) {
V_196 = F_263 ( V_424 * V_3 ) ;
V_172 = V_424 ;
V_58 = V_208 ;
} else {
V_196 = 0 ;
V_58 = 0 ;
V_423 |= V_200 ;
}
V_424 = F_142 ( V_173 , V_3 ) ;
if ( F_261 ( V_424 ) ) {
if ( V_424 == 0 )
V_423 |= V_255 ;
V_173 = V_424 ;
}
F_149 ( & V_14 -> V_40 ) ;
V_557 = V_14 -> V_58 & V_374 ;
V_558 = V_14 -> V_58 & V_200 &&
! ( V_14 -> V_58 & V_201 ) ;
V_14 -> V_58 &= ~ ( V_255 | V_200 | V_500 |
V_260 | V_374 |
V_201 ) ;
V_14 -> V_58 |= V_423 ;
V_14 -> V_78 = V_17 ;
V_14 -> V_172 = V_172 ;
V_14 -> V_173 = V_173 ;
F_150 ( & V_14 -> V_40 ) ;
if ( ! ( V_14 -> V_58 & V_149 ) )
F_157 ( 0 , V_14 ) ;
if ( ! ( V_423 & V_201 ) ) {
F_239 ( & V_14 -> V_165 , V_14 -> V_189 , V_14 -> V_9 -> V_11 ,
V_196 , V_58 ) ;
} else if ( V_558 ) {
enum V_195 V_198 ;
unsigned long V_383 ;
F_152 ( & V_14 -> V_9 -> V_40 ) ;
V_198 = F_140 ( V_14 , & V_383 ) ;
F_156 ( & V_14 -> V_9 -> V_40 ) ;
if ( V_198 != V_202 ) {
F_144 ( V_14 , V_383 ,
V_198 == V_199 ) ;
}
}
if ( V_557 || V_14 -> V_58 & V_374 ) {
if ( V_557 && ! ( V_14 -> V_58 & V_374 ) )
V_172 = V_173 = 0 ;
F_250 ( V_14 -> V_9 , V_14 , V_172 , V_173 ,
! V_557 , V_17 ) ;
}
F_279 () ;
return 0 ;
}
static int
F_363 ( struct V_94 * V_95 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
struct V_548 * V_549 ;
struct V_120 * V_121 [ V_550 + 1 ] ;
struct V_167 * V_334 , * V_422 ;
struct V_13 * V_146 ;
struct V_10 * V_11 ;
T_1 V_172 = V_432 , V_301 = V_432 ;
T_1 V_423 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_549 ) , V_121 , V_550 , V_551 ) ;
if ( V_36 < 0 )
return V_36 ;
V_549 = F_66 ( V_103 ) ;
V_334 = F_357 ( V_121 [ V_552 ] , V_121 [ V_553 ] , & V_422 ) ;
if ( ! V_334 )
return - V_39 ;
if ( V_121 [ V_559 ] ) {
struct V_560 * V_561 ;
V_561 = F_358 ( V_121 [ V_559 ] ) ;
V_172 = V_561 -> V_562 ;
V_301 = V_561 -> V_563 ;
} else {
V_301 = V_432 ;
V_172 = V_432 ;
}
V_11 = F_80 ( V_113 , V_549 -> V_555 ) ;
if ( ! V_11 )
return - V_181 ;
V_423 = V_121 [ V_554 ] ? F_361 ( V_121 [ V_554 ] ) : V_549 -> V_423 ;
V_423 &= V_500 | V_260 | V_374 |
V_201 | V_425 ;
V_146 = F_202 ( V_113 , V_334 , V_11 , 1 ) ;
if ( ! V_146 ) {
return F_278 ( V_113 , V_549 -> V_555 , V_334 , V_422 ,
V_549 -> V_556 , V_423 ,
V_301 , V_172 ) ;
}
if ( V_103 -> V_564 & V_565 ||
! ( V_103 -> V_564 & V_566 ) )
V_36 = - V_186 ;
else
V_36 = F_362 ( V_146 , V_423 , V_301 , V_172 ) ;
F_154 ( V_146 ) ;
return V_36 ;
}
static void F_364 ( struct V_102 * V_103 , T_5 V_567 , T_1 V_58 ,
T_5 V_171 , int V_96 )
{
struct V_548 * V_549 ;
V_549 = F_66 ( V_103 ) ;
V_549 -> V_568 = V_107 ;
V_549 -> V_556 = V_567 ;
V_549 -> V_423 = V_58 ;
V_549 -> V_442 = V_171 ;
V_549 -> V_555 = V_96 ;
}
static int F_365 ( struct V_94 * V_95 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_569 , T_1 V_381 )
{
struct V_560 V_561 ;
V_561 . V_1 = F_1 ( V_1 ) ;
V_561 . V_78 = F_1 ( V_78 ) ;
V_561 . V_563 = V_569 ;
V_561 . V_562 = V_381 ;
return F_366 ( V_95 , V_559 , sizeof( V_561 ) , & V_561 ) ;
}
static inline int F_367 ( int V_442 )
{
if ( V_442 & V_290 )
return V_444 ;
else if ( V_442 & V_286 )
return V_443 ;
else if ( V_442 & V_570 )
return V_571 ;
else
return V_572 ;
}
static inline int F_368 ( void )
{
return F_61 ( sizeof( struct V_548 ) )
+ F_62 ( 16 )
+ F_62 ( 16 )
+ F_62 ( sizeof( struct V_560 ) )
+ F_62 ( 4 ) ;
}
static int F_369 ( struct V_94 * V_95 , struct V_13 * V_146 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_1 V_569 , V_381 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_548 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , V_146 -> V_189 , V_146 -> V_58 , F_367 ( V_146 -> V_171 ) ,
V_146 -> V_9 -> V_11 -> V_96 ) ;
if ( ! ( ( V_146 -> V_58 & V_200 ) &&
( V_146 -> V_173 == V_432 ) ) ) {
V_569 = V_146 -> V_173 ;
V_381 = V_146 -> V_172 ;
if ( V_569 != V_432 ) {
long V_573 = ( V_17 - V_146 -> V_78 ) / V_3 ;
if ( V_569 > V_573 )
V_569 -= V_573 ;
else
V_569 = 0 ;
if ( V_381 != V_432 ) {
if ( V_381 > V_573 )
V_381 -= V_573 ;
else
V_381 = 0 ;
}
}
} else {
V_569 = V_432 ;
V_381 = V_432 ;
}
if ( ! F_214 ( & V_146 -> V_169 ) ) {
if ( F_370 ( V_95 , V_553 , & V_146 -> V_165 ) < 0 ||
F_370 ( V_95 , V_552 , & V_146 -> V_169 ) < 0 )
goto error;
} else
if ( F_370 ( V_95 , V_552 , & V_146 -> V_165 ) < 0 )
goto error;
if ( F_365 ( V_95 , V_146 -> V_1 , V_146 -> V_78 , V_569 , V_381 ) < 0 )
goto error;
if ( F_371 ( V_95 , V_554 , V_146 -> V_58 ) < 0 )
goto error;
F_68 ( V_95 , V_103 ) ;
return 0 ;
error:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_372 ( struct V_94 * V_95 , struct V_574 * V_575 ,
T_1 V_99 , T_1 V_100 , int V_101 , T_15 V_58 )
{
struct V_102 * V_103 ;
T_5 V_171 = V_572 ;
int V_96 = V_575 -> V_9 -> V_11 -> V_96 ;
if ( F_166 ( & V_575 -> V_576 ) & V_570 )
V_171 = V_571 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_548 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , 128 , V_200 , V_171 , V_96 ) ;
if ( F_370 ( V_95 , V_577 , & V_575 -> V_576 ) < 0 ||
F_365 ( V_95 , V_575 -> V_578 , V_575 -> V_579 ,
V_432 , V_432 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_373 ( struct V_94 * V_95 , struct V_580 * V_581 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_102 * V_103 ;
T_5 V_171 = V_572 ;
int V_96 = V_581 -> V_582 -> V_11 -> V_96 ;
if ( F_166 ( & V_581 -> V_583 ) & V_570 )
V_171 = V_571 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( struct V_548 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
F_364 ( V_103 , 128 , V_200 , V_171 , V_96 ) ;
if ( F_370 ( V_95 , V_584 , & V_581 -> V_583 ) < 0 ||
F_365 ( V_95 , V_581 -> V_585 , V_581 -> V_586 ,
V_432 , V_432 ) < 0 ) {
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
F_68 ( V_95 , V_103 ) ;
return 0 ;
}
static int F_374 ( struct V_8 * V_9 , struct V_94 * V_95 ,
struct V_130 * V_131 , enum V_587 type ,
int V_588 , int * V_589 )
{
struct V_574 * V_575 ;
struct V_580 * V_581 ;
int V_36 = 1 ;
int V_590 = * V_589 ;
F_181 ( & V_9 -> V_40 ) ;
switch ( type ) {
case V_591 : {
struct V_13 * V_146 ;
F_92 (ifa, &idev->addr_list, if_list) {
if ( ++ V_590 < V_588 )
continue;
V_36 = F_369 ( V_95 , V_146 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_433 ,
V_143 ) ;
if ( V_36 < 0 )
break;
F_88 ( V_131 , F_89 ( V_95 ) ) ;
}
break;
}
case V_592 :
for ( V_575 = V_9 -> V_593 ; V_575 ;
V_575 = V_575 -> V_538 , V_590 ++ ) {
if ( V_590 < V_588 )
continue;
V_36 = F_372 ( V_95 , V_575 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_594 ,
V_143 ) ;
if ( V_36 < 0 )
break;
}
break;
case V_595 :
for ( V_581 = V_9 -> V_596 ; V_581 ;
V_581 = V_581 -> V_597 , V_590 ++ ) {
if ( V_590 < V_588 )
continue;
V_36 = F_373 ( V_95 , V_581 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_598 ,
V_143 ) ;
if ( V_36 < 0 )
break;
}
break;
default:
break;
}
F_186 ( & V_9 -> V_40 ) ;
* V_589 = V_590 ;
return V_36 ;
}
static int F_375 ( struct V_94 * V_95 , struct V_130 * V_131 ,
enum V_587 type )
{
struct V_113 * V_113 = F_77 ( V_95 -> V_119 ) ;
int V_132 , V_133 ;
int V_134 , V_590 ;
int V_135 , V_588 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_136 * V_137 ;
V_133 = V_131 -> args [ 0 ] ;
V_135 = V_134 = V_131 -> args [ 1 ] ;
V_588 = V_590 = V_131 -> args [ 2 ] ;
F_84 () ;
V_131 -> V_100 = F_85 ( & V_113 -> V_22 . V_140 ) ^ V_113 -> V_141 ;
for ( V_132 = V_133 ; V_132 < V_138 ; V_132 ++ , V_135 = 0 ) {
V_134 = 0 ;
V_137 = & V_113 -> V_139 [ V_132 ] ;
F_86 (dev, head, index_hlist) {
if ( V_134 < V_135 )
goto V_142;
if ( V_132 > V_133 || V_134 > V_135 )
V_588 = 0 ;
V_590 = 0 ;
V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
goto V_142;
if ( F_374 ( V_9 , V_95 , V_131 , type ,
V_588 , & V_590 ) < 0 )
goto V_144;
V_142:
V_134 ++ ;
}
}
V_144:
F_87 () ;
V_131 -> args [ 0 ] = V_132 ;
V_131 -> args [ 1 ] = V_134 ;
V_131 -> args [ 2 ] = V_590 ;
return V_95 -> V_145 ;
}
static int F_376 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_587 type = V_591 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_377 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_587 type = V_592 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_378 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
enum V_587 type = V_595 ;
return F_375 ( V_95 , V_131 , type ) ;
}
static int F_379 ( struct V_94 * V_118 , struct V_102 * V_103 )
{
struct V_113 * V_113 = F_77 ( V_118 -> V_119 ) ;
struct V_548 * V_549 ;
struct V_120 * V_121 [ V_550 + 1 ] ;
struct V_167 * V_165 = NULL , * V_599 ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_146 ;
struct V_94 * V_95 ;
int V_36 ;
V_36 = F_78 ( V_103 , sizeof( * V_549 ) , V_121 , V_550 , V_551 ) ;
if ( V_36 < 0 )
goto V_115;
V_165 = F_357 ( V_121 [ V_552 ] , V_121 [ V_553 ] , & V_599 ) ;
if ( ! V_165 ) {
V_36 = - V_39 ;
goto V_115;
}
V_549 = F_66 ( V_103 ) ;
if ( V_549 -> V_555 )
V_11 = F_80 ( V_113 , V_549 -> V_555 ) ;
V_146 = F_202 ( V_113 , V_165 , V_11 , 1 ) ;
if ( ! V_146 ) {
V_36 = - V_180 ;
goto V_115;
}
V_95 = F_71 ( F_368 () , V_29 ) ;
if ( ! V_95 ) {
V_36 = - V_114 ;
goto V_600;
}
V_36 = F_369 ( V_95 , V_146 , F_81 ( V_118 ) . V_99 ,
V_103 -> V_129 , V_433 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_600;
}
V_36 = F_82 ( V_95 , V_113 , F_81 ( V_118 ) . V_99 ) ;
V_600:
F_154 ( V_146 ) ;
V_115:
return V_36 ;
}
static void F_380 ( int V_101 , struct V_13 * V_146 )
{
struct V_94 * V_95 ;
struct V_113 * V_113 = F_38 ( V_146 -> V_9 -> V_11 ) ;
int V_36 = - V_114 ;
if ( V_146 -> V_58 & V_149 && V_101 == V_210 )
return;
V_95 = F_71 ( F_368 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_369 ( V_95 , V_146 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_601 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_601 , V_36 ) ;
}
static inline void F_381 ( struct V_97 * V_43 ,
T_4 * V_602 , int V_603 )
{
F_382 ( V_603 < ( V_604 * 4 ) ) ;
memset ( V_602 , 0 , V_603 ) ;
V_602 [ V_605 ] = V_43 -> V_53 ;
V_602 [ V_606 ] = V_43 -> V_607 ;
V_602 [ V_608 ] = V_43 -> V_50 ;
V_602 [ V_609 ] = V_43 -> V_610 ;
V_602 [ V_611 ] = V_43 -> V_612 ;
V_602 [ V_613 ] = V_43 -> V_387 ;
V_602 [ V_614 ] = V_43 -> V_230 ;
V_602 [ V_615 ] = V_43 -> V_66 ;
V_602 [ V_616 ] =
F_383 ( V_43 -> V_523 ) ;
V_602 [ V_617 ] =
F_383 ( V_43 -> V_504 ) ;
V_602 [ V_618 ] =
F_383 ( V_43 -> V_505 ) ;
V_602 [ V_619 ] = V_43 -> V_620 ;
V_602 [ V_621 ] =
F_383 ( V_43 -> V_622 ) ;
V_602 [ V_623 ] =
F_383 ( V_43 -> V_624 ) ;
V_602 [ V_625 ] = V_43 -> V_73 ;
V_602 [ V_626 ] = V_43 -> V_234 ;
V_602 [ V_627 ] = V_43 -> V_232 ;
V_602 [ V_628 ] = V_43 -> V_228 ;
V_602 [ V_629 ] = V_43 -> V_223 ;
V_602 [ V_630 ] = V_43 -> V_307 ;
V_602 [ V_631 ] = V_43 -> V_632 ;
V_602 [ V_633 ] = V_43 -> V_634 ;
V_602 [ V_635 ] = V_43 -> V_636 ;
#ifdef F_384
V_602 [ V_637 ] = V_43 -> V_638 ;
V_602 [ V_639 ] =
F_383 ( V_43 -> V_640 ) ;
#ifdef F_385
V_602 [ V_641 ] = V_43 -> V_642 ;
#endif
#endif
V_602 [ V_643 ] = V_43 -> V_111 ;
V_602 [ V_644 ] = V_43 -> V_645 ;
#ifdef F_170
V_602 [ V_646 ] = V_43 -> V_239 ;
V_602 [ V_647 ] = V_43 -> V_240 ;
#endif
#ifdef F_63
V_602 [ V_648 ] = V_43 -> V_110 ;
#endif
V_602 [ V_649 ] = V_43 -> V_183 ;
V_602 [ V_650 ] = V_43 -> V_61 ;
V_602 [ V_651 ] = V_43 -> V_652 ;
V_602 [ V_653 ] = V_43 -> V_654 ;
V_602 [ V_655 ] = V_43 -> V_656 ;
V_602 [ V_657 ] = V_43 -> V_658 ;
V_602 [ V_659 ] = V_43 -> V_660 ;
V_602 [ V_661 ] = V_43 -> V_112 ;
V_602 [ V_662 ] = V_43 -> V_283 ;
V_602 [ V_663 ] = V_43 -> V_664 ;
V_602 [ V_665 ] = V_43 -> V_666 ;
V_602 [ V_667 ] = V_43 -> V_494 ;
V_602 [ V_668 ] = V_43 -> V_669 ;
#ifdef F_386
V_602 [ V_670 ] = V_43 -> V_671 ;
#endif
V_602 [ V_672 ] = V_43 -> V_508 ;
V_602 [ V_673 ] = V_43 -> V_47 ;
}
static inline T_16 F_387 ( void )
{
return F_62 ( 4 )
+ F_62 ( sizeof( struct V_674 ) )
+ F_62 ( V_604 * 4 )
+ F_62 ( V_675 * 8 )
+ F_62 ( V_676 * 8 )
+ F_62 ( sizeof( struct V_167 ) ) ;
}
static inline T_16 F_388 ( void )
{
return F_61 ( sizeof( struct V_677 ) )
+ F_62 ( V_678 )
+ F_62 ( V_460 )
+ F_62 ( 4 )
+ F_62 ( 4 )
+ F_62 ( 1 )
+ F_62 ( F_387 () ) ;
}
static inline void F_389 ( T_3 * V_21 , T_17 * V_679 ,
int V_603 )
{
int V_20 ;
int V_680 = V_603 - sizeof( T_3 ) * V_676 ;
F_382 ( V_680 < 0 ) ;
F_390 ( V_676 , & V_21 [ 0 ] ) ;
for ( V_20 = 1 ; V_20 < V_676 ; V_20 ++ )
F_390 ( F_391 ( & V_679 [ V_20 ] ) , & V_21 [ V_20 ] ) ;
memset ( & V_21 [ V_676 ] , 0 , V_680 ) ;
}
static inline void F_392 ( T_3 * V_21 , void T_18 * V_679 ,
int V_603 , T_16 V_681 )
{
int V_20 , V_682 ;
T_3 V_683 [ V_675 ] ;
int V_680 = V_603 - sizeof( T_3 ) * V_675 ;
F_382 ( V_680 < 0 ) ;
memset ( V_683 , 0 , sizeof( V_683 ) ) ;
V_683 [ 0 ] = V_675 ;
F_26 (c) {
for ( V_20 = 1 ; V_20 < V_675 ; V_20 ++ )
V_683 [ V_20 ] += F_393 ( V_679 , V_682 , V_20 , V_681 ) ;
}
memcpy ( V_21 , V_683 , V_675 * sizeof( T_3 ) ) ;
memset ( & V_21 [ V_675 ] , 0 , V_680 ) ;
}
static void F_394 ( T_3 * V_21 , struct V_8 * V_9 , int V_684 ,
int V_603 )
{
switch ( V_684 ) {
case V_685 :
F_392 ( V_21 , V_9 -> V_21 . V_22 , V_603 ,
F_395 ( struct V_23 , V_26 ) ) ;
break;
case V_686 :
F_389 ( V_21 , V_9 -> V_21 . V_27 -> V_687 , V_603 ) ;
break;
}
}
static int F_396 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_688 )
{
struct V_120 * V_689 ;
struct V_674 V_561 ;
if ( F_371 ( V_95 , V_690 , V_9 -> V_76 ) )
goto V_109;
V_561 . V_691 = V_692 ;
V_561 . V_78 = F_1 ( V_9 -> V_78 ) ;
V_561 . V_693 = F_383 ( V_9 -> V_51 -> V_693 ) ;
V_561 . V_694 = F_383 ( F_161 ( V_9 -> V_51 , V_231 ) ) ;
if ( F_366 ( V_95 , V_695 , sizeof( V_561 ) , & V_561 ) )
goto V_109;
V_689 = F_397 ( V_95 , V_696 , V_604 * sizeof( T_2 ) ) ;
if ( ! V_689 )
goto V_109;
F_381 ( & V_9 -> V_43 , F_358 ( V_689 ) , F_398 ( V_689 ) ) ;
if ( V_688 & V_697 )
return 0 ;
V_689 = F_397 ( V_95 , V_685 , V_675 * sizeof( T_3 ) ) ;
if ( ! V_689 )
goto V_109;
F_394 ( F_358 ( V_689 ) , V_9 , V_685 , F_398 ( V_689 ) ) ;
V_689 = F_397 ( V_95 , V_686 , V_676 * sizeof( T_3 ) ) ;
if ( ! V_689 )
goto V_109;
F_394 ( F_358 ( V_689 ) , V_9 , V_686 , F_398 ( V_689 ) ) ;
V_689 = F_397 ( V_95 , V_698 , sizeof( struct V_167 ) ) ;
if ( ! V_689 )
goto V_109;
if ( F_399 ( V_95 , V_699 , V_9 -> V_43 . V_47 ) )
goto V_109;
F_181 ( & V_9 -> V_40 ) ;
memcpy ( F_358 ( V_689 ) , V_9 -> V_74 . V_225 , F_398 ( V_689 ) ) ;
F_186 ( & V_9 -> V_40 ) ;
return 0 ;
V_109:
return - V_105 ;
}
static T_16 F_400 ( const struct V_10 * V_11 ,
T_1 V_688 )
{
if ( ! F_57 ( V_11 ) )
return 0 ;
return F_387 () ;
}
static int F_401 ( struct V_94 * V_95 , const struct V_10 * V_11 ,
T_1 V_688 )
{
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( ! V_9 )
return - V_700 ;
if ( F_396 ( V_95 , V_9 , V_688 ) < 0 )
return - V_105 ;
return 0 ;
}
static int F_402 ( struct V_8 * V_9 , struct V_167 * V_74 )
{
struct V_13 * V_14 ;
struct V_10 * V_11 = V_9 -> V_11 ;
bool V_701 , V_702 = false ;
struct V_167 V_703 ;
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
V_701 = F_214 ( V_74 ) ;
if ( V_701 )
goto V_372;
if ( ! V_9 -> V_84 && ( V_9 -> V_76 & V_77 ) &&
! F_194 ( V_11 , & V_703 , V_149 |
V_236 ) ) {
F_325 ( V_11 , & V_703 , & V_83 ) ;
V_702 = true ;
}
V_372:
F_152 ( & V_9 -> V_40 ) ;
if ( V_702 ) {
V_9 -> V_76 |= V_497 ;
V_9 -> V_503 = F_2 (
V_9 -> V_43 . V_523 ) ;
V_9 -> V_502 = 1 ;
F_16 ( V_9 , V_9 -> V_503 ) ;
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
F_311 ( V_482 , V_9 ) ;
F_279 () ;
return 0 ;
}
static int F_403 ( const struct V_10 * V_11 ,
const struct V_120 * V_689 )
{
struct V_120 * V_121 [ V_704 + 1 ] ;
if ( V_11 && ! F_57 ( V_11 ) )
return - V_705 ;
return F_404 ( V_121 , V_704 , V_689 , V_706 ) ;
}
static int F_405 ( int V_707 )
{
if ( V_707 != V_467 &&
V_707 != V_468 &&
V_707 != V_48 &&
V_707 != V_368 )
return - V_39 ;
return 1 ;
}
static int F_406 ( struct V_8 * V_9 , struct V_113 * V_113 ,
int V_707 )
{
if ( V_707 == V_48 &&
! V_9 -> V_43 . V_45 . V_46 &&
! V_113 -> V_22 . V_44 -> V_45 . V_46 )
return - V_39 ;
return 1 ;
}
static int F_407 ( struct V_10 * V_11 , const struct V_120 * V_689 )
{
int V_36 = - V_39 ;
struct V_8 * V_9 = F_57 ( V_11 ) ;
struct V_120 * V_121 [ V_704 + 1 ] ;
if ( ! V_9 )
return - V_705 ;
if ( F_404 ( V_121 , V_704 , V_689 , NULL ) < 0 )
F_408 () ;
if ( V_121 [ V_698 ] ) {
V_36 = F_402 ( V_9 , F_358 ( V_121 [ V_698 ] ) ) ;
if ( V_36 )
return V_36 ;
}
if ( V_121 [ V_699 ] ) {
T_5 V_707 = F_409 ( V_121 [ V_699 ] ) ;
if ( F_405 ( V_707 ) < 0 ||
F_406 ( V_9 , F_38 ( V_11 ) , V_707 ) < 0 )
return - V_39 ;
V_9 -> V_43 . V_47 = V_707 ;
V_36 = 0 ;
}
return V_36 ;
}
static int F_410 ( struct V_94 * V_95 , struct V_8 * V_9 ,
T_1 V_99 , T_1 V_100 , int V_101 , unsigned int V_58 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_677 * V_708 ;
struct V_102 * V_103 ;
void * V_709 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_708 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_708 = F_66 ( V_103 ) ;
V_708 -> V_710 = V_107 ;
V_708 -> V_711 = 0 ;
V_708 -> V_712 = V_11 -> type ;
V_708 -> V_713 = V_11 -> V_96 ;
V_708 -> V_714 = F_411 ( V_11 ) ;
V_708 -> V_715 = 0 ;
if ( F_412 ( V_95 , V_716 , V_11 -> V_56 ) ||
( V_11 -> V_314 &&
F_366 ( V_95 , V_717 , V_11 -> V_314 , V_11 -> V_316 ) ) ||
F_371 ( V_95 , V_718 , V_11 -> V_37 ) ||
( V_11 -> V_96 != F_413 ( V_11 ) &&
F_371 ( V_95 , V_719 , F_413 ( V_11 ) ) ) ||
F_399 ( V_95 , V_720 ,
F_49 ( V_11 ) ? V_11 -> V_721 : V_722 ) )
goto V_109;
V_709 = F_414 ( V_95 , V_723 ) ;
if ( ! V_709 )
goto V_109;
if ( F_396 ( V_95 , V_9 , 0 ) < 0 )
goto V_109;
F_415 ( V_95 , V_709 ) ;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static int F_416 ( struct V_94 * V_95 , struct V_130 * V_131 )
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
if ( F_410 ( V_95 , V_9 ,
F_81 ( V_131 -> V_95 ) . V_99 ,
V_131 -> V_103 -> V_129 ,
V_482 , V_143 ) < 0 )
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
V_95 = F_71 ( F_388 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_410 ( V_95 , V_9 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_724 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_724 , V_36 ) ;
}
static inline T_16 F_417 ( void )
{
return F_61 ( sizeof( struct V_725 ) )
+ F_62 ( sizeof( struct V_167 ) )
+ F_62 ( sizeof( struct V_726 ) ) ;
}
static int F_418 ( struct V_94 * V_95 , struct V_8 * V_9 ,
struct V_369 * V_370 , T_1 V_99 , T_1 V_100 ,
int V_101 , unsigned int V_58 )
{
struct V_725 * V_727 ;
struct V_102 * V_103 ;
struct V_726 V_561 ;
V_103 = F_65 ( V_95 , V_99 , V_100 , V_101 , sizeof( * V_727 ) , V_58 ) ;
if ( ! V_103 )
return - V_105 ;
V_727 = F_66 ( V_103 ) ;
V_727 -> V_728 = V_107 ;
V_727 -> V_729 = 0 ;
V_727 -> V_730 = 0 ;
V_727 -> V_731 = V_9 -> V_11 -> V_96 ;
V_727 -> V_189 = V_370 -> V_189 ;
V_727 -> V_732 = V_370 -> type ;
V_727 -> V_733 = 0 ;
V_727 -> V_734 = 0 ;
if ( V_370 -> V_291 )
V_727 -> V_734 |= V_735 ;
if ( V_370 -> V_387 )
V_727 -> V_734 |= V_736 ;
if ( F_366 ( V_95 , V_737 , sizeof( V_370 -> V_379 ) , & V_370 -> V_379 ) )
goto V_109;
V_561 . V_738 = F_258 ( V_370 -> V_382 ) ;
V_561 . V_739 = F_258 ( V_370 -> V_381 ) ;
if ( F_366 ( V_95 , V_740 , sizeof( V_561 ) , & V_561 ) )
goto V_109;
F_68 ( V_95 , V_103 ) ;
return 0 ;
V_109:
F_69 ( V_95 , V_103 ) ;
return - V_105 ;
}
static void F_265 ( int V_101 , struct V_8 * V_9 ,
struct V_369 * V_370 )
{
struct V_94 * V_95 ;
struct V_113 * V_113 = F_38 ( V_9 -> V_11 ) ;
int V_36 = - V_114 ;
V_95 = F_71 ( F_417 () , V_128 ) ;
if ( ! V_95 )
goto V_115;
V_36 = F_418 ( V_95 , V_9 , V_370 , 0 , 0 , V_101 , 0 ) ;
if ( V_36 < 0 ) {
F_72 ( V_36 == - V_105 ) ;
F_73 ( V_95 ) ;
goto V_115;
}
F_74 ( V_95 , V_113 , 0 , V_741 , NULL , V_128 ) ;
return;
V_115:
if ( V_36 < 0 )
F_75 ( V_113 , V_741 , V_36 ) ;
}
static void F_321 ( int V_101 , struct V_13 * V_14 )
{
struct V_113 * V_113 = F_38 ( V_14 -> V_9 -> V_11 ) ;
if ( V_101 )
F_33 () ;
F_380 ( V_101 ? : V_433 , V_14 ) ;
switch ( V_101 ) {
case V_433 :
if ( ! ( V_14 -> V_6 -> V_742 ) )
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
F_419 ( & V_113 -> V_22 . V_140 ) ;
}
static void F_157 ( int V_101 , struct V_13 * V_14 )
{
F_123 () ;
if ( F_138 ( V_14 -> V_9 -> V_84 == 0 ) )
F_321 ( V_101 , V_14 ) ;
F_137 () ;
}
static
int F_420 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 , T_10 * V_747 )
{
int * V_748 = V_743 -> V_462 ;
int V_749 = * V_748 ;
T_10 V_525 = * V_747 ;
struct V_152 V_750 ;
int V_220 ;
V_750 = * V_743 ;
V_750 . V_462 = & V_749 ;
V_220 = F_421 ( & V_750 , V_744 , V_745 , V_746 , V_747 ) ;
if ( V_744 )
V_220 = F_97 ( V_743 , V_748 , V_749 ) ;
if ( V_220 )
* V_747 = V_525 ;
return V_220 ;
}
static
int F_422 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 , T_10 * V_747 )
{
struct V_8 * V_9 = V_743 -> V_158 ;
int V_751 = V_38 ;
struct V_152 V_750 ;
V_750 = * V_743 ;
V_750 . V_158 = & V_751 ;
V_750 . V_156 = V_9 ? & V_9 -> V_11 -> V_37 : NULL ;
return F_423 ( & V_750 , V_744 , V_745 , V_746 , V_747 ) ;
}
static void F_424 ( struct V_8 * V_9 )
{
struct V_752 V_474 ;
if ( ! V_9 || ! V_9 -> V_11 )
return;
F_425 ( & V_474 , V_9 -> V_11 ) ;
if ( V_9 -> V_43 . V_183 )
F_305 ( NULL , V_211 , & V_474 ) ;
else
F_305 ( NULL , V_194 , & V_474 ) ;
}
static void F_426 ( struct V_113 * V_113 , T_4 V_150 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
F_96 (net, dev) {
V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
int V_151 = ( ! V_9 -> V_43 . V_183 ) ^ ( ! V_150 ) ;
V_9 -> V_43 . V_183 = V_150 ;
if ( V_151 )
F_424 ( V_9 ) ;
}
}
}
static int F_427 ( struct V_152 * V_153 , int * V_154 , int V_150 )
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
F_426 ( V_113 , V_150 ) ;
} else if ( ( ! V_150 ) ^ ( ! V_155 ) )
F_424 ( (struct V_8 * ) V_153 -> V_158 ) ;
F_100 () ;
return 0 ;
}
static
int F_428 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 , T_10 * V_747 )
{
int * V_748 = V_743 -> V_462 ;
int V_749 = * V_748 ;
T_10 V_525 = * V_747 ;
struct V_152 V_750 ;
int V_220 ;
V_750 = * V_743 ;
V_750 . V_462 = & V_749 ;
V_220 = F_421 ( & V_750 , V_744 , V_745 , V_746 , V_747 ) ;
if ( V_744 )
V_220 = F_427 ( V_743 , V_748 , V_749 ) ;
if ( V_220 )
* V_747 = V_525 ;
return V_220 ;
}
static
int F_429 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 , T_10 * V_747 )
{
int * V_748 = V_743 -> V_462 ;
int V_220 ;
int V_155 , V_753 ;
V_155 = * V_748 ;
V_220 = F_421 ( V_743 , V_744 , V_745 , V_746 , V_747 ) ;
V_753 = * V_748 ;
if ( V_744 && V_155 != V_753 ) {
struct V_113 * V_113 = V_743 -> V_156 ;
if ( ! F_98 () )
return F_99 () ;
if ( V_748 == & V_113 -> V_22 . V_44 -> V_111 )
F_70 ( V_113 , V_92 ,
V_127 ,
V_113 -> V_22 . V_44 ) ;
else if ( V_748 == & V_113 -> V_22 . V_126 -> V_111 )
F_70 ( V_113 , V_92 ,
V_125 ,
V_113 -> V_22 . V_126 ) ;
else {
struct V_8 * V_9 = V_743 -> V_158 ;
F_70 ( V_113 , V_92 ,
V_9 -> V_11 -> V_96 ,
& V_9 -> V_43 ) ;
}
F_100 () ;
}
return V_220 ;
}
static int F_430 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 ,
T_10 * V_747 )
{
int V_220 = 0 ;
int V_754 ;
struct V_8 * V_9 = (struct V_8 * ) V_743 -> V_158 ;
struct V_113 * V_113 = (struct V_113 * ) V_743 -> V_156 ;
if ( ! F_98 () )
return F_99 () ;
V_220 = F_421 ( V_743 , V_744 , V_745 , V_746 , V_747 ) ;
if ( V_744 ) {
V_754 = * ( ( int * ) V_743 -> V_462 ) ;
if ( F_405 ( V_754 ) < 0 ) {
V_220 = - V_39 ;
goto V_187;
}
if ( & V_113 -> V_22 . V_44 -> V_47 == V_743 -> V_462 ) {
V_49 . V_47 = V_754 ;
} else {
if ( ! V_9 )
goto V_187;
if ( F_406 ( V_9 , V_113 , V_754 ) < 0 ) {
V_220 = - V_39 ;
goto V_187;
}
if ( V_9 -> V_43 . V_47 != V_754 ) {
V_9 -> V_43 . V_47 = V_754 ;
F_299 ( V_9 -> V_11 ) ;
}
}
}
V_187:
F_100 () ;
return V_220 ;
}
static int F_431 ( struct V_152 * V_743 , int V_744 ,
void T_8 * V_745 , T_16 * V_746 ,
T_10 * V_747 )
{
int V_36 ;
struct V_167 V_165 ;
char V_755 [ V_756 ] ;
struct V_152 V_750 = * V_743 ;
struct V_113 * V_113 = V_743 -> V_156 ;
struct V_464 * V_458 = V_743 -> V_462 ;
if ( & V_113 -> V_22 . V_126 -> V_45 == V_743 -> V_462 )
return - V_757 ;
V_750 . V_758 = V_756 ;
V_750 . V_462 = V_755 ;
if ( ! F_98 () )
return F_99 () ;
if ( ! V_744 && ! V_458 -> V_46 ) {
V_36 = - V_757 ;
goto V_187;
}
V_36 = snprintf ( V_755 , sizeof( V_755 ) , L_29 , & V_458 -> V_458 ) ;
if ( V_36 >= sizeof( V_755 ) ) {
V_36 = - V_757 ;
goto V_187;
}
V_36 = F_432 ( & V_750 , V_744 , V_745 , V_746 , V_747 ) ;
if ( V_36 || ! V_744 )
goto V_187;
if ( F_433 ( V_755 , - 1 , V_165 . V_759 . V_760 , - 1 , NULL ) != 1 ) {
V_36 = - V_757 ;
goto V_187;
}
V_458 -> V_46 = true ;
V_458 -> V_458 = V_165 ;
if ( & V_113 -> V_22 . V_44 -> V_45 == V_743 -> V_462 ) {
struct V_10 * V_11 ;
F_96 (net, dev) {
struct V_8 * V_9 = F_57 ( V_11 ) ;
if ( V_9 ) {
V_9 -> V_43 . V_47 =
V_48 ;
}
}
} else {
struct V_8 * V_9 = V_743 -> V_158 ;
V_9 -> V_43 . V_47 = V_48 ;
}
V_187:
F_100 () ;
return V_36 ;
}
static
int F_434 ( struct V_152 * V_743 ,
int V_744 ,
void T_8 * V_745 ,
T_16 * V_746 ,
T_10 * V_747 )
{
int * V_748 = V_743 -> V_462 ;
int V_749 = * V_748 ;
T_10 V_525 = * V_747 ;
struct V_152 V_750 ;
int V_220 ;
V_750 = * V_743 ;
V_750 . V_462 = & V_749 ;
V_220 = F_421 ( & V_750 , V_744 , V_745 , V_746 , V_747 ) ;
if ( V_744 )
V_220 = F_103 ( V_743 , V_748 , V_749 ) ;
if ( V_220 )
* V_747 = V_525 ;
return V_220 ;
}
static int F_435 ( struct V_113 * V_113 , char * V_761 ,
struct V_8 * V_9 , struct V_97 * V_154 )
{
int V_20 , V_96 ;
struct V_152 * V_153 ;
char V_762 [ sizeof( L_30 ) + V_678 ] ;
V_153 = F_436 ( V_763 , sizeof( V_763 ) , V_29 ) ;
if ( ! V_153 )
goto V_187;
for ( V_20 = 0 ; V_153 [ V_20 ] . V_462 ; V_20 ++ ) {
V_153 [ V_20 ] . V_462 += ( char * ) V_154 - ( char * ) & V_97 ;
if ( ! V_153 [ V_20 ] . V_158 && ! V_153 [ V_20 ] . V_156 ) {
V_153 [ V_20 ] . V_158 = V_9 ;
V_153 [ V_20 ] . V_156 = V_113 ;
}
}
snprintf ( V_762 , sizeof( V_762 ) , L_31 , V_761 ) ;
V_154 -> V_764 = F_437 ( V_113 , V_762 , V_153 ) ;
if ( ! V_154 -> V_764 )
goto free;
if ( ! strcmp ( V_761 , L_32 ) )
V_96 = V_125 ;
else if ( ! strcmp ( V_761 , L_33 ) )
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
static void F_438 ( struct V_97 * V_154 )
{
struct V_152 * V_153 ;
if ( ! V_154 -> V_764 )
return;
V_153 = V_154 -> V_764 -> V_765 ;
F_439 ( V_154 -> V_764 ) ;
V_154 -> V_764 = NULL ;
F_30 ( V_153 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
int V_36 ;
if ( ! F_440 ( V_9 -> V_11 -> V_56 ) )
return - V_39 ;
V_36 = F_441 ( V_9 -> V_11 , V_9 -> V_51 ,
& V_766 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_435 ( F_38 ( V_9 -> V_11 ) , V_9 -> V_11 -> V_56 ,
V_9 , & V_9 -> V_43 ) ;
if ( V_36 )
F_442 ( V_9 -> V_51 ) ;
return V_36 ;
}
static void F_7 ( struct V_8 * V_9 )
{
F_438 ( & V_9 -> V_43 ) ;
F_442 ( V_9 -> V_51 ) ;
}
static int T_12 F_443 ( struct V_113 * V_113 )
{
int V_36 = - V_34 ;
struct V_97 * V_88 , * V_767 ;
V_88 = F_436 ( & V_97 , sizeof( V_97 ) , V_29 ) ;
if ( ! V_88 )
goto V_768;
V_767 = F_436 ( & V_49 , sizeof( V_49 ) , V_29 ) ;
if ( ! V_767 )
goto V_769;
V_767 -> V_387 = V_770 . V_387 ;
V_767 -> V_183 = V_770 . V_183 ;
V_767 -> V_45 . V_46 = false ;
V_88 -> V_45 . V_46 = false ;
V_113 -> V_22 . V_126 = V_88 ;
V_113 -> V_22 . V_44 = V_767 ;
#ifdef F_444
V_36 = F_435 ( V_113 , L_32 , NULL , V_88 ) ;
if ( V_36 < 0 )
goto V_771;
V_36 = F_435 ( V_113 , L_33 , NULL , V_767 ) ;
if ( V_36 < 0 )
goto V_772;
#endif
return 0 ;
#ifdef F_444
V_772:
F_438 ( V_88 ) ;
V_771:
F_30 ( V_767 ) ;
#endif
V_769:
F_30 ( V_88 ) ;
V_768:
return V_36 ;
}
static void T_13 F_445 ( struct V_113 * V_113 )
{
#ifdef F_444
F_438 ( V_113 -> V_22 . V_44 ) ;
F_438 ( V_113 -> V_22 . V_126 ) ;
#endif
F_30 ( V_113 -> V_22 . V_44 ) ;
F_30 ( V_113 -> V_22 . V_126 ) ;
}
int T_14 F_446 ( void )
{
struct V_8 * V_9 ;
int V_20 , V_36 ;
V_36 = F_447 () ;
if ( V_36 < 0 ) {
F_448 ( L_34 ,
V_55 , V_36 ) ;
goto V_187;
}
V_36 = F_351 ( & V_773 ) ;
if ( V_36 < 0 )
goto V_774;
V_19 = F_449 ( L_35 ) ;
if ( ! V_19 ) {
V_36 = - V_34 ;
goto V_775;
}
F_267 () ;
V_9 = F_32 ( V_776 . V_777 ) ;
F_100 () ;
if ( F_58 ( V_9 ) ) {
V_36 = F_127 ( V_9 ) ;
goto V_778;
}
for ( V_20 = 0 ; V_20 < V_495 ; V_20 ++ )
F_450 ( & V_191 [ V_20 ] ) ;
F_451 ( & V_779 ) ;
F_256 () ;
F_452 ( & V_780 ) ;
V_36 = F_453 ( V_781 , V_782 , NULL , F_416 ,
NULL ) ;
if ( V_36 < 0 )
goto V_115;
F_453 ( V_781 , V_433 , F_363 , NULL , NULL ) ;
F_453 ( V_781 , V_210 , F_360 , NULL , NULL ) ;
F_453 ( V_781 , V_783 , F_379 ,
F_376 , NULL ) ;
F_453 ( V_781 , V_594 , NULL ,
F_377 , NULL ) ;
F_453 ( V_781 , V_598 , NULL ,
F_378 , NULL ) ;
F_453 ( V_781 , V_784 , F_76 ,
F_83 , NULL ) ;
F_454 () ;
return 0 ;
V_115:
F_455 ( & V_780 ) ;
F_456 ( & V_779 ) ;
V_778:
F_457 ( V_19 ) ;
V_775:
F_353 ( & V_773 ) ;
V_774:
F_458 () ;
V_187:
return V_36 ;
}
void F_459 ( void )
{
struct V_10 * V_11 ;
int V_20 ;
F_456 ( & V_779 ) ;
F_353 ( & V_773 ) ;
F_458 () ;
F_267 () ;
F_460 ( & V_780 ) ;
F_96 (&init_net, dev) {
if ( F_57 ( V_11 ) == NULL )
continue;
F_308 ( V_11 , 1 ) ;
}
F_308 ( V_776 . V_777 , 2 ) ;
F_149 ( & V_185 ) ;
for ( V_20 = 0 ; V_20 < V_495 ; V_20 ++ )
F_72 ( ! F_461 ( & V_191 [ V_20 ] ) ) ;
F_150 ( & V_185 ) ;
F_14 ( & V_542 ) ;
F_100 () ;
F_457 ( V_19 ) ;
}
