static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
char * V_5 , * V_6 ;
V_4 = V_7 ;
V_3 = V_8 ;
if ( F_2 ( V_2 -> type ) && V_2 -> V_9 ) {
if ( V_10 == V_11 ) {
F_3 ( V_2 , V_12 , V_3 ) ;
V_5 = L_1 ;
} else if ( V_10 == V_13 ) {
F_3 ( V_2 , V_14 , V_3 ) ;
V_5 = L_2 ;
} else {
F_3 ( V_2 , 0 , V_3 ) ;
V_5 = L_3 ;
}
} else if ( F_2 ( V_2 -> type ) && V_15 ) {
F_3 ( V_2 , 0 , V_3 ) ;
V_5 = L_4 ;
} else {
F_3 ( V_2 , 0 , V_4 ) ;
V_5 = L_5 ;
}
if ( F_2 ( V_2 -> type ) && V_15 && V_2 -> V_16 > 2 )
V_6 = L_6 ;
else if ( F_2 ( V_2 -> type ) )
V_6 = L_7 ;
else
V_6 = L_5 ;
F_4 ( V_17 , V_2 ,
L_8 ,
V_2 -> V_16 , V_6 , V_5 ) ;
return 0 ;
}
static int F_5 ( unsigned long V_18 , unsigned int V_19 )
{
while ( F_6 ( V_18 + V_20 ) & V_21 ) {
F_7 ( 1L ) ;
if ( -- V_19 == 0 )
return 1 ;
}
return 0 ;
}
static int F_8 ( unsigned long V_18 , unsigned long V_22 , T_1 V_23 )
{
unsigned char * V_24 ;
unsigned long V_25 ;
if ( F_5 ( V_18 , ( V_22 ? V_26 * 100 : V_26 ) ) )
return 1 ;
if ( V_22 ) {
V_25 = F_9 ( V_22 ) ;
V_24 = ( unsigned char * ) & V_25 ;
F_10 ( V_24 [ 3 ] , V_18 + V_27 ) ;
F_10 ( V_24 [ 2 ] , V_18 + V_28 ) ;
F_10 ( V_24 [ 1 ] , V_18 + V_29 ) ;
F_10 ( V_24 [ 0 ] , V_18 + V_30 ) ;
}
F_10 ( V_23 , V_18 + V_31 ) ;
return 0 ;
}
static int F_11 ( unsigned long V_18 , T_2 * V_32 , T_2 * V_33 )
{
unsigned int V_19 = V_26 ;
T_2 * V_34 ;
for ( V_34 = V_32 ; V_34 <= V_33 ; V_34 ++ ) {
while ( ! ( F_6 ( V_18 + V_35 ) & V_36 ) ) {
F_7 ( 1L ) ;
if ( -- V_19 == 0 )
return 1 ;
}
V_19 = V_26 ;
* V_34 = F_12 ( F_13 ( V_18 ) ) ;
}
return 0 ;
}
static struct V_37 * F_14 ( unsigned long V_38 )
{
#if F_15 ( V_39 )
unsigned int V_22 ;
struct V_37 * V_2 = NULL ;
while ( ( V_2 = F_16 ( V_40 << 8 , V_2 ) ) ) {
V_22 = F_17 ( V_2 , 0 ) ;
#if F_15 ( V_41 )
F_18 ( L_9 ,
V_42 , V_2 -> V_43 -> V_44 , V_2 -> V_45 , V_22 ) ;
#endif
F_19 ( V_2 ) ;
if ( V_22 + V_46 == V_38 )
return V_2 ;
}
#endif
return NULL ;
}
static void F_20 ( void )
{
#if F_15 ( V_39 )
struct V_37 * V_2 = NULL ;
while ( ( V_2 = F_16 ( V_40 << 8 , V_2 ) ) ) {
#if F_15 ( V_41 )
F_18 ( L_10 ,
V_42 , V_2 -> V_43 -> V_44 , V_2 -> V_45 ) ;
#endif
if ( F_21 ( V_2 ) )
F_18
( L_11 ,
V_42 , V_2 -> V_43 -> V_44 , V_2 -> V_45 ) ;
}
#endif
}
static int F_22 ( unsigned long V_38 , unsigned int V_47 ,
struct V_48 * V_49 )
{
unsigned char V_50 , V_51 , V_52 , V_53 , V_54 = 0 ;
unsigned char V_55 ;
struct V_56 V_57 ;
char * V_58 , V_59 [ 16 ] ;
struct V_37 * V_60 ;
unsigned char V_61 [ 4 ] = { 5 , 6 , 7 , 0 } ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
char V_66 [ 16 ] ;
sprintf ( V_66 , L_12 , V_42 , V_47 ) ;
if ( ! F_23 ( V_38 , V_67 , V_42 ) ) {
#if F_15 ( V_68 )
F_18 ( L_13 , V_66 ,
V_38 ) ;
#endif
goto V_69;
}
F_24 ( & V_70 ) ;
if ( F_8 ( V_38 , 0 , V_71 ) ) {
#if F_15 ( V_68 )
F_18 ( L_14 , V_66 ,
V_38 ) ;
#endif
goto V_72;
}
if ( F_11 ( V_38 , ( T_2 * ) & V_57 , ( T_2 * ) & V_57 . V_73 [ 0 ] ) ) {
#if F_15 ( V_68 )
F_18 ( L_15 , V_66 ,
V_38 ) ;
#endif
goto V_72;
}
V_57 . V_74 = F_25 ( V_57 . V_74 ) ;
V_57 . V_75 = F_25 ( V_57 . V_75 ) ;
V_57 . V_76 = F_26 ( V_57 . V_76 ) ;
V_57 . V_77 = F_25 ( V_57 . V_77 ) ;
V_57 . V_78 = F_25 ( V_57 . V_78 ) ;
V_57 . V_79 = F_26 ( V_57 . V_79 ) ;
V_57 . V_80 = F_26 ( V_57 . V_80 ) ;
if ( V_57 . V_75 != V_81 ) {
#if F_15 ( V_68 )
F_18 ( L_16 , V_66 , V_57 . V_75 ) ;
#endif
goto V_72;
}
if ( V_57 . V_74 < V_82 ) {
F_18
( L_17 ,
V_66 , V_57 . V_74 ) ;
goto V_72;
} else if ( V_57 . V_74 == V_82 )
V_55 = 'A' ;
else if ( V_57 . V_74 == V_83 )
V_55 = 'B' ;
else
V_55 = 'C' ;
if ( V_55 != 'A' && V_57 . V_84 ) {
F_18 ( L_18 , V_66 ) ;
V_58 = L_19 ;
V_54 = 1 ;
V_52 = V_85 ;
} else if ( V_38 > V_86
|| ( V_55 == 'C' && V_57 . V_87 ) ) {
V_58 = L_19 ;
V_54 = 1 ;
V_52 = V_85 ;
} else if ( V_38 >= V_88
|| ( V_55 == 'C' && V_57 . V_89 ) ) {
V_58 = L_20 ;
V_52 = V_85 ;
} else if ( V_55 == 'C' && ! V_57 . V_89 && ! V_57 . V_87 ) {
V_58 = L_21 ;
V_52 = V_90 ;
} else if ( V_38 > V_91 ) {
V_58 = L_19 ;
V_54 = 1 ;
V_52 = V_85 ;
} else {
V_58 = L_21 ;
V_52 = V_90 ;
}
if ( ! V_57 . V_92 || V_57 . V_93 ) {
F_18
( L_22 ,
V_66 , V_38 , V_58 , V_57 . V_92 , V_57 . V_93 ) ;
goto V_72;
}
if ( V_57 . V_94 ) {
if ( V_52 == V_85 )
F_18 ( L_23 , V_66 ,
V_58 ) ;
V_52 = V_90 ;
V_51 = V_61 [ 3 - V_57 . V_95 ] ;
} else {
if ( V_52 == V_90 )
F_18 ( L_24 ,
V_66 , V_58 ) ;
V_52 = V_85 ;
V_51 = V_96 ;
}
if ( ! V_57 . V_97 )
F_18 ( L_25 ,
V_66 ) ;
V_50 = V_57 . V_50 ;
if ( V_52 == V_85 && ! V_57 . V_98 )
F_18
( L_26 ,
V_66 , V_50 ) ;
if ( V_54 ) {
V_60 = F_14 ( V_38 ) ;
if ( ! V_60 )
F_18
( L_27 ,
V_66 ) ;
} else
V_60 = NULL ;
if ( V_60 && ( V_50 != V_60 -> V_50 ) ) {
F_18 ( L_28 , V_66 , V_50 ,
V_60 -> V_50 ) ;
V_50 = V_60 -> V_50 ;
}
if ( F_27 ( V_50 , V_99 ,
V_100 | ( ( V_52 == V_85 ) ? V_101 : 0 ) ,
V_42 , ( void * ) & V_102 [ V_47 ] ) ) {
F_18 ( L_29 , V_66 ,
V_50 ) ;
goto V_72;
}
if ( V_52 == V_90 && F_28 ( V_51 , V_42 ) ) {
F_18 ( L_30 ,
V_66 , V_51 ) ;
goto V_103;
}
#if F_15 ( V_104 )
{
struct V_105 * V_106 ;
T_3 V_107 ;
V_106 = F_29 ( V_60 , sizeof( struct V_105 ) ,
& V_107 ) ;
if ( ! V_106 ) {
F_18
( L_31 ,
V_66 ) ;
goto V_108;
}
memset ( ( char * ) V_106 , 0 , sizeof( struct V_105 ) ) ;
V_106 -> V_109 = ( T_2 ) F_30 ( ( T_2 ) 510 ) ;
V_106 -> V_110 = 1 ;
if ( F_8 ( V_38 , V_107 , V_111 ) ) {
F_18
( L_32 ,
V_66 ) ;
F_31 ( V_60 , sizeof( struct V_105 ) ,
V_106 , V_107 ) ;
goto V_108;
}
}
#endif
F_32 ( & V_70 ) ;
V_112 [ V_47 ] = V_63 = F_33 ( V_49 , sizeof( struct V_64 ) ) ;
F_24 ( & V_70 ) ;
if ( V_63 == NULL ) {
F_18 ( L_33 , V_66 ) ;
goto V_108;
}
V_63 -> V_113 = V_38 ;
V_63 -> V_114 = V_38 ;
V_63 -> V_115 = V_67 ;
V_63 -> V_51 = V_51 ;
V_63 -> V_50 = V_50 ;
V_63 -> V_116 = ( T_2 ) V_57 . V_79 ;
V_63 -> V_117 = ( T_2 ) V_57 . V_118 [ 3 ] ;
V_63 -> V_119 = ( T_2 ) V_57 . V_80 ;
V_63 -> V_120 = V_7 ;
V_65 = (struct V_64 * ) V_63 -> V_64 ;
memset ( V_65 , 0 , sizeof( struct V_64 ) ) ;
V_65 -> V_52 = V_52 ;
V_65 -> V_55 = V_55 ;
V_65 -> V_54 = V_54 ;
V_65 -> V_60 = V_60 ;
V_65 -> V_121 = V_47 ;
if ( V_65 -> V_52 == V_85 )
V_63 -> V_122 = 0 ;
else {
unsigned long V_123 ;
V_63 -> V_122 = 1 ;
V_123 = F_34 () ;
F_35 ( V_51 ) ;
F_36 ( V_51 ) ;
F_37 ( V_51 , V_124 ) ;
F_38 ( V_51 ) ;
F_39 ( V_123 ) ;
}
strcpy ( V_65 -> V_125 , V_66 ) ;
if ( V_63 -> V_116 > V_126 || V_63 -> V_116 < 2 ) {
F_18 ( L_34 ,
V_65 -> V_125 , V_63 -> V_116 ) ;
V_63 -> V_116 = V_126 ;
}
if ( V_63 -> V_119 > V_127 || V_63 -> V_119 < 2 ) {
F_18 ( L_35 ,
V_65 -> V_125 , V_63 -> V_119 ) ;
V_63 -> V_119 = V_127 ;
}
if ( V_55 != 'A' ) {
if ( V_57 . V_128 > 0 && V_57 . V_128 < V_129 )
V_63 -> V_130 = V_57 . V_128 ;
if ( V_57 . V_131 > 7 && V_57 . V_131 < V_132 )
V_63 -> V_131 = V_57 . V_131 + 1 ;
if ( V_57 . V_133 && V_63 -> V_116 == V_126 )
V_63 -> V_116 = V_134 ;
}
if ( V_55 == 'C' ) {
if ( V_57 . V_135 > 7 && V_57 . V_135 < V_136 )
V_63 -> V_135 = V_57 . V_135 + 1 ;
}
if ( V_51 == V_96 )
sprintf ( V_59 , L_36 , L_37 ) ;
else
sprintf ( V_59 , L_38 , V_51 ) ;
F_32 ( & V_70 ) ;
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ )
V_65 -> V_137 [ V_53 ] . V_138 = F_40 ( V_65 -> V_60 ,
& V_65 -> V_137 [ V_53 ] ,
sizeof( struct V_139 ) ,
V_140 ) ;
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ ) {
T_4 V_141 = V_63 -> V_116 * sizeof( struct V_142 ) ;
T_5 V_143 = ( V_63 -> V_122 ? V_144 : 0 ) | V_145 ;
V_65 -> V_137 [ V_53 ] . V_146 = F_41 ( V_141 , V_143 ) ;
if ( ! V_65 -> V_137 [ V_53 ] . V_146 ) {
F_18
( L_39 ,
V_65 -> V_125 , V_53 ) ;
goto V_147;
}
}
if ( ! ( V_65 -> V_148 = F_29 ( V_65 -> V_60 ,
sizeof( struct V_149 ) ,
& V_65 -> V_150 ) ) ) {
F_18 ( L_40 , V_65 -> V_125 ) ;
goto V_147;
}
if ( V_8 > V_151 )
V_8 = V_151 ;
if ( V_8 < V_7 )
V_8 = V_7 ;
if ( V_10 != V_152 && V_10 != V_11 )
V_10 = V_13 ;
if ( V_47 == 0 ) {
F_18
( L_41 ) ;
F_18
( L_42
L_43 , V_42 , V_10 ,
F_42 ( V_15 ) , V_8 , F_42 ( V_153 ) ,
F_42 ( V_154 ) , F_42 ( V_155 ) , F_42 ( V_156 ) ,
F_42 ( V_157 ) ) ;
}
F_18 ( L_44 ,
V_65 -> V_125 , V_65 -> V_55 , V_58 ,
( unsigned long ) V_63 -> V_113 , V_63 -> V_50 , V_59 ,
V_63 -> V_116 , V_63 -> V_119 ) ;
if ( V_63 -> V_131 > 8 || V_63 -> V_135 > 8 )
F_18
( L_45 ,
V_65 -> V_125 , V_63 -> V_131 , V_63 -> V_135 ) ;
for ( V_53 = 0 ; V_53 <= V_63 -> V_130 ; V_53 ++ )
F_18 ( L_46 ,
V_65 -> V_125 , V_53 , V_57 . V_118 [ 3 - V_53 ] ) ;
#if F_15 ( V_68 )
F_18 ( L_47
L_48 , V_66 , V_57 . V_158 ,
V_57 . V_159 , V_57 . V_160 , V_57 . V_161 , V_57 . V_162 , V_57 . V_163 ,
V_57 . V_164 , V_57 . V_74 , V_57 . V_77 , V_57 . V_78 ) ;
if ( V_55 == 'B' || V_55 == 'C' )
F_18 ( L_49
L_50 , V_66 , V_57 . V_165 ,
V_57 . V_84 , V_57 . V_131 , V_57 . V_128 , V_57 . V_133 ,
V_57 . V_166 ) ;
if ( V_55 == 'C' )
F_18 ( L_51
L_52 , V_66 , V_57 . V_135 , V_57 . V_167 ,
V_57 . V_168 , V_57 . V_87 , V_57 . V_89 , V_57 . V_169 ) ;
#endif
if ( V_65 -> V_60 ) {
F_43 ( V_65 -> V_60 ) ;
if ( F_44 ( V_65 -> V_60 , F_45 ( 32 ) ) )
F_18 ( L_53 ,
V_65 -> V_125 ) ;
}
return 1 ;
V_108:
if ( V_52 == V_90 )
F_46 ( V_51 ) ;
V_103:
F_47 ( V_50 , & V_102 [ V_47 ] ) ;
V_72:
F_32 ( & V_70 ) ;
F_48 ( V_38 , V_67 ) ;
V_69:
return 0 ;
V_147:
F_49 ( V_63 ) ;
return 0 ;
}
static void F_50 ( char * V_170 , int * V_171 )
{
int V_53 , V_172 = V_171 [ 0 ] ;
char * V_173 = V_170 , * V_174 ;
if ( V_172 > 0 ) {
if ( V_172 > V_175 )
V_172 = V_175 ;
for ( V_53 = 0 ; V_53 < V_172 ; V_53 ++ )
V_113 [ V_53 ] = V_171 [ V_53 + 1 ] ;
V_113 [ V_53 ] = 0 ;
V_176 = 1 ;
}
while ( V_173 && ( V_174 = strchr ( V_173 , ':' ) ) ) {
int V_177 = 0 , V_178 = * ++ V_174 ;
if ( V_178 == 'n' || V_178 == 'N' )
V_177 = 0 ;
else if ( V_178 == 'y' || V_178 == 'Y' )
V_177 = 1 ;
else
V_177 = ( int ) F_51 ( V_174 , NULL , 0 ) ;
if ( ! strncmp ( V_173 , L_54 , 3 ) )
V_15 = V_177 ;
else if ( ! strncmp ( V_173 , L_55 , 3 ) )
V_10 = V_177 ;
else if ( ! strncmp ( V_173 , L_56 , 3 ) )
V_10 = V_177 ;
else if ( ! strncmp ( V_173 , L_57 , 3 ) )
V_8 = V_177 ;
else if ( ! strncmp ( V_173 , L_58 , 3 ) )
V_179 = V_177 ;
else if ( ! strncmp ( V_173 , L_59 , 3 ) )
V_154 = V_177 ;
else if ( ! strncmp ( V_173 , L_60 , 3 ) )
V_153 = V_177 ;
else if ( ! strncmp ( V_173 , L_61 , 3 ) )
V_155 = V_177 ;
else if ( ! strncmp ( V_173 , L_62 , 3 ) )
V_156 = V_177 ;
else if ( ! strncmp ( V_173 , L_63 , 3 ) )
V_157 = V_177 ;
if ( ( V_173 = strchr ( V_173 , ',' ) ) )
++ V_173 ;
}
return;
}
static int F_52 ( char * V_170 )
{
int V_171 [ V_175 ] ;
char * V_173 = V_170 ;
int V_53 = 1 ;
while ( V_173 && isdigit ( * V_173 ) && V_53 < V_175 ) {
V_171 [ V_53 ++ ] = F_51 ( V_173 , NULL , 0 ) ;
if ( ( V_173 = strchr ( V_173 , ',' ) ) != NULL )
V_173 ++ ;
}
V_171 [ 0 ] = V_53 - 1 ;
F_50 ( V_173 , V_171 ) ;
return 1 ;
}
static void F_53 ( void )
{
#if F_15 ( V_39 )
unsigned int V_22 , V_180 ;
struct V_37 * V_2 = NULL ;
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
if ( ! ( V_2 = F_16 ( V_40 << 8 , V_2 ) ) )
break;
if ( F_21 ( V_2 ) ) {
#if F_15 ( V_41 )
F_18
( L_64 ,
V_42 , V_2 -> V_43 -> V_44 , V_2 -> V_45 ) ;
#endif
continue;
}
V_22 = F_17 ( V_2 , 0 ) ;
#if F_15 ( V_41 )
F_18 ( L_65 ,
V_42 , V_180 , V_2 -> V_43 -> V_44 , V_2 -> V_45 , V_22 ) ;
#endif
V_113 [ V_175 + ( V_153 ? ( V_181 - V_180 ) : ( 1 + V_180 ) ) ] =
V_22 + V_46 ;
}
F_19 ( V_2 ) ;
#endif
}
static int F_54 ( struct V_48 * V_49 )
{
unsigned int V_47 = 0 , V_180 ;
V_49 -> V_182 = L_66 ;
if ( strlen ( V_183 ) )
F_52 ( V_183 ) ;
#if F_15 ( V_184 )
if ( V_113 [ 0 ] != V_185 ) {
V_176 = 1 ;
V_113 [ V_175 ] = 0 ;
}
#endif
for ( V_180 = V_175 ; V_113 [ V_180 ] ; V_180 ++ )
if ( V_113 [ V_180 ] == V_185 )
continue;
else if ( V_113 [ V_180 ] <= V_91 ) {
if ( ! V_155 )
V_113 [ V_180 ] = V_185 ;
} else if ( V_113 [ V_180 ] >= V_88
&& V_113 [ V_180 ] <= V_86 ) {
if ( ! V_156 )
V_113 [ V_180 ] = V_185 ;
}
if ( V_157 ) {
if ( ! V_176 )
F_53 () ;
else
F_20 () ;
}
for ( V_180 = 0 ; V_113 [ V_180 ] ; V_180 ++ ) {
if ( V_113 [ V_180 ] == V_185 )
continue;
if ( V_47 < V_186 && F_22 ( V_113 [ V_180 ] , V_47 , V_49 ) )
V_47 ++ ;
}
V_187 = V_47 ;
return V_47 ;
}
static void F_55 ( unsigned int V_53 , struct V_64 * V_65 )
{
unsigned int V_180 , V_188 ;
int V_189 ;
struct V_190 * V_191 ;
struct V_139 * V_192 ;
struct V_193 * V_194 ;
V_192 = & V_65 -> V_137 [ V_53 ] ;
V_194 = V_192 -> V_194 ;
V_188 = V_194 -> V_195 ;
if ( V_194 -> V_196 )
V_192 -> V_197 =
F_9 ( F_40 ( V_65 -> V_60 , V_194 -> V_196 ,
V_198 , V_199 ) ) ;
V_192 -> V_200 = V_198 ;
if ( ! F_56 ( V_194 ) ) {
V_192 -> V_74 = 0 ;
return;
}
V_189 = F_57 ( V_65 -> V_60 , F_58 ( V_194 ) , F_56 ( V_194 ) ,
V_188 ) ;
F_59 ( ! V_189 ) ;
F_60 (SCpnt, sg, count, k) {
V_192 -> V_146 [ V_180 ] . V_201 = F_9 ( F_61 ( V_191 ) ) ;
V_192 -> V_146 [ V_180 ] . V_202 = F_9 ( F_62 ( V_191 ) ) ;
}
V_192 -> V_191 = 1 ;
V_192 -> V_203 = F_9 ( F_40 ( V_65 -> V_60 , V_192 -> V_146 ,
F_56 ( V_194 ) *
sizeof( struct V_142 ) ,
V_188 ) ) ;
V_192 -> V_74 = F_9 ( ( F_56 ( V_194 ) * sizeof( struct V_142 ) ) ) ;
}
static void F_63 ( unsigned int V_53 , struct V_64 * V_65 )
{
unsigned int V_188 ;
struct V_139 * V_192 ;
struct V_193 * V_194 ;
V_192 = & V_65 -> V_137 [ V_53 ] ;
V_194 = V_192 -> V_194 ;
V_188 = V_194 -> V_195 ;
if ( F_25 ( V_192 -> V_197 ) )
F_64 ( V_65 -> V_60 , F_25 ( V_192 -> V_197 ) ,
F_25 ( V_192 -> V_200 ) , V_199 ) ;
if ( F_56 ( V_194 ) )
F_65 ( V_65 -> V_60 , F_58 ( V_194 ) , F_56 ( V_194 ) ,
V_188 ) ;
if ( ! F_25 ( V_192 -> V_74 ) )
V_188 = V_140 ;
if ( F_25 ( V_192 -> V_203 ) )
F_64 ( V_65 -> V_60 , F_25 ( V_192 -> V_203 ) ,
F_25 ( V_192 -> V_74 ) , V_188 ) ;
}
static void F_66 ( unsigned int V_53 , struct V_64 * V_65 )
{
unsigned int V_188 ;
struct V_139 * V_192 ;
struct V_193 * V_194 ;
V_192 = & V_65 -> V_137 [ V_53 ] ;
V_194 = V_192 -> V_194 ;
V_188 = V_194 -> V_195 ;
if ( F_25 ( V_192 -> V_197 ) )
F_67 ( V_65 -> V_60 , F_25 ( V_192 -> V_197 ) ,
F_25 ( V_192 -> V_200 ) ,
V_199 ) ;
if ( F_56 ( V_194 ) )
F_68 ( V_65 -> V_60 , F_58 ( V_194 ) ,
F_56 ( V_194 ) , V_188 ) ;
if ( ! F_25 ( V_192 -> V_74 ) )
V_188 = V_140 ;
if ( F_25 ( V_192 -> V_203 ) )
F_67 ( V_65 -> V_60 ,
F_25 ( V_192 -> V_203 ) ,
F_25 ( V_192 -> V_74 ) , V_188 ) ;
}
static void F_69 ( unsigned int V_53 , struct V_64 * V_65 )
{
unsigned int V_180 ;
static const unsigned char V_204 [] = {
0x0a , 0x2a , 0x15 , 0x55 , 0x04 , 0x07 , 0x18 , 0x1d , 0x24 , 0x2e ,
0x30 , 0x31 , 0x32 , 0x38 , 0x39 , 0x3a , 0x3b , 0x3d , 0x3f , 0x40 ,
0x41 , 0x4c , 0xaa , 0xae , 0xb0 , 0xb1 , 0xb2 , 0xb6 , 0xea , 0x1b , 0x5d
} ;
static const unsigned char V_205 [] = {
0x01 , 0x0b , 0x10 , 0x11 , 0x13 , 0x16 , 0x17 , 0x19 , 0x2b , 0x1e ,
0x2c , 0xac , 0x2f , 0xaf , 0x33 , 0xb3 , 0x35 , 0x36 , 0x45 , 0x47 ,
0x48 , 0x49 , 0xa9 , 0x4b , 0xa5 , 0xa6 , 0xb5 , 0x00
} ;
struct V_139 * V_192 ;
struct V_193 * V_194 ;
V_192 = & V_65 -> V_137 [ V_53 ] ;
V_194 = V_192 -> V_194 ;
if ( V_194 -> V_195 == V_206 ) {
V_192 -> V_207 = 1 ;
V_192 -> V_208 = 0 ;
return;
} else if ( V_194 -> V_195 == V_209 ) {
V_192 -> V_207 = 0 ;
V_192 -> V_208 = 1 ;
return;
} else if ( V_194 -> V_195 == V_210 ) {
V_192 -> V_207 = 0 ;
V_192 -> V_208 = 0 ;
return;
}
if ( V_194 -> V_195 != V_211 )
F_70 ( L_67 ,
V_65 -> V_125 ) ;
for ( V_180 = 0 ; V_180 < F_71 ( V_204 ) ; V_180 ++ )
if ( V_194 -> V_212 [ 0 ] == V_204 [ V_180 ] ) {
V_192 -> V_208 = 1 ;
break;
}
if ( ( V_192 -> V_207 = ! V_192 -> V_208 ) )
for ( V_180 = 0 ; V_180 < F_71 ( V_205 ) ; V_180 ++ )
if ( V_194 -> V_212 [ 0 ] == V_205 [ V_180 ] ) {
V_192 -> V_207 = 0 ;
break;
}
}
static int F_72 ( struct V_193 * V_194 ,
void (* F_73) ( struct V_193 * ) )
{
struct V_62 * V_63 = V_194 -> V_213 -> V_214 ;
struct V_64 * V_65 = (struct V_64 * ) V_63 -> V_64 ;
unsigned int V_53 , V_180 ;
struct V_139 * V_192 ;
if ( V_194 -> V_215 )
F_70 ( L_68 ,
V_65 -> V_125 , V_194 ) ;
V_53 = V_65 -> V_216 + 1 ;
for ( V_180 = 0 ; V_180 < V_63 -> V_119 ; V_180 ++ , V_53 ++ ) {
if ( V_53 >= V_63 -> V_119 )
V_53 = 0 ;
if ( V_65 -> V_217 [ V_53 ] == FREE ) {
V_65 -> V_216 = V_53 ;
break;
}
}
if ( V_180 == V_63 -> V_119 ) {
F_18 ( L_69 , V_65 -> V_125 ) ;
return 1 ;
}
V_192 = & V_65 -> V_137 [ V_53 ] ;
memset ( V_192 , 0 , sizeof( struct V_139 ) - V_218 ) ;
V_192 -> V_150 = F_9 ( V_65 -> V_150 ) ;
V_194 -> V_219 = F_73 ;
V_192 -> V_220 = V_53 ;
V_194 -> V_215 = ( unsigned char * ) & V_192 -> V_220 ;
if ( V_221 )
F_74 ( V_17 , V_194 ,
L_70 , V_53 ) ;
V_192 -> V_222 = 1 ;
V_192 -> V_223 = 1 ;
#if 0
if (SCpnt->device->type == TYPE_TAPE)
cpp->hbaci = 1;
#endif
V_192 -> V_224 = 1 ;
V_192 -> V_225 = V_194 -> V_213 -> V_225 ;
V_192 -> V_226 = V_194 -> V_213 -> V_227 ;
V_192 -> V_228 = V_194 -> V_213 -> V_228 ;
V_192 -> V_194 = V_194 ;
memcpy ( V_192 -> V_229 , V_194 -> V_212 , V_194 -> V_230 ) ;
F_69 ( V_53 , V_65 ) ;
F_55 ( V_53 , V_65 ) ;
if ( V_15 && V_194 -> V_213 -> V_16 > 2
&& F_2 ( V_194 -> V_213 -> type ) ) {
V_65 -> V_217 [ V_53 ] = V_231 ;
F_75 ( V_194 -> V_213 , F_76 ( V_194 -> V_232 ) , V_65 , 0 ) ;
return 0 ;
}
if ( F_8 ( V_63 -> V_113 , V_192 -> V_138 , V_233 ) ) {
F_63 ( V_53 , V_65 ) ;
V_194 -> V_215 = NULL ;
F_74 ( V_17 , V_194 , L_71 ) ;
return 1 ;
}
V_65 -> V_217 [ V_53 ] = V_234 ;
return 0 ;
}
int F_77 ( struct V_193 * V_235 )
{
unsigned int V_53 , time , V_180 , V_178 , V_236 = 0 ;
int V_237 = 0 ;
struct V_193 * V_194 ;
struct V_62 * V_63 = V_235 -> V_213 -> V_214 ;
struct V_64 * V_65 = (struct V_64 * ) V_63 -> V_64 ;
F_74 ( V_17 , V_235 , L_72 ) ;
F_24 ( V_63 -> V_238 ) ;
if ( V_235 -> V_215 == NULL )
F_18 ( L_73 , V_65 -> V_125 ) ;
if ( V_65 -> V_239 ) {
F_18 ( L_74 , V_65 -> V_125 ) ;
F_32 ( V_63 -> V_238 ) ;
return V_240 ;
}
if ( F_5 ( V_63 -> V_113 , V_26 ) ) {
F_18 ( L_75 , V_65 -> V_125 ) ;
F_32 ( V_63 -> V_238 ) ;
return V_240 ;
}
V_65 -> V_241 = 0 ;
for ( V_178 = 0 ; V_178 <= V_63 -> V_130 ; V_178 ++ )
for ( V_180 = 0 ; V_180 < V_63 -> V_131 ; V_180 ++ ) {
V_65 -> V_242 [ V_180 ] [ V_178 ] = 1 ;
V_65 -> V_243 [ V_180 ] [ V_178 ] = 0 ;
}
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ ) {
if ( V_65 -> V_217 [ V_53 ] == FREE )
continue;
if ( V_65 -> V_217 [ V_53 ] == V_244 ) {
V_65 -> V_217 [ V_53 ] = FREE ;
F_18 ( L_76 ,
V_65 -> V_125 , V_53 ) ;
continue;
}
if ( ! ( V_194 = V_65 -> V_137 [ V_53 ] . V_194 ) )
F_70 ( L_77 , V_65 -> V_125 , V_53 ) ;
if ( V_65 -> V_217 [ V_53 ] == V_231 || V_65 -> V_217 [ V_53 ] == V_245 ) {
V_65 -> V_217 [ V_53 ] = V_245 ;
F_18 ( L_78 ,
V_65 -> V_125 , V_53 ) ;
}
else {
V_65 -> V_217 [ V_53 ] = V_246 ;
F_18 ( L_79 ,
V_65 -> V_125 , V_53 ) ;
}
if ( V_194 -> V_215 == NULL )
F_70 ( L_80 , V_65 -> V_125 , V_53 ) ;
if ( * ( unsigned int * ) V_194 -> V_215 != V_53 )
F_70 ( L_81 , V_65 -> V_125 , V_53 ) ;
if ( V_194 -> V_219 == NULL )
F_70 ( L_82 ,
V_65 -> V_125 , V_53 ) ;
if ( V_194 == V_235 )
V_237 = 1 ;
}
if ( F_8 ( V_63 -> V_113 , 0 , V_247 ) ) {
F_18 ( L_83 , V_65 -> V_125 ) ;
F_32 ( V_63 -> V_238 ) ;
return V_240 ;
}
F_18 ( L_84 , V_65 -> V_125 ) ;
#if F_15 ( V_248 )
V_221 = 1 ;
#endif
V_65 -> V_239 = 1 ;
F_32 ( V_63 -> V_238 ) ;
time = V_249 ;
while ( ( V_249 - time ) < ( 10 * V_250 ) && V_236 ++ < 200000 )
F_7 ( 100L ) ;
F_24 ( V_63 -> V_238 ) ;
F_18 ( L_85 , V_65 -> V_125 , V_236 ) ;
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ ) {
if ( V_65 -> V_217 [ V_53 ] == V_246 ) {
V_194 = V_65 -> V_137 [ V_53 ] . V_194 ;
F_63 ( V_53 , V_65 ) ;
V_194 -> V_251 = V_252 << 16 ;
V_194 -> V_215 = NULL ;
V_65 -> V_217 [ V_53 ] = V_244 ;
F_18
( L_86 ,
V_65 -> V_125 , V_53 ) ;
}
else if ( V_65 -> V_217 [ V_53 ] == V_245 ) {
V_194 = V_65 -> V_137 [ V_53 ] . V_194 ;
F_63 ( V_53 , V_65 ) ;
V_194 -> V_251 = V_252 << 16 ;
V_194 -> V_215 = NULL ;
V_65 -> V_217 [ V_53 ] = FREE ;
F_18
( L_87 ,
V_65 -> V_125 , V_53 ) ;
}
else
continue;
V_194 -> V_219 ( V_194 ) ;
}
V_65 -> V_239 = 0 ;
V_221 = 0 ;
if ( V_237 )
F_18 ( L_88 , V_65 -> V_125 ) ;
else
F_18 ( L_89 , V_65 -> V_125 ) ;
F_32 ( V_63 -> V_238 ) ;
return V_253 ;
}
int F_78 ( struct V_1 * V_254 , struct V_255 * V_256 ,
T_6 V_257 , int * V_258 )
{
unsigned int V_259 = V_257 ;
if ( V_154 || ( F_79 ( V_256 , V_257 , V_258 ) < 0 ) ) {
V_258 [ 0 ] = 255 ;
V_258 [ 1 ] = 63 ;
V_258 [ 2 ] = V_259 / ( V_258 [ 0 ] * V_258 [ 1 ] ) ;
}
#if F_15 ( V_260 )
F_18 ( L_90 , V_42 ,
V_258 [ 0 ] , V_258 [ 1 ] , V_258 [ 2 ] ) ;
#endif
return 0 ;
}
static void F_80 ( unsigned long V_261 [] , unsigned int V_262 [] , unsigned int V_263 ,
unsigned int V_264 )
{
unsigned int V_53 , V_47 , V_180 , V_265 ;
unsigned long V_266 ;
for ( V_53 = 0 ; V_53 < V_263 - 1 ; V_53 ++ ) {
V_180 = V_53 ;
for ( V_47 = V_180 + 1 ; V_47 < V_263 ; V_47 ++ )
if ( V_264 ) {
if ( V_261 [ V_47 ] > V_261 [ V_180 ] )
V_180 = V_47 ;
} else {
if ( V_261 [ V_47 ] < V_261 [ V_180 ] )
V_180 = V_47 ;
}
if ( V_180 != V_53 ) {
V_266 = V_261 [ V_180 ] ;
V_261 [ V_180 ] = V_261 [ V_53 ] ;
V_261 [ V_53 ] = V_266 ;
V_265 = V_262 [ V_180 ] ;
V_262 [ V_180 ] = V_262 [ V_53 ] ;
V_262 [ V_53 ] = V_265 ;
}
}
return;
}
static int F_81 ( struct V_64 * V_65 , unsigned long V_267 ,
unsigned int V_268 , unsigned int V_269 [] , unsigned int V_270 )
{
struct V_193 * V_194 ;
struct V_139 * V_192 ;
unsigned int V_180 , V_263 ;
unsigned int V_264 = 0 , V_271 = 1 , V_272 = 1 ;
unsigned int V_273 = 1 , V_274 = 0 ;
unsigned long V_275 [ V_270 ] , V_276 [ V_270 ] , V_277 [ V_270 ] ;
unsigned long V_278 = 0 , V_279 = V_280 , V_281 = 0 , V_282 = 0 ;
unsigned long V_283 = 0 ;
static unsigned int V_284 = 0 , V_285 = 0 , V_286 = 0 ;
static unsigned int V_287 = 0 , V_288 = 0 , V_289 = 0 ;
static unsigned int V_290 = 0 , V_291 = 0 ;
static unsigned long V_292 = 0 , V_293 = 0 ;
if ( V_179 && ! ( ++ V_284 % V_179 ) )
F_18 ( L_91
L_92 , V_284 , V_285 ,
V_289 , V_288 , V_287 , V_290 , V_286 ,
V_291 , V_293 / ( V_287 + 1 ) ,
V_292 / ( V_287 + 1 ) ) ;
if ( V_270 <= 1 )
return 0 ;
for ( V_263 = 0 ; V_263 < V_270 ; V_263 ++ ) {
V_180 = V_269 [ V_263 ] ;
V_192 = & V_65 -> V_137 [ V_180 ] ;
V_194 = V_192 -> V_194 ;
if ( ! V_192 -> V_207 )
V_273 = 0 ;
if ( F_76 ( V_194 -> V_232 ) < V_279 )
V_279 = F_76 ( V_194 -> V_232 ) ;
if ( F_76 ( V_194 -> V_232 ) > V_278 )
V_278 = F_76 ( V_194 -> V_232 ) ;
V_275 [ V_263 ] = F_76 ( V_194 -> V_232 ) ;
V_283 += F_82 ( V_194 -> V_232 ) ;
if ( ! V_263 )
continue;
if ( V_275 [ V_263 ] < V_275 [ V_263 - 1 ] )
V_271 = 0 ;
if ( V_275 [ V_263 ] > V_275 [ V_263 - 1 ] )
V_272 = 0 ;
if ( V_179 ) {
if ( V_275 [ V_263 ] > V_275 [ V_263 - 1 ] )
V_281 += V_275 [ V_263 ] - V_275 [ V_263 - 1 ] ;
else
V_281 += V_275 [ V_263 - 1 ] - V_275 [ V_263 ] ;
}
}
if ( V_179 ) {
if ( V_267 > V_275 [ 0 ] )
V_281 += V_267 - V_275 [ 0 ] ;
else
V_281 += V_275 [ 0 ] - V_267 ;
}
if ( V_267 > ( ( V_278 + V_279 ) / 2 ) )
V_264 = 1 ;
if ( V_283 > ( ( V_278 - V_279 ) / 2 ) )
V_264 = 0 ;
if ( ! ( ( V_264 && V_272 ) || ( ! V_264 && V_271 ) ) )
F_80 ( V_275 , V_269 , V_270 , V_264 ) ;
if ( ! V_273 )
for ( V_263 = 0 ; V_263 < V_270 ; V_263 ++ ) {
V_180 = V_269 [ V_263 ] ;
V_192 = & V_65 -> V_137 [ V_180 ] ;
V_194 = V_192 -> V_194 ;
V_277 [ V_263 ] = F_82 ( V_194 -> V_232 ) ;
V_276 [ V_263 ] = V_194 -> V_294 ;
if ( ! V_263 )
continue;
if ( ( V_275 [ V_263 ] == V_275 [ V_263 - 1 ] )
|| ( ! V_264 && ( ( V_275 [ V_263 - 1 ] + V_277 [ V_263 - 1 ] ) > V_275 [ V_263 ] ) )
|| ( V_264 && ( ( V_275 [ V_263 ] + V_277 [ V_263 ] ) > V_275 [ V_263 - 1 ] ) ) )
V_274 = 1 ;
}
if ( V_274 )
F_80 ( V_276 , V_269 , V_270 , 0 ) ;
if ( V_179 ) {
if ( V_267 > V_275 [ 0 ] )
V_282 = V_267 - V_275 [ 0 ] ;
else
V_282 = V_275 [ 0 ] - V_267 ;
V_285 ++ ;
V_287 += V_270 ;
V_293 += V_281 / 1024 ;
if ( V_273 )
V_289 ++ ;
if ( V_274 ) {
V_288 ++ ;
V_292 += V_282 / 1024 ;
} else
V_292 += ( V_282 + V_278 - V_279 ) / 1024 ;
if ( V_264 && ! V_272 ) {
V_291 ++ ;
V_290 += V_270 ;
}
if ( ! V_264 && ! V_271 ) {
V_286 ++ ;
V_290 += V_270 ;
}
}
#if F_15 ( V_295 )
if ( V_179 && ( V_274 || ! ( V_284 % V_179 ) ) )
for ( V_263 = 0 ; V_263 < V_270 ; V_263 ++ ) {
V_180 = V_269 [ V_263 ] ;
V_192 = & V_65 -> V_137 [ V_180 ] ;
V_194 = V_192 -> V_194 ;
F_74 ( V_17 , V_194 ,
L_93
L_94 ,
( V_268 ? L_95 : L_96 ) ,
V_180 , V_284 ,
V_270 , F_76 ( V_194 -> V_232 ) ,
F_82 ( V_194 -> V_232 ) , V_267 , F_42 ( V_271 ) ,
F_42 ( V_272 ) , F_42 ( V_264 ) , F_42 ( V_273 ) ,
F_42 ( V_274 ) , V_192 -> V_207 ) ;
}
#endif
return V_274 ;
}
static void F_75 ( struct V_1 * V_2 , unsigned long V_267 ,
struct V_64 * V_65 , unsigned int V_268 )
{
struct V_193 * V_194 ;
struct V_139 * V_192 ;
unsigned int V_180 , V_263 , V_270 = 0 , V_269 [ V_127 ] ;
for ( V_180 = 0 ; V_180 < V_2 -> V_214 -> V_119 ; V_180 ++ ) {
if ( V_65 -> V_217 [ V_180 ] != V_231 && V_65 -> V_217 [ V_180 ] != V_234 )
continue;
V_192 = & V_65 -> V_137 [ V_180 ] ;
V_194 = V_192 -> V_194 ;
if ( V_194 -> V_213 != V_2 )
continue;
if ( V_65 -> V_217 [ V_180 ] == V_234 )
return;
V_269 [ V_270 ++ ] = V_180 ;
}
if ( F_81 ( V_65 , V_267 , V_268 , V_269 , V_270 ) )
V_270 = 1 ;
for ( V_263 = 0 ; V_263 < V_270 ; V_263 ++ ) {
V_180 = V_269 [ V_263 ] ;
V_192 = & V_65 -> V_137 [ V_180 ] ;
V_194 = V_192 -> V_194 ;
if ( F_8 ( V_2 -> V_214 -> V_113 , V_192 -> V_138 , V_233 ) ) {
F_74 ( V_17 , V_194 ,
L_97
L_98 ,
( V_268 ? L_95 : L_96 ) ,
V_180 ) ;
V_65 -> V_217 [ V_180 ] = V_245 ;
continue;
}
V_65 -> V_217 [ V_180 ] = V_234 ;
}
}
static T_7 V_268 ( struct V_62 * V_63 )
{
struct V_193 * V_194 ;
unsigned int V_53 , V_180 , V_178 , V_296 , V_297 , V_298 ;
struct V_149 * V_299 ;
struct V_139 * V_192 ;
struct V_64 * V_65 = (struct V_64 * ) V_63 -> V_64 ;
int V_50 = V_63 -> V_50 ;
if ( ! ( F_6 ( V_63 -> V_113 + V_20 ) & V_300 ) )
goto V_301;
V_65 -> V_302 ++ ;
if ( V_221 )
F_18 ( L_99 , V_65 -> V_125 , V_50 ,
V_65 -> V_302 ) ;
if ( F_5 ( V_63 -> V_113 , 20 * V_26 ) ) {
V_298 = F_6 ( V_63 -> V_113 + V_35 ) ;
F_18
( L_100 ,
V_65 -> V_125 , V_50 , V_298 , V_65 -> V_302 ) ;
goto V_301;
}
V_299 = & V_65 -> V_303 ;
memcpy ( V_299 , V_65 -> V_148 , sizeof( struct V_149 ) ) ;
memset ( V_65 -> V_148 , 0 , sizeof( struct V_149 ) ) ;
V_298 = F_6 ( V_63 -> V_113 + V_35 ) ;
#if F_15 ( V_304 )
{
unsigned char * V_305 ;
int V_306 ;
V_305 = ( unsigned char * ) V_299 ;
if ( V_65 -> V_302 < 200 ) {
F_18 ( L_101 ) ;
for ( V_306 = 0 ; V_306 < 15 ; V_306 ++ )
F_18 ( L_102 , V_305 [ V_306 ] ) ;
F_18 ( L_103 ) ;
}
}
#endif
if ( V_299 -> V_307 == 0 && V_65 -> V_302 > 1 )
F_18
( L_104 ,
V_65 -> V_125 , V_50 , V_298 , V_65 -> V_302 ) ;
if ( V_299 -> V_220 < 0 || V_299 -> V_220 >= V_63 -> V_119 )
F_18
( L_105 ,
V_65 -> V_125 , V_299 -> V_220 , V_50 , V_298 , V_65 -> V_302 ) ;
if ( V_299 -> V_307 == 0 || V_299 -> V_220 < 0
|| V_299 -> V_220 >= V_63 -> V_119 )
goto V_308;
V_53 = V_299 -> V_220 ;
V_192 = & ( V_65 -> V_137 [ V_53 ] ) ;
#if F_15 ( V_309 )
if ( ( V_65 -> V_302 > 500 ) && ( ( V_65 -> V_302 % 500 ) < 3 ) )
goto V_308;
#endif
if ( V_65 -> V_217 [ V_53 ] == V_310 ) {
V_65 -> V_217 [ V_53 ] = FREE ;
goto V_308;
} else if ( V_65 -> V_217 [ V_53 ] == V_244 ) {
V_65 -> V_217 [ V_53 ] = FREE ;
F_18 ( L_106 , V_65 -> V_125 , V_53 ,
V_65 -> V_302 ) ;
goto V_308;
} else if ( V_65 -> V_217 [ V_53 ] == FREE ) {
F_18 ( L_107 , V_65 -> V_125 , V_53 ,
V_65 -> V_302 ) ;
goto V_308;
} else if ( V_65 -> V_217 [ V_53 ] == V_246 )
F_18 ( L_108 , V_65 -> V_125 , V_53 ) ;
else if ( V_65 -> V_217 [ V_53 ] != V_234 )
F_70 ( L_109 ,
V_65 -> V_125 , V_53 , V_65 -> V_217 [ V_53 ] ) ;
V_65 -> V_217 [ V_53 ] = FREE ;
V_194 = V_192 -> V_194 ;
if ( V_194 == NULL )
F_70 ( L_110 , V_65 -> V_125 , V_53 ) ;
if ( V_194 -> V_215 == NULL )
F_70 ( L_111 , V_65 -> V_125 ,
V_53 , V_194 ) ;
if ( * ( unsigned int * ) V_194 -> V_215 != V_53 )
F_70 ( L_112 ,
V_65 -> V_125 , V_53 ,
* ( unsigned int * ) V_194 -> V_215 ) ;
F_66 ( V_53 , V_65 ) ;
if ( V_15 && V_194 -> V_213 -> V_16 > 2
&& F_2 ( V_194 -> V_213 -> type ) )
F_75 ( V_194 -> V_213 , F_76 ( V_194 -> V_232 ) , V_65 , 1 ) ;
V_297 = F_83 ( V_299 -> V_311 ) ;
#if F_15 ( V_312 )
if ( ( V_65 -> V_302 > 500 ) && ( ( V_65 -> V_302 % 200 ) < 2 ) )
V_299 -> V_313 = 0x01 ;
#endif
switch ( V_299 -> V_313 ) {
case V_314 :
if ( V_297 == V_315 && V_194 -> V_213 -> type != V_316 )
V_296 = V_317 << 16 ;
else if ( V_297 != V_318 && V_194 -> V_213 -> type == V_319
&& V_65 -> V_242 [ V_194 -> V_213 -> V_227 ] [ V_194 ->
V_213 ->
V_225 ] )
V_296 = V_320 << 16 ;
else if ( V_297 == V_321
&& V_194 -> V_213 -> type == V_319
&& ( V_194 -> V_196 [ 2 ] & 0xf ) == V_322 )
V_296 = V_320 << 16 ;
else
V_296 = V_323 << 16 ;
if ( V_297 == V_318 )
V_65 -> V_242 [ V_194 -> V_213 -> V_227 ] [ V_194 -> V_213 ->
V_225 ] = 0 ;
if ( V_299 -> V_311 && V_194 -> V_213 -> type == V_319 &&
( ! ( V_297 == V_321 && V_65 -> V_302 <= 1000 &&
( V_194 -> V_196 [ 2 ] & 0xf ) == V_324 ) ) )
F_18 ( L_113
L_114 ,
V_65 -> V_125 ,
V_194 -> V_213 -> V_225 , V_194 -> V_213 -> V_227 ,
V_194 -> V_213 -> V_228 ,
V_299 -> V_311 , V_194 -> V_196 [ 2 ] ) ;
V_65 -> V_243 [ V_194 -> V_213 -> V_227 ] [ V_194 -> V_213 -> V_225 ] = 0 ;
if ( V_65 -> V_325 == V_194 -> V_294 )
V_65 -> V_241 = 0 ;
break;
case V_326 :
case 0x02 :
if ( V_65 -> V_243 [ V_194 -> V_213 -> V_227 ] [ V_194 -> V_213 -> V_225 ] > 1 )
V_296 = V_317 << 16 ;
else {
V_296 = V_327 << 16 ;
V_65 -> V_243 [ V_194 -> V_213 -> V_227 ] [ V_194 -> V_213 ->
V_225 ] ++ ;
}
break;
case 0x03 :
case 0x04 :
for ( V_178 = 0 ; V_178 <= V_63 -> V_130 ; V_178 ++ )
for ( V_180 = 0 ; V_180 < V_63 -> V_131 ; V_180 ++ )
V_65 -> V_242 [ V_180 ] [ V_178 ] = 1 ;
if ( V_194 -> V_213 -> type != V_316
&& V_65 -> V_241 < V_328 ) {
#if F_15 ( V_329 )
V_296 = V_329 << 16 ;
#else
V_296 = V_320 << 16 ;
#endif
V_65 -> V_241 ++ ;
V_65 -> V_325 = V_194 -> V_294 ;
} else
V_296 = V_317 << 16 ;
break;
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x0a :
case 0x0b :
case 0x0c :
default:
V_296 = V_317 << 16 ;
break;
}
V_194 -> V_251 = V_296 | V_299 -> V_311 ;
#if F_15 ( V_304 )
if ( V_194 -> V_251 || V_221 )
#else
if ( ( V_299 -> V_313 != V_314 && V_65 -> V_302 > 1000 ) ||
( V_299 -> V_313 != V_314 &&
V_299 -> V_313 != V_326 && V_65 -> V_302 <= 1000 ) ||
V_221 || F_84 ( V_299 -> V_311 ) )
#endif
F_74 ( V_17 , V_194 , L_115
L_116 ,
V_53 , V_299 -> V_313 , V_299 -> V_311 ,
V_298 , V_65 -> V_302 ) ;
F_63 ( V_53 , V_65 ) ;
V_194 -> V_215 = NULL ;
V_194 -> V_219 ( V_194 ) ;
if ( V_221 )
F_18 ( L_117 , V_65 -> V_125 ,
V_50 , V_65 -> V_302 ) ;
V_308:
return V_330 ;
V_301:
return V_331 ;
}
static T_7 V_99 ( int V_332 , void * V_333 )
{
struct V_62 * V_63 ;
unsigned int V_47 ;
unsigned long V_334 ;
T_7 V_335 ;
if ( ( V_47 = ( unsigned int ) ( ( char * ) V_333 - V_102 ) ) >= V_187 )
return V_331 ;
V_63 = V_112 [ V_47 ] ;
F_85 ( V_63 -> V_238 , V_334 ) ;
V_335 = V_268 ( V_63 ) ;
F_86 ( V_63 -> V_238 , V_334 ) ;
return V_335 ;
}
static int F_49 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = (struct V_64 * ) V_63 -> V_64 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ )
F_87 ( ( & V_65 -> V_137 [ V_53 ] ) -> V_146 ) ;
for ( V_53 = 0 ; V_53 < V_63 -> V_119 ; V_53 ++ )
F_64 ( V_65 -> V_60 , V_65 -> V_137 [ V_53 ] . V_138 ,
sizeof( struct V_139 ) , V_140 ) ;
if ( V_65 -> V_148 )
F_31 ( V_65 -> V_60 , sizeof( struct V_149 ) ,
V_65 -> V_148 , V_65 -> V_150 ) ;
F_47 ( V_63 -> V_50 , & V_102 [ V_65 -> V_121 ] ) ;
if ( V_63 -> V_51 != V_96 )
F_46 ( V_63 -> V_51 ) ;
F_48 ( V_63 -> V_113 , V_63 -> V_115 ) ;
F_88 ( V_63 ) ;
return 0 ;
}
