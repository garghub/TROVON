int F_1 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 == & V_5 ) ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 != NULL )
F_4 ( V_9 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_10 )
{
struct V_6 * V_9 = F_2 ( & V_10 -> V_11 ) ;
struct V_6 * V_12 = V_10 -> V_13 ;
int V_14 = F_6 ( & V_10 -> V_11 ) ;
if ( F_7 ( F_1 ( V_10 ) ,
V_10 -> V_15 && V_10 -> V_13 == NULL ) )
return 1 ;
if ( ! F_7 ( V_12 != NULL , V_14 ) )
return 0 ;
if ( ! F_7 ( V_12 != NULL ,
V_12 -> V_16 . V_17 == V_10 -> V_11 . V_18 ) )
return 0 ;
if ( ! F_7 ( V_14 ,
F_7 ( V_9 != NULL && V_12 != NULL , V_9 == V_12 ) &&
F_7 ( V_9 == NULL , V_12 == NULL ) ) )
return 0 ;
if ( ! F_7 ( V_10 -> V_19 == V_20 ,
V_12 == NULL && ! V_14 ) )
return 0 ;
if ( ! F_7 ( V_12 != NULL && V_10 -> V_19 < V_20 ,
( ( V_12 -> V_21 & V_22 ) == 0 ) ) )
return 0 ;
if ( ! F_7 ( V_10 -> V_19 == V_23 ,
V_12 != NULL &&
V_12 -> V_24 == V_12 -> V_25 &&
V_10 -> V_26 ) )
return 0 ;
return 1 ;
}
static void F_8 ( const struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_6 * V_29 ;
F_9 ( & V_30 ) ;
V_29 = V_2 -> V_13 ;
if ( V_29 == NULL ) {
F_10 ( & V_30 ) ;
return;
}
V_2 -> V_13 = NULL ;
V_29 -> V_31 = NULL ;
V_2 -> V_11 . V_18 = 0ULL ;
F_10 ( & V_30 ) ;
F_11 ( V_29 ) ;
if ( V_29 -> V_25 == V_29 -> V_24 ) {
struct V_32 * V_33 = V_2 -> V_3 . V_34 ;
struct V_35 * V_36 = & F_12 ( V_28 ) -> V_37 ;
T_1 V_38 ;
F_13 ( V_33 ) ;
V_38 = F_14 ( V_33 ) -> V_39 -> V_40 ;
V_36 -> V_41 = F_15 ( V_29 , V_38 ) ;
F_16 ( V_28 , V_33 , V_36 , V_42 ) ;
F_17 ( V_33 ) ;
}
F_18 ( V_29 ) ;
F_19 ( V_2 -> V_43 ) ;
F_20 ( & V_29 -> V_44 , L_1 , V_2 ) ;
F_21 ( V_29 ) ;
V_2 -> V_43 = 0 ;
}
static int F_22 ( struct V_1 * V_10 )
{
int V_45 = 0 ;
if ( V_10 -> V_26 ) {
V_10 -> V_26 = 0 ;
V_45 = F_23 ( & V_10 -> V_11 ,
V_10 -> V_46 . V_47 ) ;
}
return V_45 ;
}
static int F_24 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
F_26 ( F_5 ( V_10 ) ) ;
switch ( V_10 -> V_19 ) {
case V_50 :
F_19 ( ! V_10 -> V_26 ) ;
F_19 ( V_10 -> V_51 ) ;
return 0 ;
case V_52 :
F_22 ( V_10 ) ;
case V_53 :
F_19 ( ! V_10 -> V_26 ) ;
F_8 ( V_28 , V_10 ) ;
V_10 -> V_19 = V_50 ;
return 0 ;
case V_23 :
F_19 ( ! V_10 -> V_54 ) ;
F_19 ( V_10 -> V_26 ) ;
V_10 -> V_19 = V_55 ;
return F_22 ( V_10 ) ;
default:
F_27 ( L_2 , V_10 -> V_19 ) ;
F_28 () ;
}
}
static void F_29 ( const struct V_27 * V_28 ,
struct V_48 * V_49 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
F_26 ( F_5 ( V_10 ) ) ;
F_22 ( V_10 ) ;
F_19 ( V_10 -> V_13 == NULL ) ;
F_19 ( F_30 ( & V_10 -> V_56 ) == 0 ||
F_30 ( & V_10 -> V_56 ) == V_57 ) ;
F_31 ( V_10 , V_58 ) ;
}
static void F_32 ( const struct V_27 * V_28 ,
const struct V_59 * V_9 ,
T_2 * V_60 )
{
const struct V_61 * V_62 = & V_9 -> V_63 ;
F_33 ( V_60 , V_62 -> V_64 , V_62 -> V_65 , V_62 -> V_66 ) ;
V_60 -> V_67 . V_68 = V_62 -> V_69 ;
}
static T_1 F_34 ( T_3 V_70 )
{
T_1 V_45 = 0 ;
F_19 ( ( V_70 & ~ V_71 ) == 0 ) ;
if ( V_70 & V_72 )
V_45 |= V_73 ;
if ( V_70 & V_74 )
V_45 |= V_75 ;
if ( V_70 & V_76 )
V_45 |= V_77 ;
return V_45 ;
}
static struct V_1 * F_35 ( struct V_6 * V_78 )
{
struct V_1 * V_2 ;
F_11 ( V_78 ) ;
F_9 ( & V_30 ) ;
V_2 = V_78 -> V_31 ;
if ( V_2 != NULL ) {
struct V_59 * V_9 = V_2 -> V_3 . V_79 ;
if ( V_9 -> V_80 < V_81 || V_2 -> V_43 ) {
F_36 ( V_9 ) ;
F_37 ( & V_9 -> V_82 ,
L_3 , V_83 ) ;
} else
V_2 = NULL ;
}
F_10 ( & V_30 ) ;
F_18 ( V_78 ) ;
return V_2 ;
}
static void F_38 ( const struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_59 * V_9 ;
V_9 = V_2 -> V_3 . V_79 ;
F_20 ( & V_9 -> V_82 , L_3 , V_83 ) ;
F_39 ( V_28 , V_9 ) ;
}
static void F_40 ( const struct V_27 * V_28 , struct V_1 * V_2 ,
int V_84 )
{
struct V_85 * V_86 ;
struct V_32 * V_33 ;
struct V_87 * V_88 ;
struct V_35 * V_36 ;
unsigned V_89 ;
if ( ! ( V_2 -> V_90 & V_91 ) )
return;
V_86 = & V_2 -> V_92 ;
V_33 = V_2 -> V_3 . V_34 ;
V_88 = F_14 ( V_33 ) -> V_39 ;
V_36 = & F_12 ( V_28 ) -> V_37 ;
V_89 = V_93 | V_94 | V_95 | V_96 | V_97 ;
F_41 ( V_36 , V_86 ) ;
F_13 ( V_33 ) ;
if ( V_84 == 0 ) {
struct V_6 * V_29 ;
T_1 V_98 ;
V_29 = V_2 -> V_13 ;
F_19 ( V_29 != NULL ) ;
* V_86 = * (struct V_85 * ) V_29 -> V_99 ;
V_98 = V_86 -> V_100 ;
if ( V_98 > V_29 -> V_101 . V_67 . V_102 )
V_98 = V_29 -> V_101 . V_67 . V_102 + 1 ;
if ( V_98 >= V_88 -> V_40 ) {
F_42 ( V_29 , L_4 V_103
L_5 V_103 , V_86 -> V_100 , V_98 ) ;
V_89 |= V_42 ;
V_36 -> V_41 = V_98 ;
} else {
F_42 ( V_29 , L_4
V_103 L_6 V_103 L_7 V_103 ,
V_86 -> V_100 , V_88 -> V_40 ,
V_29 -> V_101 . V_67 . V_102 ) ;
}
F_43 ( V_29 ) ;
} else if ( V_84 == - V_104 && V_2 -> V_54 ) {
F_44 ( V_105 , L_8 V_103 L_9
L_10 V_103 L_11 , V_86 -> V_100 , V_88 -> V_40 ) ;
} else
V_89 = 0 ;
if ( V_89 != 0 )
F_16 ( V_28 , V_33 , V_36 , V_89 ) ;
F_17 ( V_33 ) ;
}
static void F_45 ( const struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_6 * V_29 , int V_84 )
{
struct V_106 * V_107 ;
struct V_59 * V_9 ;
struct V_61 * V_108 ;
F_19 ( V_29 -> V_25 == V_29 -> V_24 ) ;
if ( V_2 -> V_19 < V_23 ) {
V_9 = V_2 -> V_3 . V_79 ;
V_107 = & V_29 -> V_101 . V_67 ;
V_108 = & F_12 ( V_28 ) -> V_109 ;
V_108 -> V_64 = V_9 -> V_63 . V_64 ;
V_108 -> V_110 = F_46 ( V_29 -> V_25 ) ;
V_108 -> V_65 = F_47 ( V_108 -> V_64 , V_107 -> V_111 ) ;
V_108 -> V_66 = F_47 ( V_108 -> V_64 , V_107 -> V_102 ) ;
V_108 -> V_69 = V_107 -> V_68 ;
V_2 -> V_19 = V_23 ;
F_40 ( V_28 , V_2 , V_84 ) ;
F_18 ( V_29 ) ;
F_48 ( V_28 , V_9 , V_108 ) ;
F_49 ( V_28 , V_9 ) ;
F_26 ( F_5 ( V_2 ) ) ;
F_11 ( V_29 ) ;
}
}
static void F_50 ( const struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_6 * V_29 ;
V_29 = F_51 ( & V_2 -> V_11 , 0 ) ;
F_19 ( V_29 != NULL ) ;
F_11 ( V_29 ) ;
F_9 ( & V_30 ) ;
F_19 ( V_29 -> V_31 == V_2 ) ;
F_19 ( V_2 -> V_13 == NULL ) ;
V_2 -> V_13 = V_29 ;
F_10 ( & V_30 ) ;
if ( V_29 -> V_25 == V_29 -> V_24 )
F_45 ( V_28 , V_2 , V_29 , 0 ) ;
F_18 ( V_29 ) ;
F_52 ( & V_2 -> V_11 , V_2 -> V_46 . V_47 ) ;
V_2 -> V_26 = 1 ;
F_53 ( & V_29 -> V_44 , L_1 , V_2 ) ;
V_2 -> V_43 = 1 ;
}
static int F_54 ( void * V_18 , int V_112 )
{
struct V_1 * V_2 = V_18 ;
struct V_48 * V_49 = & V_2 -> V_3 ;
struct V_59 * V_9 = V_49 -> V_79 ;
struct V_27 * V_28 ;
struct V_113 V_114 ;
V_28 = F_55 ( & V_114 ) ;
if ( ! F_56 ( V_28 ) ) {
int V_84 ;
F_57 ( V_28 , V_9 ) ;
F_19 ( V_9 -> V_80 >= V_115 ) ;
if ( V_2 -> V_19 == V_53 ) {
V_2 -> V_19 = V_52 ;
V_84 = F_58 ( V_112 ) ;
} else if ( V_2 -> V_19 == V_20 ) {
V_84 = - V_116 ;
} else {
F_27 ( L_2 , V_2 -> V_19 ) ;
F_28 () ;
}
if ( V_84 ) {
struct V_6 * V_29 ;
V_29 = F_3 ( & V_2 -> V_11 ) ;
if ( V_29 != NULL ) {
F_11 ( V_29 ) ;
F_9 ( & V_30 ) ;
F_19 ( V_2 -> V_13 == NULL ) ;
V_29 -> V_31 = NULL ;
V_2 -> V_11 . V_18 = 0ULL ;
F_10 ( & V_30 ) ;
F_59 ( V_29 ) ;
F_18 ( V_29 ) ;
F_4 ( V_29 ) ;
}
} else {
if ( V_2 -> V_54 )
V_2 -> V_54 = 0 ;
F_50 ( V_28 , V_2 ) ;
}
if ( V_2 -> V_15 && V_84 == - V_117 ) {
F_60 ( F_14 ( V_49 -> V_34 ) ) ;
F_19 ( V_49 -> V_4 == & V_118 ) ;
F_61 ( V_28 , V_2 , 1 ) ;
V_2 -> V_19 = V_23 ;
V_84 = 0 ;
} else if ( V_2 -> V_54 && V_84 == - V_104 ) {
F_40 ( V_28 , V_2 , V_84 ) ;
F_62 ( V_28 , V_9 ) ;
V_84 = 0 ;
}
if ( V_84 == 0 ) {
if ( V_2 -> V_51 ) {
V_9 -> V_119 |= V_120 ;
F_63 ( V_28 , V_9 ) ;
V_9 -> V_119 &= ~ V_120 ;
if ( ! V_2 -> V_54 )
V_2 -> V_51 = 0 ;
}
F_49 ( V_28 , V_9 ) ;
F_64 ( V_28 , V_9 ) ;
} else {
F_65 ( V_28 , V_9 ) ;
F_66 ( V_28 , V_9 , V_84 ) ;
}
F_67 ( V_28 , V_9 , L_12 , V_9 ) ;
F_68 ( V_28 , V_9 ) ;
F_20 ( & V_9 -> V_82 , L_12 , V_9 ) ;
F_39 ( V_28 , V_9 ) ;
F_69 ( & V_114 , V_28 ) ;
} else {
F_28 () ;
}
return V_112 ;
}
static void F_70 ( const struct V_27 * V_28 ,
struct V_6 * V_29 ,
struct V_1 * V_2 , int V_121 )
{
struct V_59 * V_9 = V_2 -> V_3 . V_79 ;
F_19 ( V_2 -> V_13 == V_29 ) ;
F_71 ( V_122 < V_20 ) ;
F_19 ( ! F_1 ( V_2 ) ) ;
F_22 ( V_2 ) ;
if ( V_121 && V_2 -> V_19 < V_122 )
V_2 -> V_19 = V_122 ;
F_72 ( V_28 , V_9 ) ;
F_62 ( V_28 , V_9 ) ;
}
static int F_73 ( const struct V_27 * V_28 ,
struct V_6 * V_29 ,
void * V_123 , int V_124 )
{
struct V_1 * V_2 ;
struct V_59 * V_9 ;
int V_45 ;
int V_125 ;
F_19 ( V_124 == V_126 || V_124 == V_127 ) ;
V_125 = 0 ;
V_2 = F_35 ( V_29 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_79 ;
F_57 ( V_28 , V_9 ) ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_2 -> V_128 ) {
F_49 ( V_28 , V_9 ) ;
V_2 -> V_128 = 0 ;
}
if ( V_2 == V_29 -> V_31 ) {
F_19 ( V_123 == V_2 ) ;
F_70 ( V_28 , V_29 ,
V_2 , V_124 == V_126 ) ;
} else
V_125 = 1 ;
F_68 ( V_28 , V_9 ) ;
F_38 ( V_28 , V_2 ) ;
} else
V_125 = ( V_124 == V_126 ) ;
if ( V_125 ) {
struct V_7 * V_129 ;
V_129 = & F_12 ( V_28 ) -> V_130 ;
F_74 ( V_29 , V_129 ) ;
V_45 = F_75 ( V_129 , V_131 ) ;
} else
V_45 = 0 ;
return V_45 ;
}
static int F_76 ( struct V_6 * V_29 ,
struct V_132 * V_133 , void * V_123 ,
int V_124 )
{
struct V_27 * V_28 ;
struct V_113 V_114 ;
int V_45 ;
V_28 = F_55 ( & V_114 ) ;
if ( ! F_56 ( V_28 ) ) {
V_45 = F_73 ( V_28 , V_29 , V_123 , V_124 ) ;
F_69 ( & V_114 , V_28 ) ;
} else {
V_45 = F_77 ( V_28 ) ;
F_28 () ;
}
if ( V_45 != 0 ) {
if ( V_45 == - V_134 )
V_45 = 0 ;
else
F_27 ( L_13 , V_45 ) ;
}
return V_45 ;
}
static int F_78 ( struct V_6 * V_29 ,
T_1 V_135 , void * V_123 )
{
struct V_113 V_114 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_59 * V_9 ;
int V_45 ;
int V_136 ;
V_136 = F_79 ( V_29 , V_135 , V_123 ) ;
V_28 = F_55 ( & V_114 ) ;
if ( ! F_56 ( V_28 ) ) {
V_2 = F_35 ( V_29 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_79 ;
F_57 ( V_28 , V_9 ) ;
F_19 ( V_29 -> V_99 != NULL ) ;
F_11 ( V_29 ) ;
V_2 -> V_92 = * (struct V_85 * ) V_29 -> V_99 ;
if ( V_2 -> V_13 == NULL ) {
} else if ( V_29 -> V_25 ==
V_29 -> V_24 ) {
F_45 ( V_28 , V_2 , V_29 , V_136 ) ;
}
F_18 ( V_29 ) ;
if ( V_136 != 0 ) {
F_80 ( V_137 , V_28 , V_9 ,
L_14 , V_136 ) ;
F_66 ( V_28 , V_9 , V_136 ) ;
}
F_68 ( V_28 , V_9 ) ;
F_38 ( V_28 , V_2 ) ;
V_45 = 0 ;
} else
V_45 = - V_138 ;
F_69 ( & V_114 , V_28 ) ;
} else
V_45 = F_77 ( V_28 ) ;
return V_136 ? : V_45 ;
}
static int F_81 ( struct V_6 * V_29 , void * V_123 )
{
struct V_139 * V_140 = V_123 ;
struct V_1 * V_2 ;
struct V_59 * V_9 ;
struct V_32 * V_33 ;
struct V_113 V_114 ;
struct V_27 * V_28 ;
struct V_85 * V_86 ;
struct V_141 * V_142 ;
int V_45 ;
F_19 ( F_82 ( V_140 -> V_143 ) == V_144 ) ;
V_28 = F_55 ( & V_114 ) ;
if ( ! F_56 ( V_28 ) ) {
V_2 = F_35 ( V_29 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_79 ;
V_142 = & V_140 -> V_145 ;
F_83 ( V_142 , & V_146 ) ;
F_84 ( V_142 , & V_147 , V_148 ,
sizeof *V_86 ) ;
V_45 = F_85 ( V_142 ) ;
if ( V_45 == 0 ) {
V_86 = F_86 ( V_142 , & V_147 ) ;
V_33 = V_9 -> V_63 . V_64 ;
V_45 = F_87 ( V_28 , V_33 , V_86 ) ;
}
if ( ! F_88 ( V_140 -> V_149 ) )
F_89 ( & V_140 -> V_145 ,
& V_147 ,
sizeof( struct V_150 ) ,
V_148 ) ;
F_38 ( V_28 , V_2 ) ;
} else {
F_90 ( V_140 , 1 , NULL , NULL ) ;
V_45 = - V_138 ;
}
F_69 ( & V_114 , V_28 ) ;
} else
V_45 = F_77 ( V_28 ) ;
V_140 -> V_151 = V_45 ;
return V_45 ;
}
static unsigned long F_91 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
return F_92 ( V_49 -> V_34 ) -> V_152 ;
}
static void F_93 ( const struct V_27 * V_28 ,
const struct V_59 * clock ,
struct V_1 * V_9 ,
struct V_153 * V_154 )
{
enum V_155 V_156 ;
V_156 = clock -> V_63 . V_110 ;
if ( V_156 == V_157 )
V_156 = V_158 ;
V_154 -> V_159 = V_160 ;
V_154 -> V_47 = F_94 ( V_156 ) ;
V_154 -> V_161 = F_76 ;
V_154 -> V_162 = F_78 ;
V_154 -> V_163 = F_81 ;
V_154 -> V_164 = V_9 ;
}
static void F_61 ( const struct V_27 * V_28 ,
struct V_1 * V_10 , int V_165 )
{
struct V_48 * V_49 = & V_10 -> V_3 ;
F_19 ( V_10 -> V_19 == V_50 ||
V_10 -> V_19 == V_52 ) ;
if ( V_165 ) {
V_10 -> V_15 = 1 ;
V_49 -> V_4 = & V_5 ;
} else {
struct V_166 * V_167 = F_95 ( V_28 ) ;
struct V_168 * V_169 = V_167 -> V_170 . V_171 ;
struct V_32 * V_33 = V_49 -> V_34 ;
struct V_172 * V_173 = F_14 ( V_33 ) ;
const struct V_174 * V_175 = F_96 ( V_33 -> V_176 . V_177 ) ;
struct V_178 * V_179 ;
F_19 ( V_169 -> V_180 == V_181 ||
V_169 -> V_180 == V_182 ||
V_169 -> V_180 == V_183 ) ;
V_179 = & F_97 ( F_98 ( V_173 ) ) -> V_184 ;
V_10 -> V_15 = ( V_169 -> V_185 != V_186 ) &&
( V_169 -> V_180 == V_182 ) &&
( V_179 -> V_187 & V_188 ) ;
if ( V_169 -> V_180 == V_183 ||
( V_10 -> V_15 && F_99 ( V_173 ) ) ||
( F_100 ( V_169 ) &&
( V_179 -> V_187 & V_189 ) &&
V_175 -> V_190 ) ) {
V_10 -> V_15 = 1 ;
V_49 -> V_4 = & V_5 ;
}
}
F_19 ( F_7 ( V_10 -> V_54 , ! F_1 ( V_10 ) ) ) ;
}
static int F_101 ( const struct V_1 * V_191 ,
const struct V_1 * V_192 )
{
enum V_155 V_193 ;
enum V_155 V_194 ;
V_193 = V_191 -> V_3 . V_79 -> V_63 . V_110 ;
if ( V_192 -> V_54 &&
( V_192 -> V_19 >= V_52 || V_193 == V_158 ) )
return 1 ;
V_194 = V_192 -> V_3 . V_79 -> V_63 . V_110 ;
return ( ( V_193 == V_158 ) && ( V_194 == V_158 ) ) ;
}
static int F_102 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 )
{
struct V_59 * V_9 = V_2 -> V_3 . V_79 ;
struct V_61 * V_108 = & V_9 -> V_63 ;
struct F_92 * V_195 = F_92 ( V_108 -> V_64 ) ;
struct V_59 * V_196 ;
struct V_59 * V_197 = NULL ;
int V_198 = F_1 ( V_2 ) ;
int V_84 = 0 ;
F_19 ( F_103 ( V_9 ) ) ;
if ( V_2 -> V_54 )
return 0 ;
F_9 ( & V_195 -> V_199 ) ;
F_104 (scan, &hdr->coh_locks, cll_linkage) {
struct V_61 * V_200 = & V_196 -> V_63 ;
const struct V_1 * V_201 ;
if ( V_196 == V_9 )
break;
if ( V_196 -> V_80 < V_115 ||
V_196 -> V_80 == V_81 ||
V_200 -> V_65 > V_108 -> V_66 ||
V_200 -> V_66 < V_108 -> V_65 )
continue;
if ( V_196 -> V_63 . V_110 == V_202 ) {
F_19 ( V_108 -> V_110 != V_202 ||
V_108 -> V_69 != V_196 -> V_63 . V_69 ) ;
continue;
}
V_201 = F_105 ( V_196 ) ;
if ( ! V_198 && F_101 ( V_2 , V_201 ) )
continue;
F_36 ( V_196 ) ;
V_197 = V_196 ;
break;
}
F_10 ( & V_195 -> V_199 ) ;
if ( V_197 ) {
if ( V_9 -> V_63 . V_110 == V_202 ) {
F_44 ( V_203 , L_15
L_16 ,
V_9 , V_197 ) ;
F_39 ( V_28 , V_197 ) ;
V_84 = 0 ;
} else {
F_44 ( V_203 , L_17
L_18 ,
V_9 , V_197 ) ;
F_19 ( V_9 -> V_204 == NULL ) ;
F_53 ( & V_197 -> V_82 , L_19 ,
V_9 ) ;
V_9 -> V_204 = V_197 ;
V_84 = V_205 ;
}
}
return V_84 ;
}
static int F_106 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 ,
struct V_168 * V_206 , T_3 V_70 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
struct V_59 * V_9 = V_10 -> V_3 . V_79 ;
int V_45 ;
F_19 ( F_103 ( V_9 ) ) ;
F_107 ( V_10 -> V_19 == V_50 ,
L_2 , V_10 -> V_19 ) ;
F_107 ( F_7 ( V_10 -> V_54 , V_9 -> V_63 . V_110 <= V_158 ) ,
L_20 , V_9 , V_10 ) ;
V_45 = F_102 ( V_28 , V_10 ) ;
if ( V_45 == 0 ) {
if ( ! F_1 ( V_10 ) ) {
struct V_172 * V_33 = F_14 ( V_49 -> V_34 ) ;
struct V_207 * V_208 = F_12 ( V_28 ) ;
struct V_209 * V_210 = & V_208 -> V_211 ;
T_2 * V_60 = & V_208 -> V_212 ;
struct V_153 * V_154 = & V_10 -> V_46 ;
F_108 ( V_28 , V_9 , L_12 , V_9 ) ;
F_109 ( V_28 , V_9 ) ;
V_10 -> V_19 = V_53 ;
F_110 ( & V_33 -> V_39 -> V_213 , V_210 ) ;
F_32 ( V_28 , V_9 , V_60 ) ;
V_45 = F_111 ( F_98 ( V_33 ) , V_210 ,
& V_10 -> V_90 , V_60 ,
& V_10 -> V_92 ,
V_33 -> V_39 -> V_214 ,
F_54 ,
V_10 , V_154 , & V_10 -> V_11 ,
V_215 , 1 , V_10 -> V_51 ) ;
if ( V_45 != 0 ) {
F_65 ( V_28 , V_9 ) ;
F_112 ( V_28 , V_9 , L_12 , V_9 ) ;
if ( F_113 ( V_45 == - V_216 ) ) {
V_10 -> V_19 = V_50 ;
V_45 = 0 ;
}
}
} else {
V_10 -> V_19 = V_23 ;
V_10 -> V_217 = F_95 ( V_28 ) ;
}
}
F_19 ( F_7 ( V_10 -> V_54 , ! F_1 ( V_10 ) ) ) ;
return V_45 ;
}
static int F_114 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
struct V_59 * V_9 = V_2 -> V_3 . V_79 ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_2 -> V_54 && V_2 -> V_19 >= V_52 ) {
if ( V_2 -> V_90 & V_91 ) {
return 0 ;
} else if ( V_2 -> V_51 ) {
if ( V_9 -> V_119 & V_120 )
return - V_104 ;
else
V_2 -> V_19 = V_50 ;
} else {
F_19 ( V_9 -> V_218 ) ;
return V_9 -> V_218 ;
}
}
if ( V_2 -> V_19 == V_50 ) {
int V_84 ;
F_19 ( V_2 -> V_51 ) ;
V_2 -> V_51 = 0 ;
V_84 = F_106 ( V_28 , V_49 , NULL , V_74 | V_219 ) ;
if ( V_84 != 0 )
return V_84 ;
else
return V_220 ;
}
F_19 ( F_115 ( V_2 -> V_19 >= V_52 &&
V_9 -> V_218 == 0 , V_2 -> V_13 != NULL ) ) ;
return V_9 -> V_218 ? : V_2 -> V_19 >= V_23 ? 0 : V_205 ;
}
static int F_116 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
int V_84 ;
F_19 ( ! V_2 -> V_26 ) ;
V_84 = F_117 ( & V_2 -> V_11 , V_2 -> V_46 . V_47 ) ;
if ( V_84 == 0 ) {
V_2 -> V_26 = 1 ;
V_2 -> V_19 = V_23 ;
} else {
struct V_59 * V_9 ;
V_9 = V_49 -> V_79 ;
F_19 ( V_9 -> V_80 == V_221 ) ;
F_19 ( V_9 -> V_222 > 0 ) ;
V_2 -> V_128 = 1 ;
V_84 = V_205 ;
}
return V_84 ;
}
static int F_118 ( struct V_1 * V_10 , int V_223 )
{
struct V_59 * V_9 = V_10 -> V_3 . V_79 ;
struct V_113 V_114 ;
struct V_27 * V_28 ;
int V_45 = 0 ;
V_28 = F_55 ( & V_114 ) ;
if ( ! F_56 ( V_28 ) ) {
struct V_172 * V_33 = F_14 ( V_10 -> V_3 . V_34 ) ;
struct V_61 * V_108 = & V_9 -> V_63 ;
int V_84 = 0 ;
if ( V_108 -> V_110 >= V_224 ) {
V_45 = F_119 ( V_28 , V_33 ,
V_108 -> V_65 , V_108 -> V_66 ,
1 , V_223 ) ;
F_42 ( V_10 -> V_13 ,
L_21 , V_9 , V_45 ,
V_223 ? L_22 : L_23 ) ;
if ( V_45 > 0 )
V_45 = 0 ;
}
V_84 = F_120 ( V_28 , V_9 ) ;
if ( V_45 == 0 && V_84 < 0 )
V_45 = V_84 ;
F_69 ( & V_114 , V_28 ) ;
} else
V_45 = F_77 ( V_28 ) ;
if ( V_45 == 0 ) {
V_10 -> V_225 = 1 ;
F_26 ( ! F_121 ( V_10 ) ) ;
}
return V_45 ;
}
static void F_122 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_59 * V_9 = V_49 -> V_79 ;
struct V_1 * V_2 = F_25 ( V_49 ) ;
struct V_6 * V_29 = V_2 -> V_13 ;
int V_45 = 0 ;
int V_223 ;
F_19 ( F_103 ( V_9 ) ) ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_29 != NULL ) {
int V_226 ;
V_223 = ! ! ( V_29 -> V_21 & V_227 ) ;
if ( V_2 -> V_19 >= V_23 )
V_45 = F_118 ( V_2 , V_223 ) ;
F_22 ( V_2 ) ;
F_11 ( V_29 ) ;
V_226 = ( V_29 -> V_228 == 0 &&
V_29 -> V_229 == 0 ) ;
V_29 -> V_21 |= V_230 ;
F_18 ( V_29 ) ;
if ( V_226 )
V_45 = F_75 ( & V_2 -> V_11 , V_131 ) ;
if ( V_45 < 0 )
F_80 ( V_137 , V_28 , V_9 ,
L_24 ,
V_9 , V_45 ) ;
}
V_2 -> V_19 = V_20 ;
V_2 -> V_90 &= ~ V_91 ;
F_8 ( V_28 , V_2 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_123 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_49 ) ;
if ( V_2 -> V_54 ) {
F_19 ( ! V_2 -> V_26 ) ;
F_19 ( ! V_2 -> V_13 ) ;
return;
}
F_26 ( F_5 ( V_2 ) ) ;
F_26 ( ! F_121 ( V_2 ) ) ;
F_22 ( V_2 ) ;
F_8 ( V_28 , V_2 ) ;
}
static void F_124 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 ,
enum V_231 V_232 )
{
struct V_1 * V_9 = F_25 ( V_49 ) ;
F_26 ( F_5 ( V_9 ) ) ;
if ( V_232 == V_233 && V_49 -> V_79 -> V_80 != V_233 ) {
struct V_166 * V_167 = F_95 ( V_28 ) ;
F_19 ( V_9 -> V_217 == NULL ) ;
V_9 -> V_217 = V_167 ;
} else if ( V_232 != V_233 )
V_9 -> V_217 = NULL ;
}
static int F_125 ( const struct V_27 * V_28 , void * V_18 ,
T_4 V_234 , const struct V_48 * V_49 )
{
struct V_1 * V_9 = F_25 ( V_49 ) ;
(* V_234)( V_28 , V_18 , L_25 V_235 L_26 ,
V_9 -> V_13 , V_9 -> V_90 , V_9 -> V_11 . V_18 ,
V_9 -> V_19 , V_9 -> V_217 ) ;
F_126 ( V_28 , V_18 , V_234 , & V_9 -> V_92 ) ;
return 0 ;
}
static int F_127 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 ,
const struct V_61 * V_236 ,
const struct V_168 * V_169 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
if ( V_236 -> V_237 & V_238 )
return 0 ;
if ( V_10 -> V_19 >= V_20 )
return 0 ;
if ( V_236 -> V_110 == V_157 ) {
if ( V_10 -> V_51 )
return ! ( V_10 -> V_19 > V_55 ) ;
if ( V_10 -> V_19 < V_23 ||
V_10 -> V_19 > V_55 )
return 0 ;
} else if ( V_236 -> V_237 & V_219 ) {
if ( V_10 -> V_19 < V_52 &&
V_10 -> V_15 )
return 0 ;
}
return 1 ;
}
static int F_128 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
struct V_59 * V_9 = V_49 -> V_79 ;
F_19 ( V_10 -> V_19 == V_23 ) ;
F_26 ( F_5 ( V_10 ) ) ;
F_72 ( V_28 , V_9 ) ;
F_62 ( V_28 , V_9 ) ;
return 0 ;
}
static void F_129 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_10 = F_25 ( V_49 ) ;
int V_45 ;
V_45 = F_118 ( V_10 , 0 ) ;
if ( V_45 )
F_27 ( L_27 ,
V_10 , V_45 ) ;
V_10 -> V_19 = V_20 ;
}
static int F_130 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
struct V_59 * V_9 = V_2 -> V_3 . V_79 ;
F_26 ( F_5 ( V_2 ) ) ;
F_19 ( V_2 -> V_19 >= V_52 ) ;
return V_9 -> V_218 ;
}
static void F_131 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 ,
enum V_231 V_232 )
{
struct V_1 * V_9 = F_25 ( V_49 ) ;
F_26 ( F_5 ( V_9 ) ) ;
if ( V_232 == V_233 ) {
struct V_166 * V_167 = F_95 ( V_28 ) ;
F_19 ( F_7 ( V_9 -> V_217 , V_9 -> V_217 == V_167 ) ) ;
V_9 -> V_217 = V_167 ;
if ( F_132 ( V_167 -> V_170 . V_239 , V_49 -> V_34 ) )
V_167 -> V_240 = 1 ;
}
}
static int F_133 ( const struct V_27 * V_28 ,
const struct V_48 * V_49 ,
const struct V_61 * V_236 ,
const struct V_168 * V_169 )
{
struct V_1 * V_9 = F_25 ( V_49 ) ;
if ( ! ( V_236 -> V_237 & V_238 ) )
return 0 ;
return ( V_9 -> V_217 == F_95 ( V_28 ) ) ;
}
int F_134 ( const struct V_27 * V_28 ,
struct V_32 * V_33 , struct V_59 * V_9 ,
const struct V_168 * V_206 )
{
struct V_1 * V_241 ;
int V_45 ;
F_135 ( V_241 , V_58 , V_242 ) ;
if ( V_241 != NULL ) {
T_3 V_70 = V_9 -> V_63 . V_237 ;
F_93 ( V_28 , V_9 , V_241 , & V_241 -> V_46 ) ;
F_136 ( & V_241 -> V_56 , 0 ) ;
V_241 -> V_19 = V_50 ;
V_241 -> V_90 = F_34 ( V_70 ) ;
V_241 -> V_51 = ! ! ( V_70 & V_243 ) ;
if ( V_241 -> V_51 )
V_241 -> V_90 |= V_73 ;
if ( V_241 -> V_90 & V_75 )
V_241 -> V_54 = 1 ;
F_137 ( V_9 , & V_241 -> V_3 , V_33 , & V_118 ) ;
if ( ! ( V_70 & V_219 ) )
F_61 ( V_28 , V_241 , ( V_70 & V_238 ) ) ;
if ( V_241 -> V_15 && ! ( V_70 & V_76 ) )
V_241 -> V_90 |= V_244 ;
F_138 ( L_28 ,
V_9 , V_241 , V_241 -> V_90 ) ;
V_45 = 0 ;
} else
V_45 = - V_245 ;
return V_45 ;
}
int F_139 ( struct V_6 * V_246 )
{
struct V_1 * V_12 ;
int V_84 = 0 ;
F_9 ( & V_30 ) ;
V_12 = V_246 -> V_31 ;
if ( V_12 != NULL &&
F_140 ( V_57 ,
& V_12 -> V_56 ) != V_57 ) {
F_141 ( V_57 , & V_12 -> V_56 ) ;
V_84 = 1 ;
}
F_10 ( & V_30 ) ;
return V_84 ;
}
