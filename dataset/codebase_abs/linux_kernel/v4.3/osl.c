static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
if ( ! strcmp ( L_8 , V_1 ) ) {
F_3 ( V_3 ) ;
V_2 = V_4 ;
}
return V_2 ;
}
static void T_3 F_4 ( struct V_5 * V_6 ,
unsigned int V_7 , char * V_8 )
{
T_4 V_9 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_7 )
return;
if ( V_6 -> V_11 == V_12 )
F_5 ( V_9 , V_7 , V_8 ) ;
else if ( V_6 -> V_11 == V_13 )
F_6 ( V_9 , V_7 , V_8 ) ;
}
static int T_3 F_7 ( void )
{
F_4 ( & V_14 . V_15 , V_14 . V_16 ,
L_9 ) ;
F_4 ( & V_14 . V_17 , V_14 . V_16 ,
L_10 ) ;
F_4 ( & V_14 . V_18 , V_14 . V_19 ,
L_11 ) ;
F_4 ( & V_14 . V_20 , V_14 . V_19 ,
L_12 ) ;
if ( V_14 . V_21 == 4 )
F_4 ( & V_14 . V_22 , 4 , L_13 ) ;
F_4 ( & V_14 . V_23 , V_14 . V_24 ,
L_14 ) ;
if ( ! ( V_14 . V_25 & 0x1 ) )
F_4 ( & V_14 . V_26 ,
V_14 . V_25 , L_15 ) ;
if ( ! ( V_14 . V_27 & 0x1 ) )
F_4 ( & V_14 . V_28 ,
V_14 . V_27 , L_16 ) ;
return 0 ;
}
void F_8 ( const char * V_29 , ... )
{
T_5 args ;
va_start ( args , V_29 ) ;
F_9 ( V_29 , args ) ;
va_end ( args ) ;
}
void F_9 ( const char * V_29 , T_5 args )
{
static char V_30 [ 512 ] ;
vsprintf ( V_30 , V_29 , args ) ;
#ifdef F_10
if ( V_31 ) {
F_11 ( L_17 , V_30 ) ;
} else {
F_12 ( V_32 L_17 , V_30 ) ;
}
#else
F_12 ( V_32 L_17 , V_30 ) ;
#endif
}
static int T_3 F_13 ( char * V_33 )
{
if ( F_14 ( V_33 , 16 , & V_34 ) )
return - V_35 ;
return 0 ;
}
T_6 T_3 F_15 ( void )
{
#ifdef F_16
if ( V_34 )
return V_34 ;
#endif
if ( F_17 ( V_36 ) ) {
if ( V_37 . V_38 != V_39 )
return V_37 . V_38 ;
else if ( V_37 . V_40 != V_39 )
return V_37 . V_40 ;
else {
F_12 (KERN_ERR PREFIX
L_18 ) ;
return 0 ;
}
} else if ( F_18 ( V_41 ) ) {
T_6 V_42 = 0 ;
F_19 ( & V_42 ) ;
return V_42 ;
}
return 0 ;
}
static struct V_43 *
F_20 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_21 (map, &acpi_ioremaps, list)
if ( V_46 -> V_44 <= V_44 &&
V_44 + V_45 <= V_46 -> V_44 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 *
F_22 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 )
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
return NULL ;
}
void T_8 * F_23 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 = NULL ;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_47 = V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
V_46 -> V_49 ++ ;
}
F_25 ( & V_48 ) ;
return V_47 ;
}
static struct V_43 *
F_26 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_21 (map, &acpi_ioremaps, list)
if ( V_46 -> V_47 <= V_47 &&
V_47 + V_45 <= V_46 -> V_47 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 * F_27 ( T_6 V_50 , unsigned long V_51 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_28 ( V_52 ) ) {
if ( V_51 > V_54 )
return NULL ;
return ( void T_8 V_55 * ) F_29 ( F_30 ( V_52 ) ) ;
} else
return F_31 ( V_50 , V_51 ) ;
}
static void F_32 ( T_6 V_50 , void T_8 * V_56 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_28 ( V_52 ) )
F_33 ( F_30 ( V_52 ) ) ;
else
F_34 ( V_56 ) ;
}
void T_8 * T_9
F_35 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 ;
T_6 V_50 ;
T_7 V_51 ;
if ( V_44 > V_57 ) {
F_12 (KERN_ERR PREFIX L_19 ) ;
return NULL ;
}
if ( ! V_58 )
return F_36 ( ( unsigned long ) V_44 , V_45 ) ;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_46 -> V_49 ++ ;
goto V_59;
}
V_46 = F_37 ( sizeof( * V_46 ) , V_60 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
return NULL ;
}
V_50 = F_38 ( V_44 , V_54 ) ;
V_51 = F_39 ( V_44 + V_45 , V_54 ) - V_50 ;
V_47 = F_27 ( V_50 , V_51 ) ;
if ( ! V_47 ) {
F_25 ( & V_48 ) ;
F_40 ( V_46 ) ;
return NULL ;
}
F_41 ( & V_46 -> V_61 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_44 = V_50 ;
V_46 -> V_45 = V_51 ;
V_46 -> V_49 = 1 ;
F_42 ( & V_46 -> V_61 , & V_62 ) ;
V_59:
F_25 ( & V_48 ) ;
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
}
void * T_9
F_43 ( T_6 V_44 , T_7 V_45 )
{
return ( void * ) F_35 ( V_44 , V_45 ) ;
}
static void F_44 ( struct V_43 * V_46 )
{
if ( ! -- V_46 -> V_49 )
F_45 ( & V_46 -> V_61 ) ;
}
static void F_46 ( struct V_43 * V_46 )
{
if ( ! V_46 -> V_49 ) {
F_47 () ;
F_32 ( V_46 -> V_44 , V_46 -> V_47 ) ;
F_40 ( V_46 ) ;
}
}
void T_10 F_48 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
if ( ! V_58 ) {
F_49 ( V_47 , V_45 ) ;
return;
}
F_24 ( & V_48 ) ;
V_46 = F_26 ( V_47 , V_45 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
F_50 ( true , V_63 L_20 , V_64 , V_47 ) ;
return;
}
F_44 ( V_46 ) ;
F_25 ( & V_48 ) ;
F_46 ( V_46 ) ;
}
void T_10 F_51 ( void * V_47 , T_7 V_45 )
{
return F_48 ( ( void T_8 * ) V_47 , V_45 ) ;
}
void T_3 F_52 ( void T_8 * V_47 , T_7 V_45 )
{
if ( ! V_58 )
F_49 ( V_47 , V_45 ) ;
}
int F_53 ( struct V_5 * V_6 )
{
T_4 V_9 ;
void T_8 * V_47 ;
if ( V_6 -> V_11 != V_13 )
return 0 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return - V_35 ;
V_47 = F_35 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_47 )
return - V_66 ;
return 0 ;
}
void F_54 ( struct V_5 * V_6 )
{
T_4 V_9 ;
struct V_43 * V_46 ;
if ( V_6 -> V_11 != V_13 )
return;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
return;
}
F_44 ( V_46 ) ;
F_25 ( & V_48 ) ;
F_46 ( V_46 ) ;
}
T_11
F_55 ( void * V_47 , T_6 * V_44 )
{
if ( ! V_44 || ! V_47 )
return V_67 ;
* V_44 = F_56 ( V_47 ) ;
return V_68 ;
}
int T_3 F_57 ( char * V_69 )
{
V_70 = true ;
return 1 ;
}
T_11
F_58 ( const struct V_71 * V_72 ,
char * * V_73 )
{
if ( ! V_72 || ! V_73 )
return V_67 ;
* V_73 = NULL ;
if ( ! memcmp ( V_72 -> V_74 , L_21 , 4 ) && strlen ( V_75 ) ) {
F_12 (KERN_INFO PREFIX L_22 ,
acpi_os_name) ;
* V_73 = V_75 ;
}
if ( ! memcmp ( V_72 -> V_74 , L_23 , 4 ) && V_70 ) {
F_12 (KERN_INFO PREFIX L_24 ) ;
* V_73 = ( char * ) 5 ;
}
return V_68 ;
}
static T_12 T_3 F_59 ( T_12 * V_30 , T_1 V_7 )
{
T_12 V_76 = 0 ;
T_12 * V_77 = V_30 + V_7 ;
while ( V_30 < V_77 )
V_76 = ( T_12 ) ( V_76 + * ( V_30 ++ ) ) ;
return V_76 ;
}
void T_3 F_60 ( void * V_78 , T_13 V_45 )
{
int V_79 , V_80 , V_81 = 0 , V_82 = 0 ;
long V_83 = 0 ;
struct V_84 * V_85 ;
char V_86 [ 32 ] = L_25 ;
struct V_87 V_88 ;
if ( V_78 == NULL || V_45 == 0 )
return;
for ( V_80 = 0 ; V_80 < V_89 ; V_80 ++ ) {
V_88 = F_61 ( V_86 , V_78 , V_45 , & V_83 ) ;
if ( ! V_88 . V_78 )
break;
V_78 += V_83 ;
V_45 -= V_83 ;
if ( V_88 . V_45 < sizeof( struct V_84 ) ) {
F_62 ( L_26 ,
V_86 , V_88 . V_74 ) ;
continue;
}
V_85 = V_88 . V_78 ;
for ( V_79 = 0 ; V_90 [ V_79 ] ; V_79 ++ )
if ( ! memcmp ( V_85 -> V_91 , V_90 [ V_79 ] , 4 ) )
break;
if ( ! V_90 [ V_79 ] ) {
F_62 ( L_27 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( V_88 . V_45 != V_85 -> V_7 ) {
F_62 ( L_28 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( F_59 ( V_88 . V_78 , V_85 -> V_7 ) ) {
F_62 ( L_29 ,
V_86 , V_88 . V_74 ) ;
continue;
}
F_63 ( L_30 ,
V_85 -> V_91 , V_86 , V_88 . V_74 , V_85 -> V_7 ) ;
V_92 += V_85 -> V_7 ;
V_93 [ V_81 ] . V_78 = V_88 . V_78 ;
V_93 [ V_81 ] . V_45 = V_88 . V_45 ;
V_81 ++ ;
}
if ( V_81 == 0 )
return;
V_94 =
F_64 ( 0 , V_95 << V_53 ,
V_92 , V_54 ) ;
if ( ! V_94 ) {
F_65 ( 1 ) ;
return;
}
F_66 ( V_94 , V_92 ) ;
F_67 ( V_94 , V_92 ) ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
unsigned char * V_96 = V_93 [ V_80 ] . V_78 ;
T_14 V_45 = V_93 [ V_80 ] . V_45 ;
T_14 V_97 = V_94 + V_82 ;
T_14 V_98 , V_99 ;
char * V_100 ;
V_82 += V_45 ;
while ( V_45 ) {
V_98 = V_97 & ~ V_101 ;
V_99 = V_45 ;
if ( V_99 > V_102 - V_98 )
V_99 = V_102 - V_98 ;
V_100 = F_68 ( V_97 & V_101 ,
V_99 + V_98 ) ;
memcpy ( V_100 + V_98 , V_96 , V_99 ) ;
F_69 ( V_100 , V_99 + V_98 ) ;
V_96 += V_99 ;
V_97 += V_99 ;
V_45 -= V_99 ;
}
}
}
static void F_70 ( struct V_84 * V_85 )
{
F_71 ( V_63
L_31 ,
V_85 -> V_91 , V_85 -> V_103 ) ;
F_72 ( V_104 , V_105 ) ;
}
T_11
F_73 ( struct V_84 * V_106 ,
struct V_84 * * V_107 )
{
if ( ! V_106 || ! V_107 )
return V_67 ;
* V_107 = NULL ;
#ifdef F_74
if ( strncmp ( V_106 -> V_91 , L_32 , 4 ) == 0 )
* V_107 = (struct V_84 * ) V_108 ;
#endif
if ( * V_107 != NULL )
F_70 ( V_106 ) ;
return V_68 ;
}
T_11
F_75 ( struct V_84 * V_106 ,
T_6 * V_10 ,
T_1 * V_109 )
{
#ifndef F_76
* V_109 = 0 ;
* V_10 = 0 ;
return V_68 ;
#else
int V_110 = 0 ;
struct V_84 * V_85 ;
* V_109 = 0 ;
* V_10 = 0 ;
if ( ! V_94 )
return V_68 ;
do {
if ( V_110 + V_111 > V_92 ) {
F_65 ( 1 ) ;
return V_68 ;
}
V_85 = F_43 ( V_94 + V_110 ,
V_111 ) ;
if ( V_110 + V_85 -> V_7 > V_92 ) {
F_51 ( V_85 , V_111 ) ;
F_65 ( 1 ) ;
return V_68 ;
}
V_110 += V_85 -> V_7 ;
if ( memcmp ( V_106 -> V_91 , V_85 -> V_91 , 4 ) ) {
F_51 ( V_85 ,
V_111 ) ;
continue;
}
if ( memcmp ( V_85 -> V_103 , V_106 -> V_103 ,
V_112 ) ) {
F_51 ( V_85 ,
V_111 ) ;
continue;
}
V_110 -= V_85 -> V_7 ;
* V_109 = V_85 -> V_7 ;
F_51 ( V_85 , V_111 ) ;
* V_10 = V_94 + V_110 ;
break;
} while ( V_110 + V_111 < V_92 );
if ( * V_10 != 0 )
F_70 ( V_106 ) ;
return V_68 ;
#endif
}
static T_15 F_77 ( int V_113 , void * V_114 )
{
T_1 V_115 ;
V_115 = (* F_78) ( V_116 ) ;
if ( V_115 ) {
V_117 ++ ;
return V_118 ;
} else {
V_119 ++ ;
return V_120 ;
}
}
T_11
F_79 ( T_1 V_121 , T_16 V_122 ,
void * V_123 )
{
unsigned int V_113 ;
F_80 () ;
if ( V_121 != V_14 . V_124 )
return V_67 ;
if ( F_78 )
return V_125 ;
if ( F_81 ( V_121 , & V_113 ) < 0 ) {
F_12 (KERN_ERR PREFIX L_33 ,
gsi) ;
return V_68 ;
}
F_78 = V_122 ;
V_116 = V_123 ;
if ( F_82 ( V_113 , F_77 , V_126 , L_34 , F_77 ) ) {
F_12 (KERN_ERR PREFIX L_35 , irq) ;
F_78 = NULL ;
return V_127 ;
}
return V_68 ;
}
T_11 F_83 ( T_1 V_113 , T_16 V_122 )
{
if ( V_113 != V_14 . V_124 )
return V_67 ;
F_84 ( V_113 , F_77 ) ;
F_78 = NULL ;
return V_68 ;
}
void F_85 ( T_4 V_128 )
{
F_86 ( V_128 ) ;
}
void F_87 ( T_1 V_129 )
{
while ( V_129 ) {
T_1 V_130 = 1000 ;
if ( V_130 > V_129 )
V_130 = V_129 ;
F_88 ( V_130 ) ;
F_89 () ;
V_129 -= V_130 ;
}
}
T_4 F_90 ( void )
{
T_4 V_131 = F_91 ( F_92 () ) ;
F_93 ( V_131 , 100 ) ;
return V_131 ;
}
T_11 F_94 ( T_17 V_132 , T_1 * V_133 , T_1 V_134 )
{
T_1 V_135 ;
if ( ! V_133 )
V_133 = & V_135 ;
* V_133 = 0 ;
if ( V_134 <= 8 ) {
* ( T_12 * ) V_133 = F_95 ( V_132 ) ;
} else if ( V_134 <= 16 ) {
* ( V_136 * ) V_133 = F_96 ( V_132 ) ;
} else if ( V_134 <= 32 ) {
* ( T_1 * ) V_133 = F_97 ( V_132 ) ;
} else {
F_98 () ;
}
return V_68 ;
}
T_11 F_99 ( T_17 V_132 , T_1 V_133 , T_1 V_134 )
{
if ( V_134 <= 8 ) {
F_100 ( V_133 , V_132 ) ;
} else if ( V_134 <= 16 ) {
F_101 ( V_133 , V_132 ) ;
} else if ( V_134 <= 32 ) {
F_102 ( V_133 , V_132 ) ;
} else {
F_98 () ;
}
return V_68 ;
}
T_11
F_103 ( T_6 V_137 , T_4 * V_133 , T_1 V_134 )
{
void T_8 * V_138 ;
unsigned int V_45 = V_134 / 8 ;
bool V_139 = false ;
T_4 V_135 ;
F_104 () ;
V_138 = F_22 ( V_137 , V_45 ) ;
if ( ! V_138 ) {
F_105 () ;
V_138 = F_31 ( V_137 , V_45 ) ;
if ( ! V_138 )
return V_140 ;
V_139 = true ;
}
if ( ! V_133 )
V_133 = & V_135 ;
switch ( V_134 ) {
case 8 :
* ( T_12 * ) V_133 = F_106 ( V_138 ) ;
break;
case 16 :
* ( V_136 * ) V_133 = F_107 ( V_138 ) ;
break;
case 32 :
* ( T_1 * ) V_133 = F_108 ( V_138 ) ;
break;
case 64 :
* ( T_4 * ) V_133 = F_109 ( V_138 ) ;
break;
default:
F_98 () ;
}
if ( V_139 )
F_34 ( V_138 ) ;
else
F_105 () ;
return V_68 ;
}
T_11
F_110 ( T_6 V_137 , T_4 V_133 , T_1 V_134 )
{
void T_8 * V_138 ;
unsigned int V_45 = V_134 / 8 ;
bool V_139 = false ;
F_104 () ;
V_138 = F_22 ( V_137 , V_45 ) ;
if ( ! V_138 ) {
F_105 () ;
V_138 = F_31 ( V_137 , V_45 ) ;
if ( ! V_138 )
return V_140 ;
V_139 = true ;
}
switch ( V_134 ) {
case 8 :
F_111 ( V_133 , V_138 ) ;
break;
case 16 :
F_112 ( V_133 , V_138 ) ;
break;
case 32 :
F_113 ( V_133 , V_138 ) ;
break;
case 64 :
F_114 ( V_133 , V_138 ) ;
break;
default:
F_98 () ;
}
if ( V_139 )
F_34 ( V_138 ) ;
else
F_105 () ;
return V_68 ;
}
T_11
F_115 ( struct V_141 * V_142 , T_1 V_143 ,
T_4 * V_133 , T_1 V_134 )
{
int V_144 , V_45 ;
T_1 V_145 ;
if ( ! V_133 )
return V_67 ;
switch ( V_134 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_146 ;
}
V_144 = F_116 ( V_142 -> V_147 , V_142 -> V_148 ,
F_117 ( V_142 -> V_149 , V_142 -> V_150 ) ,
V_143 , V_45 , & V_145 ) ;
* V_133 = V_145 ;
return ( V_144 ? V_146 : V_68 ) ;
}
T_11
F_118 ( struct V_141 * V_142 , T_1 V_143 ,
T_4 V_133 , T_1 V_134 )
{
int V_144 , V_45 ;
switch ( V_134 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_146 ;
}
V_144 = F_119 ( V_142 -> V_147 , V_142 -> V_148 ,
F_117 ( V_142 -> V_149 , V_142 -> V_150 ) ,
V_143 , V_45 , V_133 ) ;
return ( V_144 ? V_146 : V_68 ) ;
}
static void F_120 ( struct V_151 * V_152 )
{
struct V_153 * V_154 = F_121 ( V_152 , struct V_153 , V_152 ) ;
V_154 -> V_150 ( V_154 -> V_123 ) ;
F_40 ( V_154 ) ;
}
T_11 F_122 ( T_18 type ,
T_19 V_150 , void * V_123 )
{
T_11 V_155 = V_68 ;
struct V_153 * V_154 ;
struct V_156 * V_157 ;
int V_158 ;
F_123 ( ( V_159 ,
L_36 ,
V_150 , V_123 ) ) ;
V_154 = F_37 ( sizeof( struct V_153 ) , V_160 ) ;
if ( ! V_154 )
return V_161 ;
V_154 -> V_150 = V_150 ;
V_154 -> V_123 = V_123 ;
if ( type == V_162 ) {
V_157 = V_163 ;
F_124 ( & V_154 -> V_152 , F_120 ) ;
} else {
V_157 = V_164 ;
F_124 ( & V_154 -> V_152 , F_120 ) ;
}
V_158 = F_125 ( 0 , V_157 , & V_154 -> V_152 ) ;
if ( ! V_158 ) {
F_12 (KERN_ERR PREFIX
L_37 ) ;
V_155 = V_146 ;
F_40 ( V_154 ) ;
}
return V_155 ;
}
void F_126 ( void )
{
if ( F_78 )
F_127 ( V_14 . V_124 ) ;
F_128 ( V_164 ) ;
F_128 ( V_163 ) ;
}
static void F_129 ( struct V_151 * V_152 )
{
struct V_165 * V_166 = F_121 ( V_152 , struct V_165 , V_152 ) ;
F_126 () ;
F_130 ( V_166 -> V_167 , V_166 -> V_168 ) ;
F_40 ( V_166 ) ;
}
T_11 F_131 ( struct V_169 * V_167 , T_1 V_168 )
{
struct V_165 * V_166 ;
F_123 ( ( V_159 ,
L_38 ,
V_167 , V_168 ) ) ;
V_166 = F_132 ( sizeof( * V_166 ) , V_60 ) ;
if ( ! V_166 )
return V_161 ;
F_124 ( & V_166 -> V_152 , F_129 ) ;
V_166 -> V_167 = V_167 ;
V_166 -> V_168 = V_168 ;
if ( ! F_133 ( V_170 , & V_166 -> V_152 ) ) {
F_40 ( V_166 ) ;
return V_146 ;
}
return V_68 ;
}
bool F_134 ( struct V_151 * V_152 )
{
return F_133 ( V_170 , V_152 ) ;
}
T_11
F_135 ( T_1 V_171 , T_1 V_172 , T_20 * V_173 )
{
struct V_174 * V_175 = NULL ;
V_175 = F_136 ( sizeof( struct V_174 ) ) ;
if ( ! V_175 )
return V_161 ;
F_137 ( V_175 , V_172 ) ;
* V_173 = ( T_20 * ) V_175 ;
F_123 ( ( V_176 , L_39 ,
* V_173 , V_172 ) ) ;
return V_68 ;
}
T_11 F_138 ( T_20 V_173 )
{
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
if ( ! V_175 )
return V_67 ;
F_123 ( ( V_176 , L_40 , V_173 ) ) ;
F_139 ( ! F_140 ( & V_175 -> V_177 ) ) ;
F_40 ( V_175 ) ;
V_175 = NULL ;
return V_68 ;
}
T_11 F_141 ( T_20 V_173 , T_1 V_178 , V_136 V_179 )
{
T_11 V_155 = V_68 ;
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
long V_180 ;
int V_158 = 0 ;
if ( ! V_181 )
return V_68 ;
if ( ! V_175 || ( V_178 < 1 ) )
return V_67 ;
if ( V_178 > 1 )
return V_182 ;
F_123 ( ( V_176 , L_41 ,
V_173 , V_178 , V_179 ) ) ;
if ( V_179 == V_183 )
V_180 = V_184 ;
else
V_180 = F_142 ( V_179 ) ;
V_158 = F_143 ( V_175 , V_180 ) ;
if ( V_158 )
V_155 = V_185 ;
if ( F_144 ( V_155 ) ) {
F_123 ( ( V_176 ,
L_42 ,
V_173 , V_178 , V_179 ,
F_145 ( V_155 ) ) ) ;
} else {
F_123 ( ( V_176 ,
L_43 , V_173 ,
V_178 , V_179 ) ) ;
}
return V_155 ;
}
T_11 F_146 ( T_20 V_173 , T_1 V_178 )
{
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
if ( ! V_181 )
return V_68 ;
if ( ! V_175 || ( V_178 < 1 ) )
return V_67 ;
if ( V_178 > 1 )
return V_182 ;
F_123 ( ( V_176 , L_44 , V_173 ,
V_178 ) ) ;
F_147 ( V_175 ) ;
return V_68 ;
}
T_1 F_148 ( char * V_30 )
{
#ifdef F_10
if ( V_31 ) {
T_1 V_186 ;
F_149 ( V_30 , sizeof( V_187 ) ) ;
V_186 = strlen ( V_30 ) - 1 ;
V_30 [ V_186 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_150 ( T_1 V_150 , void * V_188 )
{
switch ( V_150 ) {
case V_189 :
F_12 (KERN_ERR PREFIX L_45 ) ;
break;
case V_190 :
break;
default:
break;
}
return V_68 ;
}
static int T_3 F_151 ( char * V_69 )
{
char * V_191 = V_75 ;
int V_192 = V_193 - 1 ;
if ( ! V_69 || ! * V_69 )
return 0 ;
for (; V_192 -- && * V_69 ; V_69 ++ ) {
if ( isalnum ( * V_69 ) || * V_69 == ' ' || * V_69 == ':' )
* V_191 ++ = * V_69 ;
else if ( * V_69 == '\'' || * V_69 == '"' )
continue;
else
break;
}
* V_191 = 0 ;
return 1 ;
}
void T_3 F_152 ( char * V_69 )
{
struct V_194 * V_195 ;
bool V_196 = true ;
int V_197 ;
if ( ! V_198 )
return;
if ( V_69 == NULL || * V_69 == '\0' ) {
F_12 (KERN_INFO PREFIX L_46 ) ;
V_198 = FALSE ;
return;
}
if ( * V_69 == '!' ) {
V_69 ++ ;
if ( * V_69 == '\0' ) {
V_199 . V_200 = 1 ;
return;
} else if ( * V_69 == '*' ) {
F_3 ( V_201 ) ;
for ( V_197 = 0 ; V_197 < V_202 ; V_197 ++ ) {
V_195 = & V_203 [ V_197 ] ;
V_195 -> V_196 = false ;
}
return;
}
V_196 = false ;
}
for ( V_197 = 0 ; V_197 < V_202 ; V_197 ++ ) {
V_195 = & V_203 [ V_197 ] ;
if ( ! strcmp ( V_195 -> string , V_69 ) ) {
V_195 -> V_196 = V_196 ;
break;
} else if ( V_195 -> string [ 0 ] == '\0' ) {
V_195 -> V_196 = V_196 ;
strncpy ( V_195 -> string , V_69 , V_204 ) ;
break;
}
}
}
static void T_3 F_153 ( unsigned int V_196 )
{
if ( V_199 . V_196 != V_196 )
V_199 . V_196 = V_196 ;
if ( V_199 . V_196 )
F_152 ( L_1 ) ;
else
F_152 ( L_47 ) ;
return;
}
static void T_3 F_154 ( unsigned int V_196 )
{
V_199 . V_205 = 1 ;
V_199 . V_206 = 0 ;
F_153 ( V_196 ) ;
return;
}
void T_3 F_155 ( int V_196 , const struct V_207 * V_208 )
{
F_12 (KERN_NOTICE PREFIX L_48 , d->ident) ;
if ( V_196 == - 1 )
return;
V_199 . V_206 = 1 ;
F_153 ( V_196 ) ;
return;
}
static void T_3 F_156 ( void )
{
struct V_194 * V_195 ;
char * V_69 ;
int V_197 ;
T_11 V_155 ;
if ( V_199 . V_200 ) {
V_155 = F_3 ( V_3 ) ;
if ( F_157 ( V_155 ) )
F_12 (KERN_INFO PREFIX L_49 ) ;
}
for ( V_197 = 0 ; V_197 < V_202 ; V_197 ++ ) {
V_195 = & V_203 [ V_197 ] ;
V_69 = V_195 -> string ;
if ( * V_69 == '\0' )
break;
if ( V_195 -> V_196 ) {
V_155 = F_158 ( V_69 ) ;
if ( F_157 ( V_155 ) )
F_12 (KERN_INFO PREFIX L_50 , str) ;
} else {
V_155 = F_159 ( V_69 ) ;
if ( F_157 ( V_155 ) )
F_12 (KERN_INFO PREFIX L_51 , str) ;
}
}
}
static int T_3 F_160 ( char * V_69 )
{
if ( V_69 && ! strcmp ( L_1 , V_69 ) )
F_154 ( 1 ) ;
else if ( V_69 && ! strcmp ( L_47 , V_69 ) )
F_154 ( 0 ) ;
else
F_152 ( V_69 ) ;
return 1 ;
}
static int T_3 F_161 ( char * V_69 )
{
V_209 = FALSE ;
F_63 ( L_52 ) ;
return 1 ;
}
static int T_3 F_162 ( char * V_69 )
{
if ( V_69 == NULL || * V_69 == '\0' )
return 0 ;
if ( ! strcmp ( L_53 , V_69 ) )
V_210 = V_211 ;
else if ( ! strcmp ( L_54 , V_69 ) )
V_210 = V_212 ;
else if ( ! strcmp ( L_55 , V_69 ) )
V_210 = V_213 ;
return 1 ;
}
int F_163 ( const struct V_214 * V_215 )
{
T_21 V_11 ;
T_7 V_7 ;
T_12 V_216 = 0 ;
int V_217 = 0 ;
if ( V_210 == V_213 )
return 0 ;
if ( ! ( V_215 -> V_218 & V_219 ) && ! ( V_215 -> V_218 & V_220 ) )
return 0 ;
if ( V_215 -> V_218 & V_219 )
V_11 = V_12 ;
else
V_11 = V_13 ;
V_7 = F_164 ( V_215 ) ;
if ( V_210 != V_213 )
V_216 = 1 ;
V_217 = F_165 ( V_11 , V_215 -> V_221 , V_7 , V_216 ) ;
if ( V_217 ) {
if ( V_210 != V_213 ) {
if ( V_210 == V_212 )
F_12 ( V_222 L_56
L_57
L_58 ) ;
F_12 ( V_223 L_59
L_60
L_61 ) ;
}
if ( V_210 == V_211 )
return - V_224 ;
}
return 0 ;
}
int F_166 ( T_22 V_221 , T_22 V_225 ,
const char * V_74 )
{
struct V_214 V_215 = {
. V_221 = V_221 ,
. V_77 = V_221 + V_225 - 1 ,
. V_74 = V_74 ,
. V_218 = V_219 ,
} ;
return F_163 ( & V_215 ) ;
}
int F_167 ( void )
{
return V_210 == V_211 ;
}
bool F_168 ( void )
{
return V_226 >= V_227 ;
}
void F_169 ( T_23 V_173 )
{
F_170 ( V_173 ) ;
}
T_24 F_171 ( T_23 V_228 )
{
T_24 V_218 ;
F_172 ( V_228 , V_218 ) ;
return V_218 ;
}
void F_173 ( T_23 V_228 , T_24 V_218 )
{
F_174 ( V_228 , V_218 ) ;
}
T_11
F_175 ( char * V_74 , V_136 V_45 , V_136 V_229 , T_25 * * V_230 )
{
* V_230 = F_176 ( V_74 , V_45 , 0 , 0 , NULL ) ;
if ( * V_230 == NULL )
return V_146 ;
else
return V_68 ;
}
T_11 F_177 ( T_25 * V_230 )
{
F_178 ( V_230 ) ;
return ( V_68 ) ;
}
T_11 F_179 ( T_25 * V_230 )
{
F_180 ( V_230 ) ;
return ( V_68 ) ;
}
T_11 F_181 ( T_25 * V_230 , void * V_231 )
{
F_182 ( V_230 , V_231 ) ;
return ( V_68 ) ;
}
static int T_3 F_183 ( char * V_232 )
{
V_233 = TRUE ;
F_63 ( L_62 ) ;
return 0 ;
}
static int T_3 F_184 ( char * V_232 )
{
F_12 (KERN_NOTICE PREFIX
L_63 ) ;
V_234 = TRUE ;
return 1 ;
}
T_11 T_3 F_185 ( void )
{
F_53 ( & V_14 . V_15 ) ;
F_53 ( & V_14 . V_17 ) ;
F_53 ( & V_14 . V_26 ) ;
F_53 ( & V_14 . V_28 ) ;
if ( V_14 . V_218 & V_235 ) {
int V_236 ;
V_236 = F_53 ( & V_14 . V_237 ) ;
F_186 ( V_63 L_64 , V_64 , V_236 ) ;
}
V_181 = true ;
return V_68 ;
}
T_11 T_3 F_187 ( void )
{
V_164 = F_188 ( L_65 , 0 , 1 ) ;
V_163 = F_188 ( L_66 , 0 , 1 ) ;
V_170 = F_189 ( L_67 , 0 ) ;
F_139 ( ! V_164 ) ;
F_139 ( ! V_163 ) ;
F_139 ( ! V_170 ) ;
F_190 ( F_1 ) ;
F_156 () ;
return V_68 ;
}
T_11 F_191 ( void )
{
if ( F_78 ) {
F_83 ( V_14 . V_124 ,
F_78 ) ;
}
F_54 ( & V_14 . V_28 ) ;
F_54 ( & V_14 . V_26 ) ;
F_54 ( & V_14 . V_17 ) ;
F_54 ( & V_14 . V_15 ) ;
if ( V_14 . V_218 & V_235 )
F_54 ( & V_14 . V_237 ) ;
F_192 ( V_164 ) ;
F_192 ( V_163 ) ;
F_192 ( V_170 ) ;
return V_68 ;
}
T_11 F_193 ( T_12 V_238 , T_1 V_239 ,
T_1 V_240 )
{
int V_241 = 0 ;
if ( V_242 )
V_241 = V_242 ( V_238 ,
V_239 , V_240 ) ;
if ( V_241 < 0 )
return V_146 ;
else if ( V_241 > 0 )
return V_243 ;
return V_68 ;
}
void F_194 ( int (* F_195)( T_12 V_238 ,
T_1 V_244 , T_1 V_245 ) )
{
V_242 = F_195 ;
}
T_11 F_196 ( T_12 V_238 , T_1 V_246 ,
T_1 V_247 )
{
int V_241 = 0 ;
if ( V_248 )
V_241 = V_248 ( V_238 ,
V_246 , V_247 ) ;
if ( V_241 < 0 )
return V_146 ;
else if ( V_241 > 0 )
return V_243 ;
return V_68 ;
}
void F_197 ( int (* F_195)( T_12 V_238 ,
T_1 V_246 , T_1 V_247 ) )
{
V_248 = F_195 ;
}
