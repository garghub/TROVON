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
T_4 V_7 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_5 )
return;
if ( V_4 -> V_9 == V_10 )
F_4 ( V_7 , V_5 , V_6 ) ;
else if ( V_4 -> V_9 == V_11 )
F_5 ( V_7 , V_5 , V_6 ) ;
}
static int T_3 F_6 ( void )
{
F_3 ( & V_12 . V_13 , V_12 . V_14 ,
L_8 ) ;
F_3 ( & V_12 . V_15 , V_12 . V_14 ,
L_9 ) ;
F_3 ( & V_12 . V_16 , V_12 . V_17 ,
L_10 ) ;
F_3 ( & V_12 . V_18 , V_12 . V_17 ,
L_11 ) ;
if ( V_12 . V_19 == 4 )
F_3 ( & V_12 . V_20 , 4 , L_12 ) ;
F_3 ( & V_12 . V_21 , V_12 . V_22 ,
L_13 ) ;
if ( ! ( V_12 . V_23 & 0x1 ) )
F_3 ( & V_12 . V_24 ,
V_12 . V_23 , L_14 ) ;
if ( ! ( V_12 . V_25 & 0x1 ) )
F_3 ( & V_12 . V_26 ,
V_12 . V_25 , L_15 ) ;
return 0 ;
}
void F_7 ( const char * V_27 , ... )
{
T_5 args ;
va_start ( args , V_27 ) ;
F_8 ( V_27 , args ) ;
va_end ( args ) ;
}
void F_8 ( const char * V_27 , T_5 args )
{
static char V_28 [ 512 ] ;
vsprintf ( V_28 , V_27 , args ) ;
#ifdef F_9
if ( V_29 ) {
F_10 ( L_16 , V_28 ) ;
} else {
F_11 ( V_30 L_16 , V_28 ) ;
}
#else
F_11 ( V_30 L_16 , V_28 ) ;
#endif
}
static int T_3 F_12 ( char * V_31 )
{
V_32 = F_13 ( V_31 , NULL , 16 ) ;
return 0 ;
}
T_6 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_32 )
return V_32 ;
#endif
if ( V_33 ) {
if ( V_34 . V_35 != V_36 )
return V_34 . V_35 ;
else if ( V_34 . V_37 != V_36 )
return V_34 . V_37 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_6 V_38 = 0 ;
F_16 ( & V_38 ) ;
return V_38 ;
}
}
static struct V_39 *
F_17 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 *
F_19 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_8 * F_20 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 = NULL ;
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_43 = V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
V_42 -> V_45 ++ ;
}
F_22 ( & V_44 ) ;
return V_43 ;
}
static struct V_39 *
F_23 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 * F_24 ( T_6 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_25 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_8 V_51 * ) F_26 ( F_27 ( V_48 ) ) ;
} else
return F_28 ( V_46 , V_47 ) ;
}
static void F_29 ( T_6 V_46 , void T_8 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_25 ( V_48 ) )
F_30 ( F_27 ( V_48 ) ) ;
else
F_31 ( V_52 ) ;
}
void T_8 * T_9
F_32 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 ;
T_6 V_46 ;
T_7 V_47 ;
if ( V_40 > V_53 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_54 )
return F_33 ( ( unsigned long ) V_40 , V_41 ) ;
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_45 ++ ;
goto V_55;
}
V_42 = F_34 ( sizeof( * V_42 ) , V_56 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
return NULL ;
}
V_46 = F_35 ( V_40 , V_50 ) ;
V_47 = F_36 ( V_40 + V_41 , V_50 ) - V_46 ;
V_43 = F_24 ( V_46 , V_47 ) ;
if ( ! V_43 ) {
F_22 ( & V_44 ) ;
F_37 ( V_42 ) ;
return NULL ;
}
F_38 ( & V_42 -> V_57 ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_40 = V_46 ;
V_42 -> V_41 = V_47 ;
V_42 -> V_45 = 1 ;
F_39 ( & V_42 -> V_57 , & V_58 ) ;
V_55:
F_22 ( & V_44 ) ;
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
}
static void F_40 ( struct V_39 * V_42 )
{
if ( ! -- V_42 -> V_45 )
F_41 ( & V_42 -> V_57 ) ;
}
static void F_42 ( struct V_39 * V_42 )
{
if ( ! V_42 -> V_45 ) {
F_43 () ;
F_29 ( V_42 -> V_40 , V_42 -> V_43 ) ;
F_37 ( V_42 ) ;
}
}
void T_10 F_44 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
if ( ! V_54 ) {
F_45 ( V_43 , V_41 ) ;
return;
}
F_21 ( & V_44 ) ;
V_42 = F_23 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
F_46 ( true , V_59 L_19 , V_60 , V_43 ) ;
return;
}
F_40 ( V_42 ) ;
F_22 ( & V_44 ) ;
F_42 ( V_42 ) ;
}
void T_3 F_47 ( void T_8 * V_43 , T_7 V_41 )
{
if ( ! V_54 )
F_45 ( V_43 , V_41 ) ;
}
int F_48 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_43 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return - V_62 ;
V_43 = F_32 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_43 )
return - V_63 ;
return 0 ;
}
void F_49 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_39 * V_42 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return;
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
return;
}
F_40 ( V_42 ) ;
F_22 ( & V_44 ) ;
F_42 ( V_42 ) ;
}
T_11
F_50 ( void * V_43 , T_6 * V_40 )
{
if ( ! V_40 || ! V_43 )
return V_64 ;
* V_40 = F_51 ( V_43 ) ;
return V_65 ;
}
T_11
F_52 ( const struct V_66 * V_67 ,
T_2 * V_68 )
{
if ( ! V_67 || ! V_68 )
return V_64 ;
* V_68 = NULL ;
if ( ! memcmp ( V_67 -> V_69 , L_20 , 4 ) && strlen ( V_70 ) ) {
F_11 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_68 = V_70 ;
}
return V_65 ;
}
T_11
F_53 ( struct V_71 * V_72 ,
struct V_71 * * V_73 )
{
if ( ! V_72 || ! V_73 )
return V_64 ;
* V_73 = NULL ;
#ifdef F_54
if ( strncmp ( V_72 -> V_74 , L_22 , 4 ) == 0 )
* V_73 = (struct V_71 * ) V_75 ;
#endif
if ( * V_73 != NULL ) {
F_11 (KERN_WARNING PREFIX L_23
L_24 ,
existing_table->signature,
existing_table->oem_table_id) ;
F_55 ( V_76 ) ;
}
return V_65 ;
}
T_11
F_56 ( struct V_71 * V_72 ,
T_6 * V_77 ,
T_1 * V_78 )
{
return V_79 ;
}
static T_12 F_57 ( int V_80 , void * V_81 )
{
T_1 V_82 ;
V_82 = (* F_58) ( V_83 ) ;
if ( V_82 ) {
V_84 ++ ;
return V_85 ;
} else {
V_86 ++ ;
return V_87 ;
}
}
T_11
F_59 ( T_1 V_88 , T_13 V_89 ,
void * V_90 )
{
unsigned int V_80 ;
F_60 () ;
if ( V_88 != V_12 . V_91 )
return V_64 ;
if ( F_58 )
return V_92 ;
if ( F_61 ( V_88 , & V_80 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_25 ,
gsi) ;
return V_65 ;
}
F_58 = V_89 ;
V_83 = V_90 ;
if ( F_62 ( V_80 , F_57 , V_93 , L_26 , F_57 ) ) {
F_11 (KERN_ERR PREFIX L_27 , irq) ;
F_58 = NULL ;
return V_94 ;
}
return V_65 ;
}
T_11 F_63 ( T_1 V_80 , T_13 V_89 )
{
if ( V_80 != V_12 . V_91 )
return V_64 ;
F_64 ( V_80 , F_57 ) ;
F_58 = NULL ;
return V_65 ;
}
void F_65 ( T_4 V_95 )
{
F_66 ( F_67 ( V_95 ) ) ;
}
void F_68 ( T_1 V_96 )
{
while ( V_96 ) {
T_1 V_97 = 1000 ;
if ( V_97 > V_96 )
V_97 = V_96 ;
F_69 ( V_97 ) ;
F_70 () ;
V_96 -= V_97 ;
}
}
T_4 F_71 ( void )
{
static T_4 V_98 ;
#ifdef F_72
#endif
#ifdef F_73
#endif
if ( ! V_98 )
F_11 (KERN_ERR PREFIX L_28 ) ;
return ++ V_98 ;
}
T_11 F_74 ( T_14 V_99 , T_1 * V_100 , T_1 V_101 )
{
T_1 V_102 ;
if ( ! V_100 )
V_100 = & V_102 ;
* V_100 = 0 ;
if ( V_101 <= 8 ) {
* ( V_103 * ) V_100 = F_75 ( V_99 ) ;
} else if ( V_101 <= 16 ) {
* ( V_104 * ) V_100 = F_76 ( V_99 ) ;
} else if ( V_101 <= 32 ) {
* ( T_1 * ) V_100 = F_77 ( V_99 ) ;
} else {
F_78 () ;
}
return V_65 ;
}
T_11 F_79 ( T_14 V_99 , T_1 V_100 , T_1 V_101 )
{
if ( V_101 <= 8 ) {
F_80 ( V_100 , V_99 ) ;
} else if ( V_101 <= 16 ) {
F_81 ( V_100 , V_99 ) ;
} else if ( V_101 <= 32 ) {
F_82 ( V_100 , V_99 ) ;
} else {
F_78 () ;
}
return V_65 ;
}
static inline T_4 F_83 ( const volatile void T_8 * V_7 )
{
return F_84 ( V_7 ) ;
}
static inline T_4 F_83 ( const volatile void T_8 * V_7 )
{
T_4 V_105 , V_106 ;
V_105 = F_85 ( V_7 ) ;
V_106 = F_85 ( V_7 + 4 ) ;
return V_105 | ( V_106 << 32 ) ;
}
T_11
F_86 ( T_6 V_107 , T_4 * V_100 , T_1 V_101 )
{
void T_8 * V_108 ;
unsigned int V_41 = V_101 / 8 ;
bool V_109 = false ;
T_4 V_102 ;
F_87 () ;
V_108 = F_19 ( V_107 , V_41 ) ;
if ( ! V_108 ) {
F_88 () ;
V_108 = F_28 ( V_107 , V_41 ) ;
if ( ! V_108 )
return V_110 ;
V_109 = true ;
}
if ( ! V_100 )
V_100 = & V_102 ;
switch ( V_101 ) {
case 8 :
* ( V_103 * ) V_100 = F_89 ( V_108 ) ;
break;
case 16 :
* ( V_104 * ) V_100 = F_90 ( V_108 ) ;
break;
case 32 :
* ( T_1 * ) V_100 = F_85 ( V_108 ) ;
break;
case 64 :
* ( T_4 * ) V_100 = F_83 ( V_108 ) ;
break;
default:
F_78 () ;
}
if ( V_109 )
F_31 ( V_108 ) ;
else
F_88 () ;
return V_65 ;
}
static inline void F_91 ( T_4 V_111 , volatile void T_8 * V_7 )
{
F_92 ( V_111 , V_7 ) ;
}
static inline void F_91 ( T_4 V_111 , volatile void T_8 * V_7 )
{
F_93 ( V_111 , V_7 ) ;
F_93 ( V_111 >> 32 , V_7 + 4 ) ;
}
T_11
F_94 ( T_6 V_107 , T_4 V_100 , T_1 V_101 )
{
void T_8 * V_108 ;
unsigned int V_41 = V_101 / 8 ;
bool V_109 = false ;
F_87 () ;
V_108 = F_19 ( V_107 , V_41 ) ;
if ( ! V_108 ) {
F_88 () ;
V_108 = F_28 ( V_107 , V_41 ) ;
if ( ! V_108 )
return V_110 ;
V_109 = true ;
}
switch ( V_101 ) {
case 8 :
F_95 ( V_100 , V_108 ) ;
break;
case 16 :
F_96 ( V_100 , V_108 ) ;
break;
case 32 :
F_93 ( V_100 , V_108 ) ;
break;
case 64 :
F_91 ( V_100 , V_108 ) ;
break;
default:
F_78 () ;
}
if ( V_109 )
F_31 ( V_108 ) ;
else
F_88 () ;
return V_65 ;
}
T_11
F_97 ( struct V_112 * V_113 , T_1 V_114 ,
T_4 * V_100 , T_1 V_101 )
{
int V_115 , V_41 ;
T_1 V_116 ;
if ( ! V_100 )
return V_64 ;
switch ( V_101 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_117 ;
}
V_115 = F_98 ( V_113 -> V_118 , V_113 -> V_119 ,
F_99 ( V_113 -> V_120 , V_113 -> V_121 ) ,
V_114 , V_41 , & V_116 ) ;
* V_100 = V_116 ;
return ( V_115 ? V_117 : V_65 ) ;
}
T_11
F_100 ( struct V_112 * V_113 , T_1 V_114 ,
T_4 V_100 , T_1 V_101 )
{
int V_115 , V_41 ;
switch ( V_101 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_117 ;
}
V_115 = F_101 ( V_113 -> V_118 , V_113 -> V_119 ,
F_99 ( V_113 -> V_120 , V_113 -> V_121 ) ,
V_114 , V_41 , V_100 ) ;
return ( V_115 ? V_117 : V_65 ) ;
}
static void F_102 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = F_103 ( V_123 , struct V_124 , V_123 ) ;
if ( V_125 -> V_126 )
F_104 () ;
V_125 -> V_121 ( V_125 -> V_90 ) ;
F_37 ( V_125 ) ;
}
static T_11 F_105 ( T_15 type ,
T_16 V_121 , void * V_90 , int V_127 )
{
T_11 V_128 = V_65 ;
struct V_124 * V_125 ;
struct V_129 * V_130 ;
int V_131 ;
F_106 ( ( V_132 ,
L_29 ,
V_121 , V_90 ) ) ;
V_125 = F_107 ( sizeof( struct V_124 ) , V_133 ) ;
if ( ! V_125 )
return V_134 ;
V_125 -> V_121 = V_121 ;
V_125 -> V_90 = V_90 ;
V_130 = V_127 ? V_135 :
( type == V_136 ? V_137 : V_138 ) ;
V_125 -> V_126 = V_127 ? 1 : 0 ;
if ( V_130 == V_135 )
F_108 ( & V_125 -> V_123 , F_102 ) ;
else if ( V_130 == V_137 )
F_108 ( & V_125 -> V_123 , F_102 ) ;
else
F_108 ( & V_125 -> V_123 , F_102 ) ;
V_131 = F_109 ( 0 , V_130 , & V_125 -> V_123 ) ;
if ( ! V_131 ) {
F_11 (KERN_ERR PREFIX
L_30 ) ;
V_128 = V_117 ;
F_37 ( V_125 ) ;
}
return V_128 ;
}
T_11 F_110 ( T_15 type ,
T_16 V_121 , void * V_90 )
{
return F_105 ( type , V_121 , V_90 , 0 ) ;
}
T_11 F_111 ( T_16 V_121 ,
void * V_90 )
{
return F_105 ( 0 , V_121 , V_90 , 1 ) ;
}
void F_104 ( void )
{
F_112 ( V_138 ) ;
F_112 ( V_137 ) ;
}
T_11
F_113 ( T_1 V_139 , T_1 V_140 , T_17 * V_141 )
{
struct V_142 * V_143 = NULL ;
V_143 = F_114 ( sizeof( struct V_142 ) ) ;
if ( ! V_143 )
return V_134 ;
memset ( V_143 , 0 , sizeof( struct V_142 ) ) ;
F_115 ( V_143 , V_140 ) ;
* V_141 = ( T_17 * ) V_143 ;
F_106 ( ( V_144 , L_31 ,
* V_141 , V_140 ) ) ;
return V_65 ;
}
T_11 F_116 ( T_17 V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
if ( ! V_143 )
return V_64 ;
F_106 ( ( V_144 , L_32 , V_141 ) ) ;
F_117 ( ! F_118 ( & V_143 -> V_145 ) ) ;
F_37 ( V_143 ) ;
V_143 = NULL ;
return V_65 ;
}
T_11 F_119 ( T_17 V_141 , T_1 V_146 , V_104 V_147 )
{
T_11 V_128 = V_65 ;
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
long V_148 ;
int V_131 = 0 ;
if ( ! V_143 || ( V_146 < 1 ) )
return V_64 ;
if ( V_146 > 1 )
return V_79 ;
F_106 ( ( V_144 , L_33 ,
V_141 , V_146 , V_147 ) ) ;
if ( V_147 == V_149 )
V_148 = V_150 ;
else
V_148 = F_67 ( V_147 ) ;
V_131 = F_120 ( V_143 , V_148 ) ;
if ( V_131 )
V_128 = V_151 ;
if ( F_121 ( V_128 ) ) {
F_106 ( ( V_144 ,
L_34 ,
V_141 , V_146 , V_147 ,
F_122 ( V_128 ) ) ) ;
} else {
F_106 ( ( V_144 ,
L_35 , V_141 ,
V_146 , V_147 ) ) ;
}
return V_128 ;
}
T_11 F_123 ( T_17 V_141 , T_1 V_146 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
if ( ! V_143 || ( V_146 < 1 ) )
return V_64 ;
if ( V_146 > 1 )
return V_79 ;
F_106 ( ( V_144 , L_36 , V_141 ,
V_146 ) ) ;
F_124 ( V_143 ) ;
return V_65 ;
}
T_1 F_125 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_152 ;
F_126 ( V_28 , sizeof( V_153 ) ) ;
V_152 = strlen ( V_28 ) - 1 ;
V_28 [ V_152 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_127 ( T_1 V_121 , void * V_154 )
{
switch ( V_121 ) {
case V_155 :
F_11 (KERN_ERR PREFIX L_37 ) ;
break;
case V_156 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_128 ( char * V_157 )
{
char * V_158 = V_70 ;
int V_159 = V_160 - 1 ;
if ( ! V_157 || ! * V_157 )
return 0 ;
for (; V_159 -- && V_157 && * V_157 ; V_157 ++ ) {
if ( isalnum ( * V_157 ) || * V_157 == ' ' || * V_157 == ':' )
* V_158 ++ = * V_157 ;
else if ( * V_157 == '\'' || * V_157 == '"' )
continue;
else
break;
}
* V_158 = 0 ;
return 1 ;
}
void T_3 F_129 ( char * V_157 )
{
struct V_161 * V_162 ;
bool V_163 = true ;
int V_164 ;
if ( ! V_165 )
return;
if ( V_157 == NULL || * V_157 == '\0' ) {
F_11 (KERN_INFO PREFIX L_38 ) ;
V_165 = FALSE ;
return;
}
if ( * V_157 == '!' ) {
V_157 ++ ;
V_163 = false ;
}
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ ) {
V_162 = & V_167 [ V_164 ] ;
if ( ! strcmp ( V_162 -> string , V_157 ) ) {
V_162 -> V_163 = V_163 ;
break;
} else if ( V_162 -> string [ 0 ] == '\0' ) {
V_162 -> V_163 = V_163 ;
strncpy ( V_162 -> string , V_157 , V_168 ) ;
break;
}
}
}
static void T_3 F_130 ( unsigned int V_163 )
{
if ( V_169 . V_163 != V_163 )
V_169 . V_163 = V_163 ;
if ( V_169 . V_163 )
F_129 ( L_1 ) ;
else
F_129 ( L_39 ) ;
return;
}
static void T_3 F_131 ( unsigned int V_163 )
{
V_169 . V_170 = 1 ;
V_169 . V_171 = 0 ;
F_130 ( V_163 ) ;
return;
}
void T_3 F_132 ( int V_163 , const struct V_172 * V_173 )
{
F_11 (KERN_NOTICE PREFIX L_40 , d->ident) ;
if ( V_163 == - 1 )
return;
V_169 . V_171 = 1 ;
F_130 ( V_163 ) ;
return;
}
static void T_3 F_133 ( void )
{
struct V_161 * V_162 ;
char * V_157 ;
int V_164 ;
T_11 V_128 ;
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ ) {
V_162 = & V_167 [ V_164 ] ;
V_157 = V_162 -> string ;
if ( * V_157 == '\0' )
break;
if ( V_162 -> V_163 ) {
V_128 = F_134 ( V_157 ) ;
if ( F_135 ( V_128 ) )
F_11 (KERN_INFO PREFIX L_41 , str) ;
} else {
V_128 = F_136 ( V_157 ) ;
if ( F_135 ( V_128 ) )
F_11 (KERN_INFO PREFIX L_42 , str) ;
}
}
}
static int T_3 F_137 ( char * V_157 )
{
if ( V_157 && ! strcmp ( L_1 , V_157 ) )
F_131 ( 1 ) ;
else if ( V_157 && ! strcmp ( L_39 , V_157 ) )
F_131 ( 0 ) ;
else
F_129 ( V_157 ) ;
return 1 ;
}
static int T_3 F_138 ( char * V_157 )
{
F_11 (KERN_INFO PREFIX L_43 ) ;
V_174 = TRUE ;
return 1 ;
}
static int T_3 F_139 ( char * V_157 )
{
if ( V_157 == NULL || * V_157 == '\0' )
return 0 ;
if ( ! strcmp ( L_44 , V_157 ) )
V_175 = V_176 ;
else if ( ! strcmp ( L_45 , V_157 ) )
V_175 = V_177 ;
else if ( ! strcmp ( L_46 , V_157 ) )
V_175 = V_178 ;
return 1 ;
}
int F_140 ( const struct V_179 * V_180 )
{
T_18 V_9 ;
T_7 V_5 ;
V_103 V_181 = 0 ;
int V_182 = 0 ;
if ( V_175 == V_178 )
return 0 ;
if ( ! ( V_180 -> V_183 & V_184 ) && ! ( V_180 -> V_183 & V_185 ) )
return 0 ;
if ( V_180 -> V_183 & V_184 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = V_180 -> V_186 - V_180 -> V_187 + 1 ;
if ( V_175 != V_178 )
V_181 = 1 ;
V_182 = F_141 ( V_9 , V_180 -> V_187 , V_5 , V_181 ) ;
if ( V_182 ) {
if ( V_175 != V_178 ) {
if ( V_175 == V_177 )
F_11 ( V_188 L_47
L_48
L_49 ) ;
F_11 ( V_189 L_50
L_51
L_52 ) ;
}
if ( V_175 == V_176 )
return - V_190 ;
}
return 0 ;
}
int F_142 ( T_19 V_187 , T_19 V_191 ,
const char * V_69 )
{
struct V_179 V_180 = {
. V_187 = V_187 ,
. V_186 = V_187 + V_191 - 1 ,
. V_69 = V_69 ,
. V_183 = V_184 ,
} ;
return F_140 ( & V_180 ) ;
}
int F_143 ( void )
{
return V_175 == V_176 ;
}
void F_144 ( T_20 V_141 )
{
F_145 ( V_141 ) ;
}
T_21 F_146 ( T_20 V_192 )
{
T_21 V_183 ;
F_147 ( V_192 , V_183 ) ;
return V_183 ;
}
void F_148 ( T_20 V_192 , T_21 V_183 )
{
F_149 ( V_192 , V_183 ) ;
}
T_11
F_150 ( char * V_69 , V_104 V_41 , V_104 V_193 , T_22 * * V_194 )
{
* V_194 = F_151 ( V_69 , V_41 , 0 , 0 , NULL ) ;
if ( * V_194 == NULL )
return V_117 ;
else
return V_65 ;
}
T_11 F_152 ( T_22 * V_194 )
{
F_153 ( V_194 ) ;
return ( V_65 ) ;
}
T_11 F_154 ( T_22 * V_194 )
{
F_155 ( V_194 ) ;
return ( V_65 ) ;
}
T_11 F_156 ( T_22 * V_194 , void * V_195 )
{
F_157 ( V_194 , V_195 ) ;
return ( V_65 ) ;
}
T_11 T_3 F_158 ( void )
{
F_48 ( & V_12 . V_13 ) ;
F_48 ( & V_12 . V_15 ) ;
F_48 ( & V_12 . V_24 ) ;
F_48 ( & V_12 . V_26 ) ;
return V_65 ;
}
T_11 T_3 F_159 ( void )
{
V_138 = F_160 ( L_53 , 0 , 1 ) ;
V_137 = F_160 ( L_54 , 0 , 1 ) ;
V_135 = F_160 ( L_55 , 0 , 1 ) ;
F_117 ( ! V_138 ) ;
F_117 ( ! V_137 ) ;
F_117 ( ! V_135 ) ;
F_161 ( F_1 ) ;
F_133 () ;
return V_65 ;
}
T_11 F_162 ( void )
{
if ( F_58 ) {
F_63 ( V_12 . V_91 ,
F_58 ) ;
}
F_49 ( & V_12 . V_26 ) ;
F_49 ( & V_12 . V_24 ) ;
F_49 ( & V_12 . V_15 ) ;
F_49 ( & V_12 . V_13 ) ;
F_163 ( V_138 ) ;
F_163 ( V_137 ) ;
F_163 ( V_135 ) ;
return V_65 ;
}
T_11 F_164 ( V_103 V_196 , T_1 V_197 ,
T_1 V_198 )
{
int V_199 = 0 ;
if ( V_200 )
V_199 = V_200 ( V_196 ,
V_197 , V_198 ) ;
if ( V_199 < 0 )
return V_117 ;
else if ( V_199 > 0 )
return V_201 ;
return V_65 ;
}
void F_165 ( int (* F_166)( V_103 V_196 ,
T_1 V_202 , T_1 V_203 ) )
{
V_200 = F_166 ;
}
