static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static bool F_3 ( const struct V_6 * V_7 ,
T_2 V_8 , T_1 V_1 )
{
if ( V_7 -> V_9 & V_10 ) {
if ( V_8 & V_10 )
return V_1 == V_7 -> V_11 ;
else
return false ;
} else
return ! ( V_8 & V_10 ) ;
}
struct V_12 * F_4 ( struct V_13 * V_14 ,
int V_15 , T_2 V_8 ,
T_1 V_2 , T_1 V_16 ,
T_1 V_1 )
{
unsigned int V_17 ;
struct V_12 * V_18 , * V_19 = NULL ;
struct V_20 * V_21 ;
V_17 = F_1 ( V_1 , V_2 ) ;
V_21 = & V_14 -> V_22 [ V_17 ] ;
F_5 (t, head, hash_node) {
if ( V_16 != V_18 -> V_23 . V_24 . V_25 ||
V_2 != V_18 -> V_23 . V_24 . V_26 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else
V_19 = V_18 ;
}
F_5 (t, head, hash_node) {
if ( V_2 != V_18 -> V_23 . V_24 . V_26 ||
V_18 -> V_23 . V_24 . V_25 != 0 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
V_17 = F_1 ( V_1 , 0 ) ;
V_21 = & V_14 -> V_22 [ V_17 ] ;
F_5 (t, head, hash_node) {
if ( ( V_16 != V_18 -> V_23 . V_24 . V_25 || V_18 -> V_23 . V_24 . V_26 != 0 ) &&
( V_16 != V_18 -> V_23 . V_24 . V_26 || ! F_6 ( V_16 ) ) )
continue;
if ( ! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
if ( V_8 & V_29 )
goto V_30;
F_5 (t, head, hash_node) {
if ( V_18 -> V_23 . V_11 != V_1 ||
V_18 -> V_23 . V_24 . V_25 != 0 ||
V_18 -> V_23 . V_24 . V_26 != 0 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
V_30:
if ( V_19 )
return V_19 ;
V_18 = F_7 ( V_14 -> V_31 ) ;
if ( V_18 )
return V_18 ;
if ( V_14 -> V_32 && V_14 -> V_32 -> V_8 & V_28 )
return F_8 ( V_14 -> V_32 ) ;
return NULL ;
}
static struct V_20 * F_9 ( struct V_13 * V_14 ,
struct V_6 * V_23 )
{
unsigned int V_33 ;
T_1 V_2 ;
T_1 V_11 = V_23 -> V_11 ;
if ( V_23 -> V_24 . V_26 && ! F_6 ( V_23 -> V_24 . V_26 ) )
V_2 = V_23 -> V_24 . V_26 ;
else
V_2 = 0 ;
if ( ! ( V_23 -> V_9 & V_10 ) && ( V_23 -> V_9 & V_34 ) )
V_11 = 0 ;
V_33 = F_1 ( V_11 , V_2 ) ;
return & V_14 -> V_22 [ V_33 ] ;
}
static void F_10 ( struct V_13 * V_14 , struct V_12 * V_18 )
{
struct V_20 * V_21 = F_9 ( V_14 , & V_18 -> V_23 ) ;
if ( V_18 -> V_35 )
F_11 ( V_14 -> V_31 , V_18 ) ;
F_12 ( & V_18 -> V_36 , V_21 ) ;
}
static void F_13 ( struct V_13 * V_14 , struct V_12 * V_18 )
{
if ( V_18 -> V_35 )
F_11 ( V_14 -> V_31 , NULL ) ;
F_14 ( & V_18 -> V_36 ) ;
}
static struct V_12 * F_15 ( struct V_13 * V_14 ,
struct V_6 * V_23 ,
int type )
{
T_1 V_2 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
T_1 V_1 = V_23 -> V_11 ;
T_2 V_8 = V_23 -> V_9 ;
int V_15 = V_23 -> V_15 ;
struct V_12 * V_18 = NULL ;
struct V_20 * V_21 = F_9 ( V_14 , V_23 ) ;
F_5 (t, head, hash_node) {
if ( V_16 == V_18 -> V_23 . V_24 . V_25 &&
V_2 == V_18 -> V_23 . V_24 . V_26 &&
V_15 == V_18 -> V_23 . V_15 &&
type == V_18 -> V_27 -> type &&
F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
break;
}
return V_18 ;
}
static struct V_37 * F_16 ( struct V_38 * V_38 ,
const struct V_39 * V_40 ,
struct V_6 * V_23 )
{
int V_41 ;
struct V_12 * V_42 ;
struct V_37 * V_27 ;
char V_43 [ V_44 ] ;
if ( V_23 -> V_43 [ 0 ] )
F_17 ( V_43 , V_23 -> V_43 , V_44 ) ;
else {
if ( strlen ( V_40 -> V_45 ) > ( V_44 - 3 ) ) {
V_41 = - V_46 ;
goto V_47;
}
F_17 ( V_43 , V_40 -> V_45 , V_44 ) ;
strncat ( V_43 , L_1 , 2 ) ;
}
F_18 () ;
V_27 = F_19 ( V_40 -> V_48 , V_43 , V_49 , V_40 -> V_50 ) ;
if ( ! V_27 ) {
V_41 = - V_51 ;
goto V_47;
}
F_20 ( V_27 , V_38 ) ;
V_27 -> V_39 = V_40 ;
V_42 = F_8 ( V_27 ) ;
V_42 -> V_23 = * V_23 ;
V_42 -> V_38 = V_38 ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 )
goto V_52;
return V_27 ;
V_52:
F_22 ( V_27 ) ;
V_47:
return F_23 ( V_41 ) ;
}
static inline void F_24 ( struct V_53 * V_54 ,
int V_55 ,
T_1 V_26 , T_1 V_25 ,
T_1 V_1 , T_3 V_56 , int V_57 ,
T_4 V_58 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_59 = V_57 ;
V_54 -> V_26 = V_26 ;
V_54 -> V_25 = V_25 ;
V_54 -> V_60 = V_56 ;
V_54 -> V_61 = V_55 ;
V_54 -> V_62 = V_1 ;
V_54 -> V_63 = V_58 ;
}
static int F_25 ( struct V_37 * V_27 )
{
struct V_37 * V_64 = NULL ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_65 * V_24 ;
int V_66 = V_67 ;
int V_68 = V_69 ;
int V_70 = V_42 -> V_66 + sizeof( struct V_65 ) ;
V_24 = & V_42 -> V_23 . V_24 ;
if ( V_24 -> V_26 ) {
struct V_53 V_54 ;
struct V_71 * V_72 ;
F_24 ( & V_54 , V_24 -> V_73 , V_24 -> V_26 ,
V_24 -> V_25 , V_42 -> V_23 . V_74 ,
F_26 ( V_24 -> V_56 ) , V_42 -> V_23 . V_15 ,
V_42 -> V_75 ) ;
V_72 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( ! F_28 ( V_72 ) ) {
V_64 = V_72 -> V_76 . V_27 ;
F_29 ( V_72 ) ;
}
if ( V_27 -> type != V_77 )
V_27 -> V_8 |= V_78 ;
F_30 ( & V_42 -> V_79 ) ;
}
if ( ! V_64 && V_42 -> V_23 . V_15 )
V_64 = F_31 ( V_42 -> V_38 , V_42 -> V_23 . V_15 ) ;
if ( V_64 ) {
V_66 = V_64 -> V_80 + V_64 -> V_81 ;
V_68 = V_64 -> V_68 ;
}
V_27 -> V_81 = V_70 + V_66 ;
V_68 -= ( V_27 -> V_80 + V_70 ) ;
if ( V_68 < 68 )
V_68 = 68 ;
return V_68 ;
}
static struct V_12 * F_32 ( struct V_38 * V_38 ,
struct V_13 * V_14 ,
struct V_6 * V_23 )
{
struct V_12 * V_82 ;
struct V_37 * V_27 ;
int V_70 ;
F_33 ( ! V_14 -> V_32 ) ;
V_27 = F_16 ( V_38 , V_14 -> V_32 -> V_39 , V_23 ) ;
if ( F_28 ( V_27 ) )
return F_34 ( V_27 ) ;
V_27 -> V_68 = F_25 ( V_27 ) ;
V_82 = F_8 ( V_27 ) ;
V_70 = V_82 -> V_66 + sizeof( struct V_65 ) ;
V_27 -> V_83 = V_84 ;
V_27 -> V_85 = 0xFFF8 - V_27 -> V_80 - V_70 ;
F_10 ( V_14 , V_82 ) ;
return V_82 ;
}
int F_35 ( struct V_12 * V_42 , struct V_86 * V_87 ,
const struct V_88 * V_89 , struct V_90 * V_91 ,
bool V_92 )
{
struct V_93 * V_94 ;
const struct V_65 * V_24 = F_36 ( V_87 ) ;
int V_41 ;
#ifdef F_37
if ( F_6 ( V_24 -> V_26 ) ) {
V_42 -> V_27 -> V_95 . V_96 ++ ;
V_87 -> V_97 = V_98 ;
}
#endif
if ( ( ! ( V_89 -> V_8 & V_99 ) && ( V_42 -> V_23 . V_9 & V_99 ) ) ||
( ( V_89 -> V_8 & V_99 ) && ! ( V_42 -> V_23 . V_9 & V_99 ) ) ) {
V_42 -> V_27 -> V_95 . V_100 ++ ;
V_42 -> V_27 -> V_95 . V_101 ++ ;
goto V_102;
}
if ( V_42 -> V_23 . V_9 & V_103 ) {
if ( ! ( V_89 -> V_8 & V_103 ) ||
( V_42 -> V_104 && ( V_105 ) ( F_38 ( V_89 -> V_106 ) - V_42 -> V_104 ) < 0 ) ) {
V_42 -> V_27 -> V_95 . V_107 ++ ;
V_42 -> V_27 -> V_95 . V_101 ++ ;
goto V_102;
}
V_42 -> V_104 = F_38 ( V_89 -> V_106 ) + 1 ;
}
F_39 ( V_87 ) ;
V_41 = F_40 ( V_24 , V_87 ) ;
if ( F_41 ( V_41 ) ) {
if ( V_92 )
F_42 ( L_2 ,
& V_24 -> V_25 , V_24 -> V_56 ) ;
if ( V_41 > 1 ) {
++ V_42 -> V_27 -> V_95 . V_108 ;
++ V_42 -> V_27 -> V_95 . V_101 ;
goto V_102;
}
}
V_94 = F_43 ( V_42 -> V_27 -> V_94 ) ;
F_44 ( & V_94 -> V_109 ) ;
V_94 -> V_110 ++ ;
V_94 -> V_111 += V_87 -> V_112 ;
F_45 ( & V_94 -> V_109 ) ;
F_46 ( V_87 , ! F_47 ( V_42 -> V_38 , F_48 ( V_42 -> V_27 ) ) ) ;
if ( V_42 -> V_27 -> type == V_77 ) {
V_87 -> V_73 = F_49 ( V_87 , V_42 -> V_27 ) ;
F_50 ( V_87 , F_51 ( V_87 ) , V_113 ) ;
} else {
V_87 -> V_27 = V_42 -> V_27 ;
}
if ( V_91 )
F_52 ( V_87 , (struct V_114 * ) V_91 ) ;
F_53 ( & V_42 -> V_115 , V_87 ) ;
return 0 ;
V_102:
if ( V_91 )
F_54 ( (struct V_114 * ) V_91 ) ;
F_55 ( V_87 ) ;
return 0 ;
}
int F_56 ( const struct V_116 * V_40 ,
unsigned int V_117 )
{
if ( V_117 >= V_118 )
return - V_119 ;
return ! F_57 ( ( const struct V_116 * * )
& V_120 [ V_117 ] ,
NULL , V_40 ) ? 0 : - 1 ;
}
int F_58 ( const struct V_116 * V_40 ,
unsigned int V_117 )
{
int V_121 ;
if ( V_117 >= V_118 )
return - V_119 ;
V_121 = ( F_57 ( ( const struct V_116 * * )
& V_120 [ V_117 ] ,
V_40 , NULL ) == V_40 ) ? 0 : - 1 ;
F_59 () ;
return V_121 ;
}
int F_60 ( struct V_12 * V_18 ,
struct V_122 * V_123 )
{
int V_66 ;
memset ( & V_18 -> V_124 , 0 , sizeof( V_18 -> V_124 ) ) ;
V_66 = F_61 ( V_123 ) ;
if ( V_66 < 0 )
return V_66 ;
V_18 -> V_124 . type = V_123 -> type ;
V_18 -> V_124 . V_125 = V_123 -> V_125 ;
V_18 -> V_124 . V_126 = V_123 -> V_126 ;
V_18 -> V_124 . V_8 = V_123 -> V_8 ;
V_18 -> V_127 = V_66 ;
V_18 -> V_66 = V_18 -> V_127 + V_18 -> V_128 ;
return 0 ;
}
static int F_62 ( struct V_37 * V_27 , struct V_86 * V_87 ,
struct V_71 * V_72 , T_2 V_129 ,
const struct V_65 * V_130 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_131 = V_87 -> V_112 - V_42 -> V_66 - V_27 -> V_80 ;
int V_68 ;
if ( V_129 )
V_68 = F_63 ( & V_72 -> V_76 ) - V_27 -> V_80
- sizeof( struct V_65 ) - V_42 -> V_66 ;
else
V_68 = F_64 ( V_87 ) ? F_63 ( F_64 ( V_87 ) ) : V_27 -> V_68 ;
if ( F_64 ( V_87 ) )
F_64 ( V_87 ) -> V_40 -> V_132 ( F_64 ( V_87 ) , NULL , V_87 , V_68 ) ;
if ( V_87 -> V_73 == F_65 ( V_133 ) ) {
if ( ! F_66 ( V_87 ) &&
( V_130 -> V_134 & F_65 ( V_135 ) ) &&
V_68 < V_131 ) {
memset ( F_67 ( V_87 ) , 0 , sizeof( * F_67 ( V_87 ) ) ) ;
F_68 ( V_87 , V_136 , V_137 , F_69 ( V_68 ) ) ;
return - V_46 ;
}
}
#if F_70 ( V_138 )
else if ( V_87 -> V_73 == F_65 ( V_139 ) ) {
struct V_140 * V_141 = (struct V_140 * ) F_64 ( V_87 ) ;
if ( V_141 && V_68 < F_63 ( F_64 ( V_87 ) ) &&
V_68 >= V_142 ) {
if ( ( V_42 -> V_23 . V_24 . V_26 &&
! F_6 ( V_42 -> V_23 . V_24 . V_26 ) ) ||
V_141 -> V_143 . V_144 == 128 ) {
V_141 -> V_145 |= V_146 ;
F_71 ( F_64 ( V_87 ) , V_147 , V_68 ) ;
}
}
if ( ! F_66 ( V_87 ) && V_68 >= V_142 &&
V_68 < V_131 ) {
F_72 ( V_87 , V_148 , 0 , V_68 ) ;
return - V_46 ;
}
}
#endif
return 0 ;
}
void F_73 ( struct V_86 * V_87 , struct V_37 * V_27 , T_5 V_55 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
V_4 V_149 = sizeof( struct V_65 ) ;
struct V_150 * V_151 ;
const struct V_152 * V_1 ;
const struct V_65 * V_130 ;
struct V_71 * V_72 ;
struct V_53 V_54 ;
T_2 V_129 = 0 ;
T_5 V_56 , V_153 ;
V_151 = F_74 ( V_87 ) ;
if ( F_41 ( ! V_151 || ! ( V_151 -> V_154 & V_155 ) ||
F_75 ( V_151 ) != V_156 ) )
goto V_157;
V_1 = & V_151 -> V_1 ;
memset ( & ( F_67 ( V_87 ) -> V_158 ) , 0 , sizeof( F_67 ( V_87 ) -> V_158 ) ) ;
V_130 = ( const struct V_65 * ) F_76 ( V_87 ) ;
V_56 = V_1 -> V_56 ;
if ( V_56 == 1 ) {
if ( V_87 -> V_73 == F_65 ( V_133 ) )
V_56 = V_130 -> V_56 ;
else if ( V_87 -> V_73 == F_65 ( V_139 ) )
V_56 = F_77 ( ( const struct V_159 * ) V_130 ) ;
}
F_24 ( & V_54 , V_55 , V_1 -> V_160 . V_161 . V_76 , V_1 -> V_160 . V_161 . V_162 , 0 ,
F_26 ( V_56 ) , V_42 -> V_23 . V_15 , V_42 -> V_75 ) ;
if ( V_42 -> V_124 . type != V_163 )
goto V_157;
V_72 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( F_28 ( V_72 ) ) {
V_27 -> V_95 . V_164 ++ ;
goto V_157;
}
if ( V_72 -> V_76 . V_27 == V_27 ) {
F_29 ( V_72 ) ;
V_27 -> V_95 . V_165 ++ ;
goto V_157;
}
V_56 = F_78 ( V_56 , V_130 , V_87 ) ;
V_153 = V_1 -> V_153 ;
if ( V_153 == 0 ) {
if ( V_87 -> V_73 == F_65 ( V_133 ) )
V_153 = V_130 -> V_153 ;
else if ( V_87 -> V_73 == F_65 ( V_139 ) )
V_153 = ( ( const struct V_159 * ) V_130 ) -> V_166 ;
else
V_153 = F_79 ( & V_72 -> V_76 ) ;
}
if ( V_1 -> V_167 & V_168 )
V_129 = F_65 ( V_135 ) ;
else if ( V_87 -> V_73 == F_65 ( V_133 ) )
V_129 = V_130 -> V_134 & F_65 ( V_135 ) ;
V_149 += F_80 ( V_72 -> V_76 . V_27 ) + V_72 -> V_76 . V_169 ;
if ( V_149 > V_27 -> V_81 )
V_27 -> V_81 = V_149 ;
if ( F_81 ( V_87 , V_27 -> V_81 ) ) {
F_29 ( V_72 ) ;
goto V_170;
}
F_82 ( NULL , V_72 , V_87 , V_54 . V_25 , V_54 . V_26 , V_55 , V_1 -> V_56 ,
V_1 -> V_153 , V_129 , ! F_47 ( V_42 -> V_38 , F_48 ( V_27 ) ) ) ;
return;
V_157:
V_27 -> V_95 . V_171 ++ ;
goto V_172;
V_170:
V_27 -> V_95 . V_170 ++ ;
V_172:
F_55 ( V_87 ) ;
}
void F_83 ( struct V_86 * V_87 , struct V_37 * V_27 ,
const struct V_65 * V_173 , T_5 V_73 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_65 * V_130 ;
struct V_53 V_54 ;
T_5 V_56 , V_153 ;
T_2 V_129 ;
struct V_71 * V_72 ;
unsigned int V_174 ;
T_1 V_76 ;
bool V_175 ;
V_130 = ( const struct V_65 * ) F_76 ( V_87 ) ;
V_175 = ( V_42 -> V_23 . V_24 . V_26 != 0 ) ;
memset ( & ( F_67 ( V_87 ) -> V_158 ) , 0 , sizeof( F_67 ( V_87 ) -> V_158 ) ) ;
V_76 = V_173 -> V_26 ;
if ( V_76 == 0 ) {
if ( ! F_64 ( V_87 ) ) {
V_27 -> V_95 . V_176 ++ ;
goto V_157;
}
if ( V_87 -> V_73 == F_65 ( V_133 ) ) {
V_72 = F_84 ( V_87 ) ;
V_76 = F_85 ( V_72 , V_130 -> V_26 ) ;
}
#if F_70 ( V_138 )
else if ( V_87 -> V_73 == F_65 ( V_139 ) ) {
const struct V_177 * V_178 ;
struct V_179 * V_180 ;
bool V_181 ;
int V_182 ;
V_180 = F_86 ( F_64 ( V_87 ) ,
& F_87 ( V_87 ) -> V_26 ) ;
if ( ! V_180 )
goto V_157;
V_178 = ( const struct V_177 * ) & V_180 -> V_183 ;
V_182 = F_88 ( V_178 ) ;
if ( V_182 == V_184 ) {
V_178 = & F_87 ( V_87 ) -> V_26 ;
V_182 = F_88 ( V_178 ) ;
}
if ( ( V_182 & V_185 ) == 0 )
V_181 = true ;
else {
V_181 = false ;
V_76 = V_178 -> V_186 [ 3 ] ;
}
F_89 ( V_180 ) ;
if ( V_181 )
goto V_187;
}
#endif
else
goto V_157;
V_175 = false ;
}
V_56 = V_173 -> V_56 ;
if ( V_56 & 0x1 ) {
V_56 &= ~ 0x1 ;
if ( V_87 -> V_73 == F_65 ( V_133 ) ) {
V_56 = V_130 -> V_56 ;
V_175 = false ;
} else if ( V_87 -> V_73 == F_65 ( V_139 ) ) {
V_56 = F_77 ( ( const struct V_159 * ) V_130 ) ;
V_175 = false ;
}
}
F_24 ( & V_54 , V_73 , V_76 , V_173 -> V_25 ,
V_42 -> V_23 . V_74 , F_26 ( V_56 ) , V_42 -> V_23 . V_15 ,
V_42 -> V_75 ) ;
if ( V_122 ( V_87 , V_42 , & V_73 , & V_54 ) < 0 )
goto V_157;
V_72 = V_175 ? F_90 ( & V_42 -> V_79 , & V_54 . V_25 ) :
NULL ;
if ( ! V_72 ) {
V_72 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( F_28 ( V_72 ) ) {
V_27 -> V_95 . V_164 ++ ;
goto V_157;
}
if ( V_175 )
F_91 ( & V_42 -> V_79 , & V_72 -> V_76 ,
V_54 . V_25 ) ;
}
if ( V_72 -> V_76 . V_27 == V_27 ) {
F_29 ( V_72 ) ;
V_27 -> V_95 . V_165 ++ ;
goto V_157;
}
if ( F_62 ( V_27 , V_87 , V_72 , V_173 -> V_134 , V_130 ) ) {
F_29 ( V_72 ) ;
goto V_157;
}
if ( V_42 -> V_188 > 0 ) {
if ( F_92 ( V_189 ,
V_42 -> V_190 + V_191 ) ) {
V_42 -> V_188 -- ;
F_93 ( V_87 ) ;
} else
V_42 -> V_188 = 0 ;
}
V_56 = F_78 ( V_56 , V_130 , V_87 ) ;
V_153 = V_173 -> V_153 ;
if ( V_153 == 0 ) {
if ( V_87 -> V_73 == F_65 ( V_133 ) )
V_153 = V_130 -> V_153 ;
#if F_70 ( V_138 )
else if ( V_87 -> V_73 == F_65 ( V_139 ) )
V_153 = ( ( const struct V_159 * ) V_130 ) -> V_166 ;
#endif
else
V_153 = F_79 ( & V_72 -> V_76 ) ;
}
V_129 = V_173 -> V_134 ;
if ( V_87 -> V_73 == F_65 ( V_133 ) && ! V_42 -> V_192 )
V_129 |= ( V_130 -> V_134 & F_65 ( V_135 ) ) ;
V_174 = F_80 ( V_72 -> V_76 . V_27 ) + sizeof( struct V_65 )
+ V_72 -> V_76 . V_169 + F_61 ( & V_42 -> V_124 ) ;
if ( V_174 > V_27 -> V_81 )
V_27 -> V_81 = V_174 ;
if ( F_81 ( V_87 , V_27 -> V_81 ) ) {
F_29 ( V_72 ) ;
V_27 -> V_95 . V_170 ++ ;
F_55 ( V_87 ) ;
return;
}
F_82 ( NULL , V_72 , V_87 , V_54 . V_25 , V_54 . V_26 , V_73 , V_56 , V_153 ,
V_129 , ! F_47 ( V_42 -> V_38 , F_48 ( V_27 ) ) ) ;
return;
#if F_70 ( V_138 )
V_187:
F_93 ( V_87 ) ;
#endif
V_157:
V_27 -> V_95 . V_171 ++ ;
F_55 ( V_87 ) ;
}
static void F_94 ( struct V_13 * V_14 ,
struct V_12 * V_18 ,
struct V_37 * V_27 ,
struct V_6 * V_7 ,
bool V_193 ,
T_4 V_75 )
{
F_13 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_25 = V_7 -> V_24 . V_25 ;
V_18 -> V_23 . V_24 . V_26 = V_7 -> V_24 . V_26 ;
V_18 -> V_23 . V_11 = V_7 -> V_11 ;
V_18 -> V_23 . V_74 = V_7 -> V_74 ;
if ( V_27 -> type != V_77 ) {
memcpy ( V_27 -> V_194 , & V_7 -> V_24 . V_25 , 4 ) ;
memcpy ( V_27 -> V_195 , & V_7 -> V_24 . V_26 , 4 ) ;
}
F_10 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_153 = V_7 -> V_24 . V_153 ;
V_18 -> V_23 . V_24 . V_56 = V_7 -> V_24 . V_56 ;
V_18 -> V_23 . V_24 . V_134 = V_7 -> V_24 . V_134 ;
if ( V_18 -> V_23 . V_15 != V_7 -> V_15 || V_18 -> V_75 != V_75 ) {
int V_68 ;
V_18 -> V_23 . V_15 = V_7 -> V_15 ;
V_18 -> V_75 = V_75 ;
V_68 = F_25 ( V_27 ) ;
if ( V_193 )
V_27 -> V_68 = V_68 ;
}
F_30 ( & V_18 -> V_79 ) ;
F_95 ( V_27 ) ;
}
int F_96 ( struct V_37 * V_27 , struct V_6 * V_7 , int V_196 )
{
int V_41 = 0 ;
struct V_12 * V_18 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_18 -> V_38 ;
struct V_13 * V_14 = F_97 ( V_38 , V_18 -> V_197 ) ;
F_33 ( ! V_14 -> V_32 ) ;
switch ( V_196 ) {
case V_198 :
if ( V_27 == V_14 -> V_32 ) {
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
V_18 = F_8 ( V_27 ) ;
}
memcpy ( V_7 , & V_18 -> V_23 , sizeof( * V_7 ) ) ;
break;
case V_199 :
case V_200 :
V_41 = - V_201 ;
if ( ! F_98 ( V_38 -> V_202 , V_203 ) )
goto V_204;
if ( V_7 -> V_24 . V_153 )
V_7 -> V_24 . V_134 |= F_65 ( V_135 ) ;
if ( ! ( V_7 -> V_9 & V_34 ) ) {
if ( ! ( V_7 -> V_9 & V_10 ) )
V_7 -> V_11 = 0 ;
if ( ! ( V_7 -> V_205 & V_10 ) )
V_7 -> V_74 = 0 ;
}
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( V_196 == V_199 ) {
if ( ! V_18 ) {
V_18 = F_32 ( V_38 , V_14 , V_7 ) ;
V_41 = F_99 ( V_18 ) ;
break;
}
V_41 = - V_206 ;
break;
}
if ( V_27 != V_14 -> V_32 && V_196 == V_200 ) {
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 ) {
V_41 = - V_206 ;
break;
}
} else {
unsigned int V_207 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_207 = V_208 ;
else if ( V_7 -> V_24 . V_26 )
V_207 = V_78 ;
if ( ( V_27 -> V_8 ^ V_207 ) & ( V_78 | V_208 ) ) {
V_41 = - V_209 ;
break;
}
V_18 = F_8 ( V_27 ) ;
}
}
if ( V_18 ) {
V_41 = 0 ;
F_94 ( V_14 , V_18 , V_27 , V_7 , true , 0 ) ;
} else {
V_41 = - V_210 ;
}
break;
case V_211 :
V_41 = - V_201 ;
if ( ! F_98 ( V_38 -> V_202 , V_203 ) )
goto V_204;
if ( V_27 == V_14 -> V_32 ) {
V_41 = - V_210 ;
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
goto V_204;
V_41 = - V_201 ;
if ( V_18 == F_8 ( V_14 -> V_32 ) )
goto V_204;
V_27 = V_18 -> V_27 ;
}
F_100 ( V_27 ) ;
V_41 = 0 ;
break;
default:
V_41 = - V_209 ;
}
V_204:
return V_41 ;
}
int F_101 ( struct V_37 * V_27 , int V_212 , bool V_213 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_70 = V_42 -> V_66 + sizeof( struct V_65 ) ;
int V_85 = 0xFFF8 - V_27 -> V_80 - V_70 ;
if ( V_212 < V_84 )
return - V_209 ;
if ( V_212 > V_85 ) {
if ( V_213 )
return - V_209 ;
V_212 = V_85 ;
}
V_27 -> V_68 = V_212 ;
return 0 ;
}
int F_102 ( struct V_37 * V_27 , int V_212 )
{
return F_101 ( V_27 , V_212 , true ) ;
}
static void F_103 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
F_104 ( & V_42 -> V_115 ) ;
F_105 ( & V_42 -> V_79 ) ;
F_106 ( V_27 -> V_94 ) ;
}
void F_107 ( struct V_37 * V_27 , struct V_214 * V_21 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_13 * V_14 ;
V_14 = F_97 ( V_42 -> V_38 , V_42 -> V_197 ) ;
if ( V_14 -> V_32 != V_27 ) {
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_108 ( V_27 , V_21 ) ;
}
}
struct V_38 * F_109 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_38 ;
}
int F_110 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_23 . V_15 ;
}
int F_111 ( struct V_38 * V_38 , unsigned int V_197 ,
struct V_39 * V_40 , char * V_215 )
{
struct V_13 * V_14 = F_97 ( V_38 , V_197 ) ;
struct V_6 V_23 ;
unsigned int V_216 ;
for ( V_216 = 0 ; V_216 < V_217 ; V_216 ++ )
F_112 ( & V_14 -> V_22 [ V_216 ] ) ;
if ( ! V_40 ) {
V_14 -> V_32 = NULL ;
return 0 ;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
if ( V_215 )
F_17 ( V_23 . V_43 , V_215 , V_44 ) ;
F_113 () ;
V_14 -> V_32 = F_16 ( V_38 , V_40 , & V_23 ) ;
if ( ! F_28 ( V_14 -> V_32 ) ) {
V_14 -> V_32 -> V_218 |= V_219 ;
V_14 -> V_32 -> V_68 = F_25 ( V_14 -> V_32 ) ;
F_10 ( V_14 , F_8 ( V_14 -> V_32 ) ) ;
}
F_114 () ;
return F_99 ( V_14 -> V_32 ) ;
}
static void F_115 ( struct V_13 * V_14 , struct V_214 * V_21 ,
struct V_39 * V_40 )
{
struct V_38 * V_38 = F_48 ( V_14 -> V_32 ) ;
struct V_37 * V_27 , * V_220 ;
int V_33 ;
F_116 (net, dev, aux)
if ( V_27 -> V_39 == V_40 )
F_108 ( V_27 , V_21 ) ;
for ( V_33 = 0 ; V_33 < V_217 ; V_33 ++ ) {
struct V_12 * V_18 ;
struct V_221 * V_222 ;
struct V_20 * V_223 = & V_14 -> V_22 [ V_33 ] ;
F_117 (t, n, thead, hash_node)
if ( ! F_47 ( F_48 ( V_18 -> V_27 ) , V_38 ) )
F_108 ( V_18 -> V_27 , V_21 ) ;
}
}
void F_118 ( struct V_13 * V_14 , struct V_39 * V_40 )
{
F_119 ( V_224 ) ;
F_113 () ;
F_115 ( V_14 , & V_224 , V_40 ) ;
F_120 ( & V_224 ) ;
F_114 () ;
}
int F_121 ( struct V_37 * V_27 , struct V_225 * V_226 [] ,
struct V_6 * V_7 , T_4 V_75 )
{
struct V_12 * V_82 ;
struct V_38 * V_38 = F_48 ( V_27 ) ;
struct V_13 * V_14 ;
int V_68 ;
int V_41 ;
V_82 = F_8 ( V_27 ) ;
V_14 = F_97 ( V_38 , V_82 -> V_197 ) ;
if ( V_82 -> V_35 ) {
if ( F_122 ( V_14 -> V_31 ) )
return - V_206 ;
} else {
if ( F_15 ( V_14 , V_7 , V_27 -> type ) )
return - V_206 ;
}
V_82 -> V_38 = V_38 ;
V_82 -> V_23 = * V_7 ;
V_82 -> V_75 = V_75 ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 )
goto V_227;
if ( V_27 -> type == V_77 && ! V_226 [ V_228 ] )
F_123 ( V_27 ) ;
V_68 = F_25 ( V_27 ) ;
if ( ! V_226 [ V_229 ] )
V_27 -> V_68 = V_68 ;
F_10 ( V_14 , V_82 ) ;
V_227:
return V_41 ;
}
int F_124 ( struct V_37 * V_27 , struct V_225 * V_226 [] ,
struct V_6 * V_7 , T_4 V_75 )
{
struct V_12 * V_18 ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 = F_97 ( V_38 , V_42 -> V_197 ) ;
if ( V_27 == V_14 -> V_32 )
return - V_209 ;
V_18 = F_15 ( V_14 , V_7 , V_27 -> type ) ;
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 )
return - V_206 ;
} else {
V_18 = V_42 ;
if ( V_27 -> type != V_77 ) {
unsigned int V_207 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_207 = V_208 ;
else if ( V_7 -> V_24 . V_26 )
V_207 = V_78 ;
if ( ( V_27 -> V_8 ^ V_207 ) &
( V_78 | V_208 ) )
return - V_209 ;
}
}
F_94 ( V_14 , V_18 , V_27 , V_7 , ! V_226 [ V_229 ] , V_75 ) ;
return 0 ;
}
int F_125 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_65 * V_24 = & V_42 -> V_23 . V_24 ;
int V_41 ;
V_27 -> V_230 = true ;
V_27 -> V_231 = F_103 ;
V_27 -> V_94 = F_126 ( struct V_93 ) ;
if ( ! V_27 -> V_94 )
return - V_51 ;
V_41 = F_127 ( & V_42 -> V_79 , V_232 ) ;
if ( V_41 ) {
F_106 ( V_27 -> V_94 ) ;
return V_41 ;
}
V_41 = F_128 ( & V_42 -> V_115 , V_27 ) ;
if ( V_41 ) {
F_105 ( & V_42 -> V_79 ) ;
F_106 ( V_27 -> V_94 ) ;
return V_41 ;
}
V_42 -> V_27 = V_27 ;
V_42 -> V_38 = F_48 ( V_27 ) ;
strcpy ( V_42 -> V_23 . V_43 , V_27 -> V_43 ) ;
V_24 -> V_233 = 4 ;
V_24 -> V_234 = 5 ;
if ( V_42 -> V_35 ) {
V_27 -> V_218 |= V_219 ;
F_129 ( V_27 ) ;
}
return 0 ;
}
void F_130 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 ;
V_14 = F_97 ( V_38 , V_42 -> V_197 ) ;
if ( V_14 -> V_32 != V_27 )
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_30 ( & V_42 -> V_79 ) ;
}
void F_131 ( struct V_37 * V_27 , unsigned int V_235 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
V_42 -> V_197 = V_235 ;
}
