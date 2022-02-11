static void F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_4 -> V_5 ;
F_2 ( V_3 -> V_6 , V_3 , V_1 ) ;
}
static void F_3 ( char * V_1 )
{
char * V_7 ;
for ( V_7 = V_1 ; * V_7 ; V_7 ++ ) {
T_1 V_8 [ 2 ] = { 0 } ;
V_8 [ 0 ] = * V_7 ;
if ( * V_7 == '\n' ) {
T_1 V_9 [ 2 ] = { '\r' , 0 } ;
F_1 ( V_9 ) ;
}
F_1 ( V_8 ) ;
}
}
static T_2 F_4 ( T_3 * * V_10 , unsigned long * V_11 ,
unsigned long * V_12 )
{
T_3 * V_13 = NULL ;
T_2 V_14 ;
unsigned long V_15 ;
T_4 V_16 ;
* V_11 = sizeof( * V_13 ) * 32 ;
V_17:
* V_11 += sizeof( * V_13 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , * V_11 , ( void * * ) & V_13 ) ;
if ( V_14 != V_21 )
goto V_22;
V_14 = F_6 ( V_4 -> V_18 -> V_23 , V_11 ,
V_13 , & V_15 , V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_7 ( V_4 -> V_18 -> V_25 , V_13 ) ;
goto V_17;
}
if ( V_14 != V_21 )
F_7 ( V_4 -> V_18 -> V_25 , V_13 ) ;
V_22:
* V_10 = V_13 ;
return V_14 ;
}
static T_2 F_8 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 , unsigned long V_29 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
T_5 V_31 = 0 ;
int V_32 ;
V_14 = F_4 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
V_17:
for ( V_32 = 0 ; V_32 < V_11 / V_12 ; V_32 ++ ) {
T_3 * V_34 ;
unsigned long V_13 = ( unsigned long ) V_10 ;
T_5 V_35 , V_36 ;
V_34 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
if ( V_34 -> type != V_37 )
continue;
if ( V_34 -> V_38 < V_30 )
continue;
V_35 = V_34 -> V_39 ;
V_36 = V_35 + V_34 -> V_38 * ( 1UL << V_40 ) ;
if ( ( V_35 + V_26 ) > V_36 || ( V_35 + V_26 ) > V_29 )
continue;
if ( V_36 - V_26 > V_29 )
V_36 = V_29 ;
if ( F_10 ( V_36 - V_26 , V_27 ) < V_35 )
continue;
V_35 = F_10 ( V_36 - V_26 , V_27 ) ;
if ( V_35 == 0x0 )
continue;
if ( V_35 > V_31 )
V_31 = V_35 ;
}
if ( ! V_31 )
V_14 = V_41 ;
else {
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_31 ) ;
if ( V_14 != V_21 ) {
V_29 = V_31 ;
V_31 = 0 ;
goto V_17;
}
* V_28 = V_31 ;
}
V_25:
F_7 ( V_4 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static T_2 F_12 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
int V_32 ;
V_14 = F_4 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
for ( V_32 = 0 ; V_32 < V_11 / V_12 ; V_32 ++ ) {
T_3 * V_34 ;
unsigned long V_13 = ( unsigned long ) V_10 ;
T_5 V_35 , V_36 ;
V_34 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
if ( V_34 -> type != V_37 )
continue;
if ( V_34 -> V_38 < V_30 )
continue;
V_35 = V_34 -> V_39 ;
V_36 = V_35 + V_34 -> V_38 * ( 1UL << V_40 ) ;
if ( V_35 == 0x0 )
V_35 += 8 ;
V_35 = F_9 ( V_35 , V_27 ) ;
if ( ( V_35 + V_26 ) > V_36 )
continue;
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 == V_21 ) {
* V_28 = V_35 ;
break;
}
}
if ( V_32 == V_11 / V_12 )
V_14 = V_41 ;
V_25:
F_7 ( V_4 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static void F_13 ( unsigned long V_26 , unsigned long V_28 )
{
unsigned long V_30 ;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
F_2 ( V_4 -> V_18 -> V_44 , V_28 , V_26 ) ;
}
static void F_14 ( unsigned long V_45 , T_6 * V_46 , T_6 * V_26 )
{
T_6 V_47 , V_48 ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_45 ) {
while ( ! ( V_45 & 0x1 ) ) {
V_45 = V_45 >> 1 ;
V_47 ++ ;
}
while ( V_45 & 0x1 ) {
V_45 = V_45 >> 1 ;
V_48 ++ ;
}
}
* V_46 = V_47 ;
* V_26 = V_48 ;
}
static T_2 F_15 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_5 V_55 , V_56 , V_57 ;
T_2 V_14 ;
if ( V_4 -> V_58 -> V_59 . V_60 < V_61 )
return V_62 ;
V_52 = (struct V_51 * ) ( unsigned long ) V_50 -> V_59 . V_51 ;
while ( V_52 && V_52 -> V_63 )
V_52 = (struct V_51 * ) ( unsigned long ) V_52 -> V_63 ;
V_14 = F_11 ( ( void * ) V_4 -> V_58 -> V_64 ,
V_65 |
V_66 |
V_67 , & V_55 ,
& V_56 , & V_57 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , sizeof( * V_54 ) , & V_54 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_54 -> V_52 . type = V_68 ;
V_54 -> V_52 . V_48 = sizeof( struct V_53 ) -
sizeof( struct V_51 ) ;
V_54 -> V_52 . V_63 = 0 ;
V_54 -> V_55 = V_55 ;
V_54 -> V_56 = V_56 ;
V_54 -> V_69 = V_57 ;
if ( V_52 )
V_52 -> V_63 = ( unsigned long ) V_54 ;
else
V_50 -> V_59 . V_51 = ( unsigned long ) V_54 ;
}
static T_2 F_16 ( struct V_49 * V_50 )
{
T_7 * V_70 ;
T_2 V_14 ;
void * * V_71 ;
T_8 V_72 = V_73 ;
unsigned long V_74 , V_26 = 0 ;
int V_32 ;
struct V_51 * V_52 ;
V_52 = (struct V_51 * ) ( unsigned long ) V_50 -> V_59 . V_51 ;
while ( V_52 && V_52 -> V_63 )
V_52 = (struct V_51 * ) ( unsigned long ) V_52 -> V_63 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , & V_72 ,
NULL , & V_26 , V_71 ) ;
if ( V_14 == V_24 ) {
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_71 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , & V_72 ,
NULL , & V_26 , V_71 ) ;
}
if ( V_14 != V_21 )
goto V_77;
V_74 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_74 ; V_32 ++ ) {
void * V_78 = V_71 [ V_32 ] ;
T_9 V_79 ;
struct V_80 * V_81 ;
V_14 = F_5 ( V_4 -> V_18 -> V_82 ,
V_78 , & V_72 , & V_70 ) ;
if ( V_14 != V_21 )
continue;
if ( ! V_70 )
continue;
#ifdef F_17
V_14 = F_11 ( V_70 -> V_79 , V_70 ,
V_83 , 0 ,
& V_79 ) ;
#else
V_14 = F_6 ( V_70 -> V_79 , V_70 ,
V_83 , 0 , 0 ,
& V_79 ) ;
#endif
if ( V_14 != V_21 )
continue;
if ( ! V_70 -> V_84 || ! V_70 -> V_85 )
continue;
V_26 = V_70 -> V_85 + sizeof( * V_81 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_81 ) ;
if ( V_14 != V_21 )
continue;
V_81 -> V_52 . type = V_86 ;
V_81 -> V_52 . V_48 = V_26 - sizeof( struct V_51 ) ;
V_81 -> V_52 . V_63 = 0 ;
V_81 -> V_87 = V_70 -> V_85 ;
V_14 = F_6 ( V_70 -> V_70 . V_88 , V_70 ,
V_89 , V_90 ,
1 , & ( V_81 -> V_91 ) ) ;
if ( V_14 != V_21 )
goto V_92;
V_14 = F_6 ( V_70 -> V_70 . V_88 , V_70 ,
V_89 , V_93 ,
1 , & ( V_81 -> V_94 ) ) ;
if ( V_14 != V_21 )
goto V_92;
V_14 = F_6 ( V_70 -> V_95 , V_70 ,
& ( V_81 -> V_96 ) , & ( V_81 -> V_97 ) ,
& ( V_81 -> V_98 ) , & ( V_81 -> V_99 ) ) ;
if ( V_14 != V_21 )
goto V_92;
memcpy ( V_81 -> V_100 , V_70 -> V_84 , V_70 -> V_85 ) ;
if ( V_52 )
V_52 -> V_63 = ( unsigned long ) V_81 ;
else
V_50 -> V_59 . V_51 = ( unsigned long ) V_81 ;
V_52 = (struct V_51 * ) V_81 ;
continue;
V_92:
F_7 ( V_4 -> V_18 -> V_25 , V_81 ) ;
}
V_77:
F_7 ( V_4 -> V_18 -> V_25 , V_71 ) ;
return V_14 ;
}
static T_2 F_18 ( struct V_101 * V_102 , T_8 * V_103 ,
unsigned long V_26 )
{
struct V_104 * V_105 , * V_106 ;
struct V_107 V_108 ;
unsigned long V_109 ;
T_2 V_14 ;
void * * V_110 ;
T_10 V_111 , V_112 ;
T_4 V_113 , V_114 ;
T_4 V_115 ;
int V_116 ;
int V_32 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_110 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , V_103 ,
NULL , & V_26 , V_110 ) ;
if ( V_14 != V_21 )
goto V_77;
V_106 = NULL ;
V_109 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_109 ; V_32 ++ ) {
struct V_117 * V_118 ;
T_8 V_119 = V_120 ;
bool V_121 = false ;
void * V_122 ;
void * V_78 = V_110 [ V_32 ] ;
V_14 = F_5 ( V_4 -> V_18 -> V_82 ,
V_78 , V_103 , & V_105 ) ;
if ( V_14 != V_21 )
continue;
V_14 = F_5 ( V_4 -> V_18 -> V_82 ,
V_78 , & V_119 , & V_122 ) ;
if ( V_14 == V_21 )
V_121 = true ;
V_14 = F_11 ( V_105 -> V_123 , V_105 ,
V_105 -> V_124 -> V_124 , & V_26 , & V_118 ) ;
if ( V_14 == V_21 && ( ! V_106 || V_121 ) ) {
V_111 = V_118 -> V_125 ;
V_112 = V_118 -> V_126 ;
V_113 = V_105 -> V_124 -> V_127 ;
V_114 = V_105 -> V_124 -> V_128 ;
V_116 = V_118 -> V_116 ;
V_108 = V_118 -> V_129 ;
V_115 = V_118 -> V_115 ;
V_106 = V_105 ;
if ( V_121 )
break;
}
}
if ( ! V_106 )
goto V_77;
V_102 -> V_130 = V_131 ;
V_102 -> V_132 = V_111 ;
V_102 -> V_133 = V_112 ;
V_102 -> V_134 = V_113 ;
V_102 -> V_135 = 1 ;
if ( V_116 == V_136 ) {
V_102 -> V_137 = 32 ;
V_102 -> V_138 = V_115 * 4 ;
V_102 -> V_139 = 8 ;
V_102 -> V_140 = 0 ;
V_102 -> V_141 = 8 ;
V_102 -> V_142 = 8 ;
V_102 -> V_143 = 8 ;
V_102 -> V_144 = 16 ;
V_102 -> V_145 = 8 ;
V_102 -> V_146 = 24 ;
} else if ( V_116 == V_147 ) {
V_102 -> V_137 = 32 ;
V_102 -> V_138 = V_115 * 4 ;
V_102 -> V_139 = 8 ;
V_102 -> V_140 = 16 ;
V_102 -> V_141 = 8 ;
V_102 -> V_142 = 8 ;
V_102 -> V_143 = 8 ;
V_102 -> V_144 = 0 ;
V_102 -> V_145 = 8 ;
V_102 -> V_146 = 24 ;
} else if ( V_116 == V_148 ) {
F_14 ( V_108 . V_149 , & V_102 -> V_140 , & V_102 -> V_139 ) ;
F_14 ( V_108 . V_150 , & V_102 -> V_142 ,
& V_102 -> V_141 ) ;
F_14 ( V_108 . V_151 , & V_102 -> V_144 , & V_102 -> V_143 ) ;
F_14 ( V_108 . V_152 , & V_102 -> V_146 ,
& V_102 -> V_145 ) ;
V_102 -> V_137 = V_102 -> V_139 + V_102 -> V_141 +
V_102 -> V_143 + V_102 -> V_145 ;
V_102 -> V_138 = ( V_115 * V_102 -> V_137 ) / 8 ;
} else {
V_102 -> V_137 = 4 ;
V_102 -> V_138 = V_102 -> V_132 / 2 ;
V_102 -> V_139 = 0 ;
V_102 -> V_140 = 0 ;
V_102 -> V_141 = 0 ;
V_102 -> V_142 = 0 ;
V_102 -> V_143 = 0 ;
V_102 -> V_144 = 0 ;
V_102 -> V_145 = 0 ;
V_102 -> V_146 = 0 ;
}
V_102 -> V_153 = V_102 -> V_138 * V_102 -> V_133 ;
V_102 -> V_154 |= V_155 ;
V_77:
F_7 ( V_4 -> V_18 -> V_25 , V_110 ) ;
return V_14 ;
}
static T_2 F_19 ( struct V_101 * V_102 , T_8 * V_156 ,
unsigned long V_26 )
{
struct V_157 * V_158 , * V_159 ;
unsigned long V_160 ;
T_2 V_14 ;
T_4 V_111 , V_112 ;
void * * V_161 = NULL ;
int V_32 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_161 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , V_156 ,
NULL , & V_26 , V_161 ) ;
if ( V_14 != V_21 )
goto V_77;
V_159 = NULL ;
V_160 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_160 ; V_32 ++ ) {
T_8 V_162 = V_73 ;
void * V_163 = V_161 [ V_32 ] ;
T_4 V_164 , V_78 , V_165 , V_166 ;
void * V_167 ;
V_14 = F_5 ( V_4 -> V_18 -> V_82 ,
V_163 , V_156 , & V_158 ) ;
if ( V_14 != V_21 )
continue;
F_5 ( V_4 -> V_18 -> V_82 ,
V_163 , & V_162 , & V_167 ) ;
V_14 = F_6 ( V_158 -> V_168 , V_158 , & V_164 , & V_78 ,
& V_165 , & V_166 ) ;
if ( V_14 == V_21 && ( ! V_159 || V_167 ) ) {
V_111 = V_164 ;
V_112 = V_78 ;
if ( V_167 )
break;
V_159 = V_158 ;
}
}
if ( ! V_159 )
goto V_77;
V_102 -> V_130 = V_131 ;
V_102 -> V_137 = 32 ;
V_102 -> V_132 = V_111 ;
V_102 -> V_133 = V_112 ;
V_102 -> V_139 = 8 ;
V_102 -> V_140 = 16 ;
V_102 -> V_141 = 8 ;
V_102 -> V_142 = 8 ;
V_102 -> V_143 = 8 ;
V_102 -> V_144 = 0 ;
V_102 -> V_145 = 8 ;
V_102 -> V_146 = 24 ;
V_77:
F_7 ( V_4 -> V_18 -> V_25 , V_161 ) ;
return V_14 ;
}
void F_20 ( struct V_49 * V_49 )
{
T_8 V_169 = V_170 ;
struct V_101 * V_102 ;
T_8 V_156 = V_171 ;
T_2 V_14 ;
unsigned long V_26 ;
void * * V_110 = NULL ;
void * * V_161 = NULL ;
V_102 = & V_49 -> V_101 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_26 = 0 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , & V_169 ,
NULL , & V_26 , V_110 ) ;
if ( V_14 == V_24 )
V_14 = F_18 ( V_102 , & V_169 , V_26 ) ;
if ( V_14 != V_21 ) {
V_26 = 0 ;
V_14 = F_6 ( V_4 -> V_18 -> V_75 ,
V_76 , & V_156 ,
NULL , & V_26 , V_161 ) ;
if ( V_14 == V_24 )
F_19 ( V_102 , & V_156 , V_26 ) ;
}
}
static T_2 F_21 ( T_11 * V_172 ,
struct V_173 * V_59 )
{
struct V_174 * V_175 ;
unsigned long V_176 ;
T_8 V_177 = V_178 ;
T_5 V_179 ;
T_12 * V_180 ;
T_13 * V_181 ;
T_2 V_14 ;
int V_182 ;
char * V_1 ;
int V_32 , V_183 , V_184 ;
V_176 = 0 ;
V_179 = 0 ;
V_1 = ( char * ) ( unsigned long ) V_59 -> V_185 ;
V_183 = 0 ;
if ( ! V_1 || ! * V_1 )
return V_21 ;
for ( V_182 = 0 ; * V_1 ; V_182 ++ ) {
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' )
V_1 ++ ;
}
if ( ! V_182 )
return V_21 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 ,
V_182 * sizeof( * V_175 ) ,
& V_175 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_2 ) ;
goto V_22;
}
V_1 = ( char * ) ( unsigned long ) V_59 -> V_185 ;
for ( V_32 = 0 ; V_32 < V_182 ; V_32 ++ ) {
struct V_174 * V_174 ;
T_13 * V_78 ;
T_14 * V_118 ;
T_1 V_186 [ 256 ] ;
unsigned long V_187 ;
T_8 V_188 = V_189 ;
T_1 * V_190 ;
T_5 V_191 ;
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
V_174 = & V_175 [ V_32 ] ;
V_190 = V_186 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' ) {
if ( ( T_6 * ) V_190 >= ( T_6 * ) V_186 + sizeof( V_186 ) )
break;
if ( * V_1 == '/' ) {
* V_190 ++ = '\\' ;
* V_1 ++ ;
} else {
* V_190 ++ = * V_1 ++ ;
}
}
* V_190 = '\0' ;
if ( ! V_32 ) {
T_15 * V_18 ;
V_18 = V_4 -> V_18 ;
V_14 = F_5 ( V_18 -> V_82 ,
V_172 -> V_192 , & V_177 , & V_180 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_3 ) ;
goto V_193;
}
V_14 = F_2 ( V_180 -> V_194 , V_180 , & V_181 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_4 ) ;
goto V_193;
}
}
V_14 = F_6 ( V_181 -> V_195 , V_181 , & V_78 , V_186 ,
V_196 , ( T_5 ) 0 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_5 ) ;
F_1 ( V_186 ) ;
F_3 ( L_6 ) ;
goto V_197;
}
V_174 -> V_163 = V_78 ;
V_187 = 0 ;
V_14 = F_11 ( V_78 -> V_198 , V_78 , & V_188 ,
& V_187 , NULL ) ;
if ( V_14 != V_24 ) {
F_3 ( L_7 ) ;
goto V_197;
}
V_199:
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_187 , & V_118 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_8 ) ;
goto V_197;
}
V_14 = F_11 ( V_78 -> V_198 , V_78 , & V_188 ,
& V_187 , V_118 ) ;
if ( V_14 == V_24 ) {
F_7 ( V_4 -> V_18 -> V_25 , V_118 ) ;
goto V_199;
}
V_191 = V_118 -> V_200 ;
F_7 ( V_4 -> V_18 -> V_25 , V_118 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_9 ) ;
goto V_197;
}
V_174 -> V_26 = V_191 ;
V_179 += V_191 ;
}
if ( V_179 ) {
unsigned long V_28 ;
V_14 = F_8 ( V_179 , 0x1000 ,
& V_176 , V_59 -> V_201 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_10 ) ;
goto V_197;
}
if ( V_176 > V_59 -> V_201 ) {
F_3 ( L_11 ) ;
V_14 = V_202 ;
goto V_203;
}
V_28 = V_176 ;
for ( V_183 = 0 ; V_183 < V_182 ; V_183 ++ ) {
T_5 V_26 ;
V_26 = V_175 [ V_183 ] . V_26 ;
while ( V_26 ) {
T_5 V_204 ;
if ( V_26 > V_205 )
V_204 = V_205 ;
else
V_204 = V_26 ;
V_14 = F_5 ( V_181 -> V_88 ,
V_175 [ V_183 ] . V_163 ,
& V_204 , V_28 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_12 ) ;
goto V_203;
}
V_28 += V_204 ;
V_26 -= V_204 ;
}
F_7 ( V_181 -> V_206 , V_175 [ V_183 ] . V_163 ) ;
}
}
F_7 ( V_4 -> V_18 -> V_25 , V_175 ) ;
V_59 -> V_207 = V_176 ;
V_59 -> V_208 = V_179 ;
return V_14 ;
V_203:
F_13 ( V_179 , V_176 ) ;
V_197:
for ( V_184 = V_183 ; V_184 < V_32 ; V_184 ++ )
F_7 ( V_181 -> V_206 , V_175 [ V_184 ] . V_163 ) ;
V_193:
F_7 ( V_4 -> V_18 -> V_25 , V_175 ) ;
V_22:
V_59 -> V_207 = 0 ;
V_59 -> V_208 = 0 ;
return V_14 ;
}
struct V_49 * F_22 ( void * V_163 , T_16 * V_209 )
{
struct V_49 * V_49 ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
struct V_173 * V_59 ;
struct V_214 * V_215 ;
T_11 * V_172 ;
void * V_216 ;
T_4 V_217 ;
T_8 V_103 = V_218 ;
int V_219 = 0 ;
T_2 V_14 ;
unsigned long V_220 ;
T_10 * V_221 ;
T_6 * V_222 ;
int V_32 ;
V_4 = V_209 ;
if ( V_4 -> V_59 . V_223 != V_224 )
return NULL ;
V_14 = F_5 ( V_4 -> V_18 -> V_82 ,
V_163 , & V_103 , ( void * ) & V_172 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_13 ) ;
return NULL ;
}
V_14 = F_12 ( 0x4000 , 1 , ( unsigned long * ) & V_49 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_14 ) ;
return NULL ;
}
memset ( V_49 , 0x0 , 0x4000 ) ;
V_59 = & V_49 -> V_59 ;
V_215 = & V_49 -> V_214 ;
V_213 = & V_49 -> V_212 ;
V_211 = & V_49 -> V_210 ;
memcpy ( & V_59 -> V_225 , V_172 -> V_226 + 512 , 512 ) ;
V_59 -> V_227 = 1 ;
V_59 -> V_228 = 0xffff ;
V_59 -> V_229 = 0xAA55 ;
V_59 -> V_230 = ( V_231 ) ( unsigned long ) V_172 -> V_226 ;
V_59 -> V_232 = 0x21 ;
V_216 = V_172 -> V_233 ;
V_217 = V_172 -> V_217 / 2 ;
V_220 = 0 ;
V_221 = ( T_10 * ) V_216 ;
if ( V_221 ) {
while ( * V_221 && * V_221 != '\n' && V_219 < V_217 ) {
V_221 ++ ;
V_219 ++ ;
}
if ( V_219 ) {
if ( V_219 > V_59 -> V_234 )
V_219 = V_59 -> V_234 ;
V_219 ++ ;
V_14 = F_12 ( V_219 , 1 , & V_220 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_15 ) ;
goto V_22;
}
V_222 = ( T_6 * ) ( unsigned long ) V_220 ;
V_221 = ( T_10 * ) V_216 ;
for ( V_32 = 0 ; V_32 < V_219 - 1 ; V_32 ++ )
* V_222 ++ = * V_221 ++ ;
* V_222 = '\0' ;
}
}
V_59 -> V_185 = V_220 ;
V_59 -> V_207 = 0 ;
V_59 -> V_208 = 0 ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
V_14 = F_21 ( V_172 , V_59 ) ;
if ( V_14 != V_21 )
goto V_235;
return V_49 ;
V_235:
if ( V_219 )
F_13 ( V_219 , V_59 -> V_185 ) ;
V_22:
F_13 ( 0x4000 , ( unsigned long ) V_49 ) ;
return NULL ;
}
static T_2 F_23 ( struct V_49 * V_49 ,
void * V_163 )
{
struct V_214 * V_215 = & V_49 -> V_214 ;
struct V_236 * V_237 = & V_49 -> V_237 [ 0 ] ;
struct V_236 * V_238 = NULL ;
unsigned long V_26 , V_15 , V_12 , V_239 ;
T_3 * V_240 ;
T_2 V_14 ;
T_17 V_16 ;
T_6 V_241 ;
int V_32 ;
V_26 = sizeof( * V_240 ) * 32 ;
V_17:
V_26 += sizeof( * V_240 ) ;
V_239 = V_26 ;
V_14 = F_12 ( V_26 , 1 , ( unsigned long * ) & V_240 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_23 , & V_26 ,
V_240 , & V_15 , & V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_13 ( V_239 , ( unsigned long ) V_240 ) ;
goto V_17;
}
if ( V_14 != V_21 )
goto V_242;
memcpy ( & V_215 -> V_243 , V_244 , sizeof( T_17 ) ) ;
V_215 -> V_245 = ( unsigned long ) V_4 ;
V_215 -> V_246 = V_12 ;
V_215 -> V_247 = V_16 ;
V_215 -> V_248 = ( unsigned long ) V_240 ;
V_215 -> V_249 = V_26 ;
#ifdef F_17
V_215 -> V_250 = ( unsigned long ) V_4 >> 32 ;
V_215 -> V_251 = ( unsigned long ) V_240 >> 32 ;
#endif
V_14 = F_2 ( V_4 -> V_18 -> V_252 ,
V_163 , V_15 ) ;
if ( V_14 != V_21 )
goto V_242;
V_49 -> V_253 = 32 * 1024 ;
V_241 = 0 ;
for ( V_32 = 0 ; V_32 < V_26 / V_12 ; V_32 ++ ) {
T_3 * V_254 ;
unsigned int V_255 = 0 ;
unsigned long V_13 = ( unsigned long ) V_240 ;
V_254 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
switch ( V_254 -> type ) {
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
V_255 = V_262 ;
break;
case V_263 :
V_255 = V_264 ;
break;
case V_265 :
V_255 = V_266 ;
break;
case V_267 :
case V_20 :
case V_268 :
case V_269 :
case V_37 :
V_255 = V_270 ;
break;
case V_271 :
V_255 = V_272 ;
break;
default:
continue;
}
if ( V_238 && V_238 -> type == V_255 &&
( V_238 -> V_28 + V_238 -> V_26 ) == V_254 -> V_39 )
V_238 -> V_26 += V_254 -> V_38 << 12 ;
else {
V_237 -> V_28 = V_254 -> V_39 ;
V_237 -> V_26 = V_254 -> V_38 << 12 ;
V_237 -> type = V_255 ;
V_238 = V_237 ++ ;
V_241 ++ ;
}
}
V_49 -> V_273 = V_241 ;
return V_21 ;
V_242:
F_13 ( V_239 , ( unsigned long ) V_240 ) ;
return V_14 ;
}
static T_2 F_24 ( struct V_173 * V_59 )
{
unsigned long V_35 , V_30 ;
T_2 V_14 ;
V_35 = V_59 -> V_274 ;
V_30 = F_9 ( V_59 -> V_275 , V_33 ) / V_33 ;
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 != V_21 ) {
V_14 = F_12 ( V_59 -> V_275 , V_59 -> V_276 ,
& V_35 ) ;
if ( V_14 != V_21 )
F_3 ( L_16 ) ;
}
if ( V_14 == V_21 )
memcpy ( ( void * ) V_35 , ( void * ) ( unsigned long ) V_59 -> V_230 ,
V_59 -> V_275 ) ;
V_59 -> V_274 = V_59 -> V_230 ;
V_59 -> V_230 = ( T_17 ) V_35 ;
return V_14 ;
}
struct V_49 * F_25 ( void * V_163 , T_16 * V_209 ,
struct V_49 * V_49 )
{
struct V_277 * V_278 , * V_279 ;
T_11 * V_172 ;
struct V_173 * V_59 = & V_49 -> V_59 ;
T_2 V_14 ;
struct V_280 * V_34 ;
V_4 = V_209 ;
if ( V_4 -> V_59 . V_223 != V_224 )
goto V_22;
F_20 ( V_49 ) ;
F_15 ( V_49 ) ;
F_16 ( V_49 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , sizeof( * V_278 ) ,
( void * * ) & V_278 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_17 ) ;
goto V_22;
}
V_278 -> V_26 = 0x800 ;
V_14 = F_12 ( V_278 -> V_26 , 8 , ( unsigned long * ) & V_278 -> V_281 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_18 ) ;
goto V_22;
}
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , sizeof( * V_279 ) ,
( void * * ) & V_279 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_19 ) ;
goto V_22;
}
V_279 -> V_26 = 0 ;
V_279 -> V_281 = 0 ;
if ( V_59 -> V_274 != V_59 -> V_230 ) {
V_14 = F_24 ( V_59 ) ;
if ( V_14 != V_21 )
goto V_22;
}
V_14 = F_23 ( V_49 , V_163 ) ;
if ( V_14 != V_21 )
goto V_22;
memset ( ( char * ) V_278 -> V_281 , 0x0 , V_278 -> V_26 ) ;
V_34 = (struct V_280 * ) V_278 -> V_281 ;
V_34 += 2 ;
V_34 -> V_282 = 0xffff ;
V_34 -> V_283 = 0x0000 ;
V_34 -> V_284 = 0x0000 ;
V_34 -> type = V_285 | V_286 ;
V_34 -> V_287 = V_288 ;
V_34 -> V_289 = 0 ;
V_34 -> V_190 = 1 ;
V_34 -> V_290 = 0xf ;
V_34 -> V_291 = 0 ;
V_34 -> V_292 = 0 ;
V_34 -> V_254 = V_293 ;
V_34 -> V_294 = V_295 ;
V_34 -> V_296 = 0x00 ;
V_34 ++ ;
V_34 -> V_282 = 0xffff ;
V_34 -> V_283 = 0x0000 ;
V_34 -> V_284 = 0x0000 ;
V_34 -> type = V_297 | V_298 ;
V_34 -> V_287 = V_288 ;
V_34 -> V_289 = 0 ;
V_34 -> V_190 = 1 ;
V_34 -> V_290 = 0xf ;
V_34 -> V_291 = 0 ;
V_34 -> V_292 = 0 ;
V_34 -> V_254 = V_293 ;
V_34 -> V_294 = V_295 ;
V_34 -> V_296 = 0x00 ;
#ifdef F_17
V_34 ++ ;
V_34 -> V_282 = 0x0000 ;
V_34 -> V_283 = 0x0000 ;
V_34 -> V_284 = 0x0000 ;
V_34 -> type = V_299 ;
V_34 -> V_287 = 0 ;
V_34 -> V_289 = 0 ;
V_34 -> V_190 = 1 ;
V_34 -> V_290 = 0x0 ;
V_34 -> V_291 = 0 ;
V_34 -> V_292 = 0 ;
V_34 -> V_254 = 0 ;
V_34 -> V_294 = V_295 ;
V_34 -> V_296 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_49 ;
V_22:
return NULL ;
}
