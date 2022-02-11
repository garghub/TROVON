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
F_32 ( V_12 ) ;
F_24 ( V_12 ) ;
F_33 ( V_12 ) ;
}
else if ( V_24 == 0 ) {
F_24 ( V_12 ) ;
V_12 -> V_20 . V_52 ++ ;
}
else {
F_24 ( V_12 ) ;
F_18 ( V_32 L_3 , V_24 ) ;
}
F_6 ( & V_14 -> V_31 , V_4 ) ;
F_34 ( V_16 ) ;
return V_53 ;
}
static void F_35 ( struct V_11 * V_12 )
{
return;
}
static void F_36 ( struct V_11 * V_12 )
{
F_32 ( V_12 ) ;
F_33 ( V_12 ) ;
}
static int F_37 ( struct V_11 * V_12 , int V_54 )
{
V_12 -> V_55 = V_54 ;
return 0 ;
}
static void F_38 ( struct V_11 * V_12 )
{
F_39 ( V_12 -> V_28 ) ;
F_15 ( V_12 -> V_28 , V_12 ) ;
F_40 ( V_12 -> V_28 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
struct V_56 * V_57 )
{
F_42 ( V_57 -> V_58 , V_59 , sizeof( V_57 -> V_58 ) ) ;
F_42 ( V_57 -> V_60 , L_4 , sizeof( V_57 -> V_60 ) ) ;
}
static void F_43 ( unsigned long V_61 )
{
#ifdef undef
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
F_44 ( V_64 L_5 , V_63 ) ;
F_45 ( V_63 ) ;
#endif
}
static void F_46 ( struct V_11 * V_12 , char * V_65 )
{
unsigned char * V_66 = V_12 -> V_67 ;
char * V_68 ;
int V_69 ;
if ( V_65 == NULL )
goto V_70;
for ( V_69 = 0 ; V_69 < 6 ; V_69 ++ ) {
V_66 [ V_69 ] = F_47 ( V_65 , & V_68 , 16 ) ;
if ( ( V_68 == V_65 ) ||
( ( * V_68 != ':' ) && ( * V_68 != ',' ) && ( * V_68 != '\0' ) ) ) {
F_18 ( V_32
L_6
L_7 , V_65 ) ;
goto V_70;
}
V_65 = V_68 + 1 ;
}
if ( F_48 ( V_66 ) ) {
F_18 ( V_32
L_8
L_9 ) ;
goto V_70;
}
if ( ! F_49 ( V_66 ) ) {
F_18 ( V_32
L_10
L_9 ) ;
goto V_70;
}
if ( ! F_50 ( V_66 ) ) {
F_18 ( V_71
L_11
L_12 ) ;
F_18 ( V_71 L_13
L_14 ) ;
F_18 ( V_71 L_15 ,
V_66 [ 0 ] | 0x02 , V_66 [ 1 ] , V_66 [ 2 ] , V_66 [ 3 ] , V_66 [ 4 ] ,
V_66 [ 5 ] ) ;
}
return;
V_70:
F_18 ( V_64
L_16 , V_12 -> V_33 ) ;
F_51 ( V_12 ) ;
}
static void F_52 ( struct V_72 * V_12 )
{
struct V_73 * V_72 = F_53 ( V_12 ) ;
struct V_11 * V_74 = V_72 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_74 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
F_29 ( & V_72 -> V_46 ) ;
F_54 ( V_72 ) ;
F_55 ( V_74 ) ;
}
static void F_56 ( int V_75 , void * V_76 , char * V_77 ,
struct V_78 * V_78 , T_2 V_79 )
{
struct V_73 * V_72 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_5 , V_80 ;
V_80 = V_78 -> V_81 + sizeof( struct V_13 ) ;
V_72 = F_57 ( sizeof( * V_72 ) , V_79 ) ;
if ( V_72 == NULL ) {
F_18 ( V_32 L_17
L_18 ) ;
return;
}
V_12 = F_58 ( V_80 ) ;
if ( V_12 == NULL ) {
F_18 ( V_32 L_19
L_20 , V_75 ) ;
goto V_82;
}
F_59 ( & V_72 -> V_46 ) ;
V_72 -> V_83 = V_75 ;
snprintf ( V_12 -> V_33 , sizeof( V_12 -> V_33 ) , L_21 , V_75 ) ;
F_46 ( V_12 , V_77 ) ;
F_18 ( V_64 L_22 , V_75 , V_12 -> V_67 ) ;
V_14 = F_8 ( V_12 ) ;
memset ( V_14 , 0 , V_80 ) ;
F_60 ( & V_14 -> V_27 , F_12 ) ;
if ( ! V_84 ) {
F_61 ( & V_85 ) ;
V_84 = 1 ;
}
V_72 -> V_86 . V_87 = V_75 ;
V_72 -> V_86 . V_33 = V_59 ;
V_72 -> V_86 . V_12 . V_88 = F_52 ;
F_62 ( & V_72 -> V_86 . V_12 , V_72 ) ;
if ( F_63 ( & V_72 -> V_86 ) )
goto V_89;
F_64 ( V_12 , & V_72 -> V_86 . V_12 ) ;
V_72 -> V_12 = V_12 ;
(* V_78 -> V_90 -> V_76 )( V_12 , V_76 ) ;
* V_14 = ( (struct V_13 )
{ . V_46 = F_65 ( V_14 -> V_46 ) ,
. V_12 = V_12 ,
. V_19 = - 1 ,
. V_77 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_17 = V_78 -> V_38 -> V_17 ,
. V_22 = V_78 -> V_90 -> V_22 ,
. V_37 = V_78 -> V_38 -> V_37 ,
. V_48 = V_78 -> V_38 -> V_48 ,
. remove = V_78 -> V_38 -> remove ,
. V_18 = V_78 -> V_90 -> V_18 ,
. V_49 = V_78 -> V_90 -> V_49 ,
. V_91 = V_78 -> V_38 -> V_91 ,
. V_92 = V_78 -> V_38 -> V_92 } ) ;
F_66 ( & V_14 -> V_43 ) ;
F_67 ( & V_14 -> V_31 ) ;
V_14 -> V_43 . V_93 = F_43 ;
memcpy ( V_14 -> V_77 , V_12 -> V_67 , sizeof( V_14 -> V_77 ) ) ;
if ( ( V_78 -> V_38 -> V_76 != NULL ) &&
( (* V_78 -> V_38 -> V_76 )( & V_14 -> V_38 , V_12 ) != 0 ) )
goto V_94;
V_12 -> V_55 = V_78 -> V_38 -> V_55 ;
V_12 -> V_95 = & V_96 ;
V_12 -> V_97 = & V_98 ;
V_12 -> V_99 = ( V_100 >> 1 ) ;
V_12 -> V_28 = V_34 ;
V_5 = F_1 ( V_14 -> V_17 ) ;
if ( V_5 )
goto V_101;
F_68 () ;
V_5 = F_69 ( V_12 ) ;
F_70 () ;
if ( V_5 )
goto V_101;
F_17 ( & V_102 ) ;
F_25 ( & V_72 -> V_46 , & V_103 ) ;
F_21 ( & V_102 ) ;
return;
V_101:
if ( V_78 -> V_38 -> remove != NULL )
(* V_78 -> V_38 -> remove )( & V_14 -> V_38 ) ;
V_94:
F_71 ( & V_72 -> V_86 ) ;
return;
V_89:
F_55 ( V_12 ) ;
V_82:
F_54 ( V_72 ) ;
}
static struct V_73 * F_72 ( int V_75 )
{
struct V_73 * V_72 ;
struct V_104 * V_105 ;
F_17 ( & V_102 ) ;
F_73 (ele, &devices) {
V_72 = F_74 ( V_105 , struct V_73 , V_46 ) ;
if ( V_72 -> V_83 == V_75 )
goto V_8;
}
V_72 = NULL ;
V_8:
F_21 ( & V_102 ) ;
return V_72 ;
}
static int F_75 ( char * V_65 , int * V_106 , char * * V_107 ,
char * * V_108 )
{
char * V_68 ;
int V_75 , V_5 = - V_109 ;
V_75 = F_47 ( V_65 , & V_68 , 0 ) ;
if ( V_68 == V_65 ) {
* V_108 = L_23 ;
return V_5 ;
}
V_65 = V_68 ;
if ( * V_65 != '=' ) {
* V_108 = L_24 ;
return V_5 ;
}
V_65 ++ ;
if ( F_72 ( V_75 ) ) {
* V_108 = L_25 ;
return V_5 ;
}
* V_106 = V_75 ;
* V_107 = V_65 ;
return 0 ;
}
static int F_76 ( struct V_78 * V_78 , char * V_110 , int V_75 ,
void * * V_111 , char * * V_112 , T_2 V_79 )
{
int V_24 ;
V_24 = strlen ( V_78 -> V_33 ) ;
if ( strncmp ( V_110 , V_78 -> V_33 , V_24 ) )
return 0 ;
V_110 += V_24 ;
if ( * V_110 == ',' )
V_110 ++ ;
else if ( * V_110 != '\0' )
return 0 ;
* V_111 = F_77 ( V_78 -> V_113 , V_79 ) ;
if ( * V_111 == NULL )
return 1 ;
if ( ! V_78 -> V_114 ( V_110 , V_112 , * V_111 ) ) {
F_54 ( * V_111 ) ;
* V_111 = NULL ;
}
return 1 ;
}
void F_78 ( struct V_78 * V_3 )
{
struct V_104 * V_105 , * V_115 ;
struct V_116 * V_110 ;
void * V_76 ;
char * V_77 = NULL ;
int V_117 ;
F_17 ( & V_118 ) ;
F_79 ( ! F_80 ( & V_3 -> V_46 ) ) ;
F_25 ( & V_3 -> V_46 , & V_119 ) ;
F_21 ( & V_118 ) ;
F_81 (ele, next, &eth_cmd_line) {
V_110 = F_74 ( V_105 , struct V_116 , V_46 ) ;
V_117 = F_76 ( V_3 , V_110 -> V_76 , V_110 -> V_83 , & V_76 ,
& V_77 , V_120 ) ;
if ( ! V_117 )
continue;
else if ( V_76 != NULL ) {
F_56 ( V_110 -> V_83 , V_76 , V_77 , V_3 , V_120 ) ;
F_54 ( V_76 ) ;
}
F_29 ( & V_110 -> V_46 ) ;
}
}
static int F_82 ( char * V_65 , int V_83 )
{
struct V_104 * V_105 ;
struct V_78 * V_78 ;
void * V_76 ;
char * V_77 = NULL ;
int V_121 = 0 ;
F_17 ( & V_118 ) ;
F_73 (ele, &transports) {
V_78 = F_74 ( V_105 , struct V_78 , V_46 ) ;
if ( ! F_76 ( V_78 , V_65 , V_83 , & V_76 ,
& V_77 , V_122 ) )
continue;
if ( V_76 != NULL ) {
F_56 ( V_83 , V_76 , V_77 , V_78 , V_122 ) ;
F_54 ( V_76 ) ;
}
V_121 = 1 ;
break;
}
F_21 ( & V_118 ) ;
return V_121 ;
}
static int T_3 F_83 ( char * V_65 )
{
struct V_116 * V_3 ;
char * error ;
int V_75 , V_5 ;
V_5 = F_75 ( V_65 , & V_75 , & V_65 , & error ) ;
if ( V_5 ) {
F_18 ( V_32 L_26 ,
V_65 , error ) ;
return 1 ;
}
V_3 = F_84 ( sizeof( * V_3 ) ) ;
F_59 ( & V_3 -> V_46 ) ;
V_3 -> V_83 = V_75 ;
V_3 -> V_76 = V_65 ;
F_85 ( & V_3 -> V_46 , & V_123 ) ;
return 1 ;
}
static int F_86 ( char * V_65 , char * * V_108 )
{
int V_75 , V_5 ;
V_5 = F_75 ( V_65 , & V_75 , & V_65 , V_108 ) ;
if ( V_5 )
return V_5 ;
V_65 = F_87 ( V_65 , V_120 ) ;
if ( V_65 == NULL ) {
* V_108 = L_27 ;
return - V_9 ;
}
V_5 = ! F_82 ( V_65 , V_75 ) ;
if ( V_5 )
F_54 ( V_65 ) ;
return V_5 ;
}
static int F_88 ( char * * V_65 , int * V_124 , int * V_125 )
{
char * V_68 ;
int V_75 ;
V_75 = F_47 ( * V_65 , & V_68 , 0 ) ;
if ( ( * V_68 != '\0' ) || ( V_68 == * V_65 ) )
return - 1 ;
* V_124 = V_75 ;
* V_125 = V_75 ;
* V_65 = V_68 ;
return V_75 ;
}
static int F_89 ( int V_75 , char * * V_108 )
{
struct V_73 * V_72 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_72 = F_72 ( V_75 ) ;
if ( V_72 == NULL )
return - V_126 ;
V_12 = V_72 -> V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_19 > 0 )
return - V_127 ;
F_90 ( V_12 ) ;
F_71 ( & V_72 -> V_86 ) ;
return 0 ;
}
static int F_91 ( struct V_128 * V_129 , unsigned long V_130 ,
void * V_131 )
{
struct V_132 * V_133 = V_131 ;
struct V_11 * V_12 = V_133 -> V_134 -> V_12 ;
struct V_13 * V_14 ;
void (* F_92)( unsigned char * , unsigned char * , void * );
unsigned char V_135 [ 4 ] , V_136 [ 4 ] ;
if ( V_12 -> V_95 -> V_137 != F_22 )
return V_138 ;
V_14 = F_8 ( V_12 ) ;
F_92 = NULL ;
switch ( V_130 ) {
case V_139 :
F_92 = V_14 -> V_91 ;
break;
case V_140 :
F_92 = V_14 -> V_92 ;
break;
}
if ( F_92 != NULL ) {
memcpy ( V_135 , & V_133 -> V_141 , sizeof( V_135 ) ) ;
memcpy ( V_136 , & V_133 -> V_142 , sizeof( V_136 ) ) ;
(* F_92)( V_135 , V_136 , & V_14 -> V_38 ) ;
}
return V_138 ;
}
static void F_93 ( void )
{
struct V_104 * V_105 ;
struct V_13 * V_14 ;
struct V_143 * V_144 ;
struct V_132 * V_145 ;
F_94 ( & V_146 ) ;
F_17 ( & V_45 ) ;
F_73 (ele, &opened) {
V_14 = F_74 ( V_105 , struct V_13 , V_46 ) ;
V_144 = V_14 -> V_12 -> V_147 ;
if ( V_144 == NULL )
continue;
V_145 = V_144 -> V_148 ;
while ( V_145 != NULL ) {
F_91 ( NULL , V_139 , V_145 ) ;
V_145 = V_145 -> V_149 ;
}
}
F_21 ( & V_45 ) ;
}
static inline void F_93 ( void )
{
}
static int F_95 ( void )
{
F_96 ( & V_150 ) ;
F_93 () ;
return 0 ;
}
static void F_97 ( void )
{
struct V_104 * V_105 ;
struct V_13 * V_14 ;
F_17 ( & V_45 ) ;
F_73 (ele, &opened) {
V_14 = F_74 ( V_105 , struct V_13 , V_46 ) ;
F_28 ( V_14 -> V_12 -> V_28 , V_14 -> V_12 ) ;
if ( ( V_14 -> V_48 != NULL ) && ( V_14 -> V_19 >= 0 ) )
(* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
}
F_21 ( & V_45 ) ;
}
void F_98 ( void * V_151 , void (* F_99)( unsigned char * , unsigned char * ,
void * ) ,
void * V_152 )
{
struct V_11 * V_12 = V_151 ;
struct V_143 * V_144 = V_12 -> V_147 ;
struct V_132 * V_145 ;
unsigned char V_153 [ 4 ] , V_154 [ 4 ] ;
if ( V_144 == NULL ) return;
V_145 = V_144 -> V_148 ;
while ( V_145 != NULL ) {
memcpy ( V_153 , & V_145 -> V_141 , sizeof( V_153 ) ) ;
memcpy ( V_154 , & V_145 -> V_142 , sizeof( V_154 ) ) ;
(* F_99)( V_153 , V_154 , V_152 ) ;
V_145 = V_145 -> V_149 ;
}
}
int F_100 ( void * V_151 , void * V_155 )
{
struct V_11 * V_12 = V_151 ;
struct V_143 * V_144 = V_12 -> V_147 ;
struct V_132 * V_145 ;
T_4 * V_156 = V_155 ;
if ( V_144 == NULL )
return 1 ;
V_145 = V_144 -> V_148 ;
if ( V_145 == NULL )
return 1 ;
* V_156 = V_145 -> V_142 ;
return 0 ;
}
void * F_101 ( int * V_157 )
{
void * V_158 ;
V_158 = ( void * ) F_102 ( V_120 , 0 ) ;
if ( V_158 ) * V_157 = V_159 ;
else * V_157 = 0 ;
return V_158 ;
}
void F_103 ( void * V_160 )
{
F_104 ( ( unsigned long ) V_160 , 0 ) ;
}
int F_105 ( char * V_65 , char * type , char * * V_161 , char * * V_112 ,
char * * V_162 )
{
char * V_163 ;
V_163 = F_106 ( V_65 , V_161 , V_112 , V_162 , NULL ) ;
if ( V_163 != NULL ) {
F_18 ( V_32 L_28
L_29 , V_163 ) ;
return 1 ;
}
return 0 ;
}
unsigned short F_107 ( struct V_2 * V_16 )
{
return F_108 ( V_16 , V_16 -> V_12 ) ;
}
