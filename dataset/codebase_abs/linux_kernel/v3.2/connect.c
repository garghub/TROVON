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
static int F_20 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
int V_48 ;
T_1 V_49 , V_50 ;
if ( V_45 -> V_51 != V_52 )
return 0 ;
if ( V_45 -> V_53 != 10 ) {
F_4 ( 1 , L_9 ) ;
return - V_54 ;
}
V_47 = (struct V_46 * ) V_45 ;
V_49 = F_21 ( & V_47 -> V_55 . V_56 ) ;
V_50 = F_21 ( & V_47 -> V_55 . V_57 ) ;
if ( V_49 == V_50 )
return 0 ;
else if ( V_49 < V_50 ) {
F_4 ( 1 , L_10 ,
V_49 , V_50 ) ;
return - V_54 ;
}
V_48 = V_49 - V_50 ;
F_4 ( 1 , L_11 ,
V_48 ) ;
if ( V_49 > V_58 ) {
F_22 ( 1 , L_12 ,
V_49 , V_58 ) ;
return - V_54 ;
}
return V_48 ;
}
static int F_23 ( struct V_44 * V_59 , struct V_44 * V_60 )
{
struct V_46 * V_61 = (struct V_46 * ) V_59 ;
struct V_46 * V_47 = (struct V_46 * ) V_60 ;
char * V_62 ;
char * V_63 ;
int V_48 ;
unsigned int V_64 , V_65 ;
T_1 V_49 , V_66 ;
V_49 = F_21 ( & V_47 -> V_55 . V_56 ) ;
if ( V_49 !=
F_21 ( & V_61 -> V_55 . V_56 ) )
F_4 ( 1 , L_13 ) ;
V_65 = F_21 ( & V_47 -> V_55 . V_57 ) ;
V_48 = V_49 - V_65 ;
if ( V_48 < 0 )
return - V_67 ;
if ( V_48 == 0 )
return 0 ;
V_66 = F_21 ( & V_61 -> V_55 . V_57 ) ;
if ( V_48 < V_66 ) {
F_4 ( 1 , L_14 ) ;
}
V_62 = ( char * ) & V_47 -> V_68 . V_69 +
F_21 ( & V_47 -> V_55 . V_70 ) ;
V_63 = ( char * ) & V_61 -> V_68 . V_69 +
F_21 ( & V_61 -> V_55 . V_70 ) ;
V_62 += V_65 ;
V_65 += V_66 ;
if ( V_65 > V_71 )
return - V_67 ;
F_24 ( V_65 , & V_47 -> V_55 . V_57 ) ;
V_64 = F_25 ( V_60 ) ;
V_64 += V_66 ;
if ( V_64 > V_71 )
return - V_67 ;
F_26 ( V_64 , V_60 ) ;
V_64 = F_27 ( V_60 -> V_72 ) ;
V_64 += V_66 ;
if ( V_64 > V_58 + V_73 - 4 )
return - V_74 ;
V_60 -> V_72 = F_28 ( V_64 ) ;
memcpy ( V_62 , V_63 , V_66 ) ;
if ( V_48 == V_66 ) {
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
F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_83 ) {
V_2 -> V_83 = ( char * ) F_35 () ;
if ( ! V_2 -> V_83 ) {
F_22 ( 1 , L_17 ) ;
F_18 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_84 ) {
memset ( V_2 -> V_83 , 0 , sizeof( struct V_44 ) ) ;
}
if ( ! V_2 -> V_85 ) {
V_2 -> V_85 = ( char * ) F_36 () ;
if ( ! V_2 -> V_85 ) {
F_22 ( 1 , L_18 ) ;
F_18 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_85 , 0 , sizeof( struct V_44 ) ) ;
}
return true ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
if ( V_86 > 0 && V_2 -> V_15 == V_87 &&
F_38 ( V_36 , V_2 -> V_35 +
( V_86 * V_78 ) ) ) {
F_22 ( 1 , L_19
L_20 , V_2 -> V_81 ,
( V_86 * V_78 / V_79 ) ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_88 ) ;
return true ;
}
return false ;
}
static unsigned int
F_40 ( struct V_89 * V_90 , struct V_89 * V_91 , unsigned int V_92 ,
T_2 V_93 )
{
T_2 V_94 = 0 ;
while ( V_93 || ! V_91 -> V_95 ) {
int V_96 = F_41 ( V_93 , V_91 -> V_95 ) ;
V_93 -= V_96 ;
V_94 += V_96 ;
if ( V_91 -> V_95 == V_94 ) {
V_91 ++ ;
V_92 -- ;
V_94 = 0 ;
}
}
memcpy ( V_90 , V_91 , sizeof( * V_91 ) * V_92 ) ;
V_90 -> V_97 += V_94 ;
V_90 -> V_95 -= V_94 ;
return V_92 ;
}
static struct V_89 *
F_42 ( struct V_1 * V_2 , unsigned int V_92 )
{
struct V_89 * V_98 ;
if ( V_2 -> V_91 && V_92 <= V_2 -> V_99 )
return V_2 -> V_91 ;
V_98 = F_43 ( sizeof( * V_98 ) * V_92 , V_100 ) ;
if ( V_98 ) {
F_10 ( V_2 -> V_91 ) ;
V_2 -> V_91 = V_98 ;
V_2 -> V_99 = V_92 ;
}
return V_98 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_89 * V_101 ,
unsigned int V_92 , unsigned int V_102 )
{
int V_103 = 0 ;
int V_104 ;
unsigned int V_105 ;
struct V_106 V_107 ;
struct V_89 * V_91 ;
V_91 = F_42 ( V_2 , V_92 ) ;
if ( ! V_91 )
return - V_108 ;
V_107 . V_109 = NULL ;
V_107 . V_110 = 0 ;
for ( V_104 = 0 ; V_102 ; V_104 += V_103 , V_102 -= V_103 ) {
F_16 () ;
if ( F_37 ( V_2 ) ) {
V_104 = - V_111 ;
break;
}
V_105 = F_40 ( V_91 , V_101 , V_92 , V_104 ) ;
V_103 = F_45 ( V_2 -> V_26 , & V_107 ,
V_91 , V_105 , V_102 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_104 = - V_112 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_104 = - V_111 ;
break;
} else if ( V_103 == - V_113 ||
V_103 == - V_111 ||
V_103 == - V_114 ) {
F_46 ( 1000 , 2000 ) ;
V_103 = 0 ;
continue;
} else if ( V_103 <= 0 ) {
F_4 ( 1 , L_21
L_22 , V_102 , V_103 ) ;
F_1 ( V_2 ) ;
V_104 = - V_111 ;
break;
}
}
return V_104 ;
}
int
F_47 ( struct V_1 * V_2 , char * V_115 ,
unsigned int V_102 )
{
struct V_89 V_91 ;
V_91 . V_97 = V_115 ;
V_91 . V_95 = V_102 ;
return F_44 ( V_2 , & V_91 , 1 , V_102 ) ;
}
static bool
F_48 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_116 :
return true ;
case V_117 :
F_4 ( 1 , L_23 ) ;
break;
case V_118 :
F_4 ( 1 , L_24 ) ;
break;
case V_119 :
F_4 ( 1 , L_25 ) ;
F_18 ( 1000 ) ;
F_49 ( (struct V_120 * ) & V_2 -> V_121 , V_122 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_88 ) ;
break;
default:
F_22 ( 1 , L_26 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
static struct V_11 *
F_50 ( struct V_1 * V_2 , struct V_44 * V_115 )
{
struct V_11 * V_123 ;
F_2 ( & V_14 ) ;
F_51 (mid, &server->pending_mid_q, qhead) {
if ( V_123 -> V_123 == V_115 -> V_124 &&
V_123 -> V_38 == V_39 &&
V_123 -> V_125 == V_115 -> V_51 ) {
F_3 ( & V_14 ) ;
return V_123 ;
}
}
F_3 ( & V_14 ) ;
return NULL ;
}
void
F_52 ( struct V_11 * V_123 , bool V_126 )
{
#ifdef F_53
V_123 -> V_127 = V_36 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_126 )
V_123 -> V_38 = V_128 ;
else
V_123 -> V_38 = V_129 ;
F_15 ( & V_123 -> V_37 ) ;
F_3 ( & V_14 ) ;
}
static void
F_54 ( struct V_11 * V_123 , struct V_1 * V_2 ,
struct V_44 * V_115 , int V_126 )
{
if ( V_126 == 0 && F_20 ( V_115 ) > 0 ) {
V_123 -> V_130 = true ;
if ( V_123 -> V_131 ) {
V_126 = F_23 ( V_115 , V_123 -> V_131 ) ;
if ( V_126 > 0 )
return;
V_123 -> V_132 = true ;
return F_52 ( V_123 , V_126 ) ;
}
if ( ! V_2 -> V_84 ) {
F_22 ( 1 , L_27 ) ;
} else {
V_123 -> V_131 = V_115 ;
V_123 -> V_133 = true ;
V_2 -> V_83 = NULL ;
}
return;
}
V_123 -> V_131 = V_115 ;
V_123 -> V_133 = V_2 -> V_84 ;
if ( ! V_123 -> V_130 ) {
if ( V_2 -> V_84 )
V_2 -> V_83 = NULL ;
else
V_2 -> V_85 = NULL ;
}
F_52 ( V_123 , V_126 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_103 ;
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_134 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_56 ( & V_2 -> V_88 ) ;
F_2 ( & V_14 ) ;
if ( F_57 ( & V_2 -> V_135 ) >= V_136 )
F_58 ( & V_2 -> V_135 , V_136 - 1 ) ;
F_3 ( & V_14 ) ;
F_56 ( & V_2 -> V_137 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
if ( ! F_59 ( & V_2 -> V_138 ) ) {
struct V_4 V_139 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_139 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_28 , V_12 -> V_123 ) ;
V_12 -> V_38 = V_140 ;
F_14 ( & V_12 -> V_37 , & V_139 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_29 , V_12 -> V_123 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_59 ( & V_2 -> V_138 ) ) {
F_4 ( 1 , L_30 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_81 ) ;
F_10 ( V_2 -> V_91 ) ;
F_10 ( V_2 ) ;
V_103 = F_60 ( & V_141 ) ;
if ( V_103 > 0 )
F_61 ( V_142 , V_103 + V_143 ,
V_144 ) ;
}
static int
F_62 ( struct V_1 * V_2 , struct V_11 * V_123 )
{
int V_103 ;
char * V_115 = V_2 -> V_85 ;
struct V_44 * V_145 = (struct V_44 * ) V_115 ;
unsigned int V_146 = F_27 ( V_145 -> V_72 ) ;
if ( V_146 > V_58 + V_73 - 4 ) {
F_22 ( 1 , L_31 ,
V_146 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_88 ) ;
return - V_111 ;
}
if ( V_146 > V_147 - 4 ) {
V_2 -> V_84 = true ;
memcpy ( V_2 -> V_83 , V_2 -> V_85 , V_2 -> V_104 ) ;
V_115 = V_2 -> V_83 ;
V_145 = (struct V_44 * ) V_115 ;
}
V_103 = F_47 ( V_2 ,
V_115 + sizeof( struct V_44 ) - 1 ,
V_146 - sizeof( struct V_44 ) + 1 + 4 ) ;
if ( V_103 < 0 )
return V_103 ;
V_2 -> V_104 += V_103 ;
F_63 ( V_145 , V_2 -> V_104 ) ;
V_103 = F_64 ( V_145 , V_145 -> V_124 , V_2 -> V_104 ) ;
if ( V_103 != 0 )
F_65 ( L_32 , V_115 ,
F_66 (unsigned int, server->total_read, 48 ) ) ;
if ( V_123 )
F_54 ( V_123 , V_2 , V_145 , V_103 ) ;
return V_103 ;
}
static int
F_67 ( void * V_148 )
{
int V_103 ;
struct V_1 * V_2 = V_148 ;
unsigned int V_146 ;
char * V_115 = NULL ;
struct V_44 * V_145 = NULL ;
struct V_149 * V_150 = NULL ;
struct V_11 * V_12 ;
V_151 -> V_28 |= V_152 ;
F_4 ( 1 , L_33 , F_68 ( V_151 ) ) ;
V_103 = F_69 ( & V_141 ) ;
if ( V_103 > 1 )
F_61 ( V_142 , V_103 + V_143 ,
V_144 ) ;
F_70 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( ! F_34 ( V_2 ) )
continue;
V_2 -> V_84 = false ;
V_145 = (struct V_44 * ) V_2 -> V_85 ;
V_115 = V_2 -> V_85 ;
V_146 = 4 ;
V_103 = F_47 ( V_2 , V_115 , V_146 ) ;
if ( V_103 < 0 )
continue;
V_2 -> V_104 = V_103 ;
V_146 = F_27 ( V_145 -> V_72 ) ;
F_4 ( 1 , L_34 , V_146 ) ;
if ( ! F_48 ( V_2 , V_115 [ 0 ] ) )
continue;
if ( V_146 < sizeof( struct V_44 ) - 1 - 4 ) {
F_22 ( 1 , L_35 ,
V_146 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_88 ) ;
continue;
}
V_103 = F_47 ( V_2 , V_115 + 4 ,
sizeof( struct V_44 ) - 1 - 4 ) ;
if ( V_103 < 0 )
continue;
V_2 -> V_104 += V_103 ;
V_12 = F_50 ( V_2 , V_145 ) ;
if ( ! V_12 || ! V_12 -> V_153 )
V_103 = F_62 ( V_2 , V_12 ) ;
else
V_103 = V_12 -> V_153 ( V_2 , V_12 ) ;
if ( V_103 < 0 )
continue;
if ( V_2 -> V_84 ) {
V_115 = V_2 -> V_83 ;
V_145 = (struct V_44 * ) V_115 ;
}
V_2 -> V_35 = V_36 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_130 || V_12 -> V_132 )
V_12 -> V_41 ( V_12 ) ;
} else if ( ! F_71 ( V_145 , V_2 ) ) {
F_22 ( 1 , L_36
L_37 , F_57 ( & V_154 ) ) ;
F_65 ( L_38 , V_115 ,
sizeof( struct V_44 ) ) ;
#ifdef F_72
F_73 ( V_145 ) ;
F_74 ( V_2 ) ;
#endif
}
}
F_75 ( V_2 -> V_83 ) ;
if ( V_2 -> V_85 )
F_76 ( V_2 -> V_85 ) ;
V_150 = F_77 ( & V_2 -> V_155 , NULL ) ;
F_55 ( V_2 ) ;
if ( ! V_150 ) {
F_78 ( V_156 ) ;
while ( ! F_79 ( V_151 ) ) {
F_80 () ;
F_78 ( V_156 ) ;
}
F_78 ( V_157 ) ;
}
F_81 ( 0 ) ;
}
static char *
F_82 ( const char * V_158 )
{
const char * V_159 ;
char * V_160 , * V_161 ;
unsigned int V_34 ;
V_159 = V_158 + 2 ;
V_161 = strchr ( V_159 , '\\' ) ;
if ( ! V_161 )
return F_83 ( - V_54 ) ;
V_34 = V_161 - V_159 ;
V_160 = F_43 ( ( V_34 + 1 ) , V_144 ) ;
if ( V_160 == NULL )
return F_83 ( - V_108 ) ;
memcpy ( V_160 , V_159 , V_34 ) ;
V_160 [ V_34 ] = '\0' ;
return V_160 ;
}
static int
F_84 ( const char * V_162 , const char * V_163 ,
struct V_164 * V_165 )
{
char * V_166 , * V_167 , * V_168 ;
char * V_169 = NULL , * V_170 ;
int V_171 ;
unsigned int V_172 , V_173 , V_174 ;
char V_175 [ 2 ] ;
short int V_176 = - 1 ;
short int V_177 = - 1 ;
bool V_178 = false ;
bool V_179 = false ;
char * V_180 = F_85 () -> V_180 ;
V_175 [ 0 ] = ',' ;
V_175 [ 1 ] = 0 ;
memset ( V_165 -> V_181 , 0x20 , V_182 ) ;
for ( V_173 = 0 ; V_173 < F_86 ( V_180 , V_182 ) ; V_173 ++ )
V_165 -> V_181 [ V_173 ] = toupper ( V_180 [ V_173 ] ) ;
V_165 -> V_181 [ V_182 ] = 0 ;
V_165 -> V_183 [ 0 ] = 0 ;
V_165 -> V_184 = F_87 () ;
V_165 -> V_185 = F_87 () ;
V_165 -> V_186 = F_88 () ;
V_165 -> V_187 = V_165 -> V_188 = V_189 | V_190 | V_191 ;
V_165 -> V_192 = 1 ;
V_165 -> V_193 = 1 ;
V_165 -> V_194 = V_195 ;
if ( ! V_162 )
goto V_196;
V_169 = F_89 ( V_162 , V_197 , V_144 ) ;
if ( ! V_169 )
goto V_196;
V_170 = V_169 ;
V_168 = V_170 + strlen ( V_170 ) ;
if ( strncmp ( V_170 , L_39 , 4 ) == 0 ) {
if ( V_170 [ 4 ] != 0 ) {
V_175 [ 0 ] = V_170 [ 4 ] ;
V_170 += 5 ;
} else {
F_4 ( 1 , L_40 ) ;
}
}
V_165 -> V_198 = false ;
V_165 -> V_199 = false ;
while ( ( V_167 = F_90 ( & V_170 , V_175 ) ) != NULL ) {
if ( ! * V_167 )
continue;
if ( ( V_166 = strchr ( V_167 , '=' ) ) != NULL )
* V_166 ++ = '\0' ;
if ( F_91 ( V_167 , L_41 , 10 ) == 0 ) {
V_165 -> V_200 = 0 ;
} else if ( F_91 ( V_167 , L_42 , 12 ) == 0 ) {
V_165 -> V_200 = 1 ;
} else if ( F_91 ( V_167 , L_43 , 4 ) == 0 ) {
if ( ! V_166 ) {
F_92 ( V_201
L_44 ) ;
goto V_196;
} else if ( ! * V_166 ) {
V_165 -> V_202 = 1 ;
}
if ( F_86 ( V_166 , V_203 ) <
V_203 ) {
V_165 -> V_204 = F_93 ( V_166 , V_144 ) ;
if ( ! V_165 -> V_204 ) {
F_92 ( V_201 L_45
L_46 ) ;
goto V_196;
}
} else {
F_92 ( V_201 L_47 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_48 , 4 ) == 0 ) {
if ( ! V_166 ) {
V_165 -> V_205 = NULL ;
continue;
} else if ( V_166 [ 0 ] == 0 ) {
if ( V_166 [ 1 ] != V_175 [ 0 ] ) {
V_165 -> V_205 = NULL ;
continue;
}
}
V_172 = strlen ( V_166 ) ;
if ( ( V_166 [ V_172 ] == 0 ) &&
( V_166 + V_172 < V_168 ) &&
( V_166 [ V_172 + 1 ] == V_175 [ 0 ] ) ) {
V_166 [ V_172 ] = V_175 [ 0 ] ;
V_172 += 2 ;
while ( V_166 [ V_172 ] != 0 ) {
if ( V_166 [ V_172 ] == V_175 [ 0 ] ) {
if ( V_166 [ V_172 + 1 ] ==
V_175 [ 0 ] ) {
V_172 ++ ;
} else {
break;
}
}
V_172 ++ ;
}
if ( V_166 [ V_172 ] == 0 ) {
V_170 = NULL ;
} else {
V_166 [ V_172 ] = 0 ;
V_170 = V_166 + V_172 + 1 ;
}
V_165 -> V_205 = F_94 ( V_172 , V_144 ) ;
if ( V_165 -> V_205 == NULL ) {
F_92 ( V_201 L_45
L_49 ) ;
goto V_196;
}
for ( V_173 = 0 , V_174 = 0 ; V_173 < V_172 ; V_173 ++ , V_174 ++ ) {
V_165 -> V_205 [ V_174 ] = V_166 [ V_173 ] ;
if ( V_166 [ V_173 ] == V_175 [ 0 ]
&& V_166 [ V_173 + 1 ] == V_175 [ 0 ] ) {
V_173 ++ ;
}
}
V_165 -> V_205 [ V_174 ] = 0 ;
} else {
V_165 -> V_205 = F_94 ( V_172 + 1 , V_144 ) ;
if ( V_165 -> V_205 == NULL ) {
F_92 ( V_201 L_45
L_49 ) ;
goto V_196;
}
strcpy ( V_165 -> V_205 , V_166 ) ;
}
} else if ( ! F_91 ( V_167 , L_50 , 2 ) ||
! F_91 ( V_167 , L_51 , 4 ) ) {
if ( ! V_166 || ! * V_166 ) {
V_165 -> V_206 = NULL ;
} else if ( F_86 ( V_166 , V_207 ) <
V_207 ) {
V_165 -> V_206 = F_93 ( V_166 , V_144 ) ;
if ( ! V_165 -> V_206 ) {
F_92 ( V_201 L_45
L_52 ) ;
goto V_196;
}
} else {
F_92 ( V_201 L_53
L_54 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_55 , 3 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_56 ) ;
continue;
} else if ( F_91 ( V_166 , L_57 , 5 ) == 0 ) {
V_165 -> V_208 |= V_209 |
V_210 ;
} else if ( F_91 ( V_166 , L_58 , 5 ) == 0 ) {
F_22 ( 1 , L_59 ) ;
goto V_196;
} else if ( F_91 ( V_166 , L_60 , 4 ) == 0 ) {
V_165 -> V_208 |= V_209 ;
} else if ( F_91 ( V_166 , L_61 , 8 ) == 0 ) {
V_165 -> V_208 |= V_211 |
V_210 ;
} else if ( F_91 ( V_166 , L_62 , 7 ) == 0 ) {
V_165 -> V_208 |= V_211 ;
} else if ( F_91 ( V_166 , L_63 , 7 ) == 0 ) {
V_165 -> V_208 |= V_212 |
V_210 ;
} else if ( F_91 ( V_166 , L_64 , 6 ) == 0 ) {
V_165 -> V_208 |= V_212 ;
} else if ( F_91 ( V_166 , L_65 , 5 ) == 0 ) {
V_165 -> V_208 |= V_213 |
V_210 ;
} else if ( F_91 ( V_166 , L_66 , 4 ) == 0 ) {
V_165 -> V_208 |= V_213 ;
} else if ( F_91 ( V_166 , L_67 , 6 ) == 0 ) {
V_165 -> V_208 |= V_212 ;
#ifdef F_95
} else if ( F_91 ( V_166 , L_68 , 6 ) == 0 ) {
V_165 -> V_208 |= V_214 ;
#endif
} else if ( F_91 ( V_166 , L_69 , 4 ) == 0 ) {
V_165 -> V_202 = 1 ;
} else {
F_22 ( 1 , L_70 , V_166 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_71 , 3 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_72
L_73 ) ;
} else if ( ( F_91 ( V_166 , L_74 , 4 ) == 0 ) ||
( F_91 ( V_166 , L_75 , 1 ) == 0 ) ) {
continue;
}
} else if ( ( F_91 ( V_167 , L_76 , 3 ) == 0 )
|| ( F_91 ( V_167 , L_77 , 6 ) == 0 )
|| ( F_91 ( V_167 , L_78 , 4 ) == 0 ) ) {
if ( ! V_166 || ! * V_166 ) {
F_92 ( V_201 L_79
L_80 ) ;
goto V_196;
}
if ( ( V_172 = F_86 ( V_166 , 300 ) ) < 300 ) {
V_165 -> V_215 = F_43 ( V_172 + 1 , V_144 ) ;
if ( V_165 -> V_215 == NULL )
goto V_196;
strcpy ( V_165 -> V_215 , V_166 ) ;
if ( strncmp ( V_165 -> V_215 , L_81 , 2 ) == 0 ) {
V_165 -> V_215 [ 0 ] = '\\' ;
V_165 -> V_215 [ 1 ] = '\\' ;
} else if ( strncmp ( V_165 -> V_215 , L_82 , 2 ) != 0 ) {
F_92 ( V_201
L_83
L_84 ) ;
goto V_196;
}
} else {
F_92 ( V_201 L_85 ) ;
goto V_196;
}
} else if ( ( F_91 ( V_167 , L_86 , 3 ) == 0 )
|| ( F_91 ( V_167 , L_87 , 5 ) == 0 ) ) {
if ( ! V_166 || ! * V_166 ) {
F_92 ( V_201 L_88 ) ;
goto V_196;
}
if ( F_86 ( V_166 , 256 ) < 256 ) {
V_165 -> V_216 = F_93 ( V_166 , V_144 ) ;
if ( ! V_165 -> V_216 ) {
F_92 ( V_201 L_45
L_89 ) ;
goto V_196;
}
F_4 ( 1 , L_90 ) ;
} else {
F_92 ( V_201 L_91
L_92 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_93 , 7 ) == 0 ) {
V_165 -> V_217 . V_218 = V_219 ;
if ( ! V_166 || ! * V_166 ) {
F_92 ( V_201 L_94
L_95 ) ;
goto V_196;
}
V_173 = F_96 ( (struct V_120 * ) & V_165 -> V_217 ,
V_166 , strlen ( V_166 ) ) ;
if ( V_173 == 0 ) {
F_92 ( V_201 L_96
L_97 ,
V_166 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_98 , 10 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_92 ( V_201
L_99 ) ;
goto V_196;
}
if ( ( V_172 = F_86 ( V_166 , 1024 ) ) < 1024 ) {
if ( V_166 [ 0 ] != '/' )
V_172 ++ ;
V_165 -> V_220 = F_43 ( V_172 + 1 , V_144 ) ;
if ( V_165 -> V_220 == NULL )
goto V_196;
if ( V_166 [ 0 ] != '/' ) {
V_165 -> V_220 [ 0 ] = '/' ;
strcpy ( V_165 -> V_220 + 1 , V_166 ) ;
} else
strcpy ( V_165 -> V_220 , V_166 ) ;
F_4 ( 1 , L_100 , V_165 -> V_220 ) ;
} else {
F_92 ( V_201 L_101 ) ;
goto V_196;
}
} else if ( F_91 ( V_167 , L_102 , 9 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_92 ( V_201 L_103
L_104 ) ;
goto V_196;
}
if ( F_86 ( V_166 , 65 ) < 65 ) {
if ( F_91 ( V_166 , L_105 , 7 ) ) {
V_165 -> V_221 = F_93 ( V_166 ,
V_144 ) ;
if ( ! V_165 -> V_221 ) {
F_92 ( V_201 L_106
L_107
L_108 ) ;
goto V_196;
}
}
F_4 ( 1 , L_109 , V_166 ) ;
} else {
F_92 ( V_201 L_110
L_111 ) ;
goto V_196;
}
} else if ( ! F_91 ( V_167 , L_112 , 3 ) && V_166 && * V_166 ) {
V_165 -> V_185 = F_97 ( V_166 , & V_166 , 0 ) ;
V_178 = true ;
} else if ( ! F_91 ( V_167 , L_113 , 5 ) && V_166 && * V_166 ) {
V_165 -> V_184 = F_97 ( V_166 , & V_166 , 0 ) ;
} else if ( ! F_91 ( V_167 , L_114 , 8 ) ) {
V_176 = 1 ;
} else if ( ! F_91 ( V_167 , L_115 , 10 ) ) {
V_176 = 0 ;
} else if ( ! F_91 ( V_167 , L_116 , 3 ) && V_166 && * V_166 ) {
V_165 -> V_186 = F_97 ( V_166 , & V_166 , 0 ) ;
V_179 = true ;
} else if ( ! F_91 ( V_167 , L_117 , 8 ) ) {
V_177 = 1 ;
} else if ( ! F_91 ( V_167 , L_118 , 10 ) ) {
V_177 = 0 ;
} else if ( F_91 ( V_167 , L_119 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_188 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_120 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_187 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_121 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_187 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_122 , 4 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_222 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_123 , 5 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_223 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_124 , 5 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_224 =
F_97 ( V_166 , & V_166 , 0 ) ;
}
} else if ( F_91 ( V_167 , L_125 , 5 ) == 0 ) {
if ( ! V_166 || ! * V_166 ) {
F_22 ( 1 , L_126 ) ;
continue;
} else if ( F_91 ( V_166 , L_127 , 11 ) == 0 ) {
V_165 -> V_225 = 1 ;
}
} else if ( F_91 ( V_167 , L_128 , 4 ) == 0 ) {
if ( ! V_166 || ! * V_166 || ( * V_166 == ' ' ) ) {
F_4 ( 1 , L_129 ) ;
} else {
memset ( V_165 -> V_181 , 0x20 ,
V_182 ) ;
for ( V_173 = 0 ; V_173 < V_182 ; V_173 ++ ) {
if ( V_166 [ V_173 ] == 0 )
break;
V_165 -> V_181 [ V_173 ] = V_166 [ V_173 ] ;
}
if ( V_173 == V_182 && V_166 [ V_173 ] != 0 )
F_92 ( V_201 L_130
L_131 ) ;
}
} else if ( F_91 ( V_167 , L_132 , 7 ) == 0 ) {
if ( ! V_166 || ! * V_166 || ( * V_166 == ' ' ) ) {
F_4 ( 1 , L_133 ) ;
} else {
memset ( V_165 -> V_183 , 0x20 ,
V_226 ) ;
for ( V_173 = 0 ; V_173 < 15 ; V_173 ++ ) {
if ( V_166 [ V_173 ] == 0 )
break;
else
V_165 -> V_183 [ V_173 ] =
V_166 [ V_173 ] ;
}
if ( V_173 == V_182 && V_166 [ V_173 ] != 0 )
F_92 ( V_201 L_134
L_135 ) ;
}
} else if ( F_91 ( V_167 , L_136 , 7 ) == 0 ) {
if ( V_166 && * V_166 ) {
V_165 -> V_194 = V_79 * F_97 ( V_166 ,
& V_166 , 0 ) ;
if ( V_165 -> V_194 > V_227 ) {
F_22 ( 1 , L_137
L_138 ) ;
goto V_196;
}
}
} else if ( F_91 ( V_167 , L_139 , 4 ) == 0 ) {
} else if ( F_91 ( V_167 , L_140 , 3 ) == 0 ) {
} else if ( F_91 ( V_167 , L_141 , 5 ) == 0 ) {
} else if ( F_91 ( V_167 , L_142 , 2 ) == 0 && strlen ( V_167 ) == 2 ) {
} else if ( F_91 ( V_167 , L_143 , 2 ) == 0 ) {
} else if ( F_91 ( V_167 , L_144 , 11 ) == 0 ) {
V_165 -> V_228 = 1 ;
} else if ( F_91 ( V_167 , L_145 , 10 ) == 0 ) {
V_165 -> V_229 = 1 ;
} else if ( ( F_91 ( V_167 , L_146 , 4 ) == 0 ) ||
( F_91 ( V_167 , L_147 , 6 ) == 0 ) ||
( F_91 ( V_167 , L_148 , 4 ) == 0 ) ||
( F_91 ( V_167 , L_149 , 6 ) == 0 ) ||
( F_91 ( V_167 , L_150 , 5 ) == 0 ) ||
( F_91 ( V_167 , L_151 , 6 ) == 0 ) ||
( F_91 ( V_167 , L_152 , 3 ) == 0 ) ) {
continue;
} else if ( F_91 ( V_167 , L_153 , 4 ) == 0 ) {
V_165 -> V_230 = 1 ;
} else if ( F_91 ( V_167 , L_154 , 4 ) == 0 ) {
V_165 -> V_230 = 0 ;
} else if ( F_91 ( V_167 , L_155 , 4 ) == 0 ) {
V_165 -> V_231 = 0 ;
} else if ( F_91 ( V_167 , L_156 , 6 ) == 0 ) {
V_165 -> V_231 = 1 ;
} else if ( F_91 ( V_167 , L_157 , 8 ) == 0 ) {
V_165 -> V_232 = 1 ;
} else if ( F_91 ( V_167 , L_158 , 10 ) == 0 ) {
V_165 -> V_232 = 0 ;
} else if ( F_91 ( V_167 , L_159 , 3 ) == 0 ) {
V_165 -> V_233 = 1 ;
} else if ( F_91 ( V_167 , L_160 , 5 ) == 0 ) {
V_165 -> V_233 = 0 ;
} else if ( F_91 ( V_167 , L_161 , 5 ) == 0 ) {
V_165 -> V_234 = 1 ;
} else if ( F_91 ( V_167 , L_162 , 10 ) == 0 ) {
V_165 -> V_192 = 1 ;
} else if ( F_91 ( V_167 , L_163 , 12 ) == 0 ) {
V_165 -> V_192 = 0 ;
} else if ( F_91 ( V_167 , L_164 , 6 ) == 0 ) {
V_165 -> V_235 = 1 ;
} else if ( F_91 ( V_167 , L_165 , 7 ) == 0 ) {
V_165 -> V_235 = 1 ;
} else if ( ( F_91 ( V_167 , L_166 , 6 ) == 0 ) ||
( F_91 ( V_167 , L_167 , 10 ) == 0 ) ) {
V_165 -> V_236 = 1 ;
} else if ( F_91 ( V_167 , L_168 , 4 ) == 0 ) {
} else if ( F_91 ( V_167 , L_169 , 6 ) == 0 ) {
} else if ( F_91 ( V_167 , L_170 , 7 ) == 0 ) {
} else if ( F_91 ( V_167 , L_171 , 3 ) == 0 ) {
V_165 -> V_237 = 0 ;
} else if ( ( F_91 ( V_167 , L_172 , 5 ) == 0 ) ||
( F_91 ( V_167 , L_173 , 6 ) == 0 ) ) {
V_165 -> V_237 = 1 ;
if ( V_165 -> V_188 ==
( V_238 & ~ ( V_239 | V_240 ) ) )
V_165 -> V_188 = V_238 ;
} else if ( F_91 ( V_167 , L_174 , 9 ) == 0 ) {
V_165 -> V_241 = 1 ;
} else if ( F_91 ( V_167 , L_175 , 7 ) == 0 ) {
V_165 -> V_242 = 1 ;
} else if ( F_91 ( V_167 , L_176 , 9 ) == 0 ) {
V_165 -> V_242 = 0 ;
} else if ( F_91 ( V_167 , L_177 , 7 ) == 0 ) {
V_165 -> V_243 = true ;
} else if ( F_91 ( V_167 , L_178 , 9 ) == 0 ) {
V_165 -> V_243 = false ;
} else if ( F_91 ( V_167 , L_179 , 6 ) == 0 ) {
V_165 -> V_230 = 0 ;
} else if ( F_91 ( V_167 , L_180 , 6 ) == 0 ) {
V_165 -> V_230 = 1 ;
} else if ( F_91 ( V_167 , L_181 , 6 ) == 0 ) {
V_165 -> V_244 = 0 ;
} else if ( F_91 ( V_167 , L_182 , 4 ) == 0 ) {
V_165 -> V_244 = 1 ;
} else if ( F_91 ( V_167 , L_183 , 12 ) == 0 ) {
V_165 -> V_245 = 1 ;
} else if ( F_91 ( V_167 , L_184 , 10 ) == 0 ) {
V_165 -> V_245 = 0 ;
} else if ( F_91 ( V_167 , L_185 , 7 ) == 0 ) {
V_165 -> V_193 = 1 ;
} else if ( F_91 ( V_167 , L_186 , 9 ) == 0 ) {
V_165 -> V_193 = 0 ;
} else if ( F_91 ( V_167 , L_187 , 12 ) == 0 ) {
V_165 -> V_246 = 1 ;
} else if ( F_91 ( V_167 , L_188 , 7 ) == 0 ) {
V_165 -> V_247 = 1 ;
} else if ( F_91 ( V_167 , L_189 , 9 ) == 0 ) {
V_165 -> V_247 = 0 ;
} else if ( F_91 ( V_167 , L_190 , 3 ) == 0 ) {
V_165 -> V_248 = 0 ;
} else if ( F_91 ( V_167 , L_191 , 5 ) == 0 ) {
V_165 -> V_248 = 1 ;
} else if ( F_91 ( V_167 , L_192 , 6 ) == 0 ) {
V_165 -> V_249 = 1 ;
} else if ( F_91 ( V_167 , L_193 , 4 ) == 0 ) {
V_165 -> V_208 |= V_210 ;
} else if ( F_91 ( V_167 , L_194 , 4 ) == 0 ) {
V_165 -> V_250 = 1 ;
} else if ( F_91 ( V_167 , L_195 , 6 ) == 0 ) {
V_165 -> V_251 = 1 ;
} else if ( F_91 ( V_167 , L_196 , 13 ) == 0 ) {
V_165 -> V_251 = 1 ;
} else if ( F_91 ( V_167 , L_197 , 11 ) == 0 ) {
V_165 -> V_252 = 1 ;
} else if ( F_91 ( V_167 , L_198 , 4 ) == 0 ) {
F_92 ( V_201 L_199
L_200
L_201 ) ;
} else if ( F_91 ( V_167 , L_202 , 3 ) == 0 ) {
#ifndef F_98
F_22 ( 1 , L_203
L_204 ) ;
goto V_196;
#endif
V_165 -> V_253 = true ;
} else if ( F_91 ( V_167 , L_205 , 10 ) == 0 ) {
V_165 -> V_254 = true ;
} else if ( F_91 ( V_167 , L_206 , 8 ) == 0 ) {
V_165 -> V_255 = true ;
} else if ( ! F_91 ( V_167 , L_207 , 9 ) && V_166 && * V_166 ) {
V_171 = F_99 ( V_166 , 0 , & V_165 -> V_256 ) ;
if ( V_171 < 0 ) {
F_22 ( 1 , L_208 ,
V_19 ) ;
goto V_196;
}
V_165 -> V_198 = true ;
} else if ( ! F_91 ( V_167 , L_209 , 9 ) && V_166 && * V_166 ) {
V_171 = F_99 ( V_166 , 0 , & V_165 -> V_257 ) ;
if ( V_171 < 0 ) {
F_22 ( 1 , L_210 ,
V_19 ) ;
goto V_196;
}
V_165 -> V_199 = true ;
} else
F_92 ( V_201 L_211 ,
V_167 ) ;
}
if ( V_165 -> V_215 == NULL ) {
if ( V_163 == NULL ) {
F_92 ( V_201 L_212
L_213 ) ;
goto V_196;
}
if ( ( V_172 = F_86 ( V_163 , 300 ) ) < 300 ) {
V_165 -> V_215 = F_43 ( V_172 + 1 , V_144 ) ;
if ( V_165 -> V_215 == NULL )
goto V_196;
strcpy ( V_165 -> V_215 , V_163 ) ;
if ( strncmp ( V_165 -> V_215 , L_81 , 2 ) == 0 ) {
V_165 -> V_215 [ 0 ] = '\\' ;
V_165 -> V_215 [ 1 ] = '\\' ;
} else if ( strncmp ( V_165 -> V_215 , L_82 , 2 ) != 0 ) {
F_92 ( V_201 L_214
L_215 ) ;
goto V_196;
}
V_166 = strpbrk ( V_165 -> V_215 + 2 , L_216 ) ;
if ( V_166 )
* V_166 = '\\' ;
} else {
F_92 ( V_201 L_85 ) ;
goto V_196;
}
}
if ( V_165 -> V_255 && ! ( V_165 -> V_208 & V_209 ) ) {
F_22 ( 1 , L_217
L_218 ) ;
goto V_196;
}
if ( V_165 -> V_206 == NULL )
V_165 -> V_206 = & V_165 -> V_215 [ 2 ] ;
if ( V_178 )
V_165 -> V_176 = V_176 ;
else if ( V_176 == 1 )
F_92 ( V_258 L_219
L_220 ) ;
if ( V_179 )
V_165 -> V_177 = V_177 ;
else if ( V_177 == 1 )
F_92 ( V_258 L_221
L_222 ) ;
F_10 ( V_169 ) ;
return 0 ;
V_196:
F_10 ( V_169 ) ;
return 1 ;
}
static bool
F_100 ( struct V_120 * V_217 , struct V_120 * V_259 )
{
switch ( V_217 -> V_260 ) {
case V_219 :
return ( V_259 -> V_260 == V_219 ) ;
case V_261 : {
struct V_262 * V_263 = (struct V_262 * ) V_217 ;
struct V_262 * V_264 = (struct V_262 * ) V_259 ;
return ( V_263 -> V_265 . V_266 == V_264 -> V_265 . V_266 ) ;
}
case V_267 : {
struct V_268 * V_269 = (struct V_268 * ) V_217 ;
struct V_268 * V_270 = (struct V_268 * ) & V_259 ;
return F_101 ( & V_269 -> V_271 , & V_270 -> V_271 ) ;
}
default:
F_102 ( 1 ) ;
return false ;
}
}
static bool
F_103 ( struct V_1 * V_2 , struct V_120 * V_272 )
{
T_3 V_222 , * V_273 ;
switch ( V_272 -> V_260 ) {
case V_261 :
V_273 = & ( (struct V_262 * ) & V_2 -> V_121 ) -> V_274 ;
V_222 = ( (struct V_262 * ) V_272 ) -> V_274 ;
break;
case V_267 :
V_273 = & ( (struct V_268 * ) & V_2 -> V_121 ) -> V_275 ;
V_222 = ( (struct V_268 * ) V_272 ) -> V_275 ;
break;
default:
F_102 ( 1 ) ;
return false ;
}
if ( ! V_222 ) {
V_222 = F_104 ( V_122 ) ;
if ( V_222 == * V_273 )
return true ;
V_222 = F_104 ( V_276 ) ;
}
return V_222 == * V_273 ;
}
static bool
F_105 ( struct V_1 * V_2 , struct V_120 * V_272 ,
struct V_120 * V_217 )
{
switch ( V_272 -> V_260 ) {
case V_261 : {
struct V_262 * V_277 = (struct V_262 * ) V_272 ;
struct V_262 * V_278 =
(struct V_262 * ) & V_2 -> V_121 ;
if ( V_277 -> V_265 . V_266 != V_278 -> V_265 . V_266 )
return false ;
break;
}
case V_267 : {
struct V_268 * V_279 = (struct V_268 * ) V_272 ;
struct V_268 * V_280 =
(struct V_268 * ) & V_2 -> V_121 ;
if ( ! F_101 ( & V_279 -> V_271 ,
& V_280 -> V_271 ) )
return false ;
if ( V_279 -> V_281 != V_280 -> V_281 )
return false ;
break;
}
default:
F_102 ( 1 ) ;
return false ;
}
if ( ! F_100 ( V_217 , (struct V_120 * ) & V_2 -> V_217 ) )
return false ;
return true ;
}
static bool
F_106 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
unsigned int V_282 ;
if ( V_165 -> V_208 & ( ~ ( V_210 | V_283 ) ) )
V_282 = V_165 -> V_208 ;
else
V_282 = V_284 | V_165 -> V_208 ;
switch ( V_2 -> V_285 ) {
case V_286 :
if ( ! ( V_282 & ( V_214 | V_287 ) ) )
return false ;
break;
case V_288 :
if ( ! ( V_282 & V_212 ) )
return false ;
break;
case V_289 :
if ( ! ( V_282 & V_213 ) )
return false ;
break;
case V_290 :
if ( ! ( V_282 & V_209 ) )
return false ;
break;
case V_291 :
if ( ! ( V_282 & V_211 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_282 & V_292 ) == 0 &&
( V_2 -> V_293 & V_294 ) )
return false ;
else if ( ( ( V_282 & V_210 ) == V_210 ) &&
( V_2 -> V_293 &
( V_295 | V_294 ) ) == 0 )
return false ;
return true ;
}
static int F_107 ( struct V_1 * V_2 , struct V_120 * V_272 ,
struct V_164 * V_165 )
{
if ( ! F_108 ( F_109 ( V_2 ) , V_151 -> V_296 -> V_297 ) )
return 0 ;
if ( ! F_105 ( V_2 , V_272 ,
(struct V_120 * ) & V_165 -> V_217 ) )
return 0 ;
if ( ! F_103 ( V_2 , V_272 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_165 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_110 ( struct V_120 * V_272 , struct V_164 * V_165 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_51 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_107 ( V_2 , V_272 , V_165 ) )
continue;
++ V_2 -> V_298 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_223 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_111 ( struct V_1 * V_2 )
{
struct V_149 * V_299 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_298 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_112 ( F_109 ( V_2 ) ) ;
F_15 ( & V_2 -> V_134 ) ;
F_3 ( & V_20 ) ;
F_113 ( & V_2 -> V_77 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_299 = F_77 ( & V_2 -> V_155 , NULL ) ;
if ( V_299 )
F_116 ( V_300 , V_299 ) ;
}
static struct V_1 *
F_117 ( struct V_164 * V_301 )
{
struct V_1 * V_302 = NULL ;
struct V_303 V_272 ;
struct V_262 * V_304 = (struct V_262 * ) & V_272 ;
struct V_268 * V_305 = (struct V_268 * ) & V_272 ;
int V_3 ;
memset ( & V_272 , 0 , sizeof( struct V_303 ) ) ;
F_4 ( 1 , L_224 , V_301 -> V_215 , V_301 -> V_206 ) ;
if ( V_301 -> V_206 && V_301 -> V_215 ) {
V_3 = F_118 ( (struct V_120 * ) & V_272 ,
V_301 -> V_206 ,
strlen ( V_301 -> V_206 ) ,
V_301 -> V_222 ) ;
if ( ! V_3 ) {
V_3 = - V_54 ;
goto V_306;
}
} else if ( V_301 -> V_206 ) {
F_22 ( 1 , L_225 ) ;
V_3 = - V_54 ;
goto V_306;
} else {
F_22 ( 1 , L_226
L_227 ) ;
V_3 = - V_54 ;
goto V_306;
}
V_302 = F_110 ( (struct V_120 * ) & V_272 , V_301 ) ;
if ( V_302 )
return V_302 ;
V_302 = F_94 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_302 ) {
V_3 = - V_108 ;
goto V_306;
}
V_3 = F_119 ( V_302 ) ;
if ( V_3 ) {
F_22 ( 1 , L_228 , V_3 ) ;
goto V_306;
}
F_120 ( V_302 , F_121 ( V_151 -> V_296 -> V_297 ) ) ;
V_302 -> V_81 = F_82 ( V_301 -> V_215 ) ;
if ( F_122 ( V_302 -> V_81 ) ) {
V_3 = F_123 ( V_302 -> V_81 ) ;
goto V_307;
}
V_302 -> V_228 = V_301 -> V_228 ;
V_302 -> V_229 = V_301 -> V_229 ;
V_302 -> V_308 = V_301 -> V_225 ;
F_58 ( & V_302 -> V_135 , 0 ) ;
F_124 ( & V_302 -> V_88 ) ;
F_124 ( & V_302 -> V_137 ) ;
F_12 ( & V_302 -> V_138 ) ;
F_125 ( & V_302 -> V_25 ) ;
memcpy ( V_302 -> V_309 ,
V_301 -> V_181 , V_226 ) ;
memcpy ( V_302 -> V_310 ,
V_301 -> V_183 , V_226 ) ;
V_302 -> V_31 = false ;
V_302 -> V_30 = 0 ;
V_302 -> V_35 = V_36 ;
F_12 ( & V_302 -> V_134 ) ;
F_12 ( & V_302 -> V_21 ) ;
F_126 ( & V_302 -> V_77 , F_29 ) ;
V_302 -> V_15 = V_311 ;
memcpy ( & V_302 -> V_217 , & V_301 -> V_217 ,
sizeof( V_302 -> V_217 ) ) ;
++ V_302 -> V_298 ;
if ( V_272 . V_218 == V_267 ) {
F_4 ( 1 , L_229 ) ;
memcpy ( & V_302 -> V_121 , V_305 ,
sizeof( struct V_268 ) ) ;
} else
memcpy ( & V_302 -> V_121 , V_304 ,
sizeof( struct V_262 ) ) ;
V_3 = F_127 ( V_302 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_230 ) ;
goto V_307;
}
F_128 ( V_312 ) ;
V_302 -> V_155 = F_129 ( F_67 ,
V_302 , L_231 ) ;
if ( F_122 ( V_302 -> V_155 ) ) {
V_3 = F_123 ( V_302 -> V_155 ) ;
F_22 ( 1 , L_232 , V_3 ) ;
F_130 ( V_312 ) ;
goto V_307;
}
V_302 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_131 ( & V_302 -> V_134 , & V_313 ) ;
F_3 ( & V_20 ) ;
F_132 ( V_302 ) ;
F_33 ( V_82 , & V_302 -> V_77 , V_78 ) ;
return V_302 ;
V_307:
F_114 ( V_302 ) ;
F_112 ( F_109 ( V_302 ) ) ;
V_306:
if ( V_302 ) {
if ( ! F_122 ( V_302 -> V_81 ) )
F_10 ( V_302 -> V_81 ) ;
if ( V_302 -> V_26 )
F_9 ( V_302 -> V_26 ) ;
F_10 ( V_302 ) ;
}
return F_83 ( V_3 ) ;
}
static int F_133 ( struct V_7 * V_8 , struct V_164 * V_165 )
{
switch ( V_8 -> V_2 -> V_285 ) {
case V_290 :
if ( V_165 -> V_184 != V_8 -> V_184 )
return 0 ;
break;
default:
if ( V_8 -> V_314 == NULL )
return 0 ;
if ( strncmp ( V_8 -> V_314 , V_165 -> V_204 ,
V_203 ) )
return 0 ;
if ( strlen ( V_165 -> V_204 ) != 0 &&
V_8 -> V_205 != NULL &&
strncmp ( V_8 -> V_205 ,
V_165 -> V_205 ? V_165 -> V_205 : L_233 ,
V_315 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_134 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_51 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_133 ( V_8 , V_165 ) )
continue;
++ V_8 -> V_316 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_135 ( struct V_7 * V_8 )
{
int V_317 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_234 , V_19 , V_8 -> V_316 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_316 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_318 == V_87 ) {
V_317 = F_136 () ;
F_137 ( V_317 , V_8 ) ;
F_138 ( V_317 ) ;
}
F_139 ( V_8 ) ;
F_111 ( V_2 ) ;
}
static struct V_7 *
F_140 ( struct V_1 * V_2 , struct V_164 * V_301 )
{
int V_3 = - V_108 , V_317 ;
struct V_7 * V_8 ;
struct V_262 * V_272 = (struct V_262 * ) & V_2 -> V_121 ;
struct V_268 * V_279 = (struct V_268 * ) & V_2 -> V_121 ;
V_317 = F_136 () ;
V_8 = F_134 ( V_2 , V_301 ) ;
if ( V_8 ) {
F_4 ( 1 , L_235 , V_8 -> V_318 ) ;
F_7 ( & V_8 -> V_319 ) ;
V_3 = F_141 ( V_317 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_319 ) ;
F_135 ( V_8 ) ;
F_142 ( V_317 ) ;
return F_83 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_236 ) ;
V_3 = F_143 ( V_317 , V_8 ,
V_301 -> V_320 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_319 ) ;
F_135 ( V_8 ) ;
F_142 ( V_317 ) ;
return F_83 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_319 ) ;
F_111 ( V_2 ) ;
F_142 ( V_317 ) ;
return V_8 ;
}
F_4 ( 1 , L_237 ) ;
V_8 = F_144 () ;
if ( V_8 == NULL )
goto V_321;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_121 . V_218 == V_267 )
sprintf ( V_8 -> V_322 , L_238 , & V_279 -> V_271 ) ;
else
sprintf ( V_8 -> V_322 , L_239 , & V_272 -> V_265 ) ;
if ( V_301 -> V_204 ) {
V_8 -> V_314 = F_93 ( V_301 -> V_204 , V_144 ) ;
if ( ! V_8 -> V_314 )
goto V_321;
}
if ( V_301 -> V_205 ) {
V_8 -> V_205 = F_93 ( V_301 -> V_205 , V_144 ) ;
if ( ! V_8 -> V_205 )
goto V_321;
}
if ( V_301 -> V_216 ) {
V_8 -> V_323 = F_93 ( V_301 -> V_216 , V_144 ) ;
if ( ! V_8 -> V_323 )
goto V_321;
}
V_8 -> V_184 = V_301 -> V_184 ;
V_8 -> V_185 = V_301 -> V_185 ;
if ( ( V_301 -> V_208 == 0 ) && V_324 == false ) {
V_324 = true ;
F_22 ( 1 , L_240
L_241
L_242 ) ;
}
V_8 -> V_325 = V_301 -> V_208 ;
F_7 ( & V_8 -> V_319 ) ;
V_3 = F_141 ( V_317 , V_8 ) ;
if ( ! V_3 )
V_3 = F_143 ( V_317 , V_8 , V_301 -> V_320 ) ;
F_11 ( & V_8 -> V_319 ) ;
if ( V_3 )
goto V_321;
F_2 ( & V_20 ) ;
F_131 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_142 ( V_317 ) ;
return V_8 ;
V_321:
F_139 ( V_8 ) ;
F_142 ( V_317 ) ;
return F_83 ( V_3 ) ;
}
static int F_145 ( struct V_9 * V_10 , const char * V_158 )
{
if ( V_10 -> V_326 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_327 , V_158 , V_328 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_146 ( struct V_7 * V_8 , const char * V_158 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_145 ( V_10 , V_158 ) )
continue;
++ V_10 -> V_329 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_147 ( struct V_9 * V_10 )
{
int V_317 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_243 , V_19 , V_10 -> V_329 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_329 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_317 = F_136 () ;
F_148 ( V_317 , V_10 ) ;
F_138 ( V_317 ) ;
F_149 ( V_10 ) ;
F_150 ( V_10 ) ;
F_135 ( V_8 ) ;
}
static struct V_9 *
F_151 ( struct V_7 * V_8 , struct V_164 * V_301 )
{
int V_3 , V_317 ;
struct V_9 * V_10 ;
V_10 = F_146 ( V_8 , V_301 -> V_215 ) ;
if ( V_10 ) {
F_4 ( 1 , L_244 ) ;
F_135 ( V_8 ) ;
if ( V_10 -> V_250 != V_301 -> V_250 )
F_22 ( 1 , L_245
L_246 ) ;
return V_10 ;
}
V_10 = F_152 () ;
if ( V_10 == NULL ) {
V_3 = - V_108 ;
goto V_330;
}
V_10 -> V_8 = V_8 ;
if ( V_301 -> V_205 ) {
V_10 -> V_205 = F_93 ( V_301 -> V_205 , V_144 ) ;
if ( ! V_10 -> V_205 ) {
V_3 = - V_108 ;
goto V_330;
}
}
if ( strchr ( V_301 -> V_215 + 3 , '\\' ) == NULL
&& strchr ( V_301 -> V_215 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_247 ) ;
V_3 = - V_331 ;
goto V_330;
}
V_317 = F_136 () ;
V_3 = F_153 ( V_317 , V_8 , V_301 -> V_215 , V_10 , V_301 -> V_320 ) ;
F_142 ( V_317 ) ;
F_4 ( 1 , L_248 , V_3 ) ;
if ( V_3 )
goto V_330;
if ( V_301 -> V_234 ) {
V_10 -> V_332 &= ~ V_333 ;
F_4 ( 1 , L_249 , V_10 -> V_332 ) ;
}
V_10 -> V_250 = V_301 -> V_250 ;
V_10 -> V_230 = V_301 -> V_230 ;
V_10 -> V_236 = V_301 -> V_236 ;
V_10 -> V_249 = V_301 -> V_249 ;
F_2 ( & V_20 ) ;
F_131 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_154 ( V_10 ) ;
return V_10 ;
V_330:
F_150 ( V_10 ) ;
return F_83 ( V_3 ) ;
}
void
F_155 ( struct V_334 * V_335 )
{
if ( ! V_335 || F_122 ( V_335 ) )
return;
if ( ! F_156 ( & V_335 -> V_336 ) ||
F_157 ( V_337 , & V_335 -> V_338 ) ) {
V_335 -> V_339 = V_36 ;
return;
}
if ( ! F_122 ( F_158 ( V_335 ) ) )
F_147 ( F_158 ( V_335 ) ) ;
F_10 ( V_335 ) ;
return;
}
static inline struct V_334 *
F_159 ( struct V_340 * V_341 )
{
return V_341 -> V_342 ;
}
static int
F_160 ( struct V_343 * V_344 , struct V_345 * V_346 )
{
struct V_340 * V_347 = F_161 ( V_344 ) ;
struct V_340 * V_90 = V_346 -> V_341 ;
if ( ( V_344 -> V_348 & V_349 ) != ( V_346 -> V_28 & V_349 ) )
return 0 ;
if ( ( V_347 -> V_350 & V_351 ) !=
( V_90 -> V_350 & V_351 ) )
return 0 ;
if ( V_90 -> V_224 && V_90 -> V_224 < V_347 -> V_224 )
return 0 ;
if ( V_90 -> V_223 && V_90 -> V_223 < V_347 -> V_223 )
return 0 ;
if ( V_347 -> V_352 != V_90 -> V_352 || V_347 -> V_353 != V_90 -> V_353 )
return 0 ;
if ( V_347 -> V_354 != V_90 -> V_354 ||
V_347 -> V_355 != V_90 -> V_355 )
return 0 ;
if ( strcmp ( V_347 -> V_320 -> V_356 , V_90 -> V_320 -> V_356 ) )
return 0 ;
if ( V_347 -> V_194 != V_90 -> V_194 )
return 0 ;
return 1 ;
}
int
F_162 ( struct V_343 * V_344 , void * V_167 )
{
struct V_345 * V_346 = (struct V_345 * ) V_167 ;
struct V_164 * V_301 ;
struct V_340 * V_341 ;
struct V_1 * V_357 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_334 * V_335 ;
struct V_303 V_272 ;
int V_3 = 0 ;
memset ( & V_272 , 0 , sizeof( struct V_303 ) ) ;
F_2 ( & V_20 ) ;
V_341 = F_161 ( V_344 ) ;
V_335 = F_163 ( F_159 ( V_341 ) ) ;
if ( F_122 ( V_335 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_158 ( V_335 ) ;
V_8 = V_10 -> V_8 ;
V_357 = V_8 -> V_2 ;
V_301 = V_346 -> V_165 ;
if ( ! V_301 -> V_206 || ! V_301 -> V_215 )
goto V_358;
V_3 = F_118 ( (struct V_120 * ) & V_272 ,
V_301 -> V_206 ,
strlen ( V_301 -> V_206 ) ,
V_301 -> V_222 ) ;
if ( ! V_3 )
goto V_358;
if ( ! F_107 ( V_357 , (struct V_120 * ) & V_272 , V_301 ) ||
! F_133 ( V_8 , V_301 ) ||
! F_145 ( V_10 , V_301 -> V_215 ) ) {
V_3 = 0 ;
goto V_358;
}
V_3 = F_160 ( V_344 , V_346 ) ;
V_358:
F_3 ( & V_20 ) ;
F_155 ( V_335 ) ;
return V_3 ;
}
int
F_164 ( int V_317 , struct V_7 * V_359 , const char * V_360 ,
const struct V_361 * V_362 , unsigned int * V_363 ,
struct V_364 * * V_365 , int V_232 )
{
char * V_366 ;
int V_3 = 0 ;
* V_363 = 0 ;
* V_365 = NULL ;
if ( V_359 -> V_23 == 0 ) {
V_366 = F_43 ( 2 +
F_86 ( V_359 -> V_322 ,
V_367 * 2 )
+ 1 + 4 + 2 ,
V_144 ) ;
if ( V_366 == NULL )
return - V_108 ;
V_366 [ 0 ] = '\\' ;
V_366 [ 1 ] = '\\' ;
strcpy ( V_366 + 2 , V_359 -> V_322 ) ;
strcpy ( V_366 + 2 + strlen ( V_359 -> V_322 ) , L_250 ) ;
V_3 = F_153 ( V_317 , V_359 , V_366 , NULL , V_362 ) ;
F_4 ( 1 , L_251 , V_3 , V_359 -> V_23 ) ;
F_10 ( V_366 ) ;
}
if ( V_3 == 0 )
V_3 = F_165 ( V_317 , V_359 , V_360 , V_365 ,
V_363 , V_362 , V_232 ) ;
return V_3 ;
}
static inline void
F_166 ( struct V_368 * V_369 )
{
struct V_369 * V_370 = V_369 -> V_370 ;
F_167 ( F_168 ( V_370 ) ) ;
F_169 ( V_370 , L_252 ,
& V_371 [ 0 ] , L_253 , & V_372 [ 0 ] ) ;
}
static inline void
F_170 ( struct V_368 * V_369 )
{
struct V_369 * V_370 = V_369 -> V_370 ;
F_167 ( F_168 ( V_370 ) ) ;
F_169 ( V_370 , L_254 ,
& V_371 [ 1 ] , L_255 , & V_372 [ 1 ] ) ;
}
static inline void
F_166 ( struct V_368 * V_369 )
{
}
static inline void
F_170 ( struct V_368 * V_369 )
{
}
static void F_171 ( char * V_373 , char * V_374 , unsigned int V_103 )
{
unsigned int V_173 , V_174 ;
for ( V_173 = 0 , V_174 = 0 ; V_173 < ( V_103 ) ; V_173 ++ ) {
V_373 [ V_174 ] = 'A' + ( 0x0F & ( V_374 [ V_173 ] >> 4 ) ) ;
V_373 [ V_174 + 1 ] = 'A' + ( 0x0F & V_374 [ V_173 ] ) ;
V_174 += 2 ;
}
}
static int
F_172 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_217 . V_218 != V_219 ) {
struct V_368 * V_368 = V_2 -> V_26 ;
V_3 = V_368 -> V_375 -> V_376 ( V_368 ,
(struct V_120 * ) & V_2 -> V_217 ,
sizeof( V_2 -> V_217 ) ) ;
if ( V_3 < 0 ) {
struct V_262 * V_263 ;
struct V_268 * V_269 ;
V_263 = (struct V_262 * ) & V_2 -> V_217 ;
V_269 = (struct V_268 * ) & V_2 -> V_217 ;
if ( V_269 -> V_377 == V_267 )
F_22 ( 1 , L_256
L_257 ,
& V_269 -> V_271 , V_3 ) ;
else
F_22 ( 1 , L_256
L_258 ,
& V_263 -> V_265 . V_266 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_173 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_378 * V_379 ;
struct V_44 * V_380 ;
V_379 = F_94 ( sizeof( struct V_378 ) ,
V_144 ) ;
if ( V_379 ) {
V_379 -> V_381 . V_382 . V_383 = 32 ;
if ( V_2 -> V_310 &&
V_2 -> V_310 [ 0 ] != 0 )
F_171 ( V_379 -> V_381 .
V_382 . V_384 ,
V_2 -> V_310 ,
V_226 ) ;
else
F_171 ( V_379 -> V_381 .
V_382 . V_384 ,
V_385 ,
V_226 ) ;
V_379 -> V_381 . V_382 . V_386 = 32 ;
if ( V_2 -> V_309 &&
V_2 -> V_309 [ 0 ] != 0 )
F_171 ( V_379 -> V_381 .
V_382 . V_387 ,
V_2 -> V_309 ,
V_226 ) ;
else
F_171 ( V_379 -> V_381 .
V_382 . V_387 ,
L_259 ,
V_226 ) ;
V_379 -> V_381 . V_382 . V_388 = 0 ;
V_379 -> V_381 . V_382 . V_389 = 0 ;
V_380 = (struct V_44 * ) V_379 ;
V_380 -> V_72 = F_28 ( 0x81000044 ) ;
V_3 = F_174 ( V_2 , V_380 , 0x44 ) ;
F_10 ( V_379 ) ;
F_46 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_3 V_273 ;
int V_390 , V_391 ;
struct V_368 * V_368 = V_2 -> V_26 ;
struct V_120 * V_392 ;
V_392 = (struct V_120 * ) & V_2 -> V_121 ;
if ( V_2 -> V_121 . V_218 == V_267 ) {
V_273 = ( (struct V_268 * ) V_392 ) -> V_275 ;
V_390 = sizeof( struct V_268 ) ;
V_391 = V_267 ;
} else {
V_273 = ( (struct V_262 * ) V_392 ) -> V_274 ;
V_390 = sizeof( struct V_262 ) ;
V_391 = V_261 ;
}
if ( V_368 == NULL ) {
V_3 = F_175 ( F_109 ( V_2 ) , V_391 , V_393 ,
V_394 , & V_368 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_260 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_261 ) ;
V_2 -> V_26 = V_368 ;
V_368 -> V_370 -> V_395 = V_100 ;
if ( V_391 == V_267 )
F_170 ( V_368 ) ;
else
F_166 ( V_368 ) ;
}
V_3 = F_172 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_368 -> V_370 -> V_396 = 7 * V_79 ;
V_368 -> V_370 -> V_397 = 5 * V_79 ;
if ( V_2 -> V_229 ) {
if ( V_368 -> V_370 -> V_398 < ( 200 * 1024 ) )
V_368 -> V_370 -> V_398 = 200 * 1024 ;
if ( V_368 -> V_370 -> V_399 < ( 140 * 1024 ) )
V_368 -> V_370 -> V_399 = 140 * 1024 ;
}
if ( V_2 -> V_308 ) {
int V_400 = 1 ;
V_3 = F_176 ( V_368 , V_401 , V_402 ,
( char * ) & V_400 , sizeof( V_400 ) ) ;
if ( V_3 )
F_4 ( 1 , L_262 , V_3 ) ;
}
F_4 ( 1 , L_263 ,
V_368 -> V_370 -> V_398 ,
V_368 -> V_370 -> V_399 , V_368 -> V_370 -> V_396 ) ;
V_3 = V_368 -> V_375 -> V_403 ( V_368 , V_392 , V_390 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_264 , V_3 ) ;
F_9 ( V_368 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_273 == F_104 ( V_276 ) )
V_3 = F_173 ( V_2 ) ;
return V_3 ;
}
static int
F_127 ( struct V_1 * V_2 )
{
T_3 * V_273 ;
struct V_268 * V_279 = (struct V_268 * ) & V_2 -> V_121 ;
struct V_262 * V_272 = (struct V_262 * ) & V_2 -> V_121 ;
if ( V_2 -> V_121 . V_218 == V_267 )
V_273 = & V_279 -> V_275 ;
else
V_273 = & V_272 -> V_274 ;
if ( * V_273 == 0 ) {
int V_3 ;
* V_273 = F_104 ( V_122 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_273 = F_104 ( V_276 ) ;
}
return F_17 ( V_2 ) ;
}
void F_177 ( int V_317 , struct V_9 * V_10 ,
struct V_340 * V_341 , struct V_164 * V_404 )
{
T_4 V_405 = F_178 ( V_10 -> V_406 . V_407 ) ;
if ( V_404 && V_404 -> V_235 ) {
V_10 -> V_406 . V_407 = 0 ;
V_10 -> V_408 = 0 ;
F_4 ( 1 , L_265 ) ;
return;
} else if ( V_404 )
V_10 -> V_408 = 1 ;
if ( V_10 -> V_408 == 0 ) {
F_4 ( 1 , L_266 ) ;
return;
}
if ( ! F_179 ( V_317 , V_10 ) ) {
T_4 V_409 = F_178 ( V_10 -> V_406 . V_407 ) ;
F_4 ( 1 , L_267 , V_409 ) ;
if ( V_404 == NULL ) {
if ( ( V_405 & V_410 ) == 0 )
V_409 &= ~ V_410 ;
if ( ( V_405 & V_411 ) == 0 ) {
if ( V_409 & V_411 )
F_22 ( 1 , L_268 ) ;
V_409 &= ~ V_411 ;
} else if ( ( V_409 & V_411 ) == 0 ) {
F_22 ( 1 , L_269 ) ;
F_22 ( 1 , L_270 ) ;
}
}
if ( V_409 & V_412 )
F_22 ( 1 , L_271 ) ;
V_409 &= V_413 ;
if ( V_404 && V_404 -> V_248 )
V_409 &= ~ V_410 ;
else if ( V_410 & V_409 ) {
F_4 ( 1 , L_272 ) ;
if ( V_341 )
V_341 -> V_350 |=
V_414 ;
}
if ( V_404 && V_404 -> V_192 == 0 )
V_409 &= ~ V_411 ;
else if ( V_409 & V_411 ) {
F_4 ( 1 , L_273 ) ;
if ( V_341 )
V_341 -> V_350 |=
V_415 ;
}
F_4 ( 1 , L_274 , ( int ) V_409 ) ;
#ifdef F_72
if ( V_409 & V_416 )
F_4 ( 1 , L_275 ) ;
if ( V_409 & V_417 )
F_4 ( 1 , L_276 ) ;
if ( V_409 & V_411 )
F_4 ( 1 , L_277 ) ;
if ( V_409 & V_418 )
F_4 ( 1 , L_278 ) ;
if ( V_409 & V_410 )
F_4 ( 1 , L_279 ) ;
if ( V_409 & V_419 )
F_4 ( 1 , L_280 ) ;
if ( V_409 & V_420 )
F_4 ( 1 , L_281 ) ;
if ( V_409 & V_421 )
F_4 ( 1 , L_282 ) ;
if ( V_409 & V_412 )
F_4 ( 1 , L_283 ) ;
#endif
if ( F_180 ( V_317 , V_10 , V_409 ) ) {
if ( V_404 == NULL ) {
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
void F_181 ( struct V_164 * V_422 ,
struct V_340 * V_341 )
{
F_126 ( & V_341 -> V_423 , V_424 ) ;
F_182 ( & V_341 -> V_425 ) ;
V_341 -> V_426 = V_427 ;
V_341 -> V_223 = V_422 -> V_223 ;
V_341 -> V_224 = V_422 -> V_224 ;
V_341 -> V_352 = V_422 -> V_185 ;
V_341 -> V_353 = V_422 -> V_186 ;
if ( V_422 -> V_198 )
V_341 -> V_428 = V_422 -> V_256 ;
if ( V_422 -> V_199 )
V_341 -> V_429 = V_422 -> V_257 ;
V_341 -> V_354 = V_422 -> V_188 ;
V_341 -> V_355 = V_422 -> V_187 ;
F_4 ( 1 , L_291 ,
V_341 -> V_354 , V_341 -> V_355 ) ;
V_341 -> V_194 = V_422 -> V_194 ;
V_341 -> V_320 = V_422 -> V_320 ;
if ( V_422 -> V_231 )
V_341 -> V_350 |= V_430 ;
if ( V_422 -> V_242 )
V_341 -> V_350 |= V_431 ;
if ( V_422 -> V_193 )
V_341 -> V_350 |= V_432 ;
if ( V_422 -> V_232 )
V_341 -> V_350 |= V_433 ;
if ( V_422 -> V_200 )
V_341 -> V_350 |= V_434 ;
if ( V_422 -> V_233 )
V_341 -> V_350 |= V_435 ;
if ( V_422 -> V_237 )
V_341 -> V_350 |= V_436 ;
if ( V_422 -> V_245 )
V_341 -> V_350 |= V_437 ;
if ( V_422 -> V_241 )
V_341 -> V_350 |= V_438 ;
if ( V_422 -> V_246 )
V_341 -> V_350 |= V_439 ;
if ( V_422 -> V_247 )
V_341 -> V_350 |= V_440 ;
if ( V_422 -> V_198 )
V_341 -> V_350 |= V_441 ;
if ( V_422 -> V_199 )
V_341 -> V_350 |= V_442 ;
if ( V_422 -> V_176 )
V_341 -> V_350 |= V_443 ;
if ( V_422 -> V_177 )
V_341 -> V_350 |= V_444 ;
if ( V_422 -> V_243 )
V_341 -> V_350 |= V_445 ;
if ( V_422 -> V_253 )
V_341 -> V_350 |= V_446 ;
if ( V_422 -> V_255 )
V_341 -> V_350 |= ( V_447 |
V_430 ) ;
if ( V_422 -> V_252 )
V_341 -> V_350 |= V_448 ;
if ( V_422 -> V_251 ) {
F_4 ( 1 , L_292 ) ;
V_341 -> V_350 |= V_449 ;
}
if ( V_422 -> V_254 ) {
if ( V_422 -> V_233 ) {
F_22 ( 1 , L_293
L_294 ) ;
} else {
V_341 -> V_350 |= V_450 ;
}
}
if ( ( V_422 -> V_247 ) && ( V_422 -> V_243 ) )
F_22 ( 1 , L_295
L_296 ) ;
}
static unsigned int
F_183 ( struct V_9 * V_10 , struct V_164 * V_422 )
{
T_4 V_451 = F_178 ( V_10 -> V_406 . V_407 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_224 = V_422 -> V_224 ? V_422 -> V_224 :
V_452 ;
if ( ! V_10 -> V_408 || ! ( V_451 & V_420 ) )
V_224 = F_66 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_453 & V_454 ) ||
( ! ( V_2 -> V_453 & V_455 ) &&
( V_2 -> V_293 & ( V_295 | V_294 ) ) ) )
V_224 = F_66 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_224 = F_66 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_224 ;
}
static unsigned int
F_184 ( struct V_9 * V_10 , struct V_164 * V_422 )
{
T_4 V_451 = F_178 ( V_10 -> V_406 . V_407 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_223 , V_456 ;
if ( V_10 -> V_408 && ( V_451 & V_419 ) )
V_456 = V_452 ;
else if ( V_2 -> V_453 & V_457 )
V_456 = V_458 ;
else if ( V_2 -> V_18 >= V_459 )
V_456 = V_58 ;
else
V_456 = V_2 -> V_18 - sizeof( V_460 ) ;
V_223 = V_422 -> V_223 ? V_422 -> V_223 : V_456 ;
if ( ! ( V_2 -> V_453 & V_457 ) )
V_223 = F_66 (unsigned int, CIFSMaxBufSize, rsize) ;
V_223 = F_66 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_223 ;
}
static int
F_185 ( int V_317 , struct V_9 * V_10 ,
struct V_340 * V_341 , const char * V_461 )
{
int V_3 ;
T_5 * V_462 ;
V_462 = F_43 ( sizeof( T_5 ) , V_144 ) ;
if ( V_462 == NULL )
return - V_108 ;
V_3 = F_186 ( V_317 , V_10 , V_461 , V_462 ,
0 , V_341 -> V_320 ,
V_341 -> V_350 &
V_433 ) ;
if ( V_3 == - V_463 || V_3 == - V_54 )
V_3 = F_187 ( V_317 , V_10 , V_461 , V_462 ,
V_341 -> V_320 , V_341 -> V_350 &
V_433 ) ;
F_10 ( V_462 ) ;
return V_3 ;
}
static void
F_188 ( struct V_164 * V_301 )
{
F_10 ( V_301 -> V_204 ) ;
F_189 ( V_301 -> V_205 ) ;
if ( V_301 -> V_206 != V_301 -> V_215 + 2 )
F_10 ( V_301 -> V_206 ) ;
F_10 ( V_301 -> V_215 ) ;
F_10 ( V_301 -> V_216 ) ;
F_10 ( V_301 -> V_221 ) ;
F_10 ( V_301 -> V_220 ) ;
}
void
F_190 ( struct V_164 * V_301 )
{
if ( ! V_301 )
return;
F_188 ( V_301 ) ;
F_10 ( V_301 ) ;
}
static char *
F_191 ( const struct V_164 * V_165 ,
const struct V_340 * V_341 )
{
char * V_461 , * V_464 ;
unsigned int V_465 = V_165 -> V_220 ? strlen ( V_165 -> V_220 ) : 0 ;
unsigned int V_466 = F_86 ( V_165 -> V_215 , V_328 + 1 ) ;
V_461 = F_43 ( V_466 + V_465 + 1 , V_144 ) ;
if ( V_461 == NULL )
return F_83 ( - V_108 ) ;
strncpy ( V_461 , V_165 -> V_215 , V_466 ) ;
V_464 = V_461 + V_466 ;
if ( V_465 ) {
strncpy ( V_464 , V_165 -> V_220 , V_465 ) ;
V_464 += V_465 ;
}
* V_464 = '\0' ;
F_192 ( V_461 , F_193 ( V_341 ) ) ;
F_4 ( 1 , L_297 , V_19 , V_461 ) ;
return V_461 ;
}
static int
F_194 ( int V_317 , struct V_7 * V_359 ,
struct V_164 * V_301 , struct V_340 * V_341 ,
int V_467 )
{
int V_3 ;
unsigned int V_468 = 0 ;
struct V_364 * V_469 = NULL ;
char * V_461 = NULL , * V_470 = NULL , * V_471 = NULL ;
V_461 = F_191 ( V_301 , V_341 ) ;
if ( F_122 ( V_461 ) )
return F_123 ( V_461 ) ;
V_470 = V_467 ? V_461 + 1 : V_301 -> V_215 + 1 ;
V_3 = F_164 ( V_317 , V_359 , V_470 , V_341 -> V_320 ,
& V_468 , & V_469 ,
V_341 -> V_350 & V_433 ) ;
if ( ! V_3 && V_468 > 0 ) {
char * V_472 = NULL ;
V_471 = F_195 ( V_341 -> V_162 ,
V_461 + 1 , V_469 ,
& V_472 ) ;
F_196 ( V_469 , V_468 ) ;
if ( F_122 ( V_471 ) ) {
V_3 = F_123 ( V_471 ) ;
V_471 = NULL ;
} else {
F_188 ( V_301 ) ;
memset ( V_301 , '\0' , sizeof( * V_301 ) ) ;
V_3 = F_197 ( V_301 , V_471 ,
V_472 ) ;
}
F_10 ( V_472 ) ;
F_10 ( V_341 -> V_162 ) ;
V_341 -> V_162 = V_471 ;
}
F_10 ( V_461 ) ;
return V_3 ;
}
static int
F_197 ( struct V_164 * V_301 , char * V_473 ,
const char * V_163 )
{
int V_3 = 0 ;
if ( F_84 ( V_473 , V_163 , V_301 ) )
return - V_54 ;
if ( V_301 -> V_202 ) {
F_4 ( 1 , L_298 ) ;
V_301 -> V_204 = F_94 ( 1 , V_144 ) ;
if ( V_301 -> V_204 == NULL )
return - V_108 ;
} else if ( V_301 -> V_204 ) {
F_4 ( 1 , L_299 , V_301 -> V_204 ) ;
} else {
F_198 ( L_300 ) ;
return - V_54 ;
}
if ( V_301 -> V_221 == NULL ) {
V_301 -> V_320 = F_199 () ;
} else {
V_301 -> V_320 = F_200 ( V_301 -> V_221 ) ;
if ( V_301 -> V_320 == NULL ) {
F_22 ( 1 , L_301 ,
V_301 -> V_221 ) ;
return - V_474 ;
}
}
return V_3 ;
}
struct V_164 *
F_201 ( char * V_473 , const char * V_163 )
{
int V_3 ;
struct V_164 * V_301 ;
V_301 = F_94 ( sizeof( struct V_164 ) , V_144 ) ;
if ( ! V_301 )
return F_83 ( - V_108 ) ;
V_3 = F_197 ( V_301 , V_473 , V_163 ) ;
if ( V_3 ) {
F_190 ( V_301 ) ;
V_301 = F_83 ( V_3 ) ;
}
return V_301 ;
}
static inline unsigned int
F_202 ( struct V_340 * V_341 )
{
unsigned int V_475 ;
unsigned int V_476 = V_341 -> V_223 / V_459 ;
if ( V_476 >= V_477 . V_478 )
return V_477 . V_478 ;
else if ( V_476 == 0 )
return V_476 ;
V_475 = V_477 . V_478 / V_476 ;
return V_475 * V_476 ;
}
int
F_203 ( struct V_340 * V_341 , struct V_164 * V_301 )
{
int V_3 = 0 ;
int V_317 ;
struct V_7 * V_359 ;
struct V_9 * V_10 ;
struct V_1 * V_479 ;
char * V_461 ;
struct V_334 * V_335 ;
#ifdef F_204
int V_480 = 0 ;
#endif
V_3 = F_205 ( & V_341 -> V_481 , L_74 , V_482 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_204
V_483:
if ( V_480 ) {
if ( V_10 )
F_147 ( V_10 ) ;
else if ( V_359 )
F_135 ( V_359 ) ;
F_142 ( V_317 ) ;
}
#endif
V_10 = NULL ;
V_359 = NULL ;
V_479 = NULL ;
V_461 = NULL ;
V_335 = NULL ;
V_317 = F_136 () ;
V_479 = F_117 ( V_301 ) ;
if ( F_122 ( V_479 ) ) {
V_3 = F_123 ( V_479 ) ;
F_206 ( & V_341 -> V_481 ) ;
goto V_358;
}
V_359 = F_140 ( V_479 , V_301 ) ;
if ( F_122 ( V_359 ) ) {
V_3 = F_123 ( V_359 ) ;
V_359 = NULL ;
goto V_484;
}
V_10 = F_151 ( V_359 , V_301 ) ;
if ( F_122 ( V_10 ) ) {
V_3 = F_123 ( V_10 ) ;
V_10 = NULL ;
goto V_485;
}
if ( V_10 -> V_8 -> V_453 & V_455 ) {
F_177 ( V_317 , V_10 , V_341 , V_301 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_178 ( V_10 -> V_406 . V_407 ) &
V_412 ) ) {
V_3 = - V_486 ;
goto V_484;
}
} else
V_10 -> V_408 = 0 ;
if ( ! V_10 -> V_487 ) {
F_207 ( V_317 , V_10 ) ;
F_208 ( V_317 , V_10 ) ;
}
V_341 -> V_224 = F_183 ( V_10 , V_301 ) ;
V_341 -> V_223 = F_184 ( V_10 , V_301 ) ;
V_341 -> V_481 . V_478 = F_202 ( V_341 ) ;
V_485:
#ifdef F_204
if ( V_480 == 0 ) {
int V_488 = F_194 ( V_317 , V_359 , V_301 ,
V_341 , false ) ;
if ( ! V_488 ) {
V_480 ++ ;
goto V_483;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_461 = F_209 ( V_301 , V_341 , V_10 ) ;
if ( V_461 == NULL ) {
V_3 = - V_108 ;
goto V_484;
}
V_3 = F_185 ( V_317 , V_10 , V_341 , V_461 ) ;
if ( V_3 != 0 && V_3 != - V_489 ) {
F_10 ( V_461 ) ;
goto V_484;
}
F_10 ( V_461 ) ;
}
if ( V_3 == - V_489 ) {
#ifdef F_204
if ( V_480 > V_490 ) {
V_3 = - V_491 ;
goto V_484;
}
V_3 = F_194 ( V_317 , V_359 , V_301 , V_341 ,
true ) ;
if ( ! V_3 ) {
V_480 ++ ;
goto V_483;
}
goto V_484;
#else
V_3 = - V_463 ;
#endif
}
if ( V_3 )
goto V_484;
V_335 = F_94 ( sizeof *V_335 , V_144 ) ;
if ( V_335 == NULL ) {
V_3 = - V_108 ;
goto V_484;
}
V_335 -> V_492 = V_359 -> V_185 ;
V_335 -> V_493 = V_10 ;
V_335 -> V_339 = V_36 ;
F_210 ( V_494 , & V_335 -> V_338 ) ;
F_210 ( V_337 , & V_335 -> V_338 ) ;
V_341 -> V_342 = V_335 ;
F_2 ( & V_341 -> V_425 ) ;
F_211 ( & V_341 -> V_426 , V_335 ) ;
F_3 ( & V_341 -> V_425 ) ;
F_33 ( V_82 , & V_341 -> V_423 ,
V_495 ) ;
V_484:
if ( V_3 ) {
if ( V_10 )
F_147 ( V_10 ) ;
else if ( V_359 )
F_135 ( V_359 ) ;
else
F_111 ( V_479 ) ;
F_206 ( & V_341 -> V_481 ) ;
}
V_358:
F_142 ( V_317 ) ;
return V_3 ;
}
int
F_153 ( unsigned int V_317 , struct V_7 * V_8 ,
const char * V_496 , struct V_9 * V_10 ,
const struct V_361 * V_362 )
{
struct V_44 * V_145 ;
struct V_44 * V_497 ;
T_6 * V_45 ;
T_7 * V_498 ;
unsigned char * V_499 ;
int V_3 = 0 ;
int V_103 ;
T_1 V_500 , V_501 ;
if ( V_8 == NULL )
return - V_502 ;
V_145 = F_35 () ;
if ( V_145 == NULL )
return - V_108 ;
V_497 = V_145 ;
F_212 ( V_145 , V_503 ,
NULL , 4 ) ;
V_145 -> V_124 = F_213 ( V_8 -> V_2 ) ;
V_145 -> V_504 = V_8 -> V_505 ;
V_45 = ( T_6 * ) V_145 ;
V_498 = ( T_7 * ) V_497 ;
V_45 -> V_506 = 0xFF ;
V_45 -> V_332 = F_214 ( V_507 ) ;
V_499 = & V_45 -> V_508 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_293 & V_509 ) ) {
V_45 -> V_510 = F_214 ( 1 ) ;
* V_499 = 0 ;
V_499 ++ ;
} else {
V_45 -> V_510 = F_214 ( V_511 ) ;
#ifdef F_95
if ( ( V_284 & V_214 ) &&
( V_8 -> V_2 -> V_285 == V_286 ) )
F_215 ( V_10 -> V_205 , V_8 -> V_2 -> V_512 ,
V_8 -> V_2 -> V_293 &
V_513 ? true : false ,
V_499 ) ;
else
#endif
V_3 = F_216 ( V_10 -> V_205 , V_8 -> V_2 -> V_512 ,
V_499 , V_362 ) ;
V_499 += V_511 ;
if ( V_8 -> V_453 & V_514 ) {
* V_499 = 0 ;
V_499 ++ ;
}
}
if ( V_8 -> V_2 -> V_293 &
( V_294 | V_295 ) )
V_145 -> V_515 |= V_516 ;
if ( V_8 -> V_453 & V_517 ) {
V_145 -> V_515 |= V_518 ;
}
if ( V_8 -> V_453 & V_519 ) {
V_145 -> V_515 |= V_520 ;
}
if ( V_8 -> V_453 & V_514 ) {
V_145 -> V_515 |= V_521 ;
V_103 =
F_217 ( ( V_522 * ) V_499 , V_496 ,
6 *
( + 256 ) , V_362 ) ;
V_499 += 2 * V_103 ;
V_499 += 2 ;
} else {
strcpy ( V_499 , V_496 ) ;
V_499 += strlen ( V_496 ) + 1 ;
}
strcpy ( V_499 , L_302 ) ;
V_499 += strlen ( L_302 ) ;
V_499 += 1 ;
V_501 = V_499 - & V_45 -> V_508 [ 0 ] ;
V_45 -> V_68 . V_72 = F_28 ( F_27 (
V_45 -> V_68 . V_72 ) + V_501 ) ;
V_45 -> V_523 = F_214 ( V_501 ) ;
V_3 = F_218 ( V_317 , V_8 , V_145 , V_497 , & V_103 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_524 ;
V_10 -> V_326 = V_87 ;
V_10 -> V_22 = false ;
V_10 -> V_525 = V_497 -> V_526 ;
V_499 = F_219 ( V_497 ) ;
V_500 = F_25 ( V_497 ) ;
V_103 = F_86 ( V_499 , V_500 - 2 ) ;
if ( V_145 -> V_515 & V_521 )
V_524 = true ;
else
V_524 = false ;
if ( V_103 == 3 ) {
if ( ( V_499 [ 0 ] == 'I' ) && ( V_499 [ 1 ] == 'P' ) &&
( V_499 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_303 ) ;
V_10 -> V_487 = 1 ;
}
} else if ( V_103 == 2 ) {
if ( ( V_499 [ 0 ] == 'A' ) && ( V_499 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_304 ) ;
}
}
V_499 += V_103 + 1 ;
V_500 -= ( V_103 + 1 ) ;
strncpy ( V_10 -> V_327 , V_496 , V_328 ) ;
F_10 ( V_10 -> V_527 ) ;
V_10 -> V_527 = F_220 ( V_499 ,
V_500 , V_524 ,
V_362 ) ;
F_4 ( 1 , L_305 , V_10 -> V_527 ) ;
if ( ( V_497 -> V_53 == 3 ) ||
( V_497 -> V_53 == 7 ) )
V_10 -> V_332 = F_221 ( V_498 -> V_528 ) ;
else
V_10 -> V_332 = 0 ;
F_4 ( 1 , L_306 , V_10 -> V_332 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_497 -> V_526 ;
}
F_75 ( V_145 ) ;
return V_3 ;
}
void
F_222 ( struct V_340 * V_341 )
{
struct V_529 * V_530 = & V_341 -> V_426 ;
struct V_531 * V_532 ;
struct V_334 * V_335 ;
F_113 ( & V_341 -> V_423 ) ;
F_2 ( & V_341 -> V_425 ) ;
while ( ( V_532 = F_223 ( V_530 ) ) ) {
V_335 = F_224 ( V_532 , struct V_334 , V_533 ) ;
F_163 ( V_335 ) ;
F_225 ( V_337 , & V_335 -> V_338 ) ;
F_226 ( V_532 , V_530 ) ;
F_3 ( & V_341 -> V_425 ) ;
F_155 ( V_335 ) ;
F_2 ( & V_341 -> V_425 ) ;
}
F_3 ( & V_341 -> V_425 ) ;
F_206 ( & V_341 -> V_481 ) ;
F_10 ( V_341 -> V_162 ) ;
F_227 ( V_341 -> V_320 ) ;
F_10 ( V_341 ) ;
}
int F_141 ( unsigned int V_317 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
V_3 = F_228 ( V_317 , V_8 ) ;
if ( V_3 == - V_111 ) {
V_3 = F_228 ( V_317 , V_8 ) ;
if ( V_3 == - V_111 )
V_3 = - V_534 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_87 ;
else
V_3 = - V_534 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_143 ( unsigned int V_317 , struct V_7 * V_8 ,
struct V_361 * V_535 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_453 = V_2 -> V_453 ;
if ( V_536 == 0 )
V_8 -> V_453 &= ( ~ V_455 ) ;
F_4 ( 1 , L_307 ,
V_2 -> V_293 , V_2 -> V_453 , V_2 -> V_537 ) ;
V_3 = F_229 ( V_317 , V_8 , V_535 ) ;
if ( V_3 ) {
F_22 ( 1 , L_308 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_538 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_538 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_538 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_309 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_318 = V_87 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_538 . V_33 ) ;
V_8 -> V_538 . V_33 = NULL ;
V_8 -> V_538 . V_34 = 0 ;
F_10 ( V_8 -> V_539 ) ;
V_8 -> V_539 = NULL ;
return V_3 ;
}
static struct V_9 *
F_230 ( struct V_340 * V_341 , T_8 V_540 )
{
struct V_9 * V_541 = F_231 ( V_341 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_164 * V_404 ;
char V_204 [ 28 ] ;
V_404 = F_94 ( sizeof( * V_404 ) , V_144 ) ;
if ( V_404 == NULL ) {
V_10 = F_83 ( - V_108 ) ;
goto V_358;
}
snprintf ( V_204 , sizeof( V_204 ) , L_310 , V_540 ) ;
V_404 -> V_204 = V_204 ;
V_404 -> V_320 = V_341 -> V_320 ;
V_404 -> V_185 = V_540 ;
V_404 -> V_184 = V_540 ;
V_404 -> V_215 = V_541 -> V_327 ;
V_404 -> V_230 = V_541 -> V_230 ;
V_404 -> V_236 = V_541 -> V_236 ;
V_404 -> V_249 = V_541 -> V_249 ;
V_404 -> V_235 = ! V_541 -> V_408 ;
V_404 -> V_208 = V_542 ;
F_2 ( & V_20 ) ;
++ V_541 -> V_8 -> V_2 -> V_298 ;
F_3 ( & V_20 ) ;
V_8 = F_140 ( V_541 -> V_8 -> V_2 , V_404 ) ;
if ( F_122 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_111 ( V_541 -> V_8 -> V_2 ) ;
goto V_358;
}
V_10 = F_151 ( V_8 , V_404 ) ;
if ( F_122 ( V_10 ) ) {
F_135 ( V_8 ) ;
goto V_358;
}
if ( V_8 -> V_453 & V_455 )
F_177 ( 0 , V_10 , NULL , V_404 ) ;
V_358:
F_10 ( V_404 ) ;
return V_10 ;
}
struct V_9 *
F_231 ( struct V_340 * V_341 )
{
return F_158 ( F_159 ( V_341 ) ) ;
}
static int
F_232 ( void * V_543 )
{
F_80 () ;
return F_79 ( V_151 ) ? - V_113 : 0 ;
}
static struct V_334 *
F_233 ( struct V_529 * V_530 , T_8 V_544 )
{
struct V_531 * V_532 = V_530 -> V_531 ;
struct V_334 * V_335 ;
while ( V_532 ) {
V_335 = F_224 ( V_532 , struct V_334 , V_533 ) ;
if ( V_335 -> V_492 > V_544 )
V_532 = V_532 -> V_545 ;
else if ( V_335 -> V_492 < V_544 )
V_532 = V_532 -> V_546 ;
else
return V_335 ;
}
return NULL ;
}
static void
F_211 ( struct V_529 * V_530 , struct V_334 * V_547 )
{
struct V_531 * * V_90 = & ( V_530 -> V_531 ) , * V_548 = NULL ;
struct V_334 * V_335 ;
while ( * V_90 ) {
V_335 = F_224 ( * V_90 , struct V_334 , V_533 ) ;
V_548 = * V_90 ;
if ( V_335 -> V_492 > V_547 -> V_492 )
V_90 = & ( ( * V_90 ) -> V_545 ) ;
else
V_90 = & ( ( * V_90 ) -> V_546 ) ;
}
F_234 ( & V_547 -> V_533 , V_548 , V_90 ) ;
F_235 ( & V_547 -> V_533 , V_530 ) ;
}
struct V_334 *
F_236 ( struct V_340 * V_341 )
{
int V_549 ;
T_8 V_540 = F_237 () ;
struct V_334 * V_335 , * V_550 ;
if ( ! ( V_341 -> V_350 & V_447 ) )
return F_163 ( F_159 ( V_341 ) ) ;
F_2 ( & V_341 -> V_425 ) ;
V_335 = F_233 ( & V_341 -> V_426 , V_540 ) ;
if ( V_335 )
F_163 ( V_335 ) ;
F_3 ( & V_341 -> V_425 ) ;
if ( V_335 == NULL ) {
V_550 = F_94 ( sizeof( * V_335 ) , V_144 ) ;
if ( V_550 == NULL )
return F_83 ( - V_108 ) ;
V_550 -> V_492 = V_540 ;
V_550 -> V_493 = F_83 ( - V_486 ) ;
F_210 ( V_551 , & V_550 -> V_338 ) ;
F_210 ( V_337 , & V_550 -> V_338 ) ;
F_163 ( V_550 ) ;
F_2 ( & V_341 -> V_425 ) ;
V_335 = F_233 ( & V_341 -> V_426 , V_540 ) ;
if ( V_335 ) {
F_163 ( V_335 ) ;
F_3 ( & V_341 -> V_425 ) ;
F_10 ( V_550 ) ;
goto V_552;
}
V_335 = V_550 ;
F_211 ( & V_341 -> V_426 , V_335 ) ;
F_3 ( & V_341 -> V_425 ) ;
} else {
V_552:
V_549 = F_238 ( & V_335 -> V_338 , V_551 ,
F_232 ,
V_156 ) ;
if ( V_549 ) {
F_155 ( V_335 ) ;
return F_83 ( V_549 ) ;
}
if ( ! F_122 ( V_335 -> V_493 ) )
return V_335 ;
if ( F_31 ( V_36 , V_335 -> V_339 + V_553 ) ) {
F_155 ( V_335 ) ;
return F_83 ( - V_486 ) ;
}
if ( F_239 ( V_551 , & V_335 -> V_338 ) )
goto V_552;
}
V_335 -> V_493 = F_230 ( V_341 , V_540 ) ;
F_225 ( V_551 , & V_335 -> V_338 ) ;
F_240 ( & V_335 -> V_338 , V_551 ) ;
if ( F_122 ( V_335 -> V_493 ) ) {
F_155 ( V_335 ) ;
return F_83 ( - V_486 ) ;
}
return V_335 ;
}
static void
V_424 ( struct V_75 * V_76 )
{
struct V_340 * V_341 = F_30 ( V_76 , struct V_340 ,
V_423 . V_76 ) ;
struct V_529 * V_530 = & V_341 -> V_426 ;
struct V_531 * V_532 = F_223 ( V_530 ) ;
struct V_531 * V_5 ;
struct V_334 * V_335 ;
F_2 ( & V_341 -> V_425 ) ;
V_532 = F_223 ( V_530 ) ;
while ( V_532 != NULL ) {
V_5 = V_532 ;
V_532 = F_241 ( V_5 ) ;
V_335 = F_224 ( V_5 , struct V_334 , V_533 ) ;
if ( F_157 ( V_494 , & V_335 -> V_338 ) ||
F_57 ( & V_335 -> V_336 ) != 0 ||
F_38 ( V_335 -> V_339 + V_495 , V_36 ) )
continue;
F_163 ( V_335 ) ;
F_225 ( V_337 , & V_335 -> V_338 ) ;
F_226 ( V_5 , V_530 ) ;
F_3 ( & V_341 -> V_425 ) ;
F_155 ( V_335 ) ;
F_2 ( & V_341 -> V_425 ) ;
}
F_3 ( & V_341 -> V_425 ) ;
F_33 ( V_82 , & V_341 -> V_423 ,
V_495 ) ;
}
