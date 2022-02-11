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
F_13 ( V_30 >= V_22 ) ;
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
unsigned int
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
void
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
struct V_54 * V_55 )
{
struct V_39 * V_40 ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned int V_46 ;
if ( ! ( V_40 = F_35 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_58 = V_52 -> V_59 ;
V_40 -> V_47 = V_52 ;
V_40 -> V_60 = 1 ;
V_40 -> V_61 = V_52 -> V_62 ;
if ( V_53 > V_63 )
V_53 = V_63 ;
V_40 -> V_64 = V_53 ? V_53 : 4096 ;
V_40 -> V_65 = F_36 ( V_40 -> V_64 + V_66 , V_66 ) ;
V_40 -> V_67 = V_55 ;
V_57 = 0 ;
while ( V_52 ) {
V_52 -> V_68 = V_52 -> V_49 - 1 ;
for ( V_56 = 0 ; V_56 < V_52 -> V_49 ; V_56 ++ )
if ( V_52 -> V_50 [ V_56 ] ) {
V_52 -> V_69 = V_56 ;
if ( V_52 -> V_68 > V_56 )
V_52 -> V_68 = V_56 ;
if ( V_52 -> V_50 [ V_56 ] -> V_70 > V_57 )
V_57 = V_52 -> V_50 [ V_56 ] -> V_70 ;
}
V_52 = V_52 -> V_48 ;
}
V_40 -> V_71 = V_57 ;
F_37 ( & V_40 -> V_72 ) ;
F_37 ( & V_40 -> V_73 ) ;
F_38 ( & V_40 -> V_74 ) ;
F_39 ( & V_40 -> V_75 ) ;
V_40 -> V_42 = V_33 ;
V_40 -> V_41 =
F_9 ( V_40 -> V_42 , sizeof( struct V_38 ) ,
V_24 ) ;
if ( ! V_40 -> V_41 ) {
F_10 ( V_40 ) ;
return NULL ;
}
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
struct V_38 * V_76 = & V_40 -> V_41 [ V_46 ] ;
F_40 ( L_6 ,
V_46 , V_40 -> V_58 ) ;
V_76 -> V_77 = V_46 ;
F_37 ( & V_76 -> V_78 ) ;
F_37 ( & V_76 -> V_79 ) ;
F_39 ( & V_76 -> V_80 ) ;
}
return V_40 ;
}
struct V_39 *
F_41 ( struct V_44 * V_52 , unsigned int V_53 ,
struct V_54 * V_55 )
{
return F_34 ( V_52 , V_53 , 1 , V_55 ) ;
}
struct V_39 *
F_42 ( struct V_44 * V_52 , unsigned int V_53 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_34 ( V_52 , V_53 , V_33 , V_55 ) ;
if ( ! V_40 )
goto V_81;
return V_40 ;
V_81:
F_17 () ;
return NULL ;
}
void F_43 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_44 ( V_40 , V_43 ) ;
if ( V_40 -> V_67 -> V_82 )
V_40 -> V_67 -> V_82 ( V_40 , V_43 ) ;
}
void
F_45 ( struct V_39 * V_40 )
{
F_40 ( L_7 ,
V_40 -> V_47 -> V_59 ,
V_40 -> V_60 ) ;
if ( V_40 -> V_60 ) {
if ( -- ( V_40 -> V_60 ) != 0 ) {
F_46 ( V_40 ) ;
return;
}
} else
F_47 ( L_8 , V_40 ) ;
F_48 ( & V_40 -> V_74 ) ;
F_13 ( ! F_49 ( & V_40 -> V_73 ) ) ;
F_13 ( ! F_49 ( & V_40 -> V_72 ) ) ;
F_50 ( V_40 ) ;
if ( F_26 ( V_40 ) )
F_17 () ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_51 ( struct V_83 * V_84 , unsigned int V_85 , int V_19 )
{
unsigned int V_86 , V_87 ;
if ( F_52 ( V_84 ) )
return 1 ;
V_86 = V_85 / V_66 + 1 ;
V_87 = 0 ;
F_21 ( V_86 > V_88 ) ;
if ( V_86 > V_88 )
V_86 = V_88 ;
while ( V_86 ) {
struct V_89 * V_90 = F_53 ( V_19 , V_24 , 0 ) ;
if ( ! V_90 )
break;
V_84 -> V_91 [ V_87 ++ ] = V_90 ;
V_86 -- ;
}
return V_86 == 0 ;
}
static void
F_54 ( struct V_83 * V_84 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_55 ( V_84 -> V_91 ) ; V_46 ++ )
if ( V_84 -> V_91 [ V_46 ] )
F_56 ( V_84 -> V_91 [ V_46 ] ) ;
}
struct V_83 *
F_57 ( struct V_39 * V_40 , struct V_38 * V_76 , int V_19 )
{
struct V_83 * V_84 ;
V_84 = F_58 ( sizeof( * V_84 ) , V_24 , V_19 ) ;
if ( ! V_84 )
return V_84 ;
F_59 ( V_92 , & V_84 -> V_93 ) ;
F_39 ( & V_84 -> V_94 ) ;
V_84 -> V_95 = V_40 ;
V_84 -> V_96 = V_76 ;
V_84 -> V_97 = F_60 ( V_40 -> V_71 , V_24 , V_19 ) ;
if ( ! V_84 -> V_97 )
goto V_98;
V_84 -> V_99 = F_60 ( V_40 -> V_71 , V_24 , V_19 ) ;
if ( ! V_84 -> V_99 )
goto V_98;
if ( ! F_51 ( V_84 , V_40 -> V_65 , V_19 ) )
goto V_98;
return V_84 ;
V_98:
F_61 ( V_84 ) ;
return NULL ;
}
struct V_83 *
F_62 ( struct V_39 * V_40 , struct V_38 * V_76 , int V_19 )
{
struct V_83 * V_84 ;
V_84 = F_57 ( V_40 , V_76 , V_19 ) ;
if ( ! V_84 )
return F_63 ( - V_28 ) ;
V_40 -> V_60 ++ ;
F_64 ( & V_76 -> V_80 ) ;
V_76 -> V_100 ++ ;
F_65 ( & V_84 -> V_101 , & V_76 -> V_79 ) ;
F_66 ( & V_76 -> V_80 ) ;
return V_84 ;
}
static inline struct V_38 *
F_67 ( struct V_39 * V_40 , struct V_38 * V_76 , unsigned int * V_102 )
{
if ( V_76 != NULL )
return V_76 ;
return & V_40 -> V_41 [ ( * V_102 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_68 ( struct V_39 * V_40 , struct V_38 * V_76 , unsigned int * V_102 )
{
unsigned int V_46 ;
struct V_36 * V_37 = NULL ;
if ( V_76 != NULL ) {
F_64 ( & V_76 -> V_80 ) ;
} else {
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
V_76 = & V_40 -> V_41 [ -- ( * V_102 ) % V_40 -> V_42 ] ;
F_64 ( & V_76 -> V_80 ) ;
if ( ! F_49 ( & V_76 -> V_79 ) )
goto V_103;
F_66 ( & V_76 -> V_80 ) ;
}
return NULL ;
}
V_103:
if ( ! F_49 ( & V_76 -> V_79 ) ) {
struct V_83 * V_84 ;
V_84 = F_69 ( V_76 -> V_79 . V_104 , struct V_83 , V_101 ) ;
F_70 ( V_105 , & V_84 -> V_93 ) ;
F_71 ( & V_84 -> V_101 ) ;
V_37 = V_84 -> V_106 ;
}
F_66 ( & V_76 -> V_80 ) ;
return V_37 ;
}
int
F_72 ( struct V_39 * V_40 , struct V_38 * V_76 , int V_107 )
{
struct V_83 * V_84 ;
struct V_36 * V_37 ;
struct V_38 * V_108 ;
int error = 0 ;
unsigned int V_102 = V_40 -> V_60 - 1 ;
int V_19 ;
if ( V_76 == NULL ) {
V_107 -= ( V_40 -> V_60 - 1 ) ;
} else {
F_64 ( & V_76 -> V_80 ) ;
V_107 -= V_76 -> V_100 ;
F_66 ( & V_76 -> V_80 ) ;
}
while ( V_107 > 0 ) {
V_107 -- ;
V_108 = F_67 ( V_40 , V_76 , & V_102 ) ;
V_19 = F_18 ( V_108 -> V_77 ) ;
V_84 = F_62 ( V_40 , V_108 , V_19 ) ;
if ( F_73 ( V_84 ) ) {
error = F_74 ( V_84 ) ;
break;
}
F_75 ( V_40 -> V_67 -> V_109 ) ;
V_37 = F_76 ( V_40 -> V_67 -> V_110 , V_84 ,
V_19 , L_9 , V_40 -> V_58 ) ;
if ( F_73 ( V_37 ) ) {
error = F_74 ( V_37 ) ;
F_77 ( V_40 -> V_67 -> V_109 ) ;
F_78 ( V_84 ) ;
break;
}
V_84 -> V_106 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_20 ( V_37 , V_108 -> V_77 ) ;
F_46 ( V_40 ) ;
F_79 ( V_37 ) ;
}
while ( V_107 < 0 &&
( V_37 = F_68 ( V_40 , V_76 , & V_102 ) ) != NULL ) {
F_80 ( V_111 , V_37 , 1 ) ;
V_107 ++ ;
}
return error ;
}
void
F_61 ( struct V_83 * V_84 )
{
F_54 ( V_84 ) ;
F_10 ( V_84 -> V_99 ) ;
F_10 ( V_84 -> V_97 ) ;
F_10 ( V_84 -> V_112 ) ;
F_81 ( V_84 , V_113 ) ;
}
void
F_78 ( struct V_83 * V_84 )
{
struct V_39 * V_40 = V_84 -> V_95 ;
struct V_38 * V_76 = V_84 -> V_96 ;
F_64 ( & V_76 -> V_80 ) ;
V_76 -> V_100 -- ;
if ( ! F_82 ( V_105 , & V_84 -> V_93 ) )
F_71 ( & V_84 -> V_101 ) ;
F_66 ( & V_76 -> V_80 ) ;
F_61 ( V_84 ) ;
if ( V_40 )
F_45 ( V_40 ) ;
}
static int F_83 ( struct V_43 * V_43 , const T_1 V_114 ,
const T_1 V_115 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
const struct V_118 sin = {
. V_119 = V_120 ,
. V_121 . V_122 = F_84 ( V_123 ) ,
. V_124 = F_85 ( V_117 ) ,
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
error = F_86 ( V_43 , V_114 , V_115 ,
( const struct V_131 * ) & sin , V_125 ) ;
if ( error == - V_132 )
error = F_87 ( V_43 , V_114 , V_115 , V_116 , V_117 ) ;
return error ;
}
static int F_88 ( struct V_43 * V_43 , const T_1 V_114 ,
const T_1 V_115 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
const struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 = V_138 ,
. V_139 = F_85 ( V_117 ) ,
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
error = F_86 ( V_43 , V_114 , V_115 ,
( const struct V_131 * ) & V_134 , V_125 ) ;
if ( error == - V_132 )
error = - V_142 ;
return error ;
}
static int F_89 ( struct V_43 * V_43 , const char * V_143 ,
const T_1 V_114 , const T_1 V_115 ,
const int V_144 ,
const unsigned short V_116 ,
const unsigned short V_117 )
{
int error = - V_142 ;
switch ( V_144 ) {
case V_145 :
error = F_83 ( V_43 , V_114 , V_115 ,
V_116 , V_117 ) ;
break;
#if F_90 ( V_146 )
case V_147 :
error = F_88 ( V_43 , V_114 , V_115 ,
V_116 , V_117 ) ;
#endif
}
return error ;
}
int F_91 ( const struct V_39 * V_40 , struct V_43 * V_43 ,
const int V_144 , const unsigned short V_148 ,
const unsigned short V_117 )
{
struct V_44 * V_45 ;
struct V_149 * V_56 ;
unsigned int V_46 ;
int error = 0 ;
F_21 ( V_148 == 0 && V_117 == 0 ) ;
if ( V_148 == 0 && V_117 == 0 )
return - V_17 ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
V_56 = V_45 -> V_50 [ V_46 ] ;
if ( V_56 == NULL )
continue;
F_40 ( L_10 ,
V_45 -> V_59 ,
V_46 ,
V_148 == V_126 ? L_11 : L_12 ,
V_117 ,
V_144 ,
V_56 -> V_51 ?
L_13 : L_14 ) ;
if ( V_56 -> V_51 )
continue;
error = F_89 ( V_43 , V_45 -> V_59 , V_45 -> V_150 ,
V_46 , V_144 , V_148 , V_117 ) ;
if ( V_56 -> V_151 ) {
error = 0 ;
continue;
}
if ( error < 0 ) {
F_47 ( V_152 L_15
L_16 ,
V_45 -> V_59 , V_46 , - error ) ;
break;
}
}
}
return error ;
}
static void F_92 ( struct V_43 * V_43 , const T_1 V_114 , const T_1 V_115 ,
const char * V_143 )
{
int error ;
error = F_86 ( V_43 , V_114 , V_115 , NULL , L_14 ) ;
if ( error == - V_132 )
error = F_87 ( V_43 , V_114 , V_115 , 0 , 0 ) ;
F_40 ( L_17 ,
V_153 , V_143 , V_115 , error ) ;
}
static void F_29 ( const struct V_39 * V_40 , struct V_43 * V_43 )
{
struct V_44 * V_45 ;
unsigned long V_154 ;
unsigned int V_46 ;
F_93 ( V_155 ) ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
F_40 ( L_18 ,
V_45 -> V_59 , V_46 ) ;
F_92 ( V_43 , V_45 -> V_150 , V_46 , V_45 -> V_59 ) ;
}
}
F_94 ( & V_156 -> V_157 -> V_158 , V_154 ) ;
F_95 () ;
F_96 ( & V_156 -> V_157 -> V_158 , V_154 ) ;
}
int
F_97 ( struct V_39 * V_40 , struct V_159 * V_160 ,
struct V_83 * V_84 )
{
struct V_161 * V_162 = & V_84 -> V_163 . V_164 [ 0 ] ;
struct V_161 * V_165 = & V_84 -> V_166 . V_164 [ 0 ] ;
struct V_167 * V_37 ;
int V_168 ;
int error ;
F_40 ( L_19 , V_153 , V_160 ) ;
V_84 -> V_169 = V_40 -> V_170 ;
V_84 -> V_171 = V_160 -> V_171 ;
V_84 -> V_172 = V_160 -> V_169 -> V_173 ;
V_84 -> V_95 = V_40 ;
V_84 -> V_174 = sizeof( V_160 -> V_169 -> V_175 ) ;
memcpy ( & V_84 -> V_176 , & V_160 -> V_169 -> V_175 , V_84 -> V_174 ) ;
memcpy ( & V_84 -> V_163 , & V_160 -> V_177 , sizeof( V_84 -> V_163 ) ) ;
memcpy ( & V_84 -> V_166 , & V_160 -> V_178 , sizeof( V_84 -> V_166 ) ) ;
V_84 -> V_163 . V_179 = V_160 -> V_180 . V_179 ;
if ( V_84 -> V_163 . V_179 <= V_84 -> V_163 . V_164 [ 0 ] . V_181 ) {
V_84 -> V_163 . V_164 [ 0 ] . V_181 = V_84 -> V_163 . V_179 ;
V_84 -> V_163 . V_182 = 0 ;
} else if ( V_84 -> V_163 . V_179 <= V_84 -> V_163 . V_164 [ 0 ] . V_181 +
V_84 -> V_163 . V_182 )
V_84 -> V_163 . V_182 = V_84 -> V_163 . V_179 -
V_84 -> V_163 . V_164 [ 0 ] . V_181 ;
else
V_84 -> V_163 . V_179 = V_84 -> V_163 . V_164 [ 0 ] . V_181 +
V_84 -> V_163 . V_182 ;
V_165 -> V_181 = 0 ;
F_98 ( V_162 ) ;
F_99 ( V_162 ) ;
V_168 = F_100 ( V_84 , V_162 , V_165 ) ;
F_101 ( & V_160 -> V_169 -> V_183 ) ;
if ( ! V_168 ) {
F_102 ( V_160 ) ;
return 0 ;
}
memcpy ( & V_160 -> V_178 , & V_84 -> V_166 , sizeof( V_160 -> V_178 ) ) ;
V_37 = F_103 ( V_160 ) ;
if ( F_73 ( V_37 ) ) {
error = F_74 ( V_37 ) ;
goto V_12;
}
F_21 ( F_104 ( & V_37 -> V_184 ) != 1 ) ;
error = V_37 -> V_185 ;
F_105 ( V_37 ) ;
V_12:
F_40 ( L_20 , V_153 , error ) ;
return error ;
}
T_1 F_106 ( const struct V_83 * V_84 )
{
T_1 V_186 = V_84 -> V_169 -> V_187 -> V_188 ;
if ( V_84 -> V_95 -> V_64 < V_186 )
V_186 = V_84 -> V_95 -> V_64 ;
return V_186 ;
}
