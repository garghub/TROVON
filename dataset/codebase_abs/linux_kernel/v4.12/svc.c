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
if ( ! V_45 -> V_50 [ V_46 ] -> V_51 )
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
static void
F_34 ( struct V_39 * V_40 )
{
F_35 ( & V_40 -> V_52 ) ;
F_36 ( & V_40 -> V_53 ) ;
F_37 ( & V_40 -> V_54 ) ;
}
static void
F_34 ( struct V_39 * V_40 )
{
}
static struct V_39 *
F_38 ( struct V_44 * V_55 , unsigned int V_56 , int V_33 ,
struct V_57 * V_58 )
{
struct V_39 * V_40 ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_46 ;
if ( ! ( V_40 = F_39 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_61 = V_55 -> V_62 ;
V_40 -> V_47 = V_55 ;
V_40 -> V_63 = 1 ;
V_40 -> V_64 = V_55 -> V_65 ;
if ( V_56 > V_66 )
V_56 = V_66 ;
V_40 -> V_67 = V_56 ? V_56 : 4096 ;
V_40 -> V_68 = F_40 ( V_40 -> V_67 + V_69 , V_69 ) ;
V_40 -> V_70 = V_58 ;
V_60 = 0 ;
while ( V_55 ) {
V_55 -> V_71 = V_55 -> V_49 - 1 ;
for ( V_59 = 0 ; V_59 < V_55 -> V_49 ; V_59 ++ )
if ( V_55 -> V_50 [ V_59 ] ) {
V_55 -> V_72 = V_59 ;
if ( V_55 -> V_71 > V_59 )
V_55 -> V_71 = V_59 ;
if ( V_55 -> V_50 [ V_59 ] -> V_73 > V_60 )
V_60 = V_55 -> V_50 [ V_59 ] -> V_73 ;
}
V_55 = V_55 -> V_48 ;
}
V_40 -> V_74 = V_60 ;
F_35 ( & V_40 -> V_75 ) ;
F_35 ( & V_40 -> V_76 ) ;
F_41 ( & V_40 -> V_77 ) ;
F_36 ( & V_40 -> V_78 ) ;
F_34 ( V_40 ) ;
V_40 -> V_42 = V_33 ;
V_40 -> V_41 =
F_9 ( V_40 -> V_42 , sizeof( struct V_38 ) ,
V_24 ) ;
if ( ! V_40 -> V_41 ) {
F_10 ( V_40 ) ;
return NULL ;
}
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
struct V_38 * V_79 = & V_40 -> V_41 [ V_46 ] ;
F_42 ( L_6 ,
V_46 , V_40 -> V_61 ) ;
V_79 -> V_80 = V_46 ;
F_35 ( & V_79 -> V_81 ) ;
F_35 ( & V_79 -> V_82 ) ;
F_36 ( & V_79 -> V_83 ) ;
}
return V_40 ;
}
struct V_39 *
F_43 ( struct V_44 * V_55 , unsigned int V_56 ,
struct V_57 * V_58 )
{
return F_38 ( V_55 , V_56 , 1 , V_58 ) ;
}
struct V_39 *
F_44 ( struct V_44 * V_55 , unsigned int V_56 ,
struct V_57 * V_58 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_38 ( V_55 , V_56 , V_33 , V_58 ) ;
if ( ! V_40 )
goto V_84;
return V_40 ;
V_84:
F_17 () ;
return NULL ;
}
void F_45 ( struct V_39 * V_40 , struct V_43 * V_43 )
{
F_46 ( V_40 , V_43 ) ;
if ( V_40 -> V_70 -> V_85 )
V_40 -> V_70 -> V_85 ( V_40 , V_43 ) ;
}
void
F_47 ( struct V_39 * V_40 )
{
F_42 ( L_7 ,
V_40 -> V_47 -> V_62 ,
V_40 -> V_63 ) ;
if ( V_40 -> V_63 ) {
if ( -- ( V_40 -> V_63 ) != 0 ) {
F_48 ( V_40 ) ;
return;
}
} else
F_49 ( L_8 , V_40 ) ;
F_50 ( & V_40 -> V_77 ) ;
F_13 ( ! F_51 ( & V_40 -> V_76 ) ) ;
F_13 ( ! F_51 ( & V_40 -> V_75 ) ) ;
F_52 ( V_40 ) ;
if ( F_26 ( V_40 ) )
F_17 () ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_53 ( struct V_86 * V_87 , unsigned int V_88 , int V_19 )
{
unsigned int V_89 , V_90 ;
if ( F_54 ( V_87 ) )
return 1 ;
V_89 = V_88 / V_69 + 1 ;
V_90 = 0 ;
F_21 ( V_89 > V_91 ) ;
if ( V_89 > V_91 )
V_89 = V_91 ;
while ( V_89 ) {
struct V_92 * V_93 = F_55 ( V_19 , V_24 , 0 ) ;
if ( ! V_93 )
break;
V_87 -> V_94 [ V_90 ++ ] = V_93 ;
V_89 -- ;
}
return V_89 == 0 ;
}
static void
F_56 ( struct V_86 * V_87 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_57 ( V_87 -> V_94 ) ; V_46 ++ )
if ( V_87 -> V_94 [ V_46 ] )
F_58 ( V_87 -> V_94 [ V_46 ] ) ;
}
struct V_86 *
F_59 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_19 )
{
struct V_86 * V_87 ;
V_87 = F_60 ( sizeof( * V_87 ) , V_24 , V_19 ) ;
if ( ! V_87 )
return V_87 ;
F_61 ( V_95 , & V_87 -> V_96 ) ;
F_36 ( & V_87 -> V_97 ) ;
V_87 -> V_98 = V_40 ;
V_87 -> V_99 = V_79 ;
V_87 -> V_100 = F_62 ( V_40 -> V_74 , V_24 , V_19 ) ;
if ( ! V_87 -> V_100 )
goto V_101;
V_87 -> V_102 = F_62 ( V_40 -> V_74 , V_24 , V_19 ) ;
if ( ! V_87 -> V_102 )
goto V_101;
if ( ! F_53 ( V_87 , V_40 -> V_68 , V_19 ) )
goto V_101;
return V_87 ;
V_101:
F_63 ( V_87 ) ;
return NULL ;
}
struct V_86 *
F_64 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_19 )
{
struct V_86 * V_87 ;
V_87 = F_59 ( V_40 , V_79 , V_19 ) ;
if ( ! V_87 )
return F_65 ( - V_28 ) ;
V_40 -> V_63 ++ ;
F_66 ( & V_79 -> V_83 ) ;
V_79 -> V_103 ++ ;
F_67 ( & V_87 -> V_104 , & V_79 -> V_82 ) ;
F_68 ( & V_79 -> V_83 ) ;
return V_87 ;
}
static inline struct V_38 *
F_69 ( struct V_39 * V_40 , struct V_38 * V_79 , unsigned int * V_105 )
{
if ( V_79 != NULL )
return V_79 ;
return & V_40 -> V_41 [ ( * V_105 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_70 ( struct V_39 * V_40 , struct V_38 * V_79 , unsigned int * V_105 )
{
unsigned int V_46 ;
struct V_36 * V_37 = NULL ;
if ( V_79 != NULL ) {
F_66 ( & V_79 -> V_83 ) ;
} else {
for ( V_46 = 0 ; V_46 < V_40 -> V_42 ; V_46 ++ ) {
V_79 = & V_40 -> V_41 [ -- ( * V_105 ) % V_40 -> V_42 ] ;
F_66 ( & V_79 -> V_83 ) ;
if ( ! F_51 ( & V_79 -> V_82 ) )
goto V_106;
F_68 ( & V_79 -> V_83 ) ;
}
return NULL ;
}
V_106:
if ( ! F_51 ( & V_79 -> V_82 ) ) {
struct V_86 * V_87 ;
V_87 = F_71 ( V_79 -> V_82 . V_107 , struct V_86 , V_104 ) ;
F_72 ( V_108 , & V_87 -> V_96 ) ;
F_73 ( & V_87 -> V_104 ) ;
V_37 = V_87 -> V_109 ;
}
F_68 ( & V_79 -> V_83 ) ;
return V_37 ;
}
static int
F_74 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_110 )
{
struct V_86 * V_87 ;
struct V_36 * V_37 ;
struct V_38 * V_111 ;
unsigned int V_105 = V_40 -> V_63 - 1 ;
int V_19 ;
do {
V_110 -- ;
V_111 = F_69 ( V_40 , V_79 , & V_105 ) ;
V_19 = F_18 ( V_111 -> V_80 ) ;
V_87 = F_64 ( V_40 , V_111 , V_19 ) ;
if ( F_75 ( V_87 ) )
return F_76 ( V_87 ) ;
F_77 ( V_40 -> V_70 -> V_112 ) ;
V_37 = F_78 ( V_40 -> V_70 -> V_113 , V_87 ,
V_19 , L_9 , V_40 -> V_61 ) ;
if ( F_75 ( V_37 ) ) {
F_79 ( V_40 -> V_70 -> V_112 ) ;
F_80 ( V_87 ) ;
return F_76 ( V_37 ) ;
}
V_87 -> V_109 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_20 ( V_37 , V_111 -> V_80 ) ;
F_48 ( V_40 ) ;
F_81 ( V_37 ) ;
} while ( V_110 > 0 );
return 0 ;
}
static int
F_82 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_110 )
{
struct V_36 * V_37 ;
unsigned int V_105 = V_40 -> V_63 - 1 ;
do {
V_37 = F_70 ( V_40 , V_79 , & V_105 ) ;
if ( V_37 == NULL )
break;
F_83 ( V_114 , V_37 , 1 ) ;
V_110 ++ ;
} while ( V_110 < 0 );
return 0 ;
}
int
F_84 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_110 )
{
if ( V_79 == NULL ) {
V_110 -= ( V_40 -> V_63 - 1 ) ;
} else {
F_66 ( & V_79 -> V_83 ) ;
V_110 -= V_79 -> V_103 ;
F_68 ( & V_79 -> V_83 ) ;
}
if ( V_110 > 0 )
return F_74 ( V_40 , V_79 , V_110 ) ;
if ( V_110 < 0 )
return F_82 ( V_40 , V_79 , V_110 ) ;
return 0 ;
}
static int
F_85 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_110 )
{
struct V_36 * V_37 ;
unsigned int V_105 = V_40 -> V_63 - 1 ;
do {
V_37 = F_70 ( V_40 , V_79 , & V_105 ) ;
if ( V_37 == NULL )
break;
F_86 ( V_37 ) ;
V_110 ++ ;
} while ( V_110 < 0 );
return 0 ;
}
int
F_87 ( struct V_39 * V_40 , struct V_38 * V_79 , int V_110 )
{
if ( V_79 == NULL ) {
V_110 -= ( V_40 -> V_63 - 1 ) ;
} else {
F_66 ( & V_79 -> V_83 ) ;
V_110 -= V_79 -> V_103 ;
F_68 ( & V_79 -> V_83 ) ;
}
if ( V_110 > 0 )
return F_74 ( V_40 , V_79 , V_110 ) ;
if ( V_110 < 0 )
return F_85 ( V_40 , V_79 , V_110 ) ;
return 0 ;
}
void
F_63 ( struct V_86 * V_87 )
{
F_56 ( V_87 ) ;
F_10 ( V_87 -> V_102 ) ;
F_10 ( V_87 -> V_100 ) ;
F_10 ( V_87 -> V_115 ) ;
F_88 ( V_87 , V_116 ) ;
}
void
F_80 ( struct V_86 * V_87 )
{
struct V_39 * V_40 = V_87 -> V_98 ;
struct V_38 * V_79 = V_87 -> V_99 ;
F_66 ( & V_79 -> V_83 ) ;
V_79 -> V_103 -- ;
if ( ! F_89 ( V_108 , & V_87 -> V_96 ) )
F_73 ( & V_87 -> V_104 ) ;
F_68 ( & V_79 -> V_83 ) ;
F_63 ( V_87 ) ;
if ( V_40 )
F_47 ( V_40 ) ;
}
static int F_90 ( struct V_43 * V_43 , const T_1 V_117 ,
const T_1 V_118 ,
const unsigned short V_119 ,
const unsigned short V_120 )
{
const struct V_121 sin = {
. V_122 = V_123 ,
. V_124 . V_125 = F_91 ( V_126 ) ,
. V_127 = F_92 ( V_120 ) ,
} ;
const char * V_128 ;
int error ;
switch ( V_119 ) {
case V_129 :
V_128 = V_130 ;
break;
case V_131 :
V_128 = V_132 ;
break;
default:
return - V_133 ;
}
error = F_93 ( V_43 , V_117 , V_118 ,
( const struct V_134 * ) & sin , V_128 ) ;
if ( error == - V_135 )
error = F_94 ( V_43 , V_117 , V_118 , V_119 , V_120 ) ;
return error ;
}
static int F_95 ( struct V_43 * V_43 , const T_1 V_117 ,
const T_1 V_118 ,
const unsigned short V_119 ,
const unsigned short V_120 )
{
const struct V_136 V_137 = {
. V_138 = V_139 ,
. V_140 = V_141 ,
. V_142 = F_92 ( V_120 ) ,
} ;
const char * V_128 ;
int error ;
switch ( V_119 ) {
case V_129 :
V_128 = V_143 ;
break;
case V_131 :
V_128 = V_144 ;
break;
default:
return - V_133 ;
}
error = F_93 ( V_43 , V_117 , V_118 ,
( const struct V_134 * ) & V_137 , V_128 ) ;
if ( error == - V_135 )
error = - V_145 ;
return error ;
}
static int F_96 ( struct V_43 * V_43 , const char * V_146 ,
const T_1 V_117 , const T_1 V_118 ,
const int V_147 ,
const unsigned short V_119 ,
const unsigned short V_120 )
{
int error = - V_145 ;
switch ( V_147 ) {
case V_148 :
error = F_90 ( V_43 , V_117 , V_118 ,
V_119 , V_120 ) ;
break;
#if F_97 ( V_149 )
case V_150 :
error = F_95 ( V_43 , V_117 , V_118 ,
V_119 , V_120 ) ;
#endif
}
return error ;
}
int F_98 ( const struct V_39 * V_40 , struct V_43 * V_43 ,
const int V_147 , const unsigned short V_151 ,
const unsigned short V_120 )
{
struct V_44 * V_45 ;
struct V_152 * V_59 ;
unsigned int V_46 ;
int error = 0 ;
F_21 ( V_151 == 0 && V_120 == 0 ) ;
if ( V_151 == 0 && V_120 == 0 )
return - V_17 ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
V_59 = V_45 -> V_50 [ V_46 ] ;
if ( V_59 == NULL )
continue;
F_42 ( L_10 ,
V_45 -> V_62 ,
V_46 ,
V_151 == V_129 ? L_11 : L_12 ,
V_120 ,
V_147 ,
V_59 -> V_51 ?
L_13 : L_14 ) ;
if ( V_59 -> V_51 )
continue;
if ( V_59 -> V_153 && V_151 == V_129 )
continue;
error = F_96 ( V_43 , V_45 -> V_62 , V_45 -> V_154 ,
V_46 , V_147 , V_151 , V_120 ) ;
if ( V_59 -> V_155 ) {
error = 0 ;
continue;
}
if ( error < 0 ) {
F_49 ( V_156 L_15
L_16 ,
V_45 -> V_62 , V_46 , - error ) ;
break;
}
}
}
return error ;
}
static void F_99 ( struct V_43 * V_43 , const T_1 V_117 , const T_1 V_118 ,
const char * V_146 )
{
int error ;
error = F_93 ( V_43 , V_117 , V_118 , NULL , L_14 ) ;
if ( error == - V_135 )
error = F_94 ( V_43 , V_117 , V_118 , 0 , 0 ) ;
F_42 ( L_17 ,
V_157 , V_146 , V_118 , error ) ;
}
static void F_29 ( const struct V_39 * V_40 , struct V_43 * V_43 )
{
struct V_44 * V_45 ;
unsigned long V_158 ;
unsigned int V_46 ;
F_100 ( V_159 ) ;
for ( V_45 = V_40 -> V_47 ; V_45 ; V_45 = V_45 -> V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
if ( V_45 -> V_50 [ V_46 ] == NULL )
continue;
if ( V_45 -> V_50 [ V_46 ] -> V_51 )
continue;
F_42 ( L_18 ,
V_45 -> V_62 , V_46 ) ;
F_99 ( V_43 , V_45 -> V_154 , V_46 , V_45 -> V_62 ) ;
}
}
F_101 ( & V_160 -> V_161 -> V_162 , V_158 ) ;
F_102 () ;
F_103 ( & V_160 -> V_161 -> V_162 , V_158 ) ;
}
int
F_104 ( struct V_39 * V_40 , struct V_163 * V_164 ,
struct V_86 * V_87 )
{
struct V_165 * V_166 = & V_87 -> V_167 . V_168 [ 0 ] ;
struct V_165 * V_169 = & V_87 -> V_170 . V_168 [ 0 ] ;
struct V_171 * V_37 ;
int V_172 ;
int error ;
F_42 ( L_19 , V_157 , V_164 ) ;
V_87 -> V_173 = V_40 -> V_174 ;
V_87 -> V_175 = V_164 -> V_175 ;
V_87 -> V_176 = V_164 -> V_173 -> V_177 ;
V_87 -> V_98 = V_40 ;
V_87 -> V_178 = sizeof( V_164 -> V_173 -> V_179 ) ;
memcpy ( & V_87 -> V_180 , & V_164 -> V_173 -> V_179 , V_87 -> V_178 ) ;
memcpy ( & V_87 -> V_167 , & V_164 -> V_181 , sizeof( V_87 -> V_167 ) ) ;
memcpy ( & V_87 -> V_170 , & V_164 -> V_182 , sizeof( V_87 -> V_170 ) ) ;
V_87 -> V_167 . V_183 = V_164 -> V_184 . V_183 ;
if ( V_87 -> V_167 . V_183 <= V_87 -> V_167 . V_168 [ 0 ] . V_185 ) {
V_87 -> V_167 . V_168 [ 0 ] . V_185 = V_87 -> V_167 . V_183 ;
V_87 -> V_167 . V_186 = 0 ;
} else if ( V_87 -> V_167 . V_183 <= V_87 -> V_167 . V_168 [ 0 ] . V_185 +
V_87 -> V_167 . V_186 )
V_87 -> V_167 . V_186 = V_87 -> V_167 . V_183 -
V_87 -> V_167 . V_168 [ 0 ] . V_185 ;
else
V_87 -> V_167 . V_183 = V_87 -> V_167 . V_168 [ 0 ] . V_185 +
V_87 -> V_167 . V_186 ;
V_169 -> V_185 = 0 ;
F_105 ( V_166 ) ;
F_106 ( V_166 ) ;
V_172 = F_107 ( V_87 , V_166 , V_169 ) ;
F_108 ( & V_164 -> V_173 -> V_187 ) ;
if ( ! V_172 ) {
F_109 ( V_164 ) ;
return 0 ;
}
memcpy ( & V_164 -> V_182 , & V_87 -> V_170 , sizeof( V_164 -> V_182 ) ) ;
V_37 = F_110 ( V_164 ) ;
if ( F_75 ( V_37 ) ) {
error = F_76 ( V_37 ) ;
goto V_12;
}
F_21 ( F_111 ( & V_37 -> V_188 ) != 1 ) ;
error = V_37 -> V_189 ;
F_112 ( V_37 ) ;
V_12:
F_42 ( L_20 , V_157 , error ) ;
return error ;
}
T_1 F_113 ( const struct V_86 * V_87 )
{
T_1 V_190 = V_87 -> V_173 -> V_191 -> V_192 ;
if ( V_87 -> V_98 -> V_67 < V_190 )
V_190 = V_87 -> V_98 -> V_67 ;
return V_190 ;
}
