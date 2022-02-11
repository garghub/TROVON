static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static T_1
F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_4 ( V_5 , V_6 , V_3 ) ;
}
static int
V_3 ( struct V_7 * V_7 , T_1 V_6 ,
struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_3 V_16 = V_17 ;
int V_18 = 0 ;
T_4 V_19 ;
F_6 ( V_12 , L_1 ,
V_7 -> V_20 , V_6 ) ;
if ( V_6 < 0 ) {
F_7 ( V_12 , L_2
L_3 ,
V_6 , V_7 -> V_20 ) ;
return - V_21 ;
}
if ( V_10 ) {
F_7 ( V_12 , L_4
L_5 , V_6 , V_7 -> V_20 ) ;
return - V_22 ;
}
V_18 = F_8 ( V_12 , V_14 , V_6 , & V_16 ) ;
if ( V_18 != V_23 ) {
F_7 ( V_12 ,
L_6
L_7 , V_7 -> V_20 , V_6 ) ;
return - V_24 ;
}
V_19 = ( T_4 ) F_9 ( V_12 , & V_16 ) ;
F_10 ( V_9 , V_7 -> V_13 , V_19 ) ;
F_6 ( V_12 , L_8
L_9 , V_7 -> V_20 , V_6 , V_19 ) ;
return 0 ;
}
static struct V_25 *
F_11 ( struct V_7 * V_26 , struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_7 * V_7 = NULL ;
struct V_11 * V_12 = V_26 -> V_13 ;
T_2 * V_14 = & F_5 ( V_26 ) -> V_15 . V_14 ;
T_5 V_29 ;
int V_30 ;
int V_31 ;
char * V_32 ;
const char * V_33 = V_25 -> V_34 . V_33 ;
F_6 ( V_12 , L_10
L_11 , V_25 -> V_34 . V_33 , V_26 -> V_20 ) ;
if ( F_12 ( V_12 ) -> V_35 ) {
V_30 =
F_13 ( V_12 , V_33 , strlen ( V_33 ) , & V_32 , & V_31 ) ;
if ( V_30 < 0 ) {
F_6 ( V_12 , L_12 ) ;
return F_14 ( V_30 ) ;
}
V_30 = F_15 ( V_12 , V_14 , V_32 , & V_29 ) ;
F_16 ( V_32 ) ;
} else {
V_30 = F_15 ( V_12 , V_14 , V_25 -> V_34 . V_33 , & V_29 ) ;
}
if ( V_30 == V_36 ) {
F_6 ( V_12 , L_13 ,
V_25 -> V_34 . V_33 ) ;
return F_14 ( - V_37 ) ;
} else if ( V_30 != V_23 || V_29 == 0 ) {
F_17 ( V_12 , L_14 ) ;
return F_14 ( - V_38 ) ;
}
V_7 = F_18 ( V_26 -> V_13 , ( V_39 ) V_29 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_21 ( V_25 , V_7 ) ;
F_6 ( V_12 , L_15 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_40 , void * V_41 , T_6 V_42 )
{
struct V_7 * V_7 = V_40 -> V_43 . V_25 -> V_44 ;
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_45 ;
int V_46 ;
T_7 V_47 ;
unsigned char V_48 ;
char V_49 [ V_50 + 1 ] ;
char * V_51 ;
int V_52 ;
const char * V_53 = V_40 -> V_43 . V_25 -> V_34 . V_33 ;
F_6 ( V_12 , L_16
L_17 ,
V_53 , V_7 -> V_20 , V_40 -> V_54 ) ;
V_46 = F_23 ( V_12 , V_14 , V_40 -> V_54 , V_50 + 1 ,
V_49 , & V_47 , & V_45 ) ;
if ( V_46 == V_55 ) {
F_6 ( V_12 , L_18 ) ;
F_7 ( V_12 , L_19 ,
V_53 , V_7 -> V_20 ) ;
return - V_21 ;
} else if ( V_46 == V_56 ) {
F_6 ( V_12 , L_20 ) ;
return 0 ;
} else if ( V_46 == V_57 ) {
F_6 ( V_12 , L_21 ) ;
return 0 ;
}
V_48 = V_58 ;
if ( F_12 ( V_12 ) -> V_35 ) {
V_46 =
F_24 ( V_12 , V_49 , V_47 , & V_51 , & V_52 ) ;
if ( V_46 < 0 ) {
F_6 ( V_12 , L_18 ) ;
return V_46 ;
}
V_46 = V_42 ( V_41 , V_51 , V_52 , V_40 -> V_54 ,
( V_39 ) V_45 , V_48 ) ;
F_16 ( V_51 ) ;
} else {
V_46 = V_42 ( V_41 , V_49 , V_47 , V_40 -> V_54 ,
( V_39 ) V_45 , V_48 ) ;
}
V_40 -> V_54 ++ ;
F_6 ( V_12 , L_22 , V_40 -> V_54 ) ;
return 0 ;
}
static struct V_7 *
F_25 ( struct V_11 * V_12 )
{
struct V_59 * V_60 ;
V_60 = (struct V_59 * ) F_26 ( V_61 ,
V_62 ) ;
if ( ! V_60 )
return NULL ;
return & V_60 -> V_63 ;
}
static void F_27 ( struct V_64 * V_65 )
{
struct V_7 * V_7 = F_28 ( V_65 , struct V_7 , V_66 ) ;
F_29 ( & V_7 -> V_67 ) ;
F_30 ( V_61 , F_5 ( V_7 ) ) ;
}
static void F_31 ( struct V_7 * V_7 )
{
F_32 ( & V_7 -> V_66 , F_27 ) ;
}
static void F_33 ( void * V_68 )
{
struct V_59 * V_60 = (struct V_59 * ) V_68 ;
F_34 ( & V_60 -> V_63 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_69 )
{
struct V_8 * V_70 = NULL ;
T_8 * V_71 = NULL ;
T_9 * V_72 = F_12 ( V_12 ) ;
V_59 * V_73 = NULL ;
struct V_7 * V_7 ;
long V_30 = - V_21 ;
F_6 ( V_12 , L_23 L_24 , V_69 ) ;
V_7 = F_35 ( V_12 , V_69 ) ;
if ( F_19 ( V_7 ) )
return V_7 ;
if ( ! ( V_7 -> V_74 & V_75 ) )
return V_7 ;
V_73 = F_5 ( V_7 ) ;
V_73 -> V_76 = F_36 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_25 ,
V_73 -> V_76 . V_77 ,
V_73 -> V_76 . V_78 , V_73 -> V_76 . V_79 ) ;
V_70 = F_37 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_70 ) {
F_7 ( V_12 , L_26
L_24 , V_7 -> V_20 ) ;
goto V_80;
}
V_71 = ( T_8 * ) V_70 -> V_81 ;
F_38 ( V_12 , V_71 ) ;
if ( F_39 ( V_12 , V_71 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_27 , V_7 -> V_20 ) ;
goto V_82;
}
V_7 -> V_83 = ( V_84 ) F_40 ( V_12 , V_71 -> V_85 ) ;
V_7 -> V_86 = V_72 -> V_87 . V_88 ?
V_72 -> V_87 . V_89 : ( V_90 ) F_40 ( V_12 , V_71 -> V_89 ) ;
V_7 -> V_91 = V_72 -> V_87 . V_92 ?
V_72 -> V_87 . V_93 : ( V_94 ) F_40 ( V_12 , V_71 -> V_93 ) ;
F_41 ( V_7 , 1 ) ;
V_7 -> V_95 . V_96 =
F_42 ( V_12 , V_71 -> V_97 ) >> 16 ;
V_7 -> V_95 . V_98 = 0 ;
V_7 -> V_99 = V_7 -> V_95 ;
V_7 -> V_100 = V_7 -> V_95 ;
V_73 -> V_76 = F_43 ( V_12 , V_71 -> V_101 ) ;
V_73 -> V_102 = F_43 ( V_12 , V_71 -> V_103 ) ;
V_73 -> V_104 = F_43 ( V_12 , V_71 -> V_105 ) ;
V_73 -> V_106 = F_40 ( V_12 , V_71 -> V_107 ) ;
if ( F_44 ( V_7 -> V_83 ) && ! ( V_73 -> V_106 & V_108 ) ) {
V_7 -> V_109 = 0 ;
V_7 -> V_110 = V_72 -> V_111 / V_112 ;
strncpy ( V_73 -> V_15 . V_113 , V_71 -> V_114 . V_113 ,
V_115 - 1 ) ;
V_73 -> V_15 . V_113 [ V_115 - 1 ] = '\0' ;
} else {
int V_116 ;
V_73 -> V_15 . V_14 =
F_45 ( V_12 , & V_71 -> V_114 . V_117 ) ;
V_116 = F_46 ( V_12 , & V_73 -> V_15 . V_14 ) ;
V_7 -> V_110 =
V_116 * ( V_72 -> V_111 / V_112 ) ;
V_7 -> V_109 = V_73 -> V_15 . V_14 . V_118 ;
}
V_7 -> V_119 -> V_120 = & V_121 ;
if ( F_47 ( V_7 -> V_83 ) ) {
V_7 -> V_122 = & V_123 ;
} else if ( F_48 ( V_7 -> V_83 ) ) {
V_7 -> V_124 = & V_125 ;
V_7 -> V_122 = & V_126 ;
} else if ( F_44 ( V_7 -> V_83 ) ) {
V_7 -> V_124 = & V_127 ;
} else {
F_7 ( V_12 , L_28
L_29
L_30 , V_7 -> V_20 ) ;
goto V_82;
}
F_49 ( V_70 ) ;
F_6 ( V_12 , L_31 ) ;
F_50 ( V_7 ) ;
return V_7 ;
V_82:
F_49 ( V_70 ) ;
V_80:
F_51 ( V_7 ) ;
F_6 ( V_12 , L_32 ) ;
return F_14 ( V_30 ) ;
}
static int
F_52 ( void )
{
V_61 = F_53 ( L_33 ,
sizeof ( struct V_59 ) ,
0 , ( V_128 |
V_129 ) ,
F_33 ) ;
if ( V_61 == NULL ) {
F_54 ( V_130 L_34
L_35 ) ;
return - V_131 ;
}
return 0 ;
}
static void
F_55 ( void )
{
F_56 ( V_61 ) ;
}
static void *
F_57 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_59 * V_73 = F_5 ( V_25 -> V_44 ) ;
char * V_132 ;
if ( V_73 -> V_106 & V_108 ) {
struct V_11 * V_12 = V_25 -> V_133 ;
T_2 * V_114 = & V_73 -> V_15 . V_14 ;
T_5 V_79 = V_114 -> V_118 ;
if ( V_79 == 0 ) {
F_7 ( V_12 , L_36 ) ;
V_132 = F_14 ( - V_21 ) ;
} else {
F_6 ( V_12 , L_37 ) ;
V_132 = F_58 ( V_79 , V_134 ) ;
if ( ! V_132 ) {
V_132 = F_14 ( - V_131 ) ;
} else if ( F_59 ( V_12 , V_114 , V_132 , V_79 ) != V_79 ) {
F_16 ( V_132 ) ;
F_7 ( V_12 , L_38 ) ;
V_132 = F_14 ( - V_21 ) ;
} else {
V_132 [ V_79 - 1 ] = '\0' ;
}
}
} else {
V_132 = V_73 -> V_15 . V_113 ;
}
F_60 ( V_28 , V_132 ) ;
return NULL ;
}
static void F_61 ( struct V_25 * V_25 , struct V_27 * V_28 , void * V_135 )
{
V_59 * V_73 = F_5 ( V_25 -> V_44 ) ;
if ( V_73 -> V_106 & V_108 ) {
char * V_132 = F_62 ( V_28 ) ;
if ( ! F_19 ( V_132 ) )
F_16 ( V_132 ) ;
}
}
static int
F_24 ( struct V_11 * V_12 , const char * V_136 ,
int V_137 , char * * V_138 , int * V_139 )
{
struct V_140 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_141 , V_142 ;
T_10 V_143 ;
int V_144 , V_145 ;
char * V_46 ;
int V_146 = V_137 + 1 ;
F_6 ( V_12 , L_39 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_40 ) ;
return - V_147 ;
}
* V_138 = V_46 = F_58 ( V_146 , V_134 ) ;
if ( ! * V_138 ) {
F_7 ( V_12 , L_41 ) ;
* V_139 = 0 ;
return - V_131 ;
}
for ( V_141 = V_142 = 0 ; V_141 < V_137 ; V_141 += V_145 , V_142 += V_144 ) {
V_145 = F_63 ( & V_136 [ V_141 ] , V_137 - V_141 , & V_143 ) ;
if ( V_145 < 0 )
goto V_148;
if ( V_143 > V_149 )
goto V_148;
V_144 = V_35 -> V_150 ( V_143 , & V_46 [ V_142 ] , V_137 - V_142 ) ;
if ( V_144 < 0 )
goto V_148;
}
V_46 [ V_142 ] = '\0' ;
* V_139 = V_142 ;
F_6 ( V_12 , L_42 ) ;
return V_142 ;
V_148:
F_7 ( V_12 , L_43
L_44 , V_35 -> V_151 ) ;
F_6 ( V_12 , L_42 ) ;
F_16 ( V_46 ) ;
return - V_152 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_136 ,
int V_137 , char * * V_138 , int * V_139 )
{
struct V_140 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_141 , V_142 ;
T_11 V_143 ;
int V_144 , V_145 ;
char * V_46 ;
int V_146 = ( 3 * V_137 ) + 1 ;
F_6 ( V_12 , L_45 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_46 ) ;
return - V_147 ;
}
* V_138 = V_46 = F_58 ( V_146 , V_134 ) ;
if ( ! * V_138 ) {
F_7 ( V_12 , L_47 ) ;
* V_139 = 0 ;
return - V_131 ;
}
for ( V_141 = V_142 = 0 ; V_141 < V_137 ; V_141 += V_144 , V_142 += V_145 ) {
V_144 = V_35 -> V_153 ( & V_136 [ V_141 ] , V_137 - V_141 , & V_143 ) ;
if ( V_144 < 0 )
goto V_148;
V_145 = F_64 ( V_143 , & V_46 [ V_142 ] , 3 ) ;
if ( V_145 <= 0 )
goto V_148;
}
V_46 [ V_142 ] = '\0' ;
* V_139 = V_142 ;
F_6 ( V_12 , L_48 ) ;
return V_141 ;
V_148:
F_7 ( V_12 , L_49
L_44 , V_35 -> V_151 ) ;
F_6 ( V_12 , L_48 ) ;
F_16 ( V_46 ) ;
return - V_152 ;
}
static int
F_65 ( char * V_154 , T_12 * V_155 )
{
char * V_135 ;
T_13 args [ V_156 ] ;
int V_157 ;
V_155 -> V_89 = 0 ;
V_155 -> V_93 = 0 ;
V_155 -> V_88 = 0 ;
V_155 -> V_92 = 0 ;
V_155 -> V_158 = NULL ;
V_155 -> V_159 = 0 ;
if ( ! V_154 )
return 1 ;
while ( ( V_135 = F_66 ( & V_154 , L_50 ) ) != NULL ) {
int V_160 ;
if ( ! * V_135 )
continue;
V_160 = F_67 ( V_135 , V_161 , args ) ;
switch ( V_160 ) {
case V_162 :
if ( F_68 ( & args [ 0 ] , & V_157 ) )
return 0 ;
if ( V_157 < 0 ) {
F_54 ( V_130 L_51
L_52 , V_157 ) ;
break;
}
V_155 -> V_89 = V_157 ;
V_155 -> V_88 = 1 ;
break;
case V_163 :
if ( F_68 ( & args [ 0 ] , & V_157 ) )
return 0 ;
if ( V_157 < 0 ) {
F_54 ( V_130 L_53
L_52 , V_157 ) ;
break;
}
V_155 -> V_93 = V_157 ;
V_155 -> V_92 = 1 ;
break;
case V_164 :
F_16 ( V_155 -> V_158 ) ;
V_155 -> V_158 = F_69 ( & args [ 0 ] ) ;
if ( ! V_155 -> V_158 ) {
F_54 ( V_130 L_54
L_55 ) ;
return 0 ;
}
break;
case V_165 :
V_155 -> V_159 = 1 ;
break;
default:
F_54 ( V_130 L_56
L_57 , V_135 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_70 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_87 . V_158 ) ;
F_12 ( V_12 ) -> V_87 . V_158 = NULL ;
F_71 ( F_12 ( V_12 ) -> V_35 ) ;
F_16 ( V_12 -> V_166 ) ;
V_12 -> V_166 = NULL ;
}
static int
F_72 ( struct V_11 * V_12 , void * V_114 , int V_167 )
{
struct V_8 * V_70 ;
T_9 * V_72 ;
T_14 * V_168 ;
struct V_7 * V_169 ;
long V_30 = - V_147 ;
const unsigned long V_170 = 0 ;
const T_15 V_171 = 512 ;
F_73 ( V_12 , V_114 ) ;
V_12 -> V_166 = F_58 ( sizeof ( * V_72 ) , V_62 ) ;
if ( V_12 -> V_166 == NULL ) {
F_54 ( V_130
L_58
L_59 , V_12 -> V_172 ) ;
goto V_80;
}
V_72 = F_12 ( V_12 ) ;
memset ( V_72 , 0 , sizeof( T_9 ) ) ;
if ( ! F_65 ( ( char * ) V_114 , & V_72 -> V_87 ) ) {
F_7 ( V_12 , L_60 ) ;
goto V_173;
}
F_6 ( V_12 , L_61 ) ;
#ifndef F_74
if ( ! ( V_12 -> V_174 & V_175 ) ) {
F_17 ( V_12 ,
L_62 ) ;
V_12 -> V_174 |= V_175 ;
}
#endif
F_75 ( V_12 , 1024 ) ;
if ( ! ( V_70 = F_76 ( V_12 , V_170 ) ) ) {
F_7 ( V_12 , L_63 ) ;
goto V_173;
}
V_168 = ( T_14 * ) V_70 -> V_81 ;
if ( ( V_168 -> V_176 == V_177 ) ||
( V_168 -> V_176 == V_178 ) ) {
F_6 ( V_12 , L_64 ) ;
} else {
F_6 ( V_12 , L_65 ) ;
V_168 =
( T_14 * ) ( ( void * ) V_70 -> V_81 + V_171 ) ;
}
if ( F_77 ( V_12 , V_168 ) != V_23 )
goto V_82;
F_78 ( V_12 , V_168 ) ;
F_49 ( V_70 ) ;
if ( F_79 ( V_12 ) != V_23 )
goto V_173;
if( V_72 -> V_179 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_66
L_67 ,
V_72 -> V_179 ) ;
goto V_173;
}
V_12 -> V_180 = V_181 ;
F_80 ( V_12 , ( T_4 ) V_72 -> V_111 ) ;
V_12 -> V_182 = & V_183 ;
V_169 = F_18 ( V_12 , F_9 ( V_12 , & ( V_72 -> V_184 ) ) ) ;
if ( F_19 ( V_169 ) ) {
V_30 = F_81 ( V_169 ) ;
goto V_173;
}
V_12 -> V_185 = F_82 ( V_169 ) ;
if ( ! V_12 -> V_185 ) {
F_83 ( V_169 ) ;
F_7 ( V_12 , L_68 ) ;
goto V_173;
}
if ( V_72 -> V_87 . V_158 ) {
F_6 ( V_12 , L_69 ,
V_72 -> V_87 . V_158 ) ;
V_72 -> V_35 = F_84 ( V_72 -> V_87 . V_158 ) ;
if ( ! V_72 -> V_35 ) {
F_17 ( V_12 , L_70
L_71 ,
V_72 -> V_87 . V_158 ) ;
V_72 -> V_35 = F_85 () ;
}
} else {
F_6 ( V_12 , L_72 ) ;
V_72 -> V_35 = F_85 () ;
}
return 0 ;
V_82:
F_49 ( V_70 ) ;
V_173:
F_16 ( V_72 -> V_87 . V_158 ) ;
F_16 ( V_12 -> V_166 ) ;
V_80:
V_12 -> V_166 = NULL ;
return V_30 ;
}
static int
F_86 ( struct V_11 * V_12 , int * V_107 , char * V_114 )
{
if ( ! ( * V_107 & V_175 ) )
return - V_147 ;
return 0 ;
}
static int
F_87 ( struct V_25 * V_25 , struct V_186 * V_187 )
{
struct V_11 * V_12 = V_25 -> V_133 ;
T_16 V_188 = F_88 ( V_12 -> V_189 -> V_190 ) ;
F_6 ( V_12 , L_73 ) ;
V_187 -> V_191 = V_181 ;
V_187 -> V_192 = V_12 -> V_193 ;
V_187 -> V_194 = F_12 ( V_12 ) -> V_179 ;
V_187 -> V_195 = F_12 ( V_12 ) -> V_179 - F_12 ( V_12 ) -> V_196 ;
V_187 -> V_197 = V_187 -> V_195 ;
V_187 -> V_198 = 0 ;
V_187 -> V_199 = 0 ;
V_187 -> V_200 . V_201 [ 0 ] = ( V_202 ) V_188 ;
V_187 -> V_200 . V_201 [ 1 ] = ( V_202 ) ( V_188 >> 32 ) ;
V_187 -> V_203 = V_50 ;
F_6 ( V_12 , L_74 ) ;
return 0 ;
}
static struct V_25 *
F_89 ( struct V_204 * V_205 , int V_107 , const char * V_206 ,
void * V_114 )
{
return F_90 ( V_205 , V_107 , V_206 , V_114 , F_72 ) ;
}
static int T_17
F_91 ( void )
{
int V_207 ;
F_54 ( V_208 L_75 , V_209 ) ;
V_207 = F_52 () ;
if ( V_207 )
goto V_80;
V_207 = F_92 ( & V_210 ) ;
if ( V_207 )
goto V_211;
return 0 ;
V_211:
F_55 () ;
V_80:
return V_207 ;
}
static void T_18
F_93 ( void )
{
F_55 () ;
F_94 ( & V_210 ) ;
}
