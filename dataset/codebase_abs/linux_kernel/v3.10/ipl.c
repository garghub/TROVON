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
static T_5 F_7 ( char * V_47 , T_5 V_48 ,
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
static T_5 F_14 ( char * V_47 , T_5 V_48 ,
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
static void F_56 ( struct V_26 * V_120 )
{
V_121 = V_120 ;
F_57 ( V_122 , V_121 ,
V_120 -> V_33 . V_51 ) ;
}
static int F_58 ( enum V_1 type )
{
if ( ! ( V_123 & type ) )
return - V_101 ;
switch( type ) {
case V_2 :
if ( V_59 )
V_124 = V_125 ;
else if ( V_87 )
V_124 = V_126 ;
else
V_124 = V_127 ;
F_56 ( V_103 ) ;
break;
case V_4 :
if ( V_59 )
V_124 = V_128 ;
else if ( V_87 )
V_124 = V_129 ;
else
V_124 = V_130 ;
F_56 ( V_104 ) ;
break;
case V_6 :
V_124 = V_131 ;
break;
case V_8 :
if ( V_59 )
V_124 = V_132 ;
else
V_124 = V_133 ;
F_56 ( V_102 ) ;
break;
case V_10 :
V_124 = V_134 ;
break;
default:
F_59 () ;
}
V_135 = type ;
return 0 ;
}
static T_4 F_60 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_1 ( V_135 ) ) ;
}
static T_4 F_61 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_101 ;
if ( strncmp ( V_64 , V_3 , strlen ( V_3 ) ) == 0 )
V_58 = F_58 ( V_2 ) ;
else if ( strncmp ( V_64 , V_5 , strlen ( V_5 ) ) == 0 )
V_58 = F_58 ( V_4 ) ;
else if ( strncmp ( V_64 , V_9 , strlen ( V_9 ) ) == 0 )
V_58 = F_58 ( V_8 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_62 ( char * V_115 , struct V_26 * V_49 ,
const enum V_136 V_137 )
{
char V_76 [ V_77 + 1 ] = {} ;
char V_98 [ V_63 + 1 ] = {} ;
char V_116 [ V_117 + 1 ] = {} ;
T_5 V_138 = 0 ;
F_45 ( V_76 , V_49 ) ;
F_52 ( V_116 , V_49 ) ;
F_7 ( V_98 , sizeof( V_98 ) , V_49 ) ;
switch ( V_137 ) {
case V_126 :
V_138 = sprintf ( V_115 , L_9 , V_49 -> V_38 . V_53 . V_70 ) ;
break;
case V_133 :
V_138 = sprintf ( V_115 , L_10 , V_116 ) ;
break;
default:
break;
}
if ( strlen ( V_76 ) > 0 )
V_138 += sprintf ( V_115 + V_138 , L_11 , V_76 ) ;
if ( strlen ( V_98 ) > 0 )
sprintf ( V_115 + V_138 , L_12 , V_98 ) ;
}
static void F_63 ( void * V_85 )
{
struct V_139 V_140 ;
static char V_64 [ 128 ] ;
switch ( V_124 ) {
case V_127 :
V_140 . V_70 = V_103 -> V_38 . V_53 . V_70 ;
V_140 . V_141 = 0 ;
F_30 ( & V_140 ) ;
break;
case V_126 :
F_62 ( V_64 , V_103 , V_126 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_125 :
F_3 ( V_142 , V_103 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_128 :
F_3 ( V_142 , V_104 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_130 :
F_3 ( V_86 , NULL ) ;
break;
case V_129 :
F_29 ( L_6 , NULL , 0 , NULL ) ;
break;
case V_132 :
F_3 ( V_142 , V_102 ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_133 :
F_62 ( V_64 , V_102 , V_133 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_134 :
if ( V_87 )
F_29 ( L_6 , NULL , 0 , NULL ) ;
F_3 ( V_86 , NULL ) ;
break;
case V_131 :
break;
}
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
}
static void F_66 ( struct V_90 * V_91 )
{
F_32 ( F_63 , NULL ) ;
}
static void F_67 ( struct V_26 * V_49 )
{
V_49 -> V_33 . V_51 = V_143 ;
V_49 -> V_33 . V_34 = V_144 ;
V_49 -> V_33 . V_110 = V_145 ;
V_49 -> V_33 . V_36 = V_61 ;
}
static void F_68 ( struct V_26 * V_49 )
{
if ( V_78 . V_79 )
memcpy ( V_49 -> V_38 . V_53 . V_113 ,
& V_78 . V_76 , V_77 ) ;
else
memset ( V_49 -> V_38 . V_53 . V_113 , 0x40 , V_77 ) ;
V_49 -> V_33 . V_146 = V_147 ;
if ( V_87 && V_59 &&
( V_60 . V_38 . V_53 . V_54 & V_55 ) ) {
V_49 -> V_38 . V_53 . V_54 |= V_55 ;
V_49 -> V_38 . V_53 . V_56 =
V_60 . V_38 . V_53 . V_56 ;
memcpy ( V_49 -> V_38 . V_53 . V_57 ,
V_60 . V_38 . V_53 . V_57 , V_63 ) ;
}
}
static int T_3 F_69 ( void )
{
int V_58 ;
if ( ! V_87 )
return 0 ;
V_102 = ( void * ) F_70 ( V_148 ) ;
if ( ! V_102 )
return - V_93 ;
if ( ! V_59 )
V_149 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_150 -> V_43 , & V_151 ) ;
if ( V_58 )
return V_58 ;
F_67 ( V_102 ) ;
if ( V_38 . type == V_8 ) {
memset ( V_102 -> V_38 . V_53 . V_116 ,
' ' , V_117 ) ;
memcpy ( V_102 -> V_38 . V_53 . V_116 ,
V_152 , strlen ( V_152 ) ) ;
F_38 ( V_102 -> V_38 . V_53 . V_116 , V_117 ) ;
V_102 -> V_38 . V_53 . V_54 |=
V_119 ;
F_68 ( V_102 ) ;
}
V_123 |= V_8 ;
return 0 ;
}
static int T_3 F_71 ( void )
{
int V_58 ;
V_103 = ( void * ) F_70 ( V_148 ) ;
if ( ! V_103 )
return - V_93 ;
if ( V_87 ) {
if ( ! V_59 )
V_153 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_150 -> V_43 ,
& V_154 ) ;
} else {
if( ! V_59 )
V_155 . V_45 . V_24 = V_25 ;
V_58 = F_24 ( & V_150 -> V_43 ,
& V_156 ) ;
}
if ( V_58 )
return V_58 ;
F_67 ( V_103 ) ;
if ( V_38 . type == V_2 ) {
V_103 -> V_38 . V_53 . V_70 = V_69 ;
F_68 ( V_103 ) ;
}
V_123 |= V_2 ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_58 ;
if ( ! V_59 ) {
if ( V_38 . type == V_4 ) {
F_4 ( V_157 ) ;
V_158 . V_45 . V_24 = V_25 ;
} else
return 0 ;
}
V_104 = ( void * ) F_70 ( V_148 ) ;
if ( ! V_104 )
return - V_93 ;
V_159 = F_34 ( V_5 , NULL ,
& V_150 -> V_43 ) ;
if ( ! V_159 ) {
F_73 ( ( unsigned long ) V_104 ) ;
return - V_93 ;
}
V_58 = F_24 ( & V_159 -> V_43 , & V_160 ) ;
if ( V_58 ) {
F_74 ( V_159 ) ;
F_73 ( ( unsigned long ) V_104 ) ;
return V_58 ;
}
V_58 = F_25 ( & V_159 -> V_43 ,
& V_158 ) ;
if ( V_58 ) {
F_27 ( & V_159 -> V_43 , & V_160 ) ;
F_74 ( V_159 ) ;
F_73 ( ( unsigned long ) V_104 ) ;
return V_58 ;
}
if ( V_38 . type == V_4 )
memcpy ( V_104 , V_28 , V_161 ) ;
else {
V_104 -> V_33 . V_51 = V_109 ;
V_104 -> V_33 . V_34 = V_144 ;
V_104 -> V_33 . V_110 = V_111 ;
V_104 -> V_33 . V_36 = V_37 ;
V_104 -> V_38 . V_39 . V_40 = V_162 ;
}
V_123 |= V_4 ;
return 0 ;
}
static int T_3 F_75 ( void )
{
enum V_1 V_135 = V_38 . type ;
struct V_26 * V_120 ;
unsigned long V_48 ;
V_120 = F_76 ( V_122 , & V_48 ) ;
if ( ! V_120 )
goto V_68;
if ( V_120 -> V_33 . V_36 == V_37 ) {
memcpy ( V_104 , V_120 , V_48 ) ;
V_135 = V_4 ;
} else if ( V_120 -> V_33 . V_36 == V_61 ) {
memcpy ( V_103 , V_120 , V_48 ) ;
V_135 = V_2 ;
}
V_68:
return F_58 ( V_135 ) ;
}
static int T_3 F_77 ( void )
{
int V_58 ;
V_150 = F_34 ( L_13 , NULL , V_92 ) ;
if ( ! V_150 )
return - V_93 ;
V_58 = F_78 ( & V_150 -> V_43 , & V_163 . V_45 ) ;
if ( V_58 ) {
F_74 ( V_150 ) ;
return V_58 ;
}
V_58 = F_71 () ;
if ( V_58 )
return V_58 ;
V_58 = F_72 () ;
if ( V_58 )
return V_58 ;
V_58 = F_69 () ;
if ( V_58 )
return V_58 ;
return F_75 () ;
}
static int F_79 ( enum V_12 type )
{
if ( ! ( V_164 & type ) )
return - V_101 ;
switch ( type ) {
case V_15 :
if ( V_59 )
V_165 = V_166 ;
else if ( V_87 )
V_165 = V_167 ;
else
V_165 = V_168 ;
break;
case V_17 :
V_165 = V_169 ;
break;
default:
V_165 = V_170 ;
}
V_12 = type ;
return 0 ;
}
static T_4 F_80 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_2 ( V_12 ) ) ;
}
static T_4 F_81 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_101 ;
if ( strncmp ( V_64 , V_14 , strlen ( V_14 ) ) == 0 )
V_58 = F_79 ( V_13 ) ;
else if ( strncmp ( V_64 , V_16 , strlen ( V_16 ) ) == 0 )
V_58 = F_79 ( V_15 ) ;
else if ( strncmp ( V_64 , V_18 , strlen ( V_18 ) ) == 0 )
V_58 = F_79 ( V_17 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_82 ( void * V_171 )
{
F_3 ( V_142 , V_171 ) ;
while ( 1 ) {
if ( F_3 ( V_172 , NULL ) != 0x302 )
break;
F_83 ( V_173 ) ;
}
}
static void F_84 ( void * V_85 )
{
struct V_139 V_140 ;
static char V_64 [ 100 ] ;
switch ( V_165 ) {
case V_168 :
V_140 . V_70 = V_174 -> V_38 . V_53 . V_70 ;
V_140 . V_141 = 0 ;
F_30 ( & V_140 ) ;
break;
case V_167 :
sprintf ( V_64 , L_14 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
sprintf ( V_64 , L_15 , V_174 -> V_38 . V_53 . V_70 ) ;
F_29 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_166 :
F_82 ( V_174 ) ;
break;
case V_169 :
F_82 ( V_175 ) ;
break;
default:
break;
}
}
static void F_85 ( struct V_90 * V_91 )
{
if ( V_165 == V_170 )
return;
F_86 () ;
F_32 ( F_84 , NULL ) ;
}
static int T_3 F_87 ( void )
{
int V_58 ;
V_174 = ( void * ) F_70 ( V_148 ) ;
if ( ! V_174 )
return - V_93 ;
V_58 = F_24 ( & V_176 -> V_43 , & V_177 ) ;
if ( V_58 ) {
F_73 ( ( unsigned long ) V_174 ) ;
return V_58 ;
}
V_174 -> V_33 . V_51 = V_143 ;
V_174 -> V_33 . V_34 = V_144 ;
V_174 -> V_33 . V_110 = V_145 ;
V_174 -> V_33 . V_36 = V_61 ;
V_164 |= V_15 ;
return 0 ;
}
static int T_3 F_88 ( void )
{
int V_58 ;
if ( ! V_78 . V_178 )
return 0 ;
if ( ! V_59 )
return 0 ;
V_175 = ( void * ) F_70 ( V_148 ) ;
if ( ! V_175 )
return - V_93 ;
V_58 = F_24 ( & V_176 -> V_43 , & V_179 ) ;
if ( V_58 ) {
F_73 ( ( unsigned long ) V_175 ) ;
return V_58 ;
}
V_175 -> V_33 . V_51 = V_109 ;
V_175 -> V_33 . V_34 = V_144 ;
V_175 -> V_33 . V_110 = V_111 ;
V_175 -> V_33 . V_36 = V_37 ;
V_175 -> V_38 . V_39 . V_40 = V_41 ;
V_164 |= V_17 ;
return 0 ;
}
static int T_3 F_89 ( void )
{
int V_58 ;
V_176 = F_34 ( L_16 , NULL , V_92 ) ;
if ( ! V_176 )
return - V_93 ;
V_58 = F_78 ( & V_176 -> V_43 , & V_180 . V_45 ) ;
if ( V_58 ) {
F_74 ( V_176 ) ;
return V_58 ;
}
V_58 = F_87 () ;
if ( V_58 )
return V_58 ;
V_58 = F_88 () ;
if ( V_58 )
return V_58 ;
F_79 ( V_13 ) ;
return 0 ;
}
static void F_90 ( struct V_90 * V_91 )
{
unsigned long V_181 = ( unsigned long ) V_121 ;
unsigned int V_182 ;
V_182 = F_91 ( V_121 , V_121 -> V_33 . V_51 , 0 ) ;
F_92 ( V_183 . V_181 , V_181 ) ;
F_92 ( V_183 . V_184 , V_182 ) ;
F_85 ( V_91 ) ;
}
static int T_3 F_93 ( void )
{
if ( ! V_59 )
return - V_185 ;
else
return 0 ;
}
static void F_94 ( struct V_90 * V_91 )
{
char * V_186 ;
if ( strcmp ( V_91 -> V_187 , V_188 ) == 0 )
V_186 = V_189 ;
else if ( strcmp ( V_91 -> V_187 , V_190 ) == 0 )
V_186 = V_191 ;
else if ( strcmp ( V_91 -> V_187 , V_192 ) == 0 )
V_186 = V_193 ;
else if ( strcmp ( V_91 -> V_187 , V_194 ) == 0 )
V_186 = V_195 ;
else if ( strcmp ( V_91 -> V_187 , V_196 ) == 0 )
V_186 = V_197 ;
else
return;
if ( strlen ( V_186 ) == 0 )
return;
F_29 ( V_186 , NULL , 0 , NULL ) ;
}
static int F_95 ( void )
{
if ( ! V_87 )
return - V_185 ;
V_198 = F_34 ( L_17 , NULL , V_92 ) ;
if ( ! V_198 )
return - V_93 ;
return F_24 ( & V_198 -> V_43 , & V_199 ) ;
}
static void F_96 ( struct V_90 * V_91 )
{
if ( strcmp ( V_91 -> V_187 , V_190 ) == 0 ||
strcmp ( V_91 -> V_187 , V_196 ) == 0 )
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
F_97 () ;
}
static int F_98 ( const char * V_64 , struct V_90 * V_91 ,
T_5 V_51 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_200 ; V_50 ++ ) {
if ( F_99 ( V_64 , V_201 [ V_50 ] -> V_187 ) ) {
if ( V_201 [ V_50 ] -> V_202 ) {
return V_201 [ V_50 ] -> V_202 ;
} else {
V_91 -> V_203 = V_201 [ V_50 ] ;
return V_51 ;
}
}
}
return - V_101 ;
}
static T_4 F_100 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_204 . V_203 -> V_187 ) ;
}
static T_4 F_101 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_98 ( V_64 , & V_204 , V_51 ) ;
}
static void F_102 ( char * V_205 )
{
F_86 () ;
V_204 . V_203 -> V_206 ( & V_204 ) ;
F_66 ( NULL ) ;
}
static T_4 F_103 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_207 . V_203 -> V_187 ) ;
}
static T_4 F_104 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_98 ( V_64 , & V_207 , V_51 ) ;
}
static void F_105 ( void )
{
F_106 () ;
V_207 . V_203 -> V_206 ( & V_207 ) ;
F_96 ( & V_207 ) ;
}
static T_4 F_107 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_208 . V_203 -> V_187 ) ;
}
static T_4 F_108 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_98 ( V_64 , & V_208 , V_51 ) ;
}
static void F_109 ( void * V_209 )
{
F_110 ( 0x04 ) ;
F_86 () ;
#ifdef F_111
F_112 ( NULL ) ;
#endif
V_208 . V_203 -> V_206 ( & V_208 ) ;
F_96 ( & V_208 ) ;
}
void F_113 ( void )
{
F_114 () ;
F_115 () ;
F_106 () ;
F_116 ( F_109 , NULL ) ;
}
static T_4 F_117 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_210 . V_203 -> V_187 ) ;
}
static T_4 F_118 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_98 ( V_64 , & V_210 , V_51 ) ;
}
static void F_119 ( void )
{
F_86 () ;
V_210 . V_203 -> V_206 ( & V_210 ) ;
F_96 ( & V_210 ) ;
}
static T_4 F_120 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_211 . V_203 -> V_187 ) ;
}
static T_4 F_121 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_98 ( V_64 , & V_211 , V_51 ) ;
}
static void F_122 ( void )
{
F_86 () ;
V_211 . V_203 -> V_206 ( & V_211 ) ;
F_96 ( & V_211 ) ;
}
static void T_3 F_123 ( void )
{
V_212 = F_34 ( L_18 , NULL ,
V_92 ) ;
if ( ! V_212 )
goto V_213;
if ( F_78 ( & V_212 -> V_43 ,
& V_214 . V_45 ) )
goto V_213;
if ( F_78 ( & V_212 -> V_43 ,
& V_215 . V_45 ) )
goto V_213;
if ( F_78 ( & V_212 -> V_43 ,
& V_216 . V_45 ) )
goto V_213;
if ( F_78 ( & V_212 -> V_43 ,
& V_217 . V_45 ) )
goto V_213;
if ( F_78 ( & V_212 -> V_43 ,
& V_218 . V_45 ) )
goto V_213;
return;
V_213:
F_35 ( L_19 ) ;
}
static void T_3 F_124 ( void )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_200 ; V_50 ++ ) {
if ( ! V_201 [ V_50 ] -> V_219 )
continue;
V_201 [ V_50 ] -> V_202 =
V_201 [ V_50 ] -> V_219 () ;
}
}
static int T_3 F_125 ( void )
{
F_126 ( & V_78 ) ;
F_124 () ;
F_123 () ;
return 0 ;
}
static void T_3 F_127 ( char * V_115 , char * V_220 , int V_221 )
{
int V_222 , V_223 ;
V_223 = 0 ;
for ( V_222 = 0 ; V_220 [ V_222 ] != 0 ; V_222 ++ ) {
if ( V_220 [ V_222 ] == '"' )
continue;
V_115 [ V_223 ++ ] = V_220 [ V_222 ] ;
if ( V_223 >= V_221 )
break;
}
}
static int T_3 F_128 ( char * V_224 )
{
if ( ! V_87 )
return 1 ;
F_127 ( V_189 , V_224 , 127 ) ;
V_189 [ 127 ] = 0 ;
V_204 . V_203 = & V_225 ;
return 1 ;
}
static int T_3 F_129 ( char * V_224 )
{
if ( ! V_87 )
return 1 ;
F_127 ( V_191 , V_224 , 127 ) ;
V_191 [ 127 ] = 0 ;
V_207 . V_203 = & V_225 ;
return 1 ;
}
static int T_3 F_130 ( char * V_224 )
{
if ( ! V_87 )
return 1 ;
F_127 ( V_193 , V_224 , 127 ) ;
V_193 [ 127 ] = 0 ;
V_210 . V_203 = & V_225 ;
return 1 ;
}
static int T_3 F_131 ( char * V_224 )
{
if ( ! V_87 )
return 1 ;
F_127 ( V_195 , V_224 , 127 ) ;
V_195 [ 127 ] = 0 ;
V_211 . V_203 = & V_225 ;
return 1 ;
}
static int F_132 ( struct V_226 * V_227 ,
unsigned long V_228 , void * V_88 )
{
F_105 () ;
return V_229 ;
}
void T_3 F_133 ( void )
{
V_38 . type = F_5 () ;
switch ( V_38 . type ) {
case V_2 :
V_38 . V_88 . V_53 . V_89 . V_70 = V_69 ;
V_38 . V_88 . V_53 . V_89 . V_141 = 0 ;
break;
case V_4 :
case V_6 :
V_38 . V_88 . V_39 . V_89 . V_70 =
V_28 -> V_38 . V_39 . V_70 ;
V_38 . V_88 . V_39 . V_89 . V_141 = 0 ;
V_38 . V_88 . V_39 . V_230 = V_28 -> V_38 . V_39 . V_230 ;
V_38 . V_88 . V_39 . V_231 = V_28 -> V_38 . V_39 . V_231 ;
break;
case V_8 :
strncpy ( V_38 . V_88 . V_232 . V_187 , V_152 ,
sizeof( V_38 . V_88 . V_232 . V_187 ) ) ;
break;
case V_10 :
break;
}
F_134 ( & V_233 , & V_234 ) ;
}
void T_3 F_135 ( void )
{
int V_58 ;
V_58 = F_3 ( V_235 , & V_60 ) ;
if ( ( V_58 == V_236 ) || ( V_58 == V_237 ) )
V_59 = 1 ;
}
void T_3 F_136 ( void )
{
struct V_238 V_239 ;
void * V_220 , * V_115 ;
if ( F_137 ( & V_239 ) )
return;
V_69 = V_239 . V_70 ;
V_29 |= V_31 ;
if ( ! V_239 . V_240 )
return;
V_29 |= V_32 ;
V_220 = ( void * ) ( unsigned long ) V_183 . V_241 ;
V_115 = ( void * ) V_242 ;
memmove ( V_115 , V_220 , V_161 ) ;
V_183 . V_241 = V_242 ;
}
void F_138 ( struct V_243 * V_244 )
{
F_139 ( & V_245 ) ;
F_140 ( & V_244 -> V_246 , & V_247 ) ;
F_141 ( & V_245 ) ;
}
void F_142 ( struct V_243 * V_244 )
{
F_139 ( & V_245 ) ;
F_143 ( & V_244 -> V_246 ) ;
F_141 ( & V_245 ) ;
}
static void F_144 ( void )
{
struct V_243 * V_244 ;
#ifdef F_145
if ( V_59 ) {
F_146 () ;
return;
}
#endif
F_147 (reset, &rcall, list)
V_244 -> V_206 () ;
}
void F_148 ( void (* F_149)( void * ) , void * V_88 )
{
struct V_248 * V_249 ;
V_249 = (struct V_248 * ) ( unsigned long ) F_150 () ;
V_249 -> V_250 = V_183 . V_250 ;
V_251 = ( V_252 ) ( unsigned long ) V_249 ;
F_151 ( 0 ) ;
F_152 ( 0 , 28 ) ;
V_183 . V_253 . V_254 = V_255 | V_256 ;
V_183 . V_253 . V_20 =
V_257 | ( unsigned long ) V_258 ;
V_183 . V_259 . V_254 = V_255 | V_256 ;
V_183 . V_259 . V_20 =
V_257 | ( unsigned long ) V_260 ;
F_153 () ;
F_144 () ;
if ( F_149 )
F_149 ( V_88 ) ;
}
