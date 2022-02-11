static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
return V_2 ;
}
static void T_3 F_3 ( struct V_3 * V_4 ,
unsigned int V_5 , char * V_6 )
{
if ( ! V_4 -> V_7 || ! V_5 )
return;
if ( V_4 -> V_8 == V_9 )
F_4 ( V_4 -> V_7 , V_5 , V_6 ) ;
else if ( V_4 -> V_8 == V_10 )
F_5 ( V_4 -> V_7 , V_5 , V_6 ) ;
}
static int T_3 F_6 ( void )
{
F_3 ( & V_11 . V_12 , V_11 . V_13 ,
L_8 ) ;
F_3 ( & V_11 . V_14 , V_11 . V_13 ,
L_9 ) ;
F_3 ( & V_11 . V_15 , V_11 . V_16 ,
L_10 ) ;
F_3 ( & V_11 . V_17 , V_11 . V_16 ,
L_11 ) ;
if ( V_11 . V_18 == 4 )
F_3 ( & V_11 . V_19 , 4 , L_12 ) ;
F_3 ( & V_11 . V_20 , V_11 . V_21 ,
L_13 ) ;
if ( ! ( V_11 . V_22 & 0x1 ) )
F_3 ( & V_11 . V_23 ,
V_11 . V_22 , L_14 ) ;
if ( ! ( V_11 . V_24 & 0x1 ) )
F_3 ( & V_11 . V_25 ,
V_11 . V_24 , L_15 ) ;
return 0 ;
}
void F_7 ( const char * V_26 , ... )
{
T_4 args ;
va_start ( args , V_26 ) ;
F_8 ( V_26 , args ) ;
va_end ( args ) ;
}
void F_8 ( const char * V_26 , T_4 args )
{
static char V_27 [ 512 ] ;
vsprintf ( V_27 , V_26 , args ) ;
#ifdef F_9
if ( V_28 ) {
F_10 ( L_16 , V_27 ) ;
} else {
F_2 ( V_29 L_16 , V_27 ) ;
}
#else
F_2 ( V_29 L_16 , V_27 ) ;
#endif
}
T_5 T_3 F_11 ( void )
{
if ( V_30 ) {
if ( V_31 . V_32 != V_33 )
return V_31 . V_32 ;
else if ( V_31 . V_34 != V_33 )
return V_31 . V_34 ;
else {
F_2 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_5 V_35 = 0 ;
F_12 ( & V_35 ) ;
return V_35 ;
}
}
static struct V_36 *
F_13 ( T_5 V_37 , T_6 V_38 )
{
struct V_36 * V_39 ;
F_14 (map, &acpi_ioremaps, list)
if ( V_39 -> V_37 <= V_37 &&
V_37 + V_38 <= V_39 -> V_37 + V_39 -> V_38 )
return V_39 ;
return NULL ;
}
static void T_7 *
F_15 ( T_5 V_37 , unsigned int V_38 )
{
struct V_36 * V_39 ;
V_39 = F_13 ( V_37 , V_38 ) ;
if ( V_39 )
return V_39 -> V_40 + ( V_37 - V_39 -> V_37 ) ;
return NULL ;
}
void T_7 * F_16 ( T_5 V_37 , unsigned int V_38 )
{
struct V_36 * V_39 ;
void T_7 * V_40 = NULL ;
F_17 ( & V_41 ) ;
V_39 = F_13 ( V_37 , V_38 ) ;
if ( V_39 ) {
V_40 = V_39 -> V_40 + ( V_37 - V_39 -> V_37 ) ;
V_39 -> V_42 ++ ;
}
F_18 ( & V_41 ) ;
return V_40 ;
}
static struct V_36 *
F_19 ( void T_7 * V_40 , T_6 V_38 )
{
struct V_36 * V_39 ;
F_14 (map, &acpi_ioremaps, list)
if ( V_39 -> V_40 <= V_40 &&
V_40 + V_38 <= V_39 -> V_40 + V_39 -> V_38 )
return V_39 ;
return NULL ;
}
void T_7 * T_8
F_20 ( T_5 V_37 , T_6 V_38 )
{
struct V_36 * V_39 ;
void T_7 * V_40 ;
T_5 V_43 ;
T_6 V_44 ;
if ( V_37 > V_45 ) {
F_2 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_46 )
return F_21 ( ( unsigned long ) V_37 , V_38 ) ;
F_17 ( & V_41 ) ;
V_39 = F_13 ( V_37 , V_38 ) ;
if ( V_39 ) {
V_39 -> V_42 ++ ;
goto V_47;
}
V_39 = F_22 ( sizeof( * V_39 ) , V_48 ) ;
if ( ! V_39 ) {
F_18 ( & V_41 ) ;
return NULL ;
}
V_43 = F_23 ( V_37 , V_49 ) ;
V_44 = F_24 ( V_37 + V_38 , V_49 ) - V_43 ;
V_40 = F_25 ( V_43 , V_44 ) ;
if ( ! V_40 ) {
F_18 ( & V_41 ) ;
F_26 ( V_39 ) ;
return NULL ;
}
F_27 ( & V_39 -> V_50 ) ;
V_39 -> V_40 = V_40 ;
V_39 -> V_37 = V_43 ;
V_39 -> V_38 = V_44 ;
V_39 -> V_42 = 1 ;
F_28 ( & V_39 -> V_50 , & V_51 ) ;
V_47:
F_18 ( & V_41 ) ;
return V_39 -> V_40 + ( V_37 - V_39 -> V_37 ) ;
}
static void F_29 ( struct V_36 * V_39 )
{
if ( ! -- V_39 -> V_42 )
F_30 ( & V_39 -> V_50 ) ;
}
static void F_31 ( struct V_36 * V_39 )
{
if ( ! V_39 -> V_42 ) {
F_32 () ;
F_33 ( V_39 -> V_40 ) ;
F_26 ( V_39 ) ;
}
}
void T_9 F_34 ( void T_7 * V_40 , T_6 V_38 )
{
struct V_36 * V_39 ;
if ( ! V_46 ) {
F_35 ( V_40 , V_38 ) ;
return;
}
F_17 ( & V_41 ) ;
V_39 = F_19 ( V_40 , V_38 ) ;
if ( ! V_39 ) {
F_18 ( & V_41 ) ;
F_36 ( true , V_52 L_19 , V_53 , V_40 ) ;
return;
}
F_29 ( V_39 ) ;
F_18 ( & V_41 ) ;
F_31 ( V_39 ) ;
}
void T_3 F_37 ( void T_7 * V_40 , T_6 V_38 )
{
if ( ! V_46 )
F_35 ( V_40 , V_38 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
void T_7 * V_40 ;
if ( V_4 -> V_8 != V_10 )
return 0 ;
if ( ! V_4 -> V_7 || ! V_4 -> V_54 )
return - V_55 ;
V_40 = F_20 ( V_4 -> V_7 , V_4 -> V_54 / 8 ) ;
if ( ! V_40 )
return - V_56 ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_36 * V_39 ;
if ( V_4 -> V_8 != V_10 )
return;
if ( ! V_4 -> V_7 || ! V_4 -> V_54 )
return;
F_17 ( & V_41 ) ;
V_39 = F_13 ( V_4 -> V_7 , V_4 -> V_54 / 8 ) ;
if ( ! V_39 ) {
F_18 ( & V_41 ) ;
return;
}
F_29 ( V_39 ) ;
F_18 ( & V_41 ) ;
F_31 ( V_39 ) ;
}
T_10
F_40 ( void * V_40 , T_5 * V_37 )
{
if ( ! V_37 || ! V_40 )
return V_57 ;
* V_37 = F_41 ( V_40 ) ;
return V_58 ;
}
T_10
F_42 ( const struct V_59 * V_60 ,
T_2 * V_61 )
{
if ( ! V_60 || ! V_61 )
return V_57 ;
* V_61 = NULL ;
if ( ! memcmp ( V_60 -> V_62 , L_20 , 4 ) && strlen ( V_63 ) ) {
F_2 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_61 = V_63 ;
}
return V_58 ;
}
T_10
F_43 ( struct V_64 * V_65 ,
struct V_64 * * V_66 )
{
if ( ! V_65 || ! V_66 )
return V_57 ;
* V_66 = NULL ;
#ifdef F_44
if ( strncmp ( V_65 -> V_67 , L_22 , 4 ) == 0 )
* V_66 = (struct V_64 * ) V_68 ;
#endif
if ( * V_66 != NULL ) {
F_2 (KERN_WARNING PREFIX L_23
L_24 ,
existing_table->signature,
existing_table->oem_table_id) ;
F_45 ( V_69 ) ;
}
return V_58 ;
}
static T_11 F_46 ( int V_70 , void * V_71 )
{
T_1 V_72 ;
V_72 = (* F_47) ( V_73 ) ;
if ( V_72 ) {
V_74 ++ ;
return V_75 ;
} else {
V_76 ++ ;
return V_77 ;
}
}
T_10
F_48 ( T_1 V_78 , T_12 V_79 ,
void * V_80 )
{
unsigned int V_70 ;
F_49 () ;
if ( V_78 != V_11 . V_81 )
return V_57 ;
if ( F_47 )
return V_82 ;
if ( F_50 ( V_78 , & V_70 ) < 0 ) {
F_2 (KERN_ERR PREFIX L_25 ,
gsi) ;
return V_58 ;
}
F_47 = V_79 ;
V_73 = V_80 ;
if ( F_51 ( V_70 , F_46 , V_83 , L_26 , F_46 ) ) {
F_2 (KERN_ERR PREFIX L_27 , irq) ;
F_47 = NULL ;
return V_84 ;
}
return V_58 ;
}
T_10 F_52 ( T_1 V_70 , T_12 V_79 )
{
if ( V_70 != V_11 . V_81 )
return V_57 ;
F_53 ( V_70 , F_46 ) ;
F_47 = NULL ;
return V_58 ;
}
void F_54 ( T_13 V_85 )
{
F_55 ( F_56 ( V_85 ) ) ;
}
void F_57 ( T_1 V_86 )
{
while ( V_86 ) {
T_1 V_87 = 1000 ;
if ( V_87 > V_86 )
V_87 = V_86 ;
F_58 ( V_87 ) ;
F_59 () ;
V_86 -= V_87 ;
}
}
T_13 F_60 ( void )
{
static T_13 V_88 ;
#ifdef F_61
#endif
#ifdef F_62
#endif
if ( ! V_88 )
F_2 (KERN_ERR PREFIX L_28 ) ;
return ++ V_88 ;
}
T_10 F_63 ( T_14 V_89 , T_1 * V_90 , T_1 V_91 )
{
T_1 V_92 ;
if ( ! V_90 )
V_90 = & V_92 ;
* V_90 = 0 ;
if ( V_91 <= 8 ) {
* ( V_93 * ) V_90 = F_64 ( V_89 ) ;
} else if ( V_91 <= 16 ) {
* ( V_94 * ) V_90 = F_65 ( V_89 ) ;
} else if ( V_91 <= 32 ) {
* ( T_1 * ) V_90 = F_66 ( V_89 ) ;
} else {
F_67 () ;
}
return V_58 ;
}
T_10 F_68 ( T_14 V_89 , T_1 V_90 , T_1 V_91 )
{
if ( V_91 <= 8 ) {
F_69 ( V_90 , V_89 ) ;
} else if ( V_91 <= 16 ) {
F_70 ( V_90 , V_89 ) ;
} else if ( V_91 <= 32 ) {
F_71 ( V_90 , V_89 ) ;
} else {
F_67 () ;
}
return V_58 ;
}
T_10
F_72 ( T_5 V_95 , T_1 * V_90 , T_1 V_91 )
{
void T_7 * V_96 ;
unsigned int V_38 = V_91 / 8 ;
bool V_97 = false ;
T_1 V_92 ;
F_73 () ;
V_96 = F_15 ( V_95 , V_38 ) ;
if ( ! V_96 ) {
F_74 () ;
V_96 = F_25 ( V_95 , V_38 ) ;
if ( ! V_96 )
return V_98 ;
V_97 = true ;
}
if ( ! V_90 )
V_90 = & V_92 ;
switch ( V_91 ) {
case 8 :
* ( V_93 * ) V_90 = F_75 ( V_96 ) ;
break;
case 16 :
* ( V_94 * ) V_90 = F_76 ( V_96 ) ;
break;
case 32 :
* ( T_1 * ) V_90 = F_77 ( V_96 ) ;
break;
default:
F_67 () ;
}
if ( V_97 )
F_33 ( V_96 ) ;
else
F_74 () ;
return V_58 ;
}
T_10
F_78 ( T_5 V_95 , T_1 V_90 , T_1 V_91 )
{
void T_7 * V_96 ;
unsigned int V_38 = V_91 / 8 ;
bool V_97 = false ;
F_73 () ;
V_96 = F_15 ( V_95 , V_38 ) ;
if ( ! V_96 ) {
F_74 () ;
V_96 = F_25 ( V_95 , V_38 ) ;
if ( ! V_96 )
return V_98 ;
V_97 = true ;
}
switch ( V_91 ) {
case 8 :
F_79 ( V_90 , V_96 ) ;
break;
case 16 :
F_80 ( V_90 , V_96 ) ;
break;
case 32 :
F_81 ( V_90 , V_96 ) ;
break;
default:
F_67 () ;
}
if ( V_97 )
F_33 ( V_96 ) ;
else
F_74 () ;
return V_58 ;
}
T_10
F_82 ( struct V_99 * V_100 , T_1 V_101 ,
T_13 * V_90 , T_1 V_91 )
{
int V_102 , V_38 ;
T_1 V_103 ;
if ( ! V_90 )
return V_57 ;
switch ( V_91 ) {
case 8 :
V_38 = 1 ;
break;
case 16 :
V_38 = 2 ;
break;
case 32 :
V_38 = 4 ;
break;
default:
return V_104 ;
}
V_102 = F_83 ( V_100 -> V_105 , V_100 -> V_106 ,
F_84 ( V_100 -> V_107 , V_100 -> V_108 ) ,
V_101 , V_38 , & V_103 ) ;
* V_90 = V_103 ;
return ( V_102 ? V_104 : V_58 ) ;
}
T_10
F_85 ( struct V_99 * V_100 , T_1 V_101 ,
T_13 V_90 , T_1 V_91 )
{
int V_102 , V_38 ;
switch ( V_91 ) {
case 8 :
V_38 = 1 ;
break;
case 16 :
V_38 = 2 ;
break;
case 32 :
V_38 = 4 ;
break;
default:
return V_104 ;
}
V_102 = F_86 ( V_100 -> V_105 , V_100 -> V_106 ,
F_84 ( V_100 -> V_107 , V_100 -> V_108 ) ,
V_101 , V_38 , V_90 ) ;
return ( V_102 ? V_104 : V_58 ) ;
}
static void F_87 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_88 ( V_110 , struct V_111 , V_110 ) ;
if ( V_112 -> V_113 )
F_89 ( NULL ) ;
V_112 -> V_108 ( V_112 -> V_80 ) ;
F_26 ( V_112 ) ;
}
static T_10 F_90 ( T_15 type ,
T_16 V_108 , void * V_80 , int V_114 )
{
T_10 V_115 = V_58 ;
struct V_111 * V_112 ;
struct V_116 * V_117 ;
int V_118 ;
F_91 ( ( V_119 ,
L_29 ,
V_108 , V_80 ) ) ;
V_112 = F_92 ( sizeof( struct V_111 ) , V_120 ) ;
if ( ! V_112 )
return V_121 ;
V_112 -> V_108 = V_108 ;
V_112 -> V_80 = V_80 ;
V_117 = V_114 ? V_122 :
( type == V_123 ? V_124 : V_125 ) ;
V_112 -> V_113 = V_114 ? 1 : 0 ;
if ( V_117 == V_122 )
F_93 ( & V_112 -> V_110 , F_87 ) ;
else if ( V_117 == V_124 )
F_93 ( & V_112 -> V_110 , F_87 ) ;
else
F_93 ( & V_112 -> V_110 , F_87 ) ;
V_118 = F_94 ( 0 , V_117 , & V_112 -> V_110 ) ;
if ( ! V_118 ) {
F_2 (KERN_ERR PREFIX
L_30 ) ;
V_115 = V_104 ;
F_26 ( V_112 ) ;
}
return V_115 ;
}
T_10 F_95 ( T_15 type ,
T_16 V_108 , void * V_80 )
{
return F_90 ( type , V_108 , V_80 , 0 ) ;
}
T_10 F_96 ( T_16 V_108 ,
void * V_80 )
{
return F_90 ( 0 , V_108 , V_80 , 1 ) ;
}
void F_89 ( void * V_80 )
{
F_97 ( V_125 ) ;
F_97 ( V_124 ) ;
}
T_10
F_98 ( T_1 V_126 , T_1 V_127 , T_17 * V_128 )
{
struct V_129 * V_130 = NULL ;
V_130 = F_99 ( sizeof( struct V_129 ) ) ;
if ( ! V_130 )
return V_121 ;
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
F_100 ( V_130 , V_127 ) ;
* V_128 = ( T_17 * ) V_130 ;
F_91 ( ( V_131 , L_31 ,
* V_128 , V_127 ) ) ;
return V_58 ;
}
T_10 F_101 ( T_17 V_128 )
{
struct V_129 * V_130 = (struct V_129 * ) V_128 ;
if ( ! V_130 )
return V_57 ;
F_91 ( ( V_131 , L_32 , V_128 ) ) ;
F_102 ( ! F_103 ( & V_130 -> V_132 ) ) ;
F_26 ( V_130 ) ;
V_130 = NULL ;
return V_58 ;
}
T_10 F_104 ( T_17 V_128 , T_1 V_133 , V_94 V_134 )
{
T_10 V_115 = V_58 ;
struct V_129 * V_130 = (struct V_129 * ) V_128 ;
long V_135 ;
int V_118 = 0 ;
if ( ! V_130 || ( V_133 < 1 ) )
return V_57 ;
if ( V_133 > 1 )
return V_136 ;
F_91 ( ( V_131 , L_33 ,
V_128 , V_133 , V_134 ) ) ;
if ( V_134 == V_137 )
V_135 = V_138 ;
else
V_135 = F_56 ( V_134 ) ;
V_118 = F_105 ( V_130 , V_135 ) ;
if ( V_118 )
V_115 = V_139 ;
if ( F_106 ( V_115 ) ) {
F_91 ( ( V_131 ,
L_34 ,
V_128 , V_133 , V_134 ,
F_107 ( V_115 ) ) ) ;
} else {
F_91 ( ( V_131 ,
L_35 , V_128 ,
V_133 , V_134 ) ) ;
}
return V_115 ;
}
T_10 F_108 ( T_17 V_128 , T_1 V_133 )
{
struct V_129 * V_130 = (struct V_129 * ) V_128 ;
if ( ! V_130 || ( V_133 < 1 ) )
return V_57 ;
if ( V_133 > 1 )
return V_136 ;
F_91 ( ( V_131 , L_36 , V_128 ,
V_133 ) ) ;
F_109 ( V_130 ) ;
return V_58 ;
}
T_1 F_110 ( char * V_27 )
{
#ifdef F_9
if ( V_28 ) {
T_1 V_140 ;
F_111 ( V_27 , sizeof( V_141 ) ) ;
V_140 = strlen ( V_27 ) - 1 ;
V_27 [ V_140 ] = '\0' ;
}
#endif
return 0 ;
}
T_10 F_112 ( T_1 V_108 , void * V_142 )
{
switch ( V_108 ) {
case V_143 :
F_2 (KERN_ERR PREFIX L_37 ) ;
break;
case V_144 :
break;
default:
break;
}
return V_58 ;
}
static int T_3 F_113 ( char * V_145 )
{
char * V_146 = V_63 ;
int V_147 = V_148 - 1 ;
if ( ! V_145 || ! * V_145 )
return 0 ;
for (; V_147 -- && V_145 && * V_145 ; V_145 ++ ) {
if ( isalnum ( * V_145 ) || * V_145 == ' ' || * V_145 == ':' )
* V_146 ++ = * V_145 ;
else if ( * V_145 == '\'' || * V_145 == '"' )
continue;
else
break;
}
* V_146 = 0 ;
return 1 ;
}
void T_3 F_114 ( char * V_145 )
{
struct V_149 * V_150 ;
bool V_151 = true ;
int V_152 ;
if ( ! V_153 )
return;
if ( V_145 == NULL || * V_145 == '\0' ) {
F_2 (KERN_INFO PREFIX L_38 ) ;
V_153 = FALSE ;
return;
}
if ( * V_145 == '!' ) {
V_145 ++ ;
V_151 = false ;
}
for ( V_152 = 0 ; V_152 < V_154 ; V_152 ++ ) {
V_150 = & V_155 [ V_152 ] ;
if ( ! strcmp ( V_150 -> string , V_145 ) ) {
V_150 -> V_151 = V_151 ;
break;
} else if ( V_150 -> string [ 0 ] == '\0' ) {
V_150 -> V_151 = V_151 ;
strncpy ( V_150 -> string , V_145 , V_156 ) ;
break;
}
}
}
static void T_3 F_115 ( unsigned int V_151 )
{
if ( V_157 . V_151 != V_151 )
V_157 . V_151 = V_151 ;
if ( V_157 . V_151 )
F_114 ( L_1 ) ;
else
F_114 ( L_39 ) ;
return;
}
static void T_3 F_116 ( unsigned int V_151 )
{
V_157 . V_158 = 1 ;
V_157 . V_159 = 0 ;
F_115 ( V_151 ) ;
return;
}
void T_3 F_117 ( int V_151 , const struct V_160 * V_161 )
{
F_2 (KERN_NOTICE PREFIX L_40 , d->ident) ;
if ( V_151 == - 1 )
return;
V_157 . V_159 = 1 ;
F_115 ( V_151 ) ;
return;
}
static void T_3 F_118 ( void )
{
struct V_149 * V_150 ;
char * V_145 ;
int V_152 ;
T_10 V_115 ;
for ( V_152 = 0 ; V_152 < V_154 ; V_152 ++ ) {
V_150 = & V_155 [ V_152 ] ;
V_145 = V_150 -> string ;
if ( * V_145 == '\0' )
break;
if ( V_150 -> V_151 ) {
V_115 = F_119 ( V_145 ) ;
if ( F_120 ( V_115 ) )
F_2 (KERN_INFO PREFIX L_41 , str) ;
} else {
V_115 = F_121 ( V_145 ) ;
if ( F_120 ( V_115 ) )
F_2 (KERN_INFO PREFIX L_42 , str) ;
}
}
}
static int T_3 F_122 ( char * V_145 )
{
if ( V_145 && ! strcmp ( L_1 , V_145 ) )
F_116 ( 1 ) ;
else if ( V_145 && ! strcmp ( L_39 , V_145 ) )
F_116 ( 0 ) ;
else
F_114 ( V_145 ) ;
return 1 ;
}
static int T_3 F_123 ( char * V_145 )
{
F_2 (KERN_INFO PREFIX L_43 ) ;
V_162 = TRUE ;
return 1 ;
}
static int T_3 F_124 ( char * V_145 )
{
if ( V_145 == NULL || * V_145 == '\0' )
return 0 ;
if ( ! strcmp ( L_44 , V_145 ) )
V_163 = V_164 ;
else if ( ! strcmp ( L_45 , V_145 ) )
V_163 = V_165 ;
else if ( ! strcmp ( L_46 , V_145 ) )
V_163 = V_166 ;
return 1 ;
}
int F_125 ( const struct V_167 * V_168 )
{
struct V_169 * V_170 ;
int V_171 = 0 , V_172 = 0 ;
if ( V_163 == V_166 )
return 0 ;
if ( ! ( V_168 -> V_173 & V_174 ) && ! ( V_168 -> V_173 & V_175 ) )
return 0 ;
V_171 = V_168 -> V_173 & V_174 ;
F_126 ( & V_176 ) ;
F_127 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_171 && ( V_170 -> V_177
!= V_9 ) )
continue;
if ( ! V_171 && ( V_170 -> V_177
!= V_10 ) )
continue;
if ( V_168 -> V_178 < V_170 -> V_179
|| V_170 -> V_178 < V_168 -> V_179 )
continue;
V_172 = 1 ;
break;
}
F_128 ( & V_176 ) ;
if ( V_172 ) {
if ( V_163 != V_166 ) {
F_2 ( V_180 L_47
L_48
L_49 ,
V_168 -> V_62 , V_168 , V_170 -> V_62 ,
( V_170 -> V_177 ==
V_9 ) ? L_50 : L_51 ,
( V_181 ) V_170 -> V_179 ,
( V_181 ) V_170 -> V_178 ) ;
if ( V_163 == V_165 )
F_2 ( V_182 L_52
L_53
L_54 ) ;
F_2 ( V_183 L_55
L_56
L_57 ) ;
}
if ( V_163 == V_164 )
return - V_184 ;
}
return 0 ;
}
int F_129 ( T_18 V_179 , T_18 V_185 ,
const char * V_62 )
{
struct V_167 V_168 = {
. V_179 = V_179 ,
. V_178 = V_179 + V_185 - 1 ,
. V_62 = V_62 ,
. V_173 = V_174 ,
} ;
return F_125 ( & V_168 ) ;
}
int F_130 ( void )
{
return V_163 == V_164 ;
}
void F_131 ( T_19 V_128 )
{
F_132 ( V_128 ) ;
}
T_20 F_133 ( T_19 V_186 )
{
T_20 V_173 ;
F_134 ( V_186 , V_173 ) ;
return V_173 ;
}
void F_135 ( T_19 V_186 , T_20 V_173 )
{
F_136 ( V_186 , V_173 ) ;
}
T_10
F_137 ( char * V_62 , V_94 V_38 , V_94 V_187 , T_21 * * V_188 )
{
* V_188 = F_138 ( V_62 , V_38 , 0 , 0 , NULL ) ;
if ( * V_188 == NULL )
return V_104 ;
else
return V_58 ;
}
T_10 F_139 ( T_21 * V_188 )
{
F_140 ( V_188 ) ;
return ( V_58 ) ;
}
T_10 F_141 ( T_21 * V_188 )
{
F_142 ( V_188 ) ;
return ( V_58 ) ;
}
T_10 F_143 ( T_21 * V_188 , void * V_189 )
{
F_144 ( V_188 , V_189 ) ;
return ( V_58 ) ;
}
static inline int F_145 ( struct V_169 * V_168 )
{
struct V_169 * V_170 ;
F_127 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_168 -> V_177 == V_170 -> V_177 &&
V_168 -> V_179 == V_170 -> V_179 &&
V_168 -> V_178 == V_170 -> V_178 ) {
V_170 -> V_147 ++ ;
return 0 ;
}
}
V_168 -> V_147 = 1 ;
F_146 ( & V_168 -> V_190 , & V_191 ) ;
return 1 ;
}
static inline void F_147 ( struct V_169 * V_168 )
{
struct V_169 * V_170 ;
F_127 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_168 -> V_177 == V_170 -> V_177 &&
V_168 -> V_179 == V_170 -> V_179 &&
V_168 -> V_178 == V_170 -> V_178 ) {
if ( -- V_170 -> V_147 == 0 ) {
F_148 ( & V_170 -> V_190 ) ;
F_26 ( V_170 ) ;
}
return;
}
}
}
T_10
F_149 (
V_93 V_8 ,
T_5 V_7 ,
T_6 V_5 )
{
struct V_169 V_168 ;
switch ( V_8 ) {
case V_9 :
case V_10 :
V_168 . V_179 = V_7 ;
V_168 . V_178 = V_7 + V_5 - 1 ;
V_168 . V_177 = V_8 ;
F_126 ( & V_176 ) ;
F_147 ( & V_168 ) ;
F_128 ( & V_176 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
break;
}
return V_58 ;
}
T_10
F_150 (
V_93 V_8 ,
T_5 V_7 ,
T_6 V_5 ,
char * V_62 )
{
struct V_169 * V_168 ;
int V_199 ;
if ( V_163 == V_166 )
return V_58 ;
switch ( V_8 ) {
case V_9 :
case V_10 :
V_168 = F_22 ( sizeof( struct V_169 ) , V_48 ) ;
if ( ! V_168 )
return V_58 ;
F_151 ( V_168 -> V_62 , V_62 , 5 ) ;
V_168 -> V_179 = V_7 ;
V_168 -> V_178 = V_7 + V_5 - 1 ;
V_168 -> V_177 = V_8 ;
F_126 ( & V_176 ) ;
V_199 = F_145 ( V_168 ) ;
F_128 ( & V_176 ) ;
F_152 ( L_58
L_59 , V_199 ? L_60 : L_61 ,
( V_8 == V_9 )
? L_62 : L_63 ,
( unsigned long long ) V_168 -> V_179 ,
( unsigned long long ) V_168 -> V_178 ,
V_168 -> V_62 ) ;
if ( ! V_199 )
F_26 ( V_168 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
break;
}
return V_58 ;
}
T_10 T_3 F_153 ( void )
{
F_38 ( & V_11 . V_12 ) ;
F_38 ( & V_11 . V_14 ) ;
F_38 ( & V_11 . V_23 ) ;
F_38 ( & V_11 . V_25 ) ;
return V_58 ;
}
T_10 T_3 F_154 ( void )
{
V_125 = F_155 ( L_64 , 0 , 1 ) ;
V_124 = F_155 ( L_65 , 0 , 1 ) ;
V_122 = F_155 ( L_66 , 0 , 1 ) ;
F_102 ( ! V_125 ) ;
F_102 ( ! V_124 ) ;
F_102 ( ! V_122 ) ;
F_156 ( F_1 ) ;
F_118 () ;
return V_58 ;
}
T_10 F_157 ( void )
{
if ( F_47 ) {
F_52 ( V_11 . V_81 ,
F_47 ) ;
}
F_39 ( & V_11 . V_25 ) ;
F_39 ( & V_11 . V_23 ) ;
F_39 ( & V_11 . V_14 ) ;
F_39 ( & V_11 . V_12 ) ;
F_158 ( V_125 ) ;
F_158 ( V_124 ) ;
F_158 ( V_122 ) ;
return V_58 ;
}
