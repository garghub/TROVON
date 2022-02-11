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
if ( F_16 ( V_33 ) ) {
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
F_17 ( & V_38 ) ;
return V_38 ;
}
}
static struct V_39 *
F_18 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 *
F_20 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_8 * F_21 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 = NULL ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_43 = V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
V_42 -> V_45 ++ ;
}
F_23 ( & V_44 ) ;
return V_43 ;
}
static struct V_39 *
F_24 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 * F_25 ( T_6 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_8 V_51 * ) F_27 ( F_28 ( V_48 ) ) ;
} else
return F_29 ( V_46 , V_47 ) ;
}
static void F_30 ( T_6 V_46 , void T_8 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) )
F_31 ( F_28 ( V_48 ) ) ;
else
F_32 ( V_52 ) ;
}
void T_8 * T_9
F_33 ( T_6 V_40 , T_7 V_41 )
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
return F_34 ( ( unsigned long ) V_40 , V_41 ) ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_45 ++ ;
goto V_55;
}
V_42 = F_35 ( sizeof( * V_42 ) , V_56 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return NULL ;
}
V_46 = F_36 ( V_40 , V_50 ) ;
V_47 = F_37 ( V_40 + V_41 , V_50 ) - V_46 ;
V_43 = F_25 ( V_46 , V_47 ) ;
if ( ! V_43 ) {
F_23 ( & V_44 ) ;
F_38 ( V_42 ) ;
return NULL ;
}
F_39 ( & V_42 -> V_57 ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_40 = V_46 ;
V_42 -> V_41 = V_47 ;
V_42 -> V_45 = 1 ;
F_40 ( & V_42 -> V_57 , & V_58 ) ;
V_55:
F_23 ( & V_44 ) ;
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
}
static void F_41 ( struct V_39 * V_42 )
{
if ( ! -- V_42 -> V_45 )
F_42 ( & V_42 -> V_57 ) ;
}
static void F_43 ( struct V_39 * V_42 )
{
if ( ! V_42 -> V_45 ) {
F_44 () ;
F_30 ( V_42 -> V_40 , V_42 -> V_43 ) ;
F_38 ( V_42 ) ;
}
}
void T_10 F_45 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
if ( ! V_54 ) {
F_46 ( V_43 , V_41 ) ;
return;
}
F_22 ( & V_44 ) ;
V_42 = F_24 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
F_47 ( true , V_59 L_19 , V_60 , V_43 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
void T_3 F_48 ( void T_8 * V_43 , T_7 V_41 )
{
if ( ! V_54 )
F_46 ( V_43 , V_41 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_43 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return - V_62 ;
V_43 = F_33 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_43 )
return - V_63 ;
return 0 ;
}
void F_50 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_39 * V_42 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
T_11
F_51 ( void * V_43 , T_6 * V_40 )
{
if ( ! V_40 || ! V_43 )
return V_64 ;
* V_40 = F_52 ( V_43 ) ;
return V_65 ;
}
T_11
F_53 ( const struct V_66 * V_67 ,
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
T_12 T_3 F_54 ( T_12 * V_28 , T_1 V_5 )
{
T_12 V_71 = 0 ;
T_12 * V_72 = V_28 + V_5 ;
while ( V_28 < V_72 )
V_71 = ( T_12 ) ( V_71 + * ( V_28 ++ ) ) ;
return V_71 ;
}
void T_3 F_55 ( void * V_73 , T_13 V_41 )
{
int V_74 , V_75 , V_76 = 0 , V_77 = 0 ;
long V_78 = 0 ;
struct V_79 * V_80 ;
char V_81 [ 32 ] = L_22 ;
struct V_82 V_83 ;
if ( V_73 == NULL || V_41 == 0 )
return;
for ( V_75 = 0 ; V_75 < V_84 ; V_75 ++ ) {
V_83 = F_56 ( V_81 , V_73 , V_41 , & V_78 ) ;
if ( ! V_83 . V_73 )
break;
V_73 += V_78 ;
V_41 -= V_78 ;
if ( V_83 . V_41 < sizeof( struct V_79 ) ) {
F_57 ( L_23 ,
V_81 , V_83 . V_69 ) ;
continue;
}
V_80 = V_83 . V_73 ;
for ( V_74 = 0 ; V_85 [ V_74 ] ; V_74 ++ )
if ( ! memcmp ( V_80 -> V_86 , V_85 [ V_74 ] , 4 ) )
break;
if ( ! V_85 [ V_74 ] ) {
F_57 ( L_24 ,
V_81 , V_83 . V_69 ) ;
continue;
}
if ( V_83 . V_41 != V_80 -> V_5 ) {
F_57 ( L_25 ,
V_81 , V_83 . V_69 ) ;
continue;
}
if ( F_54 ( V_83 . V_73 , V_80 -> V_5 ) ) {
F_57 ( L_26 ,
V_81 , V_83 . V_69 ) ;
continue;
}
F_58 ( L_27 ,
V_80 -> V_86 , V_81 , V_83 . V_69 , V_80 -> V_5 ) ;
V_87 += V_80 -> V_5 ;
V_88 [ V_76 ] . V_73 = V_83 . V_73 ;
V_88 [ V_76 ] . V_41 = V_83 . V_41 ;
V_76 ++ ;
}
if ( V_76 == 0 )
return;
V_89 =
F_59 ( 0 , V_90 << V_49 ,
V_87 , V_50 ) ;
if ( ! V_89 ) {
F_60 ( 1 ) ;
return;
}
F_61 ( V_89 , V_87 ) ;
F_62 ( V_89 , V_87 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
unsigned char * V_91 = V_88 [ V_75 ] . V_73 ;
T_14 V_41 = V_88 [ V_75 ] . V_41 ;
T_14 V_92 = V_89 + V_77 ;
T_14 V_93 , V_94 ;
char * V_95 ;
V_77 += V_41 ;
while ( V_41 ) {
V_93 = V_92 & ~ V_96 ;
V_94 = V_41 ;
if ( V_94 > V_97 - V_93 )
V_94 = V_97 - V_93 ;
V_95 = F_63 ( V_92 & V_96 ,
V_94 + V_93 ) ;
memcpy ( V_95 + V_93 , V_91 , V_94 ) ;
F_64 ( V_95 , V_94 + V_93 ) ;
V_91 += V_94 ;
V_92 += V_94 ;
V_41 -= V_94 ;
}
}
}
static void F_65 ( struct V_79 * V_80 )
{
F_66 ( V_59
L_28 ,
V_80 -> V_86 , V_80 -> V_98 ) ;
F_67 ( V_99 , V_100 ) ;
}
T_11
F_68 ( struct V_79 * V_101 ,
struct V_79 * * V_102 )
{
if ( ! V_101 || ! V_102 )
return V_64 ;
* V_102 = NULL ;
#ifdef F_69
if ( strncmp ( V_101 -> V_86 , L_29 , 4 ) == 0 )
* V_102 = (struct V_79 * ) V_103 ;
#endif
if ( * V_102 != NULL )
F_65 ( V_101 ) ;
return V_65 ;
}
T_11
F_70 ( struct V_79 * V_101 ,
T_6 * V_8 ,
T_1 * V_104 )
{
#ifndef F_71
* V_104 = 0 ;
* V_8 = 0 ;
return V_65 ;
#else
int V_105 = 0 ;
struct V_79 * V_80 ;
* V_104 = 0 ;
* V_8 = 0 ;
if ( ! V_89 )
return V_65 ;
do {
if ( V_105 + V_106 > V_87 ) {
F_60 ( 1 ) ;
return V_65 ;
}
V_80 = F_33 ( V_89 + V_105 ,
V_106 ) ;
if ( V_105 + V_80 -> V_5 > V_87 ) {
F_45 ( V_80 , V_106 ) ;
F_60 ( 1 ) ;
return V_65 ;
}
V_105 += V_80 -> V_5 ;
if ( memcmp ( V_101 -> V_86 , V_80 -> V_86 , 4 ) ) {
F_45 ( V_80 ,
V_106 ) ;
continue;
}
if ( memcmp ( V_80 -> V_98 , V_101 -> V_98 ,
V_107 ) ) {
F_45 ( V_80 ,
V_106 ) ;
continue;
}
V_105 -= V_80 -> V_5 ;
* V_104 = V_80 -> V_5 ;
F_45 ( V_80 , V_106 ) ;
* V_8 = V_89 + V_105 ;
break;
} while ( V_105 + V_106 < V_87 );
if ( * V_8 != 0 )
F_65 ( V_101 ) ;
return V_65 ;
#endif
}
static T_15 F_72 ( int V_108 , void * V_109 )
{
T_1 V_110 ;
V_110 = (* F_73) ( V_111 ) ;
if ( V_110 ) {
V_112 ++ ;
return V_113 ;
} else {
V_114 ++ ;
return V_115 ;
}
}
T_11
F_74 ( T_1 V_116 , T_16 V_117 ,
void * V_118 )
{
unsigned int V_108 ;
F_75 () ;
if ( V_116 != V_12 . V_119 )
return V_64 ;
if ( F_73 )
return V_120 ;
if ( F_76 ( V_116 , & V_108 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_30 ,
gsi) ;
return V_65 ;
}
F_73 = V_117 ;
V_111 = V_118 ;
if ( F_77 ( V_108 , F_72 , V_121 | V_122 , L_31 , F_72 ) ) {
F_11 (KERN_ERR PREFIX L_32 , irq) ;
F_73 = NULL ;
return V_123 ;
}
return V_65 ;
}
T_11 F_78 ( T_1 V_108 , T_16 V_117 )
{
if ( V_108 != V_12 . V_119 )
return V_64 ;
F_79 ( V_108 , F_72 ) ;
F_73 = NULL ;
return V_65 ;
}
void F_80 ( T_4 V_124 )
{
F_81 ( V_124 ) ;
}
void F_82 ( T_1 V_125 )
{
while ( V_125 ) {
T_1 V_126 = 1000 ;
if ( V_126 > V_125 )
V_126 = V_125 ;
F_83 ( V_126 ) ;
F_84 () ;
V_125 -= V_126 ;
}
}
T_4 F_85 ( void )
{
T_4 V_127 = F_86 ( F_87 () ) ;
F_88 ( V_127 , 100 ) ;
return V_127 ;
}
T_11 F_89 ( T_17 V_128 , T_1 * V_129 , T_1 V_130 )
{
T_1 V_131 ;
if ( ! V_129 )
V_129 = & V_131 ;
* V_129 = 0 ;
if ( V_130 <= 8 ) {
* ( T_12 * ) V_129 = F_90 ( V_128 ) ;
} else if ( V_130 <= 16 ) {
* ( V_132 * ) V_129 = F_91 ( V_128 ) ;
} else if ( V_130 <= 32 ) {
* ( T_1 * ) V_129 = F_92 ( V_128 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
T_11 F_94 ( T_17 V_128 , T_1 V_129 , T_1 V_130 )
{
if ( V_130 <= 8 ) {
F_95 ( V_129 , V_128 ) ;
} else if ( V_130 <= 16 ) {
F_96 ( V_129 , V_128 ) ;
} else if ( V_130 <= 32 ) {
F_97 ( V_129 , V_128 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
return F_99 ( V_7 ) ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
T_4 V_133 , V_134 ;
V_133 = F_100 ( V_7 ) ;
V_134 = F_100 ( V_7 + 4 ) ;
return V_133 | ( V_134 << 32 ) ;
}
T_11
F_101 ( T_6 V_135 , T_4 * V_129 , T_1 V_130 )
{
void T_8 * V_136 ;
unsigned int V_41 = V_130 / 8 ;
bool V_137 = false ;
T_4 V_131 ;
F_102 () ;
V_136 = F_20 ( V_135 , V_41 ) ;
if ( ! V_136 ) {
F_103 () ;
V_136 = F_29 ( V_135 , V_41 ) ;
if ( ! V_136 )
return V_138 ;
V_137 = true ;
}
if ( ! V_129 )
V_129 = & V_131 ;
switch ( V_130 ) {
case 8 :
* ( T_12 * ) V_129 = F_104 ( V_136 ) ;
break;
case 16 :
* ( V_132 * ) V_129 = F_105 ( V_136 ) ;
break;
case 32 :
* ( T_1 * ) V_129 = F_100 ( V_136 ) ;
break;
case 64 :
* ( T_4 * ) V_129 = F_98 ( V_136 ) ;
break;
default:
F_93 () ;
}
if ( V_137 )
F_32 ( V_136 ) ;
else
F_103 () ;
return V_65 ;
}
static inline void F_106 ( T_4 V_139 , volatile void T_8 * V_7 )
{
F_107 ( V_139 , V_7 ) ;
}
static inline void F_106 ( T_4 V_139 , volatile void T_8 * V_7 )
{
F_108 ( V_139 , V_7 ) ;
F_108 ( V_139 >> 32 , V_7 + 4 ) ;
}
T_11
F_109 ( T_6 V_135 , T_4 V_129 , T_1 V_130 )
{
void T_8 * V_136 ;
unsigned int V_41 = V_130 / 8 ;
bool V_137 = false ;
F_102 () ;
V_136 = F_20 ( V_135 , V_41 ) ;
if ( ! V_136 ) {
F_103 () ;
V_136 = F_29 ( V_135 , V_41 ) ;
if ( ! V_136 )
return V_138 ;
V_137 = true ;
}
switch ( V_130 ) {
case 8 :
F_110 ( V_129 , V_136 ) ;
break;
case 16 :
F_111 ( V_129 , V_136 ) ;
break;
case 32 :
F_108 ( V_129 , V_136 ) ;
break;
case 64 :
F_106 ( V_129 , V_136 ) ;
break;
default:
F_93 () ;
}
if ( V_137 )
F_32 ( V_136 ) ;
else
F_103 () ;
return V_65 ;
}
T_11
F_112 ( struct V_140 * V_141 , T_1 V_142 ,
T_4 * V_129 , T_1 V_130 )
{
int V_143 , V_41 ;
T_1 V_144 ;
if ( ! V_129 )
return V_64 ;
switch ( V_130 ) {
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
return V_145 ;
}
V_143 = F_113 ( V_141 -> V_146 , V_141 -> V_147 ,
F_114 ( V_141 -> V_148 , V_141 -> V_149 ) ,
V_142 , V_41 , & V_144 ) ;
* V_129 = V_144 ;
return ( V_143 ? V_145 : V_65 ) ;
}
T_11
F_115 ( struct V_140 * V_141 , T_1 V_142 ,
T_4 V_129 , T_1 V_130 )
{
int V_143 , V_41 ;
switch ( V_130 ) {
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
return V_145 ;
}
V_143 = F_116 ( V_141 -> V_146 , V_141 -> V_147 ,
F_114 ( V_141 -> V_148 , V_141 -> V_149 ) ,
V_142 , V_41 , V_129 ) ;
return ( V_143 ? V_145 : V_65 ) ;
}
static void F_117 ( struct V_150 * V_151 )
{
struct V_152 * V_153 = F_118 ( V_151 , struct V_152 , V_151 ) ;
V_153 -> V_149 ( V_153 -> V_118 ) ;
F_38 ( V_153 ) ;
}
T_11 F_119 ( T_18 type ,
T_19 V_149 , void * V_118 )
{
T_11 V_154 = V_65 ;
struct V_152 * V_153 ;
struct V_155 * V_156 ;
int V_157 ;
F_120 ( ( V_158 ,
L_33 ,
V_149 , V_118 ) ) ;
V_153 = F_35 ( sizeof( struct V_152 ) , V_159 ) ;
if ( ! V_153 )
return V_160 ;
V_153 -> V_149 = V_149 ;
V_153 -> V_118 = V_118 ;
if ( type == V_161 ) {
V_156 = V_162 ;
F_121 ( & V_153 -> V_151 , F_117 ) ;
} else {
V_156 = V_163 ;
F_121 ( & V_153 -> V_151 , F_117 ) ;
}
V_157 = F_122 ( 0 , V_156 , & V_153 -> V_151 ) ;
if ( ! V_157 ) {
F_11 (KERN_ERR PREFIX
L_34 ) ;
V_154 = V_145 ;
F_38 ( V_153 ) ;
}
return V_154 ;
}
void F_123 ( void )
{
F_124 ( V_163 ) ;
F_124 ( V_162 ) ;
}
static void F_125 ( struct V_150 * V_151 )
{
struct V_164 * V_165 = F_118 ( V_151 , struct V_164 , V_151 ) ;
F_123 () ;
V_165 -> V_166 ( V_165 -> V_73 , V_165 -> V_167 ) ;
F_38 ( V_165 ) ;
}
T_11 F_126 ( T_20 V_166 , void * V_73 , T_1 V_167 )
{
struct V_164 * V_165 ;
F_120 ( ( V_158 ,
L_35 ,
V_166 , V_73 , V_167 ) ) ;
V_165 = F_127 ( sizeof( * V_165 ) , V_56 ) ;
if ( ! V_165 )
return V_160 ;
F_121 ( & V_165 -> V_151 , F_125 ) ;
V_165 -> V_166 = V_166 ;
V_165 -> V_73 = V_73 ;
V_165 -> V_167 = V_167 ;
if ( ! F_128 ( V_168 , & V_165 -> V_151 ) ) {
F_38 ( V_165 ) ;
return V_145 ;
}
return V_65 ;
}
T_11
F_129 ( T_1 V_169 , T_1 V_170 , T_21 * V_171 )
{
struct V_172 * V_173 = NULL ;
V_173 = F_130 ( sizeof( struct V_172 ) ) ;
if ( ! V_173 )
return V_160 ;
memset ( V_173 , 0 , sizeof( struct V_172 ) ) ;
F_131 ( V_173 , V_170 ) ;
* V_171 = ( T_21 * ) V_173 ;
F_120 ( ( V_174 , L_36 ,
* V_171 , V_170 ) ) ;
return V_65 ;
}
T_11 F_132 ( T_21 V_171 )
{
struct V_172 * V_173 = (struct V_172 * ) V_171 ;
if ( ! V_173 )
return V_64 ;
F_120 ( ( V_174 , L_37 , V_171 ) ) ;
F_133 ( ! F_134 ( & V_173 -> V_175 ) ) ;
F_38 ( V_173 ) ;
V_173 = NULL ;
return V_65 ;
}
T_11 F_135 ( T_21 V_171 , T_1 V_176 , V_132 V_177 )
{
T_11 V_154 = V_65 ;
struct V_172 * V_173 = (struct V_172 * ) V_171 ;
long V_178 ;
int V_157 = 0 ;
if ( ! V_173 || ( V_176 < 1 ) )
return V_64 ;
if ( V_176 > 1 )
return V_179 ;
F_120 ( ( V_174 , L_38 ,
V_171 , V_176 , V_177 ) ) ;
if ( V_177 == V_180 )
V_178 = V_181 ;
else
V_178 = F_136 ( V_177 ) ;
V_157 = F_137 ( V_173 , V_178 ) ;
if ( V_157 )
V_154 = V_182 ;
if ( F_138 ( V_154 ) ) {
F_120 ( ( V_174 ,
L_39 ,
V_171 , V_176 , V_177 ,
F_139 ( V_154 ) ) ) ;
} else {
F_120 ( ( V_174 ,
L_40 , V_171 ,
V_176 , V_177 ) ) ;
}
return V_154 ;
}
T_11 F_140 ( T_21 V_171 , T_1 V_176 )
{
struct V_172 * V_173 = (struct V_172 * ) V_171 ;
if ( ! V_173 || ( V_176 < 1 ) )
return V_64 ;
if ( V_176 > 1 )
return V_179 ;
F_120 ( ( V_174 , L_41 , V_171 ,
V_176 ) ) ;
F_141 ( V_173 ) ;
return V_65 ;
}
T_1 F_142 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_183 ;
F_143 ( V_28 , sizeof( V_184 ) ) ;
V_183 = strlen ( V_28 ) - 1 ;
V_28 [ V_183 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_144 ( T_1 V_149 , void * V_185 )
{
switch ( V_149 ) {
case V_186 :
F_11 (KERN_ERR PREFIX L_42 ) ;
break;
case V_187 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_145 ( char * V_188 )
{
char * V_189 = V_70 ;
int V_190 = V_191 - 1 ;
if ( ! V_188 || ! * V_188 )
return 0 ;
for (; V_190 -- && * V_188 ; V_188 ++ ) {
if ( isalnum ( * V_188 ) || * V_188 == ' ' || * V_188 == ':' )
* V_189 ++ = * V_188 ;
else if ( * V_188 == '\'' || * V_188 == '"' )
continue;
else
break;
}
* V_189 = 0 ;
return 1 ;
}
void T_3 F_146 ( char * V_188 )
{
struct V_192 * V_193 ;
bool V_194 = true ;
int V_195 ;
if ( ! V_196 )
return;
if ( V_188 == NULL || * V_188 == '\0' ) {
F_11 (KERN_INFO PREFIX L_43 ) ;
V_196 = FALSE ;
return;
}
if ( * V_188 == '!' ) {
V_188 ++ ;
if ( * V_188 == '\0' ) {
V_197 . V_198 = 1 ;
return;
} else if ( * V_188 == '*' ) {
F_147 ( V_199 ) ;
for ( V_195 = 0 ; V_195 < V_200 ; V_195 ++ ) {
V_193 = & V_201 [ V_195 ] ;
V_193 -> V_194 = false ;
}
return;
}
V_194 = false ;
}
for ( V_195 = 0 ; V_195 < V_200 ; V_195 ++ ) {
V_193 = & V_201 [ V_195 ] ;
if ( ! strcmp ( V_193 -> string , V_188 ) ) {
V_193 -> V_194 = V_194 ;
break;
} else if ( V_193 -> string [ 0 ] == '\0' ) {
V_193 -> V_194 = V_194 ;
strncpy ( V_193 -> string , V_188 , V_202 ) ;
break;
}
}
}
static void T_3 F_148 ( unsigned int V_194 )
{
if ( V_197 . V_194 != V_194 )
V_197 . V_194 = V_194 ;
if ( V_197 . V_194 )
F_146 ( L_1 ) ;
else
F_146 ( L_44 ) ;
return;
}
static void T_3 F_149 ( unsigned int V_194 )
{
V_197 . V_203 = 1 ;
V_197 . V_204 = 0 ;
F_148 ( V_194 ) ;
return;
}
void T_3 F_150 ( int V_194 , const struct V_205 * V_206 )
{
F_11 (KERN_NOTICE PREFIX L_45 , d->ident) ;
if ( V_194 == - 1 )
return;
V_197 . V_204 = 1 ;
F_148 ( V_194 ) ;
return;
}
static void T_3 F_151 ( void )
{
struct V_192 * V_193 ;
char * V_188 ;
int V_195 ;
T_11 V_154 ;
if ( V_197 . V_198 ) {
V_154 = F_147 ( V_207 ) ;
if ( F_152 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_46 ) ;
}
for ( V_195 = 0 ; V_195 < V_200 ; V_195 ++ ) {
V_193 = & V_201 [ V_195 ] ;
V_188 = V_193 -> string ;
if ( * V_188 == '\0' )
break;
if ( V_193 -> V_194 ) {
V_154 = F_153 ( V_188 ) ;
if ( F_152 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_47 , str) ;
} else {
V_154 = F_154 ( V_188 ) ;
if ( F_152 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_48 , str) ;
}
}
}
static int T_3 F_155 ( char * V_188 )
{
if ( V_188 && ! strcmp ( L_1 , V_188 ) )
F_149 ( 1 ) ;
else if ( V_188 && ! strcmp ( L_44 , V_188 ) )
F_149 ( 0 ) ;
else
F_146 ( V_188 ) ;
return 1 ;
}
static int T_3 F_156 ( char * V_188 )
{
F_11 (KERN_INFO PREFIX L_49 ) ;
V_208 = TRUE ;
return 1 ;
}
static int T_3 F_157 ( char * V_188 )
{
if ( V_188 == NULL || * V_188 == '\0' )
return 0 ;
if ( ! strcmp ( L_50 , V_188 ) )
V_209 = V_210 ;
else if ( ! strcmp ( L_51 , V_188 ) )
V_209 = V_211 ;
else if ( ! strcmp ( L_52 , V_188 ) )
V_209 = V_212 ;
return 1 ;
}
int F_158 ( const struct V_213 * V_214 )
{
T_22 V_9 ;
T_7 V_5 ;
T_12 V_215 = 0 ;
int V_216 = 0 ;
if ( V_209 == V_212 )
return 0 ;
if ( ! ( V_214 -> V_217 & V_218 ) && ! ( V_214 -> V_217 & V_219 ) )
return 0 ;
if ( V_214 -> V_217 & V_218 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = F_159 ( V_214 ) ;
if ( V_209 != V_212 )
V_215 = 1 ;
V_216 = F_160 ( V_9 , V_214 -> V_220 , V_5 , V_215 ) ;
if ( V_216 ) {
if ( V_209 != V_212 ) {
if ( V_209 == V_211 )
F_11 ( V_221 L_53
L_54
L_55 ) ;
F_11 ( V_222 L_56
L_57
L_58 ) ;
}
if ( V_209 == V_210 )
return - V_223 ;
}
return 0 ;
}
int F_161 ( T_23 V_220 , T_23 V_224 ,
const char * V_69 )
{
struct V_213 V_214 = {
. V_220 = V_220 ,
. V_72 = V_220 + V_224 - 1 ,
. V_69 = V_69 ,
. V_217 = V_218 ,
} ;
return F_158 ( & V_214 ) ;
}
int F_162 ( void )
{
return V_209 == V_210 ;
}
void F_163 ( T_24 V_171 )
{
F_164 ( V_171 ) ;
}
T_25 F_165 ( T_24 V_225 )
{
T_25 V_217 ;
F_166 ( V_225 , V_217 ) ;
return V_217 ;
}
void F_167 ( T_24 V_225 , T_25 V_217 )
{
F_168 ( V_225 , V_217 ) ;
}
T_11
F_169 ( char * V_69 , V_132 V_41 , V_132 V_226 , T_26 * * V_227 )
{
* V_227 = F_170 ( V_69 , V_41 , 0 , 0 , NULL ) ;
if ( * V_227 == NULL )
return V_145 ;
else
return V_65 ;
}
T_11 F_171 ( T_26 * V_227 )
{
F_172 ( V_227 ) ;
return ( V_65 ) ;
}
T_11 F_173 ( T_26 * V_227 )
{
F_174 ( V_227 ) ;
return ( V_65 ) ;
}
T_11 F_175 ( T_26 * V_227 , void * V_228 )
{
F_176 ( V_227 , V_228 ) ;
return ( V_65 ) ;
}
static int T_3 F_177 ( char * V_229 )
{
F_11 (KERN_NOTICE PREFIX L_59 ) ;
V_230 = TRUE ;
return 1 ;
}
T_11 T_3 F_178 ( void )
{
F_49 ( & V_12 . V_13 ) ;
F_49 ( & V_12 . V_15 ) ;
F_49 ( & V_12 . V_24 ) ;
F_49 ( & V_12 . V_26 ) ;
return V_65 ;
}
T_11 T_3 F_179 ( void )
{
V_163 = F_180 ( L_60 , 0 , 1 ) ;
V_162 = F_180 ( L_61 , 0 , 1 ) ;
V_168 = F_180 ( L_62 , 0 , 1 ) ;
F_133 ( ! V_163 ) ;
F_133 ( ! V_162 ) ;
F_133 ( ! V_168 ) ;
F_181 ( F_1 ) ;
F_151 () ;
return V_65 ;
}
T_11 F_182 ( void )
{
if ( F_73 ) {
F_78 ( V_12 . V_119 ,
F_73 ) ;
}
F_50 ( & V_12 . V_26 ) ;
F_50 ( & V_12 . V_24 ) ;
F_50 ( & V_12 . V_15 ) ;
F_50 ( & V_12 . V_13 ) ;
F_183 ( V_163 ) ;
F_183 ( V_162 ) ;
F_183 ( V_168 ) ;
return V_65 ;
}
T_11 F_184 ( T_12 V_231 , T_1 V_232 ,
T_1 V_233 )
{
int V_234 = 0 ;
if ( V_235 )
V_234 = V_235 ( V_231 ,
V_232 , V_233 ) ;
if ( V_234 < 0 )
return V_145 ;
else if ( V_234 > 0 )
return V_236 ;
return V_65 ;
}
void F_185 ( int (* V_166)( T_12 V_231 ,
T_1 V_237 , T_1 V_238 ) )
{
V_235 = V_166 ;
}
T_11 F_186 ( T_12 V_231 , T_1 V_239 ,
T_1 V_240 )
{
int V_234 = 0 ;
if ( V_241 )
V_234 = V_241 ( V_231 ,
V_239 , V_240 ) ;
if ( V_234 < 0 )
return V_145 ;
else if ( V_234 > 0 )
return V_236 ;
return V_65 ;
}
void F_187 ( int (* V_166)( T_12 V_231 ,
T_1 V_239 , T_1 V_240 ) )
{
V_241 = V_166 ;
}
