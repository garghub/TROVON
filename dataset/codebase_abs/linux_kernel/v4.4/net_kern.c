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
V_40 , V_12 -> V_33 , V_12 ) ;
if ( V_5 != 0 ) {
F_18 ( V_32 L_2 , V_5 ) ;
V_5 = - V_41 ;
goto V_42;
}
V_14 -> V_43 . V_44 = ( unsigned long ) & V_14 -> V_38 ;
F_24 ( V_12 ) ;
while ( ( V_5 = F_7 ( V_12 ) ) > 0 ) ;
F_17 ( & V_45 ) ;
F_25 ( & V_14 -> V_46 , & V_47 ) ;
F_21 ( & V_45 ) ;
return 0 ;
V_42:
if ( V_14 -> V_48 != NULL ) (* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
V_14 -> V_19 = - 1 ;
V_8:
return V_5 ;
}
static int F_26 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
F_27 ( V_12 ) ;
F_28 ( V_12 -> V_28 , V_12 ) ;
if ( V_14 -> V_48 != NULL )
(* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
V_14 -> V_19 = - 1 ;
F_17 ( & V_45 ) ;
F_29 ( & V_14 -> V_46 ) ;
F_21 ( & V_45 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_16 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
unsigned long V_4 ;
int V_24 ;
F_27 ( V_12 ) ;
F_2 ( & V_14 -> V_31 , V_4 ) ;
V_24 = (* V_14 -> V_49 )( V_14 -> V_19 , V_16 , V_14 ) ;
F_31 ( V_16 ) ;
if ( V_24 == V_16 -> V_24 ) {
V_12 -> V_20 . V_50 ++ ;
V_12 -> V_20 . V_51 += V_16 -> V_24 ;
V_12 -> V_52 = V_53 ;
F_24 ( V_12 ) ;
F_32 ( V_12 ) ;
}
else if ( V_24 == 0 ) {
F_24 ( V_12 ) ;
V_12 -> V_20 . V_54 ++ ;
}
else {
F_24 ( V_12 ) ;
F_18 ( V_32 L_3 , V_24 ) ;
}
F_6 ( & V_14 -> V_31 , V_4 ) ;
F_33 ( V_16 ) ;
return V_55 ;
}
static void F_34 ( struct V_11 * V_12 )
{
return;
}
static void F_35 ( struct V_11 * V_12 )
{
V_12 -> V_52 = V_53 ;
F_32 ( V_12 ) ;
}
static int F_36 ( struct V_11 * V_12 , int V_56 )
{
V_12 -> V_57 = V_56 ;
return 0 ;
}
static void F_37 ( struct V_11 * V_12 )
{
F_38 ( V_12 -> V_28 ) ;
F_15 ( V_12 -> V_28 , V_12 ) ;
F_39 ( V_12 -> V_28 ) ;
}
static void F_40 ( struct V_11 * V_12 ,
struct V_58 * V_59 )
{
F_41 ( V_59 -> V_60 , V_61 , sizeof( V_59 -> V_60 ) ) ;
F_41 ( V_59 -> V_62 , L_4 , sizeof( V_59 -> V_62 ) ) ;
}
static void F_42 ( unsigned long V_63 )
{
#ifdef undef
struct V_64 * V_65 = (struct V_64 * ) V_63 ;
F_43 ( V_66 L_5 , V_65 ) ;
F_44 ( V_65 ) ;
#endif
}
static void F_45 ( struct V_11 * V_12 , char * V_67 )
{
unsigned char * V_68 = V_12 -> V_69 ;
char * V_70 ;
int V_71 ;
if ( V_67 == NULL )
goto V_72;
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ ) {
V_68 [ V_71 ] = F_46 ( V_67 , & V_70 , 16 ) ;
if ( ( V_70 == V_67 ) ||
( ( * V_70 != ':' ) && ( * V_70 != ',' ) && ( * V_70 != '\0' ) ) ) {
F_18 ( V_32
L_6
L_7 , V_67 ) ;
goto V_72;
}
V_67 = V_70 + 1 ;
}
if ( F_47 ( V_68 ) ) {
F_18 ( V_32
L_8
L_9 ) ;
goto V_72;
}
if ( ! F_48 ( V_68 ) ) {
F_18 ( V_32
L_10
L_9 ) ;
goto V_72;
}
if ( ! F_49 ( V_68 ) ) {
F_18 ( V_73
L_11
L_12 ) ;
F_18 ( V_73 L_13
L_14 ) ;
F_18 ( V_73 L_15 ,
V_68 [ 0 ] | 0x02 , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] , V_68 [ 4 ] ,
V_68 [ 5 ] ) ;
}
return;
V_72:
F_18 ( V_66
L_16 , V_12 -> V_33 ) ;
F_50 ( V_12 ) ;
}
static void F_51 ( struct V_74 * V_12 )
{
struct V_75 * V_74 = F_52 ( V_12 ) ;
struct V_11 * V_76 = V_74 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_76 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
F_29 ( & V_74 -> V_46 ) ;
F_53 ( V_74 ) ;
F_54 ( V_76 ) ;
}
static void F_55 ( int V_77 , void * V_78 , char * V_79 ,
struct V_80 * V_80 , T_2 V_81 )
{
struct V_75 * V_74 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_5 , V_82 ;
V_82 = V_80 -> V_83 + sizeof( struct V_13 ) ;
V_74 = F_56 ( sizeof( * V_74 ) , V_81 ) ;
if ( V_74 == NULL ) {
F_18 ( V_32 L_17
L_18 ) ;
return;
}
V_12 = F_57 ( V_82 ) ;
if ( V_12 == NULL ) {
F_18 ( V_32 L_19
L_20 , V_77 ) ;
goto V_84;
}
F_58 ( & V_74 -> V_46 ) ;
V_74 -> V_85 = V_77 ;
snprintf ( V_12 -> V_33 , sizeof( V_12 -> V_33 ) , L_21 , V_77 ) ;
F_45 ( V_12 , V_79 ) ;
F_18 ( V_66 L_22 , V_77 , V_12 -> V_69 ) ;
V_14 = F_8 ( V_12 ) ;
memset ( V_14 , 0 , V_82 ) ;
F_59 ( & V_14 -> V_27 , F_12 ) ;
if ( ! V_86 ) {
F_60 ( & V_87 ) ;
V_86 = 1 ;
}
V_74 -> V_88 . V_89 = V_77 ;
V_74 -> V_88 . V_33 = V_61 ;
V_74 -> V_88 . V_12 . V_90 = F_51 ;
F_61 ( & V_74 -> V_88 . V_12 , V_74 ) ;
if ( F_62 ( & V_74 -> V_88 ) )
goto V_91;
F_63 ( V_12 , & V_74 -> V_88 . V_12 ) ;
V_74 -> V_12 = V_12 ;
(* V_80 -> V_92 -> V_78 )( V_12 , V_78 ) ;
* V_14 = ( (struct V_13 )
{ . V_46 = F_64 ( V_14 -> V_46 ) ,
. V_12 = V_12 ,
. V_19 = - 1 ,
. V_79 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_17 = V_80 -> V_38 -> V_17 ,
. V_22 = V_80 -> V_92 -> V_22 ,
. V_37 = V_80 -> V_38 -> V_37 ,
. V_48 = V_80 -> V_38 -> V_48 ,
. remove = V_80 -> V_38 -> remove ,
. V_18 = V_80 -> V_92 -> V_18 ,
. V_49 = V_80 -> V_92 -> V_49 ,
. V_93 = V_80 -> V_38 -> V_93 ,
. V_94 = V_80 -> V_38 -> V_94 } ) ;
F_65 ( & V_14 -> V_43 ) ;
F_66 ( & V_14 -> V_31 ) ;
V_14 -> V_43 . V_95 = F_42 ;
memcpy ( V_14 -> V_79 , V_12 -> V_69 , sizeof( V_14 -> V_79 ) ) ;
if ( ( V_80 -> V_38 -> V_78 != NULL ) &&
( (* V_80 -> V_38 -> V_78 )( & V_14 -> V_38 , V_12 ) != 0 ) )
goto V_96;
V_12 -> V_57 = V_80 -> V_38 -> V_57 ;
V_12 -> V_97 = & V_98 ;
V_12 -> V_99 = & V_100 ;
V_12 -> V_101 = ( V_102 >> 1 ) ;
V_12 -> V_28 = V_34 ;
V_5 = F_1 ( V_14 -> V_17 ) ;
if ( V_5 )
goto V_103;
F_67 () ;
V_5 = F_68 ( V_12 ) ;
F_69 () ;
if ( V_5 )
goto V_103;
F_17 ( & V_104 ) ;
F_25 ( & V_74 -> V_46 , & V_105 ) ;
F_21 ( & V_104 ) ;
return;
V_103:
if ( V_80 -> V_38 -> remove != NULL )
(* V_80 -> V_38 -> remove )( & V_14 -> V_38 ) ;
V_96:
F_70 ( & V_74 -> V_88 ) ;
return;
V_91:
F_54 ( V_12 ) ;
V_84:
F_53 ( V_74 ) ;
}
static struct V_75 * F_71 ( int V_77 )
{
struct V_75 * V_74 ;
struct V_106 * V_107 ;
F_17 ( & V_104 ) ;
F_72 (ele, &devices) {
V_74 = F_73 ( V_107 , struct V_75 , V_46 ) ;
if ( V_74 -> V_85 == V_77 )
goto V_8;
}
V_74 = NULL ;
V_8:
F_21 ( & V_104 ) ;
return V_74 ;
}
static int F_74 ( char * V_67 , int * V_108 , char * * V_109 ,
char * * V_110 )
{
char * V_70 ;
int V_77 , V_5 = - V_111 ;
V_77 = F_46 ( V_67 , & V_70 , 0 ) ;
if ( V_70 == V_67 ) {
* V_110 = L_23 ;
return V_5 ;
}
V_67 = V_70 ;
if ( * V_67 != '=' ) {
* V_110 = L_24 ;
return V_5 ;
}
V_67 ++ ;
if ( F_71 ( V_77 ) ) {
* V_110 = L_25 ;
return V_5 ;
}
* V_108 = V_77 ;
* V_109 = V_67 ;
return 0 ;
}
static int F_75 ( struct V_80 * V_80 , char * V_112 , int V_77 ,
void * * V_113 , char * * V_114 , T_2 V_81 )
{
int V_24 ;
V_24 = strlen ( V_80 -> V_33 ) ;
if ( strncmp ( V_112 , V_80 -> V_33 , V_24 ) )
return 0 ;
V_112 += V_24 ;
if ( * V_112 == ',' )
V_112 ++ ;
else if ( * V_112 != '\0' )
return 0 ;
* V_113 = F_76 ( V_80 -> V_115 , V_81 ) ;
if ( * V_113 == NULL )
return 1 ;
if ( ! V_80 -> V_116 ( V_112 , V_114 , * V_113 ) ) {
F_53 ( * V_113 ) ;
* V_113 = NULL ;
}
return 1 ;
}
void F_77 ( struct V_80 * V_3 )
{
struct V_106 * V_107 , * V_117 ;
struct V_118 * V_112 ;
void * V_78 ;
char * V_79 = NULL ;
int V_119 ;
F_17 ( & V_120 ) ;
F_78 ( ! F_79 ( & V_3 -> V_46 ) ) ;
F_25 ( & V_3 -> V_46 , & V_121 ) ;
F_21 ( & V_120 ) ;
F_80 (ele, next, &eth_cmd_line) {
V_112 = F_73 ( V_107 , struct V_118 , V_46 ) ;
V_119 = F_75 ( V_3 , V_112 -> V_78 , V_112 -> V_85 , & V_78 ,
& V_79 , V_122 ) ;
if ( ! V_119 )
continue;
else if ( V_78 != NULL ) {
F_55 ( V_112 -> V_85 , V_78 , V_79 , V_3 , V_122 ) ;
F_53 ( V_78 ) ;
}
F_29 ( & V_112 -> V_46 ) ;
}
}
static int F_81 ( char * V_67 , int V_85 )
{
struct V_106 * V_107 ;
struct V_80 * V_80 ;
void * V_78 ;
char * V_79 = NULL ;
int V_123 = 0 ;
F_17 ( & V_120 ) ;
F_72 (ele, &transports) {
V_80 = F_73 ( V_107 , struct V_80 , V_46 ) ;
if ( ! F_75 ( V_80 , V_67 , V_85 , & V_78 ,
& V_79 , V_124 ) )
continue;
if ( V_78 != NULL ) {
F_55 ( V_85 , V_78 , V_79 , V_80 , V_124 ) ;
F_53 ( V_78 ) ;
}
V_123 = 1 ;
break;
}
F_21 ( & V_120 ) ;
return V_123 ;
}
static int T_3 F_82 ( char * V_67 )
{
struct V_118 * V_3 ;
char * error ;
int V_77 , V_5 ;
V_5 = F_74 ( V_67 , & V_77 , & V_67 , & error ) ;
if ( V_5 ) {
F_18 ( V_32 L_26 ,
V_67 , error ) ;
return 1 ;
}
V_3 = F_83 ( sizeof( * V_3 ) ) ;
F_58 ( & V_3 -> V_46 ) ;
V_3 -> V_85 = V_77 ;
V_3 -> V_78 = V_67 ;
F_84 ( & V_3 -> V_46 , & V_125 ) ;
return 1 ;
}
static int F_85 ( char * V_67 , char * * V_110 )
{
int V_77 , V_5 ;
V_5 = F_74 ( V_67 , & V_77 , & V_67 , V_110 ) ;
if ( V_5 )
return V_5 ;
V_67 = F_86 ( V_67 , V_122 ) ;
if ( V_67 == NULL ) {
* V_110 = L_27 ;
return - V_9 ;
}
V_5 = ! F_81 ( V_67 , V_77 ) ;
if ( V_5 )
F_53 ( V_67 ) ;
return V_5 ;
}
static int F_87 ( char * * V_67 , int * V_126 , int * V_127 )
{
char * V_70 ;
int V_77 ;
V_77 = F_46 ( * V_67 , & V_70 , 0 ) ;
if ( ( * V_70 != '\0' ) || ( V_70 == * V_67 ) )
return - 1 ;
* V_126 = V_77 ;
* V_127 = V_77 ;
* V_67 = V_70 ;
return V_77 ;
}
static int F_88 ( int V_77 , char * * V_110 )
{
struct V_75 * V_74 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_74 = F_71 ( V_77 ) ;
if ( V_74 == NULL )
return - V_128 ;
V_12 = V_74 -> V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_19 > 0 )
return - V_129 ;
F_89 ( V_12 ) ;
F_70 ( & V_74 -> V_88 ) ;
return 0 ;
}
static int F_90 ( struct V_130 * V_131 , unsigned long V_132 ,
void * V_133 )
{
struct V_134 * V_135 = V_133 ;
struct V_11 * V_12 = V_135 -> V_136 -> V_12 ;
struct V_13 * V_14 ;
void (* F_91)( unsigned char * , unsigned char * , void * );
unsigned char V_137 [ 4 ] , V_138 [ 4 ] ;
if ( V_12 -> V_97 -> V_139 != F_22 )
return V_140 ;
V_14 = F_8 ( V_12 ) ;
F_91 = NULL ;
switch ( V_132 ) {
case V_141 :
F_91 = V_14 -> V_93 ;
break;
case V_142 :
F_91 = V_14 -> V_94 ;
break;
}
if ( F_91 != NULL ) {
memcpy ( V_137 , & V_135 -> V_143 , sizeof( V_137 ) ) ;
memcpy ( V_138 , & V_135 -> V_144 , sizeof( V_138 ) ) ;
(* F_91)( V_137 , V_138 , & V_14 -> V_38 ) ;
}
return V_140 ;
}
static void F_92 ( void )
{
struct V_106 * V_107 ;
struct V_13 * V_14 ;
struct V_145 * V_146 ;
struct V_134 * V_147 ;
F_93 ( & V_148 ) ;
F_17 ( & V_45 ) ;
F_72 (ele, &opened) {
V_14 = F_73 ( V_107 , struct V_13 , V_46 ) ;
V_146 = V_14 -> V_12 -> V_149 ;
if ( V_146 == NULL )
continue;
V_147 = V_146 -> V_150 ;
while ( V_147 != NULL ) {
F_90 ( NULL , V_141 , V_147 ) ;
V_147 = V_147 -> V_151 ;
}
}
F_21 ( & V_45 ) ;
}
static inline void F_92 ( void )
{
}
static int F_94 ( void )
{
F_95 ( & V_152 ) ;
F_92 () ;
return 0 ;
}
static void F_96 ( void )
{
struct V_106 * V_107 ;
struct V_13 * V_14 ;
F_17 ( & V_45 ) ;
F_72 (ele, &opened) {
V_14 = F_73 ( V_107 , struct V_13 , V_46 ) ;
F_28 ( V_14 -> V_12 -> V_28 , V_14 -> V_12 ) ;
if ( ( V_14 -> V_48 != NULL ) && ( V_14 -> V_19 >= 0 ) )
(* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
}
F_21 ( & V_45 ) ;
}
void F_97 ( void * V_153 , void (* F_98)( unsigned char * , unsigned char * ,
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
(* F_98)( V_155 , V_156 , V_154 ) ;
V_147 = V_147 -> V_151 ;
}
}
int F_99 ( void * V_153 , void * V_157 )
{
struct V_11 * V_12 = V_153 ;
struct V_145 * V_146 = V_12 -> V_149 ;
struct V_134 * V_147 ;
T_4 * V_158 = V_157 ;
if ( V_146 == NULL )
return 1 ;
V_147 = V_146 -> V_150 ;
if ( V_147 == NULL )
return 1 ;
* V_158 = V_147 -> V_144 ;
return 0 ;
}
void * F_100 ( int * V_159 )
{
void * V_160 ;
V_160 = ( void * ) F_101 ( V_122 , 0 ) ;
if ( V_160 ) * V_159 = V_161 ;
else * V_159 = 0 ;
return V_160 ;
}
void F_102 ( void * V_162 )
{
F_103 ( ( unsigned long ) V_162 , 0 ) ;
}
int F_104 ( char * V_67 , char * type , char * * V_163 , char * * V_114 ,
char * * V_164 )
{
char * V_165 ;
V_165 = F_105 ( V_67 , V_163 , V_114 , V_164 , NULL ) ;
if ( V_165 != NULL ) {
F_18 ( V_32 L_28
L_29 , V_165 ) ;
return 1 ;
}
return 0 ;
}
unsigned short F_106 ( struct V_2 * V_16 )
{
return F_107 ( V_16 , V_16 -> V_12 ) ;
}
