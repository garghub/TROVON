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
F_11 ( V_29 L_16 , V_27 ) ;
}
#else
F_11 ( V_29 L_16 , V_27 ) ;
#endif
}
static int T_3 F_12 ( char * V_30 )
{
V_31 = F_13 ( V_30 , NULL , 16 ) ;
return 0 ;
}
T_5 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_31 )
return V_31 ;
#endif
if ( V_32 ) {
if ( V_33 . V_34 != V_35 )
return V_33 . V_34 ;
else if ( V_33 . V_36 != V_35 )
return V_33 . V_36 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_5 V_37 = 0 ;
F_16 ( & V_37 ) ;
return V_37 ;
}
}
static struct V_38 *
F_17 ( T_5 V_39 , T_6 V_40 )
{
struct V_38 * V_41 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_41 -> V_39 <= V_39 &&
V_39 + V_40 <= V_41 -> V_39 + V_41 -> V_40 )
return V_41 ;
return NULL ;
}
static void T_7 *
F_19 ( T_5 V_39 , unsigned int V_40 )
{
struct V_38 * V_41 ;
V_41 = F_17 ( V_39 , V_40 ) ;
if ( V_41 )
return V_41 -> V_42 + ( V_39 - V_41 -> V_39 ) ;
return NULL ;
}
void T_7 * F_20 ( T_5 V_39 , unsigned int V_40 )
{
struct V_38 * V_41 ;
void T_7 * V_42 = NULL ;
F_21 ( & V_43 ) ;
V_41 = F_17 ( V_39 , V_40 ) ;
if ( V_41 ) {
V_42 = V_41 -> V_42 + ( V_39 - V_41 -> V_39 ) ;
V_41 -> V_44 ++ ;
}
F_22 ( & V_43 ) ;
return V_42 ;
}
static struct V_38 *
F_23 ( void T_7 * V_42 , T_6 V_40 )
{
struct V_38 * V_41 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_41 -> V_42 <= V_42 &&
V_42 + V_40 <= V_41 -> V_42 + V_41 -> V_40 )
return V_41 ;
return NULL ;
}
void T_7 * T_8
F_24 ( T_5 V_39 , T_6 V_40 )
{
struct V_38 * V_41 ;
void T_7 * V_42 ;
T_5 V_45 ;
T_6 V_46 ;
if ( V_39 > V_47 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_48 )
return F_25 ( ( unsigned long ) V_39 , V_40 ) ;
F_21 ( & V_43 ) ;
V_41 = F_17 ( V_39 , V_40 ) ;
if ( V_41 ) {
V_41 -> V_44 ++ ;
goto V_49;
}
V_41 = F_26 ( sizeof( * V_41 ) , V_50 ) ;
if ( ! V_41 ) {
F_22 ( & V_43 ) ;
return NULL ;
}
V_45 = F_27 ( V_39 , V_51 ) ;
V_46 = F_28 ( V_39 + V_40 , V_51 ) - V_45 ;
V_42 = F_29 ( V_45 , V_46 ) ;
if ( ! V_42 ) {
F_22 ( & V_43 ) ;
F_30 ( V_41 ) ;
return NULL ;
}
F_31 ( & V_41 -> V_52 ) ;
V_41 -> V_42 = V_42 ;
V_41 -> V_39 = V_45 ;
V_41 -> V_40 = V_46 ;
V_41 -> V_44 = 1 ;
F_32 ( & V_41 -> V_52 , & V_53 ) ;
V_49:
F_22 ( & V_43 ) ;
return V_41 -> V_42 + ( V_39 - V_41 -> V_39 ) ;
}
static void F_33 ( struct V_38 * V_41 )
{
if ( ! -- V_41 -> V_44 )
F_34 ( & V_41 -> V_52 ) ;
}
static void F_35 ( struct V_38 * V_41 )
{
if ( ! V_41 -> V_44 ) {
F_36 () ;
F_37 ( V_41 -> V_42 ) ;
F_30 ( V_41 ) ;
}
}
void T_9 F_38 ( void T_7 * V_42 , T_6 V_40 )
{
struct V_38 * V_41 ;
if ( ! V_48 ) {
F_39 ( V_42 , V_40 ) ;
return;
}
F_21 ( & V_43 ) ;
V_41 = F_23 ( V_42 , V_40 ) ;
if ( ! V_41 ) {
F_22 ( & V_43 ) ;
F_40 ( true , V_54 L_19 , V_55 , V_42 ) ;
return;
}
F_33 ( V_41 ) ;
F_22 ( & V_43 ) ;
F_35 ( V_41 ) ;
}
void T_3 F_41 ( void T_7 * V_42 , T_6 V_40 )
{
if ( ! V_48 )
F_39 ( V_42 , V_40 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
void T_7 * V_42 ;
if ( V_4 -> V_8 != V_10 )
return 0 ;
if ( ! V_4 -> V_7 || ! V_4 -> V_56 )
return - V_57 ;
V_42 = F_24 ( V_4 -> V_7 , V_4 -> V_56 / 8 ) ;
if ( ! V_42 )
return - V_58 ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_38 * V_41 ;
if ( V_4 -> V_8 != V_10 )
return;
if ( ! V_4 -> V_7 || ! V_4 -> V_56 )
return;
F_21 ( & V_43 ) ;
V_41 = F_17 ( V_4 -> V_7 , V_4 -> V_56 / 8 ) ;
if ( ! V_41 ) {
F_22 ( & V_43 ) ;
return;
}
F_33 ( V_41 ) ;
F_22 ( & V_43 ) ;
F_35 ( V_41 ) ;
}
T_10
F_44 ( void * V_42 , T_5 * V_39 )
{
if ( ! V_39 || ! V_42 )
return V_59 ;
* V_39 = F_45 ( V_42 ) ;
return V_60 ;
}
T_10
F_46 ( const struct V_61 * V_62 ,
T_2 * V_63 )
{
if ( ! V_62 || ! V_63 )
return V_59 ;
* V_63 = NULL ;
if ( ! memcmp ( V_62 -> V_64 , L_20 , 4 ) && strlen ( V_65 ) ) {
F_11 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_63 = V_65 ;
}
return V_60 ;
}
T_10
F_47 ( struct V_66 * V_67 ,
struct V_66 * * V_68 )
{
if ( ! V_67 || ! V_68 )
return V_59 ;
* V_68 = NULL ;
#ifdef F_48
if ( strncmp ( V_67 -> V_69 , L_22 , 4 ) == 0 )
* V_68 = (struct V_66 * ) V_70 ;
#endif
if ( * V_68 != NULL ) {
F_11 (KERN_WARNING PREFIX L_23
L_24 ,
existing_table->signature,
existing_table->oem_table_id) ;
F_49 ( V_71 ) ;
}
return V_60 ;
}
static T_11 F_50 ( int V_72 , void * V_73 )
{
T_1 V_74 ;
V_74 = (* F_51) ( V_75 ) ;
if ( V_74 ) {
V_76 ++ ;
return V_77 ;
} else {
V_78 ++ ;
return V_79 ;
}
}
T_10
F_52 ( T_1 V_80 , T_12 V_81 ,
void * V_82 )
{
unsigned int V_72 ;
F_53 () ;
if ( V_80 != V_11 . V_83 )
return V_59 ;
if ( F_51 )
return V_84 ;
if ( F_54 ( V_80 , & V_72 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_25 ,
gsi) ;
return V_60 ;
}
F_51 = V_81 ;
V_75 = V_82 ;
if ( F_55 ( V_72 , F_50 , V_85 , L_26 , F_50 ) ) {
F_11 (KERN_ERR PREFIX L_27 , irq) ;
F_51 = NULL ;
return V_86 ;
}
return V_60 ;
}
T_10 F_56 ( T_1 V_72 , T_12 V_81 )
{
if ( V_72 != V_11 . V_83 )
return V_59 ;
F_57 ( V_72 , F_50 ) ;
F_51 = NULL ;
return V_60 ;
}
void F_58 ( T_13 V_87 )
{
F_59 ( F_60 ( V_87 ) ) ;
}
void F_61 ( T_1 V_88 )
{
while ( V_88 ) {
T_1 V_89 = 1000 ;
if ( V_89 > V_88 )
V_89 = V_88 ;
F_62 ( V_89 ) ;
F_63 () ;
V_88 -= V_89 ;
}
}
T_13 F_64 ( void )
{
static T_13 V_90 ;
#ifdef F_65
#endif
#ifdef F_66
#endif
if ( ! V_90 )
F_11 (KERN_ERR PREFIX L_28 ) ;
return ++ V_90 ;
}
T_10 F_67 ( T_14 V_91 , T_1 * V_92 , T_1 V_93 )
{
T_1 V_94 ;
if ( ! V_92 )
V_92 = & V_94 ;
* V_92 = 0 ;
if ( V_93 <= 8 ) {
* ( V_95 * ) V_92 = F_68 ( V_91 ) ;
} else if ( V_93 <= 16 ) {
* ( V_96 * ) V_92 = F_69 ( V_91 ) ;
} else if ( V_93 <= 32 ) {
* ( T_1 * ) V_92 = F_70 ( V_91 ) ;
} else {
F_71 () ;
}
return V_60 ;
}
T_10 F_72 ( T_14 V_91 , T_1 V_92 , T_1 V_93 )
{
if ( V_93 <= 8 ) {
F_73 ( V_92 , V_91 ) ;
} else if ( V_93 <= 16 ) {
F_74 ( V_92 , V_91 ) ;
} else if ( V_93 <= 32 ) {
F_75 ( V_92 , V_91 ) ;
} else {
F_71 () ;
}
return V_60 ;
}
T_10
F_76 ( T_5 V_97 , T_1 * V_92 , T_1 V_93 )
{
void T_7 * V_98 ;
unsigned int V_40 = V_93 / 8 ;
bool V_99 = false ;
T_1 V_94 ;
F_77 () ;
V_98 = F_19 ( V_97 , V_40 ) ;
if ( ! V_98 ) {
F_78 () ;
V_98 = F_29 ( V_97 , V_40 ) ;
if ( ! V_98 )
return V_100 ;
V_99 = true ;
}
if ( ! V_92 )
V_92 = & V_94 ;
switch ( V_93 ) {
case 8 :
* ( V_95 * ) V_92 = F_79 ( V_98 ) ;
break;
case 16 :
* ( V_96 * ) V_92 = F_80 ( V_98 ) ;
break;
case 32 :
* ( T_1 * ) V_92 = F_81 ( V_98 ) ;
break;
default:
F_71 () ;
}
if ( V_99 )
F_37 ( V_98 ) ;
else
F_78 () ;
return V_60 ;
}
T_10
F_82 ( T_5 V_97 , T_1 V_92 , T_1 V_93 )
{
void T_7 * V_98 ;
unsigned int V_40 = V_93 / 8 ;
bool V_99 = false ;
F_77 () ;
V_98 = F_19 ( V_97 , V_40 ) ;
if ( ! V_98 ) {
F_78 () ;
V_98 = F_29 ( V_97 , V_40 ) ;
if ( ! V_98 )
return V_100 ;
V_99 = true ;
}
switch ( V_93 ) {
case 8 :
F_83 ( V_92 , V_98 ) ;
break;
case 16 :
F_84 ( V_92 , V_98 ) ;
break;
case 32 :
F_85 ( V_92 , V_98 ) ;
break;
default:
F_71 () ;
}
if ( V_99 )
F_37 ( V_98 ) ;
else
F_78 () ;
return V_60 ;
}
T_10
F_86 ( struct V_101 * V_102 , T_1 V_103 ,
T_13 * V_92 , T_1 V_93 )
{
int V_104 , V_40 ;
T_1 V_105 ;
if ( ! V_92 )
return V_59 ;
switch ( V_93 ) {
case 8 :
V_40 = 1 ;
break;
case 16 :
V_40 = 2 ;
break;
case 32 :
V_40 = 4 ;
break;
default:
return V_106 ;
}
V_104 = F_87 ( V_102 -> V_107 , V_102 -> V_108 ,
F_88 ( V_102 -> V_109 , V_102 -> V_110 ) ,
V_103 , V_40 , & V_105 ) ;
* V_92 = V_105 ;
return ( V_104 ? V_106 : V_60 ) ;
}
T_10
F_89 ( struct V_101 * V_102 , T_1 V_103 ,
T_13 V_92 , T_1 V_93 )
{
int V_104 , V_40 ;
switch ( V_93 ) {
case 8 :
V_40 = 1 ;
break;
case 16 :
V_40 = 2 ;
break;
case 32 :
V_40 = 4 ;
break;
default:
return V_106 ;
}
V_104 = F_90 ( V_102 -> V_107 , V_102 -> V_108 ,
F_88 ( V_102 -> V_109 , V_102 -> V_110 ) ,
V_103 , V_40 , V_92 ) ;
return ( V_104 ? V_106 : V_60 ) ;
}
static void F_91 ( struct V_111 * V_112 )
{
struct V_113 * V_114 = F_92 ( V_112 , struct V_113 , V_112 ) ;
if ( V_114 -> V_115 )
F_93 ( NULL ) ;
V_114 -> V_110 ( V_114 -> V_82 ) ;
F_30 ( V_114 ) ;
}
static T_10 F_94 ( T_15 type ,
T_16 V_110 , void * V_82 , int V_116 )
{
T_10 V_117 = V_60 ;
struct V_113 * V_114 ;
struct V_118 * V_119 ;
int V_120 ;
F_95 ( ( V_121 ,
L_29 ,
V_110 , V_82 ) ) ;
V_114 = F_96 ( sizeof( struct V_113 ) , V_122 ) ;
if ( ! V_114 )
return V_123 ;
V_114 -> V_110 = V_110 ;
V_114 -> V_82 = V_82 ;
V_119 = V_116 ? V_124 :
( type == V_125 ? V_126 : V_127 ) ;
V_114 -> V_115 = V_116 ? 1 : 0 ;
if ( V_119 == V_124 )
F_97 ( & V_114 -> V_112 , F_91 ) ;
else if ( V_119 == V_126 )
F_97 ( & V_114 -> V_112 , F_91 ) ;
else
F_97 ( & V_114 -> V_112 , F_91 ) ;
V_120 = F_98 ( 0 , V_119 , & V_114 -> V_112 ) ;
if ( ! V_120 ) {
F_11 (KERN_ERR PREFIX
L_30 ) ;
V_117 = V_106 ;
F_30 ( V_114 ) ;
}
return V_117 ;
}
T_10 F_99 ( T_15 type ,
T_16 V_110 , void * V_82 )
{
return F_94 ( type , V_110 , V_82 , 0 ) ;
}
T_10 F_100 ( T_16 V_110 ,
void * V_82 )
{
return F_94 ( 0 , V_110 , V_82 , 1 ) ;
}
void F_93 ( void * V_82 )
{
F_101 ( V_127 ) ;
F_101 ( V_126 ) ;
}
T_10
F_102 ( T_1 V_128 , T_1 V_129 , T_17 * V_130 )
{
struct V_131 * V_132 = NULL ;
V_132 = F_103 ( sizeof( struct V_131 ) ) ;
if ( ! V_132 )
return V_123 ;
memset ( V_132 , 0 , sizeof( struct V_131 ) ) ;
F_104 ( V_132 , V_129 ) ;
* V_130 = ( T_17 * ) V_132 ;
F_95 ( ( V_133 , L_31 ,
* V_130 , V_129 ) ) ;
return V_60 ;
}
T_10 F_105 ( T_17 V_130 )
{
struct V_131 * V_132 = (struct V_131 * ) V_130 ;
if ( ! V_132 )
return V_59 ;
F_95 ( ( V_133 , L_32 , V_130 ) ) ;
F_106 ( ! F_107 ( & V_132 -> V_134 ) ) ;
F_30 ( V_132 ) ;
V_132 = NULL ;
return V_60 ;
}
T_10 F_108 ( T_17 V_130 , T_1 V_135 , V_96 V_136 )
{
T_10 V_117 = V_60 ;
struct V_131 * V_132 = (struct V_131 * ) V_130 ;
long V_137 ;
int V_120 = 0 ;
if ( ! V_132 || ( V_135 < 1 ) )
return V_59 ;
if ( V_135 > 1 )
return V_138 ;
F_95 ( ( V_133 , L_33 ,
V_130 , V_135 , V_136 ) ) ;
if ( V_136 == V_139 )
V_137 = V_140 ;
else
V_137 = F_60 ( V_136 ) ;
V_120 = F_109 ( V_132 , V_137 ) ;
if ( V_120 )
V_117 = V_141 ;
if ( F_110 ( V_117 ) ) {
F_95 ( ( V_133 ,
L_34 ,
V_130 , V_135 , V_136 ,
F_111 ( V_117 ) ) ) ;
} else {
F_95 ( ( V_133 ,
L_35 , V_130 ,
V_135 , V_136 ) ) ;
}
return V_117 ;
}
T_10 F_112 ( T_17 V_130 , T_1 V_135 )
{
struct V_131 * V_132 = (struct V_131 * ) V_130 ;
if ( ! V_132 || ( V_135 < 1 ) )
return V_59 ;
if ( V_135 > 1 )
return V_138 ;
F_95 ( ( V_133 , L_36 , V_130 ,
V_135 ) ) ;
F_113 ( V_132 ) ;
return V_60 ;
}
T_1 F_114 ( char * V_27 )
{
#ifdef F_9
if ( V_28 ) {
T_1 V_142 ;
F_115 ( V_27 , sizeof( V_143 ) ) ;
V_142 = strlen ( V_27 ) - 1 ;
V_27 [ V_142 ] = '\0' ;
}
#endif
return 0 ;
}
T_10 F_116 ( T_1 V_110 , void * V_144 )
{
switch ( V_110 ) {
case V_145 :
F_11 (KERN_ERR PREFIX L_37 ) ;
break;
case V_146 :
break;
default:
break;
}
return V_60 ;
}
static int T_3 F_117 ( char * V_147 )
{
char * V_148 = V_65 ;
int V_149 = V_150 - 1 ;
if ( ! V_147 || ! * V_147 )
return 0 ;
for (; V_149 -- && V_147 && * V_147 ; V_147 ++ ) {
if ( isalnum ( * V_147 ) || * V_147 == ' ' || * V_147 == ':' )
* V_148 ++ = * V_147 ;
else if ( * V_147 == '\'' || * V_147 == '"' )
continue;
else
break;
}
* V_148 = 0 ;
return 1 ;
}
void T_3 F_118 ( char * V_147 )
{
struct V_151 * V_152 ;
bool V_153 = true ;
int V_154 ;
if ( ! V_155 )
return;
if ( V_147 == NULL || * V_147 == '\0' ) {
F_11 (KERN_INFO PREFIX L_38 ) ;
V_155 = FALSE ;
return;
}
if ( * V_147 == '!' ) {
V_147 ++ ;
V_153 = false ;
}
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ ) {
V_152 = & V_157 [ V_154 ] ;
if ( ! strcmp ( V_152 -> string , V_147 ) ) {
V_152 -> V_153 = V_153 ;
break;
} else if ( V_152 -> string [ 0 ] == '\0' ) {
V_152 -> V_153 = V_153 ;
strncpy ( V_152 -> string , V_147 , V_158 ) ;
break;
}
}
}
static void T_3 F_119 ( unsigned int V_153 )
{
if ( V_159 . V_153 != V_153 )
V_159 . V_153 = V_153 ;
if ( V_159 . V_153 )
F_118 ( L_1 ) ;
else
F_118 ( L_39 ) ;
return;
}
static void T_3 F_120 ( unsigned int V_153 )
{
V_159 . V_160 = 1 ;
V_159 . V_161 = 0 ;
F_119 ( V_153 ) ;
return;
}
void T_3 F_121 ( int V_153 , const struct V_162 * V_163 )
{
F_11 (KERN_NOTICE PREFIX L_40 , d->ident) ;
if ( V_153 == - 1 )
return;
V_159 . V_161 = 1 ;
F_119 ( V_153 ) ;
return;
}
static void T_3 F_122 ( void )
{
struct V_151 * V_152 ;
char * V_147 ;
int V_154 ;
T_10 V_117 ;
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ ) {
V_152 = & V_157 [ V_154 ] ;
V_147 = V_152 -> string ;
if ( * V_147 == '\0' )
break;
if ( V_152 -> V_153 ) {
V_117 = F_123 ( V_147 ) ;
if ( F_124 ( V_117 ) )
F_11 (KERN_INFO PREFIX L_41 , str) ;
} else {
V_117 = F_125 ( V_147 ) ;
if ( F_124 ( V_117 ) )
F_11 (KERN_INFO PREFIX L_42 , str) ;
}
}
}
static int T_3 F_126 ( char * V_147 )
{
if ( V_147 && ! strcmp ( L_1 , V_147 ) )
F_120 ( 1 ) ;
else if ( V_147 && ! strcmp ( L_39 , V_147 ) )
F_120 ( 0 ) ;
else
F_118 ( V_147 ) ;
return 1 ;
}
static int T_3 F_127 ( char * V_147 )
{
F_11 (KERN_INFO PREFIX L_43 ) ;
V_164 = TRUE ;
return 1 ;
}
static int T_3 F_128 ( char * V_147 )
{
if ( V_147 == NULL || * V_147 == '\0' )
return 0 ;
if ( ! strcmp ( L_44 , V_147 ) )
V_165 = V_166 ;
else if ( ! strcmp ( L_45 , V_147 ) )
V_165 = V_167 ;
else if ( ! strcmp ( L_46 , V_147 ) )
V_165 = V_168 ;
return 1 ;
}
int F_129 ( const struct V_169 * V_170 )
{
struct V_171 * V_172 ;
int V_173 = 0 , V_174 = 0 ;
if ( V_165 == V_168 )
return 0 ;
if ( ! ( V_170 -> V_175 & V_176 ) && ! ( V_170 -> V_175 & V_177 ) )
return 0 ;
V_173 = V_170 -> V_175 & V_176 ;
F_130 ( & V_178 ) ;
F_131 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_173 && ( V_172 -> V_179
!= V_9 ) )
continue;
if ( ! V_173 && ( V_172 -> V_179
!= V_10 ) )
continue;
if ( V_170 -> V_180 < V_172 -> V_181
|| V_172 -> V_180 < V_170 -> V_181 )
continue;
V_174 = 1 ;
break;
}
F_132 ( & V_178 ) ;
if ( V_174 ) {
if ( V_165 != V_168 ) {
F_11 ( V_182 L_47
L_48
L_49 ,
V_170 -> V_64 , V_170 , V_172 -> V_64 ,
( V_172 -> V_179 ==
V_9 ) ? L_50 : L_51 ,
( V_183 ) V_172 -> V_181 ,
( V_183 ) V_172 -> V_180 ) ;
if ( V_165 == V_167 )
F_11 ( V_184 L_52
L_53
L_54 ) ;
F_11 ( V_185 L_55
L_56
L_57 ) ;
}
if ( V_165 == V_166 )
return - V_186 ;
}
return 0 ;
}
int F_133 ( T_18 V_181 , T_18 V_187 ,
const char * V_64 )
{
struct V_169 V_170 = {
. V_181 = V_181 ,
. V_180 = V_181 + V_187 - 1 ,
. V_64 = V_64 ,
. V_175 = V_176 ,
} ;
return F_129 ( & V_170 ) ;
}
int F_134 ( void )
{
return V_165 == V_166 ;
}
void F_135 ( T_19 V_130 )
{
F_136 ( V_130 ) ;
}
T_20 F_137 ( T_19 V_188 )
{
T_20 V_175 ;
F_138 ( V_188 , V_175 ) ;
return V_175 ;
}
void F_139 ( T_19 V_188 , T_20 V_175 )
{
F_140 ( V_188 , V_175 ) ;
}
T_10
F_141 ( char * V_64 , V_96 V_40 , V_96 V_189 , T_21 * * V_190 )
{
* V_190 = F_142 ( V_64 , V_40 , 0 , 0 , NULL ) ;
if ( * V_190 == NULL )
return V_106 ;
else
return V_60 ;
}
T_10 F_143 ( T_21 * V_190 )
{
F_144 ( V_190 ) ;
return ( V_60 ) ;
}
T_10 F_145 ( T_21 * V_190 )
{
F_146 ( V_190 ) ;
return ( V_60 ) ;
}
T_10 F_147 ( T_21 * V_190 , void * V_191 )
{
F_148 ( V_190 , V_191 ) ;
return ( V_60 ) ;
}
static inline int F_149 ( struct V_171 * V_170 )
{
struct V_171 * V_172 ;
F_131 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_170 -> V_179 == V_172 -> V_179 &&
V_170 -> V_181 == V_172 -> V_181 &&
V_170 -> V_180 == V_172 -> V_180 ) {
V_172 -> V_149 ++ ;
return 0 ;
}
}
V_170 -> V_149 = 1 ;
F_150 ( & V_170 -> V_192 , & V_193 ) ;
return 1 ;
}
static inline void F_151 ( struct V_171 * V_170 )
{
struct V_171 * V_172 ;
F_131 (res_list_elem, &resource_list_head,
resource_list) {
if ( V_170 -> V_179 == V_172 -> V_179 &&
V_170 -> V_181 == V_172 -> V_181 &&
V_170 -> V_180 == V_172 -> V_180 ) {
if ( -- V_172 -> V_149 == 0 ) {
F_152 ( & V_172 -> V_192 ) ;
F_30 ( V_172 ) ;
}
return;
}
}
}
T_10
F_153 (
V_95 V_8 ,
T_5 V_7 ,
T_6 V_5 )
{
struct V_171 V_170 ;
switch ( V_8 ) {
case V_9 :
case V_10 :
V_170 . V_181 = V_7 ;
V_170 . V_180 = V_7 + V_5 - 1 ;
V_170 . V_179 = V_8 ;
F_130 ( & V_178 ) ;
F_151 ( & V_170 ) ;
F_132 ( & V_178 ) ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
break;
}
return V_60 ;
}
T_10
F_154 (
V_95 V_8 ,
T_5 V_7 ,
T_6 V_5 ,
char * V_64 )
{
struct V_171 * V_170 ;
int V_201 ;
if ( V_165 == V_168 )
return V_60 ;
switch ( V_8 ) {
case V_9 :
case V_10 :
V_170 = F_26 ( sizeof( struct V_171 ) , V_50 ) ;
if ( ! V_170 )
return V_60 ;
F_155 ( V_170 -> V_64 , V_64 , 5 ) ;
V_170 -> V_181 = V_7 ;
V_170 -> V_180 = V_7 + V_5 - 1 ;
V_170 -> V_179 = V_8 ;
F_130 ( & V_178 ) ;
V_201 = F_149 ( V_170 ) ;
F_132 ( & V_178 ) ;
F_156 ( L_58
L_59 , V_201 ? L_60 : L_61 ,
( V_8 == V_9 )
? L_62 : L_63 ,
( unsigned long long ) V_170 -> V_181 ,
( unsigned long long ) V_170 -> V_180 ,
V_170 -> V_64 ) ;
if ( ! V_201 )
F_30 ( V_170 ) ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
break;
}
return V_60 ;
}
T_10 T_3 F_157 ( void )
{
F_42 ( & V_11 . V_12 ) ;
F_42 ( & V_11 . V_14 ) ;
F_42 ( & V_11 . V_23 ) ;
F_42 ( & V_11 . V_25 ) ;
return V_60 ;
}
T_10 T_3 F_158 ( void )
{
V_127 = F_159 ( L_64 , 0 , 1 ) ;
V_126 = F_159 ( L_65 , 0 , 1 ) ;
V_124 = F_159 ( L_66 , 0 , 1 ) ;
F_106 ( ! V_127 ) ;
F_106 ( ! V_126 ) ;
F_106 ( ! V_124 ) ;
F_160 ( F_1 ) ;
F_122 () ;
return V_60 ;
}
T_10 F_161 ( void )
{
if ( F_51 ) {
F_56 ( V_11 . V_83 ,
F_51 ) ;
}
F_43 ( & V_11 . V_25 ) ;
F_43 ( & V_11 . V_23 ) ;
F_43 ( & V_11 . V_14 ) ;
F_43 ( & V_11 . V_12 ) ;
F_162 ( V_127 ) ;
F_162 ( V_126 ) ;
F_162 ( V_124 ) ;
return V_60 ;
}
