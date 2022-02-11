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
F_11 ( struct V_7 * V_26 , struct V_25 * V_25 , unsigned int V_27 )
{
struct V_7 * V_7 = NULL ;
struct V_11 * V_12 = V_26 -> V_13 ;
T_2 * V_14 = & F_5 ( V_26 ) -> V_15 . V_14 ;
T_5 V_28 ;
int V_29 ;
int V_30 ;
char * V_31 ;
const char * V_32 = V_25 -> V_33 . V_32 ;
F_6 ( V_12 , L_10
L_11 , V_25 -> V_33 . V_32 , V_26 -> V_20 ) ;
if ( F_12 ( V_12 ) -> V_34 ) {
V_29 =
F_13 ( V_12 , V_32 , strlen ( V_32 ) , & V_31 , & V_30 ) ;
if ( V_29 < 0 ) {
F_6 ( V_12 , L_12 ) ;
return F_14 ( V_29 ) ;
}
V_29 = F_15 ( V_12 , V_14 , V_31 , & V_28 ) ;
F_16 ( V_31 ) ;
} else {
V_29 = F_15 ( V_12 , V_14 , V_25 -> V_33 . V_32 , & V_28 ) ;
}
if ( V_29 == V_35 ) {
F_6 ( V_12 , L_13 ,
V_25 -> V_33 . V_32 ) ;
return F_14 ( - V_36 ) ;
} else if ( V_29 != V_23 || V_28 == 0 ) {
F_17 ( V_12 , L_14 ) ;
return F_14 ( - V_37 ) ;
}
V_7 = F_18 ( V_26 -> V_13 , ( V_38 ) V_28 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_21 ( V_25 , V_7 ) ;
F_6 ( V_12 , L_15 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_7 * V_7 = F_23 ( V_1 ) ;
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_41 ;
int V_42 ;
T_6 V_43 ;
unsigned char V_44 ;
char V_45 [ V_46 + 1 ] ;
const char * V_47 = V_1 -> V_48 . V_25 -> V_33 . V_32 ;
F_6 ( V_12 , L_16
L_17 ,
V_47 , V_7 -> V_20 , V_40 -> V_49 ) ;
V_50:
V_42 = F_24 ( V_12 , V_14 , V_40 -> V_49 , V_46 + 1 ,
V_45 , & V_43 , & V_41 ) ;
if ( V_42 == V_51 ) {
F_6 ( V_12 , L_18 ) ;
F_7 ( V_12 , L_19 ,
V_47 , V_7 -> V_20 ) ;
return - V_21 ;
} else if ( V_42 == V_52 ) {
F_6 ( V_12 , L_20 ) ;
return 0 ;
} else if ( V_42 == V_53 ) {
F_6 ( V_12 , L_21 ) ;
return 0 ;
}
V_44 = V_54 ;
if ( F_12 ( V_12 ) -> V_34 ) {
char * V_55 ;
int V_56 ;
V_42 =
F_25 ( V_12 , V_45 , V_43 , & V_55 , & V_56 ) ;
if ( V_42 < 0 ) {
F_6 ( V_12 , L_18 ) ;
return V_42 ;
}
if ( ! F_26 ( V_40 , V_55 , V_56 ,
( V_38 ) V_41 , V_44 ) ) {
F_16 ( V_55 ) ;
return 0 ;
}
F_16 ( V_55 ) ;
} else {
if ( ! F_26 ( V_40 , V_45 , V_43 ,
( V_38 ) V_41 , V_44 ) )
return 0 ;
}
V_40 -> V_49 ++ ;
goto V_50;
F_6 ( V_12 , L_22 , V_40 -> V_49 ) ;
return 0 ;
}
static struct V_7 *
F_27 ( struct V_11 * V_12 )
{
struct V_57 * V_58 ;
V_58 = (struct V_57 * ) F_28 ( V_59 ,
V_60 ) ;
if ( ! V_58 )
return NULL ;
return & V_58 -> V_61 ;
}
static void F_29 ( struct V_62 * V_63 )
{
struct V_7 * V_7 = F_30 ( V_63 , struct V_7 , V_64 ) ;
F_31 ( V_59 , F_5 ( V_7 ) ) ;
}
static void F_32 ( struct V_7 * V_7 )
{
F_33 ( & V_7 -> V_64 , F_29 ) ;
}
static void F_34 ( void * V_65 )
{
struct V_57 * V_58 = (struct V_57 * ) V_65 ;
F_35 ( & V_58 -> V_61 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_66 )
{
struct V_8 * V_67 = NULL ;
T_7 * V_68 = NULL ;
T_8 * V_69 = F_12 ( V_12 ) ;
V_57 * V_70 = NULL ;
struct V_7 * V_7 ;
long V_29 = - V_21 ;
F_6 ( V_12 , L_23 L_24 , V_66 ) ;
V_7 = F_36 ( V_12 , V_66 ) ;
if ( F_19 ( V_7 ) )
return V_7 ;
if ( ! ( V_7 -> V_71 & V_72 ) )
return V_7 ;
V_70 = F_5 ( V_7 ) ;
V_70 -> V_73 = F_37 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_25 ,
V_70 -> V_73 . V_74 ,
V_70 -> V_73 . V_75 , V_70 -> V_73 . V_76 ) ;
V_67 = F_38 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_67 ) {
F_7 ( V_12 , L_26
L_24 , V_7 -> V_20 ) ;
goto V_77;
}
V_68 = ( T_7 * ) V_67 -> V_78 ;
F_39 ( V_12 , V_68 ) ;
if ( F_40 ( V_12 , V_68 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_27 , V_7 -> V_20 ) ;
goto V_79;
}
V_7 -> V_80 = ( V_81 ) F_41 ( V_12 , V_68 -> V_82 ) ;
V_7 -> V_83 = V_69 -> V_84 . V_85 ?
V_69 -> V_84 . V_86 :
F_42 ( & V_87 , F_41 ( V_12 , V_68 -> V_86 ) ) ;
V_7 -> V_88 = V_69 -> V_84 . V_89 ?
V_69 -> V_84 . V_90 :
F_43 ( & V_87 , F_41 ( V_12 , V_68 -> V_90 ) ) ;
F_44 ( V_7 , 1 ) ;
V_7 -> V_91 . V_92 =
F_45 ( V_12 , V_68 -> V_93 ) >> 16 ;
V_7 -> V_91 . V_94 = 0 ;
V_7 -> V_95 = V_7 -> V_91 ;
V_7 -> V_96 = V_7 -> V_91 ;
V_70 -> V_73 = F_46 ( V_12 , V_68 -> V_97 ) ;
V_70 -> V_98 = F_46 ( V_12 , V_68 -> V_99 ) ;
V_70 -> V_100 = F_46 ( V_12 , V_68 -> V_101 ) ;
V_70 -> V_102 = F_41 ( V_12 , V_68 -> V_27 ) ;
if ( F_47 ( V_7 -> V_80 ) && ! ( V_70 -> V_102 & V_103 ) ) {
V_7 -> V_104 = 0 ;
V_7 -> V_105 = V_69 -> V_106 / V_107 ;
strncpy ( V_70 -> V_15 . V_108 , V_68 -> V_109 . V_108 ,
V_110 - 1 ) ;
V_70 -> V_15 . V_108 [ V_110 - 1 ] = '\0' ;
} else {
int V_111 ;
V_70 -> V_15 . V_14 =
F_48 ( V_12 , & V_68 -> V_109 . V_112 ) ;
V_111 = F_49 ( V_12 , & V_70 -> V_15 . V_14 ) ;
V_7 -> V_105 =
V_111 * ( V_69 -> V_106 / V_107 ) ;
V_7 -> V_104 = V_70 -> V_15 . V_14 . V_113 ;
}
V_7 -> V_114 -> V_115 = & V_116 ;
if ( F_50 ( V_7 -> V_80 ) ) {
V_7 -> V_117 = & V_118 ;
} else if ( F_51 ( V_7 -> V_80 ) ) {
V_7 -> V_119 = & V_120 ;
V_7 -> V_117 = & V_121 ;
} else if ( F_47 ( V_7 -> V_80 ) ) {
V_7 -> V_119 = & V_122 ;
} else {
F_7 ( V_12 , L_28
L_29
L_30 , V_7 -> V_20 ) ;
goto V_79;
}
F_52 ( V_67 ) ;
F_6 ( V_12 , L_31 ) ;
F_53 ( V_7 ) ;
return V_7 ;
V_79:
F_52 ( V_67 ) ;
V_77:
F_54 ( V_7 ) ;
F_6 ( V_12 , L_32 ) ;
return F_14 ( V_29 ) ;
}
static int
F_55 ( void )
{
V_59 = F_56 ( L_33 ,
sizeof ( struct V_57 ) ,
0 , ( V_123 |
V_124 ) ,
F_34 ) ;
if ( V_59 == NULL ) {
F_57 ( V_125 L_34
L_35 ) ;
return - V_126 ;
}
return 0 ;
}
static void
F_58 ( void )
{
F_59 () ;
F_60 ( V_59 ) ;
}
static void *
F_61 ( struct V_25 * V_25 , struct V_127 * V_128 )
{
V_57 * V_70 = F_5 ( V_25 -> V_129 ) ;
char * V_130 ;
if ( V_70 -> V_102 & V_103 ) {
struct V_11 * V_12 = V_25 -> V_131 ;
T_2 * V_109 = & V_70 -> V_15 . V_14 ;
T_5 V_76 = V_109 -> V_113 ;
if ( V_76 == 0 ) {
F_7 ( V_12 , L_36 ) ;
V_130 = F_14 ( - V_21 ) ;
} else {
F_6 ( V_12 , L_37 ) ;
V_130 = F_62 ( V_76 , V_132 ) ;
if ( ! V_130 ) {
V_130 = F_14 ( - V_126 ) ;
} else if ( F_63 ( V_12 , V_109 , V_130 , V_76 ) != V_76 ) {
F_16 ( V_130 ) ;
F_7 ( V_12 , L_38 ) ;
V_130 = F_14 ( - V_21 ) ;
} else {
V_130 [ V_76 - 1 ] = '\0' ;
}
}
} else {
V_130 = V_70 -> V_15 . V_108 ;
}
F_64 ( V_128 , V_130 ) ;
return NULL ;
}
static void F_65 ( struct V_25 * V_25 , struct V_127 * V_128 , void * V_133 )
{
V_57 * V_70 = F_5 ( V_25 -> V_129 ) ;
if ( V_70 -> V_102 & V_103 ) {
char * V_130 = F_66 ( V_128 ) ;
if ( ! F_19 ( V_130 ) )
F_16 ( V_130 ) ;
}
}
static int
F_25 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_9 V_141 ;
int V_142 , V_143 ;
char * V_42 ;
int V_144 = V_135 + 1 ;
F_6 ( V_12 , L_39 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_40 ) ;
return - V_145 ;
}
* V_136 = V_42 = F_62 ( V_144 , V_132 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_41 ) ;
* V_137 = 0 ;
return - V_126 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_143 , V_140 += V_142 ) {
V_143 = F_67 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_143 < 0 )
goto V_146;
if ( V_141 > V_147 )
goto V_146;
V_142 = V_34 -> V_148 ( V_141 , & V_42 [ V_140 ] , V_135 - V_140 ) ;
if ( V_142 < 0 )
goto V_146;
}
V_42 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_42 ) ;
return V_140 ;
V_146:
F_7 ( V_12 , L_43
L_44 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_42 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_10 V_141 ;
int V_142 , V_143 ;
char * V_42 ;
int V_144 = ( 3 * V_135 ) + 1 ;
F_6 ( V_12 , L_45 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_46 ) ;
return - V_145 ;
}
* V_136 = V_42 = F_62 ( V_144 , V_132 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_47 ) ;
* V_137 = 0 ;
return - V_126 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_142 , V_140 += V_143 ) {
V_142 = V_34 -> V_151 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_142 < 0 )
goto V_146;
V_143 = F_68 ( V_141 , & V_42 [ V_140 ] , 3 ) ;
if ( V_143 <= 0 )
goto V_146;
}
V_42 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_48 ) ;
return V_139 ;
V_146:
F_7 ( V_12 , L_49
L_44 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_48 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static int
F_69 ( char * V_152 , T_11 * V_153 )
{
char * V_133 ;
T_12 args [ V_154 ] ;
int V_155 ;
T_13 V_86 ;
T_14 V_90 ;
V_153 -> V_86 = V_156 ;
V_153 -> V_90 = V_157 ;
V_153 -> V_85 = 0 ;
V_153 -> V_89 = 0 ;
V_153 -> V_158 = NULL ;
V_153 -> V_159 = 0 ;
if ( ! V_152 )
return 1 ;
while ( ( V_133 = F_70 ( & V_152 , L_50 ) ) != NULL ) {
int V_160 ;
if ( ! * V_133 )
continue;
V_160 = F_71 ( V_133 , V_161 , args ) ;
switch ( V_160 ) {
case V_162 :
if ( F_72 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_86 = V_163 ;
if ( V_155 >= 0 )
V_86 = F_42 ( F_73 () , V_155 ) ;
if ( ! F_74 ( V_86 ) ) {
F_57 ( V_125 L_51
L_52 , V_155 ) ;
break;
}
V_153 -> V_86 = V_86 ;
V_153 -> V_85 = 1 ;
break;
case V_164 :
if ( F_72 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_90 = V_165 ;
if ( V_155 >= 0 )
V_90 = F_43 ( F_73 () , V_155 ) ;
if ( ! F_75 ( V_90 ) ) {
F_57 ( V_125 L_53
L_52 , V_155 ) ;
break;
}
V_153 -> V_90 = V_90 ;
V_153 -> V_89 = 1 ;
break;
case V_166 :
F_16 ( V_153 -> V_158 ) ;
V_153 -> V_158 = F_76 ( & args [ 0 ] ) ;
if ( ! V_153 -> V_158 ) {
F_57 ( V_125 L_54
L_55 ) ;
return 0 ;
}
break;
case V_167 :
V_153 -> V_159 = 1 ;
break;
default:
F_57 ( V_125 L_56
L_57 , V_133 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_77 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_84 . V_158 ) ;
F_12 ( V_12 ) -> V_84 . V_158 = NULL ;
F_78 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_168 ) ;
V_12 -> V_168 = NULL ;
}
static int
F_79 ( struct V_11 * V_12 , void * V_109 , int V_169 )
{
struct V_8 * V_67 ;
T_8 * V_69 ;
T_15 * V_170 ;
struct V_7 * V_171 ;
long V_29 = - V_145 ;
const unsigned long V_172 = 0 ;
const T_16 V_173 = 512 ;
F_80 ( V_12 , V_109 ) ;
V_12 -> V_168 = F_62 ( sizeof ( * V_69 ) , V_60 ) ;
if ( V_12 -> V_168 == NULL ) {
F_57 ( V_125
L_58
L_59 , V_12 -> V_174 ) ;
goto V_77;
}
V_69 = F_12 ( V_12 ) ;
memset ( V_69 , 0 , sizeof( T_8 ) ) ;
if ( ! F_69 ( ( char * ) V_109 , & V_69 -> V_84 ) ) {
F_7 ( V_12 , L_60 ) ;
goto V_175;
}
F_6 ( V_12 , L_61 ) ;
#ifndef F_81
if ( ! ( V_12 -> V_176 & V_177 ) ) {
F_17 ( V_12 ,
L_62 ) ;
V_12 -> V_176 |= V_177 ;
}
#endif
F_82 ( V_12 , 1024 ) ;
if ( ! ( V_67 = F_83 ( V_12 , V_172 ) ) ) {
F_7 ( V_12 , L_63 ) ;
goto V_175;
}
V_170 = ( T_15 * ) V_67 -> V_78 ;
if ( ( V_170 -> V_178 == V_179 ) ||
( V_170 -> V_178 == V_180 ) ) {
F_6 ( V_12 , L_64 ) ;
} else {
F_6 ( V_12 , L_65 ) ;
V_170 =
( T_15 * ) ( ( void * ) V_67 -> V_78 + V_173 ) ;
}
if ( F_84 ( V_12 , V_170 ) != V_23 )
goto V_79;
F_85 ( V_12 , V_170 ) ;
F_52 ( V_67 ) ;
if ( F_86 ( V_12 ) != V_23 )
goto V_175;
if( V_69 -> V_181 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_66
L_67 ,
V_69 -> V_181 ) ;
goto V_175;
}
V_12 -> V_182 = V_183 ;
F_87 ( V_12 , ( T_4 ) V_69 -> V_106 ) ;
V_12 -> V_184 = & V_185 ;
V_171 = F_18 ( V_12 , F_9 ( V_12 , & ( V_69 -> V_186 ) ) ) ;
if ( F_19 ( V_171 ) ) {
V_29 = F_88 ( V_171 ) ;
goto V_175;
}
V_12 -> V_187 = F_89 ( V_171 ) ;
if ( ! V_12 -> V_187 ) {
F_7 ( V_12 , L_68 ) ;
goto V_175;
}
if ( V_69 -> V_84 . V_158 ) {
F_6 ( V_12 , L_69 ,
V_69 -> V_84 . V_158 ) ;
V_69 -> V_34 = F_90 ( V_69 -> V_84 . V_158 ) ;
if ( ! V_69 -> V_34 ) {
F_17 ( V_12 , L_70
L_71 ,
V_69 -> V_84 . V_158 ) ;
V_69 -> V_34 = F_91 () ;
}
} else {
F_6 ( V_12 , L_72 ) ;
V_69 -> V_34 = F_91 () ;
}
return 0 ;
V_79:
F_52 ( V_67 ) ;
V_175:
F_16 ( V_69 -> V_84 . V_158 ) ;
F_16 ( V_12 -> V_168 ) ;
V_77:
V_12 -> V_168 = NULL ;
return V_29 ;
}
static int
F_92 ( struct V_11 * V_12 , int * V_27 , char * V_109 )
{
if ( ! ( * V_27 & V_177 ) )
return - V_145 ;
return 0 ;
}
static int
F_93 ( struct V_25 * V_25 , struct V_188 * V_189 )
{
struct V_11 * V_12 = V_25 -> V_131 ;
T_17 V_190 = F_94 ( V_12 -> V_191 -> V_192 ) ;
F_6 ( V_12 , L_73 ) ;
V_189 -> V_193 = V_183 ;
V_189 -> V_194 = V_12 -> V_195 ;
V_189 -> V_196 = F_12 ( V_12 ) -> V_181 ;
V_189 -> V_197 = F_12 ( V_12 ) -> V_181 - F_12 ( V_12 ) -> V_198 ;
V_189 -> V_199 = V_189 -> V_197 ;
V_189 -> V_200 = 0 ;
V_189 -> V_201 = 0 ;
V_189 -> V_202 . V_203 [ 0 ] = ( V_204 ) V_190 ;
V_189 -> V_202 . V_203 [ 1 ] = ( V_204 ) ( V_190 >> 32 ) ;
V_189 -> V_205 = V_46 ;
F_6 ( V_12 , L_74 ) ;
return 0 ;
}
static struct V_25 *
F_95 ( struct V_206 * V_207 , int V_27 , const char * V_208 ,
void * V_109 )
{
return F_96 ( V_207 , V_27 , V_208 , V_109 , F_79 ) ;
}
static int T_18
F_97 ( void )
{
int V_209 ;
F_57 ( V_210 L_75 , V_211 ) ;
V_209 = F_55 () ;
if ( V_209 )
goto V_77;
V_209 = F_98 ( & V_212 ) ;
if ( V_209 )
goto V_213;
return 0 ;
V_213:
F_58 () ;
V_77:
return V_209 ;
}
static void T_19
F_99 ( void )
{
F_58 () ;
F_100 ( & V_212 ) ;
}
