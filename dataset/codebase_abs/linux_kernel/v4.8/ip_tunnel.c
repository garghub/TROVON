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
T_1 V_1 , T_3 V_56 , int V_57 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_58 = V_57 ;
V_54 -> V_26 = V_26 ;
V_54 -> V_25 = V_25 ;
V_54 -> V_59 = V_56 ;
V_54 -> V_60 = V_55 ;
V_54 -> V_61 = V_1 ;
}
static int F_25 ( struct V_37 * V_27 )
{
struct V_37 * V_62 = NULL ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_63 * V_24 ;
int V_64 = V_65 ;
int V_66 = V_67 ;
int V_68 = V_42 -> V_64 + sizeof( struct V_63 ) ;
V_24 = & V_42 -> V_23 . V_24 ;
if ( V_24 -> V_26 ) {
struct V_53 V_54 ;
struct V_69 * V_70 ;
F_24 ( & V_54 , V_24 -> V_71 , V_24 -> V_26 ,
V_24 -> V_25 , V_42 -> V_23 . V_72 ,
F_26 ( V_24 -> V_56 ) , V_42 -> V_23 . V_15 ) ;
V_70 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( ! F_28 ( V_70 ) ) {
V_62 = V_70 -> V_73 . V_27 ;
F_29 ( V_70 ) ;
}
if ( V_27 -> type != V_74 )
V_27 -> V_8 |= V_75 ;
F_30 ( & V_42 -> V_76 ) ;
}
if ( ! V_62 && V_42 -> V_23 . V_15 )
V_62 = F_31 ( V_42 -> V_38 , V_42 -> V_23 . V_15 ) ;
if ( V_62 ) {
V_64 = V_62 -> V_77 + V_62 -> V_78 ;
V_66 = V_62 -> V_66 ;
}
V_27 -> V_78 = V_68 + V_64 ;
V_66 -= ( V_27 -> V_77 + V_68 ) ;
if ( V_66 < 68 )
V_66 = 68 ;
return V_66 ;
}
static struct V_12 * F_32 ( struct V_38 * V_38 ,
struct V_13 * V_14 ,
struct V_6 * V_23 )
{
struct V_12 * V_79 ;
struct V_37 * V_27 ;
F_33 ( ! V_14 -> V_32 ) ;
V_27 = F_16 ( V_38 , V_14 -> V_32 -> V_39 , V_23 ) ;
if ( F_28 ( V_27 ) )
return F_34 ( V_27 ) ;
V_27 -> V_66 = F_25 ( V_27 ) ;
V_79 = F_8 ( V_27 ) ;
F_10 ( V_14 , V_79 ) ;
return V_79 ;
}
int F_35 ( struct V_12 * V_42 , struct V_80 * V_81 ,
const struct V_82 * V_83 , struct V_84 * V_85 ,
bool V_86 )
{
struct V_87 * V_88 ;
const struct V_63 * V_24 = F_36 ( V_81 ) ;
int V_41 ;
#ifdef F_37
if ( F_6 ( V_24 -> V_26 ) ) {
V_42 -> V_27 -> V_89 . V_90 ++ ;
V_81 -> V_91 = V_92 ;
}
#endif
if ( ( ! ( V_83 -> V_8 & V_93 ) && ( V_42 -> V_23 . V_9 & V_93 ) ) ||
( ( V_83 -> V_8 & V_93 ) && ! ( V_42 -> V_23 . V_9 & V_93 ) ) ) {
V_42 -> V_27 -> V_89 . V_94 ++ ;
V_42 -> V_27 -> V_89 . V_95 ++ ;
goto V_96;
}
if ( V_42 -> V_23 . V_9 & V_97 ) {
if ( ! ( V_83 -> V_8 & V_97 ) ||
( V_42 -> V_98 && ( V_99 ) ( F_38 ( V_83 -> V_100 ) - V_42 -> V_98 ) < 0 ) ) {
V_42 -> V_27 -> V_89 . V_101 ++ ;
V_42 -> V_27 -> V_89 . V_95 ++ ;
goto V_96;
}
V_42 -> V_98 = F_38 ( V_83 -> V_100 ) + 1 ;
}
F_39 ( V_81 ) ;
V_41 = F_40 ( V_24 , V_81 ) ;
if ( F_41 ( V_41 ) ) {
if ( V_86 )
F_42 ( L_2 ,
& V_24 -> V_25 , V_24 -> V_56 ) ;
if ( V_41 > 1 ) {
++ V_42 -> V_27 -> V_89 . V_102 ;
++ V_42 -> V_27 -> V_89 . V_95 ;
goto V_96;
}
}
V_88 = F_43 ( V_42 -> V_27 -> V_88 ) ;
F_44 ( & V_88 -> V_103 ) ;
V_88 -> V_104 ++ ;
V_88 -> V_105 += V_81 -> V_106 ;
F_45 ( & V_88 -> V_103 ) ;
F_46 ( V_81 , ! F_47 ( V_42 -> V_38 , F_48 ( V_42 -> V_27 ) ) ) ;
if ( V_42 -> V_27 -> type == V_74 ) {
V_81 -> V_71 = F_49 ( V_81 , V_42 -> V_27 ) ;
F_50 ( V_81 , F_51 ( V_81 ) , V_107 ) ;
} else {
V_81 -> V_27 = V_42 -> V_27 ;
}
if ( V_85 )
F_52 ( V_81 , (struct V_108 * ) V_85 ) ;
F_53 ( & V_42 -> V_109 , V_81 ) ;
return 0 ;
V_96:
F_54 ( V_81 ) ;
return 0 ;
}
int F_55 ( const struct V_110 * V_40 ,
unsigned int V_111 )
{
if ( V_111 >= V_112 )
return - V_113 ;
return ! F_56 ( ( const struct V_110 * * )
& V_114 [ V_111 ] ,
NULL , V_40 ) ? 0 : - 1 ;
}
int F_57 ( const struct V_110 * V_40 ,
unsigned int V_111 )
{
int V_115 ;
if ( V_111 >= V_112 )
return - V_113 ;
V_115 = ( F_56 ( ( const struct V_110 * * )
& V_114 [ V_111 ] ,
V_40 , NULL ) == V_40 ) ? 0 : - 1 ;
F_58 () ;
return V_115 ;
}
int F_59 ( struct V_12 * V_18 ,
struct V_116 * V_117 )
{
int V_64 ;
memset ( & V_18 -> V_118 , 0 , sizeof( V_18 -> V_118 ) ) ;
V_64 = F_60 ( V_117 ) ;
if ( V_64 < 0 )
return V_64 ;
V_18 -> V_118 . type = V_117 -> type ;
V_18 -> V_118 . V_119 = V_117 -> V_119 ;
V_18 -> V_118 . V_120 = V_117 -> V_120 ;
V_18 -> V_118 . V_8 = V_117 -> V_8 ;
V_18 -> V_121 = V_64 ;
V_18 -> V_64 = V_18 -> V_121 + V_18 -> V_122 ;
return 0 ;
}
static int F_61 ( struct V_37 * V_27 , struct V_80 * V_81 ,
struct V_69 * V_70 , T_2 V_123 ,
const struct V_63 * V_124 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_125 = V_81 -> V_106 - V_42 -> V_64 - V_27 -> V_77 ;
int V_66 ;
if ( V_123 )
V_66 = F_62 ( & V_70 -> V_73 ) - V_27 -> V_77
- sizeof( struct V_63 ) - V_42 -> V_64 ;
else
V_66 = F_63 ( V_81 ) ? F_62 ( F_63 ( V_81 ) ) : V_27 -> V_66 ;
if ( F_63 ( V_81 ) )
F_63 ( V_81 ) -> V_40 -> V_126 ( F_63 ( V_81 ) , NULL , V_81 , V_66 ) ;
if ( V_81 -> V_71 == F_64 ( V_127 ) ) {
if ( ! F_65 ( V_81 ) &&
( V_124 -> V_128 & F_64 ( V_129 ) ) &&
V_66 < V_125 ) {
memset ( F_66 ( V_81 ) , 0 , sizeof( * F_66 ( V_81 ) ) ) ;
F_67 ( V_81 , V_130 , V_131 , F_68 ( V_66 ) ) ;
return - V_46 ;
}
}
#if F_69 ( V_132 )
else if ( V_81 -> V_71 == F_64 ( V_133 ) ) {
struct V_134 * V_135 = (struct V_134 * ) F_63 ( V_81 ) ;
if ( V_135 && V_66 < F_62 ( F_63 ( V_81 ) ) &&
V_66 >= V_136 ) {
if ( ( V_42 -> V_23 . V_24 . V_26 &&
! F_6 ( V_42 -> V_23 . V_24 . V_26 ) ) ||
V_135 -> V_137 . V_138 == 128 ) {
V_135 -> V_139 |= V_140 ;
F_70 ( F_63 ( V_81 ) , V_141 , V_66 ) ;
}
}
if ( ! F_65 ( V_81 ) && V_66 >= V_136 &&
V_66 < V_125 ) {
F_71 ( V_81 , V_142 , 0 , V_66 ) ;
return - V_46 ;
}
}
#endif
return 0 ;
}
void F_72 ( struct V_80 * V_81 , struct V_37 * V_27 ,
const struct V_63 * V_143 , T_4 V_71 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_63 * V_124 ;
struct V_53 V_54 ;
T_4 V_56 , V_144 ;
T_2 V_123 ;
struct V_69 * V_70 ;
unsigned int V_145 ;
T_1 V_73 ;
bool V_146 ;
V_124 = ( const struct V_63 * ) F_73 ( V_81 ) ;
V_146 = ( V_42 -> V_23 . V_24 . V_26 != 0 ) ;
memset ( & ( F_66 ( V_81 ) -> V_147 ) , 0 , sizeof( F_66 ( V_81 ) -> V_147 ) ) ;
V_73 = V_143 -> V_26 ;
if ( V_73 == 0 ) {
if ( ! F_63 ( V_81 ) ) {
V_27 -> V_89 . V_148 ++ ;
goto V_149;
}
if ( V_81 -> V_71 == F_64 ( V_127 ) ) {
V_70 = F_74 ( V_81 ) ;
V_73 = F_75 ( V_70 , V_124 -> V_26 ) ;
}
#if F_69 ( V_132 )
else if ( V_81 -> V_71 == F_64 ( V_133 ) ) {
const struct V_150 * V_151 ;
struct V_152 * V_153 ;
bool V_154 ;
int V_155 ;
V_153 = F_76 ( F_63 ( V_81 ) ,
& F_77 ( V_81 ) -> V_26 ) ;
if ( ! V_153 )
goto V_149;
V_151 = ( const struct V_150 * ) & V_153 -> V_156 ;
V_155 = F_78 ( V_151 ) ;
if ( V_155 == V_157 ) {
V_151 = & F_77 ( V_81 ) -> V_26 ;
V_155 = F_78 ( V_151 ) ;
}
if ( ( V_155 & V_158 ) == 0 )
V_154 = true ;
else {
V_154 = false ;
V_73 = V_151 -> V_159 [ 3 ] ;
}
F_79 ( V_153 ) ;
if ( V_154 )
goto V_160;
}
#endif
else
goto V_149;
V_146 = false ;
}
V_56 = V_143 -> V_56 ;
if ( V_56 & 0x1 ) {
V_56 &= ~ 0x1 ;
if ( V_81 -> V_71 == F_64 ( V_127 ) ) {
V_56 = V_124 -> V_56 ;
V_146 = false ;
} else if ( V_81 -> V_71 == F_64 ( V_133 ) ) {
V_56 = F_80 ( ( const struct V_161 * ) V_124 ) ;
V_146 = false ;
}
}
F_24 ( & V_54 , V_71 , V_73 , V_143 -> V_25 ,
V_42 -> V_23 . V_72 , F_26 ( V_56 ) , V_42 -> V_23 . V_15 ) ;
if ( V_116 ( V_81 , V_42 , & V_71 , & V_54 ) < 0 )
goto V_149;
V_70 = V_146 ? F_81 ( & V_42 -> V_76 , & V_54 . V_25 ) :
NULL ;
if ( ! V_70 ) {
V_70 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( F_28 ( V_70 ) ) {
V_27 -> V_89 . V_162 ++ ;
goto V_149;
}
if ( V_146 )
F_82 ( & V_42 -> V_76 , & V_70 -> V_73 ,
V_54 . V_25 ) ;
}
if ( V_70 -> V_73 . V_27 == V_27 ) {
F_29 ( V_70 ) ;
V_27 -> V_89 . V_163 ++ ;
goto V_149;
}
if ( F_61 ( V_27 , V_81 , V_70 , V_143 -> V_128 , V_124 ) ) {
F_29 ( V_70 ) ;
goto V_149;
}
if ( V_42 -> V_164 > 0 ) {
if ( F_83 ( V_165 ,
V_42 -> V_166 + V_167 ) ) {
V_42 -> V_164 -- ;
F_84 ( V_81 ) ;
} else
V_42 -> V_164 = 0 ;
}
V_56 = F_85 ( V_56 , V_124 , V_81 ) ;
V_144 = V_143 -> V_144 ;
if ( V_144 == 0 ) {
if ( V_81 -> V_71 == F_64 ( V_127 ) )
V_144 = V_124 -> V_144 ;
#if F_69 ( V_132 )
else if ( V_81 -> V_71 == F_64 ( V_133 ) )
V_144 = ( ( const struct V_161 * ) V_124 ) -> V_168 ;
#endif
else
V_144 = F_86 ( & V_70 -> V_73 ) ;
}
V_123 = V_143 -> V_128 ;
if ( V_81 -> V_71 == F_64 ( V_127 ) && ! V_42 -> V_169 )
V_123 |= ( V_124 -> V_128 & F_64 ( V_129 ) ) ;
V_145 = F_87 ( V_70 -> V_73 . V_27 ) + sizeof( struct V_63 )
+ V_70 -> V_73 . V_170 + F_60 ( & V_42 -> V_118 ) ;
if ( V_145 > V_27 -> V_78 )
V_27 -> V_78 = V_145 ;
if ( F_88 ( V_81 , V_27 -> V_78 ) ) {
F_29 ( V_70 ) ;
V_27 -> V_89 . V_171 ++ ;
F_54 ( V_81 ) ;
return;
}
F_89 ( NULL , V_70 , V_81 , V_54 . V_25 , V_54 . V_26 , V_71 , V_56 , V_144 ,
V_123 , ! F_47 ( V_42 -> V_38 , F_48 ( V_27 ) ) ) ;
return;
#if F_69 ( V_132 )
V_160:
F_84 ( V_81 ) ;
#endif
V_149:
V_27 -> V_89 . V_172 ++ ;
F_54 ( V_81 ) ;
}
static void F_90 ( struct V_13 * V_14 ,
struct V_12 * V_18 ,
struct V_37 * V_27 ,
struct V_6 * V_7 ,
bool V_173 )
{
F_13 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_25 = V_7 -> V_24 . V_25 ;
V_18 -> V_23 . V_24 . V_26 = V_7 -> V_24 . V_26 ;
V_18 -> V_23 . V_11 = V_7 -> V_11 ;
V_18 -> V_23 . V_72 = V_7 -> V_72 ;
if ( V_27 -> type != V_74 ) {
memcpy ( V_27 -> V_174 , & V_7 -> V_24 . V_25 , 4 ) ;
memcpy ( V_27 -> V_175 , & V_7 -> V_24 . V_26 , 4 ) ;
}
F_10 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_144 = V_7 -> V_24 . V_144 ;
V_18 -> V_23 . V_24 . V_56 = V_7 -> V_24 . V_56 ;
V_18 -> V_23 . V_24 . V_128 = V_7 -> V_24 . V_128 ;
if ( V_18 -> V_23 . V_15 != V_7 -> V_15 ) {
int V_66 ;
V_18 -> V_23 . V_15 = V_7 -> V_15 ;
V_66 = F_25 ( V_27 ) ;
if ( V_173 )
V_27 -> V_66 = V_66 ;
}
F_30 ( & V_18 -> V_76 ) ;
F_91 ( V_27 ) ;
}
int F_92 ( struct V_37 * V_27 , struct V_6 * V_7 , int V_176 )
{
int V_41 = 0 ;
struct V_12 * V_18 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_18 -> V_38 ;
struct V_13 * V_14 = F_93 ( V_38 , V_18 -> V_177 ) ;
F_33 ( ! V_14 -> V_32 ) ;
switch ( V_176 ) {
case V_178 :
if ( V_27 == V_14 -> V_32 ) {
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
V_18 = F_8 ( V_27 ) ;
}
memcpy ( V_7 , & V_18 -> V_23 , sizeof( * V_7 ) ) ;
break;
case V_179 :
case V_180 :
V_41 = - V_181 ;
if ( ! F_94 ( V_38 -> V_182 , V_183 ) )
goto V_184;
if ( V_7 -> V_24 . V_144 )
V_7 -> V_24 . V_128 |= F_64 ( V_129 ) ;
if ( ! ( V_7 -> V_9 & V_34 ) ) {
if ( ! ( V_7 -> V_9 & V_10 ) )
V_7 -> V_11 = 0 ;
if ( ! ( V_7 -> V_185 & V_10 ) )
V_7 -> V_72 = 0 ;
}
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( V_176 == V_179 ) {
if ( ! V_18 ) {
V_18 = F_32 ( V_38 , V_14 , V_7 ) ;
V_41 = F_95 ( V_18 ) ;
break;
}
V_41 = - V_186 ;
break;
}
if ( V_27 != V_14 -> V_32 && V_176 == V_180 ) {
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 ) {
V_41 = - V_186 ;
break;
}
} else {
unsigned int V_187 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_187 = V_188 ;
else if ( V_7 -> V_24 . V_26 )
V_187 = V_75 ;
if ( ( V_27 -> V_8 ^ V_187 ) & ( V_75 | V_188 ) ) {
V_41 = - V_189 ;
break;
}
V_18 = F_8 ( V_27 ) ;
}
}
if ( V_18 ) {
V_41 = 0 ;
F_90 ( V_14 , V_18 , V_27 , V_7 , true ) ;
} else {
V_41 = - V_190 ;
}
break;
case V_191 :
V_41 = - V_181 ;
if ( ! F_94 ( V_38 -> V_182 , V_183 ) )
goto V_184;
if ( V_27 == V_14 -> V_32 ) {
V_41 = - V_190 ;
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
goto V_184;
V_41 = - V_181 ;
if ( V_18 == F_8 ( V_14 -> V_32 ) )
goto V_184;
V_27 = V_18 -> V_27 ;
}
F_96 ( V_27 ) ;
V_41 = 0 ;
break;
default:
V_41 = - V_189 ;
}
V_184:
return V_41 ;
}
int F_97 ( struct V_37 * V_27 , int V_192 , bool V_193 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_68 = V_42 -> V_64 + sizeof( struct V_63 ) ;
int V_194 = 0xFFF8 - V_27 -> V_77 - V_68 ;
if ( V_192 < 68 )
return - V_189 ;
if ( V_192 > V_194 ) {
if ( V_193 )
return - V_189 ;
V_192 = V_194 ;
}
V_27 -> V_66 = V_192 ;
return 0 ;
}
int F_98 ( struct V_37 * V_27 , int V_192 )
{
return F_97 ( V_27 , V_192 , true ) ;
}
static void F_99 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
F_100 ( & V_42 -> V_109 ) ;
F_101 ( & V_42 -> V_76 ) ;
F_102 ( V_27 -> V_88 ) ;
F_22 ( V_27 ) ;
}
void F_103 ( struct V_37 * V_27 , struct V_195 * V_21 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_13 * V_14 ;
V_14 = F_93 ( V_42 -> V_38 , V_42 -> V_177 ) ;
if ( V_14 -> V_32 != V_27 ) {
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_104 ( V_27 , V_21 ) ;
}
}
struct V_38 * F_105 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_38 ;
}
int F_106 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_23 . V_15 ;
}
int F_107 ( struct V_38 * V_38 , int V_177 ,
struct V_39 * V_40 , char * V_196 )
{
struct V_13 * V_14 = F_93 ( V_38 , V_177 ) ;
struct V_6 V_23 ;
unsigned int V_197 ;
for ( V_197 = 0 ; V_197 < V_198 ; V_197 ++ )
F_108 ( & V_14 -> V_22 [ V_197 ] ) ;
if ( ! V_40 ) {
V_14 -> V_32 = NULL ;
return 0 ;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
if ( V_196 )
F_17 ( V_23 . V_43 , V_196 , V_44 ) ;
F_109 () ;
V_14 -> V_32 = F_16 ( V_38 , V_40 , & V_23 ) ;
if ( ! F_28 ( V_14 -> V_32 ) ) {
V_14 -> V_32 -> V_199 |= V_200 ;
V_14 -> V_32 -> V_66 = F_25 ( V_14 -> V_32 ) ;
F_10 ( V_14 , F_8 ( V_14 -> V_32 ) ) ;
}
F_110 () ;
return F_95 ( V_14 -> V_32 ) ;
}
static void F_111 ( struct V_13 * V_14 , struct V_195 * V_21 ,
struct V_39 * V_40 )
{
struct V_38 * V_38 = F_48 ( V_14 -> V_32 ) ;
struct V_37 * V_27 , * V_201 ;
int V_33 ;
F_112 (net, dev, aux)
if ( V_27 -> V_39 == V_40 )
F_104 ( V_27 , V_21 ) ;
for ( V_33 = 0 ; V_33 < V_198 ; V_33 ++ ) {
struct V_12 * V_18 ;
struct V_202 * V_203 ;
struct V_20 * V_204 = & V_14 -> V_22 [ V_33 ] ;
F_113 (t, n, thead, hash_node)
if ( ! F_47 ( F_48 ( V_18 -> V_27 ) , V_38 ) )
F_104 ( V_18 -> V_27 , V_21 ) ;
}
}
void F_114 ( struct V_13 * V_14 , struct V_39 * V_40 )
{
F_115 ( V_205 ) ;
F_109 () ;
F_111 ( V_14 , & V_205 , V_40 ) ;
F_116 ( & V_205 ) ;
F_110 () ;
}
int F_117 ( struct V_37 * V_27 , struct V_206 * V_207 [] ,
struct V_6 * V_7 )
{
struct V_12 * V_79 ;
struct V_38 * V_38 = F_48 ( V_27 ) ;
struct V_13 * V_14 ;
int V_66 ;
int V_41 ;
V_79 = F_8 ( V_27 ) ;
V_14 = F_93 ( V_38 , V_79 -> V_177 ) ;
if ( V_79 -> V_35 ) {
if ( F_118 ( V_14 -> V_31 ) )
return - V_186 ;
} else {
if ( F_15 ( V_14 , V_7 , V_27 -> type ) )
return - V_186 ;
}
V_79 -> V_38 = V_38 ;
V_79 -> V_23 = * V_7 ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 )
goto V_208;
if ( V_27 -> type == V_74 && ! V_207 [ V_209 ] )
F_119 ( V_27 ) ;
V_66 = F_25 ( V_27 ) ;
if ( ! V_207 [ V_210 ] )
V_27 -> V_66 = V_66 ;
F_10 ( V_14 , V_79 ) ;
V_208:
return V_41 ;
}
int F_120 ( struct V_37 * V_27 , struct V_206 * V_207 [] ,
struct V_6 * V_7 )
{
struct V_12 * V_18 ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 = F_93 ( V_38 , V_42 -> V_177 ) ;
if ( V_27 == V_14 -> V_32 )
return - V_189 ;
V_18 = F_15 ( V_14 , V_7 , V_27 -> type ) ;
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 )
return - V_186 ;
} else {
V_18 = V_42 ;
if ( V_27 -> type != V_74 ) {
unsigned int V_187 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_187 = V_188 ;
else if ( V_7 -> V_24 . V_26 )
V_187 = V_75 ;
if ( ( V_27 -> V_8 ^ V_187 ) &
( V_75 | V_188 ) )
return - V_189 ;
}
}
F_90 ( V_14 , V_18 , V_27 , V_7 , ! V_207 [ V_210 ] ) ;
return 0 ;
}
int F_121 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_63 * V_24 = & V_42 -> V_23 . V_24 ;
int V_41 ;
V_27 -> V_211 = F_99 ;
V_27 -> V_88 = F_122 ( struct V_87 ) ;
if ( ! V_27 -> V_88 )
return - V_51 ;
V_41 = F_123 ( & V_42 -> V_76 , V_212 ) ;
if ( V_41 ) {
F_102 ( V_27 -> V_88 ) ;
return V_41 ;
}
V_41 = F_124 ( & V_42 -> V_109 , V_27 ) ;
if ( V_41 ) {
F_101 ( & V_42 -> V_76 ) ;
F_102 ( V_27 -> V_88 ) ;
return V_41 ;
}
V_42 -> V_27 = V_27 ;
V_42 -> V_38 = F_48 ( V_27 ) ;
strcpy ( V_42 -> V_23 . V_43 , V_27 -> V_43 ) ;
V_24 -> V_213 = 4 ;
V_24 -> V_214 = 5 ;
if ( V_42 -> V_35 ) {
V_27 -> V_199 |= V_200 ;
F_125 ( V_27 ) ;
}
return 0 ;
}
void F_126 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 ;
V_14 = F_93 ( V_38 , V_42 -> V_177 ) ;
if ( V_14 -> V_32 != V_27 )
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_30 ( & V_42 -> V_76 ) ;
}
void F_127 ( struct V_37 * V_27 , int V_215 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
V_42 -> V_177 = V_215 ;
}
