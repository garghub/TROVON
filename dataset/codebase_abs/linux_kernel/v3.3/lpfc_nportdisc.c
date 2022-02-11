static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_5 * V_7 )
{
if ( memcmp ( V_6 , & V_4 -> V_8 , sizeof ( struct V_5 ) ) )
return 0 ;
if ( memcmp ( V_7 , & V_4 -> V_9 , sizeof ( struct V_5 ) ) )
return 0 ;
return 1 ;
}
int
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_10 * V_11 , T_1 V_12 , int V_13 )
{
volatile struct V_10 * V_14 = & V_2 -> V_15 ;
T_2 V_16 , V_17 = 0 ;
if ( V_11 -> V_18 . V_19 ) {
if ( ! V_13 ) {
V_16 = ( ( V_14 -> V_18 . V_20 << 8 ) |
V_14 -> V_18 . V_21 ) ;
V_17 = ( ( V_11 -> V_18 . V_20 << 8 ) |
V_11 -> V_18 . V_21 ) ;
if ( ! V_17 )
goto V_22;
if ( V_17 > V_16 ) {
V_11 -> V_18 . V_21 =
V_14 -> V_18 . V_21 ;
V_11 -> V_18 . V_20 =
V_14 -> V_18 . V_20 ;
}
}
} else if ( V_12 == V_23 )
goto V_22;
if ( V_11 -> V_24 . V_19 ) {
if ( ! V_13 ) {
V_16 = ( ( V_14 -> V_24 . V_20 << 8 ) |
V_14 -> V_24 . V_21 ) ;
V_17 = ( ( V_11 -> V_24 . V_20 << 8 ) |
V_11 -> V_24 . V_21 ) ;
if ( ! V_17 )
goto V_22;
if ( V_17 > V_16 ) {
V_11 -> V_24 . V_21 =
V_14 -> V_24 . V_21 ;
V_11 -> V_24 . V_20 =
V_14 -> V_24 . V_20 ;
}
}
} else if ( V_12 == V_25 )
goto V_22;
if ( V_11 -> V_26 . V_19 ) {
if ( ! V_13 ) {
V_16 = ( ( V_14 -> V_26 . V_20 << 8 ) |
V_14 -> V_26 . V_21 ) ;
V_17 = ( ( V_11 -> V_26 . V_20 << 8 ) |
V_11 -> V_26 . V_21 ) ;
if ( ! V_17 )
goto V_22;
if ( V_17 > V_16 ) {
V_11 -> V_26 . V_21 =
V_14 -> V_26 . V_21 ;
V_11 -> V_26 . V_20 =
V_14 -> V_26 . V_20 ;
}
}
} else if ( V_12 == V_27 )
goto V_22;
V_16 = ( V_14 -> V_28 . V_29 << 8 ) | V_14 -> V_28 . V_30 ;
V_17 = ( V_11 -> V_28 . V_29 << 8 ) | V_11 -> V_28 . V_30 ;
if ( V_17 > V_16 ) {
V_11 -> V_28 . V_30 = V_14 -> V_28 . V_30 ;
V_11 -> V_28 . V_29 = ( V_11 -> V_28 . V_29 & 0xF0 ) |
( V_14 -> V_28 . V_29 & 0x0F ) ;
}
memcpy ( & V_4 -> V_8 , & V_11 -> V_31 , sizeof ( struct V_5 ) ) ;
memcpy ( & V_4 -> V_9 , & V_11 -> V_32 , sizeof ( struct V_5 ) ) ;
return 1 ;
V_22:
F_3 ( V_2 , V_33 , V_34 ,
L_1
L_2
L_3 ,
V_4 -> V_35 ,
V_11 -> V_31 . V_36 . V_37 [ 0 ] , V_11 -> V_31 . V_36 . V_37 [ 1 ] ,
V_11 -> V_31 . V_36 . V_37 [ 2 ] , V_11 -> V_31 . V_36 . V_37 [ 3 ] ,
V_11 -> V_31 . V_36 . V_37 [ 4 ] , V_11 -> V_31 . V_36 . V_37 [ 5 ] ,
V_11 -> V_31 . V_36 . V_37 [ 6 ] , V_11 -> V_31 . V_36 . V_37 [ 7 ] ) ;
return 0 ;
}
static void *
F_4 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_40 * V_42 )
{
struct V_43 * V_44 , * V_45 ;
T_1 * V_46 ;
void * V_47 = NULL ;
T_3 * V_48 ;
V_48 = & V_42 -> V_49 ;
V_44 = (struct V_43 * ) V_41 -> V_50 ;
if ( V_44 ) {
V_45 = F_5 ( & V_44 -> V_51 , struct V_43 ,
V_51 ) ;
if ( V_45 ) {
V_46 = ( T_1 * ) V_45 -> V_52 ;
V_47 = ( void * ) ( ( V_53 * ) V_46 + sizeof( T_1 ) ) ;
}
} else {
if ( ! ( V_48 -> V_54 ) ) {
V_48 -> V_54 = V_55 ;
V_48 -> V_56 . V_57 [ 4 ] = V_58 ;
}
V_47 = NULL ;
}
return V_47 ;
}
int
F_6 ( struct V_38 * V_39 , struct V_3 * V_4 )
{
F_7 ( V_59 ) ;
F_7 ( V_60 ) ;
F_7 ( V_61 ) ;
struct V_62 * V_63 = & V_39 -> V_64 ;
struct V_65 * V_66 = & V_63 -> V_67 [ V_68 ] ;
struct V_40 * V_49 , * V_69 ;
F_3 ( V_4 -> V_2 , V_70 , V_34 ,
L_4
L_5 ,
V_4 -> V_35 , V_4 -> V_71 , V_4 -> V_72 ,
V_4 -> V_73 ) ;
F_8 ( V_4 ) ;
F_9 ( & V_39 -> V_74 ) ;
F_10 (iocb, next_iocb, &pring->txq, list) {
if ( F_11 ( V_39 , V_66 , V_49 , V_4 ) ) {
F_12 ( & V_49 -> V_51 , & V_59 ) ;
V_66 -> V_75 -- ;
}
}
F_13 ( & V_66 -> V_76 , & V_60 ) ;
F_14 ( & V_39 -> V_74 ) ;
F_10 (iocb, next_iocb, &txcmplq_completions, list) {
if ( F_11 ( V_39 , V_66 , V_49 , V_4 ) )
F_15 ( & V_49 -> V_77 , & V_61 ) ;
}
F_9 ( & V_39 -> V_74 ) ;
F_16 ( & V_60 , & V_66 -> V_76 ) ;
F_14 ( & V_39 -> V_74 ) ;
F_10 (iocb, next_iocb, &abort_list, dlist) {
F_9 ( & V_39 -> V_74 ) ;
F_17 ( & V_49 -> V_77 ) ;
F_18 ( V_39 , V_66 , V_49 ) ;
F_14 ( & V_39 -> V_74 ) ;
}
F_19 ( V_39 , & V_59 , V_55 ,
V_58 ) ;
F_20 ( V_39 -> V_78 , V_4 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_43 * V_44 ;
T_1 * V_46 ;
T_3 * V_81 ;
struct V_10 * V_11 ;
T_4 * V_82 ;
struct V_83 V_84 ;
int V_85 ;
memset ( & V_84 , 0 , sizeof ( struct V_83 ) ) ;
if ( V_2 -> V_86 <= V_87 ) {
if ( V_2 -> V_88 & V_89 ) {
F_23 ( V_39 ) ;
if ( ! ( V_2 -> V_88 & V_90 ) ) {
V_39 -> V_91 = V_92 ;
V_39 -> V_93 = V_94 ;
F_24 ( V_2 ) ;
} else
F_25 ( V_2 ) ;
} else {
V_84 . V_56 . V_95 . V_96 = V_97 ;
V_84 . V_56 . V_95 . V_98 = V_99 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 ,
V_4 , NULL ) ;
return 0 ;
}
}
V_44 = (struct V_43 * ) V_41 -> V_50 ;
V_46 = ( T_1 * ) V_44 -> V_52 ;
V_11 = (struct V_10 * ) ( ( V_53 * ) V_46 + sizeof ( T_1 ) ) ;
if ( F_27 ( V_11 -> V_32 . V_36 . V_37 ) == 0 ) {
F_3 ( V_2 , V_33 , V_101 ,
L_6 ) ;
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_103 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 ,
NULL ) ;
return 0 ;
}
if ( F_27 ( V_11 -> V_31 . V_36 . V_37 ) == 0 ) {
F_3 ( V_2 , V_33 , V_101 ,
L_7 ) ;
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_104 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 ,
NULL ) ;
return 0 ;
}
if ( ( F_2 ( V_2 , V_4 , V_11 , V_27 , 0 ) == 0 ) ) {
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_105 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 ,
NULL ) ;
return 0 ;
}
V_81 = & V_41 -> V_49 ;
F_3 ( V_2 , V_70 , V_101 ,
L_8 ,
V_4 -> V_35 , V_4 -> V_72 , V_4 -> V_71 ,
V_4 -> V_73 ) ;
if ( V_2 -> V_106 == 2 && V_11 -> V_24 . V_19 )
V_4 -> V_107 |= V_25 ;
else
V_4 -> V_107 |= V_27 ;
V_4 -> V_108 = 0 ;
if ( V_11 -> V_18 . V_19 )
V_4 -> V_108 |= V_109 ;
if ( V_11 -> V_24 . V_19 )
V_4 -> V_108 |= V_110 ;
if ( V_11 -> V_26 . V_19 )
V_4 -> V_108 |= V_111 ;
if ( V_11 -> V_112 . V_19 )
V_4 -> V_108 |= V_113 ;
V_4 -> V_114 =
( ( V_11 -> V_28 . V_29 & 0x0F ) << 8 ) | V_11 -> V_28 . V_30 ;
switch ( V_4 -> V_72 ) {
case V_115 :
if ( ! ( V_4 -> V_71 & V_116 ) )
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_28 ( V_2 , V_121 , V_41 , V_4 , NULL ) ;
return 1 ;
}
if ( ( V_2 -> V_88 & V_89 ) &&
! ( V_2 -> V_88 & V_90 ) ) {
V_2 -> V_122 = V_81 -> V_56 . V_123 . V_124 ;
V_82 = F_29 ( V_39 -> V_125 , V_126 ) ;
if ( V_82 == NULL )
goto V_127;
F_30 ( V_39 , V_82 ) ;
V_82 -> V_128 = V_129 ;
V_82 -> V_2 = V_2 ;
V_85 = F_31 ( V_39 , V_82 , V_130 ) ;
if ( V_85 == V_131 ) {
F_32 ( V_82 , V_39 -> V_125 ) ;
goto V_127;
}
F_33 ( V_2 ) ;
}
V_82 = F_29 ( V_39 -> V_125 , V_126 ) ;
if ( ! V_82 )
goto V_127;
V_85 = F_34 ( V_39 , V_2 -> V_132 , V_81 -> V_56 . V_123 . V_133 ,
( V_53 * ) V_11 , V_82 , V_4 -> V_73 ) ;
if ( V_85 ) {
F_32 ( V_82 , V_39 -> V_125 ) ;
goto V_127;
}
V_82 -> V_128 = V_134 ;
V_82 -> V_2 = V_2 ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= ( V_136 | V_137 ) ;
F_14 ( V_80 -> V_135 ) ;
if ( V_4 -> V_72 == V_138 ) {
F_6 ( V_39 , V_4 ) ;
}
if ( ( V_2 -> V_139 == V_140 &&
V_2 -> V_141 ) ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_142 ;
F_14 ( V_80 -> V_135 ) ;
V_84 . V_56 . V_95 . V_96 = V_143 ;
V_84 . V_56 . V_95 . V_98 = V_99 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 ,
V_4 , V_82 ) ;
return 1 ;
}
F_28 ( V_2 , V_121 , V_41 , V_4 , V_82 ) ;
return 1 ;
V_127:
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_144 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 , NULL ) ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_43 * V_44 ;
struct V_10 * V_11 ;
struct V_5 * V_145 , * V_146 ;
struct V_83 V_84 ;
T_5 * V_147 ;
T_3 * V_81 ;
T_1 * V_46 ;
T_1 V_148 ;
V_44 = (struct V_43 * ) V_41 -> V_50 ;
V_46 = ( T_1 * ) V_44 -> V_52 ;
V_148 = * V_46 ++ ;
if ( V_148 == V_149 ) {
V_147 = ( T_5 * ) V_46 ;
V_145 = (struct V_5 * ) & V_147 -> V_31 ;
V_146 = (struct V_5 * ) & V_147 -> V_32 ;
} else {
V_11 = (struct V_10 * ) V_46 ;
V_145 = (struct V_5 * ) & V_11 -> V_31 ;
V_146 = (struct V_5 * ) & V_11 -> V_32 ;
}
V_81 = & V_41 -> V_49 ;
if ( V_81 -> V_54 == 0 && F_1 ( V_2 , V_4 , V_145 , V_146 ) ) {
if ( V_148 == V_149 ) {
F_36 ( V_2 , V_41 , V_4 ) ;
} else {
F_28 ( V_2 , V_121 , V_41 , V_4 ,
NULL ) ;
}
return 1 ;
}
V_84 . V_56 . V_95 . V_150 = 0 ;
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_105 ;
V_84 . V_56 . V_95 . V_151 = 0 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 , NULL ) ;
F_37 ( & V_4 -> V_152 , V_153 + V_154 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
V_4 -> V_157 = V_4 -> V_72 ;
F_38 ( V_2 , V_4 , V_115 ) ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_40 * V_41 , T_1 V_158 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_1 * * V_159 ;
int V_160 , V_161 = 0 ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_162 ;
F_14 ( V_80 -> V_135 ) ;
if ( V_158 == V_163 )
F_28 ( V_2 , V_163 , V_41 , V_4 , NULL ) ;
else
F_28 ( V_2 , V_164 , V_41 , V_4 , NULL ) ;
if ( V_4 -> V_35 == V_165 ) {
if ( V_2 -> V_86 <= V_87 )
goto V_127;
F_40 ( V_2 ) ;
F_9 ( V_80 -> V_135 ) ;
V_2 -> V_88 |= V_166 ;
F_14 ( V_80 -> V_135 ) ;
V_159 = F_41 ( V_39 ) ;
if ( V_159 ) {
for ( V_160 = 0 ; V_160 <= V_39 -> V_167 && V_159 [ V_160 ] != NULL ;
V_160 ++ ) {
if ( ( ! ( V_159 [ V_160 ] -> V_88 &
V_166 ) ) &&
( V_159 [ V_160 ] -> V_86 > V_87 ) ) {
V_161 = 1 ;
break;
}
}
F_42 ( V_39 , V_159 ) ;
}
if ( V_161 ) {
F_37 ( & V_4 -> V_152 , V_153 + V_154 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_168 ;
V_2 -> V_86 = V_87 ;
} else {
F_9 ( V_80 -> V_135 ) ;
V_39 -> V_78 -> V_88 &= ~ V_169 ;
F_14 ( V_80 -> V_135 ) ;
F_43 ( V_39 ) ;
}
} else if ( ( ! ( V_4 -> V_170 & V_171 ) &&
( ( V_4 -> V_170 & V_172 ) ||
! ( V_4 -> V_170 & V_173 ) ) ) ||
( V_4 -> V_72 == V_174 ) ) {
F_37 ( & V_4 -> V_152 , V_153 + V_154 * 1 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
}
V_127:
V_4 -> V_157 = V_4 -> V_72 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ V_116 ;
F_14 ( V_80 -> V_135 ) ;
return 0 ;
}
static void
F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_43 * V_44 ;
T_1 * V_46 ;
T_6 * V_175 ;
struct V_176 * V_177 = V_4 -> V_177 ;
T_7 V_178 ;
V_44 = (struct V_43 * ) V_41 -> V_50 ;
V_46 = ( T_1 * ) V_44 -> V_52 ;
V_175 = ( T_6 * ) ( ( V_53 * ) V_46 + sizeof ( T_1 ) ) ;
V_4 -> V_170 &= ~ ( V_172 | V_173 ) ;
V_4 -> V_107 &= ~ V_179 ;
if ( V_175 -> V_180 == V_181 ) {
if ( V_175 -> V_182 )
V_4 -> V_170 |= V_173 ;
if ( V_175 -> V_183 )
V_4 -> V_170 |= V_172 ;
if ( V_175 -> V_184 )
V_4 -> V_107 |= V_179 ;
}
if ( V_177 ) {
V_178 = V_185 ;
if ( V_4 -> V_170 & V_173 )
V_178 |= V_186 ;
if ( V_4 -> V_170 & V_172 )
V_178 |= V_187 ;
F_45 ( V_2 , V_188 ,
L_9 ,
V_178 , V_4 -> V_35 , V_4 -> V_71 ) ;
F_46 ( V_177 , V_178 ) ;
}
}
static T_1
F_47 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( ! ( V_4 -> V_71 & V_189 ) ) {
V_4 -> V_71 &= ~ V_116 ;
return 0 ;
}
if ( ! ( V_2 -> V_88 & V_89 ) ) {
if ( ( V_2 -> V_190 && ( V_2 -> V_88 & V_191 ) ) ||
( ( V_4 -> V_107 & V_179 ) &&
( V_4 -> V_170 & V_172 ) ) ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_116 ;
F_14 ( V_80 -> V_135 ) ;
return 1 ;
}
}
V_4 -> V_71 &= ~ V_116 ;
F_48 ( V_2 , V_4 ) ;
return 0 ;
}
void
F_49 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
T_2 V_192 )
{
T_4 * V_193 ;
int V_85 ;
V_193 = ( T_4 * ) F_29 ( V_39 -> V_125 ,
V_126 ) ;
if ( ! V_193 )
F_3 ( V_2 , V_33 , V_194 ,
L_10 ) ;
else {
F_50 ( V_39 , V_2 -> V_132 , V_192 , V_193 ) ;
V_193 -> V_128 = V_129 ;
V_85 = F_31 ( V_39 , V_193 , V_130 ) ;
if ( V_85 == V_131 )
F_32 ( V_193 , V_39 -> V_125 ) ;
}
}
static T_1
F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_38 * V_39 ;
T_4 * V_193 = ( T_4 * ) V_195 ;
T_8 * V_197 ;
T_2 V_192 ;
V_39 = V_2 -> V_39 ;
if ( ! ( V_39 -> V_78 -> V_198 & V_199 ) &&
( V_196 == V_200 ) &&
( ! V_193 -> V_36 . V_197 . V_201 ) ) {
V_197 = & V_193 -> V_36 . V_197 ;
V_192 = V_193 -> V_36 . V_197 . V_56 . V_202 [ 0 ] ;
F_49 ( V_39 , V_2 , V_192 ) ;
}
F_3 ( V_2 , V_33 , V_34 ,
L_11
L_12 ,
V_4 -> V_35 , V_196 , V_4 -> V_72 , V_4 -> V_73 ,
V_4 -> V_71 ) ;
return V_4 -> V_72 ;
}
static T_1
F_52 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
if ( ! ( V_4 -> V_71 & V_137 ) ) {
F_3 ( V_2 , V_33 , V_34 ,
L_13
L_12 ,
V_4 -> V_35 , V_196 , V_4 -> V_72 , V_4 -> V_73 ,
V_4 -> V_71 ) ;
}
return V_4 -> V_72 ;
}
static T_1
F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
if ( F_21 ( V_2 , V_4 , V_41 ) ) {
return V_4 -> V_72 ;
}
return V_203 ;
}
static T_1
F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
F_55 ( V_2 , V_4 , 0 ) ;
return V_4 -> V_72 ;
}
static T_1
F_56 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_162 ;
F_14 ( V_80 -> V_135 ) ;
F_28 ( V_2 , V_164 , V_41 , V_4 , NULL ) ;
return V_4 -> V_72 ;
}
static T_1
F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
return V_203 ;
}
static T_1
F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
return V_203 ;
}
static T_1
F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
return V_4 -> V_72 ;
}
static T_1
F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 = V_195 ;
struct V_43 * V_44 = (struct V_43 * ) V_41 -> V_50 ;
T_1 * V_46 = ( T_1 * ) V_44 -> V_52 ;
struct V_10 * V_11 = (struct V_10 * ) ( V_46 + 1 ) ;
struct V_83 V_84 ;
int V_204 ;
memset ( & V_84 , 0 , sizeof ( struct V_83 ) ) ;
V_39 -> V_205 . V_206 ++ ;
V_204 = memcmp ( & V_2 -> V_207 , & V_11 -> V_32 ,
sizeof( struct V_5 ) ) ;
if ( V_204 >= 0 ) {
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_208 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 ,
NULL ) ;
} else {
if ( F_21 ( V_2 , V_4 , V_41 ) &&
( V_4 -> V_71 & V_209 ) &&
( V_2 -> V_210 ) ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ V_209 ;
F_14 ( V_80 -> V_135 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_210 == 0 ) {
F_9 ( V_80 -> V_135 ) ;
V_2 -> V_88 &= ~ V_211 ;
F_14 ( V_80 -> V_135 ) ;
F_33 ( V_2 ) ;
F_62 ( V_2 ) ;
}
}
}
return V_4 -> V_72 ;
}
static T_1
F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof ( struct V_83 ) ) ;
V_84 . V_56 . V_95 . V_96 = V_97 ;
V_84 . V_56 . V_95 . V_98 = V_99 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 , NULL ) ;
return V_4 -> V_72 ;
}
static T_1
F_64 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_6 ( V_2 -> V_39 , V_4 ) ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_65 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_6 ( V_39 , V_4 ) ;
if ( V_196 == V_213 ) {
F_28 ( V_2 , V_164 , V_41 , V_4 , NULL ) ;
} else {
F_55 ( V_2 , V_4 , 0 ) ;
}
F_37 ( & V_4 -> V_152 , V_153 + V_154 * 1 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
V_4 -> V_157 = V_138 ;
F_38 ( V_2 , V_4 , V_115 ) ;
return V_4 -> V_72 ;
}
static T_1
F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 , * V_42 ;
struct V_43 * V_44 , * V_45 , * V_214 ;
T_1 * V_46 ;
T_3 * V_48 ;
struct V_10 * V_11 ;
T_4 * V_82 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
if ( V_4 -> V_71 & V_136 ) {
return V_4 -> V_72 ;
}
V_48 = & V_42 -> V_49 ;
if ( V_48 -> V_54 )
goto V_127;
V_44 = (struct V_43 * ) V_41 -> V_50 ;
V_45 = F_5 ( & V_44 -> V_51 , struct V_43 , V_51 ) ;
V_46 = ( T_1 * ) V_45 -> V_52 ;
V_11 = (struct V_10 * ) ( ( V_53 * ) V_46 + sizeof ( T_1 ) ) ;
if ( ( V_4 -> V_35 != V_217 ) &&
( F_27 ( V_11 -> V_32 . V_36 . V_37 ) == 0 ||
F_27 ( V_11 -> V_31 . V_36 . V_37 ) == 0 ) ) {
F_3 ( V_2 , V_33 , V_101 ,
L_14 ) ;
goto V_127;
}
if ( ! F_2 ( V_2 , V_4 , V_11 , V_27 , 0 ) )
goto V_127;
F_3 ( V_2 , V_70 , V_101 ,
L_15 ,
V_4 -> V_35 , V_4 -> V_72 ,
V_4 -> V_71 , V_4 -> V_73 ) ;
if ( V_2 -> V_106 == 2 && ( V_11 -> V_24 . V_19 ) )
V_4 -> V_107 |= V_25 ;
else
V_4 -> V_107 |= V_27 ;
V_4 -> V_108 = 0 ;
if ( V_11 -> V_18 . V_19 )
V_4 -> V_108 |= V_109 ;
if ( V_11 -> V_24 . V_19 )
V_4 -> V_108 |= V_110 ;
if ( V_11 -> V_26 . V_19 )
V_4 -> V_108 |= V_111 ;
if ( V_11 -> V_112 . V_19 )
V_4 -> V_108 |= V_113 ;
V_4 -> V_114 =
( ( V_11 -> V_28 . V_29 & 0x0F ) << 8 ) | V_11 -> V_28 . V_30 ;
V_82 = F_29 ( V_39 -> V_125 , V_126 ) ;
if ( ! V_82 ) {
F_3 ( V_2 , V_33 , V_101 ,
L_16
L_17 ,
V_4 -> V_35 , V_4 -> V_72 ,
V_4 -> V_71 , V_4 -> V_73 ) ;
goto V_127;
}
F_48 ( V_2 , V_4 ) ;
if ( F_34 ( V_39 , V_2 -> V_132 , V_48 -> V_56 . V_218 . V_133 ,
( V_53 * ) V_11 , V_82 , V_4 -> V_73 ) == 0 ) {
switch ( V_4 -> V_35 ) {
case V_219 :
V_82 -> V_128 = V_220 ;
break;
case V_217 :
V_82 -> V_128 = V_221 ;
break;
default:
V_4 -> V_71 |= V_222 ;
V_82 -> V_128 = V_134 ;
}
V_82 -> V_50 = F_67 ( V_4 ) ;
V_82 -> V_2 = V_2 ;
if ( F_31 ( V_39 , V_82 , V_130 )
!= V_131 ) {
F_38 ( V_2 , V_4 ,
V_117 ) ;
return V_4 -> V_72 ;
}
if ( V_4 -> V_71 & V_222 )
V_4 -> V_71 &= ~ V_222 ;
F_68 ( V_4 ) ;
V_214 = (struct V_43 * ) V_82 -> V_223 ;
F_69 ( V_39 , V_214 -> V_52 , V_214 -> V_224 ) ;
F_70 ( V_214 ) ;
F_32 ( V_82 , V_39 -> V_125 ) ;
F_3 ( V_2 , V_33 , V_101 ,
L_18
L_17 ,
V_4 -> V_35 , V_4 -> V_72 ,
V_4 -> V_71 , V_4 -> V_73 ) ;
} else {
F_32 ( V_82 , V_39 -> V_125 ) ;
F_3 ( V_2 , V_33 , V_101 ,
L_19
L_17 ,
V_4 -> V_35 , V_4 -> V_72 ,
V_4 -> V_71 , V_4 -> V_73 ) ;
}
V_127:
if ( V_4 -> V_35 == V_219 ) {
F_71 ( V_2 , V_225 ) ;
F_3 ( V_2 , V_33 , V_101 ,
L_20 ) ;
}
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_226 ;
F_14 ( V_80 -> V_135 ) ;
return V_203 ;
}
static T_1
F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
return V_4 -> V_72 ;
}
static T_1
F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_195 , T_1 V_196 )
{
struct V_38 * V_39 ;
T_4 * V_193 = ( T_4 * ) V_195 ;
T_8 * V_197 = & V_193 -> V_36 . V_197 ;
T_2 V_192 ;
V_39 = V_2 -> V_39 ;
if ( ! ( V_39 -> V_78 -> V_198 & V_199 ) &&
! V_197 -> V_201 ) {
V_192 = V_193 -> V_36 . V_197 . V_56 . V_202 [ 0 ] ;
F_49 ( V_39 , V_2 , V_192 ) ;
}
return V_4 -> V_72 ;
}
static T_1
F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_227 ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
} else {
F_6 ( V_2 -> V_39 , V_4 ) ;
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
}
static T_1
F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
if ( V_2 -> V_88 & V_228 )
return V_4 -> V_72 ;
F_6 ( V_39 , V_4 ) ;
V_4 -> V_157 = V_138 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
}
static T_1
F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 ;
F_6 ( V_39 , V_4 ) ;
V_41 = (struct V_40 * ) V_195 ;
if ( F_21 ( V_2 , V_4 , V_41 ) ) {
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ V_209 ;
F_14 ( V_80 -> V_135 ) ;
if ( V_2 -> V_210 )
F_78 ( V_2 ) ;
}
return V_4 -> V_72 ;
}
V_4 -> V_157 = V_174 ;
F_79 ( V_2 , V_4 -> V_35 , 0 ) ;
F_38 ( V_2 , V_4 , V_138 ) ;
return V_4 -> V_72 ;
}
static T_1
F_80 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_81 ( V_2 , V_41 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_82 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
F_6 ( V_39 , V_4 ) ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_84 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
F_39 ( V_2 , V_4 , V_41 , V_163 ) ;
return V_4 -> V_72 ;
}
static T_1
F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 , * V_42 ;
T_3 * V_48 ;
T_5 * V_147 ;
int V_85 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
V_147 = ( T_5 * ) F_4 ( V_39 , V_41 , V_42 ) ;
V_48 = & V_42 -> V_49 ;
if ( ( V_48 -> V_54 ) ||
( ! F_1 ( V_2 , V_4 , & V_147 -> V_31 , & V_147 -> V_32 ) ) ) {
F_37 ( & V_4 -> V_152 , V_153 + V_154 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
memset ( & V_4 -> V_8 , 0 , sizeof( struct V_5 ) ) ;
memset ( & V_4 -> V_9 , 0 , sizeof( struct V_5 ) ) ;
V_4 -> V_157 = V_174 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_48 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
if ( V_39 -> V_229 == V_230 ) {
V_85 = F_86 ( V_4 ) ;
if ( V_85 ) {
V_4 -> V_157 = V_174 ;
return V_4 -> V_72 ;
}
}
if ( V_4 -> V_170 & V_172 ) {
V_4 -> V_157 = V_174 ;
F_38 ( V_2 , V_4 , V_120 ) ;
} else {
V_4 -> V_157 = V_174 ;
F_38 ( V_2 , V_4 , V_119 ) ;
}
return V_4 -> V_72 ;
}
static T_1
F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_227 ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
} else {
F_6 ( V_2 -> V_39 , V_4 ) ;
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
}
static T_1
F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
if ( V_2 -> V_88 & V_228 )
return V_4 -> V_72 ;
F_6 ( V_39 , V_4 ) ;
V_4 -> V_157 = V_174 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
F_47 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_21 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_81 ( V_2 , V_41 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
T_4 * V_197 ;
T_4 * V_231 ;
struct V_43 * V_214 ;
V_41 = (struct V_40 * ) V_195 ;
if ( ( V_197 = V_39 -> V_64 . V_232 ) ) {
if ( ( V_197 -> V_36 . V_197 . V_233 == V_234 ) &&
( V_4 == (struct V_3 * ) V_197 -> V_50 ) ) {
F_68 ( V_4 ) ;
V_197 -> V_50 = NULL ;
V_197 -> V_128 = V_129 ;
}
}
F_9 ( & V_39 -> V_74 ) ;
F_10 (mb, nextmb, &phba->sli.mboxq, list) {
if ( ( V_197 -> V_36 . V_197 . V_233 == V_234 ) &&
( V_4 == (struct V_3 * ) V_197 -> V_50 ) ) {
V_214 = (struct V_43 * ) ( V_197 -> V_223 ) ;
if ( V_214 ) {
F_92 ( V_39 , V_214 -> V_52 , V_214 -> V_224 ) ;
F_70 ( V_214 ) ;
}
F_68 ( V_4 ) ;
F_93 ( & V_197 -> V_51 ) ;
V_39 -> V_64 . V_235 -- ;
F_32 ( V_197 , V_39 -> V_125 ) ;
}
}
F_14 ( & V_39 -> V_74 ) ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
F_28 ( V_2 , V_163 , V_41 , V_4 , NULL ) ;
return V_4 -> V_72 ;
}
static T_1
F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
T_4 * V_193 = ( T_4 * ) V_195 ;
T_8 * V_197 = & V_193 -> V_36 . V_197 ;
T_1 V_236 = V_197 -> V_56 . V_202 [ 1 ] ;
if ( V_197 -> V_201 ) {
F_3 ( V_2 , V_33 , V_34 ,
L_21
L_22 ,
V_236 , V_197 -> V_201 , V_2 -> V_86 ,
V_197 -> V_56 . V_237 . V_132 ,
V_197 -> V_56 . V_237 . V_192 ) ;
if ( V_197 -> V_201 == V_238 ) {
V_4 -> V_157 = V_117 ;
F_38 ( V_2 , V_4 , V_115 ) ;
return V_4 -> V_72 ;
}
F_37 ( & V_4 -> V_152 , V_153 + V_154 * 1 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
F_55 ( V_2 , V_4 , 0 ) ;
V_4 -> V_157 = V_117 ;
F_38 ( V_2 , V_4 , V_115 ) ;
return V_4 -> V_72 ;
}
if ( V_2 -> V_39 -> V_229 < V_230 )
V_4 -> V_73 = V_197 -> V_56 . V_202 [ 0 ] ;
V_4 -> V_71 |= V_189 ;
if ( ! ( V_4 -> V_170 & V_171 ) ) {
V_4 -> V_157 = V_117 ;
F_38 ( V_2 , V_4 , V_118 ) ;
F_97 ( V_2 , V_4 , 0 ) ;
} else {
V_4 -> V_157 = V_117 ;
F_38 ( V_2 , V_4 , V_119 ) ;
}
return V_4 -> V_72 ;
}
static T_1
F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_227 ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
} else {
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
}
static T_1
F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_2 -> V_88 & V_228 )
return V_4 -> V_72 ;
V_4 -> V_157 = V_117 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_239 ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
F_47 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_195 ;
F_21 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_101 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_81 ( V_2 , V_41 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_102 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_6 ( V_2 -> V_39 , V_4 ) ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_103 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_104 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_28 ( V_2 , V_163 , V_41 , V_4 , NULL ) ;
return V_4 -> V_72 ;
}
static T_1
F_105 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 , * V_42 ;
struct V_38 * V_39 = V_2 -> V_39 ;
T_3 * V_48 ;
T_6 * V_175 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
V_175 = ( T_6 * ) F_4 ( V_39 , V_41 , V_42 ) ;
V_48 = & V_42 -> V_49 ;
if ( V_48 -> V_54 ) {
if ( ( V_2 -> V_139 == V_140 ) &&
V_2 -> V_141 ) {
goto V_127;
}
V_4 -> V_157 = V_118 ;
F_38 ( V_2 , V_4 , V_119 ) ;
return V_4 -> V_72 ;
}
V_4 -> V_170 &= ~ ( V_172 | V_173 ) ;
V_4 -> V_107 &= ~ V_179 ;
if ( ( V_175 -> V_240 == V_241 ) &&
( V_175 -> V_180 == V_181 ) ) {
if ( V_175 -> V_182 )
V_4 -> V_170 |= V_173 ;
if ( V_175 -> V_183 )
V_4 -> V_170 |= V_172 ;
if ( V_175 -> V_184 )
V_4 -> V_107 |= V_179 ;
}
if ( ! ( V_4 -> V_170 & V_172 ) &&
( V_2 -> V_139 == V_140 ) &&
V_2 -> V_141 ) {
V_127:
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_242 ;
F_14 ( V_80 -> V_135 ) ;
F_55 ( V_2 , V_4 , 0 ) ;
V_4 -> V_157 = V_118 ;
F_38 ( V_2 , V_4 , V_115 ) ;
return V_4 -> V_72 ;
}
V_4 -> V_157 = V_118 ;
if ( V_4 -> V_170 & V_172 )
F_38 ( V_2 , V_4 , V_120 ) ;
else
F_38 ( V_2 , V_4 , V_119 ) ;
return V_4 -> V_72 ;
}
static T_1
F_106 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_227 ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
} else {
F_6 ( V_2 -> V_39 , V_4 ) ;
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
}
static T_1
F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
if ( V_2 -> V_88 & V_228 )
return V_4 -> V_72 ;
F_6 ( V_39 , V_4 ) ;
V_4 -> V_157 = V_118 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
F_47 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_108 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_21 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_109 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_44 ( V_2 , V_4 , V_41 ) ;
F_81 ( V_2 , V_41 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_110 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_111 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_112 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_28 ( V_2 , V_163 , V_41 , V_4 , NULL ) ;
return V_4 -> V_72 ;
}
static T_1
F_113 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
V_4 -> V_157 = V_119 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
F_47 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_114 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_21 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_115 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_81 ( V_2 , V_41 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_116 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_117 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
return V_4 -> V_72 ;
}
static T_1
F_118 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_119 ( V_2 , & V_39 -> V_64 . V_67 [ V_39 -> V_64 . V_243 ] ,
V_4 -> V_244 , 0 , V_245 ) ;
F_39 ( V_2 , V_4 , V_41 , V_163 ) ;
return V_4 -> V_72 ;
}
static T_1
F_120 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 ,
T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
V_4 -> V_157 = V_120 ;
F_38 ( V_2 , V_4 , V_115 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
F_47 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_121 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
if ( V_4 -> V_71 & ( V_246 | V_162 ) )
return V_4 -> V_72 ;
if ( F_21 ( V_2 , V_4 , V_41 ) ) {
F_20 ( V_2 , V_4 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_116 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
} else if ( ! ( V_4 -> V_71 & V_209 ) ) {
if ( ! ( V_4 -> V_71 & V_155 ) ) {
V_4 -> V_157 = V_115 ;
F_38 ( V_2 , V_4 , V_138 ) ;
F_79 ( V_2 , V_4 -> V_35 , 0 ) ;
}
}
return V_4 -> V_72 ;
}
static T_1
F_122 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof ( struct V_83 ) ) ;
V_84 . V_56 . V_95 . V_96 = V_102 ;
V_84 . V_56 . V_95 . V_98 = V_99 ;
F_26 ( V_2 , V_84 . V_56 . V_100 , V_41 , V_4 , NULL ) ;
if ( ! ( V_4 -> V_71 & V_155 ) ) {
if ( V_4 -> V_71 & V_116 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ V_116 ;
V_4 -> V_157 = V_115 ;
F_14 ( V_80 -> V_135 ) ;
F_38 ( V_2 , V_4 , V_174 ) ;
F_123 ( V_2 , V_4 , 0 ) ;
} else {
V_4 -> V_157 = V_115 ;
F_38 ( V_2 , V_4 , V_138 ) ;
F_79 ( V_2 , V_4 -> V_35 , 0 ) ;
}
}
return V_4 -> V_72 ;
}
static T_1
F_124 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_39 ( V_2 , V_4 , V_41 , V_212 ) ;
return V_4 -> V_72 ;
}
static T_1
F_125 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_35 ( V_2 , V_4 , V_41 ) ;
if ( ! ( V_4 -> V_71 & V_155 ) &&
! ( V_4 -> V_71 & V_209 ) ) {
if ( V_4 -> V_71 & V_116 ) {
V_4 -> V_71 &= ~ V_116 ;
V_4 -> V_157 = V_115 ;
F_38 ( V_2 , V_4 , V_174 ) ;
F_123 ( V_2 , V_4 , 0 ) ;
} else {
V_4 -> V_157 = V_115 ;
F_38 ( V_2 , V_4 , V_138 ) ;
F_79 ( V_2 , V_4 -> V_35 , 0 ) ;
}
}
return V_4 -> V_72 ;
}
static T_1
F_126 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_195 ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_162 ;
F_14 ( V_80 -> V_135 ) ;
F_28 ( V_2 , V_164 , V_41 , V_4 , NULL ) ;
if ( ( V_4 -> V_71 & V_155 ) == 0 ) {
F_37 ( & V_4 -> V_152 , V_153 + V_154 * 1 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_155 ;
V_4 -> V_71 &= ~ V_116 ;
F_14 ( V_80 -> V_135 ) ;
V_4 -> V_156 = V_121 ;
} else {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ V_116 ;
F_14 ( V_80 -> V_135 ) ;
}
return V_4 -> V_72 ;
}
static T_1
F_127 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 , * V_42 ;
T_3 * V_48 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
V_48 = & V_42 -> V_49 ;
if ( V_48 -> V_54 ) {
V_4 -> V_71 |= V_226 ;
return V_203 ;
}
return V_4 -> V_72 ;
}
static T_1
F_128 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 , * V_42 ;
T_3 * V_48 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
V_48 = & V_42 -> V_49 ;
if ( V_48 -> V_54 && ( V_4 -> V_71 & V_227 ) ) {
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
return V_4 -> V_72 ;
}
static T_1
F_129 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_35 == V_165 ) {
F_9 ( V_80 -> V_135 ) ;
V_2 -> V_88 &= ~ ( V_247 | V_248 ) ;
F_14 ( V_80 -> V_135 ) ;
}
F_48 ( V_2 , V_4 ) ;
return V_4 -> V_72 ;
}
static T_1
F_130 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_40 * V_41 , * V_42 ;
T_3 * V_48 ;
V_41 = (struct V_40 * ) V_195 ;
V_42 = V_41 -> V_215 . V_216 ;
V_48 = & V_42 -> V_49 ;
if ( V_48 -> V_54 && ( V_4 -> V_71 & V_227 ) ) {
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
return V_4 -> V_72 ;
}
static T_1
F_131 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
T_4 * V_193 = ( T_4 * ) V_195 ;
T_8 * V_197 = & V_193 -> V_36 . V_197 ;
if ( ! V_197 -> V_201 ) {
if ( V_2 -> V_39 -> V_229 < V_230 )
V_4 -> V_73 = V_197 -> V_56 . V_202 [ 0 ] ;
V_4 -> V_71 |= V_189 ;
} else {
if ( V_4 -> V_71 & V_227 ) {
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
}
return V_4 -> V_72 ;
}
static T_1
F_132 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_4 -> V_71 & V_209 ) {
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 |= V_227 ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
}
F_75 ( V_2 , V_4 ) ;
return V_203 ;
}
static T_1
F_133 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
struct V_79 * V_80 = F_22 ( V_2 ) ;
if ( V_2 -> V_88 & V_228 )
return V_4 -> V_72 ;
F_20 ( V_2 , V_4 ) ;
F_9 ( V_80 -> V_135 ) ;
V_4 -> V_71 &= ~ ( V_227 | V_209 ) ;
F_14 ( V_80 -> V_135 ) ;
return V_4 -> V_72 ;
}
int
F_134 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_195 , T_1 V_196 )
{
T_1 V_249 , V_85 ;
T_1 (* F_135) ( struct V_1 * , struct V_3 * , void * ,
T_1 );
T_1 V_250 = 0 ;
if ( F_67 ( V_4 ) )
V_250 = 1 ;
V_249 = V_4 -> V_72 ;
F_3 ( V_2 , V_70 , V_34 ,
L_23
L_24 ,
V_196 , V_4 -> V_35 , V_249 , V_4 -> V_71 ) ;
F_45 ( V_2 , V_251 ,
L_25 ,
V_196 , V_249 , V_4 -> V_35 ) ;
F_135 = V_252 [ ( V_249 * V_253 ) + V_196 ] ;
V_85 = ( F_135 ) ( V_2 , V_4 , V_195 , V_196 ) ;
if ( V_250 ) {
F_3 ( V_2 , V_70 , V_34 ,
L_26 ,
V_85 , V_4 -> V_35 , V_4 -> V_71 ) ;
F_45 ( V_2 , V_251 ,
L_27 ,
V_85 , V_4 -> V_35 , V_4 -> V_71 ) ;
F_68 ( V_4 ) ;
} else {
F_3 ( V_2 , V_70 , V_34 ,
L_28 , V_85 ) ;
F_45 ( V_2 , V_251 ,
L_27 ,
V_85 , 0 , 0 ) ;
}
return V_85 ;
}
