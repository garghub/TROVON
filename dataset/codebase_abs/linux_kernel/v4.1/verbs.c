static void
F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
void (* F_2)( struct V_2 * );
unsigned long V_4 ;
V_1 = V_1 ;
F_3 ( & V_5 , V_4 ) ;
while ( ! F_4 ( & V_6 ) ) {
V_3 = F_5 ( V_6 . V_7 ,
struct V_2 , V_8 ) ;
F_6 ( & V_3 -> V_8 ) ;
F_2 = V_3 -> V_9 ;
V_3 -> V_9 = NULL ;
F_7 ( & V_5 , V_4 ) ;
if ( F_2 )
F_2 ( V_3 ) ;
else
F_8 ( V_3 ) ;
F_3 ( & V_5 , V_4 ) ;
}
F_7 ( & V_5 , V_4 ) ;
}
static void
F_9 ( struct V_10 * V_11 )
{
unsigned long V_4 ;
F_3 ( & V_5 , V_4 ) ;
F_10 ( V_11 , & V_6 ) ;
F_7 ( & V_5 , V_4 ) ;
F_11 ( & V_12 ) ;
}
static void
F_12 ( struct V_13 * V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
F_13 ( L_1 ,
V_18 , F_14 ( V_14 -> V_14 ) ,
V_14 -> V_19 -> V_20 , V_15 ) ;
if ( V_17 -> V_21 == 1 ) {
V_17 -> V_21 = - V_22 ;
F_15 ( V_17 ) ;
F_16 ( & V_17 -> V_23 ) ;
}
}
static void
F_17 ( struct V_13 * V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
F_13 ( L_1 ,
V_18 , F_14 ( V_14 -> V_14 ) ,
V_14 -> V_19 -> V_20 , V_15 ) ;
if ( V_17 -> V_21 == 1 ) {
V_17 -> V_21 = - V_22 ;
F_15 ( V_17 ) ;
F_16 ( & V_17 -> V_23 ) ;
}
}
static void
F_18 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 == V_27 ) {
if ( V_25 -> V_28 != V_29 &&
V_25 -> V_28 != V_30 )
F_13 ( L_2 ,
V_18 , F_19 ( V_25 -> V_28 ) ) ;
} else {
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) ( unsigned long ) V_25 -> V_26 ;
V_32 -> V_33 ( V_25 ) ;
}
}
static int
F_20 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_24 * V_36 ;
int V_37 , V_38 , V_39 ;
V_37 = V_40 / V_41 ;
do {
V_36 = V_17 -> V_42 ;
V_39 = F_21 ( V_35 , V_41 , V_36 ) ;
if ( V_39 <= 0 )
return V_39 ;
V_38 = V_39 ;
while ( V_38 -- > 0 )
F_18 ( V_36 ++ ) ;
} while ( V_39 == V_41 && -- V_37 );
return 0 ;
}
static void
F_22 ( struct V_34 * V_35 , void * V_43 )
{
struct V_16 * V_17 = (struct V_16 * ) V_43 ;
int V_39 ;
V_39 = F_20 ( V_35 , V_17 ) ;
if ( V_39 ) {
F_23 ( L_3 ,
V_18 , V_39 ) ;
return;
}
V_39 = F_24 ( V_35 ,
V_44 | V_45 ) ;
if ( V_39 == 0 )
return;
if ( V_39 < 0 ) {
F_23 ( L_4 ,
V_18 , V_39 ) ;
return;
}
F_20 ( V_35 , V_17 ) ;
}
static void
F_25 ( struct V_24 * V_25 , struct V_10 * V_11 )
{
struct V_2 * V_3 =
(struct V_2 * ) ( unsigned long ) V_25 -> V_26 ;
if ( V_25 -> V_28 != V_29 )
goto V_46;
if ( V_25 -> V_47 != V_48 )
return;
F_23 ( L_5 ,
V_18 , V_3 , V_25 -> V_49 ) ;
V_3 -> V_50 = V_25 -> V_49 ;
F_26 ( F_27 ( V_3 -> V_51 ) -> V_52 -> V_19 ,
F_28 ( V_3 -> V_53 ) ,
V_3 -> V_50 , V_54 ) ;
F_29 ( F_30 ( V_3 -> V_53 ) ) ;
V_55:
F_31 ( & V_3 -> V_8 , V_11 ) ;
return;
V_46:
if ( V_25 -> V_28 != V_30 )
F_13 ( L_6 ,
V_18 , V_3 , F_19 ( V_25 -> V_28 ) ) ;
V_3 -> V_50 = ~ 0U ;
goto V_55;
}
static int
F_32 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_10 V_11 ;
struct V_24 * V_36 ;
int V_37 , V_38 , V_39 ;
F_33 ( & V_11 ) ;
V_37 = V_40 / V_41 ;
do {
V_36 = V_17 -> V_56 ;
V_39 = F_21 ( V_35 , V_41 , V_36 ) ;
if ( V_39 <= 0 )
goto V_55;
V_38 = V_39 ;
while ( V_38 -- > 0 )
F_25 ( V_36 ++ , & V_11 ) ;
} while ( V_39 == V_41 && -- V_37 );
V_39 = 0 ;
V_55:
F_9 ( & V_11 ) ;
return V_39 ;
}
static void
F_34 ( struct V_34 * V_35 , void * V_43 )
{
struct V_16 * V_17 = (struct V_16 * ) V_43 ;
int V_39 ;
V_39 = F_32 ( V_35 , V_17 ) ;
if ( V_39 ) {
F_23 ( L_3 ,
V_18 , V_39 ) ;
return;
}
V_39 = F_24 ( V_35 ,
V_44 | V_45 ) ;
if ( V_39 == 0 )
return;
if ( V_39 < 0 ) {
F_23 ( L_4 ,
V_18 , V_39 ) ;
return;
}
F_32 ( V_35 , V_17 ) ;
}
static void
F_35 ( struct V_16 * V_17 )
{
struct V_24 V_25 ;
F_36 ( V_11 ) ;
while ( F_21 ( V_17 -> V_57 . V_58 , 1 , & V_25 ) > 0 )
F_25 ( & V_25 , & V_11 ) ;
if ( ! F_4 ( & V_11 ) )
F_9 ( & V_11 ) ;
while ( F_21 ( V_17 -> V_57 . V_59 , 1 , & V_25 ) > 0 )
F_18 ( & V_25 ) ;
}
static int
F_37 ( struct V_60 * V_61 , struct V_62 * V_14 )
{
struct V_63 * V_64 = V_61 -> V_15 ;
struct V_65 * V_66 = & V_64 -> V_67 ;
struct V_16 * V_17 = & V_64 -> V_68 ;
#if F_38 ( V_69 )
struct V_70 * V_71 = (struct V_70 * ) & V_17 -> V_72 ;
#endif
struct V_73 * V_74 = & V_66 -> V_75 ;
struct V_76 * V_77 = & V_66 -> V_78 ;
int V_79 = 0 ;
switch ( V_14 -> V_14 ) {
case V_80 :
case V_81 :
V_66 -> V_82 = 0 ;
F_39 ( & V_66 -> V_83 ) ;
break;
case V_84 :
V_66 -> V_82 = - V_85 ;
F_23 ( L_7 ,
V_18 , V_17 ) ;
F_39 ( & V_66 -> V_83 ) ;
break;
case V_86 :
V_66 -> V_82 = - V_87 ;
F_23 ( L_8 ,
V_18 , V_17 ) ;
F_39 ( & V_66 -> V_83 ) ;
break;
case V_88 :
V_79 = 1 ;
F_40 ( V_66 -> V_52 -> V_89 , V_74 ,
V_90 | V_91 ,
V_77 ) ;
F_23 ( L_9
L_10 ,
V_18 , V_74 -> V_92 ,
V_74 -> V_93 ) ;
goto V_94;
case V_95 :
V_79 = - V_96 ;
goto V_94;
case V_97 :
V_79 = - V_98 ;
goto V_94;
case V_99 :
V_79 = - V_100 ;
goto V_94;
case V_101 :
V_79 = - V_102 ;
goto V_94;
case V_103 :
V_79 = - V_104 ;
V_94:
F_23 ( L_11 ,
V_18 , V_79 > 0 ? L_12 : L_13 ) ;
V_17 -> V_21 = V_79 ;
F_15 ( V_17 ) ;
F_16 ( & V_17 -> V_23 ) ;
default:
F_23 ( L_14 ,
V_18 , V_71 , F_41 ( V_71 ) , V_17 ,
F_42 ( V_14 -> V_14 ) ) ;
break;
}
#if F_38 ( V_69 )
if ( V_79 == 1 ) {
int V_105 = V_74 -> V_92 ;
int V_106 = V_17 -> V_107 . V_108 ;
F_43 ( L_15 ,
V_71 , F_41 ( V_71 ) ,
V_66 -> V_52 -> V_19 -> V_20 ,
V_66 -> V_109 -> V_110 ,
V_64 -> V_111 . V_112 ,
V_105 , V_105 < 4 && V_105 < V_106 / 2 ? L_16 : L_12 ) ;
} else if ( V_79 < 0 ) {
F_43 ( L_17 ,
V_71 , F_41 ( V_71 ) , V_79 ) ;
}
#endif
return 0 ;
}
static struct V_60 *
F_44 ( struct V_63 * V_64 ,
struct V_65 * V_66 , struct V_70 * V_113 )
{
struct V_60 * V_61 ;
int V_39 ;
F_45 ( & V_66 -> V_83 ) ;
V_61 = F_46 ( F_37 , V_64 , V_114 , V_115 ) ;
if ( F_47 ( V_61 ) ) {
V_39 = F_48 ( V_61 ) ;
F_23 ( L_18 ,
V_18 , V_39 ) ;
return V_61 ;
}
V_66 -> V_82 = - V_116 ;
V_39 = F_49 ( V_61 , NULL , V_113 , V_117 ) ;
if ( V_39 ) {
F_23 ( L_19 ,
V_18 , V_39 ) ;
goto V_118;
}
F_50 ( & V_66 -> V_83 ,
F_51 ( V_117 ) + 1 ) ;
V_39 = V_66 -> V_82 ;
if ( V_39 )
goto V_118;
V_66 -> V_82 = - V_116 ;
V_39 = F_52 ( V_61 , V_117 ) ;
if ( V_39 ) {
F_23 ( L_20 ,
V_18 , V_39 ) ;
goto V_118;
}
F_50 ( & V_66 -> V_83 ,
F_51 ( V_117 ) + 1 ) ;
V_39 = V_66 -> V_82 ;
if ( V_39 )
goto V_118;
return V_61 ;
V_118:
F_53 ( V_61 ) ;
return F_54 ( V_39 ) ;
}
static void
F_55 ( struct V_34 * V_35 )
{
struct V_24 V_25 ;
int V_38 = 0 ;
while ( 1 == F_21 ( V_35 , 1 , & V_25 ) )
++ V_38 ;
if ( V_38 )
F_23 ( L_21 ,
V_18 , V_38 , V_25 . V_47 ) ;
}
int
F_56 ( struct V_63 * V_64 , struct V_70 * V_113 , int V_119 )
{
int V_39 , V_120 ;
struct V_65 * V_66 = & V_64 -> V_67 ;
struct V_121 * V_122 = & V_66 -> V_123 ;
V_66 -> V_52 = F_44 ( V_64 , V_66 , V_113 ) ;
if ( F_47 ( V_66 -> V_52 ) ) {
V_39 = F_48 ( V_66 -> V_52 ) ;
goto V_124;
}
V_66 -> V_125 = F_57 ( V_66 -> V_52 -> V_19 ) ;
if ( F_47 ( V_66 -> V_125 ) ) {
V_39 = F_48 ( V_66 -> V_125 ) ;
F_23 ( L_22 ,
V_18 , V_39 ) ;
goto V_126;
}
V_39 = F_58 ( V_66 -> V_52 -> V_19 , V_122 ) ;
if ( V_39 ) {
F_23 ( L_23 ,
V_18 , V_39 ) ;
goto V_127;
}
if ( V_122 -> V_128 & V_129 ) {
V_66 -> V_130 = 1 ;
V_66 -> V_131 = V_66 -> V_52 -> V_19 -> V_132 ;
}
if ( V_119 == V_133 ) {
if ( ( ( V_122 -> V_128 &
( V_134 | V_129 ) ) !=
( V_134 | V_129 ) ) ||
( V_122 -> V_135 == 0 ) ) {
F_23 ( L_24
L_25 , V_18 ) ;
V_119 = V_136 ;
}
}
if ( V_119 == V_136 ) {
if ( ! V_66 -> V_52 -> V_19 -> V_137 ) {
F_23 ( L_26
L_25 , V_18 ) ;
V_119 = V_138 ;
}
}
switch ( V_119 ) {
case V_133 :
V_66 -> V_109 = & V_139 ;
break;
case V_138 :
V_66 -> V_109 = & V_140 ;
V_120 = V_141 |
V_142 |
V_143 ;
goto V_144;
case V_136 :
V_66 -> V_109 = & V_145 ;
if ( V_66 -> V_130 )
break;
V_120 = V_141 ;
V_144:
V_66 -> V_146 = F_59 ( V_66 -> V_125 , V_120 ) ;
if ( F_47 ( V_66 -> V_146 ) ) {
F_60 ( V_147 L_27
L_28 ,
V_18 , F_48 ( V_66 -> V_146 ) ) ;
V_39 = - V_148 ;
goto V_127;
}
break;
default:
F_60 ( V_149 L_29
L_30 , V_119 ) ;
V_39 = - V_148 ;
goto V_127;
}
F_23 ( L_31 ,
V_18 , V_66 -> V_109 -> V_110 ) ;
V_66 -> V_150 = V_119 ;
F_61 ( & V_66 -> V_151 ) ;
return 0 ;
V_127:
F_62 ( V_66 -> V_125 ) ;
V_66 -> V_125 = NULL ;
V_126:
F_53 ( V_66 -> V_52 ) ;
V_66 -> V_52 = NULL ;
V_124:
return V_39 ;
}
void
F_63 ( struct V_65 * V_66 )
{
int V_39 ;
F_23 ( L_32 , V_18 ) ;
if ( V_66 -> V_146 != NULL ) {
V_39 = F_64 ( V_66 -> V_146 ) ;
F_23 ( L_33 ,
V_18 , V_39 ) ;
}
if ( V_66 -> V_52 != NULL && ! F_47 ( V_66 -> V_52 ) ) {
if ( V_66 -> V_52 -> V_89 )
F_65 ( V_66 -> V_52 ) ;
F_53 ( V_66 -> V_52 ) ;
V_66 -> V_52 = NULL ;
}
if ( V_66 -> V_125 != NULL && ! F_47 ( V_66 -> V_125 ) ) {
V_39 = F_62 ( V_66 -> V_125 ) ;
F_23 ( L_34 ,
V_18 , V_39 ) ;
}
}
int
F_66 ( struct V_16 * V_17 , struct V_65 * V_66 ,
struct V_152 * V_153 )
{
struct V_121 * V_122 = & V_66 -> V_123 ;
struct V_34 * V_154 , * V_155 ;
int V_39 , V_156 ;
if ( V_153 -> V_157 > V_122 -> V_158 )
V_153 -> V_157 = V_122 -> V_158 ;
V_17 -> V_57 . V_159 = F_12 ;
V_17 -> V_57 . V_160 = V_17 ;
V_17 -> V_57 . V_161 = NULL ;
V_17 -> V_57 . V_162 . V_163 = V_153 -> V_157 ;
V_39 = V_66 -> V_109 -> V_164 ( V_66 , V_17 , V_153 ) ;
if ( V_39 )
return V_39 ;
V_17 -> V_57 . V_162 . V_165 = V_153 -> V_157 ;
V_17 -> V_57 . V_162 . V_166 = ( V_153 -> V_167 ? 4 : 2 ) ;
V_17 -> V_57 . V_162 . V_168 = 1 ;
V_17 -> V_57 . V_162 . V_169 = 0 ;
V_17 -> V_57 . V_170 = V_171 ;
V_17 -> V_57 . V_172 = V_115 ;
V_17 -> V_57 . V_173 = ~ 0 ;
if ( V_153 -> V_167 ) {
V_17 -> V_174 = F_67 ( V_66 , V_153 -> V_167 ,
V_175 ) ;
if ( F_47 ( V_17 -> V_174 ) )
return F_48 ( V_17 -> V_174 ) ;
} else
V_17 -> V_174 = NULL ;
F_23 ( L_35
L_36 ,
V_18 ,
V_17 -> V_57 . V_162 . V_163 ,
V_17 -> V_57 . V_162 . V_165 ,
V_17 -> V_57 . V_162 . V_166 ,
V_17 -> V_57 . V_162 . V_168 ) ;
V_17 -> V_176 = V_17 -> V_57 . V_162 . V_163 / 2 - 1 ;
if ( V_17 -> V_176 > V_177 )
V_17 -> V_176 = V_177 ;
else if ( V_17 -> V_176 <= 2 )
V_17 -> V_176 = 0 ;
F_68 ( V_17 ) ;
F_69 ( & V_17 -> V_23 ) ;
F_70 ( & V_17 -> V_178 , V_179 ) ;
V_154 = F_71 ( V_66 -> V_52 -> V_19 , F_22 ,
F_17 , V_17 ,
V_17 -> V_57 . V_162 . V_163 + 1 , 0 ) ;
if ( F_47 ( V_154 ) ) {
V_39 = F_48 ( V_154 ) ;
F_23 ( L_37 ,
V_18 , V_39 ) ;
goto V_124;
}
V_39 = F_24 ( V_154 , V_44 ) ;
if ( V_39 ) {
F_23 ( L_4 ,
V_18 , V_39 ) ;
goto V_126;
}
V_155 = F_71 ( V_66 -> V_52 -> V_19 , F_34 ,
F_17 , V_17 ,
V_17 -> V_57 . V_162 . V_165 + 1 , 0 ) ;
if ( F_47 ( V_155 ) ) {
V_39 = F_48 ( V_155 ) ;
F_23 ( L_38 ,
V_18 , V_39 ) ;
goto V_126;
}
V_39 = F_24 ( V_155 , V_44 ) ;
if ( V_39 ) {
F_23 ( L_4 ,
V_18 , V_39 ) ;
F_72 ( V_155 ) ;
goto V_126;
}
V_17 -> V_57 . V_59 = V_154 ;
V_17 -> V_57 . V_58 = V_155 ;
V_17 -> V_107 . V_180 = NULL ;
V_17 -> V_107 . V_181 = 0 ;
V_17 -> V_107 . V_182 = 0 ;
if ( V_122 -> V_183 > 32 )
V_17 -> V_107 . V_108 = 32 ;
else
V_17 -> V_107 . V_108 =
V_122 -> V_183 ;
V_17 -> V_107 . V_184 = 7 ;
V_17 -> V_107 . V_185 = 0 ;
V_17 -> V_107 . V_186 = 0 ;
return 0 ;
V_126:
V_156 = F_72 ( V_154 ) ;
if ( V_156 )
F_23 ( L_39 ,
V_18 , V_156 ) ;
V_124:
F_73 ( V_66 , V_17 -> V_174 ) ;
return V_39 ;
}
void
F_74 ( struct V_16 * V_17 , struct V_65 * V_66 )
{
int V_39 ;
F_23 ( L_40 ,
V_18 , V_17 -> V_21 ) ;
F_75 ( & V_17 -> V_178 ) ;
if ( V_66 -> V_52 -> V_89 ) {
F_76 ( V_17 , V_66 ) ;
F_65 ( V_66 -> V_52 ) ;
V_66 -> V_52 -> V_89 = NULL ;
}
F_73 ( V_66 , V_17 -> V_174 ) ;
F_55 ( V_17 -> V_57 . V_58 ) ;
V_39 = F_72 ( V_17 -> V_57 . V_58 ) ;
if ( V_39 )
F_23 ( L_39 ,
V_18 , V_39 ) ;
F_55 ( V_17 -> V_57 . V_59 ) ;
V_39 = F_72 ( V_17 -> V_57 . V_59 ) ;
if ( V_39 )
F_23 ( L_39 ,
V_18 , V_39 ) ;
}
int
F_77 ( struct V_16 * V_17 , struct V_65 * V_66 )
{
struct V_60 * V_61 , * V_187 ;
int V_39 = 0 ;
int V_184 = 0 ;
if ( V_17 -> V_21 != 0 ) {
struct V_63 * V_64 ;
V_188:
F_23 ( L_41 , V_18 ) ;
F_76 ( V_17 , V_66 ) ;
F_35 ( V_17 ) ;
V_64 = F_78 ( V_66 , struct V_63 , V_67 ) ;
V_66 -> V_109 -> V_189 ( V_64 ) ;
V_61 = F_44 ( V_64 , V_66 ,
(struct V_70 * ) & V_64 -> V_190 . V_113 ) ;
if ( F_47 ( V_61 ) ) {
V_39 = - V_85 ;
goto V_118;
}
if ( V_66 -> V_52 -> V_19 != V_61 -> V_19 ) {
F_60 ( L_42
L_43 , V_18 ) ;
F_53 ( V_61 ) ;
V_39 = - V_87 ;
goto V_118;
}
V_39 = F_79 ( V_61 , V_66 -> V_125 , & V_17 -> V_57 ) ;
if ( V_39 ) {
F_23 ( L_44 ,
V_18 , V_39 ) ;
F_53 ( V_61 ) ;
V_39 = - V_87 ;
goto V_118;
}
F_80 ( & V_66 -> V_151 ) ;
V_187 = V_66 -> V_52 ;
V_66 -> V_52 = V_61 ;
F_81 ( & V_66 -> V_151 ) ;
F_65 ( V_187 ) ;
F_53 ( V_187 ) ;
} else {
F_23 ( L_45 , V_18 ) ;
V_39 = F_79 ( V_66 -> V_52 , V_66 -> V_125 , & V_17 -> V_57 ) ;
if ( V_39 ) {
F_23 ( L_44 ,
V_18 , V_39 ) ;
return - V_87 ;
}
}
V_17 -> V_21 = 0 ;
V_39 = F_82 ( V_66 -> V_52 , & V_17 -> V_107 ) ;
if ( V_39 ) {
F_23 ( L_46 ,
V_18 , V_39 ) ;
goto V_118;
}
F_83 ( V_17 -> V_23 , V_17 -> V_21 != 0 ) ;
if ( V_17 -> V_21 == - V_100 &&
++ V_184 <= V_191 ) {
F_23 ( L_47 , V_18 ) ;
goto V_188;
}
if ( V_17 -> V_21 <= 0 ) {
if ( V_184 ++ <= V_191 + 1 &&
( V_17 -> V_107 . V_108 == 0 ||
V_17 -> V_107 . V_182 !=
V_17 -> V_107 . V_108 ) ) {
if ( V_17 -> V_107 . V_108 == 0 )
V_17 -> V_107 . V_108 = 1 ;
V_17 -> V_107 . V_182 =
V_17 -> V_107 . V_108 ;
goto V_188;
}
V_39 = V_17 -> V_21 ;
} else {
F_23 ( L_48 , V_18 ) ;
}
V_118:
if ( V_39 )
V_17 -> V_21 = V_39 ;
return V_39 ;
}
void
F_76 ( struct V_16 * V_17 , struct V_65 * V_66 )
{
int V_39 ;
F_35 ( V_17 ) ;
V_39 = F_84 ( V_66 -> V_52 ) ;
if ( ! V_39 ) {
F_83 ( V_17 -> V_23 ,
V_17 -> V_21 != 1 ) ;
F_23 ( L_49 , V_18 ,
( V_17 -> V_21 == 1 ) ? L_50 : L_13 ) ;
} else {
F_23 ( L_51 , V_18 , V_39 ) ;
V_17 -> V_21 = V_39 ;
}
}
static struct V_192 *
F_85 ( struct V_63 * V_193 )
{
struct V_192 * V_194 ;
V_194 = F_86 ( sizeof( * V_194 ) , V_175 ) ;
if ( V_194 == NULL )
return F_54 ( - V_148 ) ;
V_194 -> V_195 = & V_193 -> V_111 ;
return V_194 ;
}
static struct V_2 *
F_87 ( struct V_63 * V_193 )
{
struct V_152 * V_153 = & V_193 -> V_190 ;
struct V_65 * V_66 = & V_193 -> V_67 ;
struct V_2 * V_3 ;
int V_39 ;
V_39 = - V_148 ;
V_3 = F_86 ( sizeof( * V_3 ) , V_175 ) ;
if ( V_3 == NULL )
goto V_118;
V_3 -> V_53 = F_67 ( V_66 , V_153 -> V_196 ,
V_175 ) ;
if ( F_47 ( V_3 -> V_53 ) ) {
V_39 = F_48 ( V_3 -> V_53 ) ;
goto V_197;
}
V_3 -> V_51 = & V_193 -> V_111 ;
return V_3 ;
V_197:
F_88 ( V_3 ) ;
V_118:
return F_54 ( V_39 ) ;
}
int
F_89 ( struct V_63 * V_193 )
{
struct V_198 * V_199 = & V_193 -> V_111 ;
struct V_65 * V_66 = & V_193 -> V_67 ;
struct V_152 * V_153 = & V_193 -> V_190 ;
char * V_200 ;
T_1 V_201 ;
int V_202 , V_39 ;
V_199 -> V_112 = V_153 -> V_157 ;
F_90 ( & V_199 -> V_203 ) ;
V_201 = V_199 -> V_112 *
( sizeof( struct V_192 * ) + sizeof( struct V_2 * ) ) ;
V_200 = F_86 ( V_201 , V_175 ) ;
if ( V_200 == NULL ) {
F_23 ( L_52 ,
V_18 , V_201 ) ;
V_39 = - V_148 ;
goto V_118;
}
V_199 -> V_204 = V_200 ;
V_199 -> V_205 = (struct V_192 * * ) V_200 ;
V_200 = ( char * ) & V_199 -> V_205 [ V_199 -> V_112 ] ;
V_199 -> V_206 = (struct V_2 * * ) V_200 ;
V_200 = ( char * ) & V_199 -> V_206 [ V_199 -> V_112 ] ;
V_39 = V_66 -> V_109 -> V_207 ( V_193 ) ;
if ( V_39 )
goto V_118;
for ( V_202 = 0 ; V_202 < V_199 -> V_112 ; V_202 ++ ) {
struct V_192 * V_194 ;
struct V_2 * V_3 ;
V_194 = F_85 ( V_193 ) ;
if ( F_47 ( V_194 ) ) {
F_23 ( L_53
L_54 , V_18 , V_202 ) ;
V_39 = F_48 ( V_194 ) ;
goto V_118;
}
V_199 -> V_205 [ V_202 ] = V_194 ;
V_3 = F_87 ( V_193 ) ;
if ( F_47 ( V_3 ) ) {
F_23 ( L_55 ,
V_18 , V_202 ) ;
V_39 = F_48 ( V_3 ) ;
goto V_118;
}
V_199 -> V_206 [ V_202 ] = V_3 ;
}
return 0 ;
V_118:
F_91 ( V_199 ) ;
return V_39 ;
}
static void
F_92 ( struct V_65 * V_66 , struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_73 ( V_66 , V_3 -> V_53 ) ;
F_88 ( V_3 ) ;
}
static void
F_93 ( struct V_65 * V_66 , struct V_192 * V_194 )
{
if ( ! V_194 )
return;
F_73 ( V_66 , V_194 -> V_208 ) ;
F_73 ( V_66 , V_194 -> V_209 ) ;
F_88 ( V_194 ) ;
}
void
F_91 ( struct V_198 * V_199 )
{
struct V_65 * V_66 = F_27 ( V_199 ) ;
int V_202 ;
F_23 ( L_32 , V_18 ) ;
for ( V_202 = 0 ; V_202 < V_199 -> V_112 ; V_202 ++ ) {
if ( V_199 -> V_206 )
F_92 ( V_66 , V_199 -> V_206 [ V_202 ] ) ;
if ( V_199 -> V_205 )
F_93 ( V_66 , V_199 -> V_205 [ V_202 ] ) ;
}
V_66 -> V_109 -> V_210 ( V_199 ) ;
F_88 ( V_199 -> V_204 ) ;
}
static void
F_94 ( struct V_31 * * V_211 , struct V_198 * V_199 )
{
if ( * V_211 ) {
F_31 ( & ( * V_211 ) -> V_212 , & V_199 -> V_213 ) ;
* V_211 = NULL ;
}
}
static void
F_95 ( struct V_192 * V_194 , struct V_198 * V_199 )
{
struct V_214 * V_215 = V_194 -> V_216 ;
struct V_214 * V_217 = V_215 ;
int V_202 ;
for ( V_202 = 1 , V_215 ++ ; V_202 < V_218 ; V_215 ++ , V_202 ++ )
F_94 ( & V_215 -> V_219 , V_199 ) ;
F_94 ( & V_217 -> V_219 , V_199 ) ;
}
static void
F_96 ( struct V_192 * V_194 , struct V_198 * V_199 )
{
V_199 -> V_205 [ -- V_199 -> V_220 ] = V_194 ;
V_194 -> V_221 = 0 ;
if ( V_194 -> V_222 ) {
V_199 -> V_206 [ -- V_199 -> V_223 ] = V_194 -> V_222 ;
V_194 -> V_222 -> V_9 = NULL ;
V_194 -> V_222 = NULL ;
}
}
static void
F_97 ( struct V_31 * V_32 , struct V_65 * V_66 )
{
struct V_63 * V_193 =
F_78 ( V_66 , struct V_63 , V_67 ) ;
struct V_224 V_225 , * V_226 ;
int V_39 ;
F_23 ( L_56 , V_18 , V_32 ) ;
V_32 -> V_32 . V_227 . V_228 = V_229 ;
memset ( & V_225 , 0 , sizeof( V_225 ) ) ;
V_225 . V_26 = ( unsigned long ) ( void * ) V_32 ;
V_225 . V_47 = V_230 ;
V_225 . V_231 . V_232 = V_32 -> V_32 . V_227 . V_233 -> V_234 ;
F_98 ( & V_193 -> V_68 ) ;
F_23 ( L_57 ,
V_18 , V_32 , V_32 -> V_32 . V_227 . V_233 -> V_234 ) ;
F_99 ( & V_66 -> V_151 ) ;
V_39 = F_100 ( V_66 -> V_52 -> V_89 , & V_225 , & V_226 ) ;
F_101 ( & V_66 -> V_151 ) ;
if ( V_39 ) {
V_32 -> V_32 . V_227 . V_228 = V_235 ;
F_23 ( L_58 ,
V_18 , V_39 ) ;
}
}
static void
F_102 ( struct V_10 * V_236 ,
struct V_198 * V_199 )
{
struct V_65 * V_66 = F_27 ( V_199 ) ;
struct V_10 * V_237 ;
struct V_31 * V_32 ;
unsigned long V_4 ;
F_103 (pos, stale) {
V_32 = F_5 ( V_237 , struct V_31 , V_212 ) ;
F_97 ( V_32 , V_66 ) ;
}
F_3 ( & V_199 -> V_203 , V_4 ) ;
F_10 ( V_236 , & V_199 -> V_213 ) ;
F_7 ( & V_199 -> V_203 , V_4 ) ;
}
static struct V_192 *
F_104 ( struct V_192 * V_194 , struct V_198 * V_199 ,
struct V_10 * V_236 )
{
struct V_31 * V_32 ;
int V_202 ;
V_202 = V_218 - 1 ;
while ( ! F_4 ( & V_199 -> V_213 ) ) {
V_32 = F_5 ( V_199 -> V_213 . V_7 ,
struct V_31 , V_212 ) ;
F_6 ( & V_32 -> V_212 ) ;
if ( V_32 -> V_32 . V_227 . V_228 == V_235 ) {
F_105 ( & V_32 -> V_212 , V_236 ) ;
continue;
}
V_194 -> V_216 [ V_202 ] . V_219 = V_32 ;
if ( F_106 ( V_202 -- == 0 ) )
return V_194 ;
}
F_96 ( V_194 , V_199 ) ;
F_95 ( V_194 , V_199 ) ;
return NULL ;
}
static struct V_192 *
F_107 ( struct V_192 * V_194 , struct V_198 * V_199 )
{
struct V_31 * V_32 ;
int V_202 ;
V_202 = V_218 - 1 ;
while ( ! F_4 ( & V_199 -> V_213 ) ) {
V_32 = F_5 ( V_199 -> V_213 . V_7 ,
struct V_31 , V_212 ) ;
F_6 ( & V_32 -> V_212 ) ;
V_194 -> V_216 [ V_202 ] . V_219 = V_32 ;
if ( F_106 ( V_202 -- == 0 ) )
return V_194 ;
}
F_96 ( V_194 , V_199 ) ;
F_95 ( V_194 , V_199 ) ;
return NULL ;
}
struct V_192 *
F_108 ( struct V_198 * V_238 )
{
struct V_65 * V_66 = F_27 ( V_238 ) ;
struct V_10 V_236 ;
struct V_192 * V_194 ;
unsigned long V_4 ;
F_3 ( & V_238 -> V_203 , V_4 ) ;
if ( V_238 -> V_220 == V_238 -> V_112 ) {
F_7 ( & V_238 -> V_203 , V_4 ) ;
F_23 ( L_59 , V_18 ) ;
return ( (struct V_192 * ) NULL ) ;
}
V_194 = V_238 -> V_205 [ V_238 -> V_220 ] ;
if ( V_238 -> V_220 < V_238 -> V_223 ) {
F_23 ( L_60 ,
V_18 ,
V_238 -> V_223 - V_238 -> V_220 ) ;
V_194 -> V_222 = NULL ;
} else {
V_194 -> V_222 = V_238 -> V_206 [ V_238 -> V_223 ] ;
V_238 -> V_206 [ V_238 -> V_223 ++ ] = NULL ;
}
V_238 -> V_205 [ V_238 -> V_220 ++ ] = NULL ;
F_33 ( & V_236 ) ;
switch ( V_66 -> V_150 ) {
case V_133 :
V_194 = F_104 ( V_194 , V_238 , & V_236 ) ;
break;
case V_136 :
V_194 = F_107 ( V_194 , V_238 ) ;
break;
default:
break;
}
F_7 ( & V_238 -> V_203 , V_4 ) ;
if ( ! F_4 ( & V_236 ) )
F_102 ( & V_236 , V_238 ) ;
return V_194 ;
}
void
F_109 ( struct V_192 * V_194 )
{
struct V_198 * V_238 = V_194 -> V_195 ;
struct V_65 * V_66 = F_27 ( V_238 ) ;
unsigned long V_4 ;
F_3 ( & V_238 -> V_203 , V_4 ) ;
F_96 ( V_194 , V_238 ) ;
switch ( V_66 -> V_150 ) {
case V_133 :
case V_136 :
F_95 ( V_194 , V_238 ) ;
break;
default:
break;
}
F_7 ( & V_238 -> V_203 , V_4 ) ;
}
void
F_110 ( struct V_192 * V_194 )
{
struct V_198 * V_238 = V_194 -> V_195 ;
unsigned long V_4 ;
F_3 ( & V_238 -> V_203 , V_4 ) ;
if ( V_238 -> V_223 < V_238 -> V_112 ) {
V_194 -> V_222 = V_238 -> V_206 [ V_238 -> V_223 ] ;
V_238 -> V_206 [ V_238 -> V_223 ++ ] = NULL ;
}
F_7 ( & V_238 -> V_203 , V_4 ) ;
}
void
F_8 ( struct V_2 * V_3 )
{
struct V_198 * V_238 = V_3 -> V_51 ;
unsigned long V_4 ;
V_3 -> V_9 = NULL ;
F_3 ( & V_238 -> V_203 , V_4 ) ;
V_238 -> V_206 [ -- V_238 -> V_223 ] = V_3 ;
F_7 ( & V_238 -> V_203 , V_4 ) ;
}
void
F_111 ( struct V_214 * V_215 )
{
F_23 ( L_61 ,
V_215 -> V_239 ,
( unsigned long long ) V_215 -> V_240 , V_215 -> V_241 ) ;
}
static int
F_112 ( struct V_65 * V_66 , void * V_242 , int V_201 ,
struct V_243 * * V_244 , struct V_245 * V_246 )
{
struct V_247 V_248 ;
struct V_243 * V_249 ;
int V_39 ;
V_246 -> V_113 = F_113 ( V_66 -> V_52 -> V_19 ,
V_242 , V_201 , V_250 ) ;
if ( F_114 ( V_66 -> V_52 -> V_19 , V_246 -> V_113 ) )
return - V_148 ;
V_246 -> V_251 = V_201 ;
if ( V_66 -> V_130 ) {
* V_244 = NULL ;
V_246 -> V_252 = V_66 -> V_131 ;
return 0 ;
} else if ( V_66 -> V_146 != NULL ) {
* V_244 = NULL ;
V_246 -> V_252 = V_66 -> V_146 -> V_252 ;
return 0 ;
}
V_248 . V_113 = V_246 -> V_113 ;
V_248 . V_253 = V_246 -> V_251 ;
V_249 = F_115 ( V_66 -> V_125 , & V_248 , 1 ,
V_141 , & V_246 -> V_113 ) ;
F_23 ( L_62
L_63 ,
V_18 , ( unsigned long long ) V_248 . V_113 ,
( unsigned long long ) V_246 -> V_113 , V_201 ) ;
if ( F_47 ( V_249 ) ) {
* V_244 = NULL ;
V_39 = F_48 ( V_249 ) ;
F_23 ( L_64 , V_18 , V_39 ) ;
} else {
* V_244 = V_249 ;
V_246 -> V_252 = V_249 -> V_252 ;
V_39 = 0 ;
}
return V_39 ;
}
static int
F_116 ( struct V_65 * V_66 ,
struct V_243 * V_249 , struct V_245 * V_246 )
{
int V_39 ;
F_117 ( V_66 -> V_52 -> V_19 ,
V_246 -> V_113 , V_246 -> V_251 , V_250 ) ;
if ( NULL == V_249 )
return 0 ;
V_39 = F_64 ( V_249 ) ;
if ( V_39 )
F_23 ( L_65 , V_18 , V_39 ) ;
return V_39 ;
}
struct V_254 *
F_67 ( struct V_65 * V_66 , T_1 V_253 , T_2 V_4 )
{
struct V_254 * V_255 ;
int V_39 ;
V_39 = - V_148 ;
V_255 = F_118 ( sizeof( * V_255 ) + V_253 , V_4 ) ;
if ( V_255 == NULL )
goto V_118;
V_255 -> V_256 = V_253 ;
V_255 -> V_257 = NULL ;
V_39 = F_112 ( V_66 , V_255 -> V_258 , V_253 ,
& V_255 -> V_259 , & V_255 -> V_260 ) ;
if ( V_39 )
goto V_197;
return V_255 ;
V_197:
F_88 ( V_255 ) ;
V_118:
return F_54 ( V_39 ) ;
}
void
F_73 ( struct V_65 * V_66 , struct V_254 * V_255 )
{
if ( V_255 ) {
F_116 ( V_66 , V_255 -> V_259 , & V_255 -> V_260 ) ;
F_88 ( V_255 ) ;
}
}
int
F_119 ( struct V_65 * V_66 ,
struct V_16 * V_17 ,
struct V_192 * V_194 )
{
struct V_224 V_261 , * V_262 ;
struct V_2 * V_3 = V_194 -> V_222 ;
int V_39 ;
if ( V_3 ) {
V_39 = F_120 ( V_66 , V_17 , V_3 ) ;
if ( V_39 )
goto V_118;
V_194 -> V_222 = NULL ;
}
V_261 . V_7 = NULL ;
V_261 . V_26 = V_27 ;
V_261 . V_263 = V_194 -> V_264 ;
V_261 . V_265 = V_194 -> V_221 ;
V_261 . V_47 = V_266 ;
if ( V_261 . V_265 == 4 )
F_121 ( V_66 -> V_52 -> V_19 ,
V_194 -> V_264 [ 3 ] . V_113 , V_194 -> V_264 [ 3 ] . V_251 ,
V_267 ) ;
F_121 ( V_66 -> V_52 -> V_19 ,
V_194 -> V_264 [ 1 ] . V_113 , V_194 -> V_264 [ 1 ] . V_251 ,
V_267 ) ;
F_121 ( V_66 -> V_52 -> V_19 ,
V_194 -> V_264 [ 0 ] . V_113 , V_194 -> V_264 [ 0 ] . V_251 ,
V_267 ) ;
if ( F_98 ( V_17 ) > 0 )
V_261 . V_268 = 0 ;
else {
F_68 ( V_17 ) ;
V_261 . V_268 = V_269 ;
}
V_39 = F_100 ( V_66 -> V_52 -> V_89 , & V_261 , & V_262 ) ;
if ( V_39 )
F_23 ( L_66 , V_18 ,
V_39 ) ;
V_118:
return V_39 ;
}
int
F_120 ( struct V_65 * V_66 ,
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_270 V_271 , * V_272 ;
int V_39 ;
V_271 . V_7 = NULL ;
V_271 . V_26 = ( V_273 ) ( unsigned long ) V_3 ;
V_271 . V_263 = & V_3 -> V_53 -> V_260 ;
V_271 . V_265 = 1 ;
F_26 ( V_66 -> V_52 -> V_19 ,
F_28 ( V_3 -> V_53 ) ,
F_122 ( V_3 -> V_53 ) ,
V_250 ) ;
V_39 = F_123 ( V_66 -> V_52 -> V_89 , & V_271 , & V_272 ) ;
if ( V_39 )
F_23 ( L_67 , V_18 ,
V_39 ) ;
return V_39 ;
}
unsigned int
F_124 ( struct V_63 * V_193 )
{
struct V_152 * V_153 = & V_193 -> V_190 ;
int V_274 , V_275 ;
V_274 = F_125 (unsigned int, cdata->inline_wsize, cdata->inline_rsize) ;
V_274 -= V_276 ;
if ( V_274 < sizeof( struct V_277 ) * 2 ) {
F_126 ( L_68 ,
V_18 ) ;
return 0 ;
}
V_275 = 1 << ( F_127 ( V_274 / sizeof( struct V_277 ) ) - 1 ) ;
F_23 ( L_69 ,
V_18 , V_275 ) ;
return V_275 ;
}
