static char * F_1 ( enum V_1 type )
{
switch ( type ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
default:
return V_11 ;
}
}
static char * F_2 ( enum V_12 type )
{
switch ( type ) {
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
default:
return NULL ;
}
}
static inline int F_3 ( unsigned long V_19 , void * V_20 )
{
register unsigned long T_1 V_21 ( L_1 ) = ( unsigned long ) V_20 ;
register unsigned long T_2 V_21 ( L_2 ) = 0 ;
asm volatile(
" diag %0,%2,0x308\n"
"0: nopr %%r7\n"
EX_TABLE(0b,0b)
: "+d" (_addr), "+d" (_rc)
: "d" (subcode) : "cc", "memory");
return T_2 ;
}
int F_4 ( unsigned long V_19 , void * V_20 )
{
F_5 ( V_22 ) ;
return F_3 ( V_19 , V_20 ) ;
}
static void F_6 ( struct V_23 * * V_24 )
{
while ( * V_24 ) {
( * V_24 ) -> V_25 = V_26 ;
V_24 ++ ;
}
}
static T_3 enum V_1 F_7 ( void )
{
struct V_27 * V_28 = V_29 ;
if ( V_30 & V_31 )
return V_8 ;
if ( ! ( V_30 & V_32 ) )
return V_10 ;
if ( ! ( V_30 & V_33 ) )
return V_2 ;
if ( V_28 -> V_34 . V_35 > V_36 )
return V_10 ;
if ( V_28 -> V_34 . V_37 != V_38 )
return V_10 ;
if ( V_28 -> V_39 . V_40 . V_41 == V_42 )
return V_6 ;
return V_4 ;
}
static T_4 F_8 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
return sprintf ( V_47 , L_3 , F_1 ( V_39 . type ) ) ;
}
static T_5 F_9 ( char * V_48 , T_5 V_49 ,
const struct V_27 * V_50 )
{
int V_51 ;
T_5 V_52 ;
char V_53 = 0 ;
V_52 = 0 ;
if ( ( V_50 -> V_39 . V_54 . V_55 & V_56 ) &&
( V_50 -> V_39 . V_54 . V_57 > 0 ) ) {
V_52 = F_10 ( T_5 , V_49 - 1 , V_50 -> V_39 . V_54 . V_57 ) ;
memcpy ( V_48 , V_50 -> V_39 . V_54 . V_58 , V_52 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ )
if ( ( V_48 [ V_51 ] > 0x80 && V_48 [ V_51 ] < 0x8a ) ||
( V_48 [ V_51 ] > 0x90 && V_48 [ V_51 ] < 0x9a ) ||
( V_48 [ V_51 ] > 0xa1 && V_48 [ V_51 ] < 0xaa ) ) {
V_53 = 1 ;
break;
}
if ( ! V_53 )
F_11 ( V_48 , V_52 ) ;
F_12 ( V_48 , V_52 ) ;
}
V_48 [ V_52 ] = 0 ;
return V_52 ;
}
T_5 F_13 ( char * V_48 , T_5 V_49 )
{
T_5 V_59 ;
V_59 = 0 ;
if ( V_60 && ( V_61 . V_34 . V_37 == V_62 ) )
V_59 = F_9 ( V_48 , V_49 , & V_61 ) ;
else
V_48 [ 0 ] = 0 ;
return V_59 ;
}
static T_4 F_14 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
char V_63 [ V_64 + 1 ] = {} ;
F_13 ( V_63 , sizeof( V_63 ) ) ;
return sprintf ( V_47 , L_3 , V_63 ) ;
}
static T_5 F_15 ( const char * V_65 , T_5 V_66 )
{
while ( V_66 ) {
if ( V_65 [ V_66 - 1 ] != '\0' && V_65 [ V_66 - 1 ] != ' ' )
break;
V_66 -- ;
}
return V_66 ;
}
static T_5 F_16 ( char * V_48 , T_5 V_49 ,
const struct V_27 * V_50 )
{
T_5 V_66 ;
T_5 V_51 ;
int V_53 ;
V_66 = F_17 ( V_49 - 1 , F_15 ( V_50 -> V_39 . V_40 . V_67 ,
V_50 -> V_39 . V_40 . V_68 ) ) ;
if ( ! V_66 )
goto V_69;
V_53 = 0 ;
for ( V_51 = 0 ; V_51 < V_66 ; V_51 ++ ) {
if ( ! isascii ( V_50 -> V_39 . V_40 . V_67 [ V_51 ] ) ) {
V_66 = 0 ;
goto V_69;
}
if ( ! V_53 && islower ( V_50 -> V_39 . V_40 . V_67 [ V_51 ] ) )
V_53 = 1 ;
}
if ( V_53 )
memcpy ( V_48 , V_50 -> V_39 . V_40 . V_67 , V_66 ) ;
else
for ( V_51 = 0 ; V_51 < V_66 ; V_51 ++ )
V_48 [ V_51 ] = tolower ( V_50 -> V_39 . V_40 . V_67 [ V_51 ] ) ;
V_69:
V_48 [ V_66 ] = '\0' ;
return V_66 ;
}
T_5 F_18 ( char * V_48 , T_5 V_52 )
{
T_5 V_59 ;
V_59 = 0 ;
if ( V_61 . V_34 . V_37 == V_38 )
V_59 = F_16 ( V_48 , V_52 , & V_61 ) ;
else
V_48 [ 0 ] = 0 ;
return V_59 ;
}
static T_4 F_19 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_27 * V_28 = V_29 ;
switch ( V_39 . type ) {
case V_2 :
return sprintf ( V_47 , L_4 , V_70 , V_71 ) ;
case V_4 :
case V_6 :
return sprintf ( V_47 , L_5 , V_28 -> V_39 . V_40 . V_72 ) ;
default:
return 0 ;
}
}
static T_4 F_20 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 , char * V_65 ,
T_6 V_76 , T_5 V_66 )
{
return F_21 ( V_65 , V_66 , & V_76 , V_29 ,
V_77 ) ;
}
static T_4 F_22 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 , char * V_65 ,
T_6 V_76 , T_5 V_66 )
{
unsigned int V_49 = V_29 -> V_39 . V_40 . V_68 ;
void * V_67 = & V_29 -> V_39 . V_40 . V_67 ;
return F_21 ( V_65 , V_66 , & V_76 , V_67 , V_49 ) ;
}
static T_4 F_23 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
char V_78 [ V_79 + 1 ] = {} ;
if ( ! V_80 . V_81 )
return sprintf ( V_47 , L_6 ) ;
memcpy ( V_78 , & V_80 . V_78 , V_79 ) ;
F_12 ( V_78 , V_79 ) ;
F_24 ( V_78 ) ;
return sprintf ( V_47 , L_3 , V_78 ) ;
}
static void F_25 ( void * V_82 )
{
F_4 ( V_83 , NULL ) ;
if ( V_84 )
F_26 ( L_7 , NULL , 0 , NULL ) ;
else if ( V_39 . type == V_2 )
F_27 ( & V_39 . V_85 . V_54 . V_86 ) ;
}
static void F_28 ( struct V_87 * V_88 )
{
F_29 ( F_25 , NULL ) ;
}
static int T_3 F_30 ( void )
{
int V_59 ;
V_89 = F_31 ( L_8 , NULL , V_90 ) ;
if ( ! V_89 ) {
V_59 = - V_91 ;
goto V_69;
}
switch ( V_39 . type ) {
case V_2 :
if ( V_84 )
V_59 = F_32 ( & V_89 -> V_44 ,
& V_92 ) ;
else
V_59 = F_32 ( & V_89 -> V_44 ,
& V_93 ) ;
break;
case V_4 :
case V_6 :
V_59 = F_32 ( & V_89 -> V_44 , & V_94 ) ;
break;
case V_8 :
V_59 = F_32 ( & V_89 -> V_44 , & V_95 ) ;
break;
default:
V_59 = F_32 ( & V_89 -> V_44 ,
& V_96 ) ;
break;
}
V_69:
if ( V_59 )
F_33 ( L_9 , V_59 ) ;
return 0 ;
}
static T_4 F_34 ( struct V_27 * V_50 ,
char * V_47 )
{
char V_97 [ V_64 + 1 ] = {} ;
F_9 ( V_97 , sizeof( V_97 ) , V_50 ) ;
return sprintf ( V_47 , L_3 , V_97 ) ;
}
static T_4 F_35 ( struct V_27 * V_50 ,
T_5 V_98 ,
const char * V_65 , T_5 V_52 )
{
int V_51 , V_99 ;
V_99 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_99 -- ;
if ( V_99 > V_98 )
return - V_100 ;
for ( V_51 = 0 ; V_51 < V_99 ; V_51 ++ )
if ( ! ( isalnum ( V_65 [ V_51 ] ) || isascii ( V_65 [ V_51 ] ) || isprint ( V_65 [ V_51 ] ) ) )
return - V_100 ;
memset ( V_50 -> V_39 . V_54 . V_58 , 0 , V_64 ) ;
V_50 -> V_39 . V_54 . V_57 = V_99 ;
if ( V_99 > 0 ) {
V_50 -> V_39 . V_54 . V_55 |= V_56 ;
memcpy ( V_50 -> V_39 . V_54 . V_58 , V_65 , V_99 ) ;
F_36 ( V_50 -> V_39 . V_54 . V_58 , V_99 ) ;
} else {
V_50 -> V_39 . V_54 . V_55 &= ~ V_56 ;
}
return V_52 ;
}
static T_4 F_37 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_34 ( V_101 , V_47 ) ;
}
static T_4 F_38 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_35 ( V_101 , 56 , V_65 , V_52 ) ;
}
static T_4 F_39 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_34 ( V_102 , V_47 ) ;
}
static T_4 F_40 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_35 ( V_102 , 64 , V_65 , V_52 ) ;
}
static T_4 F_41 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 ,
char * V_65 , T_6 V_76 , T_5 V_66 )
{
T_5 V_49 = V_103 -> V_39 . V_40 . V_68 ;
void * V_67 = V_103 -> V_39 . V_40 . V_67 ;
return F_21 ( V_65 , V_66 , & V_76 , V_67 , V_49 ) ;
}
static T_4 F_42 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 ,
char * V_65 , T_6 V_76 , T_5 V_66 )
{
T_5 V_104 = V_66 ;
T_5 V_105 ;
if ( V_76 )
return - V_100 ;
memcpy ( V_103 -> V_39 . V_40 . V_67 , V_65 , V_66 ) ;
if ( V_104 % 8 ) {
V_105 = 8 - ( V_104 % 8 ) ;
memset ( V_103 -> V_39 . V_40 . V_67 + V_104 ,
0 , V_105 ) ;
V_104 += V_105 ;
}
V_103 -> V_39 . V_40 . V_68 = V_104 ;
V_103 -> V_34 . V_52 = V_106 + V_104 ;
V_103 -> V_34 . V_107 = V_108 + V_104 ;
return V_66 ;
}
static void F_43 ( char * V_78 ,
struct V_27 * V_109 )
{
memcpy ( V_78 , V_109 -> V_34 . V_78 , V_79 ) ;
F_12 ( V_78 , V_79 ) ;
V_78 [ V_79 ] = 0 ;
F_24 ( V_78 ) ;
}
static T_4 F_44 ( struct V_27 * V_50 ,
char * V_47 )
{
char V_65 [ V_79 + 1 ] ;
F_43 ( V_65 , V_50 ) ;
return sprintf ( V_47 , L_3 , V_65 ) ;
}
static T_4 F_45 ( struct V_27 * V_50 ,
const char * V_65 , T_5 V_52 )
{
int V_51 , V_110 ;
V_110 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_110 -- ;
if ( ( V_110 > V_79 ) || ( ( V_110 > 0 ) && ( V_65 [ 0 ] == ' ' ) ) )
return - V_100 ;
for ( V_51 = 0 ; V_51 < V_110 ; V_51 ++ ) {
if ( isalpha ( V_65 [ V_51 ] ) || isdigit ( V_65 [ V_51 ] ) || ( V_65 [ V_51 ] == ' ' ) ||
( V_65 [ V_51 ] == '.' ) )
continue;
return - V_100 ;
}
memset ( V_50 -> V_34 . V_78 , ' ' , V_79 ) ;
memcpy ( V_50 -> V_34 . V_78 , V_65 , V_110 ) ;
F_36 ( V_50 -> V_34 . V_78 , V_79 ) ;
return V_52 ;
}
static T_4 F_46 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_103 , V_47 ) ;
}
static T_4 F_47 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_103 , V_65 , V_52 ) ;
}
static T_4 F_48 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_101 , V_47 ) ;
}
static T_4 F_49 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_101 , V_65 , V_52 ) ;
}
static T_4 F_50 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_102 , V_47 ) ;
}
static T_4 F_51 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_102 , V_65 , V_52 ) ;
}
static void F_52 ( char * V_111 ,
struct V_27 * V_50 )
{
memcpy ( V_111 , V_50 -> V_39 . V_54 . V_112 , V_113 ) ;
F_12 ( V_111 , V_113 ) ;
V_111 [ V_113 ] = 0 ;
}
static T_4 F_53 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
char V_112 [ V_113 + 1 ] = {} ;
F_52 ( V_112 , V_101 ) ;
return sprintf ( V_47 , L_3 , V_112 ) ;
}
static T_4 F_54 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
int V_114 ;
V_114 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_114 -- ;
if ( V_114 > V_113 )
return - V_100 ;
memset ( V_101 -> V_39 . V_54 . V_112 , 0x40 , V_113 ) ;
if ( V_114 > 0 ) {
V_101 -> V_39 . V_54 . V_55 |=
V_115 ;
memcpy ( V_101 -> V_39 . V_54 . V_112 , V_65 , V_114 ) ;
F_36 ( V_101 -> V_39 . V_54 . V_112 , V_114 ) ;
F_55 ( V_101 -> V_39 . V_54 . V_112 , V_114 ) ;
} else {
V_101 -> V_39 . V_54 . V_55 &=
~ V_115 ;
}
return V_52 ;
}
static void F_56 ( struct V_27 * V_116 )
{
V_117 = V_116 ;
F_57 ( V_118 , V_117 ,
V_116 -> V_34 . V_52 ) ;
}
static int F_58 ( enum V_1 type )
{
if ( ! ( V_119 & type ) )
return - V_100 ;
switch( type ) {
case V_2 :
if ( V_60 )
V_120 = V_121 ;
else if ( V_84 )
V_120 = V_122 ;
else
V_120 = V_123 ;
F_56 ( V_102 ) ;
break;
case V_4 :
if ( V_60 )
V_120 = V_124 ;
else if ( V_84 )
V_120 = V_125 ;
else
V_120 = V_126 ;
F_56 ( V_103 ) ;
break;
case V_6 :
V_120 = V_127 ;
break;
case V_8 :
if ( V_60 )
V_120 = V_128 ;
else
V_120 = V_129 ;
F_56 ( V_101 ) ;
break;
case V_10 :
V_120 = V_130 ;
break;
default:
F_59 () ;
}
V_131 = type ;
return 0 ;
}
static T_4 F_60 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , F_1 ( V_131 ) ) ;
}
static T_4 F_61 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
int V_59 = - V_100 ;
if ( strncmp ( V_65 , V_3 , strlen ( V_3 ) ) == 0 )
V_59 = F_58 ( V_2 ) ;
else if ( strncmp ( V_65 , V_5 , strlen ( V_5 ) ) == 0 )
V_59 = F_58 ( V_4 ) ;
else if ( strncmp ( V_65 , V_9 , strlen ( V_9 ) ) == 0 )
V_59 = F_58 ( V_8 ) ;
return ( V_59 != 0 ) ? V_59 : V_52 ;
}
static void F_62 ( char * V_111 , struct V_27 * V_50 ,
const enum V_132 V_133 )
{
char V_78 [ V_79 + 1 ] = {} ;
char V_97 [ V_64 + 1 ] = {} ;
char V_112 [ V_113 + 1 ] = {} ;
T_5 V_134 = 0 ;
F_43 ( V_78 , V_50 ) ;
F_52 ( V_112 , V_50 ) ;
F_9 ( V_97 , sizeof( V_97 ) , V_50 ) ;
switch ( V_133 ) {
case V_122 :
V_134 = sprintf ( V_111 , L_10 , V_50 -> V_39 . V_54 . V_72 ) ;
break;
case V_129 :
V_134 = sprintf ( V_111 , L_11 , V_112 ) ;
break;
default:
break;
}
if ( strlen ( V_78 ) > 0 )
V_134 += sprintf ( V_111 + V_134 , L_12 , V_78 ) ;
if ( strlen ( V_97 ) > 0 )
sprintf ( V_111 + V_134 , L_13 , V_97 ) ;
}
static void F_63 ( void * V_82 )
{
struct V_135 V_136 ;
static char V_65 [ 128 ] ;
switch ( V_120 ) {
case V_123 :
V_136 . V_137 = V_102 -> V_39 . V_54 . V_137 ;
V_136 . V_72 = V_102 -> V_39 . V_54 . V_72 ;
F_27 ( & V_136 ) ;
break;
case V_122 :
F_62 ( V_65 , V_102 , V_122 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
break;
case V_121 :
F_4 ( V_138 , V_102 ) ;
if ( V_139 )
F_4 ( V_140 , NULL ) ;
else
F_4 ( V_83 , NULL ) ;
break;
case V_124 :
F_4 ( V_138 , V_103 ) ;
F_4 ( V_83 , NULL ) ;
break;
case V_126 :
F_4 ( V_83 , NULL ) ;
break;
case V_125 :
F_26 ( L_7 , NULL , 0 , NULL ) ;
break;
case V_128 :
F_4 ( V_138 , V_101 ) ;
F_4 ( V_83 , NULL ) ;
break;
case V_129 :
F_62 ( V_65 , V_101 , V_129 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
break;
case V_130 :
if ( V_84 )
F_26 ( L_7 , NULL , 0 , NULL ) ;
F_4 ( V_83 , NULL ) ;
break;
case V_127 :
break;
}
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
}
static void F_66 ( struct V_87 * V_88 )
{
F_29 ( F_63 , NULL ) ;
}
static void F_67 ( struct V_27 * V_50 )
{
V_50 -> V_34 . V_52 = V_141 ;
V_50 -> V_34 . V_35 = V_142 ;
V_50 -> V_34 . V_107 = V_143 ;
V_50 -> V_34 . V_37 = V_62 ;
}
static void F_68 ( struct V_27 * V_50 )
{
if ( V_80 . V_81 )
memcpy ( V_50 -> V_34 . V_78 , & V_80 . V_78 , V_79 ) ;
else
memset ( V_50 -> V_34 . V_78 , 0x40 , V_79 ) ;
V_50 -> V_34 . V_144 = V_145 ;
if ( V_84 && V_60 &&
( V_61 . V_39 . V_54 . V_55 & V_56 ) ) {
V_50 -> V_39 . V_54 . V_55 |= V_56 ;
V_50 -> V_39 . V_54 . V_57 =
V_61 . V_39 . V_54 . V_57 ;
memcpy ( V_50 -> V_39 . V_54 . V_58 ,
V_61 . V_39 . V_54 . V_58 , V_64 ) ;
}
}
static int T_3 F_69 ( void )
{
int V_59 ;
if ( ! V_84 )
return 0 ;
V_101 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_101 )
return - V_91 ;
if ( ! V_60 )
V_147 . V_46 . V_25 = V_26 ;
V_59 = F_32 ( & V_148 -> V_44 , & V_149 ) ;
if ( V_59 )
return V_59 ;
F_67 ( V_101 ) ;
if ( V_39 . type == V_8 ) {
memset ( V_101 -> V_39 . V_54 . V_112 ,
' ' , V_113 ) ;
memcpy ( V_101 -> V_39 . V_54 . V_112 ,
V_150 , strlen ( V_150 ) ) ;
F_36 ( V_101 -> V_39 . V_54 . V_112 , V_113 ) ;
V_101 -> V_39 . V_54 . V_55 |=
V_115 ;
F_68 ( V_101 ) ;
}
V_119 |= V_8 ;
return 0 ;
}
static int T_3 F_71 ( void )
{
int V_59 ;
V_102 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_102 )
return - V_91 ;
if ( V_84 ) {
if ( ! V_60 )
V_151 . V_46 . V_25 = V_26 ;
V_59 = F_32 ( & V_148 -> V_44 ,
& V_152 ) ;
} else {
if( ! V_60 )
V_153 . V_46 . V_25 = V_26 ;
V_59 = F_32 ( & V_148 -> V_44 ,
& V_154 ) ;
}
if ( V_59 )
return V_59 ;
F_67 ( V_102 ) ;
if ( V_39 . type == V_2 ) {
V_102 -> V_39 . V_54 . V_137 = V_70 ;
V_102 -> V_39 . V_54 . V_72 = V_71 ;
F_68 ( V_102 ) ;
}
V_119 |= V_2 ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_59 ;
if ( ! V_60 ) {
if ( V_39 . type == V_4 ) {
F_6 ( V_155 ) ;
V_156 . V_46 . V_25 = V_26 ;
} else
return 0 ;
}
V_103 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_103 )
return - V_91 ;
V_157 = F_31 ( V_5 , NULL ,
& V_148 -> V_44 ) ;
if ( ! V_157 ) {
F_73 ( ( unsigned long ) V_103 ) ;
return - V_91 ;
}
V_59 = F_32 ( & V_157 -> V_44 , & V_158 ) ;
if ( V_59 ) {
F_74 ( V_157 ) ;
F_73 ( ( unsigned long ) V_103 ) ;
return V_59 ;
}
if ( V_39 . type == V_4 ) {
memcpy ( V_103 , V_29 , V_159 ) ;
memcpy ( V_103 -> V_34 . V_78 , V_80 . V_78 ,
V_79 ) ;
} else {
V_103 -> V_34 . V_52 = V_106 ;
V_103 -> V_34 . V_35 = V_142 ;
V_103 -> V_34 . V_107 = V_108 ;
V_103 -> V_34 . V_37 = V_38 ;
V_103 -> V_39 . V_40 . V_41 = V_160 ;
}
V_119 |= V_4 ;
return 0 ;
}
static int T_3 F_75 ( void )
{
enum V_1 V_131 = V_39 . type ;
struct V_27 * V_116 ;
unsigned long V_49 ;
V_116 = F_76 ( V_118 , & V_49 ) ;
if ( ! V_116 )
goto V_69;
if ( V_116 -> V_34 . V_37 == V_38 ) {
memcpy ( V_103 , V_116 , V_49 ) ;
V_131 = V_4 ;
} else if ( V_116 -> V_34 . V_37 == V_62 ) {
memcpy ( V_102 , V_116 , V_49 ) ;
V_131 = V_2 ;
}
V_69:
return F_58 ( V_131 ) ;
}
static int T_3 F_77 ( void )
{
int V_59 ;
V_148 = F_31 ( L_14 , NULL , V_90 ) ;
if ( ! V_148 )
return - V_91 ;
V_59 = F_78 ( & V_148 -> V_44 , & V_161 . V_46 ) ;
if ( V_59 ) {
F_74 ( V_148 ) ;
return V_59 ;
}
V_59 = F_71 () ;
if ( V_59 )
return V_59 ;
V_59 = F_72 () ;
if ( V_59 )
return V_59 ;
V_59 = F_69 () ;
if ( V_59 )
return V_59 ;
return F_75 () ;
}
static int F_79 ( enum V_12 type )
{
if ( ! ( V_162 & type ) )
return - V_100 ;
switch ( type ) {
case V_15 :
if ( V_60 )
V_163 = V_164 ;
else if ( V_84 )
V_163 = V_165 ;
else
V_163 = V_166 ;
break;
case V_17 :
V_163 = V_167 ;
break;
default:
V_163 = V_168 ;
}
V_12 = type ;
return 0 ;
}
static T_4 F_80 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , F_2 ( V_12 ) ) ;
}
static T_4 F_81 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
int V_59 = - V_100 ;
if ( strncmp ( V_65 , V_14 , strlen ( V_14 ) ) == 0 )
V_59 = F_79 ( V_13 ) ;
else if ( strncmp ( V_65 , V_16 , strlen ( V_16 ) ) == 0 )
V_59 = F_79 ( V_15 ) ;
else if ( strncmp ( V_65 , V_18 , strlen ( V_18 ) ) == 0 )
V_59 = F_79 ( V_17 ) ;
return ( V_59 != 0 ) ? V_59 : V_52 ;
}
static void F_82 ( void * V_169 )
{
F_4 ( V_138 , V_169 ) ;
while ( 1 ) {
if ( F_4 ( V_140 , NULL ) != 0x302 )
break;
F_83 ( V_170 ) ;
}
}
static void F_84 ( void * V_82 )
{
struct V_135 V_136 ;
static char V_65 [ 100 ] ;
switch ( V_163 ) {
case V_166 :
V_136 . V_137 = V_171 -> V_39 . V_54 . V_137 ;
V_136 . V_72 = V_171 -> V_39 . V_54 . V_72 ;
F_27 ( & V_136 ) ;
break;
case V_165 :
sprintf ( V_65 , L_15 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
sprintf ( V_65 , L_16 , V_171 -> V_39 . V_54 . V_72 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
break;
case V_164 :
F_82 ( V_171 ) ;
break;
case V_167 :
F_82 ( V_172 ) ;
break;
default:
break;
}
}
static void F_85 ( struct V_87 * V_88 )
{
if ( V_163 == V_168 )
return;
F_86 () ;
F_29 ( F_84 , NULL ) ;
}
static int T_3 F_87 ( void )
{
int V_59 ;
V_171 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_171 )
return - V_91 ;
V_59 = F_32 ( & V_173 -> V_44 , & V_174 ) ;
if ( V_59 ) {
F_73 ( ( unsigned long ) V_171 ) ;
return V_59 ;
}
V_171 -> V_34 . V_52 = V_141 ;
V_171 -> V_34 . V_35 = V_142 ;
V_171 -> V_34 . V_107 = V_143 ;
V_171 -> V_34 . V_37 = V_62 ;
V_162 |= V_15 ;
return 0 ;
}
static int T_3 F_88 ( void )
{
int V_59 ;
if ( ! V_80 . V_175 )
return 0 ;
if ( ! V_60 )
return 0 ;
V_172 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_172 )
return - V_91 ;
V_59 = F_32 ( & V_173 -> V_44 , & V_176 ) ;
if ( V_59 ) {
F_73 ( ( unsigned long ) V_172 ) ;
return V_59 ;
}
V_172 -> V_34 . V_52 = V_106 ;
V_172 -> V_34 . V_35 = V_142 ;
V_172 -> V_34 . V_107 = V_108 ;
V_172 -> V_34 . V_37 = V_38 ;
V_172 -> V_39 . V_40 . V_41 = V_42 ;
V_162 |= V_17 ;
return 0 ;
}
static int T_3 F_89 ( void )
{
int V_59 ;
V_173 = F_31 ( L_17 , NULL , V_90 ) ;
if ( ! V_173 )
return - V_91 ;
V_59 = F_78 ( & V_173 -> V_44 , & V_177 . V_46 ) ;
if ( V_59 ) {
F_74 ( V_173 ) ;
return V_59 ;
}
V_59 = F_87 () ;
if ( V_59 )
return V_59 ;
V_59 = F_88 () ;
if ( V_59 )
return V_59 ;
F_79 ( V_13 ) ;
return 0 ;
}
static void F_90 ( struct V_87 * V_88 )
{
unsigned long V_178 = ( unsigned long ) V_117 ;
unsigned int V_179 ;
V_179 = F_91 ( V_117 , V_117 -> V_34 . V_52 , 0 ) ;
F_92 ( V_180 . V_178 , V_178 ) ;
F_92 ( V_180 . V_181 , V_179 ) ;
F_85 ( V_88 ) ;
}
static int T_3 F_93 ( void )
{
if ( ! V_60 )
return - V_182 ;
else
return 0 ;
}
static void F_94 ( struct V_87 * V_88 )
{
char * V_183 ;
if ( strcmp ( V_88 -> V_184 , V_185 ) == 0 )
V_183 = V_186 ;
else if ( strcmp ( V_88 -> V_184 , V_187 ) == 0 )
V_183 = V_188 ;
else if ( strcmp ( V_88 -> V_184 , V_189 ) == 0 )
V_183 = V_190 ;
else if ( strcmp ( V_88 -> V_184 , V_191 ) == 0 )
V_183 = V_192 ;
else if ( strcmp ( V_88 -> V_184 , V_193 ) == 0 )
V_183 = V_194 ;
else
return;
if ( strlen ( V_183 ) == 0 )
return;
F_26 ( V_183 , NULL , 0 , NULL ) ;
}
static int F_95 ( void )
{
if ( ! V_84 )
return - V_182 ;
V_195 = F_31 ( L_18 , NULL , V_90 ) ;
if ( ! V_195 )
return - V_91 ;
return F_32 ( & V_195 -> V_44 , & V_196 ) ;
}
static void F_96 ( struct V_87 * V_88 )
{
if ( strcmp ( V_88 -> V_184 , V_187 ) == 0 ||
strcmp ( V_88 -> V_184 , V_193 ) == 0 )
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
F_97 () ;
}
static int F_98 ( const char * V_65 , struct V_87 * V_88 ,
T_5 V_52 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_197 ; V_51 ++ ) {
if ( F_99 ( V_65 , V_198 [ V_51 ] -> V_184 ) ) {
if ( V_198 [ V_51 ] -> V_199 ) {
return V_198 [ V_51 ] -> V_199 ;
} else {
V_88 -> V_200 = V_198 [ V_51 ] ;
return V_52 ;
}
}
}
return - V_100 ;
}
static T_4 F_100 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_201 . V_200 -> V_184 ) ;
}
static T_4 F_101 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_201 , V_52 ) ;
}
static void F_102 ( char * V_202 )
{
F_86 () ;
V_201 . V_200 -> V_203 ( & V_201 ) ;
F_66 ( NULL ) ;
}
static T_4 F_103 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_204 . V_200 -> V_184 ) ;
}
static T_4 F_104 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_204 , V_52 ) ;
}
static void F_105 ( void )
{
F_106 () ;
V_204 . V_200 -> V_203 ( & V_204 ) ;
F_96 ( & V_204 ) ;
}
static T_4 F_107 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_205 . V_200 -> V_184 ) ;
}
static T_4 F_108 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_205 , V_52 ) ;
}
static void F_109 ( void * V_206 )
{
F_110 ( 0x04 ) ;
F_86 () ;
#ifdef F_111
F_112 ( NULL ) ;
#endif
V_205 . V_200 -> V_203 ( & V_205 ) ;
F_96 ( & V_205 ) ;
}
void F_113 ( void )
{
F_114 () ;
F_115 () ;
F_106 () ;
F_116 ( F_109 , NULL ) ;
}
static T_4 F_117 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_207 . V_200 -> V_184 ) ;
}
static T_4 F_118 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_207 , V_52 ) ;
}
static void F_119 ( void )
{
F_86 () ;
V_207 . V_200 -> V_203 ( & V_207 ) ;
F_96 ( & V_207 ) ;
}
static T_4 F_120 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_208 . V_200 -> V_184 ) ;
}
static T_4 F_121 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_208 , V_52 ) ;
}
static void F_122 ( void )
{
F_86 () ;
V_208 . V_200 -> V_203 ( & V_208 ) ;
F_96 ( & V_208 ) ;
}
static void T_3 F_123 ( void )
{
V_209 = F_31 ( L_19 , NULL ,
V_90 ) ;
if ( ! V_209 )
goto V_210;
if ( F_32 ( & V_209 -> V_44 ,
& V_211 ) )
goto V_210;
return;
V_210:
F_33 ( L_20 ) ;
}
static void T_3 F_124 ( void )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_197 ; V_51 ++ ) {
if ( ! V_198 [ V_51 ] -> V_212 )
continue;
V_198 [ V_51 ] -> V_199 =
V_198 [ V_51 ] -> V_212 () ;
}
}
static int T_3 F_125 ( void )
{
char V_213 [ 8 ] = { 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 } ;
F_126 ( & V_80 ) ;
if ( memcmp ( V_80 . V_78 , V_213 , sizeof( V_213 ) ) == 0 &&
V_60 )
memcpy ( V_80 . V_78 , V_61 . V_34 . V_78 ,
V_79 ) ;
F_124 () ;
F_123 () ;
return 0 ;
}
static void T_3 F_127 ( char * V_111 , char * V_214 , int V_215 )
{
int V_216 , V_217 ;
V_217 = 0 ;
for ( V_216 = 0 ; V_214 [ V_216 ] != 0 ; V_216 ++ ) {
if ( V_214 [ V_216 ] == '"' )
continue;
V_111 [ V_217 ++ ] = V_214 [ V_216 ] ;
if ( V_217 >= V_215 )
break;
}
}
static int T_3 F_128 ( char * V_213 )
{
if ( ! V_84 )
return 1 ;
F_127 ( V_186 , V_213 , 127 ) ;
V_186 [ 127 ] = 0 ;
V_201 . V_200 = & V_218 ;
return 1 ;
}
static int T_3 F_129 ( char * V_213 )
{
if ( ! V_84 )
return 1 ;
F_127 ( V_188 , V_213 , 127 ) ;
V_188 [ 127 ] = 0 ;
V_204 . V_200 = & V_218 ;
return 1 ;
}
static int T_3 F_130 ( char * V_213 )
{
if ( ! V_84 )
return 1 ;
F_127 ( V_190 , V_213 , 127 ) ;
V_190 [ 127 ] = 0 ;
V_207 . V_200 = & V_218 ;
return 1 ;
}
static int T_3 F_131 ( char * V_213 )
{
if ( ! V_84 )
return 1 ;
F_127 ( V_192 , V_213 , 127 ) ;
V_192 [ 127 ] = 0 ;
V_208 . V_200 = & V_218 ;
return 1 ;
}
static int F_132 ( struct V_219 * V_220 ,
unsigned long V_221 , void * V_85 )
{
F_105 () ;
return V_222 ;
}
void T_3 F_133 ( void )
{
V_39 . type = F_7 () ;
switch ( V_39 . type ) {
case V_2 :
V_39 . V_85 . V_54 . V_86 . V_137 = V_70 ;
V_39 . V_85 . V_54 . V_86 . V_72 = V_71 ;
break;
case V_4 :
case V_6 :
V_39 . V_85 . V_40 . V_86 . V_137 = 0 ;
V_39 . V_85 . V_40 . V_86 . V_72 =
V_29 -> V_39 . V_40 . V_72 ;
V_39 . V_85 . V_40 . V_223 = V_29 -> V_39 . V_40 . V_223 ;
V_39 . V_85 . V_40 . V_224 = V_29 -> V_39 . V_40 . V_224 ;
break;
case V_8 :
strncpy ( V_39 . V_85 . V_225 . V_184 , V_150 ,
sizeof( V_39 . V_85 . V_225 . V_184 ) ) ;
break;
case V_10 :
break;
}
F_134 ( & V_226 , & V_227 ) ;
}
void T_3 F_135 ( void )
{
int V_59 ;
V_59 = F_4 ( V_228 , & V_61 ) ;
if ( ( V_59 == V_229 ) || ( V_59 == V_230 ) )
V_60 = 1 ;
}
void T_3 F_136 ( void )
{
struct V_231 V_232 ;
if ( F_137 ( & V_232 ) )
return;
V_70 = V_232 . V_137 ;
V_71 = V_232 . V_72 ;
V_30 |= V_32 ;
if ( ! V_232 . V_233 )
return;
V_30 |= V_33 ;
}
void F_138 ( struct V_234 * V_235 )
{
F_139 ( & V_236 ) ;
F_140 ( & V_235 -> V_237 , & V_238 ) ;
F_141 ( & V_236 ) ;
}
void F_142 ( struct V_234 * V_235 )
{
F_139 ( & V_236 ) ;
F_143 ( & V_235 -> V_237 ) ;
F_141 ( & V_236 ) ;
}
static void F_144 ( void )
{
struct V_234 * V_235 ;
if ( V_60 ) {
F_145 () ;
return;
}
F_146 (reset, &rcall, list)
V_235 -> V_203 () ;
}
void F_147 ( void )
{
struct V_239 * V_240 ;
V_240 = (struct V_239 * ) ( unsigned long ) F_148 () ;
V_240 -> V_241 = V_180 . V_241 ;
F_149 ( 0 ) ;
F_150 ( 0 , 28 ) ;
V_180 . V_242 . V_243 = V_244 | V_245 ;
V_180 . V_242 . V_20 =
( unsigned long ) V_246 ;
V_180 . V_247 . V_243 = V_244 | V_245 ;
V_180 . V_247 . V_20 =
( unsigned long ) V_248 ;
F_144 () ;
}
