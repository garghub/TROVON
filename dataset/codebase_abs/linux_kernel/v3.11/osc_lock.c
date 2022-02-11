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
return
F_7 ( F_1 ( V_10 ) ,
V_10 -> V_15 && V_10 -> V_13 == NULL ) ||
( F_7 ( V_12 != NULL , V_14 ) &&
F_7 ( V_12 != NULL ,
V_12 -> V_16 . V_17 == V_10 -> V_11 . V_18 ) &&
F_7 ( V_14 ,
F_7 ( V_9 != NULL && V_12 != NULL , V_9 == V_12 ) &&
F_7 ( V_9 == NULL , V_12 == NULL ) ) &&
F_7 ( V_10 -> V_19 == V_20 ,
V_12 == NULL && ! V_14 ) &&
F_7 ( V_12 != NULL && V_10 -> V_19 < V_20 ,
! V_12 -> V_21 ) &&
F_7 ( V_10 -> V_19 == V_22 ,
V_12 != NULL &&
V_12 -> V_23 == V_12 -> V_24 &&
V_10 -> V_25 ) ) ;
}
static void F_8 ( const struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_6 * V_28 ;
F_9 ( & V_29 ) ;
V_28 = V_2 -> V_13 ;
if ( V_28 == NULL ) {
F_10 ( & V_29 ) ;
return;
}
V_2 -> V_13 = NULL ;
V_28 -> V_30 = NULL ;
V_2 -> V_11 . V_18 = 0ULL ;
F_10 ( & V_29 ) ;
F_11 ( V_28 ) ;
if ( V_28 -> V_24 == V_28 -> V_23 ) {
struct V_31 * V_32 = V_2 -> V_3 . V_33 ;
struct V_34 * V_35 = & F_12 ( V_27 ) -> V_36 ;
T_1 V_37 ;
F_13 ( V_32 ) ;
V_37 = F_14 ( V_32 ) -> V_38 -> V_39 ;
V_35 -> V_40 = F_15 ( V_28 , V_37 ) ;
F_16 ( V_27 , V_32 , V_35 , V_41 ) ;
F_17 ( V_32 ) ;
}
F_18 ( V_28 ) ;
F_19 ( V_2 -> V_42 ) ;
F_20 ( & V_28 -> V_43 , L_1 , V_2 ) ;
F_21 ( V_28 ) ;
V_2 -> V_42 = 0 ;
}
static int F_22 ( struct V_1 * V_10 )
{
int V_44 = 0 ;
if ( V_10 -> V_25 ) {
V_10 -> V_25 = 0 ;
V_44 = F_23 ( & V_10 -> V_11 ,
V_10 -> V_45 . V_46 ) ;
}
return V_44 ;
}
static int F_24 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
F_26 ( F_5 ( V_10 ) ) ;
switch ( V_10 -> V_19 ) {
case V_49 :
F_19 ( ! V_10 -> V_25 ) ;
F_19 ( V_10 -> V_50 ) ;
return 0 ;
case V_51 :
F_22 ( V_10 ) ;
case V_52 :
F_19 ( ! V_10 -> V_25 ) ;
F_8 ( V_27 , V_10 ) ;
V_10 -> V_19 = V_49 ;
return 0 ;
case V_22 :
F_19 ( ! V_10 -> V_53 ) ;
F_19 ( V_10 -> V_25 ) ;
V_10 -> V_19 = V_54 ;
return F_22 ( V_10 ) ;
default:
F_27 ( L_2 , V_10 -> V_19 ) ;
F_28 () ;
}
}
static void F_29 ( const struct V_26 * V_27 ,
struct V_47 * V_48 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
F_26 ( F_5 ( V_10 ) ) ;
F_22 ( V_10 ) ;
F_19 ( V_10 -> V_13 == NULL ) ;
F_19 ( F_30 ( & V_10 -> V_55 ) == 0 ||
F_30 ( & V_10 -> V_55 ) == V_56 ) ;
F_31 ( V_10 , V_57 ) ;
}
static void F_32 ( const struct V_26 * V_27 ,
const struct V_58 * V_9 ,
T_2 * V_59 )
{
const struct V_60 * V_61 = & V_9 -> V_62 ;
F_33 ( V_59 , V_61 -> V_63 , V_61 -> V_64 , V_61 -> V_65 ) ;
V_59 -> V_66 . V_67 = V_61 -> V_68 ;
}
static T_1 F_34 ( T_3 V_69 )
{
T_1 V_44 = 0 ;
F_19 ( ( V_69 & ~ V_70 ) == 0 ) ;
if ( V_69 & V_71 )
V_44 |= V_72 ;
if ( V_69 & V_73 )
V_44 |= V_74 ;
if ( V_69 & V_75 )
V_44 |= V_76 ;
return V_44 ;
}
static struct V_1 * F_35 ( struct V_6 * V_77 )
{
struct V_1 * V_2 ;
F_11 ( V_77 ) ;
F_9 ( & V_29 ) ;
V_2 = V_77 -> V_30 ;
if ( V_2 != NULL ) {
struct V_58 * V_9 = V_2 -> V_3 . V_78 ;
if ( V_9 -> V_79 < V_80 || V_2 -> V_42 ) {
F_36 ( V_9 ) ;
F_37 ( & V_9 -> V_81 ,
L_3 , V_82 ) ;
} else
V_2 = NULL ;
}
F_10 ( & V_29 ) ;
F_18 ( V_77 ) ;
return V_2 ;
}
static void F_38 ( const struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_58 * V_9 ;
V_9 = V_2 -> V_3 . V_78 ;
F_20 ( & V_9 -> V_81 , L_3 , V_82 ) ;
F_39 ( V_27 , V_9 ) ;
}
static void F_40 ( const struct V_26 * V_27 , struct V_1 * V_2 ,
int V_83 )
{
struct V_84 * V_85 ;
struct V_31 * V_32 ;
struct V_86 * V_87 ;
struct V_34 * V_35 ;
unsigned V_88 ;
V_89 ;
if ( ! ( V_2 -> V_90 & V_91 ) )
V_92 ;
V_85 = & V_2 -> V_93 ;
V_32 = V_2 -> V_3 . V_33 ;
V_87 = F_14 ( V_32 ) -> V_38 ;
V_35 = & F_12 ( V_27 ) -> V_36 ;
V_88 = V_94 | V_95 | V_96 | V_97 | V_98 ;
F_41 ( V_35 , V_85 ) ;
F_13 ( V_32 ) ;
if ( V_83 == 0 ) {
struct V_6 * V_28 ;
T_1 V_99 ;
V_28 = V_2 -> V_13 ;
F_19 ( V_28 != NULL ) ;
* V_85 = * (struct V_84 * ) V_28 -> V_100 ;
V_99 = V_85 -> V_101 ;
if ( V_99 > V_28 -> V_102 . V_66 . V_103 )
V_99 = V_28 -> V_102 . V_66 . V_103 + 1 ;
if ( V_99 >= V_87 -> V_39 ) {
F_42 ( V_28 , L_4 V_104
L_5 V_104 , V_85 -> V_101 , V_99 ) ;
V_88 |= V_41 ;
V_35 -> V_40 = V_99 ;
} else {
F_42 ( V_28 , L_4
V_104 L_6 V_104 L_7 V_104 ,
V_85 -> V_101 , V_87 -> V_39 ,
V_28 -> V_102 . V_66 . V_103 ) ;
}
F_43 ( V_28 ) ;
} else if ( V_83 == - V_105 && V_2 -> V_53 ) {
F_44 ( V_106 , L_8 V_104 L_9
L_10 V_104 L_11 , V_85 -> V_101 , V_87 -> V_39 ) ;
} else
V_88 = 0 ;
if ( V_88 != 0 )
F_16 ( V_27 , V_32 , V_35 , V_88 ) ;
F_17 ( V_32 ) ;
EXIT ;
}
static void F_45 ( const struct V_26 * V_27 , struct V_1 * V_2 ,
struct V_6 * V_28 , int V_83 )
{
struct V_107 * V_108 ;
struct V_58 * V_9 ;
struct V_60 * V_109 ;
F_19 ( V_28 -> V_24 == V_28 -> V_23 ) ;
V_89 ;
if ( V_2 -> V_19 < V_22 ) {
V_9 = V_2 -> V_3 . V_78 ;
V_108 = & V_28 -> V_102 . V_66 ;
V_109 = & F_12 ( V_27 ) -> V_110 ;
V_109 -> V_63 = V_9 -> V_62 . V_63 ;
V_109 -> V_111 = F_46 ( V_28 -> V_24 ) ;
V_109 -> V_64 = F_47 ( V_109 -> V_63 , V_108 -> V_112 ) ;
V_109 -> V_65 = F_47 ( V_109 -> V_63 , V_108 -> V_103 ) ;
V_109 -> V_68 = V_108 -> V_67 ;
V_2 -> V_19 = V_22 ;
F_40 ( V_27 , V_2 , V_83 ) ;
F_18 ( V_28 ) ;
F_48 ( V_27 , V_9 , V_109 ) ;
F_49 ( V_27 , V_9 ) ;
F_26 ( F_5 ( V_2 ) ) ;
F_11 ( V_28 ) ;
}
EXIT ;
}
static void F_50 ( const struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_6 * V_28 ;
V_89 ;
V_28 = F_51 ( & V_2 -> V_11 , 0 ) ;
F_19 ( V_28 != NULL ) ;
F_11 ( V_28 ) ;
F_9 ( & V_29 ) ;
F_19 ( V_28 -> V_30 == V_2 ) ;
F_19 ( V_2 -> V_13 == NULL ) ;
V_2 -> V_13 = V_28 ;
F_10 ( & V_29 ) ;
if ( V_28 -> V_24 == V_28 -> V_23 )
F_45 ( V_27 , V_2 , V_28 , 0 ) ;
F_18 ( V_28 ) ;
F_52 ( & V_2 -> V_11 , V_2 -> V_45 . V_46 ) ;
V_2 -> V_25 = 1 ;
F_53 ( & V_28 -> V_43 , L_1 , V_2 ) ;
V_2 -> V_42 = 1 ;
}
static int F_54 ( void * V_18 , int V_113 )
{
struct V_1 * V_2 = V_18 ;
struct V_47 * V_48 = & V_2 -> V_3 ;
struct V_58 * V_9 = V_48 -> V_78 ;
struct V_26 * V_27 ;
struct V_114 V_115 ;
V_89 ;
V_27 = F_55 ( & V_115 ) ;
if ( ! F_56 ( V_27 ) ) {
int V_83 ;
F_57 ( V_27 , V_9 ) ;
F_19 ( V_9 -> V_79 >= V_116 ) ;
if ( V_2 -> V_19 == V_52 ) {
V_2 -> V_19 = V_51 ;
V_83 = F_58 ( V_113 ) ;
} else if ( V_2 -> V_19 == V_20 ) {
V_83 = - V_117 ;
} else {
F_27 ( L_2 , V_2 -> V_19 ) ;
F_28 () ;
}
if ( V_83 ) {
struct V_6 * V_28 ;
V_28 = F_3 ( & V_2 -> V_11 ) ;
if ( V_28 != NULL ) {
F_11 ( V_28 ) ;
F_9 ( & V_29 ) ;
F_19 ( V_2 -> V_13 == NULL ) ;
V_28 -> V_30 = NULL ;
V_2 -> V_11 . V_18 = 0ULL ;
F_10 ( & V_29 ) ;
F_59 ( V_28 ) ;
F_18 ( V_28 ) ;
F_4 ( V_28 ) ;
}
} else {
if ( V_2 -> V_53 )
V_2 -> V_53 = 0 ;
F_50 ( V_27 , V_2 ) ;
}
if ( V_2 -> V_15 && V_83 == - V_118 ) {
F_60 ( F_14 ( V_48 -> V_33 ) ) ;
F_19 ( V_48 -> V_4 == & V_119 ) ;
F_61 ( V_27 , V_2 , 1 ) ;
V_2 -> V_19 = V_22 ;
V_83 = 0 ;
} else if ( V_2 -> V_53 && V_83 == - V_105 ) {
F_40 ( V_27 , V_2 , V_83 ) ;
F_62 ( V_27 , V_9 ) ;
V_83 = 0 ;
}
if ( V_83 == 0 ) {
if ( V_2 -> V_50 ) {
V_9 -> V_120 |= V_121 ;
F_63 ( V_27 , V_9 ) ;
V_9 -> V_120 &= ~ V_121 ;
if ( ! V_2 -> V_53 )
V_2 -> V_50 = 0 ;
}
F_49 ( V_27 , V_9 ) ;
F_64 ( V_27 , V_9 ) ;
} else {
F_65 ( V_27 , V_9 ) ;
F_66 ( V_27 , V_9 , V_83 ) ;
}
F_67 ( V_27 , V_9 , L_12 , V_9 ) ;
F_68 ( V_27 , V_9 ) ;
F_20 ( & V_9 -> V_81 , L_12 , V_9 ) ;
F_39 ( V_27 , V_9 ) ;
F_69 ( & V_115 , V_27 ) ;
} else {
F_28 () ;
}
RETURN ( V_113 ) ;
}
static void F_70 ( const struct V_26 * V_27 ,
struct V_6 * V_28 ,
struct V_1 * V_2 , int V_122 )
{
struct V_58 * V_9 = V_2 -> V_3 . V_78 ;
F_19 ( V_2 -> V_13 == V_28 ) ;
F_71 ( V_123 < V_20 ) ;
F_19 ( ! F_1 ( V_2 ) ) ;
F_22 ( V_2 ) ;
if ( V_122 && V_2 -> V_19 < V_123 )
V_2 -> V_19 = V_123 ;
F_72 ( V_27 , V_9 ) ;
F_62 ( V_27 , V_9 ) ;
}
static int F_73 ( const struct V_26 * V_27 ,
struct V_6 * V_28 ,
void * V_124 , int V_125 )
{
struct V_1 * V_2 ;
struct V_58 * V_9 ;
int V_44 ;
int V_126 ;
F_19 ( V_125 == V_127 || V_125 == V_128 ) ;
V_126 = 0 ;
V_2 = F_35 ( V_28 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_78 ;
F_57 ( V_27 , V_9 ) ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_2 -> V_129 ) {
F_49 ( V_27 , V_9 ) ;
V_2 -> V_129 = 0 ;
}
if ( V_2 == V_28 -> V_30 ) {
F_19 ( V_124 == V_2 ) ;
F_70 ( V_27 , V_28 ,
V_2 , V_125 == V_127 ) ;
} else
V_126 = 1 ;
F_68 ( V_27 , V_9 ) ;
F_38 ( V_27 , V_2 ) ;
} else
V_126 = ( V_125 == V_127 ) ;
if ( V_126 ) {
struct V_7 * V_130 ;
V_130 = & F_12 ( V_27 ) -> V_131 ;
F_74 ( V_28 , V_130 ) ;
V_44 = F_75 ( V_130 , V_132 ) ;
} else
V_44 = 0 ;
return V_44 ;
}
static int F_76 ( struct V_6 * V_28 ,
struct V_133 * V_134 , void * V_124 ,
int V_125 )
{
struct V_26 * V_27 ;
struct V_114 V_115 ;
int V_44 ;
V_27 = F_55 ( & V_115 ) ;
if ( ! F_56 ( V_27 ) ) {
V_44 = F_73 ( V_27 , V_28 , V_124 , V_125 ) ;
F_69 ( & V_115 , V_27 ) ;
} else {
V_44 = F_77 ( V_27 ) ;
F_28 () ;
}
if ( V_44 != 0 ) {
if ( V_44 == - V_135 )
V_44 = 0 ;
else
F_27 ( L_13 , V_44 ) ;
}
return V_44 ;
}
static int F_78 ( struct V_6 * V_28 ,
T_1 V_136 , void * V_124 )
{
struct V_114 V_115 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_58 * V_9 ;
int V_44 ;
int V_137 ;
V_137 = F_79 ( V_28 , V_136 , V_124 ) ;
V_27 = F_55 ( & V_115 ) ;
if ( ! F_56 ( V_27 ) ) {
V_2 = F_35 ( V_28 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_78 ;
F_57 ( V_27 , V_9 ) ;
F_19 ( V_28 -> V_100 != NULL ) ;
F_11 ( V_28 ) ;
V_2 -> V_93 = * (struct V_84 * ) V_28 -> V_100 ;
if ( V_2 -> V_13 == NULL ) {
} else if ( V_28 -> V_24 ==
V_28 -> V_23 ) {
F_45 ( V_27 , V_2 , V_28 , V_137 ) ;
}
F_18 ( V_28 ) ;
if ( V_137 != 0 ) {
F_80 ( V_138 , V_27 , V_9 ,
L_14 , V_137 ) ;
F_66 ( V_27 , V_9 , V_137 ) ;
}
F_68 ( V_27 , V_9 ) ;
F_38 ( V_27 , V_2 ) ;
V_44 = 0 ;
} else
V_44 = - V_139 ;
F_69 ( & V_115 , V_27 ) ;
} else
V_44 = F_77 ( V_27 ) ;
return V_137 ? : V_44 ;
}
static int F_81 ( struct V_6 * V_28 , void * V_124 )
{
struct V_140 * V_141 = V_124 ;
struct V_1 * V_2 ;
struct V_58 * V_9 ;
struct V_31 * V_32 ;
struct V_114 V_115 ;
struct V_26 * V_27 ;
struct V_84 * V_85 ;
struct V_142 * V_143 ;
int V_44 ;
F_19 ( F_82 ( V_141 -> V_144 ) == V_145 ) ;
V_27 = F_55 ( & V_115 ) ;
if ( ! F_56 ( V_27 ) ) {
V_2 = F_35 ( V_28 ) ;
if ( V_2 != NULL ) {
V_9 = V_2 -> V_3 . V_78 ;
V_143 = & V_141 -> V_146 ;
F_83 ( V_143 , & V_147 ) ;
F_84 ( V_143 , & V_148 , V_149 ,
sizeof *V_85 ) ;
V_44 = F_85 ( V_143 ) ;
if ( V_44 == 0 ) {
V_85 = F_86 ( V_143 , & V_148 ) ;
V_32 = V_9 -> V_62 . V_63 ;
V_44 = F_87 ( V_27 , V_32 , V_85 ) ;
}
if ( ! F_88 ( V_141 -> V_150 ) )
F_89 ( & V_141 -> V_146 ,
& V_148 ,
sizeof( struct V_151 ) ,
V_149 ) ;
F_38 ( V_27 , V_2 ) ;
} else {
F_90 ( V_141 , 1 , NULL , NULL ) ;
V_44 = - V_139 ;
}
F_69 ( & V_115 , V_27 ) ;
} else
V_44 = F_77 ( V_27 ) ;
V_141 -> V_152 = V_44 ;
return V_44 ;
}
static unsigned long F_91 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
return F_92 ( V_48 -> V_33 ) -> V_153 ;
}
static unsigned long F_93 ( struct V_6 * V_28 )
{
struct V_114 V_115 ;
struct V_26 * V_27 ;
struct V_1 * V_9 ;
struct V_58 * V_154 ;
unsigned long V_155 ;
V_89 ;
F_94 () ;
V_27 = F_55 ( & V_115 ) ;
if ( F_56 ( V_27 ) )
RETURN ( 0 ) ;
F_19 ( V_28 -> V_156 -> V_157 == V_158 ) ;
V_9 = F_35 ( V_28 ) ;
if ( V_9 == NULL ) {
GOTO ( V_159 , V_155 = 0 ) ;
}
V_154 = V_9 -> V_3 . V_78 ;
F_57 ( V_27 , V_154 ) ;
V_155 = F_95 ( V_27 , V_154 ) ;
F_68 ( V_27 , V_154 ) ;
F_38 ( V_27 , V_9 ) ;
EXIT ;
V_159:
F_69 ( & V_115 , V_27 ) ;
return V_155 ;
}
static void F_96 ( const struct V_26 * V_27 ,
const struct V_58 * clock ,
struct V_1 * V_9 ,
struct V_160 * V_161 )
{
enum V_162 V_163 ;
V_163 = clock -> V_62 . V_111 ;
if ( V_163 == V_164 )
V_163 = V_165 ;
V_161 -> V_166 = V_158 ;
V_161 -> V_46 = F_97 ( V_163 ) ;
V_161 -> V_167 = F_76 ;
V_161 -> V_168 = F_78 ;
V_161 -> V_169 = F_81 ;
V_161 -> V_170 = F_93 ;
V_161 -> V_171 = V_9 ;
}
static void F_61 ( const struct V_26 * V_27 ,
struct V_1 * V_10 , int V_172 )
{
struct V_47 * V_48 = & V_10 -> V_3 ;
F_19 ( V_10 -> V_19 == V_49 ||
V_10 -> V_19 == V_51 ) ;
if ( V_172 ) {
V_10 -> V_15 = 1 ;
V_48 -> V_4 = & V_5 ;
} else {
struct V_173 * V_174 = F_98 ( V_27 ) ;
struct V_175 * V_176 = V_174 -> V_177 . V_178 ;
struct V_31 * V_32 = V_48 -> V_33 ;
struct V_179 * V_180 = F_14 ( V_32 ) ;
const struct V_181 * V_182 = F_99 ( V_32 -> V_183 . V_184 ) ;
struct V_185 * V_186 ;
F_19 ( V_176 -> V_187 == V_188 ||
V_176 -> V_187 == V_189 ||
V_176 -> V_187 == V_190 ) ;
V_186 = & F_100 ( F_101 ( V_180 ) ) -> V_191 ;
V_10 -> V_15 = ( V_176 -> V_192 != V_193 ) &&
( V_176 -> V_187 == V_189 ) &&
( V_186 -> V_194 & V_195 ) ;
if ( V_176 -> V_187 == V_190 ||
( V_10 -> V_15 && F_102 ( V_180 ) ) ||
( F_103 ( V_176 ) &&
( V_186 -> V_194 & V_196 ) &&
V_182 -> V_197 ) ) {
V_10 -> V_15 = 1 ;
V_48 -> V_4 = & V_5 ;
}
}
F_19 ( F_7 ( V_10 -> V_53 , ! F_1 ( V_10 ) ) ) ;
}
static int F_104 ( const struct V_1 * V_198 ,
const struct V_1 * V_199 )
{
enum V_162 V_200 ;
enum V_162 V_201 ;
V_200 = V_198 -> V_3 . V_78 -> V_62 . V_111 ;
if ( V_199 -> V_53 &&
( V_199 -> V_19 >= V_51 || V_200 == V_165 ) )
return 1 ;
V_201 = V_199 -> V_3 . V_78 -> V_62 . V_111 ;
return ( ( V_200 == V_165 ) && ( V_201 == V_165 ) ) ;
}
static int F_105 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 )
{
struct V_58 * V_9 = V_2 -> V_3 . V_78 ;
struct V_60 * V_109 = & V_9 -> V_62 ;
struct F_92 * V_202 = F_92 ( V_109 -> V_63 ) ;
struct V_58 * V_203 ;
struct V_58 * V_204 = NULL ;
int V_205 = F_1 ( V_2 ) ;
int V_83 = 0 ;
V_89 ;
F_19 ( F_106 ( V_9 ) ) ;
if ( V_2 -> V_53 )
return 0 ;
F_9 ( & V_202 -> V_206 ) ;
F_107 (scan, &hdr->coh_locks, cll_linkage) {
struct V_60 * V_207 = & V_203 -> V_62 ;
const struct V_1 * V_208 ;
if ( V_203 == V_9 )
break;
if ( V_203 -> V_79 < V_116 ||
V_203 -> V_79 == V_80 ||
V_207 -> V_64 > V_109 -> V_65 ||
V_207 -> V_65 < V_109 -> V_64 )
continue;
if ( V_203 -> V_62 . V_111 == V_209 ) {
F_19 ( V_109 -> V_111 != V_209 ||
V_109 -> V_68 != V_203 -> V_62 . V_68 ) ;
continue;
}
V_208 = F_108 ( V_203 ) ;
if ( ! V_205 && F_104 ( V_2 , V_208 ) )
continue;
F_36 ( V_203 ) ;
V_204 = V_203 ;
break;
}
F_10 ( & V_202 -> V_206 ) ;
if ( V_204 ) {
if ( V_9 -> V_62 . V_111 == V_209 ) {
F_44 ( V_210 , L_15
L_16 ,
V_9 , V_204 ) ;
F_39 ( V_27 , V_204 ) ;
V_83 = 0 ;
} else {
F_44 ( V_210 , L_17
L_18 ,
V_9 , V_204 ) ;
F_19 ( V_9 -> V_211 == NULL ) ;
F_53 ( & V_204 -> V_81 , L_19 ,
V_9 ) ;
V_9 -> V_211 = V_204 ;
V_83 = V_212 ;
}
}
RETURN ( V_83 ) ;
}
static int F_109 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 ,
struct V_175 * V_213 , T_3 V_69 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
struct V_58 * V_9 = V_10 -> V_3 . V_78 ;
int V_44 ;
V_89 ;
F_19 ( F_106 ( V_9 ) ) ;
F_110 ( V_10 -> V_19 == V_49 ,
L_2 , V_10 -> V_19 ) ;
F_110 ( F_7 ( V_10 -> V_53 , V_9 -> V_62 . V_111 <= V_165 ) ,
L_20 , V_9 , V_10 ) ;
V_44 = F_105 ( V_27 , V_10 ) ;
if ( V_44 == 0 ) {
if ( ! F_1 ( V_10 ) ) {
struct V_179 * V_32 = F_14 ( V_48 -> V_33 ) ;
struct V_214 * V_215 = F_12 ( V_27 ) ;
struct V_216 * V_217 = & V_215 -> V_218 ;
T_2 * V_59 = & V_215 -> V_219 ;
struct V_160 * V_161 = & V_10 -> V_45 ;
F_111 ( V_27 , V_9 , L_12 , V_9 ) ;
F_112 ( V_27 , V_9 ) ;
V_10 -> V_19 = V_52 ;
F_113 ( & V_32 -> V_38 -> V_220 , V_217 ) ;
F_32 ( V_27 , V_9 , V_59 ) ;
V_44 = F_114 ( F_101 ( V_32 ) , V_217 ,
& V_10 -> V_90 , V_59 ,
& V_10 -> V_93 ,
V_32 -> V_38 -> V_221 ,
F_54 ,
V_10 , V_161 , & V_10 -> V_11 ,
V_222 , 1 , V_10 -> V_50 ) ;
if ( V_44 != 0 ) {
F_65 ( V_27 , V_9 ) ;
F_115 ( V_27 , V_9 , L_12 , V_9 ) ;
if ( F_116 ( V_44 == - V_223 ) ) {
V_10 -> V_19 = V_49 ;
V_44 = 0 ;
}
}
} else {
V_10 -> V_19 = V_22 ;
V_10 -> V_224 = F_98 ( V_27 ) ;
}
}
F_19 ( F_7 ( V_10 -> V_53 , ! F_1 ( V_10 ) ) ) ;
RETURN ( V_44 ) ;
}
static int F_117 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
struct V_58 * V_9 = V_2 -> V_3 . V_78 ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_2 -> V_53 && V_2 -> V_19 >= V_51 ) {
if ( V_2 -> V_90 & V_91 ) {
return 0 ;
} else if ( V_2 -> V_50 ) {
if ( V_9 -> V_120 & V_121 )
return - V_105 ;
else
V_2 -> V_19 = V_49 ;
} else {
F_19 ( V_9 -> V_225 ) ;
return V_9 -> V_225 ;
}
}
if ( V_2 -> V_19 == V_49 ) {
int V_83 ;
F_19 ( V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
V_83 = F_109 ( V_27 , V_48 , NULL , V_73 | V_226 ) ;
if ( V_83 != 0 )
return V_83 ;
else
return V_227 ;
}
F_19 ( F_118 ( V_2 -> V_19 >= V_51 &&
V_9 -> V_225 == 0 , V_2 -> V_13 != NULL ) ) ;
return V_9 -> V_225 ? : V_2 -> V_19 >= V_22 ? 0 : V_212 ;
}
static int F_119 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
int V_83 ;
F_19 ( ! V_2 -> V_25 ) ;
V_83 = F_120 ( & V_2 -> V_11 , V_2 -> V_45 . V_46 ) ;
if ( V_83 == 0 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_19 = V_22 ;
} else {
struct V_58 * V_9 ;
V_9 = V_48 -> V_78 ;
F_19 ( V_9 -> V_79 == V_228 ) ;
F_19 ( V_9 -> V_229 > 0 ) ;
V_2 -> V_129 = 1 ;
V_83 = V_212 ;
}
return V_83 ;
}
static int F_121 ( struct V_1 * V_10 , int V_230 )
{
struct V_58 * V_9 = V_10 -> V_3 . V_78 ;
struct V_114 V_115 ;
struct V_26 * V_27 ;
int V_44 = 0 ;
V_89 ;
V_27 = F_55 ( & V_115 ) ;
if ( ! F_56 ( V_27 ) ) {
struct V_179 * V_32 = F_14 ( V_10 -> V_3 . V_33 ) ;
struct V_60 * V_109 = & V_9 -> V_62 ;
int V_83 = 0 ;
if ( V_109 -> V_111 >= V_231 ) {
V_44 = F_122 ( V_27 , V_32 ,
V_109 -> V_64 , V_109 -> V_65 ,
1 , V_230 ) ;
F_42 ( V_10 -> V_13 ,
L_21 , V_9 , V_44 ,
V_230 ? L_22 : L_23 ) ;
if ( V_44 > 0 )
V_44 = 0 ;
}
V_83 = F_123 ( V_27 , V_9 ) ;
if ( V_44 == 0 && V_83 < 0 )
V_44 = V_83 ;
F_69 ( & V_115 , V_27 ) ;
} else
V_44 = F_77 ( V_27 ) ;
if ( V_44 == 0 ) {
V_10 -> V_232 = 1 ;
F_26 ( ! F_124 ( V_10 ) ) ;
}
RETURN ( V_44 ) ;
}
static void F_125 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_58 * V_9 = V_48 -> V_78 ;
struct V_1 * V_2 = F_25 ( V_48 ) ;
struct V_6 * V_28 = V_2 -> V_13 ;
int V_44 = 0 ;
int V_230 ;
F_19 ( F_106 ( V_9 ) ) ;
F_26 ( F_5 ( V_2 ) ) ;
if ( V_28 != NULL ) {
int V_233 ;
V_230 = ! ! ( V_28 -> V_234 & V_235 ) ;
if ( V_2 -> V_19 >= V_22 )
V_44 = F_121 ( V_2 , V_230 ) ;
F_22 ( V_2 ) ;
F_11 ( V_28 ) ;
V_233 = ( V_28 -> V_236 == 0 &&
V_28 -> V_237 == 0 ) ;
V_28 -> V_234 |= V_238 ;
F_18 ( V_28 ) ;
if ( V_233 )
V_44 = F_75 ( & V_2 -> V_11 , V_132 ) ;
if ( V_44 < 0 )
F_80 ( V_138 , V_27 , V_9 ,
L_24 ,
V_9 , V_44 ) ;
}
V_2 -> V_19 = V_20 ;
V_2 -> V_90 &= ~ V_91 ;
F_8 ( V_27 , V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_126 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_48 ) ;
if ( V_2 -> V_53 ) {
F_19 ( ! V_2 -> V_25 ) ;
F_19 ( ! V_2 -> V_13 ) ;
return;
}
F_26 ( F_5 ( V_2 ) ) ;
F_26 ( ! F_124 ( V_2 ) ) ;
F_22 ( V_2 ) ;
F_8 ( V_27 , V_2 ) ;
}
static void F_127 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 ,
enum V_239 V_240 )
{
struct V_1 * V_9 = F_25 ( V_48 ) ;
F_26 ( F_5 ( V_9 ) ) ;
if ( V_240 == V_241 && V_48 -> V_78 -> V_79 != V_241 ) {
struct V_173 * V_174 = F_98 ( V_27 ) ;
F_19 ( V_9 -> V_224 == NULL ) ;
V_9 -> V_224 = V_174 ;
} else if ( V_240 != V_241 )
V_9 -> V_224 = NULL ;
}
static int F_128 ( const struct V_26 * V_27 , void * V_18 ,
T_4 V_242 , const struct V_47 * V_48 )
{
struct V_1 * V_9 = F_25 ( V_48 ) ;
(* V_242)( V_27 , V_18 , L_25 V_243 L_26 ,
V_9 -> V_13 , V_9 -> V_90 , V_9 -> V_11 . V_18 ,
V_9 -> V_19 , V_9 -> V_224 ) ;
F_129 ( V_27 , V_18 , V_242 , & V_9 -> V_93 ) ;
return 0 ;
}
static int F_130 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 ,
const struct V_60 * V_244 ,
const struct V_175 * V_176 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
if ( V_244 -> V_245 & V_246 )
return 0 ;
if ( V_10 -> V_19 >= V_20 )
return 0 ;
if ( V_244 -> V_111 == V_164 ) {
if ( V_10 -> V_50 )
return ! ( V_10 -> V_19 > V_54 ) ;
if ( V_10 -> V_19 < V_22 ||
V_10 -> V_19 > V_54 )
return 0 ;
} else if ( V_244 -> V_245 & V_226 ) {
if ( V_10 -> V_19 < V_51 &&
V_10 -> V_15 )
return 0 ;
}
return 1 ;
}
static int F_131 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
struct V_58 * V_9 = V_48 -> V_78 ;
F_19 ( V_10 -> V_19 == V_22 ) ;
F_26 ( F_5 ( V_10 ) ) ;
F_72 ( V_27 , V_9 ) ;
F_62 ( V_27 , V_9 ) ;
return 0 ;
}
static void F_132 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_10 = F_25 ( V_48 ) ;
int V_44 ;
V_44 = F_121 ( V_10 , 0 ) ;
if ( V_44 )
F_27 ( L_27 ,
V_10 , V_44 ) ;
V_10 -> V_19 = V_20 ;
}
static int F_133 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
struct V_58 * V_9 = V_2 -> V_3 . V_78 ;
F_26 ( F_5 ( V_2 ) ) ;
F_19 ( V_2 -> V_19 >= V_51 ) ;
return V_9 -> V_225 ;
}
static void F_134 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 ,
enum V_239 V_240 )
{
struct V_1 * V_9 = F_25 ( V_48 ) ;
F_26 ( F_5 ( V_9 ) ) ;
if ( V_240 == V_241 ) {
struct V_173 * V_174 = F_98 ( V_27 ) ;
F_19 ( F_7 ( V_9 -> V_224 , V_9 -> V_224 == V_174 ) ) ;
V_9 -> V_224 = V_174 ;
if ( F_135 ( V_174 -> V_177 . V_247 , V_48 -> V_33 ) )
V_174 -> V_248 = 1 ;
}
}
static int F_136 ( const struct V_26 * V_27 ,
const struct V_47 * V_48 ,
const struct V_60 * V_244 ,
const struct V_175 * V_176 )
{
struct V_1 * V_9 = F_25 ( V_48 ) ;
if ( ! ( V_244 -> V_245 & V_246 ) )
return 0 ;
return ( V_9 -> V_224 == F_98 ( V_27 ) ) ;
}
int F_137 ( const struct V_26 * V_27 ,
struct V_31 * V_32 , struct V_58 * V_9 ,
const struct V_175 * V_213 )
{
struct V_1 * V_249 ;
int V_44 ;
F_138 ( V_249 , V_57 , V_250 ) ;
if ( V_249 != NULL ) {
T_3 V_69 = V_9 -> V_62 . V_245 ;
F_96 ( V_27 , V_9 , V_249 , & V_249 -> V_45 ) ;
F_139 ( & V_249 -> V_55 , 0 ) ;
V_249 -> V_19 = V_49 ;
V_249 -> V_90 = F_34 ( V_69 ) ;
V_249 -> V_50 = ! ! ( V_69 & V_251 ) ;
if ( V_249 -> V_50 )
V_249 -> V_90 |= V_72 ;
if ( V_249 -> V_90 & V_74 )
V_249 -> V_53 = 1 ;
F_140 ( V_9 , & V_249 -> V_3 , V_32 , & V_119 ) ;
if ( ! ( V_69 & V_226 ) )
F_61 ( V_27 , V_249 , ( V_69 & V_246 ) ) ;
if ( V_249 -> V_15 && ! ( V_69 & V_75 ) )
V_249 -> V_90 |= V_252 ;
F_141 ( L_28 ,
V_9 , V_249 , V_249 -> V_90 ) ;
V_44 = 0 ;
} else
V_44 = - V_253 ;
return V_44 ;
}
int F_142 ( struct V_6 * V_254 )
{
struct V_1 * V_12 ;
int V_83 = 0 ;
F_9 ( & V_29 ) ;
V_12 = V_254 -> V_30 ;
if ( V_12 != NULL &&
F_143 ( V_56 ,
& V_12 -> V_55 ) != V_56 ) {
F_144 ( V_56 , & V_12 -> V_55 ) ;
V_83 = 1 ;
}
F_10 ( & V_29 ) ;
return V_83 ;
}
