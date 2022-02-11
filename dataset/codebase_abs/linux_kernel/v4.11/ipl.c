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
if ( V_83 && V_39 . type == V_2 )
F_4 ( V_84 , NULL ) ;
F_4 ( V_85 , NULL ) ;
if ( V_86 )
F_26 ( L_7 , NULL , 0 , NULL ) ;
else if ( V_39 . type == V_2 )
F_27 ( & V_39 . V_87 . V_54 . V_88 ) ;
}
static void F_28 ( struct V_89 * V_90 )
{
F_29 ( F_25 , NULL ) ;
}
static int T_3 F_30 ( void )
{
int V_59 ;
V_91 = F_31 ( L_8 , NULL , V_92 ) ;
if ( ! V_91 ) {
V_59 = - V_93 ;
goto V_69;
}
switch ( V_39 . type ) {
case V_2 :
if ( V_86 )
V_59 = F_32 ( & V_91 -> V_44 ,
& V_94 ) ;
else
V_59 = F_32 ( & V_91 -> V_44 ,
& V_95 ) ;
break;
case V_4 :
case V_6 :
V_59 = F_32 ( & V_91 -> V_44 , & V_96 ) ;
break;
case V_8 :
V_59 = F_32 ( & V_91 -> V_44 , & V_97 ) ;
break;
default:
V_59 = F_32 ( & V_91 -> V_44 ,
& V_98 ) ;
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
char V_99 [ V_64 + 1 ] = {} ;
F_9 ( V_99 , sizeof( V_99 ) , V_50 ) ;
return sprintf ( V_47 , L_3 , V_99 ) ;
}
static T_4 F_35 ( struct V_27 * V_50 ,
T_5 V_100 ,
const char * V_65 , T_5 V_52 )
{
int V_51 , V_101 ;
V_101 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_101 -- ;
if ( V_101 > V_100 )
return - V_102 ;
for ( V_51 = 0 ; V_51 < V_101 ; V_51 ++ )
if ( ! ( isalnum ( V_65 [ V_51 ] ) || isascii ( V_65 [ V_51 ] ) || isprint ( V_65 [ V_51 ] ) ) )
return - V_102 ;
memset ( V_50 -> V_39 . V_54 . V_58 , 0 , V_64 ) ;
V_50 -> V_39 . V_54 . V_57 = V_101 ;
if ( V_101 > 0 ) {
V_50 -> V_39 . V_54 . V_55 |= V_56 ;
memcpy ( V_50 -> V_39 . V_54 . V_58 , V_65 , V_101 ) ;
F_36 ( V_50 -> V_39 . V_54 . V_58 , V_101 ) ;
} else {
V_50 -> V_39 . V_54 . V_55 &= ~ V_56 ;
}
return V_52 ;
}
static T_4 F_37 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_34 ( V_103 , V_47 ) ;
}
static T_4 F_38 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_35 ( V_103 , 56 , V_65 , V_52 ) ;
}
static T_4 F_39 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_34 ( V_104 , V_47 ) ;
}
static T_4 F_40 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_35 ( V_104 , 64 , V_65 , V_52 ) ;
}
static T_4 F_41 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 ,
char * V_65 , T_6 V_76 , T_5 V_66 )
{
T_5 V_49 = V_105 -> V_39 . V_40 . V_68 ;
void * V_67 = V_105 -> V_39 . V_40 . V_67 ;
return F_21 ( V_65 , V_66 , & V_76 , V_67 , V_49 ) ;
}
static T_4 F_42 ( struct V_73 * V_74 , struct V_43 * V_44 ,
struct V_75 * V_46 ,
char * V_65 , T_6 V_76 , T_5 V_66 )
{
T_5 V_106 = V_66 ;
T_5 V_107 ;
if ( V_76 )
return - V_102 ;
memcpy ( V_105 -> V_39 . V_40 . V_67 , V_65 , V_66 ) ;
if ( V_106 % 8 ) {
V_107 = 8 - ( V_106 % 8 ) ;
memset ( V_105 -> V_39 . V_40 . V_67 + V_106 ,
0 , V_107 ) ;
V_106 += V_107 ;
}
V_105 -> V_39 . V_40 . V_68 = V_106 ;
V_105 -> V_34 . V_52 = V_108 + V_106 ;
V_105 -> V_34 . V_109 = V_110 + V_106 ;
return V_66 ;
}
static void F_43 ( char * V_78 ,
struct V_27 * V_111 )
{
memcpy ( V_78 , V_111 -> V_34 . V_78 , V_79 ) ;
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
int V_51 , V_112 ;
V_112 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_112 -- ;
if ( ( V_112 > V_79 ) || ( ( V_112 > 0 ) && ( V_65 [ 0 ] == ' ' ) ) )
return - V_102 ;
for ( V_51 = 0 ; V_51 < V_112 ; V_51 ++ ) {
if ( isalpha ( V_65 [ V_51 ] ) || isdigit ( V_65 [ V_51 ] ) || ( V_65 [ V_51 ] == ' ' ) ||
( V_65 [ V_51 ] == '.' ) )
continue;
return - V_102 ;
}
memset ( V_50 -> V_34 . V_78 , ' ' , V_79 ) ;
memcpy ( V_50 -> V_34 . V_78 , V_65 , V_112 ) ;
F_36 ( V_50 -> V_34 . V_78 , V_79 ) ;
return V_52 ;
}
static T_4 F_46 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_105 , V_47 ) ;
}
static T_4 F_47 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_105 , V_65 , V_52 ) ;
}
static T_4 F_48 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_103 , V_47 ) ;
}
static T_4 F_49 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_103 , V_65 , V_52 ) ;
}
static T_4 F_50 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return F_44 ( V_104 , V_47 ) ;
}
static T_4 F_51 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_45 ( V_104 , V_65 , V_52 ) ;
}
static void F_52 ( char * V_113 ,
struct V_27 * V_50 )
{
memcpy ( V_113 , V_50 -> V_39 . V_54 . V_114 , V_115 ) ;
F_12 ( V_113 , V_115 ) ;
V_113 [ V_115 ] = 0 ;
}
static T_4 F_53 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
char V_114 [ V_115 + 1 ] = {} ;
F_52 ( V_114 , V_103 ) ;
return sprintf ( V_47 , L_3 , V_114 ) ;
}
static T_4 F_54 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
int V_116 ;
V_116 = V_52 ;
if ( ( V_52 > 0 ) && ( V_65 [ V_52 - 1 ] == '\n' ) )
V_116 -- ;
if ( V_116 > V_115 )
return - V_102 ;
memset ( V_103 -> V_39 . V_54 . V_114 , 0x40 , V_115 ) ;
if ( V_116 > 0 ) {
V_103 -> V_39 . V_54 . V_55 |=
V_117 ;
memcpy ( V_103 -> V_39 . V_54 . V_114 , V_65 , V_116 ) ;
F_36 ( V_103 -> V_39 . V_54 . V_114 , V_116 ) ;
F_55 ( V_103 -> V_39 . V_54 . V_114 , V_116 ) ;
} else {
V_103 -> V_39 . V_54 . V_55 &=
~ V_117 ;
}
return V_52 ;
}
static void F_56 ( struct V_27 * V_118 )
{
V_119 = V_118 ;
F_57 ( V_120 , V_119 ,
V_118 -> V_34 . V_52 ) ;
}
static int F_58 ( enum V_1 type )
{
if ( ! ( V_121 & type ) )
return - V_102 ;
switch( type ) {
case V_2 :
if ( V_60 )
V_122 = V_123 ;
else if ( V_86 )
V_122 = V_124 ;
else
V_122 = V_125 ;
F_56 ( V_104 ) ;
break;
case V_4 :
if ( V_60 )
V_122 = V_126 ;
else if ( V_86 )
V_122 = V_127 ;
else
V_122 = V_128 ;
F_56 ( V_105 ) ;
break;
case V_6 :
V_122 = V_129 ;
break;
case V_8 :
if ( V_60 )
V_122 = V_130 ;
else
V_122 = V_131 ;
F_56 ( V_103 ) ;
break;
case V_10 :
V_122 = V_132 ;
break;
default:
F_59 () ;
}
V_133 = type ;
return 0 ;
}
static T_4 F_60 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , F_1 ( V_133 ) ) ;
}
static T_4 F_61 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
int V_59 = - V_102 ;
if ( strncmp ( V_65 , V_3 , strlen ( V_3 ) ) == 0 )
V_59 = F_58 ( V_2 ) ;
else if ( strncmp ( V_65 , V_5 , strlen ( V_5 ) ) == 0 )
V_59 = F_58 ( V_4 ) ;
else if ( strncmp ( V_65 , V_9 , strlen ( V_9 ) ) == 0 )
V_59 = F_58 ( V_8 ) ;
return ( V_59 != 0 ) ? V_59 : V_52 ;
}
static void F_62 ( char * V_113 , struct V_27 * V_50 ,
const enum V_134 V_135 )
{
char V_78 [ V_79 + 1 ] = {} ;
char V_99 [ V_64 + 1 ] = {} ;
char V_114 [ V_115 + 1 ] = {} ;
T_5 V_136 = 0 ;
F_43 ( V_78 , V_50 ) ;
F_52 ( V_114 , V_50 ) ;
F_9 ( V_99 , sizeof( V_99 ) , V_50 ) ;
switch ( V_135 ) {
case V_124 :
V_136 = sprintf ( V_113 , L_10 , V_50 -> V_39 . V_54 . V_72 ) ;
break;
case V_131 :
V_136 = sprintf ( V_113 , L_11 , V_114 ) ;
break;
default:
break;
}
if ( strlen ( V_78 ) > 0 )
V_136 += sprintf ( V_113 + V_136 , L_12 , V_78 ) ;
if ( strlen ( V_99 ) > 0 )
sprintf ( V_113 + V_136 , L_13 , V_99 ) ;
}
static void F_63 ( void * V_82 )
{
struct V_137 V_138 ;
static char V_65 [ 128 ] ;
switch ( V_122 ) {
case V_125 :
V_138 . V_139 = V_104 -> V_39 . V_54 . V_139 ;
V_138 . V_72 = V_104 -> V_39 . V_54 . V_72 ;
F_27 ( & V_138 ) ;
break;
case V_124 :
F_62 ( V_65 , V_104 , V_124 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
break;
case V_123 :
F_4 ( V_140 , V_104 ) ;
if ( V_83 )
F_4 ( V_84 , NULL ) ;
else
F_4 ( V_85 , NULL ) ;
break;
case V_126 :
F_4 ( V_140 , V_105 ) ;
F_4 ( V_85 , NULL ) ;
break;
case V_128 :
F_4 ( V_85 , NULL ) ;
break;
case V_127 :
F_26 ( L_7 , NULL , 0 , NULL ) ;
break;
case V_130 :
F_4 ( V_140 , V_103 ) ;
F_4 ( V_85 , NULL ) ;
break;
case V_131 :
F_62 ( V_65 , V_103 , V_131 ) ;
F_26 ( V_65 , NULL , 0 , NULL ) ;
break;
case V_132 :
if ( V_86 )
F_26 ( L_7 , NULL , 0 , NULL ) ;
F_4 ( V_85 , NULL ) ;
break;
case V_129 :
break;
}
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
}
static void F_66 ( struct V_89 * V_90 )
{
F_29 ( F_63 , NULL ) ;
}
static void F_67 ( struct V_27 * V_50 )
{
V_50 -> V_34 . V_52 = V_141 ;
V_50 -> V_34 . V_35 = V_142 ;
V_50 -> V_34 . V_109 = V_143 ;
V_50 -> V_34 . V_37 = V_62 ;
}
static void F_68 ( struct V_27 * V_50 )
{
if ( V_80 . V_81 )
memcpy ( V_50 -> V_34 . V_78 , & V_80 . V_78 , V_79 ) ;
else
memset ( V_50 -> V_34 . V_78 , 0x40 , V_79 ) ;
V_50 -> V_34 . V_144 = V_145 ;
if ( V_86 && V_60 &&
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
if ( ! V_86 )
return 0 ;
V_103 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_103 )
return - V_93 ;
if ( ! V_60 )
V_147 . V_46 . V_25 = V_26 ;
V_59 = F_32 ( & V_148 -> V_44 , & V_149 ) ;
if ( V_59 )
return V_59 ;
F_67 ( V_103 ) ;
if ( V_39 . type == V_8 ) {
memset ( V_103 -> V_39 . V_54 . V_114 ,
' ' , V_115 ) ;
memcpy ( V_103 -> V_39 . V_54 . V_114 ,
V_150 , strlen ( V_150 ) ) ;
F_36 ( V_103 -> V_39 . V_54 . V_114 , V_115 ) ;
V_103 -> V_39 . V_54 . V_55 |=
V_117 ;
F_68 ( V_103 ) ;
}
V_121 |= V_8 ;
return 0 ;
}
static int T_3 F_71 ( void )
{
int V_59 ;
V_104 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_104 )
return - V_93 ;
if ( V_86 ) {
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
F_67 ( V_104 ) ;
if ( V_39 . type == V_2 ) {
V_104 -> V_39 . V_54 . V_139 = V_70 ;
V_104 -> V_39 . V_54 . V_72 = V_71 ;
F_68 ( V_104 ) ;
}
V_121 |= V_2 ;
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
V_105 = ( void * ) F_70 ( V_146 ) ;
if ( ! V_105 )
return - V_93 ;
V_157 = F_31 ( V_5 , NULL ,
& V_148 -> V_44 ) ;
if ( ! V_157 ) {
F_73 ( ( unsigned long ) V_105 ) ;
return - V_93 ;
}
V_59 = F_32 ( & V_157 -> V_44 , & V_158 ) ;
if ( V_59 ) {
F_74 ( V_157 ) ;
F_73 ( ( unsigned long ) V_105 ) ;
return V_59 ;
}
if ( V_39 . type == V_4 ) {
memcpy ( V_105 , V_29 , V_159 ) ;
memcpy ( V_105 -> V_34 . V_78 , V_80 . V_78 ,
V_79 ) ;
} else {
V_105 -> V_34 . V_52 = V_108 ;
V_105 -> V_34 . V_35 = V_142 ;
V_105 -> V_34 . V_109 = V_110 ;
V_105 -> V_34 . V_37 = V_38 ;
V_105 -> V_39 . V_40 . V_41 = V_160 ;
}
V_121 |= V_4 ;
return 0 ;
}
static int T_3 F_75 ( void )
{
enum V_1 V_133 = V_39 . type ;
struct V_27 * V_118 ;
unsigned long V_49 ;
V_118 = F_76 ( V_120 , & V_49 ) ;
if ( ! V_118 )
goto V_69;
if ( V_118 -> V_34 . V_37 == V_38 ) {
memcpy ( V_105 , V_118 , V_49 ) ;
V_133 = V_4 ;
} else if ( V_118 -> V_34 . V_37 == V_62 ) {
memcpy ( V_104 , V_118 , V_49 ) ;
V_133 = V_2 ;
}
V_69:
return F_58 ( V_133 ) ;
}
static int T_3 F_77 ( void )
{
int V_59 ;
V_148 = F_31 ( L_14 , NULL , V_92 ) ;
if ( ! V_148 )
return - V_93 ;
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
return - V_102 ;
switch ( type ) {
case V_15 :
if ( V_60 )
V_163 = V_164 ;
else if ( V_86 )
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
int V_59 = - V_102 ;
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
F_4 ( V_140 , V_169 ) ;
while ( 1 ) {
if ( F_4 ( V_84 , NULL ) != 0x302 )
break;
F_83 ( V_170 ) ;
}
}
static void F_84 ( void * V_82 )
{
struct V_137 V_138 ;
static char V_65 [ 100 ] ;
switch ( V_163 ) {
case V_166 :
V_138 . V_139 = V_171 -> V_39 . V_54 . V_139 ;
V_138 . V_72 = V_171 -> V_39 . V_54 . V_72 ;
F_27 ( & V_138 ) ;
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
static void F_85 ( struct V_89 * V_90 )
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
return - V_93 ;
V_59 = F_32 ( & V_173 -> V_44 , & V_174 ) ;
if ( V_59 ) {
F_73 ( ( unsigned long ) V_171 ) ;
return V_59 ;
}
V_171 -> V_34 . V_52 = V_141 ;
V_171 -> V_34 . V_35 = V_142 ;
V_171 -> V_34 . V_109 = V_143 ;
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
return - V_93 ;
V_59 = F_32 ( & V_173 -> V_44 , & V_176 ) ;
if ( V_59 ) {
F_73 ( ( unsigned long ) V_172 ) ;
return V_59 ;
}
V_172 -> V_34 . V_52 = V_108 ;
V_172 -> V_34 . V_35 = V_142 ;
V_172 -> V_34 . V_109 = V_110 ;
V_172 -> V_34 . V_37 = V_38 ;
V_172 -> V_39 . V_40 . V_41 = V_42 ;
V_162 |= V_17 ;
return 0 ;
}
static int T_3 F_89 ( void )
{
int V_59 ;
V_173 = F_31 ( L_17 , NULL , V_92 ) ;
if ( ! V_173 )
return - V_93 ;
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
static void F_90 ( struct V_89 * V_90 )
{
unsigned long V_178 = ( unsigned long ) V_119 ;
unsigned int V_179 ;
V_179 = ( V_180 unsigned int )
F_91 ( V_119 , V_119 -> V_34 . V_52 , 0 ) ;
F_92 ( V_181 . V_178 , V_178 ) ;
F_92 ( V_181 . V_182 , V_179 ) ;
F_85 ( V_90 ) ;
}
static int T_3 F_93 ( void )
{
if ( ! V_60 )
return - V_183 ;
else
return 0 ;
}
static void F_94 ( struct V_89 * V_90 )
{
char * V_184 ;
if ( strcmp ( V_90 -> V_185 , V_186 ) == 0 )
V_184 = V_187 ;
else if ( strcmp ( V_90 -> V_185 , V_188 ) == 0 )
V_184 = V_189 ;
else if ( strcmp ( V_90 -> V_185 , V_190 ) == 0 )
V_184 = V_191 ;
else if ( strcmp ( V_90 -> V_185 , V_192 ) == 0 )
V_184 = V_193 ;
else if ( strcmp ( V_90 -> V_185 , V_194 ) == 0 )
V_184 = V_195 ;
else
return;
if ( strlen ( V_184 ) == 0 )
return;
F_26 ( V_184 , NULL , 0 , NULL ) ;
}
static int F_95 ( void )
{
if ( ! V_86 )
return - V_183 ;
V_196 = F_31 ( L_18 , NULL , V_92 ) ;
if ( ! V_196 )
return - V_93 ;
return F_32 ( & V_196 -> V_44 , & V_197 ) ;
}
static void F_96 ( struct V_89 * V_90 )
{
if ( strcmp ( V_90 -> V_185 , V_188 ) == 0 ||
strcmp ( V_90 -> V_185 , V_194 ) == 0 )
F_64 ( ( unsigned long ) F_65 ( 0 ) ) ;
F_97 () ;
}
static int F_98 ( const char * V_65 , struct V_89 * V_90 ,
T_5 V_52 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_198 ; V_51 ++ ) {
if ( F_99 ( V_65 , V_199 [ V_51 ] -> V_185 ) ) {
if ( V_199 [ V_51 ] -> V_200 ) {
return V_199 [ V_51 ] -> V_200 ;
} else {
V_90 -> V_201 = V_199 [ V_51 ] ;
return V_52 ;
}
}
}
return - V_102 ;
}
static T_4 F_100 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_202 . V_201 -> V_185 ) ;
}
static T_4 F_101 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_202 , V_52 ) ;
}
static void F_102 ( char * V_203 )
{
F_86 () ;
V_202 . V_201 -> V_204 ( & V_202 ) ;
F_66 ( NULL ) ;
}
static T_4 F_103 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_205 . V_201 -> V_185 ) ;
}
static T_4 F_104 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_205 , V_52 ) ;
}
static void F_105 ( void )
{
F_106 () ;
V_205 . V_201 -> V_204 ( & V_205 ) ;
F_96 ( & V_205 ) ;
}
static T_4 F_107 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_206 . V_201 -> V_185 ) ;
}
static T_4 F_108 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_206 , V_52 ) ;
}
static void F_109 ( void * V_207 )
{
F_110 ( 0x04 ) ;
F_86 () ;
#ifdef F_111
F_112 ( NULL ) ;
#endif
V_206 . V_201 -> V_204 ( & V_206 ) ;
F_96 ( & V_206 ) ;
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
return sprintf ( V_47 , L_3 , V_208 . V_201 -> V_185 ) ;
}
static T_4 F_118 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_208 , V_52 ) ;
}
static void F_119 ( void )
{
F_86 () ;
V_208 . V_201 -> V_204 ( & V_208 ) ;
F_96 ( & V_208 ) ;
}
static T_4 F_120 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
return sprintf ( V_47 , L_3 , V_209 . V_201 -> V_185 ) ;
}
static T_4 F_121 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_65 , T_5 V_52 )
{
return F_98 ( V_65 , & V_209 , V_52 ) ;
}
static void F_122 ( void )
{
F_86 () ;
V_209 . V_201 -> V_204 ( & V_209 ) ;
F_96 ( & V_209 ) ;
}
static void T_3 F_123 ( void )
{
V_210 = F_31 ( L_19 , NULL ,
V_92 ) ;
if ( ! V_210 )
goto V_211;
if ( F_32 ( & V_210 -> V_44 ,
& V_212 ) )
goto V_211;
return;
V_211:
F_33 ( L_20 ) ;
}
static void T_3 F_124 ( void )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_198 ; V_51 ++ ) {
if ( ! V_199 [ V_51 ] -> V_213 )
continue;
V_199 [ V_51 ] -> V_200 =
V_199 [ V_51 ] -> V_213 () ;
}
}
static int T_3 F_125 ( void )
{
char V_214 [ 8 ] = { 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 , 0x40 } ;
F_126 ( & V_80 ) ;
if ( memcmp ( V_80 . V_78 , V_214 , sizeof( V_214 ) ) == 0 &&
V_60 )
memcpy ( V_80 . V_78 , V_61 . V_34 . V_78 ,
V_79 ) ;
F_124 () ;
F_123 () ;
return 0 ;
}
static void T_3 F_127 ( char * V_113 , char * V_215 , int V_216 )
{
int V_217 , V_218 ;
V_218 = 0 ;
for ( V_217 = 0 ; V_215 [ V_217 ] != 0 ; V_217 ++ ) {
if ( V_215 [ V_217 ] == '"' )
continue;
V_113 [ V_218 ++ ] = V_215 [ V_217 ] ;
if ( V_218 >= V_216 )
break;
}
}
static int T_3 F_128 ( char * V_214 )
{
if ( ! V_86 )
return 1 ;
F_127 ( V_187 , V_214 , 127 ) ;
V_187 [ 127 ] = 0 ;
V_202 . V_201 = & V_219 ;
return 1 ;
}
static int T_3 F_129 ( char * V_214 )
{
if ( ! V_86 )
return 1 ;
F_127 ( V_189 , V_214 , 127 ) ;
V_189 [ 127 ] = 0 ;
V_205 . V_201 = & V_219 ;
return 1 ;
}
static int T_3 F_130 ( char * V_214 )
{
if ( ! V_86 )
return 1 ;
F_127 ( V_191 , V_214 , 127 ) ;
V_191 [ 127 ] = 0 ;
V_208 . V_201 = & V_219 ;
return 1 ;
}
static int T_3 F_131 ( char * V_214 )
{
if ( ! V_86 )
return 1 ;
F_127 ( V_193 , V_214 , 127 ) ;
V_193 [ 127 ] = 0 ;
V_209 . V_201 = & V_219 ;
return 1 ;
}
static int F_132 ( struct V_220 * V_221 ,
unsigned long V_222 , void * V_87 )
{
F_105 () ;
return V_223 ;
}
void T_3 F_133 ( void )
{
V_39 . type = F_7 () ;
switch ( V_39 . type ) {
case V_2 :
V_39 . V_87 . V_54 . V_88 . V_139 = V_70 ;
V_39 . V_87 . V_54 . V_88 . V_72 = V_71 ;
break;
case V_4 :
case V_6 :
V_39 . V_87 . V_40 . V_88 . V_139 = 0 ;
V_39 . V_87 . V_40 . V_88 . V_72 =
V_29 -> V_39 . V_40 . V_72 ;
V_39 . V_87 . V_40 . V_224 = V_29 -> V_39 . V_40 . V_224 ;
V_39 . V_87 . V_40 . V_225 = V_29 -> V_39 . V_40 . V_225 ;
break;
case V_8 :
strncpy ( V_39 . V_87 . V_226 . V_185 , V_150 ,
sizeof( V_39 . V_87 . V_226 . V_185 ) ) ;
break;
case V_10 :
break;
}
F_134 ( & V_227 , & V_228 ) ;
}
void T_3 F_135 ( void )
{
int V_59 ;
V_59 = F_4 ( V_229 , & V_61 ) ;
if ( ( V_59 == V_230 ) || ( V_59 == V_231 ) )
V_60 = 1 ;
}
void T_3 F_136 ( void )
{
struct V_232 V_233 ;
if ( F_137 ( & V_233 ) )
return;
V_70 = V_233 . V_139 ;
V_71 = V_233 . V_72 ;
V_30 |= V_32 ;
if ( ! V_233 . V_234 )
return;
V_30 |= V_33 ;
}
void F_138 ( struct V_235 * V_236 )
{
F_139 ( & V_237 ) ;
F_140 ( & V_236 -> V_238 , & V_239 ) ;
F_141 ( & V_237 ) ;
}
void F_142 ( struct V_235 * V_236 )
{
F_139 ( & V_237 ) ;
F_143 ( & V_236 -> V_238 ) ;
F_141 ( & V_237 ) ;
}
static void F_144 ( void )
{
struct V_235 * V_236 ;
if ( V_60 ) {
F_145 () ;
return;
}
F_146 (reset, &rcall, list)
V_236 -> V_204 () ;
}
void F_147 ( void )
{
struct V_240 * V_241 ;
V_241 = (struct V_240 * ) ( unsigned long ) F_148 () ;
V_241 -> V_242 = V_181 . V_242 ;
F_149 ( 0 ) ;
F_150 ( 0 , 28 ) ;
V_181 . V_243 . V_244 = V_245 | V_246 ;
V_181 . V_243 . V_20 =
( unsigned long ) V_247 ;
V_181 . V_248 . V_244 = V_245 | V_246 ;
V_181 . V_248 . V_20 =
( unsigned long ) V_249 ;
F_144 () ;
}
