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
static inline T_2 F_12 ( T_3 * V_10 , T_3 * V_11 ,
T_4 V_20 , T_4 V_21 )
{
return F_13 ( V_10 , V_11 , V_20 , V_21 ) ;
}
static inline T_2 F_14 ( struct V_7 * V_8 )
{
return F_12 ( F_15 ( V_8 ) -> V_11 . V_22 ,
F_15 ( V_8 ) -> V_10 . V_22 ,
V_17 ( V_8 ) -> V_23 ,
V_17 ( V_8 ) -> V_24 ) ;
}
static void F_16 ( struct V_7 * V_8 , struct V_25 * V_26 ,
T_5 type , T_5 V_27 , int V_28 , T_3 V_29 )
{
const struct V_30 * V_31 = ( const struct V_30 * ) V_8 -> V_32 ;
const struct V_17 * V_18 = (struct V_17 * ) ( V_8 -> V_32 + V_28 ) ;
struct V_33 * V_34 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_35 ;
T_6 V_36 ;
struct V_37 * V_37 = F_17 ( V_8 -> V_38 ) ;
if ( V_8 -> V_12 < V_28 + sizeof( * V_18 ) ||
V_8 -> V_12 < V_28 + F_18 ( V_18 ) ) {
F_19 ( V_37 , F_20 ( V_8 -> V_38 ) ,
V_39 ) ;
return;
}
V_2 = F_21 ( V_37 , & V_40 ,
& V_31 -> V_11 , V_18 -> V_23 ,
& V_31 -> V_10 , V_18 -> V_24 , F_22 ( V_8 ) ) ;
if ( V_2 == NULL ) {
F_19 ( V_37 , F_20 ( V_8 -> V_38 ) ,
V_39 ) ;
return;
}
if ( V_2 -> V_3 == V_41 ) {
F_23 ( F_24 ( V_2 ) ) ;
return;
}
F_25 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_27 ( V_37 , V_42 ) ;
if ( V_2 -> V_3 == V_4 )
goto V_43;
V_34 = F_28 ( V_2 ) ;
V_36 = F_29 ( V_18 ) ;
if ( ( 1 << V_2 -> V_3 ) & ~ ( V_44 | V_45 ) &&
! F_30 ( V_36 , V_34 -> V_46 , V_34 -> V_47 ) ) {
F_27 ( V_37 , V_48 ) ;
goto V_43;
}
V_16 = F_10 ( V_2 ) ;
if ( type == V_49 ) {
struct V_50 * V_51 = NULL ;
if ( F_26 ( V_2 ) )
goto V_43;
if ( ( 1 << V_2 -> V_3 ) & ( V_45 | V_52 ) )
goto V_43;
V_51 = F_31 ( V_2 , V_16 -> V_53 ) ;
if ( V_51 == NULL ) {
struct V_54 * V_55 = F_32 ( V_2 ) ;
struct V_56 V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_58 = V_13 ;
F_33 ( & V_57 . V_11 , & V_16 -> V_11 ) ;
F_33 ( & V_57 . V_10 , & V_16 -> V_10 ) ;
V_57 . V_59 = V_2 -> V_60 ;
V_57 . V_61 = V_55 -> V_62 ;
V_57 . V_63 = V_55 -> V_64 ;
F_34 ( V_2 , F_35 ( & V_57 ) ) ;
V_51 = F_36 ( V_2 , & V_57 , NULL , false ) ;
if ( F_37 ( V_51 ) ) {
V_2 -> V_65 = - F_38 ( V_51 ) ;
goto V_43;
}
} else
F_39 ( V_51 ) ;
if ( F_2 ( V_2 ) -> V_66 > F_40 ( V_51 ) ) {
F_41 ( V_2 , F_40 ( V_51 ) ) ;
}
F_42 ( V_51 ) ;
goto V_43;
}
F_43 ( type , V_27 , & V_35 ) ;
switch ( V_2 -> V_3 ) {
struct V_67 * V_68 , * * V_69 ;
case V_70 :
if ( F_26 ( V_2 ) )
goto V_43;
V_68 = F_44 ( V_2 , & V_69 , V_18 -> V_23 ,
& V_31 -> V_11 , & V_31 -> V_10 ,
F_22 ( V_8 ) ) ;
if ( V_68 == NULL )
goto V_43;
F_45 ( V_68 -> V_2 != NULL ) ;
if ( V_36 != F_46 ( V_68 ) -> V_71 ) {
F_27 ( V_37 , V_48 ) ;
goto V_43;
}
F_47 ( V_2 , V_68 , V_69 ) ;
goto V_43;
case V_72 :
case V_73 :
if ( ! F_26 ( V_2 ) ) {
F_48 ( V_74 ) ;
V_2 -> V_75 = V_35 ;
V_2 -> V_76 ( V_2 ) ;
F_49 ( V_2 ) ;
} else
V_2 -> V_65 = V_35 ;
goto V_43;
}
if ( ! F_26 ( V_2 ) && V_16 -> V_77 ) {
V_2 -> V_75 = V_35 ;
V_2 -> V_76 ( V_2 ) ;
} else
V_2 -> V_65 = V_35 ;
V_43:
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_67 * V_68 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_53 ( V_68 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_82 * V_26 = NULL ;
struct V_9 * V_83 , V_84 ;
struct V_56 V_57 ;
int V_35 = - 1 ;
struct V_50 * V_51 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_58 = V_13 ;
F_33 ( & V_57 . V_11 , & V_81 -> V_85 ) ;
F_33 ( & V_57 . V_10 , & V_81 -> V_86 ) ;
V_57 . V_87 = 0 ;
V_57 . V_59 = V_81 -> V_88 ;
V_57 . V_61 = F_54 ( V_68 ) -> V_89 ;
V_57 . V_63 = F_54 ( V_68 ) -> V_90 ;
F_55 ( V_68 , F_35 ( & V_57 ) ) ;
V_26 = V_16 -> V_26 ;
V_83 = F_56 ( & V_57 , V_26 , & V_84 ) ;
V_51 = F_36 ( V_2 , & V_57 , V_83 , false ) ;
if ( F_37 ( V_51 ) ) {
V_35 = F_38 ( V_51 ) ;
V_51 = NULL ;
goto V_91;
}
V_8 = F_57 ( V_2 , V_51 , V_68 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_81 -> V_86 ,
& V_81 -> V_85 ) ;
F_33 ( & V_57 . V_11 , & V_81 -> V_85 ) ;
V_35 = F_58 ( V_2 , V_8 , & V_57 , V_26 ) ;
V_35 = F_59 ( V_35 ) ;
}
V_91:
if ( V_26 != NULL && V_26 != V_16 -> V_26 )
F_60 ( V_2 , V_26 , V_26 -> V_92 ) ;
F_42 ( V_51 ) ;
return V_35 ;
}
static void F_61 ( struct V_67 * V_68 )
{
F_62 ( & F_46 ( V_68 ) -> V_93 ) ;
if ( F_53 ( V_68 ) -> V_94 != NULL )
F_63 ( F_53 ( V_68 ) -> V_94 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_7 * V_95 )
{
const struct V_30 * V_96 ;
struct V_7 * V_8 ;
struct V_56 V_57 ;
struct V_37 * V_37 = F_17 ( F_65 ( V_95 ) -> V_38 ) ;
struct V_1 * V_97 = V_37 -> V_98 . V_99 ;
struct V_50 * V_51 ;
if ( V_17 ( V_95 ) -> V_100 == V_101 )
return;
if ( ! F_66 ( V_95 ) )
return;
V_8 = F_67 ( V_97 , V_95 ) ;
if ( V_8 == NULL )
return;
V_96 = F_15 ( V_95 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_96 -> V_10 ,
& V_96 -> V_11 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_33 ( & V_57 . V_11 , & V_96 -> V_10 ) ;
F_33 ( & V_57 . V_10 , & V_96 -> V_11 ) ;
V_57 . V_58 = V_13 ;
V_57 . V_59 = F_22 ( V_95 ) ;
V_57 . V_61 = V_17 ( V_8 ) -> V_23 ;
V_57 . V_63 = V_17 ( V_8 ) -> V_24 ;
F_68 ( V_95 , F_35 ( & V_57 ) ) ;
V_51 = F_36 ( V_97 , & V_57 , NULL , false ) ;
if ( ! F_37 ( V_51 ) ) {
F_69 ( V_8 , V_51 ) ;
F_58 ( V_97 , V_8 , & V_57 , NULL ) ;
F_48 ( V_102 ) ;
F_48 ( V_103 ) ;
return;
}
F_63 ( V_8 ) ;
}
static struct V_1 * F_70 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_30 * V_104 = F_15 ( V_8 ) ;
struct V_1 * V_105 ;
struct V_67 * * V_69 ;
struct V_67 * V_68 = F_44 ( V_2 , & V_69 ,
V_18 -> V_24 ,
& V_104 -> V_10 ,
& V_104 -> V_11 ,
F_22 ( V_8 ) ) ;
if ( V_68 != NULL )
return F_71 ( V_2 , V_8 , V_68 , V_69 ) ;
V_105 = F_72 ( F_73 ( V_2 ) , & V_40 ,
& V_104 -> V_10 , V_18 -> V_24 ,
& V_104 -> V_11 , F_74 ( V_18 -> V_23 ) ,
F_22 ( V_8 ) ) ;
if ( V_105 != NULL ) {
if ( V_105 -> V_3 != V_41 ) {
F_25 ( V_105 ) ;
return V_105 ;
}
F_23 ( F_24 ( V_105 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_67 * V_68 ;
struct V_106 * V_107 ;
struct V_80 * V_81 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_3 V_108 = F_76 ( V_8 ) -> V_109 ;
struct V_110 * V_111 = F_77 ( V_8 ) ;
if ( V_8 -> V_112 == F_78 ( V_113 ) )
return F_79 ( V_2 , V_8 ) ;
if ( ! F_66 ( V_8 ) )
return 0 ;
if ( F_80 ( V_2 , V_108 ) ) {
V_111 -> V_114 = V_115 ;
goto V_116;
}
V_111 -> V_114 = V_117 ;
if ( F_81 ( V_2 ) )
goto V_116;
if ( F_82 ( V_2 ) && F_83 ( V_2 ) > 1 )
goto V_116;
V_68 = F_84 ( & V_118 ) ;
if ( V_68 == NULL )
goto V_116;
if ( F_85 ( V_68 , F_28 ( V_2 ) , V_8 ) )
goto V_119;
V_107 = F_46 ( V_68 ) ;
if ( F_86 ( V_2 , V_107 , V_8 ) )
goto V_119;
if ( F_87 ( V_2 , V_8 , V_68 ) )
goto V_119;
V_81 = F_53 ( V_68 ) ;
F_33 ( & V_81 -> V_85 , & F_15 ( V_8 ) -> V_10 ) ;
F_33 ( & V_81 -> V_86 , & F_15 ( V_8 ) -> V_11 ) ;
if ( F_88 ( V_2 , V_8 ) ||
V_16 -> V_120 . V_121 . V_122 || V_16 -> V_120 . V_121 . V_123 ||
V_16 -> V_120 . V_121 . V_124 || V_16 -> V_120 . V_121 . V_125 ) {
F_89 ( & V_8 -> V_126 ) ;
V_81 -> V_94 = V_8 ;
}
V_81 -> V_88 = V_2 -> V_60 ;
if ( ! V_2 -> V_60 &&
F_90 ( & V_81 -> V_85 ) & V_127 )
V_81 -> V_88 = F_22 ( V_8 ) ;
V_107 -> V_128 = V_111 -> V_129 ;
V_107 -> V_71 = F_14 ( V_8 ) ;
V_107 -> V_130 = V_108 ;
if ( F_52 ( V_2 , V_68 , NULL ) )
goto V_119;
F_91 ( V_2 , V_68 , V_131 ) ;
return 0 ;
V_119:
F_92 ( V_68 ) ;
V_116:
F_48 ( V_74 ) ;
return - 1 ;
}
static struct V_1 * F_93 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_67 * V_68 ,
struct V_50 * V_51 )
{
struct V_80 * V_81 = F_53 ( V_68 ) ;
struct V_15 * V_132 , * V_16 = F_10 ( V_2 ) ;
struct V_54 * V_133 ;
struct V_134 * V_135 ;
struct V_1 * V_136 ;
struct V_82 * V_26 ;
if ( V_8 -> V_112 == F_78 ( V_113 ) ) {
V_136 = F_94 ( V_2 , V_8 , V_68 , V_51 ) ;
if ( V_136 == NULL )
return NULL ;
V_135 = (struct V_134 * ) V_136 ;
V_133 = F_32 ( V_136 ) ;
V_133 -> V_137 = & V_135 -> V_138 ;
V_132 = F_10 ( V_136 ) ;
memcpy ( V_132 , V_16 , sizeof( struct V_15 ) ) ;
F_95 ( V_133 -> V_139 , & V_132 -> V_11 ) ;
F_95 ( V_133 -> V_140 , & V_132 -> V_10 ) ;
F_33 ( & V_132 -> V_141 , & V_132 -> V_10 ) ;
F_2 ( V_136 ) -> V_5 = & V_6 ;
V_136 -> V_142 = V_143 ;
V_132 -> V_144 = NULL ;
V_132 -> V_26 = NULL ;
V_132 -> V_145 = F_22 ( V_8 ) ;
V_132 -> V_146 = F_15 ( V_8 ) -> V_147 ;
F_41 ( V_136 , F_2 ( V_136 ) -> V_66 ) ;
return V_136 ;
}
V_26 = V_16 -> V_26 ;
if ( F_82 ( V_2 ) )
goto V_148;
if ( V_51 == NULL ) {
struct V_9 * V_83 , V_84 ;
struct V_56 V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_58 = V_13 ;
F_33 ( & V_57 . V_11 , & V_81 -> V_85 ) ;
V_83 = F_56 ( & V_57 , V_26 , & V_84 ) ;
F_33 ( & V_57 . V_10 , & V_81 -> V_86 ) ;
V_57 . V_59 = V_2 -> V_60 ;
V_57 . V_61 = F_54 ( V_68 ) -> V_89 ;
V_57 . V_63 = F_54 ( V_68 ) -> V_90 ;
F_34 ( V_2 , F_35 ( & V_57 ) ) ;
V_51 = F_36 ( V_2 , & V_57 , V_83 , false ) ;
if ( F_37 ( V_51 ) )
goto V_43;
}
V_136 = F_96 ( V_2 , V_68 , V_8 ) ;
if ( V_136 == NULL )
goto V_149;
F_97 ( V_136 , V_51 , NULL , NULL ) ;
V_136 -> V_150 = V_51 -> V_38 -> V_151 & ~ ( V_152 |
V_153 ) ;
V_135 = (struct V_134 * ) V_136 ;
V_133 = F_32 ( V_136 ) ;
V_133 -> V_137 = & V_135 -> V_138 ;
V_132 = F_10 ( V_136 ) ;
memcpy ( V_132 , V_16 , sizeof( struct V_15 ) ) ;
F_33 ( & V_132 -> V_11 , & V_81 -> V_85 ) ;
F_33 ( & V_132 -> V_10 , & V_81 -> V_86 ) ;
F_33 ( & V_132 -> V_141 , & V_81 -> V_86 ) ;
V_136 -> V_60 = V_81 -> V_88 ;
V_133 -> V_154 = NULL ;
V_132 -> V_120 . V_155 = V_16 -> V_120 . V_155 ;
V_132 -> V_144 = NULL ;
if ( V_81 -> V_94 != NULL ) {
V_132 -> V_144 = F_98 ( V_81 -> V_94 , V_156 ) ;
F_63 ( V_81 -> V_94 ) ;
V_81 -> V_94 = NULL ;
if ( V_132 -> V_144 )
F_99 ( V_132 -> V_144 , V_136 ) ;
}
V_132 -> V_26 = NULL ;
V_132 -> V_145 = F_22 ( V_8 ) ;
V_132 -> V_146 = F_15 ( V_8 ) -> V_147 ;
if ( V_26 != NULL ) {
V_132 -> V_26 = F_100 ( V_136 , V_26 ) ;
if ( V_26 != V_16 -> V_26 )
F_60 ( V_2 , V_26 , V_26 -> V_92 ) ;
}
F_2 ( V_136 ) -> V_157 = 0 ;
if ( V_132 -> V_26 != NULL )
F_2 ( V_136 ) -> V_157 = ( V_132 -> V_26 -> V_158 +
V_132 -> V_26 -> V_159 ) ;
F_41 ( V_136 , F_40 ( V_51 ) ) ;
V_133 -> V_139 = V_133 -> V_140 = V_160 ;
V_133 -> V_161 = V_160 ;
if ( F_101 ( V_2 , V_136 ) < 0 ) {
F_51 ( V_136 ) ;
goto V_43;
}
F_5 ( V_136 , NULL ) ;
return V_136 ;
V_148:
F_27 ( F_73 ( V_2 ) , V_162 ) ;
V_149:
F_42 ( V_51 ) ;
V_43:
F_27 ( F_73 ( V_2 ) , V_163 ) ;
if ( V_26 != NULL && V_26 != V_16 -> V_26 )
F_60 ( V_2 , V_26 , V_26 -> V_92 ) ;
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_164 = NULL ;
if ( V_8 -> V_112 == F_78 ( V_113 ) )
return V_143 ( V_2 , V_8 ) ;
if ( F_103 ( V_2 , V_8 ) )
goto V_165;
if ( V_16 -> V_120 . V_155 )
V_164 = F_98 ( V_8 , V_156 ) ;
if ( V_2 -> V_3 == V_166 ) {
if ( F_104 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_167;
if ( V_164 ) {
F_105 ( V_164 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_70 ) {
struct V_1 * V_105 = F_70 ( V_2 , V_8 ) ;
if ( V_105 == NULL )
goto V_165;
if ( V_105 != V_2 ) {
if ( F_106 ( V_2 , V_105 , V_8 ) )
goto V_167;
if ( V_164 != NULL )
F_105 ( V_164 ) ;
return 0 ;
}
}
if ( F_107 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_167;
if ( V_164 ) {
F_105 ( V_164 ) ;
}
return 0 ;
V_167:
F_64 ( V_2 , V_8 ) ;
V_165:
if ( V_164 != NULL )
F_105 ( V_164 ) ;
F_63 ( V_8 ) ;
return 0 ;
}
static int F_108 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_168 ;
if ( F_109 ( V_8 ) )
goto V_169;
if ( F_7 ( V_8 , & F_15 ( V_8 ) -> V_10 ,
& F_15 ( V_8 ) -> V_11 ) ) {
F_110 ( L_1 ) ;
goto V_169;
}
V_18 = V_17 ( V_8 ) ;
F_77 ( V_8 ) -> V_129 = F_29 ( V_18 ) ;
F_77 ( V_8 ) -> V_170 = V_18 -> V_100 ;
if ( F_111 ( V_8 ) )
F_77 ( V_8 ) -> V_171 = V_172 ;
else
F_77 ( V_8 ) -> V_171 = F_112 ( V_8 ) ;
V_2 = F_113 ( & V_40 , V_8 ,
V_18 -> V_24 , V_18 -> V_23 ) ;
if ( V_2 == NULL ) {
F_114 ( L_2
L_3 ) ;
goto V_173;
}
if ( V_2 -> V_3 == V_41 ) {
F_114 ( L_4 ) ;
F_23 ( F_24 ( V_2 ) ) ;
goto V_173;
}
V_168 = F_28 ( V_2 ) -> V_174 ;
if ( V_18 -> V_175 && ( V_168 == 0 || V_18 -> V_175 < V_168 ) ) {
F_114 ( L_5 ,
V_18 -> V_175 , V_168 ) ;
goto V_176;
}
if ( ! F_115 ( V_2 , V_177 , V_8 ) )
goto V_176;
return F_116 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_173:
if ( ! F_115 ( NULL , V_177 , V_8 ) )
goto V_169;
if ( V_18 -> V_100 != V_101 ) {
F_77 ( V_8 ) -> V_114 =
V_178 ;
F_64 ( V_2 , V_8 ) ;
}
V_169:
F_63 ( V_8 ) ;
return 0 ;
V_176:
F_51 ( V_2 ) ;
goto V_169;
}
static int F_117 ( struct V_1 * V_2 , struct V_179 * V_180 ,
int V_181 )
{
struct V_182 * V_183 = (struct V_182 * ) V_180 ;
struct V_184 * V_185 = F_2 ( V_2 ) ;
struct V_54 * V_55 = F_32 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_33 * V_34 = F_28 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_83 , V_84 ;
struct V_56 V_57 ;
struct V_50 * V_51 ;
int V_186 ;
int V_35 ;
V_34 -> V_187 = V_188 ;
if ( V_181 < V_189 )
return - V_190 ;
if ( V_183 -> V_191 != V_192 )
return - V_193 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
if ( V_16 -> V_194 ) {
V_57 . V_87 = V_183 -> V_195 & V_196 ;
F_118 ( V_57 . V_87 ) ;
if ( V_57 . V_87 & V_197 ) {
struct V_198 * V_87 ;
V_87 = F_119 ( V_2 , V_57 . V_87 ) ;
if ( V_87 == NULL )
return - V_190 ;
F_33 ( & V_183 -> V_199 , & V_87 -> V_51 ) ;
F_120 ( V_87 ) ;
}
}
if ( F_121 ( & V_183 -> V_199 ) )
V_183 -> V_199 . V_200 [ 15 ] = 1 ;
V_186 = F_90 ( & V_183 -> V_199 ) ;
if ( V_186 & V_201 )
return - V_202 ;
if ( V_186 & V_127 ) {
if ( V_181 >= sizeof( struct V_182 ) &&
V_183 -> V_203 ) {
if ( V_2 -> V_60 &&
V_2 -> V_60 != V_183 -> V_203 )
return - V_190 ;
V_2 -> V_60 = V_183 -> V_203 ;
}
if ( ! V_2 -> V_60 )
return - V_190 ;
}
F_33 ( & V_16 -> V_11 , & V_183 -> V_199 ) ;
V_16 -> V_204 = V_57 . V_87 ;
if ( V_186 == V_205 ) {
T_7 V_206 = V_185 -> V_157 ;
struct V_207 sin ;
F_122 ( V_2 , L_6 ) ;
if ( F_123 ( V_2 ) )
return - V_202 ;
sin . V_208 = V_209 ;
sin . V_210 = V_183 -> V_211 ;
sin . V_212 . V_213 = V_183 -> V_199 . V_22 [ 3 ] ;
V_185 -> V_5 = & V_6 ;
V_2 -> V_142 = V_143 ;
V_35 = F_124 ( V_2 , (struct V_179 * ) & sin , sizeof( sin ) ) ;
if ( V_35 ) {
V_185 -> V_157 = V_206 ;
V_185 -> V_5 = & V_214 ;
V_2 -> V_142 = F_102 ;
goto V_215;
}
F_95 ( V_55 -> V_140 , & V_16 -> V_10 ) ;
F_95 ( V_55 -> V_161 , & V_16 -> V_141 ) ;
return V_35 ;
}
if ( ! F_121 ( & V_16 -> V_141 ) )
V_10 = & V_16 -> V_141 ;
V_57 . V_58 = V_13 ;
F_33 ( & V_57 . V_11 , & V_16 -> V_11 ) ;
F_33 ( & V_57 . V_10 , V_10 ? V_10 : & V_16 -> V_10 ) ;
V_57 . V_59 = V_2 -> V_60 ;
V_57 . V_61 = V_183 -> V_211 ;
V_57 . V_63 = V_55 -> V_64 ;
F_34 ( V_2 , F_35 ( & V_57 ) ) ;
V_83 = F_56 ( & V_57 , V_16 -> V_26 , & V_84 ) ;
V_51 = F_36 ( V_2 , & V_57 , V_83 , true ) ;
if ( F_37 ( V_51 ) ) {
V_35 = F_38 ( V_51 ) ;
goto V_215;
}
if ( V_10 == NULL ) {
V_10 = & V_57 . V_10 ;
F_33 ( & V_16 -> V_141 , V_10 ) ;
}
F_33 ( & V_16 -> V_10 , V_10 ) ;
V_55 -> V_161 = V_160 ;
F_97 ( V_2 , V_51 , NULL , NULL ) ;
V_185 -> V_157 = 0 ;
if ( V_16 -> V_26 != NULL )
V_185 -> V_157 = ( V_16 -> V_26 -> V_159 +
V_16 -> V_26 -> V_158 ) ;
V_55 -> V_62 = V_183 -> V_211 ;
F_125 ( V_2 , V_72 ) ;
V_35 = F_126 ( & V_216 , V_2 ) ;
if ( V_35 )
goto V_217;
V_34 -> V_218 = F_12 ( V_16 -> V_10 . V_22 ,
V_16 -> V_11 . V_22 ,
V_55 -> V_64 ,
V_55 -> V_62 ) ;
V_35 = F_127 ( V_2 ) ;
if ( V_35 )
goto V_217;
return 0 ;
V_217:
F_125 ( V_2 , V_4 ) ;
F_128 ( V_2 ) ;
V_215:
V_55 -> V_62 = 0 ;
V_2 -> V_150 = 0 ;
return V_35 ;
}
static int F_129 ( struct V_1 * V_2 )
{
static T_8 V_219 ;
int V_35 = F_130 ( V_2 , V_219 ) ;
if ( V_35 == 0 ) {
if ( F_131 ( ! V_219 ) )
V_219 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_214 ;
}
return V_35 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
}
static int T_9 F_135 ( struct V_37 * V_37 )
{
if ( V_40 . V_220 == NULL )
return - V_221 ;
return F_136 ( & V_37 -> V_98 . V_99 , V_222 ,
V_223 , V_13 , V_37 ) ;
}
static void T_10 F_137 ( struct V_37 * V_37 )
{
F_138 ( V_37 -> V_98 . V_99 ) ;
}
static int T_11 F_139 ( void )
{
int V_35 = F_140 ( & V_224 , 1 ) ;
if ( V_35 != 0 )
goto V_43;
V_35 = F_141 ( & V_225 , V_13 ) ;
if ( V_35 != 0 )
goto V_226;
F_142 ( & V_227 ) ;
V_35 = F_143 ( & V_228 ) ;
if ( V_35 != 0 )
goto V_229;
V_43:
return V_35 ;
V_229:
F_144 ( & V_225 , V_13 ) ;
F_145 ( & V_227 ) ;
V_226:
F_146 ( & V_224 ) ;
goto V_43;
}
static void T_12 F_147 ( void )
{
F_148 ( & V_228 ) ;
F_144 ( & V_225 , V_13 ) ;
F_145 ( & V_227 ) ;
F_146 ( & V_224 ) ;
}
