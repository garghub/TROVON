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
memset ( V_2 -> V_86 , 0 , F_36 () ) ;
}
if ( ! V_2 -> V_88 ) {
V_2 -> V_88 = ( char * ) F_37 () ;
if ( ! V_2 -> V_88 ) {
F_22 ( 1 , L_26 ) ;
F_18 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_88 , 0 , F_36 () ) ;
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
static struct V_11 *
F_51 ( struct V_1 * V_2 , char * V_124 )
{
struct V_45 * V_44 = (struct V_45 * ) V_124 ;
struct V_11 * V_125 ;
F_2 ( & V_14 ) ;
F_52 (mid, &server->pending_mid_q, qhead) {
if ( V_125 -> V_125 == V_44 -> V_126 &&
V_125 -> V_38 == V_39 &&
F_53 ( V_125 -> V_127 ) == V_44 -> V_52 ) {
F_3 ( & V_14 ) ;
return V_125 ;
}
}
F_3 ( & V_14 ) ;
return NULL ;
}
void
F_54 ( struct V_11 * V_125 , bool V_128 )
{
#ifdef F_55
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
F_56 ( struct V_11 * V_125 , struct V_1 * V_2 ,
char * V_44 , int V_128 )
{
if ( V_128 == 0 && F_20 ( V_44 ) > 0 ) {
V_125 -> V_132 = true ;
if ( V_125 -> V_133 ) {
V_128 = F_23 ( V_44 , V_125 -> V_133 ) ;
if ( V_128 > 0 )
return;
V_125 -> V_134 = true ;
return F_54 ( V_125 , V_128 ) ;
}
if ( ! V_2 -> V_87 ) {
F_22 ( 1 , L_35 ) ;
} else {
V_125 -> V_133 = V_44 ;
V_125 -> V_87 = true ;
V_2 -> V_86 = NULL ;
}
return;
}
V_125 -> V_133 = V_44 ;
V_125 -> V_87 = V_2 -> V_87 ;
if ( ! V_125 -> V_132 ) {
if ( V_2 -> V_87 )
V_2 -> V_86 = NULL ;
else
V_2 -> V_88 = NULL ;
}
F_54 ( V_125 , V_128 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_105 ;
F_2 ( & V_20 ) ;
F_15 ( & V_2 -> V_135 ) ;
F_3 ( & V_20 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_58 ( & V_2 -> V_90 ) ;
F_2 ( & V_2 -> V_136 ) ;
if ( V_2 -> V_137 <= 0 )
V_2 -> V_137 = 1 ;
F_3 ( & V_2 -> V_136 ) ;
F_58 ( & V_2 -> V_138 ) ;
F_18 ( 125 ) ;
if ( V_2 -> V_26 ) {
F_9 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
if ( ! F_59 ( & V_2 -> V_139 ) ) {
struct V_4 V_140 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_140 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_37 ) ;
F_4 ( 1 , L_36 , V_12 -> V_125 ) ;
V_12 -> V_38 = V_141 ;
F_14 ( & V_12 -> V_37 , & V_140 ) ;
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
if ( ! F_59 ( & V_2 -> V_139 ) ) {
F_4 ( 1 , L_38 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_84 ) ;
F_10 ( V_2 -> V_93 ) ;
F_10 ( V_2 ) ;
V_105 = F_60 ( & V_142 ) ;
if ( V_105 > 0 )
F_61 ( V_143 , V_105 + V_144 ,
V_145 ) ;
}
static int
F_62 ( struct V_1 * V_2 , struct V_11 * V_125 )
{
int V_105 ;
char * V_44 = V_2 -> V_88 ;
unsigned int V_146 = F_63 ( V_44 ) ;
if ( V_146 > V_59 + F_64 () - 4 ) {
F_22 ( 1 , L_39 ,
V_146 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
return - V_113 ;
}
if ( V_146 > V_147 - 4 ) {
V_2 -> V_87 = true ;
memcpy ( V_2 -> V_86 , V_44 , V_2 -> V_106 ) ;
V_44 = V_2 -> V_86 ;
}
V_105 = F_48 ( V_2 , V_44 + F_36 () - 1 ,
V_146 - F_36 () + 1 + 4 ) ;
if ( V_105 < 0 )
return V_105 ;
V_2 -> V_106 += V_105 ;
F_65 ( V_44 , V_2 -> V_106 ) ;
V_105 = F_66 ( V_44 , V_2 -> V_106 ) ;
if ( V_105 != 0 )
F_67 ( L_40 , V_44 ,
F_68 (unsigned int, server->total_read, 48 ) ) ;
if ( ! V_125 )
return V_105 ;
F_56 ( V_125 , V_2 , V_44 , V_105 ) ;
return 0 ;
}
static int
F_69 ( void * V_148 )
{
int V_105 ;
struct V_1 * V_2 = V_148 ;
unsigned int V_146 ;
char * V_44 = NULL ;
struct V_149 * V_150 = NULL ;
struct V_11 * V_12 ;
V_151 -> V_28 |= V_152 ;
F_4 ( 1 , L_41 , F_70 ( V_151 ) ) ;
V_105 = F_71 ( & V_142 ) ;
if ( V_105 > 1 )
F_61 ( V_143 , V_105 + V_144 ,
V_145 ) ;
F_72 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
continue;
if ( ! F_34 ( V_2 ) )
continue;
V_2 -> V_87 = false ;
V_44 = V_2 -> V_88 ;
V_146 = 4 ;
V_105 = F_48 ( V_2 , V_44 , V_146 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 = V_105 ;
V_146 = F_63 ( V_44 ) ;
F_4 ( 1 , L_42 , V_146 ) ;
if ( ! F_49 ( V_2 , V_44 [ 0 ] ) )
continue;
if ( V_146 < F_36 () - 1 - 4 ) {
F_22 ( 1 , L_43 ,
V_146 ) ;
F_1 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
continue;
}
V_105 = F_48 ( V_2 , V_44 + 4 ,
F_36 () - 1 - 4 ) ;
if ( V_105 < 0 )
continue;
V_2 -> V_106 += V_105 ;
V_12 = F_51 ( V_2 , V_44 ) ;
if ( ! V_12 || ! V_12 -> V_153 )
V_105 = F_62 ( V_2 , V_12 ) ;
else
V_105 = V_12 -> V_153 ( V_2 , V_12 ) ;
if ( V_105 < 0 )
continue;
if ( V_2 -> V_87 )
V_44 = V_2 -> V_86 ;
V_2 -> V_35 = V_36 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_132 || V_12 -> V_134 )
V_12 -> V_41 ( V_12 ) ;
} else if ( ! F_73 ( V_44 , V_2 ) ) {
F_22 ( 1 , L_44
L_45 , F_74 ( & V_154 ) ) ;
F_67 ( L_46 , V_44 , F_36 () ) ;
#ifdef F_75
F_76 ( V_44 ) ;
F_77 ( V_2 ) ;
#endif
}
}
F_78 ( V_2 -> V_86 ) ;
if ( V_2 -> V_88 )
F_79 ( V_2 -> V_88 ) ;
V_150 = F_80 ( & V_2 -> V_155 , NULL ) ;
F_57 ( V_2 ) ;
if ( ! V_150 ) {
F_81 ( V_156 ) ;
while ( ! F_82 ( V_151 ) ) {
F_83 () ;
F_81 ( V_156 ) ;
}
F_81 ( V_157 ) ;
}
F_84 ( 0 ) ;
}
static char *
F_85 ( const char * V_158 )
{
const char * V_159 ;
char * V_160 , * V_161 ;
unsigned int V_34 ;
V_159 = V_158 + 2 ;
V_161 = strchr ( V_159 , '\\' ) ;
if ( ! V_161 )
return F_86 ( - V_55 ) ;
V_34 = V_161 - V_159 ;
V_160 = F_44 ( ( V_34 + 1 ) , V_145 ) ;
if ( V_160 == NULL )
return F_86 ( - V_110 ) ;
memcpy ( V_160 , V_159 , V_34 ) ;
V_160 [ V_34 ] = '\0' ;
return V_160 ;
}
static int F_87 ( T_3 args [] , unsigned long * V_162 )
{
int V_3 ;
char * string ;
string = F_88 ( args ) ;
if ( string == NULL )
return - V_110 ;
V_3 = F_89 ( string , 0 , V_162 ) ;
F_10 ( string ) ;
return V_3 ;
}
static int F_90 ( char * V_163 ,
struct V_164 * V_165 )
{
T_3 args [ V_166 ] ;
switch ( F_91 ( V_163 , V_167 , args ) ) {
case V_168 :
V_165 -> V_169 |= V_170 ;
break;
case V_171 :
V_165 -> V_169 |= V_170 | V_172 ;
break;
case V_173 :
F_22 ( 1 , L_47 ) ;
break;
case V_174 :
V_165 -> V_169 |= V_175 ;
break;
case V_176 :
V_165 -> V_169 |= V_175 | V_172 ;
break;
case V_177 :
V_165 -> V_169 |= V_178 ;
break;
case V_179 :
V_165 -> V_169 |= V_178 | V_172 ;
break;
case V_180 :
V_165 -> V_169 |= V_181 ;
break;
case V_182 :
V_165 -> V_169 |= V_181 | V_172 ;
break;
#ifdef F_92
case V_183 :
V_165 -> V_169 |= V_184 ;
break;
#endif
case V_185 :
V_165 -> V_186 = 1 ;
break;
default:
F_22 ( 1 , L_48 , V_163 ) ;
return 1 ;
}
return 0 ;
}
static int
F_93 ( const char * V_187 , const char * V_188 ,
struct V_164 * V_165 )
{
char * V_189 , * V_190 ;
char * V_191 = NULL , * V_192 ;
unsigned int V_193 , V_194 , V_195 ;
char V_196 [ 2 ] ;
short int V_197 = - 1 ;
short int V_198 = - 1 ;
bool V_199 = false ;
bool V_200 = false ;
bool V_201 = false ;
char * V_202 = NULL ;
char * V_203 = F_94 () -> V_203 ;
char * string = NULL ;
char * V_204 , * V_163 ;
char V_161 ;
V_196 [ 0 ] = ',' ;
V_196 [ 1 ] = 0 ;
V_161 = V_196 [ 0 ] ;
memset ( V_165 -> V_205 , 0x20 , V_206 ) ;
for ( V_194 = 0 ; V_194 < F_95 ( V_203 , V_206 ) ; V_194 ++ )
V_165 -> V_205 [ V_194 ] = toupper ( V_203 [ V_194 ] ) ;
V_165 -> V_205 [ V_206 ] = 0 ;
V_165 -> V_207 [ 0 ] = 0 ;
V_165 -> V_208 = F_96 () ;
V_165 -> V_209 = F_96 () ;
V_165 -> V_210 = F_97 () ;
V_165 -> V_211 = V_165 -> V_212 = V_213 | V_214 | V_215 ;
V_165 -> V_216 = 1 ;
V_165 -> V_217 = 1 ;
V_165 -> V_218 = V_219 ;
if ( ! V_187 )
goto V_220;
V_191 = F_98 ( V_187 , V_221 , V_145 ) ;
if ( ! V_191 )
goto V_220;
V_192 = V_191 ;
V_190 = V_192 + strlen ( V_192 ) ;
if ( strncmp ( V_192 , L_49 , 4 ) == 0 ) {
if ( V_192 [ 4 ] != 0 ) {
V_196 [ 0 ] = V_192 [ 4 ] ;
V_192 += 5 ;
} else {
F_4 ( 1 , L_50 ) ;
}
}
V_165 -> V_222 = false ;
V_165 -> V_223 = false ;
while ( ( V_189 = F_99 ( & V_192 , V_196 ) ) != NULL ) {
T_3 args [ V_166 ] ;
unsigned long V_162 ;
int V_224 ;
if ( ! * V_189 )
continue;
V_224 = F_91 ( V_189 , V_225 , args ) ;
switch ( V_224 ) {
case V_226 :
break;
case V_227 :
V_165 -> V_228 = 0 ;
break;
case V_229 :
V_165 -> V_228 = 1 ;
break;
case V_230 :
V_197 = 1 ;
break;
case V_231 :
V_197 = 0 ;
break;
case V_232 :
V_165 -> V_233 = 1 ;
break;
case V_234 :
V_165 -> V_235 = 1 ;
break;
case V_236 :
V_165 -> V_237 = 1 ;
break;
case V_238 :
V_165 -> V_237 = 0 ;
break;
case V_239 :
V_165 -> V_240 = 0 ;
break;
case V_241 :
V_165 -> V_240 = 1 ;
break;
case V_242 :
V_165 -> V_243 = 1 ;
break;
case V_244 :
V_165 -> V_243 = 0 ;
break;
case V_245 :
V_165 -> V_246 = 1 ;
break;
case V_247 :
V_165 -> V_246 = 0 ;
break;
case V_248 :
V_165 -> V_249 = 1 ;
break;
case V_250 :
V_165 -> V_216 = 1 ;
break;
case V_251 :
V_165 -> V_216 = 0 ;
break;
case V_252 :
V_165 -> V_253 = 1 ;
break;
case V_254 :
V_165 -> V_255 = 1 ;
break;
case V_256 :
V_165 -> V_257 = 0 ;
break;
case V_258 :
V_165 -> V_257 = 1 ;
if ( V_165 -> V_212 ==
( V_259 & ~ ( V_260 | V_261 ) ) )
V_165 -> V_212 = V_259 ;
break;
case V_262 :
V_165 -> V_263 = 1 ;
break;
case V_264 :
V_165 -> V_265 = 1 ;
break;
case V_266 :
V_165 -> V_265 = 0 ;
break;
case V_267 :
V_165 -> V_268 = true ;
break;
case V_269 :
V_165 -> V_268 = false ;
break;
case V_270 :
V_165 -> V_237 = 0 ;
break;
case V_271 :
V_165 -> V_237 = 1 ;
break;
case V_272 :
V_165 -> V_273 = 0 ;
break;
case V_274 :
V_165 -> V_273 = 1 ;
break;
case V_275 :
V_165 -> V_276 = 1 ;
break;
case V_277 :
V_165 -> V_276 = 0 ;
break;
case V_278 :
V_165 -> V_217 = 1 ;
break;
case V_279 :
V_165 -> V_217 = 0 ;
break;
case V_280 :
V_165 -> V_281 = 1 ;
break;
case V_282 :
V_165 -> V_283 = 1 ;
break;
case V_284 :
V_165 -> V_283 = 0 ;
break;
case V_285 :
V_165 -> V_286 = 0 ;
break;
case V_287 :
V_165 -> V_286 = 1 ;
break;
case V_288 :
V_165 -> V_289 = 1 ;
break;
case V_290 :
V_165 -> V_169 |= V_172 ;
break;
case V_291 :
V_165 -> V_292 = 1 ;
break;
case V_293 :
V_165 -> V_294 = 1 ;
break;
case V_295 :
V_165 -> V_296 = 1 ;
break;
case V_297 :
F_100 ( V_298 L_51
L_52
L_53 ) ;
break;
case V_299 :
#ifndef F_101
F_22 ( 1 , L_54
L_55 ) ;
goto V_220;
#endif
V_165 -> V_300 = true ;
break;
case V_301 :
V_165 -> V_302 = true ;
break;
case V_303 :
V_165 -> V_304 = true ;
break;
case V_305 :
V_201 = true ;
break;
case V_306 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_56 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_307 = V_162 ;
V_165 -> V_222 = true ;
break;
case V_308 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_57 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_309 = V_162 ;
V_165 -> V_223 = true ;
break;
case V_310 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_58 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_209 = V_162 ;
V_199 = true ;
break;
case V_311 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_59 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_208 = V_162 ;
break;
case V_312 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_60 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_210 = V_162 ;
V_200 = true ;
break;
case V_313 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_61 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_212 = V_162 ;
break;
case V_314 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_62 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_211 = V_162 ;
break;
case V_315 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_63 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_316 = V_162 ;
break;
case V_317 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_64 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_318 = V_162 ;
break;
case V_319 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_65 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_320 = V_162 ;
break;
case V_321 :
if ( F_87 ( args , & V_162 ) ) {
F_22 ( 1 , L_66 ,
V_19 ) ;
goto V_220;
}
V_165 -> V_218 = V_82 * V_162 ;
if ( V_165 -> V_218 > V_322 ) {
F_22 ( 1 , L_67
L_68 ) ;
goto V_220;
}
break;
case V_323 :
V_165 -> V_186 = 1 ;
V_165 -> V_324 = NULL ;
break;
case V_325 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_95 ( string , V_327 ) >
V_327 ) {
F_100 ( V_298 L_69 ) ;
goto V_220;
}
V_165 -> V_324 = F_102 ( string , V_145 ) ;
if ( ! V_165 -> V_324 ) {
F_100 ( V_298 L_70
L_71 ) ;
goto V_220;
}
break;
case V_328 :
V_165 -> V_329 = NULL ;
break;
case V_330 :
V_163 = strchr ( V_189 , '=' ) ;
V_163 ++ ;
V_204 = ( char * ) V_163 + strlen ( V_163 ) ;
if ( V_204 < V_190 && V_204 [ 1 ] == V_161 )
V_204 [ 0 ] = V_161 ;
while ( ( V_204 = strchr ( V_204 , V_161 ) ) != NULL &&
( V_204 [ 1 ] == V_161 ) ) {
V_204 = ( char * ) & V_204 [ 2 ] ;
}
if ( V_204 ) {
V_204 [ 0 ] = '\0' ;
V_192 = ( char * ) & V_204 [ 1 ] ;
} else
V_192 = V_190 ;
V_193 = strlen ( V_163 ) ;
V_165 -> V_329 = F_103 ( V_193 + 1 , V_145 ) ;
if ( V_165 -> V_329 == NULL ) {
F_100 ( V_298 L_70
L_72 ) ;
goto V_220;
}
for ( V_194 = 0 , V_195 = 0 ; V_194 < V_193 ; V_194 ++ , V_195 ++ ) {
V_165 -> V_329 [ V_195 ] = V_163 [ V_194 ] ;
if ( ( V_163 [ V_194 ] == V_161 ) &&
V_163 [ V_194 + 1 ] == V_161 )
V_194 ++ ;
}
V_165 -> V_329 [ V_195 ] = '\0' ;
break;
case V_331 :
V_165 -> V_332 = NULL ;
break;
case V_333 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_95 ( string , V_334 ) >
V_334 ) {
F_100 ( V_298 L_73
L_74 ) ;
goto V_220;
}
V_165 -> V_332 = F_102 ( string , V_145 ) ;
if ( ! V_165 -> V_332 ) {
F_100 ( V_298 L_70
L_75 ) ;
goto V_220;
}
break;
case V_335 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
V_193 = F_95 ( string , 300 ) ;
if ( V_193 == 300 ) {
F_100 ( V_298 L_76 ) ;
goto V_220;
}
V_165 -> V_336 = F_44 ( V_193 + 1 , V_145 ) ;
if ( V_165 -> V_336 == NULL ) {
F_100 ( V_298 L_77 ) ;
goto V_220;
}
strcpy ( V_165 -> V_336 , string ) ;
if ( strncmp ( string , L_78 , 2 ) == 0 ) {
V_165 -> V_336 [ 0 ] = '\\' ;
V_165 -> V_336 [ 1 ] = '\\' ;
} else if ( strncmp ( string , L_79 , 2 ) != 0 ) {
F_100 ( V_298 L_80
L_81 ) ;
goto V_220;
}
break;
case V_337 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_95 ( string , 256 ) == 256 ) {
F_100 ( V_298 L_82
L_83 ) ;
goto V_220;
}
V_165 -> V_338 = F_102 ( string , V_145 ) ;
if ( ! V_165 -> V_338 ) {
F_100 ( V_298 L_70
L_84 ) ;
goto V_220;
}
F_4 ( 1 , L_85 ) ;
break;
case V_339 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( ! F_104 (
(struct V_121 * ) & V_165 -> V_340 ,
string , strlen ( string ) ) ) {
F_100 ( V_298 L_86
L_87 , string ) ;
goto V_220;
}
break;
case V_341 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
V_193 = F_95 ( string , 1024 ) ;
if ( string [ 0 ] != '/' )
V_193 ++ ;
if ( V_193 > 1024 ) {
F_100 ( V_298 L_88 ) ;
goto V_220;
}
V_165 -> V_342 = F_44 ( V_193 + 1 , V_145 ) ;
if ( V_165 -> V_342 == NULL ) {
F_100 ( V_298 L_70
L_89 ) ;
goto V_220;
}
if ( string [ 0 ] != '/' ) {
V_165 -> V_342 [ 0 ] = '/' ;
strcpy ( V_165 -> V_342 + 1 , string ) ;
} else
strcpy ( V_165 -> V_342 , string ) ;
break;
case V_343 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_95 ( string , 1024 ) >= 65 ) {
F_100 ( V_298 L_90
L_91 ) ;
goto V_220;
}
if ( F_105 ( string , L_92 , 7 ) != 0 ) {
V_165 -> V_344 = F_102 ( string ,
V_145 ) ;
if ( ! V_165 -> V_344 ) {
F_100 ( V_298 L_93
L_94 ) ;
goto V_220;
}
}
F_4 ( 1 , L_95 , string ) ;
break;
case V_345 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_105 ( string , L_96 , 11 ) == 0 )
V_165 -> V_346 = 1 ;
break;
case V_347 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
memset ( V_165 -> V_205 , 0x20 ,
V_206 ) ;
for ( V_194 = 0 ; V_194 < V_206 ; V_194 ++ ) {
if ( string [ V_194 ] == 0 )
break;
V_165 -> V_205 [ V_194 ] = string [ V_194 ] ;
}
if ( V_194 == V_206 && string [ V_194 ] != 0 )
F_100 ( V_298 L_97
L_98 ) ;
break;
case V_348 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
memset ( V_165 -> V_207 , 0x20 ,
V_349 ) ;
for ( V_194 = 0 ; V_194 < 15 ; V_194 ++ ) {
if ( string [ V_194 ] == 0 )
break;
V_165 -> V_207 [ V_194 ] = string [ V_194 ] ;
}
if ( V_194 == V_206 && string [ V_194 ] != 0 )
F_100 ( V_298 L_99
L_100 ) ;
break;
case V_350 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_105 ( string , L_101 , 4 ) == 0 ||
F_105 ( string , L_102 , 1 ) == 0 ) {
break;
}
F_100 ( V_298 L_103
L_104 ) ;
goto V_220;
case V_351 :
string = F_88 ( args ) ;
if ( string == NULL )
goto V_326;
if ( F_90 ( string , V_165 ) != 0 )
goto V_220;
break;
default:
if ( ! V_202 )
V_202 = V_189 ;
break;
}
F_10 ( string ) ;
string = NULL ;
}
if ( ! V_201 && V_202 ) {
F_100 ( V_352 L_105 , V_202 ) ;
goto V_220;
}
#ifndef F_106
if ( V_165 -> V_304 ) {
F_22 ( 1 , L_106
L_107 ) ;
goto V_220;
}
#endif
if ( V_165 -> V_332 == NULL )
V_165 -> V_332 = & V_165 -> V_336 [ 2 ] ;
if ( V_199 )
V_165 -> V_197 = V_197 ;
else if ( V_197 == 1 )
F_100 ( V_353 L_108
L_109 ) ;
if ( V_200 )
V_165 -> V_198 = V_198 ;
else if ( V_198 == 1 )
F_100 ( V_353 L_110
L_111 ) ;
F_10 ( V_191 ) ;
return 0 ;
V_326:
F_100 ( V_298 L_112 ) ;
V_220:
F_10 ( string ) ;
F_10 ( V_191 ) ;
return 1 ;
}
static bool
F_107 ( struct V_121 * V_340 , struct V_121 * V_354 )
{
switch ( V_340 -> V_355 ) {
case V_356 :
return ( V_354 -> V_355 == V_356 ) ;
case V_357 : {
struct V_358 * V_359 = (struct V_358 * ) V_340 ;
struct V_358 * V_360 = (struct V_358 * ) V_354 ;
return ( V_359 -> V_361 . V_362 == V_360 -> V_361 . V_362 ) ;
}
case V_363 : {
struct V_364 * V_365 = (struct V_364 * ) V_340 ;
struct V_364 * V_366 = (struct V_364 * ) & V_354 ;
return F_108 ( & V_365 -> V_367 , & V_366 -> V_367 ) ;
}
default:
F_109 ( 1 ) ;
return false ;
}
}
static bool
F_110 ( struct V_1 * V_2 , struct V_121 * V_368 )
{
T_4 V_316 , * V_369 ;
switch ( V_368 -> V_355 ) {
case V_357 :
V_369 = & ( (struct V_358 * ) & V_2 -> V_122 ) -> V_370 ;
V_316 = ( (struct V_358 * ) V_368 ) -> V_370 ;
break;
case V_363 :
V_369 = & ( (struct V_364 * ) & V_2 -> V_122 ) -> V_371 ;
V_316 = ( (struct V_364 * ) V_368 ) -> V_371 ;
break;
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! V_316 ) {
V_316 = F_111 ( V_123 ) ;
if ( V_316 == * V_369 )
return true ;
V_316 = F_111 ( V_372 ) ;
}
return V_316 == * V_369 ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_121 * V_368 ,
struct V_121 * V_340 )
{
switch ( V_368 -> V_355 ) {
case V_357 : {
struct V_358 * V_373 = (struct V_358 * ) V_368 ;
struct V_358 * V_374 =
(struct V_358 * ) & V_2 -> V_122 ;
if ( V_373 -> V_361 . V_362 != V_374 -> V_361 . V_362 )
return false ;
break;
}
case V_363 : {
struct V_364 * V_375 = (struct V_364 * ) V_368 ;
struct V_364 * V_376 =
(struct V_364 * ) & V_2 -> V_122 ;
if ( ! F_108 ( & V_375 -> V_367 ,
& V_376 -> V_367 ) )
return false ;
if ( V_375 -> V_377 != V_376 -> V_377 )
return false ;
break;
}
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! F_107 ( V_340 , (struct V_121 * ) & V_2 -> V_340 ) )
return false ;
return true ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
unsigned int V_378 ;
if ( V_165 -> V_169 & ( ~ ( V_172 | V_379 ) ) )
V_378 = V_165 -> V_169 ;
else
V_378 = V_380 | V_165 -> V_169 ;
switch ( V_2 -> V_381 ) {
case V_382 :
if ( ! ( V_378 & ( V_184 | V_383 ) ) )
return false ;
break;
case V_384 :
if ( ! ( V_378 & V_181 ) )
return false ;
break;
case V_385 :
if ( ! ( V_378 & V_178 ) )
return false ;
break;
case V_386 :
if ( ! ( V_378 & V_170 ) )
return false ;
break;
case V_387 :
if ( ! ( V_378 & V_175 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_378 & V_388 ) == 0 &&
( V_2 -> V_389 & V_390 ) )
return false ;
else if ( ( ( V_378 & V_172 ) == V_172 ) &&
( V_2 -> V_389 &
( V_391 | V_390 ) ) == 0 )
return false ;
return true ;
}
static int F_114 ( struct V_1 * V_2 , struct V_121 * V_368 ,
struct V_164 * V_165 )
{
if ( ! F_115 ( F_116 ( V_2 ) , V_151 -> V_392 -> V_393 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_368 ,
(struct V_121 * ) & V_165 -> V_340 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_368 ) )
return 0 ;
if ( ! F_113 ( V_2 , V_165 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_117 ( struct V_121 * V_368 , struct V_164 * V_165 )
{
struct V_1 * V_2 ;
F_2 ( & V_20 ) ;
F_52 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_114 ( V_2 , V_368 , V_165 ) )
continue;
++ V_2 -> V_394 ;
F_3 ( & V_20 ) ;
F_4 ( 1 , L_113 ) ;
return V_2 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_118 ( struct V_1 * V_2 )
{
struct V_149 * V_395 ;
F_2 ( & V_20 ) ;
if ( -- V_2 -> V_394 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_119 ( F_116 ( V_2 ) ) ;
F_15 ( & V_2 -> V_135 ) ;
F_3 ( & V_20 ) ;
F_120 ( & V_2 -> V_80 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_10 ( V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 = NULL ;
V_2 -> V_32 . V_34 = 0 ;
V_395 = F_80 ( & V_2 -> V_155 , NULL ) ;
if ( V_395 )
F_123 ( V_396 , V_395 ) ;
}
static struct V_1 *
F_124 ( struct V_164 * V_397 )
{
struct V_1 * V_398 = NULL ;
struct V_399 V_368 ;
struct V_358 * V_400 = (struct V_358 * ) & V_368 ;
struct V_364 * V_401 = (struct V_364 * ) & V_368 ;
int V_3 ;
memset ( & V_368 , 0 , sizeof( struct V_399 ) ) ;
F_4 ( 1 , L_114 , V_397 -> V_336 , V_397 -> V_332 ) ;
if ( V_397 -> V_332 && V_397 -> V_336 ) {
V_3 = F_125 ( (struct V_121 * ) & V_368 ,
V_397 -> V_332 ,
strlen ( V_397 -> V_332 ) ,
V_397 -> V_316 ) ;
if ( ! V_3 ) {
V_3 = - V_55 ;
goto V_402;
}
} else if ( V_397 -> V_332 ) {
F_22 ( 1 , L_115 ) ;
V_3 = - V_55 ;
goto V_402;
} else {
F_22 ( 1 , L_116
L_117 ) ;
V_3 = - V_55 ;
goto V_402;
}
V_398 = F_117 ( (struct V_121 * ) & V_368 , V_397 ) ;
if ( V_398 )
return V_398 ;
V_398 = F_103 ( sizeof( struct V_1 ) , V_145 ) ;
if ( ! V_398 ) {
V_3 = - V_110 ;
goto V_402;
}
V_3 = F_126 ( V_398 ) ;
if ( V_3 ) {
F_22 ( 1 , L_118 , V_3 ) ;
goto V_402;
}
F_127 ( V_398 , F_128 ( V_151 -> V_392 -> V_393 ) ) ;
V_398 -> V_84 = F_85 ( V_397 -> V_336 ) ;
if ( F_129 ( V_398 -> V_84 ) ) {
V_3 = F_130 ( V_398 -> V_84 ) ;
goto V_403;
}
V_398 -> V_233 = V_397 -> V_233 ;
V_398 -> V_235 = V_397 -> V_235 ;
V_398 -> V_404 = V_397 -> V_346 ;
V_398 -> V_405 = 0 ;
V_398 -> V_137 = 1 ;
F_131 ( & V_398 -> V_90 ) ;
F_131 ( & V_398 -> V_138 ) ;
F_12 ( & V_398 -> V_139 ) ;
F_132 ( & V_398 -> V_25 ) ;
memcpy ( V_398 -> V_406 ,
V_397 -> V_205 , V_349 ) ;
memcpy ( V_398 -> V_407 ,
V_397 -> V_207 , V_349 ) ;
V_398 -> V_31 = false ;
V_398 -> V_30 = 0 ;
V_398 -> V_35 = V_36 ;
F_133 ( & V_398 -> V_136 ) ;
F_12 ( & V_398 -> V_135 ) ;
F_12 ( & V_398 -> V_21 ) ;
F_134 ( & V_398 -> V_80 , F_29 ) ;
V_398 -> V_15 = V_408 ;
memcpy ( & V_398 -> V_340 , & V_397 -> V_340 ,
sizeof( V_398 -> V_340 ) ) ;
++ V_398 -> V_394 ;
if ( V_368 . V_409 == V_363 ) {
F_4 ( 1 , L_119 ) ;
memcpy ( & V_398 -> V_122 , V_401 ,
sizeof( struct V_364 ) ) ;
} else
memcpy ( & V_398 -> V_122 , V_400 ,
sizeof( struct V_358 ) ) ;
V_3 = F_135 ( V_398 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_120 ) ;
goto V_403;
}
F_136 ( V_410 ) ;
V_398 -> V_155 = F_137 ( F_69 ,
V_398 , L_121 ) ;
if ( F_129 ( V_398 -> V_155 ) ) {
V_3 = F_130 ( V_398 -> V_155 ) ;
F_22 ( 1 , L_122 , V_3 ) ;
F_138 ( V_410 ) ;
goto V_403;
}
V_398 -> V_15 = V_43 ;
F_2 ( & V_20 ) ;
F_139 ( & V_398 -> V_135 , & V_411 ) ;
F_3 ( & V_20 ) ;
F_140 ( V_398 ) ;
F_33 ( V_85 , & V_398 -> V_80 , V_81 ) ;
return V_398 ;
V_403:
F_121 ( V_398 ) ;
F_119 ( F_116 ( V_398 ) ) ;
V_402:
if ( V_398 ) {
if ( ! F_129 ( V_398 -> V_84 ) )
F_10 ( V_398 -> V_84 ) ;
if ( V_398 -> V_26 )
F_9 ( V_398 -> V_26 ) ;
F_10 ( V_398 ) ;
}
return F_86 ( V_3 ) ;
}
static int F_141 ( struct V_7 * V_8 , struct V_164 * V_165 )
{
switch ( V_8 -> V_2 -> V_381 ) {
case V_386 :
if ( V_165 -> V_208 != V_8 -> V_208 )
return 0 ;
break;
default:
if ( V_8 -> V_412 == NULL ) {
if ( ! V_165 -> V_186 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_412 ,
V_165 -> V_324 ? V_165 -> V_324 : L_123 ,
V_327 ) )
return 0 ;
if ( strlen ( V_165 -> V_324 ) != 0 &&
V_8 -> V_329 != NULL &&
strncmp ( V_8 -> V_329 ,
V_165 -> V_329 ? V_165 -> V_329 : L_123 ,
V_413 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_142 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_7 * V_8 ;
F_2 ( & V_20 ) ;
F_52 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_141 ( V_8 , V_165 ) )
continue;
++ V_8 -> V_414 ;
F_3 ( & V_20 ) ;
return V_8 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_143 ( struct V_7 * V_8 )
{
int V_415 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( 1 , L_124 , V_19 , V_8 -> V_414 ) ;
F_2 ( & V_20 ) ;
if ( -- V_8 -> V_414 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_8 -> V_21 ) ;
F_3 ( & V_20 ) ;
if ( V_8 -> V_416 == V_89 ) {
V_415 = F_144 () ;
F_145 ( V_415 , V_8 ) ;
F_146 ( V_415 ) ;
}
F_147 ( V_8 ) ;
F_118 ( V_2 ) ;
}
static int
F_148 ( struct V_164 * V_165 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_417 , * V_161 , * V_418 ;
T_5 V_34 ;
struct V_419 * V_419 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_358 * V_420 ;
struct V_364 * V_421 ;
struct V_422 * V_423 ;
V_417 = F_44 ( V_424 , V_145 ) ;
if ( ! V_417 )
return - V_110 ;
switch ( V_2 -> V_122 . V_409 ) {
case V_357 :
V_420 = (struct V_358 * ) & V_2 -> V_122 ;
sprintf ( V_417 , L_125 , & V_420 -> V_361 . V_362 ) ;
break;
case V_363 :
V_421 = (struct V_364 * ) & V_2 -> V_122 ;
sprintf ( V_417 , L_126 , & V_421 -> V_367 . V_425 ) ;
break;
default:
F_4 ( 1 , L_127 , V_2 -> V_122 . V_409 ) ;
V_3 = - V_55 ;
goto V_402;
}
F_4 ( 1 , L_128 , V_19 , V_417 ) ;
V_419 = F_149 ( & V_426 , V_417 , L_123 ) ;
if ( F_129 ( V_419 ) ) {
if ( ! V_8 -> V_427 ) {
F_4 ( 1 , L_129 ) ;
V_3 = F_130 ( V_419 ) ;
goto V_402;
}
sprintf ( V_417 , L_130 , V_8 -> V_427 ) ;
F_4 ( 1 , L_128 , V_19 , V_417 ) ;
V_419 = F_149 ( & V_426 , V_417 , L_123 ) ;
if ( F_129 ( V_419 ) ) {
V_3 = F_130 ( V_419 ) ;
goto V_402;
}
}
F_150 ( & V_419 -> V_428 ) ;
V_423 = V_419 -> V_418 . V_189 ;
if ( F_151 ( V_423 ) ) {
V_3 = V_423 ? F_130 ( V_423 ) : - V_55 ;
goto V_429;
}
V_418 = ( char * ) V_423 -> V_189 ;
V_161 = F_152 ( V_418 , V_423 -> V_430 , ':' ) ;
F_4 ( 1 , L_131 , V_418 ) ;
if ( ! V_161 ) {
F_4 ( 1 , L_132 ,
V_423 -> V_430 ) ;
V_3 = - V_55 ;
goto V_429;
}
V_34 = V_161 - V_418 ;
if ( V_34 > V_327 || V_34 <= 0 ) {
F_4 ( 1 , L_133 , V_34 ) ;
V_3 = - V_55 ;
goto V_429;
}
V_165 -> V_324 = F_98 ( V_418 , V_34 , V_145 ) ;
if ( ! V_165 -> V_324 ) {
F_4 ( 1 , L_134 , V_34 ) ;
V_3 = - V_110 ;
goto V_429;
}
F_4 ( 1 , L_135 , V_19 , V_165 -> V_324 ) ;
V_34 = V_419 -> V_430 - ( V_34 + 1 ) ;
if ( V_34 > V_413 || V_34 <= 0 ) {
F_4 ( 1 , L_136 , V_34 ) ;
V_3 = - V_55 ;
F_10 ( V_165 -> V_324 ) ;
V_165 -> V_324 = NULL ;
goto V_429;
}
++ V_161 ;
V_165 -> V_329 = F_98 ( V_161 , V_34 , V_145 ) ;
if ( ! V_165 -> V_329 ) {
F_4 ( 1 , L_137 , V_34 ) ;
V_3 = - V_110 ;
F_10 ( V_165 -> V_324 ) ;
V_165 -> V_324 = NULL ;
goto V_429;
}
V_429:
F_153 ( & V_419 -> V_428 ) ;
F_154 ( V_419 ) ;
V_402:
F_10 ( V_417 ) ;
F_4 ( 1 , L_138 , V_19 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_155 ( struct V_1 * V_2 , struct V_164 * V_397 )
{
int V_3 = - V_110 , V_415 ;
struct V_7 * V_8 ;
struct V_358 * V_368 = (struct V_358 * ) & V_2 -> V_122 ;
struct V_364 * V_375 = (struct V_364 * ) & V_2 -> V_122 ;
V_415 = F_144 () ;
V_8 = F_142 ( V_2 , V_397 ) ;
if ( V_8 ) {
F_4 ( 1 , L_139 , V_8 -> V_416 ) ;
F_7 ( & V_8 -> V_431 ) ;
V_3 = F_156 ( V_415 , V_8 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_431 ) ;
F_143 ( V_8 ) ;
F_157 ( V_415 ) ;
return F_86 ( V_3 ) ;
}
if ( V_8 -> V_22 ) {
F_4 ( 1 , L_140 ) ;
V_3 = F_158 ( V_415 , V_8 ,
V_397 -> V_432 ) ;
if ( V_3 ) {
F_11 ( & V_8 -> V_431 ) ;
F_143 ( V_8 ) ;
F_157 ( V_415 ) ;
return F_86 ( V_3 ) ;
}
}
F_11 ( & V_8 -> V_431 ) ;
F_118 ( V_2 ) ;
F_157 ( V_415 ) ;
return V_8 ;
}
F_4 ( 1 , L_141 ) ;
V_8 = F_159 () ;
if ( V_8 == NULL )
goto V_433;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_122 . V_409 == V_363 )
sprintf ( V_8 -> V_434 , L_142 , & V_375 -> V_367 ) ;
else
sprintf ( V_8 -> V_434 , L_143 , & V_368 -> V_361 ) ;
if ( V_397 -> V_324 ) {
V_8 -> V_412 = F_102 ( V_397 -> V_324 , V_145 ) ;
if ( ! V_8 -> V_412 )
goto V_433;
}
if ( V_397 -> V_329 ) {
V_8 -> V_329 = F_102 ( V_397 -> V_329 , V_145 ) ;
if ( ! V_8 -> V_329 )
goto V_433;
}
if ( V_397 -> V_338 ) {
V_8 -> V_427 = F_102 ( V_397 -> V_338 , V_145 ) ;
if ( ! V_8 -> V_427 )
goto V_433;
}
V_8 -> V_208 = V_397 -> V_208 ;
V_8 -> V_209 = V_397 -> V_209 ;
if ( ( V_397 -> V_169 == 0 ) && V_435 == false ) {
V_435 = true ;
F_22 ( 1 , L_144
L_145
L_146 ) ;
}
V_8 -> V_436 = V_397 -> V_169 ;
F_7 ( & V_8 -> V_431 ) ;
V_3 = F_156 ( V_415 , V_8 ) ;
if ( ! V_3 )
V_3 = F_158 ( V_415 , V_8 , V_397 -> V_432 ) ;
F_11 ( & V_8 -> V_431 ) ;
if ( V_3 )
goto V_433;
F_2 ( & V_20 ) ;
F_139 ( & V_8 -> V_21 , & V_2 -> V_21 ) ;
F_3 ( & V_20 ) ;
F_157 ( V_415 ) ;
return V_8 ;
V_433:
F_147 ( V_8 ) ;
F_157 ( V_415 ) ;
return F_86 ( V_3 ) ;
}
static int F_160 ( struct V_9 * V_10 , const char * V_158 )
{
if ( V_10 -> V_437 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_438 , V_158 , V_439 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_161 ( struct V_7 * V_8 , const char * V_158 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_20 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_24 ) ;
if ( ! F_160 ( V_10 , V_158 ) )
continue;
++ V_10 -> V_440 ;
F_3 ( & V_20 ) ;
return V_10 ;
}
F_3 ( & V_20 ) ;
return NULL ;
}
static void
F_162 ( struct V_9 * V_10 )
{
int V_415 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( 1 , L_147 , V_19 , V_10 -> V_440 ) ;
F_2 ( & V_20 ) ;
if ( -- V_10 -> V_440 > 0 ) {
F_3 ( & V_20 ) ;
return;
}
F_15 ( & V_10 -> V_24 ) ;
F_3 ( & V_20 ) ;
V_415 = F_144 () ;
F_163 ( V_415 , V_10 ) ;
F_146 ( V_415 ) ;
F_164 ( V_10 ) ;
F_165 ( V_10 ) ;
F_143 ( V_8 ) ;
}
static struct V_9 *
F_166 ( struct V_7 * V_8 , struct V_164 * V_397 )
{
int V_3 , V_415 ;
struct V_9 * V_10 ;
V_10 = F_161 ( V_8 , V_397 -> V_336 ) ;
if ( V_10 ) {
F_4 ( 1 , L_148 ) ;
F_143 ( V_8 ) ;
if ( V_10 -> V_292 != V_397 -> V_292 )
F_22 ( 1 , L_149
L_150 ) ;
return V_10 ;
}
V_10 = F_167 () ;
if ( V_10 == NULL ) {
V_3 = - V_110 ;
goto V_441;
}
V_10 -> V_8 = V_8 ;
if ( V_397 -> V_329 ) {
V_10 -> V_329 = F_102 ( V_397 -> V_329 , V_145 ) ;
if ( ! V_10 -> V_329 ) {
V_3 = - V_110 ;
goto V_441;
}
}
if ( strchr ( V_397 -> V_336 + 3 , '\\' ) == NULL
&& strchr ( V_397 -> V_336 + 3 , '/' ) == NULL ) {
F_22 ( 1 , L_151 ) ;
V_3 = - V_442 ;
goto V_441;
}
V_415 = F_144 () ;
V_3 = F_168 ( V_415 , V_8 , V_397 -> V_336 , V_10 , V_397 -> V_432 ) ;
F_157 ( V_415 ) ;
F_4 ( 1 , L_152 , V_3 ) ;
if ( V_3 )
goto V_441;
if ( V_397 -> V_249 ) {
V_10 -> V_443 &= ~ V_444 ;
F_4 ( 1 , L_153 , V_10 -> V_443 ) ;
}
V_10 -> V_292 = V_397 -> V_292 ;
V_10 -> V_237 = V_397 -> V_237 ;
V_10 -> V_255 = V_397 -> V_255 ;
V_10 -> V_289 = V_397 -> V_289 ;
F_2 ( & V_20 ) ;
F_139 ( & V_10 -> V_24 , & V_8 -> V_24 ) ;
F_3 ( & V_20 ) ;
F_169 ( V_10 ) ;
return V_10 ;
V_441:
F_165 ( V_10 ) ;
return F_86 ( V_3 ) ;
}
void
F_170 ( struct V_445 * V_446 )
{
if ( ! V_446 || F_129 ( V_446 ) )
return;
if ( ! F_171 ( & V_446 -> V_447 ) ||
F_172 ( V_448 , & V_446 -> V_449 ) ) {
V_446 -> V_450 = V_36 ;
return;
}
if ( ! F_129 ( F_173 ( V_446 ) ) )
F_162 ( F_173 ( V_446 ) ) ;
F_10 ( V_446 ) ;
return;
}
static inline struct V_445 *
F_174 ( struct V_451 * V_452 )
{
return V_452 -> V_453 ;
}
static int
F_175 ( struct V_454 * V_455 , struct V_456 * V_457 )
{
struct V_451 * V_458 = F_176 ( V_455 ) ;
struct V_451 * V_92 = V_457 -> V_452 ;
if ( ( V_455 -> V_459 & V_460 ) != ( V_457 -> V_28 & V_460 ) )
return 0 ;
if ( ( V_458 -> V_461 & V_462 ) !=
( V_92 -> V_461 & V_462 ) )
return 0 ;
if ( V_92 -> V_320 && V_92 -> V_320 < V_458 -> V_320 )
return 0 ;
if ( V_92 -> V_318 && V_92 -> V_318 < V_458 -> V_318 )
return 0 ;
if ( V_458 -> V_463 != V_92 -> V_463 || V_458 -> V_464 != V_92 -> V_464 )
return 0 ;
if ( V_458 -> V_465 != V_92 -> V_465 ||
V_458 -> V_466 != V_92 -> V_466 )
return 0 ;
if ( strcmp ( V_458 -> V_432 -> V_467 , V_92 -> V_432 -> V_467 ) )
return 0 ;
if ( V_458 -> V_218 != V_92 -> V_218 )
return 0 ;
return 1 ;
}
int
F_177 ( struct V_454 * V_455 , void * V_189 )
{
struct V_456 * V_457 = (struct V_456 * ) V_189 ;
struct V_164 * V_397 ;
struct V_451 * V_452 ;
struct V_1 * V_468 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_445 * V_446 ;
struct V_399 V_368 ;
int V_3 = 0 ;
memset ( & V_368 , 0 , sizeof( struct V_399 ) ) ;
F_2 ( & V_20 ) ;
V_452 = F_176 ( V_455 ) ;
V_446 = F_178 ( F_174 ( V_452 ) ) ;
if ( F_129 ( V_446 ) ) {
F_3 ( & V_20 ) ;
return V_3 ;
}
V_10 = F_173 ( V_446 ) ;
V_8 = V_10 -> V_8 ;
V_468 = V_8 -> V_2 ;
V_397 = V_457 -> V_165 ;
if ( ! V_397 -> V_332 || ! V_397 -> V_336 )
goto V_469;
V_3 = F_125 ( (struct V_121 * ) & V_368 ,
V_397 -> V_332 ,
strlen ( V_397 -> V_332 ) ,
V_397 -> V_316 ) ;
if ( ! V_3 )
goto V_469;
if ( ! F_114 ( V_468 , (struct V_121 * ) & V_368 , V_397 ) ||
! F_141 ( V_8 , V_397 ) ||
! F_160 ( V_10 , V_397 -> V_336 ) ) {
V_3 = 0 ;
goto V_469;
}
V_3 = F_175 ( V_455 , V_457 ) ;
V_469:
F_3 ( & V_20 ) ;
F_170 ( V_446 ) ;
return V_3 ;
}
int
F_179 ( int V_415 , struct V_7 * V_470 , const char * V_471 ,
const struct V_472 * V_473 , unsigned int * V_474 ,
struct V_475 * * V_476 , int V_243 )
{
char * V_477 ;
int V_3 = 0 ;
* V_474 = 0 ;
* V_476 = NULL ;
if ( V_470 -> V_23 == 0 ) {
V_477 = F_44 ( 2 +
F_95 ( V_470 -> V_434 ,
V_478 * 2 )
+ 1 + 4 + 2 ,
V_145 ) ;
if ( V_477 == NULL )
return - V_110 ;
V_477 [ 0 ] = '\\' ;
V_477 [ 1 ] = '\\' ;
strcpy ( V_477 + 2 , V_470 -> V_434 ) ;
strcpy ( V_477 + 2 + strlen ( V_470 -> V_434 ) , L_154 ) ;
V_3 = F_168 ( V_415 , V_470 , V_477 , NULL , V_473 ) ;
F_4 ( 1 , L_155 , V_3 , V_470 -> V_23 ) ;
F_10 ( V_477 ) ;
}
if ( V_3 == 0 )
V_3 = F_180 ( V_415 , V_470 , V_471 , V_476 ,
V_474 , V_473 , V_243 ) ;
return V_3 ;
}
static inline void
F_181 ( struct V_479 * V_480 )
{
struct V_480 * V_481 = V_480 -> V_481 ;
F_182 ( F_183 ( V_481 ) ) ;
F_184 ( V_481 , L_156 ,
& V_482 [ 0 ] , L_157 , & V_483 [ 0 ] ) ;
}
static inline void
F_185 ( struct V_479 * V_480 )
{
struct V_480 * V_481 = V_480 -> V_481 ;
F_182 ( F_183 ( V_481 ) ) ;
F_184 ( V_481 , L_158 ,
& V_482 [ 1 ] , L_159 , & V_483 [ 1 ] ) ;
}
static inline void
F_181 ( struct V_479 * V_480 )
{
}
static inline void
F_185 ( struct V_479 * V_480 )
{
}
static void F_186 ( char * V_484 , char * V_485 , unsigned int V_105 )
{
unsigned int V_194 , V_195 ;
for ( V_194 = 0 , V_195 = 0 ; V_194 < ( V_105 ) ; V_194 ++ ) {
V_484 [ V_195 ] = 'A' + ( 0x0F & ( V_485 [ V_194 ] >> 4 ) ) ;
V_484 [ V_195 + 1 ] = 'A' + ( 0x0F & V_485 [ V_194 ] ) ;
V_195 += 2 ;
}
}
static int
F_187 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_340 . V_409 != V_356 ) {
struct V_479 * V_479 = V_2 -> V_26 ;
V_3 = V_479 -> V_486 -> V_487 ( V_479 ,
(struct V_121 * ) & V_2 -> V_340 ,
sizeof( V_2 -> V_340 ) ) ;
if ( V_3 < 0 ) {
struct V_358 * V_359 ;
struct V_364 * V_365 ;
V_359 = (struct V_358 * ) & V_2 -> V_340 ;
V_365 = (struct V_364 * ) & V_2 -> V_340 ;
if ( V_365 -> V_488 == V_363 )
F_22 ( 1 , L_160
L_161 ,
& V_365 -> V_367 , V_3 ) ;
else
F_22 ( 1 , L_160
L_162 ,
& V_359 -> V_361 . V_362 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_188 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_489 * V_490 ;
struct V_45 * V_491 ;
V_490 = F_103 ( sizeof( struct V_489 ) ,
V_145 ) ;
if ( V_490 ) {
V_490 -> V_492 . V_493 . V_494 = 32 ;
if ( V_2 -> V_407 &&
V_2 -> V_407 [ 0 ] != 0 )
F_186 ( V_490 -> V_492 .
V_493 . V_495 ,
V_2 -> V_407 ,
V_349 ) ;
else
F_186 ( V_490 -> V_492 .
V_493 . V_495 ,
V_496 ,
V_349 ) ;
V_490 -> V_492 . V_493 . V_497 = 32 ;
if ( V_2 -> V_406 &&
V_2 -> V_406 [ 0 ] != 0 )
F_186 ( V_490 -> V_492 .
V_493 . V_498 ,
V_2 -> V_406 ,
V_349 ) ;
else
F_186 ( V_490 -> V_492 .
V_493 . V_498 ,
L_163 ,
V_349 ) ;
V_490 -> V_492 . V_493 . V_499 = 0 ;
V_490 -> V_492 . V_493 . V_500 = 0 ;
V_491 = (struct V_45 * ) V_490 ;
V_491 -> V_75 = F_28 ( 0x81000044 ) ;
V_3 = F_189 ( V_2 , V_491 , 0x44 ) ;
F_10 ( V_490 ) ;
F_47 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_4 V_369 ;
int V_501 , V_502 ;
struct V_479 * V_479 = V_2 -> V_26 ;
struct V_121 * V_503 ;
V_503 = (struct V_121 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_409 == V_363 ) {
V_369 = ( (struct V_364 * ) V_503 ) -> V_371 ;
V_501 = sizeof( struct V_364 ) ;
V_502 = V_363 ;
} else {
V_369 = ( (struct V_358 * ) V_503 ) -> V_370 ;
V_501 = sizeof( struct V_358 ) ;
V_502 = V_357 ;
}
if ( V_479 == NULL ) {
V_3 = F_190 ( F_116 ( V_2 ) , V_502 , V_504 ,
V_505 , & V_479 , 1 ) ;
if ( V_3 < 0 ) {
F_22 ( 1 , L_164 , V_3 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
F_4 ( 1 , L_165 ) ;
V_2 -> V_26 = V_479 ;
V_479 -> V_481 -> V_506 = V_102 ;
if ( V_502 == V_363 )
F_185 ( V_479 ) ;
else
F_181 ( V_479 ) ;
}
V_3 = F_187 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_479 -> V_481 -> V_507 = 7 * V_82 ;
V_479 -> V_481 -> V_508 = 5 * V_82 ;
if ( V_2 -> V_235 ) {
if ( V_479 -> V_481 -> V_509 < ( 200 * 1024 ) )
V_479 -> V_481 -> V_509 = 200 * 1024 ;
if ( V_479 -> V_481 -> V_510 < ( 140 * 1024 ) )
V_479 -> V_481 -> V_510 = 140 * 1024 ;
}
if ( V_2 -> V_404 ) {
int V_511 = 1 ;
V_3 = F_191 ( V_479 , V_512 , V_513 ,
( char * ) & V_511 , sizeof( V_511 ) ) ;
if ( V_3 )
F_4 ( 1 , L_166 , V_3 ) ;
}
F_4 ( 1 , L_167 ,
V_479 -> V_481 -> V_509 ,
V_479 -> V_481 -> V_510 , V_479 -> V_481 -> V_507 ) ;
V_3 = V_479 -> V_486 -> V_514 ( V_479 , V_503 , V_501 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( 1 , L_168 , V_3 ) ;
F_9 ( V_479 ) ;
V_2 -> V_26 = NULL ;
return V_3 ;
}
if ( V_369 == F_111 ( V_372 ) )
V_3 = F_188 ( V_2 ) ;
return V_3 ;
}
static int
F_135 ( struct V_1 * V_2 )
{
T_4 * V_369 ;
struct V_364 * V_375 = (struct V_364 * ) & V_2 -> V_122 ;
struct V_358 * V_368 = (struct V_358 * ) & V_2 -> V_122 ;
if ( V_2 -> V_122 . V_409 == V_363 )
V_369 = & V_375 -> V_371 ;
else
V_369 = & V_368 -> V_370 ;
if ( * V_369 == 0 ) {
int V_3 ;
* V_369 = F_111 ( V_123 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_369 = F_111 ( V_372 ) ;
}
return F_17 ( V_2 ) ;
}
void F_192 ( int V_415 , struct V_9 * V_10 ,
struct V_451 * V_452 , struct V_164 * V_515 )
{
T_6 V_516 = F_193 ( V_10 -> V_517 . V_518 ) ;
if ( V_515 && V_515 -> V_253 ) {
V_10 -> V_517 . V_518 = 0 ;
V_10 -> V_519 = 0 ;
F_4 ( 1 , L_169 ) ;
return;
} else if ( V_515 )
V_10 -> V_519 = 1 ;
if ( V_10 -> V_519 == 0 ) {
F_4 ( 1 , L_170 ) ;
return;
}
if ( ! F_194 ( V_415 , V_10 ) ) {
T_6 V_520 = F_193 ( V_10 -> V_517 . V_518 ) ;
F_4 ( 1 , L_171 , V_520 ) ;
if ( V_515 == NULL ) {
if ( ( V_516 & V_521 ) == 0 )
V_520 &= ~ V_521 ;
if ( ( V_516 & V_522 ) == 0 ) {
if ( V_520 & V_522 )
F_22 ( 1 , L_172 ) ;
V_520 &= ~ V_522 ;
} else if ( ( V_520 & V_522 ) == 0 ) {
F_22 ( 1 , L_173 ) ;
F_22 ( 1 , L_174 ) ;
}
}
if ( V_520 & V_523 )
F_22 ( 1 , L_175 ) ;
V_520 &= V_524 ;
if ( V_515 && V_515 -> V_286 )
V_520 &= ~ V_521 ;
else if ( V_521 & V_520 ) {
F_4 ( 1 , L_176 ) ;
if ( V_452 )
V_452 -> V_461 |=
V_525 ;
}
if ( V_515 && V_515 -> V_216 == 0 )
V_520 &= ~ V_522 ;
else if ( V_520 & V_522 ) {
F_4 ( 1 , L_177 ) ;
if ( V_452 )
V_452 -> V_461 |=
V_526 ;
}
F_4 ( 1 , L_178 , ( int ) V_520 ) ;
#ifdef F_75
if ( V_520 & V_527 )
F_4 ( 1 , L_179 ) ;
if ( V_520 & V_528 )
F_4 ( 1 , L_180 ) ;
if ( V_520 & V_522 )
F_4 ( 1 , L_181 ) ;
if ( V_520 & V_529 )
F_4 ( 1 , L_182 ) ;
if ( V_520 & V_521 )
F_4 ( 1 , L_183 ) ;
if ( V_520 & V_530 )
F_4 ( 1 , L_184 ) ;
if ( V_520 & V_531 )
F_4 ( 1 , L_185 ) ;
if ( V_520 & V_532 )
F_4 ( 1 , L_186 ) ;
if ( V_520 & V_523 )
F_4 ( 1 , L_187 ) ;
#endif
if ( F_195 ( V_415 , V_10 , V_520 ) ) {
if ( V_515 == NULL ) {
F_4 ( 1 , L_188 ) ;
} else
F_22 ( 1 , L_189
L_190
L_191
L_192
L_193
L_194 ) ;
}
}
}
void F_196 ( struct V_164 * V_533 ,
struct V_451 * V_452 )
{
F_134 ( & V_452 -> V_534 , V_535 ) ;
F_133 ( & V_452 -> V_536 ) ;
V_452 -> V_537 = V_538 ;
V_452 -> V_318 = V_533 -> V_318 ;
V_452 -> V_320 = V_533 -> V_320 ;
V_452 -> V_463 = V_533 -> V_209 ;
V_452 -> V_464 = V_533 -> V_210 ;
V_452 -> V_465 = V_533 -> V_212 ;
V_452 -> V_466 = V_533 -> V_211 ;
F_4 ( 1 , L_195 ,
V_452 -> V_465 , V_452 -> V_466 ) ;
V_452 -> V_218 = V_533 -> V_218 ;
V_452 -> V_432 = V_533 -> V_432 ;
if ( V_533 -> V_240 )
V_452 -> V_461 |= V_539 ;
if ( V_533 -> V_265 )
V_452 -> V_461 |= V_540 ;
if ( V_533 -> V_217 )
V_452 -> V_461 |= V_541 ;
if ( V_533 -> V_243 )
V_452 -> V_461 |= V_542 ;
if ( V_533 -> V_228 )
V_452 -> V_461 |= V_543 ;
if ( V_533 -> V_246 )
V_452 -> V_461 |= V_544 ;
if ( V_533 -> V_257 )
V_452 -> V_461 |= V_545 ;
if ( V_533 -> V_276 )
V_452 -> V_461 |= V_546 ;
if ( V_533 -> V_263 )
V_452 -> V_461 |= V_547 ;
if ( V_533 -> V_281 )
V_452 -> V_461 |= V_548 ;
if ( V_533 -> V_283 )
V_452 -> V_461 |= V_549 ;
if ( V_533 -> V_222 ) {
V_452 -> V_461 |= V_550 ;
V_452 -> V_551 = V_533 -> V_307 ;
}
if ( V_533 -> V_223 ) {
V_452 -> V_461 |= V_552 ;
V_452 -> V_553 = V_533 -> V_309 ;
}
if ( V_533 -> V_197 )
V_452 -> V_461 |= V_554 ;
if ( V_533 -> V_198 )
V_452 -> V_461 |= V_555 ;
if ( V_533 -> V_268 )
V_452 -> V_461 |= V_556 ;
if ( V_533 -> V_300 )
V_452 -> V_461 |= V_557 ;
if ( V_533 -> V_304 )
V_452 -> V_461 |= ( V_558 |
V_539 ) ;
if ( V_533 -> V_296 )
V_452 -> V_461 |= V_559 ;
if ( V_533 -> V_294 ) {
F_4 ( 1 , L_196 ) ;
V_452 -> V_461 |= V_560 ;
}
if ( V_533 -> V_302 ) {
if ( V_533 -> V_246 ) {
F_22 ( 1 , L_197
L_198 ) ;
} else {
V_452 -> V_461 |= V_561 ;
}
}
if ( ( V_533 -> V_283 ) && ( V_533 -> V_268 ) )
F_22 ( 1 , L_199
L_200 ) ;
}
static unsigned int
F_197 ( struct V_9 * V_10 , struct V_164 * V_533 )
{
T_6 V_562 = F_193 ( V_10 -> V_517 . V_518 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_320 ;
if ( V_533 -> V_320 )
V_320 = V_533 -> V_320 ;
else if ( V_10 -> V_519 && ( V_562 & V_531 ) )
V_320 = V_563 ;
else
V_320 = V_564 ;
if ( ! V_10 -> V_519 || ! ( V_562 & V_531 ) )
V_320 = F_68 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_565 & V_566 ) ||
( ! ( V_2 -> V_565 & V_567 ) &&
( V_2 -> V_389 & ( V_391 | V_390 ) ) ) )
V_320 = F_68 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_320 = F_68 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_320 ;
}
static unsigned int
F_198 ( struct V_9 * V_10 , struct V_164 * V_533 )
{
T_6 V_562 = F_193 ( V_10 -> V_517 . V_518 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_318 , V_568 ;
if ( V_10 -> V_519 && ( V_562 & V_530 ) )
V_568 = V_563 ;
else if ( V_2 -> V_565 & V_569 )
V_568 = V_570 ;
else if ( V_2 -> V_18 >= V_571 )
V_568 = V_59 ;
else
V_568 = V_2 -> V_18 - sizeof( V_572 ) ;
V_318 = V_533 -> V_318 ? V_533 -> V_318 : V_568 ;
if ( ! ( V_2 -> V_565 & V_569 ) )
V_318 = F_68 (unsigned int, CIFSMaxBufSize, rsize) ;
V_318 = F_68 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_318 ;
}
static int
F_199 ( int V_415 , struct V_9 * V_10 ,
struct V_451 * V_452 , const char * V_573 )
{
int V_3 ;
T_7 * V_574 ;
V_574 = F_44 ( sizeof( T_7 ) , V_145 ) ;
if ( V_574 == NULL )
return - V_110 ;
V_3 = F_200 ( V_415 , V_10 , V_573 , V_574 ,
0 , V_452 -> V_432 ,
V_452 -> V_461 &
V_542 ) ;
if ( V_3 == - V_575 || V_3 == - V_55 )
V_3 = F_201 ( V_415 , V_10 , V_573 , V_574 ,
V_452 -> V_432 , V_452 -> V_461 &
V_542 ) ;
F_10 ( V_574 ) ;
return V_3 ;
}
static void
F_202 ( struct V_164 * V_397 )
{
F_10 ( V_397 -> V_324 ) ;
F_203 ( V_397 -> V_329 ) ;
if ( V_397 -> V_332 != V_397 -> V_336 + 2 )
F_10 ( V_397 -> V_332 ) ;
F_10 ( V_397 -> V_336 ) ;
F_10 ( V_397 -> V_338 ) ;
F_10 ( V_397 -> V_344 ) ;
F_10 ( V_397 -> V_342 ) ;
}
void
F_204 ( struct V_164 * V_397 )
{
if ( ! V_397 )
return;
F_202 ( V_397 ) ;
F_10 ( V_397 ) ;
}
static char *
F_205 ( const struct V_164 * V_165 ,
const struct V_451 * V_452 )
{
char * V_573 , * V_576 ;
unsigned int V_577 = V_165 -> V_342 ? strlen ( V_165 -> V_342 ) : 0 ;
unsigned int V_578 = F_95 ( V_165 -> V_336 , V_439 + 1 ) ;
V_573 = F_44 ( V_578 + V_577 + 1 , V_145 ) ;
if ( V_573 == NULL )
return F_86 ( - V_110 ) ;
strncpy ( V_573 , V_165 -> V_336 , V_578 ) ;
V_576 = V_573 + V_578 ;
if ( V_577 ) {
strncpy ( V_576 , V_165 -> V_342 , V_577 ) ;
V_576 += V_577 ;
}
* V_576 = '\0' ;
F_206 ( V_573 , F_207 ( V_452 ) ) ;
F_4 ( 1 , L_201 , V_19 , V_573 ) ;
return V_573 ;
}
static int
F_208 ( int V_415 , struct V_7 * V_470 ,
struct V_164 * V_397 , struct V_451 * V_452 ,
int V_579 )
{
int V_3 ;
unsigned int V_580 = 0 ;
struct V_475 * V_581 = NULL ;
char * V_573 = NULL , * V_582 = NULL , * V_583 = NULL ;
V_573 = F_205 ( V_397 , V_452 ) ;
if ( F_129 ( V_573 ) )
return F_130 ( V_573 ) ;
V_582 = V_579 ? V_573 + 1 : V_397 -> V_336 + 1 ;
V_3 = F_179 ( V_415 , V_470 , V_582 , V_452 -> V_432 ,
& V_580 , & V_581 ,
V_452 -> V_461 & V_542 ) ;
if ( ! V_3 && V_580 > 0 ) {
char * V_584 = NULL ;
V_583 = F_209 ( V_452 -> V_187 ,
V_573 + 1 , V_581 ,
& V_584 ) ;
F_210 ( V_581 , V_580 ) ;
if ( F_129 ( V_583 ) ) {
V_3 = F_130 ( V_583 ) ;
V_583 = NULL ;
} else {
F_202 ( V_397 ) ;
memset ( V_397 , '\0' , sizeof( * V_397 ) ) ;
V_3 = F_211 ( V_397 , V_583 ,
V_584 ) ;
}
F_10 ( V_584 ) ;
F_10 ( V_452 -> V_187 ) ;
V_452 -> V_187 = V_583 ;
}
F_10 ( V_573 ) ;
return V_3 ;
}
static int
F_211 ( struct V_164 * V_397 , char * V_585 ,
const char * V_188 )
{
int V_3 = 0 ;
if ( F_93 ( V_585 , V_188 , V_397 ) )
return - V_55 ;
if ( V_397 -> V_186 ) {
F_4 ( 1 , L_202 ) ;
F_10 ( V_397 -> V_324 ) ;
V_397 -> V_324 = NULL ;
} else if ( V_397 -> V_324 ) {
F_4 ( 1 , L_203 , V_397 -> V_324 ) ;
} else {
F_212 ( L_204 ) ;
return - V_55 ;
}
if ( V_397 -> V_344 == NULL ) {
V_397 -> V_432 = F_213 () ;
} else {
V_397 -> V_432 = F_214 ( V_397 -> V_344 ) ;
if ( V_397 -> V_432 == NULL ) {
F_22 ( 1 , L_205 ,
V_397 -> V_344 ) ;
return - V_586 ;
}
}
return V_3 ;
}
struct V_164 *
F_215 ( char * V_585 , const char * V_188 )
{
int V_3 ;
struct V_164 * V_397 ;
V_397 = F_103 ( sizeof( struct V_164 ) , V_145 ) ;
if ( ! V_397 )
return F_86 ( - V_110 ) ;
V_3 = F_211 ( V_397 , V_585 , V_188 ) ;
if ( V_3 ) {
F_204 ( V_397 ) ;
V_397 = F_86 ( V_3 ) ;
}
return V_397 ;
}
int
F_216 ( struct V_451 * V_452 , struct V_164 * V_397 )
{
int V_3 ;
int V_415 ;
struct V_7 * V_470 ;
struct V_9 * V_10 ;
struct V_1 * V_587 ;
char * V_573 ;
struct V_445 * V_446 ;
#ifdef F_217
int V_588 = 0 ;
#endif
V_3 = F_218 ( & V_452 -> V_589 , L_101 , V_590 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_217
V_591:
if ( V_588 ) {
if ( V_10 )
F_162 ( V_10 ) ;
else if ( V_470 )
F_143 ( V_470 ) ;
F_157 ( V_415 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_470 = NULL ;
V_587 = NULL ;
V_573 = NULL ;
V_446 = NULL ;
V_415 = F_144 () ;
V_587 = F_124 ( V_397 ) ;
if ( F_129 ( V_587 ) ) {
V_3 = F_130 ( V_587 ) ;
F_219 ( & V_452 -> V_589 ) ;
goto V_469;
}
V_470 = F_155 ( V_587 , V_397 ) ;
if ( F_129 ( V_470 ) ) {
V_3 = F_130 ( V_470 ) ;
V_470 = NULL ;
goto V_592;
}
V_10 = F_166 ( V_470 , V_397 ) ;
if ( F_129 ( V_10 ) ) {
V_3 = F_130 ( V_10 ) ;
V_10 = NULL ;
goto V_593;
}
if ( V_10 -> V_8 -> V_565 & V_567 ) {
F_192 ( V_415 , V_10 , V_452 , V_397 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_193 ( V_10 -> V_517 . V_518 ) &
V_523 ) ) {
V_3 = - V_594 ;
goto V_592;
}
} else
V_10 -> V_519 = 0 ;
if ( ! V_10 -> V_595 ) {
F_220 ( V_415 , V_10 ) ;
F_221 ( V_415 , V_10 ) ;
}
V_452 -> V_320 = F_197 ( V_10 , V_397 ) ;
V_452 -> V_318 = F_198 ( V_10 , V_397 ) ;
V_452 -> V_589 . V_596 = V_452 -> V_318 / V_571 ;
V_593:
#ifdef F_217
if ( V_588 == 0 ) {
int V_597 = F_208 ( V_415 , V_470 , V_397 ,
V_452 , false ) ;
if ( ! V_597 ) {
V_588 ++ ;
goto V_591;
}
}
#endif
if ( ! V_3 && V_10 ) {
V_573 = F_222 ( V_397 , V_452 , V_10 ) ;
if ( V_573 == NULL ) {
V_3 = - V_110 ;
goto V_592;
}
V_3 = F_199 ( V_415 , V_10 , V_452 , V_573 ) ;
if ( V_3 != 0 && V_3 != - V_598 ) {
F_10 ( V_573 ) ;
goto V_592;
}
F_10 ( V_573 ) ;
}
if ( V_3 == - V_598 ) {
#ifdef F_217
if ( V_588 > V_599 ) {
V_3 = - V_600 ;
goto V_592;
}
V_3 = F_208 ( V_415 , V_470 , V_397 , V_452 ,
true ) ;
if ( ! V_3 ) {
V_588 ++ ;
goto V_591;
}
goto V_592;
#else
V_3 = - V_575 ;
#endif
}
if ( V_3 )
goto V_592;
V_446 = F_103 ( sizeof *V_446 , V_145 ) ;
if ( V_446 == NULL ) {
V_3 = - V_110 ;
goto V_592;
}
V_446 -> V_601 = V_470 -> V_209 ;
V_446 -> V_602 = V_10 ;
V_446 -> V_450 = V_36 ;
F_223 ( V_603 , & V_446 -> V_449 ) ;
F_223 ( V_448 , & V_446 -> V_449 ) ;
V_452 -> V_453 = V_446 ;
F_2 ( & V_452 -> V_536 ) ;
F_224 ( & V_452 -> V_537 , V_446 ) ;
F_3 ( & V_452 -> V_536 ) ;
F_33 ( V_85 , & V_452 -> V_534 ,
V_604 ) ;
V_592:
if ( V_3 ) {
if ( V_10 )
F_162 ( V_10 ) ;
else if ( V_470 )
F_143 ( V_470 ) ;
else
F_118 ( V_587 ) ;
F_219 ( & V_452 -> V_589 ) ;
}
V_469:
F_157 ( V_415 ) ;
return V_3 ;
}
int
F_168 ( unsigned int V_415 , struct V_7 * V_8 ,
const char * V_605 , struct V_9 * V_10 ,
const struct V_472 * V_473 )
{
struct V_45 * V_606 ;
struct V_45 * V_607 ;
T_8 * V_46 ;
T_9 * V_608 ;
unsigned char * V_609 ;
int V_3 = 0 ;
int V_105 ;
T_1 V_610 , V_611 ;
if ( V_8 == NULL )
return - V_612 ;
V_606 = F_35 () ;
if ( V_606 == NULL )
return - V_110 ;
V_607 = V_606 ;
F_225 ( V_606 , V_613 ,
NULL , 4 ) ;
V_606 -> V_126 = F_226 ( V_8 -> V_2 ) ;
V_606 -> V_614 = V_8 -> V_615 ;
V_46 = ( T_8 * ) V_606 ;
V_608 = ( T_9 * ) V_607 ;
V_46 -> V_616 = 0xFF ;
V_46 -> V_443 = F_227 ( V_617 ) ;
V_609 = & V_46 -> V_618 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_389 & V_619 ) ) {
V_46 -> V_620 = F_227 ( 1 ) ;
* V_609 = 0 ;
V_609 ++ ;
} else {
V_46 -> V_620 = F_227 ( V_621 ) ;
#ifdef F_92
if ( ( V_380 & V_184 ) &&
( V_8 -> V_2 -> V_381 == V_382 ) )
F_228 ( V_10 -> V_329 , V_8 -> V_2 -> V_622 ,
V_8 -> V_2 -> V_389 &
V_623 ? true : false ,
V_609 ) ;
else
#endif
V_3 = F_229 ( V_10 -> V_329 , V_8 -> V_2 -> V_622 ,
V_609 , V_473 ) ;
V_609 += V_621 ;
if ( V_8 -> V_565 & V_624 ) {
* V_609 = 0 ;
V_609 ++ ;
}
}
if ( V_8 -> V_2 -> V_389 &
( V_390 | V_391 ) )
V_606 -> V_625 |= V_626 ;
if ( V_8 -> V_565 & V_627 ) {
V_606 -> V_625 |= V_628 ;
}
if ( V_8 -> V_565 & V_629 ) {
V_606 -> V_625 |= V_630 ;
}
if ( V_8 -> V_565 & V_624 ) {
V_606 -> V_625 |= V_631 ;
V_105 =
F_230 ( ( V_632 * ) V_609 , V_605 ,
6 *
( + 256 ) , V_473 ) ;
V_609 += 2 * V_105 ;
V_609 += 2 ;
} else {
strcpy ( V_609 , V_605 ) ;
V_609 += strlen ( V_605 ) + 1 ;
}
strcpy ( V_609 , L_206 ) ;
V_609 += strlen ( L_206 ) ;
V_609 += 1 ;
V_611 = V_609 - & V_46 -> V_618 [ 0 ] ;
V_46 -> V_71 . V_75 = F_28 ( F_27 (
V_46 -> V_71 . V_75 ) + V_611 ) ;
V_46 -> V_633 = F_227 ( V_611 ) ;
V_3 = F_231 ( V_415 , V_8 , V_606 , V_607 , & V_105 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_634 ;
V_10 -> V_437 = V_89 ;
V_10 -> V_22 = false ;
V_10 -> V_635 = V_607 -> V_636 ;
V_609 = F_232 ( V_607 ) ;
V_610 = F_25 ( V_607 ) ;
V_105 = F_95 ( V_609 , V_610 - 2 ) ;
if ( V_606 -> V_625 & V_631 )
V_634 = true ;
else
V_634 = false ;
if ( V_105 == 3 ) {
if ( ( V_609 [ 0 ] == 'I' ) && ( V_609 [ 1 ] == 'P' ) &&
( V_609 [ 2 ] == 'C' ) ) {
F_4 ( 1 , L_207 ) ;
V_10 -> V_595 = 1 ;
}
} else if ( V_105 == 2 ) {
if ( ( V_609 [ 0 ] == 'A' ) && ( V_609 [ 1 ] == ':' ) ) {
F_4 ( 1 , L_208 ) ;
}
}
V_609 += V_105 + 1 ;
V_610 -= ( V_105 + 1 ) ;
strncpy ( V_10 -> V_438 , V_605 , V_439 ) ;
F_10 ( V_10 -> V_637 ) ;
V_10 -> V_637 = F_233 ( V_609 ,
V_610 , V_634 ,
V_473 ) ;
F_4 ( 1 , L_209 , V_10 -> V_637 ) ;
if ( ( V_607 -> V_54 == 3 ) ||
( V_607 -> V_54 == 7 ) )
V_10 -> V_443 = F_53 ( V_608 -> V_638 ) ;
else
V_10 -> V_443 = 0 ;
F_4 ( 1 , L_210 , V_10 -> V_443 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_23 = V_607 -> V_636 ;
}
F_78 ( V_606 ) ;
return V_3 ;
}
void
F_234 ( struct V_451 * V_452 )
{
struct V_639 * V_640 = & V_452 -> V_537 ;
struct V_641 * V_642 ;
struct V_445 * V_446 ;
F_120 ( & V_452 -> V_534 ) ;
F_2 ( & V_452 -> V_536 ) ;
while ( ( V_642 = F_235 ( V_640 ) ) ) {
V_446 = F_236 ( V_642 , struct V_445 , V_643 ) ;
F_178 ( V_446 ) ;
F_237 ( V_448 , & V_446 -> V_449 ) ;
F_238 ( V_642 , V_640 ) ;
F_3 ( & V_452 -> V_536 ) ;
F_170 ( V_446 ) ;
F_2 ( & V_452 -> V_536 ) ;
}
F_3 ( & V_452 -> V_536 ) ;
F_219 ( & V_452 -> V_589 ) ;
F_10 ( V_452 -> V_187 ) ;
F_239 ( V_452 -> V_432 ) ;
F_10 ( V_452 ) ;
}
int F_156 ( unsigned int V_415 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_18 != 0 )
return 0 ;
F_240 ( V_2 , 1 ) ;
V_3 = F_241 ( V_415 , V_8 ) ;
if ( V_3 == - V_113 ) {
F_240 ( V_2 , 1 ) ;
V_3 = F_241 ( V_415 , V_8 ) ;
if ( V_3 == - V_113 )
V_3 = - V_644 ;
}
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_43 )
V_2 -> V_15 = V_89 ;
else
V_3 = - V_644 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int F_158 ( unsigned int V_415 , struct V_7 * V_8 ,
struct V_472 * V_645 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_28 = 0 ;
V_8 -> V_565 = V_2 -> V_565 ;
if ( V_646 == 0 )
V_8 -> V_565 &= ( ~ V_567 ) ;
F_4 ( 1 , L_211 ,
V_2 -> V_389 , V_2 -> V_565 , V_2 -> V_647 ) ;
V_3 = F_242 ( V_415 , V_8 , V_645 ) ;
if ( V_3 ) {
F_22 ( 1 , L_212 , V_3 ) ;
} else {
F_7 ( & V_8 -> V_2 -> V_25 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_32 . V_33 = V_8 -> V_648 . V_33 ;
V_2 -> V_32 . V_34 = V_8 -> V_648 . V_34 ;
V_2 -> V_30 = 0x2 ;
V_2 -> V_31 = true ;
V_8 -> V_648 . V_33 = NULL ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( 1 , L_213 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_416 = V_89 ;
V_8 -> V_22 = false ;
F_3 ( & V_14 ) ;
}
F_10 ( V_8 -> V_648 . V_33 ) ;
V_8 -> V_648 . V_33 = NULL ;
V_8 -> V_648 . V_34 = 0 ;
F_10 ( V_8 -> V_649 ) ;
V_8 -> V_649 = NULL ;
return V_3 ;
}
static int
F_243 ( struct V_164 * V_165 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_381 ) {
case V_386 :
V_165 -> V_169 = V_650 ;
return 0 ;
case V_384 :
V_165 -> V_169 = V_651 ;
break;
case V_385 :
V_165 -> V_169 = V_652 ;
break;
case V_387 :
V_165 -> V_169 = V_653 ;
break;
case V_382 :
V_165 -> V_169 = V_654 ;
break;
}
return F_148 ( V_165 , V_8 ) ;
}
static struct V_9 *
F_244 ( struct V_451 * V_452 , T_10 V_655 )
{
int V_3 ;
struct V_9 * V_656 = F_245 ( V_452 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_164 * V_515 ;
V_515 = F_103 ( sizeof( * V_515 ) , V_145 ) ;
if ( V_515 == NULL )
return F_86 ( - V_110 ) ;
V_515 -> V_432 = V_452 -> V_432 ;
V_515 -> V_209 = V_655 ;
V_515 -> V_208 = V_655 ;
V_515 -> V_336 = V_656 -> V_438 ;
V_515 -> V_237 = V_656 -> V_237 ;
V_515 -> V_255 = V_656 -> V_255 ;
V_515 -> V_289 = V_656 -> V_289 ;
V_515 -> V_253 = ! V_656 -> V_519 ;
V_3 = F_243 ( V_515 , V_656 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_86 ( V_3 ) ;
goto V_469;
}
F_2 ( & V_20 ) ;
++ V_656 -> V_8 -> V_2 -> V_394 ;
F_3 ( & V_20 ) ;
V_8 = F_155 ( V_656 -> V_8 -> V_2 , V_515 ) ;
if ( F_129 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_118 ( V_656 -> V_8 -> V_2 ) ;
goto V_469;
}
V_10 = F_166 ( V_8 , V_515 ) ;
if ( F_129 ( V_10 ) ) {
F_143 ( V_8 ) ;
goto V_469;
}
if ( V_8 -> V_565 & V_567 )
F_192 ( 0 , V_10 , NULL , V_515 ) ;
V_469:
F_10 ( V_515 -> V_324 ) ;
F_10 ( V_515 -> V_329 ) ;
F_10 ( V_515 ) ;
return V_10 ;
}
struct V_9 *
F_245 ( struct V_451 * V_452 )
{
return F_173 ( F_174 ( V_452 ) ) ;
}
static int
F_246 ( void * V_657 )
{
F_83 () ;
return F_82 ( V_151 ) ? - V_115 : 0 ;
}
static struct V_445 *
F_247 ( struct V_639 * V_640 , T_10 V_658 )
{
struct V_641 * V_642 = V_640 -> V_641 ;
struct V_445 * V_446 ;
while ( V_642 ) {
V_446 = F_236 ( V_642 , struct V_445 , V_643 ) ;
if ( V_446 -> V_601 > V_658 )
V_642 = V_642 -> V_659 ;
else if ( V_446 -> V_601 < V_658 )
V_642 = V_642 -> V_660 ;
else
return V_446 ;
}
return NULL ;
}
static void
F_224 ( struct V_639 * V_640 , struct V_445 * V_661 )
{
struct V_641 * * V_92 = & ( V_640 -> V_641 ) , * V_662 = NULL ;
struct V_445 * V_446 ;
while ( * V_92 ) {
V_446 = F_236 ( * V_92 , struct V_445 , V_643 ) ;
V_662 = * V_92 ;
if ( V_446 -> V_601 > V_661 -> V_601 )
V_92 = & ( ( * V_92 ) -> V_659 ) ;
else
V_92 = & ( ( * V_92 ) -> V_660 ) ;
}
F_248 ( & V_661 -> V_643 , V_662 , V_92 ) ;
F_249 ( & V_661 -> V_643 , V_640 ) ;
}
struct V_445 *
F_250 ( struct V_451 * V_452 )
{
int V_663 ;
T_10 V_655 = F_251 () ;
struct V_445 * V_446 , * V_664 ;
if ( ! ( V_452 -> V_461 & V_558 ) )
return F_178 ( F_174 ( V_452 ) ) ;
F_2 ( & V_452 -> V_536 ) ;
V_446 = F_247 ( & V_452 -> V_537 , V_655 ) ;
if ( V_446 )
F_178 ( V_446 ) ;
F_3 ( & V_452 -> V_536 ) ;
if ( V_446 == NULL ) {
V_664 = F_103 ( sizeof( * V_446 ) , V_145 ) ;
if ( V_664 == NULL )
return F_86 ( - V_110 ) ;
V_664 -> V_601 = V_655 ;
V_664 -> V_602 = F_86 ( - V_594 ) ;
F_223 ( V_665 , & V_664 -> V_449 ) ;
F_223 ( V_448 , & V_664 -> V_449 ) ;
F_178 ( V_664 ) ;
F_2 ( & V_452 -> V_536 ) ;
V_446 = F_247 ( & V_452 -> V_537 , V_655 ) ;
if ( V_446 ) {
F_178 ( V_446 ) ;
F_3 ( & V_452 -> V_536 ) ;
F_10 ( V_664 ) ;
goto V_666;
}
V_446 = V_664 ;
F_224 ( & V_452 -> V_537 , V_446 ) ;
F_3 ( & V_452 -> V_536 ) ;
} else {
V_666:
V_663 = F_252 ( & V_446 -> V_449 , V_665 ,
F_246 ,
V_156 ) ;
if ( V_663 ) {
F_170 ( V_446 ) ;
return F_86 ( V_663 ) ;
}
if ( ! F_129 ( V_446 -> V_602 ) )
return V_446 ;
if ( F_31 ( V_36 , V_446 -> V_450 + V_667 ) ) {
F_170 ( V_446 ) ;
return F_86 ( - V_594 ) ;
}
if ( F_253 ( V_665 , & V_446 -> V_449 ) )
goto V_666;
}
V_446 -> V_602 = F_244 ( V_452 , V_655 ) ;
F_237 ( V_665 , & V_446 -> V_449 ) ;
F_254 ( & V_446 -> V_449 , V_665 ) ;
if ( F_129 ( V_446 -> V_602 ) ) {
F_170 ( V_446 ) ;
return F_86 ( - V_594 ) ;
}
return V_446 ;
}
static void
V_535 ( struct V_78 * V_79 )
{
struct V_451 * V_452 = F_30 ( V_79 , struct V_451 ,
V_534 . V_79 ) ;
struct V_639 * V_640 = & V_452 -> V_537 ;
struct V_641 * V_642 = F_235 ( V_640 ) ;
struct V_641 * V_5 ;
struct V_445 * V_446 ;
F_2 ( & V_452 -> V_536 ) ;
V_642 = F_235 ( V_640 ) ;
while ( V_642 != NULL ) {
V_5 = V_642 ;
V_642 = F_255 ( V_5 ) ;
V_446 = F_236 ( V_5 , struct V_445 , V_643 ) ;
if ( F_172 ( V_603 , & V_446 -> V_449 ) ||
F_74 ( & V_446 -> V_447 ) != 0 ||
F_39 ( V_446 -> V_450 + V_604 , V_36 ) )
continue;
F_178 ( V_446 ) ;
F_237 ( V_448 , & V_446 -> V_449 ) ;
F_238 ( V_5 , V_640 ) ;
F_3 ( & V_452 -> V_536 ) ;
F_170 ( V_446 ) ;
F_2 ( & V_452 -> V_536 ) ;
}
F_3 ( & V_452 -> V_536 ) ;
F_33 ( V_85 , & V_452 -> V_534 ,
V_604 ) ;
}
