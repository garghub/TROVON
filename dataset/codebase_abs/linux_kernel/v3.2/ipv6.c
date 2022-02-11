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
F_32 ( & V_55 . V_11 , & V_16 -> V_11 ) ;
F_32 ( & V_55 . V_10 , & V_16 -> V_10 ) ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = V_53 -> V_60 ;
V_55 . V_61 = V_53 -> V_62 ;
F_33 ( V_2 , F_34 ( & V_55 ) ) ;
V_49 = F_35 ( V_2 , & V_55 , NULL , false ) ;
if ( F_36 ( V_49 ) ) {
V_2 -> V_63 = - F_37 ( V_49 ) ;
goto V_41;
}
} else
F_38 ( V_49 ) ;
if ( F_2 ( V_2 ) -> V_64 > F_39 ( V_49 ) ) {
F_40 ( V_2 , F_39 ( V_49 ) ) ;
}
F_41 ( V_49 ) ;
goto V_41;
}
F_42 ( type , V_25 , & V_33 ) ;
switch ( V_2 -> V_3 ) {
struct V_65 * V_66 , * * V_67 ;
case V_68 :
if ( F_25 ( V_2 ) )
goto V_41;
V_66 = F_43 ( V_2 , & V_67 , V_18 -> V_21 ,
& V_29 -> V_11 , & V_29 -> V_10 ,
F_21 ( V_8 ) ) ;
if ( V_66 == NULL )
goto V_41;
F_44 ( V_66 -> V_2 != NULL ) ;
if ( V_34 != F_45 ( V_66 ) -> V_69 ) {
F_26 ( V_35 , V_46 ) ;
goto V_41;
}
F_46 ( V_2 , V_66 , V_67 ) ;
goto V_41;
case V_70 :
case V_71 :
if ( ! F_25 ( V_2 ) ) {
F_47 ( V_72 ) ;
V_2 -> V_73 = V_33 ;
V_2 -> V_74 ( V_2 ) ;
F_48 ( V_2 ) ;
} else
V_2 -> V_63 = V_33 ;
goto V_41;
}
if ( ! F_25 ( V_2 ) && V_16 -> V_75 ) {
V_2 -> V_73 = V_33 ;
V_2 -> V_74 ( V_2 ) ;
} else
V_2 -> V_63 = V_33 ;
V_41:
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_65 * V_66 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_52 ( V_66 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_80 * V_24 = NULL ;
struct V_9 * V_81 , V_82 ;
struct V_54 V_55 ;
int V_33 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_13 ;
F_32 ( & V_55 . V_11 , & V_79 -> V_83 ) ;
F_32 ( & V_55 . V_10 , & V_79 -> V_84 ) ;
V_55 . V_85 = 0 ;
V_55 . V_57 = V_79 -> V_86 ;
V_55 . V_59 = F_53 ( V_66 ) -> V_87 ;
V_55 . V_61 = F_53 ( V_66 ) -> V_88 ;
F_54 ( V_66 , F_34 ( & V_55 ) ) ;
V_24 = V_16 -> V_24 ;
V_81 = F_55 ( & V_55 , V_24 , & V_82 ) ;
V_49 = F_35 ( V_2 , & V_55 , V_81 , false ) ;
if ( F_36 ( V_49 ) ) {
V_33 = F_37 ( V_49 ) ;
V_49 = NULL ;
goto V_89;
}
V_8 = F_56 ( V_2 , V_49 , V_66 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_79 -> V_84 ,
& V_79 -> V_83 ) ;
F_32 ( & V_55 . V_11 , & V_79 -> V_83 ) ;
V_33 = F_57 ( V_2 , V_8 , & V_55 , V_24 , V_16 -> V_90 ) ;
V_33 = F_58 ( V_33 ) ;
}
V_89:
if ( V_24 != NULL && V_24 != V_16 -> V_24 )
F_59 ( V_2 , V_24 , V_24 -> V_91 ) ;
F_41 ( V_49 ) ;
return V_33 ;
}
static void F_60 ( struct V_65 * V_66 )
{
F_61 ( & F_45 ( V_66 ) -> V_92 ) ;
if ( F_52 ( V_66 ) -> V_93 != NULL )
F_62 ( F_52 ( V_66 ) -> V_93 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_7 * V_94 )
{
const struct V_28 * V_95 ;
struct V_7 * V_8 ;
struct V_54 V_55 ;
struct V_35 * V_35 = F_16 ( F_64 ( V_94 ) -> V_36 ) ;
struct V_1 * V_96 = V_35 -> V_97 . V_98 ;
struct V_48 * V_49 ;
if ( V_17 ( V_94 ) -> V_99 == V_100 )
return;
if ( ! F_65 ( V_94 ) )
return;
V_8 = F_66 ( V_96 , V_94 ) ;
if ( V_8 == NULL )
return;
V_95 = F_14 ( V_94 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_95 -> V_10 ,
& V_95 -> V_11 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
F_32 ( & V_55 . V_11 , & V_95 -> V_10 ) ;
F_32 ( & V_55 . V_10 , & V_95 -> V_11 ) ;
V_55 . V_56 = V_13 ;
V_55 . V_57 = F_21 ( V_94 ) ;
V_55 . V_59 = V_17 ( V_8 ) -> V_21 ;
V_55 . V_61 = V_17 ( V_8 ) -> V_22 ;
F_67 ( V_94 , F_34 ( & V_55 ) ) ;
V_49 = F_35 ( V_96 , & V_55 , NULL , false ) ;
if ( ! F_36 ( V_49 ) ) {
F_68 ( V_8 , V_49 ) ;
F_57 ( V_96 , V_8 , & V_55 , NULL , 0 ) ;
F_47 ( V_101 ) ;
F_47 ( V_102 ) ;
return;
}
F_62 ( V_8 ) ;
}
static struct V_1 * F_69 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_28 * V_103 = F_14 ( V_8 ) ;
struct V_1 * V_104 ;
struct V_65 * * V_67 ;
struct V_65 * V_66 = F_43 ( V_2 , & V_67 ,
V_18 -> V_22 ,
& V_103 -> V_10 ,
& V_103 -> V_11 ,
F_21 ( V_8 ) ) ;
if ( V_66 != NULL )
return F_70 ( V_2 , V_8 , V_66 , V_67 ) ;
V_104 = F_71 ( F_72 ( V_2 ) , & V_38 ,
& V_103 -> V_10 , V_18 -> V_22 ,
& V_103 -> V_11 , F_73 ( V_18 -> V_21 ) ,
F_21 ( V_8 ) ) ;
if ( V_104 != NULL ) {
if ( V_104 -> V_3 != V_39 ) {
F_24 ( V_104 ) ;
return V_104 ;
}
F_22 ( F_23 ( V_104 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_65 * V_66 ;
struct V_105 * V_106 ;
struct V_78 * V_79 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_4 V_107 = F_75 ( V_8 ) -> V_108 ;
struct V_109 * V_110 = F_76 ( V_8 ) ;
if ( V_8 -> V_111 == F_77 ( V_112 ) )
return F_78 ( V_2 , V_8 ) ;
if ( ! F_65 ( V_8 ) )
return 0 ;
if ( F_79 ( V_2 , V_107 ) ) {
V_110 -> V_113 = V_114 ;
goto V_115;
}
V_110 -> V_113 = V_116 ;
if ( F_80 ( V_2 ) )
goto V_115;
if ( F_81 ( V_2 ) && F_82 ( V_2 ) > 1 )
goto V_115;
V_66 = F_83 ( & V_117 ) ;
if ( V_66 == NULL )
goto V_115;
if ( F_84 ( V_66 , F_27 ( V_2 ) , V_8 ) )
goto V_118;
V_106 = F_45 ( V_66 ) ;
if ( F_85 ( V_2 , V_106 , V_8 ) )
goto V_118;
if ( F_86 ( V_2 , V_8 , V_66 ) )
goto V_118;
V_79 = F_52 ( V_66 ) ;
F_32 ( & V_79 -> V_83 , & F_14 ( V_8 ) -> V_10 ) ;
F_32 ( & V_79 -> V_84 , & F_14 ( V_8 ) -> V_11 ) ;
if ( F_87 ( V_2 , V_8 ) ||
V_16 -> V_119 . V_120 . V_121 || V_16 -> V_119 . V_120 . V_122 ||
V_16 -> V_119 . V_120 . V_123 || V_16 -> V_119 . V_120 . V_124 ) {
F_88 ( & V_8 -> V_125 ) ;
V_79 -> V_93 = V_8 ;
}
V_79 -> V_86 = V_2 -> V_58 ;
if ( ! V_2 -> V_58 &&
F_89 ( & V_79 -> V_83 ) & V_126 )
V_79 -> V_86 = F_21 ( V_8 ) ;
V_106 -> V_127 = V_110 -> V_128 ;
V_106 -> V_69 = F_12 ( V_8 ) ;
V_106 -> V_129 = V_107 ;
if ( F_51 ( V_2 , V_66 , NULL ) )
goto V_118;
F_90 ( V_2 , V_66 , V_130 ) ;
return 0 ;
V_118:
F_91 ( V_66 ) ;
V_115:
F_47 ( V_72 ) ;
return - 1 ;
}
static struct V_1 * F_92 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_65 * V_66 ,
struct V_48 * V_49 )
{
struct V_78 * V_79 = F_52 ( V_66 ) ;
struct V_15 * V_131 , * V_16 = F_10 ( V_2 ) ;
struct V_52 * V_132 ;
struct V_133 * V_134 ;
struct V_1 * V_135 ;
struct V_80 * V_24 ;
if ( V_8 -> V_111 == F_77 ( V_112 ) ) {
V_135 = F_93 ( V_2 , V_8 , V_66 , V_49 ) ;
if ( V_135 == NULL )
return NULL ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_31 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_131 = F_10 ( V_135 ) ;
memcpy ( V_131 , V_16 , sizeof( struct V_15 ) ) ;
F_94 ( V_132 -> V_138 , & V_131 -> V_11 ) ;
F_94 ( V_132 -> V_139 , & V_131 -> V_10 ) ;
F_32 ( & V_131 -> V_140 , & V_131 -> V_10 ) ;
F_2 ( V_135 ) -> V_5 = & V_6 ;
V_135 -> V_141 = V_142 ;
V_131 -> V_143 = NULL ;
V_131 -> V_24 = NULL ;
V_131 -> V_144 = F_21 ( V_8 ) ;
V_131 -> V_145 = F_14 ( V_8 ) -> V_146 ;
F_40 ( V_135 , F_2 ( V_135 ) -> V_64 ) ;
return V_135 ;
}
V_24 = V_16 -> V_24 ;
if ( F_81 ( V_2 ) )
goto V_147;
if ( V_49 == NULL ) {
struct V_9 * V_81 , V_82 ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_13 ;
F_32 ( & V_55 . V_11 , & V_79 -> V_83 ) ;
V_81 = F_55 ( & V_55 , V_24 , & V_82 ) ;
F_32 ( & V_55 . V_10 , & V_79 -> V_84 ) ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = F_53 ( V_66 ) -> V_87 ;
V_55 . V_61 = F_53 ( V_66 ) -> V_88 ;
F_33 ( V_2 , F_34 ( & V_55 ) ) ;
V_49 = F_35 ( V_2 , & V_55 , V_81 , false ) ;
if ( F_36 ( V_49 ) )
goto V_41;
}
V_135 = F_95 ( V_2 , V_66 , V_8 ) ;
if ( V_135 == NULL )
goto V_148;
F_96 ( V_135 , V_49 , NULL , NULL ) ;
V_135 -> V_149 = V_49 -> V_36 -> V_150 & ~ ( V_151 |
V_152 ) ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_31 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_131 = F_10 ( V_135 ) ;
memcpy ( V_131 , V_16 , sizeof( struct V_15 ) ) ;
F_32 ( & V_131 -> V_11 , & V_79 -> V_83 ) ;
F_32 ( & V_131 -> V_10 , & V_79 -> V_84 ) ;
F_32 ( & V_131 -> V_140 , & V_79 -> V_84 ) ;
V_135 -> V_58 = V_79 -> V_86 ;
V_132 -> V_153 = NULL ;
V_131 -> V_119 . V_154 = V_16 -> V_119 . V_154 ;
V_131 -> V_143 = NULL ;
if ( V_79 -> V_93 != NULL ) {
V_131 -> V_143 = F_97 ( V_79 -> V_93 , V_155 ) ;
F_62 ( V_79 -> V_93 ) ;
V_79 -> V_93 = NULL ;
if ( V_131 -> V_143 )
F_98 ( V_131 -> V_143 , V_135 ) ;
}
V_131 -> V_24 = NULL ;
V_131 -> V_144 = F_21 ( V_8 ) ;
V_131 -> V_145 = F_14 ( V_8 ) -> V_146 ;
if ( V_24 != NULL ) {
V_131 -> V_24 = F_99 ( V_135 , V_24 ) ;
if ( V_24 != V_16 -> V_24 )
F_59 ( V_2 , V_24 , V_24 -> V_91 ) ;
}
F_2 ( V_135 ) -> V_156 = 0 ;
if ( V_131 -> V_24 != NULL )
F_2 ( V_135 ) -> V_156 = ( V_131 -> V_24 -> V_157 +
V_131 -> V_24 -> V_158 ) ;
F_40 ( V_135 , F_39 ( V_49 ) ) ;
V_132 -> V_138 = V_132 -> V_139 = V_159 ;
V_132 -> V_160 = V_159 ;
if ( F_100 ( V_2 , V_135 ) < 0 ) {
F_50 ( V_135 ) ;
goto V_41;
}
F_5 ( V_135 , NULL ) ;
return V_135 ;
V_147:
F_26 ( F_72 ( V_2 ) , V_161 ) ;
V_148:
F_41 ( V_49 ) ;
V_41:
F_26 ( F_72 ( V_2 ) , V_162 ) ;
if ( V_24 != NULL && V_24 != V_16 -> V_24 )
F_59 ( V_2 , V_24 , V_24 -> V_91 ) ;
return NULL ;
}
static int F_101 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_163 = NULL ;
if ( V_8 -> V_111 == F_77 ( V_112 ) )
return V_142 ( V_2 , V_8 ) ;
if ( F_102 ( V_2 , V_8 ) )
goto V_164;
if ( V_16 -> V_119 . V_154 )
V_163 = F_97 ( V_8 , V_155 ) ;
if ( V_2 -> V_3 == V_165 ) {
if ( F_103 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_166;
if ( V_163 ) {
F_104 ( V_163 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_68 ) {
struct V_1 * V_104 = F_69 ( V_2 , V_8 ) ;
if ( V_104 == NULL )
goto V_164;
if ( V_104 != V_2 ) {
if ( F_105 ( V_2 , V_104 , V_8 ) )
goto V_166;
if ( V_163 != NULL )
F_104 ( V_163 ) ;
return 0 ;
}
}
if ( F_106 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_166;
if ( V_163 ) {
F_104 ( V_163 ) ;
}
return 0 ;
V_166:
F_63 ( V_2 , V_8 ) ;
V_164:
if ( V_163 != NULL )
F_104 ( V_163 ) ;
F_62 ( V_8 ) ;
return 0 ;
}
static int F_107 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_167 ;
if ( F_108 ( V_8 ) )
goto V_168;
if ( F_7 ( V_8 , & F_14 ( V_8 ) -> V_10 ,
& F_14 ( V_8 ) -> V_11 ) ) {
F_109 ( L_1 ) ;
goto V_168;
}
V_18 = V_17 ( V_8 ) ;
F_76 ( V_8 ) -> V_128 = F_28 ( V_18 ) ;
F_76 ( V_8 ) -> V_169 = V_18 -> V_99 ;
if ( F_110 ( V_8 ) )
F_76 ( V_8 ) -> V_170 = V_171 ;
else
F_76 ( V_8 ) -> V_170 = F_111 ( V_8 ) ;
V_2 = F_112 ( & V_38 , V_8 ,
V_18 -> V_22 , V_18 -> V_21 ) ;
if ( V_2 == NULL ) {
F_113 ( L_2
L_3 ) ;
goto V_172;
}
if ( V_2 -> V_3 == V_39 ) {
F_113 ( L_4 ) ;
F_22 ( F_23 ( V_2 ) ) ;
goto V_172;
}
V_167 = F_27 ( V_2 ) -> V_173 ;
if ( V_18 -> V_174 && ( V_167 == 0 || V_18 -> V_174 < V_167 ) ) {
F_113 ( L_5 ,
V_18 -> V_174 , V_167 ) ;
goto V_175;
}
if ( ! F_114 ( V_2 , V_176 , V_8 ) )
goto V_175;
return F_115 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_172:
if ( ! F_114 ( NULL , V_176 , V_8 ) )
goto V_168;
if ( V_18 -> V_99 != V_100 ) {
F_76 ( V_8 ) -> V_113 =
V_177 ;
F_63 ( V_2 , V_8 ) ;
}
V_168:
F_62 ( V_8 ) ;
return 0 ;
V_175:
F_50 ( V_2 ) ;
goto V_168;
}
static int F_116 ( struct V_1 * V_2 , struct V_178 * V_179 ,
int V_180 )
{
struct V_181 * V_182 = (struct V_181 * ) V_179 ;
struct V_183 * V_184 = F_2 ( V_2 ) ;
struct V_52 * V_53 = F_31 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_31 * V_32 = F_27 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_81 , V_82 ;
struct V_54 V_55 ;
struct V_48 * V_49 ;
int V_185 ;
int V_33 ;
V_32 -> V_186 = V_187 ;
if ( V_180 < V_188 )
return - V_189 ;
if ( V_182 -> V_190 != V_191 )
return - V_192 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
if ( V_16 -> V_193 ) {
V_55 . V_85 = V_182 -> V_194 & V_195 ;
F_117 ( V_55 . V_85 ) ;
if ( V_55 . V_85 & V_196 ) {
struct V_197 * V_85 ;
V_85 = F_118 ( V_2 , V_55 . V_85 ) ;
if ( V_85 == NULL )
return - V_189 ;
F_32 ( & V_182 -> V_198 , & V_85 -> V_49 ) ;
F_119 ( V_85 ) ;
}
}
if ( F_120 ( & V_182 -> V_198 ) )
V_182 -> V_198 . V_199 [ 15 ] = 1 ;
V_185 = F_89 ( & V_182 -> V_198 ) ;
if ( V_185 & V_200 )
return - V_201 ;
if ( V_185 & V_126 ) {
if ( V_180 >= sizeof( struct V_181 ) &&
V_182 -> V_202 ) {
if ( V_2 -> V_58 &&
V_2 -> V_58 != V_182 -> V_202 )
return - V_189 ;
V_2 -> V_58 = V_182 -> V_202 ;
}
if ( ! V_2 -> V_58 )
return - V_189 ;
}
F_32 ( & V_16 -> V_11 , & V_182 -> V_198 ) ;
V_16 -> V_203 = V_55 . V_85 ;
if ( V_185 == V_204 ) {
T_5 V_205 = V_184 -> V_156 ;
struct V_206 sin ;
F_121 ( V_2 , L_6 ) ;
if ( F_122 ( V_2 ) )
return - V_201 ;
sin . V_207 = V_208 ;
sin . V_209 = V_182 -> V_210 ;
sin . V_211 . V_212 = V_182 -> V_198 . V_20 [ 3 ] ;
V_184 -> V_5 = & V_6 ;
V_2 -> V_141 = V_142 ;
V_33 = F_123 ( V_2 , (struct V_178 * ) & sin , sizeof( sin ) ) ;
if ( V_33 ) {
V_184 -> V_156 = V_205 ;
V_184 -> V_5 = & V_213 ;
V_2 -> V_141 = F_101 ;
goto V_214;
}
F_94 ( V_53 -> V_139 , & V_16 -> V_10 ) ;
F_94 ( V_53 -> V_160 , & V_16 -> V_140 ) ;
return V_33 ;
}
if ( ! F_120 ( & V_16 -> V_140 ) )
V_10 = & V_16 -> V_140 ;
V_55 . V_56 = V_13 ;
F_32 ( & V_55 . V_11 , & V_16 -> V_11 ) ;
F_32 ( & V_55 . V_10 , V_10 ? V_10 : & V_16 -> V_10 ) ;
V_55 . V_57 = V_2 -> V_58 ;
V_55 . V_59 = V_182 -> V_210 ;
V_55 . V_61 = V_53 -> V_62 ;
F_33 ( V_2 , F_34 ( & V_55 ) ) ;
V_81 = F_55 ( & V_55 , V_16 -> V_24 , & V_82 ) ;
V_49 = F_35 ( V_2 , & V_55 , V_81 , true ) ;
if ( F_36 ( V_49 ) ) {
V_33 = F_37 ( V_49 ) ;
goto V_214;
}
if ( V_10 == NULL ) {
V_10 = & V_55 . V_10 ;
F_32 ( & V_16 -> V_140 , V_10 ) ;
}
F_32 ( & V_16 -> V_10 , V_10 ) ;
V_53 -> V_160 = V_159 ;
F_96 ( V_2 , V_49 , NULL , NULL ) ;
V_184 -> V_156 = 0 ;
if ( V_16 -> V_24 != NULL )
V_184 -> V_156 = ( V_16 -> V_24 -> V_158 +
V_16 -> V_24 -> V_157 ) ;
V_53 -> V_60 = V_182 -> V_210 ;
F_124 ( V_2 , V_70 ) ;
V_33 = F_125 ( & V_215 , V_2 ) ;
if ( V_33 )
goto V_216;
V_32 -> V_217 = F_13 ( V_16 -> V_10 . V_20 ,
V_16 -> V_11 . V_20 ,
V_53 -> V_62 ,
V_53 -> V_60 ) ;
V_33 = F_126 ( V_2 ) ;
if ( V_33 )
goto V_216;
return 0 ;
V_216:
F_124 ( V_2 , V_4 ) ;
F_127 ( V_2 ) ;
V_214:
V_53 -> V_60 = 0 ;
V_2 -> V_149 = 0 ;
return V_33 ;
}
static int F_128 ( struct V_1 * V_2 )
{
static T_6 V_218 ;
int V_33 = F_129 ( V_2 , V_218 ) ;
if ( V_33 == 0 ) {
if ( F_130 ( ! V_218 ) )
V_218 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_213 ;
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
if ( V_38 . V_219 == NULL )
return - V_220 ;
return F_135 ( & V_35 -> V_97 . V_98 , V_221 ,
V_222 , V_13 , V_35 ) ;
}
static void T_8 F_136 ( struct V_35 * V_35 )
{
F_137 ( V_35 -> V_97 . V_98 ) ;
}
static int T_9 F_138 ( void )
{
int V_33 = F_139 ( & V_223 , 1 ) ;
if ( V_33 != 0 )
goto V_41;
V_33 = F_140 ( & V_224 , V_13 ) ;
if ( V_33 != 0 )
goto V_225;
F_141 ( & V_226 ) ;
V_33 = F_142 ( & V_227 ) ;
if ( V_33 != 0 )
goto V_228;
V_41:
return V_33 ;
V_228:
F_143 ( & V_224 , V_13 ) ;
F_144 ( & V_226 ) ;
V_225:
F_145 ( & V_223 ) ;
goto V_41;
}
static void T_10 F_146 ( void )
{
F_147 ( & V_227 ) ;
F_143 ( & V_224 , V_13 ) ;
F_144 ( & V_226 ) ;
F_145 ( & V_223 ) ;
}
