static int
F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int * V_4 = ( int * ) V_3 -> V_5 ;
struct V_6 * V_7 = & V_6 ;
int V_8 ;
F_2 ( & V_9 ) ;
V_8 = - V_10 ;
if ( V_7 -> V_11 )
goto V_12;
V_8 = 0 ;
if ( ! strncmp ( V_1 , L_1 , 4 ) )
* V_4 = V_13 ;
else if ( ! strncmp ( V_1 , L_2 , 6 ) )
* V_4 = V_14 ;
else if ( ! strncmp ( V_1 , L_3 , 6 ) )
* V_4 = V_15 ;
else if ( ! strncmp ( V_1 , L_4 , 7 ) )
* V_4 = V_16 ;
else
V_8 = - V_17 ;
V_12:
F_3 ( & V_9 ) ;
return V_8 ;
}
static int
F_4 ( char * V_18 , struct V_2 * V_3 )
{
int * V_4 = ( int * ) V_3 -> V_5 ;
switch ( * V_4 )
{
case V_13 :
return F_5 ( V_18 , L_1 , 20 ) ;
case V_14 :
return F_5 ( V_18 , L_2 , 20 ) ;
case V_15 :
return F_5 ( V_18 , L_3 , 20 ) ;
case V_16 :
return F_5 ( V_18 , L_4 , 20 ) ;
default:
return sprintf ( V_18 , L_5 , * V_4 ) ;
}
}
static int
F_6 ( void )
{
unsigned int V_19 ;
if ( V_20 > 1 ) {
return V_16 ;
}
V_19 = V_21 ;
if ( F_7 ( V_19 ) > 2 ) {
return V_15 ;
}
return V_14 ;
}
static int
F_8 ( struct V_6 * V_7 , unsigned int V_22 )
{
V_7 -> V_23 = F_9 ( V_22 , sizeof( unsigned int ) , V_24 ) ;
if ( ! V_7 -> V_23 )
goto V_25;
V_7 -> V_26 = F_9 ( V_22 , sizeof( unsigned int ) , V_24 ) ;
if ( ! V_7 -> V_26 )
goto V_27;
return 0 ;
V_27:
F_10 ( V_7 -> V_23 ) ;
V_25:
return - V_28 ;
}
static int
F_11 ( struct V_6 * V_7 )
{
unsigned int V_22 = V_29 ;
unsigned int V_30 = 0 ;
unsigned int V_31 ;
int V_8 ;
V_8 = F_8 ( V_7 , V_22 ) ;
if ( V_8 )
return V_8 ;
F_12 (cpu) {
F_13 ( V_30 > V_22 ) ;
V_7 -> V_23 [ V_31 ] = V_30 ;
V_7 -> V_26 [ V_30 ] = V_31 ;
V_30 ++ ;
}
return V_30 ;
}
static int
F_14 ( struct V_6 * V_7 )
{
unsigned int V_22 = V_32 ;
unsigned int V_30 = 0 ;
unsigned int V_19 ;
int V_8 ;
V_8 = F_8 ( V_7 , V_22 ) ;
if ( V_8 )
return V_8 ;
F_15 (node) {
F_13 ( V_30 > V_22 ) ;
V_7 -> V_23 [ V_19 ] = V_30 ;
V_7 -> V_26 [ V_30 ] = V_19 ;
V_30 ++ ;
}
return V_30 ;
}
static unsigned int
F_16 ( void )
{
struct V_6 * V_7 = & V_6 ;
int V_33 = - 1 ;
F_2 ( & V_9 ) ;
if ( V_7 -> V_11 ++ ) {
F_3 ( & V_9 ) ;
return V_7 -> V_33 ;
}
if ( V_7 -> V_34 == V_13 )
V_7 -> V_34 = F_6 () ;
switch ( V_7 -> V_34 ) {
case V_15 :
V_33 = F_11 ( V_7 ) ;
break;
case V_16 :
V_33 = F_14 ( V_7 ) ;
break;
}
if ( V_33 < 0 ) {
V_33 = 1 ;
V_7 -> V_34 = V_14 ;
}
V_7 -> V_33 = V_33 ;
F_3 ( & V_9 ) ;
return V_7 -> V_33 ;
}
static void
F_17 ( void )
{
struct V_6 * V_7 = & V_6 ;
F_2 ( & V_9 ) ;
if ( ! -- V_7 -> V_11 ) {
V_7 -> V_34 = V_35 ;
F_10 ( V_7 -> V_23 ) ;
F_10 ( V_7 -> V_26 ) ;
V_7 -> V_33 = 0 ;
}
F_3 ( & V_9 ) ;
}
static int F_18 ( unsigned int V_30 )
{
const struct V_6 * V_7 = & V_6 ;
if ( V_7 -> V_11 ) {
if ( V_7 -> V_34 == V_15 )
return F_19 ( V_7 -> V_26 [ V_30 ] ) ;
if ( V_7 -> V_34 == V_16 )
return V_7 -> V_26 [ V_30 ] ;
}
return V_36 ;
}
static inline void
F_20 ( struct V_37 * V_38 , unsigned int V_30 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_19 = V_7 -> V_26 [ V_30 ] ;
F_13 ( V_7 -> V_11 == 0 ) ;
switch ( V_7 -> V_34 ) {
case V_15 :
{
F_21 ( V_38 , F_22 ( V_19 ) ) ;
break;
}
case V_16 :
{
F_21 ( V_38 , F_23 ( V_19 ) ) ;
break;
}
}
}
struct V_39 *
F_24 ( struct V_40 * V_41 , int V_31 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_30 = 0 ;
if ( F_25 ( V_41 ) ) {
switch ( V_7 -> V_34 ) {
case V_15 :
V_30 = V_7 -> V_23 [ V_31 ] ;
break;
case V_16 :
V_30 = V_7 -> V_23 [ F_19 ( V_31 ) ] ;
break;
}
}
return & V_41 -> V_42 [ V_30 % V_41 -> V_43 ] ;
}
static int F_26 ( struct V_40 * V_41 )
{
int V_8 ;
V_8 = F_27 () ;
if ( V_8 )
return V_8 ;
F_28 ( V_41 ) ;
return 0 ;
}
void F_29 ( struct V_40 * V_41 )
{
F_28 ( V_41 ) ;
F_30 () ;
}
static int F_31 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
unsigned int V_46 ;
for ( V_45 = V_41 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 == 0 )
return 1 ;
}
}
return 0 ;
}
static struct V_40 *
F_32 ( struct V_44 * V_52 , unsigned int V_53 , int V_33 ,
void (* F_33)( struct V_40 * V_41 ) )
{
struct V_40 * V_41 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_46 ;
if ( ! ( V_41 = F_34 ( sizeof( * V_41 ) , V_24 ) ) )
return NULL ;
V_41 -> V_56 = V_52 -> V_57 ;
V_41 -> V_47 = V_52 ;
V_41 -> V_58 = 1 ;
V_41 -> V_59 = V_52 -> V_60 ;
if ( V_53 > V_61 )
V_53 = V_61 ;
V_41 -> V_62 = V_53 ? V_53 : 4096 ;
V_41 -> V_63 = F_35 ( V_41 -> V_62 + V_64 , V_64 ) ;
V_41 -> V_65 = F_33 ;
V_55 = 0 ;
while ( V_52 ) {
V_52 -> V_66 = V_52 -> V_49 - 1 ;
for ( V_54 = 0 ; V_54 < V_52 -> V_49 ; V_54 ++ )
if ( V_52 -> V_50 [ V_54 ] ) {
V_52 -> V_67 = V_54 ;
if ( V_52 -> V_66 > V_54 )
V_52 -> V_66 = V_54 ;
if ( V_52 -> V_50 [ V_54 ] -> V_68 > V_55 )
V_55 = V_52 -> V_50 [ V_54 ] -> V_68 ;
}
V_52 = V_52 -> V_48 ;
}
V_41 -> V_69 = V_55 ;
F_36 ( & V_41 -> V_70 ) ;
F_36 ( & V_41 -> V_71 ) ;
F_37 ( & V_41 -> V_72 ) ;
F_38 ( & V_41 -> V_73 ) ;
V_41 -> V_43 = V_33 ;
V_41 -> V_42 =
F_9 ( V_41 -> V_43 , sizeof( struct V_39 ) ,
V_24 ) ;
if ( ! V_41 -> V_42 ) {
F_10 ( V_41 ) ;
return NULL ;
}
for ( V_46 = 0 ; V_46 < V_41 -> V_43 ; V_46 ++ ) {
struct V_39 * V_74 = & V_41 -> V_42 [ V_46 ] ;
F_39 ( L_6 ,
V_46 , V_41 -> V_56 ) ;
V_74 -> V_75 = V_46 ;
F_36 ( & V_74 -> V_76 ) ;
F_36 ( & V_74 -> V_77 ) ;
F_36 ( & V_74 -> V_78 ) ;
F_38 ( & V_74 -> V_79 ) ;
}
if ( F_31 ( V_41 ) ) {
if ( F_26 ( V_41 ) < 0 ) {
F_10 ( V_41 -> V_42 ) ;
F_10 ( V_41 ) ;
return NULL ;
}
if ( ! V_41 -> V_65 )
V_41 -> V_65 = F_29 ;
}
return V_41 ;
}
struct V_40 *
F_40 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_33)( struct V_40 * V_41 ) )
{
return F_32 ( V_52 , V_53 , 1 , F_33 ) ;
}
struct V_40 *
F_41 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_33)( struct V_40 * V_41 ) ,
T_1 V_80 , struct V_81 * V_82 )
{
struct V_40 * V_41 ;
unsigned int V_33 = F_16 () ;
V_41 = F_32 ( V_52 , V_53 , V_33 , F_33 ) ;
if ( V_41 != NULL ) {
V_41 -> V_83 = V_80 ;
V_41 -> V_84 = V_82 ;
}
return V_41 ;
}
void
F_42 ( struct V_40 * V_41 )
{
F_39 ( L_7 ,
V_41 -> V_47 -> V_57 ,
V_41 -> V_58 ) ;
if ( V_41 -> V_58 ) {
if ( -- ( V_41 -> V_58 ) != 0 ) {
F_43 ( V_41 ) ;
return;
}
} else
F_44 ( L_8 , V_41 ) ;
F_45 ( & V_41 -> V_72 ) ;
F_46 ( & V_41 -> V_70 ) ;
if ( V_41 -> V_65 )
V_41 -> V_65 ( V_41 ) ;
F_46 ( & V_41 -> V_71 ) ;
F_13 ( ! F_47 ( & V_41 -> V_71 ) ) ;
F_13 ( ! F_47 ( & V_41 -> V_70 ) ) ;
F_48 ( V_41 ) ;
if ( F_25 ( V_41 ) )
F_17 () ;
F_10 ( V_41 -> V_42 ) ;
F_10 ( V_41 ) ;
}
static int
F_49 ( struct V_85 * V_86 , unsigned int V_87 , int V_19 )
{
unsigned int V_88 , V_89 ;
if ( F_50 ( V_86 ) )
return 1 ;
V_88 = V_87 / V_64 + 1 ;
V_89 = 0 ;
F_13 ( V_88 > V_90 ) ;
while ( V_88 ) {
struct V_91 * V_92 = F_51 ( V_19 , V_24 , 0 ) ;
if ( ! V_92 )
break;
V_86 -> V_93 [ V_89 ++ ] = V_92 ;
V_88 -- ;
}
return V_88 == 0 ;
}
static void
F_52 ( struct V_85 * V_86 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_53 ( V_86 -> V_93 ) ; V_46 ++ )
if ( V_86 -> V_93 [ V_46 ] )
F_54 ( V_86 -> V_93 [ V_46 ] ) ;
}
struct V_85 *
F_55 ( struct V_40 * V_41 , struct V_39 * V_74 , int V_19 )
{
struct V_85 * V_86 ;
V_86 = F_56 ( sizeof( * V_86 ) , V_24 , V_19 ) ;
if ( ! V_86 )
goto V_94;
F_57 ( & V_86 -> V_95 ) ;
V_41 -> V_58 ++ ;
F_58 ( & V_74 -> V_79 ) ;
V_74 -> V_96 ++ ;
F_59 ( & V_86 -> V_97 , & V_74 -> V_78 ) ;
F_60 ( & V_74 -> V_79 ) ;
V_86 -> V_98 = V_41 ;
V_86 -> V_99 = V_74 ;
V_86 -> V_100 = F_61 ( V_41 -> V_69 , V_24 , V_19 ) ;
if ( ! V_86 -> V_100 )
goto V_101;
V_86 -> V_102 = F_61 ( V_41 -> V_69 , V_24 , V_19 ) ;
if ( ! V_86 -> V_102 )
goto V_101;
if ( ! F_49 ( V_86 , V_41 -> V_63 , V_19 ) )
goto V_101;
return V_86 ;
V_101:
F_62 ( V_86 ) ;
V_94:
return F_63 ( - V_28 ) ;
}
static inline struct V_39 *
F_64 ( struct V_40 * V_41 , struct V_39 * V_74 , unsigned int * V_103 )
{
if ( V_74 != NULL )
return V_74 ;
return & V_41 -> V_42 [ ( * V_103 ) ++ % V_41 -> V_43 ] ;
}
static inline struct V_37 *
F_65 ( struct V_40 * V_41 , struct V_39 * V_74 , unsigned int * V_103 )
{
unsigned int V_46 ;
struct V_37 * V_38 = NULL ;
if ( V_74 != NULL ) {
F_58 ( & V_74 -> V_79 ) ;
} else {
for ( V_46 = 0 ; V_46 < V_41 -> V_43 ; V_46 ++ ) {
V_74 = & V_41 -> V_42 [ -- ( * V_103 ) % V_41 -> V_43 ] ;
F_58 ( & V_74 -> V_79 ) ;
if ( ! F_47 ( & V_74 -> V_78 ) )
goto V_104;
F_60 ( & V_74 -> V_79 ) ;
}
return NULL ;
}
V_104:
if ( ! F_47 ( & V_74 -> V_78 ) ) {
struct V_85 * V_86 ;
V_86 = F_66 ( V_74 -> V_78 . V_105 , struct V_85 , V_97 ) ;
F_67 ( & V_86 -> V_97 ) ;
V_38 = V_86 -> V_106 ;
}
F_60 ( & V_74 -> V_79 ) ;
return V_38 ;
}
int
F_68 ( struct V_40 * V_41 , struct V_39 * V_74 , int V_107 )
{
struct V_85 * V_86 ;
struct V_37 * V_38 ;
struct V_39 * V_108 ;
int error = 0 ;
unsigned int V_103 = V_41 -> V_58 - 1 ;
int V_19 ;
if ( V_74 == NULL ) {
V_107 -= ( V_41 -> V_58 - 1 ) ;
} else {
F_58 ( & V_74 -> V_79 ) ;
V_107 -= V_74 -> V_96 ;
F_60 ( & V_74 -> V_79 ) ;
}
while ( V_107 > 0 ) {
V_107 -- ;
V_108 = F_64 ( V_41 , V_74 , & V_103 ) ;
V_19 = F_18 ( V_108 -> V_75 ) ;
V_86 = F_55 ( V_41 , V_108 , V_19 ) ;
if ( F_69 ( V_86 ) ) {
error = F_70 ( V_86 ) ;
break;
}
F_71 ( V_41 -> V_84 ) ;
V_38 = F_72 ( V_41 -> V_83 , V_86 ,
V_19 , V_41 -> V_56 ) ;
if ( F_69 ( V_38 ) ) {
error = F_70 ( V_38 ) ;
F_73 ( V_41 -> V_84 ) ;
F_62 ( V_86 ) ;
break;
}
V_86 -> V_106 = V_38 ;
if ( V_41 -> V_43 > 1 )
F_20 ( V_38 , V_108 -> V_75 ) ;
F_43 ( V_41 ) ;
F_74 ( V_38 ) ;
}
while ( V_107 < 0 &&
( V_38 = F_65 ( V_41 , V_74 , & V_103 ) ) != NULL ) {
F_75 ( V_109 , V_38 , 1 ) ;
V_107 ++ ;
}
return error ;
}
void
F_62 ( struct V_85 * V_86 )
{
struct V_40 * V_41 = V_86 -> V_98 ;
struct V_39 * V_74 = V_86 -> V_99 ;
F_52 ( V_86 ) ;
F_10 ( V_86 -> V_102 ) ;
F_10 ( V_86 -> V_100 ) ;
F_10 ( V_86 -> V_110 ) ;
F_58 ( & V_74 -> V_79 ) ;
V_74 -> V_96 -- ;
F_76 ( & V_86 -> V_97 ) ;
F_60 ( & V_74 -> V_79 ) ;
F_10 ( V_86 ) ;
if ( V_41 )
F_42 ( V_41 ) ;
}
static int F_77 ( const T_2 V_111 , const T_2 V_112 ,
const unsigned short V_113 ,
const unsigned short V_114 )
{
const struct V_115 sin = {
. V_116 = V_117 ,
. V_118 . V_119 = F_78 ( V_120 ) ,
. V_121 = F_79 ( V_114 ) ,
} ;
const char * V_122 ;
int error ;
switch ( V_113 ) {
case V_123 :
V_122 = V_124 ;
break;
case V_125 :
V_122 = V_126 ;
break;
default:
return - V_127 ;
}
error = F_80 ( V_111 , V_112 ,
( const struct V_128 * ) & sin , V_122 ) ;
if ( error == - V_129 )
error = F_81 ( V_111 , V_112 , V_113 , V_114 ) ;
return error ;
}
static int F_82 ( const T_2 V_111 , const T_2 V_112 ,
const unsigned short V_113 ,
const unsigned short V_114 )
{
const struct V_130 V_131 = {
. V_132 = V_133 ,
. V_134 = V_135 ,
. V_136 = F_79 ( V_114 ) ,
} ;
const char * V_122 ;
int error ;
switch ( V_113 ) {
case V_123 :
V_122 = V_137 ;
break;
case V_125 :
V_122 = V_138 ;
break;
default:
return - V_127 ;
}
error = F_80 ( V_111 , V_112 ,
( const struct V_128 * ) & V_131 , V_122 ) ;
if ( error == - V_129 )
error = - V_139 ;
return error ;
}
static int F_83 ( const char * V_140 ,
const T_2 V_111 , const T_2 V_112 ,
const int V_141 ,
const unsigned short V_113 ,
const unsigned short V_114 )
{
int error = - V_139 ;
switch ( V_141 ) {
case V_142 :
error = F_77 ( V_111 , V_112 ,
V_113 , V_114 ) ;
break;
#if F_84 ( V_143 ) || F_84 ( V_144 )
case V_145 :
error = F_82 ( V_111 , V_112 ,
V_113 , V_114 ) ;
#endif
}
if ( error < 0 )
F_44 ( V_146 L_9
L_10 , V_140 , V_112 , - error ) ;
return error ;
}
int F_85 ( const struct V_40 * V_41 , const int V_141 ,
const unsigned short V_147 , const unsigned short V_114 )
{
struct V_44 * V_45 ;
unsigned int V_46 ;
int error = 0 ;
F_13 ( V_147 == 0 && V_114 == 0 ) ;
for ( V_45 = V_41 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
F_39 ( L_11 ,
V_45 -> V_57 ,
V_46 ,
V_147 == V_123 ? L_12 : L_13 ,
V_114 ,
V_141 ,
V_45 -> V_50 [ V_46 ] -> V_51 ?
L_14 : L_15 ) ;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
error = F_83 ( V_45 -> V_57 , V_45 -> V_148 ,
V_46 , V_141 , V_147 , V_114 ) ;
if ( error < 0 )
break;
}
}
return error ;
}
static void F_86 ( const T_2 V_111 , const T_2 V_112 ,
const char * V_140 )
{
int error ;
error = F_80 ( V_111 , V_112 , NULL , L_15 ) ;
if ( error == - V_129 )
error = F_81 ( V_111 , V_112 , 0 , 0 ) ;
F_39 ( L_16 ,
V_149 , V_140 , V_112 , error ) ;
}
static void F_28 ( const struct V_40 * V_41 )
{
struct V_44 * V_45 ;
unsigned long V_150 ;
unsigned int V_46 ;
F_87 ( V_151 ) ;
for ( V_45 = V_41 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
F_39 ( L_17 ,
V_45 -> V_57 , V_46 ) ;
F_86 ( V_45 -> V_148 , V_46 , V_45 -> V_57 ) ;
}
}
F_88 ( & V_152 -> V_153 -> V_154 , V_150 ) ;
F_89 () ;
F_90 ( & V_152 -> V_153 -> V_154 , V_150 ) ;
}
int
F_91 ( struct V_85 * V_86 , struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_44 * V_45 ;
struct V_158 * V_159 = NULL ;
struct V_160 * V_161 = NULL ;
struct V_40 * V_41 = V_86 -> V_98 ;
T_3 V_162 ;
T_4 * V_163 ;
T_2 V_52 , V_54 , V_164 ;
T_4 V_165 , V_166 ;
int V_167 ;
T_4 * V_168 ;
V_166 = V_169 ;
if ( V_156 -> V_170 < 6 * 4 )
goto V_171;
V_86 -> V_172 = 1 ;
V_86 -> V_173 = 1 ;
V_86 -> V_174 = false ;
V_86 -> V_175 -> V_176 -> V_177 ( V_86 ) ;
F_92 ( V_157 , V_86 -> V_178 ) ;
V_54 = F_93 ( V_156 ) ;
F_94 ( V_157 , 1 ) ;
if ( V_54 != 2 )
goto V_179;
V_168 = V_157 -> V_180 + V_157 -> V_170 ;
F_94 ( V_157 , 0 ) ;
V_86 -> V_181 = V_52 = F_93 ( V_156 ) ;
V_86 -> V_182 = V_54 = F_93 ( V_156 ) ;
V_86 -> V_183 = V_164 = F_93 ( V_156 ) ;
V_45 = V_41 -> V_47 ;
for ( V_45 = V_41 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 )
if ( V_52 == V_45 -> V_148 )
break;
V_167 = F_95 ( V_86 , & V_165 ) ;
if ( V_167 == V_184 && V_45 ) {
V_165 = V_185 ;
V_167 = V_45 -> V_186 ( V_86 ) ;
}
switch ( V_167 ) {
case V_184 :
break;
case V_187 :
goto V_188;
case V_189 :
V_166 = V_190 ;
goto V_191;
case V_192 :
goto V_193;
case V_194 :
if ( F_96 ( V_195 , & V_86 -> V_175 -> V_196 ) )
F_97 ( V_86 -> V_175 ) ;
case V_197 :
goto V_198;
case V_199 :
goto V_200;
}
if ( V_45 == NULL )
goto V_201;
if ( V_54 >= V_45 -> V_49 ||
! ( V_159 = V_45 -> V_50 [ V_54 ] ) )
goto V_202;
V_161 = V_159 -> V_203 + V_164 ;
if ( V_164 >= V_159 -> V_204 || ! V_161 -> V_205 )
goto V_206;
V_86 -> V_207 = V_161 ;
V_41 -> V_59 -> V_208 ++ ;
V_163 = V_157 -> V_180 + V_157 -> V_170 ;
F_94 ( V_157 , V_209 ) ;
V_161 -> V_210 ++ ;
memset ( V_86 -> V_100 , 0 , V_161 -> V_211 ) ;
memset ( V_86 -> V_102 , 0 , V_161 -> V_212 ) ;
if ( V_161 -> V_213 )
F_98 ( V_86 , V_161 -> V_213 << 2 ) ;
if ( ! V_159 -> V_214 ) {
V_162 = V_161 -> V_215 ;
if ( V_162 && ! V_162 ( V_86 , V_156 -> V_180 , V_86 -> V_100 ) )
goto V_188;
* V_163 = V_161 -> V_205 ( V_86 , V_86 -> V_100 , V_86 -> V_102 ) ;
if ( V_86 -> V_174 ) {
if ( V_161 -> V_216 )
V_161 -> V_216 ( V_86 , NULL , V_86 -> V_102 ) ;
goto V_198;
}
if ( * V_163 == V_169 &&
( V_162 = V_161 -> V_217 ) &&
! V_162 ( V_86 , V_157 -> V_180 + V_157 -> V_170 , V_86 -> V_102 ) ) {
F_39 ( L_18 ) ;
* V_163 = V_190 ;
}
} else {
F_39 ( L_19 ) ;
if ( ! V_159 -> V_214 ( V_86 , V_163 ) ) {
if ( V_161 -> V_216 )
V_161 -> V_216 ( V_86 , NULL , V_86 -> V_102 ) ;
goto V_198;
}
}
if ( * V_163 != V_169 )
V_157 -> V_170 = ( ( void * ) V_163 ) - V_157 -> V_180 + 4 ;
if ( V_161 -> V_216 )
V_161 -> V_216 ( V_86 , NULL , V_86 -> V_102 ) ;
if ( V_161 -> V_217 == NULL )
goto V_198;
V_200:
if ( F_99 ( V_86 ) )
goto V_198;
return 1 ;
V_198:
F_99 ( V_86 ) ;
F_39 ( L_20 ) ;
return 0 ;
V_171:
F_100 ( V_86 , L_21 ,
V_156 -> V_170 ) ;
goto V_198;
V_179:
V_41 -> V_59 -> V_218 ++ ;
F_94 ( V_157 , 1 ) ;
F_94 ( V_157 , 0 ) ;
F_94 ( V_157 , 2 ) ;
F_94 ( V_157 , 2 ) ;
goto V_200;
V_193:
F_39 ( L_22 , F_101 ( V_165 ) ) ;
V_41 -> V_59 -> V_219 ++ ;
F_102 ( V_86 , V_168 ) ;
F_94 ( V_157 , 1 ) ;
F_94 ( V_157 , 1 ) ;
F_94 ( V_157 , F_101 ( V_165 ) ) ;
goto V_200;
V_201:
F_39 ( L_23 , V_52 ) ;
V_41 -> V_59 -> V_218 ++ ;
F_94 ( V_157 , V_220 ) ;
goto V_200;
V_202:
F_100 ( V_86 , L_24 ,
V_54 , V_52 , V_45 -> V_57 ) ;
V_41 -> V_59 -> V_218 ++ ;
F_94 ( V_157 , V_221 ) ;
F_94 ( V_157 , V_45 -> V_66 ) ;
F_94 ( V_157 , V_45 -> V_67 ) ;
goto V_200;
V_206:
F_100 ( V_86 , L_25 , V_164 ) ;
V_41 -> V_59 -> V_218 ++ ;
F_94 ( V_157 , V_222 ) ;
goto V_200;
V_188:
F_100 ( V_86 , L_26 ) ;
V_166 = V_223 ;
V_191:
V_41 -> V_59 -> V_218 ++ ;
F_94 ( V_157 , F_101 ( V_166 ) ) ;
goto V_200;
}
int
F_103 ( struct V_85 * V_86 )
{
struct V_155 * V_156 = & V_86 -> V_224 . V_225 [ 0 ] ;
struct V_155 * V_157 = & V_86 -> V_226 . V_225 [ 0 ] ;
struct V_40 * V_41 = V_86 -> V_98 ;
T_2 V_227 ;
V_86 -> V_228 = 1 ;
V_157 -> V_180 = F_104 ( V_86 -> V_229 [ 0 ] ) ;
V_157 -> V_170 = 0 ;
V_86 -> V_226 . V_88 = V_86 -> V_229 + 1 ;
V_86 -> V_226 . V_230 = 0 ;
V_86 -> V_226 . V_231 = 0 ;
V_86 -> V_226 . V_232 = 0 ;
V_86 -> V_226 . V_233 = V_64 ;
V_86 -> V_226 . V_234 [ 0 ] . V_180 = NULL ;
V_86 -> V_226 . V_234 [ 0 ] . V_170 = 0 ;
V_86 -> V_178 = F_105 ( V_156 ) ;
V_227 = F_93 ( V_156 ) ;
if ( V_227 != 0 ) {
F_100 ( V_86 , L_27 , V_227 ) ;
V_41 -> V_59 -> V_218 ++ ;
F_106 ( V_86 ) ;
return 0 ;
}
if ( F_91 ( V_86 , V_156 , V_157 ) )
return F_107 ( V_86 ) ;
else {
F_106 ( V_86 ) ;
return 0 ;
}
}
int
F_108 ( struct V_40 * V_41 , struct V_235 * V_236 ,
struct V_85 * V_86 )
{
struct V_155 * V_156 = & V_86 -> V_224 . V_225 [ 0 ] ;
struct V_155 * V_157 = & V_86 -> V_226 . V_225 [ 0 ] ;
V_86 -> V_175 = V_41 -> V_237 ;
V_86 -> V_178 = V_236 -> V_178 ;
V_86 -> V_238 = V_236 -> V_175 -> V_239 ;
V_86 -> V_98 = V_41 ;
V_86 -> V_240 = sizeof( V_236 -> V_175 -> V_241 ) ;
memcpy ( & V_86 -> V_242 , & V_236 -> V_175 -> V_241 , V_86 -> V_240 ) ;
memcpy ( & V_86 -> V_224 , & V_236 -> V_243 , sizeof( V_86 -> V_224 ) ) ;
memcpy ( & V_86 -> V_226 , & V_236 -> V_244 , sizeof( V_86 -> V_226 ) ) ;
V_157 -> V_170 = 0 ;
if ( V_86 -> V_238 != V_125 ) {
F_44 ( V_245 L_28 ) ;
F_109 () ;
}
F_105 ( V_156 ) ;
F_93 ( V_156 ) ;
if ( F_91 ( V_86 , V_156 , V_157 ) ) {
memcpy ( & V_236 -> V_244 , & V_86 -> V_226 ,
sizeof( V_236 -> V_244 ) ) ;
return F_110 ( V_236 ) ;
} else {
return 0 ;
}
}
T_2 F_111 ( const struct V_85 * V_86 )
{
T_2 V_246 = V_86 -> V_175 -> V_247 -> V_248 ;
if ( V_86 -> V_98 -> V_62 < V_246 )
V_246 = V_86 -> V_98 -> V_62 ;
return V_246 ;
}
