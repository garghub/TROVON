void F_1 ( void )
{
}
static T_1 int F_2 ( unsigned V_1 , T_2 * V_2 )
{
return F_3 ( V_3 , V_1 , V_2 ) ;
}
static T_1 int F_4 ( int V_1 )
{
return F_3 ( V_4 , V_1 ) ;
}
static T_1 int F_5 ( T_2 V_2 )
{
return F_3 ( V_5 , V_2 ) ;
}
static T_1 int F_6 ( T_2 V_2 , long V_1 , struct V_6 * * V_6 )
{
return F_3 ( V_7 , V_2 , V_1 , V_6 ) ;
}
static T_1 int F_7 ( T_2 V_2 , long V_8 , long V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
return F_3 ( V_14 , V_2 , V_8 , V_9 , V_11 , V_13 ) ;
}
static void F_8 ( T_3 * V_2 , const void * V_15 ,
T_4 V_16 , void * V_17 )
{
F_9 ( V_16 ) ;
}
static int F_10 ( T_5 * V_18 )
{
T_6 * V_19 ;
T_3 * V_20 ;
void * V_17 = NULL ;
int V_21 ;
if ( ( V_19 = F_11 () ) != NULL ) {
V_20 = F_12 ( V_19 ) ;
if ( V_20 == NULL ) {
F_13 ( L_1 , V_22 ) ;
return 0 ;
}
V_21 = F_14 ( V_20 , V_23 ,
& V_18 -> V_24 , & V_17 ) ;
if ( V_21 == 0 ) {
V_18 -> V_24 = F_4 ( 0 ) ;
if ( V_18 -> V_24 == - 1 ) {
F_15 ( L_2 , V_22 ) ;
F_16 ( V_25 ,
V_26 ) ;
return 0 ;
}
V_21 = F_17 ( V_20 , V_23 ,
V_18 -> V_24 , V_17 ,
F_8 ) ;
if ( V_21 == 0 ) {
F_13 ( L_3 , V_22 ) ;
F_9 ( V_18 -> V_24 ) ;
return 0 ;
}
if ( F_18 ( V_18 -> V_24 , V_27 , V_28 ) != 0 ) {
F_13 ( L_4 ,
V_22 ) ;
}
}
V_18 -> V_29 = V_30 ;
} else {
V_18 -> V_24 = F_4 ( 0 ) ;
if ( V_18 -> V_24 == - 1 ) {
F_15 ( L_2 , V_22 ) ;
F_16 ( V_25 ,
V_26 ) ;
return 0 ;
}
V_18 -> V_29 = V_31 ;
}
return 1 ;
}
int F_19 ( T_5 * V_18 )
{
int V_32 = - 1 ;
V_18 -> V_33 = 0 ;
V_32 = F_2 ( V_34 , & V_18 -> V_33 ) ;
if ( V_32 < 0 ) {
F_15 ( L_5 , V_22 ) ;
F_16 ( V_35 , V_36 ) ;
return 0 ;
}
memset ( V_18 -> V_37 , 0 , sizeof( V_18 -> V_37 ) ) ;
V_18 -> V_24 = - 1 ;
V_18 -> V_29 = V_38 ;
return 1 ;
}
int F_20 ( T_5 * V_18 , int V_39 , unsigned char * V_40 ,
T_7 V_41 )
{
int V_32 ;
int V_42 = 0 ;
unsigned int V_43 = 0 ;
struct V_6 * V_44 ;
struct V_12 V_13 ;
struct V_10 V_11 [ V_34 ] ;
T_8 V_45 = 0 ;
V_13 . V_46 = 0 ;
V_13 . V_47 = 0 ;
if ( V_18 -> V_29 == V_38 ) {
V_32 = F_10 ( V_18 ) ;
if ( V_32 == 0 )
return 0 ;
}
V_44 = & ( V_18 -> V_37 [ 0 % V_34 ] ) ;
memset ( V_44 , '\0' , sizeof( * V_44 ) ) ;
V_44 -> V_48 = V_39 ;
V_44 -> V_49 = V_50 ;
if ( sizeof( V_40 ) != sizeof( V_44 -> V_51 ) ) {
V_44 -> V_51 = ( V_52 ) ( unsigned long ) V_40 ;
} else {
V_44 -> V_51 = ( V_52 ) V_40 ;
}
V_44 -> V_53 = 0 ;
V_44 -> V_54 = 0 ;
V_44 -> V_55 = V_41 ;
V_44 -> V_56 = V_57 ;
V_44 -> V_58 = V_18 -> V_24 ;
V_32 = F_6 ( V_18 -> V_33 , 1 , & V_44 ) ;
if ( V_32 < 0 ) {
F_21 ( L_6 , V_22 ) ;
return 0 ;
}
do {
F_22 () ;
V_32 = F_23 ( V_18 -> V_24 , & V_45 , sizeof( V_45 ) ) ;
if ( V_32 < 0 ) {
if ( V_59 == V_60 || V_59 == V_61 )
continue;
F_15 ( L_7 , V_22 ) ;
return 0 ;
} else if ( V_32 == 0 || V_45 <= 0 ) {
F_13 ( L_8 , V_22 , V_32 ,
V_45 ) ;
}
if ( V_45 > 0 ) {
V_32 = F_7 ( V_18 -> V_33 , 1 , V_34 ,
V_11 , & V_13 ) ;
if ( V_32 > 0 ) {
if ( V_11 [ 0 ] . V_62 < 0 ) {
if ( V_11 [ 0 ] . V_62 == - V_63 && V_42 ++ < 3 ) {
V_32 = F_6 ( V_18 -> V_33 , 1 , & V_44 ) ;
if ( V_32 < 0 ) {
F_15 ( L_9 ,
V_22 , V_42 ) ;
return 0 ;
}
continue;
} else {
F_13
( L_10 ,
V_22 , V_11 [ 0 ] . V_62 ) ;
return 0 ;
}
}
V_43 = 1 ;
} else if ( V_32 < 0 ) {
F_15 ( L_11 , V_22 ) ;
return 0 ;
} else {
F_13 ( L_12 , V_22 ) ;
}
}
} while ( ! V_43 );
return 1 ;
}
static T_1 void F_24 ( struct V_64 * V_65 ,
const unsigned int V_66 )
{
V_65 -> V_67 = V_68 ;
V_65 -> V_69 = V_70 ;
V_65 -> V_71 = F_25 ( V_72 ) ;
* F_26 ( V_65 ) = ( char ) V_66 ;
}
static void F_27 ( struct V_64 * V_65 , const unsigned char * V_73 ,
const unsigned int V_41 )
{
struct V_74 * V_75 ;
V_65 -> V_67 = V_68 ;
V_65 -> V_69 = V_76 ;
V_65 -> V_71 = F_25 ( F_28 ( V_41 ) ) ;
V_75 = (struct V_74 * ) F_26 ( V_65 ) ;
V_75 -> V_77 = V_41 ;
memcpy ( V_75 -> V_73 , V_73 , V_41 ) ;
}
static T_1 int F_29 ( T_9 * V_78 , const unsigned char * V_15 ,
const int V_79 )
{
int V_21 ;
V_21 = F_30 ( V_78 -> V_80 , V_68 , V_81 , V_15 , V_79 ) ;
if ( V_21 < 0 ) {
F_15 ( L_13 , V_22 ) ;
F_16 ( V_82 , V_83 ) ;
return 0 ;
}
return 1 ;
}
static int F_31 ( T_9 * V_78 , const char * V_84 ,
const char * V_85 )
{
struct V_86 V_87 ;
V_78 -> V_80 = V_78 -> V_39 = - 1 ;
int V_32 = - 1 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_88 = V_89 ;
strncpy ( ( char * ) V_87 . V_90 , V_84 , V_91 ) ;
V_87 . V_90 [ V_91 - 1 ] = '\0' ;
strncpy ( ( char * ) V_87 . V_92 , V_85 , V_93 ) ;
V_87 . V_92 [ V_93 - 1 ] = '\0' ;
V_78 -> V_80 = F_32 ( V_89 , V_94 , 0 ) ;
if ( V_78 -> V_80 == - 1 ) {
F_15 ( L_14 , V_22 ) ;
F_16 ( V_95 , V_96 ) ;
goto V_97;
}
V_32 = F_33 ( V_78 -> V_80 , (struct V_98 * ) & V_87 , sizeof( V_87 ) ) ;
if ( V_32 < 0 ) {
F_15 ( L_15 , V_22 ) ;
F_16 ( V_95 , V_99 ) ;
goto V_97;
}
V_78 -> V_39 = F_34 ( V_78 -> V_80 , NULL , 0 ) ;
if ( V_78 -> V_39 < 0 ) {
F_15 ( L_16 , V_22 ) ;
F_16 ( V_95 , V_100 ) ;
goto V_97;
}
return 1 ;
V_97:
if ( V_78 -> V_80 >= 0 )
F_9 ( V_78 -> V_80 ) ;
if ( V_78 -> V_39 >= 0 )
F_9 ( V_78 -> V_39 ) ;
V_78 -> V_80 = V_78 -> V_39 = - 1 ;
return 0 ;
}
static int F_35 ( T_9 * V_78 , const unsigned char * V_101 ,
T_7 V_102 , const unsigned char * V_73 ,
unsigned int V_103 )
{
struct V_104 V_105 = { 0 } ;
struct V_64 * V_65 ;
struct V_106 V_107 ;
T_10 V_108 ;
# ifdef F_36
int V_21 ;
# endif
char V_109 [ F_37 ( F_28 ( V_110 ) ) + F_37 ( V_72 ) ] ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_105 . V_111 = V_109 ;
V_105 . V_112 = sizeof( V_109 ) ;
V_65 = F_38 ( & V_105 ) ;
F_24 ( V_65 , V_103 ) ;
V_65 = F_39 ( & V_105 , V_65 ) ;
F_27 ( V_65 , V_73 , V_110 ) ;
V_107 . V_113 = ( unsigned char * ) V_101 ;
V_107 . V_114 = V_102 ;
V_105 . V_115 = V_116 ;
# ifdef F_36
V_105 . V_117 = 0 ;
V_105 . V_118 = NULL ;
V_108 = F_40 ( V_78 -> V_39 , & V_105 , 0 ) ;
if ( V_108 < 0 ) {
F_15 ( L_17 ,
V_22 ) ;
return 0 ;
}
V_21 = F_41 ( V_78 -> V_119 [ 1 ] , & V_107 , 1 , V_120 ) ;
if ( V_21 < 0 ) {
F_15 ( L_18 , V_22 ) ;
return 0 ;
}
V_21 = F_42 ( V_78 -> V_119 [ 0 ] , NULL , V_78 -> V_39 , NULL , V_102 , 0 ) ;
if ( V_21 < 0 ) {
F_15 ( L_19 , V_22 ) ;
return 0 ;
}
# else
V_105 . V_117 = 1 ;
V_105 . V_118 = & V_107 ;
V_108 = F_40 ( V_78 -> V_39 , & V_105 , 0 ) ;
if ( V_108 < 0 ) {
F_15 ( L_20 , V_22 ) ;
return 0 ;
}
if ( V_108 != ( T_10 ) V_102 ) {
F_13 ( L_21 , V_108 ,
V_102 ) ;
return 0 ;
}
# endif
return 1 ;
}
static int F_43 ( T_11 * V_2 , const unsigned char * V_15 ,
const unsigned char * V_73 , int V_103 )
{
int V_84 ;
int V_21 ;
T_9 * V_78 ;
char V_85 [ V_93 ] ;
if ( V_2 == NULL || V_15 == NULL ) {
F_13 ( L_22 , V_22 ) ;
return 0 ;
}
if ( F_44 ( V_2 ) == NULL ) {
F_13 ( L_23 , V_22 ) ;
return 0 ;
}
V_78 = F_45 ( V_2 ) ;
if ( V_78 == NULL ) {
F_13 ( L_24 , V_22 ) ;
return 0 ;
}
V_84 = F_46 ( V_2 ) ;
switch ( V_84 ) {
case V_121 :
strncpy ( V_85 , L_25 , V_93 ) ;
break;
default:
F_13 ( L_26 , V_22 , V_84 ) ;
return 0 ;
}
V_85 [ V_93 - 1 ] = '\0' ;
if ( V_110 != F_47 ( V_2 ) ) {
F_13 ( L_27 , V_22 ,
F_47 ( V_2 ) ) ;
return 0 ;
}
V_21 = F_31 ( V_78 , L_28 , V_85 ) ;
if ( V_21 < 1 )
return 0 ;
V_21 = F_29 ( V_78 , V_15 , F_48 ( V_2 ) ) ;
if ( V_21 < 1 )
goto V_97;
if ( F_19 ( & V_78 -> V_18 ) == 0 )
goto V_97;
# ifdef F_36
F_49 ( V_78 -> V_119 ) ;
# endif
V_78 -> V_122 = V_123 ;
return 1 ;
V_97:
F_9 ( V_78 -> V_39 ) ;
F_9 ( V_78 -> V_80 ) ;
return 0 ;
}
static int F_50 ( T_11 * V_2 , unsigned char * V_124 ,
const unsigned char * V_101 , T_7 V_102 )
{
T_9 * V_78 ;
int V_21 ;
char V_125 [ V_110 ] = { 0 } ;
if ( V_2 == NULL || V_124 == NULL || V_101 == NULL ) {
F_13 ( L_29 , V_22 ) ;
return 0 ;
}
V_78 = ( T_9 * ) F_45 ( V_2 ) ;
if ( V_78 == NULL || V_78 -> V_122 != V_123 ) {
F_13 ( L_30 ,
V_2 == NULL ? L_31 : L_32 ) ;
return 0 ;
}
if ( F_51 ( V_2 ) == 0 ) {
memcpy ( V_125 , V_101 + ( V_102 - V_110 ) , V_110 ) ;
}
V_21 = F_35 ( V_78 , ( unsigned char * ) V_101 , V_102 ,
F_52 ( V_2 ) ,
F_51 ( V_2 ) ) ;
if ( V_21 < 1 ) {
return 0 ;
}
V_21 = F_20 ( & V_78 -> V_18 , V_78 -> V_39 , V_124 , V_102 ) ;
if ( V_21 < 1 )
return 0 ;
if ( F_51 ( V_2 ) ) {
memcpy ( F_53 ( V_2 ) , V_124 + ( V_102 - V_110 ) ,
V_110 ) ;
} else {
memcpy ( F_53 ( V_2 ) , V_125 , V_110 ) ;
}
return 1 ;
}
static int F_54 ( T_11 * V_2 )
{
T_9 * V_78 ;
if ( V_2 == NULL ) {
F_13 ( L_29 , V_22 ) ;
return 0 ;
}
V_78 = ( T_9 * ) F_45 ( V_2 ) ;
if ( V_78 == NULL || V_78 -> V_122 != V_123 ) {
F_13 ( L_30 ,
V_2 == NULL ? L_31 : L_32 ) ;
return 0 ;
}
F_9 ( V_78 -> V_39 ) ;
F_9 ( V_78 -> V_80 ) ;
# ifdef F_36
F_9 ( V_78 -> V_119 [ 0 ] ) ;
F_9 ( V_78 -> V_119 [ 1 ] ) ;
# endif
if ( V_78 -> V_18 . V_29 == V_31 )
F_9 ( V_78 -> V_18 . V_24 ) ;
F_5 ( V_78 -> V_18 . V_33 ) ;
return 1 ;
}
const T_12 * F_55 ( void )
{
if ( V_126 == NULL
&& ( ( V_126 =
F_56 ( V_121 ,
V_127 ,
V_128 ) ) == NULL
|| ! F_57 ( V_126 , V_129 )
|| ! F_58 ( V_126 ,
V_130 |
V_131 )
|| ! F_59 ( V_126 ,
F_43 )
|| ! F_60 ( V_126 ,
F_50 )
|| ! F_61 ( V_126 ,
F_54 )
|| ! F_62 ( V_126 ,
sizeof( T_9 ) ) ) ) {
F_63 ( V_126 ) ;
V_126 = NULL ;
}
return V_126 ;
}
static int F_64 ( T_13 * V_132 , const T_12 * * V_133 ,
const int * * V_134 , int V_135 )
{
int V_32 = 1 ;
if ( V_133 == NULL ) {
* V_134 = V_136 ;
return ( sizeof( V_136 ) / sizeof( V_136 [ 0 ] ) ) ;
}
switch ( V_135 ) {
case V_121 :
* V_133 = F_55 () ;
break;
default:
* V_133 = NULL ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_65 ( T_13 * V_132 )
{
F_66 () ;
if ( ! F_67 ( V_132 , V_23 )
|| ! F_68 ( V_132 , V_137 )
|| ! F_69 ( V_132 , V_138 )
|| ! F_70 ( V_132 , V_139 )
|| ! F_71 ( V_132 , V_140 ) ) {
F_16 ( V_141 , V_142 ) ;
return 0 ;
}
if ( F_55 () == NULL ) {
F_16 ( V_141 , V_142 ) ;
return 0 ;
}
if ( ! F_72 ( V_132 , F_64 ) ) {
F_16 ( V_141 , V_142 ) ;
return 0 ;
}
return 1 ;
}
static int F_73 ( T_13 * V_132 , const char * V_143 )
{
if ( V_143 && ( strcmp ( V_143 , V_23 ) != 0 ) )
return 0 ;
if ( ! F_74 () )
return 0 ;
if ( ! F_65 ( V_132 ) )
return 0 ;
return 1 ;
}
static int F_74 ( void )
{
int V_21 ;
int V_144 ;
int V_145 [ 3 ] = { - 1 , - 1 , - 1 } ;
int V_146 ;
char * V_147 ;
struct V_148 V_149 ;
V_21 = F_75 ( & V_149 ) ;
if ( V_21 != 0 ) {
F_16 ( V_150 ,
V_151 ) ;
return 0 ;
}
V_147 = strtok ( V_149 . V_152 , L_33 ) ;
for ( V_144 = 0 ; V_144 < 3 && V_147 != NULL ; V_144 ++ ) {
V_145 [ V_144 ] = atoi ( V_147 ) ;
V_147 = strtok ( NULL , L_33 ) ;
}
if ( F_76 ( V_145 [ 0 ] , V_145 [ 1 ] , V_145 [ 2 ] )
< F_76 ( V_153 , V_154 , V_155 ) ) {
F_77 ( L_34 ,
V_145 [ 0 ] , V_145 [ 1 ] , V_145 [ 2 ] ) ;
F_77 ( L_35 ,
V_153 , V_154 , V_155 ) ;
F_16 ( V_150 ,
V_156 ) ;
return 0 ;
}
V_146 = F_32 ( V_89 , V_94 , 0 ) ;
if ( V_146 == - 1 ) {
F_16 ( V_150 , V_96 ) ;
return 0 ;
}
F_9 ( V_146 ) ;
return 1 ;
}
static T_13 * F_78 ( void )
{
T_13 * V_21 = F_79 () ;
if ( V_21 == NULL )
return NULL ;
if ( ! F_65 ( V_21 ) ) {
F_80 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
void F_1 ( void )
{
T_13 * V_157 ;
if ( ! F_74 () )
return;
V_157 = F_78 () ;
if ( V_157 == NULL )
return;
F_81 ( V_157 ) ;
F_80 ( V_157 ) ;
F_82 () ;
}
static int V_139 ( T_13 * V_132 )
{
return 1 ;
}
static int V_140 ( T_13 * V_132 )
{
return 1 ;
}
static int V_138 ( T_13 * V_132 )
{
F_83 () ;
F_63 ( V_126 ) ;
V_126 = NULL ;
return 1 ;
}
