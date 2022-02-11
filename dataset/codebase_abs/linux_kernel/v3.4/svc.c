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
int F_26 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
int V_8 ;
V_8 = F_27 ( V_43 ) ;
if ( V_8 )
return V_8 ;
F_28 ( V_40 , V_43 ) ;
return 0 ;
}
void F_29 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_28 ( V_40 , V_43 ) ;
F_30 ( V_43 ) ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_44 * V_45 ;
unsigned int V_46 ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 == 0 )
return 1 ;
}
}
return 0 ;
}
static struct V_39 *
F_32 ( struct V_44 * V_52 , unsigned int V_53 , int V_33 ,
void (* F_33)( struct V_39 * V_40 , struct V_43 * V_43 ) )
{
struct V_39 * V_40 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_46 ;
if ( ! ( V_40 = F_34 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_56 = V_52 -> V_57 ;
V_40 -> V_47 = V_52 ;
V_40 -> V_58 = 1 ;
V_40 -> V_59 = V_52 -> V_60 ;
if ( V_53 > V_61 )
V_53 = V_61 ;
V_40 -> V_62 = V_53 ? V_53 : 4096 ;
V_40 -> V_63 = F_35 ( V_40 -> V_62 + V_64 , V_64 ) ;
V_40 -> V_65 = F_33 ;
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
V_40 -> V_69 = V_55 ;
F_36 ( & V_40 -> V_70 ) ;
F_36 ( & V_40 -> V_71 ) ;
F_37 ( & V_40 -> V_72 ) ;
F_38 ( & V_40 -> V_73 ) ;
V_40 -> V_42 = V_33 ;
V_40 -> V_41 =
F_9 ( V_40 -> V_42 , sizeof( struct V_38 ) ,
V_24 ) ;
if ( ! V_40 -> V_41 ) {
F_10 ( V_40 ) ;
return NULL ;
}
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
struct V_38 * V_74 = & V_40 -> V_41 [ V_46 ] ;
F_39 ( L_6 ,
V_46 , V_40 -> V_56 ) ;
V_74 -> V_75 = V_46 ;
F_36 ( & V_74 -> V_76 ) ;
F_36 ( & V_74 -> V_77 ) ;
F_36 ( & V_74 -> V_78 ) ;
F_38 ( & V_74 -> V_79 ) ;
}
if ( F_31 ( V_40 ) ) {
if ( F_26 ( V_40 , V_80 -> V_81 -> V_82 ) < 0 ) {
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
return NULL ;
}
if ( ! V_40 -> V_65 )
V_40 -> V_65 = F_29 ;
}
return V_40 ;
}
struct V_39 *
F_40 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_33)( struct V_39 * V_40 , struct V_43 * V_43 ) )
{
return F_32 ( V_52 , V_53 , 1 , F_33 ) ;
}
struct V_39 *
F_41 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_33)( struct V_39 * V_40 , struct V_43 * V_43 ) ,
T_1 V_83 , struct V_84 * V_85 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_32 ( V_52 , V_53 , V_33 , F_33 ) ;
if ( V_40 != NULL ) {
V_40 -> V_86 = V_83 ;
V_40 -> V_87 = V_85 ;
}
return V_40 ;
}
void F_42 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_43 ( V_40 , V_43 ) ;
if ( V_40 -> V_65 )
V_40 -> V_65 ( V_40 , V_43 ) ;
}
void
F_44 ( struct V_39 * V_40 )
{
struct V_43 * V_43 = V_80 -> V_81 -> V_82 ;
F_39 ( L_7 ,
V_40 -> V_47 -> V_57 ,
V_40 -> V_58 ) ;
if ( V_40 -> V_58 ) {
if ( -- ( V_40 -> V_58 ) != 0 ) {
F_45 ( V_40 ) ;
return;
}
} else
F_46 ( L_8 , V_40 ) ;
F_47 ( & V_40 -> V_72 ) ;
F_42 ( V_40 , V_43 ) ;
F_13 ( ! F_48 ( & V_40 -> V_71 ) ) ;
F_13 ( ! F_48 ( & V_40 -> V_70 ) ) ;
F_49 ( V_40 ) ;
if ( F_25 ( V_40 ) )
F_17 () ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_50 ( struct V_88 * V_89 , unsigned int V_90 , int V_19 )
{
unsigned int V_91 , V_92 ;
if ( F_51 ( V_89 ) )
return 1 ;
V_91 = V_90 / V_64 + 1 ;
V_92 = 0 ;
F_13 ( V_91 > V_93 ) ;
while ( V_91 ) {
struct V_94 * V_95 = F_52 ( V_19 , V_24 , 0 ) ;
if ( ! V_95 )
break;
V_89 -> V_96 [ V_92 ++ ] = V_95 ;
V_91 -- ;
}
return V_91 == 0 ;
}
static void
F_53 ( struct V_88 * V_89 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_54 ( V_89 -> V_96 ) ; V_46 ++ )
if ( V_89 -> V_96 [ V_46 ] )
F_55 ( V_89 -> V_96 [ V_46 ] ) ;
}
struct V_88 *
F_56 ( struct V_39 * V_40 , struct V_38 * V_74 , int V_19 )
{
struct V_88 * V_89 ;
V_89 = F_57 ( sizeof( * V_89 ) , V_24 , V_19 ) ;
if ( ! V_89 )
goto V_97;
F_58 ( & V_89 -> V_98 ) ;
V_40 -> V_58 ++ ;
F_59 ( & V_74 -> V_79 ) ;
V_74 -> V_99 ++ ;
F_60 ( & V_89 -> V_100 , & V_74 -> V_78 ) ;
F_61 ( & V_74 -> V_79 ) ;
V_89 -> V_101 = V_40 ;
V_89 -> V_102 = V_74 ;
V_89 -> V_103 = F_62 ( V_40 -> V_69 , V_24 , V_19 ) ;
if ( ! V_89 -> V_103 )
goto V_104;
V_89 -> V_105 = F_62 ( V_40 -> V_69 , V_24 , V_19 ) ;
if ( ! V_89 -> V_105 )
goto V_104;
if ( ! F_50 ( V_89 , V_40 -> V_63 , V_19 ) )
goto V_104;
return V_89 ;
V_104:
F_63 ( V_89 ) ;
V_97:
return F_64 ( - V_28 ) ;
}
static inline struct V_38 *
F_65 ( struct V_39 * V_40 , struct V_38 * V_74 , unsigned int * V_106 )
{
if ( V_74 != NULL )
return V_74 ;
return & V_40 -> V_41 [ ( * V_106 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_66 ( struct V_39 * V_40 , struct V_38 * V_74 , unsigned int * V_106 )
{
unsigned int V_46 ;
struct V_36 * V_37 = NULL ;
if ( V_74 != NULL ) {
F_59 ( & V_74 -> V_79 ) ;
} else {
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
V_74 = & V_40 -> V_41 [ -- ( * V_106 ) % V_40 -> V_42 ] ;
F_59 ( & V_74 -> V_79 ) ;
if ( ! F_48 ( & V_74 -> V_78 ) )
goto V_107;
F_61 ( & V_74 -> V_79 ) ;
}
return NULL ;
}
V_107:
if ( ! F_48 ( & V_74 -> V_78 ) ) {
struct V_88 * V_89 ;
V_89 = F_67 ( V_74 -> V_78 . V_108 , struct V_88 , V_100 ) ;
F_68 ( & V_89 -> V_100 ) ;
V_37 = V_89 -> V_109 ;
}
F_61 ( & V_74 -> V_79 ) ;
return V_37 ;
}
int
F_69 ( struct V_39 * V_40 , struct V_38 * V_74 , int V_110 )
{
struct V_88 * V_89 ;
struct V_36 * V_37 ;
struct V_38 * V_111 ;
int error = 0 ;
unsigned int V_106 = V_40 -> V_58 - 1 ;
int V_19 ;
if ( V_74 == NULL ) {
V_110 -= ( V_40 -> V_58 - 1 ) ;
} else {
F_59 ( & V_74 -> V_79 ) ;
V_110 -= V_74 -> V_99 ;
F_61 ( & V_74 -> V_79 ) ;
}
while ( V_110 > 0 ) {
V_110 -- ;
V_111 = F_65 ( V_40 , V_74 , & V_106 ) ;
V_19 = F_18 ( V_111 -> V_75 ) ;
V_89 = F_56 ( V_40 , V_111 , V_19 ) ;
if ( F_70 ( V_89 ) ) {
error = F_71 ( V_89 ) ;
break;
}
F_72 ( V_40 -> V_87 ) ;
V_37 = F_73 ( V_40 -> V_86 , V_89 ,
V_19 , V_40 -> V_56 ) ;
if ( F_70 ( V_37 ) ) {
error = F_71 ( V_37 ) ;
F_74 ( V_40 -> V_87 ) ;
F_63 ( V_89 ) ;
break;
}
V_89 -> V_109 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_20 ( V_37 , V_111 -> V_75 ) ;
F_45 ( V_40 ) ;
F_75 ( V_37 ) ;
}
while ( V_110 < 0 &&
( V_37 = F_66 ( V_40 , V_74 , & V_106 ) ) != NULL ) {
F_76 ( V_112 , V_37 , 1 ) ;
V_110 ++ ;
}
return error ;
}
void
F_63 ( struct V_88 * V_89 )
{
struct V_39 * V_40 = V_89 -> V_101 ;
struct V_38 * V_74 = V_89 -> V_102 ;
F_53 ( V_89 ) ;
F_10 ( V_89 -> V_105 ) ;
F_10 ( V_89 -> V_103 ) ;
F_10 ( V_89 -> V_113 ) ;
F_59 ( & V_74 -> V_79 ) ;
V_74 -> V_99 -- ;
F_77 ( & V_89 -> V_100 ) ;
F_61 ( & V_74 -> V_79 ) ;
F_10 ( V_89 ) ;
if ( V_40 )
F_44 ( V_40 ) ;
}
static int F_78 ( struct V_43 * V_43 , const T_2 V_114 ,
const T_2 V_115 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
const struct V_118 sin = {
. V_119 = V_120 ,
. V_121 . V_122 = F_79 ( V_123 ) ,
. V_124 = F_80 ( V_117 ) ,
} ;
const char * V_125 ;
int error ;
switch ( V_116 ) {
case V_126 :
V_125 = V_127 ;
break;
case V_128 :
V_125 = V_129 ;
break;
default:
return - V_130 ;
}
error = F_81 ( V_43 , V_114 , V_115 ,
( const struct V_131 * ) & sin , V_125 ) ;
if ( error == - V_132 )
error = F_82 ( V_43 , V_114 , V_115 , V_116 , V_117 ) ;
return error ;
}
static int F_83 ( struct V_43 * V_43 , const T_2 V_114 ,
const T_2 V_115 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
const struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 = V_138 ,
. V_139 = F_80 ( V_117 ) ,
} ;
const char * V_125 ;
int error ;
switch ( V_116 ) {
case V_126 :
V_125 = V_140 ;
break;
case V_128 :
V_125 = V_141 ;
break;
default:
return - V_130 ;
}
error = F_81 ( V_43 , V_114 , V_115 ,
( const struct V_131 * ) & V_134 , V_125 ) ;
if ( error == - V_132 )
error = - V_142 ;
return error ;
}
static int F_84 ( struct V_43 * V_43 , const char * V_143 ,
const T_2 V_114 , const T_2 V_115 ,
const int V_144 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
int error = - V_142 ;
switch ( V_144 ) {
case V_145 :
error = F_78 ( V_43 , V_114 , V_115 ,
V_116 , V_117 ) ;
break;
#if F_85 ( V_146 )
case V_147 :
error = F_83 ( V_43 , V_114 , V_115 ,
V_116 , V_117 ) ;
#endif
}
if ( error < 0 )
F_46 ( V_148 L_9
L_10 , V_143 , V_115 , - error ) ;
return error ;
}
int F_86 ( const struct V_39 * V_40 , struct V_43 * V_43 ,
const int V_144 , const unsigned short V_149 ,
const unsigned short V_117 )
{
struct V_44 * V_45 ;
unsigned int V_46 ;
int error = 0 ;
F_13 ( V_149 == 0 && V_117 == 0 ) ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
F_39 ( L_11 ,
V_45 -> V_57 ,
V_46 ,
V_149 == V_126 ? L_12 : L_13 ,
V_117 ,
V_144 ,
V_45 -> V_50 [ V_46 ] -> V_51 ?
L_14 : L_15 ) ;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
error = F_84 ( V_43 , V_45 -> V_57 , V_45 -> V_150 ,
V_46 , V_144 , V_149 , V_117 ) ;
if ( error < 0 )
break;
}
}
return error ;
}
static void F_87 ( struct V_43 * V_43 , const T_2 V_114 , const T_2 V_115 ,
const char * V_143 )
{
int error ;
error = F_81 ( V_43 , V_114 , V_115 , NULL , L_15 ) ;
if ( error == - V_132 )
error = F_82 ( V_43 , V_114 , V_115 , 0 , 0 ) ;
F_39 ( L_16 ,
V_151 , V_143 , V_115 , error ) ;
}
static void F_28 ( const struct V_39 * V_40 , struct V_43 * V_43 )
{
struct V_44 * V_45 ;
unsigned long V_152 ;
unsigned int V_46 ;
F_88 ( V_153 ) ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
F_39 ( L_17 ,
V_45 -> V_57 , V_46 ) ;
F_87 ( V_43 , V_45 -> V_150 , V_46 , V_45 -> V_57 ) ;
}
}
F_89 ( & V_80 -> V_154 -> V_155 , V_152 ) ;
F_90 () ;
F_91 ( & V_80 -> V_154 -> V_155 , V_152 ) ;
}
int
F_92 ( struct V_88 * V_89 , struct V_156 * V_157 , struct V_156 * V_158 )
{
struct V_44 * V_45 ;
struct V_159 * V_160 = NULL ;
struct V_161 * V_162 = NULL ;
struct V_39 * V_40 = V_89 -> V_101 ;
T_3 V_163 ;
T_4 * V_164 ;
T_2 V_52 , V_54 , V_165 ;
T_4 V_166 , V_167 ;
int V_168 ;
T_4 * V_169 ;
V_167 = V_170 ;
if ( V_157 -> V_171 < 6 * 4 )
goto V_172;
V_89 -> V_173 = 1 ;
V_89 -> V_174 = 1 ;
V_89 -> V_175 = false ;
V_89 -> V_176 -> V_177 -> V_178 ( V_89 ) ;
F_93 ( V_158 , V_89 -> V_179 ) ;
V_54 = F_94 ( V_157 ) ;
F_95 ( V_158 , 1 ) ;
if ( V_54 != 2 )
goto V_180;
V_169 = V_158 -> V_181 + V_158 -> V_171 ;
F_95 ( V_158 , 0 ) ;
V_89 -> V_182 = V_52 = F_94 ( V_157 ) ;
V_89 -> V_183 = V_54 = F_94 ( V_157 ) ;
V_89 -> V_184 = V_165 = F_94 ( V_157 ) ;
V_45 = V_40 -> V_47 ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 )
if ( V_52 == V_45 -> V_150 )
break;
V_168 = F_96 ( V_89 , & V_166 ) ;
if ( V_168 == V_185 && V_45 ) {
V_166 = V_186 ;
V_168 = V_45 -> V_187 ( V_89 ) ;
}
switch ( V_168 ) {
case V_185 :
break;
case V_188 :
goto V_189;
case V_190 :
V_167 = V_191 ;
goto V_192;
case V_193 :
goto V_194;
case V_195 :
if ( F_97 ( V_196 , & V_89 -> V_176 -> V_197 ) )
F_98 ( V_89 -> V_176 ) ;
case V_198 :
goto V_199;
case V_200 :
goto V_201;
}
if ( V_45 == NULL )
goto V_202;
if ( V_54 >= V_45 -> V_49 ||
! ( V_160 = V_45 -> V_50 [ V_54 ] ) )
goto V_203;
V_162 = V_160 -> V_204 + V_165 ;
if ( V_165 >= V_160 -> V_205 || ! V_162 -> V_206 )
goto V_207;
V_89 -> V_208 = V_162 ;
V_40 -> V_59 -> V_209 ++ ;
V_164 = V_158 -> V_181 + V_158 -> V_171 ;
F_95 ( V_158 , V_210 ) ;
V_162 -> V_211 ++ ;
memset ( V_89 -> V_103 , 0 , V_162 -> V_212 ) ;
memset ( V_89 -> V_105 , 0 , V_162 -> V_213 ) ;
if ( V_162 -> V_214 )
F_99 ( V_89 , V_162 -> V_214 << 2 ) ;
if ( ! V_160 -> V_215 ) {
V_163 = V_162 -> V_216 ;
if ( V_163 && ! V_163 ( V_89 , V_157 -> V_181 , V_89 -> V_103 ) )
goto V_189;
* V_164 = V_162 -> V_206 ( V_89 , V_89 -> V_103 , V_89 -> V_105 ) ;
if ( V_89 -> V_175 ) {
if ( V_162 -> V_217 )
V_162 -> V_217 ( V_89 , NULL , V_89 -> V_105 ) ;
goto V_199;
}
if ( * V_164 == V_170 &&
( V_163 = V_162 -> V_218 ) &&
! V_163 ( V_89 , V_158 -> V_181 + V_158 -> V_171 , V_89 -> V_105 ) ) {
F_39 ( L_18 ) ;
* V_164 = V_191 ;
}
} else {
F_39 ( L_19 ) ;
if ( ! V_160 -> V_215 ( V_89 , V_164 ) ) {
if ( V_162 -> V_217 )
V_162 -> V_217 ( V_89 , NULL , V_89 -> V_105 ) ;
goto V_199;
}
}
if ( * V_164 != V_170 )
V_158 -> V_171 = ( ( void * ) V_164 ) - V_158 -> V_181 + 4 ;
if ( V_162 -> V_217 )
V_162 -> V_217 ( V_89 , NULL , V_89 -> V_105 ) ;
if ( V_162 -> V_218 == NULL )
goto V_199;
V_201:
if ( F_100 ( V_89 ) )
goto V_199;
return 1 ;
V_199:
F_100 ( V_89 ) ;
F_39 ( L_20 ) ;
return 0 ;
V_172:
F_101 ( V_89 , L_21 ,
V_157 -> V_171 ) ;
goto V_199;
V_180:
V_40 -> V_59 -> V_219 ++ ;
F_95 ( V_158 , 1 ) ;
F_95 ( V_158 , 0 ) ;
F_95 ( V_158 , 2 ) ;
F_95 ( V_158 , 2 ) ;
goto V_201;
V_194:
F_39 ( L_22 , F_102 ( V_166 ) ) ;
V_40 -> V_59 -> V_220 ++ ;
F_103 ( V_89 , V_169 ) ;
F_95 ( V_158 , 1 ) ;
F_95 ( V_158 , 1 ) ;
F_95 ( V_158 , F_102 ( V_166 ) ) ;
goto V_201;
V_202:
F_39 ( L_23 , V_52 ) ;
V_40 -> V_59 -> V_219 ++ ;
F_95 ( V_158 , V_221 ) ;
goto V_201;
V_203:
F_101 ( V_89 , L_24 ,
V_54 , V_52 , V_45 -> V_57 ) ;
V_40 -> V_59 -> V_219 ++ ;
F_95 ( V_158 , V_222 ) ;
F_95 ( V_158 , V_45 -> V_66 ) ;
F_95 ( V_158 , V_45 -> V_67 ) ;
goto V_201;
V_207:
F_101 ( V_89 , L_25 , V_165 ) ;
V_40 -> V_59 -> V_219 ++ ;
F_95 ( V_158 , V_223 ) ;
goto V_201;
V_189:
F_101 ( V_89 , L_26 ) ;
V_167 = V_224 ;
V_192:
V_40 -> V_59 -> V_219 ++ ;
F_95 ( V_158 , F_102 ( V_167 ) ) ;
goto V_201;
}
int
F_104 ( struct V_88 * V_89 )
{
struct V_156 * V_157 = & V_89 -> V_225 . V_226 [ 0 ] ;
struct V_156 * V_158 = & V_89 -> V_227 . V_226 [ 0 ] ;
struct V_39 * V_40 = V_89 -> V_101 ;
T_2 V_228 ;
V_89 -> V_229 = 1 ;
V_158 -> V_181 = F_105 ( V_89 -> V_230 [ 0 ] ) ;
V_158 -> V_171 = 0 ;
V_89 -> V_227 . V_91 = V_89 -> V_230 + 1 ;
V_89 -> V_227 . V_231 = 0 ;
V_89 -> V_227 . V_232 = 0 ;
V_89 -> V_227 . V_233 = 0 ;
V_89 -> V_227 . V_234 = V_64 ;
V_89 -> V_227 . V_235 [ 0 ] . V_181 = NULL ;
V_89 -> V_227 . V_235 [ 0 ] . V_171 = 0 ;
V_89 -> V_179 = F_106 ( V_157 ) ;
V_228 = F_94 ( V_157 ) ;
if ( V_228 != 0 ) {
F_101 ( V_89 , L_27 , V_228 ) ;
V_40 -> V_59 -> V_219 ++ ;
F_107 ( V_89 ) ;
return 0 ;
}
if ( F_92 ( V_89 , V_157 , V_158 ) )
return F_108 ( V_89 ) ;
else {
F_107 ( V_89 ) ;
return 0 ;
}
}
int
F_109 ( struct V_39 * V_40 , struct V_236 * V_237 ,
struct V_88 * V_89 )
{
struct V_156 * V_157 = & V_89 -> V_225 . V_226 [ 0 ] ;
struct V_156 * V_158 = & V_89 -> V_227 . V_226 [ 0 ] ;
V_89 -> V_176 = V_40 -> V_238 ;
V_89 -> V_179 = V_237 -> V_179 ;
V_89 -> V_239 = V_237 -> V_176 -> V_240 ;
V_89 -> V_101 = V_40 ;
V_89 -> V_241 = sizeof( V_237 -> V_176 -> V_242 ) ;
memcpy ( & V_89 -> V_243 , & V_237 -> V_176 -> V_242 , V_89 -> V_241 ) ;
memcpy ( & V_89 -> V_225 , & V_237 -> V_244 , sizeof( V_89 -> V_225 ) ) ;
memcpy ( & V_89 -> V_227 , & V_237 -> V_245 , sizeof( V_89 -> V_227 ) ) ;
V_158 -> V_171 = 0 ;
if ( V_89 -> V_239 != V_128 ) {
F_46 ( V_246 L_28 ) ;
F_110 () ;
}
F_106 ( V_157 ) ;
F_94 ( V_157 ) ;
if ( F_92 ( V_89 , V_157 , V_158 ) ) {
memcpy ( & V_237 -> V_245 , & V_89 -> V_227 ,
sizeof( V_237 -> V_245 ) ) ;
return F_111 ( V_237 ) ;
} else {
return 0 ;
}
}
T_2 F_112 ( const struct V_88 * V_89 )
{
T_2 V_247 = V_89 -> V_176 -> V_248 -> V_249 ;
if ( V_89 -> V_101 -> V_62 < V_247 )
V_247 = V_89 -> V_101 -> V_62 ;
return V_247 ;
}
