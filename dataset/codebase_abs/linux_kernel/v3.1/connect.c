static int
F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 , * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_4 V_13 ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_3 ( & V_14 ) ;
return V_3 ;
} else
V_2 -> V_15 = V_17 ;
F_3 ( & V_14 ) ;
V_2 -> V_18 = 0 ;
F_4 ( 1 , L_1 ) ;
F_4 ( 1 , L_2 , V_19 ) ;
F_2 ( & V_20 ) ;
F_5 (tmp, &server->smb_ses_list) {
V_8 = F_6 ( V_5 , struct V_7 , V_21 ) ;
V_8 -> V_22 = true ;
V_8 -> V_23 = 0 ;
F_5 (tmp2, &ses->tcon_list) {
V_10 = F_6 ( V_6 , struct V_9 , V_24 ) ;
V_10 -> V_22 = true ;
}
}
F_3 ( & V_20 ) ;
F_4 ( 1 , L_3 , V_19 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_26 ) {
F_4 ( 1 , L_4 , V_2 -> V_26 -> V_27 ,
V_2 -> V_26 -> V_28 ) ;
F_8 ( V_2 -> V_26 , V_29 ) ;
F_4 ( 1 , L_5 ,
V_2 -> V_26 -> V_27 ,
V_2 -> V_26 -> V_28 ) ;
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
V_2 -> V_30 = 0 ;
V_2 -> V_31 = false ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_2 -> V_35 = V_36 ;
F_11 ( & V_2 -> V_25 ) ;
F_12 ( & V_13 ) ;
F_4 ( 1 , L_6 , V_19 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
if ( V_12 -> V_38 == V_39 )
V_12 -> V_38 = V_40 ;
F_14 ( & V_12 -> V_37 , & V_13 ) ;
}
F_3 ( & V_14 ) ;
F_4 ( 1 , L_7 , V_19 ) ;
F_13 (tmp, tmp2, &retry_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
do {
F_16 () ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 ) {
F_4 ( 1 , L_8 , V_3 ) ;
F_18 ( 3000 ) ;
} else {
F_19 ( & V_42 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_43 ;
F_3 ( & V_14 ) ;
}
} while ( V_2 -> V_15 == V_17 );
return V_3 ;
}
static int F_20 ( struct V_44 * V_45 , unsigned int V_46 )
{
struct V_47 * V_48 ;
int V_49 ;
T_1 V_50 , V_51 ;
if ( V_45 -> V_52 != V_53 )
return 0 ;
if ( V_45 -> V_54 != 10 ) {
F_4 ( 1 , L_9 ) ;
return - V_55 ;
}
V_48 = (struct V_47 * ) V_45 ;
V_50 = F_21 ( & V_48 -> V_56 . V_57 ) ;
V_51 = F_21 ( & V_48 -> V_56 . V_58 ) ;
if ( V_50 == V_51 )
return 0 ;
else if ( V_50 < V_51 ) {
F_4 ( 1 , L_10 ,
V_50 , V_51 ) ;
return - V_55 ;
}
V_49 = V_50 - V_51 ;
F_4 ( 1 , L_11 ,
V_49 ) ;
if ( V_50 > V_46 ) {
F_22 ( 1 , L_12 ,
V_50 , V_46 ) ;
return - V_55 ;
}
return V_49 ;
}
static int F_23 ( struct V_44 * V_59 , struct V_44 * V_60 )
{
struct V_47 * V_61 = (struct V_47 * ) V_59 ;
struct V_47 * V_48 = (struct V_47 * ) V_60 ;
char * V_62 ;
char * V_63 ;
int V_49 ;
unsigned int V_64 , V_65 ;
T_1 V_50 , V_66 ;
V_50 = F_21 ( & V_48 -> V_56 . V_57 ) ;
if ( V_50 !=
F_21 ( & V_61 -> V_56 . V_57 ) )
F_4 ( 1 , L_13 ) ;
V_65 = F_21 ( & V_48 -> V_56 . V_58 ) ;
V_49 = V_50 - V_65 ;
if ( V_49 < 0 )
return - V_67 ;
if ( V_49 == 0 )
return 0 ;
V_66 = F_21 ( & V_61 -> V_56 . V_58 ) ;
if ( V_49 < V_66 ) {
F_4 ( 1 , L_14 ) ;
}
V_62 = ( char * ) & V_48 -> V_68 . V_69 +
F_21 ( & V_48 -> V_56 . V_70 ) ;
V_63 = ( char * ) & V_61 -> V_68 . V_69 +
F_21 ( & V_61 -> V_56 . V_70 ) ;
V_62 += V_65 ;
V_65 += V_66 ;
if ( V_65 > V_71 )
return - V_67 ;
F_24 ( V_65 , & V_48 -> V_56 . V_58 ) ;
V_64 = F_25 ( V_60 ) ;
V_64 += V_66 ;
if ( V_64 > V_71 )
return - V_67 ;
F_26 ( V_64 , V_60 ) ;
V_64 = F_27 ( V_60 -> V_72 ) ;
V_64 += V_66 ;
if ( V_64 > V_73 )
return - V_74 ;
V_60 -> V_72 = F_28 ( V_64 ) ;
memcpy ( V_62 , V_63 , V_66 ) ;
if ( V_49 == V_66 ) {
F_4 ( 1 , L_15 ) ;
return 0 ;
} else
return 1 ;
}
static void
F_29 ( struct V_75 * V_76 )
{
int V_3 ;
struct V_1 * V_2 = F_30 ( V_76 ,
struct V_1 , V_77 . V_76 ) ;
if ( V_2 -> V_18 == 0 ||
F_31 ( V_36 , V_2 -> V_35 + V_78 - V_79 ) )
goto V_80;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
F_4 ( 1 , L_16 ,
V_2 -> V_81 ) ;
V_80:
F_33 ( V_82 , & V_2 -> V_77 , V_78 ) ;
}
static bool
F_34 ( char * * V_83 , char * * V_84 , unsigned int V_85 ,
bool V_86 )
{
char * V_87 = * V_83 , * V_88 = * V_84 ;
if ( V_87 == NULL ) {
V_87 = ( char * ) F_35 () ;
if ( ! V_87 ) {
F_22 ( 1 , L_17 ) ;
F_18 ( 3000 ) ;
return false ;
}
} else if ( V_86 ) {
memset ( V_87 , 0 , V_85 ) ;
}
if ( V_88 == NULL ) {
V_88 = ( char * ) F_36 () ;
if ( ! V_88 ) {
F_22 ( 1 , L_18 ) ;
F_18 ( 1000 ) ;
return false ;
}
} else {
memset ( V_88 , 0 , V_85 ) ;
}
* V_83 = V_87 ;
* V_84 = V_88 ;
return true ;
}
static int
F_37 ( struct V_1 * V_2 , struct V_89 * V_90 ,
struct V_91 * V_92 , unsigned int V_93 ,
unsigned int * V_94 , bool V_95 )
{
int V_96 , V_3 = 0 ;
unsigned int V_97 ;
char * V_98 = V_92 -> V_99 ;
for ( V_97 = 0 ; V_97 < V_93 ; V_97 += V_96 ) {
V_96 = F_38 ( V_2 -> V_26 , V_90 , V_92 , 1 ,
V_93 - V_97 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_3 = 2 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_3 = 1 ;
break;
} else if ( V_96 == - V_100 ||
V_96 == - V_101 ||
V_96 == - V_102 ) {
F_39 ( 1000 , 2000 ) ;
V_96 = 0 ;
if ( ! V_95 )
continue;
if ( V_97 ) {
V_92 -> V_99 = ( V_93 - V_97 ) +
V_98 ;
V_92 -> V_103 = V_93 - V_97 ;
V_90 -> V_104 = NULL ;
V_90 -> V_105 = 0 ;
V_3 = 3 ;
} else
V_3 = 1 ;
break;
} else if ( V_96 <= 0 ) {
F_22 ( 1 , L_19 ,
V_93 - V_97 ) ;
F_1 ( V_2 ) ;
V_3 = 1 ;
break;
}
}
* V_94 = V_97 ;
return V_3 ;
}
static bool
F_40 ( struct V_1 * V_2 , char * V_98 )
{
char V_106 = * V_98 ;
unsigned int V_107 = F_27 (
( (struct V_44 * ) V_98 ) -> V_72 ) ;
if ( V_106 == ( char ) V_108 ) {
return false ;
} else if ( V_106 == ( char ) V_109 ) {
F_4 ( 1 , L_20 ) ;
return false ;
} else if ( V_106 == ( char ) V_110 ) {
F_4 ( 1 , L_21 ,
V_107 ) ;
F_18 ( 1000 ) ;
F_41 ( (struct V_111 * )
& V_2 -> V_112 , V_113 ) ;
F_1 ( V_2 ) ;
F_42 ( & V_2 -> V_114 ) ;
return false ;
} else if ( V_106 != ( char ) 0 ) {
F_22 ( 1 , L_22 ) ;
F_43 ( L_23 , V_98 , 4 ) ;
F_1 ( V_2 ) ;
return false ;
}
if ( ( V_107 > V_73 + V_115 - 4 ) ||
( V_107 < sizeof( struct V_44 ) - 1 - 4 ) ) {
F_22 ( 1 , L_24 ,
4 , V_107 + 4 ) ;
F_1 ( V_2 ) ;
F_42 ( & V_2 -> V_114 ) ;
return false ;
}
return true ;
}
static struct V_11 *
F_44 ( struct V_1 * V_2 , struct V_44 * V_98 ,
int * V_96 , bool V_86 , bool * V_116 , char * * V_83 )
{
struct V_11 * V_117 = NULL , * V_118 , * V_119 = NULL ;
F_2 ( & V_14 ) ;
F_45 (mid, tmp_mid, &server->pending_mid_q, qhead) {
if ( V_117 -> V_117 != V_98 -> V_120 ||
V_117 -> V_38 != V_39 ||
V_117 -> V_121 != V_98 -> V_52 )
continue;
if ( * V_96 == 0 && F_20 ( V_98 , V_2 -> V_18 ) > 0 ) {
* V_116 = true ;
if ( V_117 -> V_122 ) {
* V_96 = F_23 ( V_98 , V_117 -> V_122 ) ;
if ( * V_96 > 0 ) {
* V_96 = 0 ;
V_117 -> V_123 = true ;
break;
}
V_117 -> V_124 = true ;
goto V_125;
}
if ( ! V_86 ) {
F_22 ( 1 , L_25 ) ;
} else {
V_117 -> V_122 = V_98 ;
V_117 -> V_126 = true ;
* V_83 = NULL ;
}
break;
}
V_117 -> V_122 = V_98 ;
V_117 -> V_126 = V_86 ;
V_125:
if ( * V_96 == 0 )
V_117 -> V_38 = V_127 ;
else
V_117 -> V_38 = V_128 ;
#ifdef F_46
V_117 -> V_129 = V_36 ;
#endif
F_15 ( & V_117 -> V_37 ) ;
V_119 = V_117 ;
break;
}
F_3 ( & V_14 ) ;
return V_119 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_96 ;
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_130 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_48 ( & V_2 -> V_114 ) ;
F_2 ( & V_14 ) ;
if ( F_49 ( & V_2 -> V_131 ) >= V_132 )
F_50 ( & V_2 -> V_131 , V_132 - 1 ) ;
F_3 ( & V_14 ) ;
F_48 ( & V_2 -> V_133 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
if ( ! F_51 ( & V_2 -> V_134 ) ) {
struct V_4 V_135 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_135 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_26 , V_12 -> V_117 ) ;
V_12 -> V_38 = V_136 ;
F_14 ( & V_12 -> V_37 , & V_135 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_27 , V_12 -> V_117 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_51 ( & V_2 -> V_134 ) ) {
F_4 ( 1 , L_28 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_81 ) ;
F_10 ( V_2 ) ;
V_96 = F_52 ( & V_137 ) ;
if ( V_96 > 0 )
F_53 ( V_138 , V_96 + V_139 ,
V_140 ) ;
}
static int
F_54 ( void * V_141 )
{
int V_96 ;
struct V_1 * V_2 = V_141 ;
unsigned int V_107 , V_97 ;
char * V_98 = NULL , * V_83 = NULL , * V_84 = NULL ;
struct V_44 * V_142 = NULL ;
struct V_89 V_90 ;
struct V_91 V_92 ;
struct V_143 * V_144 = NULL ;
struct V_11 * V_12 ;
bool V_145 = false ;
bool V_146 = false ;
int V_3 ;
V_147 -> V_28 |= V_148 ;
F_4 ( 1 , L_29 , F_55 ( V_147 ) ) ;
V_96 = F_56 ( & V_137 ) ;
if ( V_96 > 1 )
F_53 ( V_138 , V_96 + V_139 ,
V_140 ) ;
F_57 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( ! F_34 ( & V_83 , & V_84 ,
sizeof( struct V_44 ) , V_145 ) )
continue;
V_145 = false ;
V_146 = false ;
V_142 = (struct V_44 * ) V_84 ;
V_98 = V_84 ;
V_92 . V_99 = V_98 ;
V_92 . V_103 = 4 ;
V_90 . V_104 = NULL ;
V_90 . V_105 = 0 ;
V_107 = 4 ;
V_149:
if ( V_150 > 0 && V_2 -> V_15 == V_151 &&
F_58 ( V_36 , V_2 -> V_35 +
( V_150 * V_78 ) ) ) {
F_22 ( 1 , L_30
L_31 , V_2 -> V_81 ,
( V_150 * V_78 / V_79 ) ) ;
F_1 ( V_2 ) ;
F_42 ( & V_2 -> V_114 ) ;
continue;
}
V_3 = F_37 ( V_2 , & V_90 , & V_92 , V_107 ,
& V_97 , true ) ;
if ( V_3 == 3 )
goto V_149;
else if ( V_3 == 2 )
break;
else if ( V_3 == 1 )
continue;
V_107 = F_27 ( V_142 -> V_72 ) ;
F_4 ( 1 , L_32 , V_107 + 4 ) ;
if ( ! F_40 ( V_2 , V_98 ) )
continue;
if ( V_107 > V_152 - 4 ) {
V_145 = true ;
memcpy ( V_83 , V_84 , 4 ) ;
V_142 = (struct V_44 * ) V_83 ;
V_98 = V_83 ;
}
V_92 . V_99 = 4 + V_98 ;
V_92 . V_103 = V_107 ;
V_3 = F_37 ( V_2 , & V_90 , & V_92 , V_107 ,
& V_97 , false ) ;
if ( V_3 == 2 )
break;
else if ( V_3 == 1 )
continue;
V_97 += 4 ;
F_59 ( V_142 , V_97 ) ;
V_96 = F_60 ( V_142 , V_142 -> V_120 , V_97 ) ;
if ( V_96 != 0 )
F_43 ( L_33 , V_98 ,
F_61 (unsigned int, total_read, 48 ) ) ;
V_2 -> V_35 = V_36 ;
V_12 = F_44 ( V_2 , V_142 , & V_96 ,
V_145 , & V_146 , & V_83 ) ;
if ( V_12 != NULL ) {
V_12 -> V_41 ( V_12 ) ;
if ( ! V_146 ) {
if ( V_145 )
V_83 = NULL ;
else
V_84 = NULL ;
}
} else if ( V_96 != 0 ) {
continue;
} else if ( ! F_62 ( V_142 , V_2 ) &&
! V_146 ) {
F_22 ( 1 , L_34
L_35 , F_49 ( & V_153 ) ) ;
F_43 ( L_36 , V_98 ,
sizeof( struct V_44 ) ) ;
#ifdef F_63
F_64 ( V_142 ) ;
F_65 ( V_2 ) ;
#endif
}
}
F_66 ( V_83 ) ;
if ( V_84 )
F_67 ( V_84 ) ;
V_144 = F_68 ( & V_2 -> V_154 , NULL ) ;
F_47 ( V_2 ) ;
if ( ! V_144 ) {
F_69 ( V_155 ) ;
while ( ! F_70 ( V_147 ) ) {
F_71 () ;
F_69 ( V_155 ) ;
}
F_69 ( V_156 ) ;
}
F_72 ( 0 ) ;
}
static char *
F_73 ( const char * V_157 )
{
const char * V_158 ;
char * V_159 , * V_160 ;
unsigned int V_34 ;
V_158 = V_157 + 2 ;
V_160 = strchr ( V_158 , '\\' ) ;
if ( ! V_160 )
return F_74 ( - V_55 ) ;
V_34 = V_160 - V_158 ;
V_159 = F_75 ( ( V_34 + 1 ) , V_140 ) ;
if ( V_159 == NULL )
return F_74 ( - V_161 ) ;
memcpy ( V_159 , V_158 , V_34 ) ;
V_159 [ V_34 ] = '\0' ;
return V_159 ;
}
static int
F_76 ( const char * V_162 , const char * V_163 ,
struct V_164 * V_165 )
{
char * V_166 , * V_167 , * V_168 ;
char * V_169 = NULL , * V_170 ;
unsigned int V_171 , V_172 , V_173 ;
char V_174 [ 2 ] ;
short int V_175 = - 1 ;
short int V_176 = - 1 ;
bool V_177 = false ;
bool V_178 = false ;
char * V_179 = F_77 () -> V_179 ;
V_174 [ 0 ] = ',' ;
V_174 [ 1 ] = 0 ;
memset ( V_165 -> V_180 , 0x20 , V_181 ) ;
for ( V_172 = 0 ; V_172 < F_78 ( V_179 , V_181 ) ; V_172 ++ )
V_165 -> V_180 [ V_172 ] = toupper ( V_179 [ V_172 ] ) ;
V_165 -> V_180 [ V_181 ] = 0 ;
V_165 -> V_182 [ 0 ] = 0 ;
V_165 -> V_183 = F_79 () ;
V_165 -> V_184 = F_79 () ;
V_165 -> V_185 = F_80 () ;
V_165 -> V_186 = V_165 -> V_187 = V_188 | V_189 | V_190 ;
V_165 -> V_191 = 1 ;
V_165 -> V_192 = 1 ;
V_165 -> V_193 = V_194 ;
if ( ! V_162 )
goto V_195;
V_169 = F_81 ( V_162 , V_196 , V_140 ) ;
if ( ! V_169 )
goto V_195;
V_170 = V_169 ;
V_168 = V_170 + strlen ( V_170 ) ;
if ( strncmp ( V_170 , L_37 , 4 ) == 0 ) {
if ( V_170 [ 4 ] != 0 ) {
V_174 [ 0 ] = V_170 [ 4 ] ;
V_170 += 5 ;
} else {
F_4 ( 1 , L_38 ) ;
}
}
while ( ( V_167 = F_82 ( & V_170 , V_174 ) ) != NULL ) {
if ( ! * V_167 )
continue;
if ( ( V_166 = strchr ( V_167 , '=' ) ) != NULL )
* V_166 ++ = '\0' ;
if ( F_83 ( V_167 , L_39 , 10 ) == 0 ) {
V_165 -> V_197 = 0 ;
} else if ( F_83 ( V_167 , L_40 , 12 ) == 0 ) {
V_165 -> V_197 = 1 ;
} else if ( F_83 ( V_167 , L_41 , 4 ) == 0 ) {
if ( ! V_166 ) {
F_84 ( V_198
L_42 ) ;
goto V_195;
} else if ( ! * V_166 ) {
V_165 -> V_199 = 1 ;
}
if ( F_78 ( V_166 , V_200 ) <
V_200 ) {
V_165 -> V_201 = F_85 ( V_166 , V_140 ) ;
if ( ! V_165 -> V_201 ) {
F_84 ( V_198 L_43
L_44 ) ;
goto V_195;
}
} else {
F_84 ( V_198 L_45 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_46 , 4 ) == 0 ) {
if ( ! V_166 ) {
V_165 -> V_202 = NULL ;
continue;
} else if ( V_166 [ 0 ] == 0 ) {
if ( V_166 [ 1 ] != V_174 [ 0 ] ) {
V_165 -> V_202 = NULL ;
continue;
}
}
V_171 = strlen ( V_166 ) ;
if ( ( V_166 [ V_171 ] == 0 ) &&
( V_166 + V_171 < V_168 ) &&
( V_166 [ V_171 + 1 ] == V_174 [ 0 ] ) ) {
V_166 [ V_171 ] = V_174 [ 0 ] ;
V_171 += 2 ;
while ( V_166 [ V_171 ] != 0 ) {
if ( V_166 [ V_171 ] == V_174 [ 0 ] ) {
if ( V_166 [ V_171 + 1 ] ==
V_174 [ 0 ] ) {
V_171 ++ ;
} else {
break;
}
}
V_171 ++ ;
}
if ( V_166 [ V_171 ] == 0 ) {
V_170 = NULL ;
} else {
V_166 [ V_171 ] = 0 ;
V_170 = V_166 + V_171 + 1 ;
}
V_165 -> V_202 = F_86 ( V_171 , V_140 ) ;
if ( V_165 -> V_202 == NULL ) {
F_84 ( V_198 L_43
L_47 ) ;
goto V_195;
}
for ( V_172 = 0 , V_173 = 0 ; V_172 < V_171 ; V_172 ++ , V_173 ++ ) {
V_165 -> V_202 [ V_173 ] = V_166 [ V_172 ] ;
if ( V_166 [ V_172 ] == V_174 [ 0 ]
&& V_166 [ V_172 + 1 ] == V_174 [ 0 ] ) {
V_172 ++ ;
}
}
V_165 -> V_202 [ V_173 ] = 0 ;
} else {
V_165 -> V_202 = F_86 ( V_171 + 1 , V_140 ) ;
if ( V_165 -> V_202 == NULL ) {
F_84 ( V_198 L_43
L_47 ) ;
goto V_195;
}
strcpy ( V_165 -> V_202 , V_166 ) ;
}
} else if ( ! F_83 ( V_167 , L_48 , 2 ) ||
! F_83 ( V_167 , L_49 , 4 ) ) {
if ( ! V_166 || ! * V_166 ) {
V_165 -> V_203 = NULL ;
} else if ( F_78 ( V_166 , V_204 ) <
V_204 ) {
V_165 -> V_203 = F_85 ( V_166 , V_140 ) ;
if ( ! V_165 -> V_203 ) {
F_84 ( V_198 L_43
L_50 ) ;
goto V_195;
}
} else {
F_84 ( V_198 L_51
L_52 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_53 , 3 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_54 ) ;
continue;
} else if ( F_83 ( V_166 , L_55 , 5 ) == 0 ) {
V_165 -> V_205 |= V_206 |
V_207 ;
} else if ( F_83 ( V_166 , L_56 , 5 ) == 0 ) {
F_22 ( 1 , L_57 ) ;
goto V_195;
} else if ( F_83 ( V_166 , L_58 , 4 ) == 0 ) {
V_165 -> V_205 |= V_206 ;
} else if ( F_83 ( V_166 , L_59 , 8 ) == 0 ) {
V_165 -> V_205 |= V_208 |
V_207 ;
} else if ( F_83 ( V_166 , L_60 , 7 ) == 0 ) {
V_165 -> V_205 |= V_208 ;
} else if ( F_83 ( V_166 , L_61 , 7 ) == 0 ) {
V_165 -> V_205 |= V_209 |
V_207 ;
} else if ( F_83 ( V_166 , L_62 , 6 ) == 0 ) {
V_165 -> V_205 |= V_209 ;
} else if ( F_83 ( V_166 , L_63 , 5 ) == 0 ) {
V_165 -> V_205 |= V_210 |
V_207 ;
} else if ( F_83 ( V_166 , L_64 , 4 ) == 0 ) {
V_165 -> V_205 |= V_210 ;
} else if ( F_83 ( V_166 , L_65 , 6 ) == 0 ) {
V_165 -> V_205 |= V_209 ;
#ifdef F_87
} else if ( F_83 ( V_166 , L_66 , 6 ) == 0 ) {
V_165 -> V_205 |= V_211 ;
#endif
} else if ( F_83 ( V_166 , L_67 , 4 ) == 0 ) {
V_165 -> V_199 = 1 ;
} else {
F_22 ( 1 , L_68 , V_166 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_69 , 3 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_70
L_71 ) ;
} else if ( ( F_83 ( V_166 , L_72 , 4 ) == 0 ) ||
( F_83 ( V_166 , L_73 , 1 ) == 0 ) ) {
continue;
}
} else if ( ( F_83 ( V_167 , L_74 , 3 ) == 0 )
|| ( F_83 ( V_167 , L_75 , 6 ) == 0 )
|| ( F_83 ( V_167 , L_76 , 4 ) == 0 ) ) {
if ( ! V_166 || ! * V_166 ) {
F_84 ( V_198 L_77
L_78 ) ;
goto V_195;
}
if ( ( V_171 = F_78 ( V_166 , 300 ) ) < 300 ) {
V_165 -> V_212 = F_75 ( V_171 + 1 , V_140 ) ;
if ( V_165 -> V_212 == NULL )
goto V_195;
strcpy ( V_165 -> V_212 , V_166 ) ;
if ( strncmp ( V_165 -> V_212 , L_79 , 2 ) == 0 ) {
V_165 -> V_212 [ 0 ] = '\\' ;
V_165 -> V_212 [ 1 ] = '\\' ;
} else if ( strncmp ( V_165 -> V_212 , L_80 , 2 ) != 0 ) {
F_84 ( V_198
L_81
L_82 ) ;
goto V_195;
}
} else {
F_84 ( V_198 L_83 ) ;
goto V_195;
}
} else if ( ( F_83 ( V_167 , L_84 , 3 ) == 0 )
|| ( F_83 ( V_167 , L_85 , 5 ) == 0 ) ) {
if ( ! V_166 || ! * V_166 ) {
F_84 ( V_198 L_86 ) ;
goto V_195;
}
if ( F_78 ( V_166 , 256 ) < 256 ) {
V_165 -> V_213 = F_85 ( V_166 , V_140 ) ;
if ( ! V_165 -> V_213 ) {
F_84 ( V_198 L_43
L_87 ) ;
goto V_195;
}
F_4 ( 1 , L_88 ) ;
} else {
F_84 ( V_198 L_89
L_90 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_91 , 7 ) == 0 ) {
V_165 -> V_214 . V_215 = V_216 ;
if ( ! V_166 || ! * V_166 ) {
F_84 ( V_198 L_92
L_93 ) ;
goto V_195;
}
V_172 = F_88 ( (struct V_111 * ) & V_165 -> V_214 ,
V_166 , strlen ( V_166 ) ) ;
if ( V_172 == 0 ) {
F_84 ( V_198 L_94
L_95 ,
V_166 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_96 , 10 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_84 ( V_198
L_97 ) ;
goto V_195;
}
if ( ( V_171 = F_78 ( V_166 , 1024 ) ) < 1024 ) {
if ( V_166 [ 0 ] != '/' )
V_171 ++ ;
V_165 -> V_217 = F_75 ( V_171 + 1 , V_140 ) ;
if ( V_165 -> V_217 == NULL )
goto V_195;
if ( V_166 [ 0 ] != '/' ) {
V_165 -> V_217 [ 0 ] = '/' ;
strcpy ( V_165 -> V_217 + 1 , V_166 ) ;
} else
strcpy ( V_165 -> V_217 , V_166 ) ;
F_4 ( 1 , L_98 , V_165 -> V_217 ) ;
} else {
F_84 ( V_198 L_99 ) ;
goto V_195;
}
} else if ( F_83 ( V_167 , L_100 , 9 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_84 ( V_198 L_101
L_102 ) ;
goto V_195;
}
if ( F_78 ( V_166 , 65 ) < 65 ) {
if ( F_83 ( V_166 , L_103 , 7 ) ) {
V_165 -> V_218 = F_85 ( V_166 ,
V_140 ) ;
if ( ! V_165 -> V_218 ) {
F_84 ( V_198 L_104
L_105
L_106 ) ;
goto V_195;
}
}
F_4 ( 1 , L_107 , V_166 ) ;
} else {
F_84 ( V_198 L_108
L_109 ) ;
goto V_195;
}
} else if ( ! F_83 ( V_167 , L_110 , 3 ) && V_166 && * V_166 ) {
V_165 -> V_184 = F_89 ( V_166 , & V_166 , 0 ) ;
V_177 = true ;
} else if ( ! F_83 ( V_167 , L_111 , 5 ) && V_166 && * V_166 ) {
V_165 -> V_183 = F_89 ( V_166 , & V_166 , 0 ) ;
} else if ( ! F_83 ( V_167 , L_112 , 8 ) ) {
V_175 = 1 ;
} else if ( ! F_83 ( V_167 , L_113 , 10 ) ) {
V_175 = 0 ;
} else if ( ! F_83 ( V_167 , L_114 , 3 ) && V_166 && * V_166 ) {
V_165 -> V_185 = F_89 ( V_166 , & V_166 , 0 ) ;
V_178 = true ;
} else if ( ! F_83 ( V_167 , L_115 , 8 ) ) {
V_176 = 1 ;
} else if ( ! F_83 ( V_167 , L_116 , 10 ) ) {
V_176 = 0 ;
} else if ( F_83 ( V_167 , L_117 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_187 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_118 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_186 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_119 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_186 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_120 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_219 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_121 , 5 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_220 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_122 , 5 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_221 =
F_89 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_83 ( V_167 , L_123 , 5 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_124 ) ;
continue;
} else if ( F_83 ( V_166 , L_125 , 11 ) == 0 ) {
V_165 -> V_222 = 1 ;
}
} else if ( F_83 ( V_167 , L_126 , 4 ) == 0 ) {
if ( ! V_166 || ! * V_166 || ( * V_166 == ' ' ) ) {
F_4 ( 1 , L_127 ) ;
} else {
memset ( V_165 -> V_180 , 0x20 ,
V_181 ) ;
for ( V_172 = 0 ; V_172 < V_181 ; V_172 ++ ) {
if ( V_166 [ V_172 ] == 0 )
break;
V_165 -> V_180 [ V_172 ] = V_166 [ V_172 ] ;
}
if ( V_172 == V_181 && V_166 [ V_172 ] != 0 )
F_84 ( V_198 L_128
L_129 ) ;
}
} else if ( F_83 ( V_167 , L_130 , 7 ) == 0 ) {
if ( ! V_166 || ! * V_166 || ( * V_166 == ' ' ) ) {
F_4 ( 1 , L_131 ) ;
} else {
memset ( V_165 -> V_182 , 0x20 ,
V_223 ) ;
for ( V_172 = 0 ; V_172 < 15 ; V_172 ++ ) {
if ( V_166 [ V_172 ] == 0 )
break;
else
V_165 -> V_182 [ V_172 ] =
V_166 [ V_172 ] ;
}
if ( V_172 == V_181 && V_166 [ V_172 ] != 0 )
F_84 ( V_198 L_132
L_133 ) ;
}
} else if ( F_83 ( V_167 , L_134 , 7 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_193 = V_79 * F_89 ( V_166 ,
& V_166 , 0 ) ;
if ( V_165 -> V_193 > V_224 ) {
F_22 ( 1 , L_135
L_136 ) ;
goto V_195;
}
}
} else if ( F_83 ( V_167 , L_137 , 4 ) == 0 ) {
} else if ( F_83 ( V_167 , L_138 , 3 ) == 0 ) {
} else if ( F_83 ( V_167 , L_139 , 5 ) == 0 ) {
} else if ( F_83 ( V_167 , L_140 , 2 ) == 0 && strlen ( V_167 ) == 2 ) {
} else if ( F_83 ( V_167 , L_141 , 2 ) == 0 ) {
} else if ( F_83 ( V_167 , L_142 , 11 ) == 0 ) {
V_165 -> V_225 = 1 ;
} else if ( F_83 ( V_167 , L_143 , 10 ) == 0 ) {
V_165 -> V_226 = 1 ;
} else if ( ( F_83 ( V_167 , L_144 , 4 ) == 0 ) ||
( F_83 ( V_167 , L_145 , 6 ) == 0 ) ||
( F_83 ( V_167 , L_146 , 4 ) == 0 ) ||
( F_83 ( V_167 , L_147 , 6 ) == 0 ) ||
( F_83 ( V_167 , L_148 , 5 ) == 0 ) ||
( F_83 ( V_167 , L_149 , 6 ) == 0 ) ||
( F_83 ( V_167 , L_150 , 3 ) == 0 ) ) {
continue;
} else if ( F_83 ( V_167 , L_151 , 4 ) == 0 ) {
V_165 -> V_227 = 1 ;
} else if ( F_83 ( V_167 , L_152 , 4 ) == 0 ) {
V_165 -> V_227 = 0 ;
} else if ( F_83 ( V_167 , L_153 , 4 ) == 0 ) {
V_165 -> V_228 = 0 ;
} else if ( F_83 ( V_167 , L_154 , 6 ) == 0 ) {
V_165 -> V_228 = 1 ;
} else if ( F_83 ( V_167 , L_155 , 8 ) == 0 ) {
V_165 -> V_229 = 1 ;
} else if ( F_83 ( V_167 , L_156 , 10 ) == 0 ) {
V_165 -> V_229 = 0 ;
} else if ( F_83 ( V_167 , L_157 , 3 ) == 0 ) {
V_165 -> V_230 = 1 ;
} else if ( F_83 ( V_167 , L_158 , 5 ) == 0 ) {
V_165 -> V_230 = 0 ;
} else if ( F_83 ( V_167 , L_159 , 5 ) == 0 ) {
V_165 -> V_231 = 1 ;
} else if ( F_83 ( V_167 , L_160 , 10 ) == 0 ) {
V_165 -> V_191 = 1 ;
} else if ( F_83 ( V_167 , L_161 , 12 ) == 0 ) {
V_165 -> V_191 = 0 ;
} else if ( F_83 ( V_167 , L_162 , 6 ) == 0 ) {
V_165 -> V_232 = 1 ;
} else if ( F_83 ( V_167 , L_163 , 7 ) == 0 ) {
V_165 -> V_232 = 1 ;
} else if ( ( F_83 ( V_167 , L_164 , 6 ) == 0 ) ||
( F_83 ( V_167 , L_165 , 10 ) == 0 ) ) {
V_165 -> V_233 = 1 ;
} else if ( F_83 ( V_167 , L_166 , 4 ) == 0 ) {
} else if ( F_83 ( V_167 , L_167 , 6 ) == 0 ) {
} else if ( F_83 ( V_167 , L_168 , 7 ) == 0 ) {
} else if ( F_83 ( V_167 , L_169 , 3 ) == 0 ) {
V_165 -> V_234 = 0 ;
} else if ( ( F_83 ( V_167 , L_170 , 5 ) == 0 ) ||
( F_83 ( V_167 , L_171 , 6 ) == 0 ) ) {
V_165 -> V_234 = 1 ;
if ( V_165 -> V_187 ==
( V_235 & ~ ( V_236 | V_237 ) ) )
V_165 -> V_187 = V_235 ;
} else if ( F_83 ( V_167 , L_172 , 9 ) == 0 ) {
V_165 -> V_238 = 1 ;
} else if ( F_83 ( V_167 , L_173 , 7 ) == 0 ) {
V_165 -> V_239 = 1 ;
} else if ( F_83 ( V_167 , L_174 , 9 ) == 0 ) {
V_165 -> V_239 = 0 ;
} else if ( F_83 ( V_167 , L_175 , 7 ) == 0 ) {
V_165 -> V_240 = true ;
} else if ( F_83 ( V_167 , L_176 , 9 ) == 0 ) {
V_165 -> V_240 = false ;
} else if ( F_83 ( V_167 , L_177 , 6 ) == 0 ) {
V_165 -> V_227 = 0 ;
} else if ( F_83 ( V_167 , L_178 , 6 ) == 0 ) {
V_165 -> V_227 = 1 ;
} else if ( F_83 ( V_167 , L_179 , 6 ) == 0 ) {
V_165 -> V_241 = 0 ;
} else if ( F_83 ( V_167 , L_180 , 4 ) == 0 ) {
V_165 -> V_241 = 1 ;
} else if ( F_83 ( V_167 , L_181 , 12 ) == 0 ) {
V_165 -> V_242 = 1 ;
} else if ( F_83 ( V_167 , L_182 , 10 ) == 0 ) {
V_165 -> V_242 = 0 ;
} else if ( F_83 ( V_167 , L_183 , 7 ) == 0 ) {
V_165 -> V_192 = 1 ;
} else if ( F_83 ( V_167 , L_184 , 9 ) == 0 ) {
V_165 -> V_192 = 0 ;
} else if ( F_83 ( V_167 , L_185 , 12 ) == 0 ) {
V_165 -> V_243 = 1 ;
} else if ( F_83 ( V_167 , L_186 , 7 ) == 0 ) {
V_165 -> V_244 = 1 ;
} else if ( F_83 ( V_167 , L_187 , 9 ) == 0 ) {
V_165 -> V_244 = 0 ;
} else if ( F_83 ( V_167 , L_188 , 3 ) == 0 ) {
V_165 -> V_245 = 0 ;
} else if ( F_83 ( V_167 , L_189 , 5 ) == 0 ) {
V_165 -> V_245 = 1 ;
} else if ( F_83 ( V_167 , L_190 , 6 ) == 0 ) {
V_165 -> V_246 = 1 ;
} else if ( F_83 ( V_167 , L_191 , 4 ) == 0 ) {
V_165 -> V_205 |= V_207 ;
} else if ( F_83 ( V_167 , L_192 , 4 ) == 0 ) {
V_165 -> V_247 = 1 ;
} else if ( F_83 ( V_167 , L_193 , 6 ) == 0 ) {
V_165 -> V_248 = 1 ;
} else if ( F_83 ( V_167 , L_194 , 13 ) == 0 ) {
V_165 -> V_248 = 1 ;
} else if ( F_83 ( V_167 , L_195 , 11 ) == 0 ) {
V_165 -> V_249 = 1 ;
} else if ( F_83 ( V_167 , L_196 , 4 ) == 0 ) {
F_84 ( V_198 L_197
L_198
L_199 ) ;
} else if ( F_83 ( V_167 , L_200 , 3 ) == 0 ) {
#ifndef F_90
F_22 ( 1 , L_201
L_202 ) ;
goto V_195;
#endif
V_165 -> V_250 = true ;
} else if ( F_83 ( V_167 , L_203 , 10 ) == 0 ) {
V_165 -> V_251 = true ;
} else if ( F_83 ( V_167 , L_204 , 8 ) == 0 ) {
V_165 -> V_252 = true ;
} else
F_84 ( V_198 L_205 ,
V_167 ) ;
}
if ( V_165 -> V_212 == NULL ) {
if ( V_163 == NULL ) {
F_84 ( V_198 L_206
L_207 ) ;
goto V_195;
}
if ( ( V_171 = F_78 ( V_163 , 300 ) ) < 300 ) {
V_165 -> V_212 = F_75 ( V_171 + 1 , V_140 ) ;
if ( V_165 -> V_212 == NULL )
goto V_195;
strcpy ( V_165 -> V_212 , V_163 ) ;
if ( strncmp ( V_165 -> V_212 , L_79 , 2 ) == 0 ) {
V_165 -> V_212 [ 0 ] = '\\' ;
V_165 -> V_212 [ 1 ] = '\\' ;
} else if ( strncmp ( V_165 -> V_212 , L_80 , 2 ) != 0 ) {
F_84 ( V_198 L_208
L_209 ) ;
goto V_195;
}
V_166 = strpbrk ( V_165 -> V_212 + 2 , L_210 ) ;
if ( V_166 )
* V_166 = '\\' ;
} else {
F_84 ( V_198 L_83 ) ;
goto V_195;
}
}
if ( V_165 -> V_252 && ! ( V_165 -> V_205 & V_206 ) ) {
F_22 ( 1 , L_211
L_212 ) ;
goto V_195;
}
if ( V_165 -> V_203 == NULL )
V_165 -> V_203 = & V_165 -> V_212 [ 2 ] ;
if ( V_177 )
V_165 -> V_175 = V_175 ;
else if ( V_175 == 1 )
F_84 ( V_253 L_213
L_214 ) ;
if ( V_178 )
V_165 -> V_176 = V_176 ;
else if ( V_176 == 1 )
F_84 ( V_253 L_215
L_216 ) ;
F_10 ( V_169 ) ;
return 0 ;
V_195:
F_10 ( V_169 ) ;
return 1 ;
}
static bool
F_91 ( struct V_111 * V_214 , struct V_111 * V_254 )
{
switch ( V_214 -> V_255 ) {
case V_216 :
return ( V_254 -> V_255 == V_216 ) ;
case V_256 : {
struct V_257 * V_258 = (struct V_257 * ) V_214 ;
struct V_257 * V_259 = (struct V_257 * ) V_254 ;
return ( V_258 -> V_260 . V_261 == V_259 -> V_260 . V_261 ) ;
}
case V_262 : {
struct V_263 * V_264 = (struct V_263 * ) V_214 ;
struct V_263 * V_265 = (struct V_263 * ) & V_254 ;
return F_92 ( & V_264 -> V_266 , & V_265 -> V_266 ) ;
}
default:
F_93 ( 1 ) ;
return false ;
}
}
static bool
F_94 ( struct V_1 * V_2 , struct V_111 * V_267 )
{
T_2 V_219 , * V_268 ;
switch ( V_267 -> V_255 ) {
case V_256 :
V_268 = & ( (struct V_257 * ) & V_2 -> V_112 ) -> V_269 ;
V_219 = ( (struct V_257 * ) V_267 ) -> V_269 ;
break;
case V_262 :
V_268 = & ( (struct V_263 * ) & V_2 -> V_112 ) -> V_270 ;
V_219 = ( (struct V_263 * ) V_267 ) -> V_270 ;
break;
default:
F_93 ( 1 ) ;
return false ;
}
if ( ! V_219 ) {
V_219 = F_95 ( V_113 ) ;
if ( V_219 == * V_268 )
return true ;
V_219 = F_95 ( V_271 ) ;
}
return V_219 == * V_268 ;
}
static bool
F_96 ( struct V_1 * V_2 , struct V_111 * V_267 ,
struct V_111 * V_214 )
{
switch ( V_267 -> V_255 ) {
case V_256 : {
struct V_257 * V_272 = (struct V_257 * ) V_267 ;
struct V_257 * V_273 =
(struct V_257 * ) & V_2 -> V_112 ;
if ( V_272 -> V_260 . V_261 != V_273 -> V_260 . V_261 )
return false ;
break;
}
case V_262 : {
struct V_263 * V_274 = (struct V_263 * ) V_267 ;
struct V_263 * V_275 =
(struct V_263 * ) & V_2 -> V_112 ;
if ( ! F_92 ( & V_274 -> V_266 ,
& V_275 -> V_266 ) )
return false ;
if ( V_274 -> V_276 != V_275 -> V_276 )
return false ;
break;
}
default:
F_93 ( 1 ) ;
return false ;
}
if ( ! F_91 ( V_214 , (struct V_111 * ) & V_2 -> V_214 ) )
return false ;
return true ;
}
static bool
F_97 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
unsigned int V_277 ;
if ( V_165 -> V_205 & ( ~ ( V_207 | V_278 ) ) )
V_277 = V_165 -> V_205 ;
else
V_277 = V_279 | V_165 -> V_205 ;
switch ( V_2 -> V_280 ) {
case V_281 :
if ( ! ( V_277 & ( V_211 | V_282 ) ) )
return false ;
break;
case V_283 :
if ( ! ( V_277 & V_209 ) )
return false ;
break;
case V_284 :
if ( ! ( V_277 & V_210 ) )
return false ;
break;
case V_285 :
if ( ! ( V_277 & V_206 ) )
return false ;
break;
case V_286 :
if ( ! ( V_277 & V_208 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_277 & V_287 ) == 0 &&
( V_2 -> V_288 & V_289 ) )
return false ;
else if ( ( ( V_277 & V_207 ) == V_207 ) &&
( V_2 -> V_288 &
( V_290 | V_289 ) ) == 0 )
return false ;
return true ;
}
static int F_98 ( struct V_1 * V_2 , struct V_111 * V_267 ,
struct V_164 * V_165 )
{
if ( ! F_99 ( F_100 ( V_2 ) , V_147 -> V_291 -> V_292 ) )
return 0 ;
if ( ! F_96 ( V_2 , V_267 ,
(struct V_111 * ) & V_165 -> V_214 ) )
return 0 ;
if ( ! F_94 ( V_2 , V_267 ) )
return 0 ;
if ( ! F_97 ( V_2 , V_165 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_101 ( struct V_111 * V_267 , struct V_164 * V_165 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_102 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_98 ( V_2 , V_267 , V_165 ) )
continue;
++ V_2 -> V_293 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_217 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_103 ( struct V_1 * V_2 )
{
struct V_143 * V_294 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_293 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_104 ( F_100 ( V_2 ) ) ;
F_15 ( & V_2 -> V_130 ) ;
F_3 ( & V_20 ) ;
F_105 ( & V_2 -> V_77 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_294 = F_68 ( & V_2 -> V_154 , NULL ) ;
if ( V_294 )
F_108 ( V_295 , V_294 ) ;
}
static struct V_1 *
F_109 ( struct V_164 * V_296 )
{
struct V_1 * V_297 = NULL ;
struct V_298 V_267 ;
struct V_257 * V_299 = (struct V_257 * ) & V_267 ;
struct V_263 * V_300 = (struct V_263 * ) & V_267 ;
int V_3 ;
memset ( & V_267 , 0 , sizeof( struct V_298 ) ) ;
F_4 ( 1 , L_218 , V_296 -> V_212 , V_296 -> V_203 ) ;
if ( V_296 -> V_203 && V_296 -> V_212 ) {
V_3 = F_110 ( (struct V_111 * ) & V_267 ,
V_296 -> V_203 ,
strlen ( V_296 -> V_203 ) ,
V_296 -> V_219 ) ;
if ( ! V_3 ) {
V_3 = - V_55 ;
goto V_301;
}
} else if ( V_296 -> V_203 ) {
F_22 ( 1 , L_219 ) ;
V_3 = - V_55 ;
goto V_301;
} else {
F_22 ( 1 , L_220
L_221 ) ;
V_3 = - V_55 ;
goto V_301;
}
V_297 = F_101 ( (struct V_111 * ) & V_267 , V_296 ) ;
if ( V_297 )
return V_297 ;
V_297 = F_86 ( sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_297 ) {
V_3 = - V_161 ;
goto V_301;
}
V_3 = F_111 ( V_297 ) ;
if ( V_3 ) {
F_22 ( 1 , L_222 , V_3 ) ;
goto V_301;
}
F_112 ( V_297 , F_113 ( V_147 -> V_291 -> V_292 ) ) ;
V_297 -> V_81 = F_73 ( V_296 -> V_212 ) ;
if ( F_114 ( V_297 -> V_81 ) ) {
V_3 = F_115 ( V_297 -> V_81 ) ;
goto V_302;
}
V_297 -> V_225 = V_296 -> V_225 ;
V_297 -> V_226 = V_296 -> V_226 ;
V_297 -> V_303 = V_296 -> V_222 ;
F_50 ( & V_297 -> V_131 , 0 ) ;
F_116 ( & V_297 -> V_114 ) ;
F_116 ( & V_297 -> V_133 ) ;
F_12 ( & V_297 -> V_134 ) ;
F_117 ( & V_297 -> V_25 ) ;
memcpy ( V_297 -> V_304 ,
V_296 -> V_180 , V_223 ) ;
memcpy ( V_297 -> V_305 ,
V_296 -> V_182 , V_223 ) ;
V_297 -> V_31 = false ;
V_297 -> V_30 = 0 ;
V_297 -> V_35 = V_36 ;
F_12 ( & V_297 -> V_130 ) ;
F_12 ( & V_297 -> V_21 ) ;
F_118 ( & V_297 -> V_77 , F_29 ) ;
V_297 -> V_15 = V_306 ;
memcpy ( & V_297 -> V_214 , & V_296 -> V_214 ,
sizeof( V_297 -> V_214 ) ) ;
++ V_297 -> V_293 ;
if ( V_267 . V_215 == V_262 ) {
F_4 ( 1 , L_223 ) ;
memcpy ( & V_297 -> V_112 , V_300 ,
sizeof( struct V_263 ) ) ;
} else
memcpy ( & V_297 -> V_112 , V_299 ,
sizeof( struct V_257 ) ) ;
V_3 = F_119 ( V_297 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_224 ) ;
goto V_302;
}
F_120 ( V_307 ) ;
V_297 -> V_154 = F_121 ( F_54 ,
V_297 , L_225 ) ;
if ( F_114 ( V_297 -> V_154 ) ) {
V_3 = F_115 ( V_297 -> V_154 ) ;
F_22 ( 1 , L_226 , V_3 ) ;
F_122 ( V_307 ) ;
goto V_302;
}
V_297 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_123 ( & V_297 -> V_130 , & V_308 ) ;
F_3 ( & V_20 ) ;
F_124 ( V_297 ) ;
F_33 ( V_82 , & V_297 -> V_77 , V_78 ) ;
return V_297 ;
V_302:
F_106 ( V_297 ) ;
F_104 ( F_100 ( V_297 ) ) ;
V_301:
if ( V_297 ) {
if ( ! F_114 ( V_297 -> V_81 ) )
F_10 ( V_297 -> V_81 ) ;
if ( V_297 -> V_26 )
F_9 ( V_297 -> V_26 ) ;
F_10 ( V_297 ) ;
}
return F_74 ( V_3 ) ;
}
static int F_125 ( struct V_7 * V_8 , struct V_164 * V_165 )
{
switch ( V_8 -> V_2 -> V_280 ) {
case V_285 :
if ( V_165 -> V_183 != V_8 -> V_183 )
return 0 ;
break;
default:
if ( V_8 -> V_309 == NULL )
return 0 ;
if ( strncmp ( V_8 -> V_309 , V_165 -> V_201 ,
V_200 ) )
return 0 ;
if ( strlen ( V_165 -> V_201 ) != 0 &&
V_8 -> V_202 != NULL &&
strncmp ( V_8 -> V_202 ,
V_165 -> V_202 ? V_165 -> V_202 : L_227 ,
V_310 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_126 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_102 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_125 ( V_8 , V_165 ) )
continue;
++ V_8 -> V_311 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_127 ( struct V_7 * V_8 )
{
int V_312 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_228 , V_19 , V_8 -> V_311 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_311 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_313 == V_151 ) {
V_312 = F_128 () ;
F_129 ( V_312 , V_8 ) ;
F_130 ( V_312 ) ;
}
F_131 ( V_8 ) ;
F_103 ( V_2 ) ;
}
static struct V_7 *
F_132 ( struct V_1 * V_2 , struct V_164 * V_296 )
{
int V_3 = - V_161 , V_312 ;
struct V_7 * V_8 ;
struct V_257 * V_267 = (struct V_257 * ) & V_2 -> V_112 ;
struct V_263 * V_274 = (struct V_263 * ) & V_2 -> V_112 ;
V_312 = F_128 () ;
V_8 = F_126 ( V_2 , V_296 ) ;
if ( V_8 ) {
F_4 ( 1 , L_229 , V_8 -> V_313 ) ;
F_7 ( & V_8 -> V_314 ) ;
V_3 = F_133 ( V_312 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_314 ) ;
F_127 ( V_8 ) ;
F_134 ( V_312 ) ;
return F_74 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_230 ) ;
V_3 = F_135 ( V_312 , V_8 ,
V_296 -> V_315 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_314 ) ;
F_127 ( V_8 ) ;
F_134 ( V_312 ) ;
return F_74 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_314 ) ;
F_103 ( V_2 ) ;
F_134 ( V_312 ) ;
return V_8 ;
}
F_4 ( 1 , L_231 ) ;
V_8 = F_136 () ;
if ( V_8 == NULL )
goto V_316;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_112 . V_215 == V_262 )
sprintf ( V_8 -> V_317 , L_232 , & V_274 -> V_266 ) ;
else
sprintf ( V_8 -> V_317 , L_233 , & V_267 -> V_260 ) ;
if ( V_296 -> V_201 ) {
V_8 -> V_309 = F_85 ( V_296 -> V_201 , V_140 ) ;
if ( ! V_8 -> V_309 )
goto V_316;
}
if ( V_296 -> V_202 ) {
V_8 -> V_202 = F_85 ( V_296 -> V_202 , V_140 ) ;
if ( ! V_8 -> V_202 )
goto V_316;
}
if ( V_296 -> V_213 ) {
V_8 -> V_318 = F_85 ( V_296 -> V_213 , V_140 ) ;
if ( ! V_8 -> V_318 )
goto V_316;
}
V_8 -> V_183 = V_296 -> V_183 ;
V_8 -> V_184 = V_296 -> V_184 ;
if ( ( V_296 -> V_205 == 0 ) && V_319 == false ) {
V_319 = true ;
F_22 ( 1 , L_234
L_235
L_236 ) ;
}
V_8 -> V_320 = V_296 -> V_205 ;
F_7 ( & V_8 -> V_314 ) ;
V_3 = F_133 ( V_312 , V_8 ) ;
if ( ! V_3 )
V_3 = F_135 ( V_312 , V_8 , V_296 -> V_315 ) ;
F_11 ( & V_8 -> V_314 ) ;
if ( V_3 )
goto V_316;
F_2 ( & V_20 ) ;
F_123 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_134 ( V_312 ) ;
return V_8 ;
V_316:
F_131 ( V_8 ) ;
F_134 ( V_312 ) ;
return F_74 ( V_3 ) ;
}
static int F_137 ( struct V_9 * V_10 , const char * V_157 )
{
if ( V_10 -> V_321 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_322 , V_157 , V_323 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_138 ( struct V_7 * V_8 , const char * V_157 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_137 ( V_10 , V_157 ) )
continue;
++ V_10 -> V_324 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_139 ( struct V_9 * V_10 )
{
int V_312 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_237 , V_19 , V_10 -> V_324 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_324 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_312 = F_128 () ;
F_140 ( V_312 , V_10 ) ;
F_130 ( V_312 ) ;
F_141 ( V_10 ) ;
F_142 ( V_10 ) ;
F_127 ( V_8 ) ;
}
static struct V_9 *
F_143 ( struct V_7 * V_8 , struct V_164 * V_296 )
{
int V_3 , V_312 ;
struct V_9 * V_10 ;
V_10 = F_138 ( V_8 , V_296 -> V_212 ) ;
if ( V_10 ) {
F_4 ( 1 , L_238 ) ;
F_127 ( V_8 ) ;
if ( V_10 -> V_247 != V_296 -> V_247 )
F_22 ( 1 , L_239
L_240 ) ;
return V_10 ;
}
V_10 = F_144 () ;
if ( V_10 == NULL ) {
V_3 = - V_161 ;
goto V_325;
}
V_10 -> V_8 = V_8 ;
if ( V_296 -> V_202 ) {
V_10 -> V_202 = F_85 ( V_296 -> V_202 , V_140 ) ;
if ( ! V_10 -> V_202 ) {
V_3 = - V_161 ;
goto V_325;
}
}
if ( strchr ( V_296 -> V_212 + 3 , '\\' ) == NULL
&& strchr ( V_296 -> V_212 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_241 ) ;
V_3 = - V_326 ;
goto V_325;
}
V_312 = F_128 () ;
V_3 = F_145 ( V_312 , V_8 , V_296 -> V_212 , V_10 , V_296 -> V_315 ) ;
F_134 ( V_312 ) ;
F_4 ( 1 , L_242 , V_3 ) ;
if ( V_3 )
goto V_325;
if ( V_296 -> V_231 ) {
V_10 -> V_327 &= ~ V_328 ;
F_4 ( 1 , L_243 , V_10 -> V_327 ) ;
}
V_10 -> V_247 = V_296 -> V_247 ;
V_10 -> V_227 = V_296 -> V_227 ;
V_10 -> V_233 = V_296 -> V_233 ;
V_10 -> V_246 = V_296 -> V_246 ;
F_2 ( & V_20 ) ;
F_123 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_146 ( V_10 ) ;
return V_10 ;
V_325:
F_142 ( V_10 ) ;
return F_74 ( V_3 ) ;
}
void
F_147 ( struct V_329 * V_330 )
{
if ( ! V_330 || F_114 ( V_330 ) )
return;
if ( ! F_148 ( & V_330 -> V_331 ) ||
F_149 ( V_332 , & V_330 -> V_333 ) ) {
V_330 -> V_334 = V_36 ;
return;
}
if ( ! F_114 ( F_150 ( V_330 ) ) )
F_139 ( F_150 ( V_330 ) ) ;
F_10 ( V_330 ) ;
return;
}
static inline struct V_329 *
F_151 ( struct V_335 * V_336 )
{
return V_336 -> V_337 ;
}
static int
F_152 ( struct V_338 * V_339 , struct V_340 * V_341 )
{
struct V_335 * V_342 = F_153 ( V_339 ) ;
struct V_335 * V_343 = V_341 -> V_336 ;
if ( ( V_339 -> V_344 & V_345 ) != ( V_341 -> V_28 & V_345 ) )
return 0 ;
if ( ( V_342 -> V_346 & V_347 ) !=
( V_343 -> V_346 & V_347 ) )
return 0 ;
if ( V_342 -> V_220 != V_343 -> V_220 )
return 0 ;
if ( V_343 -> V_221 && V_343 -> V_221 < V_342 -> V_221 )
return 0 ;
if ( V_342 -> V_348 != V_343 -> V_348 || V_342 -> V_349 != V_343 -> V_349 )
return 0 ;
if ( V_342 -> V_350 != V_343 -> V_350 ||
V_342 -> V_351 != V_343 -> V_351 )
return 0 ;
if ( strcmp ( V_342 -> V_315 -> V_352 , V_343 -> V_315 -> V_352 ) )
return 0 ;
if ( V_342 -> V_193 != V_343 -> V_193 )
return 0 ;
return 1 ;
}
int
F_154 ( struct V_338 * V_339 , void * V_167 )
{
struct V_340 * V_341 = (struct V_340 * ) V_167 ;
struct V_164 * V_296 ;
struct V_335 * V_336 ;
struct V_1 * V_353 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_329 * V_330 ;
struct V_298 V_267 ;
int V_3 = 0 ;
memset ( & V_267 , 0 , sizeof( struct V_298 ) ) ;
F_2 ( & V_20 ) ;
V_336 = F_153 ( V_339 ) ;
V_330 = F_155 ( F_151 ( V_336 ) ) ;
if ( F_114 ( V_330 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_150 ( V_330 ) ;
V_8 = V_10 -> V_8 ;
V_353 = V_8 -> V_2 ;
V_296 = V_341 -> V_165 ;
if ( ! V_296 -> V_203 || ! V_296 -> V_212 )
goto V_354;
V_3 = F_110 ( (struct V_111 * ) & V_267 ,
V_296 -> V_203 ,
strlen ( V_296 -> V_203 ) ,
V_296 -> V_219 ) ;
if ( ! V_3 )
goto V_354;
if ( ! F_98 ( V_353 , (struct V_111 * ) & V_267 , V_296 ) ||
! F_125 ( V_8 , V_296 ) ||
! F_137 ( V_10 , V_296 -> V_212 ) ) {
V_3 = 0 ;
goto V_354;
}
V_3 = F_152 ( V_339 , V_341 ) ;
V_354:
F_3 ( & V_20 ) ;
F_147 ( V_330 ) ;
return V_3 ;
}
int
F_156 ( int V_312 , struct V_7 * V_355 , const char * V_356 ,
const struct V_357 * V_358 , unsigned int * V_359 ,
struct V_360 * * V_361 , int V_229 )
{
char * V_362 ;
int V_3 = 0 ;
* V_359 = 0 ;
* V_361 = NULL ;
if ( V_355 -> V_23 == 0 ) {
V_362 = F_75 ( 2 +
F_78 ( V_355 -> V_317 ,
V_363 * 2 )
+ 1 + 4 + 2 ,
V_140 ) ;
if ( V_362 == NULL )
return - V_161 ;
V_362 [ 0 ] = '\\' ;
V_362 [ 1 ] = '\\' ;
strcpy ( V_362 + 2 , V_355 -> V_317 ) ;
strcpy ( V_362 + 2 + strlen ( V_355 -> V_317 ) , L_244 ) ;
V_3 = F_145 ( V_312 , V_355 , V_362 , NULL , V_358 ) ;
F_4 ( 1 , L_245 , V_3 , V_355 -> V_23 ) ;
F_10 ( V_362 ) ;
}
if ( V_3 == 0 )
V_3 = F_157 ( V_312 , V_355 , V_356 , V_361 ,
V_359 , V_358 , V_229 ) ;
return V_3 ;
}
static inline void
F_158 ( struct V_364 * V_365 )
{
struct V_365 * V_366 = V_365 -> V_366 ;
F_159 ( F_160 ( V_366 ) ) ;
F_161 ( V_366 , L_246 ,
& V_367 [ 0 ] , L_247 , & V_368 [ 0 ] ) ;
}
static inline void
F_162 ( struct V_364 * V_365 )
{
struct V_365 * V_366 = V_365 -> V_366 ;
F_159 ( F_160 ( V_366 ) ) ;
F_161 ( V_366 , L_248 ,
& V_367 [ 1 ] , L_249 , & V_368 [ 1 ] ) ;
}
static inline void
F_158 ( struct V_364 * V_365 )
{
}
static inline void
F_162 ( struct V_364 * V_365 )
{
}
static void F_163 ( char * V_369 , char * V_370 , unsigned int V_96 )
{
unsigned int V_172 , V_173 ;
for ( V_172 = 0 , V_173 = 0 ; V_172 < ( V_96 ) ; V_172 ++ ) {
V_369 [ V_173 ] = 'A' + ( 0x0F & ( V_370 [ V_172 ] >> 4 ) ) ;
V_369 [ V_173 + 1 ] = 'A' + ( 0x0F & V_370 [ V_172 ] ) ;
V_173 += 2 ;
}
}
static int
F_164 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_214 . V_215 != V_216 ) {
struct V_364 * V_364 = V_2 -> V_26 ;
V_3 = V_364 -> V_371 -> V_372 ( V_364 ,
(struct V_111 * ) & V_2 -> V_214 ,
sizeof( V_2 -> V_214 ) ) ;
if ( V_3 < 0 ) {
struct V_257 * V_258 ;
struct V_263 * V_264 ;
V_258 = (struct V_257 * ) & V_2 -> V_214 ;
V_264 = (struct V_263 * ) & V_2 -> V_214 ;
if ( V_264 -> V_373 == V_262 )
F_22 ( 1 , L_250
L_251 ,
& V_264 -> V_266 , V_3 ) ;
else
F_22 ( 1 , L_250
L_252 ,
& V_258 -> V_260 . V_261 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_165 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_374 * V_375 ;
struct V_44 * V_376 ;
V_375 = F_86 ( sizeof( struct V_374 ) ,
V_140 ) ;
if ( V_375 ) {
V_375 -> V_377 . V_378 . V_379 = 32 ;
if ( V_2 -> V_305 &&
V_2 -> V_305 [ 0 ] != 0 )
F_163 ( V_375 -> V_377 .
V_378 . V_380 ,
V_2 -> V_305 ,
V_223 ) ;
else
F_163 ( V_375 -> V_377 .
V_378 . V_380 ,
V_381 ,
V_223 ) ;
V_375 -> V_377 . V_378 . V_382 = 32 ;
if ( V_2 -> V_304 &&
V_2 -> V_304 [ 0 ] != 0 )
F_163 ( V_375 -> V_377 .
V_378 . V_383 ,
V_2 -> V_304 ,
V_223 ) ;
else
F_163 ( V_375 -> V_377 .
V_378 . V_383 ,
L_253 ,
V_223 ) ;
V_375 -> V_377 . V_378 . V_384 = 0 ;
V_375 -> V_377 . V_378 . V_385 = 0 ;
V_376 = (struct V_44 * ) V_375 ;
V_376 -> V_72 = F_28 ( 0x81000044 ) ;
V_3 = F_166 ( V_2 , V_376 , 0x44 ) ;
F_10 ( V_375 ) ;
F_39 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_2 V_268 ;
int V_386 , V_387 ;
struct V_364 * V_364 = V_2 -> V_26 ;
struct V_111 * V_388 ;
V_388 = (struct V_111 * ) & V_2 -> V_112 ;
if ( V_2 -> V_112 . V_215 == V_262 ) {
V_268 = ( (struct V_263 * ) V_388 ) -> V_270 ;
V_386 = sizeof( struct V_263 ) ;
V_387 = V_262 ;
} else {
V_268 = ( (struct V_257 * ) V_388 ) -> V_269 ;
V_386 = sizeof( struct V_257 ) ;
V_387 = V_256 ;
}
if ( V_364 == NULL ) {
V_3 = F_167 ( F_100 ( V_2 ) , V_387 , V_389 ,
V_390 , & V_364 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_254 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_255 ) ;
V_2 -> V_26 = V_364 ;
V_364 -> V_366 -> V_391 = V_392 ;
if ( V_387 == V_262 )
F_162 ( V_364 ) ;
else
F_158 ( V_364 ) ;
}
V_3 = F_164 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_364 -> V_366 -> V_393 = 7 * V_79 ;
V_364 -> V_366 -> V_394 = 5 * V_79 ;
if ( V_2 -> V_226 ) {
if ( V_364 -> V_366 -> V_395 < ( 200 * 1024 ) )
V_364 -> V_366 -> V_395 = 200 * 1024 ;
if ( V_364 -> V_366 -> V_396 < ( 140 * 1024 ) )
V_364 -> V_366 -> V_396 = 140 * 1024 ;
}
if ( V_2 -> V_303 ) {
int V_397 = 1 ;
V_3 = F_168 ( V_364 , V_398 , V_399 ,
( char * ) & V_397 , sizeof( V_397 ) ) ;
if ( V_3 )
F_4 ( 1 , L_256 , V_3 ) ;
}
F_4 ( 1 , L_257 ,
V_364 -> V_366 -> V_395 ,
V_364 -> V_366 -> V_396 , V_364 -> V_366 -> V_393 ) ;
V_3 = V_364 -> V_371 -> V_400 ( V_364 , V_388 , V_386 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_258 , V_3 ) ;
F_9 ( V_364 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_268 == F_95 ( V_271 ) )
V_3 = F_165 ( V_2 ) ;
return V_3 ;
}
static int
F_119 ( struct V_1 * V_2 )
{
T_2 * V_268 ;
struct V_263 * V_274 = (struct V_263 * ) & V_2 -> V_112 ;
struct V_257 * V_267 = (struct V_257 * ) & V_2 -> V_112 ;
if ( V_2 -> V_112 . V_215 == V_262 )
V_268 = & V_274 -> V_270 ;
else
V_268 = & V_267 -> V_269 ;
if ( * V_268 == 0 ) {
int V_3 ;
* V_268 = F_95 ( V_113 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_268 = F_95 ( V_271 ) ;
}
return F_17 ( V_2 ) ;
}
void F_169 ( int V_312 , struct V_9 * V_10 ,
struct V_335 * V_336 , struct V_164 * V_401 )
{
T_3 V_402 = F_170 ( V_10 -> V_403 . V_404 ) ;
if ( V_401 && V_401 -> V_232 ) {
V_10 -> V_403 . V_404 = 0 ;
V_10 -> V_405 = 0 ;
F_4 ( 1 , L_259 ) ;
return;
} else if ( V_401 )
V_10 -> V_405 = 1 ;
if ( V_10 -> V_405 == 0 ) {
F_4 ( 1 , L_260 ) ;
return;
}
if ( ! F_171 ( V_312 , V_10 ) ) {
T_3 V_406 = F_170 ( V_10 -> V_403 . V_404 ) ;
F_4 ( 1 , L_261 , V_406 ) ;
if ( V_401 == NULL ) {
if ( ( V_402 & V_407 ) == 0 )
V_406 &= ~ V_407 ;
if ( ( V_402 & V_408 ) == 0 ) {
if ( V_406 & V_408 )
F_22 ( 1 , L_262 ) ;
V_406 &= ~ V_408 ;
} else if ( ( V_406 & V_408 ) == 0 ) {
F_22 ( 1 , L_263 ) ;
F_22 ( 1 , L_264 ) ;
}
}
if ( V_406 & V_409 )
F_22 ( 1 , L_265 ) ;
V_406 &= V_410 ;
if ( V_401 && V_401 -> V_245 )
V_406 &= ~ V_407 ;
else if ( V_407 & V_406 ) {
F_4 ( 1 , L_266 ) ;
if ( V_336 )
V_336 -> V_346 |=
V_411 ;
}
if ( V_401 && V_401 -> V_191 == 0 )
V_406 &= ~ V_408 ;
else if ( V_406 & V_408 ) {
F_4 ( 1 , L_267 ) ;
if ( V_336 )
V_336 -> V_346 |=
V_412 ;
}
if ( V_336 && ( V_336 -> V_220 > 127 * 1024 ) ) {
if ( ( V_406 & V_413 ) == 0 ) {
V_336 -> V_220 = 127 * 1024 ;
F_4 ( V_414 , L_268 ) ;
}
}
F_4 ( 1 , L_269 , ( int ) V_406 ) ;
#ifdef F_63
if ( V_406 & V_415 )
F_4 ( 1 , L_270 ) ;
if ( V_406 & V_416 )
F_4 ( 1 , L_271 ) ;
if ( V_406 & V_408 )
F_4 ( 1 , L_272 ) ;
if ( V_406 & V_417 )
F_4 ( 1 , L_273 ) ;
if ( V_406 & V_407 )
F_4 ( 1 , L_274 ) ;
if ( V_406 & V_413 )
F_4 ( 1 , L_275 ) ;
if ( V_406 & V_418 )
F_4 ( 1 , L_276 ) ;
if ( V_406 & V_419 )
F_4 ( 1 , L_277 ) ;
if ( V_406 & V_409 )
F_4 ( 1 , L_278 ) ;
#endif
if ( F_172 ( V_312 , V_10 , V_406 ) ) {
if ( V_401 == NULL ) {
F_4 ( 1 , L_279 ) ;
} else
F_22 ( 1 , L_280
L_281
L_282
L_283
L_284
L_285 ) ;
}
}
}
void F_173 ( struct V_164 * V_420 ,
struct V_335 * V_336 )
{
F_118 ( & V_336 -> V_421 , V_422 ) ;
F_174 ( & V_336 -> V_423 ) ;
V_336 -> V_424 = V_425 ;
if ( V_420 -> V_220 > V_73 ) {
F_22 ( 1 , L_286 ,
V_420 -> V_220 ) ;
V_336 -> V_220 = V_73 ;
} else if ( ( V_420 -> V_220 ) &&
( V_420 -> V_220 <= V_73 ) )
V_336 -> V_220 = V_420 -> V_220 ;
else
V_336 -> V_220 = V_73 ;
if ( V_336 -> V_220 < 2048 ) {
V_336 -> V_220 = 2048 ;
F_4 ( 1 , L_287 ) ;
}
V_336 -> V_221 = V_420 -> V_221 ;
V_336 -> V_348 = V_420 -> V_184 ;
V_336 -> V_349 = V_420 -> V_185 ;
V_336 -> V_350 = V_420 -> V_187 ;
V_336 -> V_351 = V_420 -> V_186 ;
F_4 ( 1 , L_288 ,
V_336 -> V_350 , V_336 -> V_351 ) ;
V_336 -> V_193 = V_420 -> V_193 ;
V_336 -> V_315 = V_420 -> V_315 ;
if ( V_420 -> V_228 )
V_336 -> V_346 |= V_426 ;
if ( V_420 -> V_239 )
V_336 -> V_346 |= V_427 ;
if ( V_420 -> V_192 )
V_336 -> V_346 |= V_428 ;
if ( V_420 -> V_229 )
V_336 -> V_346 |= V_429 ;
if ( V_420 -> V_197 )
V_336 -> V_346 |= V_430 ;
if ( V_420 -> V_230 )
V_336 -> V_346 |= V_431 ;
if ( V_420 -> V_234 )
V_336 -> V_346 |= V_432 ;
if ( V_420 -> V_242 )
V_336 -> V_346 |= V_433 ;
if ( V_420 -> V_238 )
V_336 -> V_346 |= V_434 ;
if ( V_420 -> V_243 )
V_336 -> V_346 |= V_435 ;
if ( V_420 -> V_244 )
V_336 -> V_346 |= V_436 ;
if ( V_420 -> V_175 )
V_336 -> V_346 |= V_437 ;
if ( V_420 -> V_176 )
V_336 -> V_346 |= V_438 ;
if ( V_420 -> V_240 )
V_336 -> V_346 |= V_439 ;
if ( V_420 -> V_250 )
V_336 -> V_346 |= V_440 ;
if ( V_420 -> V_252 )
V_336 -> V_346 |= ( V_441 |
V_426 ) ;
if ( V_420 -> V_249 )
V_336 -> V_346 |= V_442 ;
if ( V_420 -> V_248 ) {
F_4 ( 1 , L_289 ) ;
V_336 -> V_346 |= V_443 ;
}
if ( V_420 -> V_251 ) {
if ( V_420 -> V_230 ) {
F_22 ( 1 , L_290
L_291 ) ;
} else {
V_336 -> V_346 |= V_444 ;
}
}
if ( ( V_420 -> V_244 ) && ( V_420 -> V_240 ) )
F_22 ( 1 , L_292
L_293 ) ;
}
static unsigned int
F_175 ( struct V_9 * V_10 , struct V_164 * V_420 )
{
T_3 V_445 = F_170 ( V_10 -> V_403 . V_404 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_221 = V_420 -> V_221 ? V_420 -> V_221 :
V_446 ;
if ( ! V_10 -> V_405 || ! ( V_445 & V_418 ) )
V_221 = F_61 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_447 & V_448 ) ||
( ! ( V_2 -> V_447 & V_449 ) &&
( V_2 -> V_288 & ( V_290 | V_289 ) ) ) )
V_221 = F_61 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_221 = F_61 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_221 ;
}
static int
F_176 ( int V_312 , struct V_9 * V_10 ,
struct V_335 * V_336 , const char * V_450 )
{
int V_3 ;
T_4 * V_451 ;
V_451 = F_75 ( sizeof( T_4 ) , V_140 ) ;
if ( V_451 == NULL )
return - V_161 ;
V_3 = F_177 ( V_312 , V_10 , V_450 , V_451 ,
0 , V_336 -> V_315 ,
V_336 -> V_346 &
V_429 ) ;
if ( V_3 == - V_452 || V_3 == - V_55 )
V_3 = F_178 ( V_312 , V_10 , V_450 , V_451 ,
V_336 -> V_315 , V_336 -> V_346 &
V_429 ) ;
F_10 ( V_451 ) ;
return V_3 ;
}
static void
F_179 ( struct V_164 * V_296 )
{
F_10 ( V_296 -> V_201 ) ;
F_180 ( V_296 -> V_202 ) ;
F_10 ( V_296 -> V_212 ) ;
if ( V_296 -> V_203 != V_296 -> V_212 + 2 )
F_10 ( V_296 -> V_203 ) ;
F_10 ( V_296 -> V_213 ) ;
F_10 ( V_296 -> V_218 ) ;
F_10 ( V_296 -> V_217 ) ;
}
void
F_181 ( struct V_164 * V_296 )
{
if ( ! V_296 )
return;
F_179 ( V_296 ) ;
F_10 ( V_296 ) ;
}
static char *
F_182 ( const struct V_164 * V_165 ,
const struct V_335 * V_336 )
{
char * V_450 , * V_453 ;
unsigned int V_454 = V_165 -> V_217 ? strlen ( V_165 -> V_217 ) : 0 ;
unsigned int V_455 = F_78 ( V_165 -> V_212 , V_323 + 1 ) ;
V_450 = F_75 ( V_455 + V_454 + 1 , V_140 ) ;
if ( V_450 == NULL )
return F_74 ( - V_161 ) ;
strncpy ( V_450 , V_165 -> V_212 , V_455 ) ;
V_453 = V_450 + V_455 ;
if ( V_454 ) {
strncpy ( V_453 , V_165 -> V_217 , V_454 ) ;
V_453 += V_454 ;
}
* V_453 = '\0' ;
F_183 ( V_450 , F_184 ( V_336 ) ) ;
F_4 ( 1 , L_294 , V_19 , V_450 ) ;
return V_450 ;
}
static int
F_185 ( int V_312 , struct V_7 * V_355 ,
struct V_164 * V_296 , struct V_335 * V_336 ,
int V_456 )
{
int V_3 ;
unsigned int V_457 = 0 ;
struct V_360 * V_458 = NULL ;
char * V_450 = NULL , * V_459 = NULL , * V_460 = NULL ;
V_450 = F_182 ( V_296 , V_336 ) ;
if ( F_114 ( V_450 ) )
return F_115 ( V_450 ) ;
V_459 = V_456 ? V_450 + 1 : V_296 -> V_212 + 1 ;
V_3 = F_156 ( V_312 , V_355 , V_459 , V_336 -> V_315 ,
& V_457 , & V_458 ,
V_336 -> V_346 & V_429 ) ;
if ( ! V_3 && V_457 > 0 ) {
char * V_461 = NULL ;
V_460 = F_186 ( V_336 -> V_162 ,
V_450 + 1 , V_458 ,
& V_461 ) ;
F_187 ( V_458 , V_457 ) ;
if ( F_114 ( V_460 ) ) {
V_3 = F_115 ( V_460 ) ;
V_460 = NULL ;
} else {
F_179 ( V_296 ) ;
memset ( V_296 , '\0' , sizeof( * V_296 ) ) ;
V_3 = F_188 ( V_296 , V_460 ,
V_461 ) ;
}
F_10 ( V_461 ) ;
F_10 ( V_336 -> V_162 ) ;
V_336 -> V_162 = V_460 ;
}
F_10 ( V_450 ) ;
return V_3 ;
}
static int
F_188 ( struct V_164 * V_296 , char * V_462 ,
const char * V_163 )
{
int V_3 = 0 ;
if ( F_76 ( V_462 , V_163 , V_296 ) )
return - V_55 ;
if ( V_296 -> V_199 ) {
F_4 ( 1 , L_295 ) ;
V_296 -> V_201 = F_86 ( 1 , V_140 ) ;
if ( V_296 -> V_201 == NULL )
return - V_161 ;
} else if ( V_296 -> V_201 ) {
F_4 ( 1 , L_296 , V_296 -> V_201 ) ;
} else {
F_189 ( L_297 ) ;
return - V_55 ;
}
if ( V_296 -> V_218 == NULL ) {
V_296 -> V_315 = F_190 () ;
} else {
V_296 -> V_315 = F_191 ( V_296 -> V_218 ) ;
if ( V_296 -> V_315 == NULL ) {
F_22 ( 1 , L_298 ,
V_296 -> V_218 ) ;
return - V_463 ;
}
}
return V_3 ;
}
struct V_164 *
F_192 ( char * V_462 , const char * V_163 )
{
int V_3 ;
struct V_164 * V_296 ;
V_296 = F_86 ( sizeof( struct V_164 ) , V_140 ) ;
if ( ! V_296 )
return F_74 ( - V_161 ) ;
V_3 = F_188 ( V_296 , V_462 , V_163 ) ;
if ( V_3 ) {
F_181 ( V_296 ) ;
V_296 = F_74 ( V_3 ) ;
}
return V_296 ;
}
int
F_193 ( struct V_335 * V_336 , struct V_164 * V_296 )
{
int V_3 = 0 ;
int V_312 ;
struct V_7 * V_355 ;
struct V_9 * V_10 ;
struct V_1 * V_464 ;
char * V_450 ;
struct V_329 * V_330 ;
#ifdef F_194
int V_465 = 0 ;
#endif
V_3 = F_195 ( & V_336 -> V_466 , L_72 , V_467 ) ;
if ( V_3 )
return V_3 ;
V_336 -> V_466 . V_468 = V_469 . V_468 ;
#ifdef F_194
V_470:
if ( V_465 ) {
if ( V_10 )
F_139 ( V_10 ) ;
else if ( V_355 )
F_127 ( V_355 ) ;
F_134 ( V_312 ) ;
}
#endif
V_10 = NULL ;
V_355 = NULL ;
V_464 = NULL ;
V_450 = NULL ;
V_330 = NULL ;
V_312 = F_128 () ;
V_464 = F_109 ( V_296 ) ;
if ( F_114 ( V_464 ) ) {
V_3 = F_115 ( V_464 ) ;
F_196 ( & V_336 -> V_466 ) ;
goto V_354;
}
V_355 = F_132 ( V_464 , V_296 ) ;
if ( F_114 ( V_355 ) ) {
V_3 = F_115 ( V_355 ) ;
V_355 = NULL ;
goto V_471;
}
V_10 = F_143 ( V_355 , V_296 ) ;
if ( F_114 ( V_10 ) ) {
V_3 = F_115 ( V_10 ) ;
V_10 = NULL ;
goto V_472;
}
if ( V_10 -> V_8 -> V_447 & V_449 ) {
F_169 ( V_312 , V_10 , V_336 , V_296 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_170 ( V_10 -> V_403 . V_404 ) &
V_409 ) ) {
V_3 = - V_473 ;
goto V_471;
}
} else
V_10 -> V_405 = 0 ;
if ( ! V_10 -> V_474 ) {
F_197 ( V_312 , V_10 ) ;
F_198 ( V_312 , V_10 ) ;
}
if ( ( V_10 -> V_405 == 0 ) && ( V_336 -> V_220 > ( 1024 * 127 ) ) ) {
V_336 -> V_220 = 1024 * 127 ;
F_4 ( V_414 , L_299 ) ;
}
if ( ! ( V_10 -> V_8 -> V_447 & V_475 ) )
V_336 -> V_220 = F_199 ( V_336 -> V_220 ,
( V_10 -> V_8 -> V_2 -> V_18 - V_115 ) ) ;
V_336 -> V_221 = F_175 ( V_10 , V_296 ) ;
V_472:
#ifdef F_194
if ( V_465 == 0 ) {
int V_476 = F_185 ( V_312 , V_355 , V_296 ,
V_336 , false ) ;
if ( ! V_476 ) {
V_465 ++ ;
goto V_470;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_450 = F_200 ( V_296 , V_336 , V_10 ) ;
if ( V_450 == NULL ) {
V_3 = - V_161 ;
goto V_471;
}
V_3 = F_176 ( V_312 , V_10 , V_336 , V_450 ) ;
if ( V_3 != 0 && V_3 != - V_477 ) {
F_10 ( V_450 ) ;
goto V_471;
}
F_10 ( V_450 ) ;
}
if ( V_3 == - V_477 ) {
#ifdef F_194
if ( V_465 > V_478 ) {
V_3 = - V_479 ;
goto V_471;
}
V_3 = F_185 ( V_312 , V_355 , V_296 , V_336 ,
true ) ;
if ( ! V_3 ) {
V_465 ++ ;
goto V_470;
}
goto V_471;
#else
V_3 = - V_452 ;
#endif
}
if ( V_3 )
goto V_471;
V_330 = F_86 ( sizeof *V_330 , V_140 ) ;
if ( V_330 == NULL ) {
V_3 = - V_161 ;
goto V_471;
}
V_330 -> V_480 = V_355 -> V_184 ;
V_330 -> V_481 = V_10 ;
V_330 -> V_334 = V_36 ;
F_201 ( V_482 , & V_330 -> V_333 ) ;
F_201 ( V_332 , & V_330 -> V_333 ) ;
V_336 -> V_337 = V_330 ;
F_2 ( & V_336 -> V_423 ) ;
F_202 ( & V_336 -> V_424 , V_330 ) ;
F_3 ( & V_336 -> V_423 ) ;
F_33 ( V_82 , & V_336 -> V_421 ,
V_483 ) ;
V_471:
if ( V_3 ) {
if ( V_10 )
F_139 ( V_10 ) ;
else if ( V_355 )
F_127 ( V_355 ) ;
else
F_103 ( V_464 ) ;
F_196 ( & V_336 -> V_466 ) ;
}
V_354:
F_134 ( V_312 ) ;
return V_3 ;
}
int
F_145 ( unsigned int V_312 , struct V_7 * V_8 ,
const char * V_484 , struct V_9 * V_10 ,
const struct V_357 * V_358 )
{
struct V_44 * V_142 ;
struct V_44 * V_485 ;
T_5 * V_45 ;
T_6 * V_486 ;
unsigned char * V_487 ;
int V_3 = 0 ;
int V_96 ;
T_1 V_488 , V_489 ;
if ( V_8 == NULL )
return - V_490 ;
V_142 = F_35 () ;
if ( V_142 == NULL )
return - V_161 ;
V_485 = V_142 ;
F_203 ( V_142 , V_491 ,
NULL , 4 ) ;
V_142 -> V_120 = F_204 ( V_8 -> V_2 ) ;
V_142 -> V_492 = V_8 -> V_493 ;
V_45 = ( T_5 * ) V_142 ;
V_486 = ( T_6 * ) V_485 ;
V_45 -> V_494 = 0xFF ;
V_45 -> V_327 = F_205 ( V_495 ) ;
V_487 = & V_45 -> V_496 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_288 & V_497 ) ) {
V_45 -> V_498 = F_205 ( 1 ) ;
* V_487 = 0 ;
V_487 ++ ;
} else {
V_45 -> V_498 = F_205 ( V_499 ) ;
#ifdef F_87
if ( ( V_279 & V_211 ) &&
( V_8 -> V_2 -> V_280 == V_281 ) )
F_206 ( V_10 -> V_202 , V_8 -> V_2 -> V_500 ,
V_8 -> V_2 -> V_288 &
V_501 ? true : false ,
V_487 ) ;
else
#endif
V_3 = F_207 ( V_10 -> V_202 , V_8 -> V_2 -> V_500 ,
V_487 ) ;
V_487 += V_499 ;
if ( V_8 -> V_447 & V_502 ) {
* V_487 = 0 ;
V_487 ++ ;
}
}
if ( V_8 -> V_2 -> V_288 &
( V_289 | V_290 ) )
V_142 -> V_503 |= V_504 ;
if ( V_8 -> V_447 & V_505 ) {
V_142 -> V_503 |= V_506 ;
}
if ( V_8 -> V_447 & V_507 ) {
V_142 -> V_503 |= V_508 ;
}
if ( V_8 -> V_447 & V_502 ) {
V_142 -> V_503 |= V_509 ;
V_96 =
F_208 ( ( V_510 * ) V_487 , V_484 ,
6 *
( + 256 ) , V_358 ) ;
V_487 += 2 * V_96 ;
V_487 += 2 ;
} else {
strcpy ( V_487 , V_484 ) ;
V_487 += strlen ( V_484 ) + 1 ;
}
strcpy ( V_487 , L_300 ) ;
V_487 += strlen ( L_300 ) ;
V_487 += 1 ;
V_489 = V_487 - & V_45 -> V_496 [ 0 ] ;
V_45 -> V_68 . V_72 = F_28 ( F_27 (
V_45 -> V_68 . V_72 ) + V_489 ) ;
V_45 -> V_511 = F_205 ( V_489 ) ;
V_3 = F_209 ( V_312 , V_8 , V_142 , V_485 , & V_96 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_512 ;
V_10 -> V_321 = V_151 ;
V_10 -> V_22 = false ;
V_10 -> V_513 = V_485 -> V_514 ;
V_487 = F_210 ( V_485 ) ;
V_488 = F_25 ( V_485 ) ;
V_96 = F_78 ( V_487 , V_488 - 2 ) ;
if ( V_142 -> V_503 & V_509 )
V_512 = true ;
else
V_512 = false ;
if ( V_96 == 3 ) {
if ( ( V_487 [ 0 ] == 'I' ) && ( V_487 [ 1 ] == 'P' ) &&
( V_487 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_301 ) ;
V_10 -> V_474 = 1 ;
}
} else if ( V_96 == 2 ) {
if ( ( V_487 [ 0 ] == 'A' ) && ( V_487 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_302 ) ;
}
}
V_487 += V_96 + 1 ;
V_488 -= ( V_96 + 1 ) ;
strncpy ( V_10 -> V_322 , V_484 , V_323 ) ;
F_10 ( V_10 -> V_515 ) ;
V_10 -> V_515 = F_211 ( V_487 ,
V_488 , V_512 ,
V_358 ) ;
F_4 ( 1 , L_303 , V_10 -> V_515 ) ;
if ( ( V_485 -> V_54 == 3 ) ||
( V_485 -> V_54 == 7 ) )
V_10 -> V_327 = F_212 ( V_486 -> V_516 ) ;
else
V_10 -> V_327 = 0 ;
F_4 ( 1 , L_304 , V_10 -> V_327 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_485 -> V_514 ;
}
F_66 ( V_142 ) ;
return V_3 ;
}
void
F_213 ( struct V_335 * V_336 )
{
struct V_517 * V_518 = & V_336 -> V_424 ;
struct V_519 * V_520 ;
struct V_329 * V_330 ;
F_105 ( & V_336 -> V_421 ) ;
F_2 ( & V_336 -> V_423 ) ;
while ( ( V_520 = F_214 ( V_518 ) ) ) {
V_330 = F_215 ( V_520 , struct V_329 , V_521 ) ;
F_155 ( V_330 ) ;
F_216 ( V_332 , & V_330 -> V_333 ) ;
F_217 ( V_520 , V_518 ) ;
F_3 ( & V_336 -> V_423 ) ;
F_147 ( V_330 ) ;
F_2 ( & V_336 -> V_423 ) ;
}
F_3 ( & V_336 -> V_423 ) ;
F_196 ( & V_336 -> V_466 ) ;
F_10 ( V_336 -> V_162 ) ;
F_218 ( V_336 -> V_315 ) ;
F_10 ( V_336 ) ;
}
int F_133 ( unsigned int V_312 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
V_3 = F_219 ( V_312 , V_8 ) ;
if ( V_3 == - V_101 ) {
V_3 = F_219 ( V_312 , V_8 ) ;
if ( V_3 == - V_101 )
V_3 = - V_522 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_151 ;
else
V_3 = - V_522 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_135 ( unsigned int V_312 , struct V_7 * V_8 ,
struct V_357 * V_523 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_447 = V_2 -> V_447 ;
if ( V_524 == 0 )
V_8 -> V_447 &= ( ~ V_449 ) ;
F_4 ( 1 , L_305 ,
V_2 -> V_288 , V_2 -> V_447 , V_2 -> V_525 ) ;
V_3 = F_220 ( V_312 , V_8 , V_523 ) ;
if ( V_3 ) {
F_22 ( 1 , L_306 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_526 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_526 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_526 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_307 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_313 = V_151 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_526 . V_33 ) ;
V_8 -> V_526 . V_33 = NULL ;
V_8 -> V_526 . V_34 = 0 ;
F_10 ( V_8 -> V_527 ) ;
V_8 -> V_527 = NULL ;
return V_3 ;
}
static struct V_9 *
F_221 ( struct V_335 * V_336 , T_7 V_528 )
{
struct V_9 * V_529 = F_222 ( V_336 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_164 * V_401 ;
char V_201 [ 28 ] ;
V_401 = F_86 ( sizeof( * V_401 ) , V_140 ) ;
if ( V_401 == NULL ) {
V_10 = F_74 ( - V_161 ) ;
goto V_354;
}
snprintf ( V_201 , sizeof( V_201 ) , L_308 , V_528 ) ;
V_401 -> V_201 = V_201 ;
V_401 -> V_315 = V_336 -> V_315 ;
V_401 -> V_184 = V_528 ;
V_401 -> V_183 = V_528 ;
V_401 -> V_212 = V_529 -> V_322 ;
V_401 -> V_227 = V_529 -> V_227 ;
V_401 -> V_233 = V_529 -> V_233 ;
V_401 -> V_246 = V_529 -> V_246 ;
V_401 -> V_232 = ! V_529 -> V_405 ;
V_401 -> V_205 = V_530 ;
F_2 ( & V_20 ) ;
++ V_529 -> V_8 -> V_2 -> V_293 ;
F_3 ( & V_20 ) ;
V_8 = F_132 ( V_529 -> V_8 -> V_2 , V_401 ) ;
if ( F_114 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_103 ( V_529 -> V_8 -> V_2 ) ;
goto V_354;
}
V_10 = F_143 ( V_8 , V_401 ) ;
if ( F_114 ( V_10 ) ) {
F_127 ( V_8 ) ;
goto V_354;
}
if ( V_8 -> V_447 & V_449 )
F_169 ( 0 , V_10 , NULL , V_401 ) ;
V_354:
F_10 ( V_401 ) ;
return V_10 ;
}
struct V_9 *
F_222 ( struct V_335 * V_336 )
{
return F_150 ( F_151 ( V_336 ) ) ;
}
static int
F_223 ( void * V_531 )
{
F_71 () ;
return F_70 ( V_147 ) ? - V_100 : 0 ;
}
static struct V_329 *
F_224 ( struct V_517 * V_518 , T_7 V_532 )
{
struct V_519 * V_520 = V_518 -> V_519 ;
struct V_329 * V_330 ;
while ( V_520 ) {
V_330 = F_215 ( V_520 , struct V_329 , V_521 ) ;
if ( V_330 -> V_480 > V_532 )
V_520 = V_520 -> V_533 ;
else if ( V_330 -> V_480 < V_532 )
V_520 = V_520 -> V_534 ;
else
return V_330 ;
}
return NULL ;
}
static void
F_202 ( struct V_517 * V_518 , struct V_329 * V_535 )
{
struct V_519 * * V_343 = & ( V_518 -> V_519 ) , * V_536 = NULL ;
struct V_329 * V_330 ;
while ( * V_343 ) {
V_330 = F_215 ( * V_343 , struct V_329 , V_521 ) ;
V_536 = * V_343 ;
if ( V_330 -> V_480 > V_535 -> V_480 )
V_343 = & ( ( * V_343 ) -> V_533 ) ;
else
V_343 = & ( ( * V_343 ) -> V_534 ) ;
}
F_225 ( & V_535 -> V_521 , V_536 , V_343 ) ;
F_226 ( & V_535 -> V_521 , V_518 ) ;
}
struct V_329 *
F_227 ( struct V_335 * V_336 )
{
int V_119 ;
T_7 V_528 = F_228 () ;
struct V_329 * V_330 , * V_537 ;
if ( ! ( V_336 -> V_346 & V_441 ) )
return F_155 ( F_151 ( V_336 ) ) ;
F_2 ( & V_336 -> V_423 ) ;
V_330 = F_224 ( & V_336 -> V_424 , V_528 ) ;
if ( V_330 )
F_155 ( V_330 ) ;
F_3 ( & V_336 -> V_423 ) ;
if ( V_330 == NULL ) {
V_537 = F_86 ( sizeof( * V_330 ) , V_140 ) ;
if ( V_537 == NULL )
return F_74 ( - V_161 ) ;
V_537 -> V_480 = V_528 ;
V_537 -> V_481 = F_74 ( - V_473 ) ;
F_201 ( V_538 , & V_537 -> V_333 ) ;
F_201 ( V_332 , & V_537 -> V_333 ) ;
F_155 ( V_537 ) ;
F_2 ( & V_336 -> V_423 ) ;
V_330 = F_224 ( & V_336 -> V_424 , V_528 ) ;
if ( V_330 ) {
F_155 ( V_330 ) ;
F_3 ( & V_336 -> V_423 ) ;
F_10 ( V_537 ) ;
goto V_539;
}
V_330 = V_537 ;
F_202 ( & V_336 -> V_424 , V_330 ) ;
F_3 ( & V_336 -> V_423 ) ;
} else {
V_539:
V_119 = F_229 ( & V_330 -> V_333 , V_538 ,
F_223 ,
V_155 ) ;
if ( V_119 ) {
F_147 ( V_330 ) ;
return F_74 ( V_119 ) ;
}
if ( ! F_114 ( V_330 -> V_481 ) )
return V_330 ;
if ( F_31 ( V_36 , V_330 -> V_334 + V_540 ) ) {
F_147 ( V_330 ) ;
return F_74 ( - V_473 ) ;
}
if ( F_230 ( V_538 , & V_330 -> V_333 ) )
goto V_539;
}
V_330 -> V_481 = F_221 ( V_336 , V_528 ) ;
F_216 ( V_538 , & V_330 -> V_333 ) ;
F_231 ( & V_330 -> V_333 , V_538 ) ;
if ( F_114 ( V_330 -> V_481 ) ) {
F_147 ( V_330 ) ;
return F_74 ( - V_473 ) ;
}
return V_330 ;
}
static void
V_422 ( struct V_75 * V_76 )
{
struct V_335 * V_336 = F_30 ( V_76 , struct V_335 ,
V_421 . V_76 ) ;
struct V_517 * V_518 = & V_336 -> V_424 ;
struct V_519 * V_520 = F_214 ( V_518 ) ;
struct V_519 * V_5 ;
struct V_329 * V_330 ;
F_2 ( & V_336 -> V_423 ) ;
V_520 = F_214 ( V_518 ) ;
while ( V_520 != NULL ) {
V_5 = V_520 ;
V_520 = F_232 ( V_5 ) ;
V_330 = F_215 ( V_5 , struct V_329 , V_521 ) ;
if ( F_149 ( V_482 , & V_330 -> V_333 ) ||
F_49 ( & V_330 -> V_331 ) != 0 ||
F_58 ( V_330 -> V_334 + V_483 , V_36 ) )
continue;
F_155 ( V_330 ) ;
F_216 ( V_332 , & V_330 -> V_333 ) ;
F_217 ( V_5 , V_518 ) ;
F_3 ( & V_336 -> V_423 ) ;
F_147 ( V_330 ) ;
F_2 ( & V_336 -> V_423 ) ;
}
F_3 ( & V_336 -> V_423 ) ;
F_33 ( V_82 , & V_336 -> V_421 ,
V_483 ) ;
}
