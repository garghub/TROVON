static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 V_10 )
{
struct V_8 * V_11 ;
F_4 ( V_9 ) ;
V_11 = F_5 ( ( V_3 struct V_8 * * ) & V_7 -> V_9 , V_9 ) ;
F_6 ( V_11 ) ;
V_7 -> V_10 = V_10 ;
}
static T_2 void F_7 ( struct V_12 * V_13 ,
struct V_8 * V_9 , T_1 V_10 )
{
F_3 ( F_8 ( V_13 -> V_14 ) , V_9 , V_10 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
F_7 ( V_13 , NULL , 0 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
int V_15 ;
F_11 (i)
F_3 ( F_12 ( V_13 -> V_14 , V_15 ) , NULL , 0 ) ;
}
static struct V_16 * F_13 ( struct V_12 * V_13 ,
V_4 V_17 , T_1 * V_10 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_14 () ;
V_7 = F_8 ( V_13 -> V_14 ) ;
V_9 = F_15 ( V_7 -> V_9 ) ;
if ( V_9 && ! F_16 ( & V_9 -> V_18 ) )
V_9 = NULL ;
if ( V_9 ) {
if ( ! V_9 -> V_19 || V_9 -> V_20 -> V_21 ( V_9 , V_17 ) ) {
* V_10 = V_7 -> V_10 ;
} else {
F_9 ( V_13 ) ;
F_6 ( V_9 ) ;
V_9 = NULL ;
}
}
F_17 () ;
return (struct V_16 * ) V_9 ;
}
static bool F_18 ( const struct V_22 * V_23 ,
T_3 V_24 , T_1 V_1 )
{
if ( V_23 -> V_25 & V_26 ) {
if ( V_24 & V_26 )
return V_1 == V_23 -> V_27 ;
else
return false ;
} else
return ! ( V_24 & V_26 ) ;
}
struct V_12 * F_19 ( struct V_28 * V_29 ,
int V_30 , T_3 V_24 ,
T_1 V_2 , T_1 V_31 ,
T_1 V_1 )
{
unsigned int V_32 ;
struct V_12 * V_13 , * V_33 = NULL ;
struct V_34 * V_35 ;
V_32 = F_1 ( V_1 , V_2 ) ;
V_35 = & V_29 -> V_36 [ V_32 ] ;
F_20 (t, head, hash_node) {
if ( V_31 != V_13 -> V_37 . V_38 . V_10 ||
V_2 != V_13 -> V_37 . V_38 . V_39 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else
V_33 = V_13 ;
}
F_20 (t, head, hash_node) {
if ( V_2 != V_13 -> V_37 . V_38 . V_39 ||
V_13 -> V_37 . V_38 . V_10 != 0 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
V_32 = F_1 ( V_1 , 0 ) ;
V_35 = & V_29 -> V_36 [ V_32 ] ;
F_20 (t, head, hash_node) {
if ( ( V_31 != V_13 -> V_37 . V_38 . V_10 || V_13 -> V_37 . V_38 . V_39 != 0 ) &&
( V_31 != V_13 -> V_37 . V_38 . V_39 || ! F_21 ( V_31 ) ) )
continue;
if ( ! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
if ( V_24 & V_42 )
goto V_43;
F_20 (t, head, hash_node) {
if ( V_13 -> V_37 . V_27 != V_1 ||
V_13 -> V_37 . V_38 . V_10 != 0 ||
V_13 -> V_37 . V_38 . V_39 != 0 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
V_43:
if ( V_33 )
return V_33 ;
if ( V_29 -> V_44 && V_29 -> V_44 -> V_24 & V_41 )
return F_22 ( V_29 -> V_44 ) ;
return NULL ;
}
static struct V_34 * F_23 ( struct V_28 * V_29 ,
struct V_22 * V_37 )
{
unsigned int V_45 ;
T_1 V_2 ;
T_1 V_27 = V_37 -> V_27 ;
if ( V_37 -> V_38 . V_39 && ! F_21 ( V_37 -> V_38 . V_39 ) )
V_2 = V_37 -> V_38 . V_39 ;
else
V_2 = 0 ;
if ( ! ( V_37 -> V_25 & V_26 ) && ( V_37 -> V_25 & V_46 ) )
V_27 = 0 ;
V_45 = F_1 ( V_27 , V_2 ) ;
return & V_29 -> V_36 [ V_45 ] ;
}
static void F_24 ( struct V_28 * V_29 , struct V_12 * V_13 )
{
struct V_34 * V_35 = F_23 ( V_29 , & V_13 -> V_37 ) ;
F_25 ( & V_13 -> V_47 , V_35 ) ;
}
static void F_26 ( struct V_12 * V_13 )
{
F_27 ( & V_13 -> V_47 ) ;
}
static struct V_12 * F_28 ( struct V_28 * V_29 ,
struct V_22 * V_37 ,
int type )
{
T_1 V_2 = V_37 -> V_38 . V_39 ;
T_1 V_31 = V_37 -> V_38 . V_10 ;
T_1 V_1 = V_37 -> V_27 ;
T_3 V_24 = V_37 -> V_25 ;
int V_30 = V_37 -> V_30 ;
struct V_12 * V_13 = NULL ;
struct V_34 * V_35 = F_23 ( V_29 , V_37 ) ;
F_20 (t, head, hash_node) {
if ( V_31 == V_13 -> V_37 . V_38 . V_10 &&
V_2 == V_13 -> V_37 . V_38 . V_39 &&
V_30 == V_13 -> V_37 . V_30 &&
type == V_13 -> V_40 -> type &&
F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
break;
}
return V_13 ;
}
static struct V_48 * F_29 ( struct V_49 * V_49 ,
const struct V_50 * V_20 ,
struct V_22 * V_37 )
{
int V_51 ;
struct V_12 * V_52 ;
struct V_48 * V_40 ;
char V_53 [ V_54 ] ;
if ( V_37 -> V_53 [ 0 ] )
F_30 ( V_53 , V_37 -> V_53 , V_54 ) ;
else {
if ( strlen ( V_20 -> V_55 ) > ( V_54 - 3 ) ) {
V_51 = - V_56 ;
goto V_57;
}
F_30 ( V_53 , V_20 -> V_55 , V_54 ) ;
strncat ( V_53 , L_1 , 2 ) ;
}
F_31 () ;
V_40 = F_32 ( V_20 -> V_58 , V_53 , V_59 , V_20 -> V_60 ) ;
if ( ! V_40 ) {
V_51 = - V_61 ;
goto V_57;
}
F_33 ( V_40 , V_49 ) ;
V_40 -> V_50 = V_20 ;
V_52 = F_22 ( V_40 ) ;
V_52 -> V_37 = * V_37 ;
V_52 -> V_49 = V_49 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_62;
return V_40 ;
V_62:
F_35 ( V_40 ) ;
V_57:
return F_36 ( V_51 ) ;
}
static inline void F_37 ( struct V_63 * V_64 ,
int V_65 ,
T_1 V_39 , T_1 V_10 ,
T_1 V_1 , T_4 V_66 , int V_67 )
{
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_68 = V_67 ;
V_64 -> V_39 = V_39 ;
V_64 -> V_10 = V_10 ;
V_64 -> V_69 = V_66 ;
V_64 -> V_70 = V_65 ;
V_64 -> V_71 = V_1 ;
}
static int F_38 ( struct V_48 * V_40 )
{
struct V_48 * V_72 = NULL ;
struct V_12 * V_52 = F_22 ( V_40 ) ;
const struct V_73 * V_38 ;
int V_74 = V_75 ;
int V_76 = V_77 ;
int V_78 = V_52 -> V_74 + sizeof( struct V_73 ) ;
V_38 = & V_52 -> V_37 . V_38 ;
if ( V_38 -> V_39 ) {
struct V_63 V_64 ;
struct V_16 * V_79 ;
F_37 ( & V_64 , V_38 -> V_80 , V_38 -> V_39 ,
V_38 -> V_10 , V_52 -> V_37 . V_81 ,
F_39 ( V_38 -> V_66 ) , V_52 -> V_37 . V_30 ) ;
V_79 = F_40 ( V_52 -> V_49 , & V_64 ) ;
if ( ! F_41 ( V_79 ) ) {
V_72 = V_79 -> V_9 . V_40 ;
F_7 ( V_52 , & V_79 -> V_9 , V_64 . V_10 ) ;
F_42 ( V_79 ) ;
}
if ( V_40 -> type != V_82 )
V_40 -> V_24 |= V_83 ;
}
if ( ! V_72 && V_52 -> V_37 . V_30 )
V_72 = F_43 ( V_52 -> V_49 , V_52 -> V_37 . V_30 ) ;
if ( V_72 ) {
V_74 = V_72 -> V_84 + V_72 -> V_85 ;
V_76 = V_72 -> V_76 ;
}
V_40 -> V_86 = V_52 -> V_37 . V_30 ;
V_40 -> V_85 = V_78 + V_74 ;
V_76 -= ( V_40 -> V_84 + V_78 ) ;
if ( V_76 < 68 )
V_76 = 68 ;
return V_76 ;
}
static struct V_12 * F_44 ( struct V_49 * V_49 ,
struct V_28 * V_29 ,
struct V_22 * V_37 )
{
struct V_12 * V_87 ;
struct V_48 * V_40 ;
F_45 ( ! V_29 -> V_44 ) ;
V_40 = F_29 ( V_49 , V_29 -> V_44 -> V_50 , V_37 ) ;
if ( F_41 ( V_40 ) )
return F_46 ( V_40 ) ;
V_40 -> V_76 = F_38 ( V_40 ) ;
V_87 = F_22 ( V_40 ) ;
F_24 ( V_29 , V_87 ) ;
return V_87 ;
}
int F_47 ( struct V_12 * V_52 , struct V_88 * V_89 ,
const struct V_90 * V_91 , bool V_92 )
{
struct V_93 * V_94 ;
const struct V_73 * V_38 = F_48 ( V_89 ) ;
int V_51 ;
#ifdef F_49
if ( F_21 ( V_38 -> V_39 ) ) {
V_52 -> V_40 -> V_95 . V_96 ++ ;
V_89 -> V_97 = V_98 ;
}
#endif
if ( ( ! ( V_91 -> V_24 & V_99 ) && ( V_52 -> V_37 . V_25 & V_99 ) ) ||
( ( V_91 -> V_24 & V_99 ) && ! ( V_52 -> V_37 . V_25 & V_99 ) ) ) {
V_52 -> V_40 -> V_95 . V_100 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
if ( V_52 -> V_37 . V_25 & V_103 ) {
if ( ! ( V_91 -> V_24 & V_103 ) ||
( V_52 -> V_104 && ( V_105 ) ( F_50 ( V_91 -> V_106 ) - V_52 -> V_104 ) < 0 ) ) {
V_52 -> V_40 -> V_95 . V_107 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
V_52 -> V_104 = F_50 ( V_91 -> V_106 ) + 1 ;
}
F_51 ( V_89 ) ;
V_51 = F_52 ( V_38 , V_89 ) ;
if ( F_53 ( V_51 ) ) {
if ( V_92 )
F_54 ( L_2 ,
& V_38 -> V_10 , V_38 -> V_66 ) ;
if ( V_51 > 1 ) {
++ V_52 -> V_40 -> V_95 . V_108 ;
++ V_52 -> V_40 -> V_95 . V_101 ;
goto V_102;
}
}
V_94 = F_55 ( V_52 -> V_40 -> V_94 ) ;
F_56 ( & V_94 -> V_109 ) ;
V_94 -> V_110 ++ ;
V_94 -> V_111 += V_89 -> V_112 ;
F_57 ( & V_94 -> V_109 ) ;
F_58 ( V_89 , ! F_59 ( V_52 -> V_49 , F_60 ( V_52 -> V_40 ) ) ) ;
if ( V_52 -> V_40 -> type == V_82 ) {
V_89 -> V_80 = F_61 ( V_89 , V_52 -> V_40 ) ;
F_62 ( V_89 , F_63 ( V_89 ) , V_113 ) ;
} else {
V_89 -> V_40 = V_52 -> V_40 ;
}
F_64 ( & V_52 -> V_114 , V_89 ) ;
return 0 ;
V_102:
F_65 ( V_89 ) ;
return 0 ;
}
static int F_66 ( struct V_115 * V_116 )
{
switch ( V_116 -> type ) {
case V_117 :
return 0 ;
case V_118 :
return sizeof( struct V_119 ) ;
case V_120 :
return sizeof( struct V_119 ) + sizeof( struct V_121 ) ;
default:
return - V_122 ;
}
}
int F_67 ( struct V_12 * V_13 ,
struct V_115 * V_123 )
{
int V_74 ;
memset ( & V_13 -> V_124 , 0 , sizeof( V_13 -> V_124 ) ) ;
V_74 = F_66 ( V_123 ) ;
if ( V_74 < 0 )
return V_74 ;
V_13 -> V_124 . type = V_123 -> type ;
V_13 -> V_124 . V_125 = V_123 -> V_125 ;
V_13 -> V_124 . V_126 = V_123 -> V_126 ;
V_13 -> V_124 . V_24 = V_123 -> V_24 ;
V_13 -> V_127 = V_74 ;
V_13 -> V_74 = V_13 -> V_127 + V_13 -> V_128 ;
return 0 ;
}
static int F_68 ( struct V_88 * V_89 , struct V_115 * V_116 ,
T_5 V_129 , T_6 * V_80 , struct V_63 * V_64 )
{
struct V_119 * V_130 ;
T_3 V_125 ;
bool V_131 = ! ! ( V_116 -> V_24 & V_132 ) ;
int type = V_131 ? V_133 : V_134 ;
V_89 = F_69 ( V_89 , V_131 , type ) ;
if ( F_41 ( V_89 ) )
return F_70 ( V_89 ) ;
V_125 = V_116 -> V_125 ? : F_71 ( F_60 ( V_89 -> V_40 ) ,
V_89 , 0 , 0 , false ) ;
F_72 ( V_89 , V_129 ) ;
F_73 ( V_89 ) ;
V_130 = F_74 ( V_89 ) ;
if ( V_116 -> type == V_120 ) {
struct V_121 * V_121 = (struct V_121 * ) & V_130 [ 1 ] ;
V_121 -> V_135 = 0 ;
V_121 -> V_74 = 0 ;
V_121 -> V_24 = 0 ;
V_121 -> V_136 = * V_80 ;
}
V_130 -> V_137 = V_116 -> V_126 ;
V_130 -> V_138 = V_125 ;
V_130 -> V_112 = F_75 ( V_89 -> V_112 ) ;
V_130 -> V_21 = 0 ;
F_76 ( ! ( V_116 -> V_24 & V_132 ) , V_89 ,
V_64 -> V_10 , V_64 -> V_39 , V_89 -> V_112 ) ;
* V_80 = V_139 ;
return 0 ;
}
int V_115 ( struct V_88 * V_89 , struct V_12 * V_13 ,
T_6 * V_80 , struct V_63 * V_64 )
{
switch ( V_13 -> V_124 . type ) {
case V_117 :
return 0 ;
case V_118 :
case V_120 :
return F_68 ( V_89 , & V_13 -> V_124 , V_13 -> V_127 ,
V_80 , V_64 ) ;
default:
return - V_122 ;
}
}
static int F_77 ( struct V_48 * V_40 , struct V_88 * V_89 ,
struct V_16 * V_79 , T_3 V_140 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_141 = V_89 -> V_112 - V_52 -> V_74 - V_40 -> V_84 ;
int V_76 ;
if ( V_140 )
V_76 = F_78 ( & V_79 -> V_9 ) - V_40 -> V_84
- sizeof( struct V_73 ) - V_52 -> V_74 ;
else
V_76 = F_79 ( V_89 ) ? F_78 ( F_79 ( V_89 ) ) : V_40 -> V_76 ;
if ( F_79 ( V_89 ) )
F_79 ( V_89 ) -> V_20 -> V_142 ( F_79 ( V_89 ) , NULL , V_89 , V_76 ) ;
if ( V_89 -> V_80 == F_75 ( V_143 ) ) {
if ( ! F_80 ( V_89 ) &&
( V_140 & F_75 ( V_144 ) ) && V_76 < V_141 ) {
memset ( F_81 ( V_89 ) , 0 , sizeof( * F_81 ( V_89 ) ) ) ;
F_82 ( V_89 , V_145 , V_146 , F_83 ( V_76 ) ) ;
return - V_56 ;
}
}
#if F_84 ( V_147 )
else if ( V_89 -> V_80 == F_75 ( V_148 ) ) {
struct V_149 * V_150 = (struct V_149 * ) F_79 ( V_89 ) ;
if ( V_150 && V_76 < F_78 ( F_79 ( V_89 ) ) &&
V_76 >= V_151 ) {
if ( ( V_52 -> V_37 . V_38 . V_39 &&
! F_21 ( V_52 -> V_37 . V_38 . V_39 ) ) ||
V_150 -> V_152 . V_153 == 128 ) {
V_150 -> V_154 |= V_155 ;
F_85 ( F_79 ( V_89 ) , V_156 , V_76 ) ;
}
}
if ( ! F_80 ( V_89 ) && V_76 >= V_151 &&
V_76 < V_141 ) {
F_86 ( V_89 , V_157 , 0 , V_76 ) ;
return - V_56 ;
}
}
#endif
return 0 ;
}
void F_87 ( struct V_88 * V_89 , struct V_48 * V_40 ,
const struct V_73 * V_158 , T_6 V_80 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
const struct V_73 * V_159 ;
struct V_63 V_64 ;
T_6 V_66 , V_160 ;
T_3 V_140 ;
struct V_16 * V_79 ;
unsigned int V_161 ;
T_1 V_9 ;
int V_51 ;
bool V_162 ;
V_159 = ( const struct V_73 * ) F_88 ( V_89 ) ;
V_162 = ( V_52 -> V_37 . V_38 . V_39 != 0 ) ;
V_9 = V_158 -> V_39 ;
if ( V_9 == 0 ) {
if ( F_79 ( V_89 ) == NULL ) {
V_40 -> V_95 . V_163 ++ ;
goto V_164;
}
if ( V_89 -> V_80 == F_75 ( V_143 ) ) {
V_79 = F_89 ( V_89 ) ;
V_9 = F_90 ( V_79 , V_159 -> V_39 ) ;
}
#if F_84 ( V_147 )
else if ( V_89 -> V_80 == F_75 ( V_148 ) ) {
const struct V_165 * V_166 ;
struct V_167 * V_168 ;
bool V_169 ;
int V_170 ;
V_168 = F_91 ( F_79 ( V_89 ) ,
& F_92 ( V_89 ) -> V_39 ) ;
if ( V_168 == NULL )
goto V_164;
V_166 = ( const struct V_165 * ) & V_168 -> V_171 ;
V_170 = F_93 ( V_166 ) ;
if ( V_170 == V_172 ) {
V_166 = & F_92 ( V_89 ) -> V_39 ;
V_170 = F_93 ( V_166 ) ;
}
if ( ( V_170 & V_173 ) == 0 )
V_169 = true ;
else {
V_169 = false ;
V_9 = V_166 -> V_174 [ 3 ] ;
}
F_94 ( V_168 ) ;
if ( V_169 )
goto V_175;
}
#endif
else
goto V_164;
V_162 = false ;
}
V_66 = V_158 -> V_66 ;
if ( V_66 & 0x1 ) {
V_66 &= ~ 0x1 ;
if ( V_89 -> V_80 == F_75 ( V_143 ) ) {
V_66 = V_159 -> V_66 ;
V_162 = false ;
} else if ( V_89 -> V_80 == F_75 ( V_148 ) ) {
V_66 = F_95 ( ( const struct V_176 * ) V_159 ) ;
V_162 = false ;
}
}
F_37 ( & V_64 , V_80 , V_9 , V_158 -> V_10 ,
V_52 -> V_37 . V_81 , F_39 ( V_66 ) , V_52 -> V_37 . V_30 ) ;
if ( V_115 ( V_89 , V_52 , & V_80 , & V_64 ) < 0 )
goto V_164;
V_79 = V_162 ? F_13 ( V_52 , 0 , & V_64 . V_10 ) : NULL ;
if ( ! V_79 ) {
V_79 = F_40 ( V_52 -> V_49 , & V_64 ) ;
if ( F_41 ( V_79 ) ) {
V_40 -> V_95 . V_177 ++ ;
goto V_164;
}
if ( V_162 )
F_7 ( V_52 , & V_79 -> V_9 , V_64 . V_10 ) ;
}
if ( V_79 -> V_9 . V_40 == V_40 ) {
F_42 ( V_79 ) ;
V_40 -> V_95 . V_178 ++ ;
goto V_164;
}
if ( F_77 ( V_40 , V_89 , V_79 , V_158 -> V_179 ) ) {
F_42 ( V_79 ) ;
goto V_164;
}
if ( V_52 -> V_180 > 0 ) {
if ( F_96 ( V_181 ,
V_52 -> V_182 + V_183 ) ) {
V_52 -> V_180 -- ;
memset ( F_81 ( V_89 ) , 0 , sizeof( * F_81 ( V_89 ) ) ) ;
F_97 ( V_89 ) ;
} else
V_52 -> V_180 = 0 ;
}
V_66 = F_98 ( V_66 , V_159 , V_89 ) ;
V_160 = V_158 -> V_160 ;
if ( V_160 == 0 ) {
if ( V_89 -> V_80 == F_75 ( V_143 ) )
V_160 = V_159 -> V_160 ;
#if F_84 ( V_147 )
else if ( V_89 -> V_80 == F_75 ( V_148 ) )
V_160 = ( ( const struct V_176 * ) V_159 ) -> V_184 ;
#endif
else
V_160 = F_99 ( & V_79 -> V_9 ) ;
}
V_140 = V_158 -> V_179 ;
if ( V_89 -> V_80 == F_75 ( V_143 ) )
V_140 |= ( V_159 -> V_179 & F_75 ( V_144 ) ) ;
V_161 = F_100 ( V_79 -> V_9 . V_40 ) + sizeof( struct V_73 )
+ V_79 -> V_9 . V_185 + F_66 ( & V_52 -> V_124 ) ;
if ( V_161 > V_40 -> V_85 )
V_40 -> V_85 = V_161 ;
if ( F_101 ( V_89 , V_40 -> V_85 ) ) {
F_42 ( V_79 ) ;
V_40 -> V_95 . V_186 ++ ;
F_65 ( V_89 ) ;
return;
}
V_51 = F_102 ( V_89 -> V_187 , V_79 , V_89 , V_64 . V_10 , V_64 . V_39 , V_80 ,
V_66 , V_160 , V_140 , ! F_59 ( V_52 -> V_49 , F_60 ( V_40 ) ) ) ;
F_103 ( V_51 , & V_40 -> V_95 , V_40 -> V_94 ) ;
return;
#if F_84 ( V_147 )
V_175:
F_97 ( V_89 ) ;
#endif
V_164:
V_40 -> V_95 . V_188 ++ ;
F_65 ( V_89 ) ;
}
static void F_104 ( struct V_28 * V_29 ,
struct V_12 * V_13 ,
struct V_48 * V_40 ,
struct V_22 * V_23 ,
bool V_189 )
{
F_26 ( V_13 ) ;
V_13 -> V_37 . V_38 . V_10 = V_23 -> V_38 . V_10 ;
V_13 -> V_37 . V_38 . V_39 = V_23 -> V_38 . V_39 ;
V_13 -> V_37 . V_27 = V_23 -> V_27 ;
V_13 -> V_37 . V_81 = V_23 -> V_81 ;
if ( V_40 -> type != V_82 ) {
memcpy ( V_40 -> V_190 , & V_23 -> V_38 . V_10 , 4 ) ;
memcpy ( V_40 -> V_191 , & V_23 -> V_38 . V_39 , 4 ) ;
}
F_24 ( V_29 , V_13 ) ;
V_13 -> V_37 . V_38 . V_160 = V_23 -> V_38 . V_160 ;
V_13 -> V_37 . V_38 . V_66 = V_23 -> V_38 . V_66 ;
V_13 -> V_37 . V_38 . V_179 = V_23 -> V_38 . V_179 ;
if ( V_13 -> V_37 . V_30 != V_23 -> V_30 ) {
int V_76 ;
V_13 -> V_37 . V_30 = V_23 -> V_30 ;
V_76 = F_38 ( V_40 ) ;
if ( V_189 )
V_40 -> V_76 = V_76 ;
}
F_10 ( V_13 ) ;
F_105 ( V_40 ) ;
}
int F_106 ( struct V_48 * V_40 , struct V_22 * V_23 , int V_192 )
{
int V_51 = 0 ;
struct V_12 * V_13 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_13 -> V_49 ;
struct V_28 * V_29 = F_107 ( V_49 , V_13 -> V_193 ) ;
F_45 ( ! V_29 -> V_44 ) ;
switch ( V_192 ) {
case V_194 :
if ( V_40 == V_29 -> V_44 ) {
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_13 == NULL )
V_13 = F_22 ( V_40 ) ;
}
memcpy ( V_23 , & V_13 -> V_37 , sizeof( * V_23 ) ) ;
break;
case V_195 :
case V_196 :
V_51 = - V_197 ;
if ( ! F_108 ( V_49 -> V_198 , V_199 ) )
goto V_200;
if ( V_23 -> V_38 . V_160 )
V_23 -> V_38 . V_179 |= F_75 ( V_144 ) ;
if ( ! ( V_23 -> V_25 & V_46 ) ) {
if ( ! ( V_23 -> V_25 & V_26 ) )
V_23 -> V_27 = 0 ;
if ( ! ( V_23 -> V_201 & V_26 ) )
V_23 -> V_81 = 0 ;
}
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_192 == V_195 ) {
if ( ! V_13 ) {
V_13 = F_44 ( V_49 , V_29 , V_23 ) ;
V_51 = F_109 ( V_13 ) ;
break;
}
V_51 = - V_202 ;
break;
}
if ( V_40 != V_29 -> V_44 && V_192 == V_196 ) {
if ( V_13 != NULL ) {
if ( V_13 -> V_40 != V_40 ) {
V_51 = - V_202 ;
break;
}
} else {
unsigned int V_203 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_203 = V_204 ;
else if ( V_23 -> V_38 . V_39 )
V_203 = V_83 ;
if ( ( V_40 -> V_24 ^ V_203 ) & ( V_83 | V_204 ) ) {
V_51 = - V_122 ;
break;
}
V_13 = F_22 ( V_40 ) ;
}
}
if ( V_13 ) {
V_51 = 0 ;
F_104 ( V_29 , V_13 , V_40 , V_23 , true ) ;
} else {
V_51 = - V_205 ;
}
break;
case V_206 :
V_51 = - V_197 ;
if ( ! F_108 ( V_49 -> V_198 , V_199 ) )
goto V_200;
if ( V_40 == V_29 -> V_44 ) {
V_51 = - V_205 ;
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_13 == NULL )
goto V_200;
V_51 = - V_197 ;
if ( V_13 == F_22 ( V_29 -> V_44 ) )
goto V_200;
V_40 = V_13 -> V_40 ;
}
F_110 ( V_40 ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_122 ;
}
V_200:
return V_51 ;
}
int F_111 ( struct V_48 * V_40 , int V_207 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_78 = V_52 -> V_74 + sizeof( struct V_73 ) ;
if ( V_207 < 68 ||
V_207 > 0xFFF8 - V_40 -> V_84 - V_78 )
return - V_122 ;
V_40 -> V_76 = V_207 ;
return 0 ;
}
static void F_112 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
F_113 ( & V_52 -> V_114 ) ;
F_114 ( V_52 -> V_14 ) ;
F_114 ( V_40 -> V_94 ) ;
F_35 ( V_40 ) ;
}
void F_115 ( struct V_48 * V_40 , struct V_208 * V_35 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_28 * V_29 ;
V_29 = F_107 ( V_52 -> V_49 , V_52 -> V_193 ) ;
if ( V_29 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_116 ( V_40 , V_35 ) ;
}
}
int F_117 ( struct V_49 * V_49 , int V_193 ,
struct V_50 * V_20 , char * V_209 )
{
struct V_28 * V_29 = F_107 ( V_49 , V_193 ) ;
struct V_22 V_37 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_210 ; V_15 ++ )
F_118 ( & V_29 -> V_36 [ V_15 ] ) ;
if ( ! V_20 ) {
V_29 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_209 )
F_30 ( V_37 . V_53 , V_209 , V_54 ) ;
F_119 () ;
V_29 -> V_44 = F_29 ( V_49 , V_20 , & V_37 ) ;
if ( ! F_41 ( V_29 -> V_44 ) ) {
V_29 -> V_44 -> V_211 |= V_212 ;
V_29 -> V_44 -> V_76 = F_38 ( V_29 -> V_44 ) ;
F_24 ( V_29 , F_22 ( V_29 -> V_44 ) ) ;
}
F_120 () ;
return F_109 ( V_29 -> V_44 ) ;
}
static void F_121 ( struct V_28 * V_29 , struct V_208 * V_35 ,
struct V_50 * V_20 )
{
struct V_49 * V_49 = F_60 ( V_29 -> V_44 ) ;
struct V_48 * V_40 , * V_213 ;
int V_45 ;
F_122 (net, dev, aux)
if ( V_40 -> V_50 == V_20 )
F_116 ( V_40 , V_35 ) ;
for ( V_45 = 0 ; V_45 < V_210 ; V_45 ++ ) {
struct V_12 * V_13 ;
struct V_214 * V_215 ;
struct V_34 * V_216 = & V_29 -> V_36 [ V_45 ] ;
F_123 (t, n, thead, hash_node)
if ( ! F_59 ( F_60 ( V_13 -> V_40 ) , V_49 ) )
F_116 ( V_13 -> V_40 , V_35 ) ;
}
}
void F_124 ( struct V_28 * V_29 , struct V_50 * V_20 )
{
F_125 ( V_217 ) ;
F_119 () ;
F_121 ( V_29 , & V_217 , V_20 ) ;
F_126 ( & V_217 ) ;
F_120 () ;
}
int F_127 ( struct V_48 * V_40 , struct V_218 * V_219 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_87 ;
struct V_49 * V_49 = F_60 ( V_40 ) ;
struct V_28 * V_29 ;
int V_76 ;
int V_51 ;
V_87 = F_22 ( V_40 ) ;
V_29 = F_107 ( V_49 , V_87 -> V_193 ) ;
if ( F_28 ( V_29 , V_23 , V_40 -> type ) )
return - V_202 ;
V_87 -> V_49 = V_49 ;
V_87 -> V_37 = * V_23 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_220;
if ( V_40 -> type == V_82 && ! V_219 [ V_221 ] )
F_128 ( V_40 ) ;
V_76 = F_38 ( V_40 ) ;
if ( ! V_219 [ V_222 ] )
V_40 -> V_76 = V_76 ;
F_24 ( V_29 , V_87 ) ;
V_220:
return V_51 ;
}
int F_129 ( struct V_48 * V_40 , struct V_218 * V_219 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_13 ;
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 = F_107 ( V_49 , V_52 -> V_193 ) ;
if ( V_40 == V_29 -> V_44 )
return - V_122 ;
V_13 = F_28 ( V_29 , V_23 , V_40 -> type ) ;
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 )
return - V_202 ;
} else {
V_13 = V_52 ;
if ( V_40 -> type != V_82 ) {
unsigned int V_203 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_203 = V_204 ;
else if ( V_23 -> V_38 . V_39 )
V_203 = V_83 ;
if ( ( V_40 -> V_24 ^ V_203 ) &
( V_83 | V_204 ) )
return - V_122 ;
}
}
F_104 ( V_29 , V_13 , V_40 , V_23 , ! V_219 [ V_222 ] ) ;
return 0 ;
}
int F_130 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_73 * V_38 = & V_52 -> V_37 . V_38 ;
int V_51 ;
V_40 -> V_223 = F_112 ;
V_40 -> V_94 = F_131 ( struct V_93 ) ;
if ( ! V_40 -> V_94 )
return - V_61 ;
V_52 -> V_14 = F_132 ( struct V_6 ) ;
if ( ! V_52 -> V_14 ) {
F_114 ( V_40 -> V_94 ) ;
return - V_61 ;
}
V_51 = F_133 ( & V_52 -> V_114 , V_40 ) ;
if ( V_51 ) {
F_114 ( V_52 -> V_14 ) ;
F_114 ( V_40 -> V_94 ) ;
return V_51 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_49 = F_60 ( V_40 ) ;
strcpy ( V_52 -> V_37 . V_53 , V_40 -> V_53 ) ;
V_38 -> V_135 = 4 ;
V_38 -> V_224 = 5 ;
return 0 ;
}
void F_134 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 ;
V_29 = F_107 ( V_49 , V_52 -> V_193 ) ;
if ( V_29 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_52 ) ;
}
void F_135 ( struct V_48 * V_40 , int V_225 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
V_52 -> V_193 = V_225 ;
}
