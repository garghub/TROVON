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
if ( F_19 ( V_25 -> V_26 == V_27 ) )
return;
if ( V_25 -> V_28 == 0ULL ) {
if ( V_25 -> V_26 != V_29 )
F_13 ( L_2 ,
V_18 , F_20 ( V_25 -> V_26 ) ) ;
} else {
struct V_30 * V_31 ;
V_31 = (struct V_30 * ) ( unsigned long ) V_25 -> V_28 ;
V_31 -> V_31 . V_32 . V_33 = V_34 ;
F_13 ( L_3 ,
V_18 , V_31 , F_20 ( V_25 -> V_26 ) ) ;
}
}
static int
F_21 ( struct V_35 * V_36 , struct V_16 * V_17 )
{
struct V_24 * V_37 ;
int V_38 , V_39 , V_40 ;
V_38 = V_41 / V_42 ;
do {
V_37 = V_17 -> V_43 ;
V_40 = F_22 ( V_36 , V_42 , V_37 ) ;
if ( V_40 <= 0 )
return V_40 ;
V_39 = V_40 ;
while ( V_39 -- > 0 )
F_18 ( V_37 ++ ) ;
} while ( V_40 == V_42 && -- V_38 );
return 0 ;
}
static void
F_23 ( struct V_35 * V_36 , void * V_44 )
{
struct V_16 * V_17 = (struct V_16 * ) V_44 ;
int V_40 ;
V_40 = F_21 ( V_36 , V_17 ) ;
if ( V_40 ) {
F_24 ( L_4 ,
V_18 , V_40 ) ;
return;
}
V_40 = F_25 ( V_36 ,
V_45 | V_46 ) ;
if ( V_40 == 0 )
return;
if ( V_40 < 0 ) {
F_24 ( L_5 ,
V_18 , V_40 ) ;
return;
}
F_21 ( V_36 , V_17 ) ;
}
static void
F_26 ( struct V_24 * V_25 , struct V_10 * V_11 )
{
struct V_2 * V_3 =
(struct V_2 * ) ( unsigned long ) V_25 -> V_28 ;
if ( V_25 -> V_26 != V_27 )
goto V_47;
if ( V_25 -> V_48 != V_49 )
return;
F_24 ( L_6 ,
V_18 , V_3 , V_25 -> V_50 ) ;
V_3 -> V_51 = V_25 -> V_50 ;
F_27 ( F_28 ( V_3 -> V_52 ) -> V_53 -> V_19 ,
F_29 ( V_3 -> V_54 ) ,
V_3 -> V_51 , V_55 ) ;
F_30 ( F_31 ( V_3 -> V_54 ) ) ;
V_56:
F_32 ( & V_3 -> V_8 , V_11 ) ;
return;
V_47:
if ( V_25 -> V_26 != V_29 )
F_13 ( L_7 ,
V_18 , V_3 , F_20 ( V_25 -> V_26 ) ) ;
V_3 -> V_51 = ~ 0U ;
goto V_56;
}
static int
F_33 ( struct V_35 * V_36 , struct V_16 * V_17 )
{
struct V_10 V_11 ;
struct V_24 * V_37 ;
int V_38 , V_39 , V_40 ;
F_34 ( & V_11 ) ;
V_38 = V_41 / V_42 ;
do {
V_37 = V_17 -> V_57 ;
V_40 = F_22 ( V_36 , V_42 , V_37 ) ;
if ( V_40 <= 0 )
goto V_56;
V_39 = V_40 ;
while ( V_39 -- > 0 )
F_26 ( V_37 ++ , & V_11 ) ;
} while ( V_40 == V_42 && -- V_38 );
V_40 = 0 ;
V_56:
F_9 ( & V_11 ) ;
return V_40 ;
}
static void
F_35 ( struct V_35 * V_36 , void * V_44 )
{
struct V_16 * V_17 = (struct V_16 * ) V_44 ;
int V_40 ;
V_40 = F_33 ( V_36 , V_17 ) ;
if ( V_40 ) {
F_24 ( L_4 ,
V_18 , V_40 ) ;
return;
}
V_40 = F_25 ( V_36 ,
V_45 | V_46 ) ;
if ( V_40 == 0 )
return;
if ( V_40 < 0 ) {
F_24 ( L_5 ,
V_18 , V_40 ) ;
return;
}
F_33 ( V_36 , V_17 ) ;
}
static void
F_36 ( struct V_16 * V_17 )
{
struct V_24 V_25 ;
F_37 ( V_11 ) ;
while ( F_22 ( V_17 -> V_58 . V_59 , 1 , & V_25 ) > 0 )
F_26 ( & V_25 , & V_11 ) ;
if ( ! F_4 ( & V_11 ) )
F_9 ( & V_11 ) ;
while ( F_22 ( V_17 -> V_58 . V_60 , 1 , & V_25 ) > 0 )
F_18 ( & V_25 ) ;
}
static int
F_38 ( struct V_61 * V_62 , struct V_63 * V_14 )
{
struct V_64 * V_65 = V_62 -> V_15 ;
struct V_66 * V_67 = & V_65 -> V_68 ;
struct V_16 * V_17 = & V_65 -> V_69 ;
#if F_39 ( V_70 )
struct V_71 * V_72 = (struct V_71 * ) & V_17 -> V_73 ;
#endif
struct V_74 * V_75 = & V_67 -> V_76 ;
struct V_77 * V_78 = & V_67 -> V_79 ;
int V_80 = 0 ;
switch ( V_14 -> V_14 ) {
case V_81 :
case V_82 :
V_67 -> V_83 = 0 ;
F_40 ( & V_67 -> V_84 ) ;
break;
case V_85 :
V_67 -> V_83 = - V_86 ;
F_24 ( L_8 ,
V_18 , V_17 ) ;
F_40 ( & V_67 -> V_84 ) ;
break;
case V_87 :
V_67 -> V_83 = - V_88 ;
F_24 ( L_9 ,
V_18 , V_17 ) ;
F_40 ( & V_67 -> V_84 ) ;
break;
case V_89 :
V_80 = 1 ;
F_41 ( V_67 -> V_53 -> V_90 , V_75 ,
V_91 | V_92 ,
V_78 ) ;
F_24 ( L_10
L_11 ,
V_18 , V_75 -> V_93 ,
V_75 -> V_94 ) ;
goto V_95;
case V_96 :
V_80 = - V_97 ;
goto V_95;
case V_98 :
V_80 = - V_99 ;
goto V_95;
case V_100 :
V_80 = - V_101 ;
goto V_95;
case V_102 :
V_80 = - V_103 ;
goto V_95;
case V_104 :
V_80 = - V_105 ;
V_95:
F_24 ( L_12 ,
V_18 , V_80 > 0 ? L_13 : L_14 ) ;
V_17 -> V_21 = V_80 ;
F_15 ( V_17 ) ;
F_16 ( & V_17 -> V_23 ) ;
default:
F_24 ( L_15 ,
V_18 , & V_72 -> V_106 . V_107 ,
F_42 ( V_72 -> V_108 ) , V_17 ,
F_43 ( V_14 -> V_14 ) ) ;
break;
}
#if F_39 ( V_70 )
if ( V_80 == 1 ) {
int V_109 = V_75 -> V_93 ;
int V_110 = V_17 -> V_111 . V_112 ;
F_44 ( V_113 L_16
L_17 ,
& V_72 -> V_106 . V_107 ,
F_42 ( V_72 -> V_108 ) ,
V_67 -> V_53 -> V_19 -> V_20 ,
V_67 -> V_114 ,
V_65 -> V_115 . V_116 ,
V_109 , V_109 < 4 && V_109 < V_110 / 2 ? L_18 : L_13 ) ;
} else if ( V_80 < 0 ) {
F_44 ( V_113 L_19 ,
& V_72 -> V_106 . V_107 ,
F_42 ( V_72 -> V_108 ) ,
V_80 ) ;
}
#endif
return 0 ;
}
static struct V_61 *
F_45 ( struct V_64 * V_65 ,
struct V_66 * V_67 , struct V_117 * V_72 )
{
struct V_61 * V_62 ;
int V_40 ;
F_46 ( & V_67 -> V_84 ) ;
V_62 = F_47 ( F_38 , V_65 , V_118 , V_119 ) ;
if ( F_48 ( V_62 ) ) {
V_40 = F_49 ( V_62 ) ;
F_24 ( L_20 ,
V_18 , V_40 ) ;
return V_62 ;
}
V_67 -> V_83 = - V_120 ;
V_40 = F_50 ( V_62 , NULL , V_72 , V_121 ) ;
if ( V_40 ) {
F_24 ( L_21 ,
V_18 , V_40 ) ;
goto V_122;
}
F_51 ( & V_67 -> V_84 ,
F_52 ( V_121 ) + 1 ) ;
V_40 = V_67 -> V_83 ;
if ( V_40 )
goto V_122;
V_67 -> V_83 = - V_120 ;
V_40 = F_53 ( V_62 , V_121 ) ;
if ( V_40 ) {
F_24 ( L_22 ,
V_18 , V_40 ) ;
goto V_122;
}
F_51 ( & V_67 -> V_84 ,
F_52 ( V_121 ) + 1 ) ;
V_40 = V_67 -> V_83 ;
if ( V_40 )
goto V_122;
return V_62 ;
V_122:
F_54 ( V_62 ) ;
return F_55 ( V_40 ) ;
}
static void
F_56 ( struct V_35 * V_36 )
{
struct V_24 V_25 ;
int V_39 = 0 ;
while ( 1 == F_22 ( V_36 , 1 , & V_25 ) )
++ V_39 ;
if ( V_39 )
F_24 ( L_23 ,
V_18 , V_39 , V_25 . V_48 ) ;
}
int
F_57 ( struct V_64 * V_65 , struct V_117 * V_72 , int V_123 )
{
int V_40 , V_124 ;
struct V_66 * V_67 = & V_65 -> V_68 ;
struct V_125 * V_126 = & V_67 -> V_127 ;
V_67 -> V_53 = F_45 ( V_65 , V_67 , V_72 ) ;
if ( F_48 ( V_67 -> V_53 ) ) {
V_40 = F_49 ( V_67 -> V_53 ) ;
goto V_128;
}
V_67 -> V_129 = F_58 ( V_67 -> V_53 -> V_19 ) ;
if ( F_48 ( V_67 -> V_129 ) ) {
V_40 = F_49 ( V_67 -> V_129 ) ;
F_24 ( L_24 ,
V_18 , V_40 ) ;
goto V_130;
}
V_40 = F_59 ( V_67 -> V_53 -> V_19 , V_126 ) ;
if ( V_40 ) {
F_24 ( L_25 ,
V_18 , V_40 ) ;
goto V_131;
}
if ( V_126 -> V_132 & V_133 ) {
V_67 -> V_134 = 1 ;
V_67 -> V_135 = V_67 -> V_53 -> V_19 -> V_136 ;
}
if ( V_123 == V_137 ) {
if ( ( V_126 -> V_132 &
( V_138 | V_133 ) ) !=
( V_138 | V_133 ) ) {
F_24 ( L_26
L_27 , V_18 ) ;
V_123 = V_139 ;
} else {
V_67 -> V_140 = F_60 (unsigned int,
RPCRDMA_MAX_DATA_SEGS,
devattr->max_fast_reg_page_list_len) ;
}
}
if ( V_123 == V_139 ) {
if ( ! V_67 -> V_53 -> V_19 -> V_141 ) {
F_24 ( L_28
L_27 , V_18 ) ;
V_123 = V_142 ;
}
}
switch ( V_123 ) {
case V_137 :
break;
case V_142 :
V_124 = V_143 |
V_144 |
V_145 ;
goto V_146;
case V_139 :
if ( V_67 -> V_134 )
break;
V_124 = V_143 ;
V_146:
V_67 -> V_147 = F_61 ( V_67 -> V_129 , V_124 ) ;
if ( F_48 ( V_67 -> V_147 ) ) {
F_44 ( V_148 L_29
L_30 ,
V_18 , F_49 ( V_67 -> V_147 ) ) ;
V_40 = - V_149 ;
goto V_131;
}
break;
default:
F_44 ( V_150 L_31
L_32 , V_123 ) ;
V_40 = - V_149 ;
goto V_131;
}
F_24 ( L_33 ,
V_18 , V_123 ) ;
V_67 -> V_114 = V_123 ;
F_62 ( & V_67 -> V_151 ) ;
return 0 ;
V_131:
F_63 ( V_67 -> V_129 ) ;
V_67 -> V_129 = NULL ;
V_130:
F_54 ( V_67 -> V_53 ) ;
V_67 -> V_53 = NULL ;
V_128:
return V_40 ;
}
void
F_64 ( struct V_66 * V_67 )
{
int V_40 ;
F_24 ( L_34 , V_18 ) ;
if ( V_67 -> V_147 != NULL ) {
V_40 = F_65 ( V_67 -> V_147 ) ;
F_24 ( L_35 ,
V_18 , V_40 ) ;
}
if ( V_67 -> V_53 != NULL && ! F_48 ( V_67 -> V_53 ) ) {
if ( V_67 -> V_53 -> V_90 )
F_66 ( V_67 -> V_53 ) ;
F_54 ( V_67 -> V_53 ) ;
V_67 -> V_53 = NULL ;
}
if ( V_67 -> V_129 != NULL && ! F_48 ( V_67 -> V_129 ) ) {
V_40 = F_63 ( V_67 -> V_129 ) ;
F_24 ( L_36 ,
V_18 , V_40 ) ;
}
}
int
F_67 ( struct V_16 * V_17 , struct V_66 * V_67 ,
struct V_152 * V_153 )
{
struct V_125 * V_126 = & V_67 -> V_127 ;
struct V_35 * V_154 , * V_155 ;
int V_40 , V_156 ;
if ( V_153 -> V_157 > V_126 -> V_158 )
V_153 -> V_157 = V_126 -> V_158 ;
V_17 -> V_58 . V_159 = F_12 ;
V_17 -> V_58 . V_160 = V_17 ;
V_17 -> V_58 . V_161 = NULL ;
V_17 -> V_58 . V_162 . V_163 = V_153 -> V_157 ;
switch ( V_67 -> V_114 ) {
case V_137 : {
int V_164 = 7 ;
if ( V_67 -> V_140 < V_165 ) {
int V_166 = V_165 -
V_67 -> V_140 ;
do {
V_164 += 2 ;
V_166 -= V_67 -> V_140 ;
} while ( V_166 > 0 );
}
V_17 -> V_58 . V_162 . V_163 *= V_164 ;
if ( V_17 -> V_58 . V_162 . V_163 > V_126 -> V_158 ) {
V_153 -> V_157 = V_126 -> V_158 / V_164 ;
if ( ! V_153 -> V_157 )
return - V_167 ;
V_17 -> V_58 . V_162 . V_163 = V_153 -> V_157 *
V_164 ;
}
break;
}
default:
break;
}
V_17 -> V_58 . V_162 . V_168 = V_153 -> V_157 ;
V_17 -> V_58 . V_162 . V_169 = ( V_153 -> V_170 ? 4 : 2 ) ;
V_17 -> V_58 . V_162 . V_171 = 1 ;
V_17 -> V_58 . V_162 . V_172 = 0 ;
V_17 -> V_58 . V_173 = V_174 ;
V_17 -> V_58 . V_175 = V_119 ;
V_17 -> V_58 . V_176 = ~ 0 ;
if ( V_153 -> V_170 ) {
V_17 -> V_177 = F_68 ( V_67 , V_153 -> V_170 ,
V_178 ) ;
if ( F_48 ( V_17 -> V_177 ) )
return F_49 ( V_17 -> V_177 ) ;
} else
V_17 -> V_177 = NULL ;
F_24 ( L_37
L_38 ,
V_18 ,
V_17 -> V_58 . V_162 . V_163 ,
V_17 -> V_58 . V_162 . V_168 ,
V_17 -> V_58 . V_162 . V_169 ,
V_17 -> V_58 . V_162 . V_171 ) ;
V_17 -> V_179 = V_17 -> V_58 . V_162 . V_163 / 2 - 1 ;
if ( V_17 -> V_179 > V_180 )
V_17 -> V_179 = V_180 ;
else if ( V_17 -> V_179 <= 2 )
V_17 -> V_179 = 0 ;
F_69 ( V_17 ) ;
F_70 ( & V_17 -> V_23 ) ;
F_71 ( & V_17 -> V_181 , V_182 ) ;
V_154 = F_72 ( V_67 -> V_53 -> V_19 , F_23 ,
F_17 , V_17 ,
V_17 -> V_58 . V_162 . V_163 + 1 , 0 ) ;
if ( F_48 ( V_154 ) ) {
V_40 = F_49 ( V_154 ) ;
F_24 ( L_39 ,
V_18 , V_40 ) ;
goto V_128;
}
V_40 = F_25 ( V_154 , V_45 ) ;
if ( V_40 ) {
F_24 ( L_5 ,
V_18 , V_40 ) ;
goto V_130;
}
V_155 = F_72 ( V_67 -> V_53 -> V_19 , F_35 ,
F_17 , V_17 ,
V_17 -> V_58 . V_162 . V_168 + 1 , 0 ) ;
if ( F_48 ( V_155 ) ) {
V_40 = F_49 ( V_155 ) ;
F_24 ( L_40 ,
V_18 , V_40 ) ;
goto V_130;
}
V_40 = F_25 ( V_155 , V_45 ) ;
if ( V_40 ) {
F_24 ( L_5 ,
V_18 , V_40 ) ;
F_73 ( V_155 ) ;
goto V_130;
}
V_17 -> V_58 . V_60 = V_154 ;
V_17 -> V_58 . V_59 = V_155 ;
V_17 -> V_111 . V_183 = NULL ;
V_17 -> V_111 . V_184 = 0 ;
V_17 -> V_111 . V_185 = 0 ;
if ( V_126 -> V_186 > 32 )
V_17 -> V_111 . V_112 = 32 ;
else
V_17 -> V_111 . V_112 =
V_126 -> V_186 ;
V_17 -> V_111 . V_187 = 7 ;
V_17 -> V_111 . V_188 = 0 ;
V_17 -> V_111 . V_189 = 0 ;
return 0 ;
V_130:
V_156 = F_73 ( V_154 ) ;
if ( V_156 )
F_24 ( L_41 ,
V_18 , V_156 ) ;
V_128:
F_74 ( V_67 , V_17 -> V_177 ) ;
return V_40 ;
}
void
F_75 ( struct V_16 * V_17 , struct V_66 * V_67 )
{
int V_40 ;
F_24 ( L_42 ,
V_18 , V_17 -> V_21 ) ;
F_76 ( & V_17 -> V_181 ) ;
if ( V_67 -> V_53 -> V_90 ) {
F_77 ( V_17 , V_67 ) ;
F_66 ( V_67 -> V_53 ) ;
V_67 -> V_53 -> V_90 = NULL ;
}
F_74 ( V_67 , V_17 -> V_177 ) ;
F_56 ( V_17 -> V_58 . V_59 ) ;
V_40 = F_73 ( V_17 -> V_58 . V_59 ) ;
if ( V_40 )
F_24 ( L_41 ,
V_18 , V_40 ) ;
F_56 ( V_17 -> V_58 . V_60 ) ;
V_40 = F_73 ( V_17 -> V_58 . V_60 ) ;
if ( V_40 )
F_24 ( L_41 ,
V_18 , V_40 ) ;
}
int
F_78 ( struct V_16 * V_17 , struct V_66 * V_67 )
{
struct V_61 * V_62 , * V_190 ;
int V_40 = 0 ;
int V_187 = 0 ;
if ( V_17 -> V_21 != 0 ) {
struct V_64 * V_65 ;
V_191:
F_24 ( L_43 , V_18 ) ;
F_77 ( V_17 , V_67 ) ;
F_36 ( V_17 ) ;
switch ( V_67 -> V_114 ) {
case V_137 :
F_79 ( V_67 ) ;
break;
case V_139 :
F_80 ( V_67 ) ;
break;
case V_142 :
break;
default:
V_40 = - V_22 ;
goto V_122;
}
V_65 = F_81 ( V_67 , struct V_64 , V_68 ) ;
V_62 = F_45 ( V_65 , V_67 ,
(struct V_117 * ) & V_65 -> V_192 . V_72 ) ;
if ( F_48 ( V_62 ) ) {
V_40 = - V_86 ;
goto V_122;
}
if ( V_67 -> V_53 -> V_19 != V_62 -> V_19 ) {
F_44 ( L_44
L_45 , V_18 ) ;
F_54 ( V_62 ) ;
V_40 = - V_88 ;
goto V_122;
}
V_40 = F_82 ( V_62 , V_67 -> V_129 , & V_17 -> V_58 ) ;
if ( V_40 ) {
F_24 ( L_46 ,
V_18 , V_40 ) ;
F_54 ( V_62 ) ;
V_40 = - V_88 ;
goto V_122;
}
F_83 ( & V_67 -> V_151 ) ;
V_190 = V_67 -> V_53 ;
V_67 -> V_53 = V_62 ;
F_84 ( & V_67 -> V_151 ) ;
F_66 ( V_190 ) ;
F_54 ( V_190 ) ;
} else {
F_24 ( L_47 , V_18 ) ;
V_40 = F_82 ( V_67 -> V_53 , V_67 -> V_129 , & V_17 -> V_58 ) ;
if ( V_40 ) {
F_24 ( L_46 ,
V_18 , V_40 ) ;
return - V_88 ;
}
}
V_17 -> V_21 = 0 ;
V_40 = F_85 ( V_67 -> V_53 , & V_17 -> V_111 ) ;
if ( V_40 ) {
F_24 ( L_48 ,
V_18 , V_40 ) ;
goto V_122;
}
F_86 ( V_17 -> V_23 , V_17 -> V_21 != 0 ) ;
if ( V_17 -> V_21 == - V_101 &&
++ V_187 <= V_193 ) {
F_24 ( L_49 , V_18 ) ;
goto V_191;
}
if ( V_17 -> V_21 <= 0 ) {
if ( V_187 ++ <= V_193 + 1 &&
( V_17 -> V_111 . V_112 == 0 ||
V_17 -> V_111 . V_185 !=
V_17 -> V_111 . V_112 ) ) {
if ( V_17 -> V_111 . V_112 == 0 )
V_17 -> V_111 . V_112 = 1 ;
V_17 -> V_111 . V_185 =
V_17 -> V_111 . V_112 ;
goto V_191;
}
V_40 = V_17 -> V_21 ;
} else {
F_24 ( L_50 , V_18 ) ;
}
V_122:
if ( V_40 )
V_17 -> V_21 = V_40 ;
return V_40 ;
}
void
F_77 ( struct V_16 * V_17 , struct V_66 * V_67 )
{
int V_40 ;
F_36 ( V_17 ) ;
V_40 = F_87 ( V_67 -> V_53 ) ;
if ( ! V_40 ) {
F_86 ( V_17 -> V_23 ,
V_17 -> V_21 != 1 ) ;
F_24 ( L_51 , V_18 ,
( V_17 -> V_21 == 1 ) ? L_52 : L_14 ) ;
} else {
F_24 ( L_53 , V_18 , V_40 ) ;
V_17 -> V_21 = V_40 ;
}
}
static struct V_194 *
F_88 ( struct V_64 * V_195 )
{
struct V_194 * V_196 ;
V_196 = F_89 ( sizeof( * V_196 ) , V_178 ) ;
if ( V_196 == NULL )
return F_55 ( - V_149 ) ;
V_196 -> V_197 = & V_195 -> V_115 ;
return V_196 ;
}
static struct V_2 *
F_90 ( struct V_64 * V_195 )
{
struct V_152 * V_153 = & V_195 -> V_192 ;
struct V_66 * V_67 = & V_195 -> V_68 ;
struct V_2 * V_3 ;
int V_40 ;
V_40 = - V_149 ;
V_3 = F_89 ( sizeof( * V_3 ) , V_178 ) ;
if ( V_3 == NULL )
goto V_122;
V_3 -> V_54 = F_68 ( V_67 , V_153 -> V_198 ,
V_178 ) ;
if ( F_48 ( V_3 -> V_54 ) ) {
V_40 = F_49 ( V_3 -> V_54 ) ;
goto V_199;
}
V_3 -> V_52 = & V_195 -> V_115 ;
return V_3 ;
V_199:
F_91 ( V_3 ) ;
V_122:
return F_55 ( V_40 ) ;
}
static int
F_92 ( struct V_66 * V_67 , struct V_200 * V_201 )
{
int V_202 = V_144 | V_145 ;
struct V_203 V_204 = {
. V_205 = V_165 ,
. V_206 = 1 ,
. V_207 = V_208
} ;
struct V_30 * V_31 ;
int V_209 , V_40 ;
V_209 = ( V_201 -> V_116 + 1 ) * V_210 ;
F_24 ( L_54 , V_18 , V_209 ) ;
while ( V_209 -- ) {
V_31 = F_89 ( sizeof( * V_31 ) , V_178 ) ;
if ( V_31 == NULL )
return - V_149 ;
V_31 -> V_31 . V_211 = F_93 ( V_67 -> V_129 , V_202 , & V_204 ) ;
if ( F_48 ( V_31 -> V_31 . V_211 ) ) {
V_40 = F_49 ( V_31 -> V_31 . V_211 ) ;
F_24 ( L_55 ,
V_18 , V_40 ) ;
goto V_199;
}
F_94 ( & V_31 -> V_212 , & V_201 -> V_213 ) ;
F_94 ( & V_31 -> V_214 , & V_201 -> V_215 ) ;
}
return 0 ;
V_199:
F_91 ( V_31 ) ;
return V_40 ;
}
static int
F_95 ( struct V_66 * V_67 , struct V_200 * V_201 )
{
struct V_216 * V_217 ;
struct V_30 * V_31 ;
int V_209 , V_40 ;
V_209 = ( V_201 -> V_116 + 1 ) * V_210 ;
F_24 ( L_56 , V_18 , V_209 ) ;
while ( V_209 -- ) {
V_31 = F_89 ( sizeof( * V_31 ) , V_178 ) ;
if ( V_31 == NULL )
return - V_149 ;
V_217 = & V_31 -> V_31 . V_32 ;
V_217 -> V_218 = F_96 ( V_67 -> V_129 ,
V_67 -> V_140 ) ;
if ( F_48 ( V_217 -> V_218 ) ) {
V_40 = F_49 ( V_217 -> V_218 ) ;
F_24 ( L_57
L_58 , V_18 , V_40 ) ;
goto V_199;
}
V_217 -> V_219 = F_97 ( V_67 -> V_53 -> V_19 ,
V_67 -> V_140 ) ;
if ( F_48 ( V_217 -> V_219 ) ) {
V_40 = F_49 ( V_217 -> V_219 ) ;
F_24 ( L_59
L_58 , V_18 , V_40 ) ;
F_65 ( V_217 -> V_218 ) ;
goto V_199;
}
F_94 ( & V_31 -> V_212 , & V_201 -> V_213 ) ;
F_94 ( & V_31 -> V_214 , & V_201 -> V_215 ) ;
}
return 0 ;
V_199:
F_91 ( V_31 ) ;
return V_40 ;
}
int
F_98 ( struct V_64 * V_195 )
{
struct V_200 * V_201 = & V_195 -> V_115 ;
struct V_66 * V_67 = & V_195 -> V_68 ;
struct V_152 * V_153 = & V_195 -> V_192 ;
char * V_220 ;
T_1 V_221 ;
int V_209 , V_40 ;
V_201 -> V_116 = V_153 -> V_157 ;
F_99 ( & V_201 -> V_222 ) ;
V_221 = V_201 -> V_116 *
( sizeof( struct V_194 * ) + sizeof( struct V_2 * ) ) ;
V_220 = F_89 ( V_221 , V_178 ) ;
if ( V_220 == NULL ) {
F_24 ( L_60 ,
V_18 , V_221 ) ;
V_40 = - V_149 ;
goto V_122;
}
V_201 -> V_223 = V_220 ;
V_201 -> V_224 = (struct V_194 * * ) V_220 ;
V_220 = ( char * ) & V_201 -> V_224 [ V_201 -> V_116 ] ;
V_201 -> V_225 = (struct V_2 * * ) V_220 ;
V_220 = ( char * ) & V_201 -> V_225 [ V_201 -> V_116 ] ;
F_34 ( & V_201 -> V_213 ) ;
F_34 ( & V_201 -> V_215 ) ;
switch ( V_67 -> V_114 ) {
case V_137 :
V_40 = F_95 ( V_67 , V_201 ) ;
if ( V_40 )
goto V_122;
break;
case V_139 :
V_40 = F_92 ( V_67 , V_201 ) ;
if ( V_40 )
goto V_122;
break;
default:
break;
}
for ( V_209 = 0 ; V_209 < V_201 -> V_116 ; V_209 ++ ) {
struct V_194 * V_196 ;
struct V_2 * V_3 ;
V_196 = F_88 ( V_195 ) ;
if ( F_48 ( V_196 ) ) {
F_24 ( L_61
L_62 , V_18 , V_209 ) ;
V_40 = F_49 ( V_196 ) ;
goto V_122;
}
V_201 -> V_224 [ V_209 ] = V_196 ;
V_3 = F_90 ( V_195 ) ;
if ( F_48 ( V_3 ) ) {
F_24 ( L_63 ,
V_18 , V_209 ) ;
V_40 = F_49 ( V_3 ) ;
goto V_122;
}
V_201 -> V_225 [ V_209 ] = V_3 ;
}
return 0 ;
V_122:
F_100 ( V_201 ) ;
return V_40 ;
}
static void
F_101 ( struct V_66 * V_67 , struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_74 ( V_67 , V_3 -> V_54 ) ;
F_91 ( V_3 ) ;
}
static void
F_102 ( struct V_66 * V_67 , struct V_194 * V_196 )
{
if ( ! V_196 )
return;
F_74 ( V_67 , V_196 -> V_226 ) ;
F_74 ( V_67 , V_196 -> V_227 ) ;
F_91 ( V_196 ) ;
}
static void
F_103 ( struct V_200 * V_201 )
{
struct V_30 * V_31 ;
int V_40 ;
while ( ! F_4 ( & V_201 -> V_215 ) ) {
V_31 = F_5 ( V_201 -> V_215 . V_7 , struct V_30 , V_214 ) ;
F_6 ( & V_31 -> V_214 ) ;
F_6 ( & V_31 -> V_212 ) ;
V_40 = F_104 ( V_31 -> V_31 . V_211 ) ;
if ( V_40 )
F_24 ( L_64 ,
V_18 , V_40 ) ;
F_91 ( V_31 ) ;
}
}
static void
F_105 ( struct V_200 * V_201 )
{
struct V_30 * V_31 ;
int V_40 ;
while ( ! F_4 ( & V_201 -> V_215 ) ) {
V_31 = F_5 ( V_201 -> V_215 . V_7 , struct V_30 , V_214 ) ;
F_6 ( & V_31 -> V_214 ) ;
F_6 ( & V_31 -> V_212 ) ;
V_40 = F_65 ( V_31 -> V_31 . V_32 . V_218 ) ;
if ( V_40 )
F_24 ( L_65 ,
V_18 , V_40 ) ;
F_106 ( V_31 -> V_31 . V_32 . V_219 ) ;
F_91 ( V_31 ) ;
}
}
void
F_100 ( struct V_200 * V_201 )
{
struct V_66 * V_67 = F_28 ( V_201 ) ;
int V_209 ;
F_24 ( L_34 , V_18 ) ;
for ( V_209 = 0 ; V_209 < V_201 -> V_116 ; V_209 ++ ) {
if ( V_201 -> V_225 )
F_101 ( V_67 , V_201 -> V_225 [ V_209 ] ) ;
if ( V_201 -> V_224 )
F_102 ( V_67 , V_201 -> V_224 [ V_209 ] ) ;
}
switch ( V_67 -> V_114 ) {
case V_137 :
F_105 ( V_201 ) ;
break;
case V_139 :
F_103 ( V_201 ) ;
break;
default:
break;
}
F_91 ( V_201 -> V_223 ) ;
}
static void
F_80 ( struct V_66 * V_67 )
{
struct V_64 * V_195 =
F_81 ( V_67 , struct V_64 , V_68 ) ;
struct V_200 * V_201 = & V_195 -> V_115 ;
struct V_10 * V_228 ;
struct V_30 * V_31 ;
F_37 ( V_229 ) ;
int V_40 ;
F_107 (pos, &buf->rb_all) {
V_31 = F_5 ( V_228 , struct V_30 , V_214 ) ;
F_34 ( & V_229 ) ;
F_94 ( & V_31 -> V_31 . V_211 -> V_230 , & V_229 ) ;
V_40 = F_108 ( & V_229 ) ;
if ( V_40 )
F_24 ( L_66 ,
V_18 , V_40 ) ;
}
}
static void
F_79 ( struct V_66 * V_67 )
{
struct V_64 * V_195 =
F_81 ( V_67 , struct V_64 , V_68 ) ;
struct V_200 * V_201 = & V_195 -> V_115 ;
struct V_10 * V_228 ;
struct V_30 * V_31 ;
int V_40 ;
F_107 (pos, &buf->rb_all) {
V_31 = F_5 ( V_228 , struct V_30 , V_214 ) ;
if ( V_31 -> V_31 . V_32 . V_33 == V_231 )
continue;
V_40 = F_65 ( V_31 -> V_31 . V_32 . V_218 ) ;
if ( V_40 )
F_24 ( L_65 ,
V_18 , V_40 ) ;
F_106 ( V_31 -> V_31 . V_32 . V_219 ) ;
V_31 -> V_31 . V_32 . V_218 = F_96 ( V_67 -> V_129 ,
V_67 -> V_140 ) ;
if ( F_48 ( V_31 -> V_31 . V_32 . V_218 ) ) {
V_40 = F_49 ( V_31 -> V_31 . V_32 . V_218 ) ;
F_24 ( L_67
L_68 , V_18 , V_40 ) ;
continue;
}
V_31 -> V_31 . V_32 . V_219 = F_97 (
V_67 -> V_53 -> V_19 ,
V_67 -> V_140 ) ;
if ( F_48 ( V_31 -> V_31 . V_32 . V_219 ) ) {
V_40 = F_49 ( V_31 -> V_31 . V_32 . V_219 ) ;
F_24 ( L_69
L_70
L_58 , V_18 , V_40 ) ;
F_65 ( V_31 -> V_31 . V_32 . V_218 ) ;
continue;
}
V_31 -> V_31 . V_32 . V_33 = V_231 ;
}
}
static void
F_109 ( struct V_30 * * V_232 , struct V_200 * V_201 )
{
if ( * V_232 ) {
F_32 ( & ( * V_232 ) -> V_212 , & V_201 -> V_213 ) ;
* V_232 = NULL ;
}
}
static void
F_110 ( struct V_194 * V_196 , struct V_200 * V_201 )
{
struct V_233 * V_234 = V_196 -> V_235 ;
struct V_233 * V_236 = V_234 ;
int V_209 ;
for ( V_209 = 1 , V_234 ++ ; V_209 < V_210 ; V_234 ++ , V_209 ++ )
F_109 ( & V_234 -> V_237 , V_201 ) ;
F_109 ( & V_236 -> V_237 , V_201 ) ;
}
static void
F_111 ( struct V_194 * V_196 , struct V_200 * V_201 )
{
V_201 -> V_224 [ -- V_201 -> V_238 ] = V_196 ;
V_196 -> V_239 = 0 ;
if ( V_196 -> V_240 ) {
V_201 -> V_225 [ -- V_201 -> V_241 ] = V_196 -> V_240 ;
V_196 -> V_240 -> V_9 = NULL ;
V_196 -> V_240 = NULL ;
}
}
static void
F_112 ( struct V_30 * V_31 , struct V_66 * V_67 )
{
struct V_64 * V_195 =
F_81 ( V_67 , struct V_64 , V_68 ) ;
struct V_242 V_243 , * V_244 ;
int V_40 ;
F_24 ( L_71 , V_18 , V_31 ) ;
V_31 -> V_31 . V_32 . V_33 = V_231 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_28 = ( unsigned long ) ( void * ) V_31 ;
V_243 . V_48 = V_245 ;
V_243 . V_246 . V_247 = V_31 -> V_31 . V_32 . V_218 -> V_248 ;
F_113 ( & V_195 -> V_69 ) ;
F_24 ( L_72 ,
V_18 , V_31 , V_31 -> V_31 . V_32 . V_218 -> V_248 ) ;
F_114 ( & V_67 -> V_151 ) ;
V_40 = F_115 ( V_67 -> V_53 -> V_90 , & V_243 , & V_244 ) ;
F_116 ( & V_67 -> V_151 ) ;
if ( V_40 ) {
V_31 -> V_31 . V_32 . V_33 = V_34 ;
F_24 ( L_73 ,
V_18 , V_40 ) ;
}
}
static void
F_117 ( struct V_10 * V_249 ,
struct V_200 * V_201 )
{
struct V_66 * V_67 = F_28 ( V_201 ) ;
struct V_10 * V_228 ;
struct V_30 * V_31 ;
unsigned long V_4 ;
F_107 (pos, stale) {
V_31 = F_5 ( V_228 , struct V_30 , V_212 ) ;
F_112 ( V_31 , V_67 ) ;
}
F_3 ( & V_201 -> V_222 , V_4 ) ;
F_10 ( V_249 , & V_201 -> V_213 ) ;
F_7 ( & V_201 -> V_222 , V_4 ) ;
}
static struct V_194 *
F_118 ( struct V_194 * V_196 , struct V_200 * V_201 ,
struct V_10 * V_249 )
{
struct V_30 * V_31 ;
int V_209 ;
V_209 = V_210 - 1 ;
while ( ! F_4 ( & V_201 -> V_213 ) ) {
V_31 = F_5 ( V_201 -> V_213 . V_7 ,
struct V_30 , V_212 ) ;
F_6 ( & V_31 -> V_212 ) ;
if ( V_31 -> V_31 . V_32 . V_33 == V_34 ) {
F_94 ( & V_31 -> V_212 , V_249 ) ;
continue;
}
V_196 -> V_235 [ V_209 ] . V_237 = V_31 ;
if ( F_119 ( V_209 -- == 0 ) )
return V_196 ;
}
F_111 ( V_196 , V_201 ) ;
F_110 ( V_196 , V_201 ) ;
return NULL ;
}
static struct V_194 *
F_120 ( struct V_194 * V_196 , struct V_200 * V_201 )
{
struct V_30 * V_31 ;
int V_209 ;
V_209 = V_210 - 1 ;
while ( ! F_4 ( & V_201 -> V_213 ) ) {
V_31 = F_5 ( V_201 -> V_213 . V_7 ,
struct V_30 , V_212 ) ;
F_6 ( & V_31 -> V_212 ) ;
V_196 -> V_235 [ V_209 ] . V_237 = V_31 ;
if ( F_119 ( V_209 -- == 0 ) )
return V_196 ;
}
F_111 ( V_196 , V_201 ) ;
F_110 ( V_196 , V_201 ) ;
return NULL ;
}
struct V_194 *
F_121 ( struct V_200 * V_250 )
{
struct V_66 * V_67 = F_28 ( V_250 ) ;
struct V_10 V_249 ;
struct V_194 * V_196 ;
unsigned long V_4 ;
F_3 ( & V_250 -> V_222 , V_4 ) ;
if ( V_250 -> V_238 == V_250 -> V_116 ) {
F_7 ( & V_250 -> V_222 , V_4 ) ;
F_24 ( L_74 , V_18 ) ;
return ( (struct V_194 * ) NULL ) ;
}
V_196 = V_250 -> V_224 [ V_250 -> V_238 ] ;
if ( V_250 -> V_238 < V_250 -> V_241 ) {
F_24 ( L_75 ,
V_18 ,
V_250 -> V_241 - V_250 -> V_238 ) ;
V_196 -> V_240 = NULL ;
} else {
V_196 -> V_240 = V_250 -> V_225 [ V_250 -> V_241 ] ;
V_250 -> V_225 [ V_250 -> V_241 ++ ] = NULL ;
}
V_250 -> V_224 [ V_250 -> V_238 ++ ] = NULL ;
F_34 ( & V_249 ) ;
switch ( V_67 -> V_114 ) {
case V_137 :
V_196 = F_118 ( V_196 , V_250 , & V_249 ) ;
break;
case V_139 :
V_196 = F_120 ( V_196 , V_250 ) ;
break;
default:
break;
}
F_7 ( & V_250 -> V_222 , V_4 ) ;
if ( ! F_4 ( & V_249 ) )
F_117 ( & V_249 , V_250 ) ;
return V_196 ;
}
void
F_122 ( struct V_194 * V_196 )
{
struct V_200 * V_250 = V_196 -> V_197 ;
struct V_66 * V_67 = F_28 ( V_250 ) ;
unsigned long V_4 ;
F_3 ( & V_250 -> V_222 , V_4 ) ;
F_111 ( V_196 , V_250 ) ;
switch ( V_67 -> V_114 ) {
case V_137 :
case V_139 :
F_110 ( V_196 , V_250 ) ;
break;
default:
break;
}
F_7 ( & V_250 -> V_222 , V_4 ) ;
}
void
F_123 ( struct V_194 * V_196 )
{
struct V_200 * V_250 = V_196 -> V_197 ;
unsigned long V_4 ;
F_3 ( & V_250 -> V_222 , V_4 ) ;
if ( V_250 -> V_241 < V_250 -> V_116 ) {
V_196 -> V_240 = V_250 -> V_225 [ V_250 -> V_241 ] ;
V_250 -> V_225 [ V_250 -> V_241 ++ ] = NULL ;
}
F_7 ( & V_250 -> V_222 , V_4 ) ;
}
void
F_8 ( struct V_2 * V_3 )
{
struct V_200 * V_250 = V_3 -> V_52 ;
unsigned long V_4 ;
V_3 -> V_9 = NULL ;
F_3 ( & V_250 -> V_222 , V_4 ) ;
V_250 -> V_225 [ -- V_250 -> V_241 ] = V_3 ;
F_7 ( & V_250 -> V_222 , V_4 ) ;
}
static int
F_124 ( struct V_66 * V_67 , void * V_251 , int V_221 ,
struct V_252 * * V_253 , struct V_254 * V_255 )
{
struct V_256 V_257 ;
struct V_252 * V_258 ;
int V_40 ;
V_255 -> V_72 = F_125 ( V_67 -> V_53 -> V_19 ,
V_251 , V_221 , V_259 ) ;
if ( F_126 ( V_67 -> V_53 -> V_19 , V_255 -> V_72 ) )
return - V_149 ;
V_255 -> V_260 = V_221 ;
if ( V_67 -> V_134 ) {
* V_253 = NULL ;
V_255 -> V_261 = V_67 -> V_135 ;
return 0 ;
} else if ( V_67 -> V_147 != NULL ) {
* V_253 = NULL ;
V_255 -> V_261 = V_67 -> V_147 -> V_261 ;
return 0 ;
}
V_257 . V_72 = V_255 -> V_72 ;
V_257 . V_262 = V_255 -> V_260 ;
V_258 = F_127 ( V_67 -> V_129 , & V_257 , 1 ,
V_143 , & V_255 -> V_72 ) ;
F_24 ( L_76
L_77 ,
V_18 , ( unsigned long long ) V_257 . V_72 ,
( unsigned long long ) V_255 -> V_72 , V_221 ) ;
if ( F_48 ( V_258 ) ) {
* V_253 = NULL ;
V_40 = F_49 ( V_258 ) ;
F_24 ( L_78 , V_18 , V_40 ) ;
} else {
* V_253 = V_258 ;
V_255 -> V_261 = V_258 -> V_261 ;
V_40 = 0 ;
}
return V_40 ;
}
static int
F_128 ( struct V_66 * V_67 ,
struct V_252 * V_258 , struct V_254 * V_255 )
{
int V_40 ;
F_129 ( V_67 -> V_53 -> V_19 ,
V_255 -> V_72 , V_255 -> V_260 , V_259 ) ;
if ( NULL == V_258 )
return 0 ;
V_40 = F_65 ( V_258 ) ;
if ( V_40 )
F_24 ( L_65 , V_18 , V_40 ) ;
return V_40 ;
}
struct V_263 *
F_68 ( struct V_66 * V_67 , T_1 V_262 , T_2 V_4 )
{
struct V_263 * V_264 ;
int V_40 ;
V_40 = - V_149 ;
V_264 = F_130 ( sizeof( * V_264 ) + V_262 , V_4 ) ;
if ( V_264 == NULL )
goto V_122;
V_264 -> V_265 = V_262 ;
V_264 -> V_266 = NULL ;
V_40 = F_124 ( V_67 , V_264 -> V_267 , V_262 ,
& V_264 -> V_268 , & V_264 -> V_269 ) ;
if ( V_40 )
goto V_199;
return V_264 ;
V_199:
F_91 ( V_264 ) ;
V_122:
return F_55 ( V_40 ) ;
}
void
F_74 ( struct V_66 * V_67 , struct V_263 * V_264 )
{
if ( V_264 ) {
F_128 ( V_67 , V_264 -> V_268 , & V_264 -> V_269 ) ;
F_91 ( V_264 ) ;
}
}
static void
F_131 ( struct V_66 * V_67 , struct V_233 * V_234 , int V_270 )
{
V_234 -> V_271 = V_270 ? V_55 : V_272 ;
V_234 -> V_273 = V_234 -> V_274 ;
if ( V_234 -> V_275 )
V_234 -> V_276 = F_132 ( V_67 -> V_53 -> V_19 ,
V_234 -> V_275 , F_133 ( V_234 -> V_277 ) ,
V_234 -> V_273 , V_234 -> V_271 ) ;
else
V_234 -> V_276 = F_125 ( V_67 -> V_53 -> V_19 ,
V_234 -> V_277 ,
V_234 -> V_273 , V_234 -> V_271 ) ;
if ( F_126 ( V_67 -> V_53 -> V_19 , V_234 -> V_276 ) ) {
F_24 ( L_79 ,
V_18 ,
( unsigned long long ) V_234 -> V_276 ,
V_234 -> V_277 , V_234 -> V_273 ) ;
}
}
static void
F_134 ( struct V_66 * V_67 , struct V_233 * V_234 )
{
if ( V_234 -> V_275 )
F_135 ( V_67 -> V_53 -> V_19 ,
V_234 -> V_276 , V_234 -> V_273 , V_234 -> V_271 ) ;
else
F_129 ( V_67 -> V_53 -> V_19 ,
V_234 -> V_276 , V_234 -> V_273 , V_234 -> V_271 ) ;
}
static int
F_136 ( struct V_233 * V_234 ,
int * V_278 , int V_270 , struct V_66 * V_67 ,
struct V_64 * V_195 )
{
struct V_233 * V_236 = V_234 ;
struct V_30 * V_232 = V_236 -> V_237 ;
struct V_216 * V_32 = & V_232 -> V_31 . V_32 ;
struct V_252 * V_258 = V_32 -> V_218 ;
struct V_242 V_279 , * V_244 ;
T_3 V_280 ;
int V_221 , V_281 ;
int V_209 , V_40 ;
int V_282 ;
T_4 V_283 ;
int V_284 ;
V_281 = F_133 ( V_236 -> V_277 ) ;
V_236 -> V_277 -= V_281 ;
V_236 -> V_274 += V_281 ;
V_221 = - V_281 ;
if ( * V_278 > V_67 -> V_140 )
* V_278 = V_67 -> V_140 ;
for ( V_284 = V_209 = 0 ; V_209 < * V_278 ; ) {
F_131 ( V_67 , V_234 , V_270 ) ;
V_283 = V_234 -> V_276 ;
for ( V_282 = V_234 -> V_274 ; V_282 > 0 ; V_282 -= V_285 ) {
V_32 -> V_219 -> V_286 [ V_284 ++ ] = V_283 ;
V_283 += V_285 ;
}
V_221 += V_234 -> V_274 ;
++ V_234 ;
++ V_209 ;
if ( ( V_209 < * V_278 && F_133 ( V_234 -> V_277 ) ) ||
F_133 ( ( V_234 - 1 ) -> V_277 + ( V_234 - 1 ) -> V_274 ) )
break;
}
F_24 ( L_80 ,
V_18 , V_232 , V_209 ) ;
V_32 -> V_33 = V_287 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_28 = ( unsigned long ) ( void * ) V_232 ;
V_279 . V_48 = V_288 ;
V_279 . V_289 . V_290 . V_291 = V_236 -> V_276 ;
V_279 . V_289 . V_290 . V_286 = V_32 -> V_219 ;
V_279 . V_289 . V_290 . V_292 = V_284 ;
V_279 . V_289 . V_290 . V_207 = V_208 ;
V_279 . V_289 . V_290 . V_260 = V_284 << V_208 ;
if ( V_279 . V_289 . V_290 . V_260 < V_221 ) {
V_40 = - V_22 ;
goto V_293;
}
V_280 = ( T_3 ) ( V_258 -> V_248 & 0x000000FF ) ;
F_137 ( V_258 , ++ V_280 ) ;
V_279 . V_289 . V_290 . V_294 = ( V_270 ?
V_144 | V_143 :
V_145 ) ;
V_279 . V_289 . V_290 . V_248 = V_258 -> V_248 ;
F_113 ( & V_195 -> V_69 ) ;
V_40 = F_115 ( V_67 -> V_53 -> V_90 , & V_279 , & V_244 ) ;
if ( V_40 ) {
F_24 ( L_81
L_82 , V_18 , V_40 ) ;
F_137 ( V_258 , -- V_280 ) ;
goto V_293;
} else {
V_236 -> V_295 = V_258 -> V_248 ;
V_236 -> V_296 = V_236 -> V_276 + V_281 ;
V_236 -> V_297 = V_209 ;
V_236 -> V_274 = V_221 ;
}
* V_278 = V_209 ;
return 0 ;
V_293:
V_32 -> V_33 = V_231 ;
while ( V_209 -- )
F_134 ( V_67 , -- V_234 ) ;
return V_40 ;
}
static int
F_138 ( struct V_233 * V_234 ,
struct V_66 * V_67 , struct V_64 * V_195 )
{
struct V_233 * V_236 = V_234 ;
struct V_242 V_243 , * V_244 ;
int V_40 ;
V_236 -> V_237 -> V_31 . V_32 . V_33 = V_231 ;
memset ( & V_243 , 0 , sizeof V_243 ) ;
V_243 . V_28 = ( unsigned long ) ( void * ) V_236 -> V_237 ;
V_243 . V_48 = V_245 ;
V_243 . V_246 . V_247 = V_236 -> V_237 -> V_31 . V_32 . V_218 -> V_248 ;
F_113 ( & V_195 -> V_69 ) ;
F_114 ( & V_67 -> V_151 ) ;
while ( V_236 -> V_297 -- )
F_134 ( V_67 , V_234 ++ ) ;
V_40 = F_115 ( V_67 -> V_53 -> V_90 , & V_243 , & V_244 ) ;
F_116 ( & V_67 -> V_151 ) ;
if ( V_40 ) {
V_236 -> V_237 -> V_31 . V_32 . V_33 = V_34 ;
F_24 ( L_83
L_82 , V_18 , V_40 ) ;
}
return V_40 ;
}
static int
F_139 ( struct V_233 * V_234 ,
int * V_278 , int V_270 , struct V_66 * V_67 )
{
struct V_233 * V_236 = V_234 ;
T_4 V_298 [ V_165 ] ;
int V_221 , V_281 , V_209 , V_40 ;
V_281 = F_133 ( V_236 -> V_277 ) ;
V_236 -> V_277 -= V_281 ;
V_236 -> V_274 += V_281 ;
V_221 = - V_281 ;
if ( * V_278 > V_165 )
* V_278 = V_165 ;
for ( V_209 = 0 ; V_209 < * V_278 ; ) {
F_131 ( V_67 , V_234 , V_270 ) ;
V_298 [ V_209 ] = V_234 -> V_276 ;
V_221 += V_234 -> V_274 ;
++ V_234 ;
++ V_209 ;
if ( ( V_209 < * V_278 && F_133 ( V_234 -> V_277 ) ) ||
F_133 ( ( V_234 - 1 ) -> V_277 + ( V_234 - 1 ) -> V_274 ) )
break;
}
V_40 = F_140 ( V_236 -> V_237 -> V_31 . V_211 , V_298 , V_209 , V_236 -> V_276 ) ;
if ( V_40 ) {
F_24 ( L_84
L_85 , V_18 ,
V_221 , ( unsigned long long ) V_236 -> V_276 ,
V_281 , V_209 , V_40 ) ;
while ( V_209 -- )
F_134 ( V_67 , -- V_234 ) ;
} else {
V_236 -> V_295 = V_236 -> V_237 -> V_31 . V_211 -> V_248 ;
V_236 -> V_296 = V_236 -> V_276 + V_281 ;
V_236 -> V_297 = V_209 ;
V_236 -> V_274 = V_221 ;
}
* V_278 = V_209 ;
return V_40 ;
}
static int
F_141 ( struct V_233 * V_234 ,
struct V_66 * V_67 )
{
struct V_233 * V_236 = V_234 ;
F_37 ( V_229 ) ;
int V_40 ;
F_94 ( & V_236 -> V_237 -> V_31 . V_211 -> V_230 , & V_229 ) ;
V_40 = F_108 ( & V_229 ) ;
F_114 ( & V_67 -> V_151 ) ;
while ( V_236 -> V_297 -- )
F_134 ( V_67 , V_234 ++ ) ;
F_116 ( & V_67 -> V_151 ) ;
if ( V_40 )
F_24 ( L_86
L_82 , V_18 , V_40 ) ;
return V_40 ;
}
int
F_142 ( struct V_233 * V_234 ,
int V_278 , int V_270 , struct V_64 * V_195 )
{
struct V_66 * V_67 = & V_195 -> V_68 ;
int V_40 = 0 ;
switch ( V_67 -> V_114 ) {
case V_142 :
F_131 ( V_67 , V_234 , V_270 ) ;
V_234 -> V_295 = V_67 -> V_147 -> V_248 ;
V_234 -> V_296 = V_234 -> V_276 ;
V_234 -> V_297 = 1 ;
V_278 = 1 ;
break;
case V_137 :
V_40 = F_136 ( V_234 , & V_278 , V_270 , V_67 , V_195 ) ;
break;
case V_139 :
V_40 = F_139 ( V_234 , & V_278 , V_270 , V_67 ) ;
break;
default:
return - V_22 ;
}
if ( V_40 )
return V_40 ;
return V_278 ;
}
int
F_143 ( struct V_233 * V_234 ,
struct V_64 * V_195 )
{
struct V_66 * V_67 = & V_195 -> V_68 ;
int V_278 = V_234 -> V_297 , V_40 ;
switch ( V_67 -> V_114 ) {
case V_142 :
F_114 ( & V_67 -> V_151 ) ;
F_134 ( V_67 , V_234 ) ;
F_116 ( & V_67 -> V_151 ) ;
break;
case V_137 :
V_40 = F_138 ( V_234 , V_67 , V_195 ) ;
break;
case V_139 :
V_40 = F_141 ( V_234 , V_67 ) ;
break;
default:
break;
}
return V_278 ;
}
int
F_144 ( struct V_66 * V_67 ,
struct V_16 * V_17 ,
struct V_194 * V_196 )
{
struct V_242 V_299 , * V_300 ;
struct V_2 * V_3 = V_196 -> V_240 ;
int V_40 ;
if ( V_3 ) {
V_40 = F_145 ( V_67 , V_17 , V_3 ) ;
if ( V_40 )
goto V_122;
V_196 -> V_240 = NULL ;
}
V_299 . V_7 = NULL ;
V_299 . V_28 = 0ULL ;
V_299 . V_301 = V_196 -> V_302 ;
V_299 . V_303 = V_196 -> V_239 ;
V_299 . V_48 = V_304 ;
if ( V_299 . V_303 == 4 )
F_146 ( V_67 -> V_53 -> V_19 ,
V_196 -> V_302 [ 3 ] . V_72 , V_196 -> V_302 [ 3 ] . V_260 ,
V_272 ) ;
F_146 ( V_67 -> V_53 -> V_19 ,
V_196 -> V_302 [ 1 ] . V_72 , V_196 -> V_302 [ 1 ] . V_260 ,
V_272 ) ;
F_146 ( V_67 -> V_53 -> V_19 ,
V_196 -> V_302 [ 0 ] . V_72 , V_196 -> V_302 [ 0 ] . V_260 ,
V_272 ) ;
if ( F_113 ( V_17 ) > 0 )
V_299 . V_305 = 0 ;
else {
F_69 ( V_17 ) ;
V_299 . V_305 = V_306 ;
}
V_40 = F_115 ( V_67 -> V_53 -> V_90 , & V_299 , & V_300 ) ;
if ( V_40 )
F_24 ( L_87 , V_18 ,
V_40 ) ;
V_122:
return V_40 ;
}
int
F_145 ( struct V_66 * V_67 ,
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_307 V_308 , * V_309 ;
int V_40 ;
V_308 . V_7 = NULL ;
V_308 . V_28 = ( T_4 ) ( unsigned long ) V_3 ;
V_308 . V_301 = & V_3 -> V_54 -> V_269 ;
V_308 . V_303 = 1 ;
F_27 ( V_67 -> V_53 -> V_19 ,
F_29 ( V_3 -> V_54 ) ,
F_147 ( V_3 -> V_54 ) ,
V_259 ) ;
V_40 = F_148 ( V_67 -> V_53 -> V_90 , & V_308 , & V_309 ) ;
if ( V_40 )
F_24 ( L_88 , V_18 ,
V_40 ) ;
return V_40 ;
}
static T_1
F_149 ( struct V_64 * V_195 )
{
struct V_152 * V_153 = & V_195 -> V_192 ;
unsigned int V_310 , V_311 ;
V_310 = F_60 (unsigned int,
cdata->inline_wsize, cdata->inline_rsize) ;
V_310 -= V_312 ;
V_311 = V_310 / sizeof( struct V_313 ) ;
return V_311 << V_208 ;
}
static T_1
F_150 ( struct V_64 * V_195 )
{
return V_165 << V_208 ;
}
T_1
F_151 ( struct V_64 * V_195 )
{
T_1 V_314 ;
switch ( V_195 -> V_68 . V_114 ) {
case V_142 :
V_314 = F_149 ( V_195 ) ;
break;
default:
V_314 = F_150 ( V_195 ) ;
}
return V_314 ;
}
