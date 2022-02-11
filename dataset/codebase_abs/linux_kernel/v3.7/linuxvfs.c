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
F_22 ( struct V_1 * V_39 , void * V_40 , T_6 V_41 )
{
struct V_7 * V_7 = V_39 -> V_42 . V_25 -> V_43 ;
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_44 ;
int V_45 ;
T_7 V_46 ;
unsigned char V_47 ;
char V_48 [ V_49 + 1 ] ;
char * V_50 ;
int V_51 ;
const char * V_52 = V_39 -> V_42 . V_25 -> V_33 . V_32 ;
F_6 ( V_12 , L_16
L_17 ,
V_52 , V_7 -> V_20 , V_39 -> V_53 ) ;
V_45 = F_23 ( V_12 , V_14 , V_39 -> V_53 , V_49 + 1 ,
V_48 , & V_46 , & V_44 ) ;
if ( V_45 == V_54 ) {
F_6 ( V_12 , L_18 ) ;
F_7 ( V_12 , L_19 ,
V_52 , V_7 -> V_20 ) ;
return - V_21 ;
} else if ( V_45 == V_55 ) {
F_6 ( V_12 , L_20 ) ;
return 0 ;
} else if ( V_45 == V_56 ) {
F_6 ( V_12 , L_21 ) ;
return 0 ;
}
V_47 = V_57 ;
if ( F_12 ( V_12 ) -> V_34 ) {
V_45 =
F_24 ( V_12 , V_48 , V_46 , & V_50 , & V_51 ) ;
if ( V_45 < 0 ) {
F_6 ( V_12 , L_18 ) ;
return V_45 ;
}
V_45 = V_41 ( V_40 , V_50 , V_51 , V_39 -> V_53 ,
( V_38 ) V_44 , V_47 ) ;
F_16 ( V_50 ) ;
} else {
V_45 = V_41 ( V_40 , V_48 , V_46 , V_39 -> V_53 ,
( V_38 ) V_44 , V_47 ) ;
}
V_39 -> V_53 ++ ;
F_6 ( V_12 , L_22 , V_39 -> V_53 ) ;
return 0 ;
}
static struct V_7 *
F_25 ( struct V_11 * V_12 )
{
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) F_26 ( V_60 ,
V_61 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_62 ;
}
static void F_27 ( struct V_63 * V_64 )
{
struct V_7 * V_7 = F_28 ( V_64 , struct V_7 , V_65 ) ;
F_29 ( V_60 , F_5 ( V_7 ) ) ;
}
static void F_30 ( struct V_7 * V_7 )
{
F_31 ( & V_7 -> V_65 , F_27 ) ;
}
static void F_32 ( void * V_66 )
{
struct V_58 * V_59 = (struct V_58 * ) V_66 ;
F_33 ( & V_59 -> V_62 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_67 )
{
struct V_8 * V_68 = NULL ;
T_8 * V_69 = NULL ;
T_9 * V_70 = F_12 ( V_12 ) ;
V_58 * V_71 = NULL ;
struct V_7 * V_7 ;
long V_29 = - V_21 ;
F_6 ( V_12 , L_23 L_24 , V_67 ) ;
V_7 = F_34 ( V_12 , V_67 ) ;
if ( F_19 ( V_7 ) )
return V_7 ;
if ( ! ( V_7 -> V_72 & V_73 ) )
return V_7 ;
V_71 = F_5 ( V_7 ) ;
V_71 -> V_74 = F_35 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_25 ,
V_71 -> V_74 . V_75 ,
V_71 -> V_74 . V_76 , V_71 -> V_74 . V_77 ) ;
V_68 = F_36 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_68 ) {
F_7 ( V_12 , L_26
L_24 , V_7 -> V_20 ) ;
goto V_78;
}
V_69 = ( T_8 * ) V_68 -> V_79 ;
F_37 ( V_12 , V_69 ) ;
if ( F_38 ( V_12 , V_69 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_27 , V_7 -> V_20 ) ;
goto V_80;
}
V_7 -> V_81 = ( V_82 ) F_39 ( V_12 , V_69 -> V_83 ) ;
V_7 -> V_84 = V_70 -> V_85 . V_86 ?
V_70 -> V_85 . V_87 :
F_40 ( & V_88 , F_39 ( V_12 , V_69 -> V_87 ) ) ;
V_7 -> V_89 = V_70 -> V_85 . V_90 ?
V_70 -> V_85 . V_91 :
F_41 ( & V_88 , F_39 ( V_12 , V_69 -> V_91 ) ) ;
F_42 ( V_7 , 1 ) ;
V_7 -> V_92 . V_93 =
F_43 ( V_12 , V_69 -> V_94 ) >> 16 ;
V_7 -> V_92 . V_95 = 0 ;
V_7 -> V_96 = V_7 -> V_92 ;
V_7 -> V_97 = V_7 -> V_92 ;
V_71 -> V_74 = F_44 ( V_12 , V_69 -> V_98 ) ;
V_71 -> V_99 = F_44 ( V_12 , V_69 -> V_100 ) ;
V_71 -> V_101 = F_44 ( V_12 , V_69 -> V_102 ) ;
V_71 -> V_103 = F_39 ( V_12 , V_69 -> V_27 ) ;
if ( F_45 ( V_7 -> V_81 ) && ! ( V_71 -> V_103 & V_104 ) ) {
V_7 -> V_105 = 0 ;
V_7 -> V_106 = V_70 -> V_107 / V_108 ;
strncpy ( V_71 -> V_15 . V_109 , V_69 -> V_110 . V_109 ,
V_111 - 1 ) ;
V_71 -> V_15 . V_109 [ V_111 - 1 ] = '\0' ;
} else {
int V_112 ;
V_71 -> V_15 . V_14 =
F_46 ( V_12 , & V_69 -> V_110 . V_113 ) ;
V_112 = F_47 ( V_12 , & V_71 -> V_15 . V_14 ) ;
V_7 -> V_106 =
V_112 * ( V_70 -> V_107 / V_108 ) ;
V_7 -> V_105 = V_71 -> V_15 . V_14 . V_114 ;
}
V_7 -> V_115 -> V_116 = & V_117 ;
if ( F_48 ( V_7 -> V_81 ) ) {
V_7 -> V_118 = & V_119 ;
} else if ( F_49 ( V_7 -> V_81 ) ) {
V_7 -> V_120 = & V_121 ;
V_7 -> V_118 = & V_122 ;
} else if ( F_45 ( V_7 -> V_81 ) ) {
V_7 -> V_120 = & V_123 ;
} else {
F_7 ( V_12 , L_28
L_29
L_30 , V_7 -> V_20 ) ;
goto V_80;
}
F_50 ( V_68 ) ;
F_6 ( V_12 , L_31 ) ;
F_51 ( V_7 ) ;
return V_7 ;
V_80:
F_50 ( V_68 ) ;
V_78:
F_52 ( V_7 ) ;
F_6 ( V_12 , L_32 ) ;
return F_14 ( V_29 ) ;
}
static int
F_53 ( void )
{
V_60 = F_54 ( L_33 ,
sizeof ( struct V_58 ) ,
0 , ( V_124 |
V_125 ) ,
F_32 ) ;
if ( V_60 == NULL ) {
F_55 ( V_126 L_34
L_35 ) ;
return - V_127 ;
}
return 0 ;
}
static void
F_56 ( void )
{
F_57 () ;
F_58 ( V_60 ) ;
}
static void *
F_59 ( struct V_25 * V_25 , struct V_128 * V_129 )
{
V_58 * V_71 = F_5 ( V_25 -> V_43 ) ;
char * V_130 ;
if ( V_71 -> V_103 & V_104 ) {
struct V_11 * V_12 = V_25 -> V_131 ;
T_2 * V_110 = & V_71 -> V_15 . V_14 ;
T_5 V_77 = V_110 -> V_114 ;
if ( V_77 == 0 ) {
F_7 ( V_12 , L_36 ) ;
V_130 = F_14 ( - V_21 ) ;
} else {
F_6 ( V_12 , L_37 ) ;
V_130 = F_60 ( V_77 , V_132 ) ;
if ( ! V_130 ) {
V_130 = F_14 ( - V_127 ) ;
} else if ( F_61 ( V_12 , V_110 , V_130 , V_77 ) != V_77 ) {
F_16 ( V_130 ) ;
F_7 ( V_12 , L_38 ) ;
V_130 = F_14 ( - V_21 ) ;
} else {
V_130 [ V_77 - 1 ] = '\0' ;
}
}
} else {
V_130 = V_71 -> V_15 . V_109 ;
}
F_62 ( V_129 , V_130 ) ;
return NULL ;
}
static void F_63 ( struct V_25 * V_25 , struct V_128 * V_129 , void * V_133 )
{
V_58 * V_71 = F_5 ( V_25 -> V_43 ) ;
if ( V_71 -> V_103 & V_104 ) {
char * V_130 = F_64 ( V_129 ) ;
if ( ! F_19 ( V_130 ) )
F_16 ( V_130 ) ;
}
}
static int
F_24 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_10 V_141 ;
int V_142 , V_143 ;
char * V_45 ;
int V_144 = V_135 + 1 ;
F_6 ( V_12 , L_39 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_40 ) ;
return - V_145 ;
}
* V_136 = V_45 = F_60 ( V_144 , V_132 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_41 ) ;
* V_137 = 0 ;
return - V_127 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_143 , V_140 += V_142 ) {
V_143 = F_65 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_143 < 0 )
goto V_146;
if ( V_141 > V_147 )
goto V_146;
V_142 = V_34 -> V_148 ( V_141 , & V_45 [ V_140 ] , V_135 - V_140 ) ;
if ( V_142 < 0 )
goto V_146;
}
V_45 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_42 ) ;
return V_140 ;
V_146:
F_7 ( V_12 , L_43
L_44 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_42 ) ;
F_16 ( V_45 ) ;
return - V_150 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_11 V_141 ;
int V_142 , V_143 ;
char * V_45 ;
int V_144 = ( 3 * V_135 ) + 1 ;
F_6 ( V_12 , L_45 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_46 ) ;
return - V_145 ;
}
* V_136 = V_45 = F_60 ( V_144 , V_132 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_47 ) ;
* V_137 = 0 ;
return - V_127 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_142 , V_140 += V_143 ) {
V_142 = V_34 -> V_151 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_142 < 0 )
goto V_146;
V_143 = F_66 ( V_141 , & V_45 [ V_140 ] , 3 ) ;
if ( V_143 <= 0 )
goto V_146;
}
V_45 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_48 ) ;
return V_139 ;
V_146:
F_7 ( V_12 , L_49
L_44 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_48 ) ;
F_16 ( V_45 ) ;
return - V_150 ;
}
static int
F_67 ( char * V_152 , T_12 * V_153 )
{
char * V_133 ;
T_13 args [ V_154 ] ;
int V_155 ;
T_14 V_87 ;
T_15 V_91 ;
V_153 -> V_87 = V_156 ;
V_153 -> V_91 = V_157 ;
V_153 -> V_86 = 0 ;
V_153 -> V_90 = 0 ;
V_153 -> V_158 = NULL ;
V_153 -> V_159 = 0 ;
if ( ! V_152 )
return 1 ;
while ( ( V_133 = F_68 ( & V_152 , L_50 ) ) != NULL ) {
int V_160 ;
if ( ! * V_133 )
continue;
V_160 = F_69 ( V_133 , V_161 , args ) ;
switch ( V_160 ) {
case V_162 :
if ( F_70 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_87 = V_163 ;
if ( V_155 >= 0 )
V_87 = F_40 ( F_71 () , V_155 ) ;
if ( ! F_72 ( V_87 ) ) {
F_55 ( V_126 L_51
L_52 , V_155 ) ;
break;
}
V_153 -> V_87 = V_87 ;
V_153 -> V_86 = 1 ;
break;
case V_164 :
if ( F_70 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_91 = V_165 ;
if ( V_155 >= 0 )
V_91 = F_41 ( F_71 () , V_155 ) ;
if ( ! F_73 ( V_91 ) ) {
F_55 ( V_126 L_53
L_52 , V_155 ) ;
break;
}
V_153 -> V_91 = V_91 ;
V_153 -> V_90 = 1 ;
break;
case V_166 :
F_16 ( V_153 -> V_158 ) ;
V_153 -> V_158 = F_74 ( & args [ 0 ] ) ;
if ( ! V_153 -> V_158 ) {
F_55 ( V_126 L_54
L_55 ) ;
return 0 ;
}
break;
case V_167 :
V_153 -> V_159 = 1 ;
break;
default:
F_55 ( V_126 L_56
L_57 , V_133 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_75 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_85 . V_158 ) ;
F_12 ( V_12 ) -> V_85 . V_158 = NULL ;
F_76 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_168 ) ;
V_12 -> V_168 = NULL ;
}
static int
F_77 ( struct V_11 * V_12 , void * V_110 , int V_169 )
{
struct V_8 * V_68 ;
T_9 * V_70 ;
T_16 * V_170 ;
struct V_7 * V_171 ;
long V_29 = - V_145 ;
const unsigned long V_172 = 0 ;
const T_17 V_173 = 512 ;
F_78 ( V_12 , V_110 ) ;
V_12 -> V_168 = F_60 ( sizeof ( * V_70 ) , V_61 ) ;
if ( V_12 -> V_168 == NULL ) {
F_55 ( V_126
L_58
L_59 , V_12 -> V_174 ) ;
goto V_78;
}
V_70 = F_12 ( V_12 ) ;
memset ( V_70 , 0 , sizeof( T_9 ) ) ;
if ( ! F_67 ( ( char * ) V_110 , & V_70 -> V_85 ) ) {
F_7 ( V_12 , L_60 ) ;
goto V_175;
}
F_6 ( V_12 , L_61 ) ;
#ifndef F_79
if ( ! ( V_12 -> V_176 & V_177 ) ) {
F_17 ( V_12 ,
L_62 ) ;
V_12 -> V_176 |= V_177 ;
}
#endif
F_80 ( V_12 , 1024 ) ;
if ( ! ( V_68 = F_81 ( V_12 , V_172 ) ) ) {
F_7 ( V_12 , L_63 ) ;
goto V_175;
}
V_170 = ( T_16 * ) V_68 -> V_79 ;
if ( ( V_170 -> V_178 == V_179 ) ||
( V_170 -> V_178 == V_180 ) ) {
F_6 ( V_12 , L_64 ) ;
} else {
F_6 ( V_12 , L_65 ) ;
V_170 =
( T_16 * ) ( ( void * ) V_68 -> V_79 + V_173 ) ;
}
if ( F_82 ( V_12 , V_170 ) != V_23 )
goto V_80;
F_83 ( V_12 , V_170 ) ;
F_50 ( V_68 ) ;
if ( F_84 ( V_12 ) != V_23 )
goto V_175;
if( V_70 -> V_181 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_66
L_67 ,
V_70 -> V_181 ) ;
goto V_175;
}
V_12 -> V_182 = V_183 ;
F_85 ( V_12 , ( T_4 ) V_70 -> V_107 ) ;
V_12 -> V_184 = & V_185 ;
V_171 = F_18 ( V_12 , F_9 ( V_12 , & ( V_70 -> V_186 ) ) ) ;
if ( F_19 ( V_171 ) ) {
V_29 = F_86 ( V_171 ) ;
goto V_175;
}
V_12 -> V_187 = F_87 ( V_171 ) ;
if ( ! V_12 -> V_187 ) {
F_7 ( V_12 , L_68 ) ;
goto V_175;
}
if ( V_70 -> V_85 . V_158 ) {
F_6 ( V_12 , L_69 ,
V_70 -> V_85 . V_158 ) ;
V_70 -> V_34 = F_88 ( V_70 -> V_85 . V_158 ) ;
if ( ! V_70 -> V_34 ) {
F_17 ( V_12 , L_70
L_71 ,
V_70 -> V_85 . V_158 ) ;
V_70 -> V_34 = F_89 () ;
}
} else {
F_6 ( V_12 , L_72 ) ;
V_70 -> V_34 = F_89 () ;
}
return 0 ;
V_80:
F_50 ( V_68 ) ;
V_175:
F_16 ( V_70 -> V_85 . V_158 ) ;
F_16 ( V_12 -> V_168 ) ;
V_78:
V_12 -> V_168 = NULL ;
return V_29 ;
}
static int
F_90 ( struct V_11 * V_12 , int * V_27 , char * V_110 )
{
if ( ! ( * V_27 & V_177 ) )
return - V_145 ;
return 0 ;
}
static int
F_91 ( struct V_25 * V_25 , struct V_188 * V_189 )
{
struct V_11 * V_12 = V_25 -> V_131 ;
T_18 V_190 = F_92 ( V_12 -> V_191 -> V_192 ) ;
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
V_189 -> V_205 = V_49 ;
F_6 ( V_12 , L_74 ) ;
return 0 ;
}
static struct V_25 *
F_93 ( struct V_206 * V_207 , int V_27 , const char * V_208 ,
void * V_110 )
{
return F_94 ( V_207 , V_27 , V_208 , V_110 , F_77 ) ;
}
static int T_19
F_95 ( void )
{
int V_209 ;
F_55 ( V_210 L_75 , V_211 ) ;
V_209 = F_53 () ;
if ( V_209 )
goto V_78;
V_209 = F_96 ( & V_212 ) ;
if ( V_209 )
goto V_213;
return 0 ;
V_213:
F_56 () ;
V_78:
return V_209 ;
}
static void T_20
F_97 ( void )
{
F_56 () ;
F_98 ( & V_212 ) ;
}
