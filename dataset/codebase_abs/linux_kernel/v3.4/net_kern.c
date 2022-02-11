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
if ( V_24 == V_16 -> V_24 ) {
V_12 -> V_20 . V_50 ++ ;
V_12 -> V_20 . V_51 += V_16 -> V_24 ;
V_12 -> V_52 = V_53 ;
F_24 ( V_12 ) ;
F_31 ( V_12 ) ;
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
F_32 ( V_16 ) ;
return V_55 ;
}
static void F_33 ( struct V_11 * V_12 )
{
return;
}
static void F_34 ( struct V_11 * V_12 )
{
V_12 -> V_52 = V_53 ;
F_31 ( V_12 ) ;
}
static int F_35 ( struct V_11 * V_12 , int V_56 )
{
V_12 -> V_57 = V_56 ;
return 0 ;
}
static void F_36 ( struct V_11 * V_12 )
{
F_37 ( V_12 -> V_28 ) ;
F_15 ( V_12 -> V_28 , V_12 ) ;
F_38 ( V_12 -> V_28 ) ;
}
static void F_39 ( struct V_11 * V_12 ,
struct V_58 * V_59 )
{
strcpy ( V_59 -> V_60 , V_61 ) ;
strcpy ( V_59 -> V_62 , L_4 ) ;
}
static void F_40 ( unsigned long V_63 )
{
#ifdef undef
struct V_64 * V_65 = (struct V_64 * ) V_63 ;
F_41 ( V_66 L_5 , V_65 ) ;
F_42 ( V_65 ) ;
#endif
}
static int F_43 ( char * V_67 , unsigned char * V_68 , char * V_33 )
{
char * V_69 ;
int V_70 ;
if ( V_67 == NULL )
goto V_71;
for ( V_70 = 0 ; V_70 < 6 ; V_70 ++ ) {
V_68 [ V_70 ] = F_44 ( V_67 , & V_69 , 16 ) ;
if ( ( V_69 == V_67 ) ||
( ( * V_69 != ':' ) && ( * V_69 != ',' ) && ( * V_69 != '\0' ) ) ) {
F_18 ( V_32
L_6
L_7 , V_67 ) ;
goto V_71;
}
V_67 = V_69 + 1 ;
}
if ( F_45 ( V_68 ) ) {
F_18 ( V_32
L_8
L_9 ) ;
goto V_71;
}
if ( ! F_46 ( V_68 ) ) {
F_18 ( V_32
L_10
L_9 ) ;
goto V_71;
}
if ( ! F_47 ( V_68 ) ) {
F_18 ( V_72
L_11
L_12 ) ;
F_18 ( V_72 L_13
L_14 ) ;
F_18 ( V_72 L_15 ,
V_68 [ 0 ] | 0x02 , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] , V_68 [ 4 ] ,
V_68 [ 5 ] ) ;
}
return 0 ;
V_71:
F_18 ( V_66
L_16 , V_33 ) ;
F_48 ( V_68 ) ;
return 1 ;
}
static void F_49 ( struct V_73 * V_12 )
{
struct V_74 * V_73 = F_50 ( V_12 ) ;
struct V_11 * V_75 = V_73 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_75 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
F_29 ( & V_73 -> V_46 ) ;
F_51 ( V_73 ) ;
F_52 ( V_75 ) ;
}
static void F_53 ( int V_76 , void * V_77 , char * V_78 ,
struct V_79 * V_79 )
{
struct V_74 * V_73 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_5 , V_80 ;
int V_81 ;
V_80 = V_79 -> V_82 + sizeof( struct V_13 ) ;
V_73 = F_54 ( sizeof( * V_73 ) , V_83 ) ;
if ( V_73 == NULL ) {
F_18 ( V_32 L_17
L_18 ) ;
return;
}
V_12 = F_55 ( V_80 ) ;
if ( V_12 == NULL ) {
F_18 ( V_32 L_19
L_20 , V_76 ) ;
goto V_84;
}
F_56 ( & V_73 -> V_46 ) ;
V_73 -> V_85 = V_76 ;
snprintf ( V_12 -> V_33 , sizeof( V_12 -> V_33 ) , L_21 , V_76 ) ;
V_81 = F_43 ( V_78 , V_73 -> V_78 , V_12 -> V_33 ) ;
F_18 ( V_66 L_22 , V_76 , V_73 -> V_78 ) ;
V_14 = F_8 ( V_12 ) ;
memset ( V_14 , 0 , V_80 ) ;
F_57 ( & V_14 -> V_27 , F_12 ) ;
if ( ! V_86 ) {
F_58 ( & V_87 ) ;
V_86 = 1 ;
}
V_73 -> V_88 . V_89 = V_76 ;
V_73 -> V_88 . V_33 = V_61 ;
V_73 -> V_88 . V_12 . V_90 = F_49 ;
F_59 ( & V_73 -> V_88 . V_12 , V_73 ) ;
if ( F_60 ( & V_73 -> V_88 ) )
goto V_91;
F_61 ( V_12 , & V_73 -> V_88 . V_12 ) ;
V_73 -> V_12 = V_12 ;
(* V_79 -> V_92 -> V_77 )( V_12 , V_77 ) ;
* V_14 = ( (struct V_13 )
{ . V_46 = F_62 ( V_14 -> V_46 ) ,
. V_12 = V_12 ,
. V_19 = - 1 ,
. V_78 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_17 = V_79 -> V_38 -> V_17 ,
. V_22 = V_79 -> V_92 -> V_22 ,
. V_37 = V_79 -> V_38 -> V_37 ,
. V_48 = V_79 -> V_38 -> V_48 ,
. remove = V_79 -> V_38 -> remove ,
. V_18 = V_79 -> V_92 -> V_18 ,
. V_49 = V_79 -> V_92 -> V_49 ,
. V_93 = V_79 -> V_38 -> V_93 ,
. V_94 = V_79 -> V_38 -> V_94 } ) ;
F_63 ( & V_14 -> V_43 ) ;
F_64 ( & V_14 -> V_31 ) ;
V_14 -> V_43 . V_95 = F_40 ;
memcpy ( V_14 -> V_78 , V_73 -> V_78 , sizeof( V_14 -> V_78 ) ) ;
if ( ( V_79 -> V_38 -> V_77 != NULL ) &&
( (* V_79 -> V_38 -> V_77 )( & V_14 -> V_38 , V_12 ) != 0 ) )
goto V_96;
memcpy ( V_12 -> V_97 , V_73 -> V_78 , V_98 ) ;
if ( V_81 )
V_12 -> V_99 |= V_100 ;
V_12 -> V_57 = V_79 -> V_38 -> V_57 ;
V_12 -> V_101 = & V_102 ;
V_12 -> V_103 = & V_104 ;
V_12 -> V_105 = ( V_106 >> 1 ) ;
V_12 -> V_28 = V_34 ;
V_5 = F_1 ( V_14 -> V_17 ) ;
if ( V_5 )
goto V_107;
F_65 () ;
V_5 = F_66 ( V_12 ) ;
F_67 () ;
if ( V_5 )
goto V_107;
F_17 ( & V_108 ) ;
F_25 ( & V_73 -> V_46 , & V_109 ) ;
F_21 ( & V_108 ) ;
return;
V_107:
if ( V_79 -> V_38 -> remove != NULL )
(* V_79 -> V_38 -> remove )( & V_14 -> V_38 ) ;
V_96:
F_68 ( & V_73 -> V_88 ) ;
return;
V_91:
F_52 ( V_12 ) ;
V_84:
F_51 ( V_73 ) ;
}
static struct V_74 * F_69 ( int V_76 )
{
struct V_74 * V_73 ;
struct V_110 * V_111 ;
F_17 ( & V_108 ) ;
F_70 (ele, &devices) {
V_73 = F_71 ( V_111 , struct V_74 , V_46 ) ;
if ( V_73 -> V_85 == V_76 )
goto V_8;
}
V_73 = NULL ;
V_8:
F_21 ( & V_108 ) ;
return V_73 ;
}
static int F_72 ( char * V_67 , int * V_112 , char * * V_113 ,
char * * V_114 )
{
char * V_69 ;
int V_76 , V_5 = - V_115 ;
V_76 = F_44 ( V_67 , & V_69 , 0 ) ;
if ( V_69 == V_67 ) {
* V_114 = L_23 ;
return V_5 ;
}
V_67 = V_69 ;
if ( * V_67 != '=' ) {
* V_114 = L_24 ;
return V_5 ;
}
V_67 ++ ;
if ( F_69 ( V_76 ) ) {
* V_114 = L_25 ;
return V_5 ;
}
* V_112 = V_76 ;
* V_113 = V_67 ;
return 0 ;
}
static int F_73 ( struct V_79 * V_79 , char * V_116 , int V_76 ,
void * * V_117 , char * * V_118 )
{
int V_24 ;
V_24 = strlen ( V_79 -> V_33 ) ;
if ( strncmp ( V_116 , V_79 -> V_33 , V_24 ) )
return 0 ;
V_116 += V_24 ;
if ( * V_116 == ',' )
V_116 ++ ;
else if ( * V_116 != '\0' )
return 0 ;
* V_117 = F_74 ( V_79 -> V_119 , V_83 ) ;
if ( * V_117 == NULL )
return 1 ;
if ( ! V_79 -> V_120 ( V_116 , V_118 , * V_117 ) ) {
F_51 ( * V_117 ) ;
* V_117 = NULL ;
}
return 1 ;
}
void F_75 ( struct V_79 * V_3 )
{
struct V_110 * V_111 , * V_121 ;
struct V_122 * V_116 ;
void * V_77 ;
char * V_78 = NULL ;
int V_123 ;
F_17 ( & V_124 ) ;
F_76 ( ! F_77 ( & V_3 -> V_46 ) ) ;
F_25 ( & V_3 -> V_46 , & V_125 ) ;
F_21 ( & V_124 ) ;
F_78 (ele, next, &eth_cmd_line) {
V_116 = F_71 ( V_111 , struct V_122 , V_46 ) ;
V_123 = F_73 ( V_3 , V_116 -> V_77 , V_116 -> V_85 , & V_77 ,
& V_78 ) ;
if ( ! V_123 )
continue;
else if ( V_77 != NULL ) {
F_53 ( V_116 -> V_85 , V_77 , V_78 , V_3 ) ;
F_51 ( V_77 ) ;
}
F_29 ( & V_116 -> V_46 ) ;
}
}
static int F_79 ( char * V_67 , int V_85 )
{
struct V_110 * V_111 ;
struct V_79 * V_79 ;
void * V_77 ;
char * V_78 = NULL ;
int V_126 = 0 ;
F_17 ( & V_124 ) ;
F_70 (ele, &transports) {
V_79 = F_71 ( V_111 , struct V_79 , V_46 ) ;
if ( ! F_73 ( V_79 , V_67 , V_85 , & V_77 , & V_78 ) )
continue;
if ( V_77 != NULL ) {
F_53 ( V_85 , V_77 , V_78 , V_79 ) ;
F_51 ( V_77 ) ;
}
V_126 = 1 ;
break;
}
F_21 ( & V_124 ) ;
return V_126 ;
}
static int T_2 F_80 ( char * V_67 )
{
struct V_122 * V_3 ;
char * error ;
int V_76 , V_5 ;
V_5 = F_72 ( V_67 , & V_76 , & V_67 , & error ) ;
if ( V_5 ) {
F_18 ( V_32 L_26 ,
V_67 , error ) ;
return 1 ;
}
V_3 = F_81 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL ) {
F_18 ( V_32 L_27 ) ;
return 1 ;
}
F_56 ( & V_3 -> V_46 ) ;
V_3 -> V_85 = V_76 ;
V_3 -> V_77 = V_67 ;
F_82 ( & V_3 -> V_46 , & V_127 ) ;
return 1 ;
}
static int F_83 ( char * V_67 , char * * V_114 )
{
int V_76 , V_5 ;
V_5 = F_72 ( V_67 , & V_76 , & V_67 , V_114 ) ;
if ( V_5 )
return V_5 ;
V_67 = F_84 ( V_67 , V_83 ) ;
if ( V_67 == NULL ) {
* V_114 = L_28 ;
return - V_9 ;
}
V_5 = ! F_79 ( V_67 , V_76 ) ;
if ( V_5 )
F_51 ( V_67 ) ;
return V_5 ;
}
static int F_85 ( char * * V_67 , int * V_128 , int * V_129 )
{
char * V_69 ;
int V_76 ;
V_76 = F_44 ( * V_67 , & V_69 , 0 ) ;
if ( ( * V_69 != '\0' ) || ( V_69 == * V_67 ) )
return - 1 ;
* V_128 = V_76 ;
* V_129 = V_76 ;
* V_67 = V_69 ;
return V_76 ;
}
static int F_86 ( int V_76 , char * * V_114 )
{
struct V_74 * V_73 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_73 = F_69 ( V_76 ) ;
if ( V_73 == NULL )
return - V_130 ;
V_12 = V_73 -> V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_19 > 0 )
return - V_131 ;
F_87 ( V_12 ) ;
F_68 ( & V_73 -> V_88 ) ;
return 0 ;
}
static int F_88 ( struct V_132 * V_133 , unsigned long V_134 ,
void * V_135 )
{
struct V_136 * V_137 = V_135 ;
struct V_11 * V_12 = V_137 -> V_138 -> V_12 ;
struct V_13 * V_14 ;
void (* F_89)( unsigned char * , unsigned char * , void * );
unsigned char V_139 [ 4 ] , V_140 [ 4 ] ;
if ( V_12 -> V_101 -> V_141 != F_22 )
return V_142 ;
V_14 = F_8 ( V_12 ) ;
F_89 = NULL ;
switch ( V_134 ) {
case V_143 :
F_89 = V_14 -> V_93 ;
break;
case V_144 :
F_89 = V_14 -> V_94 ;
break;
}
if ( F_89 != NULL ) {
memcpy ( V_139 , & V_137 -> V_145 , sizeof( V_139 ) ) ;
memcpy ( V_140 , & V_137 -> V_146 , sizeof( V_140 ) ) ;
(* F_89)( V_139 , V_140 , & V_14 -> V_38 ) ;
}
return V_142 ;
}
static void F_90 ( void )
{
struct V_110 * V_111 ;
struct V_13 * V_14 ;
struct V_147 * V_148 ;
struct V_136 * V_149 ;
F_91 ( & V_150 ) ;
F_17 ( & V_45 ) ;
F_70 (ele, &opened) {
V_14 = F_71 ( V_111 , struct V_13 , V_46 ) ;
V_148 = V_14 -> V_12 -> V_151 ;
if ( V_148 == NULL )
continue;
V_149 = V_148 -> V_152 ;
while ( V_149 != NULL ) {
F_88 ( NULL , V_143 , V_149 ) ;
V_149 = V_149 -> V_153 ;
}
}
F_21 ( & V_45 ) ;
}
static inline void F_90 ( void )
{
}
static int F_92 ( void )
{
F_93 ( & V_154 ) ;
F_90 () ;
return 0 ;
}
static void F_94 ( void )
{
struct V_110 * V_111 ;
struct V_13 * V_14 ;
F_17 ( & V_45 ) ;
F_70 (ele, &opened) {
V_14 = F_71 ( V_111 , struct V_13 , V_46 ) ;
F_28 ( V_14 -> V_12 -> V_28 , V_14 -> V_12 ) ;
if ( ( V_14 -> V_48 != NULL ) && ( V_14 -> V_19 >= 0 ) )
(* V_14 -> V_48 )( V_14 -> V_19 , & V_14 -> V_38 ) ;
if ( V_14 -> remove != NULL )
(* V_14 -> remove )( & V_14 -> V_38 ) ;
}
F_21 ( & V_45 ) ;
}
void F_95 ( void * V_155 , void (* F_96)( unsigned char * , unsigned char * ,
void * ) ,
void * V_156 )
{
struct V_11 * V_12 = V_155 ;
struct V_147 * V_148 = V_12 -> V_151 ;
struct V_136 * V_149 ;
unsigned char V_157 [ 4 ] , V_158 [ 4 ] ;
if ( V_148 == NULL ) return;
V_149 = V_148 -> V_152 ;
while ( V_149 != NULL ) {
memcpy ( V_157 , & V_149 -> V_145 , sizeof( V_157 ) ) ;
memcpy ( V_158 , & V_149 -> V_146 , sizeof( V_158 ) ) ;
(* F_96)( V_157 , V_158 , V_156 ) ;
V_149 = V_149 -> V_153 ;
}
}
int F_97 ( void * V_155 , void * V_159 )
{
struct V_11 * V_12 = V_155 ;
struct V_147 * V_148 = V_12 -> V_151 ;
struct V_136 * V_149 ;
T_3 * V_160 = V_159 ;
if ( V_148 == NULL )
return 1 ;
V_149 = V_148 -> V_152 ;
if ( V_149 == NULL )
return 1 ;
* V_160 = V_149 -> V_146 ;
return 0 ;
}
void * F_98 ( int * V_161 )
{
void * V_162 ;
V_162 = ( void * ) F_99 ( V_83 , 0 ) ;
if ( V_162 ) * V_161 = V_163 ;
else * V_161 = 0 ;
return V_162 ;
}
void F_100 ( void * V_164 )
{
F_101 ( ( unsigned long ) V_164 , 0 ) ;
}
int F_102 ( char * V_67 , char * type , char * * V_165 , char * * V_118 ,
char * * V_166 )
{
char * V_167 ;
V_167 = F_103 ( V_67 , V_165 , V_118 , V_166 , NULL ) ;
if ( V_167 != NULL ) {
F_18 ( V_32 L_29
L_30 , V_167 ) ;
return 1 ;
}
return 0 ;
}
unsigned short F_104 ( struct V_2 * V_16 )
{
return F_105 ( V_16 , V_16 -> V_12 ) ;
}
