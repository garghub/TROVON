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
T_1 V_66 , V_67 , V_68 ;
V_67 = F_21 ( & V_61 -> V_55 . V_56 ) ;
V_66 = F_21 ( & V_47 -> V_55 . V_56 ) ;
if ( V_66 != V_67 )
F_4 ( 1 , L_13
L_14 , V_67 , V_66 ) ;
V_65 = F_21 ( & V_47 -> V_55 . V_57 ) ;
V_48 = V_66 - V_65 ;
if ( V_48 < 0 ) {
F_4 ( 1 , L_15
L_16 , V_66 , V_65 ) ;
return - V_69 ;
}
if ( V_48 == 0 ) {
F_4 ( 1 , L_17 ) ;
return 0 ;
}
V_68 = F_21 ( & V_61 -> V_55 . V_57 ) ;
if ( V_48 < V_68 )
F_4 ( 1 , L_18 ) ;
V_62 = ( char * ) & V_47 -> V_70 . V_71 +
F_21 ( & V_47 -> V_55 . V_72 ) ;
V_63 = ( char * ) & V_61 -> V_70 . V_71 +
F_21 ( & V_61 -> V_55 . V_72 ) ;
V_62 += V_65 ;
V_65 += V_68 ;
if ( V_65 > V_73 ) {
F_4 ( 1 , L_19 , V_65 ) ;
return - V_69 ;
}
F_24 ( V_65 , & V_47 -> V_55 . V_57 ) ;
V_64 = F_25 ( V_60 ) ;
V_64 += V_68 ;
if ( V_64 > V_73 ) {
F_4 ( 1 , L_20 , V_64 ) ;
return - V_69 ;
}
F_26 ( V_64 , V_60 ) ;
V_64 = F_27 ( V_60 -> V_74 ) ;
V_64 += V_68 ;
if ( V_64 > V_58 + V_75 - 4 ) {
F_4 ( 1 , L_21 , V_64 ) ;
return - V_76 ;
}
V_60 -> V_74 = F_28 ( V_64 ) ;
memcpy ( V_62 , V_63 , V_68 ) ;
if ( V_48 != V_68 ) {
F_4 ( 1 , L_22 ) ;
return 1 ;
}
F_4 ( 1 , L_23 ) ;
return 0 ;
}
static void
F_29 ( struct V_77 * V_78 )
{
int V_3 ;
struct V_1 * V_2 = F_30 ( V_78 ,
struct V_1 , V_79 . V_78 ) ;
if ( V_2 -> V_18 == 0 ||
F_31 ( V_36 , V_2 -> V_35 + V_80 - V_81 ) )
goto V_82;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
F_4 ( 1 , L_24 ,
V_2 -> V_83 ) ;
V_82:
F_33 ( V_84 , & V_2 -> V_79 , V_80 ) ;
}
static bool
F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_85 ) {
V_2 -> V_85 = ( char * ) F_35 () ;
if ( ! V_2 -> V_85 ) {
F_22 ( 1 , L_25 ) ;
F_18 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_86 ) {
memset ( V_2 -> V_85 , 0 , sizeof( struct V_44 ) ) ;
}
if ( ! V_2 -> V_87 ) {
V_2 -> V_87 = ( char * ) F_36 () ;
if ( ! V_2 -> V_87 ) {
F_22 ( 1 , L_26 ) ;
F_18 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_87 , 0 , sizeof( struct V_44 ) ) ;
}
return true ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
if ( V_88 > 0 && V_2 -> V_15 == V_89 &&
F_38 ( V_36 , V_2 -> V_35 +
( V_88 * V_80 ) ) ) {
F_22 ( 1 , L_27
L_28 , V_2 -> V_83 ,
( V_88 * V_80 / V_81 ) ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_90 ) ;
return true ;
}
return false ;
}
static unsigned int
F_40 ( struct V_91 * V_92 , struct V_91 * V_93 , unsigned int V_94 ,
T_2 V_95 )
{
T_2 V_96 = 0 ;
while ( V_95 || ! V_93 -> V_97 ) {
int V_98 = F_41 ( V_95 , V_93 -> V_97 ) ;
V_95 -= V_98 ;
V_96 += V_98 ;
if ( V_93 -> V_97 == V_96 ) {
V_93 ++ ;
V_94 -- ;
V_96 = 0 ;
}
}
memcpy ( V_92 , V_93 , sizeof( * V_93 ) * V_94 ) ;
V_92 -> V_99 += V_96 ;
V_92 -> V_97 -= V_96 ;
return V_94 ;
}
static struct V_91 *
F_42 ( struct V_1 * V_2 , unsigned int V_94 )
{
struct V_91 * V_100 ;
if ( V_2 -> V_93 && V_94 <= V_2 -> V_101 )
return V_2 -> V_93 ;
V_100 = F_43 ( sizeof( * V_100 ) * V_94 , V_102 ) ;
if ( V_100 ) {
F_10 ( V_2 -> V_93 ) ;
V_2 -> V_93 = V_100 ;
V_2 -> V_101 = V_94 ;
}
return V_100 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_91 * V_103 ,
unsigned int V_94 , unsigned int V_104 )
{
int V_105 = 0 ;
int V_106 ;
unsigned int V_107 ;
struct V_108 V_109 ;
struct V_91 * V_93 ;
V_93 = F_42 ( V_2 , V_94 ) ;
if ( ! V_93 )
return - V_110 ;
V_109 . V_111 = NULL ;
V_109 . V_112 = 0 ;
for ( V_106 = 0 ; V_104 ; V_106 += V_105 , V_104 -= V_105 ) {
F_16 () ;
if ( F_37 ( V_2 ) ) {
V_106 = - V_113 ;
break;
}
V_107 = F_40 ( V_93 , V_103 , V_94 , V_106 ) ;
V_105 = F_45 ( V_2 -> V_26 , & V_109 ,
V_93 , V_107 , V_104 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_106 = - V_114 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_106 = - V_113 ;
break;
} else if ( V_105 == - V_115 ||
V_105 == - V_113 ||
V_105 == - V_116 ) {
F_46 ( 1000 , 2000 ) ;
V_105 = 0 ;
continue;
} else if ( V_105 <= 0 ) {
F_4 ( 1 , L_29
L_30 , V_104 , V_105 ) ;
F_1 ( V_2 ) ;
V_106 = - V_113 ;
break;
}
}
return V_106 ;
}
int
F_47 ( struct V_1 * V_2 , char * V_117 ,
unsigned int V_104 )
{
struct V_91 V_93 ;
V_93 . V_99 = V_117 ;
V_93 . V_97 = V_104 ;
return F_44 ( V_2 , & V_93 , 1 , V_104 ) ;
}
static bool
F_48 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_118 :
return true ;
case V_119 :
F_4 ( 1 , L_31 ) ;
break;
case V_120 :
F_4 ( 1 , L_32 ) ;
break;
case V_121 :
F_4 ( 1 , L_33 ) ;
F_18 ( 1000 ) ;
F_49 ( (struct V_122 * ) & V_2 -> V_123 , V_124 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_90 ) ;
break;
default:
F_22 ( 1 , L_34 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
static struct V_11 *
F_50 ( struct V_1 * V_2 , struct V_44 * V_117 )
{
struct V_11 * V_125 ;
F_2 ( & V_14 ) ;
F_51 (mid, &server->pending_mid_q, qhead) {
if ( V_125 -> V_125 == V_117 -> V_126 &&
V_125 -> V_38 == V_39 &&
V_125 -> V_127 == V_117 -> V_51 ) {
F_3 ( & V_14 ) ;
return V_125 ;
}
}
F_3 ( & V_14 ) ;
return NULL ;
}
void
F_52 ( struct V_11 * V_125 , bool V_128 )
{
#ifdef F_53
V_125 -> V_129 = V_36 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_128 )
V_125 -> V_38 = V_130 ;
else
V_125 -> V_38 = V_131 ;
F_15 ( & V_125 -> V_37 ) ;
F_3 ( & V_14 ) ;
}
static void
F_54 ( struct V_11 * V_125 , struct V_1 * V_2 ,
struct V_44 * V_117 , int V_128 )
{
if ( V_128 == 0 && F_20 ( V_117 ) > 0 ) {
V_125 -> V_132 = true ;
if ( V_125 -> V_133 ) {
V_128 = F_23 ( V_117 , V_125 -> V_133 ) ;
if ( V_128 > 0 )
return;
V_125 -> V_134 = true ;
return F_52 ( V_125 , V_128 ) ;
}
if ( ! V_2 -> V_86 ) {
F_22 ( 1 , L_35 ) ;
} else {
V_125 -> V_133 = V_117 ;
V_125 -> V_135 = true ;
V_2 -> V_85 = NULL ;
}
return;
}
V_125 -> V_133 = V_117 ;
V_125 -> V_135 = V_2 -> V_86 ;
if ( ! V_125 -> V_132 ) {
if ( V_2 -> V_86 )
V_2 -> V_85 = NULL ;
else
V_2 -> V_87 = NULL ;
}
F_52 ( V_125 , V_128 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_105 ;
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_136 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_56 ( & V_2 -> V_90 ) ;
F_2 ( & V_14 ) ;
if ( F_57 ( & V_2 -> V_137 ) >= V_138 )
F_58 ( & V_2 -> V_137 , V_138 - 1 ) ;
F_3 ( & V_14 ) ;
F_56 ( & V_2 -> V_139 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
if ( ! F_59 ( & V_2 -> V_140 ) ) {
struct V_4 V_141 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_141 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_36 , V_12 -> V_125 ) ;
V_12 -> V_38 = V_142 ;
F_14 ( & V_12 -> V_37 , & V_141 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_37 , V_12 -> V_125 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_59 ( & V_2 -> V_140 ) ) {
F_4 ( 1 , L_38 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_83 ) ;
F_10 ( V_2 -> V_93 ) ;
F_10 ( V_2 ) ;
V_105 = F_60 ( & V_143 ) ;
if ( V_105 > 0 )
F_61 ( V_144 , V_105 + V_145 ,
V_146 ) ;
}
static int
F_62 ( struct V_1 * V_2 , struct V_11 * V_125 )
{
int V_105 ;
char * V_117 = V_2 -> V_87 ;
struct V_44 * V_147 = (struct V_44 * ) V_117 ;
unsigned int V_148 = F_27 ( V_147 -> V_74 ) ;
if ( V_148 > V_58 + V_75 - 4 ) {
F_22 ( 1 , L_39 ,
V_148 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_90 ) ;
return - V_113 ;
}
if ( V_148 > V_149 - 4 ) {
V_2 -> V_86 = true ;
memcpy ( V_2 -> V_85 , V_2 -> V_87 , V_2 -> V_106 ) ;
V_117 = V_2 -> V_85 ;
V_147 = (struct V_44 * ) V_117 ;
}
V_105 = F_47 ( V_2 ,
V_117 + sizeof( struct V_44 ) - 1 ,
V_148 - sizeof( struct V_44 ) + 1 + 4 ) ;
if ( V_105 < 0 )
return V_105 ;
V_2 -> V_106 += V_105 ;
F_63 ( V_147 , V_2 -> V_106 ) ;
V_105 = F_64 ( V_147 , V_147 -> V_126 , V_2 -> V_106 ) ;
if ( V_105 != 0 )
F_65 ( L_40 , V_117 ,
F_66 (unsigned int, server->total_read, 48 ) ) ;
if ( ! V_125 )
return V_105 ;
F_54 ( V_125 , V_2 , V_147 , V_105 ) ;
return 0 ;
}
static int
F_67 ( void * V_150 )
{
int V_105 ;
struct V_1 * V_2 = V_150 ;
unsigned int V_148 ;
char * V_117 = NULL ;
struct V_44 * V_147 = NULL ;
struct V_151 * V_152 = NULL ;
struct V_11 * V_12 ;
V_153 -> V_28 |= V_154 ;
F_4 ( 1 , L_41 , F_68 ( V_153 ) ) ;
V_105 = F_69 ( & V_143 ) ;
if ( V_105 > 1 )
F_61 ( V_144 , V_105 + V_145 ,
V_146 ) ;
F_70 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( ! F_34 ( V_2 ) )
continue;
V_2 -> V_86 = false ;
V_147 = (struct V_44 * ) V_2 -> V_87 ;
V_117 = V_2 -> V_87 ;
V_148 = 4 ;
V_105 = F_47 ( V_2 , V_117 , V_148 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 = V_105 ;
V_148 = F_27 ( V_147 -> V_74 ) ;
F_4 ( 1 , L_42 , V_148 ) ;
if ( ! F_48 ( V_2 , V_117 [ 0 ] ) )
continue;
if ( V_148 < sizeof( struct V_44 ) - 1 - 4 ) {
F_22 ( 1 , L_43 ,
V_148 ) ;
F_1 ( V_2 ) ;
F_39 ( & V_2 -> V_90 ) ;
continue;
}
V_105 = F_47 ( V_2 , V_117 + 4 ,
sizeof( struct V_44 ) - 1 - 4 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 += V_105 ;
V_12 = F_50 ( V_2 , V_147 ) ;
if ( ! V_12 || ! V_12 -> V_155 )
V_105 = F_62 ( V_2 , V_12 ) ;
else
V_105 = V_12 -> V_155 ( V_2 , V_12 ) ;
if ( V_105 < 0 )
continue;
if ( V_2 -> V_86 ) {
V_117 = V_2 -> V_85 ;
V_147 = (struct V_44 * ) V_117 ;
}
V_2 -> V_35 = V_36 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_132 || V_12 -> V_134 )
V_12 -> V_41 ( V_12 ) ;
} else if ( ! F_71 ( V_147 , V_2 ) ) {
F_22 ( 1 , L_44
L_45 , F_57 ( & V_156 ) ) ;
F_65 ( L_46 , V_117 ,
sizeof( struct V_44 ) ) ;
#ifdef F_72
F_73 ( V_147 ) ;
F_74 ( V_2 ) ;
#endif
}
}
F_75 ( V_2 -> V_85 ) ;
if ( V_2 -> V_87 )
F_76 ( V_2 -> V_87 ) ;
V_152 = F_77 ( & V_2 -> V_157 , NULL ) ;
F_55 ( V_2 ) ;
if ( ! V_152 ) {
F_78 ( V_158 ) ;
while ( ! F_79 ( V_153 ) ) {
F_80 () ;
F_78 ( V_158 ) ;
}
F_78 ( V_159 ) ;
}
F_81 ( 0 ) ;
}
static char *
F_82 ( const char * V_160 )
{
const char * V_161 ;
char * V_162 , * V_163 ;
unsigned int V_34 ;
V_161 = V_160 + 2 ;
V_163 = strchr ( V_161 , '\\' ) ;
if ( ! V_163 )
return F_83 ( - V_54 ) ;
V_34 = V_163 - V_161 ;
V_162 = F_43 ( ( V_34 + 1 ) , V_146 ) ;
if ( V_162 == NULL )
return F_83 ( - V_110 ) ;
memcpy ( V_162 , V_161 , V_34 ) ;
V_162 [ V_34 ] = '\0' ;
return V_162 ;
}
static int
F_84 ( const char * V_164 , const char * V_165 ,
struct V_166 * V_167 )
{
char * V_168 , * V_169 , * V_170 ;
char * V_171 = NULL , * V_172 ;
int V_173 ;
unsigned int V_174 , V_175 , V_176 ;
char V_177 [ 2 ] ;
short int V_178 = - 1 ;
short int V_179 = - 1 ;
bool V_180 = false ;
bool V_181 = false ;
char * V_182 = F_85 () -> V_182 ;
V_177 [ 0 ] = ',' ;
V_177 [ 1 ] = 0 ;
memset ( V_167 -> V_183 , 0x20 , V_184 ) ;
for ( V_175 = 0 ; V_175 < F_86 ( V_182 , V_184 ) ; V_175 ++ )
V_167 -> V_183 [ V_175 ] = toupper ( V_182 [ V_175 ] ) ;
V_167 -> V_183 [ V_184 ] = 0 ;
V_167 -> V_185 [ 0 ] = 0 ;
V_167 -> V_186 = F_87 () ;
V_167 -> V_187 = F_87 () ;
V_167 -> V_188 = F_88 () ;
V_167 -> V_189 = V_167 -> V_190 = V_191 | V_192 | V_193 ;
V_167 -> V_194 = 1 ;
V_167 -> V_195 = 1 ;
V_167 -> V_196 = V_197 ;
if ( ! V_164 )
goto V_198;
V_171 = F_89 ( V_164 , V_199 , V_146 ) ;
if ( ! V_171 )
goto V_198;
V_172 = V_171 ;
V_170 = V_172 + strlen ( V_172 ) ;
if ( strncmp ( V_172 , L_47 , 4 ) == 0 ) {
if ( V_172 [ 4 ] != 0 ) {
V_177 [ 0 ] = V_172 [ 4 ] ;
V_172 += 5 ;
} else {
F_4 ( 1 , L_48 ) ;
}
}
V_167 -> V_200 = false ;
V_167 -> V_201 = false ;
while ( ( V_169 = F_90 ( & V_172 , V_177 ) ) != NULL ) {
if ( ! * V_169 )
continue;
if ( ( V_168 = strchr ( V_169 , '=' ) ) != NULL )
* V_168 ++ = '\0' ;
if ( F_91 ( V_169 , L_49 , 10 ) == 0 ) {
V_167 -> V_202 = 0 ;
} else if ( F_91 ( V_169 , L_50 , 12 ) == 0 ) {
V_167 -> V_202 = 1 ;
} else if ( F_91 ( V_169 , L_51 , 4 ) == 0 ) {
if ( ! V_168 ) {
F_92 ( V_203
L_52 ) ;
goto V_198;
} else if ( ! * V_168 ) {
V_167 -> V_204 = 1 ;
}
if ( F_86 ( V_168 , V_205 ) <
V_205 ) {
V_167 -> V_206 = F_93 ( V_168 , V_146 ) ;
if ( ! V_167 -> V_206 ) {
F_92 ( V_203 L_53
L_54 ) ;
goto V_198;
}
} else {
F_92 ( V_203 L_55 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_56 , 4 ) == 0 ) {
if ( ! V_168 ) {
V_167 -> V_207 = NULL ;
continue;
} else if ( V_168 [ 0 ] == 0 ) {
if ( V_168 [ 1 ] != V_177 [ 0 ] ) {
V_167 -> V_207 = NULL ;
continue;
}
}
V_174 = strlen ( V_168 ) ;
if ( ( V_168 [ V_174 ] == 0 ) &&
( V_168 + V_174 < V_170 ) &&
( V_168 [ V_174 + 1 ] == V_177 [ 0 ] ) ) {
V_168 [ V_174 ] = V_177 [ 0 ] ;
V_174 += 2 ;
while ( V_168 [ V_174 ] != 0 ) {
if ( V_168 [ V_174 ] == V_177 [ 0 ] ) {
if ( V_168 [ V_174 + 1 ] ==
V_177 [ 0 ] ) {
V_174 ++ ;
} else {
break;
}
}
V_174 ++ ;
}
if ( V_168 [ V_174 ] == 0 ) {
V_172 = NULL ;
} else {
V_168 [ V_174 ] = 0 ;
V_172 = V_168 + V_174 + 1 ;
}
V_167 -> V_207 = F_94 ( V_174 , V_146 ) ;
if ( V_167 -> V_207 == NULL ) {
F_92 ( V_203 L_53
L_57 ) ;
goto V_198;
}
for ( V_175 = 0 , V_176 = 0 ; V_175 < V_174 ; V_175 ++ , V_176 ++ ) {
V_167 -> V_207 [ V_176 ] = V_168 [ V_175 ] ;
if ( V_168 [ V_175 ] == V_177 [ 0 ]
&& V_168 [ V_175 + 1 ] == V_177 [ 0 ] ) {
V_175 ++ ;
}
}
V_167 -> V_207 [ V_176 ] = 0 ;
} else {
V_167 -> V_207 = F_94 ( V_174 + 1 , V_146 ) ;
if ( V_167 -> V_207 == NULL ) {
F_92 ( V_203 L_53
L_57 ) ;
goto V_198;
}
strcpy ( V_167 -> V_207 , V_168 ) ;
}
} else if ( ! F_91 ( V_169 , L_58 , 2 ) ||
! F_91 ( V_169 , L_59 , 4 ) ) {
if ( ! V_168 || ! * V_168 ) {
V_167 -> V_208 = NULL ;
} else if ( F_86 ( V_168 , V_209 ) <
V_209 ) {
V_167 -> V_208 = F_93 ( V_168 , V_146 ) ;
if ( ! V_167 -> V_208 ) {
F_92 ( V_203 L_53
L_60 ) ;
goto V_198;
}
} else {
F_92 ( V_203 L_61
L_62 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_63 , 3 ) == 0 ) {
if ( ! V_168 || ! * V_168 ) {
F_22 ( 1 , L_64 ) ;
continue;
} else if ( F_91 ( V_168 , L_65 , 5 ) == 0 ) {
V_167 -> V_210 |= V_211 |
V_212 ;
} else if ( F_91 ( V_168 , L_66 , 5 ) == 0 ) {
F_22 ( 1 , L_67 ) ;
goto V_198;
} else if ( F_91 ( V_168 , L_68 , 4 ) == 0 ) {
V_167 -> V_210 |= V_211 ;
} else if ( F_91 ( V_168 , L_69 , 8 ) == 0 ) {
V_167 -> V_210 |= V_213 |
V_212 ;
} else if ( F_91 ( V_168 , L_70 , 7 ) == 0 ) {
V_167 -> V_210 |= V_213 ;
} else if ( F_91 ( V_168 , L_71 , 7 ) == 0 ) {
V_167 -> V_210 |= V_214 |
V_212 ;
} else if ( F_91 ( V_168 , L_72 , 6 ) == 0 ) {
V_167 -> V_210 |= V_214 ;
} else if ( F_91 ( V_168 , L_73 , 5 ) == 0 ) {
V_167 -> V_210 |= V_215 |
V_212 ;
} else if ( F_91 ( V_168 , L_74 , 4 ) == 0 ) {
V_167 -> V_210 |= V_215 ;
} else if ( F_91 ( V_168 , L_75 , 6 ) == 0 ) {
V_167 -> V_210 |= V_214 ;
#ifdef F_95
} else if ( F_91 ( V_168 , L_76 , 6 ) == 0 ) {
V_167 -> V_210 |= V_216 ;
#endif
} else if ( F_91 ( V_168 , L_77 , 4 ) == 0 ) {
V_167 -> V_204 = 1 ;
} else {
F_22 ( 1 , L_78 , V_168 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_79 , 3 ) == 0 ) {
if ( ! V_168 || ! * V_168 ) {
F_22 ( 1 , L_80
L_81 ) ;
} else if ( ( F_91 ( V_168 , L_82 , 4 ) == 0 ) ||
( F_91 ( V_168 , L_83 , 1 ) == 0 ) ) {
continue;
}
} else if ( ( F_91 ( V_169 , L_84 , 3 ) == 0 )
|| ( F_91 ( V_169 , L_85 , 6 ) == 0 )
|| ( F_91 ( V_169 , L_86 , 4 ) == 0 ) ) {
if ( ! V_168 || ! * V_168 ) {
F_92 ( V_203 L_87
L_88 ) ;
goto V_198;
}
if ( ( V_174 = F_86 ( V_168 , 300 ) ) < 300 ) {
V_167 -> V_217 = F_43 ( V_174 + 1 , V_146 ) ;
if ( V_167 -> V_217 == NULL )
goto V_198;
strcpy ( V_167 -> V_217 , V_168 ) ;
if ( strncmp ( V_167 -> V_217 , L_89 , 2 ) == 0 ) {
V_167 -> V_217 [ 0 ] = '\\' ;
V_167 -> V_217 [ 1 ] = '\\' ;
} else if ( strncmp ( V_167 -> V_217 , L_90 , 2 ) != 0 ) {
F_92 ( V_203
L_91
L_92 ) ;
goto V_198;
}
} else {
F_92 ( V_203 L_93 ) ;
goto V_198;
}
} else if ( ( F_91 ( V_169 , L_94 , 3 ) == 0 )
|| ( F_91 ( V_169 , L_95 , 5 ) == 0 ) ) {
if ( ! V_168 || ! * V_168 ) {
F_92 ( V_203 L_96 ) ;
goto V_198;
}
if ( F_86 ( V_168 , 256 ) < 256 ) {
V_167 -> V_218 = F_93 ( V_168 , V_146 ) ;
if ( ! V_167 -> V_218 ) {
F_92 ( V_203 L_53
L_97 ) ;
goto V_198;
}
F_4 ( 1 , L_98 ) ;
} else {
F_92 ( V_203 L_99
L_100 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_101 , 7 ) == 0 ) {
V_167 -> V_219 . V_220 = V_221 ;
if ( ! V_168 || ! * V_168 ) {
F_92 ( V_203 L_102
L_103 ) ;
goto V_198;
}
V_175 = F_96 ( (struct V_122 * ) & V_167 -> V_219 ,
V_168 , strlen ( V_168 ) ) ;
if ( V_175 == 0 ) {
F_92 ( V_203 L_104
L_105 ,
V_168 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_106 , 10 ) == 0 ) {
if ( ! V_168 || ! * V_168 ) {
F_92 ( V_203
L_107 ) ;
goto V_198;
}
if ( ( V_174 = F_86 ( V_168 , 1024 ) ) < 1024 ) {
if ( V_168 [ 0 ] != '/' )
V_174 ++ ;
V_167 -> V_222 = F_43 ( V_174 + 1 , V_146 ) ;
if ( V_167 -> V_222 == NULL )
goto V_198;
if ( V_168 [ 0 ] != '/' ) {
V_167 -> V_222 [ 0 ] = '/' ;
strcpy ( V_167 -> V_222 + 1 , V_168 ) ;
} else
strcpy ( V_167 -> V_222 , V_168 ) ;
F_4 ( 1 , L_108 , V_167 -> V_222 ) ;
} else {
F_92 ( V_203 L_109 ) ;
goto V_198;
}
} else if ( F_91 ( V_169 , L_110 , 9 ) == 0 ) {
if ( ! V_168 || ! * V_168 ) {
F_92 ( V_203 L_111
L_112 ) ;
goto V_198;
}
if ( F_86 ( V_168 , 65 ) < 65 ) {
if ( F_91 ( V_168 , L_113 , 7 ) ) {
V_167 -> V_223 = F_93 ( V_168 ,
V_146 ) ;
if ( ! V_167 -> V_223 ) {
F_92 ( V_203 L_114
L_115
L_116 ) ;
goto V_198;
}
}
F_4 ( 1 , L_117 , V_168 ) ;
} else {
F_92 ( V_203 L_118
L_119 ) ;
goto V_198;
}
} else if ( ! F_91 ( V_169 , L_120 , 3 ) && V_168 && * V_168 ) {
V_167 -> V_187 = F_97 ( V_168 , & V_168 , 0 ) ;
V_180 = true ;
} else if ( ! F_91 ( V_169 , L_121 , 5 ) && V_168 && * V_168 ) {
V_167 -> V_186 = F_97 ( V_168 , & V_168 , 0 ) ;
} else if ( ! F_91 ( V_169 , L_122 , 8 ) ) {
V_178 = 1 ;
} else if ( ! F_91 ( V_169 , L_123 , 10 ) ) {
V_178 = 0 ;
} else if ( ! F_91 ( V_169 , L_124 , 3 ) && V_168 && * V_168 ) {
V_167 -> V_188 = F_97 ( V_168 , & V_168 , 0 ) ;
V_181 = true ;
} else if ( ! F_91 ( V_169 , L_125 , 8 ) ) {
V_179 = 1 ;
} else if ( ! F_91 ( V_169 , L_126 , 10 ) ) {
V_179 = 0 ;
} else if ( F_91 ( V_169 , L_127 , 4 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_190 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_128 , 4 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_189 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_129 , 4 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_189 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_130 , 4 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_224 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_131 , 5 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_225 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_132 , 5 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_226 =
F_97 ( V_168 , & V_168 , 0 ) ;
}
} else if ( F_91 ( V_169 , L_133 , 5 ) == 0 ) {
if ( ! V_168 || ! * V_168 ) {
F_22 ( 1 , L_134 ) ;
continue;
} else if ( F_91 ( V_168 , L_135 , 11 ) == 0 ) {
V_167 -> V_227 = 1 ;
}
} else if ( F_91 ( V_169 , L_136 , 4 ) == 0 ) {
if ( ! V_168 || ! * V_168 || ( * V_168 == ' ' ) ) {
F_4 ( 1 , L_137 ) ;
} else {
memset ( V_167 -> V_183 , 0x20 ,
V_184 ) ;
for ( V_175 = 0 ; V_175 < V_184 ; V_175 ++ ) {
if ( V_168 [ V_175 ] == 0 )
break;
V_167 -> V_183 [ V_175 ] = V_168 [ V_175 ] ;
}
if ( V_175 == V_184 && V_168 [ V_175 ] != 0 )
F_92 ( V_203 L_138
L_139 ) ;
}
} else if ( F_91 ( V_169 , L_140 , 7 ) == 0 ) {
if ( ! V_168 || ! * V_168 || ( * V_168 == ' ' ) ) {
F_4 ( 1 , L_141 ) ;
} else {
memset ( V_167 -> V_185 , 0x20 ,
V_228 ) ;
for ( V_175 = 0 ; V_175 < 15 ; V_175 ++ ) {
if ( V_168 [ V_175 ] == 0 )
break;
else
V_167 -> V_185 [ V_175 ] =
V_168 [ V_175 ] ;
}
if ( V_175 == V_184 && V_168 [ V_175 ] != 0 )
F_92 ( V_203 L_142
L_143 ) ;
}
} else if ( F_91 ( V_169 , L_144 , 7 ) == 0 ) {
if ( V_168 && * V_168 ) {
V_167 -> V_196 = V_81 * F_97 ( V_168 ,
& V_168 , 0 ) ;
if ( V_167 -> V_196 > V_229 ) {
F_22 ( 1 , L_145
L_146 ) ;
goto V_198;
}
}
} else if ( F_91 ( V_169 , L_147 , 4 ) == 0 ) {
} else if ( F_91 ( V_169 , L_148 , 3 ) == 0 ) {
} else if ( F_91 ( V_169 , L_149 , 5 ) == 0 ) {
} else if ( F_91 ( V_169 , L_150 , 2 ) == 0 && strlen ( V_169 ) == 2 ) {
} else if ( F_91 ( V_169 , L_151 , 2 ) == 0 ) {
} else if ( F_91 ( V_169 , L_152 , 11 ) == 0 ) {
V_167 -> V_230 = 1 ;
} else if ( F_91 ( V_169 , L_153 , 10 ) == 0 ) {
V_167 -> V_231 = 1 ;
} else if ( ( F_91 ( V_169 , L_154 , 4 ) == 0 ) ||
( F_91 ( V_169 , L_155 , 6 ) == 0 ) ||
( F_91 ( V_169 , L_156 , 4 ) == 0 ) ||
( F_91 ( V_169 , L_157 , 6 ) == 0 ) ||
( F_91 ( V_169 , L_158 , 5 ) == 0 ) ||
( F_91 ( V_169 , L_159 , 6 ) == 0 ) ||
( F_91 ( V_169 , L_160 , 3 ) == 0 ) ) {
continue;
} else if ( F_91 ( V_169 , L_161 , 4 ) == 0 ) {
V_167 -> V_232 = 1 ;
} else if ( F_91 ( V_169 , L_162 , 4 ) == 0 ) {
V_167 -> V_232 = 0 ;
} else if ( F_91 ( V_169 , L_163 , 4 ) == 0 ) {
V_167 -> V_233 = 0 ;
} else if ( F_91 ( V_169 , L_164 , 6 ) == 0 ) {
V_167 -> V_233 = 1 ;
} else if ( F_91 ( V_169 , L_165 , 8 ) == 0 ) {
V_167 -> V_234 = 1 ;
} else if ( F_91 ( V_169 , L_166 , 10 ) == 0 ) {
V_167 -> V_234 = 0 ;
} else if ( F_91 ( V_169 , L_167 , 3 ) == 0 ) {
V_167 -> V_235 = 1 ;
} else if ( F_91 ( V_169 , L_168 , 5 ) == 0 ) {
V_167 -> V_235 = 0 ;
} else if ( F_91 ( V_169 , L_169 , 5 ) == 0 ) {
V_167 -> V_236 = 1 ;
} else if ( F_91 ( V_169 , L_170 , 10 ) == 0 ) {
V_167 -> V_194 = 1 ;
} else if ( F_91 ( V_169 , L_171 , 12 ) == 0 ) {
V_167 -> V_194 = 0 ;
} else if ( F_91 ( V_169 , L_172 , 6 ) == 0 ) {
V_167 -> V_237 = 1 ;
} else if ( F_91 ( V_169 , L_173 , 7 ) == 0 ) {
V_167 -> V_237 = 1 ;
} else if ( ( F_91 ( V_169 , L_174 , 6 ) == 0 ) ||
( F_91 ( V_169 , L_175 , 10 ) == 0 ) ) {
V_167 -> V_238 = 1 ;
} else if ( F_91 ( V_169 , L_176 , 4 ) == 0 ) {
} else if ( F_91 ( V_169 , L_177 , 6 ) == 0 ) {
} else if ( F_91 ( V_169 , L_178 , 7 ) == 0 ) {
} else if ( F_91 ( V_169 , L_179 , 3 ) == 0 ) {
V_167 -> V_239 = 0 ;
} else if ( ( F_91 ( V_169 , L_180 , 5 ) == 0 ) ||
( F_91 ( V_169 , L_181 , 6 ) == 0 ) ) {
V_167 -> V_239 = 1 ;
if ( V_167 -> V_190 ==
( V_240 & ~ ( V_241 | V_242 ) ) )
V_167 -> V_190 = V_240 ;
} else if ( F_91 ( V_169 , L_182 , 9 ) == 0 ) {
V_167 -> V_243 = 1 ;
} else if ( F_91 ( V_169 , L_183 , 7 ) == 0 ) {
V_167 -> V_244 = 1 ;
} else if ( F_91 ( V_169 , L_184 , 9 ) == 0 ) {
V_167 -> V_244 = 0 ;
} else if ( F_91 ( V_169 , L_185 , 7 ) == 0 ) {
V_167 -> V_245 = true ;
} else if ( F_91 ( V_169 , L_186 , 9 ) == 0 ) {
V_167 -> V_245 = false ;
} else if ( F_91 ( V_169 , L_187 , 6 ) == 0 ) {
V_167 -> V_232 = 0 ;
} else if ( F_91 ( V_169 , L_188 , 6 ) == 0 ) {
V_167 -> V_232 = 1 ;
} else if ( F_91 ( V_169 , L_189 , 6 ) == 0 ) {
V_167 -> V_246 = 0 ;
} else if ( F_91 ( V_169 , L_190 , 4 ) == 0 ) {
V_167 -> V_246 = 1 ;
} else if ( F_91 ( V_169 , L_191 , 12 ) == 0 ) {
V_167 -> V_247 = 1 ;
} else if ( F_91 ( V_169 , L_192 , 10 ) == 0 ) {
V_167 -> V_247 = 0 ;
} else if ( F_91 ( V_169 , L_193 , 7 ) == 0 ) {
V_167 -> V_195 = 1 ;
} else if ( F_91 ( V_169 , L_194 , 9 ) == 0 ) {
V_167 -> V_195 = 0 ;
} else if ( F_91 ( V_169 , L_195 , 12 ) == 0 ) {
V_167 -> V_248 = 1 ;
} else if ( F_91 ( V_169 , L_196 , 7 ) == 0 ) {
V_167 -> V_249 = 1 ;
} else if ( F_91 ( V_169 , L_197 , 9 ) == 0 ) {
V_167 -> V_249 = 0 ;
} else if ( F_91 ( V_169 , L_198 , 3 ) == 0 ) {
V_167 -> V_250 = 0 ;
} else if ( F_91 ( V_169 , L_199 , 5 ) == 0 ) {
V_167 -> V_250 = 1 ;
} else if ( F_91 ( V_169 , L_200 , 6 ) == 0 ) {
V_167 -> V_251 = 1 ;
} else if ( F_91 ( V_169 , L_201 , 4 ) == 0 ) {
V_167 -> V_210 |= V_212 ;
} else if ( F_91 ( V_169 , L_202 , 4 ) == 0 ) {
V_167 -> V_252 = 1 ;
} else if ( F_91 ( V_169 , L_203 , 6 ) == 0 ) {
V_167 -> V_253 = 1 ;
} else if ( F_91 ( V_169 , L_204 , 13 ) == 0 ) {
V_167 -> V_253 = 1 ;
} else if ( F_91 ( V_169 , L_205 , 11 ) == 0 ) {
V_167 -> V_254 = 1 ;
} else if ( F_91 ( V_169 , L_206 , 4 ) == 0 ) {
F_92 ( V_203 L_207
L_208
L_209 ) ;
} else if ( F_91 ( V_169 , L_210 , 3 ) == 0 ) {
#ifndef F_98
F_22 ( 1 , L_211
L_212 ) ;
goto V_198;
#endif
V_167 -> V_255 = true ;
} else if ( F_91 ( V_169 , L_213 , 10 ) == 0 ) {
V_167 -> V_256 = true ;
} else if ( F_91 ( V_169 , L_214 , 8 ) == 0 ) {
V_167 -> V_257 = true ;
} else if ( ! F_91 ( V_169 , L_215 , 9 ) && V_168 && * V_168 ) {
V_173 = F_99 ( V_168 , 0 , & V_167 -> V_258 ) ;
if ( V_173 < 0 ) {
F_22 ( 1 , L_216 ,
V_19 ) ;
goto V_198;
}
V_167 -> V_200 = true ;
} else if ( ! F_91 ( V_169 , L_217 , 9 ) && V_168 && * V_168 ) {
V_173 = F_99 ( V_168 , 0 , & V_167 -> V_259 ) ;
if ( V_173 < 0 ) {
F_22 ( 1 , L_218 ,
V_19 ) ;
goto V_198;
}
V_167 -> V_201 = true ;
} else
F_92 ( V_203 L_219 ,
V_169 ) ;
}
if ( V_167 -> V_217 == NULL ) {
if ( V_165 == NULL ) {
F_92 ( V_203 L_220
L_221 ) ;
goto V_198;
}
if ( ( V_174 = F_86 ( V_165 , 300 ) ) < 300 ) {
V_167 -> V_217 = F_43 ( V_174 + 1 , V_146 ) ;
if ( V_167 -> V_217 == NULL )
goto V_198;
strcpy ( V_167 -> V_217 , V_165 ) ;
if ( strncmp ( V_167 -> V_217 , L_89 , 2 ) == 0 ) {
V_167 -> V_217 [ 0 ] = '\\' ;
V_167 -> V_217 [ 1 ] = '\\' ;
} else if ( strncmp ( V_167 -> V_217 , L_90 , 2 ) != 0 ) {
F_92 ( V_203 L_222
L_223 ) ;
goto V_198;
}
V_168 = strpbrk ( V_167 -> V_217 + 2 , L_224 ) ;
if ( V_168 )
* V_168 = '\\' ;
} else {
F_92 ( V_203 L_93 ) ;
goto V_198;
}
}
#ifndef F_100
if ( V_167 -> V_257 ) {
F_22 ( 1 , L_225
L_226 ) ;
goto V_198;
}
#endif
if ( V_167 -> V_208 == NULL )
V_167 -> V_208 = & V_167 -> V_217 [ 2 ] ;
if ( V_180 )
V_167 -> V_178 = V_178 ;
else if ( V_178 == 1 )
F_92 ( V_260 L_227
L_228 ) ;
if ( V_181 )
V_167 -> V_179 = V_179 ;
else if ( V_179 == 1 )
F_92 ( V_260 L_229
L_230 ) ;
F_10 ( V_171 ) ;
return 0 ;
V_198:
F_10 ( V_171 ) ;
return 1 ;
}
static bool
F_101 ( struct V_122 * V_219 , struct V_122 * V_261 )
{
switch ( V_219 -> V_262 ) {
case V_221 :
return ( V_261 -> V_262 == V_221 ) ;
case V_263 : {
struct V_264 * V_265 = (struct V_264 * ) V_219 ;
struct V_264 * V_266 = (struct V_264 * ) V_261 ;
return ( V_265 -> V_267 . V_268 == V_266 -> V_267 . V_268 ) ;
}
case V_269 : {
struct V_270 * V_271 = (struct V_270 * ) V_219 ;
struct V_270 * V_272 = (struct V_270 * ) & V_261 ;
return F_102 ( & V_271 -> V_273 , & V_272 -> V_273 ) ;
}
default:
F_103 ( 1 ) ;
return false ;
}
}
static bool
F_104 ( struct V_1 * V_2 , struct V_122 * V_274 )
{
T_3 V_224 , * V_275 ;
switch ( V_274 -> V_262 ) {
case V_263 :
V_275 = & ( (struct V_264 * ) & V_2 -> V_123 ) -> V_276 ;
V_224 = ( (struct V_264 * ) V_274 ) -> V_276 ;
break;
case V_269 :
V_275 = & ( (struct V_270 * ) & V_2 -> V_123 ) -> V_277 ;
V_224 = ( (struct V_270 * ) V_274 ) -> V_277 ;
break;
default:
F_103 ( 1 ) ;
return false ;
}
if ( ! V_224 ) {
V_224 = F_105 ( V_124 ) ;
if ( V_224 == * V_275 )
return true ;
V_224 = F_105 ( V_278 ) ;
}
return V_224 == * V_275 ;
}
static bool
F_106 ( struct V_1 * V_2 , struct V_122 * V_274 ,
struct V_122 * V_219 )
{
switch ( V_274 -> V_262 ) {
case V_263 : {
struct V_264 * V_279 = (struct V_264 * ) V_274 ;
struct V_264 * V_280 =
(struct V_264 * ) & V_2 -> V_123 ;
if ( V_279 -> V_267 . V_268 != V_280 -> V_267 . V_268 )
return false ;
break;
}
case V_269 : {
struct V_270 * V_281 = (struct V_270 * ) V_274 ;
struct V_270 * V_282 =
(struct V_270 * ) & V_2 -> V_123 ;
if ( ! F_102 ( & V_281 -> V_273 ,
& V_282 -> V_273 ) )
return false ;
if ( V_281 -> V_283 != V_282 -> V_283 )
return false ;
break;
}
default:
F_103 ( 1 ) ;
return false ;
}
if ( ! F_101 ( V_219 , (struct V_122 * ) & V_2 -> V_219 ) )
return false ;
return true ;
}
static bool
F_107 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
unsigned int V_284 ;
if ( V_167 -> V_210 & ( ~ ( V_212 | V_285 ) ) )
V_284 = V_167 -> V_210 ;
else
V_284 = V_286 | V_167 -> V_210 ;
switch ( V_2 -> V_287 ) {
case V_288 :
if ( ! ( V_284 & ( V_216 | V_289 ) ) )
return false ;
break;
case V_290 :
if ( ! ( V_284 & V_214 ) )
return false ;
break;
case V_291 :
if ( ! ( V_284 & V_215 ) )
return false ;
break;
case V_292 :
if ( ! ( V_284 & V_211 ) )
return false ;
break;
case V_293 :
if ( ! ( V_284 & V_213 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_284 & V_294 ) == 0 &&
( V_2 -> V_295 & V_296 ) )
return false ;
else if ( ( ( V_284 & V_212 ) == V_212 ) &&
( V_2 -> V_295 &
( V_297 | V_296 ) ) == 0 )
return false ;
return true ;
}
static int F_108 ( struct V_1 * V_2 , struct V_122 * V_274 ,
struct V_166 * V_167 )
{
if ( ! F_109 ( F_110 ( V_2 ) , V_153 -> V_298 -> V_299 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_274 ,
(struct V_122 * ) & V_167 -> V_219 ) )
return 0 ;
if ( ! F_104 ( V_2 , V_274 ) )
return 0 ;
if ( ! F_107 ( V_2 , V_167 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_111 ( struct V_122 * V_274 , struct V_166 * V_167 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_51 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_108 ( V_2 , V_274 , V_167 ) )
continue;
++ V_2 -> V_300 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_231 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_112 ( struct V_1 * V_2 )
{
struct V_151 * V_301 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_300 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_113 ( F_110 ( V_2 ) ) ;
F_15 ( & V_2 -> V_136 ) ;
F_3 ( & V_20 ) ;
F_114 ( & V_2 -> V_79 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_301 = F_77 ( & V_2 -> V_157 , NULL ) ;
if ( V_301 )
F_117 ( V_302 , V_301 ) ;
}
static struct V_1 *
F_118 ( struct V_166 * V_303 )
{
struct V_1 * V_304 = NULL ;
struct V_305 V_274 ;
struct V_264 * V_306 = (struct V_264 * ) & V_274 ;
struct V_270 * V_307 = (struct V_270 * ) & V_274 ;
int V_3 ;
memset ( & V_274 , 0 , sizeof( struct V_305 ) ) ;
F_4 ( 1 , L_232 , V_303 -> V_217 , V_303 -> V_208 ) ;
if ( V_303 -> V_208 && V_303 -> V_217 ) {
V_3 = F_119 ( (struct V_122 * ) & V_274 ,
V_303 -> V_208 ,
strlen ( V_303 -> V_208 ) ,
V_303 -> V_224 ) ;
if ( ! V_3 ) {
V_3 = - V_54 ;
goto V_308;
}
} else if ( V_303 -> V_208 ) {
F_22 ( 1 , L_233 ) ;
V_3 = - V_54 ;
goto V_308;
} else {
F_22 ( 1 , L_234
L_235 ) ;
V_3 = - V_54 ;
goto V_308;
}
V_304 = F_111 ( (struct V_122 * ) & V_274 , V_303 ) ;
if ( V_304 )
return V_304 ;
V_304 = F_94 ( sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_304 ) {
V_3 = - V_110 ;
goto V_308;
}
V_3 = F_120 ( V_304 ) ;
if ( V_3 ) {
F_22 ( 1 , L_236 , V_3 ) ;
goto V_308;
}
F_121 ( V_304 , F_122 ( V_153 -> V_298 -> V_299 ) ) ;
V_304 -> V_83 = F_82 ( V_303 -> V_217 ) ;
if ( F_123 ( V_304 -> V_83 ) ) {
V_3 = F_124 ( V_304 -> V_83 ) ;
goto V_309;
}
V_304 -> V_230 = V_303 -> V_230 ;
V_304 -> V_231 = V_303 -> V_231 ;
V_304 -> V_310 = V_303 -> V_227 ;
F_58 ( & V_304 -> V_137 , 0 ) ;
F_125 ( & V_304 -> V_90 ) ;
F_125 ( & V_304 -> V_139 ) ;
F_12 ( & V_304 -> V_140 ) ;
F_126 ( & V_304 -> V_25 ) ;
memcpy ( V_304 -> V_311 ,
V_303 -> V_183 , V_228 ) ;
memcpy ( V_304 -> V_312 ,
V_303 -> V_185 , V_228 ) ;
V_304 -> V_31 = false ;
V_304 -> V_30 = 0 ;
V_304 -> V_35 = V_36 ;
F_12 ( & V_304 -> V_136 ) ;
F_12 ( & V_304 -> V_21 ) ;
F_127 ( & V_304 -> V_79 , F_29 ) ;
V_304 -> V_15 = V_313 ;
memcpy ( & V_304 -> V_219 , & V_303 -> V_219 ,
sizeof( V_304 -> V_219 ) ) ;
++ V_304 -> V_300 ;
if ( V_274 . V_220 == V_269 ) {
F_4 ( 1 , L_237 ) ;
memcpy ( & V_304 -> V_123 , V_307 ,
sizeof( struct V_270 ) ) ;
} else
memcpy ( & V_304 -> V_123 , V_306 ,
sizeof( struct V_264 ) ) ;
V_3 = F_128 ( V_304 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_238 ) ;
goto V_309;
}
F_129 ( V_314 ) ;
V_304 -> V_157 = F_130 ( F_67 ,
V_304 , L_239 ) ;
if ( F_123 ( V_304 -> V_157 ) ) {
V_3 = F_124 ( V_304 -> V_157 ) ;
F_22 ( 1 , L_240 , V_3 ) ;
F_131 ( V_314 ) ;
goto V_309;
}
V_304 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_132 ( & V_304 -> V_136 , & V_315 ) ;
F_3 ( & V_20 ) ;
F_133 ( V_304 ) ;
F_33 ( V_84 , & V_304 -> V_79 , V_80 ) ;
return V_304 ;
V_309:
F_115 ( V_304 ) ;
F_113 ( F_110 ( V_304 ) ) ;
V_308:
if ( V_304 ) {
if ( ! F_123 ( V_304 -> V_83 ) )
F_10 ( V_304 -> V_83 ) ;
if ( V_304 -> V_26 )
F_9 ( V_304 -> V_26 ) ;
F_10 ( V_304 ) ;
}
return F_83 ( V_3 ) ;
}
static int F_134 ( struct V_7 * V_8 , struct V_166 * V_167 )
{
switch ( V_8 -> V_2 -> V_287 ) {
case V_292 :
if ( V_167 -> V_186 != V_8 -> V_186 )
return 0 ;
break;
default:
if ( V_8 -> V_316 == NULL ) {
if ( ! V_167 -> V_204 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_316 ,
V_167 -> V_206 ? V_167 -> V_206 : L_241 ,
V_205 ) )
return 0 ;
if ( strlen ( V_167 -> V_206 ) != 0 &&
V_8 -> V_207 != NULL &&
strncmp ( V_8 -> V_207 ,
V_167 -> V_207 ? V_167 -> V_207 : L_241 ,
V_317 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_135 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_51 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_134 ( V_8 , V_167 ) )
continue;
++ V_8 -> V_318 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_136 ( struct V_7 * V_8 )
{
int V_319 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_242 , V_19 , V_8 -> V_318 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_318 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_320 == V_89 ) {
V_319 = F_137 () ;
F_138 ( V_319 , V_8 ) ;
F_139 ( V_319 ) ;
}
F_140 ( V_8 ) ;
F_112 ( V_2 ) ;
}
static int
F_141 ( struct V_166 * V_167 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_321 , * V_163 , * V_322 ;
T_4 V_34 ;
struct V_323 * V_323 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_264 * V_324 ;
struct V_270 * V_325 ;
struct V_326 * V_327 ;
V_321 = F_43 ( V_328 , V_146 ) ;
if ( ! V_321 )
return - V_110 ;
switch ( V_2 -> V_123 . V_220 ) {
case V_263 :
V_324 = (struct V_264 * ) & V_2 -> V_123 ;
sprintf ( V_321 , L_243 , & V_324 -> V_267 . V_268 ) ;
break;
case V_269 :
V_325 = (struct V_270 * ) & V_2 -> V_123 ;
sprintf ( V_321 , L_244 , & V_325 -> V_273 . V_329 ) ;
break;
default:
F_4 ( 1 , L_245 , V_2 -> V_123 . V_220 ) ;
V_3 = - V_54 ;
goto V_308;
}
F_4 ( 1 , L_246 , V_19 , V_321 ) ;
V_323 = F_142 ( & V_330 , V_321 , L_241 ) ;
if ( F_123 ( V_323 ) ) {
if ( ! V_8 -> V_331 ) {
F_4 ( 1 , L_247 ) ;
V_3 = F_124 ( V_323 ) ;
goto V_308;
}
sprintf ( V_321 , L_248 , V_8 -> V_331 ) ;
F_4 ( 1 , L_246 , V_19 , V_321 ) ;
V_323 = F_142 ( & V_330 , V_321 , L_241 ) ;
if ( F_123 ( V_323 ) ) {
V_3 = F_124 ( V_323 ) ;
goto V_308;
}
}
F_143 ( & V_323 -> V_332 ) ;
V_327 = V_323 -> V_322 . V_169 ;
if ( F_144 ( V_327 ) ) {
V_3 = V_327 ? F_124 ( V_327 ) : - V_54 ;
goto V_333;
}
V_322 = ( char * ) V_327 -> V_169 ;
V_163 = F_145 ( V_322 , V_327 -> V_334 , ':' ) ;
F_4 ( 1 , L_249 , V_322 ) ;
if ( ! V_163 ) {
F_4 ( 1 , L_250 ,
V_327 -> V_334 ) ;
V_3 = - V_54 ;
goto V_333;
}
V_34 = V_163 - V_322 ;
if ( V_34 > V_205 || V_34 <= 0 ) {
F_4 ( 1 , L_251 , V_34 ) ;
V_3 = - V_54 ;
goto V_333;
}
V_167 -> V_206 = F_89 ( V_322 , V_34 , V_146 ) ;
if ( ! V_167 -> V_206 ) {
F_4 ( 1 , L_252 , V_34 ) ;
V_3 = - V_110 ;
goto V_333;
}
F_4 ( 1 , L_253 , V_19 , V_167 -> V_206 ) ;
V_34 = V_323 -> V_334 - ( V_34 + 1 ) ;
if ( V_34 > V_317 || V_34 <= 0 ) {
F_4 ( 1 , L_254 , V_34 ) ;
V_3 = - V_54 ;
F_10 ( V_167 -> V_206 ) ;
V_167 -> V_206 = NULL ;
goto V_333;
}
++ V_163 ;
V_167 -> V_207 = F_89 ( V_163 , V_34 , V_146 ) ;
if ( ! V_167 -> V_207 ) {
F_4 ( 1 , L_255 , V_34 ) ;
V_3 = - V_110 ;
F_10 ( V_167 -> V_206 ) ;
V_167 -> V_206 = NULL ;
goto V_333;
}
V_333:
F_146 ( & V_323 -> V_332 ) ;
F_147 ( V_323 ) ;
V_308:
F_10 ( V_321 ) ;
F_4 ( 1 , L_256 , V_19 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_148 ( struct V_1 * V_2 , struct V_166 * V_303 )
{
int V_3 = - V_110 , V_319 ;
struct V_7 * V_8 ;
struct V_264 * V_274 = (struct V_264 * ) & V_2 -> V_123 ;
struct V_270 * V_281 = (struct V_270 * ) & V_2 -> V_123 ;
V_319 = F_137 () ;
V_8 = F_135 ( V_2 , V_303 ) ;
if ( V_8 ) {
F_4 ( 1 , L_257 , V_8 -> V_320 ) ;
F_7 ( & V_8 -> V_335 ) ;
V_3 = F_149 ( V_319 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_335 ) ;
F_136 ( V_8 ) ;
F_150 ( V_319 ) ;
return F_83 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_258 ) ;
V_3 = F_151 ( V_319 , V_8 ,
V_303 -> V_336 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_335 ) ;
F_136 ( V_8 ) ;
F_150 ( V_319 ) ;
return F_83 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_335 ) ;
F_112 ( V_2 ) ;
F_150 ( V_319 ) ;
return V_8 ;
}
F_4 ( 1 , L_259 ) ;
V_8 = F_152 () ;
if ( V_8 == NULL )
goto V_337;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_123 . V_220 == V_269 )
sprintf ( V_8 -> V_338 , L_260 , & V_281 -> V_273 ) ;
else
sprintf ( V_8 -> V_338 , L_261 , & V_274 -> V_267 ) ;
if ( V_303 -> V_206 ) {
V_8 -> V_316 = F_93 ( V_303 -> V_206 , V_146 ) ;
if ( ! V_8 -> V_316 )
goto V_337;
}
if ( V_303 -> V_207 ) {
V_8 -> V_207 = F_93 ( V_303 -> V_207 , V_146 ) ;
if ( ! V_8 -> V_207 )
goto V_337;
}
if ( V_303 -> V_218 ) {
V_8 -> V_331 = F_93 ( V_303 -> V_218 , V_146 ) ;
if ( ! V_8 -> V_331 )
goto V_337;
}
V_8 -> V_186 = V_303 -> V_186 ;
V_8 -> V_187 = V_303 -> V_187 ;
if ( ( V_303 -> V_210 == 0 ) && V_339 == false ) {
V_339 = true ;
F_22 ( 1 , L_262
L_263
L_264 ) ;
}
V_8 -> V_340 = V_303 -> V_210 ;
F_7 ( & V_8 -> V_335 ) ;
V_3 = F_149 ( V_319 , V_8 ) ;
if ( ! V_3 )
V_3 = F_151 ( V_319 , V_8 , V_303 -> V_336 ) ;
F_11 ( & V_8 -> V_335 ) ;
if ( V_3 )
goto V_337;
F_2 ( & V_20 ) ;
F_132 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_150 ( V_319 ) ;
return V_8 ;
V_337:
F_140 ( V_8 ) ;
F_150 ( V_319 ) ;
return F_83 ( V_3 ) ;
}
static int F_153 ( struct V_9 * V_10 , const char * V_160 )
{
if ( V_10 -> V_341 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_342 , V_160 , V_343 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_154 ( struct V_7 * V_8 , const char * V_160 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_153 ( V_10 , V_160 ) )
continue;
++ V_10 -> V_344 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_155 ( struct V_9 * V_10 )
{
int V_319 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_265 , V_19 , V_10 -> V_344 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_344 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_319 = F_137 () ;
F_156 ( V_319 , V_10 ) ;
F_139 ( V_319 ) ;
F_157 ( V_10 ) ;
F_158 ( V_10 ) ;
F_136 ( V_8 ) ;
}
static struct V_9 *
F_159 ( struct V_7 * V_8 , struct V_166 * V_303 )
{
int V_3 , V_319 ;
struct V_9 * V_10 ;
V_10 = F_154 ( V_8 , V_303 -> V_217 ) ;
if ( V_10 ) {
F_4 ( 1 , L_266 ) ;
F_136 ( V_8 ) ;
if ( V_10 -> V_252 != V_303 -> V_252 )
F_22 ( 1 , L_267
L_268 ) ;
return V_10 ;
}
V_10 = F_160 () ;
if ( V_10 == NULL ) {
V_3 = - V_110 ;
goto V_345;
}
V_10 -> V_8 = V_8 ;
if ( V_303 -> V_207 ) {
V_10 -> V_207 = F_93 ( V_303 -> V_207 , V_146 ) ;
if ( ! V_10 -> V_207 ) {
V_3 = - V_110 ;
goto V_345;
}
}
if ( strchr ( V_303 -> V_217 + 3 , '\\' ) == NULL
&& strchr ( V_303 -> V_217 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_269 ) ;
V_3 = - V_346 ;
goto V_345;
}
V_319 = F_137 () ;
V_3 = F_161 ( V_319 , V_8 , V_303 -> V_217 , V_10 , V_303 -> V_336 ) ;
F_150 ( V_319 ) ;
F_4 ( 1 , L_270 , V_3 ) ;
if ( V_3 )
goto V_345;
if ( V_303 -> V_236 ) {
V_10 -> V_347 &= ~ V_348 ;
F_4 ( 1 , L_271 , V_10 -> V_347 ) ;
}
V_10 -> V_252 = V_303 -> V_252 ;
V_10 -> V_232 = V_303 -> V_232 ;
V_10 -> V_238 = V_303 -> V_238 ;
V_10 -> V_251 = V_303 -> V_251 ;
F_2 ( & V_20 ) ;
F_132 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_162 ( V_10 ) ;
return V_10 ;
V_345:
F_158 ( V_10 ) ;
return F_83 ( V_3 ) ;
}
void
F_163 ( struct V_349 * V_350 )
{
if ( ! V_350 || F_123 ( V_350 ) )
return;
if ( ! F_164 ( & V_350 -> V_351 ) ||
F_165 ( V_352 , & V_350 -> V_353 ) ) {
V_350 -> V_354 = V_36 ;
return;
}
if ( ! F_123 ( F_166 ( V_350 ) ) )
F_155 ( F_166 ( V_350 ) ) ;
F_10 ( V_350 ) ;
return;
}
static inline struct V_349 *
F_167 ( struct V_355 * V_356 )
{
return V_356 -> V_357 ;
}
static int
F_168 ( struct V_358 * V_359 , struct V_360 * V_361 )
{
struct V_355 * V_362 = F_169 ( V_359 ) ;
struct V_355 * V_92 = V_361 -> V_356 ;
if ( ( V_359 -> V_363 & V_364 ) != ( V_361 -> V_28 & V_364 ) )
return 0 ;
if ( ( V_362 -> V_365 & V_366 ) !=
( V_92 -> V_365 & V_366 ) )
return 0 ;
if ( V_92 -> V_226 && V_92 -> V_226 < V_362 -> V_226 )
return 0 ;
if ( V_92 -> V_225 && V_92 -> V_225 < V_362 -> V_225 )
return 0 ;
if ( V_362 -> V_367 != V_92 -> V_367 || V_362 -> V_368 != V_92 -> V_368 )
return 0 ;
if ( V_362 -> V_369 != V_92 -> V_369 ||
V_362 -> V_370 != V_92 -> V_370 )
return 0 ;
if ( strcmp ( V_362 -> V_336 -> V_371 , V_92 -> V_336 -> V_371 ) )
return 0 ;
if ( V_362 -> V_196 != V_92 -> V_196 )
return 0 ;
return 1 ;
}
int
F_170 ( struct V_358 * V_359 , void * V_169 )
{
struct V_360 * V_361 = (struct V_360 * ) V_169 ;
struct V_166 * V_303 ;
struct V_355 * V_356 ;
struct V_1 * V_372 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_349 * V_350 ;
struct V_305 V_274 ;
int V_3 = 0 ;
memset ( & V_274 , 0 , sizeof( struct V_305 ) ) ;
F_2 ( & V_20 ) ;
V_356 = F_169 ( V_359 ) ;
V_350 = F_171 ( F_167 ( V_356 ) ) ;
if ( F_123 ( V_350 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_166 ( V_350 ) ;
V_8 = V_10 -> V_8 ;
V_372 = V_8 -> V_2 ;
V_303 = V_361 -> V_167 ;
if ( ! V_303 -> V_208 || ! V_303 -> V_217 )
goto V_373;
V_3 = F_119 ( (struct V_122 * ) & V_274 ,
V_303 -> V_208 ,
strlen ( V_303 -> V_208 ) ,
V_303 -> V_224 ) ;
if ( ! V_3 )
goto V_373;
if ( ! F_108 ( V_372 , (struct V_122 * ) & V_274 , V_303 ) ||
! F_134 ( V_8 , V_303 ) ||
! F_153 ( V_10 , V_303 -> V_217 ) ) {
V_3 = 0 ;
goto V_373;
}
V_3 = F_168 ( V_359 , V_361 ) ;
V_373:
F_3 ( & V_20 ) ;
F_163 ( V_350 ) ;
return V_3 ;
}
int
F_172 ( int V_319 , struct V_7 * V_374 , const char * V_375 ,
const struct V_376 * V_377 , unsigned int * V_378 ,
struct V_379 * * V_380 , int V_234 )
{
char * V_381 ;
int V_3 = 0 ;
* V_378 = 0 ;
* V_380 = NULL ;
if ( V_374 -> V_23 == 0 ) {
V_381 = F_43 ( 2 +
F_86 ( V_374 -> V_338 ,
V_382 * 2 )
+ 1 + 4 + 2 ,
V_146 ) ;
if ( V_381 == NULL )
return - V_110 ;
V_381 [ 0 ] = '\\' ;
V_381 [ 1 ] = '\\' ;
strcpy ( V_381 + 2 , V_374 -> V_338 ) ;
strcpy ( V_381 + 2 + strlen ( V_374 -> V_338 ) , L_272 ) ;
V_3 = F_161 ( V_319 , V_374 , V_381 , NULL , V_377 ) ;
F_4 ( 1 , L_273 , V_3 , V_374 -> V_23 ) ;
F_10 ( V_381 ) ;
}
if ( V_3 == 0 )
V_3 = F_173 ( V_319 , V_374 , V_375 , V_380 ,
V_378 , V_377 , V_234 ) ;
return V_3 ;
}
static inline void
F_174 ( struct V_383 * V_384 )
{
struct V_384 * V_385 = V_384 -> V_385 ;
F_175 ( F_176 ( V_385 ) ) ;
F_177 ( V_385 , L_274 ,
& V_386 [ 0 ] , L_275 , & V_387 [ 0 ] ) ;
}
static inline void
F_178 ( struct V_383 * V_384 )
{
struct V_384 * V_385 = V_384 -> V_385 ;
F_175 ( F_176 ( V_385 ) ) ;
F_177 ( V_385 , L_276 ,
& V_386 [ 1 ] , L_277 , & V_387 [ 1 ] ) ;
}
static inline void
F_174 ( struct V_383 * V_384 )
{
}
static inline void
F_178 ( struct V_383 * V_384 )
{
}
static void F_179 ( char * V_388 , char * V_389 , unsigned int V_105 )
{
unsigned int V_175 , V_176 ;
for ( V_175 = 0 , V_176 = 0 ; V_175 < ( V_105 ) ; V_175 ++ ) {
V_388 [ V_176 ] = 'A' + ( 0x0F & ( V_389 [ V_175 ] >> 4 ) ) ;
V_388 [ V_176 + 1 ] = 'A' + ( 0x0F & V_389 [ V_175 ] ) ;
V_176 += 2 ;
}
}
static int
F_180 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_219 . V_220 != V_221 ) {
struct V_383 * V_383 = V_2 -> V_26 ;
V_3 = V_383 -> V_390 -> V_391 ( V_383 ,
(struct V_122 * ) & V_2 -> V_219 ,
sizeof( V_2 -> V_219 ) ) ;
if ( V_3 < 0 ) {
struct V_264 * V_265 ;
struct V_270 * V_271 ;
V_265 = (struct V_264 * ) & V_2 -> V_219 ;
V_271 = (struct V_270 * ) & V_2 -> V_219 ;
if ( V_271 -> V_392 == V_269 )
F_22 ( 1 , L_278
L_279 ,
& V_271 -> V_273 , V_3 ) ;
else
F_22 ( 1 , L_278
L_280 ,
& V_265 -> V_267 . V_268 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_393 * V_394 ;
struct V_44 * V_395 ;
V_394 = F_94 ( sizeof( struct V_393 ) ,
V_146 ) ;
if ( V_394 ) {
V_394 -> V_396 . V_397 . V_398 = 32 ;
if ( V_2 -> V_312 &&
V_2 -> V_312 [ 0 ] != 0 )
F_179 ( V_394 -> V_396 .
V_397 . V_399 ,
V_2 -> V_312 ,
V_228 ) ;
else
F_179 ( V_394 -> V_396 .
V_397 . V_399 ,
V_400 ,
V_228 ) ;
V_394 -> V_396 . V_397 . V_401 = 32 ;
if ( V_2 -> V_311 &&
V_2 -> V_311 [ 0 ] != 0 )
F_179 ( V_394 -> V_396 .
V_397 . V_402 ,
V_2 -> V_311 ,
V_228 ) ;
else
F_179 ( V_394 -> V_396 .
V_397 . V_402 ,
L_281 ,
V_228 ) ;
V_394 -> V_396 . V_397 . V_403 = 0 ;
V_394 -> V_396 . V_397 . V_404 = 0 ;
V_395 = (struct V_44 * ) V_394 ;
V_395 -> V_74 = F_28 ( 0x81000044 ) ;
V_3 = F_182 ( V_2 , V_395 , 0x44 ) ;
F_10 ( V_394 ) ;
F_46 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_3 V_275 ;
int V_405 , V_406 ;
struct V_383 * V_383 = V_2 -> V_26 ;
struct V_122 * V_407 ;
V_407 = (struct V_122 * ) & V_2 -> V_123 ;
if ( V_2 -> V_123 . V_220 == V_269 ) {
V_275 = ( (struct V_270 * ) V_407 ) -> V_277 ;
V_405 = sizeof( struct V_270 ) ;
V_406 = V_269 ;
} else {
V_275 = ( (struct V_264 * ) V_407 ) -> V_276 ;
V_405 = sizeof( struct V_264 ) ;
V_406 = V_263 ;
}
if ( V_383 == NULL ) {
V_3 = F_183 ( F_110 ( V_2 ) , V_406 , V_408 ,
V_409 , & V_383 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_282 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_283 ) ;
V_2 -> V_26 = V_383 ;
V_383 -> V_385 -> V_410 = V_102 ;
if ( V_406 == V_269 )
F_178 ( V_383 ) ;
else
F_174 ( V_383 ) ;
}
V_3 = F_180 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_383 -> V_385 -> V_411 = 7 * V_81 ;
V_383 -> V_385 -> V_412 = 5 * V_81 ;
if ( V_2 -> V_231 ) {
if ( V_383 -> V_385 -> V_413 < ( 200 * 1024 ) )
V_383 -> V_385 -> V_413 = 200 * 1024 ;
if ( V_383 -> V_385 -> V_414 < ( 140 * 1024 ) )
V_383 -> V_385 -> V_414 = 140 * 1024 ;
}
if ( V_2 -> V_310 ) {
int V_415 = 1 ;
V_3 = F_184 ( V_383 , V_416 , V_417 ,
( char * ) & V_415 , sizeof( V_415 ) ) ;
if ( V_3 )
F_4 ( 1 , L_284 , V_3 ) ;
}
F_4 ( 1 , L_285 ,
V_383 -> V_385 -> V_413 ,
V_383 -> V_385 -> V_414 , V_383 -> V_385 -> V_411 ) ;
V_3 = V_383 -> V_390 -> V_418 ( V_383 , V_407 , V_405 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_286 , V_3 ) ;
F_9 ( V_383 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_275 == F_105 ( V_278 ) )
V_3 = F_181 ( V_2 ) ;
return V_3 ;
}
static int
F_128 ( struct V_1 * V_2 )
{
T_3 * V_275 ;
struct V_270 * V_281 = (struct V_270 * ) & V_2 -> V_123 ;
struct V_264 * V_274 = (struct V_264 * ) & V_2 -> V_123 ;
if ( V_2 -> V_123 . V_220 == V_269 )
V_275 = & V_281 -> V_277 ;
else
V_275 = & V_274 -> V_276 ;
if ( * V_275 == 0 ) {
int V_3 ;
* V_275 = F_105 ( V_124 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_275 = F_105 ( V_278 ) ;
}
return F_17 ( V_2 ) ;
}
void F_185 ( int V_319 , struct V_9 * V_10 ,
struct V_355 * V_356 , struct V_166 * V_419 )
{
T_5 V_420 = F_186 ( V_10 -> V_421 . V_422 ) ;
if ( V_419 && V_419 -> V_237 ) {
V_10 -> V_421 . V_422 = 0 ;
V_10 -> V_423 = 0 ;
F_4 ( 1 , L_287 ) ;
return;
} else if ( V_419 )
V_10 -> V_423 = 1 ;
if ( V_10 -> V_423 == 0 ) {
F_4 ( 1 , L_288 ) ;
return;
}
if ( ! F_187 ( V_319 , V_10 ) ) {
T_5 V_424 = F_186 ( V_10 -> V_421 . V_422 ) ;
F_4 ( 1 , L_289 , V_424 ) ;
if ( V_419 == NULL ) {
if ( ( V_420 & V_425 ) == 0 )
V_424 &= ~ V_425 ;
if ( ( V_420 & V_426 ) == 0 ) {
if ( V_424 & V_426 )
F_22 ( 1 , L_290 ) ;
V_424 &= ~ V_426 ;
} else if ( ( V_424 & V_426 ) == 0 ) {
F_22 ( 1 , L_291 ) ;
F_22 ( 1 , L_292 ) ;
}
}
if ( V_424 & V_427 )
F_22 ( 1 , L_293 ) ;
V_424 &= V_428 ;
if ( V_419 && V_419 -> V_250 )
V_424 &= ~ V_425 ;
else if ( V_425 & V_424 ) {
F_4 ( 1 , L_294 ) ;
if ( V_356 )
V_356 -> V_365 |=
V_429 ;
}
if ( V_419 && V_419 -> V_194 == 0 )
V_424 &= ~ V_426 ;
else if ( V_424 & V_426 ) {
F_4 ( 1 , L_295 ) ;
if ( V_356 )
V_356 -> V_365 |=
V_430 ;
}
F_4 ( 1 , L_296 , ( int ) V_424 ) ;
#ifdef F_72
if ( V_424 & V_431 )
F_4 ( 1 , L_297 ) ;
if ( V_424 & V_432 )
F_4 ( 1 , L_298 ) ;
if ( V_424 & V_426 )
F_4 ( 1 , L_299 ) ;
if ( V_424 & V_433 )
F_4 ( 1 , L_300 ) ;
if ( V_424 & V_425 )
F_4 ( 1 , L_301 ) ;
if ( V_424 & V_434 )
F_4 ( 1 , L_302 ) ;
if ( V_424 & V_435 )
F_4 ( 1 , L_303 ) ;
if ( V_424 & V_436 )
F_4 ( 1 , L_304 ) ;
if ( V_424 & V_427 )
F_4 ( 1 , L_305 ) ;
#endif
if ( F_188 ( V_319 , V_10 , V_424 ) ) {
if ( V_419 == NULL ) {
F_4 ( 1 , L_306 ) ;
} else
F_22 ( 1 , L_307
L_308
L_309
L_310
L_311
L_312 ) ;
}
}
}
void F_189 ( struct V_166 * V_437 ,
struct V_355 * V_356 )
{
F_127 ( & V_356 -> V_438 , V_439 ) ;
F_190 ( & V_356 -> V_440 ) ;
V_356 -> V_441 = V_442 ;
V_356 -> V_225 = V_437 -> V_225 ;
V_356 -> V_226 = V_437 -> V_226 ;
V_356 -> V_367 = V_437 -> V_187 ;
V_356 -> V_368 = V_437 -> V_188 ;
if ( V_437 -> V_200 )
V_356 -> V_443 = V_437 -> V_258 ;
if ( V_437 -> V_201 )
V_356 -> V_444 = V_437 -> V_259 ;
V_356 -> V_369 = V_437 -> V_190 ;
V_356 -> V_370 = V_437 -> V_189 ;
F_4 ( 1 , L_313 ,
V_356 -> V_369 , V_356 -> V_370 ) ;
V_356 -> V_196 = V_437 -> V_196 ;
V_356 -> V_336 = V_437 -> V_336 ;
if ( V_437 -> V_233 )
V_356 -> V_365 |= V_445 ;
if ( V_437 -> V_244 )
V_356 -> V_365 |= V_446 ;
if ( V_437 -> V_195 )
V_356 -> V_365 |= V_447 ;
if ( V_437 -> V_234 )
V_356 -> V_365 |= V_448 ;
if ( V_437 -> V_202 )
V_356 -> V_365 |= V_449 ;
if ( V_437 -> V_235 )
V_356 -> V_365 |= V_450 ;
if ( V_437 -> V_239 )
V_356 -> V_365 |= V_451 ;
if ( V_437 -> V_247 )
V_356 -> V_365 |= V_452 ;
if ( V_437 -> V_243 )
V_356 -> V_365 |= V_453 ;
if ( V_437 -> V_248 )
V_356 -> V_365 |= V_454 ;
if ( V_437 -> V_249 )
V_356 -> V_365 |= V_455 ;
if ( V_437 -> V_200 )
V_356 -> V_365 |= V_456 ;
if ( V_437 -> V_201 )
V_356 -> V_365 |= V_457 ;
if ( V_437 -> V_178 )
V_356 -> V_365 |= V_458 ;
if ( V_437 -> V_179 )
V_356 -> V_365 |= V_459 ;
if ( V_437 -> V_245 )
V_356 -> V_365 |= V_460 ;
if ( V_437 -> V_255 )
V_356 -> V_365 |= V_461 ;
if ( V_437 -> V_257 )
V_356 -> V_365 |= ( V_462 |
V_445 ) ;
if ( V_437 -> V_254 )
V_356 -> V_365 |= V_463 ;
if ( V_437 -> V_253 ) {
F_4 ( 1 , L_314 ) ;
V_356 -> V_365 |= V_464 ;
}
if ( V_437 -> V_256 ) {
if ( V_437 -> V_235 ) {
F_22 ( 1 , L_315
L_316 ) ;
} else {
V_356 -> V_365 |= V_465 ;
}
}
if ( ( V_437 -> V_249 ) && ( V_437 -> V_245 ) )
F_22 ( 1 , L_317
L_318 ) ;
}
static unsigned int
F_191 ( struct V_9 * V_10 , struct V_166 * V_437 )
{
T_5 V_466 = F_186 ( V_10 -> V_421 . V_422 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_226 ;
if ( V_437 -> V_226 )
V_226 = V_437 -> V_226 ;
else if ( V_10 -> V_423 && ( V_466 & V_435 ) )
V_226 = V_467 ;
else
V_226 = V_468 ;
if ( ! V_10 -> V_423 || ! ( V_466 & V_435 ) )
V_226 = F_66 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_469 & V_470 ) ||
( ! ( V_2 -> V_469 & V_471 ) &&
( V_2 -> V_295 & ( V_297 | V_296 ) ) ) )
V_226 = F_66 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_226 = F_66 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_226 ;
}
static unsigned int
F_192 ( struct V_9 * V_10 , struct V_166 * V_437 )
{
T_5 V_466 = F_186 ( V_10 -> V_421 . V_422 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_225 , V_472 ;
if ( V_10 -> V_423 && ( V_466 & V_434 ) )
V_472 = V_467 ;
else if ( V_2 -> V_469 & V_473 )
V_472 = V_474 ;
else if ( V_2 -> V_18 >= V_475 )
V_472 = V_58 ;
else
V_472 = V_2 -> V_18 - sizeof( V_476 ) ;
V_225 = V_437 -> V_225 ? V_437 -> V_225 : V_472 ;
if ( ! ( V_2 -> V_469 & V_473 ) )
V_225 = F_66 (unsigned int, CIFSMaxBufSize, rsize) ;
V_225 = F_66 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_225 ;
}
static int
F_193 ( int V_319 , struct V_9 * V_10 ,
struct V_355 * V_356 , const char * V_477 )
{
int V_3 ;
T_6 * V_478 ;
V_478 = F_43 ( sizeof( T_6 ) , V_146 ) ;
if ( V_478 == NULL )
return - V_110 ;
V_3 = F_194 ( V_319 , V_10 , V_477 , V_478 ,
0 , V_356 -> V_336 ,
V_356 -> V_365 &
V_448 ) ;
if ( V_3 == - V_479 || V_3 == - V_54 )
V_3 = F_195 ( V_319 , V_10 , V_477 , V_478 ,
V_356 -> V_336 , V_356 -> V_365 &
V_448 ) ;
F_10 ( V_478 ) ;
return V_3 ;
}
static void
F_196 ( struct V_166 * V_303 )
{
F_10 ( V_303 -> V_206 ) ;
F_197 ( V_303 -> V_207 ) ;
if ( V_303 -> V_208 != V_303 -> V_217 + 2 )
F_10 ( V_303 -> V_208 ) ;
F_10 ( V_303 -> V_217 ) ;
F_10 ( V_303 -> V_218 ) ;
F_10 ( V_303 -> V_223 ) ;
F_10 ( V_303 -> V_222 ) ;
}
void
F_198 ( struct V_166 * V_303 )
{
if ( ! V_303 )
return;
F_196 ( V_303 ) ;
F_10 ( V_303 ) ;
}
static char *
F_199 ( const struct V_166 * V_167 ,
const struct V_355 * V_356 )
{
char * V_477 , * V_480 ;
unsigned int V_481 = V_167 -> V_222 ? strlen ( V_167 -> V_222 ) : 0 ;
unsigned int V_482 = F_86 ( V_167 -> V_217 , V_343 + 1 ) ;
V_477 = F_43 ( V_482 + V_481 + 1 , V_146 ) ;
if ( V_477 == NULL )
return F_83 ( - V_110 ) ;
strncpy ( V_477 , V_167 -> V_217 , V_482 ) ;
V_480 = V_477 + V_482 ;
if ( V_481 ) {
strncpy ( V_480 , V_167 -> V_222 , V_481 ) ;
V_480 += V_481 ;
}
* V_480 = '\0' ;
F_200 ( V_477 , F_201 ( V_356 ) ) ;
F_4 ( 1 , L_319 , V_19 , V_477 ) ;
return V_477 ;
}
static int
F_202 ( int V_319 , struct V_7 * V_374 ,
struct V_166 * V_303 , struct V_355 * V_356 ,
int V_483 )
{
int V_3 ;
unsigned int V_484 = 0 ;
struct V_379 * V_485 = NULL ;
char * V_477 = NULL , * V_486 = NULL , * V_487 = NULL ;
V_477 = F_199 ( V_303 , V_356 ) ;
if ( F_123 ( V_477 ) )
return F_124 ( V_477 ) ;
V_486 = V_483 ? V_477 + 1 : V_303 -> V_217 + 1 ;
V_3 = F_172 ( V_319 , V_374 , V_486 , V_356 -> V_336 ,
& V_484 , & V_485 ,
V_356 -> V_365 & V_448 ) ;
if ( ! V_3 && V_484 > 0 ) {
char * V_488 = NULL ;
V_487 = F_203 ( V_356 -> V_164 ,
V_477 + 1 , V_485 ,
& V_488 ) ;
F_204 ( V_485 , V_484 ) ;
if ( F_123 ( V_487 ) ) {
V_3 = F_124 ( V_487 ) ;
V_487 = NULL ;
} else {
F_196 ( V_303 ) ;
memset ( V_303 , '\0' , sizeof( * V_303 ) ) ;
V_3 = F_205 ( V_303 , V_487 ,
V_488 ) ;
}
F_10 ( V_488 ) ;
F_10 ( V_356 -> V_164 ) ;
V_356 -> V_164 = V_487 ;
}
F_10 ( V_477 ) ;
return V_3 ;
}
static int
F_205 ( struct V_166 * V_303 , char * V_489 ,
const char * V_165 )
{
int V_3 = 0 ;
if ( F_84 ( V_489 , V_165 , V_303 ) )
return - V_54 ;
if ( V_303 -> V_204 ) {
F_4 ( 1 , L_320 ) ;
F_10 ( V_303 -> V_206 ) ;
V_303 -> V_206 = NULL ;
} else if ( V_303 -> V_206 ) {
F_4 ( 1 , L_321 , V_303 -> V_206 ) ;
} else {
F_206 ( L_322 ) ;
return - V_54 ;
}
if ( V_303 -> V_223 == NULL ) {
V_303 -> V_336 = F_207 () ;
} else {
V_303 -> V_336 = F_208 ( V_303 -> V_223 ) ;
if ( V_303 -> V_336 == NULL ) {
F_22 ( 1 , L_323 ,
V_303 -> V_223 ) ;
return - V_490 ;
}
}
return V_3 ;
}
struct V_166 *
F_209 ( char * V_489 , const char * V_165 )
{
int V_3 ;
struct V_166 * V_303 ;
V_303 = F_94 ( sizeof( struct V_166 ) , V_146 ) ;
if ( ! V_303 )
return F_83 ( - V_110 ) ;
V_3 = F_205 ( V_303 , V_489 , V_165 ) ;
if ( V_3 ) {
F_198 ( V_303 ) ;
V_303 = F_83 ( V_3 ) ;
}
return V_303 ;
}
static inline unsigned int
F_210 ( struct V_355 * V_356 )
{
unsigned int V_491 ;
unsigned int V_492 = V_356 -> V_225 / V_475 ;
if ( V_492 >= V_493 . V_494 )
return V_493 . V_494 ;
else if ( V_492 == 0 )
return V_492 ;
V_491 = V_493 . V_494 / V_492 ;
return V_491 * V_492 ;
}
int
F_211 ( struct V_355 * V_356 , struct V_166 * V_303 )
{
int V_3 = 0 ;
int V_319 ;
struct V_7 * V_374 ;
struct V_9 * V_10 ;
struct V_1 * V_495 ;
char * V_477 ;
struct V_349 * V_350 ;
#ifdef F_212
int V_496 = 0 ;
#endif
V_3 = F_213 ( & V_356 -> V_497 , L_82 , V_498 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_212
V_499:
if ( V_496 ) {
if ( V_10 )
F_155 ( V_10 ) ;
else if ( V_374 )
F_136 ( V_374 ) ;
F_150 ( V_319 ) ;
}
#endif
V_10 = NULL ;
V_374 = NULL ;
V_495 = NULL ;
V_477 = NULL ;
V_350 = NULL ;
V_319 = F_137 () ;
V_495 = F_118 ( V_303 ) ;
if ( F_123 ( V_495 ) ) {
V_3 = F_124 ( V_495 ) ;
F_214 ( & V_356 -> V_497 ) ;
goto V_373;
}
V_374 = F_148 ( V_495 , V_303 ) ;
if ( F_123 ( V_374 ) ) {
V_3 = F_124 ( V_374 ) ;
V_374 = NULL ;
goto V_500;
}
V_10 = F_159 ( V_374 , V_303 ) ;
if ( F_123 ( V_10 ) ) {
V_3 = F_124 ( V_10 ) ;
V_10 = NULL ;
goto V_501;
}
if ( V_10 -> V_8 -> V_469 & V_471 ) {
F_185 ( V_319 , V_10 , V_356 , V_303 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_186 ( V_10 -> V_421 . V_422 ) &
V_427 ) ) {
V_3 = - V_502 ;
goto V_500;
}
} else
V_10 -> V_423 = 0 ;
if ( ! V_10 -> V_503 ) {
F_215 ( V_319 , V_10 ) ;
F_216 ( V_319 , V_10 ) ;
}
V_356 -> V_226 = F_191 ( V_10 , V_303 ) ;
V_356 -> V_225 = F_192 ( V_10 , V_303 ) ;
V_356 -> V_497 . V_494 = F_210 ( V_356 ) ;
V_501:
#ifdef F_212
if ( V_496 == 0 ) {
int V_504 = F_202 ( V_319 , V_374 , V_303 ,
V_356 , false ) ;
if ( ! V_504 ) {
V_496 ++ ;
goto V_499;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_477 = F_217 ( V_303 , V_356 , V_10 ) ;
if ( V_477 == NULL ) {
V_3 = - V_110 ;
goto V_500;
}
V_3 = F_193 ( V_319 , V_10 , V_356 , V_477 ) ;
if ( V_3 != 0 && V_3 != - V_505 ) {
F_10 ( V_477 ) ;
goto V_500;
}
F_10 ( V_477 ) ;
}
if ( V_3 == - V_505 ) {
#ifdef F_212
if ( V_496 > V_506 ) {
V_3 = - V_507 ;
goto V_500;
}
V_3 = F_202 ( V_319 , V_374 , V_303 , V_356 ,
true ) ;
if ( ! V_3 ) {
V_496 ++ ;
goto V_499;
}
goto V_500;
#else
V_3 = - V_479 ;
#endif
}
if ( V_3 )
goto V_500;
V_350 = F_94 ( sizeof *V_350 , V_146 ) ;
if ( V_350 == NULL ) {
V_3 = - V_110 ;
goto V_500;
}
V_350 -> V_508 = V_374 -> V_187 ;
V_350 -> V_509 = V_10 ;
V_350 -> V_354 = V_36 ;
F_218 ( V_510 , & V_350 -> V_353 ) ;
F_218 ( V_352 , & V_350 -> V_353 ) ;
V_356 -> V_357 = V_350 ;
F_2 ( & V_356 -> V_440 ) ;
F_219 ( & V_356 -> V_441 , V_350 ) ;
F_3 ( & V_356 -> V_440 ) ;
F_33 ( V_84 , & V_356 -> V_438 ,
V_511 ) ;
V_500:
if ( V_3 ) {
if ( V_10 )
F_155 ( V_10 ) ;
else if ( V_374 )
F_136 ( V_374 ) ;
else
F_112 ( V_495 ) ;
F_214 ( & V_356 -> V_497 ) ;
}
V_373:
F_150 ( V_319 ) ;
return V_3 ;
}
int
F_161 ( unsigned int V_319 , struct V_7 * V_8 ,
const char * V_512 , struct V_9 * V_10 ,
const struct V_376 * V_377 )
{
struct V_44 * V_147 ;
struct V_44 * V_513 ;
T_7 * V_45 ;
T_8 * V_514 ;
unsigned char * V_515 ;
int V_3 = 0 ;
int V_105 ;
T_1 V_516 , V_517 ;
if ( V_8 == NULL )
return - V_518 ;
V_147 = F_35 () ;
if ( V_147 == NULL )
return - V_110 ;
V_513 = V_147 ;
F_220 ( V_147 , V_519 ,
NULL , 4 ) ;
V_147 -> V_126 = F_221 ( V_8 -> V_2 ) ;
V_147 -> V_520 = V_8 -> V_521 ;
V_45 = ( T_7 * ) V_147 ;
V_514 = ( T_8 * ) V_513 ;
V_45 -> V_522 = 0xFF ;
V_45 -> V_347 = F_222 ( V_523 ) ;
V_515 = & V_45 -> V_524 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_295 & V_525 ) ) {
V_45 -> V_526 = F_222 ( 1 ) ;
* V_515 = 0 ;
V_515 ++ ;
} else {
V_45 -> V_526 = F_222 ( V_527 ) ;
#ifdef F_95
if ( ( V_286 & V_216 ) &&
( V_8 -> V_2 -> V_287 == V_288 ) )
F_223 ( V_10 -> V_207 , V_8 -> V_2 -> V_528 ,
V_8 -> V_2 -> V_295 &
V_529 ? true : false ,
V_515 ) ;
else
#endif
V_3 = F_224 ( V_10 -> V_207 , V_8 -> V_2 -> V_528 ,
V_515 , V_377 ) ;
V_515 += V_527 ;
if ( V_8 -> V_469 & V_530 ) {
* V_515 = 0 ;
V_515 ++ ;
}
}
if ( V_8 -> V_2 -> V_295 &
( V_296 | V_297 ) )
V_147 -> V_531 |= V_532 ;
if ( V_8 -> V_469 & V_533 ) {
V_147 -> V_531 |= V_534 ;
}
if ( V_8 -> V_469 & V_535 ) {
V_147 -> V_531 |= V_536 ;
}
if ( V_8 -> V_469 & V_530 ) {
V_147 -> V_531 |= V_537 ;
V_105 =
F_225 ( ( V_538 * ) V_515 , V_512 ,
6 *
( + 256 ) , V_377 ) ;
V_515 += 2 * V_105 ;
V_515 += 2 ;
} else {
strcpy ( V_515 , V_512 ) ;
V_515 += strlen ( V_512 ) + 1 ;
}
strcpy ( V_515 , L_324 ) ;
V_515 += strlen ( L_324 ) ;
V_515 += 1 ;
V_517 = V_515 - & V_45 -> V_524 [ 0 ] ;
V_45 -> V_70 . V_74 = F_28 ( F_27 (
V_45 -> V_70 . V_74 ) + V_517 ) ;
V_45 -> V_539 = F_222 ( V_517 ) ;
V_3 = F_226 ( V_319 , V_8 , V_147 , V_513 , & V_105 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_540 ;
V_10 -> V_341 = V_89 ;
V_10 -> V_22 = false ;
V_10 -> V_541 = V_513 -> V_542 ;
V_515 = F_227 ( V_513 ) ;
V_516 = F_25 ( V_513 ) ;
V_105 = F_86 ( V_515 , V_516 - 2 ) ;
if ( V_147 -> V_531 & V_537 )
V_540 = true ;
else
V_540 = false ;
if ( V_105 == 3 ) {
if ( ( V_515 [ 0 ] == 'I' ) && ( V_515 [ 1 ] == 'P' ) &&
( V_515 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_325 ) ;
V_10 -> V_503 = 1 ;
}
} else if ( V_105 == 2 ) {
if ( ( V_515 [ 0 ] == 'A' ) && ( V_515 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_326 ) ;
}
}
V_515 += V_105 + 1 ;
V_516 -= ( V_105 + 1 ) ;
strncpy ( V_10 -> V_342 , V_512 , V_343 ) ;
F_10 ( V_10 -> V_543 ) ;
V_10 -> V_543 = F_228 ( V_515 ,
V_516 , V_540 ,
V_377 ) ;
F_4 ( 1 , L_327 , V_10 -> V_543 ) ;
if ( ( V_513 -> V_53 == 3 ) ||
( V_513 -> V_53 == 7 ) )
V_10 -> V_347 = F_229 ( V_514 -> V_544 ) ;
else
V_10 -> V_347 = 0 ;
F_4 ( 1 , L_328 , V_10 -> V_347 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_513 -> V_542 ;
}
F_75 ( V_147 ) ;
return V_3 ;
}
void
F_230 ( struct V_355 * V_356 )
{
struct V_545 * V_546 = & V_356 -> V_441 ;
struct V_547 * V_548 ;
struct V_349 * V_350 ;
F_114 ( & V_356 -> V_438 ) ;
F_2 ( & V_356 -> V_440 ) ;
while ( ( V_548 = F_231 ( V_546 ) ) ) {
V_350 = F_232 ( V_548 , struct V_349 , V_549 ) ;
F_171 ( V_350 ) ;
F_233 ( V_352 , & V_350 -> V_353 ) ;
F_234 ( V_548 , V_546 ) ;
F_3 ( & V_356 -> V_440 ) ;
F_163 ( V_350 ) ;
F_2 ( & V_356 -> V_440 ) ;
}
F_3 ( & V_356 -> V_440 ) ;
F_214 ( & V_356 -> V_497 ) ;
F_10 ( V_356 -> V_164 ) ;
F_235 ( V_356 -> V_336 ) ;
F_10 ( V_356 ) ;
}
int F_149 ( unsigned int V_319 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
V_3 = F_236 ( V_319 , V_8 ) ;
if ( V_3 == - V_113 ) {
V_3 = F_236 ( V_319 , V_8 ) ;
if ( V_3 == - V_113 )
V_3 = - V_550 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_89 ;
else
V_3 = - V_550 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_151 ( unsigned int V_319 , struct V_7 * V_8 ,
struct V_376 * V_551 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_469 = V_2 -> V_469 ;
if ( V_552 == 0 )
V_8 -> V_469 &= ( ~ V_471 ) ;
F_4 ( 1 , L_329 ,
V_2 -> V_295 , V_2 -> V_469 , V_2 -> V_553 ) ;
V_3 = F_237 ( V_319 , V_8 , V_551 ) ;
if ( V_3 ) {
F_22 ( 1 , L_330 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_554 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_554 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_554 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_331 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_320 = V_89 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_554 . V_33 ) ;
V_8 -> V_554 . V_33 = NULL ;
V_8 -> V_554 . V_34 = 0 ;
F_10 ( V_8 -> V_555 ) ;
V_8 -> V_555 = NULL ;
return V_3 ;
}
static int
F_238 ( struct V_166 * V_167 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_287 ) {
case V_292 :
V_167 -> V_210 = V_556 ;
return 0 ;
case V_290 :
V_167 -> V_210 = V_557 ;
break;
case V_291 :
V_167 -> V_210 = V_558 ;
break;
case V_293 :
V_167 -> V_210 = V_559 ;
break;
case V_288 :
V_167 -> V_210 = V_560 ;
break;
}
return F_141 ( V_167 , V_8 ) ;
}
static struct V_9 *
F_239 ( struct V_355 * V_356 , T_9 V_561 )
{
int V_3 ;
struct V_9 * V_562 = F_240 ( V_356 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_166 * V_419 ;
V_419 = F_94 ( sizeof( * V_419 ) , V_146 ) ;
if ( V_419 == NULL )
return F_83 ( - V_110 ) ;
V_419 -> V_336 = V_356 -> V_336 ;
V_419 -> V_187 = V_561 ;
V_419 -> V_186 = V_561 ;
V_419 -> V_217 = V_562 -> V_342 ;
V_419 -> V_232 = V_562 -> V_232 ;
V_419 -> V_238 = V_562 -> V_238 ;
V_419 -> V_251 = V_562 -> V_251 ;
V_419 -> V_237 = ! V_562 -> V_423 ;
V_3 = F_238 ( V_419 , V_562 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_83 ( V_3 ) ;
goto V_373;
}
F_2 ( & V_20 ) ;
++ V_562 -> V_8 -> V_2 -> V_300 ;
F_3 ( & V_20 ) ;
V_8 = F_148 ( V_562 -> V_8 -> V_2 , V_419 ) ;
if ( F_123 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_112 ( V_562 -> V_8 -> V_2 ) ;
goto V_373;
}
V_10 = F_159 ( V_8 , V_419 ) ;
if ( F_123 ( V_10 ) ) {
F_136 ( V_8 ) ;
goto V_373;
}
if ( V_8 -> V_469 & V_471 )
F_185 ( 0 , V_10 , NULL , V_419 ) ;
V_373:
F_10 ( V_419 -> V_206 ) ;
F_10 ( V_419 -> V_207 ) ;
F_10 ( V_419 ) ;
return V_10 ;
}
struct V_9 *
F_240 ( struct V_355 * V_356 )
{
return F_166 ( F_167 ( V_356 ) ) ;
}
static int
F_241 ( void * V_563 )
{
F_80 () ;
return F_79 ( V_153 ) ? - V_115 : 0 ;
}
static struct V_349 *
F_242 ( struct V_545 * V_546 , T_9 V_564 )
{
struct V_547 * V_548 = V_546 -> V_547 ;
struct V_349 * V_350 ;
while ( V_548 ) {
V_350 = F_232 ( V_548 , struct V_349 , V_549 ) ;
if ( V_350 -> V_508 > V_564 )
V_548 = V_548 -> V_565 ;
else if ( V_350 -> V_508 < V_564 )
V_548 = V_548 -> V_566 ;
else
return V_350 ;
}
return NULL ;
}
static void
F_219 ( struct V_545 * V_546 , struct V_349 * V_567 )
{
struct V_547 * * V_92 = & ( V_546 -> V_547 ) , * V_568 = NULL ;
struct V_349 * V_350 ;
while ( * V_92 ) {
V_350 = F_232 ( * V_92 , struct V_349 , V_549 ) ;
V_568 = * V_92 ;
if ( V_350 -> V_508 > V_567 -> V_508 )
V_92 = & ( ( * V_92 ) -> V_565 ) ;
else
V_92 = & ( ( * V_92 ) -> V_566 ) ;
}
F_243 ( & V_567 -> V_549 , V_568 , V_92 ) ;
F_244 ( & V_567 -> V_549 , V_546 ) ;
}
struct V_349 *
F_245 ( struct V_355 * V_356 )
{
int V_569 ;
T_9 V_561 = F_246 () ;
struct V_349 * V_350 , * V_570 ;
if ( ! ( V_356 -> V_365 & V_462 ) )
return F_171 ( F_167 ( V_356 ) ) ;
F_2 ( & V_356 -> V_440 ) ;
V_350 = F_242 ( & V_356 -> V_441 , V_561 ) ;
if ( V_350 )
F_171 ( V_350 ) ;
F_3 ( & V_356 -> V_440 ) ;
if ( V_350 == NULL ) {
V_570 = F_94 ( sizeof( * V_350 ) , V_146 ) ;
if ( V_570 == NULL )
return F_83 ( - V_110 ) ;
V_570 -> V_508 = V_561 ;
V_570 -> V_509 = F_83 ( - V_502 ) ;
F_218 ( V_571 , & V_570 -> V_353 ) ;
F_218 ( V_352 , & V_570 -> V_353 ) ;
F_171 ( V_570 ) ;
F_2 ( & V_356 -> V_440 ) ;
V_350 = F_242 ( & V_356 -> V_441 , V_561 ) ;
if ( V_350 ) {
F_171 ( V_350 ) ;
F_3 ( & V_356 -> V_440 ) ;
F_10 ( V_570 ) ;
goto V_572;
}
V_350 = V_570 ;
F_219 ( & V_356 -> V_441 , V_350 ) ;
F_3 ( & V_356 -> V_440 ) ;
} else {
V_572:
V_569 = F_247 ( & V_350 -> V_353 , V_571 ,
F_241 ,
V_158 ) ;
if ( V_569 ) {
F_163 ( V_350 ) ;
return F_83 ( V_569 ) ;
}
if ( ! F_123 ( V_350 -> V_509 ) )
return V_350 ;
if ( F_31 ( V_36 , V_350 -> V_354 + V_573 ) ) {
F_163 ( V_350 ) ;
return F_83 ( - V_502 ) ;
}
if ( F_248 ( V_571 , & V_350 -> V_353 ) )
goto V_572;
}
V_350 -> V_509 = F_239 ( V_356 , V_561 ) ;
F_233 ( V_571 , & V_350 -> V_353 ) ;
F_249 ( & V_350 -> V_353 , V_571 ) ;
if ( F_123 ( V_350 -> V_509 ) ) {
F_163 ( V_350 ) ;
return F_83 ( - V_502 ) ;
}
return V_350 ;
}
static void
V_439 ( struct V_77 * V_78 )
{
struct V_355 * V_356 = F_30 ( V_78 , struct V_355 ,
V_438 . V_78 ) ;
struct V_545 * V_546 = & V_356 -> V_441 ;
struct V_547 * V_548 = F_231 ( V_546 ) ;
struct V_547 * V_5 ;
struct V_349 * V_350 ;
F_2 ( & V_356 -> V_440 ) ;
V_548 = F_231 ( V_546 ) ;
while ( V_548 != NULL ) {
V_5 = V_548 ;
V_548 = F_250 ( V_5 ) ;
V_350 = F_232 ( V_5 , struct V_349 , V_549 ) ;
if ( F_165 ( V_510 , & V_350 -> V_353 ) ||
F_57 ( & V_350 -> V_351 ) != 0 ||
F_38 ( V_350 -> V_354 + V_511 , V_36 ) )
continue;
F_171 ( V_350 ) ;
F_233 ( V_352 , & V_350 -> V_353 ) ;
F_234 ( V_5 , V_546 ) ;
F_3 ( & V_356 -> V_440 ) ;
F_163 ( V_350 ) ;
F_2 ( & V_356 -> V_440 ) ;
}
F_3 ( & V_356 -> V_440 ) ;
F_33 ( V_84 , & V_356 -> V_438 ,
V_511 ) ;
}
