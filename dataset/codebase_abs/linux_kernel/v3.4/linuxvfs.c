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
F_29 ( V_61 , F_5 ( V_7 ) ) ;
}
static void F_30 ( struct V_7 * V_7 )
{
F_31 ( & V_7 -> V_66 , F_27 ) ;
}
static void F_32 ( void * V_67 )
{
struct V_59 * V_60 = (struct V_59 * ) V_67 ;
F_33 ( & V_60 -> V_63 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_68 )
{
struct V_8 * V_69 = NULL ;
T_8 * V_70 = NULL ;
T_9 * V_71 = F_12 ( V_12 ) ;
V_59 * V_72 = NULL ;
struct V_7 * V_7 ;
long V_30 = - V_21 ;
F_6 ( V_12 , L_23 L_24 , V_68 ) ;
V_7 = F_34 ( V_12 , V_68 ) ;
if ( F_19 ( V_7 ) )
return V_7 ;
if ( ! ( V_7 -> V_73 & V_74 ) )
return V_7 ;
V_72 = F_5 ( V_7 ) ;
V_72 -> V_75 = F_35 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_25 ,
V_72 -> V_75 . V_76 ,
V_72 -> V_75 . V_77 , V_72 -> V_75 . V_78 ) ;
V_69 = F_36 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_69 ) {
F_7 ( V_12 , L_26
L_24 , V_7 -> V_20 ) ;
goto V_79;
}
V_70 = ( T_8 * ) V_69 -> V_80 ;
F_37 ( V_12 , V_70 ) ;
if ( F_38 ( V_12 , V_70 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_27 , V_7 -> V_20 ) ;
goto V_81;
}
V_7 -> V_82 = ( V_83 ) F_39 ( V_12 , V_70 -> V_84 ) ;
V_7 -> V_85 = V_71 -> V_86 . V_87 ?
V_71 -> V_86 . V_88 : ( V_89 ) F_39 ( V_12 , V_70 -> V_88 ) ;
V_7 -> V_90 = V_71 -> V_86 . V_91 ?
V_71 -> V_86 . V_92 : ( V_93 ) F_39 ( V_12 , V_70 -> V_92 ) ;
F_40 ( V_7 , 1 ) ;
V_7 -> V_94 . V_95 =
F_41 ( V_12 , V_70 -> V_96 ) >> 16 ;
V_7 -> V_94 . V_97 = 0 ;
V_7 -> V_98 = V_7 -> V_94 ;
V_7 -> V_99 = V_7 -> V_94 ;
V_72 -> V_75 = F_42 ( V_12 , V_70 -> V_100 ) ;
V_72 -> V_101 = F_42 ( V_12 , V_70 -> V_102 ) ;
V_72 -> V_103 = F_42 ( V_12 , V_70 -> V_104 ) ;
V_72 -> V_105 = F_39 ( V_12 , V_70 -> V_106 ) ;
if ( F_43 ( V_7 -> V_82 ) && ! ( V_72 -> V_105 & V_107 ) ) {
V_7 -> V_108 = 0 ;
V_7 -> V_109 = V_71 -> V_110 / V_111 ;
strncpy ( V_72 -> V_15 . V_112 , V_70 -> V_113 . V_112 ,
V_114 - 1 ) ;
V_72 -> V_15 . V_112 [ V_114 - 1 ] = '\0' ;
} else {
int V_115 ;
V_72 -> V_15 . V_14 =
F_44 ( V_12 , & V_70 -> V_113 . V_116 ) ;
V_115 = F_45 ( V_12 , & V_72 -> V_15 . V_14 ) ;
V_7 -> V_109 =
V_115 * ( V_71 -> V_110 / V_111 ) ;
V_7 -> V_108 = V_72 -> V_15 . V_14 . V_117 ;
}
V_7 -> V_118 -> V_119 = & V_120 ;
if ( F_46 ( V_7 -> V_82 ) ) {
V_7 -> V_121 = & V_122 ;
} else if ( F_47 ( V_7 -> V_82 ) ) {
V_7 -> V_123 = & V_124 ;
V_7 -> V_121 = & V_125 ;
} else if ( F_43 ( V_7 -> V_82 ) ) {
V_7 -> V_123 = & V_126 ;
} else {
F_7 ( V_12 , L_28
L_29
L_30 , V_7 -> V_20 ) ;
goto V_81;
}
F_48 ( V_69 ) ;
F_6 ( V_12 , L_31 ) ;
F_49 ( V_7 ) ;
return V_7 ;
V_81:
F_48 ( V_69 ) ;
V_79:
F_50 ( V_7 ) ;
F_6 ( V_12 , L_32 ) ;
return F_14 ( V_30 ) ;
}
static int
F_51 ( void )
{
V_61 = F_52 ( L_33 ,
sizeof ( struct V_59 ) ,
0 , ( V_127 |
V_128 ) ,
F_32 ) ;
if ( V_61 == NULL ) {
F_53 ( V_129 L_34
L_35 ) ;
return - V_130 ;
}
return 0 ;
}
static void
F_54 ( void )
{
F_55 ( V_61 ) ;
}
static void *
F_56 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_59 * V_72 = F_5 ( V_25 -> V_44 ) ;
char * V_131 ;
if ( V_72 -> V_105 & V_107 ) {
struct V_11 * V_12 = V_25 -> V_132 ;
T_2 * V_113 = & V_72 -> V_15 . V_14 ;
T_5 V_78 = V_113 -> V_117 ;
if ( V_78 == 0 ) {
F_7 ( V_12 , L_36 ) ;
V_131 = F_14 ( - V_21 ) ;
} else {
F_6 ( V_12 , L_37 ) ;
V_131 = F_57 ( V_78 , V_133 ) ;
if ( ! V_131 ) {
V_131 = F_14 ( - V_130 ) ;
} else if ( F_58 ( V_12 , V_113 , V_131 , V_78 ) != V_78 ) {
F_16 ( V_131 ) ;
F_7 ( V_12 , L_38 ) ;
V_131 = F_14 ( - V_21 ) ;
} else {
V_131 [ V_78 - 1 ] = '\0' ;
}
}
} else {
V_131 = V_72 -> V_15 . V_112 ;
}
F_59 ( V_28 , V_131 ) ;
return NULL ;
}
static void F_60 ( struct V_25 * V_25 , struct V_27 * V_28 , void * V_134 )
{
V_59 * V_72 = F_5 ( V_25 -> V_44 ) ;
if ( V_72 -> V_105 & V_107 ) {
char * V_131 = F_61 ( V_28 ) ;
if ( ! F_19 ( V_131 ) )
F_16 ( V_131 ) ;
}
}
static int
F_24 ( struct V_11 * V_12 , const char * V_135 ,
int V_136 , char * * V_137 , int * V_138 )
{
struct V_139 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_140 , V_141 ;
T_10 V_142 ;
int V_143 , V_144 ;
char * V_46 ;
int V_145 = V_136 + 1 ;
F_6 ( V_12 , L_39 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_40 ) ;
return - V_146 ;
}
* V_137 = V_46 = F_57 ( V_145 , V_133 ) ;
if ( ! * V_137 ) {
F_7 ( V_12 , L_41 ) ;
* V_138 = 0 ;
return - V_130 ;
}
for ( V_140 = V_141 = 0 ; V_140 < V_136 ; V_140 += V_144 , V_141 += V_143 ) {
V_144 = F_62 ( & V_135 [ V_140 ] , V_136 - V_140 , & V_142 ) ;
if ( V_144 < 0 )
goto V_147;
if ( V_142 > V_148 )
goto V_147;
V_143 = V_35 -> V_149 ( V_142 , & V_46 [ V_141 ] , V_136 - V_141 ) ;
if ( V_143 < 0 )
goto V_147;
}
V_46 [ V_141 ] = '\0' ;
* V_138 = V_141 ;
F_6 ( V_12 , L_42 ) ;
return V_141 ;
V_147:
F_7 ( V_12 , L_43
L_44 , V_35 -> V_150 ) ;
F_6 ( V_12 , L_42 ) ;
F_16 ( V_46 ) ;
return - V_151 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_135 ,
int V_136 , char * * V_137 , int * V_138 )
{
struct V_139 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_140 , V_141 ;
T_11 V_142 ;
int V_143 , V_144 ;
char * V_46 ;
int V_145 = ( 3 * V_136 ) + 1 ;
F_6 ( V_12 , L_45 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_46 ) ;
return - V_146 ;
}
* V_137 = V_46 = F_57 ( V_145 , V_133 ) ;
if ( ! * V_137 ) {
F_7 ( V_12 , L_47 ) ;
* V_138 = 0 ;
return - V_130 ;
}
for ( V_140 = V_141 = 0 ; V_140 < V_136 ; V_140 += V_143 , V_141 += V_144 ) {
V_143 = V_35 -> V_152 ( & V_135 [ V_140 ] , V_136 - V_140 , & V_142 ) ;
if ( V_143 < 0 )
goto V_147;
V_144 = F_63 ( V_142 , & V_46 [ V_141 ] , 3 ) ;
if ( V_144 <= 0 )
goto V_147;
}
V_46 [ V_141 ] = '\0' ;
* V_138 = V_141 ;
F_6 ( V_12 , L_48 ) ;
return V_140 ;
V_147:
F_7 ( V_12 , L_49
L_44 , V_35 -> V_150 ) ;
F_6 ( V_12 , L_48 ) ;
F_16 ( V_46 ) ;
return - V_151 ;
}
static int
F_64 ( char * V_153 , T_12 * V_154 )
{
char * V_134 ;
T_13 args [ V_155 ] ;
int V_156 ;
V_154 -> V_88 = 0 ;
V_154 -> V_92 = 0 ;
V_154 -> V_87 = 0 ;
V_154 -> V_91 = 0 ;
V_154 -> V_157 = NULL ;
V_154 -> V_158 = 0 ;
if ( ! V_153 )
return 1 ;
while ( ( V_134 = F_65 ( & V_153 , L_50 ) ) != NULL ) {
int V_159 ;
if ( ! * V_134 )
continue;
V_159 = F_66 ( V_134 , V_160 , args ) ;
switch ( V_159 ) {
case V_161 :
if ( F_67 ( & args [ 0 ] , & V_156 ) )
return 0 ;
if ( V_156 < 0 ) {
F_53 ( V_129 L_51
L_52 , V_156 ) ;
break;
}
V_154 -> V_88 = V_156 ;
V_154 -> V_87 = 1 ;
break;
case V_162 :
if ( F_67 ( & args [ 0 ] , & V_156 ) )
return 0 ;
if ( V_156 < 0 ) {
F_53 ( V_129 L_53
L_52 , V_156 ) ;
break;
}
V_154 -> V_92 = V_156 ;
V_154 -> V_91 = 1 ;
break;
case V_163 :
F_16 ( V_154 -> V_157 ) ;
V_154 -> V_157 = F_68 ( & args [ 0 ] ) ;
if ( ! V_154 -> V_157 ) {
F_53 ( V_129 L_54
L_55 ) ;
return 0 ;
}
break;
case V_164 :
V_154 -> V_158 = 1 ;
break;
default:
F_53 ( V_129 L_56
L_57 , V_134 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_69 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_86 . V_157 ) ;
F_12 ( V_12 ) -> V_86 . V_157 = NULL ;
F_70 ( F_12 ( V_12 ) -> V_35 ) ;
F_16 ( V_12 -> V_165 ) ;
V_12 -> V_165 = NULL ;
}
static int
F_71 ( struct V_11 * V_12 , void * V_113 , int V_166 )
{
struct V_8 * V_69 ;
T_9 * V_71 ;
T_14 * V_167 ;
struct V_7 * V_168 ;
long V_30 = - V_146 ;
const unsigned long V_169 = 0 ;
const T_15 V_170 = 512 ;
F_72 ( V_12 , V_113 ) ;
V_12 -> V_165 = F_57 ( sizeof ( * V_71 ) , V_62 ) ;
if ( V_12 -> V_165 == NULL ) {
F_53 ( V_129
L_58
L_59 , V_12 -> V_171 ) ;
goto V_79;
}
V_71 = F_12 ( V_12 ) ;
memset ( V_71 , 0 , sizeof( T_9 ) ) ;
if ( ! F_64 ( ( char * ) V_113 , & V_71 -> V_86 ) ) {
F_7 ( V_12 , L_60 ) ;
goto V_172;
}
F_6 ( V_12 , L_61 ) ;
#ifndef F_73
if ( ! ( V_12 -> V_173 & V_174 ) ) {
F_17 ( V_12 ,
L_62 ) ;
V_12 -> V_173 |= V_174 ;
}
#endif
F_74 ( V_12 , 1024 ) ;
if ( ! ( V_69 = F_75 ( V_12 , V_169 ) ) ) {
F_7 ( V_12 , L_63 ) ;
goto V_172;
}
V_167 = ( T_14 * ) V_69 -> V_80 ;
if ( ( V_167 -> V_175 == V_176 ) ||
( V_167 -> V_175 == V_177 ) ) {
F_6 ( V_12 , L_64 ) ;
} else {
F_6 ( V_12 , L_65 ) ;
V_167 =
( T_14 * ) ( ( void * ) V_69 -> V_80 + V_170 ) ;
}
if ( F_76 ( V_12 , V_167 ) != V_23 )
goto V_81;
F_77 ( V_12 , V_167 ) ;
F_48 ( V_69 ) ;
if ( F_78 ( V_12 ) != V_23 )
goto V_172;
if( V_71 -> V_178 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_66
L_67 ,
V_71 -> V_178 ) ;
goto V_172;
}
V_12 -> V_179 = V_180 ;
F_79 ( V_12 , ( T_4 ) V_71 -> V_110 ) ;
V_12 -> V_181 = & V_182 ;
V_168 = F_18 ( V_12 , F_9 ( V_12 , & ( V_71 -> V_183 ) ) ) ;
if ( F_19 ( V_168 ) ) {
V_30 = F_80 ( V_168 ) ;
goto V_172;
}
V_12 -> V_184 = F_81 ( V_168 ) ;
if ( ! V_12 -> V_184 ) {
F_7 ( V_12 , L_68 ) ;
goto V_172;
}
if ( V_71 -> V_86 . V_157 ) {
F_6 ( V_12 , L_69 ,
V_71 -> V_86 . V_157 ) ;
V_71 -> V_35 = F_82 ( V_71 -> V_86 . V_157 ) ;
if ( ! V_71 -> V_35 ) {
F_17 ( V_12 , L_70
L_71 ,
V_71 -> V_86 . V_157 ) ;
V_71 -> V_35 = F_83 () ;
}
} else {
F_6 ( V_12 , L_72 ) ;
V_71 -> V_35 = F_83 () ;
}
return 0 ;
V_81:
F_48 ( V_69 ) ;
V_172:
F_16 ( V_71 -> V_86 . V_157 ) ;
F_16 ( V_12 -> V_165 ) ;
V_79:
V_12 -> V_165 = NULL ;
return V_30 ;
}
static int
F_84 ( struct V_11 * V_12 , int * V_106 , char * V_113 )
{
if ( ! ( * V_106 & V_174 ) )
return - V_146 ;
return 0 ;
}
static int
F_85 ( struct V_25 * V_25 , struct V_185 * V_186 )
{
struct V_11 * V_12 = V_25 -> V_132 ;
T_16 V_187 = F_86 ( V_12 -> V_188 -> V_189 ) ;
F_6 ( V_12 , L_73 ) ;
V_186 -> V_190 = V_180 ;
V_186 -> V_191 = V_12 -> V_192 ;
V_186 -> V_193 = F_12 ( V_12 ) -> V_178 ;
V_186 -> V_194 = F_12 ( V_12 ) -> V_178 - F_12 ( V_12 ) -> V_195 ;
V_186 -> V_196 = V_186 -> V_194 ;
V_186 -> V_197 = 0 ;
V_186 -> V_198 = 0 ;
V_186 -> V_199 . V_200 [ 0 ] = ( V_201 ) V_187 ;
V_186 -> V_199 . V_200 [ 1 ] = ( V_201 ) ( V_187 >> 32 ) ;
V_186 -> V_202 = V_50 ;
F_6 ( V_12 , L_74 ) ;
return 0 ;
}
static struct V_25 *
F_87 ( struct V_203 * V_204 , int V_106 , const char * V_205 ,
void * V_113 )
{
return F_88 ( V_204 , V_106 , V_205 , V_113 , F_71 ) ;
}
static int T_17
F_89 ( void )
{
int V_206 ;
F_53 ( V_207 L_75 , V_208 ) ;
V_206 = F_51 () ;
if ( V_206 )
goto V_79;
V_206 = F_90 ( & V_209 ) ;
if ( V_206 )
goto V_210;
return 0 ;
V_210:
F_54 () ;
V_79:
return V_206 ;
}
static void T_18
F_91 ( void )
{
F_54 () ;
F_92 ( & V_209 ) ;
}
