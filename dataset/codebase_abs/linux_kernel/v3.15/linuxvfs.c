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
( unsigned long ) V_7 -> V_20 , ( long ) V_6 ) ;
if ( V_6 < 0 ) {
F_7 ( V_12 , L_2
L_3 ,
( long ) V_6 , ( unsigned long ) V_7 -> V_20 ) ;
return - V_21 ;
}
if ( V_10 ) {
F_7 ( V_12 , L_4
L_5 , ( long ) V_6 ,
( unsigned long ) V_7 -> V_20 ) ;
return - V_22 ;
}
V_18 = F_8 ( V_12 , V_14 , V_6 , & V_16 ) ;
if ( V_18 != V_23 ) {
F_7 ( V_12 ,
L_6 ,
V_24 , ( unsigned long ) V_7 -> V_20 ,
( long ) V_6 ) ;
return - V_25 ;
}
V_19 = ( T_4 ) F_9 ( V_12 , & V_16 ) ;
F_10 ( V_9 , V_7 -> V_13 , V_19 ) ;
F_6 ( V_12 , L_7 ,
V_24 , ( unsigned long ) V_7 -> V_20 , ( long ) V_6 ,
( unsigned long ) V_19 ) ;
return 0 ;
}
static struct V_26 *
F_11 ( struct V_7 * V_27 , struct V_26 * V_26 , unsigned int V_28 )
{
struct V_7 * V_7 = NULL ;
struct V_11 * V_12 = V_27 -> V_13 ;
T_2 * V_14 = & F_5 ( V_27 ) -> V_15 . V_14 ;
T_5 V_29 ;
int V_30 ;
int V_31 ;
char * V_32 ;
const char * V_33 = V_26 -> V_34 . V_33 ;
F_6 ( V_12 , L_8 , V_24 ,
V_26 -> V_34 . V_33 , V_27 -> V_20 ) ;
if ( F_12 ( V_12 ) -> V_35 ) {
V_30 =
F_13 ( V_12 , V_33 , strlen ( V_33 ) , & V_32 , & V_31 ) ;
if ( V_30 < 0 ) {
F_6 ( V_12 , L_9 , V_24 ) ;
return F_14 ( V_30 ) ;
}
V_30 = F_15 ( V_12 , V_14 , V_32 , & V_29 ) ;
F_16 ( V_32 ) ;
} else {
V_30 = F_15 ( V_12 , V_14 , V_26 -> V_34 . V_33 , & V_29 ) ;
}
if ( V_30 == V_36 ) {
F_6 ( V_12 , L_10 , V_24 ,
V_26 -> V_34 . V_33 ) ;
return F_14 ( - V_37 ) ;
} else if ( V_30 != V_23 || V_29 == 0 ) {
F_17 ( V_12 , L_11 , V_24 ) ;
return F_14 ( - V_38 ) ;
}
V_7 = F_18 ( V_27 -> V_13 , ( V_39 ) V_29 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_21 ( V_26 , V_7 ) ;
F_6 ( V_12 , L_12 , V_24 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_1 , struct V_40 * V_41 )
{
struct V_7 * V_7 = F_23 ( V_1 ) ;
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_42 ;
int V_43 ;
T_6 V_44 ;
unsigned char V_45 ;
char V_46 [ V_47 + 1 ] ;
const char * V_48 = V_1 -> V_49 . V_26 -> V_34 . V_33 ;
F_6 ( V_12 , L_13 ,
V_24 , V_48 , V_7 -> V_20 , V_41 -> V_50 ) ;
V_51:
V_43 = F_24 ( V_12 , V_14 , V_41 -> V_50 , V_47 + 1 ,
V_46 , & V_44 , & V_42 ) ;
if ( V_43 == V_52 ) {
F_6 ( V_12 , L_9 , V_24 ) ;
F_7 ( V_12 , L_14 ,
V_48 , V_7 -> V_20 ) ;
return - V_21 ;
} else if ( V_43 == V_53 ) {
F_6 ( V_12 , L_15 , V_24 ) ;
return 0 ;
} else if ( V_43 == V_54 ) {
F_6 ( V_12 , L_16 , V_24 ) ;
return 0 ;
}
V_45 = V_55 ;
if ( F_12 ( V_12 ) -> V_35 ) {
char * V_56 ;
int V_57 ;
V_43 =
F_25 ( V_12 , V_46 , V_44 , & V_56 , & V_57 ) ;
if ( V_43 < 0 ) {
F_6 ( V_12 , L_9 , V_24 ) ;
return V_43 ;
}
if ( ! F_26 ( V_41 , V_56 , V_57 ,
( V_39 ) V_42 , V_45 ) ) {
F_16 ( V_56 ) ;
return 0 ;
}
F_16 ( V_56 ) ;
} else {
if ( ! F_26 ( V_41 , V_46 , V_44 ,
( V_39 ) V_42 , V_45 ) )
return 0 ;
}
V_41 -> V_50 ++ ;
goto V_51;
F_6 ( V_12 , L_17 , V_24 , V_41 -> V_50 ) ;
return 0 ;
}
static struct V_7 *
F_27 ( struct V_11 * V_12 )
{
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) F_28 ( V_60 ,
V_61 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_62 ;
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_7 * V_7 = F_30 ( V_64 , struct V_7 , V_65 ) ;
F_31 ( V_60 , F_5 ( V_7 ) ) ;
}
static void F_32 ( struct V_7 * V_7 )
{
F_33 ( & V_7 -> V_65 , F_29 ) ;
}
static void F_34 ( void * V_66 )
{
struct V_58 * V_59 = (struct V_58 * ) V_66 ;
F_35 ( & V_59 -> V_62 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_67 )
{
struct V_8 * V_68 = NULL ;
T_7 * V_69 = NULL ;
T_8 * V_70 = F_12 ( V_12 ) ;
V_58 * V_71 = NULL ;
struct V_7 * V_7 ;
long V_30 = - V_21 ;
F_6 ( V_12 , L_18 , V_24 , V_67 ) ;
V_7 = F_36 ( V_12 , V_67 ) ;
if ( ! V_7 )
return F_14 ( - V_72 ) ;
if ( ! ( V_7 -> V_73 & V_74 ) )
return V_7 ;
V_71 = F_5 ( V_7 ) ;
V_71 -> V_75 = F_37 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_19 ,
V_71 -> V_75 . V_76 ,
V_71 -> V_75 . V_77 , V_71 -> V_75 . V_78 ) ;
V_68 = F_38 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_68 ) {
F_7 ( V_12 , L_20
L_21 , V_7 -> V_20 ) ;
goto V_79;
}
V_69 = ( T_7 * ) V_68 -> V_80 ;
F_39 ( V_12 , V_69 ) ;
if ( F_40 ( V_12 , V_69 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_22 , V_7 -> V_20 ) ;
goto V_81;
}
V_7 -> V_82 = ( V_83 ) F_41 ( V_12 , V_69 -> V_84 ) ;
V_7 -> V_85 = V_70 -> V_86 . V_87 ?
V_70 -> V_86 . V_88 :
F_42 ( & V_89 , F_41 ( V_12 , V_69 -> V_88 ) ) ;
V_7 -> V_90 = V_70 -> V_86 . V_91 ?
V_70 -> V_86 . V_92 :
F_43 ( & V_89 , F_41 ( V_12 , V_69 -> V_92 ) ) ;
F_44 ( V_7 , 1 ) ;
V_7 -> V_93 . V_94 =
F_45 ( V_12 , V_69 -> V_95 ) >> 16 ;
V_7 -> V_93 . V_96 = 0 ;
V_7 -> V_97 = V_7 -> V_93 ;
V_7 -> V_98 = V_7 -> V_93 ;
V_71 -> V_75 = F_46 ( V_12 , V_69 -> V_99 ) ;
V_71 -> V_100 = F_46 ( V_12 , V_69 -> V_101 ) ;
V_71 -> V_102 = F_46 ( V_12 , V_69 -> V_103 ) ;
V_71 -> V_104 = F_41 ( V_12 , V_69 -> V_28 ) ;
if ( F_47 ( V_7 -> V_82 ) && ! ( V_71 -> V_104 & V_105 ) ) {
V_7 -> V_106 = 0 ;
V_7 -> V_107 = V_70 -> V_108 / V_109 ;
strncpy ( V_71 -> V_15 . V_110 , V_69 -> V_111 . V_110 ,
V_112 - 1 ) ;
V_71 -> V_15 . V_110 [ V_112 - 1 ] = '\0' ;
} else {
int V_113 ;
V_71 -> V_15 . V_14 =
F_48 ( V_12 , & V_69 -> V_111 . V_114 ) ;
V_113 = F_49 ( V_12 , & V_71 -> V_15 . V_14 ) ;
V_7 -> V_107 =
V_113 * ( V_70 -> V_108 / V_109 ) ;
V_7 -> V_106 = V_71 -> V_15 . V_14 . V_115 ;
}
V_7 -> V_116 -> V_117 = & V_118 ;
if ( F_50 ( V_7 -> V_82 ) ) {
V_7 -> V_119 = & V_120 ;
} else if ( F_51 ( V_7 -> V_82 ) ) {
V_7 -> V_121 = & V_122 ;
V_7 -> V_119 = & V_123 ;
} else if ( F_47 ( V_7 -> V_82 ) ) {
if ( V_71 -> V_104 & V_105 )
V_7 -> V_121 = & V_124 ;
else
V_7 -> V_121 = & V_125 ;
} else {
F_7 ( V_12 , L_23
L_24
L_25 , V_7 -> V_20 ) ;
goto V_81;
}
F_52 ( V_68 ) ;
F_6 ( V_12 , L_12 , V_24 ) ;
F_53 ( V_7 ) ;
return V_7 ;
V_81:
F_52 ( V_68 ) ;
V_79:
F_54 ( V_7 ) ;
F_6 ( V_12 , L_26 , V_24 ) ;
return F_14 ( V_30 ) ;
}
static int T_9
F_55 ( void )
{
V_60 = F_56 ( L_27 ,
sizeof ( struct V_58 ) ,
0 , ( V_126 |
V_127 ) ,
F_34 ) ;
if ( V_60 == NULL ) {
F_57 ( L_28 , V_24 ) ;
return - V_72 ;
}
return 0 ;
}
static void
F_58 ( void )
{
F_59 () ;
F_60 ( V_60 ) ;
}
static void *
F_61 ( struct V_26 * V_26 , struct V_128 * V_129 )
{
struct V_11 * V_12 = V_26 -> V_130 ;
V_58 * V_71 = F_5 ( V_26 -> V_131 ) ;
T_2 * V_111 = & V_71 -> V_15 . V_14 ;
T_5 V_78 = V_111 -> V_115 ;
char * V_132 ;
if ( V_78 == 0 ) {
F_7 ( V_12 , L_29 ) ;
V_132 = F_14 ( - V_21 ) ;
} else {
F_6 ( V_12 , L_30 ) ;
V_132 = F_62 ( V_78 , V_133 ) ;
if ( ! V_132 ) {
V_132 = F_14 ( - V_72 ) ;
} else if ( F_63 ( V_12 , V_111 , V_132 , V_78 ) != V_78 ) {
F_16 ( V_132 ) ;
F_7 ( V_12 , L_31 ) ;
V_132 = F_14 ( - V_21 ) ;
} else {
V_132 [ V_78 - 1 ] = '\0' ;
}
}
F_64 ( V_129 , V_132 ) ;
return NULL ;
}
static void *
F_65 ( struct V_26 * V_26 , struct V_128 * V_129 )
{
V_58 * V_71 = F_5 ( V_26 -> V_131 ) ;
F_64 ( V_129 , V_71 -> V_15 . V_110 ) ;
return NULL ;
}
static int
F_25 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_139 , V_140 ;
T_10 V_141 ;
int V_142 , V_143 ;
char * V_43 ;
int V_144 = V_135 + 1 ;
F_6 ( V_12 , L_32 , V_24 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_33 , V_24 ) ;
return - V_145 ;
}
* V_136 = V_43 = F_62 ( V_144 , V_133 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_34 , V_24 ) ;
* V_137 = 0 ;
return - V_72 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_143 , V_140 += V_142 ) {
V_143 = F_66 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_143 < 0 )
goto V_146;
if ( V_141 > V_147 )
goto V_146;
V_142 = V_35 -> V_148 ( V_141 , & V_43 [ V_140 ] , V_135 - V_140 ) ;
if ( V_142 < 0 )
goto V_146;
}
V_43 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_12 , V_24 ) ;
return V_140 ;
V_146:
F_7 ( V_12 , L_35
L_36 , V_35 -> V_149 ) ;
F_6 ( V_12 , L_12 , V_24 ) ;
F_16 ( V_43 ) ;
return - V_150 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_139 , V_140 ;
T_11 V_141 ;
int V_142 , V_143 ;
char * V_43 ;
int V_144 = ( 3 * V_135 ) + 1 ;
F_6 ( V_12 , L_37 , V_24 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_38 ,
V_24 ) ;
return - V_145 ;
}
* V_136 = V_43 = F_62 ( V_144 , V_133 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_34 , V_24 ) ;
* V_137 = 0 ;
return - V_72 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_142 , V_140 += V_143 ) {
V_142 = V_35 -> V_151 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_142 < 0 )
goto V_146;
V_143 = F_67 ( V_141 , & V_43 [ V_140 ] , 3 ) ;
if ( V_143 <= 0 )
goto V_146;
}
V_43 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_12 , V_24 ) ;
return V_139 ;
V_146:
F_7 ( V_12 , L_39
L_36 , V_35 -> V_149 ) ;
F_6 ( V_12 , L_12 , V_24 ) ;
F_16 ( V_43 ) ;
return - V_150 ;
}
static int
F_68 ( char * V_152 , T_12 * V_153 )
{
char * V_154 ;
T_13 args [ V_155 ] ;
int V_156 ;
T_14 V_88 ;
T_15 V_92 ;
V_153 -> V_88 = V_157 ;
V_153 -> V_92 = V_158 ;
V_153 -> V_87 = 0 ;
V_153 -> V_91 = 0 ;
V_153 -> V_159 = NULL ;
V_153 -> V_160 = 0 ;
if ( ! V_152 )
return 1 ;
while ( ( V_154 = F_69 ( & V_152 , L_40 ) ) != NULL ) {
int V_161 ;
if ( ! * V_154 )
continue;
V_161 = F_70 ( V_154 , V_162 , args ) ;
switch ( V_161 ) {
case V_163 :
if ( F_71 ( & args [ 0 ] , & V_156 ) )
return 0 ;
V_88 = V_164 ;
if ( V_156 >= 0 )
V_88 = F_42 ( F_72 () , V_156 ) ;
if ( ! F_73 ( V_88 ) ) {
F_57 ( L_41
L_42 , V_156 ) ;
break;
}
V_153 -> V_88 = V_88 ;
V_153 -> V_87 = 1 ;
break;
case V_165 :
if ( F_71 ( & args [ 0 ] , & V_156 ) )
return 0 ;
V_92 = V_166 ;
if ( V_156 >= 0 )
V_92 = F_43 ( F_72 () , V_156 ) ;
if ( ! F_74 ( V_92 ) ) {
F_57 ( L_43
L_42 , V_156 ) ;
break;
}
V_153 -> V_92 = V_92 ;
V_153 -> V_91 = 1 ;
break;
case V_167 :
F_16 ( V_153 -> V_159 ) ;
V_153 -> V_159 = F_75 ( & args [ 0 ] ) ;
if ( ! V_153 -> V_159 ) {
F_57 ( L_44
L_45 ) ;
return 0 ;
}
break;
case V_168 :
V_153 -> V_160 = 1 ;
break;
default:
F_57 ( L_46
L_47 , V_154 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_76 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_86 . V_159 ) ;
F_12 ( V_12 ) -> V_86 . V_159 = NULL ;
F_77 ( F_12 ( V_12 ) -> V_35 ) ;
F_16 ( V_12 -> V_169 ) ;
V_12 -> V_169 = NULL ;
}
static int
F_78 ( struct V_11 * V_12 , void * V_111 , int V_170 )
{
struct V_8 * V_68 ;
T_8 * V_70 ;
T_16 * V_171 ;
struct V_7 * V_172 ;
long V_30 = - V_145 ;
const unsigned long V_173 = 0 ;
const T_17 V_174 = 512 ;
F_79 ( V_12 , V_111 ) ;
V_12 -> V_169 = F_80 ( sizeof( * V_70 ) , V_61 ) ;
if ( V_12 -> V_169 == NULL ) {
F_57 ( L_48
L_49 , V_12 -> V_175 ) ;
goto V_79;
}
V_70 = F_12 ( V_12 ) ;
if ( ! F_68 ( ( char * ) V_111 , & V_70 -> V_86 ) ) {
F_7 ( V_12 , L_50 ) ;
goto V_176;
}
F_6 ( V_12 , L_32 , V_24 ) ;
#ifndef F_81
if ( ! ( V_12 -> V_177 & V_178 ) ) {
F_17 ( V_12 ,
L_51 ) ;
V_12 -> V_177 |= V_178 ;
}
#endif
F_82 ( V_12 , 1024 ) ;
if ( ! ( V_68 = F_83 ( V_12 , V_173 ) ) ) {
F_7 ( V_12 , L_52 ) ;
goto V_176;
}
V_171 = ( T_16 * ) V_68 -> V_80 ;
if ( ( V_171 -> V_179 == V_180 ) ||
( V_171 -> V_179 == V_181 ) ) {
F_6 ( V_12 , L_53 ) ;
} else {
F_6 ( V_12 , L_54 ) ;
V_171 =
( T_16 * ) ( ( void * ) V_68 -> V_80 + V_174 ) ;
}
if ( F_84 ( V_12 , V_171 ) != V_23 )
goto V_81;
F_85 ( V_12 , V_171 ) ;
F_52 ( V_68 ) ;
if ( F_86 ( V_12 ) != V_23 )
goto V_176;
if( V_70 -> V_182 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_55
L_56 ,
V_70 -> V_182 ) ;
goto V_176;
}
V_12 -> V_183 = V_184 ;
F_87 ( V_12 , ( T_4 ) V_70 -> V_108 ) ;
V_12 -> V_185 = & V_186 ;
V_172 = F_18 ( V_12 , F_9 ( V_12 , & ( V_70 -> V_187 ) ) ) ;
if ( F_19 ( V_172 ) ) {
V_30 = F_88 ( V_172 ) ;
goto V_176;
}
V_12 -> V_188 = F_89 ( V_172 ) ;
if ( ! V_12 -> V_188 ) {
F_7 ( V_12 , L_57 ) ;
goto V_176;
}
if ( V_70 -> V_86 . V_159 ) {
F_6 ( V_12 , L_58 ,
V_70 -> V_86 . V_159 ) ;
V_70 -> V_35 = F_90 ( V_70 -> V_86 . V_159 ) ;
if ( ! V_70 -> V_35 ) {
F_17 ( V_12 , L_59
L_60 ,
V_70 -> V_86 . V_159 ) ;
V_70 -> V_35 = F_91 () ;
}
} else {
F_6 ( V_12 , L_61 ) ;
V_70 -> V_35 = F_91 () ;
}
return 0 ;
V_81:
F_52 ( V_68 ) ;
V_176:
F_16 ( V_70 -> V_86 . V_159 ) ;
F_16 ( V_12 -> V_169 ) ;
V_79:
V_12 -> V_169 = NULL ;
return V_30 ;
}
static int
F_92 ( struct V_11 * V_12 , int * V_28 , char * V_111 )
{
F_93 ( V_12 ) ;
if ( ! ( * V_28 & V_178 ) )
return - V_145 ;
return 0 ;
}
static int
F_94 ( struct V_26 * V_26 , struct V_189 * V_190 )
{
struct V_11 * V_12 = V_26 -> V_130 ;
T_18 V_191 = F_95 ( V_12 -> V_192 -> V_193 ) ;
F_6 ( V_12 , L_32 , V_24 ) ;
V_190 -> V_194 = V_184 ;
V_190 -> V_195 = V_12 -> V_196 ;
V_190 -> V_197 = F_12 ( V_12 ) -> V_182 ;
V_190 -> V_198 = F_12 ( V_12 ) -> V_182 - F_12 ( V_12 ) -> V_199 ;
V_190 -> V_200 = V_190 -> V_198 ;
V_190 -> V_201 = 0 ;
V_190 -> V_202 = 0 ;
V_190 -> V_203 . V_204 [ 0 ] = ( V_205 ) V_191 ;
V_190 -> V_203 . V_204 [ 1 ] = ( V_205 ) ( V_191 >> 32 ) ;
V_190 -> V_206 = V_47 ;
F_6 ( V_12 , L_12 , V_24 ) ;
return 0 ;
}
static struct V_26 *
F_96 ( struct V_207 * V_208 , int V_28 , const char * V_209 ,
void * V_111 )
{
return F_97 ( V_208 , V_28 , V_209 , V_111 , F_78 ) ;
}
static int T_9
F_98 ( void )
{
int V_210 ;
F_99 ( L_62 , V_211 ) ;
V_210 = F_55 () ;
if ( V_210 )
goto V_79;
V_210 = F_100 ( & V_212 ) ;
if ( V_210 )
goto V_213;
return 0 ;
V_213:
F_58 () ;
V_79:
return V_210 ;
}
static void T_19
F_101 ( void )
{
F_58 () ;
F_102 ( & V_212 ) ;
}
