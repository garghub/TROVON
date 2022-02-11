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
static void F_37 ( struct V_11 * V_12 )
{
F_38 ( V_12 -> V_28 ) ;
F_15 ( V_12 -> V_28 , V_12 ) ;
F_39 ( V_12 -> V_28 ) ;
}
static void F_40 ( struct V_11 * V_12 ,
struct V_54 * V_55 )
{
F_41 ( V_55 -> V_56 , V_57 , sizeof( V_55 -> V_56 ) ) ;
F_41 ( V_55 -> V_58 , L_4 , sizeof( V_55 -> V_58 ) ) ;
}
static void F_42 ( unsigned long V_59 )
{
#ifdef undef
struct V_60 * V_61 = (struct V_60 * ) V_59 ;
F_43 ( V_62 L_5 , V_61 ) ;
F_44 ( V_61 ) ;
#endif
}
static void F_45 ( struct V_11 * V_12 , char * V_63 )
{
unsigned char * V_64 = V_12 -> V_65 ;
char * V_66 ;
int V_67 ;
if ( V_63 == NULL )
goto V_68;
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ ) {
V_64 [ V_67 ] = F_46 ( V_63 , & V_66 , 16 ) ;
if ( ( V_66 == V_63 ) ||
( ( * V_66 != ':' ) && ( * V_66 != ',' ) && ( * V_66 != '\0' ) ) ) {
F_18 ( V_32
L_6
L_7 , V_63 ) ;
goto V_68;
}
V_63 = V_66 + 1 ;
}
if ( F_47 ( V_64 ) ) {
F_18 ( V_32
L_8
L_9 ) ;
goto V_68;
}
if ( ! F_48 ( V_64 ) ) {
F_18 ( V_32
L_10
L_9 ) ;
goto V_68;
}
if ( ! F_49 ( V_64 ) ) {
F_18 ( V_69
L_11
L_12 ) ;
F_18 ( V_69 L_13
L_14 ) ;
F_18 ( V_69 L_15 ,
V_64 [ 0 ] | 0x02 , V_64 [ 1 ] , V_64 [ 2 ] , V_64 [ 3 ] , V_64 [ 4 ] ,
V_64 [ 5 ] ) ;
}
return;
V_68:
F_18 ( V_62
L_16 , V_12 -> V_33 ) ;
F_50 ( V_12 ) ;
}
static void F_51 ( struct V_70 * V_12 )
{
struct V_71 * V_70 = F_52 ( V_12 ) ;
struct V_11 * V_72 = V_70 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_72 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
F_29 ( & V_70 -> V_46 ) ;
F_53 ( V_70 ) ;
F_54 ( V_72 ) ;
}
static void F_55 ( int V_73 , void * V_74 , char * V_75 ,
struct V_76 * V_76 , T_2 V_77 )
{
struct V_71 * V_70 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_5 , V_78 ;
V_78 = V_76 -> V_79 + sizeof( struct V_13 ) ;
V_70 = F_56 ( sizeof( * V_70 ) , V_77 ) ;
if ( V_70 == NULL ) {
F_18 ( V_32 L_17
L_18 ) ;
return;
}
V_12 = F_57 ( V_78 ) ;
if ( V_12 == NULL ) {
F_18 ( V_32 L_19
L_20 , V_73 ) ;
goto V_80;
}
F_58 ( & V_70 -> V_46 ) ;
V_70 -> V_81 = V_73 ;
snprintf ( V_12 -> V_33 , sizeof( V_12 -> V_33 ) , L_21 , V_73 ) ;
F_45 ( V_12 , V_75 ) ;
F_18 ( V_62 L_22 , V_73 , V_12 -> V_65 ) ;
V_14 = F_8 ( V_12 ) ;
memset ( V_14 , 0 , V_78 ) ;
F_59 ( & V_14 -> V_27 , F_12 ) ;
if ( ! V_82 ) {
F_60 ( & V_83 ) ;
V_82 = 1 ;
}
V_70 -> V_84 . V_85 = V_73 ;
V_70 -> V_84 . V_33 = V_57 ;
V_70 -> V_84 . V_12 . V_86 = F_51 ;
F_61 ( & V_70 -> V_84 . V_12 , V_70 ) ;
if ( F_62 ( & V_70 -> V_84 ) )
goto V_87;
F_63 ( V_12 , & V_70 -> V_84 . V_12 ) ;
V_70 -> V_12 = V_12 ;
(* V_76 -> V_88 -> V_74 )( V_12 , V_74 ) ;
* V_14 = ( (struct V_13 )
{ . V_46 = F_64 ( V_14 -> V_46 ) ,
. V_12 = V_12 ,
. V_19 = - 1 ,
. V_75 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_17 = V_76 -> V_38 -> V_17 ,
. V_22 = V_76 -> V_88 -> V_22 ,
. V_37 = V_76 -> V_38 -> V_37 ,
. V_48 = V_76 -> V_38 -> V_48 ,
. remove = V_76 -> V_38 -> remove ,
. V_18 = V_76 -> V_88 -> V_18 ,
. V_49 = V_76 -> V_88 -> V_49 ,
. V_89 = V_76 -> V_38 -> V_89 ,
. V_90 = V_76 -> V_38 -> V_90 } ) ;
F_65 ( & V_14 -> V_43 ) ;
F_66 ( & V_14 -> V_31 ) ;
V_14 -> V_43 . V_91 = F_42 ;
memcpy ( V_14 -> V_75 , V_12 -> V_65 , sizeof( V_14 -> V_75 ) ) ;
if ( ( V_76 -> V_38 -> V_74 != NULL ) &&
( (* V_76 -> V_38 -> V_74 )( & V_14 -> V_38 , V_12 ) != 0 ) )
goto V_92;
V_12 -> V_93 = V_76 -> V_38 -> V_93 ;
V_12 -> V_94 = & V_95 ;
V_12 -> V_96 = & V_97 ;
V_12 -> V_98 = ( V_99 >> 1 ) ;
V_12 -> V_28 = V_34 ;
V_5 = F_1 ( V_14 -> V_17 ) ;
if ( V_5 )
goto V_100;
F_67 () ;
V_5 = F_68 ( V_12 ) ;
F_69 () ;
if ( V_5 )
goto V_100;
F_17 ( & V_101 ) ;
F_25 ( & V_70 -> V_46 , & V_102 ) ;
F_21 ( & V_101 ) ;
return;
V_100:
if ( V_76 -> V_38 -> remove != NULL )
(* V_76 -> V_38 -> remove )( & V_14 -> V_38 ) ;
V_92:
F_70 ( & V_70 -> V_84 ) ;
return;
V_87:
F_54 ( V_12 ) ;
V_80:
F_53 ( V_70 ) ;
}
static struct V_71 * F_71 ( int V_73 )
{
struct V_71 * V_70 ;
struct V_103 * V_104 ;
F_17 ( & V_101 ) ;
F_72 (ele, &devices) {
V_70 = F_73 ( V_104 , struct V_71 , V_46 ) ;
if ( V_70 -> V_81 == V_73 )
goto V_8;
}
V_70 = NULL ;
V_8:
F_21 ( & V_101 ) ;
return V_70 ;
}
static int F_74 ( char * V_63 , int * V_105 , char * * V_106 ,
char * * V_107 )
{
char * V_66 ;
int V_73 , V_5 = - V_108 ;
V_73 = F_46 ( V_63 , & V_66 , 0 ) ;
if ( V_66 == V_63 ) {
* V_107 = L_23 ;
return V_5 ;
}
V_63 = V_66 ;
if ( * V_63 != '=' ) {
* V_107 = L_24 ;
return V_5 ;
}
V_63 ++ ;
if ( F_71 ( V_73 ) ) {
* V_107 = L_25 ;
return V_5 ;
}
* V_105 = V_73 ;
* V_106 = V_63 ;
return 0 ;
}
static int F_75 ( struct V_76 * V_76 , char * V_109 , int V_73 ,
void * * V_110 , char * * V_111 , T_2 V_77 )
{
int V_24 ;
V_24 = strlen ( V_76 -> V_33 ) ;
if ( strncmp ( V_109 , V_76 -> V_33 , V_24 ) )
return 0 ;
V_109 += V_24 ;
if ( * V_109 == ',' )
V_109 ++ ;
else if ( * V_109 != '\0' )
return 0 ;
* V_110 = F_76 ( V_76 -> V_112 , V_77 ) ;
if ( * V_110 == NULL )
return 1 ;
if ( ! V_76 -> V_113 ( V_109 , V_111 , * V_110 ) ) {
F_53 ( * V_110 ) ;
* V_110 = NULL ;
}
return 1 ;
}
void F_77 ( struct V_76 * V_3 )
{
struct V_103 * V_104 , * V_114 ;
struct V_115 * V_109 ;
void * V_74 ;
char * V_75 = NULL ;
int V_116 ;
F_17 ( & V_117 ) ;
F_78 ( ! F_79 ( & V_3 -> V_46 ) ) ;
F_25 ( & V_3 -> V_46 , & V_118 ) ;
F_21 ( & V_117 ) ;
F_80 (ele, next, &eth_cmd_line) {
V_109 = F_73 ( V_104 , struct V_115 , V_46 ) ;
V_116 = F_75 ( V_3 , V_109 -> V_74 , V_109 -> V_81 , & V_74 ,
& V_75 , V_119 ) ;
if ( ! V_116 )
continue;
else if ( V_74 != NULL ) {
F_55 ( V_109 -> V_81 , V_74 , V_75 , V_3 , V_119 ) ;
F_53 ( V_74 ) ;
}
F_29 ( & V_109 -> V_46 ) ;
}
}
static int F_81 ( char * V_63 , int V_81 )
{
struct V_103 * V_104 ;
struct V_76 * V_76 ;
void * V_74 ;
char * V_75 = NULL ;
int V_120 = 0 ;
F_17 ( & V_117 ) ;
F_72 (ele, &transports) {
V_76 = F_73 ( V_104 , struct V_76 , V_46 ) ;
if ( ! F_75 ( V_76 , V_63 , V_81 , & V_74 ,
& V_75 , V_121 ) )
continue;
if ( V_74 != NULL ) {
F_55 ( V_81 , V_74 , V_75 , V_76 , V_121 ) ;
F_53 ( V_74 ) ;
}
V_120 = 1 ;
break;
}
F_21 ( & V_117 ) ;
return V_120 ;
}
static int T_3 F_82 ( char * V_63 )
{
struct V_115 * V_3 ;
char * error ;
int V_73 , V_5 ;
V_5 = F_74 ( V_63 , & V_73 , & V_63 , & error ) ;
if ( V_5 ) {
F_18 ( V_32 L_26 ,
V_63 , error ) ;
return 1 ;
}
V_3 = F_83 ( sizeof( * V_3 ) ) ;
F_58 ( & V_3 -> V_46 ) ;
V_3 -> V_81 = V_73 ;
V_3 -> V_74 = V_63 ;
F_84 ( & V_3 -> V_46 , & V_122 ) ;
return 1 ;
}
static int F_85 ( char * V_63 , char * * V_107 )
{
int V_73 , V_5 ;
V_5 = F_74 ( V_63 , & V_73 , & V_63 , V_107 ) ;
if ( V_5 )
return V_5 ;
V_63 = F_86 ( V_63 , V_119 ) ;
if ( V_63 == NULL ) {
* V_107 = L_27 ;
return - V_9 ;
}
V_5 = ! F_81 ( V_63 , V_73 ) ;
if ( V_5 )
F_53 ( V_63 ) ;
return V_5 ;
}
static int F_87 ( char * * V_63 , int * V_123 , int * V_124 )
{
char * V_66 ;
int V_73 ;
V_73 = F_46 ( * V_63 , & V_66 , 0 ) ;
if ( ( * V_66 != '\0' ) || ( V_66 == * V_63 ) )
return - 1 ;
* V_123 = V_73 ;
* V_124 = V_73 ;
* V_63 = V_66 ;
return V_73 ;
}
static int F_88 ( int V_73 , char * * V_107 )
{
struct V_71 * V_70 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_70 = F_71 ( V_73 ) ;
if ( V_70 == NULL )
return - V_125 ;
V_12 = V_70 -> V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_19 > 0 )
return - V_126 ;
F_89 ( V_12 ) ;
F_70 ( & V_70 -> V_84 ) ;
return 0 ;
}
static int F_90 ( struct V_127 * V_128 , unsigned long V_129 ,
void * V_130 )
{
struct V_131 * V_132 = V_130 ;
struct V_11 * V_12 = V_132 -> V_133 -> V_12 ;
struct V_13 * V_14 ;
void (* F_91)( unsigned char * , unsigned char * , void * );
unsigned char V_134 [ 4 ] , V_135 [ 4 ] ;
if ( V_12 -> V_94 -> V_136 != F_22 )
return V_137 ;
V_14 = F_8 ( V_12 ) ;
F_91 = NULL ;
switch ( V_129 ) {
case V_138 :
F_91 = V_14 -> V_89 ;
break;
case V_139 :
F_91 = V_14 -> V_90 ;
break;
}
if ( F_91 != NULL ) {
memcpy ( V_134 , & V_132 -> V_140 , sizeof( V_134 ) ) ;
memcpy ( V_135 , & V_132 -> V_141 , sizeof( V_135 ) ) ;
(* F_91)( V_134 , V_135 , & V_14 -> V_38 ) ;
}
return V_137 ;
}
static void F_92 ( void )
{
struct V_103 * V_104 ;
struct V_13 * V_14 ;
struct V_142 * V_143 ;
struct V_131 * V_144 ;
F_93 ( & V_145 ) ;
F_17 ( & V_45 ) ;
F_72 (ele, &opened) {
V_14 = F_73 ( V_104 , struct V_13 , V_46 ) ;
V_143 = V_14 -> V_12 -> V_146 ;
if ( V_143 == NULL )
continue;
V_144 = V_143 -> V_147 ;
while ( V_144 != NULL ) {
F_90 ( NULL , V_138 , V_144 ) ;
V_144 = V_144 -> V_148 ;
}
}
F_21 ( & V_45 ) ;
}
static inline void F_92 ( void )
{
}
static int F_94 ( void )
{
F_95 ( & V_149 ) ;
F_92 () ;
return 0 ;
}
static void F_96 ( void )
{
struct V_103 * V_104 ;
struct V_13 * V_14 ;
F_17 ( & V_45 ) ;
F_72 (ele, &opened) {
V_14 = F_73 ( V_104 , struct V_13 , V_46 ) ;
F_28 ( V_14 -> V_12 -> V_28 , V_14 -> V_12 ) ;
if ( ( V_14 -> V_48 != NULL ) && ( V_14 -> V_19 >= 0 ) )
(* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
}
F_21 ( & V_45 ) ;
}
void F_97 ( void * V_150 , void (* F_98)( unsigned char * , unsigned char * ,
void * ) ,
void * V_151 )
{
struct V_11 * V_12 = V_150 ;
struct V_142 * V_143 = V_12 -> V_146 ;
struct V_131 * V_144 ;
unsigned char V_152 [ 4 ] , V_153 [ 4 ] ;
if ( V_143 == NULL ) return;
V_144 = V_143 -> V_147 ;
while ( V_144 != NULL ) {
memcpy ( V_152 , & V_144 -> V_140 , sizeof( V_152 ) ) ;
memcpy ( V_153 , & V_144 -> V_141 , sizeof( V_153 ) ) ;
(* F_98)( V_152 , V_153 , V_151 ) ;
V_144 = V_144 -> V_148 ;
}
}
int F_99 ( void * V_150 , void * V_154 )
{
struct V_11 * V_12 = V_150 ;
struct V_142 * V_143 = V_12 -> V_146 ;
struct V_131 * V_144 ;
T_4 * V_155 = V_154 ;
if ( V_143 == NULL )
return 1 ;
V_144 = V_143 -> V_147 ;
if ( V_144 == NULL )
return 1 ;
* V_155 = V_144 -> V_141 ;
return 0 ;
}
void * F_100 ( int * V_156 )
{
void * V_157 ;
V_157 = ( void * ) F_101 ( V_119 , 0 ) ;
if ( V_157 ) * V_156 = V_158 ;
else * V_156 = 0 ;
return V_157 ;
}
void F_102 ( void * V_159 )
{
F_103 ( ( unsigned long ) V_159 , 0 ) ;
}
int F_104 ( char * V_63 , char * type , char * * V_160 , char * * V_111 ,
char * * V_161 )
{
char * V_162 ;
V_162 = F_105 ( V_63 , V_160 , V_111 , V_161 , NULL ) ;
if ( V_162 != NULL ) {
F_18 ( V_32 L_28
L_29 , V_162 ) ;
return 1 ;
}
return 0 ;
}
unsigned short F_106 ( struct V_2 * V_16 )
{
return F_107 ( V_16 , V_16 -> V_12 ) ;
}
