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
F_21 ( V_7 -> V_11 == 0 ) ;
if ( V_7 -> V_11 == 0 )
return;
switch ( V_7 -> V_34 ) {
case V_15 :
{
F_22 ( V_37 , F_23 ( V_19 ) ) ;
break;
}
case V_16 :
{
F_22 ( V_37 , F_24 ( V_19 ) ) ;
break;
}
}
}
struct V_38 *
F_25 ( struct V_39 * V_40 , int V_31 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_30 = 0 ;
if ( F_26 ( V_40 ) ) {
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
int F_27 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
int V_8 ;
V_8 = F_28 ( V_43 ) ;
if ( V_8 )
return V_8 ;
F_29 ( V_40 , V_43 ) ;
return 0 ;
}
void F_30 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_29 ( V_40 , V_43 ) ;
F_31 ( V_43 ) ;
}
static int F_32 ( struct V_39 * V_40 )
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
int F_33 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
if ( ! F_32 ( V_40 ) )
return 0 ;
return F_27 ( V_40 , V_43 ) ;
}
static struct V_39 *
F_34 ( struct V_44 * V_52 , unsigned int V_53 , int V_33 ,
void (* F_35)( struct V_39 * V_40 , struct V_43 * V_43 ) )
{
struct V_39 * V_40 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_46 ;
if ( ! ( V_40 = F_36 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_56 = V_52 -> V_57 ;
V_40 -> V_47 = V_52 ;
V_40 -> V_58 = 1 ;
V_40 -> V_59 = V_52 -> V_60 ;
if ( V_53 > V_61 )
V_53 = V_61 ;
V_40 -> V_62 = V_53 ? V_53 : 4096 ;
V_40 -> V_63 = F_37 ( V_40 -> V_62 + V_64 , V_64 ) ;
V_40 -> V_65 = F_35 ;
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
F_38 ( & V_40 -> V_70 ) ;
F_38 ( & V_40 -> V_71 ) ;
F_39 ( & V_40 -> V_72 ) ;
F_40 ( & V_40 -> V_73 ) ;
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
F_41 ( L_6 ,
V_46 , V_40 -> V_56 ) ;
V_74 -> V_75 = V_46 ;
F_38 ( & V_74 -> V_76 ) ;
F_38 ( & V_74 -> V_77 ) ;
F_38 ( & V_74 -> V_78 ) ;
F_40 ( & V_74 -> V_79 ) ;
}
if ( F_32 ( V_40 ) && ( ! V_40 -> V_65 ) )
V_40 -> V_65 = F_30 ;
return V_40 ;
}
struct V_39 *
F_42 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_35)( struct V_39 * V_40 , struct V_43 * V_43 ) )
{
return F_34 ( V_52 , V_53 , 1 , F_35 ) ;
}
struct V_39 *
F_43 ( struct V_44 * V_52 , unsigned int V_53 ,
void (* F_35)( struct V_39 * V_40 , struct V_43 * V_43 ) ,
T_1 V_80 , struct V_81 * V_82 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_34 ( V_52 , V_53 , V_33 , F_35 ) ;
if ( V_40 != NULL ) {
V_40 -> V_83 = V_80 ;
V_40 -> V_84 = V_82 ;
}
return V_40 ;
}
void F_44 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_45 ( V_40 , V_43 ) ;
if ( V_40 -> V_65 )
V_40 -> V_65 ( V_40 , V_43 ) ;
}
void
F_46 ( struct V_39 * V_40 )
{
F_41 ( L_7 ,
V_40 -> V_47 -> V_57 ,
V_40 -> V_58 ) ;
if ( V_40 -> V_58 ) {
if ( -- ( V_40 -> V_58 ) != 0 ) {
F_47 ( V_40 ) ;
return;
}
} else
F_48 ( L_8 , V_40 ) ;
F_49 ( & V_40 -> V_72 ) ;
F_13 ( ! F_50 ( & V_40 -> V_71 ) ) ;
F_13 ( ! F_50 ( & V_40 -> V_70 ) ) ;
F_51 ( V_40 ) ;
if ( F_26 ( V_40 ) )
F_17 () ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_52 ( struct V_85 * V_86 , unsigned int V_87 , int V_19 )
{
unsigned int V_88 , V_89 ;
if ( F_53 ( V_86 ) )
return 1 ;
V_88 = V_87 / V_64 + 1 ;
V_89 = 0 ;
F_21 ( V_88 > V_90 ) ;
if ( V_88 > V_90 )
V_88 = V_90 ;
while ( V_88 ) {
struct V_91 * V_92 = F_54 ( V_19 , V_24 , 0 ) ;
if ( ! V_92 )
break;
V_86 -> V_93 [ V_89 ++ ] = V_92 ;
V_88 -- ;
}
return V_88 == 0 ;
}
static void
F_55 ( struct V_85 * V_86 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_56 ( V_86 -> V_93 ) ; V_46 ++ )
if ( V_86 -> V_93 [ V_46 ] )
F_57 ( V_86 -> V_93 [ V_46 ] ) ;
}
struct V_85 *
F_58 ( struct V_39 * V_40 , struct V_38 * V_74 , int V_19 )
{
struct V_85 * V_86 ;
V_86 = F_59 ( sizeof( * V_86 ) , V_24 , V_19 ) ;
if ( ! V_86 )
goto V_94;
V_40 -> V_58 ++ ;
F_60 ( & V_74 -> V_79 ) ;
V_74 -> V_95 ++ ;
F_61 ( & V_86 -> V_96 , & V_74 -> V_78 ) ;
F_62 ( & V_74 -> V_79 ) ;
V_86 -> V_97 = V_40 ;
V_86 -> V_98 = V_74 ;
V_86 -> V_99 = F_63 ( V_40 -> V_69 , V_24 , V_19 ) ;
if ( ! V_86 -> V_99 )
goto V_100;
V_86 -> V_101 = F_63 ( V_40 -> V_69 , V_24 , V_19 ) ;
if ( ! V_86 -> V_101 )
goto V_100;
if ( ! F_52 ( V_86 , V_40 -> V_63 , V_19 ) )
goto V_100;
return V_86 ;
V_100:
F_64 ( V_86 ) ;
V_94:
return F_65 ( - V_28 ) ;
}
static inline struct V_38 *
F_66 ( struct V_39 * V_40 , struct V_38 * V_74 , unsigned int * V_102 )
{
if ( V_74 != NULL )
return V_74 ;
return & V_40 -> V_41 [ ( * V_102 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_67 ( struct V_39 * V_40 , struct V_38 * V_74 , unsigned int * V_102 )
{
unsigned int V_46 ;
struct V_36 * V_37 = NULL ;
if ( V_74 != NULL ) {
F_60 ( & V_74 -> V_79 ) ;
} else {
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
V_74 = & V_40 -> V_41 [ -- ( * V_102 ) % V_40 -> V_42 ] ;
F_60 ( & V_74 -> V_79 ) ;
if ( ! F_50 ( & V_74 -> V_78 ) )
goto V_103;
F_62 ( & V_74 -> V_79 ) ;
}
return NULL ;
}
V_103:
if ( ! F_50 ( & V_74 -> V_78 ) ) {
struct V_85 * V_86 ;
V_86 = F_68 ( V_74 -> V_78 . V_104 , struct V_85 , V_96 ) ;
F_69 ( & V_86 -> V_96 ) ;
V_37 = V_86 -> V_105 ;
}
F_62 ( & V_74 -> V_79 ) ;
return V_37 ;
}
int
F_70 ( struct V_39 * V_40 , struct V_38 * V_74 , int V_106 )
{
struct V_85 * V_86 ;
struct V_36 * V_37 ;
struct V_38 * V_107 ;
int error = 0 ;
unsigned int V_102 = V_40 -> V_58 - 1 ;
int V_19 ;
if ( V_74 == NULL ) {
V_106 -= ( V_40 -> V_58 - 1 ) ;
} else {
F_60 ( & V_74 -> V_79 ) ;
V_106 -= V_74 -> V_95 ;
F_62 ( & V_74 -> V_79 ) ;
}
while ( V_106 > 0 ) {
V_106 -- ;
V_107 = F_66 ( V_40 , V_74 , & V_102 ) ;
V_19 = F_18 ( V_107 -> V_75 ) ;
V_86 = F_58 ( V_40 , V_107 , V_19 ) ;
if ( F_71 ( V_86 ) ) {
error = F_72 ( V_86 ) ;
break;
}
F_73 ( V_40 -> V_84 ) ;
V_37 = F_74 ( V_40 -> V_83 , V_86 ,
V_19 , L_9 , V_40 -> V_56 ) ;
if ( F_71 ( V_37 ) ) {
error = F_72 ( V_37 ) ;
F_75 ( V_40 -> V_84 ) ;
F_64 ( V_86 ) ;
break;
}
V_86 -> V_105 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_20 ( V_37 , V_107 -> V_75 ) ;
F_47 ( V_40 ) ;
F_76 ( V_37 ) ;
}
while ( V_106 < 0 &&
( V_37 = F_67 ( V_40 , V_74 , & V_102 ) ) != NULL ) {
F_77 ( V_108 , V_37 , 1 ) ;
V_106 ++ ;
}
return error ;
}
void
F_64 ( struct V_85 * V_86 )
{
struct V_39 * V_40 = V_86 -> V_97 ;
struct V_38 * V_74 = V_86 -> V_98 ;
F_55 ( V_86 ) ;
F_10 ( V_86 -> V_101 ) ;
F_10 ( V_86 -> V_99 ) ;
F_10 ( V_86 -> V_109 ) ;
F_60 ( & V_74 -> V_79 ) ;
V_74 -> V_95 -- ;
F_78 ( & V_86 -> V_96 ) ;
F_62 ( & V_74 -> V_79 ) ;
F_10 ( V_86 ) ;
if ( V_40 )
F_46 ( V_40 ) ;
}
static int F_79 ( struct V_43 * V_43 , const T_2 V_110 ,
const T_2 V_111 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
const struct V_114 sin = {
. V_115 = V_116 ,
. V_117 . V_118 = F_80 ( V_119 ) ,
. V_120 = F_81 ( V_113 ) ,
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
error = F_82 ( V_43 , V_110 , V_111 ,
( const struct V_127 * ) & sin , V_121 ) ;
if ( error == - V_128 )
error = F_83 ( V_43 , V_110 , V_111 , V_112 , V_113 ) ;
return error ;
}
static int F_84 ( struct V_43 * V_43 , const T_2 V_110 ,
const T_2 V_111 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
const struct V_129 V_130 = {
. V_131 = V_132 ,
. V_133 = V_134 ,
. V_135 = F_81 ( V_113 ) ,
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
error = F_82 ( V_43 , V_110 , V_111 ,
( const struct V_127 * ) & V_130 , V_121 ) ;
if ( error == - V_128 )
error = - V_138 ;
return error ;
}
static int F_85 ( struct V_43 * V_43 , const char * V_139 ,
const T_2 V_110 , const T_2 V_111 ,
const int V_140 ,
const unsigned short V_112 ,
const unsigned short V_113 )
{
int error = - V_138 ;
switch ( V_140 ) {
case V_141 :
error = F_79 ( V_43 , V_110 , V_111 ,
V_112 , V_113 ) ;
break;
#if F_86 ( V_142 )
case V_143 :
error = F_84 ( V_43 , V_110 , V_111 ,
V_112 , V_113 ) ;
#endif
}
return error ;
}
int F_87 ( const struct V_39 * V_40 , struct V_43 * V_43 ,
const int V_140 , const unsigned short V_144 ,
const unsigned short V_113 )
{
struct V_44 * V_45 ;
struct V_145 * V_54 ;
unsigned int V_46 ;
int error = 0 ;
F_21 ( V_144 == 0 && V_113 == 0 ) ;
if ( V_144 == 0 && V_113 == 0 )
return - V_17 ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
V_54 = V_45 -> V_50 [ V_46 ] ;
if ( V_54 == NULL )
continue;
F_41 ( L_10 ,
V_45 -> V_57 ,
V_46 ,
V_144 == V_122 ? L_11 : L_12 ,
V_113 ,
V_140 ,
V_54 -> V_51 ?
L_13 : L_14 ) ;
if ( V_54 -> V_51 )
continue;
error = F_85 ( V_43 , V_45 -> V_57 , V_45 -> V_146 ,
V_46 , V_140 , V_144 , V_113 ) ;
if ( V_54 -> V_147 ) {
error = 0 ;
continue;
}
if ( error < 0 ) {
F_48 ( V_148 L_15
L_16 ,
V_45 -> V_57 , V_46 , - error ) ;
break;
}
}
}
return error ;
}
static void F_88 ( struct V_43 * V_43 , const T_2 V_110 , const T_2 V_111 ,
const char * V_139 )
{
int error ;
error = F_82 ( V_43 , V_110 , V_111 , NULL , L_14 ) ;
if ( error == - V_128 )
error = F_83 ( V_43 , V_110 , V_111 , 0 , 0 ) ;
F_41 ( L_17 ,
V_149 , V_139 , V_111 , error ) ;
}
static void F_29 ( const struct V_39 * V_40 , struct V_43 * V_43 )
{
struct V_44 * V_45 ;
unsigned long V_150 ;
unsigned int V_46 ;
F_89 ( V_151 ) ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
F_41 ( L_18 ,
V_45 -> V_57 , V_46 ) ;
F_88 ( V_43 , V_45 -> V_146 , V_46 , V_45 -> V_57 ) ;
}
}
F_90 ( & V_152 -> V_153 -> V_154 , V_150 ) ;
F_91 () ;
F_92 ( & V_152 -> V_153 -> V_154 , V_150 ) ;
}
int
F_93 ( struct V_85 * V_86 )
{
struct V_155 * V_156 = & V_86 -> V_157 . V_158 [ 0 ] ;
struct V_155 * V_159 = & V_86 -> V_160 . V_158 [ 0 ] ;
struct V_39 * V_40 = V_86 -> V_97 ;
T_2 V_161 ;
V_86 -> V_162 = & V_86 -> V_163 [ 1 ] ;
V_159 -> V_164 = F_94 ( V_86 -> V_163 [ 0 ] ) ;
V_159 -> V_165 = 0 ;
V_86 -> V_160 . V_88 = V_86 -> V_163 + 1 ;
V_86 -> V_160 . V_166 = 0 ;
V_86 -> V_160 . V_167 = 0 ;
V_86 -> V_160 . V_168 = 0 ;
V_86 -> V_160 . V_169 = V_64 ;
V_86 -> V_160 . V_170 [ 0 ] . V_164 = NULL ;
V_86 -> V_160 . V_170 [ 0 ] . V_165 = 0 ;
V_86 -> V_171 = F_95 ( V_156 ) ;
V_161 = F_96 ( V_156 ) ;
if ( V_161 != 0 ) {
F_97 ( V_86 , L_19 , V_161 ) ;
V_40 -> V_59 -> V_172 ++ ;
F_98 ( V_86 ) ;
return 0 ;
}
if ( F_99 ( V_86 , V_156 , V_159 ) )
return F_100 ( V_86 ) ;
else {
F_98 ( V_86 ) ;
return 0 ;
}
}
int
F_101 ( struct V_39 * V_40 , struct V_173 * V_174 ,
struct V_85 * V_86 )
{
struct V_155 * V_156 = & V_86 -> V_157 . V_158 [ 0 ] ;
struct V_155 * V_159 = & V_86 -> V_160 . V_158 [ 0 ] ;
V_86 -> V_175 = V_40 -> V_176 ;
V_86 -> V_171 = V_174 -> V_171 ;
V_86 -> V_177 = V_174 -> V_175 -> V_178 ;
V_86 -> V_97 = V_40 ;
V_86 -> V_179 = sizeof( V_174 -> V_175 -> V_180 ) ;
memcpy ( & V_86 -> V_181 , & V_174 -> V_175 -> V_180 , V_86 -> V_179 ) ;
memcpy ( & V_86 -> V_157 , & V_174 -> V_182 , sizeof( V_86 -> V_157 ) ) ;
memcpy ( & V_86 -> V_160 , & V_174 -> V_183 , sizeof( V_86 -> V_160 ) ) ;
V_159 -> V_165 = 0 ;
if ( V_86 -> V_177 != V_124 ) {
F_48 ( V_184 L_20 ) ;
F_102 () ;
}
F_95 ( V_156 ) ;
F_96 ( V_156 ) ;
if ( F_99 ( V_86 , V_156 , V_159 ) ) {
memcpy ( & V_174 -> V_183 , & V_86 -> V_160 ,
sizeof( V_174 -> V_183 ) ) ;
return F_103 ( V_174 ) ;
} else {
F_104 ( V_174 ) ;
return 0 ;
}
}
T_2 F_105 ( const struct V_85 * V_86 )
{
T_2 V_185 = V_86 -> V_175 -> V_186 -> V_187 ;
if ( V_86 -> V_97 -> V_62 < V_185 )
V_185 = V_86 -> V_97 -> V_62 ;
return V_185 ;
}
