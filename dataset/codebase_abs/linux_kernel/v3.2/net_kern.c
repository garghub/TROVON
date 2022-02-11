static int F_1 ( int V_1 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
int V_5 = 0 ;
F_2 ( & V_6 , V_4 ) ;
if ( V_1 <= V_7 )
goto V_8;
V_5 = - V_9 ;
V_3 = F_3 ( V_1 ) ;
if ( V_3 == NULL )
goto V_8;
F_4 ( V_3 , V_1 ) ;
F_5 ( V_10 ) ;
V_10 = V_3 ;
V_7 = V_1 ;
V_5 = 0 ;
V_8:
F_6 ( & V_6 , V_4 ) ;
return V_5 ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_15 ;
struct V_2 * V_16 ;
V_16 = F_3 ( V_14 -> V_17 ) ;
if ( V_16 == NULL ) {
V_10 -> V_12 = V_12 ;
(* V_14 -> V_18 )( V_14 -> V_19 , V_10 , V_14 ) ;
V_12 -> V_20 . V_21 ++ ;
return 0 ;
}
V_16 -> V_12 = V_12 ;
F_4 ( V_16 , V_14 -> V_17 ) ;
F_9 ( V_16 ) ;
V_15 = (* V_14 -> V_18 )( V_14 -> V_19 , V_16 , V_14 ) ;
if ( V_15 > 0 ) {
F_10 ( V_16 , V_15 ) ;
V_16 -> V_22 = (* V_14 -> V_22 )( V_16 ) ;
V_12 -> V_20 . V_23 += V_16 -> V_24 ;
V_12 -> V_20 . V_25 ++ ;
F_11 ( V_16 ) ;
return V_15 ;
}
F_5 ( V_16 ) ;
return V_15 ;
}
static void F_12 ( struct V_26 * V_27 )
{
struct V_13 * V_14 =
F_13 ( V_27 , struct V_13 , V_27 ) ;
F_14 ( V_14 -> V_12 ) ;
}
static T_1 F_15 ( int V_28 , void * V_29 )
{
struct V_11 * V_12 = V_29 ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_5 ;
if ( ! F_16 ( V_12 ) )
return V_30 ;
F_17 ( & V_14 -> V_31 ) ;
while ( ( V_5 = F_7 ( V_12 ) ) > 0 ) ;
if ( V_5 < 0 ) {
F_18 ( V_32
L_1 ,
V_12 -> V_33 , V_5 ) ;
F_19 ( & V_14 -> V_27 ) ;
goto V_8;
}
F_20 ( V_14 -> V_19 , V_34 ) ;
V_8:
F_21 ( & V_14 -> V_31 ) ;
return V_35 ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_5 ;
if ( V_14 -> V_19 >= 0 ) {
V_5 = - V_36 ;
goto V_8;
}
V_14 -> V_19 = (* V_14 -> V_37 )( & V_14 -> V_38 ) ;
if ( V_14 -> V_19 < 0 ) {
V_5 = V_14 -> V_19 ;
goto V_8;
}
V_5 = F_23 ( V_12 -> V_28 , V_14 -> V_19 , V_39 , F_15 ,
V_40 | V_41 , V_12 -> V_33 , V_12 ) ;
if ( V_5 != 0 ) {
F_18 ( V_32 L_2 , V_5 ) ;
V_5 = - V_42 ;
goto V_43;
}
V_14 -> V_44 . V_45 = ( unsigned long ) & V_14 -> V_38 ;
F_24 ( V_12 ) ;
while ( ( V_5 = F_7 ( V_12 ) ) > 0 ) ;
F_17 ( & V_46 ) ;
F_25 ( & V_14 -> V_47 , & V_48 ) ;
F_21 ( & V_46 ) ;
return 0 ;
V_43:
if ( V_14 -> V_49 != NULL ) (* V_14 -> V_49 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
V_14 -> V_19 = - 1 ;
V_8:
return V_5 ;
}
static int F_26 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
F_27 ( V_12 ) ;
F_28 ( V_12 -> V_28 , V_12 ) ;
if ( V_14 -> V_49 != NULL )
(* V_14 -> V_49 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
V_14 -> V_19 = - 1 ;
F_17 ( & V_46 ) ;
F_29 ( & V_14 -> V_47 ) ;
F_21 ( & V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_16 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
unsigned long V_4 ;
int V_24 ;
F_27 ( V_12 ) ;
F_2 ( & V_14 -> V_31 , V_4 ) ;
V_24 = (* V_14 -> V_50 )( V_14 -> V_19 , V_16 , V_14 ) ;
if ( V_24 == V_16 -> V_24 ) {
V_12 -> V_20 . V_51 ++ ;
V_12 -> V_20 . V_52 += V_16 -> V_24 ;
V_12 -> V_53 = V_54 ;
F_24 ( V_12 ) ;
F_31 ( V_12 ) ;
}
else if ( V_24 == 0 ) {
F_24 ( V_12 ) ;
V_12 -> V_20 . V_55 ++ ;
}
else {
F_24 ( V_12 ) ;
F_18 ( V_32 L_3 , V_24 ) ;
}
F_6 ( & V_14 -> V_31 , V_4 ) ;
F_32 ( V_16 ) ;
return V_56 ;
}
static void F_33 ( struct V_11 * V_12 )
{
return;
}
static void F_34 ( struct V_11 * V_12 )
{
V_12 -> V_53 = V_54 ;
F_31 ( V_12 ) ;
}
static int F_35 ( struct V_11 * V_12 , int V_57 )
{
V_12 -> V_58 = V_57 ;
return 0 ;
}
static void F_36 ( struct V_11 * V_12 )
{
F_37 ( V_12 -> V_28 ) ;
F_15 ( V_12 -> V_28 , V_12 ) ;
F_38 ( V_12 -> V_28 ) ;
}
static void F_39 ( struct V_11 * V_12 ,
struct V_59 * V_60 )
{
strcpy ( V_60 -> V_61 , V_62 ) ;
strcpy ( V_60 -> V_63 , L_4 ) ;
}
static void F_40 ( unsigned long V_64 )
{
#ifdef undef
struct V_65 * V_66 = (struct V_65 * ) V_64 ;
F_41 ( V_67 L_5 , V_66 ) ;
F_42 ( V_66 ) ;
#endif
}
static void F_43 ( char * V_68 , unsigned char * V_69 , char * V_33 )
{
char * V_70 ;
int V_71 ;
if ( V_68 == NULL )
goto V_72;
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ ) {
V_69 [ V_71 ] = F_44 ( V_68 , & V_70 , 16 ) ;
if ( ( V_70 == V_68 ) ||
( ( * V_70 != ':' ) && ( * V_70 != ',' ) && ( * V_70 != '\0' ) ) ) {
F_18 ( V_32
L_6
L_7 , V_68 ) ;
goto V_72;
}
V_68 = V_70 + 1 ;
}
if ( F_45 ( V_69 ) ) {
F_18 ( V_32
L_8
L_9 ) ;
goto V_72;
}
if ( ! F_46 ( V_69 ) ) {
F_18 ( V_32
L_10
L_9 ) ;
goto V_72;
}
if ( ! F_47 ( V_69 ) ) {
F_18 ( V_73
L_11
L_12 ) ;
F_18 ( V_73 L_13
L_14 ) ;
F_18 ( V_73 L_15 ,
V_69 [ 0 ] | 0x02 , V_69 [ 1 ] , V_69 [ 2 ] , V_69 [ 3 ] , V_69 [ 4 ] ,
V_69 [ 5 ] ) ;
}
return;
V_72:
F_18 ( V_67
L_16 , V_33 ) ;
F_48 ( V_69 ) ;
}
static void F_49 ( struct V_74 * V_12 )
{
struct V_75 * V_74 = F_50 ( V_12 ) ;
struct V_11 * V_76 = V_74 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_76 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
F_29 ( & V_74 -> V_47 ) ;
F_51 ( V_74 ) ;
F_52 ( V_76 ) ;
}
static void F_53 ( int V_77 , void * V_78 , char * V_79 ,
struct V_80 * V_80 )
{
struct V_75 * V_74 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_5 , V_81 ;
V_81 = V_80 -> V_82 + sizeof( struct V_13 ) ;
V_74 = F_54 ( sizeof( * V_74 ) , V_83 ) ;
if ( V_74 == NULL ) {
F_18 ( V_32 L_17
L_18 ) ;
return;
}
V_12 = F_55 ( V_81 ) ;
if ( V_12 == NULL ) {
F_18 ( V_32 L_19
L_20 , V_77 ) ;
goto V_84;
}
F_56 ( & V_74 -> V_47 ) ;
V_74 -> V_85 = V_77 ;
snprintf ( V_12 -> V_33 , sizeof( V_12 -> V_33 ) , L_21 , V_77 ) ;
F_43 ( V_79 , V_74 -> V_79 , V_12 -> V_33 ) ;
F_18 ( V_67 L_22 , V_77 , V_74 -> V_79 ) ;
V_14 = F_8 ( V_12 ) ;
memset ( V_14 , 0 , V_81 ) ;
F_57 ( & V_14 -> V_27 , F_12 ) ;
if ( ! V_86 ) {
F_58 ( & V_87 ) ;
V_86 = 1 ;
}
V_74 -> V_88 . V_89 = V_77 ;
V_74 -> V_88 . V_33 = V_62 ;
V_74 -> V_88 . V_12 . V_90 = F_49 ;
F_59 ( & V_74 -> V_88 . V_12 , V_74 ) ;
if ( F_60 ( & V_74 -> V_88 ) )
goto V_91;
F_61 ( V_12 , & V_74 -> V_88 . V_12 ) ;
V_74 -> V_12 = V_12 ;
(* V_80 -> V_92 -> V_78 )( V_12 , V_78 ) ;
* V_14 = ( (struct V_13 )
{ . V_47 = F_62 ( V_14 -> V_47 ) ,
. V_12 = V_12 ,
. V_19 = - 1 ,
. V_79 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_17 = V_80 -> V_38 -> V_17 ,
. V_22 = V_80 -> V_92 -> V_22 ,
. V_37 = V_80 -> V_38 -> V_37 ,
. V_49 = V_80 -> V_38 -> V_49 ,
. remove = V_80 -> V_38 -> remove ,
. V_18 = V_80 -> V_92 -> V_18 ,
. V_50 = V_80 -> V_92 -> V_50 ,
. V_93 = V_80 -> V_38 -> V_93 ,
. V_94 = V_80 -> V_38 -> V_94 } ) ;
F_63 ( & V_14 -> V_44 ) ;
F_64 ( & V_14 -> V_31 ) ;
V_14 -> V_44 . V_95 = F_40 ;
memcpy ( V_14 -> V_79 , V_74 -> V_79 , sizeof( V_14 -> V_79 ) ) ;
if ( ( V_80 -> V_38 -> V_78 != NULL ) &&
( (* V_80 -> V_38 -> V_78 )( & V_14 -> V_38 , V_12 ) != 0 ) )
goto V_96;
memcpy ( V_12 -> V_97 , V_74 -> V_79 , V_98 ) ;
V_12 -> V_58 = V_80 -> V_38 -> V_58 ;
V_12 -> V_99 = & V_100 ;
V_12 -> V_101 = & V_102 ;
V_12 -> V_103 = ( V_104 >> 1 ) ;
V_12 -> V_28 = V_34 ;
V_5 = F_1 ( V_14 -> V_17 ) ;
if ( V_5 )
goto V_105;
F_65 () ;
V_5 = F_66 ( V_12 ) ;
F_67 () ;
if ( V_5 )
goto V_105;
F_17 ( & V_106 ) ;
F_25 ( & V_74 -> V_47 , & V_107 ) ;
F_21 ( & V_106 ) ;
return;
V_105:
if ( V_80 -> V_38 -> remove != NULL )
(* V_80 -> V_38 -> remove )( & V_14 -> V_38 ) ;
V_96:
F_68 ( & V_74 -> V_88 ) ;
return;
V_91:
F_52 ( V_12 ) ;
V_84:
F_51 ( V_74 ) ;
}
static struct V_75 * F_69 ( int V_77 )
{
struct V_75 * V_74 ;
struct V_108 * V_109 ;
F_17 ( & V_106 ) ;
F_70 (ele, &devices) {
V_74 = F_71 ( V_109 , struct V_75 , V_47 ) ;
if ( V_74 -> V_85 == V_77 )
goto V_8;
}
V_74 = NULL ;
V_8:
F_21 ( & V_106 ) ;
return V_74 ;
}
static int F_72 ( char * V_68 , int * V_110 , char * * V_111 ,
char * * V_112 )
{
char * V_70 ;
int V_77 , V_5 = - V_113 ;
V_77 = F_44 ( V_68 , & V_70 , 0 ) ;
if ( V_70 == V_68 ) {
* V_112 = L_23 ;
return V_5 ;
}
V_68 = V_70 ;
if ( * V_68 != '=' ) {
* V_112 = L_24 ;
return V_5 ;
}
V_68 ++ ;
if ( F_69 ( V_77 ) ) {
* V_112 = L_25 ;
return V_5 ;
}
* V_110 = V_77 ;
* V_111 = V_68 ;
return 0 ;
}
static int F_73 ( struct V_80 * V_80 , char * V_114 , int V_77 ,
void * * V_115 , char * * V_116 )
{
int V_24 ;
V_24 = strlen ( V_80 -> V_33 ) ;
if ( strncmp ( V_114 , V_80 -> V_33 , V_24 ) )
return 0 ;
V_114 += V_24 ;
if ( * V_114 == ',' )
V_114 ++ ;
else if ( * V_114 != '\0' )
return 0 ;
* V_115 = F_74 ( V_80 -> V_117 , V_83 ) ;
if ( * V_115 == NULL )
return 1 ;
if ( ! V_80 -> V_118 ( V_114 , V_116 , * V_115 ) ) {
F_51 ( * V_115 ) ;
* V_115 = NULL ;
}
return 1 ;
}
void F_75 ( struct V_80 * V_3 )
{
struct V_108 * V_109 , * V_119 ;
struct V_120 * V_114 ;
void * V_78 ;
char * V_79 = NULL ;
int V_121 ;
F_17 ( & V_122 ) ;
F_76 ( ! F_77 ( & V_3 -> V_47 ) ) ;
F_25 ( & V_3 -> V_47 , & V_123 ) ;
F_21 ( & V_122 ) ;
F_78 (ele, next, &eth_cmd_line) {
V_114 = F_71 ( V_109 , struct V_120 , V_47 ) ;
V_121 = F_73 ( V_3 , V_114 -> V_78 , V_114 -> V_85 , & V_78 ,
& V_79 ) ;
if ( ! V_121 )
continue;
else if ( V_78 != NULL ) {
F_53 ( V_114 -> V_85 , V_78 , V_79 , V_3 ) ;
F_51 ( V_78 ) ;
}
F_29 ( & V_114 -> V_47 ) ;
}
}
static int F_79 ( char * V_68 , int V_85 )
{
struct V_108 * V_109 ;
struct V_80 * V_80 ;
void * V_78 ;
char * V_79 = NULL ;
int V_124 = 0 ;
F_17 ( & V_122 ) ;
F_70 (ele, &transports) {
V_80 = F_71 ( V_109 , struct V_80 , V_47 ) ;
if ( ! F_73 ( V_80 , V_68 , V_85 , & V_78 , & V_79 ) )
continue;
if ( V_78 != NULL ) {
F_53 ( V_85 , V_78 , V_79 , V_80 ) ;
F_51 ( V_78 ) ;
}
V_124 = 1 ;
break;
}
F_21 ( & V_122 ) ;
return V_124 ;
}
static int T_2 F_80 ( char * V_68 )
{
struct V_120 * V_3 ;
char * error ;
int V_77 , V_5 ;
V_5 = F_72 ( V_68 , & V_77 , & V_68 , & error ) ;
if ( V_5 ) {
F_18 ( V_32 L_26 ,
V_68 , error ) ;
return 1 ;
}
V_3 = F_81 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL ) {
F_18 ( V_32 L_27 ) ;
return 1 ;
}
F_56 ( & V_3 -> V_47 ) ;
V_3 -> V_85 = V_77 ;
V_3 -> V_78 = V_68 ;
F_82 ( & V_3 -> V_47 , & V_125 ) ;
return 1 ;
}
static int F_83 ( char * V_68 , char * * V_112 )
{
int V_77 , V_5 ;
V_5 = F_72 ( V_68 , & V_77 , & V_68 , V_112 ) ;
if ( V_5 )
return V_5 ;
V_68 = F_84 ( V_68 , V_83 ) ;
if ( V_68 == NULL ) {
* V_112 = L_28 ;
return - V_9 ;
}
V_5 = ! F_79 ( V_68 , V_77 ) ;
if ( V_5 )
F_51 ( V_68 ) ;
return V_5 ;
}
static int F_85 ( char * * V_68 , int * V_126 , int * V_127 )
{
char * V_70 ;
int V_77 ;
V_77 = F_44 ( * V_68 , & V_70 , 0 ) ;
if ( ( * V_70 != '\0' ) || ( V_70 == * V_68 ) )
return - 1 ;
* V_126 = V_77 ;
* V_127 = V_77 ;
* V_68 = V_70 ;
return V_77 ;
}
static int F_86 ( int V_77 , char * * V_112 )
{
struct V_75 * V_74 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_74 = F_69 ( V_77 ) ;
if ( V_74 == NULL )
return - V_128 ;
V_12 = V_74 -> V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_19 > 0 )
return - V_129 ;
F_87 ( V_12 ) ;
F_68 ( & V_74 -> V_88 ) ;
return 0 ;
}
static int F_88 ( struct V_130 * V_131 , unsigned long V_132 ,
void * V_133 )
{
struct V_134 * V_135 = V_133 ;
struct V_11 * V_12 = V_135 -> V_136 -> V_12 ;
struct V_13 * V_14 ;
void (* F_89)( unsigned char * , unsigned char * , void * );
unsigned char V_137 [ 4 ] , V_138 [ 4 ] ;
if ( V_12 -> V_99 -> V_139 != F_22 )
return V_140 ;
V_14 = F_8 ( V_12 ) ;
F_89 = NULL ;
switch ( V_132 ) {
case V_141 :
F_89 = V_14 -> V_93 ;
break;
case V_142 :
F_89 = V_14 -> V_94 ;
break;
}
if ( F_89 != NULL ) {
memcpy ( V_137 , & V_135 -> V_143 , sizeof( V_137 ) ) ;
memcpy ( V_138 , & V_135 -> V_144 , sizeof( V_138 ) ) ;
(* F_89)( V_137 , V_138 , & V_14 -> V_38 ) ;
}
return V_140 ;
}
static void F_90 ( void )
{
struct V_108 * V_109 ;
struct V_13 * V_14 ;
struct V_145 * V_146 ;
struct V_134 * V_147 ;
F_91 ( & V_148 ) ;
F_17 ( & V_46 ) ;
F_70 (ele, &opened) {
V_14 = F_71 ( V_109 , struct V_13 , V_47 ) ;
V_146 = V_14 -> V_12 -> V_149 ;
if ( V_146 == NULL )
continue;
V_147 = V_146 -> V_150 ;
while ( V_147 != NULL ) {
F_88 ( NULL , V_141 , V_147 ) ;
V_147 = V_147 -> V_151 ;
}
}
F_21 ( & V_46 ) ;
}
static inline void F_90 ( void )
{
}
static int F_92 ( void )
{
F_93 ( & V_152 ) ;
F_90 () ;
return 0 ;
}
static void F_94 ( void )
{
struct V_108 * V_109 ;
struct V_13 * V_14 ;
F_17 ( & V_46 ) ;
F_70 (ele, &opened) {
V_14 = F_71 ( V_109 , struct V_13 , V_47 ) ;
F_28 ( V_14 -> V_12 -> V_28 , V_14 -> V_12 ) ;
if ( ( V_14 -> V_49 != NULL ) && ( V_14 -> V_19 >= 0 ) )
(* V_14 -> V_49 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
}
F_21 ( & V_46 ) ;
}
void F_95 ( void * V_153 , void (* F_96)( unsigned char * , unsigned char * ,
void * ) ,
void * V_154 )
{
struct V_11 * V_12 = V_153 ;
struct V_145 * V_146 = V_12 -> V_149 ;
struct V_134 * V_147 ;
unsigned char V_155 [ 4 ] , V_156 [ 4 ] ;
if ( V_146 == NULL ) return;
V_147 = V_146 -> V_150 ;
while ( V_147 != NULL ) {
memcpy ( V_155 , & V_147 -> V_143 , sizeof( V_155 ) ) ;
memcpy ( V_156 , & V_147 -> V_144 , sizeof( V_156 ) ) ;
(* F_96)( V_155 , V_156 , V_154 ) ;
V_147 = V_147 -> V_151 ;
}
}
int F_97 ( void * V_153 , void * V_157 )
{
struct V_11 * V_12 = V_153 ;
struct V_145 * V_146 = V_12 -> V_149 ;
struct V_134 * V_147 ;
T_3 * V_158 = V_157 ;
if ( V_146 == NULL )
return 1 ;
V_147 = V_146 -> V_150 ;
if ( V_147 == NULL )
return 1 ;
* V_158 = V_147 -> V_144 ;
return 0 ;
}
void * F_98 ( int * V_159 )
{
void * V_160 ;
V_160 = ( void * ) F_99 ( V_83 , 0 ) ;
if ( V_160 ) * V_159 = V_161 ;
else * V_159 = 0 ;
return V_160 ;
}
void F_100 ( void * V_162 )
{
F_101 ( ( unsigned long ) V_162 , 0 ) ;
}
int F_102 ( char * V_68 , char * type , char * * V_163 , char * * V_116 ,
char * * V_164 )
{
char * V_165 ;
V_165 = F_103 ( V_68 , V_163 , V_116 , V_164 , NULL ) ;
if ( V_165 != NULL ) {
F_18 ( V_32 L_29
L_30 , V_165 ) ;
return 1 ;
}
return 0 ;
}
unsigned short F_104 ( struct V_2 * V_16 )
{
return F_105 ( V_16 , V_16 -> V_12 ) ;
}
