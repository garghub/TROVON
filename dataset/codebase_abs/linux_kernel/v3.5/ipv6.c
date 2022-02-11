static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
if ( F_2 ( V_2 ) -> V_5 == & V_6 ) {
F_3 ( V_2 ) ;
return;
}
F_4 () ;
F_5 ( V_2 , NULL ) ;
F_6 () ;
}
}
static inline T_1 F_7 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_9 * V_11 )
{
return F_8 ( V_10 , V_11 , V_8 -> V_12 , V_13 , V_8 -> V_14 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_17 * V_18 = V_17 ( V_8 ) ;
F_11 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 , & V_16 -> V_10 , & V_16 -> V_11 ) ;
}
static inline T_2 F_12 ( struct V_7 * V_8 )
{
return F_13 ( F_14 ( V_8 ) -> V_11 . V_20 ,
F_14 ( V_8 ) -> V_10 . V_20 ,
V_17 ( V_8 ) -> V_21 ,
V_17 ( V_8 ) -> V_22 ) ;
}
static void F_15 ( struct V_7 * V_8 , struct V_23 * V_24 ,
T_3 type , T_3 V_25 , int V_26 , T_4 V_27 )
{
const struct V_28 * V_29 = ( const struct V_28 * ) V_8 -> V_30 ;
const struct V_17 * V_18 = (struct V_17 * ) ( V_8 -> V_30 + V_26 ) ;
struct V_31 * V_32 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_33 ;
T_2 V_34 ;
struct V_35 * V_35 = F_16 ( V_8 -> V_36 ) ;
if ( V_8 -> V_12 < V_26 + sizeof( * V_18 ) ||
V_8 -> V_12 < V_26 + F_17 ( V_18 ) ) {
F_18 ( V_35 , F_19 ( V_8 -> V_36 ) ,
V_37 ) ;
return;
}
V_2 = F_20 ( V_35 , & V_38 ,
& V_29 -> V_11 , V_18 -> V_21 ,
& V_29 -> V_10 , V_18 -> V_22 , F_21 ( V_8 ) ) ;
if ( V_2 == NULL ) {
F_18 ( V_35 , F_19 ( V_8 -> V_36 ) ,
V_37 ) ;
return;
}
if ( V_2 -> V_3 == V_39 ) {
F_22 ( F_23 ( V_2 ) ) ;
return;
}
F_24 ( V_2 ) ;
if ( F_25 ( V_2 ) )
F_26 ( V_35 , V_40 ) ;
if ( V_2 -> V_3 == V_4 )
goto V_41;
V_32 = F_27 ( V_2 ) ;
V_34 = F_28 ( V_18 ) ;
if ( ( 1 << V_2 -> V_3 ) & ~ ( V_42 | V_43 ) &&
! F_29 ( V_34 , V_32 -> V_44 , V_32 -> V_45 ) ) {
F_26 ( V_35 , V_46 ) ;
goto V_41;
}
V_16 = F_10 ( V_2 ) ;
if ( type == V_47 ) {
struct V_48 * V_49 = NULL ;
if ( F_25 ( V_2 ) )
goto V_41;
if ( ( 1 << V_2 -> V_3 ) & ( V_43 | V_50 ) )
goto V_41;
V_49 = F_30 ( V_2 , V_16 -> V_51 ) ;
if ( V_49 == NULL ) {
struct V_52 * V_53 = F_31 ( V_2 ) ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_13 ;
V_55 . V_11 = V_16 -> V_11 ;
V_55 . V_10 = V_16 -> V_10 ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = V_53 -> V_60 ;
V_55 . V_61 = V_53 -> V_62 ;
F_32 ( V_2 , F_33 ( & V_55 ) ) ;
V_49 = F_34 ( V_2 , & V_55 , NULL , false ) ;
if ( F_35 ( V_49 ) ) {
V_2 -> V_63 = - F_36 ( V_49 ) ;
goto V_41;
}
} else
F_37 ( V_49 ) ;
if ( F_2 ( V_2 ) -> V_64 > F_38 ( V_49 ) ) {
F_39 ( V_2 , F_38 ( V_49 ) ) ;
}
F_40 ( V_49 ) ;
goto V_41;
}
F_41 ( type , V_25 , & V_33 ) ;
switch ( V_2 -> V_3 ) {
struct V_65 * V_66 , * * V_67 ;
case V_68 :
if ( F_25 ( V_2 ) )
goto V_41;
V_66 = F_42 ( V_2 , & V_67 , V_18 -> V_21 ,
& V_29 -> V_11 , & V_29 -> V_10 ,
F_21 ( V_8 ) ) ;
if ( V_66 == NULL )
goto V_41;
F_43 ( V_66 -> V_2 != NULL ) ;
if ( ! F_29 ( V_34 , F_44 ( V_66 ) -> V_69 ,
F_44 ( V_66 ) -> V_70 ) ) {
F_26 ( V_35 , V_46 ) ;
goto V_41;
}
F_45 ( V_2 , V_66 , V_67 ) ;
goto V_41;
case V_71 :
case V_72 :
if ( ! F_25 ( V_2 ) ) {
F_46 ( V_73 ) ;
V_2 -> V_74 = V_33 ;
V_2 -> V_75 ( V_2 ) ;
F_47 ( V_2 ) ;
} else
V_2 -> V_63 = V_33 ;
goto V_41;
}
if ( ! F_25 ( V_2 ) && V_16 -> V_76 ) {
V_2 -> V_74 = V_33 ;
V_2 -> V_75 ( V_2 ) ;
} else
V_2 -> V_63 = V_33 ;
V_41:
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_65 * V_66 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_51 ( V_66 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_81 * V_24 = NULL ;
struct V_9 * V_82 , V_83 ;
struct V_54 V_55 ;
int V_33 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_13 ;
V_55 . V_11 = V_80 -> V_84 ;
V_55 . V_10 = V_80 -> V_85 ;
V_55 . V_86 = 0 ;
V_55 . V_57 = V_80 -> V_87 ;
V_55 . V_59 = F_52 ( V_66 ) -> V_88 ;
V_55 . V_61 = F_52 ( V_66 ) -> V_89 ;
F_53 ( V_66 , F_33 ( & V_55 ) ) ;
V_24 = V_16 -> V_24 ;
V_82 = F_54 ( & V_55 , V_24 , & V_83 ) ;
V_49 = F_34 ( V_2 , & V_55 , V_82 , false ) ;
if ( F_35 ( V_49 ) ) {
V_33 = F_36 ( V_49 ) ;
V_49 = NULL ;
goto V_90;
}
V_8 = F_55 ( V_2 , V_49 , V_66 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_80 -> V_85 ,
& V_80 -> V_84 ) ;
V_55 . V_11 = V_80 -> V_84 ;
V_33 = F_56 ( V_2 , V_8 , & V_55 , V_24 , V_16 -> V_91 ) ;
V_33 = F_57 ( V_33 ) ;
}
V_90:
if ( V_24 != NULL && V_24 != V_16 -> V_24 )
F_58 ( V_2 , V_24 , V_24 -> V_92 ) ;
F_40 ( V_49 ) ;
return V_33 ;
}
static void F_59 ( struct V_65 * V_66 )
{
F_60 ( & F_44 ( V_66 ) -> V_93 ) ;
if ( F_51 ( V_66 ) -> V_94 != NULL )
F_61 ( F_51 ( V_66 ) -> V_94 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_7 * V_95 )
{
const struct V_28 * V_96 ;
struct V_7 * V_8 ;
struct V_54 V_55 ;
struct V_35 * V_35 = F_16 ( F_63 ( V_95 ) -> V_36 ) ;
struct V_1 * V_97 = V_35 -> V_98 . V_99 ;
struct V_48 * V_49 ;
if ( V_17 ( V_95 ) -> V_100 == V_101 )
return;
if ( ! F_64 ( V_95 ) )
return;
V_8 = F_65 ( V_97 , V_95 ) ;
if ( V_8 == NULL )
return;
V_96 = F_14 ( V_95 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_96 -> V_10 ,
& V_96 -> V_11 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_11 = V_96 -> V_10 ;
V_55 . V_10 = V_96 -> V_11 ;
V_55 . V_56 = V_13 ;
V_55 . V_57 = F_21 ( V_95 ) ;
V_55 . V_59 = V_17 ( V_8 ) -> V_21 ;
V_55 . V_61 = V_17 ( V_8 ) -> V_22 ;
F_66 ( V_95 , F_33 ( & V_55 ) ) ;
V_49 = F_34 ( V_97 , & V_55 , NULL , false ) ;
if ( ! F_35 ( V_49 ) ) {
F_67 ( V_8 , V_49 ) ;
F_56 ( V_97 , V_8 , & V_55 , NULL , 0 ) ;
F_46 ( V_102 ) ;
F_46 ( V_103 ) ;
return;
}
F_61 ( V_8 ) ;
}
static struct V_1 * F_68 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_28 * V_104 = F_14 ( V_8 ) ;
struct V_1 * V_105 ;
struct V_65 * * V_67 ;
struct V_65 * V_66 = F_42 ( V_2 , & V_67 ,
V_18 -> V_22 ,
& V_104 -> V_10 ,
& V_104 -> V_11 ,
F_21 ( V_8 ) ) ;
if ( V_66 != NULL )
return F_69 ( V_2 , V_8 , V_66 , V_67 ) ;
V_105 = F_70 ( F_71 ( V_2 ) , & V_38 ,
& V_104 -> V_10 , V_18 -> V_22 ,
& V_104 -> V_11 , F_72 ( V_18 -> V_21 ) ,
F_21 ( V_8 ) ) ;
if ( V_105 != NULL ) {
if ( V_105 -> V_3 != V_39 ) {
F_24 ( V_105 ) ;
return V_105 ;
}
F_22 ( F_23 ( V_105 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_65 * V_66 ;
struct V_106 * V_107 ;
struct V_79 * V_80 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_4 V_108 = F_74 ( V_8 ) -> V_109 ;
struct V_110 * V_111 = F_75 ( V_8 ) ;
if ( V_8 -> V_112 == F_76 ( V_113 ) )
return F_77 ( V_2 , V_8 ) ;
if ( ! F_64 ( V_8 ) )
return 0 ;
if ( F_78 ( V_2 , V_108 ) ) {
V_111 -> V_114 = V_115 ;
goto V_116;
}
V_111 -> V_114 = V_117 ;
if ( F_79 ( V_2 ) )
goto V_116;
if ( F_80 ( V_2 ) && F_81 ( V_2 ) > 1 )
goto V_116;
V_66 = F_82 ( & V_118 ) ;
if ( V_66 == NULL )
goto V_116;
if ( F_83 ( V_66 , F_27 ( V_2 ) , V_8 ) )
goto V_119;
V_107 = F_44 ( V_66 ) ;
if ( F_84 ( V_2 , V_107 , V_8 ) )
goto V_119;
if ( F_85 ( V_2 , V_8 , V_66 ) )
goto V_119;
V_80 = F_51 ( V_66 ) ;
V_80 -> V_84 = F_14 ( V_8 ) -> V_10 ;
V_80 -> V_85 = F_14 ( V_8 ) -> V_11 ;
if ( F_86 ( V_2 , V_8 ) ||
V_16 -> V_120 . V_121 . V_122 || V_16 -> V_120 . V_121 . V_123 ||
V_16 -> V_120 . V_121 . V_124 || V_16 -> V_120 . V_121 . V_125 ) {
F_87 ( & V_8 -> V_126 ) ;
V_80 -> V_94 = V_8 ;
}
V_80 -> V_87 = V_2 -> V_58 ;
if ( ! V_2 -> V_58 &&
F_88 ( & V_80 -> V_84 ) & V_127 )
V_80 -> V_87 = F_21 ( V_8 ) ;
V_107 -> V_128 = V_111 -> V_129 ;
V_107 -> V_130 = V_107 -> V_128 ;
V_107 -> V_69 = F_12 ( V_8 ) ;
V_107 -> V_70 = V_107 -> V_69 ;
V_107 -> V_131 = V_108 ;
if ( F_50 ( V_2 , V_66 , NULL ) )
goto V_119;
F_89 ( V_2 , V_66 , V_132 ) ;
return 0 ;
V_119:
F_90 ( V_66 ) ;
V_116:
F_46 ( V_73 ) ;
return - 1 ;
}
static struct V_1 * F_91 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_65 * V_66 ,
struct V_48 * V_49 )
{
struct V_79 * V_80 = F_51 ( V_66 ) ;
struct V_15 * V_133 , * V_16 = F_10 ( V_2 ) ;
struct V_52 * V_134 ;
struct V_135 * V_136 ;
struct V_1 * V_137 ;
struct V_81 * V_24 ;
if ( V_8 -> V_112 == F_76 ( V_113 ) ) {
V_137 = F_92 ( V_2 , V_8 , V_66 , V_49 ) ;
if ( V_137 == NULL )
return NULL ;
V_136 = (struct V_135 * ) V_137 ;
V_134 = F_31 ( V_137 ) ;
V_134 -> V_138 = & V_136 -> V_139 ;
V_133 = F_10 ( V_137 ) ;
memcpy ( V_133 , V_16 , sizeof( struct V_15 ) ) ;
F_93 ( V_134 -> V_140 , & V_133 -> V_11 ) ;
F_93 ( V_134 -> V_141 , & V_133 -> V_10 ) ;
V_133 -> V_142 = V_133 -> V_10 ;
F_2 ( V_137 ) -> V_5 = & V_6 ;
V_137 -> V_143 = V_144 ;
V_133 -> V_145 = NULL ;
V_133 -> V_24 = NULL ;
V_133 -> V_146 = F_21 ( V_8 ) ;
V_133 -> V_147 = F_14 ( V_8 ) -> V_148 ;
F_39 ( V_137 , F_2 ( V_137 ) -> V_64 ) ;
return V_137 ;
}
V_24 = V_16 -> V_24 ;
if ( F_80 ( V_2 ) )
goto V_149;
if ( V_49 == NULL ) {
struct V_9 * V_82 , V_83 ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_13 ;
V_55 . V_11 = V_80 -> V_84 ;
V_82 = F_54 ( & V_55 , V_24 , & V_83 ) ;
V_55 . V_10 = V_80 -> V_85 ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = F_52 ( V_66 ) -> V_88 ;
V_55 . V_61 = F_52 ( V_66 ) -> V_89 ;
F_32 ( V_2 , F_33 ( & V_55 ) ) ;
V_49 = F_34 ( V_2 , & V_55 , V_82 , false ) ;
if ( F_35 ( V_49 ) )
goto V_41;
}
V_137 = F_94 ( V_2 , V_66 , V_8 ) ;
if ( V_137 == NULL )
goto V_150;
F_95 ( V_137 , V_49 , NULL , NULL ) ;
V_137 -> V_151 = V_49 -> V_36 -> V_152 & ~ ( V_153 |
V_154 ) ;
V_136 = (struct V_135 * ) V_137 ;
V_134 = F_31 ( V_137 ) ;
V_134 -> V_138 = & V_136 -> V_139 ;
V_133 = F_10 ( V_137 ) ;
memcpy ( V_133 , V_16 , sizeof( struct V_15 ) ) ;
V_133 -> V_11 = V_80 -> V_84 ;
V_133 -> V_10 = V_80 -> V_85 ;
V_133 -> V_142 = V_80 -> V_85 ;
V_137 -> V_58 = V_80 -> V_87 ;
V_134 -> V_155 = NULL ;
V_133 -> V_120 . V_156 = V_16 -> V_120 . V_156 ;
V_133 -> V_145 = NULL ;
if ( V_80 -> V_94 != NULL ) {
V_133 -> V_145 = F_96 ( V_80 -> V_94 , V_157 ) ;
F_97 ( V_80 -> V_94 ) ;
V_80 -> V_94 = NULL ;
if ( V_133 -> V_145 )
F_98 ( V_133 -> V_145 , V_137 ) ;
}
V_133 -> V_24 = NULL ;
V_133 -> V_146 = F_21 ( V_8 ) ;
V_133 -> V_147 = F_14 ( V_8 ) -> V_148 ;
if ( V_24 != NULL ) {
V_133 -> V_24 = F_99 ( V_137 , V_24 ) ;
if ( V_24 != V_16 -> V_24 )
F_58 ( V_2 , V_24 , V_24 -> V_92 ) ;
}
F_2 ( V_137 ) -> V_158 = 0 ;
if ( V_133 -> V_24 != NULL )
F_2 ( V_137 ) -> V_158 = ( V_133 -> V_24 -> V_159 +
V_133 -> V_24 -> V_160 ) ;
F_39 ( V_137 , F_38 ( V_49 ) ) ;
V_134 -> V_140 = V_134 -> V_141 = V_161 ;
V_134 -> V_162 = V_161 ;
if ( F_100 ( V_2 , V_137 ) < 0 ) {
F_49 ( V_137 ) ;
goto V_41;
}
F_5 ( V_137 , NULL ) ;
return V_137 ;
V_149:
F_26 ( F_71 ( V_2 ) , V_163 ) ;
V_150:
F_40 ( V_49 ) ;
V_41:
F_26 ( F_71 ( V_2 ) , V_164 ) ;
if ( V_24 != NULL && V_24 != V_16 -> V_24 )
F_58 ( V_2 , V_24 , V_24 -> V_92 ) ;
return NULL ;
}
static int F_101 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_165 = NULL ;
if ( V_8 -> V_112 == F_76 ( V_113 ) )
return V_144 ( V_2 , V_8 ) ;
if ( F_102 ( V_2 , V_8 ) )
goto V_166;
if ( V_16 -> V_120 . V_156 )
V_165 = F_96 ( V_8 , V_157 ) ;
if ( V_2 -> V_3 == V_167 ) {
if ( F_103 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_168;
if ( V_165 ) {
F_104 ( V_165 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_68 ) {
struct V_1 * V_105 = F_68 ( V_2 , V_8 ) ;
if ( V_105 == NULL )
goto V_166;
if ( V_105 != V_2 ) {
if ( F_105 ( V_2 , V_105 , V_8 ) )
goto V_168;
if ( V_165 != NULL )
F_104 ( V_165 ) ;
return 0 ;
}
}
if ( F_106 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_168;
if ( V_165 ) {
F_104 ( V_165 ) ;
}
return 0 ;
V_168:
F_62 ( V_2 , V_8 ) ;
V_166:
if ( V_165 != NULL )
F_104 ( V_165 ) ;
F_61 ( V_8 ) ;
return 0 ;
}
static int F_107 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_169 ;
if ( F_108 ( V_8 ) )
goto V_170;
if ( F_7 ( V_8 , & F_14 ( V_8 ) -> V_10 ,
& F_14 ( V_8 ) -> V_11 ) ) {
F_109 ( L_1 ) ;
goto V_170;
}
V_18 = V_17 ( V_8 ) ;
F_75 ( V_8 ) -> V_129 = F_28 ( V_18 ) ;
F_75 ( V_8 ) -> V_171 = V_18 -> V_100 ;
if ( F_110 ( V_8 ) )
F_75 ( V_8 ) -> V_172 = V_173 ;
else
F_75 ( V_8 ) -> V_172 = F_111 ( V_8 ) ;
V_2 = F_112 ( & V_38 , V_8 ,
V_18 -> V_22 , V_18 -> V_21 ) ;
if ( V_2 == NULL ) {
F_113 ( L_2
L_3 ) ;
goto V_174;
}
if ( V_2 -> V_3 == V_39 ) {
F_113 ( L_4 ) ;
F_22 ( F_23 ( V_2 ) ) ;
goto V_174;
}
V_169 = F_27 ( V_2 ) -> V_175 ;
if ( V_18 -> V_176 && ( V_169 == 0 || V_18 -> V_176 < V_169 ) ) {
F_113 ( L_5 ,
V_18 -> V_176 , V_169 ) ;
goto V_177;
}
if ( ! F_114 ( V_2 , V_178 , V_8 ) )
goto V_177;
return F_115 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_174:
if ( ! F_114 ( NULL , V_178 , V_8 ) )
goto V_170;
if ( V_18 -> V_100 != V_101 ) {
F_75 ( V_8 ) -> V_114 =
V_179 ;
F_62 ( V_2 , V_8 ) ;
}
V_170:
F_61 ( V_8 ) ;
return 0 ;
V_177:
F_49 ( V_2 ) ;
goto V_170;
}
static int F_116 ( struct V_1 * V_2 , struct V_180 * V_181 ,
int V_182 )
{
struct V_183 * V_184 = (struct V_183 * ) V_181 ;
struct V_185 * V_186 = F_2 ( V_2 ) ;
struct V_52 * V_53 = F_31 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_31 * V_32 = F_27 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_82 , V_83 ;
struct V_54 V_55 ;
struct V_48 * V_49 ;
int V_187 ;
int V_33 ;
V_32 -> V_188 = V_189 ;
if ( V_182 < V_190 )
return - V_191 ;
if ( V_184 -> V_192 != V_193 )
return - V_194 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
if ( V_16 -> V_195 ) {
V_55 . V_86 = V_184 -> V_196 & V_197 ;
F_117 ( V_55 . V_86 ) ;
if ( V_55 . V_86 & V_198 ) {
struct V_199 * V_86 ;
V_86 = F_118 ( V_2 , V_55 . V_86 ) ;
if ( V_86 == NULL )
return - V_191 ;
V_184 -> V_200 = V_86 -> V_49 ;
F_119 ( V_86 ) ;
}
}
if ( F_120 ( & V_184 -> V_200 ) )
V_184 -> V_200 . V_201 [ 15 ] = 1 ;
V_187 = F_88 ( & V_184 -> V_200 ) ;
if ( V_187 & V_202 )
return - V_203 ;
if ( V_187 & V_127 ) {
if ( V_182 >= sizeof( struct V_183 ) &&
V_184 -> V_204 ) {
if ( V_2 -> V_58 &&
V_2 -> V_58 != V_184 -> V_204 )
return - V_191 ;
V_2 -> V_58 = V_184 -> V_204 ;
}
if ( ! V_2 -> V_58 )
return - V_191 ;
}
V_16 -> V_11 = V_184 -> V_200 ;
V_16 -> V_205 = V_55 . V_86 ;
if ( V_187 == V_206 ) {
T_5 V_207 = V_186 -> V_158 ;
struct V_208 sin ;
F_121 ( V_2 , L_6 ) ;
if ( F_122 ( V_2 ) )
return - V_203 ;
sin . V_209 = V_210 ;
sin . V_211 = V_184 -> V_212 ;
sin . V_213 . V_214 = V_184 -> V_200 . V_20 [ 3 ] ;
V_186 -> V_5 = & V_6 ;
V_2 -> V_143 = V_144 ;
V_33 = F_123 ( V_2 , (struct V_180 * ) & sin , sizeof( sin ) ) ;
if ( V_33 ) {
V_186 -> V_158 = V_207 ;
V_186 -> V_5 = & V_215 ;
V_2 -> V_143 = F_101 ;
goto V_216;
}
F_93 ( V_53 -> V_141 , & V_16 -> V_10 ) ;
F_93 ( V_53 -> V_162 , & V_16 -> V_142 ) ;
return V_33 ;
}
if ( ! F_120 ( & V_16 -> V_142 ) )
V_10 = & V_16 -> V_142 ;
V_55 . V_56 = V_13 ;
V_55 . V_11 = V_16 -> V_11 ;
V_55 . V_10 = V_10 ? * V_10 : V_16 -> V_10 ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = V_184 -> V_212 ;
V_55 . V_61 = V_53 -> V_62 ;
F_32 ( V_2 , F_33 ( & V_55 ) ) ;
V_82 = F_54 ( & V_55 , V_16 -> V_24 , & V_83 ) ;
V_49 = F_34 ( V_2 , & V_55 , V_82 , true ) ;
if ( F_35 ( V_49 ) ) {
V_33 = F_36 ( V_49 ) ;
goto V_216;
}
if ( V_10 == NULL ) {
V_10 = & V_55 . V_10 ;
V_16 -> V_142 = * V_10 ;
}
V_16 -> V_10 = * V_10 ;
V_53 -> V_162 = V_161 ;
F_95 ( V_2 , V_49 , NULL , NULL ) ;
V_186 -> V_158 = 0 ;
if ( V_16 -> V_24 != NULL )
V_186 -> V_158 = ( V_16 -> V_24 -> V_160 +
V_16 -> V_24 -> V_159 ) ;
V_53 -> V_60 = V_184 -> V_212 ;
F_124 ( V_2 , V_71 ) ;
V_33 = F_125 ( & V_217 , V_2 ) ;
if ( V_33 )
goto V_218;
V_32 -> V_219 = F_13 ( V_16 -> V_10 . V_20 ,
V_16 -> V_11 . V_20 ,
V_53 -> V_62 ,
V_53 -> V_60 ) ;
V_33 = F_126 ( V_2 ) ;
if ( V_33 )
goto V_218;
return 0 ;
V_218:
F_124 ( V_2 , V_4 ) ;
F_127 ( V_2 ) ;
V_216:
V_53 -> V_60 = 0 ;
V_2 -> V_151 = 0 ;
return V_33 ;
}
static int F_128 ( struct V_1 * V_2 )
{
static T_6 V_220 ;
int V_33 = F_129 ( V_2 , V_220 ) ;
if ( V_33 == 0 ) {
if ( F_130 ( ! V_220 ) )
V_220 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_215 ;
}
return V_33 ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
}
static int T_7 F_134 ( struct V_35 * V_35 )
{
if ( V_38 . V_221 == NULL )
return - V_222 ;
return F_135 ( & V_35 -> V_98 . V_99 , V_223 ,
V_224 , V_13 , V_35 ) ;
}
static void T_8 F_136 ( struct V_35 * V_35 )
{
F_137 ( V_35 -> V_98 . V_99 ) ;
}
static int T_9 F_138 ( void )
{
int V_33 = F_139 ( & V_225 , 1 ) ;
if ( V_33 != 0 )
goto V_41;
V_33 = F_140 ( & V_226 , V_13 ) ;
if ( V_33 != 0 )
goto V_227;
F_141 ( & V_228 ) ;
V_33 = F_142 ( & V_229 ) ;
if ( V_33 != 0 )
goto V_230;
V_41:
return V_33 ;
V_230:
F_143 ( & V_226 , V_13 ) ;
F_144 ( & V_228 ) ;
V_227:
F_145 ( & V_225 ) ;
goto V_41;
}
static void T_10 F_146 ( void )
{
F_147 ( & V_229 ) ;
F_143 ( & V_226 , V_13 ) ;
F_144 ( & V_228 ) ;
F_145 ( & V_225 ) ;
}
