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
V_7 -> V_23 = NULL ;
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
F_10 ( V_7 -> V_23 ) ;
V_7 -> V_23 = NULL ;
F_10 ( V_7 -> V_26 ) ;
V_7 -> V_26 = NULL ;
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
return V_35 ;
}
static inline void
F_20 ( struct V_36 * V_37 , unsigned int V_30 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_19 = V_7 -> V_26 [ V_30 ] ;
F_13 ( V_7 -> V_11 == 0 ) ;
switch ( V_7 -> V_34 ) {
case V_15 :
{
F_21 ( V_37 , F_22 ( V_19 ) ) ;
break;
}
case V_16 :
{
F_21 ( V_37 , F_23 ( V_19 ) ) ;
break;
}
}
}
struct V_38 *
F_24 ( struct V_39 * V_40 , int V_31 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_30 = 0 ;
if ( F_25 ( V_40 ) ) {
switch ( V_7 -> V_34 ) {
case V_15 :
V_30 = V_7 -> V_23 [ V_31 ] ;
break;
case V_16 :
V_30 = V_7 -> V_23 [ F_19 ( V_31 ) ] ;
break;
}
}
return & V_40 -> V_41 [ V_30 % V_40 -> V_42 ] ;
}
static int F_26 ( struct V_39 * V_40 )
{
int V_8 ;
V_8 = F_27 () ;
if ( V_8 )
return V_8 ;
F_28 ( V_40 ) ;
return 0 ;
}
void F_29 ( struct V_39 * V_40 )
{
F_28 ( V_40 ) ;
F_30 () ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_43 * V_44 ;
unsigned int V_45 ;
for ( V_44 = V_40 -> V_46 ; V_44 ; V_44 = V_44 -> V_47 ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; V_45 ++ ) {
if ( V_44 -> V_49 [ V_45 ] == NULL )
continue;
if ( V_44 -> V_49 [ V_45 ] -> V_50 == 0 )
return 1 ;
}
}
return 0 ;
}
static struct V_39 *
F_32 ( struct V_43 * V_51 , unsigned int V_52 , int V_33 ,
void (* F_33)( struct V_39 * V_40 ) )
{
struct V_39 * V_40 ;
unsigned int V_53 ;
unsigned int V_54 ;
unsigned int V_45 ;
if ( ! ( V_40 = F_34 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_55 = V_51 -> V_56 ;
V_40 -> V_46 = V_51 ;
V_40 -> V_57 = 1 ;
V_40 -> V_58 = V_51 -> V_59 ;
if ( V_52 > V_60 )
V_52 = V_60 ;
V_40 -> V_61 = V_52 ? V_52 : 4096 ;
V_40 -> V_62 = F_35 ( V_40 -> V_61 + V_63 , V_63 ) ;
V_40 -> V_64 = F_33 ;
V_54 = 0 ;
while ( V_51 ) {
V_51 -> V_65 = V_51 -> V_48 - 1 ;
for ( V_53 = 0 ; V_53 < V_51 -> V_48 ; V_53 ++ )
if ( V_51 -> V_49 [ V_53 ] ) {
V_51 -> V_66 = V_53 ;
if ( V_51 -> V_65 > V_53 )
V_51 -> V_65 = V_53 ;
if ( V_51 -> V_49 [ V_53 ] -> V_67 > V_54 )
V_54 = V_51 -> V_49 [ V_53 ] -> V_67 ;
}
V_51 = V_51 -> V_47 ;
}
V_40 -> V_68 = V_54 ;
F_36 ( & V_40 -> V_69 ) ;
F_36 ( & V_40 -> V_70 ) ;
F_37 ( & V_40 -> V_71 ) ;
F_38 ( & V_40 -> V_72 ) ;
V_40 -> V_42 = V_33 ;
V_40 -> V_41 =
F_9 ( V_40 -> V_42 , sizeof( struct V_38 ) ,
V_24 ) ;
if ( ! V_40 -> V_41 ) {
F_10 ( V_40 ) ;
return NULL ;
}
for ( V_45 = 0 ; V_45 < V_40 -> V_42 ; V_45 ++ ) {
struct V_38 * V_73 = & V_40 -> V_41 [ V_45 ] ;
F_39 ( L_6 ,
V_45 , V_40 -> V_55 ) ;
V_73 -> V_74 = V_45 ;
F_36 ( & V_73 -> V_75 ) ;
F_36 ( & V_73 -> V_76 ) ;
F_36 ( & V_73 -> V_77 ) ;
F_38 ( & V_73 -> V_78 ) ;
}
if ( F_31 ( V_40 ) ) {
if ( F_26 ( V_40 ) < 0 ) {
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
return NULL ;
}
if ( ! V_40 -> V_64 )
V_40 -> V_64 = F_29 ;
}
return V_40 ;
}
struct V_39 *
F_40 ( struct V_43 * V_51 , unsigned int V_52 ,
void (* F_33)( struct V_39 * V_40 ) )
{
return F_32 ( V_51 , V_52 , 1 , F_33 ) ;
}
struct V_39 *
F_41 ( struct V_43 * V_51 , unsigned int V_52 ,
void (* F_33)( struct V_39 * V_40 ) ,
T_1 V_79 , struct V_80 * V_81 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_32 ( V_51 , V_52 , V_33 , F_33 ) ;
if ( V_40 != NULL ) {
V_40 -> V_82 = V_79 ;
V_40 -> V_83 = V_81 ;
}
return V_40 ;
}
void
F_42 ( struct V_39 * V_40 )
{
F_39 ( L_7 ,
V_40 -> V_46 -> V_56 ,
V_40 -> V_57 ) ;
if ( V_40 -> V_57 ) {
if ( -- ( V_40 -> V_57 ) != 0 ) {
F_43 ( V_40 ) ;
return;
}
} else
F_44 ( L_8 , V_40 ) ;
F_45 ( & V_40 -> V_71 ) ;
F_46 ( V_40 ) ;
if ( V_40 -> V_64 )
V_40 -> V_64 ( V_40 ) ;
F_47 ( V_40 ) ;
if ( F_25 ( V_40 ) )
F_17 () ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_48 ( struct V_84 * V_85 , unsigned int V_86 , int V_19 )
{
unsigned int V_87 , V_88 ;
if ( F_49 ( V_85 ) )
return 1 ;
V_87 = V_86 / V_63 + 1 ;
V_88 = 0 ;
F_13 ( V_87 > V_89 ) ;
while ( V_87 ) {
struct V_90 * V_91 = F_50 ( V_19 , V_24 , 0 ) ;
if ( ! V_91 )
break;
V_85 -> V_92 [ V_88 ++ ] = V_91 ;
V_87 -- ;
}
return V_87 == 0 ;
}
static void
F_51 ( struct V_84 * V_85 )
{
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < F_52 ( V_85 -> V_92 ) ; V_45 ++ )
if ( V_85 -> V_92 [ V_45 ] )
F_53 ( V_85 -> V_92 [ V_45 ] ) ;
}
struct V_84 *
F_54 ( struct V_39 * V_40 , struct V_38 * V_73 , int V_19 )
{
struct V_84 * V_85 ;
V_85 = F_55 ( sizeof( * V_85 ) , V_24 , V_19 ) ;
if ( ! V_85 )
goto V_93;
F_56 ( & V_85 -> V_94 ) ;
V_40 -> V_57 ++ ;
F_57 ( & V_73 -> V_78 ) ;
V_73 -> V_95 ++ ;
F_58 ( & V_85 -> V_96 , & V_73 -> V_77 ) ;
F_59 ( & V_73 -> V_78 ) ;
V_85 -> V_97 = V_40 ;
V_85 -> V_98 = V_73 ;
V_85 -> V_99 = F_60 ( V_40 -> V_68 , V_24 , V_19 ) ;
if ( ! V_85 -> V_99 )
goto V_100;
V_85 -> V_101 = F_60 ( V_40 -> V_68 , V_24 , V_19 ) ;
if ( ! V_85 -> V_101 )
goto V_100;
if ( ! F_48 ( V_85 , V_40 -> V_62 , V_19 ) )
goto V_100;
return V_85 ;
V_100:
F_61 ( V_85 ) ;
V_93:
return F_62 ( - V_28 ) ;
}
static inline struct V_38 *
F_63 ( struct V_39 * V_40 , struct V_38 * V_73 , unsigned int * V_102 )
{
if ( V_73 != NULL )
return V_73 ;
return & V_40 -> V_41 [ ( * V_102 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_64 ( struct V_39 * V_40 , struct V_38 * V_73 , unsigned int * V_102 )
{
unsigned int V_45 ;
struct V_36 * V_37 = NULL ;
if ( V_73 != NULL ) {
F_57 ( & V_73 -> V_78 ) ;
} else {
for ( V_45 = 0 ; V_45 < V_40 -> V_42 ; V_45 ++ ) {
V_73 = & V_40 -> V_41 [ -- ( * V_102 ) % V_40 -> V_42 ] ;
F_57 ( & V_73 -> V_78 ) ;
if ( ! F_65 ( & V_73 -> V_77 ) )
goto V_103;
F_59 ( & V_73 -> V_78 ) ;
}
return NULL ;
}
V_103:
if ( ! F_65 ( & V_73 -> V_77 ) ) {
struct V_84 * V_85 ;
V_85 = F_66 ( V_73 -> V_77 . V_104 , struct V_84 , V_96 ) ;
F_67 ( & V_85 -> V_96 ) ;
V_37 = V_85 -> V_105 ;
}
F_59 ( & V_73 -> V_78 ) ;
return V_37 ;
}
int
F_68 ( struct V_39 * V_40 , struct V_38 * V_73 , int V_106 )
{
struct V_84 * V_85 ;
struct V_36 * V_37 ;
struct V_38 * V_107 ;
int error = 0 ;
unsigned int V_102 = V_40 -> V_57 - 1 ;
int V_19 ;
if ( V_73 == NULL ) {
V_106 -= ( V_40 -> V_57 - 1 ) ;
} else {
F_57 ( & V_73 -> V_78 ) ;
V_106 -= V_73 -> V_95 ;
F_59 ( & V_73 -> V_78 ) ;
}
while ( V_106 > 0 ) {
V_106 -- ;
V_107 = F_63 ( V_40 , V_73 , & V_102 ) ;
V_19 = F_18 ( V_107 -> V_74 ) ;
V_85 = F_54 ( V_40 , V_107 , V_19 ) ;
if ( F_69 ( V_85 ) ) {
error = F_70 ( V_85 ) ;
break;
}
F_71 ( V_40 -> V_83 ) ;
V_37 = F_72 ( V_40 -> V_82 , V_85 ,
V_19 , V_40 -> V_55 ) ;
if ( F_69 ( V_37 ) ) {
error = F_70 ( V_37 ) ;
F_73 ( V_40 -> V_83 ) ;
F_61 ( V_85 ) ;
break;
}
V_85 -> V_105 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_20 ( V_37 , V_107 -> V_74 ) ;
F_43 ( V_40 ) ;
F_74 ( V_37 ) ;
}
while ( V_106 < 0 &&
( V_37 = F_64 ( V_40 , V_73 , & V_102 ) ) != NULL ) {
F_75 ( V_108 , V_37 , 1 ) ;
V_106 ++ ;
}
return error ;
}
void
F_61 ( struct V_84 * V_85 )
{
struct V_39 * V_40 = V_85 -> V_97 ;
struct V_38 * V_73 = V_85 -> V_98 ;
F_51 ( V_85 ) ;
F_10 ( V_85 -> V_101 ) ;
F_10 ( V_85 -> V_99 ) ;
F_10 ( V_85 -> V_109 ) ;
F_57 ( & V_73 -> V_78 ) ;
V_73 -> V_95 -- ;
F_76 ( & V_85 -> V_96 ) ;
F_59 ( & V_73 -> V_78 ) ;
F_10 ( V_85 ) ;
if ( V_40 )
F_42 ( V_40 ) ;
}
static int F_77 ( const T_2 V_110 , const T_2 V_111 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
const struct V_114 sin = {
. V_115 = V_116 ,
. V_117 . V_118 = F_78 ( V_119 ) ,
. V_120 = F_79 ( V_113 ) ,
} ;
const char * V_121 ;
int error ;
switch ( V_112 ) {
case V_122 :
V_121 = V_123 ;
break;
case V_124 :
V_121 = V_125 ;
break;
default:
return - V_126 ;
}
error = F_80 ( V_110 , V_111 ,
( const struct V_127 * ) & sin , V_121 ) ;
if ( error == - V_128 )
error = F_81 ( V_110 , V_111 , V_112 , V_113 ) ;
return error ;
}
static int F_82 ( const T_2 V_110 , const T_2 V_111 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
const struct V_129 V_130 = {
. V_131 = V_132 ,
. V_133 = V_134 ,
. V_135 = F_79 ( V_113 ) ,
} ;
const char * V_121 ;
int error ;
switch ( V_112 ) {
case V_122 :
V_121 = V_136 ;
break;
case V_124 :
V_121 = V_137 ;
break;
default:
return - V_126 ;
}
error = F_80 ( V_110 , V_111 ,
( const struct V_127 * ) & V_130 , V_121 ) ;
if ( error == - V_128 )
error = - V_138 ;
return error ;
}
static int F_83 ( const char * V_139 ,
const T_2 V_110 , const T_2 V_111 ,
const int V_140 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
int error = - V_138 ;
switch ( V_140 ) {
case V_141 :
error = F_77 ( V_110 , V_111 ,
V_112 , V_113 ) ;
break;
#if F_84 ( V_142 )
case V_143 :
error = F_82 ( V_110 , V_111 ,
V_112 , V_113 ) ;
#endif
}
if ( error < 0 )
F_44 ( V_144 L_9
L_10 , V_139 , V_111 , - error ) ;
return error ;
}
int F_85 ( const struct V_39 * V_40 , const int V_140 ,
const unsigned short V_145 , const unsigned short V_113 )
{
struct V_43 * V_44 ;
unsigned int V_45 ;
int error = 0 ;
F_13 ( V_145 == 0 && V_113 == 0 ) ;
for ( V_44 = V_40 -> V_46 ; V_44 ; V_44 = V_44 -> V_47 ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; V_45 ++ ) {
if ( V_44 -> V_49 [ V_45 ] == NULL )
continue;
F_39 ( L_11 ,
V_44 -> V_56 ,
V_45 ,
V_145 == V_122 ? L_12 : L_13 ,
V_113 ,
V_140 ,
V_44 -> V_49 [ V_45 ] -> V_50 ?
L_14 : L_15 ) ;
if ( V_44 -> V_49 [ V_45 ] -> V_50 )
continue;
error = F_83 ( V_44 -> V_56 , V_44 -> V_146 ,
V_45 , V_140 , V_145 , V_113 ) ;
if ( error < 0 )
break;
}
}
return error ;
}
static void F_86 ( const T_2 V_110 , const T_2 V_111 ,
const char * V_139 )
{
int error ;
error = F_80 ( V_110 , V_111 , NULL , L_15 ) ;
if ( error == - V_128 )
error = F_81 ( V_110 , V_111 , 0 , 0 ) ;
F_39 ( L_16 ,
V_147 , V_139 , V_111 , error ) ;
}
static void F_28 ( const struct V_39 * V_40 )
{
struct V_43 * V_44 ;
unsigned long V_148 ;
unsigned int V_45 ;
F_87 ( V_149 ) ;
for ( V_44 = V_40 -> V_46 ; V_44 ; V_44 = V_44 -> V_47 ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; V_45 ++ ) {
if ( V_44 -> V_49 [ V_45 ] == NULL )
continue;
if ( V_44 -> V_49 [ V_45 ] -> V_50 )
continue;
F_39 ( L_17 ,
V_44 -> V_56 , V_45 ) ;
F_86 ( V_44 -> V_146 , V_45 , V_44 -> V_56 ) ;
}
}
F_88 ( & V_150 -> V_151 -> V_152 , V_148 ) ;
F_89 () ;
F_90 ( & V_150 -> V_151 -> V_152 , V_148 ) ;
}
int
F_91 ( struct V_84 * V_85 , struct V_153 * V_154 , struct V_153 * V_155 )
{
struct V_43 * V_44 ;
struct V_156 * V_157 = NULL ;
struct V_158 * V_159 = NULL ;
struct V_39 * V_40 = V_85 -> V_97 ;
T_3 V_160 ;
T_4 * V_161 ;
T_2 V_51 , V_53 , V_162 ;
T_4 V_163 , V_164 ;
int V_165 ;
T_4 * V_166 ;
V_164 = V_167 ;
if ( V_154 -> V_168 < 6 * 4 )
goto V_169;
V_85 -> V_170 = 1 ;
V_85 -> V_171 = 1 ;
V_85 -> V_172 = false ;
V_85 -> V_173 -> V_174 -> V_175 ( V_85 ) ;
F_92 ( V_155 , V_85 -> V_176 ) ;
V_53 = F_93 ( V_154 ) ;
F_94 ( V_155 , 1 ) ;
if ( V_53 != 2 )
goto V_177;
V_166 = V_155 -> V_178 + V_155 -> V_168 ;
F_94 ( V_155 , 0 ) ;
V_85 -> V_179 = V_51 = F_93 ( V_154 ) ;
V_85 -> V_180 = V_53 = F_93 ( V_154 ) ;
V_85 -> V_181 = V_162 = F_93 ( V_154 ) ;
V_44 = V_40 -> V_46 ;
for ( V_44 = V_40 -> V_46 ; V_44 ; V_44 = V_44 -> V_47 )
if ( V_51 == V_44 -> V_146 )
break;
V_165 = F_95 ( V_85 , & V_163 ) ;
if ( V_165 == V_182 && V_44 ) {
V_163 = V_183 ;
V_165 = V_44 -> V_184 ( V_85 ) ;
}
switch ( V_165 ) {
case V_182 :
break;
case V_185 :
goto V_186;
case V_187 :
V_164 = V_188 ;
goto V_189;
case V_190 :
goto V_191;
case V_192 :
if ( F_96 ( V_193 , & V_85 -> V_173 -> V_194 ) )
F_97 ( V_85 -> V_173 ) ;
case V_195 :
goto V_196;
case V_197 :
goto V_198;
}
if ( V_44 == NULL )
goto V_199;
if ( V_53 >= V_44 -> V_48 ||
! ( V_157 = V_44 -> V_49 [ V_53 ] ) )
goto V_200;
V_159 = V_157 -> V_201 + V_162 ;
if ( V_162 >= V_157 -> V_202 || ! V_159 -> V_203 )
goto V_204;
V_85 -> V_205 = V_159 ;
V_40 -> V_58 -> V_206 ++ ;
V_161 = V_155 -> V_178 + V_155 -> V_168 ;
F_94 ( V_155 , V_207 ) ;
V_159 -> V_208 ++ ;
memset ( V_85 -> V_99 , 0 , V_159 -> V_209 ) ;
memset ( V_85 -> V_101 , 0 , V_159 -> V_210 ) ;
if ( V_159 -> V_211 )
F_98 ( V_85 , V_159 -> V_211 << 2 ) ;
if ( ! V_157 -> V_212 ) {
V_160 = V_159 -> V_213 ;
if ( V_160 && ! V_160 ( V_85 , V_154 -> V_178 , V_85 -> V_99 ) )
goto V_186;
* V_161 = V_159 -> V_203 ( V_85 , V_85 -> V_99 , V_85 -> V_101 ) ;
if ( V_85 -> V_172 ) {
if ( V_159 -> V_214 )
V_159 -> V_214 ( V_85 , NULL , V_85 -> V_101 ) ;
goto V_196;
}
if ( * V_161 == V_167 &&
( V_160 = V_159 -> V_215 ) &&
! V_160 ( V_85 , V_155 -> V_178 + V_155 -> V_168 , V_85 -> V_101 ) ) {
F_39 ( L_18 ) ;
* V_161 = V_188 ;
}
} else {
F_39 ( L_19 ) ;
if ( ! V_157 -> V_212 ( V_85 , V_161 ) ) {
if ( V_159 -> V_214 )
V_159 -> V_214 ( V_85 , NULL , V_85 -> V_101 ) ;
goto V_196;
}
}
if ( * V_161 != V_167 )
V_155 -> V_168 = ( ( void * ) V_161 ) - V_155 -> V_178 + 4 ;
if ( V_159 -> V_214 )
V_159 -> V_214 ( V_85 , NULL , V_85 -> V_101 ) ;
if ( V_159 -> V_215 == NULL )
goto V_196;
V_198:
if ( F_99 ( V_85 ) )
goto V_196;
return 1 ;
V_196:
F_99 ( V_85 ) ;
F_39 ( L_20 ) ;
return 0 ;
V_169:
F_100 ( V_85 , L_21 ,
V_154 -> V_168 ) ;
goto V_196;
V_177:
V_40 -> V_58 -> V_216 ++ ;
F_94 ( V_155 , 1 ) ;
F_94 ( V_155 , 0 ) ;
F_94 ( V_155 , 2 ) ;
F_94 ( V_155 , 2 ) ;
goto V_198;
V_191:
F_39 ( L_22 , F_101 ( V_163 ) ) ;
V_40 -> V_58 -> V_217 ++ ;
F_102 ( V_85 , V_166 ) ;
F_94 ( V_155 , 1 ) ;
F_94 ( V_155 , 1 ) ;
F_94 ( V_155 , F_101 ( V_163 ) ) ;
goto V_198;
V_199:
F_39 ( L_23 , V_51 ) ;
V_40 -> V_58 -> V_216 ++ ;
F_94 ( V_155 , V_218 ) ;
goto V_198;
V_200:
F_100 ( V_85 , L_24 ,
V_53 , V_51 , V_44 -> V_56 ) ;
V_40 -> V_58 -> V_216 ++ ;
F_94 ( V_155 , V_219 ) ;
F_94 ( V_155 , V_44 -> V_65 ) ;
F_94 ( V_155 , V_44 -> V_66 ) ;
goto V_198;
V_204:
F_100 ( V_85 , L_25 , V_162 ) ;
V_40 -> V_58 -> V_216 ++ ;
F_94 ( V_155 , V_220 ) ;
goto V_198;
V_186:
F_100 ( V_85 , L_26 ) ;
V_164 = V_221 ;
V_189:
V_40 -> V_58 -> V_216 ++ ;
F_94 ( V_155 , F_101 ( V_164 ) ) ;
goto V_198;
}
int
F_103 ( struct V_84 * V_85 )
{
struct V_153 * V_154 = & V_85 -> V_222 . V_223 [ 0 ] ;
struct V_153 * V_155 = & V_85 -> V_224 . V_223 [ 0 ] ;
struct V_39 * V_40 = V_85 -> V_97 ;
T_2 V_225 ;
V_85 -> V_226 = 1 ;
V_155 -> V_178 = F_104 ( V_85 -> V_227 [ 0 ] ) ;
V_155 -> V_168 = 0 ;
V_85 -> V_224 . V_87 = V_85 -> V_227 + 1 ;
V_85 -> V_224 . V_228 = 0 ;
V_85 -> V_224 . V_229 = 0 ;
V_85 -> V_224 . V_230 = 0 ;
V_85 -> V_224 . V_231 = V_63 ;
V_85 -> V_224 . V_232 [ 0 ] . V_178 = NULL ;
V_85 -> V_224 . V_232 [ 0 ] . V_168 = 0 ;
V_85 -> V_176 = F_105 ( V_154 ) ;
V_225 = F_93 ( V_154 ) ;
if ( V_225 != 0 ) {
F_100 ( V_85 , L_27 , V_225 ) ;
V_40 -> V_58 -> V_216 ++ ;
F_106 ( V_85 ) ;
return 0 ;
}
if ( F_91 ( V_85 , V_154 , V_155 ) )
return F_107 ( V_85 ) ;
else {
F_106 ( V_85 ) ;
return 0 ;
}
}
int
F_108 ( struct V_39 * V_40 , struct V_233 * V_234 ,
struct V_84 * V_85 )
{
struct V_153 * V_154 = & V_85 -> V_222 . V_223 [ 0 ] ;
struct V_153 * V_155 = & V_85 -> V_224 . V_223 [ 0 ] ;
V_85 -> V_173 = V_40 -> V_235 ;
V_85 -> V_176 = V_234 -> V_176 ;
V_85 -> V_236 = V_234 -> V_173 -> V_237 ;
V_85 -> V_97 = V_40 ;
V_85 -> V_238 = sizeof( V_234 -> V_173 -> V_239 ) ;
memcpy ( & V_85 -> V_240 , & V_234 -> V_173 -> V_239 , V_85 -> V_238 ) ;
memcpy ( & V_85 -> V_222 , & V_234 -> V_241 , sizeof( V_85 -> V_222 ) ) ;
memcpy ( & V_85 -> V_224 , & V_234 -> V_242 , sizeof( V_85 -> V_224 ) ) ;
V_155 -> V_168 = 0 ;
if ( V_85 -> V_236 != V_124 ) {
F_44 ( V_243 L_28 ) ;
F_109 () ;
}
F_105 ( V_154 ) ;
F_93 ( V_154 ) ;
if ( F_91 ( V_85 , V_154 , V_155 ) ) {
memcpy ( & V_234 -> V_242 , & V_85 -> V_224 ,
sizeof( V_234 -> V_242 ) ) ;
return F_110 ( V_234 ) ;
} else {
return 0 ;
}
}
T_2 F_111 ( const struct V_84 * V_85 )
{
T_2 V_244 = V_85 -> V_173 -> V_245 -> V_246 ;
if ( V_85 -> V_97 -> V_61 < V_244 )
V_244 = V_85 -> V_97 -> V_61 ;
return V_244 ;
}
