static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 64 ) ;
F_2 ( sizeof( struct V_8 ) != 960 ) ;
F_2 ( sizeof( struct V_9 ) != 128 ) ;
F_2 ( sizeof( struct V_10 ) != 4096 ) ;
F_2 ( sizeof( struct V_11 ) != 512 ) ;
}
static int F_3 ( struct V_12 * V_12 , struct V_10 * V_10 )
{
struct V_8 * V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_17 = F_4 ( V_18 , 4 , V_12 -> V_19 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_13 = & V_10 -> V_20 [ V_16 ] ;
V_15 = & V_12 -> V_20 [ V_16 ] ;
V_15 -> V_21 = V_13 -> V_21 ;
V_15 -> V_22 = V_13 -> V_22 ;
V_15 -> V_23 = V_13 -> V_23 ;
V_15 -> V_24 = V_13 -> V_24 ;
V_15 -> V_25 = V_13 -> V_25 ;
V_15 -> V_26 = F_5 ( V_13 -> V_26 ) ;
V_15 -> V_27 = F_5 ( V_13 -> V_27 ) ;
V_15 -> V_28 = F_5 ( V_13 -> V_28 ) ;
V_15 -> V_29 = F_5 ( V_13 -> V_29 ) ;
V_15 -> V_30 = F_5 ( V_13 -> V_30 ) ;
V_15 -> V_31 = F_6 ( V_13 -> V_31 ) ;
V_15 -> V_32 = F_6 ( V_13 -> V_32 ) ;
V_15 -> V_33 = F_6 ( V_13 -> V_33 ) ;
V_15 -> V_34 = F_6 ( V_13 -> V_34 ) ;
V_15 -> V_35 = F_6 ( V_13 -> V_35 ) ;
V_15 -> V_36 = F_6 ( V_13 -> V_36 ) ;
V_15 -> V_37 = F_6 ( V_13 -> V_37 ) ;
V_15 -> V_38 = F_6 ( V_13 -> V_38 ) ;
V_15 -> V_39 = F_5 ( V_13 -> V_39 ) ;
if ( V_15 -> V_22 == V_40 ) {
memcpy ( V_15 -> V_41 . V_42 , V_13 -> V_41 . V_42 , 8 ) ;
V_15 -> V_41 . V_43 . V_44 =
F_5 ( V_13 -> V_41 . V_43 . V_44 ) ;
if ( V_15 -> V_41 . V_43 . V_44 > V_45 ) {
F_7 ( L_1 ) ;
return - V_46 ;
}
memcpy ( V_15 -> V_41 . V_43 . V_47 , V_13 -> V_41 . V_43 . V_47 ,
V_15 -> V_41 . V_43 . V_44 ) ;
}
}
return 0 ;
}
static int V_1 ( struct V_48 * V_49 , struct V_12 * V_12 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_10 * V_10 ;
struct V_54 V_55 = {} ;
int V_56 ;
V_55 . V_57 . V_58 = V_59 ;
V_55 . V_57 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_57 . V_62 = 0 ;
V_10 = F_9 ( sizeof( struct V_10 ) , V_63 ) ;
if ( ! V_10 )
return - V_64 ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_10 , sizeof( struct V_10 ) ) ;
if ( V_56 ) {
V_56 = - V_68 ;
goto V_69;
}
V_12 -> V_70 = V_10 -> V_70 ;
V_12 -> V_71 = V_10 -> V_71 ;
V_12 -> V_19 = V_10 -> V_19 ;
V_12 -> V_72 = F_6 ( V_10 -> V_72 ) ;
V_12 -> V_73 = F_6 ( V_10 -> V_73 ) ;
memcpy ( & V_12 -> V_74 , & V_10 -> V_74 ,
sizeof( struct V_9 ) ) ;
V_56 = F_3 ( V_12 , V_10 ) ;
V_69:
F_11 ( V_10 ) ;
return V_56 ;
}
static int F_12 ( struct V_48 * V_49 , T_1 V_75 , V_18 V_76 ,
T_2 * V_77 , void * V_78 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_18 V_79 = F_13 ( V_51 -> V_65 -> V_66 ) << 9 ;
V_18 V_80 = V_79 / sizeof( T_1 ) ;
T_1 V_81 = V_75 ;
void * V_82 ;
int V_56 = 0 ;
V_55 . V_83 . V_58 = V_84 ;
V_55 . V_83 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_82 = F_9 ( V_79 , V_63 ) ;
if ( ! V_82 )
return - V_64 ;
while ( V_76 ) {
V_18 V_85 = F_14 ( V_80 , V_76 ) ;
T_1 V_86 = V_75 + V_85 ;
V_55 . V_83 . V_75 = F_15 ( V_81 ) ;
V_55 . V_83 . V_76 = F_8 ( V_85 ) ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 ,
(struct V_67 * ) & V_55 , V_82 , V_79 ) ;
if ( V_56 ) {
F_16 ( V_51 -> V_65 -> V_87 ,
L_2 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( F_17 ( V_86 > V_49 -> V_88 ) ) {
F_7 ( L_3 ) ;
return - V_46 ;
}
V_49 -> V_89 -> V_90 ( V_49 , V_82 , V_85 ) ;
if ( V_77 ( V_81 , V_85 , V_82 , V_78 ) ) {
V_56 = - V_91 ;
goto V_69;
}
V_81 += V_85 ;
V_76 -= V_85 ;
}
V_69:
F_11 ( V_82 ) ;
return V_56 ;
}
static int F_18 ( struct V_48 * V_49 , struct V_92 V_93 ,
T_3 * V_94 )
{
struct V_95 * V_52 = V_49 -> V_52 ;
struct V_96 * V_97 = & V_49 -> V_97 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_98 * V_65 = V_51 -> V_65 ;
struct V_54 V_55 = {} ;
struct V_11 * V_99 ;
int V_100 = V_97 -> V_101 * V_97 -> V_102 ;
int V_103 = sizeof( struct V_11 ) + V_100 ;
int V_56 = 0 ;
V_55 . V_104 . V_58 = V_105 ;
V_55 . V_104 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_104 . V_106 = F_15 ( V_93 . V_93 ) ;
V_99 = F_19 ( V_103 , V_63 ) ;
if ( ! V_99 )
return - V_64 ;
V_56 = F_10 ( V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_99 , V_103 ) ;
if ( V_56 ) {
F_16 ( V_65 -> V_87 , L_4 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_99 -> V_107 [ 0 ] != 'B' || V_99 -> V_107 [ 1 ] != 'B' ||
V_99 -> V_107 [ 2 ] != 'L' || V_99 -> V_107 [ 3 ] != 'T' ) {
F_16 ( V_65 -> V_87 , L_5 ) ;
V_56 = - V_46 ;
goto V_69;
}
if ( F_5 ( V_99 -> V_108 ) != 1 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_87 , L_6 ) ;
goto V_69;
}
if ( F_6 ( V_99 -> V_109 ) != V_100 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_87 ,
L_7 ,
F_6 ( V_99 -> V_109 ) , V_100 ) ;
goto V_69;
}
memcpy ( V_94 , V_99 -> V_110 , V_97 -> V_101 * V_97 -> V_102 ) ;
V_69:
F_11 ( V_99 ) ;
return V_56 ;
}
static int F_20 ( struct V_48 * V_49 , struct V_92 * V_111 ,
int V_112 , int type )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
int V_56 = 0 ;
V_55 . V_113 . V_58 = V_114 ;
V_55 . V_113 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_113 . V_106 = F_15 ( V_111 -> V_93 ) ;
V_55 . V_113 . V_76 = F_21 ( V_112 - 1 ) ;
V_55 . V_113 . V_115 = type ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
NULL , 0 ) ;
if ( V_56 )
F_16 ( V_51 -> V_65 -> V_87 , L_8 ,
V_56 ) ;
return V_56 ;
}
static inline void F_22 ( struct V_116 * V_117 , struct V_118 * V_119 ,
struct V_50 * V_51 , struct V_54 * V_55 )
{
V_55 -> V_120 . V_58 = V_119 -> V_58 ;
V_55 -> V_120 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 -> V_120 . V_106 = F_15 ( V_119 -> V_92 . V_93 ) ;
V_55 -> V_120 . V_121 = F_15 ( V_119 -> V_122 ) ;
V_55 -> V_120 . V_123 = F_21 ( V_119 -> V_124 ) ;
V_55 -> V_120 . V_125 = F_21 ( V_119 -> V_112 - 1 ) ;
if ( V_119 -> V_58 == V_126 || V_119 -> V_58 == V_127 )
V_55 -> V_128 . V_75 = F_15 ( F_23 ( V_51 ,
V_119 -> V_129 -> V_130 . V_131 ) ) ;
}
static void F_24 ( struct V_116 * V_117 , int error )
{
struct V_118 * V_119 = V_117 -> V_132 ;
V_119 -> V_133 = F_25 ( V_117 ) -> V_134 . T_1 ;
F_26 ( V_119 , error ) ;
F_11 ( F_25 ( V_117 ) -> V_135 ) ;
F_27 ( V_117 ) ;
}
static int F_28 ( struct V_48 * V_136 , struct V_118 * V_119 )
{
struct V_95 * V_52 = V_136 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_116 * V_117 ;
struct V_129 * V_129 = V_119 -> V_129 ;
struct V_54 * V_135 ;
V_135 = F_19 ( sizeof( struct V_54 ) , V_63 ) ;
if ( ! V_135 )
return - V_64 ;
V_117 = F_29 ( V_52 , (struct V_67 * ) V_135 , 0 , V_137 ) ;
if ( F_30 ( V_117 ) ) {
F_11 ( V_135 ) ;
return - V_64 ;
}
V_117 -> V_138 &= ~ V_139 ;
V_117 -> V_140 = F_31 ( V_129 ) ;
if ( F_32 ( V_129 ) )
V_117 -> V_141 = F_33 ( V_52 , V_129 ) ;
V_117 -> V_142 = V_129 -> V_130 . V_143 ;
V_117 -> V_129 = V_117 -> V_144 = V_129 ;
F_22 ( V_117 , V_119 , V_51 , V_135 ) ;
V_117 -> V_132 = V_119 ;
F_34 ( V_52 , NULL , V_117 , 0 , F_24 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_136 , struct V_118 * V_119 )
{
struct V_95 * V_52 = V_136 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_55 . V_145 . V_58 = V_146 ;
V_55 . V_145 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_145 . V_106 = F_15 ( V_119 -> V_92 . V_93 ) ;
V_55 . V_145 . V_125 = F_21 ( V_119 -> V_112 - 1 ) ;
V_55 . V_145 . V_123 = F_21 ( V_119 -> V_124 ) ;
return F_10 ( V_52 , (struct V_67 * ) & V_55 , NULL , 0 ) ;
}
static void * F_36 ( struct V_48 * V_49 , char * V_147 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
return F_37 ( V_147 , V_51 -> V_65 -> V_136 , V_148 , V_148 , 0 ) ;
}
static void F_38 ( void * V_149 )
{
struct V_150 * V_150 = V_149 ;
F_39 ( V_150 ) ;
}
static void * F_40 ( struct V_48 * V_136 , void * V_149 ,
T_4 V_151 , T_5 * V_152 )
{
return F_41 ( V_149 , V_151 , V_152 ) ;
}
static void F_42 ( void * V_149 , void * V_153 ,
T_5 V_152 )
{
F_43 ( V_149 , V_153 , V_152 ) ;
}
int F_44 ( struct V_50 * V_51 , char * V_154 , int V_155 )
{
struct V_95 * V_52 = V_51 -> V_156 ;
struct V_48 * V_136 ;
V_136 = F_45 ( V_155 ) ;
if ( ! V_136 )
return - V_64 ;
V_136 -> V_52 = V_52 ;
memcpy ( V_136 -> V_147 , V_154 , V_157 ) ;
V_136 -> V_158 = & V_159 ;
V_136 -> V_160 = V_51 ;
V_51 -> V_161 = V_136 ;
return F_46 ( V_136 ) ;
}
void F_47 ( struct V_50 * V_51 )
{
F_48 ( V_51 -> V_161 ) ;
}
static T_6 F_49 ( struct V_87 * V_136 ,
struct V_162 * V_163 , char * V_164 )
{
struct V_50 * V_51 = F_50 ( V_136 ) ;
struct V_48 * V_161 = V_51 -> V_161 ;
struct V_12 * V_42 ;
struct V_14 * V_165 ;
struct V_166 * V_167 ;
if ( ! V_161 )
return 0 ;
V_42 = & V_161 -> V_57 ;
V_165 = & V_42 -> V_20 [ 0 ] ;
V_167 = & V_163 -> V_167 ;
if ( strcmp ( V_167 -> V_147 , L_9 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_42 -> V_70 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_11 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_42 -> V_71 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_12 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_42 -> V_72 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_13 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_42 -> V_73 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_14 ) == 0 ) {
if ( ! V_161 -> V_89 )
return F_51 ( V_164 , V_148 , L_15 , L_16 ) ;
return F_51 ( V_164 , V_148 , L_15 , V_161 -> V_89 -> V_147 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_17 ) == 0 ) {
return F_51 ( V_164 , V_148 ,
L_18 ,
V_42 -> V_74 . V_168 , V_42 -> V_74 . V_169 ,
V_42 -> V_74 . V_170 , V_42 -> V_74 . V_171 ,
V_42 -> V_74 . V_172 , V_42 -> V_74 . V_173 ,
V_42 -> V_74 . V_174 , V_42 -> V_74 . V_175 ,
V_42 -> V_74 . V_176 , V_42 -> V_74 . V_177 ,
V_42 -> V_74 . V_178 , V_42 -> V_74 . V_179 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_19 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_21 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_20 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_22 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_21 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_23 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_22 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_24 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_23 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_25 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_24 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_27 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_25 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_26 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_26 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_28 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_27 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_29 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_28 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_30 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_29 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_31 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_30 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_32 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_31 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_33 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_32 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_34 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_33 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_35 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_34 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 , V_165 -> V_36 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_35 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_36 , V_165 -> V_37 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_37 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_36 , V_165 -> V_38 ) ;
} else if ( strcmp ( V_167 -> V_147 , L_38 ) == 0 ) {
return F_51 ( V_164 , V_148 , L_10 ,
V_161 -> V_158 -> V_180 ) ;
} else {
return F_51 ( V_164 ,
V_148 ,
L_39 ,
V_167 -> V_147 ) ;
}
}
int F_52 ( struct V_50 * V_51 )
{
return F_53 ( & F_54 ( V_51 -> V_181 ) -> V_182 ,
& V_183 ) ;
}
void F_55 ( struct V_50 * V_51 )
{
F_56 ( & F_54 ( V_51 -> V_181 ) -> V_182 ,
& V_183 ) ;
}
int F_57 ( struct V_50 * V_51 , struct V_184 * V_42 )
{
struct V_98 * V_65 = V_51 -> V_65 ;
struct V_185 * V_186 = F_58 ( V_65 -> V_136 ) ;
if ( V_186 -> V_187 == V_188 &&
V_186 -> V_87 == V_189 &&
V_42 -> V_190 [ 0 ] == 0x1 )
return 1 ;
if ( V_186 -> V_187 == V_188 &&
V_186 -> V_87 == V_191 &&
V_42 -> V_190 [ 0 ] == 0x1 )
return 1 ;
return 0 ;
}
