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
struct V_12 * V_86 ;
struct V_48 * V_40 ;
F_45 ( ! V_29 -> V_44 ) ;
V_40 = F_29 ( V_49 , V_29 -> V_44 -> V_50 , V_37 ) ;
if ( F_41 ( V_40 ) )
return F_46 ( V_40 ) ;
V_40 -> V_76 = F_38 ( V_40 ) ;
V_86 = F_22 ( V_40 ) ;
F_24 ( V_29 , V_86 ) ;
return V_86 ;
}
int F_47 ( struct V_12 * V_52 , struct V_87 * V_88 ,
const struct V_89 * V_90 , bool V_91 )
{
struct V_92 * V_93 ;
const struct V_73 * V_38 = F_48 ( V_88 ) ;
int V_51 ;
#ifdef F_49
if ( F_21 ( V_38 -> V_39 ) ) {
V_52 -> V_40 -> V_94 . V_95 ++ ;
V_88 -> V_96 = V_97 ;
}
#endif
if ( ( ! ( V_90 -> V_24 & V_98 ) && ( V_52 -> V_37 . V_25 & V_98 ) ) ||
( ( V_90 -> V_24 & V_98 ) && ! ( V_52 -> V_37 . V_25 & V_98 ) ) ) {
V_52 -> V_40 -> V_94 . V_99 ++ ;
V_52 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
if ( V_52 -> V_37 . V_25 & V_102 ) {
if ( ! ( V_90 -> V_24 & V_102 ) ||
( V_52 -> V_103 && ( V_104 ) ( F_50 ( V_90 -> V_105 ) - V_52 -> V_103 ) < 0 ) ) {
V_52 -> V_40 -> V_94 . V_106 ++ ;
V_52 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
V_52 -> V_103 = F_50 ( V_90 -> V_105 ) + 1 ;
}
F_51 ( V_88 ) ;
V_51 = F_52 ( V_38 , V_88 ) ;
if ( F_53 ( V_51 ) ) {
if ( V_91 )
F_54 ( L_2 ,
& V_38 -> V_10 , V_38 -> V_66 ) ;
if ( V_51 > 1 ) {
++ V_52 -> V_40 -> V_94 . V_107 ;
++ V_52 -> V_40 -> V_94 . V_100 ;
goto V_101;
}
}
V_93 = F_55 ( V_52 -> V_40 -> V_93 ) ;
F_56 ( & V_93 -> V_108 ) ;
V_93 -> V_109 ++ ;
V_93 -> V_110 += V_88 -> V_111 ;
F_57 ( & V_93 -> V_108 ) ;
F_58 ( V_88 , ! F_59 ( V_52 -> V_49 , F_60 ( V_52 -> V_40 ) ) ) ;
if ( V_52 -> V_40 -> type == V_82 ) {
V_88 -> V_80 = F_61 ( V_88 , V_52 -> V_40 ) ;
F_62 ( V_88 , F_63 ( V_88 ) , V_112 ) ;
} else {
V_88 -> V_40 = V_52 -> V_40 ;
}
F_64 ( & V_52 -> V_113 , V_88 ) ;
return 0 ;
V_101:
F_65 ( V_88 ) ;
return 0 ;
}
static int F_66 ( struct V_114 * V_115 )
{
const struct V_116 * V_20 ;
int V_74 = - V_117 ;
if ( V_115 -> type == V_118 )
return 0 ;
if ( V_115 -> type >= V_119 )
return - V_117 ;
F_14 () ;
V_20 = F_15 ( V_120 [ V_115 -> type ] ) ;
if ( F_67 ( V_20 && V_20 -> V_121 ) )
V_74 = V_20 -> V_121 ( V_115 ) ;
F_17 () ;
return V_74 ;
}
int F_68 ( const struct V_116 * V_20 ,
unsigned int V_122 )
{
if ( V_122 >= V_119 )
return - V_123 ;
return ! F_69 ( ( const struct V_116 * * )
& V_120 [ V_122 ] ,
NULL , V_20 ) ? 0 : - 1 ;
}
int F_70 ( const struct V_116 * V_20 ,
unsigned int V_122 )
{
int V_124 ;
if ( V_122 >= V_119 )
return - V_123 ;
V_124 = ( F_69 ( ( const struct V_116 * * )
& V_120 [ V_122 ] ,
V_20 , NULL ) == V_20 ) ? 0 : - 1 ;
F_71 () ;
return V_124 ;
}
int F_72 ( struct V_12 * V_13 ,
struct V_114 * V_125 )
{
int V_74 ;
memset ( & V_13 -> V_126 , 0 , sizeof( V_13 -> V_126 ) ) ;
V_74 = F_66 ( V_125 ) ;
if ( V_74 < 0 )
return V_74 ;
V_13 -> V_126 . type = V_125 -> type ;
V_13 -> V_126 . V_127 = V_125 -> V_127 ;
V_13 -> V_126 . V_128 = V_125 -> V_128 ;
V_13 -> V_126 . V_24 = V_125 -> V_24 ;
V_13 -> V_121 = V_74 ;
V_13 -> V_74 = V_13 -> V_121 + V_13 -> V_129 ;
return 0 ;
}
int V_114 ( struct V_87 * V_88 , struct V_12 * V_13 ,
T_5 * V_80 , struct V_63 * V_64 )
{
const struct V_116 * V_20 ;
int V_124 = - V_117 ;
if ( V_13 -> V_126 . type == V_118 )
return 0 ;
if ( V_13 -> V_126 . type >= V_119 )
return - V_117 ;
F_14 () ;
V_20 = F_15 ( V_120 [ V_13 -> V_126 . type ] ) ;
if ( F_67 ( V_20 && V_20 -> V_130 ) )
V_124 = V_20 -> V_130 ( V_88 , & V_13 -> V_126 , V_80 , V_64 ) ;
F_17 () ;
return V_124 ;
}
static int F_73 ( struct V_48 * V_40 , struct V_87 * V_88 ,
struct V_16 * V_79 , T_3 V_131 ,
const struct V_73 * V_132 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_133 = V_88 -> V_111 - V_52 -> V_74 - V_40 -> V_84 ;
int V_76 ;
if ( V_131 )
V_76 = F_74 ( & V_79 -> V_9 ) - V_40 -> V_84
- sizeof( struct V_73 ) - V_52 -> V_74 ;
else
V_76 = F_75 ( V_88 ) ? F_74 ( F_75 ( V_88 ) ) : V_40 -> V_76 ;
if ( F_75 ( V_88 ) )
F_75 ( V_88 ) -> V_20 -> V_134 ( F_75 ( V_88 ) , NULL , V_88 , V_76 ) ;
if ( V_88 -> V_80 == F_76 ( V_135 ) ) {
if ( ! F_77 ( V_88 ) &&
( V_132 -> V_136 & F_76 ( V_137 ) ) &&
V_76 < V_133 ) {
memset ( F_78 ( V_88 ) , 0 , sizeof( * F_78 ( V_88 ) ) ) ;
F_79 ( V_88 , V_138 , V_139 , F_80 ( V_76 ) ) ;
return - V_56 ;
}
}
#if F_81 ( V_140 )
else if ( V_88 -> V_80 == F_76 ( V_141 ) ) {
struct V_142 * V_143 = (struct V_142 * ) F_75 ( V_88 ) ;
if ( V_143 && V_76 < F_74 ( F_75 ( V_88 ) ) &&
V_76 >= V_144 ) {
if ( ( V_52 -> V_37 . V_38 . V_39 &&
! F_21 ( V_52 -> V_37 . V_38 . V_39 ) ) ||
V_143 -> V_145 . V_146 == 128 ) {
V_143 -> V_147 |= V_148 ;
F_82 ( F_75 ( V_88 ) , V_149 , V_76 ) ;
}
}
if ( ! F_77 ( V_88 ) && V_76 >= V_144 &&
V_76 < V_133 ) {
F_83 ( V_88 , V_150 , 0 , V_76 ) ;
return - V_56 ;
}
}
#endif
return 0 ;
}
void F_84 ( struct V_87 * V_88 , struct V_48 * V_40 ,
const struct V_73 * V_151 , T_5 V_80 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
const struct V_73 * V_132 ;
struct V_63 V_64 ;
T_5 V_66 , V_152 ;
T_3 V_131 ;
struct V_16 * V_79 ;
unsigned int V_153 ;
T_1 V_9 ;
int V_51 ;
bool V_154 ;
V_132 = ( const struct V_73 * ) F_85 ( V_88 ) ;
V_154 = ( V_52 -> V_37 . V_38 . V_39 != 0 ) ;
V_9 = V_151 -> V_39 ;
if ( V_9 == 0 ) {
if ( ! F_75 ( V_88 ) ) {
V_40 -> V_94 . V_155 ++ ;
goto V_156;
}
if ( V_88 -> V_80 == F_76 ( V_135 ) ) {
V_79 = F_86 ( V_88 ) ;
V_9 = F_87 ( V_79 , V_132 -> V_39 ) ;
}
#if F_81 ( V_140 )
else if ( V_88 -> V_80 == F_76 ( V_141 ) ) {
const struct V_157 * V_158 ;
struct V_159 * V_160 ;
bool V_161 ;
int V_162 ;
V_160 = F_88 ( F_75 ( V_88 ) ,
& F_89 ( V_88 ) -> V_39 ) ;
if ( ! V_160 )
goto V_156;
V_158 = ( const struct V_157 * ) & V_160 -> V_163 ;
V_162 = F_90 ( V_158 ) ;
if ( V_162 == V_164 ) {
V_158 = & F_89 ( V_88 ) -> V_39 ;
V_162 = F_90 ( V_158 ) ;
}
if ( ( V_162 & V_165 ) == 0 )
V_161 = true ;
else {
V_161 = false ;
V_9 = V_158 -> V_166 [ 3 ] ;
}
F_91 ( V_160 ) ;
if ( V_161 )
goto V_167;
}
#endif
else
goto V_156;
V_154 = false ;
}
V_66 = V_151 -> V_66 ;
if ( V_66 & 0x1 ) {
V_66 &= ~ 0x1 ;
if ( V_88 -> V_80 == F_76 ( V_135 ) ) {
V_66 = V_132 -> V_66 ;
V_154 = false ;
} else if ( V_88 -> V_80 == F_76 ( V_141 ) ) {
V_66 = F_92 ( ( const struct V_168 * ) V_132 ) ;
V_154 = false ;
}
}
F_37 ( & V_64 , V_80 , V_9 , V_151 -> V_10 ,
V_52 -> V_37 . V_81 , F_39 ( V_66 ) , V_52 -> V_37 . V_30 ) ;
if ( V_114 ( V_88 , V_52 , & V_80 , & V_64 ) < 0 )
goto V_156;
V_79 = V_154 ? F_13 ( V_52 , 0 , & V_64 . V_10 ) : NULL ;
if ( ! V_79 ) {
V_79 = F_40 ( V_52 -> V_49 , & V_64 ) ;
if ( F_41 ( V_79 ) ) {
V_40 -> V_94 . V_169 ++ ;
goto V_156;
}
if ( V_154 )
F_7 ( V_52 , & V_79 -> V_9 , V_64 . V_10 ) ;
}
if ( V_79 -> V_9 . V_40 == V_40 ) {
F_42 ( V_79 ) ;
V_40 -> V_94 . V_170 ++ ;
goto V_156;
}
if ( F_73 ( V_40 , V_88 , V_79 , V_151 -> V_136 , V_132 ) ) {
F_42 ( V_79 ) ;
goto V_156;
}
if ( V_52 -> V_171 > 0 ) {
if ( F_93 ( V_172 ,
V_52 -> V_173 + V_174 ) ) {
V_52 -> V_171 -- ;
memset ( F_78 ( V_88 ) , 0 , sizeof( * F_78 ( V_88 ) ) ) ;
F_94 ( V_88 ) ;
} else
V_52 -> V_171 = 0 ;
}
V_66 = F_95 ( V_66 , V_132 , V_88 ) ;
V_152 = V_151 -> V_152 ;
if ( V_152 == 0 ) {
if ( V_88 -> V_80 == F_76 ( V_135 ) )
V_152 = V_132 -> V_152 ;
#if F_81 ( V_140 )
else if ( V_88 -> V_80 == F_76 ( V_141 ) )
V_152 = ( ( const struct V_168 * ) V_132 ) -> V_175 ;
#endif
else
V_152 = F_96 ( & V_79 -> V_9 ) ;
}
V_131 = V_151 -> V_136 ;
if ( V_88 -> V_80 == F_76 ( V_135 ) )
V_131 |= ( V_132 -> V_136 & F_76 ( V_137 ) ) ;
V_153 = F_97 ( V_79 -> V_9 . V_40 ) + sizeof( struct V_73 )
+ V_79 -> V_9 . V_176 + F_66 ( & V_52 -> V_126 ) ;
if ( V_153 > V_40 -> V_85 )
V_40 -> V_85 = V_153 ;
if ( F_98 ( V_88 , V_40 -> V_85 ) ) {
F_42 ( V_79 ) ;
V_40 -> V_94 . V_177 ++ ;
F_65 ( V_88 ) ;
return;
}
V_51 = F_99 ( NULL , V_79 , V_88 , V_64 . V_10 , V_64 . V_39 , V_80 ,
V_66 , V_152 , V_131 , ! F_59 ( V_52 -> V_49 , F_60 ( V_40 ) ) ) ;
F_100 ( V_51 , & V_40 -> V_94 , V_40 -> V_93 ) ;
return;
#if F_81 ( V_140 )
V_167:
F_94 ( V_88 ) ;
#endif
V_156:
V_40 -> V_94 . V_178 ++ ;
F_65 ( V_88 ) ;
}
static void F_101 ( struct V_28 * V_29 ,
struct V_12 * V_13 ,
struct V_48 * V_40 ,
struct V_22 * V_23 ,
bool V_179 )
{
F_26 ( V_13 ) ;
V_13 -> V_37 . V_38 . V_10 = V_23 -> V_38 . V_10 ;
V_13 -> V_37 . V_38 . V_39 = V_23 -> V_38 . V_39 ;
V_13 -> V_37 . V_27 = V_23 -> V_27 ;
V_13 -> V_37 . V_81 = V_23 -> V_81 ;
if ( V_40 -> type != V_82 ) {
memcpy ( V_40 -> V_180 , & V_23 -> V_38 . V_10 , 4 ) ;
memcpy ( V_40 -> V_181 , & V_23 -> V_38 . V_39 , 4 ) ;
}
F_24 ( V_29 , V_13 ) ;
V_13 -> V_37 . V_38 . V_152 = V_23 -> V_38 . V_152 ;
V_13 -> V_37 . V_38 . V_66 = V_23 -> V_38 . V_66 ;
V_13 -> V_37 . V_38 . V_136 = V_23 -> V_38 . V_136 ;
if ( V_13 -> V_37 . V_30 != V_23 -> V_30 ) {
int V_76 ;
V_13 -> V_37 . V_30 = V_23 -> V_30 ;
V_76 = F_38 ( V_40 ) ;
if ( V_179 )
V_40 -> V_76 = V_76 ;
}
F_10 ( V_13 ) ;
F_102 ( V_40 ) ;
}
int F_103 ( struct V_48 * V_40 , struct V_22 * V_23 , int V_182 )
{
int V_51 = 0 ;
struct V_12 * V_13 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_13 -> V_49 ;
struct V_28 * V_29 = F_104 ( V_49 , V_13 -> V_183 ) ;
F_45 ( ! V_29 -> V_44 ) ;
switch ( V_182 ) {
case V_184 :
if ( V_40 == V_29 -> V_44 ) {
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( ! V_13 )
V_13 = F_22 ( V_40 ) ;
}
memcpy ( V_23 , & V_13 -> V_37 , sizeof( * V_23 ) ) ;
break;
case V_185 :
case V_186 :
V_51 = - V_187 ;
if ( ! F_105 ( V_49 -> V_188 , V_189 ) )
goto V_190;
if ( V_23 -> V_38 . V_152 )
V_23 -> V_38 . V_136 |= F_76 ( V_137 ) ;
if ( ! ( V_23 -> V_25 & V_46 ) ) {
if ( ! ( V_23 -> V_25 & V_26 ) )
V_23 -> V_27 = 0 ;
if ( ! ( V_23 -> V_191 & V_26 ) )
V_23 -> V_81 = 0 ;
}
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_182 == V_185 ) {
if ( ! V_13 ) {
V_13 = F_44 ( V_49 , V_29 , V_23 ) ;
V_51 = F_106 ( V_13 ) ;
break;
}
V_51 = - V_192 ;
break;
}
if ( V_40 != V_29 -> V_44 && V_182 == V_186 ) {
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 ) {
V_51 = - V_192 ;
break;
}
} else {
unsigned int V_193 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_193 = V_194 ;
else if ( V_23 -> V_38 . V_39 )
V_193 = V_83 ;
if ( ( V_40 -> V_24 ^ V_193 ) & ( V_83 | V_194 ) ) {
V_51 = - V_117 ;
break;
}
V_13 = F_22 ( V_40 ) ;
}
}
if ( V_13 ) {
V_51 = 0 ;
F_101 ( V_29 , V_13 , V_40 , V_23 , true ) ;
} else {
V_51 = - V_195 ;
}
break;
case V_196 :
V_51 = - V_187 ;
if ( ! F_105 ( V_49 -> V_188 , V_189 ) )
goto V_190;
if ( V_40 == V_29 -> V_44 ) {
V_51 = - V_195 ;
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( ! V_13 )
goto V_190;
V_51 = - V_187 ;
if ( V_13 == F_22 ( V_29 -> V_44 ) )
goto V_190;
V_40 = V_13 -> V_40 ;
}
F_107 ( V_40 ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_117 ;
}
V_190:
return V_51 ;
}
int F_108 ( struct V_48 * V_40 , int V_197 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_78 = V_52 -> V_74 + sizeof( struct V_73 ) ;
if ( V_197 < 68 ||
V_197 > 0xFFF8 - V_40 -> V_84 - V_78 )
return - V_117 ;
V_40 -> V_76 = V_197 ;
return 0 ;
}
static void F_109 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
F_110 ( & V_52 -> V_113 ) ;
F_111 ( V_52 -> V_14 ) ;
F_111 ( V_40 -> V_93 ) ;
F_35 ( V_40 ) ;
}
void F_112 ( struct V_48 * V_40 , struct V_198 * V_35 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_28 * V_29 ;
V_29 = F_104 ( V_52 -> V_49 , V_52 -> V_183 ) ;
if ( V_29 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_113 ( V_40 , V_35 ) ;
}
}
struct V_49 * F_114 ( const struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
return V_52 -> V_49 ;
}
int F_115 ( const struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
return V_52 -> V_37 . V_30 ;
}
int F_116 ( struct V_49 * V_49 , int V_183 ,
struct V_50 * V_20 , char * V_199 )
{
struct V_28 * V_29 = F_104 ( V_49 , V_183 ) ;
struct V_22 V_37 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_200 ; V_15 ++ )
F_117 ( & V_29 -> V_36 [ V_15 ] ) ;
if ( ! V_20 ) {
V_29 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_199 )
F_30 ( V_37 . V_53 , V_199 , V_54 ) ;
F_118 () ;
V_29 -> V_44 = F_29 ( V_49 , V_20 , & V_37 ) ;
if ( ! F_41 ( V_29 -> V_44 ) ) {
V_29 -> V_44 -> V_201 |= V_202 ;
V_29 -> V_44 -> V_76 = F_38 ( V_29 -> V_44 ) ;
F_24 ( V_29 , F_22 ( V_29 -> V_44 ) ) ;
}
F_119 () ;
return F_106 ( V_29 -> V_44 ) ;
}
static void F_120 ( struct V_28 * V_29 , struct V_198 * V_35 ,
struct V_50 * V_20 )
{
struct V_49 * V_49 = F_60 ( V_29 -> V_44 ) ;
struct V_48 * V_40 , * V_203 ;
int V_45 ;
F_121 (net, dev, aux)
if ( V_40 -> V_50 == V_20 )
F_113 ( V_40 , V_35 ) ;
for ( V_45 = 0 ; V_45 < V_200 ; V_45 ++ ) {
struct V_12 * V_13 ;
struct V_204 * V_205 ;
struct V_34 * V_206 = & V_29 -> V_36 [ V_45 ] ;
F_122 (t, n, thead, hash_node)
if ( ! F_59 ( F_60 ( V_13 -> V_40 ) , V_49 ) )
F_113 ( V_13 -> V_40 , V_35 ) ;
}
}
void F_123 ( struct V_28 * V_29 , struct V_50 * V_20 )
{
F_124 ( V_207 ) ;
F_118 () ;
F_120 ( V_29 , & V_207 , V_20 ) ;
F_125 ( & V_207 ) ;
F_119 () ;
}
int F_126 ( struct V_48 * V_40 , struct V_208 * V_209 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_86 ;
struct V_49 * V_49 = F_60 ( V_40 ) ;
struct V_28 * V_29 ;
int V_76 ;
int V_51 ;
V_86 = F_22 ( V_40 ) ;
V_29 = F_104 ( V_49 , V_86 -> V_183 ) ;
if ( F_28 ( V_29 , V_23 , V_40 -> type ) )
return - V_192 ;
V_86 -> V_49 = V_49 ;
V_86 -> V_37 = * V_23 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_210;
if ( V_40 -> type == V_82 && ! V_209 [ V_211 ] )
F_127 ( V_40 ) ;
V_76 = F_38 ( V_40 ) ;
if ( ! V_209 [ V_212 ] )
V_40 -> V_76 = V_76 ;
F_24 ( V_29 , V_86 ) ;
V_210:
return V_51 ;
}
int F_128 ( struct V_48 * V_40 , struct V_208 * V_209 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_13 ;
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 = F_104 ( V_49 , V_52 -> V_183 ) ;
if ( V_40 == V_29 -> V_44 )
return - V_117 ;
V_13 = F_28 ( V_29 , V_23 , V_40 -> type ) ;
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 )
return - V_192 ;
} else {
V_13 = V_52 ;
if ( V_40 -> type != V_82 ) {
unsigned int V_193 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_193 = V_194 ;
else if ( V_23 -> V_38 . V_39 )
V_193 = V_83 ;
if ( ( V_40 -> V_24 ^ V_193 ) &
( V_83 | V_194 ) )
return - V_117 ;
}
}
F_101 ( V_29 , V_13 , V_40 , V_23 , ! V_209 [ V_212 ] ) ;
return 0 ;
}
int F_129 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_73 * V_38 = & V_52 -> V_37 . V_38 ;
int V_51 ;
V_40 -> V_213 = F_109 ;
V_40 -> V_93 = F_130 ( struct V_92 ) ;
if ( ! V_40 -> V_93 )
return - V_61 ;
V_52 -> V_14 = F_131 ( struct V_6 ) ;
if ( ! V_52 -> V_14 ) {
F_111 ( V_40 -> V_93 ) ;
return - V_61 ;
}
V_51 = F_132 ( & V_52 -> V_113 , V_40 ) ;
if ( V_51 ) {
F_111 ( V_52 -> V_14 ) ;
F_111 ( V_40 -> V_93 ) ;
return V_51 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_49 = F_60 ( V_40 ) ;
strcpy ( V_52 -> V_37 . V_53 , V_40 -> V_53 ) ;
V_38 -> V_214 = 4 ;
V_38 -> V_215 = 5 ;
return 0 ;
}
void F_133 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 ;
V_29 = F_104 ( V_49 , V_52 -> V_183 ) ;
if ( V_29 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_52 ) ;
}
void F_134 ( struct V_48 * V_40 , int V_216 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
V_52 -> V_183 = V_216 ;
}
