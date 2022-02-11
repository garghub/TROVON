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
if ( F_13 ( V_30 ) < 0 )
F_12 ( V_32 L_17 , V_30 ) ;
#endif
}
static int T_3 F_14 ( char * V_33 )
{
if ( F_15 ( V_33 , 16 , & V_34 ) )
return - V_35 ;
return 0 ;
}
T_6 T_3 F_16 ( void )
{
#ifdef F_17
if ( V_34 )
return V_34 ;
#endif
if ( F_18 ( V_36 ) ) {
if ( V_37 . V_38 != V_39 )
return V_37 . V_38 ;
else if ( V_37 . V_40 != V_39 )
return V_37 . V_40 ;
else {
F_12 (KERN_ERR PREFIX
L_18 ) ;
return 0 ;
}
} else if ( F_19 ( V_41 ) ) {
T_6 V_42 = 0 ;
F_20 ( & V_42 ) ;
return V_42 ;
}
return 0 ;
}
static struct V_43 *
F_21 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_22 (map, &acpi_ioremaps, list)
if ( V_46 -> V_44 <= V_44 &&
V_44 + V_45 <= V_46 -> V_44 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 *
F_23 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 )
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
return NULL ;
}
void T_8 * F_24 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 = NULL ;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_47 = V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
V_46 -> V_49 ++ ;
}
F_26 ( & V_48 ) ;
return V_47 ;
}
static struct V_43 *
F_27 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_22 (map, &acpi_ioremaps, list)
if ( V_46 -> V_47 <= V_47 &&
V_47 + V_45 <= V_46 -> V_47 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 * F_28 ( T_6 V_50 , unsigned long V_51 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_29 ( V_52 ) ) {
if ( V_51 > V_54 )
return NULL ;
return ( void T_8 V_55 * ) F_30 ( F_31 ( V_52 ) ) ;
} else
return F_32 ( V_50 , V_51 ) ;
}
static void F_33 ( T_6 V_50 , void T_8 * V_56 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_29 ( V_52 ) )
F_34 ( F_31 ( V_52 ) ) ;
else
F_35 ( V_56 ) ;
}
void T_8 * T_9
F_36 ( T_6 V_44 , T_7 V_45 )
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
return F_37 ( ( unsigned long ) V_44 , V_45 ) ;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_46 -> V_49 ++ ;
goto V_59;
}
V_46 = F_38 ( sizeof( * V_46 ) , V_60 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
return NULL ;
}
V_50 = F_39 ( V_44 , V_54 ) ;
V_51 = F_40 ( V_44 + V_45 , V_54 ) - V_50 ;
V_47 = F_28 ( V_50 , V_51 ) ;
if ( ! V_47 ) {
F_26 ( & V_48 ) ;
F_41 ( V_46 ) ;
return NULL ;
}
F_42 ( & V_46 -> V_61 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_44 = V_50 ;
V_46 -> V_45 = V_51 ;
V_46 -> V_49 = 1 ;
F_43 ( & V_46 -> V_61 , & V_62 ) ;
V_59:
F_26 ( & V_48 ) ;
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
}
void * T_9
F_44 ( T_6 V_44 , T_7 V_45 )
{
return ( void * ) F_36 ( V_44 , V_45 ) ;
}
static void F_45 ( struct V_43 * V_46 )
{
if ( ! -- V_46 -> V_49 )
F_46 ( & V_46 -> V_61 ) ;
}
static void F_47 ( struct V_43 * V_46 )
{
if ( ! V_46 -> V_49 ) {
F_48 () ;
F_33 ( V_46 -> V_44 , V_46 -> V_47 ) ;
F_41 ( V_46 ) ;
}
}
void T_10 F_49 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
if ( ! V_58 ) {
F_50 ( V_47 , V_45 ) ;
return;
}
F_25 ( & V_48 ) ;
V_46 = F_27 ( V_47 , V_45 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
F_51 ( true , V_63 L_20 , V_64 , V_47 ) ;
return;
}
F_45 ( V_46 ) ;
F_26 ( & V_48 ) ;
F_47 ( V_46 ) ;
}
void T_10 F_52 ( void * V_47 , T_7 V_45 )
{
return F_49 ( ( void T_8 * ) V_47 , V_45 ) ;
}
void T_3 F_53 ( void T_8 * V_47 , T_7 V_45 )
{
if ( ! V_58 )
F_50 ( V_47 , V_45 ) ;
}
int F_54 ( struct V_5 * V_6 )
{
T_4 V_9 ;
void T_8 * V_47 ;
if ( V_6 -> V_11 != V_13 )
return 0 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return - V_35 ;
V_47 = F_36 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_47 )
return - V_66 ;
return 0 ;
}
void F_55 ( struct V_5 * V_6 )
{
T_4 V_9 ;
struct V_43 * V_46 ;
if ( V_6 -> V_11 != V_13 )
return;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
return;
}
F_45 ( V_46 ) ;
F_26 ( & V_48 ) ;
F_47 ( V_46 ) ;
}
T_11
F_56 ( void * V_47 , T_6 * V_44 )
{
if ( ! V_44 || ! V_47 )
return V_67 ;
* V_44 = F_57 ( V_47 ) ;
return V_68 ;
}
int T_3 F_58 ( char * V_69 )
{
V_70 = true ;
return 1 ;
}
T_11
F_59 ( const struct V_71 * V_72 ,
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
static T_12 T_3 F_60 ( T_12 * V_30 , T_1 V_7 )
{
T_12 V_76 = 0 ;
T_12 * V_77 = V_30 + V_7 ;
while ( V_30 < V_77 )
V_76 = ( T_12 ) ( V_76 + * ( V_30 ++ ) ) ;
return V_76 ;
}
void T_3 F_61 ( void * V_78 , T_13 V_45 )
{
int V_79 , V_80 , V_81 = 0 , V_82 = 0 ;
long V_83 = 0 ;
struct V_84 * V_85 ;
char V_86 [ 32 ] = L_25 ;
struct V_87 V_88 ;
if ( V_78 == NULL || V_45 == 0 )
return;
for ( V_80 = 0 ; V_80 < V_89 ; V_80 ++ ) {
V_88 = F_62 ( V_86 , V_78 , V_45 , & V_83 ) ;
if ( ! V_88 . V_78 )
break;
V_78 += V_83 ;
V_45 -= V_83 ;
if ( V_88 . V_45 < sizeof( struct V_84 ) ) {
F_63 ( L_26 ,
V_86 , V_88 . V_74 ) ;
continue;
}
V_85 = V_88 . V_78 ;
for ( V_79 = 0 ; V_90 [ V_79 ] ; V_79 ++ )
if ( ! memcmp ( V_85 -> V_91 , V_90 [ V_79 ] , 4 ) )
break;
if ( ! V_90 [ V_79 ] ) {
F_63 ( L_27 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( V_88 . V_45 != V_85 -> V_7 ) {
F_63 ( L_28 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( F_60 ( V_88 . V_78 , V_85 -> V_7 ) ) {
F_63 ( L_29 ,
V_86 , V_88 . V_74 ) ;
continue;
}
F_64 ( L_30 ,
V_85 -> V_91 , V_86 , V_88 . V_74 , V_85 -> V_7 ) ;
V_92 += V_85 -> V_7 ;
V_93 [ V_81 ] . V_78 = V_88 . V_78 ;
V_93 [ V_81 ] . V_45 = V_88 . V_45 ;
V_81 ++ ;
}
if ( V_81 == 0 )
return;
V_94 =
F_65 ( 0 , V_95 << V_53 ,
V_92 , V_54 ) ;
if ( ! V_94 ) {
F_66 ( 1 ) ;
return;
}
F_67 ( V_94 , V_92 ) ;
F_68 ( V_94 , V_92 ) ;
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
V_100 = F_69 ( V_97 & V_101 ,
V_99 + V_98 ) ;
memcpy ( V_100 + V_98 , V_96 , V_99 ) ;
F_70 ( V_100 , V_99 + V_98 ) ;
V_96 += V_99 ;
V_97 += V_99 ;
V_45 -= V_99 ;
}
}
}
static void F_71 ( struct V_84 * V_85 )
{
F_72 ( V_63
L_31 ,
V_85 -> V_91 , V_85 -> V_103 ) ;
F_73 ( V_104 , V_105 ) ;
}
T_11
F_74 ( struct V_84 * V_106 ,
struct V_84 * * V_107 )
{
if ( ! V_106 || ! V_107 )
return V_67 ;
* V_107 = NULL ;
#ifdef F_75
if ( strncmp ( V_106 -> V_91 , L_32 , 4 ) == 0 )
* V_107 = (struct V_84 * ) V_108 ;
#endif
if ( * V_107 != NULL )
F_71 ( V_106 ) ;
return V_68 ;
}
T_11
F_76 ( struct V_84 * V_106 ,
T_6 * V_10 ,
T_1 * V_109 )
{
#ifndef F_77
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
F_66 ( 1 ) ;
return V_68 ;
}
V_85 = F_44 ( V_94 + V_110 ,
V_111 ) ;
if ( V_110 + V_85 -> V_7 > V_92 ) {
F_52 ( V_85 , V_111 ) ;
F_66 ( 1 ) ;
return V_68 ;
}
V_110 += V_85 -> V_7 ;
if ( memcmp ( V_106 -> V_91 , V_85 -> V_91 , 4 ) ) {
F_52 ( V_85 ,
V_111 ) ;
continue;
}
if ( memcmp ( V_85 -> V_103 , V_106 -> V_103 ,
V_112 ) ) {
F_52 ( V_85 ,
V_111 ) ;
continue;
}
V_110 -= V_85 -> V_7 ;
* V_109 = V_85 -> V_7 ;
F_52 ( V_85 , V_111 ) ;
* V_10 = V_94 + V_110 ;
break;
} while ( V_110 + V_111 < V_92 );
if ( * V_10 != 0 )
F_71 ( V_106 ) ;
return V_68 ;
#endif
}
static T_15 F_78 ( int V_113 , void * V_114 )
{
T_1 V_115 ;
V_115 = (* F_79) ( V_116 ) ;
if ( V_115 ) {
V_117 ++ ;
return V_118 ;
} else {
V_119 ++ ;
return V_120 ;
}
}
T_11
F_80 ( T_1 V_121 , T_16 V_122 ,
void * V_123 )
{
unsigned int V_113 ;
F_81 () ;
if ( V_121 != V_14 . V_124 )
return V_67 ;
if ( F_79 )
return V_125 ;
if ( F_82 ( V_121 , & V_113 ) < 0 ) {
F_12 (KERN_ERR PREFIX L_33 ,
gsi) ;
return V_68 ;
}
F_79 = V_122 ;
V_116 = V_123 ;
if ( F_83 ( V_113 , F_78 , V_126 , L_34 , F_78 ) ) {
F_12 (KERN_ERR PREFIX L_35 , irq) ;
F_79 = NULL ;
return V_127 ;
}
V_128 = V_113 ;
return V_68 ;
}
T_11 F_84 ( T_1 V_121 , T_16 V_122 )
{
if ( V_121 != V_14 . V_124 || ! F_85 () )
return V_67 ;
F_86 ( V_128 , F_78 ) ;
F_79 = NULL ;
V_128 = V_129 ;
return V_68 ;
}
void F_87 ( T_4 V_130 )
{
F_88 ( V_130 ) ;
}
void F_89 ( T_1 V_131 )
{
while ( V_131 ) {
T_1 V_132 = 1000 ;
if ( V_132 > V_131 )
V_132 = V_131 ;
F_90 ( V_132 ) ;
F_91 () ;
V_131 -= V_132 ;
}
}
T_4 F_92 ( void )
{
T_4 V_133 = F_93 ( F_94 () ) ;
F_95 ( V_133 , 100 ) ;
return V_133 ;
}
T_11 F_96 ( T_17 V_134 , T_1 * V_135 , T_1 V_136 )
{
T_1 V_137 ;
if ( ! V_135 )
V_135 = & V_137 ;
* V_135 = 0 ;
if ( V_136 <= 8 ) {
* ( T_12 * ) V_135 = F_97 ( V_134 ) ;
} else if ( V_136 <= 16 ) {
* ( V_138 * ) V_135 = F_98 ( V_134 ) ;
} else if ( V_136 <= 32 ) {
* ( T_1 * ) V_135 = F_99 ( V_134 ) ;
} else {
F_100 () ;
}
return V_68 ;
}
T_11 F_101 ( T_17 V_134 , T_1 V_135 , T_1 V_136 )
{
if ( V_136 <= 8 ) {
F_102 ( V_135 , V_134 ) ;
} else if ( V_136 <= 16 ) {
F_103 ( V_135 , V_134 ) ;
} else if ( V_136 <= 32 ) {
F_104 ( V_135 , V_134 ) ;
} else {
F_100 () ;
}
return V_68 ;
}
T_11
F_105 ( T_6 V_139 , T_4 * V_135 , T_1 V_136 )
{
void T_8 * V_140 ;
unsigned int V_45 = V_136 / 8 ;
bool V_141 = false ;
T_4 V_137 ;
F_106 () ;
V_140 = F_23 ( V_139 , V_45 ) ;
if ( ! V_140 ) {
F_107 () ;
V_140 = F_32 ( V_139 , V_45 ) ;
if ( ! V_140 )
return V_142 ;
V_141 = true ;
}
if ( ! V_135 )
V_135 = & V_137 ;
switch ( V_136 ) {
case 8 :
* ( T_12 * ) V_135 = F_108 ( V_140 ) ;
break;
case 16 :
* ( V_138 * ) V_135 = F_109 ( V_140 ) ;
break;
case 32 :
* ( T_1 * ) V_135 = F_110 ( V_140 ) ;
break;
case 64 :
* ( T_4 * ) V_135 = F_111 ( V_140 ) ;
break;
default:
F_100 () ;
}
if ( V_141 )
F_35 ( V_140 ) ;
else
F_107 () ;
return V_68 ;
}
T_11
F_112 ( T_6 V_139 , T_4 V_135 , T_1 V_136 )
{
void T_8 * V_140 ;
unsigned int V_45 = V_136 / 8 ;
bool V_141 = false ;
F_106 () ;
V_140 = F_23 ( V_139 , V_45 ) ;
if ( ! V_140 ) {
F_107 () ;
V_140 = F_32 ( V_139 , V_45 ) ;
if ( ! V_140 )
return V_142 ;
V_141 = true ;
}
switch ( V_136 ) {
case 8 :
F_113 ( V_135 , V_140 ) ;
break;
case 16 :
F_114 ( V_135 , V_140 ) ;
break;
case 32 :
F_115 ( V_135 , V_140 ) ;
break;
case 64 :
F_116 ( V_135 , V_140 ) ;
break;
default:
F_100 () ;
}
if ( V_141 )
F_35 ( V_140 ) ;
else
F_107 () ;
return V_68 ;
}
T_11
F_117 ( struct V_143 * V_144 , T_1 V_145 ,
T_4 * V_135 , T_1 V_136 )
{
int V_146 , V_45 ;
T_1 V_147 ;
if ( ! V_135 )
return V_67 ;
switch ( V_136 ) {
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
return V_148 ;
}
V_146 = F_118 ( V_144 -> V_149 , V_144 -> V_150 ,
F_119 ( V_144 -> V_151 , V_144 -> V_152 ) ,
V_145 , V_45 , & V_147 ) ;
* V_135 = V_147 ;
return ( V_146 ? V_148 : V_68 ) ;
}
T_11
F_120 ( struct V_143 * V_144 , T_1 V_145 ,
T_4 V_135 , T_1 V_136 )
{
int V_146 , V_45 ;
switch ( V_136 ) {
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
return V_148 ;
}
V_146 = F_121 ( V_144 -> V_149 , V_144 -> V_150 ,
F_119 ( V_144 -> V_151 , V_144 -> V_152 ) ,
V_145 , V_45 , V_135 ) ;
return ( V_146 ? V_148 : V_68 ) ;
}
static void F_122 ( struct V_153 * V_154 )
{
struct V_155 * V_156 = F_123 ( V_154 , struct V_155 , V_154 ) ;
V_156 -> V_152 ( V_156 -> V_123 ) ;
F_41 ( V_156 ) ;
}
int F_124 ( struct V_157 * V_158 ,
const struct V_159 * V_160 )
{
int V_161 = 0 ;
F_25 ( & V_162 . V_163 ) ;
if ( V_162 . V_160 ) {
V_161 = - V_164 ;
goto V_165;
}
V_162 . V_158 = V_158 ;
V_162 . V_160 = V_160 ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
void F_125 ( const struct V_159 * V_160 )
{
F_25 ( & V_162 . V_163 ) ;
if ( V_160 == V_162 . V_160 ) {
V_162 . V_160 = NULL ;
V_162 . V_158 = NULL ;
}
F_26 ( & V_162 . V_163 ) ;
}
int F_126 ( T_18 V_152 , void * V_123 )
{
int V_161 ;
int (* F_127)( T_18 , void * );
struct V_157 * V_158 ;
if ( ! V_166 )
return - V_167 ;
F_25 ( & V_162 . V_163 ) ;
if ( ! V_162 . V_160 ) {
V_161 = - V_167 ;
goto V_165;
}
if ( ! F_128 ( V_162 . V_158 ) ) {
V_161 = - V_167 ;
goto V_165;
}
F_127 = V_162 . V_160 -> V_168 ;
V_158 = V_162 . V_158 ;
F_26 ( & V_162 . V_163 ) ;
V_161 = F_127 ( V_152 , V_123 ) ;
F_25 ( & V_162 . V_163 ) ;
F_129 ( V_158 ) ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
T_19 F_13 ( const char * V_169 )
{
T_19 V_161 ;
T_19 (* F_127)( const char * );
struct V_157 * V_158 ;
if ( ! V_166 )
return - V_167 ;
F_25 ( & V_162 . V_163 ) ;
if ( ! V_162 . V_160 ) {
V_161 = - V_167 ;
goto V_165;
}
if ( ! F_128 ( V_162 . V_158 ) ) {
V_161 = - V_167 ;
goto V_165;
}
F_127 = V_162 . V_160 -> V_170 ;
V_158 = V_162 . V_158 ;
F_26 ( & V_162 . V_163 ) ;
V_161 = F_127 ( V_169 ) ;
F_25 ( & V_162 . V_163 ) ;
F_129 ( V_158 ) ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
T_19 F_130 ( char * V_30 , T_13 V_171 )
{
T_19 V_161 ;
T_19 (* F_127)( char * , T_13 );
struct V_157 * V_158 ;
if ( ! V_166 )
return - V_167 ;
F_25 ( & V_162 . V_163 ) ;
if ( ! V_162 . V_160 ) {
V_161 = - V_167 ;
goto V_165;
}
if ( ! F_128 ( V_162 . V_158 ) ) {
V_161 = - V_167 ;
goto V_165;
}
F_127 = V_162 . V_160 -> V_172 ;
V_158 = V_162 . V_158 ;
F_26 ( & V_162 . V_163 ) ;
V_161 = F_127 ( V_30 , V_171 ) ;
F_25 ( & V_162 . V_163 ) ;
F_129 ( V_158 ) ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
int F_131 ( void )
{
int V_161 ;
int (* F_127)( bool , char * , T_13 );
struct V_157 * V_158 ;
if ( ! V_166 )
return - V_167 ;
F_25 ( & V_162 . V_163 ) ;
if ( ! V_162 . V_160 ) {
V_161 = - V_167 ;
goto V_165;
}
if ( ! F_128 ( V_162 . V_158 ) ) {
V_161 = - V_167 ;
goto V_165;
}
F_127 = V_162 . V_160 -> V_173 ;
V_158 = V_162 . V_158 ;
F_26 ( & V_162 . V_163 ) ;
V_161 = F_127 ( V_174 ,
V_175 , V_176 ) ;
F_25 ( & V_162 . V_163 ) ;
F_129 ( V_158 ) ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
int F_132 ( void )
{
int V_161 ;
int (* F_127)( void );
struct V_157 * V_158 ;
if ( ! V_166 )
return - V_167 ;
F_25 ( & V_162 . V_163 ) ;
if ( ! V_162 . V_160 ) {
V_161 = - V_167 ;
goto V_165;
}
if ( ! F_128 ( V_162 . V_158 ) ) {
V_161 = - V_167 ;
goto V_165;
}
F_127 = V_162 . V_160 -> V_177 ;
V_158 = V_162 . V_158 ;
F_26 ( & V_162 . V_163 ) ;
V_161 = F_127 () ;
F_25 ( & V_162 . V_163 ) ;
F_129 ( V_158 ) ;
V_165:
F_26 ( & V_162 . V_163 ) ;
return V_161 ;
}
int T_3 F_133 ( void )
{
F_134 ( & V_162 . V_163 ) ;
V_166 = true ;
return 0 ;
}
T_11 F_135 ( T_20 type ,
T_18 V_152 , void * V_123 )
{
T_11 V_178 = V_68 ;
struct V_155 * V_156 ;
struct V_179 * V_180 ;
int V_161 ;
F_136 ( ( V_181 ,
L_36 ,
V_152 , V_123 ) ) ;
if ( type == V_182 ) {
V_161 = F_126 ( V_152 , V_123 ) ;
if ( V_161 ) {
F_63 ( L_37 ) ;
V_178 = V_148 ;
}
goto V_183;
}
V_156 = F_38 ( sizeof( struct V_155 ) , V_184 ) ;
if ( ! V_156 )
return V_185 ;
V_156 -> V_152 = V_152 ;
V_156 -> V_123 = V_123 ;
if ( type == V_186 ) {
V_180 = V_187 ;
F_137 ( & V_156 -> V_154 , F_122 ) ;
} else if ( type == V_188 ) {
V_180 = V_189 ;
F_137 ( & V_156 -> V_154 , F_122 ) ;
} else {
F_63 ( L_38 , type ) ;
V_178 = V_148 ;
}
if ( F_138 ( V_178 ) )
goto V_190;
V_161 = F_139 ( 0 , V_180 , & V_156 -> V_154 ) ;
if ( ! V_161 ) {
F_12 (KERN_ERR PREFIX
L_39 ) ;
V_178 = V_148 ;
}
V_190:
if ( F_138 ( V_178 ) )
F_41 ( V_156 ) ;
V_183:
return V_178 ;
}
void F_140 ( void )
{
if ( F_85 () )
F_141 ( V_128 ) ;
F_142 ( V_189 ) ;
F_142 ( V_187 ) ;
}
static void F_143 ( struct V_153 * V_154 )
{
struct V_191 * V_192 = F_123 ( V_154 , struct V_191 , V_154 ) ;
F_140 () ;
F_144 ( V_192 -> V_193 , V_192 -> V_194 ) ;
F_41 ( V_192 ) ;
}
T_11 F_145 ( struct V_195 * V_193 , T_1 V_194 )
{
struct V_191 * V_192 ;
F_136 ( ( V_181 ,
L_40 ,
V_193 , V_194 ) ) ;
V_192 = F_146 ( sizeof( * V_192 ) , V_60 ) ;
if ( ! V_192 )
return V_185 ;
F_137 ( & V_192 -> V_154 , F_143 ) ;
V_192 -> V_193 = V_193 ;
V_192 -> V_194 = V_194 ;
if ( ! F_147 ( V_196 , & V_192 -> V_154 ) ) {
F_41 ( V_192 ) ;
return V_148 ;
}
return V_68 ;
}
bool F_148 ( struct V_153 * V_154 )
{
return F_147 ( V_196 , V_154 ) ;
}
T_11
F_149 ( T_1 V_197 , T_1 V_198 , T_21 * V_199 )
{
struct V_200 * V_201 = NULL ;
V_201 = F_150 ( sizeof( struct V_200 ) ) ;
if ( ! V_201 )
return V_185 ;
F_151 ( V_201 , V_198 ) ;
* V_199 = ( T_21 * ) V_201 ;
F_136 ( ( V_202 , L_41 ,
* V_199 , V_198 ) ) ;
return V_68 ;
}
T_11 F_152 ( T_21 V_199 )
{
struct V_200 * V_201 = (struct V_200 * ) V_199 ;
if ( ! V_201 )
return V_67 ;
F_136 ( ( V_202 , L_42 , V_199 ) ) ;
F_153 ( ! F_154 ( & V_201 -> V_203 ) ) ;
F_41 ( V_201 ) ;
V_201 = NULL ;
return V_68 ;
}
T_11 F_155 ( T_21 V_199 , T_1 V_204 , V_138 V_205 )
{
T_11 V_178 = V_68 ;
struct V_200 * V_201 = (struct V_200 * ) V_199 ;
long V_206 ;
int V_161 = 0 ;
if ( ! V_207 )
return V_68 ;
if ( ! V_201 || ( V_204 < 1 ) )
return V_67 ;
if ( V_204 > 1 )
return V_208 ;
F_136 ( ( V_202 , L_43 ,
V_199 , V_204 , V_205 ) ) ;
if ( V_205 == V_209 )
V_206 = V_210 ;
else
V_206 = F_156 ( V_205 ) ;
V_161 = F_157 ( V_201 , V_206 ) ;
if ( V_161 )
V_178 = V_211 ;
if ( F_138 ( V_178 ) ) {
F_136 ( ( V_202 ,
L_44 ,
V_199 , V_204 , V_205 ,
F_158 ( V_178 ) ) ) ;
} else {
F_136 ( ( V_202 ,
L_45 , V_199 ,
V_204 , V_205 ) ) ;
}
return V_178 ;
}
T_11 F_159 ( T_21 V_199 , T_1 V_204 )
{
struct V_200 * V_201 = (struct V_200 * ) V_199 ;
if ( ! V_207 )
return V_68 ;
if ( ! V_201 || ( V_204 < 1 ) )
return V_67 ;
if ( V_204 > 1 )
return V_208 ;
F_136 ( ( V_202 , L_46 , V_199 ,
V_204 ) ) ;
F_160 ( V_201 ) ;
return V_68 ;
}
T_11 F_161 ( char * V_30 , T_1 V_171 , T_1 * V_212 )
{
#ifdef F_10
if ( V_31 ) {
T_1 V_213 ;
F_162 ( V_30 , V_171 ) ;
V_213 = strlen ( V_30 ) - 1 ;
V_30 [ V_213 ] = '\0' ;
}
#else
int V_161 ;
V_161 = F_130 ( V_30 , V_171 ) ;
if ( V_161 < 0 )
return V_148 ;
if ( V_212 )
* V_212 = V_161 ;
#endif
return V_68 ;
}
T_11 F_163 ( void )
{
int V_161 ;
V_161 = F_131 () ;
if ( V_161 < 0 )
return V_148 ;
return V_68 ;
}
T_11 F_164 ( void )
{
int V_161 ;
V_161 = F_132 () ;
if ( V_161 < 0 )
return V_148 ;
return V_68 ;
}
T_11 F_165 ( T_1 V_152 , void * V_214 )
{
switch ( V_152 ) {
case V_215 :
F_12 (KERN_ERR PREFIX L_47 ) ;
break;
case V_216 :
break;
default:
break;
}
return V_68 ;
}
static int T_3 F_166 ( char * V_69 )
{
char * V_217 = V_75 ;
int V_218 = V_219 - 1 ;
if ( ! V_69 || ! * V_69 )
return 0 ;
for (; V_218 -- && * V_69 ; V_69 ++ ) {
if ( isalnum ( * V_69 ) || * V_69 == ' ' || * V_69 == ':' )
* V_217 ++ = * V_69 ;
else if ( * V_69 == '\'' || * V_69 == '"' )
continue;
else
break;
}
* V_217 = 0 ;
return 1 ;
}
void T_3 F_167 ( char * V_69 )
{
struct V_220 * V_221 ;
bool V_222 = true ;
int V_223 ;
if ( ! V_224 )
return;
if ( V_69 == NULL || * V_69 == '\0' ) {
F_12 (KERN_INFO PREFIX L_48 ) ;
V_224 = FALSE ;
return;
}
if ( * V_69 == '!' ) {
V_69 ++ ;
if ( * V_69 == '\0' ) {
V_225 . V_226 = 1 ;
return;
} else if ( * V_69 == '*' ) {
F_3 ( V_227 ) ;
for ( V_223 = 0 ; V_223 < V_228 ; V_223 ++ ) {
V_221 = & V_229 [ V_223 ] ;
V_221 -> V_222 = false ;
}
return;
}
V_222 = false ;
}
for ( V_223 = 0 ; V_223 < V_228 ; V_223 ++ ) {
V_221 = & V_229 [ V_223 ] ;
if ( ! strcmp ( V_221 -> string , V_69 ) ) {
V_221 -> V_222 = V_222 ;
break;
} else if ( V_221 -> string [ 0 ] == '\0' ) {
V_221 -> V_222 = V_222 ;
strncpy ( V_221 -> string , V_69 , V_230 ) ;
break;
}
}
}
static void T_3 F_168 ( unsigned int V_222 )
{
if ( V_225 . V_222 != V_222 )
V_225 . V_222 = V_222 ;
if ( V_225 . V_222 )
F_167 ( L_1 ) ;
else
F_167 ( L_49 ) ;
return;
}
static void T_3 F_169 ( unsigned int V_222 )
{
V_225 . V_231 = 1 ;
V_225 . V_232 = 0 ;
F_168 ( V_222 ) ;
return;
}
void T_3 F_170 ( int V_222 , const struct V_233 * V_234 )
{
F_12 (KERN_NOTICE PREFIX L_50 , d->ident) ;
if ( V_222 == - 1 )
return;
V_225 . V_232 = 1 ;
F_168 ( V_222 ) ;
return;
}
static void T_3 F_171 ( void )
{
struct V_220 * V_221 ;
char * V_69 ;
int V_223 ;
T_11 V_178 ;
if ( V_225 . V_226 ) {
V_178 = F_3 ( V_3 ) ;
if ( F_172 ( V_178 ) )
F_12 (KERN_INFO PREFIX L_51 ) ;
}
for ( V_223 = 0 ; V_223 < V_228 ; V_223 ++ ) {
V_221 = & V_229 [ V_223 ] ;
V_69 = V_221 -> string ;
if ( * V_69 == '\0' )
break;
if ( V_221 -> V_222 ) {
V_178 = F_173 ( V_69 ) ;
if ( F_172 ( V_178 ) )
F_12 (KERN_INFO PREFIX L_52 , str) ;
} else {
V_178 = F_174 ( V_69 ) ;
if ( F_172 ( V_178 ) )
F_12 (KERN_INFO PREFIX L_53 , str) ;
}
}
}
static int T_3 F_175 ( char * V_69 )
{
if ( V_69 && ! strcmp ( L_1 , V_69 ) )
F_169 ( 1 ) ;
else if ( V_69 && ! strcmp ( L_49 , V_69 ) )
F_169 ( 0 ) ;
else
F_167 ( V_69 ) ;
return 1 ;
}
static int T_3 F_176 ( char * V_69 )
{
V_235 = FALSE ;
F_64 ( L_54 ) ;
return 1 ;
}
static int T_3 F_177 ( char * V_69 )
{
if ( V_69 == NULL || * V_69 == '\0' )
return 0 ;
if ( ! strcmp ( L_55 , V_69 ) )
V_236 = V_237 ;
else if ( ! strcmp ( L_56 , V_69 ) )
V_236 = V_238 ;
else if ( ! strcmp ( L_57 , V_69 ) )
V_236 = V_239 ;
return 1 ;
}
int F_178 ( const struct V_240 * V_241 )
{
T_22 V_11 ;
T_7 V_7 ;
T_12 V_242 = 0 ;
int V_243 = 0 ;
if ( V_236 == V_239 )
return 0 ;
if ( ! ( V_241 -> V_244 & V_245 ) && ! ( V_241 -> V_244 & V_246 ) )
return 0 ;
if ( V_241 -> V_244 & V_245 )
V_11 = V_12 ;
else
V_11 = V_13 ;
V_7 = F_179 ( V_241 ) ;
if ( V_236 != V_239 )
V_242 = 1 ;
V_243 = F_180 ( V_11 , V_241 -> V_247 , V_7 , V_242 ) ;
if ( V_243 ) {
if ( V_236 != V_239 ) {
if ( V_236 == V_238 )
F_12 ( V_248 L_58
L_59
L_60 ) ;
F_12 ( V_249 L_61
L_62
L_63 ) ;
}
if ( V_236 == V_237 )
return - V_164 ;
}
return 0 ;
}
int F_181 ( T_23 V_247 , T_23 V_250 ,
const char * V_74 )
{
struct V_240 V_241 = {
. V_247 = V_247 ,
. V_77 = V_247 + V_250 - 1 ,
. V_74 = V_74 ,
. V_244 = V_245 ,
} ;
return F_178 ( & V_241 ) ;
}
int F_182 ( void )
{
return V_236 == V_237 ;
}
bool F_183 ( void )
{
return V_251 >= V_252 ;
}
void F_184 ( T_24 V_199 )
{
F_185 ( V_199 ) ;
}
T_25 F_186 ( T_24 V_253 )
{
T_25 V_244 ;
F_187 ( V_253 , V_244 ) ;
return V_244 ;
}
void F_188 ( T_24 V_253 , T_25 V_244 )
{
F_189 ( V_253 , V_244 ) ;
}
T_11
F_190 ( char * V_74 , V_138 V_45 , V_138 V_254 , T_26 * * V_255 )
{
* V_255 = F_191 ( V_74 , V_45 , 0 , 0 , NULL ) ;
if ( * V_255 == NULL )
return V_148 ;
else
return V_68 ;
}
T_11 F_192 ( T_26 * V_255 )
{
F_193 ( V_255 ) ;
return ( V_68 ) ;
}
T_11 F_194 ( T_26 * V_255 )
{
F_195 ( V_255 ) ;
return ( V_68 ) ;
}
T_11 F_196 ( T_26 * V_255 , void * V_256 )
{
F_197 ( V_255 , V_256 ) ;
return ( V_68 ) ;
}
static int T_3 F_198 ( char * V_257 )
{
V_258 = TRUE ;
F_64 ( L_64 ) ;
return 0 ;
}
static int T_3 F_199 ( char * V_257 )
{
F_12 (KERN_NOTICE PREFIX
L_65 ) ;
V_259 = TRUE ;
return 1 ;
}
T_11 T_3 F_200 ( void )
{
F_54 ( & V_14 . V_15 ) ;
F_54 ( & V_14 . V_17 ) ;
F_54 ( & V_14 . V_26 ) ;
F_54 ( & V_14 . V_28 ) ;
if ( V_14 . V_244 & V_260 ) {
int V_261 ;
V_261 = F_54 ( & V_14 . V_262 ) ;
F_201 ( V_63 L_66 , V_64 , V_261 ) ;
}
V_207 = true ;
return V_68 ;
}
T_11 T_3 F_202 ( void )
{
V_189 = F_203 ( L_67 , 0 , 1 ) ;
V_187 = F_203 ( L_68 , 0 , 1 ) ;
V_196 = F_204 ( L_69 , 0 ) ;
F_153 ( ! V_189 ) ;
F_153 ( ! V_187 ) ;
F_153 ( ! V_196 ) ;
F_205 ( F_1 ) ;
F_171 () ;
return V_68 ;
}
T_11 F_206 ( void )
{
if ( F_79 ) {
F_84 ( V_14 . V_124 ,
F_79 ) ;
}
F_55 ( & V_14 . V_28 ) ;
F_55 ( & V_14 . V_26 ) ;
F_55 ( & V_14 . V_17 ) ;
F_55 ( & V_14 . V_15 ) ;
if ( V_14 . V_244 & V_260 )
F_55 ( & V_14 . V_262 ) ;
F_207 ( V_189 ) ;
F_207 ( V_187 ) ;
F_207 ( V_196 ) ;
return V_68 ;
}
T_11 F_208 ( T_12 V_263 , T_1 V_264 ,
T_1 V_265 )
{
int V_266 = 0 ;
if ( V_267 )
V_266 = V_267 ( V_263 ,
V_264 , V_265 ) ;
if ( V_266 < 0 )
return V_148 ;
else if ( V_266 > 0 )
return V_268 ;
return V_68 ;
}
void F_209 ( int (* F_127)( T_12 V_263 ,
T_1 V_269 , T_1 V_270 ) )
{
V_267 = F_127 ;
}
T_11 F_210 ( T_12 V_263 , T_1 V_271 ,
T_1 V_272 )
{
int V_266 = 0 ;
if ( V_273 )
V_266 = V_273 ( V_263 ,
V_271 , V_272 ) ;
if ( V_266 < 0 )
return V_148 ;
else if ( V_266 > 0 )
return V_268 ;
return V_68 ;
}
void F_211 ( int (* F_127)( T_12 V_263 ,
T_1 V_271 , T_1 V_272 ) )
{
V_273 = F_127 ;
}
