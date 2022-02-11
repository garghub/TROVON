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
static int F_20 ( char * V_44 )
{
struct V_45 * V_46 = (struct V_45 * ) V_44 ;
struct V_47 * V_48 ;
int V_49 ;
T_1 V_50 , V_51 ;
if ( V_46 -> V_52 != V_53 )
return 0 ;
if ( V_46 -> V_54 != 10 ) {
F_4 ( 1 , L_9 ) ;
return - V_55 ;
}
V_48 = (struct V_47 * ) V_46 ;
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
if ( V_50 > V_59 ) {
F_22 ( 1 , L_12 ,
V_50 , V_59 ) ;
return - V_55 ;
}
return V_49 ;
}
static int F_23 ( char * V_60 , struct V_45 * V_61 )
{
struct V_47 * V_62 = (struct V_47 * ) V_60 ;
struct V_47 * V_48 = (struct V_47 * ) V_61 ;
char * V_63 ;
char * V_64 ;
int V_49 ;
unsigned int V_65 , V_66 ;
T_1 V_67 , V_68 , V_69 ;
V_68 = F_21 ( & V_62 -> V_56 . V_57 ) ;
V_67 = F_21 ( & V_48 -> V_56 . V_57 ) ;
if ( V_67 != V_68 )
F_4 ( 1 , L_13
L_14 , V_68 , V_67 ) ;
V_66 = F_21 ( & V_48 -> V_56 . V_58 ) ;
V_49 = V_67 - V_66 ;
if ( V_49 < 0 ) {
F_4 ( 1 , L_15
L_16 , V_67 , V_66 ) ;
return - V_70 ;
}
if ( V_49 == 0 ) {
F_4 ( 1 , L_17 ) ;
return 0 ;
}
V_69 = F_21 ( & V_62 -> V_56 . V_58 ) ;
if ( V_49 < V_69 )
F_4 ( 1 , L_18 ) ;
V_63 = ( char * ) & V_48 -> V_71 . V_72 +
F_21 ( & V_48 -> V_56 . V_73 ) ;
V_64 = ( char * ) & V_62 -> V_71 . V_72 +
F_21 ( & V_62 -> V_56 . V_73 ) ;
V_63 += V_66 ;
V_66 += V_69 ;
if ( V_66 > V_74 ) {
F_4 ( 1 , L_19 , V_66 ) ;
return - V_70 ;
}
F_24 ( V_66 , & V_48 -> V_56 . V_58 ) ;
V_65 = F_25 ( V_61 ) ;
V_65 += V_69 ;
if ( V_65 > V_74 ) {
F_4 ( 1 , L_20 , V_65 ) ;
return - V_70 ;
}
F_26 ( V_65 , V_61 ) ;
V_65 = F_27 ( V_61 -> V_75 ) ;
V_65 += V_69 ;
if ( V_65 > V_59 + V_76 - 4 ) {
F_4 ( 1 , L_21 , V_65 ) ;
return - V_77 ;
}
V_61 -> V_75 = F_28 ( V_65 ) ;
memcpy ( V_63 , V_64 , V_69 ) ;
if ( V_49 != V_69 ) {
F_4 ( 1 , L_22 ) ;
return 1 ;
}
F_4 ( 1 , L_23 ) ;
return 0 ;
}
static void
F_29 ( struct V_78 * V_79 )
{
int V_3 ;
struct V_1 * V_2 = F_30 ( V_79 ,
struct V_1 , V_80 . V_79 ) ;
if ( V_2 -> V_18 == 0 ||
F_31 ( V_36 , V_2 -> V_35 + V_81 - V_82 ) )
goto V_83;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
F_4 ( 1 , L_24 ,
V_2 -> V_84 ) ;
V_83:
F_33 ( V_85 , & V_2 -> V_80 , V_81 ) ;
}
static bool
F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_86 ) {
V_2 -> V_86 = ( char * ) F_35 () ;
if ( ! V_2 -> V_86 ) {
F_22 ( 1 , L_25 ) ;
F_18 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_87 ) {
memset ( V_2 -> V_86 , 0 , F_36 ( V_2 ) ) ;
}
if ( ! V_2 -> V_88 ) {
V_2 -> V_88 = ( char * ) F_37 () ;
if ( ! V_2 -> V_88 ) {
F_22 ( 1 , L_26 ) ;
F_18 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_88 , 0 , F_36 ( V_2 ) ) ;
}
return true ;
}
static bool
F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 == V_89 &&
F_39 ( V_36 , V_2 -> V_35 + 2 * V_81 ) ) {
F_22 ( 1 , L_27
L_28 , V_2 -> V_84 ,
( 2 * V_81 ) / V_82 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
return true ;
}
return false ;
}
static unsigned int
F_41 ( struct V_91 * V_92 , struct V_91 * V_93 , unsigned int V_94 ,
T_2 V_95 )
{
T_2 V_96 = 0 ;
while ( V_95 || ! V_93 -> V_97 ) {
int V_98 = F_42 ( V_95 , V_93 -> V_97 ) ;
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
F_43 ( struct V_1 * V_2 , unsigned int V_94 )
{
struct V_91 * V_100 ;
if ( V_2 -> V_93 && V_94 <= V_2 -> V_101 )
return V_2 -> V_93 ;
V_100 = F_44 ( sizeof( * V_100 ) * V_94 , V_102 ) ;
if ( V_100 ) {
F_10 ( V_2 -> V_93 ) ;
V_2 -> V_93 = V_100 ;
V_2 -> V_101 = V_94 ;
}
return V_100 ;
}
int
F_45 ( struct V_1 * V_2 , struct V_91 * V_103 ,
unsigned int V_94 , unsigned int V_104 )
{
int V_105 = 0 ;
int V_106 ;
unsigned int V_107 ;
struct V_108 V_109 ;
struct V_91 * V_93 ;
V_93 = F_43 ( V_2 , V_94 ) ;
if ( ! V_93 )
return - V_110 ;
V_109 . V_111 = NULL ;
V_109 . V_112 = 0 ;
for ( V_106 = 0 ; V_104 ; V_106 += V_105 , V_104 -= V_105 ) {
F_16 () ;
if ( F_38 ( V_2 ) ) {
V_106 = - V_113 ;
break;
}
V_107 = F_41 ( V_93 , V_103 , V_94 , V_106 ) ;
V_105 = F_46 ( V_2 -> V_26 , & V_109 ,
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
F_47 ( 1000 , 2000 ) ;
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
F_48 ( struct V_1 * V_2 , char * V_44 ,
unsigned int V_104 )
{
struct V_91 V_93 ;
V_93 . V_99 = V_44 ;
V_93 . V_97 = V_104 ;
return F_45 ( V_2 , & V_93 , 1 , V_104 ) ;
}
static bool
F_49 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_117 :
return true ;
case V_118 :
F_4 ( 1 , L_31 ) ;
break;
case V_119 :
F_4 ( 1 , L_32 ) ;
break;
case V_120 :
F_4 ( 1 , L_33 ) ;
F_18 ( 1000 ) ;
F_50 ( (struct V_121 * ) & V_2 -> V_122 , V_123 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
break;
default:
F_22 ( 1 , L_34 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
void
F_51 ( struct V_11 * V_124 , bool V_125 )
{
#ifdef F_52
V_124 -> V_126 = V_36 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_125 )
V_124 -> V_38 = V_127 ;
else
V_124 -> V_38 = V_128 ;
F_15 ( & V_124 -> V_37 ) ;
F_3 ( & V_14 ) ;
}
static void
F_53 ( struct V_11 * V_124 , struct V_1 * V_2 ,
char * V_44 , int V_125 )
{
if ( V_125 == 0 && F_20 ( V_44 ) > 0 ) {
V_124 -> V_129 = true ;
if ( V_124 -> V_130 ) {
V_125 = F_23 ( V_44 , V_124 -> V_130 ) ;
if ( V_125 > 0 )
return;
V_124 -> V_131 = true ;
return F_51 ( V_124 , V_125 ) ;
}
if ( ! V_2 -> V_87 ) {
F_22 ( 1 , L_35 ) ;
} else {
V_124 -> V_130 = V_44 ;
V_124 -> V_87 = true ;
V_2 -> V_86 = NULL ;
}
return;
}
V_124 -> V_130 = V_44 ;
V_124 -> V_87 = V_2 -> V_87 ;
if ( ! V_124 -> V_129 ) {
if ( V_2 -> V_87 )
V_2 -> V_86 = NULL ;
else
V_2 -> V_88 = NULL ;
}
F_51 ( V_124 , V_125 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_105 ;
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_132 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_55 ( & V_2 -> V_90 ) ;
F_2 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_134 <= 0 )
V_2 -> V_134 = 1 ;
F_3 ( & V_2 -> V_133 ) ;
F_55 ( & V_2 -> V_135 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
if ( ! F_56 ( & V_2 -> V_136 ) ) {
struct V_4 V_137 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_137 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_36 , V_12 -> V_124 ) ;
V_12 -> V_38 = V_138 ;
F_14 ( & V_12 -> V_37 , & V_137 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_37 , V_12 -> V_124 ) ;
F_15 ( & V_12 -> V_37 ) ;
V_12 -> V_41 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_56 ( & V_2 -> V_136 ) ) {
F_4 ( 1 , L_38 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_84 ) ;
F_10 ( V_2 -> V_93 ) ;
F_10 ( V_2 ) ;
V_105 = F_57 ( & V_139 ) ;
if ( V_105 > 0 )
F_58 ( V_140 , V_105 + V_141 ,
V_142 ) ;
}
static int
F_59 ( struct V_1 * V_2 , struct V_11 * V_124 )
{
int V_105 ;
char * V_44 = V_2 -> V_88 ;
unsigned int V_143 = F_60 ( V_44 ) ;
if ( V_143 > V_59 + F_61 ( V_2 ) - 4 ) {
F_22 ( 1 , L_39 ,
V_143 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
return - V_113 ;
}
if ( V_143 > V_144 - 4 ) {
V_2 -> V_87 = true ;
memcpy ( V_2 -> V_86 , V_44 , V_2 -> V_106 ) ;
V_44 = V_2 -> V_86 ;
}
V_105 = F_48 ( V_2 , V_44 + F_36 ( V_2 ) - 1 ,
V_143 - F_36 ( V_2 ) + 1 + 4 ) ;
if ( V_105 < 0 )
return V_105 ;
V_2 -> V_106 += V_105 ;
F_62 ( V_44 , V_2 -> V_106 ) ;
V_105 = V_2 -> V_145 -> V_146 ( V_44 , V_2 -> V_106 ) ;
if ( V_105 != 0 )
F_63 ( L_40 , V_44 ,
F_64 (unsigned int, server->total_read, 48 ) ) ;
if ( ! V_124 )
return V_105 ;
F_53 ( V_124 , V_2 , V_44 , V_105 ) ;
return 0 ;
}
static int
F_65 ( void * V_147 )
{
int V_105 ;
struct V_1 * V_2 = V_147 ;
unsigned int V_143 ;
char * V_44 = NULL ;
struct V_148 * V_149 = NULL ;
struct V_11 * V_12 ;
V_150 -> V_28 |= V_151 ;
F_4 ( 1 , L_41 , F_66 ( V_150 ) ) ;
V_105 = F_67 ( & V_139 ) ;
if ( V_105 > 1 )
F_58 ( V_140 , V_105 + V_141 ,
V_142 ) ;
F_68 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( ! F_34 ( V_2 ) )
continue;
V_2 -> V_87 = false ;
V_44 = V_2 -> V_88 ;
V_143 = 4 ;
V_105 = F_48 ( V_2 , V_44 , V_143 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 = V_105 ;
V_143 = F_60 ( V_44 ) ;
F_4 ( 1 , L_42 , V_143 ) ;
if ( ! F_49 ( V_2 , V_44 [ 0 ] ) )
continue;
if ( V_143 < F_36 ( V_2 ) - 1 - 4 ) {
F_22 ( 1 , L_43 ,
V_143 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
continue;
}
V_105 = F_48 ( V_2 , V_44 + 4 ,
F_36 ( V_2 ) - 1 - 4 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 += V_105 ;
V_12 = V_2 -> V_145 -> V_152 ( V_2 , V_44 ) ;
if ( ! V_12 || ! V_12 -> V_153 )
V_105 = F_59 ( V_2 , V_12 ) ;
else
V_105 = V_12 -> V_153 ( V_2 , V_12 ) ;
if ( V_105 < 0 )
continue;
if ( V_2 -> V_87 )
V_44 = V_2 -> V_86 ;
V_2 -> V_35 = V_36 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_129 || V_12 -> V_131 )
V_12 -> V_41 ( V_12 ) ;
} else if ( ! V_2 -> V_145 -> V_154 ||
! V_2 -> V_145 -> V_154 ( V_44 , V_2 ) ) {
F_22 ( 1 , L_44
L_45 , F_69 ( & V_155 ) ) ;
F_63 ( L_46 , V_44 ,
F_36 ( V_2 ) ) ;
#ifdef F_70
if ( V_2 -> V_145 -> V_156 )
V_2 -> V_145 -> V_156 ( V_44 ) ;
F_71 ( V_2 ) ;
#endif
}
}
F_72 ( V_2 -> V_86 ) ;
if ( V_2 -> V_88 )
F_73 ( V_2 -> V_88 ) ;
V_149 = F_74 ( & V_2 -> V_157 , NULL ) ;
F_54 ( V_2 ) ;
if ( ! V_149 ) {
F_75 ( V_158 ) ;
while ( ! F_76 ( V_150 ) ) {
F_77 () ;
F_75 ( V_158 ) ;
}
F_75 ( V_159 ) ;
}
F_78 ( 0 ) ;
}
static char *
F_79 ( const char * V_160 )
{
const char * V_161 ;
char * V_162 , * V_163 ;
unsigned int V_34 ;
V_161 = V_160 + 2 ;
V_163 = strchr ( V_161 , '\\' ) ;
if ( ! V_163 )
return F_80 ( - V_55 ) ;
V_34 = V_163 - V_161 ;
V_162 = F_44 ( ( V_34 + 1 ) , V_142 ) ;
if ( V_162 == NULL )
return F_80 ( - V_110 ) ;
memcpy ( V_162 , V_161 , V_34 ) ;
V_162 [ V_34 ] = '\0' ;
return V_162 ;
}
static int F_81 ( T_3 args [] , unsigned long * V_164 )
{
int V_3 ;
char * string ;
string = F_82 ( args ) ;
if ( string == NULL )
return - V_110 ;
V_3 = F_83 ( string , 0 , V_164 ) ;
F_10 ( string ) ;
return V_3 ;
}
static int F_84 ( char * V_165 ,
struct V_166 * V_167 )
{
T_3 args [ V_168 ] ;
switch ( F_85 ( V_165 , V_169 , args ) ) {
case V_170 :
V_167 -> V_171 |= V_172 ;
break;
case V_173 :
V_167 -> V_171 |= V_172 | V_174 ;
break;
case V_175 :
F_22 ( 1 , L_47 ) ;
break;
case V_176 :
V_167 -> V_171 |= V_177 ;
break;
case V_178 :
V_167 -> V_171 |= V_177 | V_174 ;
break;
case V_179 :
V_167 -> V_171 |= V_180 ;
break;
case V_181 :
V_167 -> V_171 |= V_180 | V_174 ;
break;
case V_182 :
V_167 -> V_171 |= V_183 ;
break;
case V_184 :
V_167 -> V_171 |= V_183 | V_174 ;
break;
#ifdef F_86
case V_185 :
V_167 -> V_171 |= V_186 ;
break;
#endif
case V_187 :
V_167 -> V_188 = 1 ;
break;
default:
F_22 ( 1 , L_48 , V_165 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( char * V_165 , struct V_166 * V_167 )
{
T_3 args [ V_168 ] ;
switch ( F_85 ( V_165 , V_189 , args ) ) {
case V_190 :
V_167 -> V_191 = false ;
V_167 -> V_192 = false ;
break;
case V_193 :
V_167 -> V_191 = false ;
V_167 -> V_192 = true ;
break;
case V_194 :
V_167 -> V_191 = true ;
V_167 -> V_192 = false ;
break;
default:
F_22 ( 1 , L_49 , V_165 ) ;
return 1 ;
}
return 0 ;
}
static int
F_88 ( char * V_165 , struct V_166 * V_167 )
{
T_3 args [ V_168 ] ;
switch ( F_85 ( V_165 , V_195 , args ) ) {
case V_196 :
V_167 -> V_145 = & V_197 ;
V_167 -> V_198 = & V_199 ;
break;
#ifdef F_89
case V_200 :
V_167 -> V_145 = & V_201 ;
V_167 -> V_198 = & V_202 ;
break;
#endif
default:
F_22 ( 1 , L_50 , V_165 ) ;
return 1 ;
}
return 0 ;
}
static int
F_90 ( const char * V_203 , const char * V_204 ,
struct V_166 * V_167 )
{
char * V_205 , * V_206 ;
char * V_207 = NULL , * V_208 ;
unsigned int V_209 , V_210 , V_211 ;
char V_212 [ 2 ] ;
short int V_213 = - 1 ;
short int V_214 = - 1 ;
bool V_215 = false ;
bool V_216 = false ;
bool V_217 = false ;
char * V_218 = NULL ;
char * V_219 = F_91 () -> V_219 ;
char * string = NULL ;
char * V_220 , * V_165 ;
char V_163 ;
bool V_221 = false ;
static bool V_222 = false ;
V_212 [ 0 ] = ',' ;
V_212 [ 1 ] = 0 ;
V_163 = V_212 [ 0 ] ;
memset ( V_167 -> V_223 , 0x20 , V_224 ) ;
for ( V_210 = 0 ; V_210 < F_92 ( V_219 , V_224 ) ; V_210 ++ )
V_167 -> V_223 [ V_210 ] = toupper ( V_219 [ V_210 ] ) ;
V_167 -> V_223 [ V_224 ] = 0 ;
V_167 -> V_225 [ 0 ] = 0 ;
V_167 -> V_226 = F_93 () ;
V_167 -> V_227 = F_93 () ;
V_167 -> V_228 = F_94 () ;
V_167 -> V_229 = V_167 -> V_230 = V_231 | V_232 | V_233 ;
V_167 -> V_234 = 1 ;
V_167 -> V_235 = 1 ;
V_167 -> V_236 = V_237 ;
V_167 -> V_145 = & V_197 ;
V_167 -> V_198 = & V_199 ;
if ( ! V_203 )
goto V_238;
V_207 = F_95 ( V_203 , V_239 , V_142 ) ;
if ( ! V_207 )
goto V_238;
V_208 = V_207 ;
V_206 = V_208 + strlen ( V_208 ) ;
if ( strncmp ( V_208 , L_51 , 4 ) == 0 ) {
if ( V_208 [ 4 ] != 0 ) {
V_212 [ 0 ] = V_208 [ 4 ] ;
V_208 += 5 ;
} else {
F_4 ( 1 , L_52 ) ;
}
}
V_167 -> V_240 = false ;
V_167 -> V_241 = false ;
while ( ( V_205 = F_96 ( & V_208 , V_212 ) ) != NULL ) {
T_3 args [ V_168 ] ;
unsigned long V_164 ;
int V_242 ;
if ( ! * V_205 )
continue;
V_242 = F_85 ( V_205 , V_243 , args ) ;
switch ( V_242 ) {
case V_244 :
break;
case V_245 :
V_167 -> V_246 = 0 ;
break;
case V_247 :
V_167 -> V_246 = 1 ;
break;
case V_248 :
V_213 = 1 ;
break;
case V_249 :
V_213 = 0 ;
break;
case V_250 :
V_167 -> V_251 = 1 ;
break;
case V_252 :
V_167 -> V_253 = 1 ;
break;
case V_254 :
V_167 -> V_255 = 1 ;
break;
case V_256 :
V_167 -> V_255 = 0 ;
break;
case V_257 :
V_167 -> V_258 = 0 ;
break;
case V_259 :
V_167 -> V_258 = 1 ;
break;
case V_260 :
V_167 -> V_261 = 1 ;
break;
case V_262 :
V_167 -> V_261 = 0 ;
break;
case V_263 :
V_167 -> V_264 = 1 ;
break;
case V_265 :
V_167 -> V_264 = 0 ;
break;
case V_266 :
V_167 -> V_267 = 1 ;
break;
case V_268 :
V_167 -> V_234 = 1 ;
break;
case V_269 :
V_167 -> V_234 = 0 ;
break;
case V_270 :
V_167 -> V_271 = 1 ;
break;
case V_272 :
V_167 -> V_273 = 1 ;
break;
case V_274 :
V_167 -> V_275 = 0 ;
break;
case V_276 :
V_167 -> V_275 = 1 ;
if ( V_167 -> V_230 ==
( V_277 & ~ ( V_278 | V_279 ) ) )
V_167 -> V_230 = V_277 ;
break;
case V_280 :
V_167 -> V_281 = 1 ;
break;
case V_282 :
V_167 -> V_283 = 1 ;
break;
case V_284 :
V_167 -> V_283 = 0 ;
break;
case V_285 :
V_167 -> V_286 = true ;
break;
case V_287 :
V_167 -> V_286 = false ;
break;
case V_288 :
V_167 -> V_255 = 0 ;
break;
case V_289 :
V_167 -> V_255 = 1 ;
break;
case V_290 :
V_167 -> V_291 = 0 ;
break;
case V_292 :
V_167 -> V_291 = 1 ;
break;
case V_293 :
V_167 -> V_294 = 1 ;
break;
case V_295 :
V_167 -> V_294 = 0 ;
break;
case V_296 :
V_167 -> V_235 = 1 ;
break;
case V_297 :
V_167 -> V_235 = 0 ;
break;
case V_298 :
V_167 -> V_299 = 1 ;
break;
case V_300 :
V_167 -> V_301 = 1 ;
break;
case V_302 :
V_167 -> V_301 = 0 ;
break;
case V_303 :
V_167 -> V_304 = 0 ;
break;
case V_305 :
V_167 -> V_304 = 1 ;
break;
case V_306 :
V_167 -> V_307 = 1 ;
break;
case V_308 :
V_167 -> V_171 |= V_174 ;
break;
case V_309 :
V_167 -> V_310 = 1 ;
break;
case V_311 :
V_221 = true ;
V_167 -> V_191 = true ;
V_167 -> V_192 = false ;
F_22 ( 1 , L_53
L_54
L_55 ) ;
break;
case V_312 :
V_221 = true ;
V_167 -> V_191 = false ;
V_167 -> V_192 = true ;
F_22 ( 1 , L_56
L_57
L_55 ) ;
break;
case V_313 :
F_97 ( V_314 L_58
L_59
L_60 ) ;
break;
case V_315 :
#ifndef F_98
F_22 ( 1 , L_61
L_62 ) ;
goto V_238;
#endif
V_167 -> V_316 = true ;
break;
case V_317 :
V_167 -> V_318 = true ;
break;
case V_319 :
V_167 -> V_320 = true ;
break;
case V_321 :
V_217 = true ;
break;
case V_322 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_63 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_323 = V_164 ;
V_167 -> V_240 = true ;
break;
case V_324 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_64 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_325 = V_164 ;
V_167 -> V_241 = true ;
break;
case V_326 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_65 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_227 = V_164 ;
V_215 = true ;
break;
case V_327 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_66 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_226 = V_164 ;
break;
case V_328 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_67 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_228 = V_164 ;
V_216 = true ;
break;
case V_329 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_68 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_230 = V_164 ;
break;
case V_330 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_69 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_229 = V_164 ;
break;
case V_331 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_70 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_332 = V_164 ;
break;
case V_333 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_71 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_334 = V_164 ;
break;
case V_335 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_72 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_336 = V_164 ;
break;
case V_337 :
if ( F_81 ( args , & V_164 ) ) {
F_22 ( 1 , L_73 ,
V_19 ) ;
goto V_238;
}
V_167 -> V_236 = V_82 * V_164 ;
if ( V_167 -> V_236 > V_338 ) {
F_22 ( 1 , L_74
L_75 ) ;
goto V_238;
}
break;
case V_339 :
V_167 -> V_188 = 1 ;
V_167 -> V_340 = NULL ;
break;
case V_341 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_92 ( string , V_343 ) >
V_343 ) {
F_97 ( V_314 L_76 ) ;
goto V_238;
}
V_167 -> V_340 = F_99 ( string , V_142 ) ;
if ( ! V_167 -> V_340 ) {
F_97 ( V_314 L_77
L_78 ) ;
goto V_238;
}
break;
case V_344 :
V_167 -> V_345 = NULL ;
break;
case V_346 :
V_165 = strchr ( V_205 , '=' ) ;
V_165 ++ ;
V_220 = ( char * ) V_165 + strlen ( V_165 ) ;
if ( V_220 < V_206 && V_220 [ 1 ] == V_163 ) {
V_220 [ 0 ] = V_163 ;
while ( ( V_220 = strchr ( V_220 , V_163 ) )
!= NULL && ( V_220 [ 1 ] == V_163 ) ) {
V_220 = ( char * ) & V_220 [ 2 ] ;
}
if ( V_220 ) {
V_220 [ 0 ] = '\0' ;
V_208 = ( char * ) & V_220 [ 1 ] ;
} else
V_208 = V_206 ;
}
V_209 = strlen ( V_165 ) ;
V_167 -> V_345 = F_100 ( V_209 + 1 , V_142 ) ;
if ( V_167 -> V_345 == NULL ) {
F_97 ( V_314 L_77
L_79 ) ;
goto V_238;
}
for ( V_210 = 0 , V_211 = 0 ; V_210 < V_209 ; V_210 ++ , V_211 ++ ) {
V_167 -> V_345 [ V_211 ] = V_165 [ V_210 ] ;
if ( ( V_165 [ V_210 ] == V_163 ) &&
V_165 [ V_210 + 1 ] == V_163 )
V_210 ++ ;
}
V_167 -> V_345 [ V_211 ] = '\0' ;
break;
case V_347 :
V_167 -> V_348 = NULL ;
break;
case V_349 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_92 ( string , V_350 ) >
V_350 ) {
F_97 ( V_314 L_80
L_81 ) ;
goto V_238;
}
V_167 -> V_348 = F_99 ( string , V_142 ) ;
if ( ! V_167 -> V_348 ) {
F_97 ( V_314 L_77
L_82 ) ;
goto V_238;
}
break;
case V_351 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
V_209 = F_92 ( string , 300 ) ;
if ( V_209 == 300 ) {
F_97 ( V_314 L_83 ) ;
goto V_238;
}
V_167 -> V_352 = F_44 ( V_209 + 1 , V_142 ) ;
if ( V_167 -> V_352 == NULL ) {
F_97 ( V_314 L_84 ) ;
goto V_238;
}
strcpy ( V_167 -> V_352 , string ) ;
if ( strncmp ( string , L_85 , 2 ) == 0 ) {
V_167 -> V_352 [ 0 ] = '\\' ;
V_167 -> V_352 [ 1 ] = '\\' ;
} else if ( strncmp ( string , L_86 , 2 ) != 0 ) {
F_97 ( V_314 L_87
L_88 ) ;
goto V_238;
}
break;
case V_353 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_92 ( string , 256 ) == 256 ) {
F_97 ( V_314 L_89
L_90 ) ;
goto V_238;
}
V_167 -> V_354 = F_99 ( string , V_142 ) ;
if ( ! V_167 -> V_354 ) {
F_97 ( V_314 L_77
L_91 ) ;
goto V_238;
}
F_4 ( 1 , L_92 ) ;
break;
case V_355 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( ! F_101 (
(struct V_121 * ) & V_167 -> V_356 ,
string , strlen ( string ) ) ) {
F_97 ( V_314 L_93
L_94 , string ) ;
goto V_238;
}
break;
case V_357 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
V_209 = F_92 ( string , 1024 ) ;
if ( string [ 0 ] != '/' )
V_209 ++ ;
if ( V_209 > 1024 ) {
F_97 ( V_314 L_95 ) ;
goto V_238;
}
V_167 -> V_358 = F_44 ( V_209 + 1 , V_142 ) ;
if ( V_167 -> V_358 == NULL ) {
F_97 ( V_314 L_77
L_96 ) ;
goto V_238;
}
if ( string [ 0 ] != '/' ) {
V_167 -> V_358 [ 0 ] = '/' ;
strcpy ( V_167 -> V_358 + 1 , string ) ;
} else
strcpy ( V_167 -> V_358 , string ) ;
break;
case V_359 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_92 ( string , 1024 ) >= 65 ) {
F_97 ( V_314 L_97
L_98 ) ;
goto V_238;
}
if ( F_102 ( string , L_99 , 7 ) != 0 ) {
V_167 -> V_360 = F_99 ( string ,
V_142 ) ;
if ( ! V_167 -> V_360 ) {
F_97 ( V_314 L_100
L_101 ) ;
goto V_238;
}
}
F_4 ( 1 , L_102 , string ) ;
break;
case V_361 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_102 ( string , L_103 , 11 ) == 0 )
V_167 -> V_362 = 1 ;
break;
case V_363 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
memset ( V_167 -> V_223 , 0x20 ,
V_224 ) ;
for ( V_210 = 0 ; V_210 < V_224 ; V_210 ++ ) {
if ( string [ V_210 ] == 0 )
break;
V_167 -> V_223 [ V_210 ] = string [ V_210 ] ;
}
if ( V_210 == V_224 && string [ V_210 ] != 0 )
F_97 ( V_314 L_104
L_105 ) ;
break;
case V_364 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
memset ( V_167 -> V_225 , 0x20 ,
V_365 ) ;
for ( V_210 = 0 ; V_210 < 15 ; V_210 ++ ) {
if ( string [ V_210 ] == 0 )
break;
V_167 -> V_225 [ V_210 ] = string [ V_210 ] ;
}
if ( V_210 == V_224 && string [ V_210 ] != 0 )
F_97 ( V_314 L_106
L_107 ) ;
break;
case V_366 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_102 ( string , L_108 , 1 ) == 0 ) {
break;
}
F_97 ( V_314 L_109
L_110 ) ;
goto V_238;
case V_367 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_88 ( string , V_167 ) != 0 )
goto V_238;
break;
case V_368 :
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_84 ( string , V_167 ) != 0 )
goto V_238;
break;
case V_369 :
V_221 = true ;
string = F_82 ( args ) ;
if ( string == NULL )
goto V_342;
if ( F_87 ( string , V_167 ) != 0 )
goto V_238;
break;
default:
if ( ! V_218 )
V_218 = V_205 ;
break;
}
F_10 ( string ) ;
string = NULL ;
}
if ( ! V_217 && V_218 ) {
F_97 ( V_370 L_111 , V_218 ) ;
goto V_238;
}
#ifndef F_103
if ( V_167 -> V_320 ) {
F_22 ( 1 , L_112
L_113 ) ;
goto V_238;
}
#endif
if ( V_167 -> V_348 == NULL )
V_167 -> V_348 = & V_167 -> V_352 [ 2 ] ;
if ( V_215 )
V_167 -> V_213 = V_213 ;
else if ( V_213 == 1 )
F_97 ( V_371 L_114
L_115 ) ;
if ( V_216 )
V_167 -> V_214 = V_214 ;
else if ( V_214 == 1 )
F_97 ( V_371 L_116
L_117 ) ;
if ( ! V_221 && ! V_222 ) {
V_222 = true ;
F_97 ( V_371 L_118
L_119
L_120 ) ;
}
F_10 ( V_207 ) ;
return 0 ;
V_342:
F_97 ( V_314 L_121 ) ;
V_238:
F_10 ( string ) ;
F_10 ( V_207 ) ;
return 1 ;
}
static bool
F_104 ( struct V_121 * V_356 , struct V_121 * V_372 )
{
switch ( V_356 -> V_373 ) {
case V_374 :
return ( V_372 -> V_373 == V_374 ) ;
case V_375 : {
struct V_376 * V_377 = (struct V_376 * ) V_356 ;
struct V_376 * V_378 = (struct V_376 * ) V_372 ;
return ( V_377 -> V_379 . V_380 == V_378 -> V_379 . V_380 ) ;
}
case V_381 : {
struct V_382 * V_383 = (struct V_382 * ) V_356 ;
struct V_382 * V_384 = (struct V_382 * ) & V_372 ;
return F_105 ( & V_383 -> V_385 , & V_384 -> V_385 ) ;
}
default:
F_106 ( 1 ) ;
return false ;
}
}
static bool
F_107 ( struct V_1 * V_2 , struct V_121 * V_386 )
{
T_4 V_332 , * V_387 ;
switch ( V_386 -> V_373 ) {
case V_375 :
V_387 = & ( (struct V_376 * ) & V_2 -> V_122 ) -> V_388 ;
V_332 = ( (struct V_376 * ) V_386 ) -> V_388 ;
break;
case V_381 :
V_387 = & ( (struct V_382 * ) & V_2 -> V_122 ) -> V_389 ;
V_332 = ( (struct V_382 * ) V_386 ) -> V_389 ;
break;
default:
F_106 ( 1 ) ;
return false ;
}
if ( ! V_332 ) {
V_332 = F_108 ( V_123 ) ;
if ( V_332 == * V_387 )
return true ;
V_332 = F_108 ( V_390 ) ;
}
return V_332 == * V_387 ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_121 * V_386 ,
struct V_121 * V_356 )
{
switch ( V_386 -> V_373 ) {
case V_375 : {
struct V_376 * V_391 = (struct V_376 * ) V_386 ;
struct V_376 * V_392 =
(struct V_376 * ) & V_2 -> V_122 ;
if ( V_391 -> V_379 . V_380 != V_392 -> V_379 . V_380 )
return false ;
break;
}
case V_381 : {
struct V_382 * V_393 = (struct V_382 * ) V_386 ;
struct V_382 * V_394 =
(struct V_382 * ) & V_2 -> V_122 ;
if ( ! F_105 ( & V_393 -> V_385 ,
& V_394 -> V_385 ) )
return false ;
if ( V_393 -> V_395 != V_394 -> V_395 )
return false ;
break;
}
default:
F_106 ( 1 ) ;
return false ;
}
if ( ! F_104 ( V_356 , (struct V_121 * ) & V_2 -> V_356 ) )
return false ;
return true ;
}
static bool
F_110 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
unsigned int V_396 ;
if ( V_167 -> V_171 & ( ~ ( V_174 | V_397 ) ) )
V_396 = V_167 -> V_171 ;
else
V_396 = V_398 | V_167 -> V_171 ;
switch ( V_2 -> V_399 ) {
case V_400 :
if ( ! ( V_396 & ( V_186 | V_401 ) ) )
return false ;
break;
case V_402 :
if ( ! ( V_396 & V_183 ) )
return false ;
break;
case V_403 :
if ( ! ( V_396 & V_180 ) )
return false ;
break;
case V_404 :
if ( ! ( V_396 & V_172 ) )
return false ;
break;
case V_405 :
if ( ! ( V_396 & V_177 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_396 & V_406 ) == 0 &&
( V_2 -> V_407 & V_408 ) )
return false ;
else if ( ( ( V_396 & V_174 ) == V_174 ) &&
( V_2 -> V_407 &
( V_409 | V_408 ) ) == 0 )
return false ;
return true ;
}
static int F_111 ( struct V_1 * V_2 , struct V_121 * V_386 ,
struct V_166 * V_167 )
{
if ( ( V_2 -> V_198 != V_167 -> V_198 ) || ( V_2 -> V_145 != V_167 -> V_145 ) )
return 0 ;
if ( ! F_112 ( F_113 ( V_2 ) , V_150 -> V_410 -> V_411 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_386 ,
(struct V_121 * ) & V_167 -> V_356 ) )
return 0 ;
if ( ! F_107 ( V_2 , V_386 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_167 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_114 ( struct V_121 * V_386 , struct V_166 * V_167 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_115 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_111 ( V_2 , V_386 , V_167 ) )
continue;
++ V_2 -> V_412 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_122 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_116 ( struct V_1 * V_2 )
{
struct V_148 * V_413 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_412 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_117 ( F_113 ( V_2 ) ) ;
F_15 ( & V_2 -> V_132 ) ;
F_3 ( & V_20 ) ;
F_118 ( & V_2 -> V_80 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_413 = F_74 ( & V_2 -> V_157 , NULL ) ;
if ( V_413 )
F_121 ( V_414 , V_413 ) ;
}
static struct V_1 *
F_122 ( struct V_166 * V_415 )
{
struct V_1 * V_416 = NULL ;
struct V_417 V_386 ;
struct V_376 * V_418 = (struct V_376 * ) & V_386 ;
struct V_382 * V_419 = (struct V_382 * ) & V_386 ;
int V_3 ;
memset ( & V_386 , 0 , sizeof( struct V_417 ) ) ;
F_4 ( 1 , L_123 , V_415 -> V_352 , V_415 -> V_348 ) ;
if ( V_415 -> V_348 && V_415 -> V_352 ) {
V_3 = F_123 ( (struct V_121 * ) & V_386 ,
V_415 -> V_348 ,
strlen ( V_415 -> V_348 ) ,
V_415 -> V_332 ) ;
if ( ! V_3 ) {
V_3 = - V_55 ;
goto V_420;
}
} else if ( V_415 -> V_348 ) {
F_22 ( 1 , L_124 ) ;
V_3 = - V_55 ;
goto V_420;
} else {
F_22 ( 1 , L_125
L_126 ) ;
V_3 = - V_55 ;
goto V_420;
}
V_416 = F_114 ( (struct V_121 * ) & V_386 , V_415 ) ;
if ( V_416 )
return V_416 ;
V_416 = F_100 ( sizeof( struct V_1 ) , V_142 ) ;
if ( ! V_416 ) {
V_3 = - V_110 ;
goto V_420;
}
V_3 = F_124 ( V_416 ) ;
if ( V_3 ) {
F_22 ( 1 , L_127 , V_3 ) ;
goto V_420;
}
V_416 -> V_145 = V_415 -> V_145 ;
V_416 -> V_198 = V_415 -> V_198 ;
F_125 ( V_416 , F_126 ( V_150 -> V_410 -> V_411 ) ) ;
V_416 -> V_84 = F_79 ( V_415 -> V_352 ) ;
if ( F_127 ( V_416 -> V_84 ) ) {
V_3 = F_128 ( V_416 -> V_84 ) ;
goto V_421;
}
V_416 -> V_251 = V_415 -> V_251 ;
V_416 -> V_253 = V_415 -> V_253 ;
V_416 -> V_422 = V_415 -> V_362 ;
V_416 -> V_423 = 0 ;
V_416 -> V_134 = 1 ;
F_129 ( & V_416 -> V_90 ) ;
F_129 ( & V_416 -> V_135 ) ;
F_12 ( & V_416 -> V_136 ) ;
F_130 ( & V_416 -> V_25 ) ;
memcpy ( V_416 -> V_424 ,
V_415 -> V_223 , V_365 ) ;
memcpy ( V_416 -> V_425 ,
V_415 -> V_225 , V_365 ) ;
V_416 -> V_31 = false ;
V_416 -> V_30 = 0 ;
V_416 -> V_35 = V_36 ;
F_131 ( & V_416 -> V_133 ) ;
F_12 ( & V_416 -> V_132 ) ;
F_12 ( & V_416 -> V_21 ) ;
F_132 ( & V_416 -> V_80 , F_29 ) ;
V_416 -> V_15 = V_426 ;
memcpy ( & V_416 -> V_356 , & V_415 -> V_356 ,
sizeof( V_416 -> V_356 ) ) ;
++ V_416 -> V_412 ;
if ( V_386 . V_427 == V_381 ) {
F_4 ( 1 , L_128 ) ;
memcpy ( & V_416 -> V_122 , V_419 ,
sizeof( struct V_382 ) ) ;
} else
memcpy ( & V_416 -> V_122 , V_418 ,
sizeof( struct V_376 ) ) ;
V_3 = F_133 ( V_416 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_129 ) ;
goto V_421;
}
F_134 ( V_428 ) ;
V_416 -> V_157 = F_135 ( F_65 ,
V_416 , L_130 ) ;
if ( F_127 ( V_416 -> V_157 ) ) {
V_3 = F_128 ( V_416 -> V_157 ) ;
F_22 ( 1 , L_131 , V_3 ) ;
F_136 ( V_428 ) ;
goto V_421;
}
V_416 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_137 ( & V_416 -> V_132 , & V_429 ) ;
F_3 ( & V_20 ) ;
F_138 ( V_416 ) ;
F_33 ( V_85 , & V_416 -> V_80 , V_81 ) ;
return V_416 ;
V_421:
F_119 ( V_416 ) ;
F_117 ( F_113 ( V_416 ) ) ;
V_420:
if ( V_416 ) {
if ( ! F_127 ( V_416 -> V_84 ) )
F_10 ( V_416 -> V_84 ) ;
if ( V_416 -> V_26 )
F_9 ( V_416 -> V_26 ) ;
F_10 ( V_416 ) ;
}
return F_80 ( V_3 ) ;
}
static int F_139 ( struct V_7 * V_8 , struct V_166 * V_167 )
{
switch ( V_8 -> V_2 -> V_399 ) {
case V_404 :
if ( V_167 -> V_226 != V_8 -> V_226 )
return 0 ;
break;
default:
if ( V_8 -> V_430 == NULL ) {
if ( ! V_167 -> V_188 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_430 ,
V_167 -> V_340 ? V_167 -> V_340 : L_132 ,
V_343 ) )
return 0 ;
if ( strlen ( V_167 -> V_340 ) != 0 &&
V_8 -> V_345 != NULL &&
strncmp ( V_8 -> V_345 ,
V_167 -> V_345 ? V_167 -> V_345 : L_132 ,
V_431 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_140 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_115 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_139 ( V_8 , V_167 ) )
continue;
++ V_8 -> V_432 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_141 ( struct V_7 * V_8 )
{
int V_433 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_133 , V_19 , V_8 -> V_432 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_432 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_434 == V_89 ) {
V_433 = F_142 () ;
F_143 ( V_433 , V_8 ) ;
F_144 ( V_433 ) ;
}
F_145 ( V_8 ) ;
F_116 ( V_2 ) ;
}
static int
F_146 ( struct V_166 * V_167 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_435 , * V_163 , * V_436 ;
T_5 V_34 ;
struct V_437 * V_437 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_376 * V_438 ;
struct V_382 * V_439 ;
struct V_440 * V_441 ;
V_435 = F_44 ( V_442 , V_142 ) ;
if ( ! V_435 )
return - V_110 ;
switch ( V_2 -> V_122 . V_427 ) {
case V_375 :
V_438 = (struct V_376 * ) & V_2 -> V_122 ;
sprintf ( V_435 , L_134 , & V_438 -> V_379 . V_380 ) ;
break;
case V_381 :
V_439 = (struct V_382 * ) & V_2 -> V_122 ;
sprintf ( V_435 , L_135 , & V_439 -> V_385 . V_443 ) ;
break;
default:
F_4 ( 1 , L_136 , V_2 -> V_122 . V_427 ) ;
V_3 = - V_55 ;
goto V_420;
}
F_4 ( 1 , L_137 , V_19 , V_435 ) ;
V_437 = F_147 ( & V_444 , V_435 , L_132 ) ;
if ( F_127 ( V_437 ) ) {
if ( ! V_8 -> V_445 ) {
F_4 ( 1 , L_138 ) ;
V_3 = F_128 ( V_437 ) ;
goto V_420;
}
sprintf ( V_435 , L_139 , V_8 -> V_445 ) ;
F_4 ( 1 , L_137 , V_19 , V_435 ) ;
V_437 = F_147 ( & V_444 , V_435 , L_132 ) ;
if ( F_127 ( V_437 ) ) {
V_3 = F_128 ( V_437 ) ;
goto V_420;
}
}
F_148 ( & V_437 -> V_446 ) ;
V_441 = V_437 -> V_436 . V_205 ;
if ( F_149 ( V_441 ) ) {
V_3 = V_441 ? F_128 ( V_441 ) : - V_55 ;
goto V_447;
}
V_436 = ( char * ) V_441 -> V_205 ;
V_163 = F_150 ( V_436 , V_441 -> V_448 , ':' ) ;
F_4 ( 1 , L_140 , V_436 ) ;
if ( ! V_163 ) {
F_4 ( 1 , L_141 ,
V_441 -> V_448 ) ;
V_3 = - V_55 ;
goto V_447;
}
V_34 = V_163 - V_436 ;
if ( V_34 > V_343 || V_34 <= 0 ) {
F_4 ( 1 , L_142 , V_34 ) ;
V_3 = - V_55 ;
goto V_447;
}
V_167 -> V_340 = F_95 ( V_436 , V_34 , V_142 ) ;
if ( ! V_167 -> V_340 ) {
F_4 ( 1 , L_143 , V_34 ) ;
V_3 = - V_110 ;
goto V_447;
}
F_4 ( 1 , L_144 , V_19 , V_167 -> V_340 ) ;
V_34 = V_437 -> V_448 - ( V_34 + 1 ) ;
if ( V_34 > V_431 || V_34 <= 0 ) {
F_4 ( 1 , L_145 , V_34 ) ;
V_3 = - V_55 ;
F_10 ( V_167 -> V_340 ) ;
V_167 -> V_340 = NULL ;
goto V_447;
}
++ V_163 ;
V_167 -> V_345 = F_95 ( V_163 , V_34 , V_142 ) ;
if ( ! V_167 -> V_345 ) {
F_4 ( 1 , L_146 , V_34 ) ;
V_3 = - V_110 ;
F_10 ( V_167 -> V_340 ) ;
V_167 -> V_340 = NULL ;
goto V_447;
}
V_447:
F_151 ( & V_437 -> V_446 ) ;
F_152 ( V_437 ) ;
V_420:
F_10 ( V_435 ) ;
F_4 ( 1 , L_147 , V_19 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_153 ( struct V_1 * V_2 , struct V_166 * V_415 )
{
int V_3 = - V_110 , V_433 ;
struct V_7 * V_8 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_122 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_122 ;
V_433 = F_142 () ;
V_8 = F_140 ( V_2 , V_415 ) ;
if ( V_8 ) {
F_4 ( 1 , L_148 , V_8 -> V_434 ) ;
F_7 ( & V_8 -> V_449 ) ;
V_3 = F_154 ( V_433 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_449 ) ;
F_141 ( V_8 ) ;
F_155 ( V_433 ) ;
return F_80 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_149 ) ;
V_3 = F_156 ( V_433 , V_8 ,
V_415 -> V_450 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_449 ) ;
F_141 ( V_8 ) ;
F_155 ( V_433 ) ;
return F_80 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_449 ) ;
F_116 ( V_2 ) ;
F_155 ( V_433 ) ;
return V_8 ;
}
F_4 ( 1 , L_150 ) ;
V_8 = F_157 () ;
if ( V_8 == NULL )
goto V_451;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_122 . V_427 == V_381 )
sprintf ( V_8 -> V_452 , L_151 , & V_393 -> V_385 ) ;
else
sprintf ( V_8 -> V_452 , L_152 , & V_386 -> V_379 ) ;
if ( V_415 -> V_340 ) {
V_8 -> V_430 = F_99 ( V_415 -> V_340 , V_142 ) ;
if ( ! V_8 -> V_430 )
goto V_451;
}
if ( V_415 -> V_345 ) {
V_8 -> V_345 = F_99 ( V_415 -> V_345 , V_142 ) ;
if ( ! V_8 -> V_345 )
goto V_451;
}
if ( V_415 -> V_354 ) {
V_8 -> V_445 = F_99 ( V_415 -> V_354 , V_142 ) ;
if ( ! V_8 -> V_445 )
goto V_451;
}
V_8 -> V_226 = V_415 -> V_226 ;
V_8 -> V_227 = V_415 -> V_227 ;
if ( ( V_415 -> V_171 == 0 ) && V_453 == false ) {
V_453 = true ;
F_22 ( 1 , L_153
L_154
L_155 ) ;
}
V_8 -> V_454 = V_415 -> V_171 ;
F_7 ( & V_8 -> V_449 ) ;
V_3 = F_154 ( V_433 , V_8 ) ;
if ( ! V_3 )
V_3 = F_156 ( V_433 , V_8 , V_415 -> V_450 ) ;
F_11 ( & V_8 -> V_449 ) ;
if ( V_3 )
goto V_451;
F_2 ( & V_20 ) ;
F_137 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_155 ( V_433 ) ;
return V_8 ;
V_451:
F_145 ( V_8 ) ;
F_155 ( V_433 ) ;
return F_80 ( V_3 ) ;
}
static int F_158 ( struct V_9 * V_10 , const char * V_160 )
{
if ( V_10 -> V_455 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_456 , V_160 , V_457 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_159 ( struct V_7 * V_8 , const char * V_160 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_158 ( V_10 , V_160 ) )
continue;
++ V_10 -> V_458 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_160 ( struct V_9 * V_10 )
{
int V_433 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_156 , V_19 , V_10 -> V_458 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_458 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_433 = F_142 () ;
F_161 ( V_433 , V_10 ) ;
F_144 ( V_433 ) ;
F_162 ( V_10 ) ;
F_163 ( V_10 ) ;
F_141 ( V_8 ) ;
}
static struct V_9 *
F_164 ( struct V_7 * V_8 , struct V_166 * V_415 )
{
int V_3 , V_433 ;
struct V_9 * V_10 ;
V_10 = F_159 ( V_8 , V_415 -> V_352 ) ;
if ( V_10 ) {
F_4 ( 1 , L_157 ) ;
F_141 ( V_8 ) ;
if ( V_10 -> V_310 != V_415 -> V_310 )
F_22 ( 1 , L_158
L_159 ) ;
return V_10 ;
}
V_10 = F_165 () ;
if ( V_10 == NULL ) {
V_3 = - V_110 ;
goto V_459;
}
V_10 -> V_8 = V_8 ;
if ( V_415 -> V_345 ) {
V_10 -> V_345 = F_99 ( V_415 -> V_345 , V_142 ) ;
if ( ! V_10 -> V_345 ) {
V_3 = - V_110 ;
goto V_459;
}
}
if ( strchr ( V_415 -> V_352 + 3 , '\\' ) == NULL
&& strchr ( V_415 -> V_352 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_160 ) ;
V_3 = - V_460 ;
goto V_459;
}
V_433 = F_142 () ;
V_3 = F_166 ( V_433 , V_8 , V_415 -> V_352 , V_10 , V_415 -> V_450 ) ;
F_155 ( V_433 ) ;
F_4 ( 1 , L_161 , V_3 ) ;
if ( V_3 )
goto V_459;
if ( V_415 -> V_267 ) {
V_10 -> V_461 &= ~ V_462 ;
F_4 ( 1 , L_162 , V_10 -> V_461 ) ;
}
V_10 -> V_310 = V_415 -> V_310 ;
V_10 -> V_255 = V_415 -> V_255 ;
V_10 -> V_273 = V_415 -> V_273 ;
V_10 -> V_307 = V_415 -> V_307 ;
F_2 ( & V_20 ) ;
F_137 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_167 ( V_10 ) ;
return V_10 ;
V_459:
F_163 ( V_10 ) ;
return F_80 ( V_3 ) ;
}
void
F_168 ( struct V_463 * V_464 )
{
if ( ! V_464 || F_127 ( V_464 ) )
return;
if ( ! F_169 ( & V_464 -> V_465 ) ||
F_170 ( V_466 , & V_464 -> V_467 ) ) {
V_464 -> V_468 = V_36 ;
return;
}
if ( ! F_127 ( F_171 ( V_464 ) ) )
F_160 ( F_171 ( V_464 ) ) ;
F_10 ( V_464 ) ;
return;
}
static inline struct V_463 *
F_172 ( struct V_469 * V_470 )
{
return V_470 -> V_471 ;
}
static int
F_173 ( struct V_472 * V_473 , struct V_474 * V_475 )
{
struct V_469 * V_476 = F_174 ( V_473 ) ;
struct V_469 * V_92 = V_475 -> V_470 ;
if ( ( V_473 -> V_477 & V_478 ) != ( V_475 -> V_28 & V_478 ) )
return 0 ;
if ( ( V_476 -> V_479 & V_480 ) !=
( V_92 -> V_479 & V_480 ) )
return 0 ;
if ( V_92 -> V_336 && V_92 -> V_336 < V_476 -> V_336 )
return 0 ;
if ( V_92 -> V_334 && V_92 -> V_334 < V_476 -> V_334 )
return 0 ;
if ( V_476 -> V_481 != V_92 -> V_481 || V_476 -> V_482 != V_92 -> V_482 )
return 0 ;
if ( V_476 -> V_483 != V_92 -> V_483 ||
V_476 -> V_484 != V_92 -> V_484 )
return 0 ;
if ( strcmp ( V_476 -> V_450 -> V_485 , V_92 -> V_450 -> V_485 ) )
return 0 ;
if ( V_476 -> V_236 != V_92 -> V_236 )
return 0 ;
return 1 ;
}
int
F_175 ( struct V_472 * V_473 , void * V_205 )
{
struct V_474 * V_475 = (struct V_474 * ) V_205 ;
struct V_166 * V_415 ;
struct V_469 * V_470 ;
struct V_1 * V_486 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_463 * V_464 ;
struct V_417 V_386 ;
int V_3 = 0 ;
memset ( & V_386 , 0 , sizeof( struct V_417 ) ) ;
F_2 ( & V_20 ) ;
V_470 = F_174 ( V_473 ) ;
V_464 = F_176 ( F_172 ( V_470 ) ) ;
if ( F_127 ( V_464 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_171 ( V_464 ) ;
V_8 = V_10 -> V_8 ;
V_486 = V_8 -> V_2 ;
V_415 = V_475 -> V_167 ;
if ( ! V_415 -> V_348 || ! V_415 -> V_352 )
goto V_487;
V_3 = F_123 ( (struct V_121 * ) & V_386 ,
V_415 -> V_348 ,
strlen ( V_415 -> V_348 ) ,
V_415 -> V_332 ) ;
if ( ! V_3 )
goto V_487;
if ( ! F_111 ( V_486 , (struct V_121 * ) & V_386 , V_415 ) ||
! F_139 ( V_8 , V_415 ) ||
! F_158 ( V_10 , V_415 -> V_352 ) ) {
V_3 = 0 ;
goto V_487;
}
V_3 = F_173 ( V_473 , V_475 ) ;
V_487:
F_3 ( & V_20 ) ;
F_168 ( V_464 ) ;
return V_3 ;
}
int
F_177 ( int V_433 , struct V_7 * V_488 , const char * V_489 ,
const struct V_490 * V_491 , unsigned int * V_492 ,
struct V_493 * * V_494 , int V_261 )
{
char * V_495 ;
int V_3 = 0 ;
* V_492 = 0 ;
* V_494 = NULL ;
if ( V_488 -> V_23 == 0 ) {
V_495 = F_44 ( 2 +
F_92 ( V_488 -> V_452 ,
V_496 * 2 )
+ 1 + 4 + 2 ,
V_142 ) ;
if ( V_495 == NULL )
return - V_110 ;
V_495 [ 0 ] = '\\' ;
V_495 [ 1 ] = '\\' ;
strcpy ( V_495 + 2 , V_488 -> V_452 ) ;
strcpy ( V_495 + 2 + strlen ( V_488 -> V_452 ) , L_163 ) ;
V_3 = F_166 ( V_433 , V_488 , V_495 , NULL , V_491 ) ;
F_4 ( 1 , L_164 , V_3 , V_488 -> V_23 ) ;
F_10 ( V_495 ) ;
}
if ( V_3 == 0 )
V_3 = F_178 ( V_433 , V_488 , V_489 , V_494 ,
V_492 , V_491 , V_261 ) ;
return V_3 ;
}
static inline void
F_179 ( struct V_497 * V_498 )
{
struct V_498 * V_499 = V_498 -> V_499 ;
F_180 ( F_181 ( V_499 ) ) ;
F_182 ( V_499 , L_165 ,
& V_500 [ 0 ] , L_166 , & V_501 [ 0 ] ) ;
}
static inline void
F_183 ( struct V_497 * V_498 )
{
struct V_498 * V_499 = V_498 -> V_499 ;
F_180 ( F_181 ( V_499 ) ) ;
F_182 ( V_499 , L_167 ,
& V_500 [ 1 ] , L_168 , & V_501 [ 1 ] ) ;
}
static inline void
F_179 ( struct V_497 * V_498 )
{
}
static inline void
F_183 ( struct V_497 * V_498 )
{
}
static void F_184 ( char * V_502 , char * V_503 , unsigned int V_105 )
{
unsigned int V_210 , V_211 ;
for ( V_210 = 0 , V_211 = 0 ; V_210 < ( V_105 ) ; V_210 ++ ) {
V_502 [ V_211 ] = 'A' + ( 0x0F & ( V_503 [ V_210 ] >> 4 ) ) ;
V_502 [ V_211 + 1 ] = 'A' + ( 0x0F & V_503 [ V_210 ] ) ;
V_211 += 2 ;
}
}
static int
F_185 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_356 . V_427 != V_374 ) {
struct V_497 * V_497 = V_2 -> V_26 ;
V_3 = V_497 -> V_145 -> V_504 ( V_497 ,
(struct V_121 * ) & V_2 -> V_356 ,
sizeof( V_2 -> V_356 ) ) ;
if ( V_3 < 0 ) {
struct V_376 * V_377 ;
struct V_382 * V_383 ;
V_377 = (struct V_376 * ) & V_2 -> V_356 ;
V_383 = (struct V_382 * ) & V_2 -> V_356 ;
if ( V_383 -> V_505 == V_381 )
F_22 ( 1 , L_169
L_170 ,
& V_383 -> V_385 , V_3 ) ;
else
F_22 ( 1 , L_169
L_171 ,
& V_377 -> V_379 . V_380 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_186 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_506 * V_507 ;
struct V_45 * V_508 ;
V_507 = F_100 ( sizeof( struct V_506 ) ,
V_142 ) ;
if ( V_507 ) {
V_507 -> V_509 . V_510 . V_511 = 32 ;
if ( V_2 -> V_425 &&
V_2 -> V_425 [ 0 ] != 0 )
F_184 ( V_507 -> V_509 .
V_510 . V_512 ,
V_2 -> V_425 ,
V_365 ) ;
else
F_184 ( V_507 -> V_509 .
V_510 . V_512 ,
V_513 ,
V_365 ) ;
V_507 -> V_509 . V_510 . V_514 = 32 ;
if ( V_2 -> V_424 &&
V_2 -> V_424 [ 0 ] != 0 )
F_184 ( V_507 -> V_509 .
V_510 . V_515 ,
V_2 -> V_424 ,
V_365 ) ;
else
F_184 ( V_507 -> V_509 .
V_510 . V_515 ,
L_172 ,
V_365 ) ;
V_507 -> V_509 . V_510 . V_516 = 0 ;
V_507 -> V_509 . V_510 . V_517 = 0 ;
V_508 = (struct V_45 * ) V_507 ;
V_508 -> V_75 = F_28 ( 0x81000044 ) ;
V_3 = F_187 ( V_2 , V_508 , 0x44 ) ;
F_10 ( V_507 ) ;
F_47 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_4 V_387 ;
int V_518 , V_519 ;
struct V_497 * V_497 = V_2 -> V_26 ;
struct V_121 * V_520 ;
V_520 = (struct V_121 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_427 == V_381 ) {
V_387 = ( (struct V_382 * ) V_520 ) -> V_389 ;
V_518 = sizeof( struct V_382 ) ;
V_519 = V_381 ;
} else {
V_387 = ( (struct V_376 * ) V_520 ) -> V_388 ;
V_518 = sizeof( struct V_376 ) ;
V_519 = V_375 ;
}
if ( V_497 == NULL ) {
V_3 = F_188 ( F_113 ( V_2 ) , V_519 , V_521 ,
V_522 , & V_497 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_173 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_174 ) ;
V_2 -> V_26 = V_497 ;
V_497 -> V_499 -> V_523 = V_102 ;
if ( V_519 == V_381 )
F_183 ( V_497 ) ;
else
F_179 ( V_497 ) ;
}
V_3 = F_185 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_497 -> V_499 -> V_524 = 7 * V_82 ;
V_497 -> V_499 -> V_525 = 5 * V_82 ;
if ( V_2 -> V_253 ) {
if ( V_497 -> V_499 -> V_526 < ( 200 * 1024 ) )
V_497 -> V_499 -> V_526 = 200 * 1024 ;
if ( V_497 -> V_499 -> V_527 < ( 140 * 1024 ) )
V_497 -> V_499 -> V_527 = 140 * 1024 ;
}
if ( V_2 -> V_422 ) {
int V_528 = 1 ;
V_3 = F_189 ( V_497 , V_529 , V_530 ,
( char * ) & V_528 , sizeof( V_528 ) ) ;
if ( V_3 )
F_4 ( 1 , L_175 , V_3 ) ;
}
F_4 ( 1 , L_176 ,
V_497 -> V_499 -> V_526 ,
V_497 -> V_499 -> V_527 , V_497 -> V_499 -> V_524 ) ;
V_3 = V_497 -> V_145 -> V_531 ( V_497 , V_520 , V_518 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_177 , V_3 ) ;
F_9 ( V_497 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_387 == F_108 ( V_390 ) )
V_3 = F_186 ( V_2 ) ;
return V_3 ;
}
static int
F_133 ( struct V_1 * V_2 )
{
T_4 * V_387 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_122 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_427 == V_381 )
V_387 = & V_393 -> V_389 ;
else
V_387 = & V_386 -> V_388 ;
if ( * V_387 == 0 ) {
int V_3 ;
* V_387 = F_108 ( V_123 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_387 = F_108 ( V_390 ) ;
}
return F_17 ( V_2 ) ;
}
void F_190 ( int V_433 , struct V_9 * V_10 ,
struct V_469 * V_470 , struct V_166 * V_532 )
{
T_6 V_533 = F_191 ( V_10 -> V_534 . V_535 ) ;
if ( V_532 && V_532 -> V_271 ) {
V_10 -> V_534 . V_535 = 0 ;
V_10 -> V_536 = 0 ;
F_4 ( 1 , L_178 ) ;
return;
} else if ( V_532 )
V_10 -> V_536 = 1 ;
if ( V_10 -> V_536 == 0 ) {
F_4 ( 1 , L_179 ) ;
return;
}
if ( ! F_192 ( V_433 , V_10 ) ) {
T_6 V_537 = F_191 ( V_10 -> V_534 . V_535 ) ;
F_4 ( 1 , L_180 , V_537 ) ;
if ( V_532 == NULL ) {
if ( ( V_533 & V_538 ) == 0 )
V_537 &= ~ V_538 ;
if ( ( V_533 & V_539 ) == 0 ) {
if ( V_537 & V_539 )
F_22 ( 1 , L_181 ) ;
V_537 &= ~ V_539 ;
} else if ( ( V_537 & V_539 ) == 0 ) {
F_22 ( 1 , L_182 ) ;
F_22 ( 1 , L_183 ) ;
}
}
if ( V_537 & V_540 )
F_22 ( 1 , L_184 ) ;
V_537 &= V_541 ;
if ( V_532 && V_532 -> V_304 )
V_537 &= ~ V_538 ;
else if ( V_538 & V_537 ) {
F_4 ( 1 , L_185 ) ;
if ( V_470 )
V_470 -> V_479 |=
V_542 ;
}
if ( V_532 && V_532 -> V_234 == 0 )
V_537 &= ~ V_539 ;
else if ( V_537 & V_539 ) {
F_4 ( 1 , L_186 ) ;
if ( V_470 )
V_470 -> V_479 |=
V_543 ;
}
F_4 ( 1 , L_187 , ( int ) V_537 ) ;
#ifdef F_70
if ( V_537 & V_544 )
F_4 ( 1 , L_188 ) ;
if ( V_537 & V_545 )
F_4 ( 1 , L_189 ) ;
if ( V_537 & V_539 )
F_4 ( 1 , L_190 ) ;
if ( V_537 & V_546 )
F_4 ( 1 , L_191 ) ;
if ( V_537 & V_538 )
F_4 ( 1 , L_192 ) ;
if ( V_537 & V_547 )
F_4 ( 1 , L_193 ) ;
if ( V_537 & V_548 )
F_4 ( 1 , L_194 ) ;
if ( V_537 & V_549 )
F_4 ( 1 , L_195 ) ;
if ( V_537 & V_540 )
F_4 ( 1 , L_196 ) ;
#endif
if ( F_193 ( V_433 , V_10 , V_537 ) ) {
if ( V_532 == NULL ) {
F_4 ( 1 , L_197 ) ;
} else
F_22 ( 1 , L_198
L_199
L_200
L_201
L_202
L_55 ) ;
}
}
}
void F_194 ( struct V_166 * V_550 ,
struct V_469 * V_470 )
{
F_132 ( & V_470 -> V_551 , V_552 ) ;
F_131 ( & V_470 -> V_553 ) ;
V_470 -> V_554 = V_555 ;
V_470 -> V_334 = V_550 -> V_334 ;
V_470 -> V_336 = V_550 -> V_336 ;
V_470 -> V_481 = V_550 -> V_227 ;
V_470 -> V_482 = V_550 -> V_228 ;
V_470 -> V_483 = V_550 -> V_230 ;
V_470 -> V_484 = V_550 -> V_229 ;
F_4 ( 1 , L_203 ,
V_470 -> V_483 , V_470 -> V_484 ) ;
V_470 -> V_236 = V_550 -> V_236 ;
V_470 -> V_450 = V_550 -> V_450 ;
if ( V_550 -> V_258 )
V_470 -> V_479 |= V_556 ;
if ( V_550 -> V_283 )
V_470 -> V_479 |= V_557 ;
if ( V_550 -> V_235 )
V_470 -> V_479 |= V_558 ;
if ( V_550 -> V_261 )
V_470 -> V_479 |= V_559 ;
if ( V_550 -> V_246 )
V_470 -> V_479 |= V_560 ;
if ( V_550 -> V_264 )
V_470 -> V_479 |= V_561 ;
if ( V_550 -> V_275 )
V_470 -> V_479 |= V_562 ;
if ( V_550 -> V_294 )
V_470 -> V_479 |= V_563 ;
if ( V_550 -> V_281 )
V_470 -> V_479 |= V_564 ;
if ( V_550 -> V_299 )
V_470 -> V_479 |= V_565 ;
if ( V_550 -> V_301 )
V_470 -> V_479 |= V_566 ;
if ( V_550 -> V_240 ) {
V_470 -> V_479 |= V_567 ;
V_470 -> V_568 = V_550 -> V_323 ;
}
if ( V_550 -> V_241 ) {
V_470 -> V_479 |= V_569 ;
V_470 -> V_570 = V_550 -> V_325 ;
}
if ( V_550 -> V_213 )
V_470 -> V_479 |= V_571 ;
if ( V_550 -> V_214 )
V_470 -> V_479 |= V_572 ;
if ( V_550 -> V_286 )
V_470 -> V_479 |= V_573 ;
if ( V_550 -> V_316 )
V_470 -> V_479 |= V_574 ;
if ( V_550 -> V_320 )
V_470 -> V_479 |= ( V_575 |
V_556 ) ;
if ( V_550 -> V_192 )
V_470 -> V_479 |= V_576 ;
if ( V_550 -> V_191 ) {
F_4 ( 1 , L_204 ) ;
V_470 -> V_479 |= V_577 ;
}
if ( V_550 -> V_318 ) {
if ( V_550 -> V_264 ) {
F_22 ( 1 , L_205
L_206 ) ;
} else {
V_470 -> V_479 |= V_578 ;
}
}
if ( ( V_550 -> V_301 ) && ( V_550 -> V_286 ) )
F_22 ( 1 , L_207
L_208 ) ;
}
static unsigned int
F_195 ( struct V_9 * V_10 , struct V_166 * V_550 )
{
T_6 V_579 = F_191 ( V_10 -> V_534 . V_535 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_336 ;
if ( V_550 -> V_336 )
V_336 = V_550 -> V_336 ;
else if ( V_10 -> V_536 && ( V_579 & V_548 ) )
V_336 = V_580 ;
else
V_336 = V_581 ;
if ( ! V_10 -> V_536 || ! ( V_579 & V_548 ) )
V_336 = F_64 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_582 & V_583 ) ||
( ! ( V_2 -> V_582 & V_584 ) &&
( V_2 -> V_407 & ( V_409 | V_408 ) ) ) )
V_336 = F_64 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_336 = F_64 (unsigned int, wsize, CIFS_KMAP_SIZE_LIMIT) ;
V_336 = F_64 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_336 ;
}
static unsigned int
F_196 ( struct V_9 * V_10 , struct V_166 * V_550 )
{
T_6 V_579 = F_191 ( V_10 -> V_534 . V_535 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_334 , V_585 ;
if ( V_10 -> V_536 && ( V_579 & V_547 ) )
V_585 = V_580 ;
else if ( V_2 -> V_582 & V_586 )
V_585 = V_587 ;
else
V_585 = V_2 -> V_18 - sizeof( V_588 ) ;
V_334 = V_550 -> V_334 ? V_550 -> V_334 : V_585 ;
if ( ! ( V_2 -> V_582 & V_586 ) )
V_334 = F_64 (unsigned int, CIFSMaxBufSize, rsize) ;
V_334 = F_64 (unsigned int, rsize, CIFS_KMAP_SIZE_LIMIT) ;
V_334 = F_64 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_334 ;
}
static int
F_197 ( int V_433 , struct V_9 * V_10 ,
struct V_469 * V_470 , const char * V_589 )
{
int V_3 ;
T_7 * V_590 ;
V_590 = F_44 ( sizeof( T_7 ) , V_142 ) ;
if ( V_590 == NULL )
return - V_110 ;
V_3 = F_198 ( V_433 , V_10 , V_589 , V_590 ,
0 , V_470 -> V_450 ,
V_470 -> V_479 &
V_559 ) ;
if ( V_3 == - V_591 || V_3 == - V_55 )
V_3 = F_199 ( V_433 , V_10 , V_589 , V_590 ,
V_470 -> V_450 , V_470 -> V_479 &
V_559 ) ;
F_10 ( V_590 ) ;
return V_3 ;
}
static void
F_200 ( struct V_166 * V_415 )
{
F_10 ( V_415 -> V_340 ) ;
F_201 ( V_415 -> V_345 ) ;
if ( V_415 -> V_348 != V_415 -> V_352 + 2 )
F_10 ( V_415 -> V_348 ) ;
F_10 ( V_415 -> V_352 ) ;
F_10 ( V_415 -> V_354 ) ;
F_10 ( V_415 -> V_360 ) ;
F_10 ( V_415 -> V_358 ) ;
}
void
F_202 ( struct V_166 * V_415 )
{
if ( ! V_415 )
return;
F_200 ( V_415 ) ;
F_10 ( V_415 ) ;
}
static char *
F_203 ( const struct V_166 * V_167 ,
const struct V_469 * V_470 )
{
char * V_589 , * V_592 ;
unsigned int V_593 = V_167 -> V_358 ? strlen ( V_167 -> V_358 ) : 0 ;
unsigned int V_594 = F_92 ( V_167 -> V_352 , V_457 + 1 ) ;
V_589 = F_44 ( V_594 + V_593 + 1 , V_142 ) ;
if ( V_589 == NULL )
return F_80 ( - V_110 ) ;
strncpy ( V_589 , V_167 -> V_352 , V_594 ) ;
V_592 = V_589 + V_594 ;
if ( V_593 ) {
strncpy ( V_592 , V_167 -> V_358 , V_593 ) ;
V_592 += V_593 ;
}
* V_592 = '\0' ;
F_204 ( V_589 , F_205 ( V_470 ) ) ;
F_4 ( 1 , L_209 , V_19 , V_589 ) ;
return V_589 ;
}
static int
F_206 ( int V_433 , struct V_7 * V_488 ,
struct V_166 * V_415 , struct V_469 * V_470 ,
int V_595 )
{
int V_3 ;
unsigned int V_596 = 0 ;
struct V_493 * V_597 = NULL ;
char * V_589 = NULL , * V_598 = NULL , * V_599 = NULL ;
V_589 = F_203 ( V_415 , V_470 ) ;
if ( F_127 ( V_589 ) )
return F_128 ( V_589 ) ;
V_598 = V_595 ? V_589 + 1 : V_415 -> V_352 + 1 ;
V_3 = F_177 ( V_433 , V_488 , V_598 , V_470 -> V_450 ,
& V_596 , & V_597 ,
V_470 -> V_479 & V_559 ) ;
if ( ! V_3 && V_596 > 0 ) {
char * V_600 = NULL ;
V_599 = F_207 ( V_470 -> V_203 ,
V_589 + 1 , V_597 ,
& V_600 ) ;
F_208 ( V_597 , V_596 ) ;
if ( F_127 ( V_599 ) ) {
V_3 = F_128 ( V_599 ) ;
V_599 = NULL ;
} else {
F_200 ( V_415 ) ;
memset ( V_415 , '\0' , sizeof( * V_415 ) ) ;
V_3 = F_209 ( V_415 , V_599 ,
V_600 ) ;
}
F_10 ( V_600 ) ;
F_10 ( V_470 -> V_203 ) ;
V_470 -> V_203 = V_599 ;
}
F_10 ( V_589 ) ;
return V_3 ;
}
static int
F_209 ( struct V_166 * V_415 , char * V_601 ,
const char * V_204 )
{
int V_3 = 0 ;
if ( F_90 ( V_601 , V_204 , V_415 ) )
return - V_55 ;
if ( V_415 -> V_188 ) {
F_4 ( 1 , L_210 ) ;
F_10 ( V_415 -> V_340 ) ;
V_415 -> V_340 = NULL ;
} else if ( V_415 -> V_340 ) {
F_4 ( 1 , L_211 , V_415 -> V_340 ) ;
} else {
F_210 ( L_212 ) ;
return - V_55 ;
}
if ( V_415 -> V_360 == NULL ) {
V_415 -> V_450 = F_211 () ;
} else {
V_415 -> V_450 = F_212 ( V_415 -> V_360 ) ;
if ( V_415 -> V_450 == NULL ) {
F_22 ( 1 , L_213 ,
V_415 -> V_360 ) ;
return - V_602 ;
}
}
return V_3 ;
}
struct V_166 *
F_213 ( char * V_601 , const char * V_204 )
{
int V_3 ;
struct V_166 * V_415 ;
V_415 = F_100 ( sizeof( struct V_166 ) , V_142 ) ;
if ( ! V_415 )
return F_80 ( - V_110 ) ;
V_3 = F_209 ( V_415 , V_601 , V_204 ) ;
if ( V_3 ) {
F_202 ( V_415 ) ;
V_415 = F_80 ( V_3 ) ;
}
return V_415 ;
}
int
F_214 ( struct V_469 * V_470 , struct V_166 * V_415 )
{
int V_3 ;
int V_433 ;
struct V_7 * V_488 ;
struct V_9 * V_10 ;
struct V_1 * V_603 ;
char * V_589 ;
struct V_463 * V_464 ;
#ifdef F_215
int V_604 = 0 ;
#endif
V_3 = F_216 ( & V_470 -> V_605 , L_214 , V_606 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_215
V_607:
if ( V_604 ) {
if ( V_10 )
F_160 ( V_10 ) ;
else if ( V_488 )
F_141 ( V_488 ) ;
F_155 ( V_433 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_488 = NULL ;
V_603 = NULL ;
V_589 = NULL ;
V_464 = NULL ;
V_433 = F_142 () ;
V_603 = F_122 ( V_415 ) ;
if ( F_127 ( V_603 ) ) {
V_3 = F_128 ( V_603 ) ;
F_217 ( & V_470 -> V_605 ) ;
goto V_487;
}
V_488 = F_153 ( V_603 , V_415 ) ;
if ( F_127 ( V_488 ) ) {
V_3 = F_128 ( V_488 ) ;
V_488 = NULL ;
goto V_608;
}
V_10 = F_164 ( V_488 , V_415 ) ;
if ( F_127 ( V_10 ) ) {
V_3 = F_128 ( V_10 ) ;
V_10 = NULL ;
goto V_609;
}
if ( V_10 -> V_8 -> V_582 & V_584 ) {
F_190 ( V_433 , V_10 , V_470 , V_415 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_191 ( V_10 -> V_534 . V_535 ) &
V_540 ) ) {
V_3 = - V_610 ;
goto V_608;
}
} else
V_10 -> V_536 = 0 ;
if ( ! V_10 -> V_611 ) {
F_218 ( V_433 , V_10 ) ;
F_219 ( V_433 , V_10 ) ;
}
V_470 -> V_336 = F_195 ( V_10 , V_415 ) ;
V_470 -> V_334 = F_196 ( V_10 , V_415 ) ;
V_470 -> V_605 . V_612 = V_470 -> V_334 / V_613 ;
V_609:
#ifdef F_215
if ( V_604 == 0 ) {
int V_614 = F_206 ( V_433 , V_488 , V_415 ,
V_470 , false ) ;
if ( ! V_614 ) {
V_604 ++ ;
goto V_607;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_589 = F_220 ( V_415 , V_470 , V_10 ) ;
if ( V_589 == NULL ) {
V_3 = - V_110 ;
goto V_608;
}
V_3 = F_197 ( V_433 , V_10 , V_470 , V_589 ) ;
if ( V_3 != 0 && V_3 != - V_615 ) {
F_10 ( V_589 ) ;
goto V_608;
}
F_10 ( V_589 ) ;
}
if ( V_3 == - V_615 ) {
#ifdef F_215
if ( V_604 > V_616 ) {
V_3 = - V_617 ;
goto V_608;
}
V_3 = F_206 ( V_433 , V_488 , V_415 , V_470 ,
true ) ;
if ( ! V_3 ) {
V_604 ++ ;
goto V_607;
}
goto V_608;
#else
V_3 = - V_591 ;
#endif
}
if ( V_3 )
goto V_608;
V_464 = F_100 ( sizeof *V_464 , V_142 ) ;
if ( V_464 == NULL ) {
V_3 = - V_110 ;
goto V_608;
}
V_464 -> V_618 = V_488 -> V_227 ;
V_464 -> V_619 = V_10 ;
V_464 -> V_468 = V_36 ;
F_221 ( V_620 , & V_464 -> V_467 ) ;
F_221 ( V_466 , & V_464 -> V_467 ) ;
V_470 -> V_471 = V_464 ;
F_2 ( & V_470 -> V_553 ) ;
F_222 ( & V_470 -> V_554 , V_464 ) ;
F_3 ( & V_470 -> V_553 ) ;
F_33 ( V_85 , & V_470 -> V_551 ,
V_621 ) ;
V_608:
if ( V_3 ) {
if ( V_10 )
F_160 ( V_10 ) ;
else if ( V_488 )
F_141 ( V_488 ) ;
else
F_116 ( V_603 ) ;
F_217 ( & V_470 -> V_605 ) ;
}
V_487:
F_155 ( V_433 ) ;
return V_3 ;
}
int
F_166 ( unsigned int V_433 , struct V_7 * V_8 ,
const char * V_622 , struct V_9 * V_10 ,
const struct V_490 * V_491 )
{
struct V_45 * V_623 ;
struct V_45 * V_624 ;
T_8 * V_46 ;
T_9 * V_625 ;
unsigned char * V_626 ;
int V_3 = 0 ;
int V_105 ;
T_1 V_627 , V_628 ;
if ( V_8 == NULL )
return - V_629 ;
V_623 = F_35 () ;
if ( V_623 == NULL )
return - V_110 ;
V_624 = V_623 ;
F_223 ( V_623 , V_630 ,
NULL , 4 ) ;
V_623 -> V_631 = F_224 ( V_8 -> V_2 ) ;
V_623 -> V_632 = V_8 -> V_633 ;
V_46 = ( T_8 * ) V_623 ;
V_625 = ( T_9 * ) V_624 ;
V_46 -> V_634 = 0xFF ;
V_46 -> V_461 = F_225 ( V_635 ) ;
V_626 = & V_46 -> V_636 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_407 & V_637 ) ) {
V_46 -> V_638 = F_225 ( 1 ) ;
* V_626 = 0 ;
V_626 ++ ;
} else {
V_46 -> V_638 = F_225 ( V_639 ) ;
#ifdef F_86
if ( ( V_398 & V_186 ) &&
( V_8 -> V_2 -> V_399 == V_400 ) )
F_226 ( V_10 -> V_345 , V_8 -> V_2 -> V_640 ,
V_8 -> V_2 -> V_407 &
V_641 ? true : false ,
V_626 ) ;
else
#endif
V_3 = F_227 ( V_10 -> V_345 , V_8 -> V_2 -> V_640 ,
V_626 , V_491 ) ;
V_626 += V_639 ;
if ( V_8 -> V_582 & V_642 ) {
* V_626 = 0 ;
V_626 ++ ;
}
}
if ( V_8 -> V_2 -> V_407 &
( V_408 | V_409 ) )
V_623 -> V_643 |= V_644 ;
if ( V_8 -> V_582 & V_645 ) {
V_623 -> V_643 |= V_646 ;
}
if ( V_8 -> V_582 & V_647 ) {
V_623 -> V_643 |= V_648 ;
}
if ( V_8 -> V_582 & V_642 ) {
V_623 -> V_643 |= V_649 ;
V_105 =
F_228 ( ( V_650 * ) V_626 , V_622 ,
6 *
( + 256 ) , V_491 ) ;
V_626 += 2 * V_105 ;
V_626 += 2 ;
} else {
strcpy ( V_626 , V_622 ) ;
V_626 += strlen ( V_622 ) + 1 ;
}
strcpy ( V_626 , L_215 ) ;
V_626 += strlen ( L_215 ) ;
V_626 += 1 ;
V_628 = V_626 - & V_46 -> V_636 [ 0 ] ;
V_46 -> V_71 . V_75 = F_28 ( F_27 (
V_46 -> V_71 . V_75 ) + V_628 ) ;
V_46 -> V_651 = F_225 ( V_628 ) ;
V_3 = F_229 ( V_433 , V_8 , V_623 , V_624 , & V_105 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_652 ;
V_10 -> V_455 = V_89 ;
V_10 -> V_22 = false ;
V_10 -> V_653 = V_624 -> V_654 ;
V_626 = F_230 ( V_624 ) ;
V_627 = F_25 ( V_624 ) ;
V_105 = F_92 ( V_626 , V_627 - 2 ) ;
if ( V_623 -> V_643 & V_649 )
V_652 = true ;
else
V_652 = false ;
if ( V_105 == 3 ) {
if ( ( V_626 [ 0 ] == 'I' ) && ( V_626 [ 1 ] == 'P' ) &&
( V_626 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_216 ) ;
V_10 -> V_611 = 1 ;
}
} else if ( V_105 == 2 ) {
if ( ( V_626 [ 0 ] == 'A' ) && ( V_626 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_217 ) ;
}
}
V_626 += V_105 + 1 ;
V_627 -= ( V_105 + 1 ) ;
strncpy ( V_10 -> V_456 , V_622 , V_457 ) ;
F_10 ( V_10 -> V_655 ) ;
V_10 -> V_655 = F_231 ( V_626 ,
V_627 , V_652 ,
V_491 ) ;
F_4 ( 1 , L_218 , V_10 -> V_655 ) ;
if ( ( V_624 -> V_54 == 3 ) ||
( V_624 -> V_54 == 7 ) )
V_10 -> V_461 = F_232 ( V_625 -> V_656 ) ;
else
V_10 -> V_461 = 0 ;
F_4 ( 1 , L_219 , V_10 -> V_461 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_624 -> V_654 ;
}
F_72 ( V_623 ) ;
return V_3 ;
}
void
F_233 ( struct V_469 * V_470 )
{
struct V_657 * V_658 = & V_470 -> V_554 ;
struct V_659 * V_660 ;
struct V_463 * V_464 ;
F_118 ( & V_470 -> V_551 ) ;
F_2 ( & V_470 -> V_553 ) ;
while ( ( V_660 = F_234 ( V_658 ) ) ) {
V_464 = F_235 ( V_660 , struct V_463 , V_661 ) ;
F_176 ( V_464 ) ;
F_236 ( V_466 , & V_464 -> V_467 ) ;
F_237 ( V_660 , V_658 ) ;
F_3 ( & V_470 -> V_553 ) ;
F_168 ( V_464 ) ;
F_2 ( & V_470 -> V_553 ) ;
}
F_3 ( & V_470 -> V_553 ) ;
F_217 ( & V_470 -> V_605 ) ;
F_10 ( V_470 -> V_203 ) ;
F_238 ( V_470 -> V_450 ) ;
F_10 ( V_470 ) ;
}
int F_154 ( unsigned int V_433 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
F_239 ( V_2 , 1 ) ;
V_3 = F_240 ( V_433 , V_8 ) ;
if ( V_3 == - V_113 ) {
F_239 ( V_2 , 1 ) ;
V_3 = F_240 ( V_433 , V_8 ) ;
if ( V_3 == - V_113 )
V_3 = - V_662 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_89 ;
else
V_3 = - V_662 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_156 ( unsigned int V_433 , struct V_7 * V_8 ,
struct V_490 * V_663 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_582 = V_2 -> V_582 ;
if ( V_664 == 0 )
V_8 -> V_582 &= ( ~ V_584 ) ;
F_4 ( 1 , L_220 ,
V_2 -> V_407 , V_2 -> V_582 , V_2 -> V_665 ) ;
V_3 = F_241 ( V_433 , V_8 , V_663 ) ;
if ( V_3 ) {
F_22 ( 1 , L_221 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_666 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_666 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_666 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_222 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_434 = V_89 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_666 . V_33 ) ;
V_8 -> V_666 . V_33 = NULL ;
V_8 -> V_666 . V_34 = 0 ;
F_10 ( V_8 -> V_667 ) ;
V_8 -> V_667 = NULL ;
return V_3 ;
}
static int
F_242 ( struct V_166 * V_167 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_399 ) {
case V_404 :
V_167 -> V_171 = V_668 ;
return 0 ;
case V_402 :
V_167 -> V_171 = V_669 ;
break;
case V_403 :
V_167 -> V_171 = V_670 ;
break;
case V_405 :
V_167 -> V_171 = V_671 ;
break;
case V_400 :
V_167 -> V_171 = V_672 ;
break;
}
return F_146 ( V_167 , V_8 ) ;
}
static struct V_9 *
F_243 ( struct V_469 * V_470 , T_10 V_673 )
{
int V_3 ;
struct V_9 * V_674 = F_244 ( V_470 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_166 * V_532 ;
V_532 = F_100 ( sizeof( * V_532 ) , V_142 ) ;
if ( V_532 == NULL )
return F_80 ( - V_110 ) ;
V_532 -> V_450 = V_470 -> V_450 ;
V_532 -> V_227 = V_673 ;
V_532 -> V_226 = V_673 ;
V_532 -> V_352 = V_674 -> V_456 ;
V_532 -> V_255 = V_674 -> V_255 ;
V_532 -> V_273 = V_674 -> V_273 ;
V_532 -> V_307 = V_674 -> V_307 ;
V_532 -> V_271 = ! V_674 -> V_536 ;
V_3 = F_242 ( V_532 , V_674 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_80 ( V_3 ) ;
goto V_487;
}
F_2 ( & V_20 ) ;
++ V_674 -> V_8 -> V_2 -> V_412 ;
F_3 ( & V_20 ) ;
V_8 = F_153 ( V_674 -> V_8 -> V_2 , V_532 ) ;
if ( F_127 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_116 ( V_674 -> V_8 -> V_2 ) ;
goto V_487;
}
V_10 = F_164 ( V_8 , V_532 ) ;
if ( F_127 ( V_10 ) ) {
F_141 ( V_8 ) ;
goto V_487;
}
if ( V_8 -> V_582 & V_584 )
F_190 ( 0 , V_10 , NULL , V_532 ) ;
V_487:
F_10 ( V_532 -> V_340 ) ;
F_10 ( V_532 -> V_345 ) ;
F_10 ( V_532 ) ;
return V_10 ;
}
struct V_9 *
F_244 ( struct V_469 * V_470 )
{
return F_171 ( F_172 ( V_470 ) ) ;
}
static int
F_245 ( void * V_675 )
{
F_77 () ;
return F_76 ( V_150 ) ? - V_115 : 0 ;
}
static struct V_463 *
F_246 ( struct V_657 * V_658 , T_10 V_676 )
{
struct V_659 * V_660 = V_658 -> V_659 ;
struct V_463 * V_464 ;
while ( V_660 ) {
V_464 = F_235 ( V_660 , struct V_463 , V_661 ) ;
if ( V_464 -> V_618 > V_676 )
V_660 = V_660 -> V_677 ;
else if ( V_464 -> V_618 < V_676 )
V_660 = V_660 -> V_678 ;
else
return V_464 ;
}
return NULL ;
}
static void
F_222 ( struct V_657 * V_658 , struct V_463 * V_679 )
{
struct V_659 * * V_92 = & ( V_658 -> V_659 ) , * V_680 = NULL ;
struct V_463 * V_464 ;
while ( * V_92 ) {
V_464 = F_235 ( * V_92 , struct V_463 , V_661 ) ;
V_680 = * V_92 ;
if ( V_464 -> V_618 > V_679 -> V_618 )
V_92 = & ( ( * V_92 ) -> V_677 ) ;
else
V_92 = & ( ( * V_92 ) -> V_678 ) ;
}
F_247 ( & V_679 -> V_661 , V_680 , V_92 ) ;
F_248 ( & V_679 -> V_661 , V_658 ) ;
}
struct V_463 *
F_249 ( struct V_469 * V_470 )
{
int V_681 ;
T_10 V_673 = F_250 () ;
struct V_463 * V_464 , * V_682 ;
if ( ! ( V_470 -> V_479 & V_575 ) )
return F_176 ( F_172 ( V_470 ) ) ;
F_2 ( & V_470 -> V_553 ) ;
V_464 = F_246 ( & V_470 -> V_554 , V_673 ) ;
if ( V_464 )
F_176 ( V_464 ) ;
F_3 ( & V_470 -> V_553 ) ;
if ( V_464 == NULL ) {
V_682 = F_100 ( sizeof( * V_464 ) , V_142 ) ;
if ( V_682 == NULL )
return F_80 ( - V_110 ) ;
V_682 -> V_618 = V_673 ;
V_682 -> V_619 = F_80 ( - V_610 ) ;
F_221 ( V_683 , & V_682 -> V_467 ) ;
F_221 ( V_466 , & V_682 -> V_467 ) ;
F_176 ( V_682 ) ;
F_2 ( & V_470 -> V_553 ) ;
V_464 = F_246 ( & V_470 -> V_554 , V_673 ) ;
if ( V_464 ) {
F_176 ( V_464 ) ;
F_3 ( & V_470 -> V_553 ) ;
F_10 ( V_682 ) ;
goto V_684;
}
V_464 = V_682 ;
F_222 ( & V_470 -> V_554 , V_464 ) ;
F_3 ( & V_470 -> V_553 ) ;
} else {
V_684:
V_681 = F_251 ( & V_464 -> V_467 , V_683 ,
F_245 ,
V_158 ) ;
if ( V_681 ) {
F_168 ( V_464 ) ;
return F_80 ( V_681 ) ;
}
if ( ! F_127 ( V_464 -> V_619 ) )
return V_464 ;
if ( F_31 ( V_36 , V_464 -> V_468 + V_685 ) ) {
F_168 ( V_464 ) ;
return F_80 ( - V_610 ) ;
}
if ( F_252 ( V_683 , & V_464 -> V_467 ) )
goto V_684;
}
V_464 -> V_619 = F_243 ( V_470 , V_673 ) ;
F_236 ( V_683 , & V_464 -> V_467 ) ;
F_253 ( & V_464 -> V_467 , V_683 ) ;
if ( F_127 ( V_464 -> V_619 ) ) {
F_168 ( V_464 ) ;
return F_80 ( - V_610 ) ;
}
return V_464 ;
}
static void
V_552 ( struct V_78 * V_79 )
{
struct V_469 * V_470 = F_30 ( V_79 , struct V_469 ,
V_551 . V_79 ) ;
struct V_657 * V_658 = & V_470 -> V_554 ;
struct V_659 * V_660 = F_234 ( V_658 ) ;
struct V_659 * V_5 ;
struct V_463 * V_464 ;
F_2 ( & V_470 -> V_553 ) ;
V_660 = F_234 ( V_658 ) ;
while ( V_660 != NULL ) {
V_5 = V_660 ;
V_660 = F_254 ( V_5 ) ;
V_464 = F_235 ( V_5 , struct V_463 , V_661 ) ;
if ( F_170 ( V_620 , & V_464 -> V_467 ) ||
F_69 ( & V_464 -> V_465 ) != 0 ||
F_39 ( V_464 -> V_468 + V_621 , V_36 ) )
continue;
F_176 ( V_464 ) ;
F_236 ( V_466 , & V_464 -> V_467 ) ;
F_237 ( V_5 , V_658 ) ;
F_3 ( & V_470 -> V_553 ) ;
F_168 ( V_464 ) ;
F_2 ( & V_470 -> V_553 ) ;
}
F_3 ( & V_470 -> V_553 ) ;
F_33 ( V_85 , & V_470 -> V_551 ,
V_621 ) ;
}
