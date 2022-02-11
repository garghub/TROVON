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
if ( F_13 ( V_31 , 16 , & V_32 ) )
return - V_33 ;
return 0 ;
}
T_6 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_32 )
return V_32 ;
#endif
if ( F_16 ( V_34 ) ) {
if ( V_35 . V_36 != V_37 )
return V_35 . V_36 ;
else if ( V_35 . V_38 != V_37 )
return V_35 . V_38 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else if ( F_17 ( V_39 ) ) {
T_6 V_40 = 0 ;
F_18 ( & V_40 ) ;
return V_40 ;
}
return 0 ;
}
static struct V_41 *
F_19 ( T_6 V_42 , T_7 V_43 )
{
struct V_41 * V_44 ;
F_20 (map, &acpi_ioremaps, list)
if ( V_44 -> V_42 <= V_42 &&
V_42 + V_43 <= V_44 -> V_42 + V_44 -> V_43 )
return V_44 ;
return NULL ;
}
static void T_8 *
F_21 ( T_6 V_42 , unsigned int V_43 )
{
struct V_41 * V_44 ;
V_44 = F_19 ( V_42 , V_43 ) ;
if ( V_44 )
return V_44 -> V_45 + ( V_42 - V_44 -> V_42 ) ;
return NULL ;
}
void T_8 * F_22 ( T_6 V_42 , unsigned int V_43 )
{
struct V_41 * V_44 ;
void T_8 * V_45 = NULL ;
F_23 ( & V_46 ) ;
V_44 = F_19 ( V_42 , V_43 ) ;
if ( V_44 ) {
V_45 = V_44 -> V_45 + ( V_42 - V_44 -> V_42 ) ;
V_44 -> V_47 ++ ;
}
F_24 ( & V_46 ) ;
return V_45 ;
}
static struct V_41 *
F_25 ( void T_8 * V_45 , T_7 V_43 )
{
struct V_41 * V_44 ;
F_20 (map, &acpi_ioremaps, list)
if ( V_44 -> V_45 <= V_45 &&
V_45 + V_43 <= V_44 -> V_45 + V_44 -> V_43 )
return V_44 ;
return NULL ;
}
static void T_8 * F_26 ( T_6 V_48 , unsigned long V_49 )
{
unsigned long V_50 ;
V_50 = V_48 >> V_51 ;
if ( F_27 ( V_50 ) ) {
if ( V_49 > V_52 )
return NULL ;
return ( void T_8 V_53 * ) F_28 ( F_29 ( V_50 ) ) ;
} else
return F_30 ( V_48 , V_49 ) ;
}
static void F_31 ( T_6 V_48 , void T_8 * V_54 )
{
unsigned long V_50 ;
V_50 = V_48 >> V_51 ;
if ( F_27 ( V_50 ) )
F_32 ( F_29 ( V_50 ) ) ;
else
F_33 ( V_54 ) ;
}
void T_8 * T_9
F_34 ( T_6 V_42 , T_7 V_43 )
{
struct V_41 * V_44 ;
void T_8 * V_45 ;
T_6 V_48 ;
T_7 V_49 ;
if ( V_42 > V_55 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_56 )
return F_35 ( ( unsigned long ) V_42 , V_43 ) ;
F_23 ( & V_46 ) ;
V_44 = F_19 ( V_42 , V_43 ) ;
if ( V_44 ) {
V_44 -> V_47 ++ ;
goto V_57;
}
V_44 = F_36 ( sizeof( * V_44 ) , V_58 ) ;
if ( ! V_44 ) {
F_24 ( & V_46 ) ;
return NULL ;
}
V_48 = F_37 ( V_42 , V_52 ) ;
V_49 = F_38 ( V_42 + V_43 , V_52 ) - V_48 ;
V_45 = F_26 ( V_48 , V_49 ) ;
if ( ! V_45 ) {
F_24 ( & V_46 ) ;
F_39 ( V_44 ) ;
return NULL ;
}
F_40 ( & V_44 -> V_59 ) ;
V_44 -> V_45 = V_45 ;
V_44 -> V_42 = V_48 ;
V_44 -> V_43 = V_49 ;
V_44 -> V_47 = 1 ;
F_41 ( & V_44 -> V_59 , & V_60 ) ;
V_57:
F_24 ( & V_46 ) ;
return V_44 -> V_45 + ( V_42 - V_44 -> V_42 ) ;
}
void * T_9
F_42 ( T_6 V_42 , T_7 V_43 )
{
return ( void * ) F_34 ( V_42 , V_43 ) ;
}
static void F_43 ( struct V_41 * V_44 )
{
if ( ! -- V_44 -> V_47 )
F_44 ( & V_44 -> V_59 ) ;
}
static void F_45 ( struct V_41 * V_44 )
{
if ( ! V_44 -> V_47 ) {
F_46 () ;
F_31 ( V_44 -> V_42 , V_44 -> V_45 ) ;
F_39 ( V_44 ) ;
}
}
void T_10 F_47 ( void T_8 * V_45 , T_7 V_43 )
{
struct V_41 * V_44 ;
if ( ! V_56 ) {
F_48 ( V_45 , V_43 ) ;
return;
}
F_23 ( & V_46 ) ;
V_44 = F_25 ( V_45 , V_43 ) ;
if ( ! V_44 ) {
F_24 ( & V_46 ) ;
F_49 ( true , V_61 L_19 , V_62 , V_45 ) ;
return;
}
F_43 ( V_44 ) ;
F_24 ( & V_46 ) ;
F_45 ( V_44 ) ;
}
void T_10 F_50 ( void * V_45 , T_7 V_43 )
{
return F_47 ( ( void T_8 * ) V_45 , V_43 ) ;
}
void T_3 F_51 ( void T_8 * V_45 , T_7 V_43 )
{
if ( ! V_56 )
F_48 ( V_45 , V_43 ) ;
}
int F_52 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_45 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_63 )
return - V_33 ;
V_45 = F_34 ( V_7 , V_4 -> V_63 / 8 ) ;
if ( ! V_45 )
return - V_64 ;
return 0 ;
}
void F_53 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_41 * V_44 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_63 )
return;
F_23 ( & V_46 ) ;
V_44 = F_19 ( V_7 , V_4 -> V_63 / 8 ) ;
if ( ! V_44 ) {
F_24 ( & V_46 ) ;
return;
}
F_43 ( V_44 ) ;
F_24 ( & V_46 ) ;
F_45 ( V_44 ) ;
}
T_11
F_54 ( void * V_45 , T_6 * V_42 )
{
if ( ! V_42 || ! V_45 )
return V_65 ;
* V_42 = F_55 ( V_45 ) ;
return V_66 ;
}
T_11
F_56 ( const struct V_67 * V_68 ,
T_2 * V_69 )
{
if ( ! V_68 || ! V_69 )
return V_65 ;
* V_69 = NULL ;
if ( ! memcmp ( V_68 -> V_70 , L_20 , 4 ) && strlen ( V_71 ) ) {
F_11 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_69 = V_71 ;
}
return V_66 ;
}
static T_12 T_3 F_57 ( T_12 * V_28 , T_1 V_5 )
{
T_12 V_72 = 0 ;
T_12 * V_73 = V_28 + V_5 ;
while ( V_28 < V_73 )
V_72 = ( T_12 ) ( V_72 + * ( V_28 ++ ) ) ;
return V_72 ;
}
void T_3 F_58 ( void * V_74 , T_13 V_43 )
{
int V_75 , V_76 , V_77 = 0 , V_78 = 0 ;
long V_79 = 0 ;
struct V_80 * V_81 ;
char V_82 [ 32 ] = L_22 ;
struct V_83 V_84 ;
if ( V_74 == NULL || V_43 == 0 )
return;
for ( V_76 = 0 ; V_76 < V_85 ; V_76 ++ ) {
V_84 = F_59 ( V_82 , V_74 , V_43 , & V_79 ) ;
if ( ! V_84 . V_74 )
break;
V_74 += V_79 ;
V_43 -= V_79 ;
if ( V_84 . V_43 < sizeof( struct V_80 ) ) {
F_60 ( L_23 ,
V_82 , V_84 . V_70 ) ;
continue;
}
V_81 = V_84 . V_74 ;
for ( V_75 = 0 ; V_86 [ V_75 ] ; V_75 ++ )
if ( ! memcmp ( V_81 -> V_87 , V_86 [ V_75 ] , 4 ) )
break;
if ( ! V_86 [ V_75 ] ) {
F_60 ( L_24 ,
V_82 , V_84 . V_70 ) ;
continue;
}
if ( V_84 . V_43 != V_81 -> V_5 ) {
F_60 ( L_25 ,
V_82 , V_84 . V_70 ) ;
continue;
}
if ( F_57 ( V_84 . V_74 , V_81 -> V_5 ) ) {
F_60 ( L_26 ,
V_82 , V_84 . V_70 ) ;
continue;
}
F_61 ( L_27 ,
V_81 -> V_87 , V_82 , V_84 . V_70 , V_81 -> V_5 ) ;
V_88 += V_81 -> V_5 ;
V_89 [ V_77 ] . V_74 = V_84 . V_74 ;
V_89 [ V_77 ] . V_43 = V_84 . V_43 ;
V_77 ++ ;
}
if ( V_77 == 0 )
return;
V_90 =
F_62 ( 0 , V_91 << V_51 ,
V_88 , V_52 ) ;
if ( ! V_90 ) {
F_63 ( 1 ) ;
return;
}
F_64 ( V_90 , V_88 ) ;
F_65 ( V_90 , V_88 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
unsigned char * V_92 = V_89 [ V_76 ] . V_74 ;
T_14 V_43 = V_89 [ V_76 ] . V_43 ;
T_14 V_93 = V_90 + V_78 ;
T_14 V_94 , V_95 ;
char * V_96 ;
V_78 += V_43 ;
while ( V_43 ) {
V_94 = V_93 & ~ V_97 ;
V_95 = V_43 ;
if ( V_95 > V_98 - V_94 )
V_95 = V_98 - V_94 ;
V_96 = F_66 ( V_93 & V_97 ,
V_95 + V_94 ) ;
memcpy ( V_96 + V_94 , V_92 , V_95 ) ;
F_67 ( V_96 , V_95 + V_94 ) ;
V_92 += V_95 ;
V_93 += V_95 ;
V_43 -= V_95 ;
}
}
}
static void F_68 ( struct V_80 * V_81 )
{
F_69 ( V_61
L_28 ,
V_81 -> V_87 , V_81 -> V_99 ) ;
F_70 ( V_100 , V_101 ) ;
}
T_11
F_71 ( struct V_80 * V_102 ,
struct V_80 * * V_103 )
{
if ( ! V_102 || ! V_103 )
return V_65 ;
* V_103 = NULL ;
#ifdef F_72
if ( strncmp ( V_102 -> V_87 , L_29 , 4 ) == 0 )
* V_103 = (struct V_80 * ) V_104 ;
#endif
if ( * V_103 != NULL )
F_68 ( V_102 ) ;
return V_66 ;
}
T_11
F_73 ( struct V_80 * V_102 ,
T_6 * V_8 ,
T_1 * V_105 )
{
#ifndef F_74
* V_105 = 0 ;
* V_8 = 0 ;
return V_66 ;
#else
int V_106 = 0 ;
struct V_80 * V_81 ;
* V_105 = 0 ;
* V_8 = 0 ;
if ( ! V_90 )
return V_66 ;
do {
if ( V_106 + V_107 > V_88 ) {
F_63 ( 1 ) ;
return V_66 ;
}
V_81 = F_42 ( V_90 + V_106 ,
V_107 ) ;
if ( V_106 + V_81 -> V_5 > V_88 ) {
F_50 ( V_81 , V_107 ) ;
F_63 ( 1 ) ;
return V_66 ;
}
V_106 += V_81 -> V_5 ;
if ( memcmp ( V_102 -> V_87 , V_81 -> V_87 , 4 ) ) {
F_50 ( V_81 ,
V_107 ) ;
continue;
}
if ( memcmp ( V_81 -> V_99 , V_102 -> V_99 ,
V_108 ) ) {
F_50 ( V_81 ,
V_107 ) ;
continue;
}
V_106 -= V_81 -> V_5 ;
* V_105 = V_81 -> V_5 ;
F_50 ( V_81 , V_107 ) ;
* V_8 = V_90 + V_106 ;
break;
} while ( V_106 + V_107 < V_88 );
if ( * V_8 != 0 )
F_68 ( V_102 ) ;
return V_66 ;
#endif
}
static T_15 F_75 ( int V_109 , void * V_110 )
{
T_1 V_111 ;
V_111 = (* F_76) ( V_112 ) ;
if ( V_111 ) {
V_113 ++ ;
return V_114 ;
} else {
V_115 ++ ;
return V_116 ;
}
}
T_11
F_77 ( T_1 V_117 , T_16 V_118 ,
void * V_119 )
{
unsigned int V_109 ;
F_78 () ;
if ( V_117 != V_12 . V_120 )
return V_65 ;
if ( F_76 )
return V_121 ;
if ( F_79 ( V_117 , & V_109 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_30 ,
gsi) ;
return V_66 ;
}
F_76 = V_118 ;
V_112 = V_119 ;
if ( F_80 ( V_109 , F_75 , V_122 | V_123 , L_31 , F_75 ) ) {
F_11 (KERN_ERR PREFIX L_32 , irq) ;
F_76 = NULL ;
return V_124 ;
}
return V_66 ;
}
T_11 F_81 ( T_1 V_109 , T_16 V_118 )
{
if ( V_109 != V_12 . V_120 )
return V_65 ;
F_82 ( V_109 , F_75 ) ;
F_76 = NULL ;
return V_66 ;
}
void F_83 ( T_4 V_125 )
{
F_84 ( V_125 ) ;
}
void F_85 ( T_1 V_126 )
{
while ( V_126 ) {
T_1 V_127 = 1000 ;
if ( V_127 > V_126 )
V_127 = V_126 ;
F_86 ( V_127 ) ;
F_87 () ;
V_126 -= V_127 ;
}
}
T_4 F_88 ( void )
{
T_4 V_128 = F_89 ( F_90 () ) ;
F_91 ( V_128 , 100 ) ;
return V_128 ;
}
T_11 F_92 ( T_17 V_129 , T_1 * V_130 , T_1 V_131 )
{
T_1 V_132 ;
if ( ! V_130 )
V_130 = & V_132 ;
* V_130 = 0 ;
if ( V_131 <= 8 ) {
* ( T_12 * ) V_130 = F_93 ( V_129 ) ;
} else if ( V_131 <= 16 ) {
* ( V_133 * ) V_130 = F_94 ( V_129 ) ;
} else if ( V_131 <= 32 ) {
* ( T_1 * ) V_130 = F_95 ( V_129 ) ;
} else {
F_96 () ;
}
return V_66 ;
}
T_11 F_97 ( T_17 V_129 , T_1 V_130 , T_1 V_131 )
{
if ( V_131 <= 8 ) {
F_98 ( V_130 , V_129 ) ;
} else if ( V_131 <= 16 ) {
F_99 ( V_130 , V_129 ) ;
} else if ( V_131 <= 32 ) {
F_100 ( V_130 , V_129 ) ;
} else {
F_96 () ;
}
return V_66 ;
}
static inline T_4 F_101 ( const volatile void T_8 * V_7 )
{
return F_102 ( V_7 ) ;
}
static inline T_4 F_101 ( const volatile void T_8 * V_7 )
{
T_4 V_134 , V_135 ;
V_134 = F_103 ( V_7 ) ;
V_135 = F_103 ( V_7 + 4 ) ;
return V_134 | ( V_135 << 32 ) ;
}
T_11
F_104 ( T_6 V_136 , T_4 * V_130 , T_1 V_131 )
{
void T_8 * V_137 ;
unsigned int V_43 = V_131 / 8 ;
bool V_138 = false ;
T_4 V_132 ;
F_105 () ;
V_137 = F_21 ( V_136 , V_43 ) ;
if ( ! V_137 ) {
F_106 () ;
V_137 = F_30 ( V_136 , V_43 ) ;
if ( ! V_137 )
return V_139 ;
V_138 = true ;
}
if ( ! V_130 )
V_130 = & V_132 ;
switch ( V_131 ) {
case 8 :
* ( T_12 * ) V_130 = F_107 ( V_137 ) ;
break;
case 16 :
* ( V_133 * ) V_130 = F_108 ( V_137 ) ;
break;
case 32 :
* ( T_1 * ) V_130 = F_103 ( V_137 ) ;
break;
case 64 :
* ( T_4 * ) V_130 = F_101 ( V_137 ) ;
break;
default:
F_96 () ;
}
if ( V_138 )
F_33 ( V_137 ) ;
else
F_106 () ;
return V_66 ;
}
static inline void F_109 ( T_4 V_140 , volatile void T_8 * V_7 )
{
F_110 ( V_140 , V_7 ) ;
}
static inline void F_109 ( T_4 V_140 , volatile void T_8 * V_7 )
{
F_111 ( V_140 , V_7 ) ;
F_111 ( V_140 >> 32 , V_7 + 4 ) ;
}
T_11
F_112 ( T_6 V_136 , T_4 V_130 , T_1 V_131 )
{
void T_8 * V_137 ;
unsigned int V_43 = V_131 / 8 ;
bool V_138 = false ;
F_105 () ;
V_137 = F_21 ( V_136 , V_43 ) ;
if ( ! V_137 ) {
F_106 () ;
V_137 = F_30 ( V_136 , V_43 ) ;
if ( ! V_137 )
return V_139 ;
V_138 = true ;
}
switch ( V_131 ) {
case 8 :
F_113 ( V_130 , V_137 ) ;
break;
case 16 :
F_114 ( V_130 , V_137 ) ;
break;
case 32 :
F_111 ( V_130 , V_137 ) ;
break;
case 64 :
F_109 ( V_130 , V_137 ) ;
break;
default:
F_96 () ;
}
if ( V_138 )
F_33 ( V_137 ) ;
else
F_106 () ;
return V_66 ;
}
T_11
F_115 ( struct V_141 * V_142 , T_1 V_143 ,
T_4 * V_130 , T_1 V_131 )
{
int V_144 , V_43 ;
T_1 V_145 ;
if ( ! V_130 )
return V_65 ;
switch ( V_131 ) {
case 8 :
V_43 = 1 ;
break;
case 16 :
V_43 = 2 ;
break;
case 32 :
V_43 = 4 ;
break;
default:
return V_146 ;
}
V_144 = F_116 ( V_142 -> V_147 , V_142 -> V_148 ,
F_117 ( V_142 -> V_149 , V_142 -> V_150 ) ,
V_143 , V_43 , & V_145 ) ;
* V_130 = V_145 ;
return ( V_144 ? V_146 : V_66 ) ;
}
T_11
F_118 ( struct V_141 * V_142 , T_1 V_143 ,
T_4 V_130 , T_1 V_131 )
{
int V_144 , V_43 ;
switch ( V_131 ) {
case 8 :
V_43 = 1 ;
break;
case 16 :
V_43 = 2 ;
break;
case 32 :
V_43 = 4 ;
break;
default:
return V_146 ;
}
V_144 = F_119 ( V_142 -> V_147 , V_142 -> V_148 ,
F_117 ( V_142 -> V_149 , V_142 -> V_150 ) ,
V_143 , V_43 , V_130 ) ;
return ( V_144 ? V_146 : V_66 ) ;
}
static void F_120 ( struct V_151 * V_152 )
{
struct V_153 * V_154 = F_121 ( V_152 , struct V_153 , V_152 ) ;
V_154 -> V_150 ( V_154 -> V_119 ) ;
F_39 ( V_154 ) ;
}
T_11 F_122 ( T_18 type ,
T_19 V_150 , void * V_119 )
{
T_11 V_155 = V_66 ;
struct V_153 * V_154 ;
struct V_156 * V_157 ;
int V_158 ;
F_123 ( ( V_159 ,
L_33 ,
V_150 , V_119 ) ) ;
V_154 = F_36 ( sizeof( struct V_153 ) , V_160 ) ;
if ( ! V_154 )
return V_161 ;
V_154 -> V_150 = V_150 ;
V_154 -> V_119 = V_119 ;
if ( type == V_162 ) {
V_157 = V_163 ;
F_124 ( & V_154 -> V_152 , F_120 ) ;
} else {
V_157 = V_164 ;
F_124 ( & V_154 -> V_152 , F_120 ) ;
}
V_158 = F_125 ( 0 , V_157 , & V_154 -> V_152 ) ;
if ( ! V_158 ) {
F_11 (KERN_ERR PREFIX
L_34 ) ;
V_155 = V_146 ;
F_39 ( V_154 ) ;
}
return V_155 ;
}
void F_126 ( void )
{
F_127 ( V_164 ) ;
F_127 ( V_163 ) ;
}
static void F_128 ( struct V_151 * V_152 )
{
struct V_165 * V_166 = F_121 ( V_152 , struct V_165 , V_152 ) ;
F_126 () ;
F_129 ( V_166 -> V_167 , V_166 -> V_168 ) ;
F_39 ( V_166 ) ;
}
T_11 F_130 ( struct V_169 * V_167 , T_1 V_168 )
{
struct V_165 * V_166 ;
F_123 ( ( V_159 ,
L_35 ,
V_167 , V_168 ) ) ;
V_166 = F_131 ( sizeof( * V_166 ) , V_58 ) ;
if ( ! V_166 )
return V_161 ;
F_124 ( & V_166 -> V_152 , F_128 ) ;
V_166 -> V_167 = V_167 ;
V_166 -> V_168 = V_168 ;
if ( ! F_132 ( V_170 , & V_166 -> V_152 ) ) {
F_39 ( V_166 ) ;
return V_146 ;
}
return V_66 ;
}
bool F_133 ( struct V_151 * V_152 )
{
return F_132 ( V_170 , V_152 ) ;
}
T_11
F_134 ( T_1 V_171 , T_1 V_172 , T_20 * V_173 )
{
struct V_174 * V_175 = NULL ;
V_175 = F_135 ( sizeof( struct V_174 ) ) ;
if ( ! V_175 )
return V_161 ;
F_136 ( V_175 , V_172 ) ;
* V_173 = ( T_20 * ) V_175 ;
F_123 ( ( V_176 , L_36 ,
* V_173 , V_172 ) ) ;
return V_66 ;
}
T_11 F_137 ( T_20 V_173 )
{
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
if ( ! V_175 )
return V_65 ;
F_123 ( ( V_176 , L_37 , V_173 ) ) ;
F_138 ( ! F_139 ( & V_175 -> V_177 ) ) ;
F_39 ( V_175 ) ;
V_175 = NULL ;
return V_66 ;
}
T_11 F_140 ( T_20 V_173 , T_1 V_178 , V_133 V_179 )
{
T_11 V_155 = V_66 ;
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
long V_180 ;
int V_158 = 0 ;
if ( ! V_175 || ( V_178 < 1 ) )
return V_65 ;
if ( V_178 > 1 )
return V_181 ;
F_123 ( ( V_176 , L_38 ,
V_173 , V_178 , V_179 ) ) ;
if ( V_179 == V_182 )
V_180 = V_183 ;
else
V_180 = F_141 ( V_179 ) ;
V_158 = F_142 ( V_175 , V_180 ) ;
if ( V_158 )
V_155 = V_184 ;
if ( F_143 ( V_155 ) ) {
F_123 ( ( V_176 ,
L_39 ,
V_173 , V_178 , V_179 ,
F_144 ( V_155 ) ) ) ;
} else {
F_123 ( ( V_176 ,
L_40 , V_173 ,
V_178 , V_179 ) ) ;
}
return V_155 ;
}
T_11 F_145 ( T_20 V_173 , T_1 V_178 )
{
struct V_174 * V_175 = (struct V_174 * ) V_173 ;
if ( ! V_175 || ( V_178 < 1 ) )
return V_65 ;
if ( V_178 > 1 )
return V_181 ;
F_123 ( ( V_176 , L_41 , V_173 ,
V_178 ) ) ;
F_146 ( V_175 ) ;
return V_66 ;
}
T_1 F_147 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_185 ;
F_148 ( V_28 , sizeof( V_186 ) ) ;
V_185 = strlen ( V_28 ) - 1 ;
V_28 [ V_185 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_149 ( T_1 V_150 , void * V_187 )
{
switch ( V_150 ) {
case V_188 :
F_11 (KERN_ERR PREFIX L_42 ) ;
break;
case V_189 :
break;
default:
break;
}
return V_66 ;
}
static int T_3 F_150 ( char * V_190 )
{
char * V_191 = V_71 ;
int V_192 = V_193 - 1 ;
if ( ! V_190 || ! * V_190 )
return 0 ;
for (; V_192 -- && * V_190 ; V_190 ++ ) {
if ( isalnum ( * V_190 ) || * V_190 == ' ' || * V_190 == ':' )
* V_191 ++ = * V_190 ;
else if ( * V_190 == '\'' || * V_190 == '"' )
continue;
else
break;
}
* V_191 = 0 ;
return 1 ;
}
void T_3 F_151 ( char * V_190 )
{
struct V_194 * V_195 ;
bool V_196 = true ;
int V_197 ;
if ( ! V_198 )
return;
if ( V_190 == NULL || * V_190 == '\0' ) {
F_11 (KERN_INFO PREFIX L_43 ) ;
V_198 = FALSE ;
return;
}
if ( * V_190 == '!' ) {
V_190 ++ ;
if ( * V_190 == '\0' ) {
V_199 . V_200 = 1 ;
return;
} else if ( * V_190 == '*' ) {
F_152 ( V_201 ) ;
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
if ( ! strcmp ( V_195 -> string , V_190 ) ) {
V_195 -> V_196 = V_196 ;
break;
} else if ( V_195 -> string [ 0 ] == '\0' ) {
V_195 -> V_196 = V_196 ;
strncpy ( V_195 -> string , V_190 , V_204 ) ;
break;
}
}
}
static void T_3 F_153 ( unsigned int V_196 )
{
if ( V_199 . V_196 != V_196 )
V_199 . V_196 = V_196 ;
if ( V_199 . V_196 )
F_151 ( L_1 ) ;
else
F_151 ( L_44 ) ;
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
F_11 (KERN_NOTICE PREFIX L_45 , d->ident) ;
if ( V_196 == - 1 )
return;
V_199 . V_206 = 1 ;
F_153 ( V_196 ) ;
return;
}
static void T_3 F_156 ( void )
{
struct V_194 * V_195 ;
char * V_190 ;
int V_197 ;
T_11 V_155 ;
if ( V_199 . V_200 ) {
V_155 = F_152 ( V_209 ) ;
if ( F_157 ( V_155 ) )
F_11 (KERN_INFO PREFIX L_46 ) ;
}
for ( V_197 = 0 ; V_197 < V_202 ; V_197 ++ ) {
V_195 = & V_203 [ V_197 ] ;
V_190 = V_195 -> string ;
if ( * V_190 == '\0' )
break;
if ( V_195 -> V_196 ) {
V_155 = F_158 ( V_190 ) ;
if ( F_157 ( V_155 ) )
F_11 (KERN_INFO PREFIX L_47 , str) ;
} else {
V_155 = F_159 ( V_190 ) ;
if ( F_157 ( V_155 ) )
F_11 (KERN_INFO PREFIX L_48 , str) ;
}
}
}
static int T_3 F_160 ( char * V_190 )
{
if ( V_190 && ! strcmp ( L_1 , V_190 ) )
F_154 ( 1 ) ;
else if ( V_190 && ! strcmp ( L_44 , V_190 ) )
F_154 ( 0 ) ;
else
F_151 ( V_190 ) ;
return 1 ;
}
static int T_3 F_161 ( char * V_190 )
{
V_210 = FALSE ;
F_61 ( L_49 ) ;
return 1 ;
}
static int T_3 F_162 ( char * V_190 )
{
if ( V_190 == NULL || * V_190 == '\0' )
return 0 ;
if ( ! strcmp ( L_50 , V_190 ) )
V_211 = V_212 ;
else if ( ! strcmp ( L_51 , V_190 ) )
V_211 = V_213 ;
else if ( ! strcmp ( L_52 , V_190 ) )
V_211 = V_214 ;
return 1 ;
}
int F_163 ( const struct V_215 * V_216 )
{
T_21 V_9 ;
T_7 V_5 ;
T_12 V_217 = 0 ;
int V_218 = 0 ;
if ( V_211 == V_214 )
return 0 ;
if ( ! ( V_216 -> V_219 & V_220 ) && ! ( V_216 -> V_219 & V_221 ) )
return 0 ;
if ( V_216 -> V_219 & V_220 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = F_164 ( V_216 ) ;
if ( V_211 != V_214 )
V_217 = 1 ;
V_218 = F_165 ( V_9 , V_216 -> V_222 , V_5 , V_217 ) ;
if ( V_218 ) {
if ( V_211 != V_214 ) {
if ( V_211 == V_213 )
F_11 ( V_223 L_53
L_54
L_55 ) ;
F_11 ( V_224 L_56
L_57
L_58 ) ;
}
if ( V_211 == V_212 )
return - V_225 ;
}
return 0 ;
}
int F_166 ( T_22 V_222 , T_22 V_226 ,
const char * V_70 )
{
struct V_215 V_216 = {
. V_222 = V_222 ,
. V_73 = V_222 + V_226 - 1 ,
. V_70 = V_70 ,
. V_219 = V_220 ,
} ;
return F_163 ( & V_216 ) ;
}
int F_167 ( void )
{
return V_211 == V_212 ;
}
void F_168 ( T_23 V_173 )
{
F_169 ( V_173 ) ;
}
T_24 F_170 ( T_23 V_227 )
{
T_24 V_219 ;
F_171 ( V_227 , V_219 ) ;
return V_219 ;
}
void F_172 ( T_23 V_227 , T_24 V_219 )
{
F_173 ( V_227 , V_219 ) ;
}
T_11
F_174 ( char * V_70 , V_133 V_43 , V_133 V_228 , T_25 * * V_229 )
{
* V_229 = F_175 ( V_70 , V_43 , 0 , 0 , NULL ) ;
if ( * V_229 == NULL )
return V_146 ;
else
return V_66 ;
}
T_11 F_176 ( T_25 * V_229 )
{
F_177 ( V_229 ) ;
return ( V_66 ) ;
}
T_11 F_178 ( T_25 * V_229 )
{
F_179 ( V_229 ) ;
return ( V_66 ) ;
}
T_11 F_180 ( T_25 * V_229 , void * V_230 )
{
F_181 ( V_229 , V_230 ) ;
return ( V_66 ) ;
}
static int T_3 F_182 ( char * V_231 )
{
V_232 = TRUE ;
F_61 ( L_59 ) ;
return 0 ;
}
static int T_3 F_183 ( char * V_231 )
{
F_11 (KERN_NOTICE PREFIX
L_60 ) ;
V_233 = TRUE ;
return 1 ;
}
T_11 T_3 F_184 ( void )
{
F_52 ( & V_12 . V_13 ) ;
F_52 ( & V_12 . V_15 ) ;
F_52 ( & V_12 . V_24 ) ;
F_52 ( & V_12 . V_26 ) ;
if ( V_12 . V_219 & V_234 ) {
int V_235 ;
V_235 = F_52 ( & V_12 . V_236 ) ;
F_185 ( V_61 L_61 , V_62 , V_235 ) ;
}
return V_66 ;
}
T_11 T_3 F_186 ( void )
{
V_164 = F_187 ( L_62 , 0 , 1 ) ;
V_163 = F_187 ( L_63 , 0 , 1 ) ;
V_170 = F_188 ( L_64 , 0 ) ;
F_138 ( ! V_164 ) ;
F_138 ( ! V_163 ) ;
F_138 ( ! V_170 ) ;
F_189 ( F_1 ) ;
F_156 () ;
return V_66 ;
}
T_11 F_190 ( void )
{
if ( F_76 ) {
F_81 ( V_12 . V_120 ,
F_76 ) ;
}
F_53 ( & V_12 . V_26 ) ;
F_53 ( & V_12 . V_24 ) ;
F_53 ( & V_12 . V_15 ) ;
F_53 ( & V_12 . V_13 ) ;
if ( V_12 . V_219 & V_234 )
F_53 ( & V_12 . V_236 ) ;
F_191 ( V_164 ) ;
F_191 ( V_163 ) ;
F_191 ( V_170 ) ;
return V_66 ;
}
T_11 F_192 ( T_12 V_237 , T_1 V_238 ,
T_1 V_239 )
{
int V_240 = 0 ;
if ( V_241 )
V_240 = V_241 ( V_237 ,
V_238 , V_239 ) ;
if ( V_240 < 0 )
return V_146 ;
else if ( V_240 > 0 )
return V_242 ;
return V_66 ;
}
void F_193 ( int (* F_194)( T_12 V_237 ,
T_1 V_243 , T_1 V_244 ) )
{
V_241 = F_194 ;
}
T_11 F_195 ( T_12 V_237 , T_1 V_245 ,
T_1 V_246 )
{
int V_240 = 0 ;
if ( V_247 )
V_240 = V_247 ( V_237 ,
V_245 , V_246 ) ;
if ( V_240 < 0 )
return V_146 ;
else if ( V_240 > 0 )
return V_242 ;
return V_66 ;
}
void F_196 ( int (* F_194)( T_12 V_237 ,
T_1 V_245 , T_1 V_246 ) )
{
V_247 = F_194 ;
}
