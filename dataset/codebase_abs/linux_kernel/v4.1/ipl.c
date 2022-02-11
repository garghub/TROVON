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
static void F_23 ( void * V_80 )
{
F_3 ( V_81 , NULL ) ;
if ( V_82 )
F_24 ( L_6 , NULL , 0 , NULL ) ;
else if ( V_38 . type == V_2 )
F_25 ( & V_38 . V_83 . V_53 . V_84 ) ;
}
static void F_26 ( struct V_85 * V_86 )
{
F_27 ( F_23 , NULL ) ;
}
static int T_3 F_28 ( void )
{
int V_58 ;
V_87 = F_29 ( L_7 , NULL , V_88 ) ;
if ( ! V_87 ) {
V_58 = - V_89 ;
goto V_68;
}
switch ( V_38 . type ) {
case V_2 :
if ( V_82 )
V_58 = F_30 ( & V_87 -> V_43 ,
& V_90 ) ;
else
V_58 = F_30 ( & V_87 -> V_43 ,
& V_91 ) ;
break;
case V_4 :
case V_6 :
V_58 = F_30 ( & V_87 -> V_43 , & V_92 ) ;
break;
case V_8 :
V_58 = F_30 ( & V_87 -> V_43 , & V_93 ) ;
break;
default:
V_58 = F_30 ( & V_87 -> V_43 ,
& V_94 ) ;
break;
}
V_68:
if ( V_58 )
F_31 ( L_8 , V_58 ) ;
return 0 ;
}
static T_4 F_32 ( struct V_26 * V_49 ,
char * V_46 )
{
char V_95 [ V_63 + 1 ] = {} ;
F_7 ( V_95 , sizeof( V_95 ) , V_49 ) ;
return sprintf ( V_46 , L_3 , V_95 ) ;
}
static T_4 F_33 ( struct V_26 * V_49 ,
T_5 V_96 ,
const char * V_64 , T_5 V_51 )
{
int V_50 , V_97 ;
V_97 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_97 -- ;
if ( V_97 > V_96 )
return - V_98 ;
for ( V_50 = 0 ; V_50 < V_97 ; V_50 ++ )
if ( ! ( isalnum ( V_64 [ V_50 ] ) || isascii ( V_64 [ V_50 ] ) || isprint ( V_64 [ V_50 ] ) ) )
return - V_98 ;
memset ( V_49 -> V_38 . V_53 . V_57 , 0 , V_63 ) ;
V_49 -> V_38 . V_53 . V_56 = V_97 ;
if ( V_97 > 0 ) {
V_49 -> V_38 . V_53 . V_54 |= V_55 ;
memcpy ( V_49 -> V_38 . V_53 . V_57 , V_64 , V_97 ) ;
F_34 ( V_49 -> V_38 . V_53 . V_57 , V_97 ) ;
} else {
V_49 -> V_38 . V_53 . V_54 &= ~ V_55 ;
}
return V_51 ;
}
static T_4 F_35 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_32 ( V_99 , V_46 ) ;
}
static T_4 F_36 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_33 ( V_99 , 56 , V_64 , V_51 ) ;
}
static T_4 F_37 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_32 ( V_100 , V_46 ) ;
}
static T_4 F_38 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_33 ( V_100 , 64 , V_64 , V_51 ) ;
}
static T_4 F_39 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 ,
char * V_64 , T_6 V_74 , T_5 V_65 )
{
T_5 V_48 = V_101 -> V_38 . V_39 . V_67 ;
void * V_66 = V_101 -> V_38 . V_39 . V_66 ;
return F_19 ( V_64 , V_65 , & V_74 , V_66 , V_48 ) ;
}
static T_4 F_40 ( struct V_71 * V_72 , struct V_42 * V_43 ,
struct V_73 * V_45 ,
char * V_64 , T_6 V_74 , T_5 V_65 )
{
T_5 V_102 ;
T_5 V_103 ;
if ( V_74 < 0 )
return - V_98 ;
if ( V_74 >= V_104 )
return - V_105 ;
if ( V_65 > V_104 - V_74 )
V_65 = V_104 - V_74 ;
memcpy ( V_101 -> V_38 . V_39 . V_66 , V_64 + V_74 , V_65 ) ;
V_103 = V_74 + V_65 ;
if ( V_103 % 8 ) {
V_102 = 8 - ( V_103 % 8 ) ;
memset ( V_101 -> V_38 . V_39 . V_66 + V_103 ,
0 , V_102 ) ;
V_103 += V_102 ;
}
V_101 -> V_38 . V_39 . V_67 = V_103 ;
V_101 -> V_33 . V_51 = V_106 + V_103 ;
V_101 -> V_33 . V_107 = V_108 + V_103 ;
return V_65 ;
}
static void F_41 ( char * V_76 ,
struct V_26 * V_109 )
{
memcpy ( V_76 , V_109 -> V_33 . V_76 , V_77 ) ;
F_10 ( V_76 , V_77 ) ;
V_76 [ V_77 ] = 0 ;
F_22 ( V_76 ) ;
}
static T_4 F_42 ( struct V_26 * V_49 ,
char * V_46 )
{
char V_64 [ V_77 + 1 ] ;
F_41 ( V_64 , V_49 ) ;
return sprintf ( V_46 , L_3 , V_64 ) ;
}
static T_4 F_43 ( struct V_26 * V_49 ,
const char * V_64 , T_5 V_51 )
{
int V_50 , V_110 ;
V_110 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_110 -- ;
if ( ( V_110 > V_77 ) || ( ( V_110 > 0 ) && ( V_64 [ 0 ] == ' ' ) ) )
return - V_98 ;
for ( V_50 = 0 ; V_50 < V_110 ; V_50 ++ ) {
if ( isalpha ( V_64 [ V_50 ] ) || isdigit ( V_64 [ V_50 ] ) || ( V_64 [ V_50 ] == ' ' ) ||
( V_64 [ V_50 ] == '.' ) )
continue;
return - V_98 ;
}
memset ( V_49 -> V_33 . V_76 , ' ' , V_77 ) ;
memcpy ( V_49 -> V_33 . V_76 , V_64 , V_110 ) ;
F_34 ( V_49 -> V_33 . V_76 , V_77 ) ;
return V_51 ;
}
static T_4 F_44 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_42 ( V_101 , V_46 ) ;
}
static T_4 F_45 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_43 ( V_101 , V_64 , V_51 ) ;
}
static T_4 F_46 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_42 ( V_99 , V_46 ) ;
}
static T_4 F_47 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_43 ( V_99 , V_64 , V_51 ) ;
}
static T_4 F_48 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return F_42 ( V_100 , V_46 ) ;
}
static T_4 F_49 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_43 ( V_100 , V_64 , V_51 ) ;
}
static void F_50 ( char * V_111 ,
struct V_26 * V_49 )
{
memcpy ( V_111 , V_49 -> V_38 . V_53 . V_112 , V_113 ) ;
F_10 ( V_111 , V_113 ) ;
V_111 [ V_113 ] = 0 ;
}
static T_4 F_51 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
char V_112 [ V_113 + 1 ] = {} ;
F_50 ( V_112 , V_99 ) ;
return sprintf ( V_46 , L_3 , V_112 ) ;
}
static T_4 F_52 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_114 ;
V_114 = V_51 ;
if ( ( V_51 > 0 ) && ( V_64 [ V_51 - 1 ] == '\n' ) )
V_114 -- ;
if ( V_114 > V_113 )
return - V_98 ;
memset ( V_99 -> V_38 . V_53 . V_112 , 0x40 , V_113 ) ;
if ( V_114 > 0 ) {
V_99 -> V_38 . V_53 . V_54 |=
V_115 ;
memcpy ( V_99 -> V_38 . V_53 . V_112 , V_64 , V_114 ) ;
F_34 ( V_99 -> V_38 . V_53 . V_112 , V_114 ) ;
F_53 ( V_99 -> V_38 . V_53 . V_112 , V_114 ) ;
} else {
V_99 -> V_38 . V_53 . V_54 &=
~ V_115 ;
}
return V_51 ;
}
static void F_54 ( struct V_26 * V_116 )
{
V_117 = V_116 ;
F_55 ( V_118 , V_117 ,
V_116 -> V_33 . V_51 ) ;
}
static int F_56 ( enum V_1 type )
{
if ( ! ( V_119 & type ) )
return - V_98 ;
switch( type ) {
case V_2 :
if ( V_59 )
V_120 = V_121 ;
else if ( V_82 )
V_120 = V_122 ;
else
V_120 = V_123 ;
F_54 ( V_100 ) ;
break;
case V_4 :
if ( V_59 )
V_120 = V_124 ;
else if ( V_82 )
V_120 = V_125 ;
else
V_120 = V_126 ;
F_54 ( V_101 ) ;
break;
case V_6 :
V_120 = V_127 ;
break;
case V_8 :
if ( V_59 )
V_120 = V_128 ;
else
V_120 = V_129 ;
F_54 ( V_99 ) ;
break;
case V_10 :
V_120 = V_130 ;
break;
default:
F_57 () ;
}
V_131 = type ;
return 0 ;
}
static T_4 F_58 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_1 ( V_131 ) ) ;
}
static T_4 F_59 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_98 ;
if ( strncmp ( V_64 , V_3 , strlen ( V_3 ) ) == 0 )
V_58 = F_56 ( V_2 ) ;
else if ( strncmp ( V_64 , V_5 , strlen ( V_5 ) ) == 0 )
V_58 = F_56 ( V_4 ) ;
else if ( strncmp ( V_64 , V_9 , strlen ( V_9 ) ) == 0 )
V_58 = F_56 ( V_8 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_60 ( char * V_111 , struct V_26 * V_49 ,
const enum V_132 V_133 )
{
char V_76 [ V_77 + 1 ] = {} ;
char V_95 [ V_63 + 1 ] = {} ;
char V_112 [ V_113 + 1 ] = {} ;
T_5 V_134 = 0 ;
F_41 ( V_76 , V_49 ) ;
F_50 ( V_112 , V_49 ) ;
F_7 ( V_95 , sizeof( V_95 ) , V_49 ) ;
switch ( V_133 ) {
case V_122 :
V_134 = sprintf ( V_111 , L_9 , V_49 -> V_38 . V_53 . V_70 ) ;
break;
case V_129 :
V_134 = sprintf ( V_111 , L_10 , V_112 ) ;
break;
default:
break;
}
if ( strlen ( V_76 ) > 0 )
V_134 += sprintf ( V_111 + V_134 , L_11 , V_76 ) ;
if ( strlen ( V_95 ) > 0 )
sprintf ( V_111 + V_134 , L_12 , V_95 ) ;
}
static void F_61 ( void * V_80 )
{
struct V_135 V_136 ;
static char V_64 [ 128 ] ;
switch ( V_120 ) {
case V_123 :
V_136 . V_70 = V_100 -> V_38 . V_53 . V_70 ;
V_136 . V_137 = 0 ;
F_25 ( & V_136 ) ;
break;
case V_122 :
F_60 ( V_64 , V_100 , V_122 ) ;
F_24 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_121 :
F_3 ( V_138 , V_100 ) ;
F_3 ( V_81 , NULL ) ;
break;
case V_124 :
F_3 ( V_138 , V_101 ) ;
F_3 ( V_81 , NULL ) ;
break;
case V_126 :
F_3 ( V_81 , NULL ) ;
break;
case V_125 :
F_24 ( L_6 , NULL , 0 , NULL ) ;
break;
case V_128 :
F_3 ( V_138 , V_99 ) ;
F_3 ( V_81 , NULL ) ;
break;
case V_129 :
F_60 ( V_64 , V_99 , V_129 ) ;
F_24 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_130 :
if ( V_82 )
F_24 ( L_6 , NULL , 0 , NULL ) ;
F_3 ( V_81 , NULL ) ;
break;
case V_127 :
break;
}
F_62 ( ( unsigned long ) F_63 ( 0 ) ) ;
}
static void F_64 ( struct V_85 * V_86 )
{
F_27 ( F_61 , NULL ) ;
}
static void F_65 ( struct V_26 * V_49 )
{
V_49 -> V_33 . V_51 = V_139 ;
V_49 -> V_33 . V_34 = V_140 ;
V_49 -> V_33 . V_107 = V_141 ;
V_49 -> V_33 . V_36 = V_61 ;
}
static void F_66 ( struct V_26 * V_49 )
{
if ( V_78 . V_79 )
memcpy ( V_49 -> V_33 . V_76 , & V_78 . V_76 , V_77 ) ;
else
memset ( V_49 -> V_33 . V_76 , 0x40 , V_77 ) ;
V_49 -> V_33 . V_142 = V_143 ;
if ( V_82 && V_59 &&
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
if ( ! V_82 )
return 0 ;
V_99 = ( void * ) F_68 ( V_144 ) ;
if ( ! V_99 )
return - V_89 ;
if ( ! V_59 )
V_145 . V_45 . V_24 = V_25 ;
V_58 = F_30 ( & V_146 -> V_43 , & V_147 ) ;
if ( V_58 )
return V_58 ;
F_65 ( V_99 ) ;
if ( V_38 . type == V_8 ) {
memset ( V_99 -> V_38 . V_53 . V_112 ,
' ' , V_113 ) ;
memcpy ( V_99 -> V_38 . V_53 . V_112 ,
V_148 , strlen ( V_148 ) ) ;
F_34 ( V_99 -> V_38 . V_53 . V_112 , V_113 ) ;
V_99 -> V_38 . V_53 . V_54 |=
V_115 ;
F_66 ( V_99 ) ;
}
V_119 |= V_8 ;
return 0 ;
}
static int T_3 F_69 ( void )
{
int V_58 ;
V_100 = ( void * ) F_68 ( V_144 ) ;
if ( ! V_100 )
return - V_89 ;
if ( V_82 ) {
if ( ! V_59 )
V_149 . V_45 . V_24 = V_25 ;
V_58 = F_30 ( & V_146 -> V_43 ,
& V_150 ) ;
} else {
if( ! V_59 )
V_151 . V_45 . V_24 = V_25 ;
V_58 = F_30 ( & V_146 -> V_43 ,
& V_152 ) ;
}
if ( V_58 )
return V_58 ;
F_65 ( V_100 ) ;
if ( V_38 . type == V_2 ) {
V_100 -> V_38 . V_53 . V_70 = V_69 ;
F_66 ( V_100 ) ;
}
V_119 |= V_2 ;
return 0 ;
}
static int T_3 F_70 ( void )
{
int V_58 ;
if ( ! V_59 ) {
if ( V_38 . type == V_4 ) {
F_4 ( V_153 ) ;
V_154 . V_45 . V_24 = V_25 ;
} else
return 0 ;
}
V_101 = ( void * ) F_68 ( V_144 ) ;
if ( ! V_101 )
return - V_89 ;
V_155 = F_29 ( V_5 , NULL ,
& V_146 -> V_43 ) ;
if ( ! V_155 ) {
F_71 ( ( unsigned long ) V_101 ) ;
return - V_89 ;
}
V_58 = F_30 ( & V_155 -> V_43 , & V_156 ) ;
if ( V_58 ) {
F_72 ( V_155 ) ;
F_71 ( ( unsigned long ) V_101 ) ;
return V_58 ;
}
if ( V_38 . type == V_4 ) {
memcpy ( V_101 , V_28 , V_157 ) ;
memcpy ( V_101 -> V_33 . V_76 , V_78 . V_76 ,
V_77 ) ;
} else {
V_101 -> V_33 . V_51 = V_106 ;
V_101 -> V_33 . V_34 = V_140 ;
V_101 -> V_33 . V_107 = V_108 ;
V_101 -> V_33 . V_36 = V_37 ;
V_101 -> V_38 . V_39 . V_40 = V_158 ;
}
V_119 |= V_4 ;
return 0 ;
}
static int T_3 F_73 ( void )
{
enum V_1 V_131 = V_38 . type ;
struct V_26 * V_116 ;
unsigned long V_48 ;
V_116 = F_74 ( V_118 , & V_48 ) ;
if ( ! V_116 )
goto V_68;
if ( V_116 -> V_33 . V_36 == V_37 ) {
memcpy ( V_101 , V_116 , V_48 ) ;
V_131 = V_4 ;
} else if ( V_116 -> V_33 . V_36 == V_61 ) {
memcpy ( V_100 , V_116 , V_48 ) ;
V_131 = V_2 ;
}
V_68:
return F_56 ( V_131 ) ;
}
static int T_3 F_75 ( void )
{
int V_58 ;
V_146 = F_29 ( L_13 , NULL , V_88 ) ;
if ( ! V_146 )
return - V_89 ;
V_58 = F_76 ( & V_146 -> V_43 , & V_159 . V_45 ) ;
if ( V_58 ) {
F_72 ( V_146 ) ;
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
return F_73 () ;
}
static int F_77 ( enum V_12 type )
{
if ( ! ( V_160 & type ) )
return - V_98 ;
switch ( type ) {
case V_15 :
if ( V_59 )
V_161 = V_162 ;
else if ( V_82 )
V_161 = V_163 ;
else
V_161 = V_164 ;
break;
case V_17 :
V_161 = V_165 ;
break;
default:
V_161 = V_166 ;
}
V_12 = type ;
return 0 ;
}
static T_4 F_78 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , F_2 ( V_12 ) ) ;
}
static T_4 F_79 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
int V_58 = - V_98 ;
if ( strncmp ( V_64 , V_14 , strlen ( V_14 ) ) == 0 )
V_58 = F_77 ( V_13 ) ;
else if ( strncmp ( V_64 , V_16 , strlen ( V_16 ) ) == 0 )
V_58 = F_77 ( V_15 ) ;
else if ( strncmp ( V_64 , V_18 , strlen ( V_18 ) ) == 0 )
V_58 = F_77 ( V_17 ) ;
return ( V_58 != 0 ) ? V_58 : V_51 ;
}
static void F_80 ( void * V_167 )
{
F_3 ( V_138 , V_167 ) ;
while ( 1 ) {
if ( F_3 ( V_168 , NULL ) != 0x302 )
break;
F_81 ( V_169 ) ;
}
}
static void F_82 ( void * V_80 )
{
struct V_135 V_136 ;
static char V_64 [ 100 ] ;
switch ( V_161 ) {
case V_164 :
V_136 . V_70 = V_170 -> V_38 . V_53 . V_70 ;
V_136 . V_137 = 0 ;
F_25 ( & V_136 ) ;
break;
case V_163 :
sprintf ( V_64 , L_14 ) ;
F_24 ( V_64 , NULL , 0 , NULL ) ;
sprintf ( V_64 , L_15 , V_170 -> V_38 . V_53 . V_70 ) ;
F_24 ( V_64 , NULL , 0 , NULL ) ;
break;
case V_162 :
F_80 ( V_170 ) ;
break;
case V_165 :
F_80 ( V_171 ) ;
break;
default:
break;
}
}
static void F_83 ( struct V_85 * V_86 )
{
if ( V_161 == V_166 )
return;
F_84 () ;
F_27 ( F_82 , NULL ) ;
}
static int T_3 F_85 ( void )
{
int V_58 ;
V_170 = ( void * ) F_68 ( V_144 ) ;
if ( ! V_170 )
return - V_89 ;
V_58 = F_30 ( & V_172 -> V_43 , & V_173 ) ;
if ( V_58 ) {
F_71 ( ( unsigned long ) V_170 ) ;
return V_58 ;
}
V_170 -> V_33 . V_51 = V_139 ;
V_170 -> V_33 . V_34 = V_140 ;
V_170 -> V_33 . V_107 = V_141 ;
V_170 -> V_33 . V_36 = V_61 ;
V_160 |= V_15 ;
return 0 ;
}
static int T_3 F_86 ( void )
{
int V_58 ;
if ( ! V_78 . V_174 )
return 0 ;
if ( ! V_59 )
return 0 ;
V_171 = ( void * ) F_68 ( V_144 ) ;
if ( ! V_171 )
return - V_89 ;
V_58 = F_30 ( & V_172 -> V_43 , & V_175 ) ;
if ( V_58 ) {
F_71 ( ( unsigned long ) V_171 ) ;
return V_58 ;
}
V_171 -> V_33 . V_51 = V_106 ;
V_171 -> V_33 . V_34 = V_140 ;
V_171 -> V_33 . V_107 = V_108 ;
V_171 -> V_33 . V_36 = V_37 ;
V_171 -> V_38 . V_39 . V_40 = V_41 ;
V_160 |= V_17 ;
return 0 ;
}
static int T_3 F_87 ( void )
{
int V_58 ;
V_172 = F_29 ( L_16 , NULL , V_88 ) ;
if ( ! V_172 )
return - V_89 ;
V_58 = F_76 ( & V_172 -> V_43 , & V_176 . V_45 ) ;
if ( V_58 ) {
F_72 ( V_172 ) ;
return V_58 ;
}
V_58 = F_85 () ;
if ( V_58 )
return V_58 ;
V_58 = F_86 () ;
if ( V_58 )
return V_58 ;
F_77 ( V_13 ) ;
return 0 ;
}
static void F_88 ( struct V_85 * V_86 )
{
unsigned long V_177 = ( unsigned long ) V_117 ;
unsigned int V_178 ;
V_178 = F_89 ( V_117 , V_117 -> V_33 . V_51 , 0 ) ;
F_90 ( V_179 . V_177 , V_177 ) ;
F_90 ( V_179 . V_180 , V_178 ) ;
F_83 ( V_86 ) ;
}
static int T_3 F_91 ( void )
{
if ( ! V_59 )
return - V_181 ;
else
return 0 ;
}
static void F_92 ( struct V_85 * V_86 )
{
char * V_182 ;
if ( strcmp ( V_86 -> V_183 , V_184 ) == 0 )
V_182 = V_185 ;
else if ( strcmp ( V_86 -> V_183 , V_186 ) == 0 )
V_182 = V_187 ;
else if ( strcmp ( V_86 -> V_183 , V_188 ) == 0 )
V_182 = V_189 ;
else if ( strcmp ( V_86 -> V_183 , V_190 ) == 0 )
V_182 = V_191 ;
else if ( strcmp ( V_86 -> V_183 , V_192 ) == 0 )
V_182 = V_193 ;
else
return;
if ( strlen ( V_182 ) == 0 )
return;
F_24 ( V_182 , NULL , 0 , NULL ) ;
}
static int F_93 ( void )
{
if ( ! V_82 )
return - V_181 ;
V_194 = F_29 ( L_17 , NULL , V_88 ) ;
if ( ! V_194 )
return - V_89 ;
return F_30 ( & V_194 -> V_43 , & V_195 ) ;
}
static void F_94 ( struct V_85 * V_86 )
{
if ( strcmp ( V_86 -> V_183 , V_186 ) == 0 ||
strcmp ( V_86 -> V_183 , V_192 ) == 0 )
F_62 ( ( unsigned long ) F_63 ( 0 ) ) ;
F_95 () ;
}
static int F_96 ( const char * V_64 , struct V_85 * V_86 ,
T_5 V_51 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_196 ; V_50 ++ ) {
if ( F_97 ( V_64 , V_197 [ V_50 ] -> V_183 ) ) {
if ( V_197 [ V_50 ] -> V_198 ) {
return V_197 [ V_50 ] -> V_198 ;
} else {
V_86 -> V_199 = V_197 [ V_50 ] ;
return V_51 ;
}
}
}
return - V_98 ;
}
static T_4 F_98 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_200 . V_199 -> V_183 ) ;
}
static T_4 F_99 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_96 ( V_64 , & V_200 , V_51 ) ;
}
static void F_100 ( char * V_201 )
{
F_84 () ;
V_200 . V_199 -> V_202 ( & V_200 ) ;
F_64 ( NULL ) ;
}
static T_4 F_101 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_203 . V_199 -> V_183 ) ;
}
static T_4 F_102 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_96 ( V_64 , & V_203 , V_51 ) ;
}
static void F_103 ( void )
{
F_104 () ;
V_203 . V_199 -> V_202 ( & V_203 ) ;
F_94 ( & V_203 ) ;
}
static T_4 F_105 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_204 . V_199 -> V_183 ) ;
}
static T_4 F_106 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_96 ( V_64 , & V_204 , V_51 ) ;
}
static void F_107 ( void * V_205 )
{
F_108 ( 0x04 ) ;
F_84 () ;
#ifdef F_109
F_110 ( NULL ) ;
#endif
V_204 . V_199 -> V_202 ( & V_204 ) ;
F_94 ( & V_204 ) ;
}
void F_111 ( void )
{
F_112 () ;
F_113 () ;
F_104 () ;
F_114 ( F_107 , NULL ) ;
}
static T_4 F_115 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_206 . V_199 -> V_183 ) ;
}
static T_4 F_116 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_96 ( V_64 , & V_206 , V_51 ) ;
}
static void F_117 ( void )
{
F_84 () ;
V_206 . V_199 -> V_202 ( & V_206 ) ;
F_94 ( & V_206 ) ;
}
static T_4 F_118 ( struct V_42 * V_43 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_3 , V_207 . V_199 -> V_183 ) ;
}
static T_4 F_119 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_64 , T_5 V_51 )
{
return F_96 ( V_64 , & V_207 , V_51 ) ;
}
static void F_120 ( void )
{
F_84 () ;
V_207 . V_199 -> V_202 ( & V_207 ) ;
F_94 ( & V_207 ) ;
}
static void T_3 F_121 ( void )
{
V_208 = F_29 ( L_18 , NULL ,
V_88 ) ;
if ( ! V_208 )
goto V_209;
if ( F_30 ( & V_208 -> V_43 ,
& V_210 ) )
goto V_209;
return;
V_209:
F_31 ( L_19 ) ;
}
static void T_3 F_122 ( void )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_196 ; V_50 ++ ) {
if ( ! V_197 [ V_50 ] -> V_211 )
continue;
V_197 [ V_50 ] -> V_198 =
V_197 [ V_50 ] -> V_211 () ;
}
}
static int T_3 F_123 ( void )
{
char V_212 [ 8 ] = { 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 } ;
F_124 ( & V_78 ) ;
if ( memcmp ( V_78 . V_76 , V_212 , sizeof( V_212 ) ) == 0 &&
V_59 )
memcpy ( V_78 . V_76 , V_60 . V_33 . V_76 ,
V_77 ) ;
F_122 () ;
F_121 () ;
return 0 ;
}
static void T_3 F_125 ( char * V_111 , char * V_213 , int V_214 )
{
int V_215 , V_216 ;
V_216 = 0 ;
for ( V_215 = 0 ; V_213 [ V_215 ] != 0 ; V_215 ++ ) {
if ( V_213 [ V_215 ] == '"' )
continue;
V_111 [ V_216 ++ ] = V_213 [ V_215 ] ;
if ( V_216 >= V_214 )
break;
}
}
static int T_3 F_126 ( char * V_212 )
{
if ( ! V_82 )
return 1 ;
F_125 ( V_185 , V_212 , 127 ) ;
V_185 [ 127 ] = 0 ;
V_200 . V_199 = & V_217 ;
return 1 ;
}
static int T_3 F_127 ( char * V_212 )
{
if ( ! V_82 )
return 1 ;
F_125 ( V_187 , V_212 , 127 ) ;
V_187 [ 127 ] = 0 ;
V_203 . V_199 = & V_217 ;
return 1 ;
}
static int T_3 F_128 ( char * V_212 )
{
if ( ! V_82 )
return 1 ;
F_125 ( V_189 , V_212 , 127 ) ;
V_189 [ 127 ] = 0 ;
V_206 . V_199 = & V_217 ;
return 1 ;
}
static int T_3 F_129 ( char * V_212 )
{
if ( ! V_82 )
return 1 ;
F_125 ( V_191 , V_212 , 127 ) ;
V_191 [ 127 ] = 0 ;
V_207 . V_199 = & V_217 ;
return 1 ;
}
static int F_130 ( struct V_218 * V_219 ,
unsigned long V_220 , void * V_83 )
{
F_103 () ;
return V_221 ;
}
void T_3 F_131 ( void )
{
V_38 . type = F_5 () ;
switch ( V_38 . type ) {
case V_2 :
V_38 . V_83 . V_53 . V_84 . V_70 = V_69 ;
V_38 . V_83 . V_53 . V_84 . V_137 = 0 ;
break;
case V_4 :
case V_6 :
V_38 . V_83 . V_39 . V_84 . V_70 =
V_28 -> V_38 . V_39 . V_70 ;
V_38 . V_83 . V_39 . V_84 . V_137 = 0 ;
V_38 . V_83 . V_39 . V_222 = V_28 -> V_38 . V_39 . V_222 ;
V_38 . V_83 . V_39 . V_223 = V_28 -> V_38 . V_39 . V_223 ;
break;
case V_8 :
strncpy ( V_38 . V_83 . V_224 . V_183 , V_148 ,
sizeof( V_38 . V_83 . V_224 . V_183 ) ) ;
break;
case V_10 :
break;
}
F_132 ( & V_225 , & V_226 ) ;
}
void T_3 F_133 ( void )
{
int V_58 ;
V_58 = F_3 ( V_227 , & V_60 ) ;
if ( ( V_58 == V_228 ) || ( V_58 == V_229 ) )
V_59 = 1 ;
}
void T_3 F_134 ( void )
{
struct V_230 V_231 ;
void * V_213 , * V_111 ;
if ( F_135 ( & V_231 ) )
return;
V_69 = V_231 . V_70 ;
V_29 |= V_31 ;
if ( ! V_231 . V_232 )
return;
V_29 |= V_32 ;
V_213 = ( void * ) ( unsigned long ) V_179 . V_233 ;
V_111 = ( void * ) V_234 ;
memmove ( V_111 , V_213 , V_157 ) ;
V_179 . V_233 = V_234 ;
}
void F_136 ( struct V_235 * V_236 )
{
F_137 ( & V_237 ) ;
F_138 ( & V_236 -> V_238 , & V_239 ) ;
F_139 ( & V_237 ) ;
}
void F_140 ( struct V_235 * V_236 )
{
F_137 ( & V_237 ) ;
F_141 ( & V_236 -> V_238 ) ;
F_139 ( & V_237 ) ;
}
static void F_142 ( void )
{
struct V_235 * V_236 ;
if ( V_59 ) {
F_143 () ;
return;
}
F_144 (reset, &rcall, list)
V_236 -> V_202 () ;
}
void F_145 ( void (* F_146)( void ) ,
void (* F_147)( void * ) , void * V_83 )
{
struct V_240 * V_241 ;
V_241 = (struct V_240 * ) ( unsigned long ) F_148 () ;
V_241 -> V_242 = V_179 . V_242 ;
V_243 = ( V_244 ) ( unsigned long ) V_241 ;
F_149 ( 0 ) ;
F_150 ( 0 , 28 ) ;
V_179 . V_245 . V_246 = V_247 | V_248 ;
V_179 . V_245 . V_20 =
V_249 | ( unsigned long ) V_250 ;
V_179 . V_251 . V_246 = V_247 | V_248 ;
V_179 . V_251 . V_20 =
V_249 | ( unsigned long ) V_252 ;
V_179 . V_253 = 0 ;
V_179 . V_254 = 0 ;
F_151 () ;
if ( F_146 )
F_146 () ;
F_142 () ;
if ( F_147 )
F_147 ( V_83 ) ;
}
