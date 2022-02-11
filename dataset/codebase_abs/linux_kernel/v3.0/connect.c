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
static int
F_34 ( struct V_1 * V_2 )
{
int V_83 ;
unsigned int V_84 , V_85 ;
struct V_44 * V_86 = NULL ;
struct V_44 * V_87 = NULL ;
struct V_44 * V_88 = NULL ;
struct V_89 V_90 ;
struct V_91 V_92 ;
struct V_93 * V_94 = V_2 -> V_26 ;
struct V_4 * V_5 , * V_6 ;
struct V_95 * V_96 = NULL ;
struct V_11 * V_12 ;
char V_97 ;
bool V_98 = false ;
bool V_99 ;
int V_100 ;
V_101 -> V_28 |= V_102 ;
F_4 ( 1 , L_17 , F_35 ( V_101 ) ) ;
V_83 = F_36 ( & V_103 ) ;
if ( V_83 > 1 )
F_37 ( V_104 , V_83 + V_105 ,
V_106 ) ;
F_38 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( V_87 == NULL ) {
V_87 = F_39 () ;
if ( ! V_87 ) {
F_22 ( 1 , L_18 ) ;
F_18 ( 3000 ) ;
continue;
}
} else if ( V_98 ) {
memset ( V_87 , 0 , sizeof( struct V_44 ) ) ;
}
if ( V_88 == NULL ) {
V_88 = F_40 () ;
if ( ! V_88 ) {
F_22 ( 1 , L_19 ) ;
F_18 ( 1000 ) ;
continue;
}
} else
memset ( V_88 , 0 , sizeof( struct V_44 ) ) ;
V_98 = false ;
V_99 = false ;
V_86 = V_88 ;
V_92 . V_107 = V_86 ;
V_92 . V_108 = 4 ;
V_90 . V_109 = NULL ;
V_90 . V_110 = 0 ;
V_84 = 4 ;
V_111:
if ( V_112 > 0 && V_2 -> V_15 == V_113 &&
F_41 ( V_36 , V_2 -> V_35 +
( V_112 * V_78 ) ) ) {
F_22 ( 1 , L_20
L_21 , V_2 -> V_81 ,
( V_112 * V_78 / V_79 ) ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
F_42 ( & V_2 -> V_114 ) ;
continue;
}
V_83 =
F_43 ( V_94 , & V_90 ,
& V_92 , 1 , V_84 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_4 ( 1 , L_22 ) ;
F_1 ( V_2 ) ;
F_4 ( 1 , L_23 ) ;
V_94 = V_2 -> V_26 ;
continue;
} else if ( V_83 == - V_115 ||
V_83 == - V_116 ||
V_83 == - V_117 ) {
F_18 ( 1 ) ;
if ( V_84 < 4 ) {
V_92 . V_107 = ( 4 - V_84 ) +
( char * ) V_86 ;
V_92 . V_108 = V_84 ;
V_90 . V_109 = NULL ;
V_90 . V_110 = 0 ;
goto V_111;
} else
continue;
} else if ( V_83 <= 0 ) {
F_4 ( 1 , L_24 ,
V_83 ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
F_42 ( & V_2 -> V_114 ) ;
continue;
} else if ( V_83 < V_84 ) {
F_4 ( 1 , L_25 ,
V_84 , V_83 ) ;
V_84 -= V_83 ;
F_18 ( 1 ) ;
goto V_111;
}
V_97 = * ( ( char * ) V_86 ) ;
V_84 = F_27 ( V_86 -> V_72 ) ;
F_4 ( 1 , L_26 , V_84 + 4 ) ;
if ( V_97 == ( char ) V_118 ) {
continue;
} else if ( V_97 == ( char ) V_119 ) {
F_4 ( 1 , L_27 ) ;
continue;
} else if ( V_97 == ( char ) V_120 ) {
F_4 ( 1 , L_28 ,
V_84 ) ;
F_18 ( 1000 ) ;
F_44 ( (struct V_121 * )
& V_2 -> V_122 , V_123 ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
F_42 ( & V_2 -> V_114 ) ;
continue;
} else if ( V_97 != ( char ) 0 ) {
F_22 ( 1 , L_29 ) ;
F_45 ( L_30 , ( char * ) V_86 ,
V_83 ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
continue;
}
if ( ( V_84 > V_73 + V_124 - 4 ) ||
( V_84 < sizeof( struct V_44 ) - 1 - 4 ) ) {
F_22 ( 1 , L_31 ,
V_83 , V_84 + 4 ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
F_42 ( & V_2 -> V_114 ) ;
continue;
}
V_100 = 0 ;
if ( V_84 > V_125 - 4 ) {
V_98 = true ;
memcpy ( V_87 , V_88 , 4 ) ;
V_86 = V_87 ;
}
V_83 = 0 ;
V_92 . V_107 = 4 + ( char * ) V_86 ;
V_92 . V_108 = V_84 ;
for ( V_85 = 0 ; V_85 < V_84 ;
V_85 += V_83 ) {
V_83 = F_43 ( V_94 , & V_90 , & V_92 , 1 ,
V_84 - V_85 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_100 = 2 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
V_100 = 1 ;
break;
} else if ( V_83 == - V_115 ||
V_83 == - V_116 ||
V_83 == - V_117 ) {
F_18 ( 1 ) ;
V_83 = 0 ;
continue;
} else if ( V_83 <= 0 ) {
F_22 ( 1 , L_32 ,
V_84 - V_85 ) ;
F_1 ( V_2 ) ;
V_94 = V_2 -> V_26 ;
V_100 = 1 ;
break;
}
}
if ( V_100 == 2 )
break;
else if ( V_100 == 1 )
continue;
V_85 += 4 ;
F_46 ( V_86 , V_85 ) ;
V_83 = F_47 ( V_86 , V_86 -> V_126 , V_85 ) ;
if ( V_83 != 0 )
F_45 ( L_33 , V_86 ,
F_48 (unsigned int, total_read, 48 ) ) ;
V_12 = NULL ;
V_2 -> V_35 = V_36 ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
if ( V_12 -> V_127 != V_86 -> V_126 ||
V_12 -> V_38 != V_39 ||
V_12 -> V_128 != V_86 -> V_52 ) {
V_12 = NULL ;
continue;
}
if ( V_83 == 0 &&
F_20 ( V_86 , V_2 -> V_18 ) > 0 ) {
V_99 = true ;
if ( V_12 -> V_129 ) {
V_83 = F_23 ( V_86 ,
V_12 -> V_129 ) ;
if ( V_83 > 0 ) {
V_83 = 0 ;
V_12 -> V_130 = true ;
break;
} else {
V_12 -> V_131 = true ;
goto V_132;
}
} else {
if ( ! V_98 ) {
F_22 ( 1 , L_34
L_35 ) ;
} else {
V_12 -> V_129 =
V_86 ;
V_12 -> V_133 = true ;
V_87 = NULL ;
}
}
break;
}
V_12 -> V_129 = V_86 ;
V_12 -> V_133 = V_98 ;
V_132:
if ( V_83 == 0 )
V_12 -> V_38 = V_134 ;
else
V_12 -> V_38 = V_135 ;
#ifdef F_49
V_12 -> V_136 = V_36 ;
#endif
F_15 ( & V_12 -> V_37 ) ;
break;
}
F_3 ( & V_14 ) ;
if ( V_12 != NULL ) {
V_12 -> V_41 ( V_12 ) ;
if ( ! V_99 ) {
if ( V_98 )
V_87 = NULL ;
else
V_88 = NULL ;
}
} else if ( V_83 != 0 ) {
continue;
} else if ( ! F_50 ( V_86 , V_2 ) &&
! V_99 ) {
F_22 ( 1 , L_36
L_37 , F_51 ( & V_137 ) ) ;
F_45 ( L_38 , ( char * ) V_86 ,
sizeof( struct V_44 ) ) ;
#ifdef F_52
F_53 ( V_86 ) ;
F_54 ( V_2 ) ;
#endif
}
}
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_138 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_55 ( & V_2 -> V_114 ) ;
F_2 ( & V_14 ) ;
if ( F_51 ( & V_2 -> V_139 ) >= V_140 )
F_56 ( & V_2 -> V_139 , V_140 - 1 ) ;
F_3 ( & V_14 ) ;
F_55 ( & V_2 -> V_141 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_94 ) ;
V_2 -> V_26 = NULL ;
}
F_57 ( V_87 ) ;
if ( V_88 )
F_58 ( V_88 ) ;
if ( ! F_59 ( & V_2 -> V_142 ) ) {
struct V_4 V_143 ;
F_12 ( & V_143 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_39 , V_12 -> V_127 ) ;
V_12 -> V_38 = V_144 ;
F_14 ( & V_12 -> V_37 , & V_143 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_40 , V_12 -> V_127 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_59 ( & V_2 -> V_142 ) ) {
F_4 ( 1 , L_41 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_81 ) ;
V_96 = F_60 ( & V_2 -> V_145 , NULL ) ;
F_10 ( V_2 ) ;
V_83 = F_61 ( & V_103 ) ;
if ( V_83 > 0 )
F_37 ( V_104 , V_83 + V_105 ,
V_106 ) ;
if ( ! V_96 ) {
F_62 ( V_146 ) ;
while ( ! F_63 ( V_101 ) ) {
F_64 () ;
F_62 ( V_146 ) ;
}
F_62 ( V_147 ) ;
}
F_65 ( 0 ) ;
}
static char *
F_66 ( const char * V_148 )
{
const char * V_149 ;
char * V_150 , * V_151 ;
unsigned int V_34 ;
V_149 = V_148 + 2 ;
V_151 = strchr ( V_149 , '\\' ) ;
if ( ! V_151 )
return F_67 ( - V_55 ) ;
V_34 = V_151 - V_149 ;
V_150 = F_68 ( ( V_34 + 1 ) , V_106 ) ;
if ( V_150 == NULL )
return F_67 ( - V_152 ) ;
memcpy ( V_150 , V_149 , V_34 ) ;
V_150 [ V_34 ] = '\0' ;
return V_150 ;
}
static int
F_69 ( const char * V_153 , const char * V_154 ,
struct V_155 * V_156 )
{
char * V_157 , * V_158 , * V_159 ;
char * V_160 = NULL , * V_161 ;
unsigned int V_162 , V_163 , V_164 ;
char V_165 [ 2 ] ;
short int V_166 = - 1 ;
short int V_167 = - 1 ;
bool V_168 = false ;
bool V_169 = false ;
char * V_170 = F_70 () -> V_170 ;
V_165 [ 0 ] = ',' ;
V_165 [ 1 ] = 0 ;
memset ( V_156 -> V_171 , 0x20 , V_172 ) ;
for ( V_163 = 0 ; V_163 < F_71 ( V_170 , V_172 ) ; V_163 ++ )
V_156 -> V_171 [ V_163 ] = toupper ( V_170 [ V_163 ] ) ;
V_156 -> V_171 [ V_172 ] = 0 ;
V_156 -> V_173 [ 0 ] = 0 ;
V_156 -> V_174 = F_72 () ;
V_156 -> V_175 = F_72 () ;
V_156 -> V_176 = F_73 () ;
V_156 -> V_177 = V_156 -> V_178 = V_179 | V_180 | V_181 ;
V_156 -> V_182 = 1 ;
V_156 -> V_183 = 1 ;
V_156 -> V_184 = V_185 ;
if ( ! V_153 )
goto V_186;
V_160 = F_74 ( V_153 , V_187 , V_106 ) ;
if ( ! V_160 )
goto V_186;
V_161 = V_160 ;
V_159 = V_161 + strlen ( V_161 ) ;
if ( strncmp ( V_161 , L_42 , 4 ) == 0 ) {
if ( V_161 [ 4 ] != 0 ) {
V_165 [ 0 ] = V_161 [ 4 ] ;
V_161 += 5 ;
} else {
F_4 ( 1 , L_43 ) ;
}
}
while ( ( V_158 = F_75 ( & V_161 , V_165 ) ) != NULL ) {
if ( ! * V_158 )
continue;
if ( ( V_157 = strchr ( V_158 , '=' ) ) != NULL )
* V_157 ++ = '\0' ;
if ( F_76 ( V_158 , L_44 , 10 ) == 0 ) {
V_156 -> V_188 = 0 ;
} else if ( F_76 ( V_158 , L_45 , 12 ) == 0 ) {
V_156 -> V_188 = 1 ;
} else if ( F_76 ( V_158 , L_46 , 4 ) == 0 ) {
if ( ! V_157 ) {
F_77 ( V_189
L_47 ) ;
goto V_186;
} else if ( ! * V_157 ) {
V_156 -> V_190 = 1 ;
}
if ( F_71 ( V_157 , V_191 ) <
V_191 ) {
V_156 -> V_192 = F_78 ( V_157 , V_106 ) ;
if ( ! V_156 -> V_192 ) {
F_77 ( V_189 L_48
L_49 ) ;
goto V_186;
}
} else {
F_77 ( V_189 L_50 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_51 , 4 ) == 0 ) {
if ( ! V_157 ) {
V_156 -> V_193 = NULL ;
continue;
} else if ( V_157 [ 0 ] == 0 ) {
if ( V_157 [ 1 ] != V_165 [ 0 ] ) {
V_156 -> V_193 = NULL ;
continue;
}
}
V_162 = strlen ( V_157 ) ;
if ( ( V_157 [ V_162 ] == 0 ) &&
( V_157 + V_162 < V_159 ) &&
( V_157 [ V_162 + 1 ] == V_165 [ 0 ] ) ) {
V_157 [ V_162 ] = V_165 [ 0 ] ;
V_162 += 2 ;
while ( V_157 [ V_162 ] != 0 ) {
if ( V_157 [ V_162 ] == V_165 [ 0 ] ) {
if ( V_157 [ V_162 + 1 ] ==
V_165 [ 0 ] ) {
V_162 ++ ;
} else {
break;
}
}
V_162 ++ ;
}
if ( V_157 [ V_162 ] == 0 ) {
V_161 = NULL ;
} else {
V_157 [ V_162 ] = 0 ;
V_161 = V_157 + V_162 + 1 ;
}
V_156 -> V_193 = F_79 ( V_162 , V_106 ) ;
if ( V_156 -> V_193 == NULL ) {
F_77 ( V_189 L_48
L_52 ) ;
goto V_186;
}
for ( V_163 = 0 , V_164 = 0 ; V_163 < V_162 ; V_163 ++ , V_164 ++ ) {
V_156 -> V_193 [ V_164 ] = V_157 [ V_163 ] ;
if ( V_157 [ V_163 ] == V_165 [ 0 ]
&& V_157 [ V_163 + 1 ] == V_165 [ 0 ] ) {
V_163 ++ ;
}
}
V_156 -> V_193 [ V_164 ] = 0 ;
} else {
V_156 -> V_193 = F_79 ( V_162 + 1 , V_106 ) ;
if ( V_156 -> V_193 == NULL ) {
F_77 ( V_189 L_48
L_52 ) ;
goto V_186;
}
strcpy ( V_156 -> V_193 , V_157 ) ;
}
} else if ( ! F_76 ( V_158 , L_53 , 2 ) ||
! F_76 ( V_158 , L_54 , 4 ) ) {
if ( ! V_157 || ! * V_157 ) {
V_156 -> V_194 = NULL ;
} else if ( F_71 ( V_157 , V_195 ) <
V_195 ) {
V_156 -> V_194 = F_78 ( V_157 , V_106 ) ;
if ( ! V_156 -> V_194 ) {
F_77 ( V_189 L_48
L_55 ) ;
goto V_186;
}
} else {
F_77 ( V_189 L_56
L_57 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_58 , 3 ) == 0 ) {
if ( ! V_157 || ! * V_157 ) {
F_22 ( 1 , L_59 ) ;
continue;
} else if ( F_76 ( V_157 , L_60 , 5 ) == 0 ) {
V_156 -> V_196 |= V_197 |
V_198 ;
} else if ( F_76 ( V_157 , L_61 , 5 ) == 0 ) {
F_22 ( 1 , L_62 ) ;
goto V_186;
} else if ( F_76 ( V_157 , L_63 , 4 ) == 0 ) {
V_156 -> V_196 |= V_197 ;
} else if ( F_76 ( V_157 , L_64 , 8 ) == 0 ) {
V_156 -> V_196 |= V_199 |
V_198 ;
} else if ( F_76 ( V_157 , L_65 , 7 ) == 0 ) {
V_156 -> V_196 |= V_199 ;
} else if ( F_76 ( V_157 , L_66 , 7 ) == 0 ) {
V_156 -> V_196 |= V_200 |
V_198 ;
} else if ( F_76 ( V_157 , L_67 , 6 ) == 0 ) {
V_156 -> V_196 |= V_200 ;
} else if ( F_76 ( V_157 , L_68 , 5 ) == 0 ) {
V_156 -> V_196 |= V_201 |
V_198 ;
} else if ( F_76 ( V_157 , L_69 , 4 ) == 0 ) {
V_156 -> V_196 |= V_201 ;
} else if ( F_76 ( V_157 , L_70 , 6 ) == 0 ) {
V_156 -> V_196 |= V_200 ;
#ifdef F_80
} else if ( F_76 ( V_157 , L_71 , 6 ) == 0 ) {
V_156 -> V_196 |= V_202 ;
#endif
} else if ( F_76 ( V_157 , L_72 , 4 ) == 0 ) {
V_156 -> V_190 = 1 ;
} else {
F_22 ( 1 , L_73 , V_157 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_74 , 3 ) == 0 ) {
if ( ! V_157 || ! * V_157 ) {
F_22 ( 1 , L_75
L_76 ) ;
} else if ( ( F_76 ( V_157 , L_77 , 4 ) == 0 ) ||
( F_76 ( V_157 , L_78 , 1 ) == 0 ) ) {
continue;
}
} else if ( ( F_76 ( V_158 , L_79 , 3 ) == 0 )
|| ( F_76 ( V_158 , L_80 , 6 ) == 0 )
|| ( F_76 ( V_158 , L_81 , 4 ) == 0 ) ) {
if ( ! V_157 || ! * V_157 ) {
F_77 ( V_189 L_82
L_83 ) ;
goto V_186;
}
if ( ( V_162 = F_71 ( V_157 , 300 ) ) < 300 ) {
V_156 -> V_203 = F_68 ( V_162 + 1 , V_106 ) ;
if ( V_156 -> V_203 == NULL )
goto V_186;
strcpy ( V_156 -> V_203 , V_157 ) ;
if ( strncmp ( V_156 -> V_203 , L_84 , 2 ) == 0 ) {
V_156 -> V_203 [ 0 ] = '\\' ;
V_156 -> V_203 [ 1 ] = '\\' ;
} else if ( strncmp ( V_156 -> V_203 , L_85 , 2 ) != 0 ) {
F_77 ( V_189
L_86
L_87 ) ;
goto V_186;
}
} else {
F_77 ( V_189 L_88 ) ;
goto V_186;
}
} else if ( ( F_76 ( V_158 , L_89 , 3 ) == 0 )
|| ( F_76 ( V_158 , L_90 , 5 ) == 0 ) ) {
if ( ! V_157 || ! * V_157 ) {
F_77 ( V_189 L_91 ) ;
goto V_186;
}
if ( F_71 ( V_157 , 256 ) < 256 ) {
V_156 -> V_204 = F_78 ( V_157 , V_106 ) ;
if ( ! V_156 -> V_204 ) {
F_77 ( V_189 L_48
L_92 ) ;
goto V_186;
}
F_4 ( 1 , L_93 ) ;
} else {
F_77 ( V_189 L_94
L_95 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_96 , 7 ) == 0 ) {
V_156 -> V_205 . V_206 = V_207 ;
if ( ! V_157 || ! * V_157 ) {
F_77 ( V_189 L_97
L_98 ) ;
goto V_186;
}
V_163 = F_81 ( (struct V_121 * ) & V_156 -> V_205 ,
V_157 , strlen ( V_157 ) ) ;
if ( V_163 == 0 ) {
F_77 ( V_189 L_99
L_100 ,
V_157 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_101 , 10 ) == 0 ) {
if ( ! V_157 || ! * V_157 ) {
F_77 ( V_189
L_102 ) ;
goto V_186;
}
if ( ( V_162 = F_71 ( V_157 , 1024 ) ) < 1024 ) {
if ( V_157 [ 0 ] != '/' )
V_162 ++ ;
V_156 -> V_208 = F_68 ( V_162 + 1 , V_106 ) ;
if ( V_156 -> V_208 == NULL )
goto V_186;
if ( V_157 [ 0 ] != '/' ) {
V_156 -> V_208 [ 0 ] = '/' ;
strcpy ( V_156 -> V_208 + 1 , V_157 ) ;
} else
strcpy ( V_156 -> V_208 , V_157 ) ;
F_4 ( 1 , L_103 , V_156 -> V_208 ) ;
} else {
F_77 ( V_189 L_104 ) ;
goto V_186;
}
} else if ( F_76 ( V_158 , L_105 , 9 ) == 0 ) {
if ( ! V_157 || ! * V_157 ) {
F_77 ( V_189 L_106
L_107 ) ;
goto V_186;
}
if ( F_71 ( V_157 , 65 ) < 65 ) {
if ( F_76 ( V_157 , L_108 , 7 ) ) {
V_156 -> V_209 = F_78 ( V_157 ,
V_106 ) ;
if ( ! V_156 -> V_209 ) {
F_77 ( V_189 L_109
L_110
L_111 ) ;
goto V_186;
}
}
F_4 ( 1 , L_112 , V_157 ) ;
} else {
F_77 ( V_189 L_113
L_114 ) ;
goto V_186;
}
} else if ( ! F_76 ( V_158 , L_115 , 3 ) && V_157 && * V_157 ) {
V_156 -> V_175 = F_82 ( V_157 , & V_157 , 0 ) ;
V_168 = true ;
} else if ( ! F_76 ( V_158 , L_116 , 5 ) && V_157 && * V_157 ) {
V_156 -> V_174 = F_82 ( V_157 , & V_157 , 0 ) ;
} else if ( ! F_76 ( V_158 , L_117 , 8 ) ) {
V_166 = 1 ;
} else if ( ! F_76 ( V_158 , L_118 , 10 ) ) {
V_166 = 0 ;
} else if ( ! F_76 ( V_158 , L_119 , 3 ) && V_157 && * V_157 ) {
V_156 -> V_176 = F_82 ( V_157 , & V_157 , 0 ) ;
V_169 = true ;
} else if ( ! F_76 ( V_158 , L_120 , 8 ) ) {
V_167 = 1 ;
} else if ( ! F_76 ( V_158 , L_121 , 10 ) ) {
V_167 = 0 ;
} else if ( F_76 ( V_158 , L_122 , 4 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_178 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_123 , 4 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_177 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_124 , 4 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_177 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_125 , 4 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_210 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_126 , 5 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_211 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_127 , 5 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_212 =
F_82 ( V_157 , & V_157 , 0 ) ;
}
} else if ( F_76 ( V_158 , L_128 , 5 ) == 0 ) {
if ( ! V_157 || ! * V_157 ) {
F_22 ( 1 , L_129 ) ;
continue;
} else if ( F_76 ( V_157 , L_130 , 11 ) == 0 ) {
V_156 -> V_213 = 1 ;
}
} else if ( F_76 ( V_158 , L_131 , 4 ) == 0 ) {
if ( ! V_157 || ! * V_157 || ( * V_157 == ' ' ) ) {
F_4 ( 1 , L_132 ) ;
} else {
memset ( V_156 -> V_171 , 0x20 ,
V_172 ) ;
for ( V_163 = 0 ; V_163 < V_172 ; V_163 ++ ) {
if ( V_157 [ V_163 ] == 0 )
break;
V_156 -> V_171 [ V_163 ] = V_157 [ V_163 ] ;
}
if ( V_163 == V_172 && V_157 [ V_163 ] != 0 )
F_77 ( V_189 L_133
L_134 ) ;
}
} else if ( F_76 ( V_158 , L_135 , 7 ) == 0 ) {
if ( ! V_157 || ! * V_157 || ( * V_157 == ' ' ) ) {
F_4 ( 1 , L_136 ) ;
} else {
memset ( V_156 -> V_173 , 0x20 ,
V_214 ) ;
for ( V_163 = 0 ; V_163 < 15 ; V_163 ++ ) {
if ( V_157 [ V_163 ] == 0 )
break;
else
V_156 -> V_173 [ V_163 ] =
V_157 [ V_163 ] ;
}
if ( V_163 == V_172 && V_157 [ V_163 ] != 0 )
F_77 ( V_189 L_137
L_138 ) ;
}
} else if ( F_76 ( V_158 , L_139 , 7 ) == 0 ) {
if ( V_157 && * V_157 ) {
V_156 -> V_184 = V_79 * F_82 ( V_157 ,
& V_157 , 0 ) ;
if ( V_156 -> V_184 > V_215 ) {
F_22 ( 1 , L_140
L_141 ) ;
goto V_186;
}
}
} else if ( F_76 ( V_158 , L_142 , 4 ) == 0 ) {
} else if ( F_76 ( V_158 , L_143 , 3 ) == 0 ) {
} else if ( F_76 ( V_158 , L_144 , 5 ) == 0 ) {
} else if ( F_76 ( V_158 , L_145 , 2 ) == 0 ) {
} else if ( F_76 ( V_158 , L_146 , 2 ) == 0 ) {
} else if ( F_76 ( V_158 , L_147 , 11 ) == 0 ) {
V_156 -> V_216 = 1 ;
} else if ( F_76 ( V_158 , L_148 , 10 ) == 0 ) {
V_156 -> V_217 = 1 ;
} else if ( ( F_76 ( V_158 , L_149 , 4 ) == 0 ) ||
( F_76 ( V_158 , L_150 , 6 ) == 0 ) ||
( F_76 ( V_158 , L_151 , 4 ) == 0 ) ||
( F_76 ( V_158 , L_152 , 6 ) == 0 ) ||
( F_76 ( V_158 , L_153 , 5 ) == 0 ) ||
( F_76 ( V_158 , L_154 , 6 ) == 0 ) ||
( F_76 ( V_158 , L_155 , 3 ) == 0 ) ) {
continue;
} else if ( F_76 ( V_158 , L_156 , 4 ) == 0 ) {
V_156 -> V_218 = 1 ;
} else if ( F_76 ( V_158 , L_157 , 4 ) == 0 ) {
V_156 -> V_218 = 0 ;
} else if ( F_76 ( V_158 , L_158 , 4 ) == 0 ) {
V_156 -> V_219 = 0 ;
} else if ( F_76 ( V_158 , L_159 , 6 ) == 0 ) {
V_156 -> V_219 = 1 ;
} else if ( F_76 ( V_158 , L_160 , 8 ) == 0 ) {
V_156 -> V_220 = 1 ;
} else if ( F_76 ( V_158 , L_161 , 10 ) == 0 ) {
V_156 -> V_220 = 0 ;
} else if ( F_76 ( V_158 , L_162 , 3 ) == 0 ) {
V_156 -> V_221 = 1 ;
} else if ( F_76 ( V_158 , L_163 , 5 ) == 0 ) {
V_156 -> V_221 = 0 ;
} else if ( F_76 ( V_158 , L_164 , 5 ) == 0 ) {
V_156 -> V_222 = 1 ;
} else if ( F_76 ( V_158 , L_165 , 10 ) == 0 ) {
V_156 -> V_182 = 1 ;
} else if ( F_76 ( V_158 , L_166 , 12 ) == 0 ) {
V_156 -> V_182 = 0 ;
} else if ( F_76 ( V_158 , L_167 , 6 ) == 0 ) {
V_156 -> V_223 = 1 ;
} else if ( F_76 ( V_158 , L_168 , 7 ) == 0 ) {
V_156 -> V_223 = 1 ;
} else if ( ( F_76 ( V_158 , L_169 , 6 ) == 0 ) ||
( F_76 ( V_158 , L_170 , 10 ) == 0 ) ) {
V_156 -> V_224 = 1 ;
} else if ( F_76 ( V_158 , L_171 , 4 ) == 0 ) {
} else if ( F_76 ( V_158 , L_172 , 6 ) == 0 ) {
} else if ( F_76 ( V_158 , L_173 , 7 ) == 0 ) {
} else if ( F_76 ( V_158 , L_174 , 3 ) == 0 ) {
V_156 -> V_225 = 0 ;
} else if ( ( F_76 ( V_158 , L_175 , 5 ) == 0 ) ||
( F_76 ( V_158 , L_176 , 6 ) == 0 ) ) {
V_156 -> V_225 = 1 ;
if ( V_156 -> V_178 ==
( V_226 & ~ ( V_227 | V_228 ) ) )
V_156 -> V_178 = V_226 ;
} else if ( F_76 ( V_158 , L_177 , 9 ) == 0 ) {
V_156 -> V_229 = 1 ;
} else if ( F_76 ( V_158 , L_178 , 7 ) == 0 ) {
V_156 -> V_230 = 1 ;
} else if ( F_76 ( V_158 , L_179 , 9 ) == 0 ) {
V_156 -> V_230 = 0 ;
} else if ( F_76 ( V_158 , L_180 , 7 ) == 0 ) {
V_156 -> V_231 = true ;
} else if ( F_76 ( V_158 , L_181 , 9 ) == 0 ) {
V_156 -> V_231 = false ;
} else if ( F_76 ( V_158 , L_182 , 6 ) == 0 ) {
V_156 -> V_218 = 0 ;
} else if ( F_76 ( V_158 , L_183 , 6 ) == 0 ) {
V_156 -> V_218 = 1 ;
} else if ( F_76 ( V_158 , L_184 , 6 ) == 0 ) {
V_156 -> V_232 = 0 ;
} else if ( F_76 ( V_158 , L_185 , 4 ) == 0 ) {
V_156 -> V_232 = 1 ;
} else if ( F_76 ( V_158 , L_186 , 12 ) == 0 ) {
V_156 -> V_233 = 1 ;
} else if ( F_76 ( V_158 , L_187 , 10 ) == 0 ) {
V_156 -> V_233 = 0 ;
} else if ( F_76 ( V_158 , L_188 , 7 ) == 0 ) {
V_156 -> V_183 = 1 ;
} else if ( F_76 ( V_158 , L_189 , 9 ) == 0 ) {
V_156 -> V_183 = 0 ;
} else if ( F_76 ( V_158 , L_190 , 4 ) == 0 ) {
V_156 -> V_234 = 1 ;
} else if ( F_76 ( V_158 , L_191 , 7 ) == 0 ) {
V_156 -> V_235 = 1 ;
} else if ( F_76 ( V_158 , L_192 , 9 ) == 0 ) {
V_156 -> V_235 = 0 ;
} else if ( F_76 ( V_158 , L_193 , 3 ) == 0 ) {
V_156 -> V_236 = 0 ;
} else if ( F_76 ( V_158 , L_194 , 5 ) == 0 ) {
V_156 -> V_236 = 1 ;
} else if ( F_76 ( V_158 , L_195 , 6 ) == 0 ) {
V_156 -> V_237 = 1 ;
} else if ( F_76 ( V_158 , L_196 , 4 ) == 0 ) {
V_156 -> V_196 |= V_198 ;
} else if ( F_76 ( V_158 , L_197 , 4 ) == 0 ) {
V_156 -> V_238 = 1 ;
} else if ( F_76 ( V_158 , L_198 , 6 ) == 0 ) {
V_156 -> V_239 = 1 ;
} else if ( F_76 ( V_158 , L_199 , 13 ) == 0 ) {
V_156 -> V_239 = 1 ;
} else if ( F_76 ( V_158 , L_200 , 11 ) == 0 ) {
V_156 -> V_240 = 1 ;
} else if ( F_76 ( V_158 , L_201 , 4 ) == 0 ) {
F_77 ( V_189 L_202
L_203
L_204 ) ;
} else if ( F_76 ( V_158 , L_205 , 3 ) == 0 ) {
#ifndef F_83
F_22 ( 1 , L_206
L_207 ) ;
goto V_186;
#endif
V_156 -> V_241 = true ;
} else if ( F_76 ( V_158 , L_208 , 10 ) == 0 ) {
V_156 -> V_242 = true ;
} else if ( F_76 ( V_158 , L_209 , 8 ) == 0 ) {
V_156 -> V_243 = true ;
} else
F_77 ( V_189 L_210 ,
V_158 ) ;
}
if ( V_156 -> V_203 == NULL ) {
if ( V_154 == NULL ) {
F_77 ( V_189 L_211
L_212 ) ;
goto V_186;
}
if ( ( V_162 = F_71 ( V_154 , 300 ) ) < 300 ) {
V_156 -> V_203 = F_68 ( V_162 + 1 , V_106 ) ;
if ( V_156 -> V_203 == NULL )
goto V_186;
strcpy ( V_156 -> V_203 , V_154 ) ;
if ( strncmp ( V_156 -> V_203 , L_84 , 2 ) == 0 ) {
V_156 -> V_203 [ 0 ] = '\\' ;
V_156 -> V_203 [ 1 ] = '\\' ;
} else if ( strncmp ( V_156 -> V_203 , L_85 , 2 ) != 0 ) {
F_77 ( V_189 L_213
L_214 ) ;
goto V_186;
}
V_157 = strpbrk ( V_156 -> V_203 + 2 , L_215 ) ;
if ( V_157 )
* V_157 = '\\' ;
} else {
F_77 ( V_189 L_88 ) ;
goto V_186;
}
}
if ( V_156 -> V_243 && ! ( V_156 -> V_196 & V_197 ) ) {
F_22 ( 1 , L_216
L_217 ) ;
goto V_186;
}
if ( V_156 -> V_194 == NULL )
V_156 -> V_194 = & V_156 -> V_203 [ 2 ] ;
if ( V_168 )
V_156 -> V_166 = V_166 ;
else if ( V_166 == 1 )
F_77 ( V_244 L_218
L_219 ) ;
if ( V_169 )
V_156 -> V_167 = V_167 ;
else if ( V_167 == 1 )
F_77 ( V_244 L_220
L_221 ) ;
F_10 ( V_160 ) ;
return 0 ;
V_186:
F_10 ( V_160 ) ;
return 1 ;
}
static bool
F_84 ( struct V_121 * V_205 , struct V_121 * V_245 )
{
switch ( V_205 -> V_246 ) {
case V_207 :
return ( V_245 -> V_246 == V_207 ) ;
case V_247 : {
struct V_248 * V_249 = (struct V_248 * ) V_205 ;
struct V_248 * V_250 = (struct V_248 * ) V_245 ;
return ( V_249 -> V_251 . V_252 == V_250 -> V_251 . V_252 ) ;
}
case V_253 : {
struct V_254 * V_255 = (struct V_254 * ) V_205 ;
struct V_254 * V_256 = (struct V_254 * ) & V_245 ;
return F_85 ( & V_255 -> V_257 , & V_256 -> V_257 ) ;
}
default:
F_86 ( 1 ) ;
return false ;
}
}
static bool
F_87 ( struct V_1 * V_2 , struct V_121 * V_258 )
{
T_2 V_210 , * V_259 ;
switch ( V_258 -> V_246 ) {
case V_247 :
V_259 = & ( (struct V_248 * ) & V_2 -> V_122 ) -> V_260 ;
V_210 = ( (struct V_248 * ) V_258 ) -> V_260 ;
break;
case V_253 :
V_259 = & ( (struct V_254 * ) & V_2 -> V_122 ) -> V_261 ;
V_210 = ( (struct V_254 * ) V_258 ) -> V_261 ;
break;
default:
F_86 ( 1 ) ;
return false ;
}
if ( ! V_210 ) {
V_210 = F_88 ( V_123 ) ;
if ( V_210 == * V_259 )
return true ;
V_210 = F_88 ( V_262 ) ;
}
return V_210 == * V_259 ;
}
static bool
F_89 ( struct V_1 * V_2 , struct V_121 * V_258 ,
struct V_121 * V_205 )
{
switch ( V_258 -> V_246 ) {
case V_247 : {
struct V_248 * V_263 = (struct V_248 * ) V_258 ;
struct V_248 * V_264 =
(struct V_248 * ) & V_2 -> V_122 ;
if ( V_263 -> V_251 . V_252 != V_264 -> V_251 . V_252 )
return false ;
break;
}
case V_253 : {
struct V_254 * V_265 = (struct V_254 * ) V_258 ;
struct V_254 * V_266 =
(struct V_254 * ) & V_2 -> V_122 ;
if ( ! F_85 ( & V_265 -> V_257 ,
& V_266 -> V_257 ) )
return false ;
if ( V_265 -> V_267 != V_266 -> V_267 )
return false ;
break;
}
default:
F_86 ( 1 ) ;
return false ;
}
if ( ! F_84 ( V_205 , (struct V_121 * ) & V_2 -> V_205 ) )
return false ;
return true ;
}
static bool
F_90 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
unsigned int V_268 ;
if ( V_156 -> V_196 & ( ~ ( V_198 | V_269 ) ) )
V_268 = V_156 -> V_196 ;
else
V_268 = V_270 | V_156 -> V_196 ;
switch ( V_2 -> V_271 ) {
case V_272 :
if ( ! ( V_268 & ( V_202 | V_273 ) ) )
return false ;
break;
case V_274 :
if ( ! ( V_268 & V_200 ) )
return false ;
break;
case V_275 :
if ( ! ( V_268 & V_201 ) )
return false ;
break;
case V_276 :
if ( ! ( V_268 & V_197 ) )
return false ;
break;
case V_277 :
if ( ! ( V_268 & V_199 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_268 & V_278 ) == 0 &&
( V_2 -> V_279 & V_280 ) )
return false ;
else if ( ( ( V_268 & V_198 ) == V_198 ) &&
( V_2 -> V_279 &
( V_281 | V_280 ) ) == 0 )
return false ;
return true ;
}
static int F_91 ( struct V_1 * V_2 , struct V_121 * V_258 ,
struct V_155 * V_156 )
{
if ( ! F_92 ( F_93 ( V_2 ) , V_101 -> V_282 -> V_283 ) )
return 0 ;
if ( ! F_89 ( V_2 , V_258 ,
(struct V_121 * ) & V_156 -> V_205 ) )
return 0 ;
if ( ! F_87 ( V_2 , V_258 ) )
return 0 ;
if ( ! F_90 ( V_2 , V_156 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_94 ( struct V_121 * V_258 , struct V_155 * V_156 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_95 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_91 ( V_2 , V_258 , V_156 ) )
continue;
++ V_2 -> V_284 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_222 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_96 ( struct V_1 * V_2 )
{
struct V_95 * V_285 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_284 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_97 ( F_93 ( V_2 ) ) ;
F_15 ( & V_2 -> V_138 ) ;
F_3 ( & V_20 ) ;
F_98 ( & V_2 -> V_77 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_285 = F_60 ( & V_2 -> V_145 , NULL ) ;
if ( V_285 )
F_101 ( V_286 , V_285 ) ;
}
static struct V_1 *
F_102 ( struct V_155 * V_287 )
{
struct V_1 * V_288 = NULL ;
struct V_289 V_258 ;
struct V_248 * V_290 = (struct V_248 * ) & V_258 ;
struct V_254 * V_291 = (struct V_254 * ) & V_258 ;
int V_3 ;
memset ( & V_258 , 0 , sizeof( struct V_289 ) ) ;
F_4 ( 1 , L_223 , V_287 -> V_203 , V_287 -> V_194 ) ;
if ( V_287 -> V_194 && V_287 -> V_203 ) {
V_3 = F_103 ( (struct V_121 * ) & V_258 ,
V_287 -> V_194 ,
strlen ( V_287 -> V_194 ) ,
V_287 -> V_210 ) ;
if ( ! V_3 ) {
V_3 = - V_55 ;
goto V_292;
}
} else if ( V_287 -> V_194 ) {
F_22 ( 1 , L_224 ) ;
V_3 = - V_55 ;
goto V_292;
} else {
F_22 ( 1 , L_225
L_226 ) ;
V_3 = - V_55 ;
goto V_292;
}
V_288 = F_94 ( (struct V_121 * ) & V_258 , V_287 ) ;
if ( V_288 )
return V_288 ;
V_288 = F_79 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_288 ) {
V_3 = - V_152 ;
goto V_292;
}
V_3 = F_104 ( V_288 ) ;
if ( V_3 ) {
F_22 ( 1 , L_227 , V_3 ) ;
goto V_292;
}
F_105 ( V_288 , F_106 ( V_101 -> V_282 -> V_283 ) ) ;
V_288 -> V_81 = F_66 ( V_287 -> V_203 ) ;
if ( F_107 ( V_288 -> V_81 ) ) {
V_3 = F_108 ( V_288 -> V_81 ) ;
goto V_293;
}
V_288 -> V_216 = V_287 -> V_216 ;
V_288 -> V_217 = V_287 -> V_217 ;
V_288 -> V_294 = V_287 -> V_213 ;
F_56 ( & V_288 -> V_139 , 0 ) ;
F_109 ( & V_288 -> V_114 ) ;
F_109 ( & V_288 -> V_141 ) ;
F_12 ( & V_288 -> V_142 ) ;
F_110 ( & V_288 -> V_25 ) ;
memcpy ( V_288 -> V_295 ,
V_287 -> V_171 , V_214 ) ;
memcpy ( V_288 -> V_296 ,
V_287 -> V_173 , V_214 ) ;
V_288 -> V_31 = false ;
V_288 -> V_30 = 0 ;
V_288 -> V_35 = V_36 ;
F_12 ( & V_288 -> V_138 ) ;
F_12 ( & V_288 -> V_21 ) ;
F_111 ( & V_288 -> V_77 , F_29 ) ;
V_288 -> V_15 = V_297 ;
memcpy ( & V_288 -> V_205 , & V_287 -> V_205 ,
sizeof( V_288 -> V_205 ) ) ;
++ V_288 -> V_284 ;
if ( V_258 . V_206 == V_253 ) {
F_4 ( 1 , L_228 ) ;
memcpy ( & V_288 -> V_122 , V_291 ,
sizeof( struct V_254 ) ) ;
} else
memcpy ( & V_288 -> V_122 , V_290 ,
sizeof( struct V_248 ) ) ;
V_3 = F_112 ( V_288 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_229 ) ;
goto V_293;
}
F_113 ( V_298 ) ;
V_288 -> V_145 = F_114 ( ( void * ) ( void * ) F_34 ,
V_288 , L_230 ) ;
if ( F_107 ( V_288 -> V_145 ) ) {
V_3 = F_108 ( V_288 -> V_145 ) ;
F_22 ( 1 , L_231 , V_3 ) ;
F_115 ( V_298 ) ;
goto V_293;
}
V_288 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_116 ( & V_288 -> V_138 , & V_299 ) ;
F_3 ( & V_20 ) ;
F_117 ( V_288 ) ;
F_33 ( V_82 , & V_288 -> V_77 , V_78 ) ;
return V_288 ;
V_293:
F_99 ( V_288 ) ;
F_97 ( F_93 ( V_288 ) ) ;
V_292:
if ( V_288 ) {
if ( ! F_107 ( V_288 -> V_81 ) )
F_10 ( V_288 -> V_81 ) ;
if ( V_288 -> V_26 )
F_9 ( V_288 -> V_26 ) ;
F_10 ( V_288 ) ;
}
return F_67 ( V_3 ) ;
}
static int F_118 ( struct V_7 * V_8 , struct V_155 * V_156 )
{
switch ( V_8 -> V_2 -> V_271 ) {
case V_276 :
if ( V_156 -> V_174 != V_8 -> V_174 )
return 0 ;
break;
default:
if ( V_8 -> V_300 == NULL )
return 0 ;
if ( strncmp ( V_8 -> V_300 , V_156 -> V_192 ,
V_191 ) )
return 0 ;
if ( strlen ( V_156 -> V_192 ) != 0 &&
V_8 -> V_193 != NULL &&
strncmp ( V_8 -> V_193 ,
V_156 -> V_193 ? V_156 -> V_193 : L_232 ,
V_301 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_119 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_95 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_118 ( V_8 , V_156 ) )
continue;
++ V_8 -> V_302 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_120 ( struct V_7 * V_8 )
{
int V_303 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_233 , V_19 , V_8 -> V_302 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_302 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_304 == V_113 ) {
V_303 = F_121 () ;
F_122 ( V_303 , V_8 ) ;
F_123 ( V_303 ) ;
}
F_124 ( V_8 ) ;
F_96 ( V_2 ) ;
}
static struct V_7 *
F_125 ( struct V_1 * V_2 , struct V_155 * V_287 )
{
int V_3 = - V_152 , V_303 ;
struct V_7 * V_8 ;
struct V_248 * V_258 = (struct V_248 * ) & V_2 -> V_122 ;
struct V_254 * V_265 = (struct V_254 * ) & V_2 -> V_122 ;
V_303 = F_121 () ;
V_8 = F_119 ( V_2 , V_287 ) ;
if ( V_8 ) {
F_4 ( 1 , L_234 , V_8 -> V_304 ) ;
F_7 ( & V_8 -> V_305 ) ;
V_3 = F_126 ( V_303 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_305 ) ;
F_120 ( V_8 ) ;
F_127 ( V_303 ) ;
return F_67 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_235 ) ;
V_3 = F_128 ( V_303 , V_8 ,
V_287 -> V_306 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_305 ) ;
F_120 ( V_8 ) ;
F_127 ( V_303 ) ;
return F_67 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_305 ) ;
F_96 ( V_2 ) ;
F_127 ( V_303 ) ;
return V_8 ;
}
F_4 ( 1 , L_236 ) ;
V_8 = F_129 () ;
if ( V_8 == NULL )
goto V_307;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_122 . V_206 == V_253 )
sprintf ( V_8 -> V_308 , L_237 , & V_265 -> V_257 ) ;
else
sprintf ( V_8 -> V_308 , L_238 , & V_258 -> V_251 ) ;
if ( V_287 -> V_192 ) {
V_8 -> V_300 = F_78 ( V_287 -> V_192 , V_106 ) ;
if ( ! V_8 -> V_300 )
goto V_307;
}
if ( V_287 -> V_193 ) {
V_8 -> V_193 = F_78 ( V_287 -> V_193 , V_106 ) ;
if ( ! V_8 -> V_193 )
goto V_307;
}
if ( V_287 -> V_204 ) {
V_8 -> V_309 = F_78 ( V_287 -> V_204 , V_106 ) ;
if ( ! V_8 -> V_309 )
goto V_307;
}
V_8 -> V_174 = V_287 -> V_174 ;
V_8 -> V_175 = V_287 -> V_175 ;
if ( ( V_287 -> V_196 == 0 ) && V_310 == false ) {
V_310 = true ;
F_22 ( 1 , L_239
L_240
L_241 ) ;
}
V_8 -> V_311 = V_287 -> V_196 ;
F_7 ( & V_8 -> V_305 ) ;
V_3 = F_126 ( V_303 , V_8 ) ;
if ( ! V_3 )
V_3 = F_128 ( V_303 , V_8 , V_287 -> V_306 ) ;
F_11 ( & V_8 -> V_305 ) ;
if ( V_3 )
goto V_307;
F_2 ( & V_20 ) ;
F_116 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_127 ( V_303 ) ;
return V_8 ;
V_307:
F_124 ( V_8 ) ;
F_127 ( V_303 ) ;
return F_67 ( V_3 ) ;
}
static int F_130 ( struct V_9 * V_10 , const char * V_148 )
{
if ( V_10 -> V_312 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_313 , V_148 , V_314 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_131 ( struct V_7 * V_8 , const char * V_148 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_130 ( V_10 , V_148 ) )
continue;
++ V_10 -> V_315 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_132 ( struct V_9 * V_10 )
{
int V_303 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_242 , V_19 , V_10 -> V_315 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_315 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_303 = F_121 () ;
F_133 ( V_303 , V_10 ) ;
F_123 ( V_303 ) ;
F_134 ( V_10 ) ;
F_135 ( V_10 ) ;
F_120 ( V_8 ) ;
}
static struct V_9 *
F_136 ( struct V_7 * V_8 , struct V_155 * V_287 )
{
int V_3 , V_303 ;
struct V_9 * V_10 ;
V_10 = F_131 ( V_8 , V_287 -> V_203 ) ;
if ( V_10 ) {
F_4 ( 1 , L_243 ) ;
F_120 ( V_8 ) ;
if ( V_10 -> V_238 != V_287 -> V_238 )
F_22 ( 1 , L_244
L_245 ) ;
return V_10 ;
}
V_10 = F_137 () ;
if ( V_10 == NULL ) {
V_3 = - V_152 ;
goto V_316;
}
V_10 -> V_8 = V_8 ;
if ( V_287 -> V_193 ) {
V_10 -> V_193 = F_78 ( V_287 -> V_193 , V_106 ) ;
if ( ! V_10 -> V_193 ) {
V_3 = - V_152 ;
goto V_316;
}
}
if ( strchr ( V_287 -> V_203 + 3 , '\\' ) == NULL
&& strchr ( V_287 -> V_203 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_246 ) ;
V_3 = - V_317 ;
goto V_316;
}
V_303 = F_121 () ;
V_3 = F_138 ( V_303 , V_8 , V_287 -> V_203 , V_10 , V_287 -> V_306 ) ;
F_127 ( V_303 ) ;
F_4 ( 1 , L_247 , V_3 ) ;
if ( V_3 )
goto V_316;
if ( V_287 -> V_222 ) {
V_10 -> V_318 &= ~ V_319 ;
F_4 ( 1 , L_248 , V_10 -> V_318 ) ;
}
V_10 -> V_238 = V_287 -> V_238 ;
V_10 -> V_218 = V_287 -> V_218 ;
V_10 -> V_224 = V_287 -> V_224 ;
V_10 -> V_237 = V_287 -> V_237 ;
F_2 ( & V_20 ) ;
F_116 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_139 ( V_10 ) ;
return V_10 ;
V_316:
F_135 ( V_10 ) ;
return F_67 ( V_3 ) ;
}
void
F_140 ( struct V_320 * V_321 )
{
if ( ! V_321 || F_107 ( V_321 ) )
return;
if ( ! F_141 ( & V_321 -> V_322 ) ||
F_142 ( V_323 , & V_321 -> V_324 ) ) {
V_321 -> V_325 = V_36 ;
return;
}
if ( ! F_107 ( F_143 ( V_321 ) ) )
F_132 ( F_143 ( V_321 ) ) ;
F_10 ( V_321 ) ;
return;
}
static inline struct V_320 *
F_144 ( struct V_326 * V_327 )
{
return V_327 -> V_328 ;
}
static int
F_145 ( struct V_329 * V_330 , struct V_331 * V_332 )
{
struct V_326 * V_333 = F_146 ( V_330 ) ;
struct V_326 * V_334 = V_332 -> V_327 ;
if ( ( V_330 -> V_335 & V_336 ) != ( V_332 -> V_28 & V_336 ) )
return 0 ;
if ( ( V_333 -> V_337 & V_338 ) !=
( V_334 -> V_337 & V_338 ) )
return 0 ;
if ( V_333 -> V_211 != V_334 -> V_211 )
return 0 ;
if ( V_334 -> V_212 && V_334 -> V_212 < V_333 -> V_212 )
return 0 ;
if ( V_333 -> V_339 != V_334 -> V_339 || V_333 -> V_340 != V_334 -> V_340 )
return 0 ;
if ( V_333 -> V_341 != V_334 -> V_341 ||
V_333 -> V_342 != V_334 -> V_342 )
return 0 ;
if ( strcmp ( V_333 -> V_306 -> V_343 , V_334 -> V_306 -> V_343 ) )
return 0 ;
if ( V_333 -> V_184 != V_334 -> V_184 )
return 0 ;
return 1 ;
}
int
F_147 ( struct V_329 * V_330 , void * V_158 )
{
struct V_331 * V_332 = (struct V_331 * ) V_158 ;
struct V_155 * V_287 ;
struct V_326 * V_327 ;
struct V_1 * V_344 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_320 * V_321 ;
struct V_289 V_258 ;
int V_3 = 0 ;
memset ( & V_258 , 0 , sizeof( struct V_289 ) ) ;
F_2 ( & V_20 ) ;
V_327 = F_146 ( V_330 ) ;
V_321 = F_148 ( F_144 ( V_327 ) ) ;
if ( F_107 ( V_321 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_143 ( V_321 ) ;
V_8 = V_10 -> V_8 ;
V_344 = V_8 -> V_2 ;
V_287 = V_332 -> V_156 ;
if ( ! V_287 -> V_194 || ! V_287 -> V_203 )
goto V_345;
V_3 = F_103 ( (struct V_121 * ) & V_258 ,
V_287 -> V_194 ,
strlen ( V_287 -> V_194 ) ,
V_287 -> V_210 ) ;
if ( ! V_3 )
goto V_345;
if ( ! F_91 ( V_344 , (struct V_121 * ) & V_258 , V_287 ) ||
! F_118 ( V_8 , V_287 ) ||
! F_130 ( V_10 , V_287 -> V_203 ) ) {
V_3 = 0 ;
goto V_345;
}
V_3 = F_145 ( V_330 , V_332 ) ;
V_345:
F_3 ( & V_20 ) ;
F_140 ( V_321 ) ;
return V_3 ;
}
int
F_149 ( int V_303 , struct V_7 * V_346 , const char * V_347 ,
const struct V_348 * V_349 , unsigned int * V_350 ,
struct V_351 * * V_352 , int V_220 )
{
char * V_353 ;
int V_3 = 0 ;
* V_350 = 0 ;
* V_352 = NULL ;
if ( V_346 -> V_23 == 0 ) {
V_353 = F_68 ( 2 +
F_71 ( V_346 -> V_308 ,
V_354 * 2 )
+ 1 + 4 + 2 ,
V_106 ) ;
if ( V_353 == NULL )
return - V_152 ;
V_353 [ 0 ] = '\\' ;
V_353 [ 1 ] = '\\' ;
strcpy ( V_353 + 2 , V_346 -> V_308 ) ;
strcpy ( V_353 + 2 + strlen ( V_346 -> V_308 ) , L_249 ) ;
V_3 = F_138 ( V_303 , V_346 , V_353 , NULL , V_349 ) ;
F_4 ( 1 , L_250 , V_3 , V_346 -> V_23 ) ;
F_10 ( V_353 ) ;
}
if ( V_3 == 0 )
V_3 = F_150 ( V_303 , V_346 , V_347 , V_352 ,
V_350 , V_349 , V_220 ) ;
return V_3 ;
}
static inline void
F_151 ( struct V_93 * V_355 )
{
struct V_355 * V_356 = V_355 -> V_356 ;
F_152 ( F_153 ( V_356 ) ) ;
F_154 ( V_356 , L_251 ,
& V_357 [ 0 ] , L_252 , & V_358 [ 0 ] ) ;
}
static inline void
F_155 ( struct V_93 * V_355 )
{
struct V_355 * V_356 = V_355 -> V_356 ;
F_152 ( F_153 ( V_356 ) ) ;
F_154 ( V_356 , L_253 ,
& V_357 [ 1 ] , L_254 , & V_358 [ 1 ] ) ;
}
static inline void
F_151 ( struct V_93 * V_355 )
{
}
static inline void
F_155 ( struct V_93 * V_355 )
{
}
static void F_156 ( char * V_359 , char * V_360 , unsigned int V_83 )
{
unsigned int V_163 , V_164 ;
for ( V_163 = 0 , V_164 = 0 ; V_163 < ( V_83 ) ; V_163 ++ ) {
V_359 [ V_164 ] = 'A' + ( 0x0F & ( V_360 [ V_163 ] >> 4 ) ) ;
V_359 [ V_164 + 1 ] = 'A' + ( 0x0F & V_360 [ V_163 ] ) ;
V_164 += 2 ;
}
}
static int
F_157 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_205 . V_206 != V_207 ) {
struct V_93 * V_93 = V_2 -> V_26 ;
V_3 = V_93 -> V_361 -> V_362 ( V_93 ,
(struct V_121 * ) & V_2 -> V_205 ,
sizeof( V_2 -> V_205 ) ) ;
if ( V_3 < 0 ) {
struct V_248 * V_249 ;
struct V_254 * V_255 ;
V_249 = (struct V_248 * ) & V_2 -> V_205 ;
V_255 = (struct V_254 * ) & V_2 -> V_205 ;
if ( V_255 -> V_363 == V_253 )
F_22 ( 1 , L_255
L_256 ,
& V_255 -> V_257 , V_3 ) ;
else
F_22 ( 1 , L_255
L_257 ,
& V_249 -> V_251 . V_252 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_158 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_364 * V_365 ;
struct V_44 * V_366 ;
V_365 = F_79 ( sizeof( struct V_364 ) ,
V_106 ) ;
if ( V_365 ) {
V_365 -> V_367 . V_368 . V_369 = 32 ;
if ( V_2 -> V_296 &&
V_2 -> V_296 [ 0 ] != 0 )
F_156 ( V_365 -> V_367 .
V_368 . V_370 ,
V_2 -> V_296 ,
V_214 ) ;
else
F_156 ( V_365 -> V_367 .
V_368 . V_370 ,
V_371 ,
V_214 ) ;
V_365 -> V_367 . V_368 . V_372 = 32 ;
if ( V_2 -> V_295 &&
V_2 -> V_295 [ 0 ] != 0 )
F_156 ( V_365 -> V_367 .
V_368 . V_373 ,
V_2 -> V_295 ,
V_214 ) ;
else
F_156 ( V_365 -> V_367 .
V_368 . V_373 ,
L_258 ,
V_214 ) ;
V_365 -> V_367 . V_368 . V_374 = 0 ;
V_365 -> V_367 . V_368 . V_375 = 0 ;
V_366 = (struct V_44 * ) V_365 ;
V_366 -> V_72 = F_28 ( 0x81000044 ) ;
V_3 = F_159 ( V_2 , V_366 , 0x44 ) ;
F_10 ( V_365 ) ;
F_160 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_2 V_259 ;
int V_376 , V_377 ;
struct V_93 * V_93 = V_2 -> V_26 ;
struct V_121 * V_378 ;
V_378 = (struct V_121 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_206 == V_253 ) {
V_259 = ( (struct V_254 * ) V_378 ) -> V_261 ;
V_376 = sizeof( struct V_254 ) ;
V_377 = V_253 ;
} else {
V_259 = ( (struct V_248 * ) V_378 ) -> V_260 ;
V_376 = sizeof( struct V_248 ) ;
V_377 = V_247 ;
}
if ( V_93 == NULL ) {
V_3 = F_161 ( F_93 ( V_2 ) , V_377 , V_379 ,
V_380 , & V_93 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_259 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_260 ) ;
V_2 -> V_26 = V_93 ;
V_93 -> V_356 -> V_381 = V_382 ;
if ( V_377 == V_253 )
F_155 ( V_93 ) ;
else
F_151 ( V_93 ) ;
}
V_3 = F_157 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_93 -> V_356 -> V_383 = 7 * V_79 ;
V_93 -> V_356 -> V_384 = 5 * V_79 ;
if ( V_2 -> V_217 ) {
if ( V_93 -> V_356 -> V_385 < ( 200 * 1024 ) )
V_93 -> V_356 -> V_385 = 200 * 1024 ;
if ( V_93 -> V_356 -> V_386 < ( 140 * 1024 ) )
V_93 -> V_356 -> V_386 = 140 * 1024 ;
}
if ( V_2 -> V_294 ) {
int V_387 = 1 ;
V_3 = F_162 ( V_93 , V_388 , V_389 ,
( char * ) & V_387 , sizeof( V_387 ) ) ;
if ( V_3 )
F_4 ( 1 , L_261 , V_3 ) ;
}
F_4 ( 1 , L_262 ,
V_93 -> V_356 -> V_385 ,
V_93 -> V_356 -> V_386 , V_93 -> V_356 -> V_383 ) ;
V_3 = V_93 -> V_361 -> V_390 ( V_93 , V_378 , V_376 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_263 , V_3 ) ;
F_9 ( V_93 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_259 == F_88 ( V_262 ) )
V_3 = F_158 ( V_2 ) ;
return V_3 ;
}
static int
F_112 ( struct V_1 * V_2 )
{
T_2 * V_259 ;
struct V_254 * V_265 = (struct V_254 * ) & V_2 -> V_122 ;
struct V_248 * V_258 = (struct V_248 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_206 == V_253 )
V_259 = & V_265 -> V_261 ;
else
V_259 = & V_258 -> V_260 ;
if ( * V_259 == 0 ) {
int V_3 ;
* V_259 = F_88 ( V_123 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_259 = F_88 ( V_262 ) ;
}
return F_17 ( V_2 ) ;
}
void F_163 ( int V_303 , struct V_9 * V_10 ,
struct V_326 * V_327 , struct V_155 * V_391 )
{
T_3 V_392 = F_164 ( V_10 -> V_393 . V_394 ) ;
if ( V_391 && V_391 -> V_223 ) {
V_10 -> V_393 . V_394 = 0 ;
V_10 -> V_395 = 0 ;
F_4 ( 1 , L_264 ) ;
return;
} else if ( V_391 )
V_10 -> V_395 = 1 ;
if ( V_10 -> V_395 == 0 ) {
F_4 ( 1 , L_265 ) ;
return;
}
if ( ! F_165 ( V_303 , V_10 ) ) {
T_3 V_396 = F_164 ( V_10 -> V_393 . V_394 ) ;
F_4 ( 1 , L_266 , V_396 ) ;
if ( V_391 == NULL ) {
if ( ( V_392 & V_397 ) == 0 )
V_396 &= ~ V_397 ;
if ( ( V_392 & V_398 ) == 0 ) {
if ( V_396 & V_398 )
F_22 ( 1 , L_267 ) ;
V_396 &= ~ V_398 ;
} else if ( ( V_396 & V_398 ) == 0 ) {
F_22 ( 1 , L_268 ) ;
F_22 ( 1 , L_269 ) ;
}
}
if ( V_396 & V_399 )
F_22 ( 1 , L_270 ) ;
V_396 &= V_400 ;
if ( V_391 && V_391 -> V_236 )
V_396 &= ~ V_397 ;
else if ( V_397 & V_396 ) {
F_4 ( 1 , L_271 ) ;
if ( V_327 )
V_327 -> V_337 |=
V_401 ;
}
if ( V_391 && V_391 -> V_182 == 0 )
V_396 &= ~ V_398 ;
else if ( V_396 & V_398 ) {
F_4 ( 1 , L_272 ) ;
if ( V_327 )
V_327 -> V_337 |=
V_402 ;
}
if ( V_327 && ( V_327 -> V_211 > 127 * 1024 ) ) {
if ( ( V_396 & V_403 ) == 0 ) {
V_327 -> V_211 = 127 * 1024 ;
F_4 ( V_404 , L_273 ) ;
}
}
F_4 ( 1 , L_274 , ( int ) V_396 ) ;
#ifdef F_52
if ( V_396 & V_405 )
F_4 ( 1 , L_275 ) ;
if ( V_396 & V_406 )
F_4 ( 1 , L_276 ) ;
if ( V_396 & V_398 )
F_4 ( 1 , L_277 ) ;
if ( V_396 & V_407 )
F_4 ( 1 , L_278 ) ;
if ( V_396 & V_397 )
F_4 ( 1 , L_279 ) ;
if ( V_396 & V_403 )
F_4 ( 1 , L_280 ) ;
if ( V_396 & V_408 )
F_4 ( 1 , L_281 ) ;
if ( V_396 & V_409 )
F_4 ( 1 , L_282 ) ;
if ( V_396 & V_399 )
F_4 ( 1 , L_283 ) ;
#endif
if ( F_166 ( V_303 , V_10 , V_396 ) ) {
if ( V_391 == NULL ) {
F_4 ( 1 , L_284 ) ;
} else
F_22 ( 1 , L_285
L_286
L_287
L_288
L_289
L_290 ) ;
}
}
}
void F_167 ( struct V_155 * V_410 ,
struct V_326 * V_327 )
{
F_111 ( & V_327 -> V_411 , V_412 ) ;
F_168 ( & V_327 -> V_413 ) ;
V_327 -> V_414 = V_415 ;
if ( V_410 -> V_211 > V_73 ) {
F_22 ( 1 , L_291 ,
V_410 -> V_211 ) ;
V_327 -> V_211 = V_73 ;
} else if ( ( V_410 -> V_211 ) &&
( V_410 -> V_211 <= V_73 ) )
V_327 -> V_211 = V_410 -> V_211 ;
else
V_327 -> V_211 = V_73 ;
if ( V_327 -> V_211 < 2048 ) {
V_327 -> V_211 = 2048 ;
F_4 ( 1 , L_292 ) ;
}
V_327 -> V_212 = V_410 -> V_212 ;
V_327 -> V_339 = V_410 -> V_175 ;
V_327 -> V_340 = V_410 -> V_176 ;
V_327 -> V_341 = V_410 -> V_178 ;
V_327 -> V_342 = V_410 -> V_177 ;
F_4 ( 1 , L_293 ,
V_327 -> V_341 , V_327 -> V_342 ) ;
V_327 -> V_184 = V_410 -> V_184 ;
V_327 -> V_306 = V_410 -> V_306 ;
if ( V_410 -> V_219 )
V_327 -> V_337 |= V_416 ;
if ( V_410 -> V_230 )
V_327 -> V_337 |= V_417 ;
if ( V_410 -> V_183 )
V_327 -> V_337 |= V_418 ;
if ( V_410 -> V_220 )
V_327 -> V_337 |= V_419 ;
if ( V_410 -> V_188 )
V_327 -> V_337 |= V_420 ;
if ( V_410 -> V_221 )
V_327 -> V_337 |= V_421 ;
if ( V_410 -> V_225 )
V_327 -> V_337 |= V_422 ;
if ( V_410 -> V_233 )
V_327 -> V_337 |= V_423 ;
if ( V_410 -> V_229 )
V_327 -> V_337 |= V_424 ;
if ( V_410 -> V_234 )
V_327 -> V_337 |= V_425 ;
if ( V_410 -> V_235 )
V_327 -> V_337 |= V_426 ;
if ( V_410 -> V_166 )
V_327 -> V_337 |= V_427 ;
if ( V_410 -> V_167 )
V_327 -> V_337 |= V_428 ;
if ( V_410 -> V_231 )
V_327 -> V_337 |= V_429 ;
if ( V_410 -> V_241 )
V_327 -> V_337 |= V_430 ;
if ( V_410 -> V_243 )
V_327 -> V_337 |= ( V_431 |
V_416 ) ;
if ( V_410 -> V_240 )
V_327 -> V_337 |= V_432 ;
if ( V_410 -> V_239 ) {
F_4 ( 1 , L_294 ) ;
V_327 -> V_337 |= V_433 ;
}
if ( V_410 -> V_242 ) {
if ( V_410 -> V_221 ) {
F_22 ( 1 , L_295
L_296 ) ;
} else {
V_327 -> V_337 |= V_434 ;
}
}
if ( ( V_410 -> V_235 ) && ( V_410 -> V_231 ) )
F_22 ( 1 , L_297
L_298 ) ;
}
static unsigned int
F_169 ( struct V_9 * V_10 , struct V_155 * V_410 )
{
T_3 V_435 = F_164 ( V_10 -> V_393 . V_394 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_212 = V_410 -> V_212 ? V_410 -> V_212 :
V_436 ;
if ( ! V_10 -> V_395 || ! ( V_435 & V_408 ) )
V_212 = F_48 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_437 & V_438 ) ||
( ! ( V_2 -> V_437 & V_439 ) &&
( V_2 -> V_279 & ( V_281 | V_280 ) ) ) )
V_212 = F_48 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_212 = F_48 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_212 ;
}
static int
F_170 ( int V_303 , struct V_9 * V_10 ,
struct V_326 * V_327 , const char * V_440 )
{
int V_3 ;
T_4 * V_441 ;
V_441 = F_68 ( sizeof( T_4 ) , V_106 ) ;
if ( V_441 == NULL )
return - V_152 ;
V_3 = F_171 ( V_303 , V_10 , V_440 , V_441 ,
0 , V_327 -> V_306 ,
V_327 -> V_337 &
V_419 ) ;
if ( V_3 == - V_442 || V_3 == - V_55 )
V_3 = F_172 ( V_303 , V_10 , V_440 , V_441 ,
V_327 -> V_306 , V_327 -> V_337 &
V_419 ) ;
F_10 ( V_441 ) ;
return V_3 ;
}
static void
F_173 ( struct V_155 * V_287 )
{
F_10 ( V_287 -> V_192 ) ;
F_174 ( V_287 -> V_193 ) ;
F_10 ( V_287 -> V_203 ) ;
F_10 ( V_287 -> V_194 ) ;
F_10 ( V_287 -> V_204 ) ;
F_10 ( V_287 -> V_209 ) ;
F_10 ( V_287 -> V_208 ) ;
}
void
F_175 ( struct V_155 * V_287 )
{
if ( ! V_287 )
return;
F_173 ( V_287 ) ;
F_10 ( V_287 ) ;
}
static char *
F_176 ( const struct V_155 * V_156 ,
const struct V_326 * V_327 )
{
char * V_440 , * V_443 ;
unsigned int V_444 = V_156 -> V_208 ? strlen ( V_156 -> V_208 ) : 0 ;
unsigned int V_445 = F_71 ( V_156 -> V_203 , V_314 + 1 ) ;
V_440 = F_68 ( V_445 + V_444 + 1 , V_106 ) ;
if ( V_440 == NULL )
return F_67 ( - V_152 ) ;
strncpy ( V_440 , V_156 -> V_203 , V_445 ) ;
V_443 = V_440 + V_445 ;
if ( V_444 ) {
strncpy ( V_443 , V_156 -> V_208 , V_444 ) ;
V_443 += V_444 ;
}
* V_443 = '\0' ;
F_177 ( V_440 , F_178 ( V_327 ) ) ;
F_4 ( 1 , L_299 , V_19 , V_440 ) ;
return V_440 ;
}
static int
F_179 ( int V_303 , struct V_7 * V_346 ,
struct V_155 * V_287 , struct V_326 * V_327 ,
int V_446 )
{
int V_3 ;
unsigned int V_447 = 0 ;
struct V_351 * V_448 = NULL ;
char * V_440 = NULL , * V_449 = NULL , * V_450 = NULL ;
V_440 = F_176 ( V_287 , V_327 ) ;
if ( F_107 ( V_440 ) )
return F_108 ( V_440 ) ;
V_449 = V_446 ? V_440 + 1 : V_287 -> V_203 + 1 ;
V_3 = F_149 ( V_303 , V_346 , V_449 , V_327 -> V_306 ,
& V_447 , & V_448 ,
V_327 -> V_337 & V_419 ) ;
if ( ! V_3 && V_447 > 0 ) {
char * V_451 = NULL ;
V_450 = F_180 ( V_327 -> V_153 ,
V_440 + 1 , V_448 ,
& V_451 ) ;
F_181 ( V_448 , V_447 ) ;
if ( F_107 ( V_450 ) ) {
V_3 = F_108 ( V_450 ) ;
V_450 = NULL ;
} else {
F_173 ( V_287 ) ;
memset ( V_287 , '\0' , sizeof( * V_287 ) ) ;
V_3 = F_182 ( V_287 , V_450 ,
V_451 ) ;
}
F_10 ( V_451 ) ;
F_10 ( V_327 -> V_153 ) ;
V_327 -> V_153 = V_450 ;
}
F_10 ( V_440 ) ;
return V_3 ;
}
static int
F_182 ( struct V_155 * V_287 , char * V_452 ,
const char * V_154 )
{
int V_3 = 0 ;
if ( F_69 ( V_452 , V_154 , V_287 ) )
return - V_55 ;
if ( V_287 -> V_190 ) {
F_4 ( 1 , L_300 ) ;
V_287 -> V_192 = F_79 ( 1 , V_106 ) ;
if ( V_287 -> V_192 == NULL )
return - V_152 ;
} else if ( V_287 -> V_192 ) {
F_4 ( 1 , L_301 , V_287 -> V_192 ) ;
} else {
F_183 ( L_302 ) ;
return - V_55 ;
}
if ( V_287 -> V_209 == NULL ) {
V_287 -> V_306 = F_184 () ;
} else {
V_287 -> V_306 = F_185 ( V_287 -> V_209 ) ;
if ( V_287 -> V_306 == NULL ) {
F_22 ( 1 , L_303 ,
V_287 -> V_209 ) ;
return - V_453 ;
}
}
return V_3 ;
}
struct V_155 *
F_186 ( char * V_452 , const char * V_154 )
{
int V_3 ;
struct V_155 * V_287 ;
V_287 = F_79 ( sizeof( struct V_155 ) , V_106 ) ;
if ( ! V_287 )
return F_67 ( - V_152 ) ;
V_3 = F_182 ( V_287 , V_452 , V_154 ) ;
if ( V_3 ) {
F_175 ( V_287 ) ;
V_287 = F_67 ( V_3 ) ;
}
return V_287 ;
}
int
F_187 ( struct V_326 * V_327 , struct V_155 * V_287 )
{
int V_3 = 0 ;
int V_303 ;
struct V_7 * V_346 ;
struct V_9 * V_10 ;
struct V_1 * V_454 ;
char * V_440 ;
struct V_320 * V_321 ;
#ifdef F_188
int V_455 = 0 ;
#endif
V_3 = F_189 ( & V_327 -> V_456 , L_77 , V_457 ) ;
if ( V_3 )
return V_3 ;
V_327 -> V_456 . V_458 = V_459 . V_458 ;
#ifdef F_188
V_460:
if ( V_455 ) {
if ( V_10 )
F_132 ( V_10 ) ;
else if ( V_346 )
F_120 ( V_346 ) ;
F_127 ( V_303 ) ;
}
#endif
V_10 = NULL ;
V_346 = NULL ;
V_454 = NULL ;
V_440 = NULL ;
V_321 = NULL ;
V_303 = F_121 () ;
V_454 = F_102 ( V_287 ) ;
if ( F_107 ( V_454 ) ) {
V_3 = F_108 ( V_454 ) ;
F_190 ( & V_327 -> V_456 ) ;
goto V_345;
}
V_346 = F_125 ( V_454 , V_287 ) ;
if ( F_107 ( V_346 ) ) {
V_3 = F_108 ( V_346 ) ;
V_346 = NULL ;
goto V_461;
}
V_10 = F_136 ( V_346 , V_287 ) ;
if ( F_107 ( V_10 ) ) {
V_3 = F_108 ( V_10 ) ;
V_10 = NULL ;
goto V_462;
}
if ( V_10 -> V_8 -> V_437 & V_439 ) {
F_163 ( V_303 , V_10 , V_327 , V_287 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_164 ( V_10 -> V_393 . V_394 ) &
V_399 ) ) {
V_3 = - V_463 ;
goto V_461;
}
} else
V_10 -> V_395 = 0 ;
if ( ! V_10 -> V_464 ) {
F_191 ( V_303 , V_10 ) ;
F_192 ( V_303 , V_10 ) ;
}
if ( ( V_10 -> V_395 == 0 ) && ( V_327 -> V_211 > ( 1024 * 127 ) ) ) {
V_327 -> V_211 = 1024 * 127 ;
F_4 ( V_404 , L_304 ) ;
}
if ( ! ( V_10 -> V_8 -> V_437 & V_465 ) )
V_327 -> V_211 = F_193 ( V_327 -> V_211 ,
( V_10 -> V_8 -> V_2 -> V_18 - V_124 ) ) ;
V_327 -> V_212 = F_169 ( V_10 , V_287 ) ;
V_462:
#ifdef F_188
if ( V_455 == 0 ) {
int V_466 = F_179 ( V_303 , V_346 , V_287 ,
V_327 , false ) ;
if ( ! V_466 ) {
V_455 ++ ;
goto V_460;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_440 = F_194 ( V_287 , V_327 , V_10 ) ;
if ( V_440 == NULL ) {
V_3 = - V_152 ;
goto V_461;
}
V_3 = F_170 ( V_303 , V_10 , V_327 , V_440 ) ;
if ( V_3 != 0 && V_3 != - V_467 ) {
F_10 ( V_440 ) ;
goto V_461;
}
F_10 ( V_440 ) ;
}
if ( V_3 == - V_467 ) {
#ifdef F_188
if ( V_455 > V_468 ) {
V_3 = - V_469 ;
goto V_461;
}
V_3 = F_179 ( V_303 , V_346 , V_287 , V_327 ,
true ) ;
if ( ! V_3 ) {
V_455 ++ ;
goto V_460;
}
goto V_461;
#else
V_3 = - V_442 ;
#endif
}
if ( V_3 )
goto V_461;
V_321 = F_79 ( sizeof *V_321 , V_106 ) ;
if ( V_321 == NULL ) {
V_3 = - V_152 ;
goto V_461;
}
V_321 -> V_470 = V_346 -> V_175 ;
V_321 -> V_471 = V_10 ;
V_321 -> V_325 = V_36 ;
F_195 ( V_472 , & V_321 -> V_324 ) ;
F_195 ( V_323 , & V_321 -> V_324 ) ;
V_327 -> V_328 = V_321 ;
F_2 ( & V_327 -> V_413 ) ;
F_196 ( & V_327 -> V_414 , V_321 ) ;
F_3 ( & V_327 -> V_413 ) ;
F_33 ( V_82 , & V_327 -> V_411 ,
V_473 ) ;
V_461:
if ( V_3 ) {
if ( V_10 )
F_132 ( V_10 ) ;
else if ( V_346 )
F_120 ( V_346 ) ;
else
F_96 ( V_454 ) ;
F_190 ( & V_327 -> V_456 ) ;
goto V_345;
}
V_345:
F_127 ( V_303 ) ;
return V_3 ;
}
int
F_138 ( unsigned int V_303 , struct V_7 * V_8 ,
const char * V_474 , struct V_9 * V_10 ,
const struct V_348 * V_349 )
{
struct V_44 * V_86 ;
struct V_44 * V_475 ;
T_5 * V_45 ;
T_6 * V_476 ;
unsigned char * V_477 ;
int V_3 = 0 ;
int V_83 ;
T_1 V_478 , V_479 ;
if ( V_8 == NULL )
return - V_480 ;
V_86 = F_39 () ;
if ( V_86 == NULL )
return - V_152 ;
V_475 = V_86 ;
F_197 ( V_86 , V_481 ,
NULL , 4 ) ;
V_86 -> V_126 = F_198 ( V_8 -> V_2 ) ;
V_86 -> V_482 = V_8 -> V_483 ;
V_45 = ( T_5 * ) V_86 ;
V_476 = ( T_6 * ) V_475 ;
V_45 -> V_484 = 0xFF ;
V_45 -> V_318 = F_199 ( V_485 ) ;
V_477 = & V_45 -> V_486 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_279 & V_487 ) ) {
V_45 -> V_488 = F_199 ( 1 ) ;
* V_477 = 0 ;
V_477 ++ ;
} else {
V_45 -> V_488 = F_199 ( V_489 ) ;
#ifdef F_80
if ( ( V_270 & V_202 ) &&
( V_8 -> V_2 -> V_271 == V_272 ) )
F_200 ( V_10 -> V_193 , V_8 -> V_2 -> V_490 ,
V_8 -> V_2 -> V_279 &
V_491 ? true : false ,
V_477 ) ;
else
#endif
V_3 = F_201 ( V_10 -> V_193 , V_8 -> V_2 -> V_490 ,
V_477 ) ;
V_477 += V_489 ;
if ( V_8 -> V_437 & V_492 ) {
* V_477 = 0 ;
V_477 ++ ;
}
}
if ( V_8 -> V_2 -> V_279 &
( V_280 | V_281 ) )
V_86 -> V_493 |= V_494 ;
if ( V_8 -> V_437 & V_495 ) {
V_86 -> V_493 |= V_496 ;
}
if ( V_8 -> V_437 & V_497 ) {
V_86 -> V_493 |= V_498 ;
}
if ( V_8 -> V_437 & V_492 ) {
V_86 -> V_493 |= V_499 ;
V_83 =
F_202 ( ( V_500 * ) V_477 , V_474 ,
6 *
( + 256 ) , V_349 ) ;
V_477 += 2 * V_83 ;
V_477 += 2 ;
} else {
strcpy ( V_477 , V_474 ) ;
V_477 += strlen ( V_474 ) + 1 ;
}
strcpy ( V_477 , L_305 ) ;
V_477 += strlen ( L_305 ) ;
V_477 += 1 ;
V_479 = V_477 - & V_45 -> V_486 [ 0 ] ;
V_45 -> V_68 . V_72 = F_28 ( F_27 (
V_45 -> V_68 . V_72 ) + V_479 ) ;
V_45 -> V_501 = F_199 ( V_479 ) ;
V_3 = F_203 ( V_303 , V_8 , V_86 , V_475 , & V_83 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_502 ;
V_10 -> V_312 = V_113 ;
V_10 -> V_22 = false ;
V_10 -> V_503 = V_475 -> V_504 ;
V_477 = F_204 ( V_475 ) ;
V_478 = F_25 ( V_475 ) ;
V_83 = F_71 ( V_477 , V_478 - 2 ) ;
if ( V_86 -> V_493 & V_499 )
V_502 = true ;
else
V_502 = false ;
if ( V_83 == 3 ) {
if ( ( V_477 [ 0 ] == 'I' ) && ( V_477 [ 1 ] == 'P' ) &&
( V_477 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_306 ) ;
V_10 -> V_464 = 1 ;
}
} else if ( V_83 == 2 ) {
if ( ( V_477 [ 0 ] == 'A' ) && ( V_477 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_307 ) ;
}
}
V_477 += V_83 + 1 ;
V_478 -= ( V_83 + 1 ) ;
strncpy ( V_10 -> V_313 , V_474 , V_314 ) ;
F_10 ( V_10 -> V_505 ) ;
V_10 -> V_505 = F_205 ( V_477 ,
V_478 , V_502 ,
V_349 ) ;
F_4 ( 1 , L_308 , V_10 -> V_505 ) ;
if ( ( V_475 -> V_54 == 3 ) ||
( V_475 -> V_54 == 7 ) )
V_10 -> V_318 = F_206 ( V_476 -> V_506 ) ;
else
V_10 -> V_318 = 0 ;
F_4 ( 1 , L_309 , V_10 -> V_318 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_475 -> V_504 ;
}
F_57 ( V_86 ) ;
return V_3 ;
}
void
F_207 ( struct V_326 * V_327 )
{
struct V_507 * V_508 = & V_327 -> V_414 ;
struct V_509 * V_510 ;
struct V_320 * V_321 ;
F_98 ( & V_327 -> V_411 ) ;
F_2 ( & V_327 -> V_413 ) ;
while ( ( V_510 = F_208 ( V_508 ) ) ) {
V_321 = F_209 ( V_510 , struct V_320 , V_511 ) ;
F_148 ( V_321 ) ;
F_210 ( V_323 , & V_321 -> V_324 ) ;
F_211 ( V_510 , V_508 ) ;
F_3 ( & V_327 -> V_413 ) ;
F_140 ( V_321 ) ;
F_2 ( & V_327 -> V_413 ) ;
}
F_3 ( & V_327 -> V_413 ) ;
F_190 ( & V_327 -> V_456 ) ;
F_10 ( V_327 -> V_153 ) ;
F_212 ( V_327 -> V_306 ) ;
F_10 ( V_327 ) ;
}
int F_126 ( unsigned int V_303 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
V_3 = F_213 ( V_303 , V_8 ) ;
if ( V_3 == - V_116 ) {
V_3 = F_213 ( V_303 , V_8 ) ;
if ( V_3 == - V_116 )
V_3 = - V_512 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_113 ;
else
V_3 = - V_512 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_128 ( unsigned int V_303 , struct V_7 * V_8 ,
struct V_348 * V_513 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_437 = V_2 -> V_437 ;
if ( V_514 == 0 )
V_8 -> V_437 &= ( ~ V_439 ) ;
F_4 ( 1 , L_310 ,
V_2 -> V_279 , V_2 -> V_437 , V_2 -> V_515 ) ;
V_3 = F_214 ( V_303 , V_8 , V_513 ) ;
if ( V_3 ) {
F_22 ( 1 , L_311 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_516 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_516 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_516 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_312 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_304 = V_113 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_516 . V_33 ) ;
V_8 -> V_516 . V_33 = NULL ;
V_8 -> V_516 . V_34 = 0 ;
F_10 ( V_8 -> V_517 ) ;
V_8 -> V_517 = NULL ;
return V_3 ;
}
static struct V_9 *
F_215 ( struct V_326 * V_327 , T_7 V_518 )
{
struct V_9 * V_519 = F_216 ( V_327 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_155 * V_391 ;
char V_192 [ 28 ] ;
V_391 = F_79 ( sizeof( * V_391 ) , V_106 ) ;
if ( V_391 == NULL ) {
V_10 = F_67 ( - V_152 ) ;
goto V_345;
}
snprintf ( V_192 , sizeof( V_192 ) , L_313 , V_518 ) ;
V_391 -> V_192 = V_192 ;
V_391 -> V_306 = V_327 -> V_306 ;
V_391 -> V_175 = V_518 ;
V_391 -> V_174 = V_518 ;
V_391 -> V_203 = V_519 -> V_313 ;
V_391 -> V_218 = V_519 -> V_218 ;
V_391 -> V_224 = V_519 -> V_224 ;
V_391 -> V_237 = V_519 -> V_237 ;
V_391 -> V_223 = ! V_519 -> V_395 ;
V_391 -> V_196 = V_520 ;
F_2 ( & V_20 ) ;
++ V_519 -> V_8 -> V_2 -> V_284 ;
F_3 ( & V_20 ) ;
V_8 = F_125 ( V_519 -> V_8 -> V_2 , V_391 ) ;
if ( F_107 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_96 ( V_519 -> V_8 -> V_2 ) ;
goto V_345;
}
V_10 = F_136 ( V_8 , V_391 ) ;
if ( F_107 ( V_10 ) ) {
F_120 ( V_8 ) ;
goto V_345;
}
if ( V_8 -> V_437 & V_439 )
F_163 ( 0 , V_10 , NULL , V_391 ) ;
V_345:
F_10 ( V_391 ) ;
return V_10 ;
}
struct V_9 *
F_216 ( struct V_326 * V_327 )
{
return F_143 ( F_144 ( V_327 ) ) ;
}
static int
F_217 ( void * V_521 )
{
F_64 () ;
return F_63 ( V_101 ) ? - V_115 : 0 ;
}
static struct V_320 *
F_218 ( struct V_507 * V_508 , T_7 V_522 )
{
struct V_509 * V_510 = V_508 -> V_509 ;
struct V_320 * V_321 ;
while ( V_510 ) {
V_321 = F_209 ( V_510 , struct V_320 , V_511 ) ;
if ( V_321 -> V_470 > V_522 )
V_510 = V_510 -> V_523 ;
else if ( V_321 -> V_470 < V_522 )
V_510 = V_510 -> V_524 ;
else
return V_321 ;
}
return NULL ;
}
static void
F_196 ( struct V_507 * V_508 , struct V_320 * V_525 )
{
struct V_509 * * V_334 = & ( V_508 -> V_509 ) , * V_526 = NULL ;
struct V_320 * V_321 ;
while ( * V_334 ) {
V_321 = F_209 ( * V_334 , struct V_320 , V_511 ) ;
V_526 = * V_334 ;
if ( V_321 -> V_470 > V_525 -> V_470 )
V_334 = & ( ( * V_334 ) -> V_523 ) ;
else
V_334 = & ( ( * V_334 ) -> V_524 ) ;
}
F_219 ( & V_525 -> V_511 , V_526 , V_334 ) ;
F_220 ( & V_525 -> V_511 , V_508 ) ;
}
struct V_320 *
F_221 ( struct V_326 * V_327 )
{
int V_527 ;
T_7 V_518 = F_222 () ;
struct V_320 * V_321 , * V_528 ;
if ( ! ( V_327 -> V_337 & V_431 ) )
return F_148 ( F_144 ( V_327 ) ) ;
F_2 ( & V_327 -> V_413 ) ;
V_321 = F_218 ( & V_327 -> V_414 , V_518 ) ;
if ( V_321 )
F_148 ( V_321 ) ;
F_3 ( & V_327 -> V_413 ) ;
if ( V_321 == NULL ) {
V_528 = F_79 ( sizeof( * V_321 ) , V_106 ) ;
if ( V_528 == NULL )
return F_67 ( - V_152 ) ;
V_528 -> V_470 = V_518 ;
V_528 -> V_471 = F_67 ( - V_463 ) ;
F_195 ( V_529 , & V_528 -> V_324 ) ;
F_195 ( V_323 , & V_528 -> V_324 ) ;
F_148 ( V_528 ) ;
F_2 ( & V_327 -> V_413 ) ;
V_321 = F_218 ( & V_327 -> V_414 , V_518 ) ;
if ( V_321 ) {
F_148 ( V_321 ) ;
F_3 ( & V_327 -> V_413 ) ;
F_10 ( V_528 ) ;
goto V_530;
}
V_321 = V_528 ;
F_196 ( & V_327 -> V_414 , V_321 ) ;
F_3 ( & V_327 -> V_413 ) ;
} else {
V_530:
V_527 = F_223 ( & V_321 -> V_324 , V_529 ,
F_217 ,
V_146 ) ;
if ( V_527 ) {
F_140 ( V_321 ) ;
return F_67 ( V_527 ) ;
}
if ( ! F_107 ( V_321 -> V_471 ) )
return V_321 ;
if ( F_31 ( V_36 , V_321 -> V_325 + V_531 ) ) {
F_140 ( V_321 ) ;
return F_67 ( - V_463 ) ;
}
if ( F_224 ( V_529 , & V_321 -> V_324 ) )
goto V_530;
}
V_321 -> V_471 = F_215 ( V_327 , V_518 ) ;
F_210 ( V_529 , & V_321 -> V_324 ) ;
F_225 ( & V_321 -> V_324 , V_529 ) ;
if ( F_107 ( V_321 -> V_471 ) ) {
F_140 ( V_321 ) ;
return F_67 ( - V_463 ) ;
}
return V_321 ;
}
static void
V_412 ( struct V_75 * V_76 )
{
struct V_326 * V_327 = F_30 ( V_76 , struct V_326 ,
V_411 . V_76 ) ;
struct V_507 * V_508 = & V_327 -> V_414 ;
struct V_509 * V_510 = F_208 ( V_508 ) ;
struct V_509 * V_5 ;
struct V_320 * V_321 ;
F_2 ( & V_327 -> V_413 ) ;
V_510 = F_208 ( V_508 ) ;
while ( V_510 != NULL ) {
V_5 = V_510 ;
V_510 = F_226 ( V_5 ) ;
V_321 = F_209 ( V_5 , struct V_320 , V_511 ) ;
if ( F_142 ( V_472 , & V_321 -> V_324 ) ||
F_51 ( & V_321 -> V_322 ) != 0 ||
F_41 ( V_321 -> V_325 + V_473 , V_36 ) )
continue;
F_148 ( V_321 ) ;
F_210 ( V_323 , & V_321 -> V_324 ) ;
F_211 ( V_5 , V_508 ) ;
F_3 ( & V_327 -> V_413 ) ;
F_140 ( V_321 ) ;
F_2 ( & V_327 -> V_413 ) ;
}
F_3 ( & V_327 -> V_413 ) ;
F_33 ( V_82 , & V_327 -> V_411 ,
V_473 ) ;
}
