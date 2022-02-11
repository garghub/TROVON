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
int F_3 ( unsigned long V_19 , void * V_20 )
{
register unsigned long T_1 V_21 ( L_1 ) = ( unsigned long ) V_20 ;
register unsigned long T_2 V_21 ( L_2 ) = 0 ;
asm volatile(
" diag %0,%2,0x308\n"
"0:\n"
EX_TABLE(0b,0b)
: "+d" (_addr), "+d" (_rc)
: "d" (subcode) : "cc", "memory");
return T_2 ;
}
static void F_4 ( struct V_22 * * V_23 )
{
while ( * V_23 ) {
( * V_23 ) -> V_24 = V_25 ;
V_23 ++ ;
}
}
static T_3 enum V_1 F_5 ( void )
{
struct V_26 * V_27 = V_28 ;
if ( V_29 & V_30 )
return V_8 ;
if ( ! ( V_29 & V_31 ) )
return V_10 ;
if ( ! ( V_29 & V_32 ) )
return V_2 ;
if ( V_27 -> V_33 . V_34 > V_35 )
return V_10 ;
if ( V_27 -> V_33 . V_36 != V_37 )
return V_10 ;
if ( V_27 -> V_38 . V_39 . V_40 == V_41 )
return V_6 ;
return V_4 ;
}
static T_4 F_6 ( struct V_42 * V_43 , struct V_44 * V_45 ,
char * V_46 )
{
return sprintf ( V_46 , L_3 , F_1 ( V_38 . type ) ) ;
}
T_5 F_7 ( char * V_47 , T_5 V_48 ,
const struct V_26 * V_49 )
{
int V_50 ;
T_5 V_51 ;
char V_52 = 0 ;
V_51 = 0 ;
if ( ( V_49 -> V_38 . V_53 . V_54 & V_55 ) &&
( V_49 -> V_38 . V_53 . V_56 > 0 ) ) {
V_51 = F_8 ( T_5 , V_48 - 1 , V_49 -> V_38 . V_53 . V_56 ) ;
memcpy ( V_47 , V_49 -> V_38 . V_53 . V_57 , V_51 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ )
if ( ( V_47 [ V_50 ] > 0x80 && V_47 [ V_50 ] < 0x8a ) ||
( V_47 [ V_50 ] > 0x90 && V_47 [ V_50 ] < 0x9a ) ||
( V_47 [ V_50 ] > 0xa1 && V_47 [ V_50 ] < 0xaa ) ) {
V_52 = 1 ;
break;
}
if ( ! V_52 )
F_9 ( V_47 , V_51 ) ;
F_10 ( V_47 , V_51 ) ;
}
V_47 [ V_51 ] = 0 ;
return V_51 ;
}
T_5 F_11 ( char * V_47 , T_5 V_48 )
{
T_5 V_58 ;
V_58 = 0 ;
if ( V_59 && ( V_60 . V_33 . V_36 == V_61 ) )
V_58 = F_7 ( V_47 , V_48 , & V_60 ) ;
else
V_47 [ 0 ] = 0 ;
return V_58 ;
}
static T_4 F_12 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
char V_62 [ V_63 + 1 ] = {} ;
F_11 ( V_62 , sizeof( V_62 ) ) ;
return sprintf ( V_46 , L_3 , V_62 ) ;
}
static T_5 F_13 ( const char * V_64 , T_5 V_65 )
{
while ( V_65 ) {
if ( V_64 [ V_65 - 1 ] != '\0' && V_64 [ V_65 - 1 ] != ' ' )
break;
V_65 -- ;
}
return V_65 ;
}
T_5 F_14 ( char * V_47 , T_5 V_48 ,
const struct V_26 * V_49 )
{
T_5 V_65 ;
T_5 V_50 ;
int V_52 ;
V_65 = F_15 ( V_48 - 1 , F_13 ( V_49 -> V_38 . V_39 . V_66 ,
V_49 -> V_38 . V_39 . V_67 ) ) ;
if ( ! V_65 )
goto V_68;
V_52 = 0 ;
for ( V_50 = 0 ; V_50 < V_65 ; V_50 ++ ) {
if ( ! isascii ( V_49 -> V_38 . V_39 . V_66 [ V_50 ] ) ) {
V_65 = 0 ;
goto V_68;
}
if ( ! V_52 && islower ( V_49 -> V_38 . V_39 . V_66 [ V_50 ] ) )
V_52 = 1 ;
}
if ( V_52 )
memcpy ( V_47 , V_49 -> V_38 . V_39 . V_66 , V_65 ) ;
else
for ( V_50 = 0 ; V_50 < V_65 ; V_50 ++ )
V_47 [ V_50 ] = tolower ( V_49 -> V_38 . V_39 . V_66 [ V_50 ] ) ;
V_68:
V_47 [ V_65 ] = '\0' ;
return V_65 ;
}
T_5 F_16 ( char * V_47 , T_5 V_51 )
{
T_5 V_58 ;
V_58 = 0 ;
if ( V_60 . V_33 . V_36 == V_37 )
V_58 = F_14 ( V_47 , V_51 , & V_60 ) ;
else
V_47 [ 0 ] = 0 ;
return V_58 ;
}
static T_4 F_17 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_26 * V_27 = V_28 ;
switch ( V_38 . type ) {
case V_2 :
return sprintf ( V_46 , L_4 , V_69 ) ;
case V_4 :
case V_6 :
return sprintf ( V_46 , L_4 , V_27 -> V_38 . V_39 . V_70 ) ;
default:
return 0 ;
}
}
static T_4 F_18 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 , char * V_64 ,
T_6 V_74 , T_5 V_65 )
{
return F_19 ( V_64 , V_65 , & V_74 , V_28 ,
V_75 ) ;
}
static T_4 F_20 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 , char * V_64 ,
T_6 V_74 , T_5 V_65 )
{
unsigned int V_48 = V_28 -> V_38 . V_39 . V_67 ;
void * V_66 = & V_28 -> V_38 . V_39 . V_66 ;
return F_19 ( V_64 , V_65 , & V_74 , V_66 , V_48 ) ;
}
static T_4 F_21 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
char V_76 [ V_77 + 1 ] = {} ;
if ( ! V_78 . V_79 )
return sprintf ( V_46 , L_5 ) ;
memcpy ( V_76 , & V_78 . V_76 , V_77 ) ;
F_10 ( V_76 , V_77 ) ;
F_22 ( V_76 ) ;
return sprintf ( V_46 , L_3 , V_76 ) ;
}
static int T_3 F_23 ( void )
{
int V_58 ;
V_58 = F_24 ( & V_80 -> V_43 , & V_81 ) ;
if ( V_58 )
goto V_68;
V_58 = F_25 ( & V_80 -> V_43 , & V_82 ) ;
if ( V_58 )
goto V_83;
V_58 = F_25 ( & V_80 -> V_43 , & V_84 ) ;
if ( ! V_58 )
goto V_68;
F_26 ( & V_80 -> V_43 , & V_82 ) ;
V_83:
F_27 ( & V_80 -> V_43 , & V_81 ) ;
V_68:
return V_58 ;
}
static void F_28 ( void * V_85 )
{
F_3 ( V_86 , NULL ) ;
if ( V_87 )
F_29 ( L_6 , NULL , 0 , NULL ) ;
else if ( V_38 . type == V_2 )
F_30 ( & V_38 . V_88 . V_53 . V_89 ) ;
}
static void F_31 ( struct V_90 * V_91 )
{
F_32 ( F_28 , NULL ) ;
}
static int T_3 F_33 ( void )
{
int V_58 ;
V_80 = F_34 ( L_7 , NULL , V_92 ) ;
if ( ! V_80 ) {
V_58 = - V_93 ;
goto V_68;
}
switch ( V_38 . type ) {
case V_2 :
if ( V_87 )
V_58 = F_24 ( & V_80 -> V_43 ,
& V_94 ) ;
else
V_58 = F_24 ( & V_80 -> V_43 ,
& V_95 ) ;
break;
case V_4 :
case V_6 :
V_58 = F_23 () ;
break;
case V_8 :
V_58 = F_24 ( & V_80 -> V_43 , & V_96 ) ;
break;
default:
V_58 = F_24 ( & V_80 -> V_43 ,
& V_97 ) ;
break;
}
V_68:
if ( V_58 )
F_35 ( L_8 , V_58 ) ;
return 0 ;
}
static T_4 F_36 ( struct V_26 * V_49 ,
char * V_46 )
{
char V_98 [ V_63 + 1 ] = {} ;
F_7 ( V_98 , sizeof( V_98 ) , V_49 ) ;
return sprintf ( V_46 , L_3 , V_98 ) ;
}
static T_4 F_37 ( struct V_26 * V_49 ,
T_5 V_99 ,
const char * V_64 , T_5 V_51 )
{
int V_50 , V_100 ;
V_100 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_100 -- ;
if ( V_100 > V_99 )
return - V_101 ;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ )
if ( ! ( isalnum ( V_64 [ V_50 ] ) || isascii ( V_64 [ V_50 ] ) || isprint ( V_64 [ V_50 ] ) ) )
return - V_101 ;
memset ( V_49 -> V_38 . V_53 . V_57 , 0 , V_63 ) ;
V_49 -> V_38 . V_53 . V_56 = V_100 ;
if ( V_100 > 0 ) {
V_49 -> V_38 . V_53 . V_54 |= V_55 ;
memcpy ( V_49 -> V_38 . V_53 . V_57 , V_64 , V_100 ) ;
F_38 ( V_49 -> V_38 . V_53 . V_57 , V_100 ) ;
} else {
V_49 -> V_38 . V_53 . V_54 &= ~ V_55 ;
}
return V_51 ;
}
static T_4 F_39 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_36 ( V_102 , V_46 ) ;
}
static T_4 F_40 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_37 ( V_102 , 56 , V_64 , V_51 ) ;
}
static T_4 F_41 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_36 ( V_103 , V_46 ) ;
}
static T_4 F_42 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_37 ( V_103 , 64 , V_64 , V_51 ) ;
}
static T_4 F_43 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 ,
char * V_64 , T_6 V_74 , T_5 V_65 )
{
T_5 V_48 = V_104 -> V_38 . V_39 . V_67 ;
void * V_66 = V_104 -> V_38 . V_39 . V_66 ;
return F_19 ( V_64 , V_65 , & V_74 , V_66 , V_48 ) ;
}
static T_4 F_44 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 ,
char * V_64 , T_6 V_74 , T_5 V_65 )
{
T_5 V_105 ;
T_5 V_106 ;
if ( V_74 < 0 )
return - V_101 ;
if ( V_74 >= V_107 )
return - V_108 ;
if ( V_65 > V_107 - V_74 )
V_65 = V_107 - V_74 ;
memcpy ( V_104 -> V_38 . V_39 . V_66 , V_64 + V_74 , V_65 ) ;
V_106 = V_74 + V_65 ;
if ( V_106 % 8 ) {
V_105 = 8 - ( V_106 % 8 ) ;
memset ( V_104 -> V_38 . V_39 . V_66 + V_106 ,
0 , V_105 ) ;
V_106 += V_105 ;
}
V_104 -> V_38 . V_39 . V_67 = V_106 ;
V_104 -> V_33 . V_51 = V_109 + V_106 ;
V_104 -> V_33 . V_110 = V_111 + V_106 ;
return V_65 ;
}
static void F_45 ( char * V_76 ,
struct V_26 * V_112 )
{
memcpy ( V_76 , V_112 -> V_38 . V_53 . V_113 , V_77 ) ;
F_10 ( V_76 , V_77 ) ;
V_76 [ V_77 ] = 0 ;
F_22 ( V_76 ) ;
}
static T_4 F_46 ( struct V_26 * V_49 ,
char * V_46 )
{
char V_64 [ V_77 + 1 ] ;
F_45 ( V_64 , V_49 ) ;
return sprintf ( V_46 , L_3 , V_64 ) ;
}
static T_4 F_47 ( struct V_26 * V_49 ,
const char * V_64 , T_5 V_51 )
{
int V_50 , V_114 ;
V_114 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_114 -- ;
if ( ( V_114 > V_77 ) || ( ( V_114 > 0 ) && ( V_64 [ 0 ] == ' ' ) ) )
return - V_101 ;
for ( V_50 = 0 ; V_50 < V_114 ; V_50 ++ ) {
if ( isalpha ( V_64 [ V_50 ] ) || isdigit ( V_64 [ V_50 ] ) || ( V_64 [ V_50 ] == ' ' ) ||
( V_64 [ V_50 ] == '.' ) )
continue;
return - V_101 ;
}
memset ( V_49 -> V_38 . V_53 . V_113 , ' ' , V_77 ) ;
memcpy ( V_49 -> V_38 . V_53 . V_113 , V_64 , V_114 ) ;
F_38 ( V_49 -> V_38 . V_53 . V_113 , V_77 ) ;
return V_51 ;
}
static T_4 F_48 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_46 ( V_102 , V_46 ) ;
}
static T_4 F_49 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_47 ( V_102 , V_64 , V_51 ) ;
}
static T_4 F_50 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_46 ( V_103 , V_46 ) ;
}
static T_4 F_51 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_47 ( V_103 , V_64 , V_51 ) ;
}
static void F_52 ( char * V_115 ,
struct V_26 * V_49 )
{
memcpy ( V_115 , V_49 -> V_38 . V_53 . V_116 , V_117 ) ;
F_10 ( V_115 , V_117 ) ;
V_115 [ V_117 ] = 0 ;
}
static T_4 F_53 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
char V_116 [ V_117 + 1 ] = {} ;
F_52 ( V_116 , V_102 ) ;
return sprintf ( V_46 , L_3 , V_116 ) ;
}
static T_4 F_54 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_118 ;
V_118 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_118 -- ;
if ( V_118 > V_117 )
return - V_101 ;
memset ( V_102 -> V_38 . V_53 . V_116 , 0x40 , V_117 ) ;
if ( V_118 > 0 ) {
V_102 -> V_38 . V_53 . V_54 |=
V_119 ;
memcpy ( V_102 -> V_38 . V_53 . V_116 , V_64 , V_118 ) ;
F_38 ( V_102 -> V_38 . V_53 . V_116 , V_118 ) ;
F_55 ( V_102 -> V_38 . V_53 . V_116 , V_118 ) ;
} else {
V_102 -> V_38 . V_53 . V_54 &=
~ V_119 ;
}
return V_51 ;
}
static int F_56 ( enum V_1 type )
{
if ( ! ( V_120 & type ) )
return - V_101 ;
switch( type ) {
case V_2 :
if ( V_59 )
V_121 = V_122 ;
else if ( V_87 )
V_121 = V_123 ;
else
V_121 = V_124 ;
V_125 = V_103 ;
break;
case V_4 :
if ( V_59 )
V_121 = V_126 ;
else if ( V_87 )
V_121 = V_127 ;
else
V_121 = V_128 ;
V_125 = V_104 ;
break;
case V_6 :
V_121 = V_129 ;
break;
case V_8 :
if ( V_59 )
V_121 = V_130 ;
else
V_121 = V_131 ;
V_125 = V_102 ;
break;
case V_10 :
V_121 = V_132 ;
break;
default:
F_57 () ;
}
V_133 = type ;
return 0 ;
}
static T_4 F_58 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_1 ( V_133 ) ) ;
}
static T_4 F_59 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_101 ;
if ( strncmp ( V_64 , V_3 , strlen ( V_3 ) ) == 0 )
V_58 = F_56 ( V_2 ) ;
else if ( strncmp ( V_64 , V_5 , strlen ( V_5 ) ) == 0 )
V_58 = F_56 ( V_4 ) ;
else if ( strncmp ( V_64 , V_9 , strlen ( V_9 ) ) == 0 )
V_58 = F_56 ( V_8 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_60 ( char * V_115 , struct V_26 * V_49 ,
const enum V_134 V_135 )
{
char V_76 [ V_77 + 1 ] = {} ;
char V_98 [ V_63 + 1 ] = {} ;
char V_116 [ V_117 + 1 ] = {} ;
T_5 V_136 = 0 ;
F_45 ( V_76 , V_49 ) ;
F_52 ( V_116 , V_49 ) ;
F_7 ( V_98 , sizeof( V_98 ) , V_49 ) ;
switch ( V_135 ) {
case V_123 :
V_136 = sprintf ( V_115 , L_9 , V_49 -> V_38 . V_53 . V_70 ) ;
break;
case V_131 :
V_136 = sprintf ( V_115 , L_10 , V_116 ) ;
break;
default:
break;
}
if ( strlen ( V_76 ) > 0 )
V_136 += sprintf ( V_115 + V_136 , L_11 , V_76 ) ;
if ( strlen ( V_98 ) > 0 )
sprintf ( V_115 + V_136 , L_12 , V_98 ) ;
}
static void F_61 ( void * V_85 )
{
struct V_137 V_138 ;
static char V_64 [ 128 ] ;
switch ( V_121 ) {
case V_124 :
V_138 . V_70 = V_103 -> V_38 . V_53 . V_70 ;
V_138 . V_139 = 0 ;
F_30 ( & V_138 ) ;
break;
case V_123 :
F_60 ( V_64 , V_103 , V_123 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_122 :
F_3 ( V_140 , V_103 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_126 :
F_3 ( V_140 , V_104 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_128 :
F_3 ( V_86 , NULL ) ;
break;
case V_127 :
F_29 ( L_6 , NULL , 0 , NULL ) ;
break;
case V_130 :
F_3 ( V_140 , V_102 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_131 :
F_60 ( V_64 , V_102 , V_131 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_132 :
if ( V_87 )
F_29 ( L_6 , NULL , 0 , NULL ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_129 :
break;
}
F_62 ( ( unsigned long ) F_63 ( 0 ) ) ;
}
static void F_64 ( struct V_90 * V_91 )
{
F_32 ( F_61 , NULL ) ;
}
static void F_65 ( struct V_26 * V_49 )
{
V_49 -> V_33 . V_51 = V_141 ;
V_49 -> V_33 . V_34 = V_142 ;
V_49 -> V_33 . V_110 = V_143 ;
V_49 -> V_33 . V_36 = V_61 ;
}
static void F_66 ( struct V_26 * V_49 )
{
if ( V_78 . V_79 )
memcpy ( V_49 -> V_38 . V_53 . V_113 ,
& V_78 . V_76 , V_77 ) ;
else
memset ( V_49 -> V_38 . V_53 . V_113 , 0x40 , V_77 ) ;
V_49 -> V_33 . V_144 = V_145 ;
if ( V_87 && V_59 &&
( V_60 . V_38 . V_53 . V_54 & V_55 ) ) {
V_49 -> V_38 . V_53 . V_54 |= V_55 ;
V_49 -> V_38 . V_53 . V_56 =
V_60 . V_38 . V_53 . V_56 ;
memcpy ( V_49 -> V_38 . V_53 . V_57 ,
V_60 . V_38 . V_53 . V_57 , V_63 ) ;
}
}
static int T_3 F_67 ( void )
{
int V_58 ;
if ( ! V_87 )
return 0 ;
V_102 = ( void * ) F_68 ( V_146 ) ;
if ( ! V_102 )
return - V_93 ;
if ( ! V_59 )
V_147 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_148 -> V_43 , & V_149 ) ;
if ( V_58 )
return V_58 ;
F_65 ( V_102 ) ;
if ( V_38 . type == V_8 ) {
memset ( V_102 -> V_38 . V_53 . V_116 ,
' ' , V_117 ) ;
memcpy ( V_102 -> V_38 . V_53 . V_116 ,
V_150 , strlen ( V_150 ) ) ;
F_38 ( V_102 -> V_38 . V_53 . V_116 , V_117 ) ;
V_102 -> V_38 . V_53 . V_54 |=
V_119 ;
F_66 ( V_102 ) ;
}
V_120 |= V_8 ;
return 0 ;
}
static int T_3 F_69 ( void )
{
int V_58 ;
V_103 = ( void * ) F_68 ( V_146 ) ;
if ( ! V_103 )
return - V_93 ;
if ( V_87 ) {
if ( ! V_59 )
V_151 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_148 -> V_43 ,
& V_152 ) ;
} else {
if( ! V_59 )
V_153 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_148 -> V_43 ,
& V_154 ) ;
}
if ( V_58 )
return V_58 ;
F_65 ( V_103 ) ;
if ( V_38 . type == V_2 ) {
V_103 -> V_38 . V_53 . V_70 = V_69 ;
F_66 ( V_103 ) ;
}
V_120 |= V_2 ;
return 0 ;
}
static int T_3 F_70 ( void )
{
int V_58 ;
if ( ! V_59 ) {
if ( V_38 . type == V_4 ) {
F_4 ( V_155 ) ;
V_156 . V_45 . V_24 = V_25 ;
} else
return 0 ;
}
V_104 = ( void * ) F_68 ( V_146 ) ;
if ( ! V_104 )
return - V_93 ;
V_157 = F_34 ( V_5 , NULL ,
& V_148 -> V_43 ) ;
if ( ! V_157 ) {
F_71 ( ( unsigned long ) V_104 ) ;
return - V_93 ;
}
V_58 = F_24 ( & V_157 -> V_43 , & V_158 ) ;
if ( V_58 ) {
F_72 ( V_157 ) ;
F_71 ( ( unsigned long ) V_104 ) ;
return V_58 ;
}
V_58 = F_25 ( & V_157 -> V_43 ,
& V_156 ) ;
if ( V_58 ) {
F_27 ( & V_157 -> V_43 , & V_158 ) ;
F_72 ( V_157 ) ;
F_71 ( ( unsigned long ) V_104 ) ;
return V_58 ;
}
if ( V_38 . type == V_4 )
memcpy ( V_104 , V_28 , V_159 ) ;
else {
V_104 -> V_33 . V_51 = V_109 ;
V_104 -> V_33 . V_34 = V_142 ;
V_104 -> V_33 . V_110 = V_111 ;
V_104 -> V_33 . V_36 = V_37 ;
V_104 -> V_38 . V_39 . V_40 = V_160 ;
}
V_120 |= V_4 ;
return 0 ;
}
static int T_3 F_73 ( void )
{
int V_58 ;
V_148 = F_34 ( L_13 , NULL , V_92 ) ;
if ( ! V_148 )
return - V_93 ;
V_58 = F_74 ( & V_148 -> V_43 , & V_161 . V_45 ) ;
if ( V_58 ) {
F_72 ( V_148 ) ;
return V_58 ;
}
V_58 = F_69 () ;
if ( V_58 )
return V_58 ;
V_58 = F_70 () ;
if ( V_58 )
return V_58 ;
V_58 = F_67 () ;
if ( V_58 )
return V_58 ;
V_58 = F_56 ( V_38 . type ) ;
if ( V_58 )
return V_58 ;
return 0 ;
}
static int F_75 ( enum V_12 type )
{
if ( ! ( V_162 & type ) )
return - V_101 ;
switch ( type ) {
case V_15 :
if ( V_59 )
V_163 = V_164 ;
else if ( V_87 )
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
static T_4 F_76 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_2 ( V_12 ) ) ;
}
static T_4 F_77 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_101 ;
if ( strncmp ( V_64 , V_14 , strlen ( V_14 ) ) == 0 )
V_58 = F_75 ( V_13 ) ;
else if ( strncmp ( V_64 , V_16 , strlen ( V_16 ) ) == 0 )
V_58 = F_75 ( V_15 ) ;
else if ( strncmp ( V_64 , V_18 , strlen ( V_18 ) ) == 0 )
V_58 = F_75 ( V_17 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_78 ( void * V_85 )
{
struct V_137 V_138 ;
static char V_64 [ 100 ] ;
switch ( V_163 ) {
case V_166 :
V_138 . V_70 = V_169 -> V_38 . V_53 . V_70 ;
V_138 . V_139 = 0 ;
F_30 ( & V_138 ) ;
break;
case V_165 :
sprintf ( V_64 , L_14 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
sprintf ( V_64 , L_15 , V_169 -> V_38 . V_53 . V_70 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_164 :
F_3 ( V_140 , V_169 ) ;
F_3 ( V_170 , NULL ) ;
break;
case V_167 :
F_3 ( V_140 , V_171 ) ;
F_3 ( V_170 , NULL ) ;
break;
default:
break;
}
}
static void F_79 ( struct V_90 * V_91 )
{
if ( V_163 == V_168 )
return;
F_80 () ;
F_32 ( F_78 , NULL ) ;
}
static int T_3 F_81 ( void )
{
int V_58 ;
V_169 = ( void * ) F_68 ( V_146 ) ;
if ( ! V_169 )
return - V_93 ;
V_58 = F_24 ( & V_172 -> V_43 , & V_173 ) ;
if ( V_58 ) {
F_71 ( ( unsigned long ) V_169 ) ;
return V_58 ;
}
V_169 -> V_33 . V_51 = V_141 ;
V_169 -> V_33 . V_34 = V_142 ;
V_169 -> V_33 . V_110 = V_143 ;
V_169 -> V_33 . V_36 = V_61 ;
V_162 |= V_15 ;
return 0 ;
}
static int T_3 F_82 ( void )
{
int V_58 ;
if ( ! V_78 . V_174 )
return 0 ;
if ( ! V_59 )
return 0 ;
V_171 = ( void * ) F_68 ( V_146 ) ;
if ( ! V_171 )
return - V_93 ;
V_58 = F_24 ( & V_172 -> V_43 , & V_175 ) ;
if ( V_58 ) {
F_71 ( ( unsigned long ) V_171 ) ;
return V_58 ;
}
V_171 -> V_33 . V_51 = V_109 ;
V_171 -> V_33 . V_34 = V_142 ;
V_171 -> V_33 . V_110 = V_111 ;
V_171 -> V_33 . V_36 = V_37 ;
V_171 -> V_38 . V_39 . V_40 = V_41 ;
V_162 |= V_17 ;
return 0 ;
}
static int T_3 F_83 ( void )
{
int V_58 ;
V_172 = F_34 ( L_16 , NULL , V_92 ) ;
if ( ! V_172 )
return - V_93 ;
V_58 = F_74 ( & V_172 -> V_43 , & V_176 . V_45 ) ;
if ( V_58 ) {
F_72 ( V_172 ) ;
return V_58 ;
}
V_58 = F_81 () ;
if ( V_58 )
return V_58 ;
V_58 = F_82 () ;
if ( V_58 )
return V_58 ;
F_75 ( V_13 ) ;
return 0 ;
}
static void F_84 ( struct V_90 * V_91 )
{
F_85 () ;
#ifdef F_86
asm volatile("sturg %0,%1"
:: "a" ((unsigned long) reipl_block_actual),
"a" (&lowcore_ptr[smp_processor_id()]->ipib));
#else
asm volatile("stura %0,%1"
:: "a" ((unsigned long) reipl_block_actual),
"a" (&lowcore_ptr[smp_processor_id()]->ipib));
#endif
asm volatile("stura %0,%1"
:: "a" (csum_partial(reipl_block_actual,
reipl_block_actual->hdr.len, 0)),
"a" (&lowcore_ptr[smp_processor_id()]->ipib_checksum));
F_87 () ;
F_79 ( V_91 ) ;
}
static int T_3 F_88 ( void )
{
if ( ! V_59 )
return - V_177 ;
else
return 0 ;
}
static void F_89 ( struct V_90 * V_91 )
{
char * V_178 , * V_179 ;
if ( strcmp ( V_91 -> V_180 , V_181 ) == 0 )
V_178 = V_182 ;
else if ( strcmp ( V_91 -> V_180 , V_183 ) == 0 )
V_178 = V_184 ;
else if ( strcmp ( V_91 -> V_180 , V_185 ) == 0 )
V_178 = V_186 ;
else if ( strcmp ( V_91 -> V_180 , V_187 ) == 0 )
V_178 = V_188 ;
else if ( strcmp ( V_91 -> V_180 , V_189 ) == 0 )
V_178 = V_190 ;
else
return;
if ( strlen ( V_178 ) == 0 )
return;
do {
V_179 = strchr ( V_178 , '\n' ) ;
if ( V_179 ) {
V_179 [ 0 ] = 0 ;
V_179 += 1 ;
}
F_29 ( V_178 , NULL , 0 , NULL ) ;
V_178 = V_179 ;
} while ( V_178 != NULL );
}
static int F_90 ( void )
{
if ( ! V_87 )
return - V_177 ;
V_191 = F_34 ( L_17 , NULL , V_92 ) ;
if ( ! V_191 )
return - V_93 ;
return F_24 ( & V_191 -> V_43 , & V_192 ) ;
}
static void F_91 ( struct V_90 * V_91 )
{
if ( strcmp ( V_91 -> V_180 , V_183 ) == 0 ||
strcmp ( V_91 -> V_180 , V_189 ) == 0 )
F_62 ( ( unsigned long ) F_63 ( 0 ) ) ;
while ( F_92 ( F_93 () , V_193 ) == V_194 )
F_94 () ;
for (; ; ) ;
}
static int F_95 ( const char * V_64 , struct V_90 * V_91 ,
T_5 V_51 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_195 ; V_50 ++ ) {
if ( F_96 ( V_64 , V_196 [ V_50 ] -> V_180 ) ) {
if ( V_196 [ V_50 ] -> V_197 ) {
return V_196 [ V_50 ] -> V_197 ;
} else {
V_91 -> V_198 = V_196 [ V_50 ] ;
return V_51 ;
}
}
}
return - V_101 ;
}
static T_4 F_97 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_199 . V_198 -> V_180 ) ;
}
static T_4 F_98 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_95 ( V_64 , & V_199 , V_51 ) ;
}
static void F_99 ( char * V_200 )
{
F_80 () ;
V_199 . V_198 -> V_201 ( & V_199 ) ;
F_64 ( NULL ) ;
}
static T_4 F_100 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_202 . V_198 -> V_180 ) ;
}
static T_4 F_101 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_95 ( V_64 , & V_202 , V_51 ) ;
}
static void F_102 ( void )
{
V_202 . V_198 -> V_201 ( & V_202 ) ;
F_91 ( & V_202 ) ;
}
static T_4 F_103 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_203 . V_198 -> V_180 ) ;
}
static T_4 F_104 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_95 ( V_64 , & V_203 , V_51 ) ;
}
void F_105 ( void )
{
F_80 () ;
V_203 . V_198 -> V_201 ( & V_203 ) ;
F_91 ( & V_203 ) ;
}
static T_4 F_106 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_204 . V_198 -> V_180 ) ;
}
static T_4 F_107 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_95 ( V_64 , & V_204 , V_51 ) ;
}
static void F_108 ( void )
{
F_80 () ;
V_204 . V_198 -> V_201 ( & V_204 ) ;
F_91 ( & V_204 ) ;
}
static T_4 F_109 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_205 . V_198 -> V_180 ) ;
}
static T_4 F_110 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_95 ( V_64 , & V_205 , V_51 ) ;
}
static void F_111 ( void )
{
F_80 () ;
V_205 . V_198 -> V_201 ( & V_205 ) ;
F_91 ( & V_205 ) ;
}
static void T_3 F_112 ( void )
{
V_206 = F_34 ( L_18 , NULL ,
V_92 ) ;
if ( ! V_206 )
goto V_207;
if ( F_74 ( & V_206 -> V_43 ,
& V_208 . V_45 ) )
goto V_207;
if ( F_74 ( & V_206 -> V_43 ,
& V_209 . V_45 ) )
goto V_207;
if ( F_74 ( & V_206 -> V_43 ,
& V_210 . V_45 ) )
goto V_207;
if ( F_74 ( & V_206 -> V_43 ,
& V_211 . V_45 ) )
goto V_207;
if ( F_74 ( & V_206 -> V_43 ,
& V_212 . V_45 ) )
goto V_207;
return;
V_207:
F_35 ( L_19 ) ;
}
static void T_3 F_113 ( void )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_195 ; V_50 ++ ) {
if ( ! V_196 [ V_50 ] -> V_213 )
continue;
V_196 [ V_50 ] -> V_197 =
V_196 [ V_50 ] -> V_213 () ;
}
}
static int T_3 F_114 ( void )
{
F_115 ( & V_78 ) ;
F_113 () ;
F_112 () ;
return 0 ;
}
static void T_3 F_116 ( char * V_115 , char * V_214 , int V_215 )
{
int V_216 , V_217 ;
V_217 = 0 ;
for ( V_216 = 0 ; V_214 [ V_216 ] != 0 ; V_216 ++ ) {
if ( V_214 [ V_216 ] == '"' )
continue;
V_115 [ V_217 ++ ] = V_214 [ V_216 ] ;
if ( V_217 >= V_215 )
break;
}
}
static int T_3 F_117 ( char * V_218 )
{
if ( ! V_87 )
return 1 ;
F_116 ( V_182 , V_218 , 127 ) ;
V_182 [ 127 ] = 0 ;
V_199 . V_198 = & V_219 ;
return 1 ;
}
static int T_3 F_118 ( char * V_218 )
{
if ( ! V_87 )
return 1 ;
F_116 ( V_184 , V_218 , 127 ) ;
V_184 [ 127 ] = 0 ;
V_202 . V_198 = & V_219 ;
return 1 ;
}
static int T_3 F_119 ( char * V_218 )
{
if ( ! V_87 )
return 1 ;
F_116 ( V_186 , V_218 , 127 ) ;
V_186 [ 127 ] = 0 ;
V_204 . V_198 = & V_219 ;
return 1 ;
}
static int T_3 F_120 ( char * V_218 )
{
if ( ! V_87 )
return 1 ;
F_116 ( V_188 , V_218 , 127 ) ;
V_188 [ 127 ] = 0 ;
V_205 . V_198 = & V_219 ;
return 1 ;
}
static int F_121 ( struct V_220 * V_221 ,
unsigned long V_222 , void * V_88 )
{
F_102 () ;
return V_223 ;
}
void T_3 F_122 ( void )
{
V_38 . type = F_5 () ;
switch ( V_38 . type ) {
case V_2 :
V_38 . V_88 . V_53 . V_89 . V_70 = V_69 ;
V_38 . V_88 . V_53 . V_89 . V_139 = 0 ;
break;
case V_4 :
case V_6 :
V_38 . V_88 . V_39 . V_89 . V_70 =
V_28 -> V_38 . V_39 . V_70 ;
V_38 . V_88 . V_39 . V_89 . V_139 = 0 ;
V_38 . V_88 . V_39 . V_224 = V_28 -> V_38 . V_39 . V_224 ;
V_38 . V_88 . V_39 . V_225 = V_28 -> V_38 . V_39 . V_225 ;
break;
case V_8 :
strncpy ( V_38 . V_88 . V_226 . V_180 , V_150 ,
sizeof( V_38 . V_88 . V_226 . V_180 ) ) ;
break;
case V_10 :
break;
}
F_123 ( & V_227 , & V_228 ) ;
}
void T_3 F_124 ( void )
{
int V_58 ;
V_58 = F_3 ( V_229 , & V_60 ) ;
if ( ( V_58 == V_230 ) || ( V_58 == V_231 ) )
V_59 = 1 ;
}
void T_3 F_125 ( void )
{
struct V_232 V_233 ;
void * V_214 , * V_115 ;
if ( F_126 ( & V_233 ) )
return;
V_69 = V_233 . V_70 ;
V_29 |= V_31 ;
if ( ! V_233 . V_234 )
return;
V_29 |= V_32 ;
V_214 = ( void * ) ( unsigned long ) V_235 . V_236 ;
V_115 = ( void * ) V_237 ;
memmove ( V_115 , V_214 , V_159 ) ;
V_235 . V_236 = V_237 ;
}
void F_127 ( struct V_238 * V_239 )
{
F_128 ( & V_240 ) ;
F_129 ( & V_239 -> V_241 , & V_242 ) ;
F_130 ( & V_240 ) ;
}
void F_131 ( struct V_238 * V_239 )
{
F_128 ( & V_240 ) ;
F_132 ( & V_239 -> V_241 ) ;
F_130 ( & V_240 ) ;
}
static void F_133 ( void )
{
struct V_238 * V_239 ;
#ifdef F_86
if ( V_59 ) {
F_134 () ;
return;
}
#endif
F_135 (reset, &rcall, list)
V_239 -> V_201 () ;
}
void F_136 ( void )
{
struct V_243 * V_244 ;
V_244 = (struct V_243 * ) ( unsigned long ) F_137 () ;
V_244 -> V_245 = V_235 . V_245 ;
V_246 = ( V_247 ) ( unsigned long ) V_244 ;
F_138 ( 0 ) ;
F_139 ( 0 , 28 ) ;
V_235 . V_248 . V_249 = V_250 & ~ V_251 ;
V_235 . V_248 . V_20 =
V_252 | ( unsigned long ) V_253 ;
V_235 . V_254 . V_249 = V_250 & ~ V_251 ;
V_235 . V_254 . V_20 =
V_252 | ( unsigned long ) V_255 ;
F_133 () ;
}
